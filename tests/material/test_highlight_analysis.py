"""Synthetic negative controls for the analyzer, never renderer acceptance."""
from pathlib import Path
import hashlib
import json
import math
import tempfile
import unittest

import analyze_rs_highlights as analysis


def image(case):
    pixels = []
    for y in range(32):
        for x in range(32):
            distance = (x + .5 - 16) ** 2 + (y + .5 - 16) ** 2
            radius = 7 if case == "white_broad" else 2
            value = .6 * math.exp(-distance / (2 * radius ** 2)) if case != "zero" else 0.
            pixels.append((value, 0. if case == "red" else value,
                           0. if case == "red" else value, float(distance <= 13 ** 2)))
    return 32, 32, pixels


class HighlightAnalysis(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="cmt-highlight-analysis-")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.identity = {"fixture_profile": analysis.PROFILE, "module": {"sha256": "a" * 64},
                         "resolution": [32, 32], "view_transform_baked": False,
                         "evidence_kind": "synthetic_analyzer_test"}
        self.cleanup = {"errors": [], "remaining_owned_documents": [],
                        "original_document_restored": True, "devices_restored": True, "hybrid_restored": True}
        self.rows, self.images = [], {}
        for device in ("cpu", "gpu"):
            for index, case in enumerate((*analysis.CASES, "white_narrow", "white_narrow")):
                label = f"{device}-{index}-{case}"
                payload = label.encode("ascii")
                (self.root / (label + ".png")).write_bytes(payload)
                self.images[label] = image(case)
                self.rows.append({"label": label, "case": case, "device": device,
                                  "specular_color": analysis.CASES[case][0],
                                  "specular_power": analysis.CASES[case][1],
                                  "reopen": index == 5, "status": "rendered_pending_analysis",
                                  "result": 0, "error": None, "sha256": hashlib.sha256(payload).hexdigest(),
                                  "devices": [["CPU" if device == "cpu" else "NVIDIA GPU", True]]})

    def analyze(self, **options):
        for name, data in (("identity", self.identity), ("cleanup", self.cleanup), ("renders", self.rows)):
            (self.root / (name + ".json")).write_text(json.dumps(data), encoding="utf-8")
        return analysis.analyze(self.root, loader=lambda path: self.images[path.stem], **options)

    def assert_failed_check(self, report, name):
        self.assertEqual(report["status"], "failed")
        self.assertTrue(any(name in check["name"] and not check["passed"] for check in report["checks"]), report)

    def test_complete_directional_matrix_passes_without_claiming_native_fidelity(self):
        report = self.analyze()
        self.assertEqual(report["status"], "response_checks_passed", report)
        self.assertEqual(len(report["images"]), 12)
        self.assertFalse(report["native_mmd_fidelity_accepted"])
        self.assertFalse(report["backend_execution_verified"])

    def test_identical_broad_and_narrow_images_fail_even_when_devices_agree(self):
        for row in self.rows:
            if row["case"] == "white_narrow":
                self.images[row["label"]] = image("white_broad")
        self.assert_failed_check(self.analyze(), "power_narrows_highlight")

    def test_opaque_black_images_do_not_pass_as_equivalent_devices(self):
        for label in self.images:
            self.images[label] = image("zero")
        self.assert_failed_check(self.analyze(), "visible_highlight")

    def test_transparent_image_rejected(self):
        self.images[self.rows[0]["label"]] = (32, 32, [(1., 1., 1., 0.)] * 1024)
        self.assertIn("coverage", self.analyze()["errors"][0])

    def test_wrong_color_and_nonzero_disabled_specular_rejected(self):
        for row in self.rows:
            if row["case"] in ("red", "zero"):
                self.images[row["label"]] = image("white_narrow")
        report = self.analyze()
        self.assert_failed_check(report, "red_highlight")
        self.assert_failed_check(report, "zero_highlight")

    def test_missing_reopen_does_not_count_as_complete(self):
        self.rows = [row for row in self.rows if not row["reopen"]]
        self.assertIn("Missing reopen", self.analyze()["errors"][0])

    def test_changed_repeat_and_reopen_are_detected(self):
        for row in self.rows:
            if row["label"].startswith(("cpu-4-", "gpu-5-")):
                self.images[row["label"]] = image("white_broad")
        report = self.analyze()
        self.assert_failed_check(report, "cpu/repeat")
        self.assert_failed_check(report, "gpu/reopen")

    def test_failed_render_rejected_even_with_valid_image(self):
        self.rows[0]["result"] = 1
        self.assertIn("Failed or unfinished", self.analyze()["errors"][0])

    def test_hash_mismatch_rejected(self):
        (self.root / (self.rows[0]["label"] + ".png")).write_bytes(b"changed")
        self.assertIn("hash mismatch", self.analyze()["errors"][0])

    def test_cpu_selected_for_gpu_label_rejected(self):
        self.rows[-1]["devices"] = [["CPU", True]]
        self.assertIn("devices disagree", self.analyze()["errors"][0])

    def test_missing_original_restore_fails(self):
        self.cleanup["original_document_restored"] = False
        self.assert_failed_check(self.analyze(), "cleanup")

    def test_module_identity_and_color_transform_required(self):
        self.identity["module"]["sha256"] = ""
        self.assertIn("module", self.analyze()["errors"][0])
        self.identity["module"]["sha256"] = "a" * 64
        self.identity["view_transform_baked"] = True
        self.assertIn("view transform", self.analyze()["errors"][0])

    def test_device_difference_reported(self):
        for row in self.rows:
            if row["device"] == "gpu" and row["case"] != "zero":
                width, height, pixels = self.images[row["label"]]
                self.images[row["label"]] = (width, height, [tuple(v * .5 for v in p[:3]) + (p[3],) for p in pixels])
        self.assert_failed_check(self.analyze(compare_devices=True), "requested_device_comparison")

    def test_single_device_is_sufficient_for_response_acceptance(self):
        self.rows = [row for row in self.rows if row["device"] == "cpu"]
        report = self.analyze()
        self.assertEqual(report["status"], "response_checks_passed", report)
        self.assertFalse(report["device_comparison_required"])

    def test_explicit_device_comparison_requires_both(self):
        self.rows = [row for row in self.rows if row["device"] == "cpu"]
        self.assertIn("both CPU and GPU", self.analyze(compare_devices=True)["errors"][0])

    def test_nonfinite_pixel_rejected(self):
        self.images[self.rows[0]["label"]][2][0] = (float("nan"), 0., 0., 1.)
        self.assertIn("finite", self.analyze()["errors"][0])

    def test_wrong_input_power_cannot_pass_under_correct_label(self):
        self.rows[1]["specular_power"] = 2.
        self.assertIn("material inputs differ", self.analyze()["errors"][0])

    def test_archived_image_path_is_resolved_from_local_label(self):
        for row in self.rows:
            row["image"] = "Z:/unavailable/original/output.png"
        self.assertEqual(self.analyze()["status"], "response_checks_passed")


if __name__ == "__main__":
    unittest.main()
