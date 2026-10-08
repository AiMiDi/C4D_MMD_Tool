"""Render a production Toon recipe on smooth spheres in an isolated c4dpy host.

The top row deliberately restores the invalid gradient interpolation ID from
the earlier candidate; the bottom row uses the imported recipe unchanged.
Columns are zero Specular, Power 8 and Power 64. Reader defaults isolate the
shader recipe from mesh attributes; this is not a Morph animation image test.
Call run(c4d, output) only in a task-owned headless process: rendering blocks.
"""

from pathlib import Path
import json


def run(c4d, output):
    import maxon
    import redshift
    import native_render_matrix as render
    import native_toon_test as toon
    import shader_binding_test as binding
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

    output = Path(output).resolve()
    output.mkdir(parents=True, exist_ok=False)
    manifest = {"resource_ids": load_resource_ids(Path(__file__).resolve().parents[2]),
                "output": str(output), "fixtures": binding.prepare(output)}
    suite = binding.production_suite(c4d, manifest, material_type="redshift_toon")
    prefs = c4d.plugins.FindPlugin(1036220, c4d.PLUGINTYPE_PREFS)
    devices = []
    for data, identifier, _ in prefs.GetDescription(c4d.DESCFLAGS_DESC_0):
        key = identifier[0].id
        if c4d.PREFS_REDSHIFT_FIRST_DEVICE <= key <= c4d.PREFS_REDSHIFT_LAST_DEVICE:
            devices.append((key, data.GetString(c4d.DESC_NAME), prefs[key]))
    hybrid = prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING]
    preview = prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE]
    receipt = {"module": loaded_plugin_binary(), "redshift": redshift.GetCoreVersion(),
               "c4d": c4d.GetC4DVersion(), "cases": [], "native_mmd_reference": False,
               "rows": ["invalid linear ID", "production linearknot"],
               "powers": [0, 8, 64], "mesh_attribute_animation_test": False}
    try:
        suite.new_model("binding.pmx")
        receipt["binding"] = toon.binding_snapshot(suite)
        source = next(m for m in suite.doc.GetMaterials() if m.GetName() == "plain")
        scene = c4d.documents.BaseDocument()
        scene.SetDocumentName("CMT Toon Specular comparison")
        p = toon.PREFIX
        for row in (0, 1):
            for column, power in enumerate((0, 8, 64)):
                material = source.GetClone(c4d.COPYFLAGS_NONE)
                material.SetName(f"row-{row}-power-{power}")
                scene.InsertMaterial(material)
                graph = material.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
                with graph.BeginTransaction() as transaction:
                    root = graph.GetViewRoot()
                    for role, value, color in (
                        ("diffuse", maxon.Color(.25, .08, .035), True),
                        ("opacity", 1., False),
                        ("specular", maxon.Color(0. if power == 0 else .5), True),
                        ("roughness", (2. / (power + 2.)) ** .25, False),
                    ):
                        reader = root.FindChild("cmt_morph_" + role)
                        asset = "rsuserdatacolor" if color else "rsuserdatascalar"
                        reader.GetInputs().FindChild(p + asset + ".default").SetPortValue(value)
                    if row == 0:
                        knots = root.FindChild("cmt_specular_mask").GetInputs().FindChild(p + "rsramp.ramp")
                        for index in (0, 1):
                            knots.FindChild("_" + str(index)).FindChild("interpolation").SetPortValue(maxon.Id("linear"))
                    transaction.Commit()
                sphere = c4d.BaseObject(c4d.Osphere)
                sphere[c4d.PRIM_SPHERE_RAD] = 40.
                sphere[c4d.PRIM_SPHERE_SUB] = 96
                sphere.SetAbsPos(c4d.Vector((column - 1) * 100., (.5 - row) * 100., 0.))
                sphere.MakeTag(c4d.Tphong)
                tag = c4d.TextureTag()
                tag[c4d.TEXTURETAG_PROJECTION] = c4d.TEXTURETAG_PROJECTION_UVW
                tag.SetMaterial(material)
                sphere.InsertTag(tag)
                scene.InsertObject(sphere)
        camera = c4d.BaseObject(c4d.Ocamera)
        camera.SetAbsPos(c4d.Vector(0., 0., -550.))
        scene.InsertObject(camera)
        scene.GetRenderBaseDraw().SetSceneCamera(camera)
        light = c4d.BaseObject(c4d.Olight)
        light[c4d.LIGHT_TYPE] = c4d.LIGHT_TYPE_DISTANT
        light[c4d.LIGHT_BRIGHTNESS] = 1.
        light.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(.4, -.5, 1.)))
        scene.InsertObject(light)
        rd = scene.GetActiveRenderData()
        for key, value in ((c4d.RDATA_RENDERENGINE, 1036219), (c4d.RDATA_XRES, 600),
                           (c4d.RDATA_YRES, 400), (c4d.RDATA_ALPHACHANNEL, True),
                           (c4d.RDATA_STRAIGHTALPHA, True), (c4d.RDATA_SAVEIMAGE, False)):
            rd[key] = value
        post = render.ensure_redshift_post(c4d, rd)
        assert render.ensure_redshift_post(c4d, rd) == post
        settings = post.GetDataInstance()
        settings.SetInt32(c4d.REDSHIFT_RENDERER_PRIMARY_GI_ENGINE, 0)
        settings.SetInt32(c4d.REDSHIFT_RENDERER_SECONDARY_GI_ENGINE, 0)
        settings.SetInt32(c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES, 16)
        settings.SetInt32(c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES, 64)
        settings.SetBool(c4d.REDSHIFT_RENDERER_DENOISE_ENABLED, False)
        path = output / "specular.c4d"
        assert c4d.documents.SaveDocument(scene, str(path), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT)
        for device in ("gpu", "cpu"):
            selected = [key for key, name, _ in devices if ("CPU" in name.upper()) == (device == "cpu")]
            if not selected:
                raise RuntimeError("Requested compute device unavailable: " + device)
            for key, _, _ in devices:
                prefs[key] = key in selected
            prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = False
            prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = 0
            # Both devices render a saved/reopened scene with the same camera.
            reopened = c4d.documents.LoadDocument(str(path), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
            bitmap = c4d.bitmaps.MultipassBitmap(600, 400, c4d.COLORMODE_RGB)
            bitmap.AddChannel(True, True)
            result = c4d.documents.RenderDocument(reopened, reopened.GetActiveRenderData().GetDataInstance(),
                                                  bitmap, c4d.RENDERFLAGS_EXTERNAL)
            if result != c4d.RENDERRESULT_OK:
                raise AssertionError((device, result))
            image_path = output / (device + ".png")
            assert bitmap.Save(str(image_path), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA) == c4d.IMAGERESULT_OK
            receipt["cases"].append({"device": device, "selected": selected,
                                     "image": str(image_path), "save_reopen": True, "result": int(result)})
        receipt["passed"] = True
        return receipt
    finally:
        for key, _, value in devices:
            prefs[key] = value
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = hybrid
        prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = preview
        (output / "receipt.json").write_text(json.dumps(receipt, indent=2, default=str), encoding="utf-8")
        suite.close()
