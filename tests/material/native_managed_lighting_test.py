"""Real lit-sphere images through installed material Morph bindings.

Run in a task-owned c4dpy host. The original imported mesh keeps its binding,
User Data and material assignment; only its private fixture geometry is replaced
by a sphere. No reader, managed shader or connection is bypassed for rendering.
"""
from pathlib import Path
import hashlib
import json


def run(c4d, output, renderer):
    import shader_binding_test as binding
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary
    from native_render_matrix import ensure_redshift_post

    output = Path(output)
    output.mkdir(parents=True, exist_ok=False)
    suite = binding.production_suite(c4d, {
        "resource_ids": load_resource_ids(Path(__file__).resolve().parents[2]),
        "output": str(output)}, material_type=renderer)
    prefs = c4d.plugins.FindPlugin(1036220, c4d.PLUGINTYPE_PREFS)
    devices = [(key, prefs[key]) for key in (2500, 2501, 19018)]
    guard = None
    rows = []
    try:
        original = suite.original_document
        if original and original.GetFirstObject() is None:
            guard = c4d.BaseObject(c4d.Onull)
            original.InsertObject(guard)
        fixtures = binding.prepare(output / "fixtures")
        suite.manifest["fixtures"] = fixtures
        suite.new_model("binding.pmx")
        model, ids = suite.model, suite.ids
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
        model[ids["MODEL_MATERIAL_LIST"]] = 0
        model[ids["MODEL_MATERIAL_DIFFUSE_COLOR"]] = c4d.Vector(0.)
        model[ids["MODEL_MATERIAL_DIFFUSE_ALPHA"]] = 1.
        model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]] = c4d.Vector(1.)
        model[ids["MODEL_MATERIAL_SPECULAR_POWER"]] = 2.
        mesh = model[ids["MODEL_MATERIAL_MESH_LINK"]]
        sphere = c4d.BaseObject(c4d.Osphere)
        sphere[c4d.PRIM_SPHERE_RAD] = 60.
        sphere[c4d.PRIM_SPHERE_SUB] = 96
        geometry = c4d.utils.SendModelingCommand(c4d.MCOMMAND_CURRENTSTATETOOBJECT,
                                                list=[sphere], doc=suite.doc)[0]
        if not isinstance(geometry, c4d.PolygonObject):
            raise AssertionError("Sphere fixture did not produce polygon geometry")
        if not mesh.ResizeObject(geometry.GetPointCount(), geometry.GetPolygonCount()):
            raise MemoryError("Cannot resize bound fixture geometry")
        mesh.SetAllPoints(geometry.GetAllPoints())
        for index, polygon in enumerate(geometry.GetAllPolygons()):
            mesh.SetPolygon(index, polygon)
        mesh.SetAbsPos(c4d.Vector())
        for tag in mesh.GetTags():
            if tag.CheckType(c4d.Ttexture):
                tag[c4d.TEXTURETAG_RESTRICTION] = ""
        mesh.Message(c4d.MSG_UPDATE)
        for other in suite.nodes(c4d.Opolygon):
            if other != mesh:
                other.SetRenderMode(c4d.MODE_OFF)
        camera = c4d.BaseObject(c4d.Ocamera)
        camera.SetAbsPos(c4d.Vector(0., 0., -300.))
        suite.doc.InsertObject(camera)
        suite.doc.GetRenderBaseDraw().SetSceneCamera(camera)
        light = c4d.BaseObject(1036751 if renderer == "redshift" else c4d.Olight)
        if renderer == "redshift":
            light[c4d.REDSHIFT_LIGHT_TYPE] = c4d.REDSHIFT_LIGHT_TYPE_PHYSICAL_INFINITE
            light[c4d.REDSHIFT_LIGHT_PHYSICAL_INTENSITY] = 1.
        else:
            light[c4d.LIGHT_TYPE] = c4d.LIGHT_TYPE_DISTANT
            light[c4d.LIGHT_BRIGHTNESS] = 1.
        light.SetAbsPos(c4d.Vector(0., 0., -200.))
        suite.doc.InsertObject(light)
        rd = suite.doc.GetActiveRenderData()
        for key, value in ((c4d.RDATA_RENDERENGINE, 1036219 if renderer == "redshift" else c4d.RDATA_RENDERENGINE_STANDARD),
                           (c4d.RDATA_XRES, 256), (c4d.RDATA_YRES, 256),
                           (c4d.RDATA_ALPHACHANNEL, True), (c4d.RDATA_STRAIGHTALPHA, True),
                           (c4d.RDATA_SAVEIMAGE, False), (c4d.RDATA_BAKE_OCIO_VIEW_TRANSFORM_RENDER, False)):
            rd[key] = value
        if renderer == "redshift":
            post = ensure_redshift_post(c4d, rd)
            post[c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES] = 16
            post[c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES] = 64
            post[c4d.REDSHIFT_RENDERER_DENOISE_ENABLED] = False
            prefs[2500], prefs[2501], prefs[19018] = False, True, False
        model[ids["MODEL_MATMORPH_LIST"]] = 0
        model[ids["MODEL_MATMORPH_OFFSET_LIST"]] = 0
        for field in ("DIFFUSE_COLOR", "SPECULAR_COLOR", "AMBIENT_COLOR", "EDGE_COLOR",
                      "TEXTURE_FACTOR_COLOR", "SPHERE_FACTOR_COLOR", "TOON_FACTOR_COLOR"):
            key = "MODEL_MATMORPH_" + field
            model[ids[key]] = c4d.Vector(0.)
        for field in ("DIFFUSE_ALPHA", "SPECULAR_POWER", "EDGE_ALPHA", "EDGE_SIZE",
                      "TEXTURE_FACTOR_ALPHA", "SPHERE_FACTOR_ALPHA", "TOON_FACTOR_ALPHA"):
            key = "MODEL_MATMORPH_" + field
            model[ids[key]] = 0.
        material = model[ids["MODEL_MATERIAL_LINK"]]
        before = _structure(material, suite.doc, renderer)
        cases = [("white_broad", (0., 0., 0.), 0., False),
                 ("white_narrow", (0., 0., 0.), 508., False),
                 ("red", (0., -1., -1.), 28., False),
                 ("zero", (-1., -1., -1.), 28., False),
                 ("white_narrow", (0., 0., 0.), 508., False),
                 ("white_narrow", (0., 0., 0.), 508., True)]
        for index, (case, color, power, reopen) in enumerate(cases):
            model = suite.model
            model[ids["MODEL_MATERIAL_LIST"]] = 0
            model[ids["MODEL_MATMORPH_SPECULAR_COLOR"]] = c4d.Vector(*color)
            model[ids["MODEL_MATMORPH_SPECULAR_POWER"]] = power
            model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
            model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
            model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = 1.
            if reopen:
                suite.reopen("managed-lighting")
                model = suite.model
                if model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]]:
                    raise AssertionError("Preview persisted across ordinary reopening")
                model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = True
                model[ids["MODEL_MATMORPH_PREVIEW_LIST"]] = 0
                model[ids["MODEL_MATMORPH_PREVIEW_WEIGHT"]] = 1.
                model[ids["MODEL_MATERIAL_LIST"]] = 0
            suite.evaluate(0)
            material = model[ids["MODEL_MATERIAL_LINK"]]
            if _structure(material, suite.doc, renderer) != before:
                raise AssertionError("Morph evaluation changed managed material structure")
            translator = c4d.AliasTrans()
            if not translator.Init(suite.doc):
                raise RuntimeError("Cannot translate render document")
            clone = suite.doc.GetClone(c4d.COPYFLAGS_NONE, translator)
            translator.Translate(True)
            clone.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
            bitmap = c4d.bitmaps.MultipassBitmap(256, 256, c4d.COLORMODE_RGB)
            bitmap.AddChannel(True, True)
            result = c4d.documents.RenderDocument(clone, clone.GetActiveRenderData().GetDataInstance(),
                                                 bitmap, c4d.RENDERFLAGS_EXTERNAL)
            if result != c4d.RENDERRESULT_OK:
                raise AssertionError((renderer, case, result))
            path = output / (str(index) + "-" + case + ".png")
            if bitmap.Save(str(path), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA) != c4d.IMAGERESULT_OK:
                raise RuntimeError("Cannot persist actual RGBA output")
            rows.append({"case": case, "reopen": reopen, "image": str(path),
                         "sha256": hashlib.sha256(path.read_bytes()).hexdigest(), "result": int(result)})
            (output / "renders.json").write_text(json.dumps(rows, indent=2))
            clone = bitmap = None
        (output / "identity.json").write_text(json.dumps({"module": loaded_plugin_binary(),
            "renderer": renderer, "managed_structure": before, "native_mmd_fidelity": False,
            "sphere_points": geometry.GetPointCount()}, indent=2))
        return rows
    finally:
        for key, value in devices:
            prefs[key] = value
        cleanup = suite.close()
        if guard and cleanup["original_document_restored"]:
            guard.Remove()
        cleanup["devices_restored"] = all(prefs[key] == value for key, value in devices)
        (output / "cleanup.json").write_text(json.dumps(cleanup, indent=2))


def _structure(material, doc, renderer):
    if material.GetDataInstance().GetContainer(1068715).GetInt32(100) != 2:
        raise AssertionError("Fixture has no current managed binding")
    if renderer == "redshift":
        import maxon
        graph = material.GetNodeMaterialReference().GetGraph(
            maxon.Id("com.redshift3d.redshift4c4d.class.nodespace"))
        return sorted(str(node.GetId()) for node in graph.GetViewRoot().GetChildren())
    def walk(shader):
        while shader:
            yield shader.GetType()
            yield from walk(shader.GetDown())
            shader = shader.GetNext()
    return list(walk(material.GetFirstShader()))
