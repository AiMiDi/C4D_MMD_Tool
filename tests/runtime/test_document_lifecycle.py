"""Ownership and failure cleanup checks using fake C4D documents only."""

import json
import os
from pathlib import Path
import sys
import tempfile
import types
import unittest
from unittest import mock


REPOSITORY = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPOSITORY / "scripts"))
import c4d_runtime_regression as regression
import c4d_extended_validation as extended


class FakeDocument:
    def __init__(self, documents, name="private"):
        self.documents = documents
        self.name = name
        self.alive = True

    def __bool__(self):
        if not self.alive:
            raise ReferenceError("The fake native document has been deleted")
        return True

    def __eq__(self, other):
        if not self.alive or isinstance(other, FakeDocument) and not other.alive:
            raise ReferenceError("The fake native document has been deleted")
        return self is other

    def GetNext(self):
        position = self.documents.live.index(self) + 1
        return self.documents.live[position] if position < len(self.documents.live) else None

    def SetName(self, name):
        self.name = name

    def SetDocumentName(self, name):
        self.name = name

    def SetFps(self, fps):
        self.fps = fps


class FakeDocuments:
    def __init__(self):
        self.live = []
        self.active = None
        self.events = []
        self.insert_failure = None
        self.close_failures = {}

    def BaseDocument(self):
        return FakeDocument(self)

    def add_user_document(self, name):
        document = FakeDocument(self, name)
        self.live.append(document)
        self.active = document
        return document

    def GetFirstDocument(self):
        return self.live[0] if self.live else None

    def GetActiveDocument(self):
        return self.active

    def SetActiveDocument(self, document):
        if document not in self.live:
            raise ReferenceError("Cannot activate a closed document")
        self.active = document
        self.events.append(("activate", document))

    def InsertBaseDocument(self, document):
        if self.insert_failure == "before":
            raise RuntimeError("Insertion failed before linking")
        self.live.append(document)
        self.active = document
        if self.insert_failure == "after":
            raise RuntimeError("Insertion failed after linking")

    def KillDocument(self, document):
        self.events.append(("kill", document))
        remaining_failures = self.close_failures.get(id(document), 0)
        if remaining_failures:
            self.close_failures[id(document)] = remaining_failures - 1
            raise RuntimeError("A fake close failed")
        self.live.remove(document)
        document.alive = False
        if self.active is document:
            self.active = self.live[0] if self.live else None

    def SaveDocument(self, document, path, flags, format_id):
        self.events.append(("scene", document))
        Path(path).write_text("fake lifecycle scene", encoding="utf-8")
        return True


class DocumentLifecycleTests(unittest.TestCase):
    def setUp(self):
        temporary_root = Path(os.environ.get("CMT_TEST_TEMP_DIR", r"S:\tmp")) if os.name == "nt" else Path(tempfile.gettempdir())
        temporary_root.mkdir(parents=True, exist_ok=True)
        self.temporary = tempfile.TemporaryDirectory(prefix="cmt-fake-document-lifecycle-", dir=temporary_root)
        self.addCleanup(self.temporary.cleanup)
        self.documents = FakeDocuments()
        self.user = self.documents.add_user_document("User scene")
        self.c4d = types.SimpleNamespace(documents=self.documents, SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST=0,
                                         FORMAT_C4DEXPORT=0, GetC4DVersion=lambda: 0, EventAdd=lambda: None)
        self.manifest = {"resource_ids": {}, "output": self.temporary.name, "fixtures": {}}
        self.suite = regression.Suite(self.c4d, self.manifest)

    def test_same_name_user_and_unregistered_active_document_are_protected(self):
        owned = self.suite.new_document("same name")
        user_with_same_name = self.documents.add_user_document(owned.name)
        self.suite.doc = user_with_same_name
        result = self.suite.close()
        self.assertFalse(regression.document_is_live(self.c4d, owned))
        self.assertTrue(regression.document_is_live(self.c4d, user_with_same_name))
        self.assertTrue(regression.document_is_live(self.c4d, self.user))
        self.assertIs(self.documents.active, self.user)
        self.assertEqual(result["errors"], [])
        with self.assertRaises(ValueError):
            self.suite.register_document(user_with_same_name, "cannot adopt a user scene")

    def test_failure_after_insertion_still_has_an_owned_reference(self):
        self.documents.insert_failure = "after"
        with self.assertRaisesRegex(RuntimeError, "after linking"):
            self.suite.new_document("insert failure")
        result = self.suite.close()
        self.assertEqual(len(result["closed_owned_documents"]), 1)
        self.assertEqual(self.documents.live, [self.user])
        self.assertIs(self.documents.active, self.user)

    def test_failure_before_insertion_releases_private_reference_without_closing_user(self):
        self.documents.insert_failure = "before"
        with self.assertRaisesRegex(RuntimeError, "before linking"):
            self.suite.new_document("private allocation")
        result = self.suite.close()
        self.assertEqual(len(result["released_nonlive_documents"]), 1)
        self.assertEqual([event for event in self.documents.events if event[0] == "kill"], [])
        self.assertEqual(self.documents.live, [self.user])

    def test_replaced_and_clone_documents_close_once(self):
        first = self.suite.new_document("first")
        clone = self.suite.register_document(self.documents.BaseDocument(), "clone")
        self.documents.InsertBaseDocument(clone)
        self.suite.new_document("replacement")
        self.documents.KillDocument(first)  # Simulate a close performed outside the Suite.
        result = self.suite.close()
        self.assertEqual(len(result["closed_owned_documents"]), 2)
        self.assertEqual(self.documents.live, [self.user])
        kill_count = len([event for event in self.documents.events if event[0] == "kill"])
        repeated = self.suite.close()
        self.assertEqual(repeated["errors"], [])
        self.assertEqual(kill_count, len([event for event in self.documents.events if event[0] == "kill"]))

    def test_failed_close_keeps_only_failed_reference_for_retry(self):
        owned = self.suite.new_document("retry")
        self.documents.close_failures[id(owned)] = 1
        result = self.suite.close()
        self.assertEqual(len(result["errors"]), 1)
        self.assertEqual(self.suite.owned_documents, (owned,))
        self.assertIs(self.documents.active, self.user)
        with self.assertRaisesRegex(RuntimeError, "Retry cleanup"):
            self.suite.new_document("cannot accumulate after failed close")
        retried = self.suite.close()
        self.assertEqual(retried["errors"], [])
        self.assertEqual(self.suite.owned_documents, ())

    def test_loaded_replacement_is_retained_until_insertion(self):
        self.suite.new_document("old")
        replacement = self.suite.register_document(self.documents.BaseDocument(), "loaded replacement")
        result = self.suite.close(keep_documents=(replacement,))
        self.assertEqual(result["errors"], [])
        self.assertEqual(self.suite.owned_documents, (replacement,))
        self.documents.InsertBaseDocument(replacement)
        self.suite.doc = replacement
        self.suite.close()
        self.assertEqual(self.documents.live, [self.user])

    def test_extended_failed_phase_saves_evidence_before_cleanup_and_cannot_replay(self):
        validator = extended.ExtendedNativeValidation.__new__(extended.ExtendedNativeValidation)
        validator.suite, validator.retired_documents = self.suite, []
        validator.terminated = False
        validator.receipt = {"binary_identity_confirmed": True, "phases": [], "acceptance_eligible": False}
        validator.write_receipt = lambda: self.documents.events.append(("receipt", validator.receipt["status"]))
        first = self.suite.new_document("retained")
        validator.retain_current_document()
        self.suite.new_document("current")

        def fail():
            raise AssertionError("Original replay failure")

        with mock.patch.object(extended, "c4d", self.c4d):
            with self.assertRaisesRegex(AssertionError, "Original replay failure"):
                validator.phase("replay", fail)
            first_kill = next(index for index, event in enumerate(self.documents.events) if event[0] == "kill")
            self.assertTrue(any(event[0] == "receipt" for event in self.documents.events[:first_kill]))
            self.assertTrue(any(event[0] == "scene" for event in self.documents.events[:first_kill]))
            self.assertFalse(regression.document_is_live(self.c4d, first))
            self.assertEqual(self.documents.live, [self.user])
            with self.assertRaisesRegex(RuntimeError, "has ended"):
                validator.phase("replay", fail)

    def test_extended_successful_stage_retains_documents_for_next_stage(self):
        validator = extended.ExtendedNativeValidation.__new__(extended.ExtendedNativeValidation)
        validator.suite, validator.retired_documents = self.suite, []
        validator.terminated = False
        validator.receipt = {"binary_identity_confirmed": True, "phases": [], "acceptance_eligible": False}
        validator.write_receipt = lambda: None
        owned = self.suite.new_document("cross stage")
        self.documents.SetActiveDocument(self.user)
        with mock.patch.object(extended, "c4d", self.c4d):
            self.assertEqual(validator.phase("one", lambda: {"sample": 1}), {"sample": 1})
            self.assertTrue(regression.document_is_live(self.c4d, owned))
            self.assertFalse(validator.terminated)
            self.assertEqual([event for event in self.documents.events if event[0] == "kill"], [])
            validator.close()
        self.assertEqual(self.documents.live, [self.user])

    def test_legacy_run_writes_case_failure_before_native_close(self):
        manifest = {**self.manifest, "schema_version": 1, "cases": list(regression.CASE_NAMES),
                    "revision": "fake-lifecycle-only", "source_sha256": "fake-lifecycle-only",
                    "sdk": "fake-c4d-lifecycle", "plugin_binary": {"sha256": "fake"}}
        manifest_path = Path(self.temporary.name) / "manifest.json"
        manifest_path.write_text(json.dumps(manifest), encoding="utf-8")

        class FailingCaseSuite(regression.Suite):
            def __getattribute__(suite, name):
                if name in regression.CASE_NAMES:
                    def case():
                        suite.new_document(name)
                        raise AssertionError("Fake fixture failure")
                    return case
                return super().__getattribute__(name)

        original_write = Path.write_text

        def record_write(path, data, *args, **kwargs):
            if path.name == "receipt.json":
                self.documents.events.append(("receipt", json.loads(data)))
            return original_write(path, data, *args, **kwargs)

        with mock.patch.dict(sys.modules, {"c4d": self.c4d}), mock.patch.object(regression, "Suite", FailingCaseSuite), \
                mock.patch.object(regression, "loaded_plugin_binary", return_value={"sha256": "fake"}), \
                mock.patch.object(Path, "write_text", record_write):
            receipt = regression.run(manifest_path)
        first_kill = next(index for index, event in enumerate(self.documents.events) if event[0] == "kill")
        recorded_failures = [event for event in self.documents.events[:first_kill] if event[0] == "receipt"]
        self.assertEqual(recorded_failures[-1][1]["cases"][0]["error"], "Fake fixture failure")
        self.assertFalse(receipt["acceptance_eligible"])
        self.assertEqual(receipt["status"], "failed")
        self.assertEqual(self.documents.live, [self.user])


if __name__ == "__main__":
    unittest.main()
