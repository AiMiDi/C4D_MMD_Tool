"""Host-free ownership tests; these never claim C4D or image acceptance."""
from pathlib import Path
import gc
import sys
import unittest
from types import SimpleNamespace
from unittest.mock import Mock, patch
import weakref

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_rs_highlight_test as highlight


class HighlightLifecycle(unittest.TestCase):
    def tearDown(self):
        highlight._active_session = None

    def make_session(self, restored=True):
        session = object.__new__(highlight._Session)
        session.c4d = SimpleNamespace(PREFS_REDSHIFT_HYBRID_RENDERING=19018)
        session.prefs = {2500: True, 2501: False, 19018: False}
        session.devices = [(2500, "GPU", False), (2501, "CPU", True)]
        session.hybrid = True
        session.guard = None
        session.worker = None
        session._write = Mock()
        session.suite = SimpleNamespace(close=Mock(return_value={
            "errors": [], "remaining_owned_documents": [],
            "original_document_restored": restored}))
        highlight._active_session = session
        return session

    def test_callback_reference_survives_local_scope_and_blocks_duplicate(self):
        class Retained:
            pass
        with patch.object(highlight, "_Session", side_effect=lambda *args: Retained()) as create:
            def callback():
                return weakref.ref(highlight.create_session(None, "unused"))
            reference = callback()
            gc.collect()
            self.assertIs(reference(), highlight.active_session())
            with self.assertRaises(RuntimeError):
                highlight.create_session(None, "another")
            self.assertEqual(create.call_count, 1)

    def test_running_worker_keeps_document_and_preferences_until_stopped(self):
        session = self.make_session()
        worker = SimpleNamespace(IsRunning=Mock(return_value=True), End=Mock(),
                                 document=object(), bitmap=object())
        session.worker = worker
        self.assertTrue(session.close()["cleanup_pending"])
        worker.End.assert_called_once_with(False)
        session.suite.close.assert_not_called()
        self.assertIsNotNone(worker.document)
        self.assertTrue(session.prefs[2500])
        self.assertIs(highlight.active_session(), session)
        worker.IsRunning.return_value = False
        result = session.close()
        self.assertTrue(result["devices_restored"])
        self.assertTrue(result["hybrid_restored"])
        self.assertIsNone(worker.document)
        self.assertFalse(session.prefs[2500])
        self.assertTrue(session.prefs[2501])
        with self.assertRaises(RuntimeError):
            highlight.active_session()

    def test_failed_original_restore_keeps_session_for_recovery(self):
        session = self.make_session(restored=False)
        self.assertFalse(session.close()["original_document_restored"])
        self.assertIs(highlight.active_session(), session)

    def test_setup_failure_restores_device_selection(self):
        session = self.make_session()
        session._start = Mock(side_effect=RuntimeError("fixture setup failed"))
        with self.assertRaisesRegex(RuntimeError, "fixture setup failed"):
            session.start("white_broad", "gpu")
        self.assertFalse(session.prefs[2500])
        self.assertTrue(session.prefs[2501])
        self.assertTrue(session.prefs[19018])


if __name__ == "__main__":
    unittest.main()
