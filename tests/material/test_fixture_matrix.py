"""Pure input/oracle and async ownership regressions; no C4D installation used."""

from pathlib import Path
from types import SimpleNamespace
import hashlib
import json
import os
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
import zlib

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parent.parent / "scripts"))
import material_fixture_matrix as matrix
import native_render_matrix as render
import native_diffuse_test as diffuse
from c4d_regression_fixtures import read_pmx_bones, read_pmx_morphs_and_frames


def case(name):
    return next(item for item in matrix.CASES if item["name"] == name)


def temporary_directory(prefix):
    configured = os.environ.get("CMT_TEST_TEMP_DIR")
    local_root = Path("S:/tmp")
    if configured:
        temporary_root = Path(configured)
    elif os.name == "nt" and local_root.is_dir():
        temporary_root = local_root
    else:
        temporary_root = Path(tempfile.gettempdir())
    temporary_root.mkdir(parents=True, exist_ok=True)
    return tempfile.TemporaryDirectory(prefix=prefix, dir=temporary_root)


class InputAndOracleTests(unittest.TestCase):
    def test_png_rgb_has_no_synthetic_alpha(self):
        content = matrix.png_bytes(case("rgb_without_alpha")["stripes"], False)
        self.assertEqual(content[25], 2)  # PNG truecolor, not truecolor-with-alpha.
        offset, data = 8, b""
        while offset < len(content):
            size = struct.unpack_from(">I", content, offset)[0]
            kind = content[offset + 4:offset + 8]
            payload = content[offset + 8:offset + 8 + size]
            self.assertEqual(struct.unpack_from(">I", content, offset + 8 + size)[0],
                             zlib.crc32(kind + payload))
            if kind == b"IDAT":
                data += payload
            offset += 12 + size
        rows = zlib.decompress(data)
        self.assertEqual(len(rows), matrix.SIZE * (1 + matrix.SIZE * 3))
        self.assertEqual(rows[:13], b"\0" + bytes((32, 32, 32)) * 4)

    def test_rgba_encodes_independent_alpha(self):
        content = matrix.png_bytes(case("gray_varied_alpha")["stripes"], True)
        size = struct.unpack_from(">I", content, 33)[0]
        rows = zlib.decompress(content[41:41 + size])
        self.assertEqual(content[25], 6)
        self.assertEqual([rows[1 + stripe * 16:5 + stripe * 16] for stripe in range(4)],
                         [bytes((128, 128, 128, a)) for a in (0, 64, 128, 255)])

    def test_tga_is_rgb24_top_left(self):
        data = matrix.tga_bytes(case("rgb_without_alpha")["stripes"])
        self.assertEqual(data[16:18], bytes((24, 0x20)))
        self.assertEqual(len(data), 18 + matrix.SIZE ** 2 * 3)

    def test_tiff_declares_embedded_unassociated_alpha(self):
        data = matrix.tiff_bytes(case("gray_varied_alpha")["stripes"])
        self.assertEqual(data[:8], b"II*\0\x08\0\0\0")
        count = struct.unpack_from("<H", data, 8)[0]
        tags = {tag: (kind, size, value) for tag, kind, size, value in
                (struct.unpack_from("<HHII", data, 10 + index * 12) for index in range(count))}
        self.assertEqual(tags[338], (3, 1, 2))
        self.assertEqual(tags[277], (3, 1, 4))
        self.assertEqual(data[tags[273][2]:tags[273][2] + 4], bytes((128, 128, 128, 0)))

    def test_unicode_relative_pmx_and_morph_roundtrip(self):
        with temporary_directory(prefix="cmt-matrix-") as directory:
            prepared = matrix.prepare(directory)
            self.assertEqual(len(prepared["cases"]), 9)
            for item in prepared["cases"]:
                parsed = read_pmx_bones(Path(directory) / item["pmx"])
                self.assertEqual(parsed["vertices"], 4)
                self.assertEqual(parsed["materials"], 1)
                self.assertEqual(parsed["textures"], [item["texture_relative"]] if item["stripes"] else [])
                morphs = read_pmx_morphs_and_frames(Path(directory) / item["pmx"])["morphs"]
                self.assertEqual(len(morphs), int(item["morph"]))
                if item["name"] == "rgb_factor_zero":
                    self.assertAlmostEqual(morphs[0]["offsets"][0]["values"][19], -1.)
            for item in prepared["fixtures"].values():
                self.assertEqual(hashlib.sha256(Path(item["path"]).read_bytes()).hexdigest(), item["sha256"])

    def test_opaque_factor_reaches_zero_and_resets(self):
        item = case("rgb_factor_zero")
        self.assertEqual(matrix.expected_opacity(item, 0.), [.5] * 4)
        self.assertEqual(matrix.expected_opacity(item, .5), [.275] * 4)
        self.assertEqual(matrix.expected_opacity(item, 1.), [0.] * 4)
        self.assertEqual(matrix.expected_opacity(item, 0.), [.5] * 4)

    def test_untextured_opacity_ignores_texture_factor(self):
        self.assertEqual(matrix.expected_opacity(case("no_texture"), 1.), [.6] * 4)

    def test_oracle_rejects_rgb_as_alpha(self):
        samples = [{"alpha": 128. / 255. * .5, "rgb": [.1] * 3}] * 4
        with self.assertRaises(AssertionError):
            matrix.verify_render_samples(case("gray_varied_alpha"), 0., samples)

    def test_oracle_rejects_skipped_opaque_factor(self):
        with self.assertRaises(AssertionError):
            matrix.verify_render_samples(case("rgb_factor_zero"), 1., [{"alpha": .6, "rgb": [.1] * 3}] * 4)

    def test_oracle_rejects_texture_loading_white_fallback(self):
        with self.assertRaises(AssertionError):
            matrix.verify_render_samples(case("alpha_full"), 0., [{"alpha": 1., "rgb": [1.] * 3}] * 4)

    def test_camera_framing_matches_actual_import_world_scale(self):
        position = render.frame_camera_position([-1., -1., 0.], [1., 1., 0.], 256, 256)
        scaled = render.frame_camera_position([-8.5, -8.5, 0.], [8.5, 8.5, 0.], 256, 256)
        self.assertAlmostEqual(position[2], -3.2)
        self.assertAlmostEqual(scaled[2] / position[2], 8.5)

    def test_camera_rejects_degenerate_fixture(self):
        with self.assertRaises(AssertionError):
            render.frame_camera_position([0., 0., 0.], [0., 1., 0.], 256, 256)


class FakeWorker:
    def __init__(self, running):
        self.running = running
        self.ends = []
        self.document, self.bitmap = object(), object()
        self.progress, self.progress_type = .3, 2

    def IsRunning(self):
        return self.running

    def End(self, wait):
        self.ends.append(wait)
        if wait and self.running:
            raise AssertionError("Blocked on a running worker")


class FakeSuite:
    def __init__(self, errors=False):
        self.c4d = SimpleNamespace(threading=SimpleNamespace(GeIsMainThread=lambda: True))
        self.closes = 0
        self.errors = errors

    def close(self):
        self.closes += 1
        return {"errors": ["locked"] if self.errors else []}


def session(running, errors=False):
    instance = render.RenderMatrixSession.__new__(render.RenderMatrixSession)
    instance.suite = FakeSuite(errors)
    instance.worker = FakeWorker(running)
    instance.current = {"case": {"name": "alpha_full"}, "configuration": {"shading": "isolated_channels"}}
    instance.renderer = "redshift"
    instance.closed = instance.cancel_requested = False
    return instance


class AsyncOwnershipTests(unittest.TestCase):
    def setUp(self):
        self.restore = render._restore
        render._restore = lambda suite: True

    def tearDown(self):
        render._restore = self.restore

    def test_running_close_requests_cancel_and_retains_document(self):
        instance = session(True)
        worker = instance.worker
        self.assertTrue(instance.close()["cleanup_pending"])
        self.assertEqual(worker.ends, [False])
        self.assertIsNotNone(worker.document)
        self.assertIs(instance.worker, worker)
        self.assertEqual(instance.suite.closes, 0)

    def test_running_collect_never_waits_or_frees(self):
        instance = session(True)
        self.assertEqual(instance.collect()["state"], "running")
        self.assertEqual(instance.worker.ends, [])
        self.assertEqual(instance.suite.closes, 0)

    def test_cancel_then_stopped_close_releases_only_after_worker_end(self):
        instance = session(True)
        instance.close()
        worker = instance.worker
        worker.running = False
        self.assertEqual(instance.close()["state"], "closed")
        self.assertEqual(worker.ends, [False, True])
        self.assertIsNone(worker.document)
        self.assertIsNone(instance.worker)
        self.assertEqual(instance.suite.closes, 1)

    def test_cleanup_failure_remains_retryable(self):
        instance = session(False, errors=True)
        self.assertTrue(instance.close()["cleanup_pending"])
        self.assertFalse(instance.closed)
        instance.suite.errors = False
        self.assertFalse(instance.close()["cleanup_pending"])
        self.assertTrue(instance.closed)

    def test_prepare_failure_persists_failure_before_cleanup(self):
        with temporary_directory(prefix="cmt-material-failure-") as directory:
            events = []
            class PreparationSuite:
                output = Path(directory)
                manifest = {"fixtures": {}}

                def save_failure_scenes(self, name):
                    events.append("capture")
                    return []

                def close(self):
                    receipt = json.loads((self.output / "standard_matrix_receipt.json").read_text())
                    self_assert = receipt["status"] == "failed" and receipt["failed_case"] == "prepare"
                    if not self_assert:
                        raise AssertionError("Failure receipt must precede document cleanup")
                    events.append("close")
                    return {"errors": []}

            with patch.object(matrix, "prepare", side_effect=ValueError("input failed")):
                with self.assertRaisesRegex(ValueError, "input failed"):
                    diffuse.run_matrix(PreparationSuite())
            self.assertEqual(events, ["capture", "close"])
            final = json.loads((Path(directory) / "standard_matrix_receipt.json").read_text())
            self.assertEqual(final["error"]["message"], "input failed")
            self.assertEqual(final["cleanup"], {"errors": []})

    def test_jpeg_codec_uses_optional_data_before_savebits(self):
        with temporary_directory(prefix="cmt-jpeg-signature-") as directory:
            prepared = matrix.prepare(directory)
            calls = []
            class NativeBitmap:
                def InitWith(self, path):
                    return 0, False

                def Save(self, path, format_, data=None, savebits=0):
                    if data is not None:
                        raise TypeError("Argument 3 must be a BaseContainer or None")
                    calls.append((format_, data, savebits))
                    Path(path).write_bytes(b"codec fixture")
                    return 0

            suite = SimpleNamespace(c4d=SimpleNamespace(
                bitmaps=SimpleNamespace(BaseBitmap=NativeBitmap), IMAGERESULT_OK=0, FILTER_JPG=7, SAVEBIT_0=8))
            matrix.add_native_jpeg(suite, prepared)
            self.assertEqual(calls, [(7, None, 8)])
            self.assertEqual(prepared["cases"][-1]["name"], "jpeg_factor_zero")

    def test_calibration_failure_preserves_actual_png_and_alpha_diagnostics(self):
        with temporary_directory(prefix="cmt-calibration-evidence-") as directory:
            instance = session(False)
            instance.width = instance.height = 128
            instance.suite.output = Path(directory)
            instance.suite.c4d.RENDERRESULT_OK = instance.suite.c4d.IMAGERESULT_OK = 0
            instance.suite.c4d.FILTER_PNG = 1
            instance.suite.c4d.SAVEBIT_ALPHA = 2
            instance.current.update(strength=0., reopen=False, source_snapshot={})
            instance.receipts = []
            instance.references = {}
            class AllOpaqueImage:
                def Save(self, path, format_, data=None, savebits=0):
                    Path(path).write_bytes(b"actual-render-evidence")
                    return 0

                def GetInternalChannel(self):
                    return object()

                def GetAlphaPixel(self, alpha, x, y):
                    return 255

            instance.worker.bitmap = AllOpaqueImage()
            instance.worker.result, instance.worker.error = 0, None
            with self.assertRaisesRegex(AssertionError, "unoccupied image border"):
                instance.collect()
            receipt = instance.receipts[0]
            self.assertEqual(Path(receipt["image"]["path"]).read_bytes(), b"actual-render-evidence")
            self.assertEqual(receipt["image_alpha"]["opaque_bbox"], [0, 0, 127, 127])
            self.assertEqual(receipt["image_alpha"]["minimum"], 255)
            self.assertEqual(instance.suite.closes, 1)
            self.assertIsNone(instance.worker)

    def test_redshift_plain_emission_never_queries_an_empty_node(self):
        ports = {}
        class Port:
            def GetPortValue(self):
                return "plain diffuse color"

            def SetPortValue(self, value):
                self.value = value

        class Transaction:
            def __enter__(self):
                return self

            def __exit__(self, *args):
                return False

            def Commit(self):
                self.committed = True

        class Graph:
            def BeginTransaction(self):
                return Transaction()

            def GetNode(self, path):
                raise AssertionError("No texture node may be queried for an untextured material")

        def port(node, direction, identifier):
            ports.setdefault(identifier, Port())
            return ports[identifier]

        fake_maxon = SimpleNamespace(Id=lambda value: value, GraphModelHelper=SimpleNamespace(
            FindNodesByAssetId=lambda *args: []))
        import native_redshift_test as redshift
        with patch.dict(sys.modules, {"maxon": fake_maxon}), \
             patch.object(render, "_redshift_graph", return_value=(Graph(), object())), \
             patch.object(redshift, "_port", side_effect=port):
            render._isolate_color(None, object(), "redshift")
        self.assertEqual(ports[redshift.PREFIX + "standardmaterial.emission_color"].value, "plain diffuse color")
        self.assertEqual(ports[redshift.PREFIX + "standardmaterial.base_color_weight"].value, 0.)


if __name__ == "__main__":
    unittest.main()
