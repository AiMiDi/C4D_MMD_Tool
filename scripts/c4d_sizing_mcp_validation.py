"""Validate sizing through real stdio typed tools on an already configured C4D.

Uses owned synthetic documents and the normal production API. The optional
--ui-regression mode additionally exercises the command-owned panel through the
test-only runtime bridge, on an isolated test host with an empty panel queue.
Does not start/restart C4D or enable its MCP server. A missing bridge is blocked,
not a UI pass; default production validation still requires the bridge disabled.
Requires an existing nonempty baseline document; it never populates or changes
the user's startup document to prevent C4D from automatically closing it.
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import json
from pathlib import Path
import re
import struct
import sys
import time
import uuid

from c4d_production_mcp_validation import StdioClient, extract_marker
from c4d_runtime_regression import load_resource_ids
from mmdtool_mcp.host import HostConnection
from mmdtool_mcp.schema import TOOL_BY_NAME, validate

ROOT = Path(__file__).resolve().parents[1]
STAGES = ("original", "scale", "offset", "stance", "twist", "avoidance", "contact", "multi_character")
MARKER = "CMT_SIZING_TEST:"
UI_CONTROLS = {"source": 2000, "motion": 2002, "target_pick": 2004,
               "movement": 2006, "calculate": 2010, "queue": 2216,
               "queue_add": 2217, "queue_remove": 2218, "slot": 2219, "live_preview": 2220}
UI_FIELDS = {"report": 1000062, "slot": 1000063, "movement": 1000064,
             "source": 1000065, "motion": 1000066, "queue_count": 1000067,
             "target": 1000068, "stored_source": 1000070, "stored_motion": 1000071,
             "stored_movement": 1000072, "stored_slot": 1000073}

# This helper only manages documents owned by this validation run. All sizing,
# import/export and result calls go through the actual adapter subprocess.
# Only explicitly requested UI regression actions use the test-only bridge.
HELPER = '''import base64, builtins, json, os, sys, uuid, c4d
p = json.loads(base64.b64decode("__PAYLOAD__"))
registry = getattr(builtins, "_cmt_sizing_mcp_tests", {})
builtins._cmt_sizing_mcp_tests = registry
state = registry.get(p["run"])
def live(doc):
    if doc is None: return False
    try:
        doc.GetDocumentName()
    except ReferenceError:
        return False
    node = c4d.documents.GetFirstDocument()
    while node:
        if node == doc: return True
        node = node.GetNext()
    return False
def snapshot(doc):
    return {"time": doc.GetTime().Get(), "slots": [int(o[p["ids"]["MODEL_ANIM_LIST"]])
        for o in doc.GetObjects() if o.GetType() == 1056724]}
def camera_roots(doc):
    return [o for o in doc.GetObjects() if o.GetType() == 1056978]

def matrix_values(matrix):
    return [[v.x, v.y, v.z] for v in (matrix.off, matrix.v1, matrix.v2, matrix.v3)]

def matrix_error(left, right):
    return max((getattr(left, key) - getattr(right, key)).GetLength()
               for key in ("off", "v1", "v2", "v3"))

def sample_camera(doc, camera):
    # Evaluation is temporary: comparison must not move the source playhead.
    time = doc.GetTime()
    try:
        doc.SetTime(c4d.BaseTime(15, 30))
        doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
        return c4d.Matrix(camera.GetMg())
    finally:
        doc.SetTime(time)
        doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)

def camera_pair(doc):
    roots = camera_roots(doc)
    pair = {}
    for role, labels in p["camera_labels"].items():
        matching = [root for root in roots if root.GetName() in labels]
        if len(matching) != 1:
            raise RuntimeError("Expected one resource-named camera for " + role)
        pair[role] = matching[0]
    return pair

def camera_style(root, color):
    child = root.GetDown()
    valid_child = bool(child and child.GetType() == c4d.Ocamera)
    nodes = (root, child) if valid_child else (root,)
    icon_supported = all(hasattr(c4d, key) for key in (
        "ID_BASELIST_ICON_COLOR", "ID_BASELIST_ICON_COLORIZE_MODE", "ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM"))
    def vector(value):
        return [value.x, value.y, value.z] if isinstance(value, c4d.Vector) else None
    return {"name": root.GetName(), "camera_child": valid_child,
            "viewport_colors": [vector(node[c4d.ID_BASEOBJECT_COLOR]) for node in nodes],
            "viewport_ok": all(isinstance(node[c4d.ID_BASEOBJECT_COLOR], c4d.Vector) and
                (node[c4d.ID_BASEOBJECT_COLOR] - color).GetLength() < 1e-6 and
                node[c4d.ID_BASEOBJECT_USECOLOR] == c4d.ID_BASEOBJECT_USECOLOR_ALWAYS for node in nodes),
            "icon_supported": icon_supported,
            "icon_colors": [vector(node[c4d.ID_BASELIST_ICON_COLOR]) for node in nodes] if icon_supported else [],
            "icon_ok": all(isinstance(node[c4d.ID_BASELIST_ICON_COLOR], c4d.Vector) and
                (node[c4d.ID_BASELIST_ICON_COLOR] - color).GetLength() < 1e-6 and
                node[c4d.ID_BASELIST_ICON_COLORIZE_MODE] == c4d.ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM
                for node in nodes) if icon_supported else None}

def inspect_camera_pair(doc, reference):
    pair = camera_pair(doc)
    expected = sample_camera(state["doc"], state["camera_reference"].GetDown())
    original = sample_camera(doc, pair["original"].GetDown())
    return {"count": len(camera_roots(doc)), "roles": {
                "original": camera_style(pair["original"], c4d.Vector(.15, .45, 1.)),
                "adjusted": camera_style(pair["adjusted"], c4d.Vector(1., .5, .1))},
            "original_error": matrix_error(expected, original),
            "reference_unchanged_error": matrix_error(expected, state["camera_reference_matrix"]),
            "reference_present": reference in camera_roots(doc) if reference is not None else False,
            "original_matrix": matrix_values(original), "reference_matrix": matrix_values(expected)}

def reload_owned(doc, path):
    if not c4d.documents.SaveDocument(doc, path, c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
        raise RuntimeError("Owned document save failed")
    reopened = c4d.documents.LoadDocument(path, c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
    if not reopened: raise RuntimeError("Owned document reload failed")
    state["extra"].append(reopened)
    c4d.documents.InsertBaseDocument(reopened)
    return reopened

action = p["action"]
result = {}
if action == "identity":
    sys.path.insert(0, p["repository"] + "/scripts")
    import c4d_runtime_regression as regression
    result = {"pid": os.getpid(), "c4d_version": c4d.GetC4DVersion(),
              "loaded_binary": regression.loaded_plugin_binary()}
elif action == "setup":
    if state: raise RuntimeError("Run already owns documents")
    original = c4d.documents.GetActiveDocument()
    if not live(original) or not (original.GetFirstObject() or original.GetFirstMaterial()):
        raise RuntimeError("A nonempty baseline document is required before setup")
    doc = c4d.documents.BaseDocument()
    doc.SetDocumentName("Sizing MCP " + p["run"])
    # Register before insertion: the outer exec wrapper can fail after native
    # side effects, and cleanup must still discover this exact owned document.
    registry[p["run"]] = {"original": original, "doc": doc, "extra": []}
    c4d.documents.InsertBaseDocument(doc)
    c4d.documents.SetActiveDocument(doc)
    result = {"name": doc.GetDocumentName()}
elif action == "baseline":
    original = c4d.documents.GetActiveDocument()
    result = {"usable": bool(live(original) and (original.GetFirstObject() or original.GetFirstMaterial())),
              "reason": "An existing document with an object or material is required; inserting a test document can close C4D's empty startup document."}
elif action == "owned_state":
    result = {"registry_present": state is not None,
              "source_document_live": bool(state and live(state["doc"])),
              "original_document_live": bool(state and live(state["original"])),
              "remaining_owned_documents": []}
    if state:
        result["remaining_owned_documents"] = [d.GetDocumentName() for d in state["extra"] + [state["doc"]] if live(d)]
elif action == "activate_cleanup_baseline":
    if not state: raise RuntimeError("Owned-document registry is unavailable")
    original = state["original"]
    candidate = original if live(original) else None
    if candidate is None:
        owned = [d for d in state["extra"] + [state["doc"]] if live(d)]
        node = c4d.documents.GetFirstDocument()
        while node:
            if all(node != document for document in owned):
                candidate = node
                break
            node = node.GetNext()
    if candidate is None:
        raise RuntimeError("No surviving non-owned baseline; leave owned documents registered for cleanup")
    c4d.documents.SetActiveDocument(candidate)
    result = {"activated": True, "original_document_restored": live(original) and candidate == original}
elif action == "cleanup":
    result = {"registry_present": False, "remaining_owned_documents": []}
    if state:
        owned = [doc for doc in state["extra"] + [state["doc"]] if live(doc)]
        if any(c4d.documents.GetActiveDocument() == doc for doc in owned):
            raise RuntimeError("Activate a surviving baseline in a separate request before cleanup")
        for doc in owned: c4d.documents.KillDocument(doc)
        if live(state["original"]): c4d.documents.SetActiveDocument(state["original"])
        result = {"original_document_restored": live(state["original"]) and c4d.documents.GetActiveDocument() == state["original"],
                  "remaining_owned_documents": [d.GetDocumentName() for d in state["extra"] + [state["doc"]] if live(d)]}
        if not result["remaining_owned_documents"]: del registry[p["run"]]
        result["registry_present"] = p["run"] in registry
elif action == "activate_original":
    if not state or not live(state["original"]): raise RuntimeError("Original document is unavailable")
    c4d.documents.SetActiveDocument(state["original"])
    result = {"activated": True}
else:
    if not state or not live(state["doc"]): raise RuntimeError("Owned source is unavailable")
    doc = state["doc"]
    models = [o for o in doc.GetObjects() if o.GetType() == 1056724]
    if action == "active_name":
        result = {"name": c4d.documents.GetActiveDocument().GetDocumentName()}
    elif action == "activate_source":
        c4d.documents.SetActiveDocument(doc)
        result = {"activated": True}
    elif action == "invalid_packets":
        # Bypass client schema validation deliberately to exercise native type
        # checks. Each packet must be rejected before it can mutate the scene.
        hook = doc.FindSceneHook(1057017)
        if hook is None: raise RuntimeError("Production SceneHook is unavailable")
        before = snapshot(doc)
        objects = list(doc.GetObjects())
        cases = ("protocol", "operation", "operation_id", "options",
                 "characters", "character", "character_options", "sizing_options",
                 "movement_string", "movement_container", "avoidance_bodies", "body_name")
        observed = []
        for case in cases:
            request = c4d.BaseContainer()
            request.SetInt32(0, 1)
            request.SetString(1, "mmdtool_sizing_start")
            request.SetString(2, str(uuid.uuid4()))
            request.SetString(3, "")
            request.SetString(4, "")
            options = c4d.BaseContainer()
            values = c4d.BaseContainer()
            if case == "movement_string": values.SetString(149, "invalid")
            if case == "movement_container": values.SetContainer(149, c4d.BaseContainer())
            if case == "avoidance_bodies": values.SetString(168, "invalid")
            if case == "body_name":
                bodies = c4d.BaseContainer()
                bodies.SetInt32(0, 1)
                values.SetContainer(168, bodies)
            options.SetContainer(144, values)
            if case == "sizing_options": options.SetString(144, "invalid")
            if case in ("characters", "character", "character_options"):
                characters = c4d.BaseContainer()
                if case == "character": characters.SetString(0, "invalid")
                else:
                    character = c4d.BaseContainer()
                    character.SetString(144, "invalid")
                    characters.SetContainer(0, character)
                options.SetContainer(141, characters)
                if case == "characters": options.SetString(141, "invalid")
            request.SetContainer(5, options)
            if case == "protocol": request.SetString(0, "invalid")
            if case == "operation": request.SetInt32(1, 1)
            if case == "operation_id": request.SetInt32(2, 1)
            if case == "options": request.SetString(5, "invalid")
            packet = c4d.BaseContainer(1057017)
            packet.SetContainer(2000000, request)
            packet.SetString(2000001, "")
            hook.Message(c4d.MSG_BASECONTAINER, packet)
            raw = packet.GetString(2000001)
            if not raw:
                raw = hook.GetParameter(c4d.DescID(c4d.DescLevel(2000001, c4d.DTYPE_STRING, 0)), c4d.DESCFLAGS_GET_0)
            response = json.loads(raw)
            expected_id = "" if case == "operation_id" else request.GetString(2)
            observed.append({"case": case, "passed": response["code"] == "invalid_argument" and
                not response["success"] and bool(response["message"]) and response["operation_id"] == expected_id})
        # Malformed outer transport packets are safely ignored, rather than
        # reading a scalar as the request container or dispatching stale input.
        packet = c4d.BaseContainer(1057017)
        packet.SetString(2000000, "invalid")
        packet.SetString(2000001, "")
        hook.Message(c4d.MSG_BASECONTAINER, packet)
        observed.append({"case": "outer_request", "passed": packet.GetString(2000001) == "" and
            hook.GetParameter(c4d.DescID(c4d.DescLevel(2000001, c4d.DTYPE_STRING, 0)), c4d.DESCFLAGS_GET_0) == ""})
        packet.SetInt32(2000001, 1)
        hook.Message(c4d.MSG_BASECONTAINER, packet)
        observed.append({"case": "outer_response", "passed": packet.GetInt32(2000001) == 1 and
            hook.GetParameter(c4d.DescID(c4d.DescLevel(2000001, c4d.DTYPE_STRING, 0)), c4d.DESCFLAGS_GET_0) == ""})
        result = {"cases": observed, "scene_unchanged": snapshot(doc) == before and objects == list(doc.GetObjects())}
    elif action == "ui_request":
        hook = doc.FindSceneHook(1057017)
        result = {"accepted": False, "error": "Runtime regression SceneHook is unavailable"}
        if hook:
            hook[1000000] = 1
            hook[1000001] = p["operation"]
            hook[1000060] = p.get("control", 0)
            data = hook.GetDataInstance()
            data.RemoveData(1000061)  # Never reuse the previous command's value.
            for field in p["fields"].values(): data.RemoveData(field)
            hook[1000100] = False
            hook[1000101] = ""
            if "value" in p: hook[1000061] = p["value"]
            handled = hook.Message(1057017)
            result = {"accepted": bool(handled and hook[1000100]), "error": hook[1000101] or "",
                      "state": {name: hook[field] for name, field in p["fields"].items()}}
    elif action == "ui_select_model":
        # Imports insert at the head: the first typed model is last in this
        # run's two-model document. Keep normal helper ordering unchanged.
        if len(models) != 2: raise RuntimeError("UI fixture requires exactly two owned models")
        c4d.documents.SetActiveDocument(doc)
        doc.SetActiveObject(models[-1], c4d.SELECTION_NEW)
        c4d.EventAdd()
        result = {"target": models[-1].GetName()}
    elif action == "ui_delete_slot":
        if len(models) != 2: raise RuntimeError("UI fixture requires exactly two owned models")
        c4d.documents.SetActiveDocument(doc)
        doc.SetActiveObject(models[-1], c4d.SELECTION_NEW)
        c4d.CallButton(models[-1], p["ids"]["MODEL_ANIM_DElETE_BUTTON"])
        c4d.EventAdd()
        result = {"requested": True}
    elif action == "snapshot": result = snapshot(doc)
    elif action == "camera_reference":
        roots = camera_roots(doc)
        if len(roots) != 1 or not roots[0].GetDown() or roots[0].GetDown().GetType() != c4d.Ocamera:
            raise RuntimeError("Expected the single independently imported reference camera")
        state["camera_reference"] = roots[0]
        state["camera_reference_matrix"] = sample_camera(doc, roots[0].GetDown())
        result = {"name": roots[0].GetName(), "count": len(roots),
                  "matrix": matrix_values(state["camera_reference_matrix"]), "source": snapshot(doc)}
    elif action == "camera_preview":
        preview = c4d.documents.GetActiveDocument()
        if preview == doc or preview == state["original"] or preview.GetDocumentName() != p["name"]:
            raise RuntimeError("Expected this job's active preview document")
        pair = camera_pair(preview)
        view = preview.GetActiveBaseDraw()
        viewed = view.GetSceneCamera(preview)
        result = inspect_camera_pair(preview, None)
        result["viewed_role"] = next((role for role, root in pair.items() if viewed == root.GetDown()), None)
        view.SetSceneCamera(pair[p["select_role"]].GetDown())
        result["selected_role"] = p["select_role"]
        result["source"] = snapshot(doc)
    elif action in ("camera_applied", "camera_undo", "camera_redo", "camera_roundtrip"):
        if c4d.documents.GetActiveDocument() != doc:
            raise RuntimeError("Activate the owned source before camera mutation checks")
        reference = state["camera_reference"]
        if action == "camera_undo":
            ok = doc.DoUndo()
            result = {"ok": ok, "count": len(camera_roots(doc)),
                      "reference_present": camera_roots(doc) == [reference], "source": snapshot(doc)}
        else:
            ok = doc.DoRedo() if action == "camera_redo" else True
            observed = reload_owned(doc, p["path"]) if action == "camera_roundtrip" else doc
            if observed != doc:
                reference = next((root for root in camera_roots(observed)
                                  if root.GetName() == reference.GetName()), None)
            result = inspect_camera_pair(observed, reference)
            if reference is not None:
                result["saved_reference_error"] = matrix_error(sample_camera(observed, reference.GetDown()),
                                                                state["camera_reference_matrix"])
            result.update(ok=ok, source=snapshot(doc))
    elif action == "preview_snapshot":
        preview = c4d.documents.GetActiveDocument()
        if preview == doc or preview == state["original"] or preview.GetDocumentName() != p["name"]:
            raise RuntimeError("Expected this job's active preview document")
        if "frame" in p:
            preview.SetTime(c4d.BaseTime(p["frame"], 30))
            preview.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
        result = {"min": preview.GetMinTime().GetFrame(30), "max": preview.GetMaxTime().GetFrame(30),
                  "loop_min": preview.GetLoopMinTime().GetFrame(30),
                  "loop_max": preview.GetLoopMaxTime().GetFrame(30), "time": preview.GetTime().GetFrame(30)}
    elif action == "undo": result = {"ok": doc.DoUndo(), "snapshot": snapshot(doc)}
    elif action == "redo": result = {"ok": doc.DoRedo(), "snapshot": snapshot(doc)}
    elif action == "stale":
        models[0][p["ids"]["MODEL_POSITION_MULTIPLE"]] *= 2
        result = {"changed": True}
    elif action == "roundtrip":
        result = snapshot(reload_owned(doc, p["path"]))
    else: raise RuntimeError("Unknown owned-document action")
print("CMT_SIZING_TEST:" + json.dumps(result, ensure_ascii=False))
'''


def camera_resource_labels(binary):
    """Use the loaded plugin's translated strings, including escaped Unicode."""
    labels = {"original": [], "adjusted": []}
    symbols = {"original": "IDS_SIZING_CAMERA_ORIGINAL", "adjusted": "IDS_SIZING_CAMERA_RESULT"}
    for path in sorted((binary.parent / "res").glob("strings_*/c4d_strings.str")):
        text = path.read_text(encoding="utf-8-sig")
        for role, symbol in symbols.items():
            match = re.search(r'\b' + symbol + r'\s+("(?:\\.|[^"\\])*")\s*;', text)
            if match:
                label = json.loads(match.group(1))
                if label not in labels[role]: labels[role].append(label)
    if not all(labels.values()):
        raise RuntimeError("Loaded plugin resources do not contain both comparison camera labels")
    return labels


def preview_range_fixtures(directory, fixture):
    """Make unequal-duration files without changing any maintained fixture.

    Keep all real fixture bone channels and curves. The extra morph is an
    intentionally unbound pass-through track; the model-info key exercises a
    real IK channel and remains visible. Each can outlast the bone animation.
    """
    motion = (fixture / "motion.vmd").read_bytes()
    count = struct.unpack_from("<I", motion, 50)[0]
    bone_end = 54 + count * 111
    records = [motion[54 + i * 111:54 + (i + 1) * 111] for i in range(count)]
    last = max(struct.unpack_from("<I", record, 15)[0] for record in records)
    if not last or any(motion[bone_end:]):
        raise ValueError("Range fixture expects bone animation with empty optional sections")

    def write_motion(name, end, morph_end=None, ik_end=None):
        data = bytearray(motion[:54])
        for original in records:
            record = bytearray(original)
            frame = struct.unpack_from("<I", record, 15)[0]
            struct.pack_into("<I", record, 15, round(frame * end / last))
            data.extend(record)
        data.extend(struct.pack("<I", int(morph_end is not None)))
        if morph_end is not None:
            data.extend(b"range_test".ljust(15, b"\0") + struct.pack("<If", morph_end, .5))
        data.extend(struct.pack("<3I", 0, 0, 0))  # Camera, light and shadow.
        data.extend(struct.pack("<I", int(ik_end is not None)))
        if ik_end is not None:
            data.extend(struct.pack("<IBI", ik_end, 1, 1))
            data.extend("左足ＩＫ".encode("shift_jis").ljust(20, b"\0") + b"\1")
        path = directory / (name + ".vmd")
        path.write_bytes(data)
        return path

    paths = {"short": write_motion("range-short", 60),
             "bone": write_motion("range-bone", 180),
             "morph": write_motion("range-morph", 180, morph_end=240),
             "ik": write_motion("range-ik", 180, ik_end=300)}
    camera = bytearray((fixture / "camera.vmd").read_bytes())
    # The maintained camera fixture has zero bone/morph keys and two cameras.
    if struct.unpack_from("<3I", camera, 50) != (0, 0, 2):
        raise ValueError("Unexpected camera fixture layout")
    struct.pack_into("<I", camera, 62 + 61, 360)
    paths["camera"] = directory / "range-camera.vmd"
    paths["camera"].write_bytes(camera)
    return paths


class SizingValidation:
    def __init__(self, args):
        self.args = args
        self.ui_mode = bool(getattr(args, "ui_regression", False))
        self.output = Path(args.output).resolve()
        self.output.mkdir(parents=True, exist_ok=True)
        if (self.output / "receipt.json").exists():
            raise ValueError("Use a new output directory for each run")
        self.run_id = str(uuid.uuid4())
        self.ids = load_resource_ids(ROOT)
        self.host = HostConnection(args.endpoint, args.token_file, args.timeout)
        self.client = None
        self.jobs = []
        self.owned = False
        self.setup_attempted = False
        self.ui_close_needed = False
        self.ui_queue_owned = False
        self.ui_owned_target = None
        self.doc = ""
        self.receipt = {"run_id": self.run_id, "kind": "synthetic-production-sizing-mcp",
                        "status": "incomplete", "checks": [], "native_executed": False,
                        "ui_regression_requested": self.ui_mode, "ui_native_executed": False,
                        "remaining_owned_documents": []}

    def save(self):
        (self.output / "receipt.json").write_text(json.dumps(self.receipt, ensure_ascii=False, indent=2), encoding="utf-8")

    def check(self, name, passed):
        self.receipt["checks"].append({"name": name, "passed": bool(passed)})
        self.save()
        if not passed:
            raise AssertionError(name)

    def helper(self, action, **values):
        payload = {"action": action, "run": self.run_id, "repository": str(ROOT), "ids": self.ids, **values}
        code = HELPER.replace("__PAYLOAD__", base64.b64encode(json.dumps(payload).encode()).decode())
        result = self.host.request("tools/call", {"name": "exec_python", "arguments": {
            "code": code, "timeout_seconds": self.args.timeout, "max_iterations": 50000000}}, may_mutate=action != "identity")
        with (self.output / "helper-responses.jsonl").open("a", encoding="utf-8") as log:
            log.write(json.dumps({"action": action, "result": result}, ensure_ascii=False) + "\n")
        return extract_marker(result, MARKER)

    def call(self, suffix, arguments=None, *, expected=True, operation_id=None):
        name = "mmdtool_" + suffix
        arguments = dict(arguments or {})
        if operation_id:
            arguments["operation_id"] = operation_id
        response = self.client.request("tools/call", {"name": name, "arguments": arguments})
        if "error" in response:
            raise AssertionError(response["error"])
        result = response["result"]["structuredContent"]
        validate(result, TOOL_BY_NAME[name]["outputSchema"])
        with (self.output / "transcript.jsonl").open("a", encoding="utf-8") as stream:
            stream.write(json.dumps({"tool": name, "arguments": arguments, "result": result}, ensure_ascii=False) + "\n")
        if result["success"] != expected:
            raise AssertionError(f"{name}: {result['code']}: {result['message']}")
        return result

    def wait_job(self, job):
        deadline = time.monotonic() + 120
        while time.monotonic() < deadline:
            data = self.call("sizing_status", {"document": self.doc, "job": job})["data"]
            if data["job_state"] not in ("running", "cancelling"):
                return data
            time.sleep(.1)  # Outside C4D, never block the UI thread.
        raise TimeoutError("Sizing worker did not finish within the validation budget")

    def ui_request(self, operation, control=None, value=None, *, required=True):
        """One host request per operation; allow the native UI to pump outside it."""
        arguments = {"operation": operation, "fields": UI_FIELDS}
        if control is not None:
            arguments["control"] = UI_CONTROLS[control]
        if value is not None:
            arguments["value"] = value
        result = self.helper("ui_request", **arguments)
        time.sleep(.3)  # This script runs outside C4D. Never sleep in HELPER.
        self.receipt.setdefault("ui_observations", []).append(
            {"operation": operation, "control": control, "value": value, **result})
        self.save()
        if required and not result["accepted"]:
            raise AssertionError("UI bridge rejected operation: " + result["error"])
        return result

    def ui_command(self, control=None, value=None):
        return self.ui_request(29, control, value)["state"]

    def ui_close(self):
        self.ui_request(28)
        self.ui_close_needed = False

    def ui_open(self):
        # Set before dispatch so cleanup also handles a partially opened dialog.
        self.ui_close_needed = True
        self.ui_request(27)
        return self.ui_command()

    def ui_clear_owned_queue(self):
        """Only clear the one entry created after observing an empty panel."""
        if not self.ui_queue_owned:
            return
        state = self.ui_command() if self.ui_close_needed else self.ui_open()
        self.ui_command("live_preview", 0)
        if state["queue_count"]:
            if state["queue_count"] != 1 or state["target"] != self.ui_owned_target:
                raise AssertionError("Panel queue no longer matches this run's owned single entry")
            self.ui_command("queue", 0)
            state = self.ui_command("queue_remove")
        self.receipt["ui_cleanup_queue"] = state
        self.check("ui_owned_queue_removed", state["queue_count"] == 0)
        self.ui_queue_owned = False

    def ui_regression(self, fixture, models, slots):
        """Exercise the real command's panel, never another dialog instance."""
        def has_ui_state(response):
            value = response.get("state", {})
            return (response["accepted"] and isinstance(value.get("queue_count"), int) and
                    isinstance(value.get("slot"), int) and
                    isinstance(value.get("movement"), (int, float)) and
                    isinstance(value.get("source"), str) and isinstance(value.get("motion"), str))

        bridge = self.ui_request(0, required=False)
        self.receipt["ui_bridge_available"] = bridge["accepted"]
        if not bridge["accepted"]:
            self.receipt.update(status="blocked", reason="Loaded DLL has no usable runtime UI regression bridge; no UI acceptance performed.")
            return
        # Preserve an already open, populated artist panel. Closed command
        # rejection is also checked later against a panel this run owns.
        existing = self.ui_request(29, required=False)
        if has_ui_state(existing) and existing["state"]["queue_count"]:
            self.receipt.update(status="blocked", reason="UI regression requires an isolated host with an empty panel queue; existing queue preserved.")
            return
        self.ui_close_needed = True
        if has_ui_state(existing):
            observed = existing
        else:
            opened = self.ui_request(27, required=False)
            observed = self.ui_request(29, required=False)
            if not opened["accepted"] or not has_ui_state(observed):
                # A handshake alone does not prove the newer UI operations.
                # Attempt Close in its own request even for a partial Open.
                self.ui_request(28, required=False)
                self.ui_close_needed = False
                self.receipt.update(status="blocked", reason="Loaded DLL does not support command-owned UI operations and state fields; no UI acceptance performed.")
                return
        self.receipt["ui_command_bridge_available"] = True
        state = observed["state"]
        if state["queue_count"]:
            self.receipt.update(status="blocked", reason="Closed panel retained a nonempty queue; queue preserved and no UI checks performed.")
            return
        self.ui_queue_owned = True
        self.receipt["ui_native_executed"] = True
        self.ui_command("live_preview", 0)
        selected = self.helper("ui_select_model")
        self.ui_owned_target = selected["target"]
        time.sleep(.3)
        self.ui_command("target_pick")
        source, motion = str(fixture / "source.pmx"), str(fixture / "motion.vmd")
        self.ui_command("source", source)
        self.ui_command("motion", motion)
        self.ui_command("slot", 1)
        self.ui_command("movement", 2.7)
        state = self.ui_command("queue_add")
        identity = state["stored_slot"]

        def paths_match(value):
            return all(value[key] == path for key, path in (
                ("source", source), ("stored_source", source),
                ("motion", motion), ("stored_motion", motion)))

        def movement_matches(value, expected):
            return all(abs(value[key] - expected) < 1.e-9 for key in ("movement", "stored_movement"))

        self.check("ui_queue_created_with_scene_slot", state["queue_count"] == 1 and
                   state["slot"] == 1 and identity > 0 and state["target"] == selected["target"] and
                   paths_match(state) and movement_matches(state, 2.7))
        self.ui_close()
        self.check("ui_closed_dialog_rejects_command", not self.ui_request(29, required=False)["accepted"])
        state = self.ui_open()
        self.check("ui_queue_restored_after_reopen", state["queue_count"] == 1 and paths_match(state) and
                   movement_matches(state, 2.7) and state["slot"] == 1 and state["stored_slot"] == identity)
        self.ui_command("live_preview", 0)
        target = {"document": self.doc, "model": models[0]}
        self.call("select_animation_slot", {**target, "slot": slots[0]})
        count = self.call("list_animation_slots", target)["data"]["total"]
        self.helper("ui_delete_slot")
        time.sleep(.3)
        self.check("ui_owned_scene_slot_deleted", self.call("list_animation_slots", target)["data"]["total"] == count - 1)
        state = self.ui_command("queue", 0)
        self.check("ui_missing_slot_remains_explicit", state["slot"] != 0 and state["stored_slot"] == identity)
        edited = self.ui_command("movement", 1.1)
        self.check("ui_edit_preserves_missing_identity", edited["slot"] != 0 and
                   edited["stored_slot"] == identity and movement_matches(edited, 1.1))
        rejected = self.ui_command("calculate")
        self.check("ui_missing_slot_calculate_reports_error", bool(rejected["report"]) and
                   rejected["report"] != edited["report"] and rejected["slot"] != 0 and
                   rejected["stored_slot"] == identity)
        state = self.ui_command("slot", 0)
        self.check("ui_explicit_file_selection", state["slot"] == 0 and state["stored_slot"] == 0 and paths_match(state))
        self.ui_close()

        def start_file_job(multiplier):
            job = self.call("sizing_start", {"document": self.doc, "characters": [{
                "model": models[0], "source_pmx": source, "path": motion}],
                "sizing_options": {"movement_multiplier": multiplier}})["data"]["job"]
            self.jobs.append(job)
            self.check("ui_mcp_job_completed_" + str(multiplier), self.wait_job(job)["job_state"] == "completed")
            return job

        original_job = start_file_job(.8)
        state = self.ui_open()
        self.check("ui_mcp_initial_sync", state["queue_count"] == 1 and movement_matches(state, .8) and paths_match(state))
        self.ui_command("live_preview", 0)
        state = self.ui_command("movement", 2.7)
        self.check("ui_mcp_local_edit", movement_matches(state, 2.7))
        self.ui_close()
        state = self.ui_open()
        self.check("ui_mcp_local_edit_survives_reopen", movement_matches(state, 2.7) and paths_match(state))
        self.check("ui_mcp_original_job_preserved", self.call("sizing_status", {
            "document": self.doc, "job": original_job})["data"]["job_state"] == "completed")
        self.ui_close()
        start_file_job(.9)  # New publication while the panel is closed.
        state = self.ui_open()
        self.check("ui_mcp_new_publication_received", movement_matches(state, .9) and paths_match(state))
        self.check("ui_mcp_original_job_still_completed", self.call("sizing_status", {
            "document": self.doc, "job": original_job})["data"]["job_state"] == "completed")
        self.ui_close()
        self.receipt["status"] = "passed"

    def preview_ranges(self, fixture, models):
        paths = preview_range_fixtures(self.output, fixture)
        source_before = self.helper("snapshot")
        options = {name: False for name in ("stance", "twist", "avoidance", "wrist_contact",
                                           "finger_contact", "floor_contact", "multi_contact")}
        for kind, end in (("bone", 180), ("morph", 240), ("ik", 300), ("camera", 360)):
            for reverse in (False, True):
                paths_in_order = [paths["ik" if kind == "camera" else kind], paths["short"]]
                if reverse:
                    paths_in_order.reverse()
                arguments = {"document": self.doc, "characters": [
                    {"model": model, "source_pmx": str(fixture / "source.pmx"), "path": str(path)}
                    for model, path in zip(models, paths_in_order)], "sizing_options": options}
                if kind == "camera":
                    arguments["camera_path"] = str(paths["camera"])
                job = self.call("sizing_start", arguments)["data"]["job"]
                self.jobs.append(job)
                label = f"preview_range_{kind}_{'short_first' if reverse else 'long_first'}"
                self.check(label + "_completed", self.wait_job(job)["job_state"] == "completed")
                base = {"document": self.doc, "job": job}
                for stage in ("original", "offset", "multi_character"):
                    result = self.call("sizing_preview", {**base, "stage": stage})["data"]
                    preview_name = next(d["name"] for d in self.call("capabilities")["data"]["documents"]
                                        if d["handle"] == result["preview_document"])
                    observed = self.helper("preview_snapshot", name=preview_name)
                    self.receipt.setdefault("preview_ranges", []).append(
                        {"case": label, "stage": stage, "expected_max": end, **observed})
                    self.check(label + "_" + stage, observed["max"] == end and observed["loop_max"] == end
                               and observed["min"] == 0 and observed["loop_min"] == 0)
                    if stage != "original":
                        self.check(label + "_" + stage + "_playhead", observed["time"] == 75)
                    self.helper("preview_snapshot", name=preview_name, frame=75)
                    self.check(label + "_" + stage + "_source_unchanged", self.helper("snapshot") == source_before)
                self.call("sizing_close_preview", base)
                self.call("sizing_release", base)
                self.jobs.remove(job)

    def check_camera_pair(self, label, observed, expected_count):
        """Record numerical evidence before asserting role, storage and color behavior."""
        self.receipt.setdefault("camera_observations", {})[label] = observed
        self.check(label + "_pair", observed["count"] == expected_count and all(
            role["camera_child"] for role in observed["roles"].values()))
        self.check(label + "_colors", all(role["viewport_ok"] and
                   (not role["icon_supported"] or role["icon_ok"]) for role in observed["roles"].values()))
        self.check(label + "_original_track", observed["original_error"] < 1e-5 and
                   observed["reference_unchanged_error"] < 1e-5)
        if expected_count == 3:
            self.check(label + "_reference_preserved", observed["reference_present"] and
                       observed.get("saved_reference_error", float("inf")) < 1e-5)

    def camera_apply_regression(self, base, labels, source_before):
        self.call("sizing_apply_camera", base)
        applied = self.helper("camera_applied", camera_labels=labels)
        self.check_camera_pair("camera_apply", applied, 3)
        self.check("camera_apply_source_unchanged", applied["source"] == source_before)
        undone = self.helper("camera_undo")
        self.receipt["camera_observations"]["undo"] = undone
        self.check("camera_single_undo", undone["ok"] and undone["count"] == 1 and
                   undone["reference_present"] and undone["source"] == source_before)
        redone = self.helper("camera_redo", camera_labels=labels)
        self.check_camera_pair("camera_redo", redone, 3)
        self.check("camera_single_redo", redone["ok"] and redone["source"] == source_before)
        reopened = self.helper("camera_roundtrip", camera_labels=labels, path=str(self.output / "camera-pair.c4d"))
        self.check_camera_pair("camera_save_reload", reopened, 3)
        self.check("camera_save_reload_source_unchanged", reopened["source"] == source_before)

    def execute(self):
        self.host.initialize()
        self.client = StdioClient(self.args.endpoint, self.args.token_file, self.args.timeout)
        listed = self.client.request("tools/list", {})["result"]["tools"]
        self.check("stdio_sizing_discovery", len([t for t in listed if t["name"].startswith("mmdtool_sizing_")]) == 11)
        capabilities = self.call("capabilities")["data"]
        if "mmdtool_sizing_start" not in capabilities["supported_operations"]:
            self.receipt.update(status="blocked", reason="Loaded plugin does not expose sizing; load the new ordinary Release first.")
            return
        self.receipt["host"] = self.helper("identity")
        expected = Path(self.args.expected_binary).resolve()
        cache_path = Path(self.args.build_cache) if self.args.build_cache else expected.parents[4] / "CMakeCache.txt"
        cache = cache_path.read_text(encoding="utf-8")
        # The loaded binary and actual bridge response are authoritative for
        # UI mode: an SDK cache can describe a different, subsequently rebuilt
        # output from the private DLL this test host still has loaded.
        self.receipt["cached_runtime_regression"] = (
            "ON" if "CMT_ENABLE_RUNTIME_REGRESSION:BOOL=ON" in cache else
            "OFF" if "CMT_ENABLE_RUNTIME_REGRESSION:BOOL=OFF" in cache else "unknown")
        if not self.ui_mode:
            self.check("runtime_regression_off", self.receipt["cached_runtime_regression"] == "OFF")
        self.receipt["build_cache"] = {"path": str(cache_path), "sha256": hashlib.sha256(cache_path.read_bytes()).hexdigest()}
        loaded = self.receipt["host"]["loaded_binary"]
        self.check("loaded_binary_identity" if self.ui_mode else "normal_release_identity",
                   Path(loaded["path"]).resolve() == expected and
                   loaded["sha256"] == hashlib.sha256(expected.read_bytes()).hexdigest())
        baseline = self.helper("baseline")
        self.receipt["baseline"] = baseline
        if not baseline["usable"]:
            self.receipt.update(status="blocked", reason=baseline["reason"])
            return
        # A dispatch may create a document and then fail in the outer wrapper.
        # Unknown ownership is not the same thing as a confirmed empty list.
        self.setup_attempted = True
        self.receipt.update(setup_attempted=True, remaining_owned_documents=None)
        self.save()
        setup = self.helper("setup")
        self.owned = True
        self.receipt["native_executed"] = True
        self.doc = next(d["handle"] for d in self.call("capabilities")["data"]["documents"] if d["name"] == setup["name"])
        fixture = ROOT / "dependency/libMMD/tests/fixtures/vmd-sizing-advanced"
        # Keep specialized range/UI fixtures unchanged. Normal comparison uses
        # the user's 8.5 scene scale explicitly on all three import operations.
        import_scale = {} if self.args.preview_range_only or self.ui_mode else {"position_multiple": 8.5}
        models = [self.call("import_pmx", {"document": self.doc, "path": str(fixture / "target.pmx"),
                                         **import_scale})["data"]["model"]["handle"] for _ in range(2)]
        if self.args.preview_range_only:
            self.preview_ranges(fixture, models)
            self.receipt["status"] = "passed"
            return
        slots = [self.call("import_motion", {"document": self.doc, "model": model, "path": str(fixture / "motion.vmd"),
                                           "ignore_physics": False, **import_scale})["data"]["slot"] for model in models]
        if self.ui_mode:
            self.receipt["kind"] = "synthetic-sizing-command-ui-regression"
            self.ui_regression(fixture, models, slots)
            return
        invalid = self.helper("invalid_packets")
        self.receipt["invalid_packets"] = invalid
        for item in invalid["cases"]:
            self.check("native_type_guard_" + item["case"], item["passed"])
        self.check("native_type_guard_scene_unchanged", invalid["scene_unchanged"])
        camera_labels = camera_resource_labels(expected)
        self.receipt["camera_resource_labels"] = camera_labels
        self.receipt["camera_reference_import"] = self.call("import_camera", {
            "document": self.doc, "path": str(fixture / "camera.vmd"), "position_multiple": 8.5})["data"]
        self.receipt["camera_reference"] = self.helper("camera_reference")
        before = self.helper("snapshot")
        arguments = {"document": self.doc, "characters": [
            {"model": model, "source_pmx": str(fixture / "source.pmx"), "slot": slot}
            for model, slot in zip(models, slots)], "camera_path": str(fixture / "camera.vmd"),
            "sizing_options": {"stance": True, "twist": True, "avoidance": True, "wrist_contact": True,
                               "finger_contact": True, "floor_contact": True, "multi_contact": True}}
        op_id = str(uuid.uuid4())
        started = self.call("sizing_start", arguments, operation_id=op_id)
        job = started["data"]["job"]
        self.jobs.append(job)
        self.check("start_deduplication", self.call("sizing_start", arguments, operation_id=op_id)["data"]["job"] == job)
        conflict = self.call("sizing_start", {**arguments, "sizing_options": {"stance": False}}, operation_id=op_id, expected=False)
        self.check("nested_option_conflict", conflict["code"] == "operation_id_conflict")
        self.check("batch_completed", self.wait_job(job)["job_state"] == "completed")
        base = {"document": self.doc, "job": job}
        for section in ("summary", "stages", "warnings", "constraints"):
            data = self.call("sizing_result", {**base, "member": 1, "section": section, "limit": 2})["data"]
            self.check("paged_" + section, len(data["items"]) <= 2)
        previous_camera_role = None
        for index, stage in enumerate(STAGES):
            preview = self.call("sizing_preview", {**base, "stage": stage, "member": 1, "overlay": True})["data"]
            preview_name = next(d["name"] for d in self.call("capabilities")["data"]["documents"]
                                if d["handle"] == preview["preview_document"])
            role = "original" if index % 2 == 0 else "adjusted"
            observed = self.helper("camera_preview", name=preview_name,
                                   camera_labels=camera_labels, select_role=role)
            self.check_camera_pair("camera_preview_" + stage, observed, 2)
            if previous_camera_role is not None:
                self.check("camera_view_retained_" + stage, observed["viewed_role"] == previous_camera_role)
            previous_camera_role = role
            self.check("preview_source_unchanged_" + stage, self.helper("snapshot") == before)
        # Closing an active preview must preserve its SceneHook receiver and
        # the outer exec_python wrapper until the current call returns.
        self.check("close_preview_was_active", self.helper("active_name")["name"] == preview_name)
        close_id = str(uuid.uuid4())
        self.call("sizing_close_preview", base, operation_id=close_id)
        self.check("closed_preview_removed", all(d["name"] != preview_name for d in self.call("capabilities")["data"]["documents"]))
        self.check("close_deduplication", self.call("sizing_close_preview", base, operation_id=close_id)["success"])
        self.check("close_source_unchanged", self.helper("snapshot") == before)
        destination = str(self.output / "result.vmd")
        first_export = self.call("sizing_export", {**base, "path": destination})
        protected = self.call("sizing_export", {**base, "path": destination}, expected=False)
        self.check("export_preserves_existing", protected["code"] == "destination_exists" and
                   hashlib.sha256(Path(destination).read_bytes()).hexdigest() == first_export["data"]["sha256"])
        self.call("sizing_export_camera", {**base, "path": str(self.output / "camera.vmd")})
        self.call("sizing_apply", {**base, "member": 1})
        after = self.helper("snapshot")
        self.check("new_slot", after["slots"] != before["slots"])
        self.check("single_undo", self.helper("undo")["snapshot"]["slots"] == before["slots"])
        self.check("single_redo", self.helper("redo")["snapshot"]["slots"] == after["slots"])
        self.check("save_reload_slots", self.helper("roundtrip", path=str(self.output / "scene.c4d"))["slots"] == after["slots"])
        self.camera_apply_regression(base, camera_labels, after)
        self.helper("stale")
        stale = self.call("sizing_apply", base, expected=False)
        self.check("stale_binding_rejected", stale["code"] == "sizing_apply_failed")
        self.call("sizing_release", base)
        self.jobs.remove(job)
        released = self.call("sizing_status", base, expected=False)
        self.check("released_handle_rejected", released["code"] == "stale_handle")
        # The model scale changed in the stale test; use a single member next.
        cancelled = self.call("sizing_start", {**arguments, "characters": arguments["characters"][:1]})["data"]["job"]
        self.jobs.append(cancelled)
        self.call("sizing_cancel", {"document": self.doc, "job": cancelled})
        terminal = self.wait_job(cancelled)["job_state"]
        self.receipt["cancel_terminal_state"] = terminal
        self.check("cancel_terminal_state", terminal in ("cancelled", "completed"))
        self.check("cancel_does_not_apply", self.helper("snapshot")["slots"] == after["slots"])
        release_job = self.call("sizing_start", {**arguments, "characters": arguments["characters"][:1]})["data"]["job"]
        self.jobs.append(release_job)
        self.check("release_fixture_completed", self.wait_job(release_job)["job_state"] == "completed")
        release_base = {"document": self.doc, "job": release_job}
        release_preview = self.call("sizing_preview", release_base)["data"]["preview_document"]
        release_id = str(uuid.uuid4())
        self.call("sizing_release", release_base, operation_id=release_id)
        self.jobs.remove(release_job)
        self.check("active_preview_release_removed", all(d["handle"] != release_preview for d in self.call("capabilities")["data"]["documents"]))
        self.check("release_deduplication", self.call("sizing_release", release_base, operation_id=release_id)["success"])
        self.receipt["status"] = "passed"

    def cleanup(self):
        errors = []
        ownership = None
        if self.setup_attempted:
            try:
                ownership = self.helper("owned_state")
                self.receipt["cleanup_ownership"] = ownership
                self.receipt["remaining_owned_documents"] = ownership["remaining_owned_documents"]
                self.owned = ownership["registry_present"]
            except Exception as error:
                self.receipt["remaining_owned_documents"] = None
                errors.append("owned_state:" + type(error).__name__)
        if self.owned and ownership and ownership["source_document_live"]:
            try:
                # A failed range assertion can leave the preview active. Move
                # out before release closes it inside the host exec wrapper.
                self.helper("activate_source")
            except Exception as error:
                errors.append(type(error).__name__)
        if self.ui_queue_owned:
            try:
                self.ui_clear_owned_queue()
            except Exception as error:
                errors.append("ui_queue_cleanup:" + type(error).__name__)
        if self.ui_close_needed:
            try:
                self.ui_close()
            except Exception as error:
                errors.append("ui_close:" + type(error).__name__)
        for job in list(self.jobs):
            try:
                base = {"document": self.doc, "job": job}
                self.call("sizing_cancel", base)
                self.wait_job(job)
                self.call("sizing_release", base)
                self.jobs.remove(job)
            except Exception as error:
                errors.append(type(error).__name__)
        if self.owned and not errors:
            try:
                # Never kill the document captured by exec_python's wrapper.
                # Selection and destruction must be separate host requests.
                self.helper("activate_cleanup_baseline")
                self.receipt.update(self.helper("cleanup"))
            except Exception as error:
                errors.append("document_cleanup:" + type(error).__name__)
        if self.setup_attempted:
            try:
                final_ownership = self.helper("owned_state")
                self.receipt["cleanup_final_ownership"] = final_ownership
                self.receipt["remaining_owned_documents"] = final_ownership["remaining_owned_documents"]
                if final_ownership["registry_present"]:
                    errors.append("owned_registry_remains")
            except Exception as error:
                self.receipt["remaining_owned_documents"] = None
                errors.append("final_owned_state:" + type(error).__name__)
        self.receipt["cleanup_errors"] = errors
        if errors or (self.owned and not self.receipt.get("original_document_restored")):
            self.receipt["status"] = "cleanup_pending"
        if self.client:
            self.client.close()
        self.save()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--endpoint", default="http://127.0.0.1:5556/mcp")
    parser.add_argument("--token-file", required=True)
    parser.add_argument("--expected-binary", required=True)
    parser.add_argument("--build-cache", help="Defaults to the SDK build cache inferred from expected-binary.")
    parser.add_argument("--output", required=True)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--preview-range-only", action="store_true",
                        help="Check unequal bone/morph/IK/camera durations in both member orders and stage playhead preservation.")
    mode.add_argument("--ui-regression", action="store_true",
                      help="Use the test-only bridge on an isolated host with an empty command-owned sizing panel; exercise queue/slot recovery and MCP edit/reopen synchronization.")
    parser.add_argument("--timeout", type=int, default=60, choices=range(1, 601))
    args = parser.parse_args()
    run = SizingValidation(args)
    try:
        run.execute()
    except Exception as error:
        run.receipt.update(status="failed", error_type=type(error).__name__)
        raise
    finally:
        run.cleanup()
    print(json.dumps({"status": run.receipt["status"], "checks": len(run.receipt["checks"])}))
    return 0 if run.receipt["status"] == "passed" else 2


if __name__ == "__main__":
    sys.exit(main())
