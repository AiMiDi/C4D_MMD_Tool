"""Native production Sphere binding, editing and Morph regression.

The generated fixture uses ordinary UVs, a constant colored sphere bitmap and
independent Mul/Add RGBA factors. Run inside a task-owned c4dpy host.
"""

from pathlib import Path
import hashlib
import struct


def prepare(directory):
    import native_toon_test as toon
    from native_diffuse_test import _pack, _text
    directory = Path(directory)
    fixtures = toon.prepare(directory)
    data = bytearray((directory / "toon-binding.pmx").read_bytes())
    for name in ("plain", "textured"):
        offset = data.index(_text(name) * 2) + len(_text(name)) * 2
        struct.pack_into("i", data, offset + 69, 0)
        data[offset + 73] = 2
    for name, header, factor in (
        ("Tint", _pack("BBiiB", 4, 8, 1, -1, 1), (.08, -.02, .04, .2)),
        ("Multiply", _pack("BBiiB", 4, 8, 1, 1, 0), (.5, .8, 1.2, .4)),
    ):
        start = data.index(_text(name) * 2 + header) + len(_text(name)) * 2 + len(header)
        struct.pack_into("4f", data, start + 20 * 4, *factor)
    path = directory / "sphere-binding.pmx"
    path.write_bytes(data)
    fixtures[path.name] = {"path": str(path), "sha256": hashlib.sha256(data).hexdigest()}
    return fixtures


def run(suite):
    import maxon
    import native_toon_test as toon
    import shader_binding_test as binding
    c4d, ids, model = suite.c4d, suite.ids, suite.model
    baseline = toon.binding_snapshot(suite)
    if any(row["values"][13:] != [[1., 1., 1.], [0., 0., 0.], [0., 0., 0.]] for row in baseline):
        raise AssertionError("Sphere neutral factors were not installed")
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .5
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 1
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .25
    mixed = toon.binding_snapshot(suite)
    # Hand-calculated affine coefficients: Mul.A=.85, Add.A=.1;
    # Mul.RGB=(.875,.95,1.05). Add RGB remains independent of saturation.
    expected = {"plain": ([1.1]*3, [-.1]*3, [.04,-.01,.02]),
                "textured": ([.818125,.88825,.98175], [.065]*3, [.04,-.01,.02])}
    for row in mixed:
        for actual, wanted in zip(row["values"][13:], expected[row["material"]]):
            binding.near(actual, wanted, "Sphere preview " + row["material"])
        if row["nodes"] != next(base["nodes"] for base in baseline if base["material"] == row["material"]):
            raise AssertionError("Sphere preview rebuilt graph nodes")
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
    if toon.binding_snapshot(suite) != baseline:
        raise AssertionError("Sphere preview did not reset to baseline")
    model[ids["MODEL_MATERIAL_LIST"]] = 1
    material = model[ids["MODEL_MATERIAL_LINK"]]
    graph = material.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
    root = graph.GetViewRoot()
    sampler = root.FindChild("cmt_sphere_texture")
    with graph.BeginTransaction() as transaction:
        sampler.GetInputs().FindChild(toon.PREFIX + "texturesampler.prefer_sharp").SetPortValue(False)
        transaction.Commit()
    sampling_before = str(sampler.GetInputs().FindChild(toon.PREFIX + "texturesampler.prefer_sharp").GetPortValue())
    # Mode switches must retain all roles and restore via immediate save/reopen.
    modes = []
    for mode in (1, 0, 3, 2):
        model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = mode
        metadata = material.GetDataInstance().GetContainer(1068715)
        if metadata.GetInt32(180) != mode or metadata.GetBool(181) != (mode in (1, 2)):
            raise AssertionError("Sphere mode was not synchronized")
        if mode == 3 and "SubTexture" not in metadata.GetString(175):
            raise AssertionError("SubTexture lost its unsupported diagnostic")
        modes.append(mode)
    model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = ""
    if material.GetDataInstance().GetContainer(1068715).GetBool(181):
        raise AssertionError("Empty Sphere path did not bypass contribution")
    path = str(suite.output / "colored-alpha.png")
    model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = path
    model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = str(suite.output / "missing.png")
    if model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] != path:
        raise AssertionError("Invalid Sphere path overwrote authoritative data")
    if str(sampler.GetInputs().FindChild(toon.PREFIX + "texturesampler.prefer_sharp").GetPortValue()) != sampling_before:
        raise AssertionError("Sphere path update overwrote artist sampling settings")
    artist_source = root.FindChild("cmt_toon_ramp").GetOutputs().FindChild(toon.PREFIX + "rsramp.outcolor")
    dormant_input = root.FindChild("cmt_sphere_combine_mul").GetInputs().FindChild(toon.PREFIX + "rsmathmulvector.input1")
    with graph.BeginTransaction() as transaction:
        artist_source.Connect(dormant_input)
        transaction.Commit()
    model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 1
    if model[ids["MODEL_MATERIAL_SPHERE_MODE"]] != 2:
        raise AssertionError("A dormant artist connection was overwritten by a mode switch")
    with graph.BeginTransaction() as transaction:
        artist_source.Connect(dormant_input, maxon.WIRE_MODE.REMOVE)
        transaction.Commit()
    suite.doc.FlushUndoBuffer()
    suite.doc.StartUndo()
    suite.doc.AddUndo(c4d.UNDOTYPE_CHANGE, model)
    model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 1
    suite.doc.EndUndo()
    undo_redo = []
    for action, expected_mode in (("undo",2),("redo",1)):
        assert (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo())
        saved = suite.output / ("sphere-" + action + ".c4d")
        assert c4d.documents.SaveDocument(suite.doc, str(saved), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT)
        loaded = c4d.documents.LoadDocument(str(saved), c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS, None)
        current = next(m for m in loaded.GetMaterials() if m.GetName() == "textured")
        if current.GetDataInstance().GetContainer(1068715).GetInt32(180) != expected_mode:
            raise AssertionError("Sphere mode did not survive " + action + " and immediate reopen")
        undo_redo.append(action)
    suite.model = next(node for node in suite.nodes(1056724))
    suite.model[ids["MODEL_MATERIAL_LIST"]] = 1
    suite.model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 2
    final = toon.binding_snapshot(suite)
    return {"baseline":baseline,"mixed":mixed,"final":final,"modes":modes,
            "undo_redo_save_reopen":undo_redo,"artist_connection_preserved":True,"passed":True}
