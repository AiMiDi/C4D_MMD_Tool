"""Exercise the production MMD API through real HTTP and newline stdio MCP.

Run outside Cinema 4D, one bounded stage at a time. ``prepare`` creates inputs
and provenance; ``setup`` creates only this run's test documents. Production
calls use the maintained fixed bridge. A separate, fixed test-only Python body
creates/clones/undoes/saves/reopens those documents; it is never a tool exposed
by the production adapter. No source asset, user preference or process is reset.

Example:
  python scripts/c4d_production_mcp_validation.py --stage prepare --output S:/tmp/cmt-prod
      --expected-binary <normal Release xdl64> --build-cache <SDK CMakeCache.txt>
  python scripts/c4d_production_mcp_validation.py --stage setup --output S:/tmp/cmt-prod
      --token-file <Cinema 4D MCP token file>

Continue discovery, model, motion, camera, invalid, lifecycle, then cleanup.
``--stage all`` runs the same stages in order and stops at the first failure.
Receipts remain incomplete until every required native stage passes and the
original live document has been restored. A graph or transport pass never
claims an image render, performance comparison, remote CI or another host.
"""

from __future__ import annotations

import argparse
import copy
import base64
import datetime
import hashlib
import json
import math
import os
from pathlib import Path
import queue
import re
import stat
import subprocess
import sys
import threading
import time
import uuid
import xml.etree.ElementTree as ET

REPOSITORY = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPOSITORY / "mcp"))
sys.path.insert(0, str(REPOSITORY / "scripts"))
from mmdtool_mcp.host import HostConnection, HostError, RESULT_MARKER, SUPPORTED_MCP_VERSIONS
from mmdtool_mcp.schema import TOOL_BY_NAME, TOOLS, validate, validated_arguments
import c4d_regression_fixtures as fixtures
import c4d_runtime_regression as regression

STAGES = ("setup", "discovery", "model", "motion", "camera", "invalid", "lifecycle", "cleanup")
TEST_MARKER = "CMT_PRODUCTION_VALIDATION:"


class CleanupPending(RuntimeError):
    """The run is terminated but scene cleanup has not safely completed."""


def uncertain_execution(error):
    return isinstance(error, (HostError, TimeoutError, queue.Empty, ConnectionError, OSError, CleanupPending))


def operation_may_mutate(name):
    definition = TOOL_BY_NAME.get(name)
    return definition is None or not definition["annotations"]["readOnlyHint"]


def utc_now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def file_identity(path):
    path = Path(path).resolve()
    return {"path": str(path), "bytes": path.stat().st_size,
            "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}


def atomic_json(path, value):
    path = Path(path)
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(json.dumps(value, indent=2, ensure_ascii=False, allow_nan=False), encoding="utf-8")
    temporary.replace(path)


def source_identity():
    digest = hashlib.sha256()
    for directory in ("source", "res/S24_up"):
        for path in sorted((REPOSITORY / directory).rglob("*")):
            if path.is_file():
                digest.update(path.relative_to(REPOSITORY).as_posix().encode("utf-8"))
                digest.update(path.read_bytes())
    return digest.hexdigest()


def read_cache(path):
    result = {}
    for line in Path(path).read_text(encoding="utf-8", errors="replace").splitlines():
        if ":" in line and "=" in line and not line.startswith(("#", "//")):
            key, value = line.split("=", 1)
            key = key.split(":", 1)[0]
            if key in ("CMT_ENABLE_RUNTIME_REGRESSION", "CMT_ENABLE_PRODUCTION_MCP",
                       "CMT_SDK_BUILD_CONFIG", "CMAKE_GENERATOR", "CMAKE_HOME_DIRECTORY",
                       "CMT_DEPS_PREBUILT_DIR", "CMT_BULLET_SOURCE_DIR", "CMT_LIBMMD_SOURCE_DIR"):
                result[key] = value
    return {"identity": file_identity(path), "values": result}


def dependency_source_identity(root):
    """Fingerprint maintained src bytes; do not mix in tests or build output."""
    if root is None:
        return {"status": "unknown", "reason": "relative_source_override_cannot_be_resolved"}
    root = Path(root).resolve()
    source = root / "src"
    if not source.is_dir():
        return {"status": "unknown", "path": str(root), "reason": "maintained_src_missing"}
    digest, count, size = hashlib.sha256(), 0, 0
    try:
        for path in sorted(item for item in source.rglob("*") if item.is_file()):
            data = path.read_bytes()
            # Length-framed records prevent ambiguous path/content boundaries.
            record = {"path": path.relative_to(root).as_posix(), "bytes": len(data),
                      "sha256": hashlib.sha256(data).hexdigest()}
            encoded = json.dumps(record, sort_keys=True, separators=(",", ":"), ensure_ascii=False).encode("utf-8")
            digest.update(len(encoded).to_bytes(8, "big"))
            digest.update(encoded)
            count, size = count + 1, size + len(data)
    except OSError:
        return {"status": "unknown", "path": str(root), "reason": "maintained_src_unreadable"}
    if not count:
        return {"status": "unknown", "path": str(root), "reason": "maintained_src_empty"}
    git = {"status": "unknown", "head": None, "dirty_scope": "src", "dirty_entries": None}
    try:
        def git_read(*arguments):
            process = subprocess.run(["git", "-C", str(root), *arguments], capture_output=True,
                                     encoding="utf-8", errors="replace", check=False)
            if process.returncode:
                raise ValueError("Git identity unavailable")
            return process.stdout.strip()

        if Path(git_read("rev-parse", "--show-toplevel")).resolve() != root:
            raise ValueError("Dependency is not an independent Git checkout")
        git.update(status="recorded", head=git_read("rev-parse", "HEAD"),
                   dirty_entries=git_read("status", "--porcelain=v1", "--untracked-files=all", "--", "src").splitlines())
    except (OSError, ValueError):
        git["reason"] = "dependency_git_identity_unavailable"
    return {"status": "recorded", "path": str(root), "scope": "src", "sha256": digest.hexdigest(),
            "file_count": count, "bytes": size, "git": git}


def prebuilt_linker_identity(cache):
    """Record only libraries selected by this cache and generated VS project.

    CMake's maintained collector distinguishes *_Debug.lib from other *.lib.
    The generated project confirms actual link names/search paths, so adding an
    unrelated library to a directory after configure cannot masquerade as input.
    No fallback scan of other prebuilt/build/install directories is performed.
    """
    configurations = {name: {"status": "unknown", "libraries": []} for name in ("Debug", "Release")}
    result = {"status": "unknown", "selection_source": "CMT_DEPS_PREBUILT_DIR + generated mmdtool.vcxproj",
              "configurations": configurations, "source_build_relationship_verified": False}
    value = cache["values"].get("CMT_DEPS_PREBUILT_DIR", "")
    if not value:
        return {**result, "reason": "prebuilt_cache_not_configured"}
    directory = Path(value)
    if not directory.is_absolute():
        return {**result, "reason": "relative_prebuilt_cache_path_unresolved", "configured_path": value}
    directory = directory.resolve()
    result["path"] = str(directory)
    library_directory = directory / "lib"
    if not library_directory.is_dir():
        return {**result, "reason": "configured_prebuilt_lib_directory_missing"}
    project = Path(cache["identity"]["path"]).parent / "plugins/mmdtool/project/mmdtool.vcxproj"
    if not project.is_file():
        return {**result, "reason": "generated_linker_project_unavailable"}
    try:
        result["generated_project"] = file_identity(project)
        graph = ET.parse(project).getroot()
    except (OSError, ET.ParseError):
        return {**result, "reason": "generated_linker_project_unreadable"}
    required = ("libMMD", "Bullet3Common", "BulletCollision", "BulletDynamics",
                "BulletInverseDynamics", "BulletSoftBody", "LinearMath")
    catalog = {path.name: path for path in library_directory.glob("*.lib") if path.is_file()}
    for group in graph.findall("{*}ItemDefinitionGroup"):
        condition = group.get("Condition", "")
        configuration = next((name for name in configurations if re.search(
            r"==\s*['\"]" + name + r"\|[^'\"]+['\"]", condition)), None)
        link = group.find("{*}Link")
        if configuration is None or link is None:
            continue
        directories = (link.findtext("{*}AdditionalLibraryDirectories") or "").split(";")
        selected_search_path = False
        for raw in directories:
            raw = raw.replace("$(Configuration)", configuration)
            if "$(" in raw or "%(" in raw or not raw:
                continue
            candidate = Path(raw)
            if candidate.is_absolute() and candidate.resolve() == library_directory:
                selected_search_path = True
        if not selected_search_path:
            configurations[configuration]["reason"] = "configured_prebuilt_link_search_path_not_confirmed"
            continue
        names = (link.findtext("{*}AdditionalDependencies") or "").split(";")
        linked = [name for name in names if name in catalog]
        suffix = "_Debug.lib" if configuration == "Debug" else ".lib"
        expected = {name + suffix for name in required}
        missing = sorted(expected - set(linked))
        wrong_configuration = [name for name in linked if name.endswith("_Debug.lib") != (configuration == "Debug")]
        try:
            identities = [file_identity(catalog[name]) for name in sorted(set(linked))]
        except OSError:
            configurations[configuration]["reason"] = "configured_link_input_unreadable"
            continue
        configurations[configuration] = {"status": "recorded" if not missing and not wrong_configuration else "unknown",
                                         "libraries": identities, "missing_required": missing,
                                         "wrong_configuration": wrong_configuration}
    if all(item["status"] == "recorded" for item in configurations.values()):
        result["status"] = "recorded"
    else:
        result["reason"] = "configured_link_inputs_incomplete"
    return result


def dependency_identity(cache):
    values = cache["values"]

    def source_root(key, default):
        override = values.get(key, "")
        if not override:
            return REPOSITORY / default
        path = Path(override)
        return path if path.is_absolute() else None

    libmmd = dependency_source_identity(source_root("CMT_LIBMMD_SOURCE_DIR", "dependency/libMMD"))
    bullet = dependency_source_identity(source_root("CMT_BULLET_SOURCE_DIR", "dependency/bullet3"))
    prebuilt = prebuilt_linker_identity(cache)
    eligible = (libmmd["status"] == bullet["status"] == "recorded"
                and prebuilt["configurations"]["Release"]["status"] == "recorded")
    return {"schema_version": 1, "libMMD": libmmd, "Bullet": bullet, "prebuilt_linker_inputs": prebuilt,
            "snapshot_complete_for_release": eligible,
            "evidence_scope": "prepare-time dependency source and configured linker inputs; not a historical build attestation"}


def prepare(output, expected_binary, build_cache):
    if not expected_binary or not build_cache:
        raise ValueError("prepare requires --expected-binary and --build-cache")
    output = Path(output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    state_path = output / "state.json"
    if state_path.exists():
        raise ValueError("This output already contains a run; use another output directory")
    run_id = str(uuid.uuid4())
    cache = read_cache(build_cache)
    if cache["values"].get("CMT_ENABLE_RUNTIME_REGRESSION") != "OFF":
        raise AssertionError("Production acceptance requires a cache with runtime regression OFF")
    binary = file_identity(expected_binary)
    if not any(part.lower() == "release" for part in Path(binary["path"]).parts):
        raise AssertionError("Production acceptance requires the normal Release artifact")
    manifest = {"schema_version": 1, "created_utc": utc_now(), "run_id": run_id,
                "repository": str(REPOSITORY), "expected_binary": binary, "build_cache": cache,
                "source_sha256": source_identity(), "resource_ids": regression.load_resource_ids(REPOSITORY),
                "dependency_provenance": dependency_identity(cache),
                "fixtures": fixtures.generate(output / "inputs"), "stages": list(STAGES)}
    atomic_json(output / "manifest.json", manifest)
    state = {"schema_version": 1, "run_id": run_id, "created_utc": utc_now(),
             "document_name": "CMT production API " + run_id[:8], "values": {}, "stages": {},
             "native_executed": False, "acceptance_eligible": False, "original_document_restored": False,
             "terminated": False, "cleanup_pending": False}
    atomic_json(state_path, state)
    atomic_json(output / "receipt.json", {**state, "status": "prepared", "manifest": str(output / "manifest.json")})
    return manifest


def extract_marker(host_result, marker):
    if host_result.get("isError"):
        raise AssertionError("The fixed native validation helper failed; inspect the task-owned response")
    texts = [item.get("text", "") for item in host_result.get("content", []) if item.get("type") == "text"]
    structured = host_result.get("structuredContent", {})
    if isinstance(structured, dict) and isinstance(structured.get("stdout"), str):
        texts.append(structured["stdout"])
    for text in texts:
        try:
            wrapped = json.loads(text)
        except (ValueError, TypeError):
            wrapped = None
        if isinstance(wrapped, dict) and isinstance(wrapped.get("stdout"), str):
            text = wrapped["stdout"]
        for line in text.splitlines():
            if line.startswith(marker):
                return json.loads(line[len(marker):])
    raise AssertionError("Native validation helper did not return its fixed result marker")


# Only maintained statements below are executable. CLI input is encoded JSON
# data and cannot add code. All target documents are held by this run's private
# Python module; a generic name search never selects or closes a user document.
_TEST_CODE = r'''import base64, json, math, os, sys, types, c4d
_p = json.loads(base64.b64decode("__PAYLOAD__").decode("utf-8"))
_key = "_cmt_production_validation_" + _p["run_id"].replace("-", "")
_m = sys.modules.get(_key)
_action = _p["action"]
_main_thread = c4d.threading.GeIsMainThreadAndNoDrawThread()
if not _main_thread:
    raise RuntimeError("Native validation requires the main thread outside drawing")

def _same(_left, _right):
    if _left is _right:
        return True
    try:
        return _left == _right
    except ReferenceError:
        return False

def _live(_doc):
    _item = c4d.documents.GetFirstDocument()
    while _item is not None:
        if _same(_item, _doc):
            return True
        _item = _item.GetNext()
    return False

def _own(_doc):
    if _doc is None or _same(_doc, _m.original):
        raise RuntimeError("Cannot register the original document as test-owned")
    if not any(_same(_existing, _doc) for _existing in _m.owned_docs):
        _m.owned_docs.append(_doc)
    return _doc

if _m is not None:
    # Upgrade only the exact references held by this run's older private module.
    # Names, paths and the global document list never establish ownership.
    if not hasattr(_m, "owned_docs"):
        _m.owned_docs = []
        for _existing in _m.documents.values():
            if not _same(_existing, _m.original):
                _own(_existing)
    if not hasattr(_m, "terminated"):
        _m.terminated = False
    if _m.terminated and _action not in ("identity", "snapshot", "restore", "cleanup_status", "cleanup"):
        raise RuntimeError("This test run is terminated; mutations cannot be replayed")

if _action == "setup":
    if _m is not None:
        if set(_m.documents) != {"A","B"}:
            raise RuntimeError("A partially created test run must be cleaned before retrying setup")
    else:
        _m = types.ModuleType(_key)
        _m.original = c4d.documents.GetActiveDocument()
        _m.documents = {}
        _m.owned_docs = []
        _m.terminated = False
        _m.guard = None
        _m.original_was_blank = False
        sys.modules[_key] = _m
        if _m.original and _m.original.GetFirstObject() is None and _m.original.GetFirstMaterial() is None:
            # C4D otherwise closes its untouched blank document when the first test
            # doc is inserted. This guard is removed at cleanup, with its use recorded.
            _m.guard = c4d.BaseObject(c4d.Onull)
            _m.guard.SetName("CMT validation original-document guard")
            _m.original.InsertObject(_m.guard)
            _m.original_was_blank = True
        for _label in ("A", "B"):
            _doc = _own(c4d.documents.BaseDocument())
            _m.documents[_label] = _doc
            _doc.SetName(_p["document_name"])
            _doc.SetDocumentName(_p["document_name"]+".c4d")
            _doc.SetFps(30)
            _guard = c4d.BaseObject(c4d.Onull)
            _guard.SetName("CMT validation owned document " + _label)
            _doc.InsertObject(_guard)
            c4d.documents.InsertBaseDocument(_doc)
    for _doc in _m.documents.values():
        _doc.SetDocumentName(_p["document_name"]+".c4d")
    if not getattr(_m,"saved_same_names",False):
        # Use two actual native files with the same basename, in distinct
        # run-owned directories. Loading them makes the C++ Filename-backed
        # document names identical independently of Python's BaseList2D name.
        for _label,_old in list(_m.documents.items()):
            _directory = os.path.join(_p["output"],"native-documents",_label)
            os.makedirs(_directory,exist_ok=True)
            _path = os.path.join(_directory,"same-name.c4d")
            if not c4d.documents.SaveDocument(_old,_path,c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT):
                raise RuntimeError("Could not save the owned same-name document fixture")
            _new = c4d.documents.LoadDocument(_path,c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
            if _new is None:
                raise RuntimeError("Could not load the owned same-name document fixture")
            _own(_new)
            c4d.documents.InsertBaseDocument(_new)
            _m.documents[_label] = _new
            c4d.documents.KillDocument(_old)
        _m.saved_same_names = True
elif _m is None and _action not in ("identity", "cleanup_status"):
    raise RuntimeError("Run setup in this live host before using native test state")

def _walk(_node):
    while _node is not None:
        yield _node
        yield from _walk(_node.GetDown())
        _node = _node.GetNext()

def _values(_matrix):
    _result = [float(_v) for _vector in (_matrix.off, _matrix.v1, _matrix.v2, _matrix.v3)
               for _v in (_vector.x, _vector.y, _vector.z)]
    if not all(math.isfinite(_v) for _v in _result):
        raise RuntimeError("Non-finite native matrix in production validation")
    return _result

def _snapshot(_doc):
    _models = []
    _cameras = []
    for _node in _walk(_doc.GetFirstObject()):
        if _node.GetType() == 1056978 or _node.IsInstanceOf(c4d.Ocamera):
            _track_keys = []
            _track = _node.GetFirstCTrack()
            while _track is not None:
                _curve = _track.GetCurve()
                _track_keys.append({"key_count":_curve.GetKeyCount(),
                                    "times":[float(_curve.GetKey(_i).GetTime().Get()) for _i in range(_curve.GetKeyCount())]})
                _track = _track.GetNext()
            _camera = {"name":_node.GetName(),"type":_node.GetType(),"world":_values(_node.GetMg()),
                       "local":_values(_node.GetMl()),"tracks":_track_keys}
            if _node.IsInstanceOf(c4d.Ocamera):
                _camera["vertical_fov"] = float(_node[c4d.CAMERAOBJECT_FOV_VERTICAL])
                _camera["aperture"] = float(_node[c4d.CAMERAOBJECT_APERTURE])
            _cameras.append(_camera)
        if _node.GetType() != 1056724:
            continue
        _bones = []
        for _bone in _walk(_node.GetDown()):
            if _bone.GetTag(1056720) is not None:
                _bones.append({"name":_bone.GetName(), "world":_values(_bone.GetMg()),
                               "local":_values(_bone.GetMl()), "frozen":_values(_bone.GetFrozenMln())})
        _models.append({"name":_node.GetName(), "mode":int(_node[_p["ids"]["MODEL_MODE"]]),
                        "physics":bool(_node[_p["ids"]["MODEL_PHYSICS_ENABLED"]]),
                        "slot":int(_node[_p["ids"]["MODEL_ANIM_LIST"]]), "bones":_bones})
    _materials = []
    _material = _doc.GetFirstMaterial()
    while _material is not None:
        _shader = _material[c4d.MATERIAL_COLOR_SHADER]
        _color = None
        if _shader is not None and _shader.GetType() == c4d.Xcolor:
            _v = _shader[c4d.COLORSHADER_COLOR]
            _color = [float(_v.x), float(_v.y), float(_v.z)]
        _materials.append({"name":_material.GetName(), "color":_color})
        _material = _material.GetNext()
    return {"name":_doc.GetName(), "time_seconds":float(_doc.GetTime().Get()), "fps":_doc.GetFps(),
            "models":_models, "materials":_materials,"cameras":_cameras}

_result = {}
if _action == "identity":
    sys.path.insert(0, os.path.join(_p["repository"], "scripts"))
    import c4d_runtime_regression as _reg
    _result = {"host_version":c4d.GetC4DVersion(), "pid":os.getpid(),
               "loaded_binary":_reg.loaded_plugin_binary()}
elif _action == "setup":
    _result = {"created_documents":2, "original_blank_guard_used":_m.original_was_blank}
elif _action == "cleanup_status":
    # A successful fixed helper response on the main thread is a serial
    # execution checkpoint, including after an earlier helper transport timeout.
    _result = {"main_thread_checkpoint":bool(_main_thread), "module_exists":_m is not None,
               "original_live":_m is not None and _live(_m.original),
               "owned_document_count":len(_m.owned_docs) if _m is not None else None}
elif _action in ("activate","probe_active"):
    _doc = _m.documents[_p["label"]]
    if not _live(_doc):
        raise RuntimeError("Owned test document is no longer live")
    if _action == "activate":
        c4d.documents.SetActiveDocument(_doc)
    _result = {"name":_doc.GetName(),"document_name":_doc.GetDocumentName(),
               "active_is_owned":c4d.documents.GetActiveDocument()==_doc,"owned_document_live":True}
elif _action == "snapshot":
    _result = {"documents":{_label:_snapshot(_doc) for _label,_doc in _m.documents.items() if _live(_doc)},
               "original_live":_live(_m.original),
               "original_active":c4d.documents.GetActiveDocument() == _m.original}
elif _action == "rename_models":
    _count = 0
    for _doc in _m.documents.values():
        if _live(_doc):
            for _node in _walk(_doc.GetFirstObject()):
                if _node.GetType() == 1056724:
                    _node.SetName("same-name-model")
                    _count += 1
    c4d.EventAdd()
    _result = {"renamed":_count}
elif _action in ("undo", "redo"):
    _doc = _m.documents[_p["label"]]
    # Native undo callbacks can consult GetActiveDocument(), so choose the
    # explicitly owned doc for the complete operation and restore the user doc
    # afterwards. Record the actual tree to distinguish SDK/Undo failures from
    # an API listing/cache failure.
    c4d.documents.SetActiveDocument(_doc)
    _result = {"done":bool(_doc.DoUndo() if _action == "undo" else _doc.DoRedo()),
               "active_while_undo_is_owned":c4d.documents.GetActiveDocument()==_doc,
               "native_model_count":sum(1 for _node in _walk(_doc.GetFirstObject()) if _node.GetType()==1056724)}
    c4d.EventAdd()
elif _action == "set_time":
    _doc = _m.documents[_p["label"]]
    _doc.SetTime(c4d.BaseTime(_p["frame"], _doc.GetFps()))
    _doc.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_NONE)
    _doc.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_NONE)
    _result = _snapshot(_doc)
elif _action == "clone":
    _source = _m.documents[_p["label"]]
    _translator = c4d.AliasTrans()
    if not _translator.Init(_source):
        raise RuntimeError("Could not initialize native clone alias translator")
    _clone = _source.GetClone(c4d.COPYFLAGS_NONE,_translator)
    if _clone is None:
        raise RuntimeError("Owned test document clone failed")
    _own(_clone)
    _translator.Translate(True)
    _clone.SetName(_p["document_name"])
    _clone.SetDocumentName(_p["document_name"]+".c4d")
    c4d.documents.InsertBaseDocument(_clone)
    _m.documents["C"] = _clone
    c4d.documents.SetActiveDocument(_clone)
    _result = _snapshot(_clone)
elif _action == "delete_model":
    _doc = _m.documents[_p["label"]]
    _models = [_node for _node in _walk(_doc.GetFirstObject()) if _node.GetType() == 1056724]
    if len(_models) != 1:
        raise RuntimeError("Deletion fixture must contain exactly one owned model")
    _doc.StartUndo()
    _doc.AddUndo(c4d.UNDOTYPE_DELETEOBJ,_models[0])
    _models[0].Remove()
    _doc.EndUndo()
    c4d.EventAdd()
    _result = {"deleted":1}
elif _action == "save_reopen":
    _old = _m.documents[_p["label"]]
    if not c4d.documents.SaveDocument(_old,_p["path"],c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT):
        raise RuntimeError("Owned native scene save failed")
    _new = c4d.documents.LoadDocument(_p["path"],c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
    if _new is None:
        raise RuntimeError("Owned native scene reopen failed")
    _own(_new)
    _new.SetName(_p["document_name"])
    _new.SetDocumentName(_p["document_name"]+".c4d")
    c4d.documents.InsertBaseDocument(_new)
    _m.documents[_p["label"]] = _new
    c4d.documents.KillDocument(_old)
    c4d.documents.SetActiveDocument(_new)
    _result = _snapshot(_new)
elif _action == "load_restart_scene":
    _old = _m.documents[_p["label"]]
    _new = c4d.documents.LoadDocument(_p["path"],c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
    if _new is None:
        raise RuntimeError("Saved restart scene could not be loaded")
    _own(_new)
    c4d.documents.InsertBaseDocument(_new)
    _m.documents[_p["label"]] = _new
    c4d.documents.SetActiveDocument(_m.original)
    c4d.documents.KillDocument(_old)
    _result = _snapshot(_new)
elif _action == "regression_disabled":
    _doc = _m.documents["A"]
    _hook = _doc.FindSceneHook(1057017)
    if _hook is None:
        raise RuntimeError("Production plugin SceneHook is absent")
    _storage = _hook.GetDataInstance()
    _storage.RemoveData(2000000)
    _storage.RemoveData(2000001)
    _hook[1000000] = 1
    _hook[1000001] = 0
    _hook[1000100] = False
    _hook.Message(1057017)
    _result = {"runtime_regression_responded":bool(_hook[1000100])}
elif _action == "cleanup":
    _m.terminated = True
    _closed = []
    _remaining = []
    _errors = []
    for _index,_doc in enumerate(list(_m.owned_docs)):
        if _same(_doc, _m.original):
            continue
        try:
            # A valid detached LoadDocument/clone also needs to be freed.
            # Closed references raise ReferenceError and are already disposed.
            _doc.GetDocumentName()
            c4d.documents.KillDocument(_doc)
            if _live(_doc):
                raise RuntimeError("Owned document remained live after closing")
            _closed.append(_index)
        except ReferenceError:
            continue
        except Exception as _error:
            _remaining.append(_doc)
            _errors.append({"owned_index":_index,"error_type":type(_error).__name__})
    _m.owned_docs = _remaining
    _m.documents = {_label:_doc for _label,_doc in _m.documents.items() if _live(_doc)}
    if not _remaining and _m.guard is not None:
        try:
            _m.guard.Remove()
        except ReferenceError:
            _m.guard = None
        except Exception as _error:
            _errors.append({"original_guard":True,"error_type":type(_error).__name__})
        else:
            _m.guard = None
    _result = {"closed_owned_documents":_closed, "remaining_owned_documents":len(_remaining),
               "cleanup_errors":_errors, "cleanup_pending":bool(_remaining or _errors),
               "original_blank_guard_used":_m.original_was_blank}
elif _action != "restore":
    raise RuntimeError("Unsupported fixed native validation action")

if _m is not None and _action not in ("activate","clone","save_reopen","cleanup_status"):
    if _live(_m.original):
        c4d.documents.SetActiveDocument(_m.original)
    _result["original_document_live"] = _live(_m.original)
    _result["original_document_restored"] = _live(_m.original) and c4d.documents.GetActiveDocument() == _m.original
print("CMT_PRODUCTION_VALIDATION:" + json.dumps(_result,ensure_ascii=False,allow_nan=False))
'''


class StdioClient:
    """A real serial adapter subprocess, never an in-memory server fixture."""

    def __init__(self, endpoint, token_file, timeout, *, python_executable=None, adapter_entry=None):
        self.timeout, self.next_id = timeout, 0
        self.responses = queue.Queue()
        flags = subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0
        self.process = subprocess.Popen([str(python_executable or sys.executable), "-X", "utf8",
                         str(adapter_entry or REPOSITORY / "mcp/run_mmdtool_mcp.py"),
                         "--endpoint", endpoint, "--token-file", str(token_file), "--timeout", str(timeout)],
                         stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                         creationflags=flags)
        self.stderr = []
        threading.Thread(target=self._read, daemon=True).start()
        threading.Thread(target=self._read_errors, daemon=True).start()
        self.request("initialize", {"protocolVersion": SUPPORTED_MCP_VERSIONS[0], "capabilities": {},
                                    "clientInfo": {"name": "cmt-production-validation", "version": "1"}})
        self.request("notifications/initialized", {}, notification=True)

    def _read(self):
        for line in self.process.stdout:
            try:
                self.responses.put(json.loads(line.decode("utf-8")))
            except (ValueError, UnicodeError):
                self.responses.put({"error": {"code": "invalid_adapter_output"}})
        self.responses.put({"error": {"code": "adapter_closed"}})

    def _read_errors(self):
        # The adapter sanitizes errors. Keep bounded stderr for evidence, never
        # print a credential or raw host response body in validation progress.
        for line in self.process.stderr:
            if len(self.stderr) < 100:
                self.stderr.append(line.decode("utf-8", errors="replace").strip())

    def request(self, method, params, *, notification=False):
        self.next_id += 1
        message = {"jsonrpc": "2.0", "method": method, "params": params}
        if not notification:
            message["id"] = self.next_id
        self.process.stdin.write(json.dumps(message, ensure_ascii=False, allow_nan=False).encode("utf-8") + b"\n")
        self.process.stdin.flush()
        if notification:
            return {}
        response = self.responses.get(timeout=self.timeout + 15)
        if response.get("id") != self.next_id:
            raise AssertionError("stdio JSON-RPC response identity mismatch")
        return response

    def malformed_json(self, encoded):
        self.process.stdin.write(encoded + b"\n")
        self.process.stdin.flush()
        return self.responses.get(timeout=15)

    def close(self):
        if self.process.stdin:
            self.process.stdin.close()
        try:
            self.process.wait(timeout=3)
        except subprocess.TimeoutExpired:
            # Only this task's adapter subprocess is terminated. Its uncertain
            # mutation result remains uncertain; Cinema 4D is never terminated.
            self.process.terminate()
            self.process.wait(timeout=3)


class ValidationRun:
    def __init__(self, output, endpoint, token_file, timeout):
        self.output = Path(output).resolve()
        self.manifest = json.loads((self.output / "manifest.json").read_text(encoding="utf-8"))
        self.state = json.loads((self.output / "state.json").read_text(encoding="utf-8"))
        self.values = self.state["values"]
        self.state.setdefault("terminated", False)
        self.state.setdefault("cleanup_pending", False)
        if any(record.get("status") == "failed" for record in self.state["stages"].values()):
            self.state["terminated"] = True
        self.endpoint, self.token_file, self.timeout = endpoint, token_file, timeout
        self.host = HostConnection(endpoint, token_file, timeout)
        self.host_connected = False
        self.stage_name = ""

    def ensure_host(self):
        if not self.host_connected:
            self.host.initialize()
            self.host_connected = True

    def record(self, kind, request, response):
        event = {"utc": utc_now(), "stage": self.stage_name, "transport": kind,
                 "request": request, "response": response}
        with (self.output / "transcript.jsonl").open("a", encoding="utf-8") as destination:
            destination.write(json.dumps(event, ensure_ascii=False, allow_nan=False) + "\n")

    def native(self, action, **data):
        self.ensure_host()
        if action in ("save_reopen", "cleanup"):
            # The host can retain the request's starting document for postchecks.
            # Restore in a separate request before closing any owned document.
            self.native("restore")
        payload = {"action": action, "run_id": self.state["run_id"],
                   "repository": str(REPOSITORY), "output":str(self.output),"document_name": self.state["document_name"],
                   "ids": self.manifest["resource_ids"], **data}
        encoded = base64.b64encode(json.dumps(payload, ensure_ascii=False, allow_nan=False).encode("utf-8")).decode("ascii")
        may_mutate = action not in ("identity", "snapshot", "cleanup_status")
        if may_mutate:
            self.state["pending_helper"] = {"action": action, "started_utc": utc_now()}
            self.write_receipt()
        result = self.host.request("tools/call", {"name": "exec_python", "arguments": {
                    "code": _TEST_CODE.replace("__PAYLOAD__", encoded), "timeout_seconds": min(int(self.timeout), 600),
                    "max_iterations": 50000000}}, may_mutate=may_mutate)
        self.record("fixed_native_test_helper", {"action": action, **data}, result)
        if result.get("isError") and may_mutate:
            raise CleanupPending("Native helper execution did not confirm completion; cleanup requires a main-thread checkpoint")
        self.state.pop("pending_helper", None)
        parsed = extract_marker(result, TEST_MARKER)
        if "original_document_restored" in parsed:
            self.state["original_document_restored"] = parsed["original_document_restored"]
        return parsed

    def call(self, name, arguments=None, *, expected=True, operation_id=None, stdio=None,
             validate_input=True, expected_codes=None):
        arguments = dict(arguments or {})
        arguments["operation_id"] = operation_id or str(uuid.uuid4())
        if validate_input:
            arguments = validated_arguments(name, arguments)
        may_mutate = operation_may_mutate(name)
        if may_mutate:
            self.state["pending_operation"] = {"tool_name": name, "operation_id": arguments["operation_id"],
                                                "started_utc": utc_now()}
            self.write_receipt()
        if stdio is not None:
            response = stdio.request("tools/call", {"name": name, "arguments": arguments})
            self.record("stdio", {"name": name, "arguments": arguments}, response)
            if "error" in response:
                raise AssertionError("Unexpected stdio input/protocol error: " + str(response["error"]["code"]))
            result = response["result"]["structuredContent"]
        else:
            self.ensure_host()
            result = self.host.call_production(name, arguments, arguments["operation_id"],
                                             may_mutate=may_mutate)
            self.record("http_fixed_production_bridge", {"name": name, "arguments": arguments}, result)
        if may_mutate and result.get("state") in ("queued", "running", "outcome_unknown"):
            raise CleanupPending("Production operation has an uncertain outcome; query its ID before scene cleanup")
        if may_mutate:
            self.state.pop("pending_operation", None)
        validate(result, TOOL_BY_NAME[name]["outputSchema"], "native_result")
        if result["operation_id"] != arguments["operation_id"]:
            raise AssertionError("Production response operation_id mismatch")
        if bool(result["success"]) != expected:
            raise AssertionError(f"{name}: success={result['success']} code={result['code']}")
        if expected and result["state"] != "completed":
            raise AssertionError("Synchronous production operation did not complete")
        if not expected and result["code"] in ("host_protocol_error", "plugin_unavailable", "host_execution_failed"):
            raise AssertionError("A negative domain test failed because the host/API was broken")
        if expected_codes and result["code"] not in expected_codes:
            raise AssertionError("Unexpected domain rejection code: " + result["code"])
        return result

    def fixture(self, name):
        identity = self.manifest["fixtures"][name]
        if file_identity(identity["path"])["sha256"] != identity["sha256"]:
            raise AssertionError("Fixture identity changed: " + name)
        return identity["path"]

    def target(self, label="A", model="A1"):
        return {"document": self.values["documents"][label], "model": self.values["models"][model]}

    def documents(self, label):
        self.native("activate", label=label)
        result = self.call("mmdtool_capabilities")
        active = [item for item in result["data"]["documents"] if item.get("active")]
        if len(active) != 1:
            raise AssertionError("Capabilities did not identify the explicitly active owned document")
        ownership = self.native("probe_active", label=label)
        if not ownership["owned_document_live"] or not ownership["active_is_owned"]:
            raise AssertionError("Capabilities changed the explicitly active owned native document")
        self.native("restore")
        return active[0]["handle"]

    def setup(self):
        prepared_dependencies = self.manifest.get("dependency_provenance")
        if prepared_dependencies is not None:
            current_dependencies = dependency_identity(read_cache(self.manifest["build_cache"]["identity"]["path"]))
            if current_dependencies != prepared_dependencies:
                raise AssertionError("Dependency source or configured static linker inputs changed after preparation")
            self.state["dependency_identity_verified"] = prepared_dependencies["snapshot_complete_for_release"]
        identity = self.native("identity")
        expected = self.manifest["expected_binary"]
        if not identity.get("loaded_binary") or identity["loaded_binary"]["sha256"] != expected["sha256"]:
            raise AssertionError("The live C4D module is not the prepared normal Release binary")
        if source_identity() != self.manifest["source_sha256"]:
            raise AssertionError("Maintained source changed after this run was prepared")
        self.state["native_identity"] = identity
        created = self.native("setup")
        disabled = self.native("regression_disabled")
        if disabled["runtime_regression_responded"]:
            raise AssertionError("Test-only regression bridge unexpectedly responded in normal Release")
        self.values["documents"] = {label: self.documents(label) for label in ("A", "B")}
        if len(set(self.values["documents"].values())) != 2:
            raise AssertionError("Same-name documents shared a production handle")
        self.values["models"] = {}
        self.state["native_executed"] = True
        return {"identity": identity, "created": created, "regression_bridge_disabled": disabled,
                "documents": self.values["documents"]}

    def discovery(self):
        capabilities = self.call("mmdtool_capabilities")["data"]
        if capabilities["protocol_version"] != 1 or not capabilities.get("host_session"):
            raise AssertionError("Production compatibility handshake is incomplete")
        if set(capabilities["supported_operations"]) != set(TOOL_BY_NAME):
            raise AssertionError("Normal Release does not advertise the complete maintained operation set")
        same_names = [doc for doc in capabilities["documents"] if doc["handle"] in self.values["documents"].values()]
        if len(same_names) != 2 or len({doc["name"] for doc in same_names}) != 1:
            raise AssertionError("Capabilities lost a same-name test document")
        stdio = StdioClient(self.endpoint, self.token_file, self.timeout)
        try:
            catalog = stdio.request("tools/list", {})
            self.record("stdio", {"method": "tools/list"}, catalog)
            tools = catalog["result"]["tools"]
            if {tool["name"] for tool in tools} != set(TOOL_BY_NAME):
                raise AssertionError("Actual stdio discovery differs from the maintained catalog")
            for tool in tools:
                if tool["inputSchema"].get("additionalProperties") is not False or "code" in tool["inputSchema"]["properties"]:
                    raise AssertionError("Production tool catalog exposes an open/arbitrary-code input")
            operation_id = str(uuid.uuid4())
            arguments = {"document": self.values["documents"]["A"], "path": self.fixture("model.pmx"),
                         "position_multiple": 1.}
            first = self.call("mmdtool_import_pmx", arguments, operation_id=operation_id)
            duplicate = self.call("mmdtool_import_pmx", arguments, operation_id=operation_id, stdio=stdio)
            if duplicate["data"]["model"]["handle"] != first["data"]["model"]["handle"]:
                raise AssertionError("Cross-transport deduplication created a different model")
            models = self.call("mmdtool_list_models", {"document": arguments["document"]})["data"]["models"]
            if len(models) != 1:
                raise AssertionError("Repeated operation_id imported the PMX twice")
            status = self.call("mmdtool_operation_status", {"query_operation_id": operation_id})
            if status["data"]["operation"].get("operation_id") != operation_id:
                raise AssertionError("Operation status did not recover the original mutation")
            self.call("mmdtool_import_pmx", {**arguments, "path": self.fixture("mixed_morphs.pmx")},
                      operation_id=operation_id, expected=False, expected_codes={"operation_id_conflict"})
            self.call("mmdtool_operation_status", {"query_operation_id": str(uuid.uuid4())}, expected=False)
            old_model = first["data"]["model"]["handle"]
            if not self.native("undo", label="A")["done"]:
                raise AssertionError("Production PMX import did not create one usable Undo action")
            if self.call("mmdtool_list_models", {"document": arguments["document"]})["data"]["total"] != 0:
                raise AssertionError("One Undo failed to remove the entire model import")
            self.call("mmdtool_inspect_model", {"document": arguments["document"], "model": old_model}, expected=False)
            if not self.native("redo", label="A")["done"]:
                raise AssertionError("Production import Redo failed")
            restored = self.call("mmdtool_list_models", {"document": arguments["document"]})["data"]["models"]
            if len(restored) != 1:
                raise AssertionError("Redo did not restore exactly one imported model")
            self.values["models"]["A1"] = restored[0]["handle"]
            self.values["dedup_operation"] = operation_id
        finally:
            stdio.close()
        for label, model in (("A", "A2"), ("B", "B1")):
            response = self.call("mmdtool_import_pmx", {"document": self.values["documents"][label],
                                 "path": self.fixture("model.pmx"), "position_multiple": 1.})
            self.values["models"][model] = response["data"]["model"]["handle"]
        self.native("rename_models")
        first_page = self.call("mmdtool_list_models", {"document": self.values["documents"]["A"], "limit": 1})["data"]
        second_page = self.call("mmdtool_list_models", {"document": self.values["documents"]["A"], "limit": 1, "offset": 1})["data"]
        if first_page["total"] != 2 or second_page["total"] != 2:
            raise AssertionError("Model pagination lost an identically named model")
        page_models = first_page["models"] + second_page["models"]
        if len({item["handle"] for item in page_models}) != 2 or {item["name"] for item in page_models} != {"same-name-model"}:
            raise AssertionError("Model targeting depends on names instead of opaque identities")
        self.call("mmdtool_inspect_model", {"document": self.values["documents"]["B"],
                  "model": self.values["models"]["A1"]}, expected=False)
        return {"capabilities": capabilities, "stdio_tools": [tool["name"] for tool in tools],
                "deduplication": "HTTP mutation replayed through a new real stdio adapter",
                "same_name_pages": [first_page, second_page], "models": self.values["models"]}

    def model(self):
        target = self.target()
        summary = self.call("mmdtool_inspect_model", target)["data"]
        bones = self.call("mmdtool_inspect_model", {**target, "section": "bones", "limit": 2})["data"]
        if bones["total"] != 4 or len(bones["items"]) != 2:
            raise AssertionError("Paginated bone inspection differs from the independent fixture")
        morphs = self.call("mmdtool_inspect_model", {**target, "section": "morphs"})["data"]
        tint = next(item for item in morphs["items"] if item["name"] == "tint")
        morph_handle = tint.get("handle", tint.get("morph_handle"))
        if not morph_handle:
            raise AssertionError("Morph inspection did not return an opaque morph handle")
        self.values["morph"] = morph_handle
        self.call("mmdtool_set_physics_enabled", {**target, "enabled": False})
        self.call("mmdtool_set_physics_enabled", {**target, "enabled": True})
        if not self.native("undo", label="A")["done"]:
            raise AssertionError("Physics mutation produced no usable Undo action")
        undone = self.call("mmdtool_inspect_model", target)["data"]["model"]
        if undone.get("physics_enabled") is not False:
            raise AssertionError("Undo failed to restore the prior physics value")
        self.call("mmdtool_set_mode", {**target, "mode": "anim"})
        self.call("mmdtool_set_morph_strength", {**target, "morph_handle": morph_handle, "strength": .5})
        self.call("mmdtool_set_morph_strength", {**target, "morph_handle": morph_handle, "strength": 0.})
        self.call("mmdtool_set_mode", {**target, "mode": "edit"})
        editable = self.call("mmdtool_inspect_model", target)["data"]["model"]
        if editable.get("mode") != "edit":
            raise AssertionError("The production mode setter did not reach the model")
        path = self.output / "exports/model.pmx"
        path.parent.mkdir(exist_ok=True)
        exported = self.call("mmdtool_export_pmx", {**target, "path": str(path), "position_multiple": 1.})
        self.verify_file(exported)
        parsed = fixtures.read_pmx_bones(path)
        if parsed["vertices"] != 3 or len(parsed["bones"]) != 4 or parsed["materials"] != 1:
            raise AssertionError("Production PMX export differs from fixture topology")
        baseline = fixtures.read_pmx_morphs_and_frames(path, include_physics=True)
        source_before_scale = self.native("snapshot")
        scale_exports = []
        for export_scale in (2., .5):
            scaled_path = self.output / ("exports/model-scale-" + str(export_scale) + ".pmx")
            scaled = self.call("mmdtool_export_pmx", {**target, "path": str(scaled_path),
                               "position_multiple": export_scale})
            self.verify_file(scaled)
            snapshot = fixtures.read_pmx_morphs_and_frames(scaled_path, include_physics=True)
            assert_pmx_length_ratio(baseline, snapshot, 1. / export_scale)
            scale_exports.append({"export_scale": export_scale, "length_ratio": 1. / export_scale,
                                  "file": file_identity(scaled_path)})
        assert_equal_numeric(source_before_scale["documents"], self.native("snapshot")["documents"])
        before = file_identity(path)
        self.call("mmdtool_export_pmx", {**target, "path": str(path), "position_multiple": 1.}, expected=False)
        if file_identity(path) != before:
            raise AssertionError("overwrite=false modified an existing PMX")
        replaced = self.call("mmdtool_export_pmx", {**target, "path": str(path), "position_multiple": 1., "overwrite": True})
        self.verify_file(replaced)
        return {"summary": summary, "bones": bones, "morphs": morphs, "export": exported,
                "pmx_scale_exports": scale_exports, "scale_source_snapshot_unchanged": True,
                "overwrite_rejection_preserved_file": True, "mode_and_physics_undo": True}

    def motion(self):
        target = self.target()
        baseline = self.call("mmdtool_list_animation_slots", target)["data"]
        initial_count = baseline["total"]
        a = self.call("mmdtool_import_motion", {**target, "path": self.fixture("motion_a.vmd"),
                      "position_multiple": 1., "strategy": "append"})["data"]["slot"]
        b = self.call("mmdtool_import_motion", {**target, "path": self.fixture("motion_b.vmd"),
                      "position_multiple": 1., "strategy": "append"})["data"]["slot"]
        appended = self.call("mmdtool_list_animation_slots", target)["data"]
        if a == b or appended["total"] != initial_count + 2:
            raise AssertionError("Append did not create two independent animation slots")
        self.call("mmdtool_select_animation_slot", {**target, "slot": a})
        replacement = self.call("mmdtool_import_motion", {**target, "path": self.fixture("motion_b.vmd"),
                               "position_multiple": 1., "strategy": "replace"})
        if replacement["data"]["slot"] != a:
            raise AssertionError("Replace changed the selected slot's opaque identity")
        merged = self.call("mmdtool_import_motion", {**target, "path": self.fixture("motion_a.vmd"),
                          "position_multiple": 1., "time_offset": 10, "strategy": "merge"})
        after = self.call("mmdtool_list_animation_slots", target)["data"]
        if merged["data"]["slot"] != a or after["total"] != appended["total"]:
            raise AssertionError("Merge created or replaced an animation slot")
        self.values["slots"] = {"A": a, "B": b}
        self.call("mmdtool_set_mode", {**target, "mode": "anim"})
        self.native("set_time", label="A", frame=42)
        before = self.native("snapshot")
        temporary = self.call("mmdtool_evaluate_frame", {**target, "frame": 1., "unit": "vmd_frames", "set_playhead": False})
        if not temporary["data"].get("finite") or temporary["data"].get("bone_count") != 4:
            raise AssertionError("Temporary evaluation did not return four finite bones")
        after_temporary = self.native("snapshot")
        assert_equal_numeric(before["documents"], after_temporary["documents"])
        if not after_temporary["original_active"]:
            raise AssertionError("An explicit-document API call left a test document active")
        self.call("mmdtool_evaluate_frame", {**target, "frame": 1., "unit": "vmd_frames", "set_playhead": True})
        persistent = self.native("snapshot")["documents"]["A"]
        if abs(persistent["time_seconds"] - 1. / 30.) > 1e-8:
            raise AssertionError("set_playhead=true did not set the document time")
        precision_checks = []
        for frame, unit, expected_seconds in ((.5, "vmd_frames", 1. / 60.),
                                              (-.5, "vmd_frames", -1. / 60.),
                                              (.000123456, "seconds", .000123456),
                                              (-.000123456, "seconds", -.000123456),
                                              (1. / 3., "seconds", 1. / 3.),
                                              (1.25, "document_frames", 1.25 / persistent["fps"])):
            evaluated = self.call("mmdtool_evaluate_frame", {**target, "frame": frame, "unit": unit,
                                                            "set_playhead": True})
            actual = self.native("snapshot")["documents"]["A"]
            assert_equal_numeric(actual["time_seconds"], expected_seconds, tolerance=1e-12,
                                 location="fractional document time: " + unit)
            assert_equal_numeric(evaluated["data"]["seconds"], expected_seconds, tolerance=1e-12,
                                 location="fractional evaluation response: " + unit)
            precision_checks.append({"frame": frame, "unit": unit, "expected_seconds": expected_seconds,
                                     "document_seconds": actual["time_seconds"],
                                     "response_seconds": evaluated["data"]["seconds"], "fps": actual["fps"]})
        self.call("mmdtool_evaluate_frame", {**target, "frame": 1., "unit": "vmd_frames", "set_playhead": True})
        assert_equal_numeric(self.native("snapshot")["documents"]["A"]["time_seconds"], 1. / 30.,
                             tolerance=1e-12, location="restored export playhead")
        path = self.output / "exports/motion.vmd"
        exported = self.call("mmdtool_export_motion", {**target, "path": str(path), "position_multiple": 1., "bake": False})
        self.verify_file(exported)
        parsed = fixtures.read_vmd(path)
        root_keys = [key for key in parsed["motions"] if key["name"] == "root"]
        key_by_frame = {key["frame"]: key for key in root_keys}
        if not {0, 2, 10, 12}.issubset(key_by_frame):
            raise AssertionError("Append/replace/merge lost independent VMD frame ranges")
        if abs(key_by_frame[2]["translation"][0] - 3.) > 1e-4 or abs(key_by_frame[12]["translation"][0] - 1.) > 1e-4:
            raise AssertionError("Replace/merge changed the fixture's actual root motion")
        baked_before = self.native("snapshot")
        baked = self.call("mmdtool_export_motion", {**target, "path": str(self.output / "exports/motion-baked.vmd"),
                          "position_multiple": 1., "bake": True, "model_info": False})
        self.verify_file(baked)
        assert_equal_numeric(baked_before["documents"], self.native("snapshot")["documents"])
        if fixtures.read_vmd(baked["data"]["path"])["iks"]:
            raise AssertionError("model_info=false export still included IK/visibility metadata")
        matched = self.call("mmdtool_import_motion", {**target, "path": self.fixture("motion_a.vmd"),
                            "position_multiple": 1., "strategy": "append"})
        if matched["data"]["unmatched_bones"] or matched["data"]["unmatched_morphs"]:
            raise AssertionError("Matched motion names were incorrectly reported as absent")
        missing_names = self.output / "inputs/unmatched-names.vmd"
        data = Path(self.fixture("motion_a.vmd")).read_bytes()
        data = data.replace(fixtures.fixed("root", 15), fixtures.fixed("absent_bone", 15))
        data = data.replace(fixtures.fixed("tint", 15), fixtures.fixed("absent_morph", 15))
        missing_names.write_bytes(data)
        unmatched = self.call("mmdtool_import_motion", {**target, "path": str(missing_names),
                              "position_multiple": 1., "strategy": "append"})
        if set(unmatched["data"]["unmatched_bones"]) != {"absent_bone"} or set(
                unmatched["data"]["unmatched_morphs"]) != {"absent_morph"}:
            raise AssertionError("Missing VMD names did not produce the exact structured report")
        return {"baseline_slots": baseline, "appended_slots": appended, "merged_slots": after,
                "temporary_evaluation": temporary, "source_state_restored": True,
                "time_precision_checks": precision_checks,
                "raw_export": exported, "baked_export": baked,
                "matched_name_report": matched, "unmatched_name_report": unmatched,
                "unmatched_input": file_identity(missing_names)}

    def camera(self):
        document = self.values["documents"]["A"]
        imported = self.call("mmdtool_import_camera", {"document": document, "path": self.fixture("camera.vmd"),
                             "position_multiple": 1.})
        handle = imported["data"]["camera"]
        self.values["camera"] = handle
        before = self.native("snapshot")
        path = self.output / "exports/camera.vmd"
        exported = self.call("mmdtool_export_camera", {"document": document, "camera": handle,
                             "path": str(path), "position_multiple": 1., "bake": False})
        self.verify_file(exported)
        parsed = fixtures.read_vmd(path)
        # Camera import samples the VMD animation into linear C4D tracks at
        # every 30 fps frame. Non-baked export preserves those existing keys;
        # it does not reconstruct the two sparse input VMD keys.
        if len(parsed["cameras"]) != 3 or {key["frame"] for key in parsed["cameras"]} != {0, 1, 2}:
            raise AssertionError("Non-baked camera export lost the imported C4D frame keys")
        for key in parsed["cameras"]:
            assert_equal_numeric(key["position"], [float(key["frame"]), 1., 2.],
                                 tolerance=1e-5, location="camera interpolated position")
            assert_equal_numeric(key["distance"], -4., tolerance=1e-5, location="camera distance")
        if any(key["angle"] != 45 for key in parsed["cameras"]):
            raise AssertionError("Camera VMD angle/FOV conversion regressed")
        assert_equal_numeric(before["documents"], self.native("snapshot")["documents"])
        identity = file_identity(path)
        self.call("mmdtool_export_camera", {"document": document, "camera": handle,
                  "path": str(path), "position_multiple": 1., "bake": False}, expected=False)
        if file_identity(path) != identity:
            raise AssertionError("Camera overwrite rejection changed the destination")
        baked = self.call("mmdtool_export_camera", {"document": document, "camera": handle,
                          "path": str(self.output / "exports/camera-baked-offset.vmd"),
                          "position_multiple": 2., "time_offset": 7, "bake": True, "rotation": "euler"})
        self.verify_file(baked)
        baked_keys = fixtures.read_vmd(baked["data"]["path"])["cameras"]
        if len(baked_keys) != 3 or {key["frame"] for key in baked_keys} != {7, 8, 9}:
            raise AssertionError("Baked camera export changed frame coverage or ignored the VMD offset")
        for key in baked_keys:
            assert_equal_numeric(key["position"], [(key["frame"] - 7.) / 2., .5, 1.],
                                 tolerance=1e-5, location="baked camera position scaling")
            assert_equal_numeric(key["distance"], -2., tolerance=1e-5, location="baked camera distance scaling")
            if key["angle"] != 45:
                raise AssertionError("Baked camera export changed the fixture's FOV")
        assert_equal_numeric(before["documents"], self.native("snapshot")["documents"])
        return {"import": imported, "export": exported, "baked_export": baked,
                "import_samples_all_vmd_frames": True, "source_state_restored": True}

    def invalid(self):
        target = self.target()
        before = self.native("snapshot")
        stdio = StdioClient(self.endpoint, self.token_file, self.timeout)
        cases = [("mmdtool_import_motion", {**target, "path": self.fixture("motion_a.vmd"), "time_offset": 1.5}),
                 ("mmdtool_import_pmx", {"document": target["document"], "path": "relative.pmx"}),
                 ("mmdtool_evaluate_frame", {**target, "frame": 1., "unit": "frames"}),
                 ("mmdtool_list_models", {"document": target["document"], "limit": 257}),
                 ("mmdtool_set_mode", {**target, "mode": "anim", "code": "raise RuntimeError('client code')"})]
        rejections = []
        try:
            for name, arguments in cases:
                response = stdio.request("tools/call", {"name": name, "arguments": arguments})
                self.record("stdio", {"name": name, "arguments": arguments}, response)
                if response.get("error", {}).get("code") != -32602:
                    raise AssertionError("Invalid typed input reached a production operation")
                rejections.append({"name": name, "error": response["error"]})
            response = stdio.malformed_json(b'{"jsonrpc":"2.0","id":999,"method":"tools/call","params":{"name":"mmdtool_set_morph_strength","arguments":{"strength":NaN}}}')
            self.record("stdio", {"fixture": "literal nonfinite JSON token"}, response)
            if response.get("error", {}).get("code") != -32700:
                raise AssertionError("Non-finite JSON was accepted by the real stdio process")
        finally:
            stdio.close()
        # Bypass adapter input validation to prove native admission, while still
        # using the fixed production host bridge rather than arbitrary Python.
        self.call("mmdtool_import_pmx", {"document": target["document"], "path": self.fixture("model.pmx"),
                  "position_multiple": 0.}, expected=False, validate_input=False)
        self.call("mmdtool_import_motion", {**target, "path": self.fixture("motion_a.vmd"),
                  "time_offset": 1.5}, expected=False, validate_input=False)
        precision_rejection = self.call("mmdtool_evaluate_frame", {**target, "frame": 1e-13,
                                       "unit": "seconds", "set_playhead": True}, expected=False)
        if precision_rejection["code"] != "invalid_time_precision":
            raise AssertionError("Unrepresentable nonzero time was not explicitly rejected")
        self.call("mmdtool_import_pmx", {"document": target["document"], "path": self.fixture("motion_a.vmd")}, expected=False)
        invalid_files = []
        for name, options, extension, valid_input in (
                ("mmdtool_import_pmx", {"document": target["document"]}, "pmx", "model.pmx"),
                ("mmdtool_import_motion", target, "vmd", "motion_a.vmd"),
                ("mmdtool_import_camera", {"document": target["document"]}, "vmd", "camera.vmd")):
            for fault in ("missing", "truncated", "wrong-format"):
                path = self.output / "inputs" / (name + "-" + fault + "." + extension)
                if fault == "truncated":
                    path.write_bytes(Path(self.fixture(valid_input)).read_bytes()[:20])
                elif fault == "wrong-format":
                    path.write_bytes(b"invalid model or motion format")
                result = self.call(name, {**options, "path": str(path)}, expected=False)
                invalid_files.append({"tool": name, "fault": fault, "result": result})
                assert_equal_numeric(before["documents"], self.native("snapshot")["documents"])
        self.call("mmdtool_select_animation_slot", {**target, "slot": "not-a-live-slot"}, expected=False)
        self.call("mmdtool_set_morph_strength", {**target, "morph_handle": "not-a-live-morph", "strength": .5}, expected=False)
        write_failures = self.export_write_failures()
        assert_equal_numeric(before["documents"], self.native("snapshot")["documents"])
        return {"stdio_rejections": rejections, "nonfinite_json_rejected": True,
                "native_admission_rejected_invalid_values": True, "export_write_failures": write_failures,
                "invalid_import_files": invalid_files,
                "scene_unchanged": True}

    def export_write_failures(self):
        """Exercise actual staging/commit errors using only this run's files."""
        session = self.call("mmdtool_capabilities")["data"]["host_session"]
        targets = [("mmdtool_export_pmx", self.target(), "pmx"),
                   ("mmdtool_export_motion", {**self.target(), "bake": False}, "vmd"),
                   ("mmdtool_export_camera", {"document": self.values["documents"]["A"],
                                              "camera": self.values["camera"], "bake": False}, "vmd")]
        before = self.native("snapshot")
        records = []
        for tool, target, suffix in targets:
            kinds = ["missing_parent", "directory_destination", "staging_collision"]
            if os.name == "nt": kinds.append("readonly_destination")
            for kind in kinds:
                case = self.output / "write-failures" / tool / kind
                case.mkdir(parents=True, exist_ok=False)
                operation_id = str(uuid.uuid4())
                path = case / ("destination." + suffix)
                protected = None
                original_mode = None
                if kind == "missing_parent":
                    path = case / "missing" / path.name
                elif kind == "directory_destination":
                    path.mkdir()
                    protected = path / "preserved.bin"
                elif kind == "staging_collision":
                    protected = case / (".cmt-" + session + "-" + operation_id + ".tmp")
                else:
                    protected = path
                if protected:
                    protected.write_bytes((tool + ": previous private fixture").encode())
                    previous = file_identity(protected)
                if kind == "readonly_destination":
                    original_mode = stat.S_IMODE(path.stat().st_mode)
                    os.chmod(path, stat.S_IREAD)
                    if not path.stat().st_file_attributes & stat.FILE_ATTRIBUTE_READONLY:
                        raise AssertionError("Windows readonly failure fixture was not activated")
                received = False
                try:
                    arguments = {**target, "path": str(path), "position_multiple": 1., "overwrite": True}
                    result = self.call(tool, arguments, expected=False, operation_id=operation_id,
                                       expected_codes={"write_failed"})
                    received = True
                    status = self.call("mmdtool_operation_status", {"query_operation_id": operation_id})["data"]["operation"]
                    if (status["state"] != "failed" or status["success"] or status["code"] != "write_failed"
                            or status["operation_id"] != operation_id):
                        raise AssertionError("A failed export was not retained as the same finished operation")
                    if protected and file_identity(protected) != previous:
                        raise AssertionError("Failed export changed the pre-existing destination/staging fixture")
                    leftover = sorted(item.name for item in case.glob(".cmt-*.tmp") if item != protected)
                    if leftover: raise AssertionError("Failed export leaked staging files: " + str(leftover))
                    if kind in ("missing_parent", "staging_collision") and path.exists():
                        raise AssertionError("Failed export unexpectedly created its final destination")
                    records.append({"tool": tool, "case": kind, "result": result, "status": status,
                                    "preserved_file": previous if protected else None, "staging_leaks": leftover})
                finally:
                    # Keep the failure fixture in place if host execution remains
                    # unknown; do not enable a delayed overwrite by unlocking it.
                    if original_mode is not None and (received or not self.state.get("pending_operation")):
                        os.chmod(path, original_mode)
        assert_equal_numeric(before["documents"], self.native("snapshot")["documents"])
        return {"cases": records, "source_snapshot_unchanged": True,
                "scope": "real missing-parent/staging-collision/final-commit failures; not a disk-full simulation"}

    def lifecycle(self):
        source_document = self.values["documents"]["A"]
        source_model = self.values["models"]["A1"]
        before_clone = self.native("snapshot")["documents"]["A"]
        self.native("clone", label="A")
        clone_document = self.documents("C")
        if clone_document in self.values["documents"].values():
            raise AssertionError("A document clone shared its source document's handle")
        self.values["documents"]["C"] = clone_document
        models = self.call("mmdtool_list_models", {"document": clone_document})["data"]["models"]
        if {item["handle"] for item in models}.intersection(self.values["models"].values()):
            raise AssertionError("Cloned models shared source opaque handles")
        self.call("mmdtool_inspect_model", {"document": clone_document, "model": source_model}, expected=False)
        clone_target = {"document": clone_document, "model": models[0]["handle"]}
        self.call("mmdtool_set_mode", {**clone_target, "mode": "anim"})
        self.call("mmdtool_set_morph_strength", {**clone_target, "morph_handle": self.values["morph"], "strength": .5}, expected=False)
        assert_equal_numeric(before_clone, self.native("snapshot")["documents"]["A"])
        removed = self.values["models"]["B1"]
        self.native("delete_model", label="B")
        self.call("mmdtool_inspect_model", {"document": self.values["documents"]["B"], "model": removed}, expected=False)
        scene = self.output / "owned-scene-reopened.c4d"
        reopened = self.native("save_reopen", label="A", path=str(scene))
        self.call("mmdtool_list_models", {"document": source_document}, expected=False)
        new_document = self.documents("A")
        if new_document == source_document:
            raise AssertionError("Closing/reopening a native scene revived an expired document handle")
        self.values["documents"]["A"] = new_document
        self.call("mmdtool_inspect_model", {"document": new_document, "model": source_model}, expected=False)
        fresh = self.call("mmdtool_list_models", {"document": new_document})["data"]["models"]
        if len(fresh) != 2 or {item["handle"] for item in fresh}.intersection(self.values["models"].values()):
            raise AssertionError("Reopened models revived stale handles or lost scene content")
        self.call("mmdtool_set_morph_strength", {"document": new_document, "model": fresh[0]["handle"],
                  "morph_handle": self.values["morph"], "strength": .5}, expected=False)
        self.call("mmdtool_export_camera", {"document": new_document, "camera": self.values["camera"],
                  "path": str(self.output / "exports/stale-camera.vmd")}, expected=False)
        return {"clone_document": clone_document, "clone_models": models,
                "reopened_document": new_document, "reopened_models": fresh, "scene": file_identity(scene),
                "saved_snapshot": reopened, "deleted_and_closed_handles_rejected": True}

    def cleanup(self):
        self.state["terminated"] = True
        self.write_receipt()
        # A cleanup retry must resolve a timed-out production request. Missing
        # records or running states are not proof that scene work ended.
        pending = self.state.get("pending_operation")
        if pending and not operation_may_mutate(pending.get("tool_name", pending.get("name"))):
            # Older runners tracked readonly negative status tests as pending.
            # They cannot leave a scene mutation running; preserve the failure
            # record and still require the private main-thread checkpoint.
            self.state.pop("pending_operation", None)
            pending = None
        if pending:
            self.ensure_host()
            status = self.host.call_production("mmdtool_operation_status", {
                "query_operation_id": pending["operation_id"]}, str(uuid.uuid4()))
            self.record("http_cleanup_status", pending, status)
            validate(status, TOOL_BY_NAME["mmdtool_operation_status"]["outputSchema"], "operation_status")
            original = status.get("data", {}).get("operation", {})
            if not status.get("success") or original.get("state") in (None, "queued", "running"):
                raise CleanupPending("The pending production operation has not reached a confirmed terminal state")
            self.state.pop("pending_operation", None)
        checkpoint = self.native("cleanup_status")
        if not checkpoint.get("module_exists") or not checkpoint.get("main_thread_checkpoint"):
            raise CleanupPending("The run's private state or main-thread execution checkpoint is unavailable")
        if not checkpoint.get("original_live"):
            raise CleanupPending("The original document is no longer live; no replacement document will be treated as restored")
        self.state.pop("pending_helper", None)
        self.state["cleanup_pending"] = False
        # Older staged runs may have failed before automatic cleanup existed.
        for stage, record in self.state["stages"].items():
            if stage != "cleanup" and record.get("status") == "failed" and (
                    not record.get("failure_snapshot") or record.get("failure_snapshot_available") is False):
                self.capture_failure(stage)
                if self.state["cleanup_pending"]:
                    raise CleanupPending("Could not safely capture the failed scene before cleanup")
        result = self.native("cleanup")
        self.state["cleanup_result"] = result
        self.state["cleanup_pending"] = result.get("cleanup_pending", True)
        if self.state["cleanup_pending"] or not result["original_document_restored"]:
            raise CleanupPending("Owned scene cleanup is incomplete; retained references can be retried")
        return result

    def finish(self, *, uncertain=False):
        """Terminate without replaying a mutation or concealing its failed stage."""
        self.state["terminated"] = True
        if uncertain or self.state["cleanup_pending"]:
            self.state["cleanup_pending"] = True
            self.write_receipt()
            return
        if self.state["stages"].get("cleanup", {}).get("status") == "passed":
            self.write_receipt()
            return
        started = utc_now()
        try:
            evidence = self.cleanup()
            self.state["stages"]["cleanup"] = {"status": "passed", "started_utc": started,
                                               "completed_utc": utc_now(), "native_executed": True,
                                               "evidence": evidence}
        except BaseException as error:
            self.state["cleanup_pending"] = True
            self.state["cleanup_error_type"] = type(error).__name__
            if not isinstance(error, Exception):
                raise
        finally:
            self.write_receipt()

    def capture_failure(self, name, *, uncertain=False):
        path = self.output / ("failure-" + name + "-snapshot.json")
        if uncertain:
            snapshot = {"available": False, "reason": "Execution is uncertain; no concurrent host snapshot was requested"}
        else:
            try:
                snapshot = self.native("snapshot")
            except Exception as error:
                snapshot = {"available": False, "error_type": type(error).__name__}
                if uncertain_execution(error):
                    self.state["cleanup_pending"] = True
        atomic_json(path, snapshot)
        self.state["stages"][name]["failure_snapshot"] = str(path)
        self.state["stages"][name]["failure_snapshot_available"] = snapshot.get("available", True)
        self.write_receipt()

    @staticmethod
    def verify_file(result):
        data = result["data"]
        actual = file_identity(data["path"])
        if actual["sha256"] != data.get("sha256") or actual["bytes"] != data.get("size", data.get("bytes")):
            raise AssertionError("Export's reported file identity differs from the actual destination")

    def write_receipt(self):
        passed = all(self.state["stages"].get(stage, {}).get("status") == "passed" for stage in STAGES)
        dependencies_required = "dependency_provenance" in self.manifest
        dependencies_verified = self.state.get("dependency_identity_verified", False)
        self.state["acceptance_eligible"] = (passed and self.state["native_executed"] and self.state["original_document_restored"]
                                             and (not dependencies_required or dependencies_verified))
        atomic_json(self.output / "state.json", self.state)
        receipt = {**self.state, "updated_utc": utc_now(),
                   "status": "cleanup_pending" if self.state["cleanup_pending"] else "passed" if self.state["acceptance_eligible"] else "incomplete",
                   "manifest": str(self.output / "manifest.json"), "transcript": str(self.output / "transcript.jsonl"),
                   "acceptance_scope": "normal Release production native API, actual HTTP and actual stdio transport",
                   "image_render_accepted": False, "performance_accepted": False,
                   "other_sdks_accepted": False, "remote_ci_accepted": False}
        receipt["dependency_identity_status"] = ("verified_snapshot" if dependencies_verified else
                                                   "unknown" if dependencies_required else "legacy_manifest_without_dependency_identity")
        atomic_json(self.output / "receipt.json", receipt)

    def stage(self, name):
        if name not in STAGES:
            raise ValueError("Unknown native validation stage")
        if self.state["terminated"] and name != "cleanup":
            raise ValueError("This run is terminated; use a new prepared run instead of replaying mutations")
        if self.state["stages"].get(name, {}).get("status") == "passed":
            if name == "cleanup" and not self.state["cleanup_pending"]:
                return self.state["stages"][name]
            raise ValueError("Stage already passed; mutations are not replayed automatically")
        if name != "cleanup":
            prerequisites = STAGES[:STAGES.index(name)]
            if any(self.state["stages"].get(previous, {}).get("status") != "passed" for previous in prerequisites):
                raise ValueError("Earlier stages must pass before this stage")
        self.stage_name = name
        started = utc_now()
        try:
            evidence = getattr(self, name)()
            self.state["stages"][name] = {"status": "passed", "started_utc": started,
                                          "completed_utc": utc_now(), "native_executed": True, "evidence": evidence}
        except BaseException as error:
            self.state["stages"][name] = {"status": "failed", "started_utc": started,
                                          "completed_utc": utc_now(), "error_type": type(error).__name__,
                                          "message": str(error), "native_executed": name != "setup" or self.state["native_executed"]}
            # Save the failed stage and available scene evidence before cleanup.
            # Timeout/connection loss must not issue another scene mutation.
            self.write_receipt()
            if name == "cleanup":
                self.state["terminated"] = True
                self.state["cleanup_pending"] = True
            elif uncertain_execution(error) or self.state.get("pending_helper") or self.state.get("pending_operation"):
                self.capture_failure(name, uncertain=True)
                self.finish(uncertain=True)
            else:
                self.capture_failure(name)
                self.finish(uncertain=self.state["cleanup_pending"])
            raise
        finally:
            if name != "cleanup" and not self.state["terminated"]:
                try:
                    self.native("restore")
                except Exception as restore_error:
                    self.state["original_document_restored"] = False
                    self.state["restoration_error_type"] = type(restore_error).__name__
                    self.finish(uncertain=True)
                    raise CleanupPending("Original document restoration is uncertain; scene cleanup remains pending") from restore_error
            self.write_receipt()
        return self.state["stages"][name]


def assert_pmx_length_ratio(baseline, actual, ratio):
    """Compare serialized lengths and independently require all other fields unchanged."""
    expected = copy.deepcopy(baseline)
    def scaled(vector):
        return tuple(value * ratio for value in vector)
    for vertex in expected["vertex_data"]:
        vertex["position"] = scaled(vertex["position"])
        if "sdef" in vertex:
            vertex["sdef"] = [scaled(vector) for vector in vertex["sdef"]]
    for bone in expected["bones"]:
        bone["position"] = scaled(bone["position"])
        if not bone["flags"] & 1:
            bone["tail"] = scaled(bone["tail"])
    for morph in expected["morphs"]:
        for offset in morph["offsets"]:
            if morph["kind"] in (1, 2): offset["position"] = scaled(offset["position"])
            if morph["kind"] == 10: offset["translate"] = scaled(offset["translate"])
    for rigid in expected["rigidbodies"]:
        for field in ("size", "position"): rigid[field] = scaled(rigid[field])
    for joint in expected["joints"]:
        for field in ("position", "translate_lower", "translate_upper"): joint[field] = scaled(joint[field])
    assert_equal_numeric(expected, actual, tolerance=1e-6, location="PMX export scale")


def assert_equal_numeric(left, right, *, tolerance=1e-5, location="snapshot"):
    if isinstance(left, dict) and isinstance(right, dict):
        if left.keys() != right.keys():
            raise AssertionError(location + " keys changed")
        for key in left:
            assert_equal_numeric(left[key], right[key], tolerance=tolerance, location=location + "." + key)
    elif isinstance(left, (list, tuple)) and isinstance(right, (list, tuple)):
        if len(left) != len(right):
            raise AssertionError(location + " length changed")
        for index, (a, b) in enumerate(zip(left, right)):
            assert_equal_numeric(a, b, tolerance=tolerance, location=f"{location}[{index}]")
    elif isinstance(left, (int, float)) and not isinstance(left, bool) and isinstance(right, (int, float)) and not isinstance(right, bool):
        if not math.isfinite(left) or not math.isfinite(right) or abs(left - right) > tolerance:
            raise AssertionError(location + " numeric state changed")
    elif left != right:
        raise AssertionError(location + " state changed")


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--stage", choices=("prepare", "all", *STAGES), required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--expected-binary")
    parser.add_argument("--build-cache")
    parser.add_argument("--endpoint", default="http://127.0.0.1:5556/mcp")
    parser.add_argument("--token-file", default=os.environ.get("CMT_MCP_TOKEN_FILE"))
    parser.add_argument("--timeout", type=float, default=180.)
    args = parser.parse_args(argv)
    if not math.isfinite(args.timeout) or not 1 <= args.timeout <= 600:
        parser.error("--timeout must be finite and between 1 and 600")
    if args.stage == "prepare":
        manifest = prepare(args.output, args.expected_binary, args.build_cache)
        print(json.dumps({"status": "prepared", "run_id": manifest["run_id"],
                          "manifest": str(Path(args.output).resolve() / "manifest.json")}, ensure_ascii=False))
        return 0
    if not args.token_file:
        parser.error("Native stages require --token-file or CMT_MCP_TOKEN_FILE")
    run = ValidationRun(args.output, args.endpoint, args.token_file, args.timeout)
    try:
        for stage in STAGES if args.stage == "all" else (args.stage,):
            try:
                result = run.stage(stage)
            except Exception as error:
                print(json.dumps({"stage": stage, "status": "failed", "error_type": type(error).__name__,
                                  "message": str(error), "receipt": str(run.output / "receipt.json")}, ensure_ascii=False))
                return 1
            print(json.dumps({"stage": stage, "status": result["status"],
                              "acceptance_eligible": run.state["acceptance_eligible"]}, ensure_ascii=False), flush=True)
    finally:
        if args.stage == "all":
            run.finish()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
