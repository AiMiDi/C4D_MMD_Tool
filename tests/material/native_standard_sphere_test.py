"""Production Matcap Sphere regression for C4D Standard and RS Standard.

Run inside a task-owned c4dpy host. Native sampling, graph readback and editor
transactions are separate from the saved-scene render matrix.
"""

from pathlib import Path


def run(suite, renderer):
    import maxon
    import shader_binding_test as binding
    import native_toon_test as toon
    c4d, ids, model = suite.c4d, suite.ids, suite.model
    fields = [0, 1, 2, 3, 4, 5, 6, 13, 14, 15]

    def snapshot():
        rows = []
        for material in suite.doc.GetMaterials():
            metadata = material.GetDataInstance().GetContainer(1068715)
            if metadata.GetInt32(100) != 2:
                raise AssertionError("Production import did not bind material " + material.GetName())
            row = {"material": material.GetName(), "mode": metadata.GetInt32(180),
                   "active": metadata.GetBool(181)}
            if renderer == "redshift":
                if metadata.GetInt32(170) != 2 or metadata.GetInt32(171) != 1:
                    raise AssertionError("RS Standard did not install the Matcap profile")
                token = metadata.GetString(102)
                meshes = [mesh for mesh in suite.nodes(c4d.Opolygon)
                          if any(token in entry.GetString(c4d.DESC_NAME)
                                 for _, entry in mesh.GetUserDataContainer())]
                if len(meshes) != 1:
                    raise AssertionError("RS attributes do not identify one mesh")
                row["fields"] = {}
                for field in fields:
                    value = meshes[0][c4d.DescID(c4d.DescLevel(c4d.ID_USERDATA),
                                                  c4d.DescLevel(metadata.GetInt32(400 + field)))]
                    row["fields"][field] = suite.vector(value) if isinstance(value, c4d.Vector) else [float(value)]
                row["attribute_count"] = sum(token in entry.GetString(c4d.DESC_NAME)
                                             for _, entry in meshes[0].GetUserDataContainer())
                if row["attribute_count"] != 10:
                    raise AssertionError("RS profile allocated overlapping or unused fields")
            else:
                if metadata.GetInt32(182) != 1 or material[c4d.MATERIAL_USE_ENVIRONMENT]:
                    raise AssertionError("Standard still uses the Environment approximation")
                output = material[c4d.MATERIAL_COLOR_SHADER]
                row["color"] = binding.sample(c4d, suite.doc, output, c4d.CHANNEL_COLOR)[0]
                row["opacity"] = binding.sample(c4d, suite.doc, material[c4d.MATERIAL_ALPHA_SHADER], c4d.CHANNEL_ALPHA, True)[0]
            rows.append(row)
        return rows

    baseline = snapshot()
    if renderer == "standard":
        for row in baseline:
            image = [64./255., 128./255., 192./255.]
            diffuse = [.2,.4,.6]
            base = [d*t for d,t in zip(diffuse,image)] if row["material"] == "textured" else diffuse
            binding.near(row["color"], [b+s for b,s in zip(base,image)], "Standard Sphere Add formula")
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .5
    model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 1
    model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = .25
    mixed = snapshot()
    if renderer == "redshift":
        expected = {"plain": ([1.1]*3, [-.1]*3, [.04,-.01,.02]),
                    "textured": ([.818125,.88825,.98175], [.065]*3, [.04,-.01,.02])}
        for row in mixed:
            for field, wanted in zip((13,14,15), expected[row["material"]]):
                binding.near(row["fields"][field], wanted, "PBR Sphere Morph " + row["material"])
    else:
        sphere_factors = {"plain": ([1.1]*3, [-.1]*3, [.04,-.01,.02]),
                          "textured": ([.818125,.88825,.98175], [.065]*3, [.04,-.01,.02])}
        image = [64./255.,128./255.,192./255.]
        for row in mixed:
            textured = row["material"] == "textured"
            diffuse = [.225 if textured else .25,.4,.6]
            if textured:
                texture = [min(1.,max(0.,t*scale+.015625))+add
                           for t,scale,add in zip(image,[.861328125,1.0458984375,.93515625],[.1,.05,0.])]
                base = [d*t for d,t in zip(diffuse,texture)]
            else:
                base = diffuse
            scales,biases,adds = sphere_factors[row["material"]]
            sphere = [min(1.,max(0.,t*scale+bias))+add
                      for t,scale,bias,add in zip(image,scales,biases,adds)]
            binding.near(row["color"],[b+s for b,s in zip(base,sphere)],"Standard independent Sphere RGBA Morph formula")
    model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
    if snapshot() != baseline:
        raise AssertionError("Matcap preview did not reset")

    model[ids["MODEL_MATERIAL_LIST"]] = 1
    material = model[ids["MODEL_MATERIAL_LINK"]]
    if renderer == "redshift":
        graph = material.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
        root = graph.GetViewRoot()
        sampler = root.FindChild("cmt_sphere_texture")
        setting = sampler.GetInputs().FindChild(toon.PREFIX + "texturesampler.prefer_sharp")
        with graph.BeginTransaction() as transaction:
            setting.SetPortValue(False)
            transaction.Commit()
        sampling = str(setting.GetPortValue())
    else:
        output = material[c4d.MATERIAL_COLOR_SHADER]
        sampler = output[2005]
        setting = c4d.BITMAPSHADER_INTERPOLATION
        sampler[setting] = c4d.BITMAPSHADER_INTERPOLATION_NONE
        sampling = sampler[setting]
    # Sphere RGB and embedded A must never enter the independent opacity path.
    modes = []
    for mode in (1, 0, 3, 2):
        model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = mode
        metadata = material.GetDataInstance().GetContainer(1068715)
        if metadata.GetInt32(180) != mode or metadata.GetBool(181) != (mode in (1, 2)):
            raise AssertionError("Sphere mode did not synchronize: " + str(mode))
        if mode == 3 and "SubTexture" not in metadata.GetString(175):
            raise AssertionError("SubTexture diagnostic was lost")
        current = snapshot()
        if renderer == "standard":
            for row, old in zip(current, baseline):
                binding.near(row["opacity"], old["opacity"], "Sphere must not alter opacity")
        modes.append(current)
    path = str(suite.output / "colored-alpha.png")
    model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = ""
    if material.GetDataInstance().GetContainer(1068715).GetBool(181):
        raise AssertionError("Empty Sphere path did not bypass Matcap")
    model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = path
    model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = str(suite.output / "missing.png")
    if model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] != path:
        raise AssertionError("Bad Sphere file overwrote authoritative data")
    actual_sampling = str(setting.GetPortValue()) if renderer == "redshift" else sampler[setting]
    if sampling != actual_sampling:
        raise AssertionError("Sphere edit overwrote sampling settings")

    # Protect artist edits in an inactive RS combine or the Standard child link.
    if renderer == "redshift":
        artist = root.FindChild("cmt_morph_specular").GetOutputs().FindChild(toon.PREFIX + "rsuserdatacolor.out")
        dormant = root.FindChild("cmt_sphere_combine_mul").GetInputs().FindChild(toon.PREFIX + "rsmathmulvector.input1")
        with graph.BeginTransaction() as transaction:
            artist.Connect(dormant)
            transaction.Commit()
    else:
        artist = c4d.BaseShader(c4d.Xcolor)
        material.InsertShader(artist)
        output[2005] = artist
    model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 1
    if model[ids["MODEL_MATERIAL_SPHERE_MODE"]] != 2:
        raise AssertionError("Sphere edit replaced an artist input")
    if renderer == "redshift":
        with graph.BeginTransaction() as transaction:
            artist.Connect(dormant, maxon.WIRE_MODE.REMOVE)
            transaction.Commit()
    else:
        output[2005] = sampler
        artist.Remove()

    suite.doc.FlushUndoBuffer()
    suite.doc.StartUndo()
    suite.doc.AddUndo(c4d.UNDOTYPE_CHANGE, model)
    model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 1
    suite.doc.EndUndo()
    records = []
    for action, expected in (("undo",2), ("redo",1)):
        if not (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo()):
            raise AssertionError("Missing Sphere " + action)
        saved = suite.output / (renderer + "-sphere-" + action + ".c4d")
        if not c4d.documents.SaveDocument(suite.doc, str(saved), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
            raise AssertionError("Immediate save failed")
        loaded = c4d.documents.LoadDocument(str(saved), c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS, None)
        current = next(mat for mat in loaded.GetMaterials() if mat.GetName() == "textured")
        if current.GetDataInstance().GetContainer(1068715).GetInt32(180) != expected:
            raise AssertionError("Sphere mode did not survive " + action + "/reopen")
        records.append(action)
    return {"baseline":baseline,"mixed":mixed,"modes":modes,"undo_redo_reopen":records,
            "artist_input_preserved":True,"sampling_preserved":True,"passed":True}


def repair_legacy_seven_fields(suite):
    """Explicitly migrate a v2 seven-field graph without changing runtime reads."""
    import maxon
    import native_toon_test as toon
    c4d,ids,model = suite.c4d,suite.ids,suite.model
    model[ids["MODEL_MATERIAL_LIST"]] = 1
    material = model[ids["MODEL_MATERIAL_LINK"]]
    mesh = model[ids["MODEL_MATERIAL_MESH_LINK"]]
    metadata = material.GetDataInstance().GetContainer(1068715)
    graph = material.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
    root = graph.GetRoot()
    # Restore the actual old graph contract, including its original key range.
    with graph.BeginTransaction() as transaction:
        for node in list(root.GetChildren()):
            if str(node.GetId()).startswith(("cmt_sphere_","cmt_morph_sphere_")):
                node.Remove()
        surface = graph.GetNode(maxon.NodePath(metadata.GetString(103)))
        source = root.FindChild("cmt_texture_diffuse").GetOutputs().FindChild(toon.PREFIX+"rsmathmulvector.out")
        source.Connect(surface.GetInputs().FindChild(toon.PREFIX+"standardmaterial.base_color"))
        transaction.Commit()
    for field in range(7):
        metadata.SetInt32(120+field,metadata.GetInt32(400+field))
    for field in (13,14,15):
        mesh.RemoveUserData(c4d.DescID(c4d.DescLevel(c4d.ID_USERDATA),c4d.DescLevel(metadata.GetInt32(400+field))))
    metadata.RemoveData(170)
    metadata.RemoveData(171)
    material.GetDataInstance().SetContainer(1068715,metadata)
    suite.evaluate(0)
    if material.GetDataInstance().GetContainer(1068715).GetInt32(170) != 0:
        raise AssertionError("Runtime silently upgraded the seven-field graph")
    suite.doc.FlushUndoBuffer()
    c4d.CallButton(model,ids["MODEL_MATMORPH_REPAIR"])
    upgraded = material.GetDataInstance().GetContainer(1068715)
    if upgraded.GetInt32(170) != 2:
        raise AssertionError("Explicit repair did not migrate v2 seven-field binding: "+str(model[ids["MODEL_MATMORPH_STATUS"]]))
    count = sum(upgraded.GetString(102) in entry.GetString(c4d.DESC_NAME) for _,entry in mesh.GetUserDataContainer())
    if count != 10:
        raise AssertionError("Migration left obsolete attributes")
    records = []
    for action,profile in (("undo",0),("redo",2)):
        assert (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo())
        saved = suite.output/("seven-fields-"+action+".c4d")
        assert c4d.documents.SaveDocument(suite.doc,str(saved),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT)
        loaded = c4d.documents.LoadDocument(str(saved),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
        current = next(mat for mat in loaded.GetMaterials() if mat.GetName() == "textured")
        if current.GetDataInstance().GetContainer(1068715).GetInt32(170) != profile:
            raise AssertionError("Seven-field migration failed immediate "+action+"/reopen")
        records.append(action)
    return {"runtime_preserved":True,"explicit_repair":True,"attributes":count,"undo_redo_reopen":records,"passed":True}
