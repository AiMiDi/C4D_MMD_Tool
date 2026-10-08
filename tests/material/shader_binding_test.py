"""Two-material native fixture for the internal shader binding implementation.

The fixture contains a plain and an RGBA-textured quad, additive/all-material
and multiplicative/single-material offsets, and Group/Flip references. Native
sampling is deliberately separate from image acceptance.
"""

from pathlib import Path
import hashlib
import math

from native_diffuse_test import _pack, _text, _png


def production_suite(c4d, manifest, material_type="standard", import_options=None):
    """Use the maintained production transport in a normal Release build.

    Only fixture import/export is adapted; sampling and authoring still execute
    through the same UI parameters and native shader/node interfaces as before.
    This helper never enables the regression bridge in a shipping module.
    """
    import contextlib
    import io
    import sys
    import uuid
    from c4d_runtime_regression import Suite
    sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "mcp"))
    from mmdtool_mcp.host import fixed_host_code

    class ProductionSuite(Suite):
        def production_call(self, name, arguments):
            namespace = {}
            with contextlib.redirect_stdout(io.StringIO()):
                exec(fixed_host_code(name, arguments, str(uuid.uuid4())), namespace)
            result = namespace["_result"]
            self.assert_true(result["success"], str(result))
            return result["data"]

        def call(self, action, path="", expected=True, **settings):
            if not expected or settings:
                raise ValueError("Production material fixture only adapts basic import/export")
            c4d.documents.SetActiveDocument(self.doc)
            capabilities = self.production_call("mmdtool_capabilities", {})
            if action == "hello":
                return capabilities
            document = next(item["handle"] for item in capabilities["documents"] if item["active"])
            if action == "import_model":
                result = self.production_call("mmdtool_import_pmx", {
                    "document": document, "path": str(path), "position_multiple": 1., "material_type": material_type,
                    **(import_options or {})})
                models = self.nodes(1056724)
                self.assert_true(len(models) == 1, "Import fixture must contain exactly one model")
                self.doc.SetActiveObject(models[0], c4d.SELECTION_NEW)
                return result
            if action == "export_model":
                models = self.production_call("mmdtool_list_models", {"document": document})["models"]
                self.assert_true(len(models) == 1, "Export fixture must contain exactly one model")
                return self.production_call("mmdtool_export_pmx", {
                    "document": document, "model": models[0]["handle"], "path": str(path),
                    "position_multiple": 1., "overwrite": True})
            raise ValueError("No production material fixture mapping for " + action)

    return ProductionSuite(c4d, manifest)


def prepare(directory, include_mesh_morphs=False, texture_multiply=(1., 1., 1., 1.)):
    directory = Path(directory).resolve()
    directory.mkdir(parents=True, exist_ok=True)
    data = bytearray(b"PMX " + _pack("fB", 2., 8) + bytes((1, 0, 4, 4, 4, 4, 4, 4)))
    for text in ("Morph binding", "Morph binding", "native two-material test", ""):
        data.extend(_text(text))
    data.extend(_pack("i", 8))
    for left in (-2., 0.):
        for x, y, u, v in ((left, -1., 0., 0.), (left + 2., -1., 1., 0.),
                            (left + 2., 1., 1., 1.), (left, 1., 0., 1.)):
            data.extend(_pack("3f3f2fBif", x, y, 0., 0., 0., 1., u, v, 0, 0, 1.))
    data.extend(_pack("i12I", 12, 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7))
    data.extend(_pack("i", 1) + _text("colored-alpha.png") + _pack("i", 2))
    for index, name in enumerate(("plain", "textured")):
        data.extend(_text(name) + _text(name))
        data.extend(_pack("4f3ff3fB4ffiiBBi", .2, .4, .6, .5, .1, .2, .3, 10.,
                          0., 0., 0., 1, 0., 0., 0., 1., 0., -1 if index == 0 else 0, -1, 0, 0, -1))
        data.extend(_text("") + _pack("i", 6))
    data.extend(_pack("i", 1) + _text("root") + _text("root"))
    data.extend(_pack("3fiiH3f", 0., 0., 0., -1, 0, 0x1e, 0., .1, 0.))
    data.extend(_pack("i", 6 if include_mesh_morphs else 4))
    data.extend(_text("Tint") + _text("Tint") + _pack("BBiiB", 4, 8, 1, -1, 1))
    add = [.1, 0., 0., .1, .2, 0., 0., 20.] + [0.] * 8 + [.2, .1, 0., .25] + [0.] * 8
    data.extend(_pack("28f", *add))
    data.extend(_text("Multiply") + _text("Multiply") + _pack("BBiiB", 4, 8, 1, 1, 0))
    multiplication = [.5] + [1.] * 27
    multiplication[16:20] = texture_multiply
    data.extend(_pack("28f", *multiplication))
    data.extend(_text("Group") + _text("Group") + _pack("BBiifif", 4, 0, 2, 0, .5, 1, .25))
    data.extend(_text("Flip") + _text("Flip") + _pack("BBiif", 4, 9, 1, 2, 1.))
    if include_mesh_morphs:
        data.extend(_text("Vertex") + _text("Vertex") + _pack("BBii3f", 4, 1, 1, 0, .25, 0., 0.))
        data.extend(_text("UV") + _text("UV") + _pack("BBii4f", 4, 3, 1, 0, .2, 0., 0., 0.))
    data.extend(_pack("iii", 0, 0, 0))
    fixtures = {}
    filename = "binding-mesh.pmx" if include_mesh_morphs else "binding.pmx"
    for name, content in ((filename, data), ("colored-alpha.png", _png())):
        path = directory / name
        path.write_bytes(content)
        fixtures[name] = {"path": str(path), "sha256": hashlib.sha256(content).hexdigest()}
    return fixtures


def near(actual, expected, label):
    if any(not math.isfinite(a) or abs(a - e) > 2e-5 for a, e in zip(actual, expected)):
        raise AssertionError(f"{label}: {actual} != {expected}")


def sample(c4d, doc, shader, channel, alpha=False):
    irs = c4d.modules.render.InitRenderStruct(doc)
    irs.linear_workflow = False
    irs.document_colorprofile = c4d.DOCUMENT_COLORPROFILE_DISABLED
    if shader.InitRender(irs) != c4d.INITRENDERRESULT_OK:
        raise AssertionError("Binding shader InitRender failed")
    try:
        cd = c4d.modules.render.ChannelData()
        cd.p, cd.n, cd.d = c4d.Vector(.5, .5, 0.), c4d.Vector(0., 0., 1.), c4d.Vector()
        cd.t = cd.off = cd.scale = 0.
        cd.texflag = (c4d.TEX_ALPHA if alpha else 0) | (channel << 6)
        value = shader.Sample(cd)
        child = shader.GetDown()
        # Scalar output keeps a legacy child for preservation but does not
        # sample it. In particular, an opaque bitmap has no alpha child.
        child_value = child.Sample(cd) if child and shader[2000] in (0, 3, 4) else c4d.Vector(1.)
        return [value.x, value.y, value.z], [child_value.x, child_value.y, child_value.z]
    finally:
        shader.FreeRender()


def standard_snapshot(suite, additive, multiply, texture_multiply=(1., 1., 1., 1.)):
    c4d = suite.c4d
    result = []
    materials = {m.GetName(): m for m in suite.doc.GetMaterials()}
    for name in ("plain", "textured"):
        material = materials[name]
        metadata = material.GetDataInstance().GetContainer(1068715)
        if metadata.GetInt32(100) != 2:
            raise AssertionError("Import did not install a binding")
        layer = material.GetReflectionLayerID(metadata.GetInt32(109))
        near([material[layer.GetDataID() + c4d.REFLECTION_LAYER_MAIN_VALUE_ROUGHNESS]],
             [1.], "roughness channel must not rescale the shader output")
        textured = name == "textured"
        diffuse = [.2 * (1. - .5 * multiply if textured else 1.) + .1 * additive, .4, .6]
        addition = [.2 * additive, .1 * additive, 0.]
        color, bitmap = sample(c4d, suite.doc, material[c4d.MATERIAL_COLOR_SHADER], c4d.CHANNEL_COLOR)
        factors = [1. + (value - 1.) * multiply for value in texture_multiply]
        multiplied = [(1. - factors[3]) + t * factor * factors[3]
                      for t, factor in zip(bitmap, factors[:3])]
        expected = [d * (min(1., max(0., t + (t - 1.) * .25 * additive)) + a)
                    for d, t, a in zip(diffuse, multiplied, addition)] if textured else diffuse
        near(color, expected, name + " diffuse")
        opacity, bitmap_alpha = sample(c4d, suite.doc, material[c4d.MATERIAL_ALPHA_SHADER], c4d.CHANNEL_ALPHA, True)
        alpha = .5 + .1 * additive
        near(opacity, [a * alpha for a in bitmap_alpha] if textured else [alpha] * 3, name + " alpha")
        specular, _ = sample(c4d, suite.doc, metadata.GetLink(107, suite.doc), c4d.CHANNEL_COLOR)
        roughness, _ = sample(c4d, suite.doc, metadata.GetLink(108, suite.doc), c4d.CHANNEL_COLOR)
        near(specular, [.1 + .2 * additive, .2, .3], name + " specular")
        near(roughness, [(2. / (12. + 20. * additive)) ** .25] * 3, name + " roughness")
        result.append(dict(material=name, color=color, alpha=opacity, specular=specular, roughness=roughness))
    return result


def start_render(suite, frame, renderer, isolated=False):
    """Return a retained worker; caller collects it in a later main-thread call."""
    import native_render_matrix as render
    c4d = suite.c4d
    translator = c4d.AliasTrans()
    if not translator.Init(suite.doc):
        raise RuntimeError("AliasTrans initialization failed")
    clone = suite.doc.GetClone(c4d.COPYFLAGS_NONE, translator)
    translator.Translate(True)
    clone.SetTime(c4d.BaseTime(frame, 30))
    clone.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
    if isolated:
        for material in clone.GetMaterials():
            if renderer == "standard":
                render._isolate_color(c4d, material, renderer)
            else:
                import maxon
                from native_redshift_test import SPACE, PREFIX
                graph, surface = render._redshift_graph(material)
                root = graph.GetNode(maxon.NodePath())
                textures = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "texturesampler"), True)
                textured = material.GetDataInstance().GetContainer(1068715).GetBool(104)
                texture = next((node for node in textures if str(node.GetId()) == "cmt_diffuse_texture"), None) if textured else None
                source = root.FindChild("cmt_texture_diffuse") if texture is not None else root.FindChild("cmt_morph_diffuse")
                source_port = "rsmathmulvector.out" if texture is not None else "rsuserdatacolor.out"
                with graph.BeginTransaction() as transaction:
                    source.GetOutputs().FindChild(PREFIX + source_port).Connect(
                        surface.GetInputs().FindChild(PREFIX + "standardmaterial.emission_color"))
                    for field, value in (("emission_weight", 1.), ("base_color_weight", 0.), ("refl_weight", 0.)):
                        surface.GetInputs().FindChild(PREFIX + "standardmaterial." + field).SetPortValue(value)
                    transaction.Commit()
    bitmap = c4d.bitmaps.MultipassBitmap(320, 160, c4d.COLORMODE_RGB)
    if bitmap is None or bitmap.AddChannel(True, True) is None:
        raise MemoryError("Cannot allocate render RGBA")
    worker = render._worker(c4d, clone, bitmap)
    if not worker.Start(c4d.THREADMODE_ASYNC):
        raise RuntimeError("Render thread did not start")
    return worker


def collect_render(c4d, worker, path, expected_alpha):
    """Save actual RGBA before asserting; never release a running worker."""
    if worker.IsRunning():
        return {"running": True}
    worker.End(True)
    if worker.result != c4d.RENDERRESULT_OK or worker.error:
        raise AssertionError((worker.result, worker.error))
    bitmap = worker.bitmap
    alpha = bitmap.GetInternalChannel()
    result = {"alpha": [bitmap.GetAlphaPixel(alpha, x, 80) for x in (110, 210)],
              "rgb": [bitmap.GetPixel(x, 80) for x in (110, 210)], "frame_result": worker.result}
    bitmap.Save(str(path), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA)
    worker.document = worker.bitmap = None
    if any(abs(a - b) > 1 for a, b in zip(result["alpha"], expected_alpha)):
        raise AssertionError(result)
    return result


def preview_roundtrip(suite):
    """Assert preview isolation from formal weights, persistence, and mode changes."""
    c4d, model, ids = suite.c4d, suite.model, suite.ids
    strength_ids = [did for did, bc in model.GetUserDataContainer()
                    if bc.GetString(c4d.DESC_NAME) in ("Tint", "Multiply", "Group", "Flip")
                    and did[-1].dtype == c4d.DTYPE_REAL]
    formal = [float(model[did]) for did in strength_ids]
    model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    for index, weight in ((0, .5), (2, 1.)):
        model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = index
        model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = weight
    mixed = standard_snapshot(suite, 1., .25)
    if [float(model[did]) for did in strength_ids] != formal:
        raise AssertionError("Preview changed formal morph weights")
    clone_translator = c4d.AliasTrans()
    if not clone_translator.Init(suite.doc):
        raise RuntimeError("Cannot translate preview render clone")
    clone = suite.doc.GetClone(c4d.COPYFLAGS_NONE, clone_translator)
    clone_translator.Translate(True)
    original_doc = suite.doc
    try:
        suite.doc = clone
        cloned = standard_snapshot(suite, 1., .25)
    finally:
        suite.doc = original_doc
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
    disabled = standard_snapshot(suite, 0., 0.)
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    suite.reopen("preview_must_not_persist")
    model = suite.model
    if model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]]:
        raise AssertionError("Preview enabled state survived disk reopen")
    reopened = standard_snapshot(suite, 0., 0.)
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .75
    model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
    if model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] or model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] != 0.:
        raise AssertionError("Entering ANIM did not clear preview")
    return {"mixed": mixed, "render_clone": cloned, "disabled": disabled, "reopened": reopened}


def authoring_roundtrip(suite):
    """Run on a fresh binding fixture; Undo/Redo is checked in later host events."""
    from c4d_regression_fixtures import read_pmx_bones, read_pmx_morphs_and_frames
    c4d, model, ids = suite.c4d, suite.model, suite.ids
    model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = 1.
    export_path = suite.output / "preview_export.pmx"
    suite.call("export_model", export_path)
    original = read_pmx_morphs_and_frames(suite.fixture("binding.pmx"))
    exported = read_pmx_morphs_and_frames(export_path)
    if original["morphs"] != exported["morphs"]:
        raise AssertionError("Preview changed exported Morph definitions")
    original_materials = read_pmx_bones(suite.fixture("binding.pmx"))["material_data"]
    exported_materials = read_pmx_bones(export_path)["material_data"]
    if original_materials != exported_materials:
        raise AssertionError(("Preview changed PMX base materials", original_materials, exported_materials))
    before = standard_snapshot(suite, 1., 0.)
    model[ids["MODEL_MATERIAL_LIST"]] = 1
    c4d.CallButton(model, ids["MODEL_MATERIAL_MOVE_UP_BUTTON"])
    reordered = standard_snapshot(suite, 1., 0.)
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 1
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .5
    standard_snapshot(suite, 1., .5)
    model[ids["MODEL_MATMORPH_LIST"]] = 0
    model[ids["MODEL_MATMORPH_OFFSET_LIST"]] = 0
    c4d.CallButton(model, ids["MODEL_MATMORPH_OFFSET_DELETE_BUTTON"])
    deleted = standard_snapshot(suite, 0., .5)
    c4d.CallButton(model, ids["MODEL_MATMORPH_OFFSET_ADD_BUTTON"])
    near([model[ids["MODEL_MATMORPH_DIFFUSE_ALPHA"]]], [1.], "new multiply neutral")
    model[ids["MODEL_MATMORPH_OP_TYPE"]] = ids["MODEL_MATMORPH_OP_ADD"]
    near([model[ids["MODEL_MATMORPH_DIFFUSE_ALPHA"]]], [1.], "operation switch preserves input")
    c4d.CallButton(model, ids["MODEL_MATMORPH_RESET_NEUTRAL"])
    near([model[ids["MODEL_MATMORPH_DIFFUSE_ALPHA"]]], [0.], "explicit additive neutral")
    neutral = standard_snapshot(suite, 0., .5)
    return {"export": str(export_path), "before": before, "reordered": reordered,
            "deleted_last_offset": deleted, "neutral": neutral}


def base_parameter_binding(suite, verify_authoring_metadata=True):
    """Edit through MMD UI parameters, with no sync button or evaluation call.

    Run on a fresh binding/toon-binding fixture. Check native shader samples or
    object attributes, then verify that Morph preview adds to the edited base.
    RS reader fallbacks must remain the base even while the preview is active.
    """
    import maxon
    c4d, model, ids = suite.c4d, suite.model, suite.ids
    model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
    model[ids["MODEL_MATERIAL_LIST"]] = 0
    material = model[ids["MODEL_MATERIAL_LINK"]]
    metadata = material.GetDataInstance().GetContainer(1068715)
    toon = metadata.GetInt32(170) == 1
    space = maxon.Id("com.redshift3d.redshift4c4d.class.nodespace")
    node_material = material.GetNodeMaterialReference()
    redshift = node_material.HasSpace(space)
    graph = node_material.GetGraph(space) if redshift else None
    node_ids_before = sorted(str(n.GetId()) for n in graph.GetViewRoot().GetChildren()) if graph else []
    edits = {"NAME_LOCAL": "Edited base material", "DIFFUSE_COLOR": c4d.Vector(.31, .42, .53),
             "DIFFUSE_ALPHA": .64, "SPECULAR_COLOR": c4d.Vector(.15, .25, .35), "SPECULAR_POWER": 30.}
    for key, value in edits.items():
        model[ids["MODEL_MATERIAL_" + key]] = value
    if verify_authoring_metadata and material.GetName() != edits["NAME_LOCAL"]:
        raise AssertionError("Material name did not follow the MMD authoring parameter")

    def snapshot(weight):
        expected = [[.31 + .1 * weight, .42, .53], [.64 + .1 * weight],
                    [.15 + .2 * weight, .25, .35], [(2. / (32. + 20. * weight)) ** .25]]
        values = []
        for field in range(4):
            if redshift:
                mesh = model[ids["MODEL_MATERIAL_MESH_LINK"]]
                profile = metadata.GetInt32(170)
                parameter = metadata.GetInt32((300 if toon else 400 if profile == 2 else 120) + field)
                value = mesh[c4d.DescID(c4d.DescLevel(c4d.ID_USERDATA), c4d.DescLevel(parameter))]
                value = [value.x, value.y, value.z] if isinstance(value, c4d.Vector) else [float(value)]
            else:
                shader = metadata.GetLink(105 + field, suite.doc)
                value, _ = sample(c4d, suite.doc, shader,
                                  c4d.CHANNEL_ALPHA if field == 1 else c4d.CHANNEL_COLOR, field == 1)
                if field in (1, 3):
                    near(value, expected[field] * 3, "scalar shader is uniform")
                    value = value[:1]
            near(value, expected[field], "authoring binding field " + str(field))
            values.append(value)
        return values

    base = snapshot(0.)
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .5
    preview = snapshot(.5)
    fallbacks = []
    if redshift and verify_authoring_metadata:
        root = graph.GetViewRoot()
        prefix = "com.redshift3d.redshift4c4d.nodes.core."
        for field, name in enumerate(("diffuse", "opacity", "specular", "roughness")):
            reader = root.FindChild("cmt_morph_" + name)
            kind = "rsuserdatascalar" if field in (1, 3) else "rsuserdatacolor"
            value = reader.GetInputs().FindChild(prefix + kind + ".default").GetPortValue()
            value = [float(value)] if field in (1, 3) else [value.r, value.g, value.b]
            near(value, base[field], "RS preview fallback remains authored base")
            fallbacks.append(value)
        if sorted(str(n.GetId()) for n in root.GetChildren()) != node_ids_before:
            raise AssertionError("Parameter edits rebuilt the graph")
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
    restored = snapshot(0.)
    nodes_unchanged = not graph or sorted(str(n.GetId()) for n in graph.GetViewRoot().GetChildren()) == node_ids_before
    if not nodes_unchanged:
        raise AssertionError("Parameter edits rebuilt the graph")
    return {"base": base, "morph_preview": preview, "restored": restored,
            "reader_defaults": fallbacks, "name": material.GetName(),
            "renderer": "redshift_toon" if toon else "redshift" if redshift else "standard",
            "authoring_metadata_verified": verify_authoring_metadata,
            "graph_nodes_unchanged": nodes_unchanged}


def delete_referenced_morph(suite):
    """Delete Tint while Group is previewed; inspect Undo in a later host event."""
    from c4d_regression_fixtures import read_pmx_morphs_and_frames
    model, ids = suite.model, suite.ids
    model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 2
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = 1.
    suite.doc.FlushUndoBuffer()
    suite.doc.StartUndo()
    suite.doc.AddUndo(suite.c4d.UNDOTYPE_CHANGE, model)
    try:
        suite.call("delete_morph", morph_index=0)
    finally:
        suite.doc.EndUndo()
    path = suite.output / "deleted-referenced-morph.pmx"
    suite.call("export_model", path)
    morphs = read_pmx_morphs_and_frames(path)["morphs"]
    if [morph["name"] for morph in morphs] != ["Multiply", "Group", "Flip"]:
        raise AssertionError(morphs)
    if morphs[1]["offsets"] != [{"morph_index": 0, "weight": .25}]:
        raise AssertionError("Group retained a deleted or shifted target: " + str(morphs[1]))
    if morphs[2]["offsets"] != [{"morph_index": 1, "weight": 1.}]:
        raise AssertionError("Flip no longer targets Group: " + str(morphs[2]))
    if model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] != 1:
        raise AssertionError("Preview selector no longer identifies Group")
    return {"morphs": morphs, "samples": standard_snapshot(suite, 0., .25)}


def edit_texture(suite, material_index, path):
    """Use the same parameter operation as the editor and record one undo step."""
    c4d, model, ids = suite.c4d, suite.model, suite.ids
    model[ids["MODEL_MATERIAL_LIST"]] = material_index
    suite.doc.StartUndo()
    suite.doc.AddUndo(c4d.UNDOTYPE_CHANGE, model)
    try:
        accepted = model.SetParameter(c4d.DescID(ids["MODEL_MATERIAL_TEXTURE_PATH"]),
                                      str(path), c4d.DESCFLAGS_SET_NONE)
    finally:
        suite.doc.EndUndo()
    if not accepted or model[ids["MODEL_MATERIAL_TEXTURE_PATH"]] != str(path):
        raise AssertionError("Texture edit rejected: " + str(model[ids["MODEL_MATMORPH_STATUS"]]))
    suite.evaluate(0)


def texture_snapshot(suite, material_index, textured, expected_alpha, renderer="standard"):
    """Check ownership, finite values, alpha sampling and stable structure size."""
    c4d, model, ids = suite.c4d, suite.model, suite.ids
    model[ids["MODEL_MATERIAL_LIST"]] = material_index
    material = model[ids["MODEL_MATERIAL_LINK"]]
    metadata = material.GetDataInstance().GetContainer(1068715)
    if metadata.GetBool(104) != textured:
        raise AssertionError("Texture-presence metadata did not follow the edit")
    result = {"path": str(model[ids["MODEL_MATERIAL_TEXTURE_PATH"]]), "textured": textured}
    if renderer == "standard":
        alpha, _ = sample(c4d, suite.doc, material[c4d.MATERIAL_ALPHA_SHADER], c4d.CHANNEL_ALPHA, True)
        near(alpha, [expected_alpha] * 3, "edited texture alpha")
        color, _ = sample(c4d, suite.doc, material[c4d.MATERIAL_COLOR_SHADER], c4d.CHANNEL_COLOR)
        if not all(math.isfinite(value) for value in color):
            raise AssertionError("Nonfinite texture color")
        count = sum(1 for _ in suite.walk(material.GetFirstShader()))
        result.update(alpha=alpha, color=color, shader_count=count)
    else:
        import maxon
        graph = material.GetNodeMaterialReference().GetGraph(maxon.Id("com.redshift3d.redshift4c4d.class.nodespace"))
        result["node_count"] = len(graph.GetRoot().GetChildren())
        if textured:
            texture = graph.GetRoot().FindChild("cmt_diffuse_texture")
            port = texture.GetInputs().FindChild("com.redshift3d.redshift4c4d.nodes.core.texturesampler.tex0").FindChild("path")
            if str(port.GetDefaultValue()).replace("\\", "/").removeprefix("file:///") != result["path"].replace("\\", "/"):
                raise AssertionError("Redshift texture path did not follow the edit")
    return result


def use_redshift_materials(suite):
    """Create via plugin authoring UI, reassign only this private fixture's tags."""
    c4d, model, ids = suite.c4d, suite.model, suite.ids
    for index in (0, 1):
        model[ids["MODEL_MATERIAL_LIST"]] = index
        previous = model[ids["MODEL_MATERIAL_LINK"]]
        model[ids["MODEL_MATERIAL_CREATE_TYPE"]] = ids["MODEL_MATERIAL_CREATE_TYPE_REDSHIFT"]
        c4d.CallButton(model, ids["MODEL_MATERIAL_CREATE_BUTTON"])
        current = model[ids["MODEL_MATERIAL_LINK"]]
        if not current or current == previous:
            raise AssertionError("Redshift material creation failed")
        for node in suite.walk(suite.doc.GetFirstObject()):
            for tag in node.GetTags():
                if tag.CheckType(c4d.Ttexture) and tag[c4d.TEXTURETAG_MATERIAL] == previous:
                    tag[c4d.TEXTURETAG_MATERIAL] = current
        previous.Remove()
    suite.evaluate(0)


def redshift_repair_undo_roundtrip(suite, cycles=3):
    """Reproduce structural repair Undo and save before any evaluation pass.

    This catches dangling mesh-tag caches during serialization and verifies
    structural graph Undo independently from model fields. Use only a fresh
    private two-material Redshift fixture.
    """
    import maxon
    c4d, ids = suite.c4d, suite.ids
    space = maxon.Id("com.redshift3d.redshift4c4d.class.nodespace")
    suite.model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    suite.model[ids["MODEL_MATERIAL_LIST"]] = 0
    material = suite.model[ids["MODEL_MATERIAL_LINK"]]
    name = material.GetName()

    def graph_in(document):
        current = next(m for m in document.GetMaterials() if m.GetName() == name)
        return current.GetNodeMaterialReference().GetGraph(space)

    def has_reader(document):
        # C4D 2026 Python IsValid() raises on the null FindChild result. Enumerate
        # actual children so a missing node cannot be mistaken for a broken graph.
        return any(str(node.GetId()) == "cmt_morph_specular"
                   for node in graph_in(document).GetRoot().GetChildren())

    graph = graph_in(suite.doc)
    settings = maxon.DataDictionary()
    settings.Set(maxon.nodes.UndoMode, maxon.nodes.UNDO_MODE.NONE)
    with graph.BeginTransaction(settings) as transaction:
        graph.GetRoot().FindChild("cmt_morph_specular").Remove()
        transaction.Commit()
    suite.doc.FlushUndoBuffer()
    c4d.CallButton(suite.model, ids["MODEL_MATMORPH_REPAIR"])
    if not has_reader(suite.doc):
        raise AssertionError("Repair did not restore the missing owned reader")

    records = []
    for cycle in range(cycles):
        for action, expected in (("undo", False), ("redo", True)):
            if not (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo()):
                raise AssertionError("Missing repair " + action)
            path = suite.output / f"rs-repair-{cycle}-{action}.c4d"
            # Do not evaluate/refresh caches between Undo and this save.
            if not c4d.documents.SaveDocument(suite.doc, str(path),
                    c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
                raise AssertionError("Save failed after " + action)
            restored = has_reader(suite.doc)
            if restored != expected:
                raise AssertionError("Live graph did not follow " + action)
            loaded = c4d.documents.LoadDocument(str(path),
                c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
            if loaded is None:
                raise AssertionError("Could not reopen " + str(path))
            reopened = has_reader(loaded)
            if reopened != expected:
                raise AssertionError("Reopened graph did not follow " + action)
            records.append({"cycle": cycle, "action": action, "saved": True,
                            "live_reader": restored, "reopened_reader": reopened})
    return records


def redshift_upgrade_undo_roundtrip(suite, cycles=3):
    """Upgrade two legacy-shaped RS materials in one undoable authoring action."""
    import maxon
    c4d, ids = suite.c4d, suite.ids
    suite.model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    space = maxon.Id("com.redshift3d.redshift4c4d.class.nodespace")
    settings = maxon.DataDictionary()
    settings.Set(maxon.nodes.UndoMode, maxon.nodes.UNDO_MODE.NONE)
    for material in suite.doc.GetMaterials():
        graph = material.GetNodeMaterialReference().GetGraph(space)
        metadata = material.GetDataInstance().GetContainer(1068715)
        # Retain imported texture/surface nodes, with one unrelated artist node.
        with graph.BeginTransaction(settings) as transaction:
            for node in graph.GetRoot().GetChildren():
                if str(node.GetId()).startswith(("cmt_morph_", "cmt_texture_", "cmt_sphere_")):
                    node.Remove()
            graph.AddChild(maxon.Id("artist_keep"),
                           maxon.Id("com.redshift3d.redshift4c4d.nodes.core.rsuserdatascalar"))
            transaction.Commit()
        for mesh in suite.nodes(c4d.Opolygon):
            for did, entry in list(mesh.GetUserDataContainer()):
                if metadata.GetString(102) in entry.GetString(c4d.DESC_NAME):
                    mesh.RemoveUserData(did)
        legacy = c4d.BaseContainer()
        legacy.SetBool(90, True)
        material.GetDataInstance().SetContainer(1068715, legacy)

    def snapshot(document):
        result = []
        for material in document.GetMaterials():
            graph = material.GetNodeMaterialReference().GetGraph(space)
            nodes = [str(node.GetId()) for node in graph.GetRoot().GetChildren()]
            result.append({"material": material.GetName(),
                "version": material.GetDataInstance().GetContainer(1068715).GetInt32(100),
                "readers": sorted(name for name in nodes if name.startswith("cmt_morph_")),
                "artist": "artist_keep" in nodes})
        return result

    suite.evaluate(0)
    legacy = snapshot(suite.doc)
    if len(legacy) != 2 or any(item["version"] != 0 or item["readers"] for item in legacy):
        raise AssertionError("Legacy structures changed before explicit upgrade")
    suite.doc.FlushUndoBuffer()
    c4d.CallButton(suite.model, ids["MODEL_MATMORPH_UPGRADE"])
    records = []
    for cycle in range(cycles):
        for action, version in (("undo", 0), ("redo", 2)):
            if not (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo()):
                raise AssertionError("Missing batch upgrade " + action)
            path = suite.output / f"rs-upgrade-{cycle}-{action}.c4d"
            if not c4d.documents.SaveDocument(suite.doc, str(path),
                    c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
                raise AssertionError("Batch upgrade save failed")
            actual = snapshot(suite.doc)
            if not all(item["version"] == version and len(item["readers"]) == (10 if version else 0)
                       and item["artist"] for item in actual):
                raise AssertionError("Batch upgrade did not undo/redo both materials: " + str(actual))
            loaded = c4d.documents.LoadDocument(str(path),
                c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
            if loaded is None or snapshot(loaded) != actual:
                raise AssertionError("Batch upgrade save/reopen changed its structure")
            records.append({"cycle": cycle, "action": action, "live_and_reopen": actual})
    return records


def mesh_cache_undo_save_roundtrip(suite, cycles=3):
    """Replace Pose Morph tags through a deep mesh Undo, then save immediately."""
    c4d = suite.c4d
    mesh = suite.nodes(c4d.Opolygon)[0]
    original_name = mesh.GetName()
    suite.doc.FlushUndoBuffer()
    suite.doc.StartUndo()
    suite.doc.AddUndo(c4d.UNDOTYPE_CHANGE, mesh)
    mesh.SetName(original_name + " changed")
    suite.doc.EndUndo()
    suite.evaluate(0)

    def signature(document):
        current = next(node for node in suite.walk(document.GetFirstObject()) if node.CheckType(c4d.Opolygon))
        return {"name": current.GetName(), "points": [suite.vector(p) for p in current.GetAllPoints()],
                "tags": [(tag.GetType(), tag.GetName()) for tag in current.GetTags()],
                "morph_count": current.GetTag(c4d.Tposemorph).GetMorphCount()}

    baseline = signature(suite.doc)
    records = []
    for cycle in range(cycles):
        for action, name in (("undo", original_name), ("redo", original_name + " changed")):
            if not (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo()):
                raise AssertionError("Missing deep mesh " + action)
            path = suite.output / f"mesh-cache-{cycle}-{action}.c4d"
            if not c4d.documents.SaveDocument(suite.doc, str(path),
                    c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
                raise AssertionError("Immediate mesh save failed after " + action)
            loaded = c4d.documents.LoadDocument(str(path),
                c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
            expected = dict(baseline, name=name)
            if signature(suite.doc) != expected or loaded is None or signature(loaded) != expected:
                raise AssertionError("Deep mesh Undo/save/reopen lost mesh or Pose Morph data")
            records.append({"cycle": cycle, "action": action, "saved": True, "reopened": True})
            suite.evaluate(0)
    return records


def independent_binding_undo_roundtrip(suite):
    """Clone a model with shared materials, isolate its bindings, then Undo/Redo."""
    c4d, ids = suite.c4d, suite.ids
    translator = c4d.AliasTrans()
    if not translator.Init(suite.doc):
        raise RuntimeError("Cannot initialize model clone translation")
    source = suite.model
    source[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    clone = source.GetClone(c4d.COPYFLAGS_NONE, translator)
    clone.SetName("Material binding isolation copy")
    suite.doc.InsertObject(clone)
    translator.Translate(True)

    def current_copy():
        return next(node for node in suite.walk(suite.doc.GetFirstObject())
                    if node.GetName() == "Material binding isolation copy")

    def material(model, index):
        model[ids["MODEL_MATERIAL_LIST"]] = index
        return model[ids["MODEL_MATERIAL_LINK"]]

    if any(material(source, i) != material(clone, i) for i in (0, 1)):
        raise AssertionError("Fixture clone did not retain shared material links")
    clone[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    clone[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
    clone[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .75
    suite.evaluate(0)
    diagnostic = str(clone[ids["MODEL_MATMORPH_STATUS"]])
    if not any(word in diagnostic.lower() for word in ("shared", "another", "different")):
        raise AssertionError("Shared model binding was not diagnosed: " + diagnostic)

    records = []
    for index in (0, 1):
        clone = current_copy()
        previous = material(source, index)
        material(clone, index)
        count = len(suite.doc.GetMaterials())
        suite.doc.FlushUndoBuffer()
        c4d.CallButton(clone, ids["MODEL_MATMORPH_INDEPENDENT"])
        independent = material(current_copy(), index)
        if independent == previous or len(suite.doc.GetMaterials()) != count + 1:
            raise AssertionError("Independent binding was not created")
        for cycle in range(2):
            if not suite.doc.DoUndo():
                raise AssertionError("Missing independent binding Undo")
            if material(current_copy(), index) != previous or len(suite.doc.GetMaterials()) != count:
                raise AssertionError("Independent binding Undo did not restore sharing")
            if not suite.doc.DoRedo():
                raise AssertionError("Missing independent binding Redo")
            current = material(current_copy(), index)
            if current == previous or len(suite.doc.GetMaterials()) != count + 1:
                raise AssertionError("Independent binding Redo did not restore isolation")
            if current.GetDataInstance().GetContainer(1068715).GetLink(101, suite.doc) != current_copy():
                raise AssertionError("Independent binding owner was not remapped")
            records.append({"material_index": index, "cycle": cycle, "undo_redo": True})
    suite.evaluate(0)
    if any(material(source, i) == material(current_copy(), i) for i in (0, 1)):
        raise AssertionError("Copy still shares a driven material")
    return {"conflict_diagnostic": diagnostic, "checks": records}
