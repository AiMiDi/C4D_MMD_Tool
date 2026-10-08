"""Native RS creation, legacy sync and reverse-sync regression through MMD UI.

Run inside C4D using a normal Release plugin. The suite owns and cleans one
private document; this checks node/base data, not rendered highlight appearance.
"""

from pathlib import Path
import json
import math
import os


def run(c4d, output):
    import maxon
    import shader_binding_test as binding
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

    output = Path(output).resolve()
    output.mkdir(parents=True, exist_ok=False)
    fixtures = binding.prepare(output)
    suite = binding.production_suite(c4d, {
        "resource_ids": load_resource_ids(Path(__file__).resolve().parents[2]),
        "output": str(output)}, material_type="redshift")
    receipt = {"status": "running", "cases": [], "rendered": False,
               "pid": os.getpid(), "c4d_version": c4d.GetC4DVersion(),
               "plugin_binary": loaded_plugin_binary()}
    original = suite.original_document
    guard = None
    core = "com.redshift3d.redshift4c4d.nodes.core."
    space = maxon.Id("com.redshift3d.redshift4c4d.class.nodespace")
    settings = maxon.DataDictionary()
    settings.Set(maxon.nodes.UndoMode, maxon.nodes.UNDO_MODE.NONE)

    def near(actual, expected):
        if any(not math.isfinite(a) or abs(a - b) > 2e-5 for a, b in zip(actual, expected)):
            raise AssertionError(f"Unexpected material values: {actual}, expected {expected}")

    def rgb(color):
        return [float(color.r), float(color.g), float(color.b)]

    def surface(graph):
        nodes = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(core + "standardmaterial"), True)
        if len(nodes) != 1:
            raise AssertionError("Fixture must have exactly one RS Standard surface")
        return nodes[0]

    def port(node, name):
        return node.GetInputs().FindChild(core + "standardmaterial." + name)

    try:
        # C4D auto-closes an untouched empty document when another is inserted.
        if original and original.GetFirstObject() is None and original.GetFirstMaterial() is None:
            guard = c4d.BaseObject(c4d.Onull)
            guard.SetName("CMT specular validation original-document guard")
            original.InsertObject(guard)
        receipt["original_blank_guard_used"] = guard is not None
        suite.new_document("RS ordinary specular")
        suite.call("import_model", fixtures["binding.pmx"]["path"])
        suite.model = suite.nodes(1056724)[0]
        ids = suite.ids
        suite.model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
        for index in range(2):
            suite.model[ids["MODEL_MATERIAL_LIST"]] = index
            material = suite.model[ids["MODEL_MATERIAL_LINK"]]
            graph = material.GetNodeMaterialReference().GetGraph(space)
            node = surface(graph)
            color_port, roughness_port = port(node, "refl_color"), port(node, "refl_roughness")
            # User Data connections retain the defaults written at creation.
            near(rgb(color_port.GetPortValue()), [.1, .2, .3])
            near([float(roughness_port.GetPortValue())], [(2. / 12.) ** .25])
            receipt["cases"].append({"index": index, "creation": "passed"})

            # Convert this owned fixture to the supported legacy structure.
            with graph.BeginTransaction(settings) as transaction:
                for child in list(graph.GetRoot().GetChildren()):
                    if str(child.GetId()).startswith(("cmt_morph_", "cmt_texture_")):
                        child.Remove()
                transaction.Commit()
            legacy = c4d.BaseContainer()
            legacy.SetBool(90, True)
            material.GetDataInstance().SetContainer(1068715, legacy)
            suite.model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]] = c4d.Vector(.7, .4, .2)
            suite.model[ids["MODEL_MATERIAL_SPECULAR_POWER"]] = 30.
            suite.model[ids["MODEL_MATERIAL_DIFFUSE_COLOR"]] = c4d.Vector(.21, .31, .41)
            c4d.CallButton(suite.model, ids["MODEL_MATERIAL_SYNC_BUTTON"])
            if index == 0:
                plain = graph.GetRoot().FindChild("cmt_plain_diffuse")
                near(rgb(plain.GetInputs().FindChild(core + "rsuserdatacolor.default").GetPortValue()), [.21,.31,.41])
            near(rgb(color_port.GetPortValue()), [.7, .4, .2])
            near([float(roughness_port.GetPortValue())], [.5])

            with graph.BeginTransaction(settings) as transaction:
                color_port.SetPortValue(maxon.Color(.3, .6, .9))
                roughness_port.SetPortValue(.25)
                transaction.Commit()
            c4d.CallButton(suite.model, ids["MODEL_MATERIAL_REVERSE_SYNC_BUTTON"])
            value = suite.model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]]
            near([value.x, value.y, value.z], [.3, .6, .9])
            near([suite.model[ids["MODEL_MATERIAL_SPECULAR_POWER"]]], [510.])

            # A connected shader's fallback is not its evaluated base color.
            with graph.BeginTransaction(settings) as transaction:
                reader = graph.AddChild(maxon.Id("artist_specular"), maxon.Id(core + "rsuserdatacolor"))
                reader.GetOutputs().FindChild(core + "rsuserdatacolor.out").Connect(color_port)
                color_port.SetPortValue(maxon.Color(1., 0., 0.))
                scalar = graph.AddChild(maxon.Id("artist_roughness"), maxon.Id(core + "rsuserdatascalar"))
                scalar.GetOutputs().FindChild(core + "rsuserdatascalar.out").Connect(roughness_port)
                roughness_port.SetPortValue(.75)
                transaction.Commit()
            c4d.CallButton(suite.model, ids["MODEL_MATERIAL_REVERSE_SYNC_BUTTON"])
            value = suite.model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]]
            near([value.x, value.y, value.z], [.3, .6, .9])
            near([suite.model[ids["MODEL_MATERIAL_SPECULAR_POWER"]]], [510.])
            receipt["cases"][-1].update(sync="passed", reverse_sync="passed", connected_inputs_preserved=True)

        suite.reopen("ordinary-rs-specular")
        for index in range(2):
            suite.model[ids["MODEL_MATERIAL_LIST"]] = index
            value = suite.model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]]
            near([value.x, value.y, value.z], [.3, .6, .9])
            near([suite.model[ids["MODEL_MATERIAL_SPECULAR_POWER"]]], [510.])
        receipt["save_reopen"] = "passed"
        receipt["status"] = "passed"
    except Exception as error:
        receipt.update(status="failed", error=str(error))
        receipt["failure_scenes"] = suite.save_failure_scenes("rs-specular")
        raise
    finally:
        receipt["cleanup"] = suite.close()
        if guard is not None and receipt["cleanup"]["original_document_restored"]:
            try:
                guard.Remove()
            except Exception as error:
                receipt["cleanup"]["errors"].append({"stage": "remove_guard", "error": str(error)})
        if (receipt["cleanup"]["errors"] or receipt["cleanup"]["remaining_owned_documents"]
                or not receipt["cleanup"]["original_document_restored"]):
            receipt["status"] = "cleanup_pending"
        (output / "receipt.json").write_text(json.dumps(receipt, indent=2), encoding="utf-8")
    if receipt["status"] != "passed":
        raise RuntimeError("Native validation did not complete cleanup; inspect receipt.json")
    return receipt
