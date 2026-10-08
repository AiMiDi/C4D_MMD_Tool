"""Native UV offset roundtrip across merged/split meshes and scene reload.

The generated fixture affects every corner of two material sections. Independent
PMX reads compare offsets by vertex positions rather than exporter index order.
Only the ordinary PMX UV channel is covered; additional UV channels are separate.
"""

from pathlib import Path
import json
import sys
import traceback

REPOSITORY = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(REPOSITORY / "scripts"), str(REPOSITORY / "tests/material")]
import c4d_regression_fixtures as fixtures
import c4d_native_production_suite as binding


def prepare(directory):
    directory = Path(directory)
    path = directory / "uv-offsets.pmx"
    pack, text = fixtures.pack, fixtures.text
    data = bytearray(b"PMX " + pack("fB", 2., 8) + bytes((1, 0, 4, 4, 4, 4, 4, 4)))
    for value in ("UV offsets", "UV offsets", "Generated native UV fixture", ""):
        data.extend(text(value))
    data.extend(pack("i", 8))
    for left in (-2., 0.):
        for x, y, u, v in ((left, -1., 0., 0.), (left + 2., -1., 1., 0.),
                           (left + 2., 1., 1., 1.), (left, 1., 0., 1.)):
            data.extend(pack("3f3f2fBif", x, y, 0., 0., 0., 1., u, v, 0, 0, 1.))
    data.extend(pack("i12I", 12, 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7))
    data.extend(pack("ii", 0, 2))
    for name in ("left", "right"):
        data.extend(text(name) * 2)
        data.extend(pack("4f3ff3fB4ffiiBBi", .5, .5, .5, 1., 0., 0., 0., 1.,
            0., 0., 0., 1, 0., 0., 0., 1., 0., -1, -1, 0, 0, -1))
        data.extend(text("") + pack("i", 6))
    data.extend(pack("i", 1) + text("root") * 2)
    data.extend(pack("3fiiH3f", 0., 0., 0., -1, 0, 0x1e, 0., .1, 0.))
    data.extend(pack("i", 2))
    data.extend(text("Vertex") * 2 + pack("BBi", 4, 1, 2))
    for vertex in (0, 4):
        data.extend(pack("i3f", vertex, .25, 0., 0.))
    data.extend(text("UV") * 2 + pack("BBi", 4, 3, 8))
    for vertex in range(8):
        data.extend(pack("i4f", vertex, .02 * (vertex + 1), -.015 * (vertex + 1), 0., 0.))
    data.extend(pack("iii", 0, 0, 0))
    path.write_bytes(data)
    return path


def uv_by_position(path):
    data = fixtures.read_pmx_morphs_and_frames(path, include_physics=True)
    uv = next(row for row in data["morphs"] if row["name"] == "UV")
    return {tuple(round(value, 5) for value in (
                *data["vertex_data"][row["vertex_index"]]["position"],
                *data["vertex_data"][row["vertex_index"]]["uv"])):
            row["uv"] for row in uv["offsets"]}


def run(c4d, output, expected_module_sha256):
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    receipt = {"status": "running", "module": loaded_plugin_binary(), "cases": [],
               "additional_uv_verified": False}
    suite = None
    try:
        if not receipt["module"] or receipt["module"]["sha256"] != expected_module_sha256:
            raise AssertionError("Loaded plugin differs from the frozen candidate")
        source = prepare(output)
        expected = uv_by_position(source)
        for multipart in (False, True):
            suite = binding.production_suite(c4d, {"resource_ids": load_resource_ids(REPOSITORY),
                "output": str(output)}, import_options={"multipart": multipart, "materials": False})
            suite.new_document("UV offsets " + str(multipart))
            suite.call("import_model", source)
            suite.model = suite.nodes(1056724)[0]
            suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False
            suite.model[suite.ids["MODEL_MODE"]] = suite.ids["MODEL_MODE_EDIT"]
            suite.evaluate(0)
            for phase in ("direct", "reopened"):
                if phase == "reopened":
                    suite.reopen("uv-" + str(multipart))
                    suite.evaluate(0)
                path = output / (str(multipart) + "-" + phase + ".pmx")
                def source_snapshot():
                    rows = []
                    for mesh in suite.nodes(c4d.Opolygon):
                        tag = mesh.GetTag(c4d.Tposemorph)
                        uv_tag = mesh.GetTag(c4d.Tuvw)
                        rows.append({"uv": [str(uv_tag.GetSlow(i)) for i in range(mesh.GetPolygonCount())],
                            "mode": tag[c4d.ID_CA_POSE_MODE], "active": tag.GetActiveMorphIndex(),
                            "strengths": [float(tag[tag.GetMorphID(i)]) for i in range(tag.GetMorphCount())]})
                    return rows
                before = source_snapshot()
                suite.call("export_model", path)
                if source_snapshot() != before:
                    raise AssertionError("UV export changed source UVs, strengths or editor mode")
                actual = uv_by_position(path)
                row = {"multipart": multipart, "phase": phase,
                       "offset_count": len(actual), "passed": False}
                receipt["cases"].append(row)
                if actual.keys() != expected.keys():
                    raise AssertionError("UV affected vertices changed: " + str(actual))
                for position, uv in expected.items():
                    if any(abs(a - b) > 2e-5 for a, b in zip(actual[position], uv)):
                        raise AssertionError("UV offset changed: " + str((position, actual[position], uv)))
                row["passed"] = True
                row["source_state_preserved"] = True
            suite.close()
            suite = None
        receipt["status"] = "passed"
    except Exception:
        receipt["status"] = "failed"
        receipt["error"] = traceback.format_exc()
    finally:
        if suite:
            receipt["cleanup"] = suite.close()
        (output / "receipt.json").write_text(json.dumps(receipt, ensure_ascii=False, indent=2), encoding="utf-8")
    return receipt
