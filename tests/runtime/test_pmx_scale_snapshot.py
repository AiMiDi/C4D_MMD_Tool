"""The export oracle must observe geometry/physics without rescaling metadata."""
import copy
import importlib.util
from pathlib import Path
import sys
import tempfile
import unittest

REPO = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPO / "scripts"))
import c4d_regression_fixtures as fixtures
spec = importlib.util.spec_from_file_location("pmx_scale_fixture_runner", REPO / "scripts/c4d_production_mcp_validation.py")
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)


class PMXScaleSnapshotTests(unittest.TestCase):
    def setUp(self):
        self.folder = tempfile.TemporaryDirectory(prefix="cmt-pmx-scale-", dir="S:/tmp" if Path("S:/tmp").is_dir() else None)
        self.addCleanup(self.folder.cleanup)
        self.path = Path(self.folder.name) / "fixture.pmx"
        self.path.write_bytes(fixtures.make_pmx())
        self.snapshot = fixtures.read_pmx_morphs_and_frames(self.path, include_physics=True)

    def test_snapshot_reads_geometry_and_physics(self):
        self.assertEqual(self.snapshot["vertex_data"][1]["position"], (1., 0., 0.))
        self.assertEqual(self.snapshot["vertex_data"][1]["uv"], (1., 0.))
        self.assertEqual(self.snapshot["rigidbodies"][1]["position"], (0., 1., 0.))
        self.assertEqual(self.snapshot["joints"][0]["translate_lower"], (-10., -10., -10.))

    def test_scale_oracle_rejects_ignored_multiplier(self):
        with self.assertRaises(AssertionError):
            runner.assert_pmx_length_ratio(self.snapshot, self.snapshot, .5)

    def test_scale_oracle_checks_physics_and_nondimensional_data(self):
        scaled = copy.deepcopy(self.snapshot)
        for vertex in scaled["vertex_data"]: vertex["position"] = tuple(x * .5 for x in vertex["position"])
        for bone in scaled["bones"]:
            bone["position"] = tuple(x * .5 for x in bone["position"])
            if not bone["flags"] & 1: bone["tail"] = tuple(x * .5 for x in bone["tail"])
        for rigid in scaled["rigidbodies"]:
            for field in ("position", "size"): rigid[field] = tuple(x * .5 for x in rigid[field])
        for joint in scaled["joints"]:
            for field in ("position", "translate_lower", "translate_upper"):
                joint[field] = tuple(x * .5 for x in joint[field])
        runner.assert_pmx_length_ratio(self.snapshot, scaled, .5)
        scaled["rigidbodies"][0]["coefficients"] = (2., 0., 0., 0., .5)
        with self.assertRaises(AssertionError): runner.assert_pmx_length_ratio(self.snapshot, scaled, .5)

    def test_snapshot_rejects_truncated_physics_and_trailing_data(self):
        original = self.path.read_bytes()
        for changed in (original[:-1], original + b"unexpected"):
            self.path.write_bytes(changed)
            with self.assertRaises(ValueError): fixtures.read_pmx_morphs_and_frames(self.path, include_physics=True)


if __name__ == "__main__": unittest.main()
