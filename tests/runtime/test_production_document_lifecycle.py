"""Production runner ownership/coordinator fixtures without Cinema 4D."""

import base64
from contextlib import redirect_stdout
import importlib.util
import io
import json
from pathlib import Path
import queue
import re
import sys
import tempfile
import types
import unittest
from unittest.mock import patch

REPO = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("production_runner_fixture", REPO / "scripts/c4d_production_mcp_validation.py")
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)


class Node:
    def __init__(self, kind=0):
        self.doc = None
        self.name = ""
    def SetName(self, name): self.name = name
    def GetName(self): return self.name
    def GetType(self): return 0
    def GetDown(self): return None
    def GetNext(self): return None
    def Remove(self):
        if self.doc:
            self.doc.nodes.remove(self)
            self.doc = None


class Doc:
    def __init__(self, owner):
        self.owner, self.alive, self.nodes = owner, True, []
        self.name, self.filename, self.fps = "", "", 30
    def check(self):
        if not self.alive: raise ReferenceError("dead document")
    def SetName(self, name): self.check(); self.name = name
    def GetName(self): self.check(); return self.name
    def SetDocumentName(self, name): self.check(); self.filename = name
    def GetDocumentName(self): self.check(); return self.filename
    def SetFps(self, fps): self.fps = fps
    def GetFps(self): return self.fps
    def GetTime(self): return types.SimpleNamespace(Get=lambda: 0)
    def InsertObject(self, node): self.nodes.append(node); node.doc = self
    def GetFirstObject(self): return self.nodes[0] if self.nodes else None
    def GetFirstMaterial(self): return None
    def GetNext(self):
        self.check()
        index = self.owner.live.index(self)
        return self.owner.live[index + 1] if index + 1 < len(self.owner.live) else None
    def GetClone(self, *args): return Doc(self.owner)


class Documents:
    def __init__(self):
        self.live = []
        self.active = None
        self.fail_insert_at = None
        self.insert_count = 0
        self.fail_close_once = set()
        self.killed = []
    def BaseDocument(self): return Doc(self)
    def InsertBaseDocument(self, doc):
        self.live.append(doc)
        self.active = doc
        self.insert_count += 1
        if self.insert_count == self.fail_insert_at:
            raise RuntimeError("insert failed after adopting the document")
    def GetFirstDocument(self): return self.live[0] if self.live else None
    def GetActiveDocument(self): return self.active
    def SetActiveDocument(self, doc):
        if doc not in self.live: raise RuntimeError("active must be live")
        self.active = doc
    def SaveDocument(self, *args): return True
    def LoadDocument(self, *args): return Doc(self)
    def KillDocument(self, doc):
        doc.check()
        if doc in self.fail_close_once:
            self.fail_close_once.remove(doc)
            raise RuntimeError("close failed once")
        if doc in self.live: self.live.remove(doc)
        doc.alive = False
        self.killed.append(doc)
        if self.active is doc: self.active = self.live[0] if self.live else None


class NativeOwnershipTests(unittest.TestCase):
    def setUp(self):
        self.folder = tempfile.TemporaryDirectory(prefix="cmt-production-lifecycle-", dir="S:/tmp" if Path("S:/tmp").is_dir() else None)
        self.addCleanup(self.folder.cleanup)
        self.documents = Documents()
        self.original = self.documents.BaseDocument()
        self.documents.InsertBaseDocument(self.original)
        self.user_same_name = self.documents.BaseDocument()
        self.user_same_name.SetName("CMT owned fixture")
        self.documents.InsertBaseDocument(self.user_same_name)
        self.documents.SetActiveDocument(self.original)
        self.key = "_cmt_production_validation_fixture"
        self.addCleanup(sys.modules.pop, self.key, None)
        self.fail_translate = False
        owner = self
        class Translator:
            def Init(self, source): return True
            def Translate(self, *args):
                if owner.fail_translate: raise RuntimeError("translate failed")
        self.c4d = types.SimpleNamespace(documents=self.documents, BaseObject=Node, Onull=0,
            threading=types.SimpleNamespace(GeIsMainThreadAndNoDrawThread=lambda: True),
            AliasTrans=Translator, COPYFLAGS_NONE=0,
            SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST=0, FORMAT_C4DEXPORT=0,
            SCENEFILTER_OBJECTS=1, SCENEFILTER_MATERIALS=2)
    def execute(self, action, **data):
        payload = {"run_id": "fixture", "action": action, "document_name": "CMT owned fixture",
                   "output": self.folder.name, **data}
        encoded = base64.b64encode(json.dumps(payload).encode()).decode()
        output = io.StringIO()
        module = None
        try:
            with patch.dict(sys.modules, {"c4d": self.c4d}), redirect_stdout(output):
                try:
                    exec(runner._TEST_CODE.replace("__PAYLOAD__", encoded), {})
                finally:
                    module = sys.modules.get(self.key)
        finally:
            if module is not None:
                sys.modules[self.key] = module
        return json.loads(output.getvalue().split(runner.TEST_MARKER)[1])
    def test_cleanup_preserves_user_documents_with_the_same_name(self):
        self.execute("setup")
        module = sys.modules[self.key]
        self.assertEqual(len(module.owned_docs), 4)
        result = self.execute("cleanup")
        self.assertFalse(result["cleanup_pending"])
        self.assertEqual(self.documents.live, [self.original, self.user_same_name])
        self.assertIsNone(self.original.GetFirstObject())
        with self.assertRaises(RuntimeError): self.execute("setup")
    def test_legacy_private_registry_upgrade_excludes_original(self):
        owned = self.documents.BaseDocument()
        self.documents.InsertBaseDocument(owned)
        sys.modules[self.key] = types.SimpleNamespace(original=self.original,
            documents={"A": owned, "B": self.original}, guard=None, original_was_blank=False)
        self.execute("cleanup_status")
        self.assertEqual(sys.modules[self.key].owned_docs, [owned])
        self.execute("cleanup")
        self.assertEqual(self.documents.live, [self.original, self.user_same_name])
    def test_setup_insert_failure_keeps_ownership_before_insertion(self):
        self.documents.fail_insert_at = self.documents.insert_count + 1
        with self.assertRaises(RuntimeError): self.execute("setup")
        self.assertEqual(len(sys.modules[self.key].owned_docs), 1)
        self.execute("cleanup")
        self.assertEqual(self.documents.live, [self.original, self.user_same_name])
    def test_reopen_insert_failure_retains_loaded_replacement(self):
        self.documents.fail_insert_at = self.documents.insert_count + 3
        with self.assertRaises(RuntimeError): self.execute("setup")
        self.assertEqual(len(sys.modules[self.key].owned_docs), 3)
        self.execute("cleanup")
        self.assertEqual(self.documents.live, [self.original, self.user_same_name])
    def test_clone_translate_failure_retains_detached_clone(self):
        self.execute("setup")
        self.fail_translate = True
        with self.assertRaises(RuntimeError): self.execute("clone", label="A")
        clone = sys.modules[self.key].owned_docs[-1]
        self.assertNotIn(clone, self.documents.live)
        self.execute("cleanup")
        self.assertFalse(clone.alive)
    def test_repeated_clone_does_not_lose_previous_owned_clone(self):
        self.execute("setup")
        self.execute("clone", label="A")
        first = sys.modules[self.key].documents["C"]
        self.execute("clone", label="A")
        self.assertIn(first, sys.modules[self.key].owned_docs)
        self.execute("cleanup")
        self.assertFalse(first.alive)
        self.assertEqual(self.documents.live, [self.original, self.user_same_name])
    def test_failed_close_retains_reference_and_guard_for_retry(self):
        self.execute("setup")
        failed = sys.modules[self.key].documents["A"]
        self.documents.fail_close_once.add(failed)
        first = self.execute("cleanup")
        self.assertTrue(first["cleanup_pending"])
        self.assertEqual(sys.modules[self.key].owned_docs, [failed])
        self.assertIsNotNone(sys.modules[self.key].guard)
        second = self.execute("cleanup")
        self.assertFalse(second["cleanup_pending"])
        self.assertEqual(self.documents.live, [self.original, self.user_same_name])


class CoordinatorTests(unittest.TestCase):
    def setUp(self):
        self.folder = tempfile.TemporaryDirectory(prefix="cmt-production-coordinator-", dir="S:/tmp" if Path("S:/tmp").is_dir() else None)
        self.addCleanup(self.folder.cleanup)
        self.run = runner.ValidationRun.__new__(runner.ValidationRun)
        self.run.output = Path(self.folder.name)
        self.run.manifest = {}
        self.run.values = {}
        self.run.state = {"values": {}, "stages": {"setup": {"status": "passed"}},
                          "native_executed": True, "original_document_restored": True,
                          "terminated": False, "cleanup_pending": False}
        self.run.stage_name = ""
        self.events = []
        self.run.native = self.native
    def native(self, action, **data):
        self.events.append(action)
        if action == "snapshot": return {"documents": {"A": {"objects": "failure-scene"}}}
        if action == "cleanup_status":
            return {"module_exists": True, "main_thread_checkpoint": True, "original_live": True}
        if action == "cleanup":
            self.assertTrue((self.run.output / "receipt.json").exists())
            failed = self.run.state["stages"].get("discovery", {})
            if failed.get("status") == "failed":
                self.assertTrue(Path(failed["failure_snapshot"]).exists())
            return {"cleanup_pending": False, "remaining_owned_documents": 0,
                    "original_document_restored": True}
        if action == "restore": return {"original_document_restored": True}
        raise AssertionError(action)
    def test_successful_single_stage_retains_documents(self):
        self.run.discovery = lambda: {"checked": True}
        self.run.stage("discovery")
        self.assertEqual(self.events, ["restore"])
        self.assertFalse(self.run.state["terminated"])
    def test_failed_stage_records_scene_then_cleanup_without_changing_failure(self):
        def fail(): raise AssertionError("business assertion")
        self.run.discovery = fail
        with self.assertRaisesRegex(AssertionError, "business assertion"):
            self.run.stage("discovery")
        self.assertEqual(self.events, ["snapshot", "cleanup_status", "cleanup"])
        self.assertEqual(self.run.state["stages"]["discovery"]["status"], "failed")
        self.assertTrue(self.run.state["terminated"])
        self.assertFalse(self.run.state["acceptance_eligible"])
        with self.assertRaises(ValueError): self.run.stage("model")
    def test_timeout_defers_snapshot_restore_and_cleanup(self):
        def fail(): raise queue.Empty()
        self.run.discovery = fail
        with self.assertRaises(queue.Empty): self.run.stage("discovery")
        self.assertEqual(self.events, [])
        self.assertTrue(self.run.state["terminated"])
        self.assertTrue(self.run.state["cleanup_pending"])
        self.assertEqual(json.loads((self.run.output / "receipt.json").read_text())["status"], "cleanup_pending")
    def test_cleanup_captures_failure_from_older_runner(self):
        self.run.state["stages"]["discovery"] = {"status": "failed", "error_type": "AssertionError"}
        self.run.stage("cleanup")
        self.assertEqual(self.events, ["cleanup_status", "snapshot", "cleanup"])
        self.assertTrue(self.run.state["terminated"])
        self.assertFalse(self.run.state["cleanup_pending"])
    def test_pending_operation_running_prevents_any_cleanup_helper(self):
        self.run.state["pending_operation"] = {"name": "mmdtool_set_mode", "operation_id": "pending"}
        self.run.ensure_host = lambda: None
        self.run.record = lambda *args: None
        operation = {"success": True, "code": "accepted", "message": "", "operation_id": "pending",
                     "state": "running", "data": {}, "warnings": []}
        self.run.host = types.SimpleNamespace(call_production=lambda *args: {
            "success": True, "code": "ok", "message": "", "operation_id": "status",
            "state": "completed", "data": {"operation": operation}, "warnings": []})
        with self.assertRaises(runner.CleanupPending): self.run.stage("cleanup")
        self.assertEqual(self.events, [])
        self.assertTrue(self.run.state["cleanup_pending"])
    def test_expected_readonly_unknown_status_is_a_normal_negative_result(self):
        self.run.ensure_host = lambda: None
        self.run.record = lambda *args: None
        self.run.host = types.SimpleNamespace(call_production=lambda name, arguments, operation_id, **kwargs: {
            "success": False, "code": "outcome_unknown", "message": "Record unavailable",
            "operation_id": operation_id, "state": "outcome_unknown", "data": {}, "warnings": []})
        result = self.run.call("mmdtool_operation_status", {
            "query_operation_id": "11111111-1111-1111-1111-111111111111"}, expected=False)
        self.assertEqual(result["state"], "outcome_unknown")
        self.assertNotIn("pending_operation", self.run.state)
        self.assertFalse(self.run.state["cleanup_pending"])
    def test_legacy_pending_readonly_status_allows_safe_cleanup(self):
        self.run.state["cleanup_pending"] = True
        self.run.state["pending_operation"] = {"name": "mmdtool_operation_status", "operation_id": "old-status"}
        self.run.stage("cleanup")
        self.assertEqual(self.events, ["cleanup_status", "cleanup"])
        self.assertNotIn("pending_operation", self.run.state)
        self.assertFalse(self.run.state["cleanup_pending"])
    def test_finish_is_idempotent_after_successful_cleanup(self):
        self.run.finish()
        before = list(self.events)
        self.run.finish()
        self.assertEqual(self.events, before)


if __name__ == "__main__":
    unittest.main(verbosity=2)
