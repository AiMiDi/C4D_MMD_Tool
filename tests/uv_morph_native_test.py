"""Native UV/vertex morph classification and scene persistence acceptance.

Run inside a task-owned Cinema 4D host with the production plugin. This checks
Attribute Manager descriptions and native morph types, not rendered UV fidelity
or additional-UV channel mapping. The ``reload`` phase loads only saved scenes;
it can run through MCP in the same host or in a separately started host.
"""

from pathlib import Path
import hashlib
import json
import os
import struct
import sys
import traceback

REPOSITORY = Path(__file__).resolve().parents[1]
UV_NAMES = ("UV", "AddUV1", "AddUV2", "AddUV3", "AddUV4")
MORPH_TYPES = {"Vertex": 4, **{name: 16 for name in UV_NAMES}}


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def prepare(path):
    """Write a valid two-part PMX with position and all five UV morph kinds."""
    def pack(fmt, *values):
        return struct.pack("<" + fmt, *values)

    def text(value):
        encoded = value.encode("utf-8")
        return pack("i", len(encoded)) + encoded

    # UTF-8; four additional UV channels; all index sizes are four bytes.
    data = bytearray(b"PMX " + pack("fB", 2., 8) + bytes((1, 4, 4, 4, 4, 4, 4, 4)))
    for value in ("UV classification", "UV classification", "Native UV acceptance fixture", ""):
        data.extend(text(value))
    data.extend(pack("i", 8))
    for left in (-2., 0.):
        for x, y, u, v in ((left, -1., 0., 0.), (left + 2., -1., 1., 0.),
                           (left + 2., 1., 1., 1.), (left, 1., 0., 1.)):
            data.extend(pack("3f3f2f", x, y, 0., 0., 0., 1., u, v))
            data.extend(pack("16f", *([0.] * 16)))
            data.extend(pack("Bif", 0, 0, 1.))
    data.extend(pack("i12I", 12, 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7))
    data.extend(pack("ii", 0, 2))  # No textures, two material sections.
    for name in ("left", "right"):
        data.extend(text(name) + text(name))
        data.extend(pack("4f3ff3fB4ffiiBBi", .5, .5, .5, 1., 0., 0., 0., 1.,
                         0., 0., 0., 1, 0., 0., 0., 1., 0., -1, -1, 0, 0, -1))
        data.extend(text("") + pack("i", 6))
    data.extend(pack("i", 1) + text("root") + text("root"))
    data.extend(pack("3fiiH3f", 0., 0., 0., -1, 0, 0x1e, 0., .1, 0.))
    data.extend(pack("i", 6))
    data.extend(text("Vertex") + text("Vertex") + pack("BBi", 4, 1, 2))
    for vertex in (0, 4):
        data.extend(pack("i3f", vertex, .25, 0., 0.))
    for morph_type, name in enumerate(UV_NAMES, start=3):
        data.extend(text(name) + text(name) + pack("BBi", 4, morph_type, 2))
        for vertex in (0, 4):
            data.extend(pack("i4f", vertex, .2, .1, 0., 0.))
    data.extend(pack("iii", 0, 0, 0))  # Display frames, rigid bodies, joints.
    path = Path(path)
    path.write_bytes(data)
    return {"path": str(path), "sha256": sha256(path), "morph_types": MORPH_TYPES}


def inspect(suite):
    """Read production morph types and each real slider's native parent group."""
    c4d = suite.c4d
    capabilities = suite.production_call("mmdtool_capabilities", {})
    document = next(row["handle"] for row in capabilities["documents"] if row["active"])
    models = suite.production_call("mmdtool_list_models", {"document": document})["models"]
    suite.assert_true(len(models) == 1, "Expected one imported model")
    morphs = suite.production_call("mmdtool_inspect_model", {
        "document": document, "model": models[0]["handle"], "section": "morphs", "limit": 64})["items"]
    suite.assert_true(len(morphs) == len(MORPH_TYPES), "Unexpected or duplicated native morph entries")
    actual_types = {row["name"]: row["type"] for row in morphs}
    suite.assert_true(actual_types == MORPH_TYPES, "Wrong native morph classification: " + str(actual_types))
    description = list(suite.model.GetDescription(c4d.DESCFLAGS_DESC_0))
    groups = {name: suite.ids[name] for name in ("MODEL_MORPH_MESH_GRP", "MODEL_MORPH_UV_GRP")}
    sliders = {}
    for name in MORPH_TYPES:
        matches = [(bc, desc_id, parent) for bc, desc_id, parent in description
                   if bc.GetString(c4d.DESC_NAME) == name
                   and bc[c4d.DESC_CUSTOMGUI] == c4d.CUSTOMGUI_REALSLIDER]
        suite.assert_true(len(matches) == 1, "Missing or duplicated native slider: " + name)
        bc, desc_id, parent = matches[0]
        parent_id = parent[0].id
        expected_parent = groups["MODEL_MORPH_MESH_GRP" if name == "Vertex" else "MODEL_MORPH_UV_GRP"]
        suite.assert_true(parent_id == expected_parent, "Wrong Attribute Manager parent for " + name)
        sliders[name] = {"id": [desc_id[level].id for level in range(desc_id.GetDepth())], "parent": parent_id, "strength": float(suite.model[desc_id])}
    return {"types": actual_types, "groups": groups, "sliders": sliders,
            "polygon_objects": sum(node.GetType() == c4d.Opolygon for node in suite.walk(suite.doc.GetFirstObject()))}


def run(c4d, output, expected_module_sha256, phase="import"):
    """Persist receipts even on failure; close only explicitly owned documents."""
    if phase not in ("import", "reload"):
        raise ValueError("Unknown UV acceptance phase")
    sys.path[:0] = [str(REPOSITORY / "scripts"), str(REPOSITORY / "tests/material")]
    import shader_binding_test as binding
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

    output = Path(output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    receipt_path = output / (phase + "-receipt.json")
    receipt = {"status": "running", "phase": phase, "native_executed": True,
               "c4d_version": c4d.GetC4DVersion(), "host_pid": os.getpid(), "module": loaded_plugin_binary(),
               "rendered_uv_fidelity": False, "cases": []}
    suite = None
    try:
        if receipt["module"] is None or receipt["module"]["sha256"] != expected_module_sha256:
            raise AssertionError("Loaded plugin differs from the frozen candidate")
        fixture_path = output / "uv-classification.pmx"
        if phase == "import":
            receipt["fixture"] = prepare(fixture_path)
        else:
            previous = json.loads((output / "import-receipt.json").read_text(encoding="utf-8"))
            if previous["status"] != "passed" or previous["fixture"]["sha256"] != sha256(fixture_path):
                raise AssertionError("The accepted import evidence or fixture changed")
            receipt["fixture"] = previous["fixture"]
        for multipart in (False, True):
            label = "multipart" if multipart else "single-mesh"
            suite = binding.production_suite(c4d, {"resource_ids": load_resource_ids(REPOSITORY),
                "output": str(output)}, import_options={"multipart": multipart, "materials": False})
            row = {"case": label, "status": "running"}
            receipt["cases"].append(row)
            scene = output / (label + ".c4d")
            if phase == "import":
                suite.new_document("UV morph " + label)
                suite.call("import_model", fixture_path)
                suite.model = suite.nodes(1056724)[0]
            else:
                imported = next(item for item in previous["cases"] if item["case"] == label)
                suite.assert_true(sha256(scene) == imported["scene"]["sha256"], "Saved scene changed")
                document = c4d.documents.LoadDocument(str(scene),
                    c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
                suite.assert_true(document is not None, "Scene load failed")
                suite.register_document(document, label)
                c4d.documents.InsertBaseDocument(document)
                c4d.documents.SetActiveDocument(document)
                suite.doc = document
                suite.model = suite.nodes(1056724)[0]
            suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False
            suite.evaluate(0)
            row["description"] = inspect(suite)
            suite.assert_true(row["description"]["polygon_objects"] == (2 if multipart else 1),
                              "The requested import path did not produce the expected mesh count")
            if phase == "import":
                for index, name in enumerate(MORPH_TYPES):
                    suite.model[suite.morph_strength_id(suite.model, name)] = (index + 1) / 10.
                suite.evaluate(0)
                row["weighted_description"] = inspect(suite)
                saved = c4d.documents.SaveDocument(suite.doc, str(scene),
                    c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT)
                suite.assert_true(saved and scene.is_file(), "Native scene save failed")
                row["scene"] = {"path": str(scene), "sha256": sha256(scene)}
                suite.reopen(label + "-same-host")
                suite.evaluate(0)
                row["reopened_description"] = inspect(suite)
                suite.assert_true(row["reopened_description"] == row["weighted_description"],
                                  "Same-host save/load changed UV classification or strengths")
            else:
                suite.assert_true(row["description"] == imported["weighted_description"],
                                  "Disk-only reload changed UV classification or strengths")
                row["scene"] = imported["scene"]
            row["cleanup"] = suite.close()
            suite.assert_true(not row["cleanup"]["errors"] and not row["cleanup"]["remaining_owned_documents"],
                              "Owned scene cleanup failed")
            suite = None
            row["status"] = "passed"
        receipt["status"] = "passed"
    except Exception:
        receipt["status"] = "failed"
        receipt["error"] = traceback.format_exc()
        if suite is not None:
            receipt["failure_scenes"] = suite.save_failure_scenes("uv-classification")
    finally:
        if suite is not None:
            receipt["cleanup"] = suite.close()
        receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2), encoding="utf-8")
    return receipt
