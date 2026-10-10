"""Validate sizing through real stdio typed tools on an already configured C4D.

Uses owned synthetic documents and the normal production API, never the runtime
regression bridge. Does not start/restart C4D or enable its MCP server. A host
without sizing support produces a blocked receipt before creating documents.
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import json
from pathlib import Path
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

# This helper only manages documents owned by this validation run. All sizing,
# import/export and result calls go through the actual adapter subprocess.
HELPER = '''import base64, builtins, json, os, sys, c4d
p = json.loads(base64.b64decode("__PAYLOAD__"))
registry = getattr(builtins, "_cmt_sizing_mcp_tests", {})
builtins._cmt_sizing_mcp_tests = registry
state = registry.get(p["run"])
def live(doc):
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
    doc = c4d.documents.BaseDocument()
    doc.SetDocumentName("Sizing MCP " + p["run"])
    c4d.documents.InsertBaseDocument(doc)
    c4d.documents.SetActiveDocument(doc)
    registry[p["run"]] = {"original": original, "doc": doc, "extra": []}
    result = {"name": doc.GetDocumentName()}
elif action == "cleanup":
    if state:
        for doc in state["extra"] + [state["doc"]]:
            if live(doc): c4d.documents.KillDocument(doc)
        if live(state["original"]): c4d.documents.SetActiveDocument(state["original"])
        result = {"original_document_restored": live(state["original"]) and c4d.documents.GetActiveDocument() == state["original"],
                  "remaining_owned_documents": [d.GetDocumentName() for d in state["extra"] + [state["doc"]] if live(d)]}
        del registry[p["run"]]
elif action == "activate_original":
    if not state or not live(state["original"]): raise RuntimeError("Original document is unavailable")
    c4d.documents.SetActiveDocument(state["original"])
    result = {"activated": True}
else:
    if not state or not live(state["doc"]): raise RuntimeError("Owned source is unavailable")
    doc = state["doc"]
    models = [o for o in doc.GetObjects() if o.GetType() == 1056724]
    if action == "activate_source":
        c4d.documents.SetActiveDocument(doc)
        result = {"activated": True}
    elif action == "snapshot": result = snapshot(doc)
    elif action == "undo": result = {"ok": doc.DoUndo(), "snapshot": snapshot(doc)}
    elif action == "redo": result = {"ok": doc.DoRedo(), "snapshot": snapshot(doc)}
    elif action == "stale":
        models[0][p["ids"]["MODEL_POSITION_MULTIPLE"]] *= 2
        result = {"changed": True}
    elif action == "roundtrip":
        path = p["path"]
        if not c4d.documents.SaveDocument(doc, path, c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
            raise RuntimeError("Owned document save failed")
        reopened = c4d.documents.LoadDocument(path, c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
        if not reopened: raise RuntimeError("Owned document reload failed")
        c4d.documents.InsertBaseDocument(reopened)
        state["extra"].append(reopened)
        result = snapshot(reopened)
    else: raise RuntimeError("Unknown owned-document action")
print("CMT_SIZING_TEST:" + json.dumps(result, ensure_ascii=False))
'''


class SizingValidation:
    def __init__(self, args):
        self.args = args
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
        self.doc = ""
        self.receipt = {"run_id": self.run_id, "kind": "synthetic-production-sizing-mcp",
                        "status": "incomplete", "checks": [], "native_executed": False,
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
        self.check("runtime_regression_off", "CMT_ENABLE_RUNTIME_REGRESSION:BOOL=OFF" in cache)
        self.receipt["build_cache"] = {"path": str(cache_path), "sha256": hashlib.sha256(cache_path.read_bytes()).hexdigest()}
        loaded = self.receipt["host"]["loaded_binary"]
        self.check("normal_release_identity", Path(loaded["path"]).resolve() == expected and
                   loaded["sha256"] == hashlib.sha256(expected.read_bytes()).hexdigest())
        setup = self.helper("setup")
        self.owned = True
        self.receipt["native_executed"] = True
        self.doc = next(d["handle"] for d in self.call("capabilities")["data"]["documents"] if d["name"] == setup["name"])
        fixture = ROOT / "dependency/libMMD/tests/fixtures/vmd-sizing-advanced"
        models = [self.call("import_pmx", {"document": self.doc, "path": str(fixture / "target.pmx")})["data"]["model"]["handle"] for _ in range(2)]
        slots = [self.call("import_motion", {"document": self.doc, "model": model, "path": str(fixture / "motion.vmd"),
                                           "ignore_physics": False})["data"]["slot"] for model in models]
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
        for stage in STAGES:
            self.call("sizing_preview", {**base, "stage": stage, "member": 1})
            self.check("preview_source_unchanged_" + stage, self.helper("snapshot") == before)
        # The host exec wrapper inspects the document it captured at entry.
        # Switch in a separate request before closing that preview document.
        self.helper("activate_source")
        self.call("sizing_close_preview", base)
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
        self.call("sizing_apply_camera", base)
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
        self.receipt["status"] = "passed"

    def cleanup(self):
        errors = []
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
            self.helper("activate_original")
            self.receipt.update(self.helper("cleanup"))
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
