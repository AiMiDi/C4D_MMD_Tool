"""Prepare deterministic inputs outside C4D, or run native cases in Script Manager.

Usage outside C4D:
  python scripts/c4d_runtime_regression.py --prepare --output S:/tmp/cmt-runtime --binary <xdl64>

Inside C4D, set CMT_REGRESSION_MANIFEST to the prepared manifest.json and run this
file in Script Manager. Every case creates and closes its own test document.
"""

from pathlib import Path
import argparse
import ctypes
import datetime
import hashlib
import importlib
import json
import math
import os
import re
import subprocess
import sys
import traceback
import uuid

SCRIPT_DIRECTORY = Path(__file__).resolve().parent
sys.path.insert(0, str(SCRIPT_DIRECTORY))
# C4D's Python process persists between MCP/Script Manager runs. Reload the pure
# fixture module so a maintained helper update does not leave an older parser
# cached while this entry point is executed from current source.
import c4d_regression_fixtures
importlib.reload(c4d_regression_fixtures)
from c4d_regression_fixtures import generate, read_pmx_bones, read_pmx_morphs_and_frames, read_vmd

PROTOCOL = 1
HOOK_ID = 1057017
MODEL_ID = 1056724
BONE_MANAGER_ID = 1057944
BONE_TAG_ID = 1056720
RIGID_ID = 1056722
JOINT_ID = 1056723
CAMERA_ID = 1056978
MATERIAL_MORPH_SHADER_ID = 1068715
FIELDS = dict(zip(("protocol", "action", "path", "motion", "morph", "info", "replace", "bake",
                   "offset", "ignore_physics", "morph_index", "strength"), range(1000000, 1000012)))
SUCCESS, ERROR = 1000100, 1000101
OPERATIONS = dict(zip(("hello", "import_model", "import_motion", "export_model", "export_motion",
                      "import_camera", "export_camera", "delete_morph", "set_strength"), range(9)))
CASE_NAMES = ("import_save_reopen", "mode_bind_restore", "hierarchy_edit_and_selectors",
              "hierarchy_export_and_anim", "animation_slots_and_options", "physics_toggle_and_reopen",
              "material_morph_zero_and_delete", "motion_roundtrip_and_bake", "camera_export_and_failures")


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def utc_now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def same_document(left, right):
    if left is right:
        return True
    try:
        return left == right
    except ReferenceError:
        return False


def document_is_live(c4d, candidate):
    if candidate is None:
        return False
    document = c4d.documents.GetFirstDocument()
    while document is not None:
        if same_document(document, candidate):
            return True
        document = document.GetNext()
    return False


def restore_active_document(c4d, original):
    """Restore only a document which is still in C4D's live document list.

    Inserting the first test document can close C4D's untouched blank document.
    Its former Python wrapper then raises ReferenceError on native access.
    """
    if original is None:
        return False
    document = c4d.documents.GetFirstDocument()
    while document is not None:
        if same_document(document, original):
            c4d.documents.SetActiveDocument(document)
            return True
        document = document.GetNext()
    return False


def load_resource_ids(repository):
    """Resolve enum values from the maintained resources instead of freezing copies."""
    result = {}
    for name in ("OMMDModelManager.h", "TMMDBone.h", "OMMDRigid.h", "OMMDJoint.h", "OMMDBoneManager.h", "OMMDCamera.h"):
        content = (Path(repository) / "res/S24_up/description" / name).read_text(encoding="utf-8-sig")
        content = re.sub(r"/\*.*?\*/|//[^\n]*", "", content, flags=re.S)
        value = -1
        for item in re.search(r"enum\s*\{(.*?)\}", content, re.S).group(1).split(","):
            item = item.strip()
            if not item:
                continue
            parts = item.split("=", 1)
            key = parts[0].strip()
            value = int(parts[1].strip(), 0) if len(parts) > 1 else value + 1
            result[key] = value
    return result


def prepare(output, sdk="sdk_2026", binary=None):
    repository = SCRIPT_DIRECTORY.parent
    output = Path(output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    revision = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=repository, text=True).strip()
    dirty = subprocess.check_output(["git", "status", "--porcelain"], cwd=repository, text=True).splitlines()
    source_hash = hashlib.sha256()
    for directory in ("source", "res/S24_up"):
        for path in sorted((repository / directory).rglob("*")):
            if path.is_file():
                source_hash.update(path.relative_to(repository).as_posix().encode("utf-8"))
                source_hash.update(path.read_bytes())
    manifest = {"schema_version": 1, "created_utc": utc_now(), "repository": str(repository),
                "revision": revision, "working_tree": dirty, "source_sha256": source_hash.hexdigest(),
                "sdk": sdk, "fixtures": generate(output / "inputs"), "resource_ids": load_resource_ids(repository),
                "output": str(output), "plugin_binary": None, "cases": list(CASE_NAMES)}
    if binary:
        binary = Path(binary).resolve()
        if not binary.is_file():
            raise FileNotFoundError(binary)
        manifest["plugin_binary"] = {"path": str(binary), "sha256": sha256(binary), "bytes": binary.stat().st_size}
    path = output / "manifest.json"
    path.write_text(json.dumps(manifest, indent=2, ensure_ascii=False), encoding="utf-8")
    pending = {"schema_version": 1, "status": "pending_native_runtime", "manifest": str(path),
               "native_executed": False, "acceptance_eligible": False,
               "reason": "Run this manifest inside Cinema 4D with CMT_ENABLE_RUNTIME_REGRESSION=ON",
               "cases": [{"name": name, "status": "pending", "native_executed": False} for name in CASE_NAMES]}
    (output / "receipt.json").write_text(json.dumps(pending, indent=2), encoding="utf-8")
    return path


def loaded_plugin_binary():
    """Read the loaded module path in this process; never infer it from a build folder."""
    if sys.platform != "win32":
        return None
    from ctypes import wintypes
    kernel = ctypes.WinDLL("kernel32", use_last_error=True)
    psapi = ctypes.WinDLL("psapi", use_last_error=True)
    kernel.GetCurrentProcess.restype = wintypes.HANDLE
    process = kernel.GetCurrentProcess()
    modules = (wintypes.HMODULE * 4096)()
    needed = wintypes.DWORD()
    psapi.EnumProcessModulesEx.argtypes = (wintypes.HANDLE, ctypes.POINTER(wintypes.HMODULE), wintypes.DWORD,
                                          ctypes.POINTER(wintypes.DWORD), wintypes.DWORD)
    psapi.GetModuleFileNameExW.argtypes = (wintypes.HANDLE, wintypes.HMODULE, wintypes.LPWSTR, wintypes.DWORD)
    if not psapi.EnumProcessModulesEx(process, modules, ctypes.sizeof(modules), ctypes.byref(needed), 3):
        raise OSError(ctypes.get_last_error(), "Could not enumerate C4D loaded modules")
    for module in modules[:min(len(modules), needed.value // ctypes.sizeof(wintypes.HMODULE))]:
        buffer = ctypes.create_unicode_buffer(32768)
        if psapi.GetModuleFileNameExW(process, module, buffer, len(buffer)):
            path = Path(buffer.value)
            if path.suffix.lower() == ".xdl64" and path.name.lower().startswith("mmdtool"):
                return {"path": str(path), "sha256": sha256(path)}
    return None


class Suite:
    def __init__(self, c4d, manifest):
        self.c4d, self.manifest = c4d, manifest
        self.ids = manifest["resource_ids"]
        self.output = Path(manifest["output"])
        self.doc = self.model = None
        self.original_document = c4d.documents.GetActiveDocument()
        self.document_owner_run_id = str(uuid.uuid4())
        self._owned_documents = []
        self._cleanup_failed = False

    def assert_true(self, condition, message):
        if not condition:
            raise AssertionError(message)

    def register_document(self, document, label):
        """Claim only an explicitly created, loaded or cloned private document.

        Call before InsertBaseDocument. An existing live document cannot be
        adopted by assigning suite.doc or by matching its name.
        """
        if document is None:
            raise ValueError("Cannot register a missing test document")
        for entry in self._owned_documents:
            if same_document(entry["document"], document):
                return document
        if same_document(document, self.original_document) or document_is_live(self.c4d, document):
            raise ValueError("An existing live/user document cannot become test-owned")
        self._owned_documents.append({"document": document, "label": str(label)})
        return document

    @property
    def owned_documents(self):
        return tuple(entry["document"] for entry in self._owned_documents)

    def new_document(self, label):
        if self._cleanup_failed:
            raise RuntimeError("Retry cleanup before creating another owned document")
        document = self.register_document(self.c4d.documents.BaseDocument(), label)
        self.doc, self.model = document, None
        name = "CMT test " + self.document_owner_run_id[:8] + " - " + str(label)
        document.SetName(name)
        document.SetDocumentName(name + ".c4d")
        document.SetFps(30)
        self.c4d.documents.InsertBaseDocument(document)
        self.c4d.documents.SetActiveDocument(document)
        return document

    def save_failure_scenes(self, case_name):
        evidence = []
        safe_case_name = re.sub(r"[^A-Za-z0-9_-]", "_", str(case_name))[:64]
        for index, entry in enumerate(self._owned_documents):
            document = entry["document"]
            path = self.output / ("failed-" + safe_case_name + "-" + str(index) + ".c4d")
            item = {"label": entry["label"], "path": str(path)}
            try:
                if same_document(document, self.original_document) or not document_is_live(self.c4d, document):
                    continue
                saved = self.c4d.documents.SaveDocument(
                    document, str(path), self.c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, self.c4d.FORMAT_C4DEXPORT)
                item["saved"] = bool(saved and path.is_file())
            except Exception as error:
                item.update(saved=False, error_type=type(error).__name__, error=str(error))
            evidence.append(item)
        return evidence

    def close(self, keep_documents=()):
        """Restore the user document and close this Suite's registered docs.

        Failed closes retain their references for a later retry. keep_documents
        is used only to retain a newly loaded private doc during replacement.
        Cleanup reports do not replace a case's original failure.
        """
        result = {"owner_run_id": self.document_owner_run_id, "closed_owned_documents": [],
                  "released_nonlive_documents": [], "remaining_owned_documents": [], "errors": []}
        try:
            restore_active_document(self.c4d, self.original_document)
        except Exception as error:
            result["errors"].append({"label": "original", "stage": "restore_before_cleanup", "error": str(error)})
        remaining = []
        for entry in self._owned_documents:
            document, label = entry["document"], entry["label"]
            if any(same_document(document, kept) for kept in keep_documents):
                remaining.append(entry)
                continue
            if same_document(document, self.original_document):
                remaining.append(entry)
                result["errors"].append({"label": label, "error": "Refused to close the original user document"})
                continue
            try:
                if not document_is_live(self.c4d, document):
                    result["released_nonlive_documents"].append(label)
                    continue
                self.c4d.documents.KillDocument(document)
                if document_is_live(self.c4d, document):
                    raise RuntimeError("The owned document remained open after KillDocument")
            except Exception as error:
                remaining.append(entry)
                result["errors"].append({"label": label, "error_type": type(error).__name__, "error": str(error)})
            else:
                result["closed_owned_documents"].append(label)
        self._owned_documents = remaining
        result["remaining_owned_documents"] = [entry["label"] for entry in remaining]
        try:
            result["original_document_restored"] = restore_active_document(self.c4d, self.original_document)
        except Exception as error:
            result["original_document_restored"] = False
            result["errors"].append({"label": "original", "stage": "restore_after_cleanup", "error": str(error)})
        if self.doc is not None and not any(same_document(self.doc, entry["document"]) for entry in remaining):
            self.doc = self.model = None
        self._cleanup_failed = bool(result["errors"])
        return result

    def new_model(self, fixture_name="model.pmx"):
        cleanup = self.close()
        if cleanup["errors"]:
            raise RuntimeError("Previous owned documents could not be closed")
        self.new_document(fixture_name)
        self.call("hello")
        self.call("import_model", self.fixture(fixture_name))
        self.model = self.doc.GetActiveObject()
        self.assert_true(self.model and self.model.GetType() == MODEL_ID, "PMX import did not select model")
        self.model[self.ids["MODEL_PHYSICS_ENABLED"]] = False
        self.evaluate(0)
        return self.model

    def fixture(self, name):
        fixture = self.manifest["fixtures"][name]
        self.assert_true(sha256(fixture["path"]) == fixture["sha256"], "Input identity changed: " + name)
        return fixture["path"]

    def call(self, action, path="", expected=True, **settings):
        hook = self.doc.FindSceneHook(HOOK_ID)
        self.assert_true(hook is not None, "CMT scene hook not loaded")
        defaults = {"protocol": PROTOCOL, "action": OPERATIONS[action], "path": str(path),
                    "motion": True, "morph": True, "info": True, "replace": True, "bake": False,
                    "offset": 0., "ignore_physics": False, "morph_index": 0, "strength": 0.}
        defaults.update(settings)
        for key, value in defaults.items():
            hook[FIELDS[key]] = value
        hook[SUCCESS] = False
        hook[ERROR] = "No response; rebuild with CMT_ENABLE_RUNTIME_REGRESSION=ON"
        hook.Message(HOOK_ID)
        self.assert_true(bool(hook[SUCCESS]) == expected, action + ": " + str(hook[ERROR]))
        return hook

    def evaluate(self, frame):
        self.doc.SetTime(self.c4d.BaseTime(frame, 30))
        self.doc.ExecutePasses(None, True, True, True, self.c4d.BUILDFLAGS_NONE)
        self.doc.ExecutePasses(None, True, True, True, self.c4d.BUILDFLAGS_NONE)

    def walk(self, root):
        while root:
            yield root
            yield from self.walk(root.GetDown())
            root = root.GetNext()

    def nodes(self, plugin_id):
        return [node for node in self.walk(self.doc.GetFirstObject()) if node.GetType() == plugin_id]

    def bones(self):
        managers = self.nodes(BONE_MANAGER_ID)
        self.assert_true(len(managers) == 1, "Expected one bone manager")
        return [node for node in self.walk(managers[0].GetDown()) if node.GetTag(BONE_TAG_ID)]

    def bone(self, name):
        return next(node for node in self.bones() if node.GetTag(BONE_TAG_ID)[self.ids["PMX_BONE_NAME_LOCAL"]] == name)

    def vector(self, value):
        return [float(value.x), float(value.y), float(value.z)]

    def pose(self):
        result = {}
        for bone in self.bones():
            values = self.vector(bone.GetRelPos()) + self.vector(bone.GetRelRot())
            self.assert_true(all(math.isfinite(value) for value in values), "Non-finite bone transform")
            result[bone.GetName()] = values
        return result

    def near(self, left, right, tolerance=1e-4):
        return len(left) == len(right) and all(abs(a - b) <= tolerance for a, b in zip(left, right))

    def material_color(self):
        material = self.doc.GetFirstMaterial()
        self.assert_true(material is not None, "Missing imported material")
        shader = material[self.c4d.MATERIAL_COLOR_SHADER]
        if shader is not None and shader.GetType() == MATERIAL_MORPH_SHADER_ID and shader[2000]:
            # Bound Standard materials evaluate in InitRender. Read the real
            # shader output rather than an obsolete Xcolor child or UI factor.
            render = self.c4d.modules.render
            context = render.InitRenderStruct(self.doc)
            context.linear_workflow = False
            context.document_colorprofile = self.c4d.DOCUMENT_COLORPROFILE_DISABLED
            self.assert_true(shader.InitRender(context) == self.c4d.INITRENDERRESULT_OK,
                             "Material binding failed to initialize")
            try:
                sample = render.ChannelData()
                sample.p = self.c4d.Vector(.5, .5, 0.)
                sample.n = self.c4d.Vector(0., 0., 1.)
                sample.d = self.c4d.Vector()
                sample.t = sample.off = sample.scale = 0.
                sample.texflag = self.c4d.CHANNEL_COLOR << 6
                return self.vector(shader.Sample(sample))
            finally:
                shader.FreeRender()
        self.assert_true(shader is not None and shader.GetType() == self.c4d.Xcolor, "Expected untextured color shader")
        return self.vector(shader[self.c4d.COLORSHADER_COLOR])

    def reopen(self, name):
        path = self.output / (name + ".c4d")
        expected = self.pose()
        saved = self.c4d.documents.SaveDocument(self.doc, str(path), self.c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,
                                               self.c4d.FORMAT_C4DEXPORT)
        self.assert_true(saved and path.is_file(), "C4D scene save failed")
        document = self.c4d.documents.LoadDocument(str(path), self.c4d.SCENEFILTER_OBJECTS | self.c4d.SCENEFILTER_MATERIALS, None)
        self.assert_true(document is not None, "C4D scene reopen failed")
        self.register_document(document, "reopened " + name)
        cleanup = self.close(keep_documents=(document,))
        self.assert_true(not cleanup["errors"], "Previous owned scene could not be closed before reopen")
        self.doc = document
        self.c4d.documents.InsertBaseDocument(document)
        self.c4d.documents.SetActiveDocument(document)
        models = self.nodes(MODEL_ID)
        self.assert_true(len(models) == 1, "Model did not persist")
        self.model = models[0]
        self.doc.SetActiveObject(self.model)
        return expected

    def import_save_reopen(self):
        self.new_model()
        self.call("import_motion", self.fixture("motion_a.vmd"))
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        self.evaluate(2)
        expected = self.reopen("import_reopen")
        self.evaluate(2)
        actual = self.pose()
        self.assert_true(expected.keys() == actual.keys() and all(self.near(expected[key], actual[key]) for key in expected),
                         "Saved animation pose changed after reopen")
        return {"pose": actual, "scene": "import_reopen.c4d"}

    def mode_bind_restore(self):
        self.new_model()
        root = self.bone("root")
        root.SetRelPos(self.c4d.Vector(.4, .2, .1))
        before = self.vector(root.GetMl().off)
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        self.evaluate(0)
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_EDIT"]
        self.evaluate(1)
        self.assert_true(self.near(before, self.vector(root.GetMl().off)), "EDIT bind pose was not restored")
        expected = self.reopen("mode_reopen")
        self.evaluate(1)
        self.assert_true(all(self.near(values, self.pose()[name]) for name, values in expected.items()),
                         "EDIT mode changed after reopen")
        evidence = {"bind_position": before, "restored_mode": int(self.model[self.ids["MODEL_MODE"]])}
        evidence["bone_morph_fixed_frame"] = self.check_bone_morph_fixed_frame()
        return evidence

    def morph_strength_id(self, node, name):
        """Find the actual slider, not a PMX index or a similarly named group."""
        matches = [desc_id for container, desc_id, _ in node.GetDescription(self.c4d.DESCFLAGS_DESC_0)
                   if str(container[self.c4d.DESC_NAME]) == name and
                   container[self.c4d.DESC_CUSTOMGUI] == self.c4d.CUSTOMGUI_REALSLIDER]
        self.assert_true(len(matches) == 1, "Expected exactly one morph strength slider: " + name)
        return matches[0]

    def check_bone_morph_fixed_frame(self):
        """Changing a slider or its offset must pose bones and Skin at one time.

        The fixture translates the triangle's root and rotates it by 30 degrees.
        Reading a tag's stored weight alone cannot catch a stale scene pose, so
        inspect the bone world matrix, evaluated mesh points, and frozen bind.
        """
        c4d = self.c4d
        self.new_model("mixed_morphs.pmx")
        frame = 0

        def snapshot():
            matrix = self.bone("root").GetMg()
            world_matrix = sum((self.vector(value) for value in (matrix.off, matrix.v1, matrix.v2, matrix.v3)), [])
            meshes = [node for node in self.walk(self.doc.GetFirstObject()) if isinstance(node, c4d.PolygonObject)]
            self.assert_true(len(meshes) == 1 and meshes[0].GetPointCount() == 3,
                             "Bone morph fixture lost its skinned triangle")
            mesh = meshes[0]
            deform_cache = mesh.GetDeformCache()
            object_cache = mesh.GetCache() if deform_cache is None else None
            evaluated = deform_cache or object_cache or mesh
            cache_kind = "deform" if deform_cache is not None else "object" if object_cache is not None else "raw_bind"
            if int(self.model[self.ids["MODEL_MODE"]]) == self.ids["MODEL_MODE_ANIM"]:
                self.assert_true(deform_cache is not None,
                                 "ANIM bone morph snapshot requires an evaluated Skin cache")
            self.assert_true(isinstance(evaluated, c4d.PolygonObject) and evaluated.GetPointCount() == 3,
                             "Unexpected evaluated bone morph mesh")
            mesh_points = sum((self.vector(mesh.GetMg() * point) for point in evaluated.GetAllPoints()), [])
            frozen = {bone.GetName(): self.vector(bone.GetFrozenPos()) + self.vector(bone.GetFrozenRot()) +
                      self.vector(bone.GetFrozenScale()) for bone in self.bones()}
            values = world_matrix + mesh_points + sum(frozen.values(), [])
            self.assert_true(all(math.isfinite(value) for value in values), "Non-finite bone morph pose")
            return {"world_matrix": world_matrix, "mesh_points": mesh_points, "frozen_bind": frozen,
                    "mesh_cache_kind": cache_kind, "used_mesh_cache": cache_kind != "raw_bind",
                    "used_deform_cache": deform_cache is not None}

        def rotation_angle(before, after):
            trace = 0.
            for axis in range(3):
                start = 3 + axis * 3
                left, right = before[start:start + 3], after[start:start + 3]
                length = math.sqrt(sum(value * value for value in left) * sum(value * value for value in right))
                self.assert_true(length > 0., "Degenerate bone basis in morph fixture")
                trace += sum(a * b for a, b in zip(left, right)) / length
            return math.acos(max(-1., min(1., (trace - 1.) / 2.)))

        def assert_same_pose(expected, actual, message):
            self.assert_true(self.near(expected["world_matrix"], actual["world_matrix"], 1e-5) and
                             self.near(expected["mesh_points"], actual["mesh_points"], 1e-5), message)

        edit_bind = snapshot()
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        self.evaluate(frame)
        baseline = snapshot()
        assert_same_pose(edit_bind, baseline, "Entering ANIM changed the fixture bind pose")

        def assert_bind_unchanged(actual):
            frozen = actual["frozen_bind"]
            expected = baseline["frozen_bind"]
            self.assert_true(frozen.keys() == expected.keys() and
                             all(self.near(expected[name], frozen[name], 1e-6) for name in expected),
                             "Bone morph was baked into frozen bind transforms")

        def sample(strength):
            desc_id = self.morph_strength_id(self.model, "bone_pose")
            self.model[desc_id] = strength
            self.evaluate(frame)
            self.assert_true(self.doc.GetTime() == c4d.BaseTime(frame, 30), "Bone morph test advanced the frame")
            self.assert_true(abs(self.model[desc_id] - strength) < 1e-6, "Wrong bone morph slider was sampled")
            tag = self.bone("root").GetTag(BONE_TAG_ID)
            self.assert_true(abs(tag[self.morph_strength_id(tag, "bone_pose")] - strength) < 1e-6,
                             "Model bone morph slider did not reach its linked bone tag")
            actual = snapshot()
            assert_bind_unchanged(actual)
            self.assert_true(abs(actual["world_matrix"][0] - baseline["world_matrix"][0] - .3 * strength) < 1e-5,
                             "Same-frame bone morph translation did not reach the scene")
            angle = rotation_angle(baseline["world_matrix"], actual["world_matrix"])
            self.assert_true(abs(angle - math.radians(30.) * strength) < 1e-5,
                             "Same-frame weighted bone morph rotation did not reach the scene")
            if strength:
                self.assert_true(not self.near(baseline["mesh_points"], actual["mesh_points"], 1e-4),
                                 "Bone morph changed stored values without deforming the mesh")
            else:
                assert_same_pose(baseline, actual, "Zero bone morph did not restore the evaluated pose")
            return actual

        samples = [sample(strength) for strength in (0., .5, 1., 0.)]
        self.assert_true(not self.near(samples[1]["mesh_points"], samples[2]["mesh_points"], 1e-4),
                         "Half and full bone morph strengths produced the same mesh")
        half = sample(.5)
        self.reopen("bone_morph_fixed_frame_reopen")
        self.evaluate(frame)
        reopened = snapshot()
        self.assert_true(abs(self.model[self.morph_strength_id(self.model, "bone_pose")] - .5) < 1e-6,
                         "Active bone morph strength did not persist")
        assert_same_pose(half, reopened, "Save/reopen changed the active bone morph at the same frame")
        assert_bind_unchanged(reopened)
        # A copied half pose can survive a missing runtime mapping. Change the
        # weight immediately after Read to prove the hub was actually restored.
        reopened_samples = [sample(strength) for strength in (0., 1., .5)]
        assert_same_pose(half, reopened_samples[-1], "Reopened bone morph mapping did not restore the half pose")

        # Definition edits can change a bone pose without changing its weight.
        # Locate this fixture's two vectors by parent group and initial value,
        # so the test works with localized labels and dynamically allocated IDs.
        tag = self.bone("root").GetTag(BONE_TAG_ID)
        entries = list(tag.GetDescription(c4d.DESCFLAGS_DESC_0))
        groups = [desc_id for container, desc_id, _ in entries if str(container[c4d.DESC_NAME]) == "bone_pose"
                  and desc_id.GetDepth() and desc_id[desc_id.GetDepth() - 1].dtype == c4d.DTYPE_GROUP]
        self.assert_true(len(groups) == 1, "Missing bone morph definition group")
        vectors = [desc_id for container, desc_id, _ in entries if container[c4d.DESC_PARENTGROUP] == groups[0]
                   and desc_id.GetDepth() and desc_id[desc_id.GetDepth() - 1].dtype == c4d.DTYPE_VECTOR]
        self.assert_true(len(vectors) == 2, "Missing bone morph translation/rotation definitions")
        translations = [desc_id for desc_id in vectors if self.near(self.vector(tag[desc_id]), [.3, 0., 0.], 1e-5)]
        self.assert_true(len(translations) == 1, "Bone morph translation definition changed")
        translation_id = translations[0]
        rotation_id = next(desc_id for desc_id in vectors if desc_id != translation_id)
        original_translation, original_rotation = tag[translation_id], tag[rotation_id]
        tag[translation_id] = c4d.Vector(.6, .2, 0.)
        self.evaluate(frame)
        edited_translation = snapshot()
        self.assert_true(self.near(edited_translation["world_matrix"][:3],
                                  [baseline["world_matrix"][0] + .3, baseline["world_matrix"][1] + .1,
                                   baseline["world_matrix"][2]], 1e-5) and
                         not self.near(half["mesh_points"], edited_translation["mesh_points"], 1e-4),
                         "Same-frame bone morph translation definition edit did not reach bones and mesh")
        assert_bind_unchanged(edited_translation)
        tag[translation_id] = original_translation
        tag[rotation_id] = original_rotation * 2.
        self.evaluate(frame)
        edited_rotation = snapshot()
        self.assert_true(abs(rotation_angle(baseline["world_matrix"], edited_rotation["world_matrix"]) -
                             math.radians(30.)) < 1e-5 and
                         not self.near(half["mesh_points"], edited_rotation["mesh_points"], 1e-4),
                         "Same-frame bone morph rotation definition edit did not reach bones and mesh")
        assert_bind_unchanged(edited_rotation)
        tag[rotation_id] = original_rotation
        self.evaluate(frame)
        assert_same_pose(half, snapshot(), "Restoring bone morph definitions did not restore the same-frame pose")

        # A document clone must rebuild its private runtime on its very first
        # evaluation, without committing the copied animated pose as bind state.
        source_document, source_model = self.doc, self.model
        translator = c4d.AliasTrans()
        self.assert_true(translator is not None and translator.Init(source_document),
                         "Bone morph clone alias translator initialization failed")
        # Match the maintained bake path: explicitly translate scene BaseLinks
        # before any copied runtime is evaluated or its hubs are registered.
        clone = source_document.GetClone(c4d.COPYFLAGS_NONE, translator)
        self.assert_true(clone is not None, "Bone morph document clone failed")
        self.register_document(clone, "bone morph clone")
        translator.Translate(True)

        def document_state(document, model):
            previous_document, previous_model = self.doc, self.model
            previous_active = c4d.documents.GetActiveDocument()
            try:
                self.doc, self.model = document, model
                bone = self.bone("root")
                tag = bone.GetTag(BONE_TAG_ID)
                self.assert_true(model.GetDocument() == document and tag.GetDocument() == document,
                                 "Bone morph state probe crossed document ownership")
                matrix = bone.GetMg()
                before = {"model_strength": float(model[self.morph_strength_id(model, "bone_pose")]),
                          "tag_strength": float(tag[self.morph_strength_id(tag, "bone_pose")]),
                          "model_mode": int(model[self.ids["MODEL_MODE"]]),
                          "world_matrix": sum((self.vector(value) for value in
                                               (matrix.off, matrix.v1, matrix.v2, matrix.v3)), [])}
                # Cinema 4D can discard an inactive document's deformation
                # cache during cloning or document activation. Read persistent
                # strengths and Mg first, then evaluate the requested document
                # as active before comparing its actual skinned geometry.
                c4d.documents.SetActiveDocument(document)
                self.evaluate(frame)
                return {"model_strength": float(model[self.morph_strength_id(model, "bone_pose")]),
                        "tag_strength": float(tag[self.morph_strength_id(tag, "bone_pose")]),
                        "before_evaluation": before, "pose": snapshot()}
            finally:
                self.doc, self.model = previous_document, previous_model
                if previous_active is not None:
                    c4d.documents.SetActiveDocument(previous_active)

        def assert_document_state(actual, strength, pose, message):
            before = actual["before_evaluation"]
            self.assert_true(abs(before["model_strength"] - strength) < 1e-6 and
                             abs(before["tag_strength"] - strength) < 1e-6 and
                             before["model_mode"] == self.ids["MODEL_MODE_ANIM"] and
                             self.near(before["world_matrix"], pose["world_matrix"], 1e-5),
                             message + " (persistent state before cache rebuild)")
            self.assert_true(abs(actual["model_strength"] - strength) < 1e-6 and
                             abs(actual["tag_strength"] - strength) < 1e-6, message)
            assert_same_pose(pose, actual["pose"], message)
            assert_bind_unchanged(actual["pose"])

        clone_samples, source_samples = [], []
        try:
            c4d.documents.InsertBaseDocument(clone)
            c4d.documents.SetActiveDocument(clone)
            self.doc = clone
            models = self.nodes(MODEL_ID)
            self.assert_true(len(models) == 1, "Bone morph document clone lost its model")
            self.model = models[0]
            copied_model = self.model
            self.doc.SetActiveObject(self.model)
            self.evaluate(frame)
            copied = snapshot()
            assert_same_pose(half, copied, "First evaluation changed the copied active bone morph")
            assert_bind_unchanged(copied)
            for strength in (0., 1.):
                clone_samples.append(sample(strength))
                assert_document_state(document_state(source_document, source_model), .5, half,
                                      "Changing the clone mutated its source bone morph")
            self.doc, self.model = source_document, source_model
            c4d.documents.SetActiveDocument(source_document)
            for strength in (1., 0.):
                source_samples.append(sample(strength))
                assert_document_state(document_state(clone, copied_model), 1., samples[2],
                                      "Changing the source mutated its clone bone morph")
        finally:
            c4d.documents.KillDocument(clone)
            self.doc, self.model = source_document, source_model
            c4d.documents.SetActiveDocument(source_document)
        after_clone_samples = [sample(strength) for strength in (0., .5)]
        assert_same_pose(half, after_clone_samples[-1], "Destroying the clone damaged the source morph mapping")

        sample(1.)
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_EDIT"]
        self.evaluate(frame)
        assert_same_pose(edit_bind, snapshot(), "Returning to EDIT retained a posed bone morph as bind state")
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        self.evaluate(frame)
        assert_same_pose(samples[2], sample(1.), "EDIT/ANIM mode cycling baked or duplicated the bone morph")
        sample(0.)

        # The fixture has a root-following body and a dynamic body on hinge.
        # Simulation is reflected into the hinge bone, not the authoring rigid
        # object's Mg. After advancing to frame 2, posing the root at that same
        # time must retain the simulated bone pose and authoring configuration.
        def dynamic_snapshot():
            rigid = next((node for node in self.nodes(RIGID_ID) if node.GetName() == "rigid1"), None)
            self.assert_true(rigid is not None, "Missing dynamic body in bone morph fixture")
            result = {}
            for name, node in (("authoring_rigid1_world", rigid), ("simulated_hinge_world", self.bone("hinge"))):
                matrix = node.GetMg()
                result[name] = sum((self.vector(value) for value in (matrix.off, matrix.v1, matrix.v2, matrix.v3)), [])
            self.assert_true(all(math.isfinite(value) for values in result.values() for value in values),
                             "Non-finite physics bone or authoring rigid state in bone morph fixture")
            return result

        def assert_dynamic_same(expected, actual, message):
            self.assert_true(self.near(expected["simulated_hinge_world"], actual["simulated_hinge_world"], 1e-5), message)
            self.assert_true(self.near(expected["authoring_rigid1_world"], actual["authoring_rigid1_world"], 1e-5),
                             "Same-frame bone morph changed the authoring rigid configuration")

        self.model[self.ids["MODEL_PHYSICS_ENABLED"]] = True
        physics_frames = {}
        for physics_frame in (0, 1, 2):
            self.evaluate(physics_frame)
            physics_frames[str(physics_frame)] = dynamic_snapshot()
        self.assert_true(not self.near(physics_frames["0"]["simulated_hinge_world"],
                                      physics_frames["2"]["simulated_hinge_world"], 1e-6),
                         "Physics fixture did not exercise an advancing simulated hinge bone")
        fixed_time = c4d.BaseTime(2, 30)
        physics_base = snapshot()
        desc_id = self.morph_strength_id(self.model, "bone_pose")
        self.model[desc_id] = .5
        self.evaluate(2)
        physics_morph = snapshot()
        assert_bind_unchanged(physics_morph)
        self.assert_true(not self.near(physics_base["world_matrix"], physics_morph["world_matrix"], 1e-4) and
                         not self.near(physics_base["mesh_points"], physics_morph["mesh_points"], 1e-4),
                         "Fixed-frame bone morph did not pose bones and mesh with physics enabled")
        assert_dynamic_same(physics_frames["2"], dynamic_snapshot(),
                            "Changing a bone morph at one frame advanced the simulated hinge bone")
        repeated = []
        for _ in range(3):
            self.evaluate(2)
            self.assert_true(self.doc.GetTime() == fixed_time, "Physics morph test advanced document time")
            actual = dynamic_snapshot()
            assert_dynamic_same(physics_frames["2"], actual, "Repeated same-frame evaluation advanced the simulated hinge bone")
            assert_same_pose(physics_morph, snapshot(), "Repeated same-frame evaluation drifted the bone morph pose")
            repeated.append(actual)
        self.model[desc_id] = 0.
        self.evaluate(2)
        assert_same_pose(physics_base, snapshot(), "Zero fixed-frame morph failed to restore the physics-enabled pose")
        assert_dynamic_same(physics_frames["2"], dynamic_snapshot(),
                            "Restoring a zero morph at one frame advanced the simulated hinge bone")
        return {"frame": frame, "strengths": [0., .5, 1., 0.], "samples": samples,
                "active_half_strength_reopen": reopened, "reopened_strength_samples": reopened_samples,
                "active_half_strength_copy": copied, "clone_strength_samples": clone_samples,
                "source_strength_samples_with_live_clone": source_samples,
                "source_strength_samples_after_clone_destroy": after_clone_samples,
                "definition_translation_edit": edited_translation,
                "definition_rotation_edit": edited_rotation, "frozen_bind_unchanged": True,
                "edit_anim_cycle_unchanged": True, "scene": "bone_morph_fixed_frame_reopen.c4d",
                "physics_fixed_frame": {"frame": 2, "continuous_physics_states": physics_frames,
                                        "morph_pose": physics_morph, "repeated_physics_states": repeated,
                                        "no_extra_physics_step": True}}

    def cycle(self, node, resource):
        description = node.GetDescription(self.c4d.DESCFLAGS_DESC_0)
        for container, desc_id, _ in description:
            if desc_id.GetDepth() and desc_id[0].id == self.ids[resource]:
                cycle = container[self.c4d.DESC_CYCLE]
                if cycle is None:
                    raise AssertionError("Missing dropdown: " + resource)
                return {int(key): str(value) for key, value in cycle if key >= 0}
        raise AssertionError("Missing description: " + resource)

    def check_hierarchy(self, selectors=True):
        self.evaluate(0)
        bones = self.bones()
        expected = {index: bone.GetName() for index, bone in enumerate(bones)}
        parents = []
        for index, bone in enumerate(bones):
            tag = bone.GetTag(BONE_TAG_ID)
            self.assert_true(int(tag[self.ids["PMX_BONE_INDEX"]]) == index, "Bone index differs from DFS order")
            parent = bone.GetUp()
            while parent and parent not in bones:
                parent = parent.GetUp()
            parent_index = bones.index(parent) if parent in bones else -1
            self.assert_true(int(tag[self.ids["PMX_BONE_PARENT_BONE_INDEX"]]) == parent_index,
                             "Parent index differs from actual hierarchy")
            parents.append(parent_index)
        if selectors:
            for node in self.nodes(RIGID_ID):
                self.assert_true(self.cycle(node, "RIGID_RELATED_BONE_INDEX") == expected, "Rigid bone dropdown is stale")
            for node in self.nodes(JOINT_ID):
                self.assert_true(self.cycle(node, "JOINT_ATTITUDE_USE_BONE_INDEX") == expected, "Joint bone dropdown is stale")
            self.model[self.ids["MODEL_DISPLAY_FRAME_ADD_TYPE"]] = self.ids["MODEL_DISPLAY_FRAME_ADD_TYPE_BONE"]
            # The fixture's display frame already contains root and hinge.
            # Add-target cycles intentionally omit bones used by any frame;
            # their new DFS indices must still be excluded after reordering.
            available = {index: name for index, name in expected.items() if name not in ("root", "hinge")}
            self.assert_true(self.cycle(self.model, "MODEL_DISPLAY_FRAME_ADD_TARGET") == available,
                             "Display frame bone dropdown is stale")
        root_tag = self.bone("root").GetTag(BONE_TAG_ID)
        hinge_index = next((index for index, name in expected.items() if name == "hinge"), -1)
        self.assert_true(int(root_tag[self.ids["PMX_BONE_TAIL_INDEX"]]) == hinge_index,
                         "Indexed tail changed target after DFS synchronization")
        return {"order": list(expected.values()), "parents": parents}

    def hierarchy_edit_and_selectors(self):
        self.new_model()
        results = {"initial": self.check_hierarchy()}
        joint = self.nodes(JOINT_ID)[0]
        joint[self.ids["JOINT_ATTITUDE_USE_BONE_INDEX"]] = self.bones().index(self.bone("hinge"))
        tip, goal = self.bone("tip"), self.bone("goal")
        tip.Remove()
        tip.InsertUnder(goal)
        results["reparent"] = self.check_hierarchy()
        goal.Remove()
        goal.InsertBefore(self.bone("root"))
        results["reorder"] = self.check_hierarchy()
        added = self.c4d.BaseObject(self.c4d.Ojoint)
        tag = self.c4d.BaseTag(BONE_TAG_ID)
        self.assert_true(tag is not None, "Bone tag allocation failed")
        added.InsertTag(tag)
        added.SetName("added")
        tag[self.ids["PMX_BONE_NAME_LOCAL"]] = "added"
        added.InsertUnder(self.nodes(BONE_MANAGER_ID)[0])
        results["add"] = self.check_hierarchy()
        clone = added.GetClone(self.c4d.COPYFLAGS_NONE)
        clone.SetName("copied")
        clone.GetTag(BONE_TAG_ID)[self.ids["PMX_BONE_NAME_LOCAL"]] = "copied"
        clone.InsertAfter(added)
        results["copy"] = self.check_hierarchy()
        added.Remove()
        results["delete"] = self.check_hierarchy()
        self.assert_true(int(joint[self.ids["JOINT_ATTITUDE_USE_BONE_INDEX"]]) == self.bones().index(self.bone("hinge")),
                         "Joint bone selection changed target after reordering/copy")
        self.bone("hinge").Remove()
        results["delete_referenced"] = self.check_hierarchy()
        self.assert_true(int(joint[self.ids["JOINT_ATTITUDE_USE_BONE_INDEX"]]) == -1,
                         "Deleted joint bone selection did not detach")
        referenced_rigid = next(node for node in self.nodes(RIGID_ID) if node.GetName() == "rigid1")
        self.assert_true(int(referenced_rigid[self.ids["RIGID_RELATED_BONE_INDEX"]]) == -1,
                         "Deleted rigid bone reference did not detach")
        return results

    def hierarchy_export_and_anim(self):
        self.hierarchy_edit_and_selectors()
        expected = self.check_hierarchy()
        self.doc.SetActiveObject(self.model)
        path = self.output / "hierarchy.pmx"
        self.call("export_model", path)
        exported = read_pmx_bones(path)["bones"]
        self.assert_true([bone["name"] for bone in exported] == expected["order"], "PMX export order differs")
        self.assert_true([bone["parent"] for bone in exported] == expected["parents"], "PMX export parent indices differ")
        self.assert_true(next(bone for bone in exported if bone["name"] == "root")["tail"] == -1,
                         "PMX export retained a deleted tail reference")
        self.call("import_motion", self.fixture("motion_a.vmd"))
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        self.evaluate(2)
        self.assert_true(abs(self.bone("root").GetRelPos().x - 1.) < 1e-4, "ANIM regressed after hierarchy edits")
        self.reopen("hierarchy_anim")
        self.check_hierarchy()
        return expected

    def animation_slots_and_options(self):
        self.new_model()
        base_color = self.material_color()
        self.call("import_motion", self.fixture("motion_a.vmd"))
        first = int(self.model[self.ids["MODEL_ANIM_LIST"]])
        self.call("import_motion", self.fixture("motion_b.vmd"), replace=False)
        second = int(self.model[self.ids["MODEL_ANIM_LIST"]])
        self.assert_true(first != second, "Append import replaced selected animation")
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        for slot, x, visible in ((first, 1., True), (second, 3., False), (first, 1., True)):
            self.model[self.ids["MODEL_ANIM_LIST"]] = slot
            self.evaluate(0)
            self.assert_true(self.near(base_color, self.material_color()), "Slot initial morph weight was not restored")
            self.evaluate(1)
            increment = .125 if slot == first else .0625
            self.assert_true(self.near(self.material_color(), [base_color[0] + increment, *base_color[1:]]),
                             "Slot morph interpolation differs")
            self.evaluate(2)
            self.assert_true(self.near(self.material_color(), [base_color[0] + increment * 2, *base_color[1:]]),
                             "Slot morph end weight differs")
            self.assert_true(abs(self.bone("root").GetRelPos().x - x) < 1e-4, "Slot pose mismatch")
            self.assert_true((self.model[self.c4d.ID_BASEOBJECT_VISIBILITY_EDITOR] != self.c4d.MODE_OFF) == visible,
                             "Slot visibility mismatch")
        self.reopen("animation_slots_reopen")
        for slot, x, visible, increment in ((second, 3., False, .125), (first, 1., True, .25)):
            self.model[self.ids["MODEL_ANIM_LIST"]] = slot
            self.evaluate(0)
            self.evaluate(2)
            self.assert_true(abs(self.bone("root").GetRelPos().x - x) < 1e-4, "Reopened slot pose mismatch")
            self.assert_true(self.near(self.material_color(), [base_color[0] + increment, *base_color[1:]]),
                             "Reopened slot morph weight mismatch")
            self.assert_true((self.model[self.c4d.ID_BASEOBJECT_VISIBILITY_EDITOR] != self.c4d.MODE_OFF) == visible,
                             "Reopened slot visibility mismatch")
        self.call("import_motion", self.fixture("motion_b.vmd"), info=False, replace=True)
        self.assert_true(int(self.model[self.ids["MODEL_ANIM_LIST"]]) == first, "Replace import changed slot identity")
        self.evaluate(0)
        self.evaluate(2)
        self.assert_true(self.model[self.c4d.ID_BASEOBJECT_VISIBILITY_EDITOR] != self.c4d.MODE_OFF,
                         "Disabled model-info import affected visibility")
        path = self.output / "without_model_info.vmd"
        self.call("export_motion", path, info=False)
        self.assert_true(not read_vmd(path)["iks"], "Disabled model-info export wrote IK/visibility")
        return {"first_slot": first, "second_slot": second, "metadata_disabled": True,
                "morph_interpolation_checked": True, "two_slots_reopened": True}

    def physics_toggle_and_reopen(self):
        self.new_model()
        self.call("import_motion", self.fixture("motion_a.vmd"))
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        self.model[self.ids["MODEL_PHYSICS_ENABLED"]] = False
        self.evaluate(0)
        self.evaluate(2)
        disabled = self.pose()
        self.model[self.ids["MODEL_PHYSICS_ENABLED"]] = True
        for frame in range(16):
            self.evaluate(frame)
        enabled = self.pose()
        self.assert_true(any(not self.near(enabled[key], disabled[key], .001) for key in enabled),
                         "Physics produced no observable fixture response")
        self.reopen("physics_reopen")
        self.assert_true(bool(self.model[self.ids["MODEL_PHYSICS_ENABLED"]]), "Physics option did not persist")
        self.evaluate(0)
        for frame in range(16):
            self.evaluate(frame)
        reopened = self.pose()
        self.assert_true(all(self.near(enabled[key], reopened[key], .01) for key in enabled),
                         "Physics reconstruction changed sequential playback")
        self.model[self.ids["MODEL_PHYSICS_ENABLED"]] = False
        self.evaluate(0)
        self.evaluate(2)
        self.assert_true(all(self.near(disabled[key], self.pose()[key], .001) for key in disabled),
                         "Disabling physics did not restore animation result")
        return {"disabled": disabled, "enabled": enabled, "reopened": reopened}

    def material_morph_zero_and_delete(self):
        self.new_model()
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        base = self.material_color()
        self.call("set_strength", strength=1.)
        full = self.material_color()
        self.assert_true(self.near(full, [base[0] + .25, base[1], base[2]]), "Material morph did not apply fixture tint")
        self.call("set_strength", strength=0.)
        self.assert_true(self.near(base, self.material_color()), "Zero morph did not restore base color")
        self.call("set_strength", strength=1.)
        self.call("delete_morph")
        self.assert_true(self.near(base, self.material_color()), "Deleting active morph left runtime tint")
        self.reopen("material_reopen")
        self.assert_true(self.near(base, self.material_color()), "Deleted morph tint returned after reopen")
        evidence = {"base": base, "full": full, "restored": self.material_color()}
        # Derived bone morphs are collected separately from root-owned morphs.
        # A bone-first input forces a genuine index change for forward group and
        # display-frame references, instead of allowing identity mappings to pass.
        self.new_model("mixed_morphs.pmx")
        input_data = read_pmx_morphs_and_frames(self.fixture("mixed_morphs.pmx"))
        output = self.output / "mixed_morphs_export.pmx"
        self.call("export_model", output)
        output_data = read_pmx_morphs_and_frames(output)
        input_order = [morph["name"] for morph in input_data["morphs"]]
        output_order = [morph["name"] for morph in output_data["morphs"]]
        self.assert_true(input_order == ["bone_pose", "group", "tint"], "Mixed-morph fixture order changed")
        self.assert_true(output_order == ["group", "tint", "bone_pose"] and input_order != output_order,
                         "Mixed-morph regression did not exercise index remapping")
        group = next(morph for morph in output_data["morphs"] if morph["name"] == "group")
        self.assert_true(group["kind"] == 0 and len(group["offsets"]) == 1, "Group morph shape changed")
        group_child = group["offsets"][0]["morph_index"]
        self.assert_true(0 <= group_child < len(output_order) and output_order[group_child] == "tint" and
                         abs(group["offsets"][0]["weight"] - 1.) < 1e-6,
                         "Forward group reference did not remap to tint")
        frame = next(frame for frame in output_data["display_frames"] if frame["name"] == "bones")
        frame_targets = [target["index"] for target in frame["targets"] if target["kind"] == 1]
        self.assert_true(len(frame_targets) == 1 and 0 <= frame_targets[0] < len(output_order) and
                         output_order[frame_targets[0]] == "tint", "Display-frame morph reference did not remap to tint")
        evidence["mixed_morph_remap"] = {"input_order": input_order, "output_order": output_order,
                                         "group_child_index": group_child, "group_child_name": output_order[group_child],
                                         "display_frame_morph_index": frame_targets[0],
                                         "display_frame_morph_name": output_order[frame_targets[0]], "export": str(output)}
        evidence["toon_channels"] = self.check_toon_material_channels()
        return evidence

    def check_toon_export(self, name):
        """Inspect the actual PMX file, independently of C4D's shader graph."""
        path = self.output / (name + ".pmx")
        self.doc.SetActiveObject(self.model)
        self.call("export_model", path)
        data = read_pmx_bones(path)
        self.assert_true(len(data["material_data"]) == 1, "Toon fixture material count changed")
        material = data["material_data"][0]
        index = material["toon_index"]
        self.assert_true(material["toon_mode"] == 0 and 0 <= index < len(data["textures"]),
                         "Separate PMX toon mode/texture reference was lost")
        texture = Path(data["textures"][index])
        if not texture.is_absolute():
            texture = path.parent / texture
        expected = Path(self.fixture("toon_white.bmp"))
        self.assert_true(texture.resolve() == expected.resolve() and sha256(texture) == sha256(expected),
                         "PMX export changed the toon texture identity")
        morphs = read_pmx_morphs_and_frames(path)["morphs"]
        tint = next(morph for morph in morphs if morph["name"] == "tint")
        self.assert_true(self.near(tint["offsets"][0]["values"][-4:], [.2, .3, .4, .1], 1e-6),
                         "PMX export lost the authored toon-factor morph")
        return {"export": str(path), "toon_mode": material["toon_mode"], "toon_index": index,
                "toon_texture": str(texture), "toon_texture_sha256": sha256(texture)}

    def install_fixture_luminance(self, material, kind):
        """Reproduce old importer graphs using only generated fixture assets."""
        c4d = self.c4d
        bitmap = c4d.BaseShader(c4d.Xbitmap)
        self.assert_true(bitmap is not None, "Bitmap shader allocation failed")
        bitmap[c4d.BITMAPSHADER_FILENAME] = self.fixture("toon_white.bmp")
        shader = bitmap
        if kind == "wrapper":
            shader = c4d.BaseShader(MATERIAL_MORPH_SHADER_ID)
            self.assert_true(shader is not None, "Material-morph wrapper allocation failed")
            bitmap.InsertUnder(shader)
        material.InsertShader(shader)
        material[c4d.MATERIAL_LUMINANCE_SHADER] = shader
        material[c4d.MATERIAL_USE_LUMINANCE] = True
        material[c4d.MATERIAL_LUMINANCE_COLOR] = c4d.Vector(1., 1., 1.)
        material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] = 1.
        material[c4d.MATERIAL_LUMINANCE_TEXTURESTRENGTH] = 1.
        material[c4d.MATERIAL_LUMINANCE_TEXTUREMIXING] = c4d.MATERIAL_TEXTUREMIXING_NORMAL
        # This reproduces a scene saved before the migration schema existed.
        # Clear only the plugin-owned namespace on this test-owned material.
        material.GetDataInstance().SetContainer(MATERIAL_MORPH_SHADER_ID, c4d.BaseContainer())
        return shader

    def check_toon_material_channels(self):
        c4d = self.c4d
        self.new_model("toon_material.pmx")
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        material = self.doc.GetFirstMaterial()
        base = self.material_color()
        self.assert_true(not material[c4d.MATERIAL_USE_LUMINANCE], "PMX toon texture was imported as emission")
        for strength in (1., .5, 0.):
            self.call("set_strength", strength=strength)
            self.assert_true(self.near(self.material_color(), [base[0] + .25 * strength, *base[1:]]),
                             "Toon fixture diffuse morph did not execute")
            self.assert_true(not material[c4d.MATERIAL_USE_LUMINANCE], "Material sync re-enabled toon emission")
        exports = [self.check_toon_export("toon_import_export")]
        self.reopen("toon_material_reopen")
        self.evaluate(0)
        self.assert_true(not self.doc.GetFirstMaterial()[c4d.MATERIAL_USE_LUMINANCE],
                         "Toon emission returned after save/reopen")
        exports.append(self.check_toon_export("toon_reopen_export"))

        # A user-authored emission channel is independent of the PMX shadow ramp
        # and its animated factor. Check real shader identity and values across
        # material sync, deletion, serialization, and another export.
        material = self.doc.GetFirstMaterial()
        emission = c4d.BaseShader(c4d.Xcolor)
        self.assert_true(emission is not None, "Artist emission shader allocation failed")
        emission_color = [.11, .22, .33]
        emission[c4d.COLORSHADER_COLOR] = c4d.Vector(*emission_color)
        material.InsertShader(emission)
        material[c4d.MATERIAL_LUMINANCE_SHADER] = emission
        material[c4d.MATERIAL_USE_LUMINANCE] = True
        material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] = .37
        material[c4d.MATERIAL_LUMINANCE_TEXTURESTRENGTH] = .66
        material.GetDataInstance().SetContainer(MATERIAL_MORPH_SHADER_ID, c4d.BaseContainer())
        for strength in (1., 0.):
            self.call("set_strength", strength=strength)
            self.assert_true(material[c4d.MATERIAL_USE_LUMINANCE] and material[c4d.MATERIAL_LUMINANCE_SHADER] == emission,
                             "Material sync replaced or disabled artist emission")
            self.assert_true(self.near(self.vector(emission[c4d.COLORSHADER_COLOR]), emission_color) and
                             abs(material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] - .37) < 1e-6 and
                             abs(material[c4d.MATERIAL_LUMINANCE_TEXTURESTRENGTH] - .66) < 1e-6,
                             "Material sync applied PMX toon factors to artist emission")
        exports.append(self.check_toon_export("toon_artist_emission_export"))
        self.call("delete_morph")
        self.assert_true(material[c4d.MATERIAL_USE_LUMINANCE] and material[c4d.MATERIAL_LUMINANCE_SHADER] == emission,
                         "Deleting the material morph changed artist emission")
        self.reopen("toon_artist_emission_reopen")
        self.evaluate(0)
        material = self.doc.GetFirstMaterial()
        emission = material[c4d.MATERIAL_LUMINANCE_SHADER]
        self.assert_true(material[c4d.MATERIAL_USE_LUMINANCE] and emission and emission.GetType() == c4d.Xcolor and
                         self.near(self.vector(emission[c4d.COLORSHADER_COLOR]), emission_color) and
                         abs(material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] - .37) < 1e-6,
                         "Artist emission did not survive save/reopen")

        migrations = {}
        for kind in ("bitmap", "wrapper"):
            self.new_model("toon_material.pmx")
            material = self.doc.GetFirstMaterial()
            shader = self.install_fixture_luminance(material, kind)
            self.call("set_strength", strength=1.)
            self.assert_true(not material[c4d.MATERIAL_USE_LUMINANCE], "Unedited legacy toon emission was not migrated: " + kind)
            self.assert_true(material[c4d.MATERIAL_LUMINANCE_SHADER] == shader,
                             "Legacy migration discarded the existing toon shader: " + kind)
            # Migration is one-time. Re-enabling the retained shader is an
            # artist's choice and must survive another sync and a scene reopen.
            material[c4d.MATERIAL_USE_LUMINANCE] = True
            self.call("set_strength", strength=.5)
            self.assert_true(material[c4d.MATERIAL_USE_LUMINANCE] and material[c4d.MATERIAL_LUMINANCE_SHADER] == shader,
                             "Legacy migration ran again after artist re-enabled emission: " + kind)
            self.reopen("toon_legacy_" + kind + "_reopen")
            self.call("set_strength", strength=1.)
            material = self.doc.GetFirstMaterial()
            self.assert_true(material[c4d.MATERIAL_USE_LUMINANCE], "Legacy migration marker did not persist: " + kind)
            migrations[kind] = {"disabled_once": True, "shader_retained": True, "artist_reenable_persisted": True}

        # Even an exact toon bitmap match belongs to the artist if the emission
        # settings were edited. This prevents migration based on filename alone.
        self.new_model("toon_material.pmx")
        material = self.doc.GetFirstMaterial()
        shader = self.install_fixture_luminance(material, "bitmap")
        material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] = .42
        self.call("set_strength", strength=1.)
        self.assert_true(material[c4d.MATERIAL_USE_LUMINANCE] and material[c4d.MATERIAL_LUMINANCE_SHADER] == shader and
                         abs(material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] - .42) < 1e-6,
                         "Migration changed edited emission which uses the toon bitmap")
        return {"import_luminance_disabled": True, "morph_sync_luminance_disabled": True,
                "toon_metadata_exports": exports, "artist_emission_preserved": True,
                "legacy_migrations": migrations, "edited_toon_emission_preserved": True}

    def motion_roundtrip_and_bake(self):
        self.new_model()
        self.call("import_motion", self.fixture("motion_a.vmd"))
        sparse_path = self.output / "sparse.vmd"
        self.call("export_motion", sparse_path)
        sparse = read_vmd(sparse_path)
        root_keys = [key for key in sparse["motions"] if key["name"] == "root"]
        self.assert_true([key["frame"] for key in root_keys] == [0, 2], "Nonbake export changed sparse key frames")
        self.assert_true(self.near(root_keys[-1]["translation"], [1., 0., 0.]), "Nonbake export changed translation")
        self.model[self.ids["MODEL_MODE"]] = self.ids["MODEL_MODE_ANIM"]
        samples = {}
        for frame in range(3):
            self.evaluate(frame)
            samples[frame] = self.vector(self.bone("root").GetRelPos())
        before_pose, before_time, before_mode = self.pose(), self.doc.GetTime(), int(self.model[self.ids["MODEL_MODE"]])
        before_color = self.material_color()
        baked_path = self.output / "baked.vmd"
        self.call("export_motion", baked_path, bake=True)
        baked = read_vmd(baked_path)
        baked_root = [key for key in baked["motions"] if key["name"] == "root"]
        self.assert_true([key["frame"] for key in baked_root] == [0, 1, 2], "Bake did not sample every VMD frame")
        self.assert_true(all(self.near(key["translation"], samples[key["frame"]]) for key in baked_root),
                         "Bake does not match native sequential playback")
        self.assert_true(before_time == self.doc.GetTime() and before_mode == int(self.model[self.ids["MODEL_MODE"]])
                         and before_pose == self.pose(), "Bake changed source document state")
        self.assert_true(self.near(before_color, self.material_color()), "Bake changed source document material")
        baked_morphs = [key for key in baked["morphs"] if key["name"] == "tint"]
        self.assert_true([(key["frame"], key["weight"]) for key in baked_morphs] == [(0, 0.), (1, .5), (2, 1.)],
                         "Baked morph does not match sequential playback")
        before_max, before_loop = self.doc.GetMaxTime(), self.doc.GetLoopMaxTime()
        self.call("import_motion", self.fixture("motion_b.vmd"), expected=False, offset=.5)
        self.model = self.nodes(MODEL_ID)[0]
        self.doc.SetActiveObject(self.model)
        self.assert_true(self.doc.GetTime() == before_time and self.doc.GetMaxTime() == before_max
                         and self.doc.GetLoopMaxTime() == before_loop, "Rejected import changed document time range")
        self.evaluate(2)
        self.assert_true(before_pose == self.pose() and self.near(before_color, self.material_color()),
                         "Rejected import changed animation or material state")
        self.call("import_motion", sparse_path, replace=False)
        self.evaluate(0)
        self.evaluate(2)
        self.assert_true(abs(self.bone("root").GetRelPos().x - 1.) < 1e-4, "VMD roundtrip changed pose")
        return {"sparse_frames": [key["frame"] for key in root_keys], "baked_root": baked_root,
                "baked_morphs": baked_morphs, "source_material_unchanged": True,
                "rejected_import_unchanged": True}

    def camera_export_and_failures(self):
        self.new_model()
        self.doc.SetTime(self.c4d.BaseTime(1, 30))
        self.call("import_camera", self.fixture("camera.vmd"))
        camera = self.doc.GetActiveObject()
        self.assert_true(camera.GetType() == CAMERA_ID, "Camera import failed")
        self.evaluate(1)
        child = camera.GetDown()
        self.assert_true(child is not None and child.GetType() == self.c4d.Ocamera, "Missing generated camera child")
        self.assert_true(abs(child[self.c4d.CAMERAOBJECT_FOV_VERTICAL] - math.radians(45.)) < 1e-5,
                         "VMD import changed sensor width instead of actual vertical FOV")
        self.assert_true(child.FindCTrack(self.c4d.DescID(self.c4d.DescLevel(self.c4d.CAMERAOBJECT_APERTURE))) is None,
                         "New camera import created legacy aperture animation")
        before_time = self.doc.GetTime()
        path = self.output / "camera_baked.vmd"
        self.call("export_camera", path, bake=True)
        exported = read_vmd(path)
        self.assert_true(exported["model_name"] == "カメラ・照明" and len(exported["cameras"]) == 3,
                         "Camera header/frame count invalid")
        self.assert_true(self.near(exported["cameras"][1]["position"], [1., 1., 2.]), "Camera interpolation changed")
        self.assert_true(self.doc.GetTime() == before_time, "Camera export changed document time")
        clone = camera.GetClone(self.c4d.COPYFLAGS_NONE)
        self.doc.InsertObject(clone)
        self.evaluate(1)
        clone_children = list(self.walk(clone.GetDown()))
        self.assert_true(len(clone_children) == 1 and clone_children[0].GetType() == self.c4d.Ocamera,
                         "Camera clone created extra/detached child objects")
        self.assert_true(bool(clone_children[0].GetDataInstance()[CAMERA_ID]) and
                         clone_children[0].FindUniqueID(CAMERA_ID) is not None,
                         "Camera clone lost its generated-child role or did not rebuild UniqueID")
        self.assert_true(abs(clone_children[0][self.c4d.CAMERAOBJECT_FOV_VERTICAL] - math.radians(45.)) < 1e-5,
                         "Camera clone did not reconnect to its animated child")
        self.doc.SetActiveObject(clone)
        self.call("export_camera", self.output / "cloned_camera.vmd", bake=True)
        self.assert_true(read_vmd(self.output / "cloned_camera.vmd")["cameras"] == exported["cameras"],
                         "Cloned camera serialization diverged from source")
        clone.Remove()
        self.doc.SetActiveObject(camera)
        migration = self.check_camera_legacy_migration(camera)
        ordinary = self.c4d.BaseObject(self.c4d.Ocamera)
        ordinary.SetRelPos(self.c4d.Vector(3., 4., 5.))
        self.doc.InsertObject(ordinary)
        ordinary[self.c4d.CAMERAOBJECT_APERTURE] = 32.
        ordinary[self.c4d.CAMERAOBJECT_FOV_VERTICAL] = math.radians(60.)
        self.doc.SetActiveObject(ordinary)
        before_count = len(list(self.walk(self.doc.GetFirstObject())))
        path = self.output / "static_camera.vmd"
        self.call("export_camera", path)
        static = read_vmd(path)["cameras"]
        self.assert_true(len(static) == 1 and self.near(static[0]["position"], [3., 4., 5.]), "Static camera export lost values")
        self.assert_true(static[0]["angle"] == 60, "Standard camera export did not read actual vertical FOV")
        self.assert_true(before_count == len(list(self.walk(self.doc.GetFirstObject()))) and not ordinary.GetCTracks(),
                         "Export inserted temporary camera/tracks")
        self.assert_true(self.doc.GetTime() == before_time, "Standard camera export changed document time")
        # An artist's sensor-width track is not legacy MMD FOV data. Conversion
        # can read the ordinary camera, but must preserve its authored curve.
        aperture_track = self.c4d.CTrack(ordinary, self.c4d.DescID(self.c4d.DescLevel(self.c4d.CAMERAOBJECT_APERTURE)))
        aperture_curve = aperture_track.GetCurve()
        aperture_key = aperture_curve.AddKey(self.c4d.BaseTime(0, 30))["key"]
        aperture_key.SetValue(aperture_curve, 32.)
        ordinary.InsertTrackSorted(aperture_track)
        self.call("export_camera", self.output / "artist_aperture.vmd")
        self.assert_true(ordinary.FindCTrack(self.c4d.DescID(self.c4d.DescLevel(self.c4d.CAMERAOBJECT_APERTURE))) == aperture_track
                         and aperture_curve.GetKey(0).GetValue() == 32., "Export migrated an artist's aperture curve")
        blocked_path = self.output / "missing-parent" / "camera.vmd"
        self.assert_true(not blocked_path.parent.exists(), "Failure fixture directory already exists")
        self.call("export_camera", blocked_path, expected=False)
        self.assert_true(not blocked_path.exists() and self.doc.GetTime() == before_time, "Failed camera write changed state")
        self.call("export_camera", self.output / "negative_offset.vmd", expected=False, offset=-1.)
        return {"baked_frames": len(exported["cameras"]), "static_position": static[0]["position"],
                "static_fov_degrees": static[0]["angle"], "migration": migration, "clone_checked": True, "failure_checked": True}

    def check_camera_legacy_migration(self, camera):
        child = camera.GetDown()
        fov_id = self.c4d.DescID(self.c4d.DescLevel(self.c4d.CAMERAOBJECT_FOV_VERTICAL))
        aperture_id = self.c4d.DescID(self.c4d.DescLevel(self.c4d.CAMERAOBJECT_APERTURE))
        existing = child.FindCTrack(fov_id)
        self.assert_true(existing is not None, "Missing FOV input for legacy migration fixture")
        existing.Remove()
        legacy = self.c4d.CTrack(child, aperture_id)
        curve = legacy.GetCurve()
        for frame, degrees in ((0, 45.), (2, 60.)):
            key = curve.AddKey(self.c4d.BaseTime(frame, 30))["key"]
            key.SetValue(curve, degrees)
            key.SetInterpolation(curve, self.c4d.CINTERPOLATION_SPLINE)
            key.SetTimeLeft(curve, self.c4d.BaseTime(-1, 60))
            key.SetTimeRight(curve, self.c4d.BaseTime(1, 60))
            key.SetValueLeft(curve, -3.)
            key.SetValueRight(curve, 5.)
        before = [{"value": curve.GetKey(index).GetValue(), "left": curve.GetKey(index).GetValueLeft(),
                   "right": curve.GetKey(index).GetValueRight(), "time_left": curve.GetKey(index).GetTimeLeft().Get(),
                   "time_right": curve.GetKey(index).GetTimeRight().Get(),
                   "interpolation": curve.GetKey(index).GetInterpolation()} for index in range(curve.GetKeyCount())]
        child.InsertTrackSorted(legacy)
        marker = self.ids["MMD_CAMERA_ANIMATION_SCHEMA_VERSION"]
        camera[marker] = 0
        self.doc.SetActiveObject(camera)
        self.call("export_camera", self.output / "migrated_camera.vmd", bake=True)
        self.assert_true(int(camera[marker]) == self.ids["MMD_CAMERA_ANIMATION_SCHEMA_VERTICAL_FOV_RADIANS"],
                         "Camera migration did not persist schema marker")
        self.assert_true(child.FindCTrack(aperture_id) is None, "Migration left legacy aperture animation active")
        migrated = child.FindCTrack(fov_id)
        self.assert_true(migrated is not None, "Migration did not create FOV animation")
        migrated_curve = migrated.GetCurve()
        self.assert_true(migrated_curve.GetKeyCount() == len(before), "Migration changed key count")
        for index, expected in enumerate(before):
            key = migrated_curve.GetKey(index)
            self.assert_true(self.near([key.GetValue(), key.GetValueLeft(), key.GetValueRight()],
                                      [math.radians(expected["value"]), math.radians(expected["left"]),
                                       math.radians(expected["right"])], 1e-6), "Migration did not scale values/tangents")
            self.assert_true(key.GetTimeLeft().Get() == expected["time_left"] and
                             key.GetTimeRight().Get() == expected["time_right"] and
                             key.GetInterpolation() == expected["interpolation"], "Migration changed timing/interpolation")
        first_values = [migrated_curve.GetKey(index).GetValue() for index in range(len(before))]
        self.call("export_camera", self.output / "migrated_again.vmd", bake=True)
        self.assert_true(first_values == [migrated_curve.GetKey(index).GetValue() for index in range(len(before))],
                         "Camera FOV was migrated more than once")
        self.reopen("camera_migration")
        reopened = self.nodes(CAMERA_ID)[0]
        self.assert_true(int(reopened[marker]) == 1, "Camera schema marker did not survive save/reopen")
        reopened_curve = reopened.GetDown().FindCTrack(fov_id).GetCurve()
        self.assert_true(self.near(first_values, [reopened_curve.GetKey(index).GetValue() for index in range(len(before))]),
                         "Migrated camera FOV changed after reopen")
        return {"old_values_degrees": [key["value"] for key in before], "new_values_radians": first_values,
                "tangents_scaled": True, "repeat_unchanged": True, "reopen_confirmed": True}


def run(manifest_path):
    import c4d
    manifest_path = Path(manifest_path).resolve()
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    if manifest.get("schema_version") != 1 or manifest.get("cases") != list(CASE_NAMES):
        raise ValueError("Manifest schema/case set is incompatible")
    receipt = {"schema_version": 1, "started_utc": utc_now(), "manifest": str(manifest_path),
               "revision": manifest["revision"], "source_sha256": manifest["source_sha256"], "sdk": manifest["sdk"],
               "c4d_version": c4d.GetC4DVersion(), "native_executed": False, "cases": [], "acceptance_eligible": False}
    output = Path(manifest["output"])
    suite = Suite(c4d, manifest)
    receipt["document_owner_run_id"] = suite.document_owner_run_id
    receipt["cleanup"] = []

    def write_receipt():
        (output / "receipt.json").write_text(json.dumps(receipt, indent=2, ensure_ascii=False), encoding="utf-8")

    def cleanup_suite():
        cleanup = suite.close()
        receipt["cleanup"].append(cleanup)
        receipt["original_document_restored"] = cleanup["original_document_restored"]
        return cleanup

    try:
        try:
            loaded = loaded_plugin_binary()
        except Exception as error:
            loaded = None
            receipt["identity_error"] = str(error)
        receipt["loaded_plugin"] = loaded
        receipt["binary_identity_confirmed"] = bool(loaded and manifest["plugin_binary"] and
                                                     loaded["sha256"] == manifest["plugin_binary"]["sha256"])
        for name in CASE_NAMES:
            started = utc_now()
            receipt["native_executed"] = True
            try:
                result = getattr(suite, name)()
                receipt["cases"].append({"name": name, "status": "passed", "native_executed": True,
                                         "started_utc": started, "evidence": result})
            except Exception as error:
                receipt["cases"].append({"name": name, "status": "failed", "native_executed": True,
                                         "started_utc": started, "error": str(error), "traceback": traceback.format_exc(),
                                         "failure_scenes": suite.save_failure_scenes(name)})
            finally:
                # Persist the original case outcome before cleanup can fail.
                try:
                    write_receipt()
                finally:
                    cleanup_suite()
                write_receipt()
        passed = all(case["status"] == "passed" for case in receipt["cases"])
        receipt["acceptance_eligible"] = passed and receipt["binary_identity_confirmed"]
        receipt["status"] = "passed" if receipt["acceptance_eligible"] else "failed" if not passed else "identity_unverified"
    finally:
        try:
            write_receipt()
        finally:
            cleanup_suite()
        cleanup_ok = not any(cleanup["errors"] or cleanup["remaining_owned_documents"] for cleanup in receipt["cleanup"])
        restored = receipt["original_document_restored"]
        receipt["acceptance_eligible"] = receipt["acceptance_eligible"] and cleanup_ok and restored
        if not cleanup_ok or not restored:
            receipt["cleanup_complete"] = False
            if receipt.get("status") == "passed":
                receipt["status"] = "cleanup_failed"
        else:
            receipt["cleanup_complete"] = True
        c4d.EventAdd()
        receipt["finished_utc"] = utc_now()
        write_receipt()
    return receipt


if __name__ == "__main__":
    if "c4d" in sys.modules or os.environ.get("CMT_REGRESSION_MANIFEST"):
        manifest_path = os.environ.get("CMT_REGRESSION_MANIFEST")
        if not manifest_path:
            raise RuntimeError("Set CMT_REGRESSION_MANIFEST to the prepared manifest.json path")
        print(json.dumps(run(manifest_path), indent=2, ensure_ascii=True))
    else:
        parser = argparse.ArgumentParser(description=__doc__)
        parser.add_argument("--prepare", action="store_true", required=True)
        parser.add_argument("--output", type=Path, required=True)
        parser.add_argument("--sdk", default="sdk_2026")
        parser.add_argument("--binary", type=Path)
        arguments = parser.parse_args()
        print(prepare(arguments.output, arguments.sdk, arguments.binary))
