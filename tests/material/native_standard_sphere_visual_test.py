"""Saved-scene Matcap projection and actual PMX render acceptance.

The unlit sphere isolates projection from each renderer's lighting. The real
stockings retain native Standard/PBR shading and one directional light.
"""

from pathlib import Path
import json
import struct
import zlib


def gradient(path):
    def chunk(kind, data):
        return struct.pack(">I", len(data)) + kind + data + struct.pack(">I", zlib.crc32(kind + data))
    rows = b"".join(b"\0" + b"".join(bytes((32+int(191*x/63),32+int(191*y/63),64,96))
                                     for x in range(64)) for y in range(64))
    data = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR",struct.pack(">IIBBBBB",64,64,8,6,0,0,0))
    Path(path).write_bytes(data + chunk(b"IDAT",zlib.compress(rows)) + chunk(b"IEND",b""))


def run(c4d, output, pmx_path):
    import maxon
    import redshift
    import shader_binding_test as binding
    import native_render_matrix as render
    import native_sphere_test as fixture
    import native_toon_test as toon
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    gradient(output / "matcap-gradient.png")
    ids = load_resource_ids(Path(__file__).resolve().parents[2])
    prefs = c4d.plugins.FindPlugin(1036220,c4d.PLUGINTYPE_PREFS)
    devices = [(identifier[0].id,data.GetString(c4d.DESC_NAME),prefs[identifier])
               for data,identifier,_ in prefs.GetDescription(c4d.DESCFLAGS_DESC_0)
               if c4d.PREFS_REDSHIFT_FIRST_DEVICE <= identifier[0].id <= c4d.PREFS_REDSHIFT_LAST_DEVICE]
    hybrid,preview = prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING],prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE]
    receipt = {"module":loaded_plugin_binary(),"rs":redshift.GetCoreVersion(),"pmx":str(pmx_path),
               "cases":[],"passed":False,"native_mmd_equivalence":False}

    def save_receipt():
        (output/"receipt.json").write_text(json.dumps(receipt,indent=2,default=str),encoding="utf8")

    def configure(scene, renderer, width, height):
        rd = scene.GetActiveRenderData()
        rd[c4d.RDATA_XRES],rd[c4d.RDATA_YRES] = width,height
        rd[c4d.RDATA_ALPHACHANNEL] = True
        rd[c4d.RDATA_STRAIGHTALPHA] = True
        rd[c4d.RDATA_RENDERENGINE] = 1036219 if renderer == "redshift" else 0
        if renderer == "redshift":
            post = render.ensure_redshift_post(c4d,rd)
            settings = post.GetDataInstance()
            settings.SetInt32(c4d.REDSHIFT_RENDERER_PRIMARY_GI_ENGINE,0)
            settings.SetInt32(c4d.REDSHIFT_RENDERER_SECONDARY_GI_ENGINE,0)
            settings.SetInt32(c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES,16)
            settings.SetInt32(c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES,64)
            settings.SetBool(c4d.REDSHIFT_RENDERER_DENOISE_ENABLED,False)

    def render_saved(scene, name, device, renderer):
        if renderer == "standard":
            device = "cpu"
        selected = []
        if renderer == "redshift":
            selected = [key for key,label,_ in devices if ("CPU" in label.upper()) == (device == "cpu")]
            if not selected:
                raise AssertionError("Missing compute device " + device)
            for key,_,_ in devices:
                prefs[key] = key in selected
            prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = False
            prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = 0
        path = output/(name+".c4d")
        assert c4d.documents.SaveDocument(scene,str(path),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT)
        loaded = c4d.documents.LoadDocument(str(path),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
        rd = loaded.GetActiveRenderData()
        bitmap = c4d.bitmaps.MultipassBitmap(int(rd[c4d.RDATA_XRES]),int(rd[c4d.RDATA_YRES]),c4d.COLORMODE_RGB)
        bitmap.AddChannel(True,True)
        result = c4d.documents.RenderDocument(loaded,rd.GetDataInstance(),bitmap,c4d.RENDERFLAGS_EXTERNAL)
        if result != c4d.RENDERRESULT_OK:
            raise AssertionError((name,result))
        assert bitmap.Save(str(output/(name+".png")),c4d.FILTER_PNG,savebits=c4d.SAVEBIT_ALPHA)==c4d.IMAGERESULT_OK
        receipt["cases"].append({"name":name,"renderer":renderer,"device":device,"selected":selected,
                                 "save_reopen":True,"result":int(result)})
        save_receipt()

    def verify_projection(renderer):
        front, rotated = c4d.bitmaps.BaseBitmap(),c4d.bitmaps.BaseBitmap()
        if front.InitWith(str(output/(renderer+"-projection-front.png")))[0] != c4d.IMAGERESULT_OK:
            raise AssertionError("Cannot read projection image")
        if rotated.InitWith(str(output/(renderer+"-projection-rotated.png")))[0] != c4d.IMAGERESULT_OK:
            raise AssertionError("Cannot read rotated projection image")
        points = [(120,120),(120,90),(120,150),(90,120),(150,120)]
        values = [front.GetPixel(*point) for point in points]
        other = [rotated.GetPixel(*point) for point in points]
        if values[2][1] <= values[1][1]+20 or values[4][0] <= values[3][0]+20:
            raise AssertionError("Matcap image axes are reversed: "+str(values))
        if max(abs(a-b) for x,y in zip(values,other) for a,b in zip(x,y)) > 2:
            raise AssertionError("Matcap projection failed to follow the camera")
        alpha = front.GetInternalChannel()
        if alpha is None or front.GetAlphaPixel(alpha,120,120) != 255:
            raise AssertionError("Sphere bitmap Alpha entered surface opacity")
        receipt.setdefault("projection",{})[renderer] = {"sample_points":points,"front":values,
            "rotated":other,"axes_verified":True,"camera_verified":True,"center_alpha":255}
        save_receipt()

    try:
        for renderer in ("standard","redshift"):
            case = output/renderer
            case.mkdir(exist_ok=True)
            suite = binding.production_suite(c4d,{"output":str(case),"resource_ids":ids},material_type=renderer)
            try:
                fixture.prepare(case)
                scene = suite.new_document("Matcap UV "+renderer)
                suite.call("import_model",str(case/"sphere-binding.pmx"))
                model = suite.nodes(1056724)[0]
                suite.model = model
                model[ids["MODEL_MATERIAL_LIST"]] = 0
                model[ids["MODEL_MATERIAL_DIFFUSE_COLOR"]] = c4d.Vector(1.)
                model[ids["MODEL_MATERIAL_DIFFUSE_ALPHA"]] = 1.
                model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]] = c4d.Vector(0.)
                model[ids["MODEL_MATERIAL_SPHERE_TEXTURE_PATH"]] = str(output/"matcap-gradient.png")
                model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 1
                material = model[ids["MODEL_MATERIAL_LINK"]]
                model[c4d.ID_BASEOBJECT_VISIBILITY_RENDER] = c4d.OBJECT_OFF
                sphere = c4d.BaseObject(c4d.Osphere)
                sphere[c4d.PRIM_SPHERE_RAD] = 1.
                sphere[c4d.PRIM_SPHERE_SUB] = 96
                scene.InsertObject(sphere)
                tag = c4d.BaseTag(c4d.Ttexture)
                tag[c4d.TEXTURETAG_MATERIAL] = material
                tag[c4d.TEXTURETAG_PROJECTION] = c4d.TEXTURETAG_PROJECTION_UVW
                sphere.InsertTag(tag)
                if renderer == "standard":
                    material[c4d.MATERIAL_USE_COLOR] = False
                    material[c4d.MATERIAL_USE_REFLECTION] = False
                    material[c4d.MATERIAL_USE_LUMINANCE] = True
                    material[c4d.MATERIAL_LUMINANCE_SHADER] = material[c4d.MATERIAL_COLOR_SHADER]
                else:
                    graph = material.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
                    root = graph.GetNode(maxon.NodePath())
                    surface = maxon.GraphModelHelper.FindNodesByAssetId(graph,maxon.Id(toon.PREFIX+"standardmaterial"),True)[0]
                    with graph.BeginTransaction() as transaction:
                        surface.GetInputs().FindChild(toon.PREFIX+"standardmaterial.base_color_weight").SetPortValue(0.)
                        surface.GetInputs().FindChild(toon.PREFIX+"standardmaterial.emission_weight").SetPortValue(1.)
                        source = root.FindChild("cmt_sphere_combine_mul").GetOutputs().FindChild(toon.PREFIX+"rsmathmulvector.out")
                        source.Connect(surface.GetInputs().FindChild(toon.PREFIX+"standardmaterial.emission_color"))
                        transaction.Commit()
                camera = c4d.BaseObject(c4d.Ocamera)
                camera.SetAbsPos(c4d.Vector(0.,0.,-5.))
                scene.InsertObject(camera)
                scene.GetRenderBaseDraw().SetSceneCamera(camera)
                configure(scene,renderer,240,240)
                render_saved(scene,renderer+"-projection-front","gpu",renderer)
                camera.SetAbsPos(c4d.Vector(-5.,0.,0.))
                camera.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(5.,0.,0.)))
                render_saved(scene,renderer+"-projection-rotated","gpu",renderer)
                verify_projection(renderer)
            finally:
                suite.close()

            suite = binding.production_suite(c4d,{"output":str(case),"resource_ids":ids},material_type=renderer)
            try:
                scene = suite.new_document("阿芙-Matcap-"+renderer)
                suite.call("import_model",str(pmx_path))
                model = suite.nodes(1056724)[0]
                suite.model = model
                suite.evaluate(0)
                model[ids["MODEL_MATERIAL_LIST"]] = 13
                material = model[ids["MODEL_MATERIAL_LINK"]]
                if material.GetName() != "丝袜":
                    raise AssertionError("Unexpected stockings material")
                light = c4d.BaseObject(c4d.Olight)
                light[c4d.LIGHT_TYPE] = c4d.LIGHT_TYPE_DISTANT
                light[c4d.LIGHT_BRIGHTNESS] = 1.
                light.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(.25,-.65,1.)))
                scene.InsertObject(light)
                camera = c4d.BaseObject(c4d.Ocamera)
                camera.SetAbsPos(c4d.Vector(0.,4.4,-13.5))
                scene.InsertObject(camera)
                scene.GetRenderBaseDraw().SetSceneCamera(camera)
                configure(scene,renderer,320,560)
                model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 0
                render_saved(scene,renderer+"-stockings-none","gpu",renderer)
                model[ids["MODEL_MATERIAL_SPHERE_MODE"]] = 2
                render_saved(scene,renderer+"-stockings-add","gpu",renderer)
                if renderer == "redshift":
                    render_saved(scene,renderer+"-stockings-add-cpu","cpu",renderer)
                camera.SetAbsPos(c4d.Vector(0.,9.521,-25.356))
                configure(scene,renderer,480,640)
                render_saved(scene,"阿芙-Matcap-"+renderer,"gpu",renderer)
            finally:
                suite.close()
        receipt["passed"] = True
        return receipt
    finally:
        for key,_,value in devices:
            prefs[key] = value
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING],prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = hybrid,preview
        save_receipt()
