"""PMX 2.1 impulse data acceptance in a normal production plugin.

Use generated, redistributable data and an independent PMX reader. This checks
data preservation and units, not impulse application in the physics solver.
"""

from pathlib import Path
import hashlib
import json
import struct
import sys
import traceback

REPOSITORY = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(REPOSITORY / "scripts"), str(REPOSITORY / "tests/material")]
import c4d_regression_fixtures as fixtures


def prepare(path):
    material = fixtures.text("tint") * 2 + fixtures.pack("BBi", 4, 8, 1)
    material += fixtures.pack("iB", 0, 1) + fixtures.pack("28f", .25, *([0.] * 27))
    impulse = fixtures.text("kick") * 2 + fixtures.pack("BBi", 4, 10, 2)
    for local, velocity, torque in ((0, (1., 2., 3.), (4., 5., 6.)),
                                    (1, (-2., .5, 7.), (-1., 3., .25))):
        impulse += fixtures.pack("iB3f3f", 1, local, *velocity, *torque)
    original = fixtures.pack("i", 1) + material
    data = fixtures.make_pmx()
    if data.count(original) != 1:
        raise AssertionError("Base fixture morph layout changed")
    data = data.replace(original, fixtures.pack("i", 2) + material + impulse, 1)
    data = data[:4] + struct.pack("<f", 2.1) + data[8:] + fixtures.pack("i", 0)
    path = Path(path)
    path.write_bytes(data)
    return fixtures.read_pmx_morphs_and_frames(path, include_physics=True)


def assert_impulse(path, expected, scale=1., rigid_index=1):
    snapshot = fixtures.read_pmx_morphs_and_frames(path, include_physics=True)
    morph = next(row for row in snapshot["morphs"] if row["name"] == "kick")
    if morph["kind"] != 10 or morph["panel"] != 4 or len(morph["offsets"]) != len(expected):
        raise AssertionError("Impulse definition/offsets changed: " + str(morph))
    for actual, source in zip(morph["offsets"], expected):
        if actual["rigid_index"] != rigid_index or actual["local"] != source["local"]:
            raise AssertionError("Impulse target/local flag changed")
        for field, multiple in (("translate", scale), ("rotate", 1.)):
            if any(abs(a - b * multiple) > 2e-5 for a, b in zip(actual[field], source[field])):
                raise AssertionError("Impulse units changed: " + str(actual))
    return snapshot


def run(c4d, output, expected_module_sha256):
    import c4d_native_production_suite as binding
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    receipt = {"status": "running", "module": loaded_plugin_binary(),
               "physics_application_verified": False, "cases": []}
    suite = None
    try:
        if not receipt["module"] or receipt["module"]["sha256"] != expected_module_sha256:
            raise AssertionError("Loaded plugin differs from the frozen candidate")
        source = output / "impulse.pmx"
        original = prepare(source)
        expected = next(row["offsets"] for row in original["morphs"] if row["name"] == "kick")
        suite = binding.production_suite(c4d, {"resource_ids": load_resource_ids(REPOSITORY),
                                              "output": str(output)})
        suite.new_document("Impulse preservation")
        suite.call("import_model", source)
        suite.model = suite.nodes(1056724)[0]
        suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False
        suite.model[suite.ids["MODEL_MODE"]] = suite.ids["MODEL_MODE_EDIT"]
        suite.evaluate(0)

        def export_case(label, scale=1., rigid_index=1):
            path = output / (label + ".pmx")
            capabilities = suite.production_call("mmdtool_capabilities", {})
            document = next(row["handle"] for row in capabilities["documents"] if row["active"])
            model = suite.production_call("mmdtool_list_models", {"document": document})["models"][0]["handle"]
            suite.production_call("mmdtool_export_pmx", {"document": document, "model": model,
                "path": str(path), "overwrite": True, "position_multiple": 1. / scale})
            snapshot = assert_impulse(path, expected, scale, rigid_index)
            receipt["cases"].append({"name": label, "morphs": snapshot["morphs"],
                "rigidbodies": len(snapshot["rigidbodies"]),
                "sha256": hashlib.sha256(path.read_bytes()).hexdigest(), "passed": True})

        export_case("direct")
        export_case("scale-two", 2.)
        export_case("scale-half", .5)
        scene = output / "impulse.c4d"
        if not c4d.documents.SaveDocument(suite.doc, str(scene),
                c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
            raise AssertionError("Scene save failed")
        suite.reopen("impulse-reopened")
        suite.model = suite.nodes(1056724)[0]
        suite.evaluate(0)
        export_case("reopened")
        document_clone = suite.doc.GetClone(c4d.COPYFLAGS_NONE)
        if document_clone is None:
            raise AssertionError("Document clone failed")
        suite.register_document(document_clone, "impulse-cloned")
        suite.close(keep_documents=(document_clone,))
        c4d.documents.InsertBaseDocument(document_clone)
        c4d.documents.SetActiveDocument(document_clone)
        suite.doc = document_clone
        suite.model = suite.nodes(1056724)[0]
        clone = suite.model
        suite.evaluate(0)
        export_case("cloned")
        # The base fixture has a joint referencing rigid0. Remove that joint
        # before testing impulse-only target remapping after deletion.
        next(node for node in suite.walk(clone) if node.GetName() == "joint").Remove()
        rigid = next(node for node in suite.walk(clone) if node.GetName() == "rigid0")
        rigid.Remove()
        suite.evaluate(0)
        export_case("rigid-remapped", rigid_index=0)
        target = next(node for node in suite.walk(clone) if node.GetName() == "rigid1")
        target.Remove()
        suite.evaluate(0)
        capabilities = suite.production_call("mmdtool_capabilities", {})
        document = next(row["handle"] for row in capabilities["documents"] if row["active"])
        model = suite.production_call("mmdtool_list_models", {"document": document})["models"][0]["handle"]
        protected = output / "protected.pmx"
        protected.write_bytes(b"existing destination must survive")
        from mmdtool_mcp.host import fixed_host_code
        import contextlib
        import io
        import uuid
        namespace = {}
        with contextlib.redirect_stdout(io.StringIO()):
            exec(fixed_host_code("mmdtool_export_pmx", {"document": document, "model": model,
                "path": str(protected), "overwrite": True}, str(uuid.uuid4())), namespace)
        result = namespace["_result"]
        if result["success"] or result["state"] != "failed":
            raise AssertionError("Missing impulse target did not reject export: " + str(result))
        if protected.read_bytes() != b"existing destination must survive":
            raise AssertionError("Failed export overwrote the destination")
        receipt["cases"].append({"name": "missing-rigid-target", "result": result,
                                 "existing_destination_preserved": True, "passed": True})
        receipt["status"] = "passed"
    except Exception:
        receipt["status"] = "failed"
        receipt["error"] = traceback.format_exc()
    finally:
        if suite:
            receipt["cleanup"] = suite.close()
        (output / "receipt.json").write_text(json.dumps(receipt, ensure_ascii=False, indent=2), encoding="utf-8")
    return receipt
