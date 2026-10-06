"""Portable checks for the native harness's evidence and input contracts."""

from pathlib import Path
import hashlib
import json
import math
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest

REPOSITORY = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPOSITORY / "scripts"))
import c4d_regression_fixtures as fixtures
import c4d_runtime_regression as regression


class RegressionContractTests(unittest.TestCase):
    def setUp(self):
        # Temporary evidence belongs under S:/tmp when that drive is available.
        temporary_root = Path("S:/tmp")
        self.temporary = tempfile.TemporaryDirectory(prefix="cmt-regression-contract-",
                                                     dir=temporary_root if temporary_root.is_dir() else None)
        self.directory = Path(self.temporary.name)
        self.inputs = fixtures.generate(self.directory / "inputs")
        self.c4d = SimpleNamespace(documents=SimpleNamespace(GetActiveDocument=lambda: None))

    def tearDown(self):
        self.temporary.cleanup()

    def test_fixture_identity_is_deterministic(self):
        second = fixtures.generate(self.directory / "second")
        self.assertEqual({name: data["sha256"] for name, data in self.inputs.items()},
                         {name: data["sha256"] for name, data in second.items()})
        for data in self.inputs.values():
            path = Path(data["path"])
            self.assertEqual(data["bytes"], path.stat().st_size)
            self.assertEqual(data["sha256"], hashlib.sha256(path.read_bytes()).hexdigest())

    def test_model_has_topology_ik_and_geometry(self):
        model = fixtures.read_pmx_bones(self.inputs["model.pmx"]["path"])
        self.assertEqual(model["vertices"], 3)
        self.assertEqual(model["materials"], 1)
        self.assertEqual([bone["name"] for bone in model["bones"]], ["root", "hinge", "tip", "goal"])
        self.assertEqual([bone["parent"] for bone in model["bones"]], [-1, 0, 1, 0])
        self.assertTrue(model["bones"][3]["flags"] & 0x20)

    def test_mixed_morph_fixture_forces_forward_reference_remapping(self):
        model = fixtures.read_pmx_morphs_and_frames(self.inputs["mixed_morphs.pmx"]["path"])
        self.assertEqual([morph["name"] for morph in model["morphs"]], ["bone_pose", "group", "tint"])
        bone, group, tint = model["morphs"]
        self.assertEqual([bone["kind"], group["kind"], tint["kind"]], [2, 0, 8])
        self.assertEqual(bone["offsets"][0]["bone_index"], 0)
        self.assertAlmostEqual(bone["offsets"][0]["position"][0], .3, places=6)
        quaternion = bone["offsets"][0]["quaternion"]
        self.assertAlmostEqual(sum(component * component for component in quaternion), 1., places=6)
        self.assertAlmostEqual(2. * math.acos(quaternion[3]), math.radians(30.), places=6)
        self.assertAlmostEqual(quaternion[2], math.sin(math.radians(15.)), places=6)
        self.assertEqual(group["offsets"], [{"morph_index": 2, "weight": 1.}])
        self.assertEqual(model["morphs"][group["offsets"][0]["morph_index"]]["name"], "tint")
        frame = next(frame for frame in model["display_frames"] if frame["name"] == "bones")
        self.assertEqual([target for target in frame["targets"] if target["kind"] == 1], [{"kind": 1, "index": 2}])

    def test_toon_fixture_has_separate_texture_and_observable_factor_morph(self):
        path = self.inputs["toon_material.pmx"]["path"]
        model = fixtures.read_pmx_bones(path)
        self.assertEqual(model["materials"], 1)
        self.assertEqual(model["textures"], ["toon_white.bmp"])
        material = model["material_data"][0]
        self.assertEqual(material["toon_mode"], 0)  # Separate toon uses the texture table.
        self.assertEqual(material["toon_index"], 0)
        self.assertEqual(material["texture_index"], -1)
        self.assertEqual(material["sphere_index"], -1)
        self.assertEqual((Path(path).parent / model["textures"][material["toon_index"]]).resolve(),
                         Path(self.inputs["toon_white.bmp"]["path"]).resolve())
        morphs = fixtures.read_pmx_morphs_and_frames(path)["morphs"]
        self.assertEqual(len(morphs), 1)
        self.assertEqual(morphs[0]["kind"], 8)
        self.assertEqual(len(morphs[0]["offsets"]), 1)
        offset = morphs[0]["offsets"][0]
        self.assertEqual(offset["material_index"], 0)
        self.assertEqual(offset["operation"], 1)  # Add, not multiply.
        for actual, expected in zip(offset["values"][-4:], (.2, .3, .4, .1)):
            self.assertAlmostEqual(actual, expected, places=6)

    def test_toon_bitmap_decodes_as_white_at_every_sample(self):
        # Inspect the BMP layout independently of the fixture's writer. White
        # samples everywhere make erroneous toon emission camera-independent.
        data = Path(self.inputs["toon_white.bmp"]["path"]).read_bytes()
        self.assertEqual(data[:2], b"BM")
        file_size, _, _, pixel_offset = struct.unpack_from("<IHHI", data, 2)
        self.assertEqual(file_size, len(data))
        dib_size, width, height, planes, bits, compression = struct.unpack_from("<IiiHHI", data, 14)
        self.assertGreaterEqual(dib_size, 40)
        self.assertEqual((width, height, planes, bits, compression), (2, 4, 1, 24, 0))
        self.assertGreaterEqual(pixel_offset, 14 + dib_size)
        row_stride = ((width * bits + 31) // 32) * 4
        self.assertEqual(len(data) - pixel_offset, row_stride * abs(height))
        samples = [tuple(data[pixel_offset + row * row_stride + column * 3:
                              pixel_offset + row * row_stride + column * 3 + 3])
                   for row in range(abs(height)) for column in range(width)]
        self.assertEqual(set(samples), {(255, 255, 255)})

    def test_morph_reader_preserves_base_material_and_rejects_truncation(self):
        model = fixtures.read_pmx_morphs_and_frames(self.inputs["model.pmx"]["path"])
        self.assertEqual([morph["name"] for morph in model["morphs"]], ["tint"])
        self.assertEqual(model["morphs"][0]["kind"], 8)
        self.assertAlmostEqual(model["morphs"][0]["offsets"][0]["values"][0], .25)
        data = fixtures.make_mixed_morph_pmx()
        start = data.index(fixtures.text("bone_pose") + fixtures.text("bone_pose"))
        path = self.directory / "truncated_morph.pmx"
        path.write_bytes(data[:start + 5])
        with self.assertRaises(ValueError):
            fixtures.read_pmx_morphs_and_frames(path)

    def test_slots_have_observable_differences(self):
        first = fixtures.read_vmd(self.inputs["motion_a.vmd"]["path"])
        second = fixtures.read_vmd(self.inputs["motion_b.vmd"]["path"])
        self.assertEqual([key["frame"] for key in first["motions"]], [0, 2])
        self.assertEqual(first["motions"][-1]["translation"][0], 1.)
        self.assertEqual(second["motions"][-1]["translation"][0], 3.)
        self.assertEqual(first["morphs"][-1]["weight"], 1.)
        self.assertEqual(second["morphs"][-1]["weight"], .5)
        self.assertTrue(first["iks"][0]["show"])
        self.assertFalse(second["iks"][0]["show"])
        self.assertFalse(first["iks"][0]["states"]["goal"])
        self.assertTrue(second["iks"][0]["states"]["goal"])

    def test_camera_has_valid_header_and_sparse_endpoints(self):
        camera = fixtures.read_vmd(self.inputs["camera.vmd"]["path"])
        self.assertEqual(camera["model_name"], "カメラ・照明")
        self.assertEqual([key["frame"] for key in camera["cameras"]], [0, 2])
        self.assertEqual(camera["cameras"][-1]["position"], (2., 1., 2.))
        self.assertEqual(camera["cameras"][-1]["angle"], 45)

    def test_truncated_files_and_invalid_headers_fail(self):
        for name, reader in (("motion_a.vmd", fixtures.read_vmd), ("model.pmx", fixtures.read_pmx_bones)):
            data = Path(self.inputs[name]["path"]).read_bytes()
            path = self.directory / name
            path.write_bytes(data[:20])
            with self.assertRaises((ValueError, UnicodeDecodeError)):
                reader(path)
        path = self.directory / "bad-header.vmd"
        path.write_bytes(b"Invalid".ljust(50, b"\0"))
        with self.assertRaises(ValueError):
            fixtures.read_vmd(path)

    def test_resource_ids_follow_maintained_descriptions(self):
        ids = regression.load_resource_ids(REPOSITORY)
        self.assertEqual(ids["MODEL_MODE"], 1005)
        self.assertEqual(ids["MODEL_MODE_EDIT"], 0)
        self.assertEqual(ids["MODEL_MODE_ANIM"], 1)
        self.assertEqual(ids["PMX_BONE_INDEX"], 10001)
        self.assertIn("JOINT_ATTITUDE_USE_BONE_INDEX", ids)
        self.assertIn("MODEL_DISPLAY_FRAME_ADD_TARGET", ids)
        self.assertEqual(ids["MMD_CAMERA_ANIMATION_SCHEMA_VERSION"], 10000)
        self.assertEqual(ids["MMD_CAMERA_ANIMATION_SCHEMA_VERTICAL_FOV_RADIANS"], 1)

    def test_preparation_never_claims_native_pass(self):
        path = regression.prepare(self.directory / "run")
        manifest = json.loads(path.read_text(encoding="utf-8"))
        receipt = json.loads((path.parent / "receipt.json").read_text(encoding="utf-8"))
        self.assertEqual(manifest["cases"], list(regression.CASE_NAMES))
        self.assertIsNone(manifest["plugin_binary"])
        self.assertFalse(receipt["native_executed"])
        self.assertFalse(receipt["acceptance_eligible"])
        self.assertEqual({case["status"] for case in receipt["cases"]}, {"pending"})

    def test_changed_fixture_is_rejected_before_native_import(self):
        manifest_path = regression.prepare(self.directory / "run")
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        suite = regression.Suite(self.c4d, manifest)
        self.assertTrue(Path(suite.fixture("motion_a.vmd")).is_file())
        Path(manifest["fixtures"]["motion_a.vmd"]["path"]).write_bytes(b"changed")
        with self.assertRaisesRegex(AssertionError, "Input identity changed"):
            suite.fixture("motion_a.vmd")

    def test_missing_bridge_fails_closed(self):
        class MissingBridge(dict):
            def Message(self, _):
                pass

        class Document:
            def __init__(self):
                self.hook = MissingBridge()

            def FindSceneHook(self, _):
                return self.hook

        manifest_path = regression.prepare(self.directory / "run")
        suite = regression.Suite(self.c4d, json.loads(manifest_path.read_text(encoding="utf-8")))
        suite.doc = Document()
        with self.assertRaisesRegex(AssertionError, "CMT_ENABLE_RUNTIME_REGRESSION"):
            suite.call("hello")

    def test_closed_blank_document_is_not_restored(self):
        class ClosedDocument:
            pass

        class LiveDocument:
            def __eq__(self, other):
                if isinstance(other, ClosedDocument):
                    raise ReferenceError("Original C4D document is no longer alive")
                return self is other

            def GetNext(self):
                return None

        class Documents:
            def GetFirstDocument(self):
                return LiveDocument()

            def SetActiveDocument(self, document):
                raise AssertionError("Must not activate a document after original was released")

        class C4D:
            documents = Documents()

        self.assertFalse(regression.restore_active_document(C4D(), ClosedDocument()))

    def test_original_document_is_restored_only_when_still_listed(self):
        class Document:
            def __init__(self, following=None):
                self.following = following

            def GetNext(self):
                return self.following

        original = Document()
        first = Document(original)

        class Documents:
            active = None

            def GetFirstDocument(self):
                return first

            def SetActiveDocument(self, document):
                self.active = document

        class C4D:
            documents = Documents()

        api = C4D()
        self.assertTrue(regression.restore_active_document(api, original))
        self.assertIs(api.documents.active, original)
        self.assertFalse(regression.restore_active_document(api, Document()))


if __name__ == "__main__":
    unittest.main()
