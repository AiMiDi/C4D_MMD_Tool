"""Render the actual PMX stockings with a production revision 5 import.

Run only in a task-owned c4dpy host: native rendering is synchronous. The
baseline restores the earlier stockings sampling recipe on the same geometry,
camera and single distant light; it is not a native MMD reference image.
"""

from pathlib import Path
import json


def run(c4d, output, pmx_path):
    import maxon
    import redshift
    import shader_binding_test as binding
    import native_toon_test as toon
    import native_render_matrix as render
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    manifest = {"resource_ids":load_resource_ids(Path(__file__).resolve().parents[2]), "output":str(output)}
    suite = binding.production_suite(c4d, manifest, material_type="redshift_toon")
    prefs = c4d.plugins.FindPlugin(1036220, c4d.PLUGINTYPE_PREFS)
    devices = [(identifier[0].id, data.GetString(c4d.DESC_NAME), prefs[identifier])
               for data, identifier, _ in prefs.GetDescription(c4d.DESCFLAGS_DESC_0)
               if c4d.PREFS_REDSHIFT_FIRST_DEVICE <= identifier[0].id <= c4d.PREFS_REDSHIFT_LAST_DEVICE]
    hybrid, preview = prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING], prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE]
    receipt = {"module":loaded_plugin_binary(), "rs":redshift.GetCoreVersion(),
               "pmx":str(pmx_path), "cases":[], "native_mmd_equivalence":False}
    p = toon.PREFIX

    def select_device(device):
        selected = [key for key, name, _ in devices if ("CPU" in name.upper()) == (device == "cpu")]
        if not selected:
            raise AssertionError("Compute device is unavailable: " + device)
        for key, _, _ in devices:
            prefs[key] = key in selected
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = False
        prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = 0
        return selected

    def render_saved(scene, name, device, width, height):
        path = output / (name + ".c4d")
        rd = scene.GetActiveRenderData()
        rd[c4d.RDATA_XRES], rd[c4d.RDATA_YRES] = width, height
        assert c4d.documents.SaveDocument(scene, str(path), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT)
        loaded = c4d.documents.LoadDocument(str(path), c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS, None)
        selected = select_device(device)
        bitmap = c4d.bitmaps.MultipassBitmap(width,height,c4d.COLORMODE_RGB)
        bitmap.AddChannel(True,True)
        result = c4d.documents.RenderDocument(loaded,loaded.GetActiveRenderData().GetDataInstance(),bitmap,c4d.RENDERFLAGS_EXTERNAL)
        if result != c4d.RENDERRESULT_OK:
            raise AssertionError((name,result))
        assert bitmap.Save(str(output/(name+".png")),c4d.FILTER_PNG,savebits=c4d.SAVEBIT_ALPHA)==c4d.IMAGERESULT_OK
        receipt["cases"].append({"name":name,"device":device,"selected":selected,"result":int(result),"save_reopen":True})
        (output/"receipt.json").write_text(json.dumps(receipt,indent=2,default=str),encoding="utf8")

    try:
        suite.new_document("阿芙-RS-Toon-球面贴图对齐")
        suite.call("import_model",pmx_path)
        suite.model = suite.nodes(1056724)[0]
        suite.evaluate(0)
        receipt["binding"] = toon.binding_snapshot(suite)
        scene, model, ids = suite.doc, suite.model, suite.ids
        model[ids["MODEL_MATERIAL_LIST"]] = 13
        mat = model[ids["MODEL_MATERIAL_LINK"]]
        if mat.GetName() != "丝袜" or model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]] != c4d.Vector(0):
            raise AssertionError("The real stockings must have zero PMX Specular")
        receipt["stockings"] = {"specular":str(model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]]),
                                 "sphere_mode":model[ids["MODEL_MATERIAL_SPHERE_MODE"]],
                                 "sphere_path":model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]]}
        light = c4d.BaseObject(c4d.Olight)
        light[c4d.LIGHT_TYPE] = c4d.LIGHT_TYPE_DISTANT
        light[c4d.LIGHT_BRIGHTNESS] = 1.
        light.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(-.5,-1.,.5)))
        scene.InsertObject(light)
        camera = c4d.BaseObject(c4d.Ocamera)
        camera[c4d.CAMERA_FOCUS] = 50.
        camera.SetAbsPos(c4d.Vector(0.,4.4,-13.5))
        camera.SetName("丝袜固定相机")
        scene.InsertObject(camera)
        scene.GetRenderBaseDraw().SetSceneCamera(camera)
        scene.GetActiveBaseDraw().SetSceneCamera(camera)
        rd = scene.GetActiveRenderData()
        rd[c4d.RDATA_RENDERENGINE] = 1036219
        rd[c4d.RDATA_ALPHACHANNEL] = True
        rd[c4d.RDATA_STRAIGHTALPHA] = True
        post = render.ensure_redshift_post(c4d,rd)
        settings = post.GetDataInstance()
        settings.SetInt32(c4d.REDSHIFT_RENDERER_PRIMARY_GI_ENGINE,0)
        settings.SetInt32(c4d.REDSHIFT_RENDERER_SECONDARY_GI_ENGINE,0)
        settings.SetInt32(c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES,16)
        settings.SetInt32(c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES,64)
        settings.SetBool(c4d.REDSHIFT_RENDERER_DENOISE_ENABLED,False)
        graph = mat.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
        root = graph.GetViewRoot()

        def stockings_recipe(legacy):
            model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 0 if legacy else 2
            with graph.BeginTransaction() as transaction:
                for role in ("cmt_diffuse_texture","cmt_toon_texture","cmt_toon_border_texture"):
                    root.FindChild(role).GetInputs().FindChild(p+"texturesampler.tex0").FindChild("colorspace").SetPortValue("Auto")
                uv_port = root.FindChild("cmt_toon_texture").GetInputs().FindChild(p+"texturesampler.offset")
                uv = uv_port.GetPortValue()
                uv.x, uv.y = 0., 0. if legacy else .5
                uv_port.SetPortValue(uv)
                root.FindChild("cmt_toon_surface").GetInputs().FindChild(p+"toonmaterial.base_tone_map_mode").SetPortValue(0 if legacy else 1)
                transaction.Commit()
            mat.SetDirty(c4d.DIRTYFLAGS_DATA)
            scene.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_NONE)

        stockings_recipe(True)
        render_saved(scene,"before-gpu","gpu",400,700)
        stockings_recipe(False)
        render_saved(scene,"after-gpu","gpu",400,700)
        render_saved(scene,"after-cpu","cpu",400,700)
        render_saved(scene,"after-repeat-gpu","gpu",400,700)
        camera.SetAbsPos(c4d.Vector(0.,9.521,-25.356))
        render_saved(scene,"阿芙-RS-Toon-球面贴图对齐","gpu",600,800)
        # Keep one directional light; this second angle is a lighting study,
        # separate from the same-light before/after shader comparison above.
        light.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(.25,-.65,1.)))
        camera.SetAbsPos(c4d.Vector(0.,4.4,-13.5))
        render_saved(scene,"frontal-light-gpu","gpu",400,700)
        render_saved(scene,"frontal-light-cpu","cpu",400,700)
        camera.SetAbsPos(c4d.Vector(0.,9.521,-25.356))
        render_saved(scene,"阿芙-RS-Toon-丝袜对齐","gpu",600,800)
        receipt["lights"] = {"shader_comparison_direction":[-.5,-1.,.5],
                             "frontal_study_direction":[.25,-.65,1.],"count":1}
        receipt["passed"] = True
        return receipt
    finally:
        for key,_,value in devices:
            prefs[key] = value
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING], prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = hybrid, preview
        (output/"receipt.json").write_text(json.dumps(receipt,indent=2,default=str),encoding="utf8")
        suite.close()
