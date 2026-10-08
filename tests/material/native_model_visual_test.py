"""Controlled real-model visual comparison in an isolated c4dpy process.

Successful rendering is recorded separately from manual appearance acceptance.
Never run the blocking entry point in the user's GUI host.
"""
from pathlib import Path
import hashlib
import json
import math


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def run(c4d, model_path, output):
    import redshift
    import shader_binding_test as binding
    import native_render_matrix as rendering
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

    model_path, output = Path(model_path).resolve(), Path(output).resolve()
    output.mkdir(parents=True, exist_ok=False)
    prefs = c4d.plugins.FindPlugin(1036220, c4d.PLUGINTYPE_PREFS)
    devices = [(identifier[0].id, data.GetString(c4d.DESC_NAME), prefs[identifier])
               for data, identifier, group in prefs.GetDescription(c4d.DESCFLAGS_DESC_0)
               if c4d.PREFS_REDSHIFT_FIRST_DEVICE <= identifier[0].id <= c4d.PREFS_REDSHIFT_LAST_DEVICE]
    prior = {key: value for key, name, value in devices}
    for key in (c4d.PREFS_REDSHIFT_HYBRID_RENDERING, c4d.PREFS_REDSHIFT_MATPREVIEW_MODE):
        prior[key] = prefs[key]
    cpu = [key for key, name, value in devices if "CPU" in name.upper()]
    if not cpu:
        raise RuntimeError("This headless profile requires a CPU device")
    receipt = {"status": "running", "module": loaded_plugin_binary(), "c4d": c4d.GetC4DVersion(),
               "rs": redshift.GetCoreVersion(), "model": {"path": str(model_path), "sha256": sha256(model_path)},
               "native_mmd_reference": False, "visual_acceptance": "pending_manual_review", "cases": [],
               "lights": [{"direction": [-.5, -1., .5], "brightness": 1.}],
               "lighting_profile": "single_directional_no_fill",
               "resolution": [640, 960], "view_transform_baked": True, "cleanup": []}
    receipt["asset_images"] = [{"name": p.name, "sha256": sha256(p)} for p in model_path.parent.glob("*.png")]
    suite, guard = None, None

    def persist():
        (output / "receipt.json").write_text(json.dumps(receipt, indent=2, ensure_ascii=False), encoding="utf-8")

    def render_image(scene, material_type, view):
        bitmap = c4d.bitmaps.MultipassBitmap(640, 960, c4d.COLORMODE_RGB)
        if bitmap is None or bitmap.AddChannel(True, True) is None:
            raise MemoryError("Cannot allocate real-model RGBA target")
        result = c4d.documents.RenderDocument(scene, scene.GetActiveRenderData().GetDataInstance(),
                                              bitmap, c4d.RENDERFLAGS_EXTERNAL)
        label = material_type + "-" + view
        row = {"material_type": material_type, "view": view, "result": int(result), "status": "failed"}
        receipt["cases"].append(row)
        image = output / (label + ".png")
        if bitmap.Save(str(image), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA) != c4d.IMAGERESULT_OK:
            raise RuntimeError("Could not save real-model render")
        position = scene.GetRenderBaseDraw().GetSceneCamera(scene).GetAbsPos()
        row.update(image=image.name, sha256=sha256(image),
                   camera_position=[position.x, position.y, position.z])
        if result != c4d.RENDERRESULT_OK:
            raise RuntimeError("Real-model renderer failed: " + label)
        alpha = bitmap.GetInternalChannel()
        samples = [(bitmap.GetPixel(x, y), bitmap.GetAlphaPixel(alpha, x, y))
                   for y in range(0, 960, 8) for x in range(0, 640, 8)]
        row["foreground_fraction"] = sum(a > 0 for rgb, a in samples) / len(samples)
        row["visible_fraction"] = sum(a > 0 and max(rgb) > 5 for rgb, a in samples) / len(samples)
        if row["foreground_fraction"] < .03 or row["visible_fraction"] < .02:
            raise AssertionError("Real-model image is empty or effectively black: " + label)
        row["status"] = "rendered_pending_visual_review"
        persist()
        print(label, "rendered", flush=True)
        return row

    try:
        for key, name, value in devices:
            prefs[key] = key in cpu
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = False
        prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = 0
        for material_type in ("standard", "redshift", "redshift_toon"):
            suite = binding.production_suite(c4d, {"resource_ids": load_resource_ids(Path(__file__).resolve().parents[2]),
                                                  "output": str(output)}, material_type=material_type)
            original = suite.original_document
            if original and original.GetFirstObject() is None and original.GetFirstMaterial() is None:
                guard = c4d.BaseObject(c4d.Onull)
                guard.SetName("CMT real-model original-document guard")
                original.InsertObject(guard)
            suite.new_document("CMT real-model " + material_type)
            imported = suite.call("import_model", str(model_path))
            suite.model = suite.nodes(1056724)[0]
            suite.model[suite.ids["MODEL_MODE"]] = suite.ids["MODEL_MODE_EDIT"]
            suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False
            scene = suite.doc
            scene.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
            points = [obj.GetMg() * point for obj in suite.walk(scene.GetFirstObject())
                      if isinstance(obj, c4d.PolygonObject) for point in obj.GetAllPoints()]
            low = [min(getattr(p, a) for p in points) for a in ("x", "y", "z")]
            high = [max(getattr(p, a) for p in points) for a in ("x", "y", "z")]
            height = high[1] - low[1]
            center = c4d.Vector((low[0]+high[0])/2, (low[1]+high[1])/2, (low[2]+high[2])/2)
            receipt.setdefault("imports", {})[material_type] = {"result": imported, "bounds": [low, high],
                                                                "material_count": len(scene.GetMaterials())}
            for description in receipt["lights"]:
                light = c4d.BaseObject(c4d.Olight)
                light[c4d.LIGHT_TYPE] = c4d.LIGHT_TYPE_DISTANT
                light[c4d.LIGHT_BRIGHTNESS] = description["brightness"]
                light.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(*description["direction"])))
                scene.InsertObject(light)
            camera = c4d.BaseObject(c4d.Ocamera)
            camera[c4d.CAMERA_FOCUS], camera[c4d.CAMERAOBJECT_APERTURE] = 50., 36.
            scene.InsertObject(camera)
            scene.GetRenderBaseDraw().SetSceneCamera(camera)
            rd = scene.GetActiveRenderData()
            for key, value in ((c4d.RDATA_XRES, 640), (c4d.RDATA_YRES, 960),
                               (c4d.RDATA_ALPHACHANNEL, True), (c4d.RDATA_STRAIGHTALPHA, True),
                               (c4d.RDATA_SAVEIMAGE, False), (c4d.RDATA_BAKE_OCIO_VIEW_TRANSFORM_RENDER, True)):
                rd[key] = value
            rd[c4d.RDATA_RENDERENGINE] = c4d.RDATA_RENDERENGINE_STANDARD if material_type == "standard" else 1036219
            if material_type != "standard":
                post = rendering.ensure_redshift_post(c4d, rd)
                settings = post.GetDataInstance()
                for key, value in ((c4d.REDSHIFT_RENDERER_PRIMARY_GI_ENGINE, 0),
                                   (c4d.REDSHIFT_RENDERER_SECONDARY_GI_ENGINE, 0),
                                   (c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES, 16),
                                   (c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES, 64)):
                    settings.SetInt32(key, value)
                settings.SetBool(c4d.REDSHIFT_RENDERER_DENOISE_ENABLED, False)
            targets = {"front": (center, height * 1.6, 0.),
                       "quarter": (center, height * 1.6, math.pi/5),
                       "back": (center, height * 1.6, math.pi),
                       "face": (c4d.Vector(center.x, low[1]+height*.84, center.z), height*.42, 0.),
                       "legs": (c4d.Vector(center.x, low[1]+height*.31, center.z), height*.70, 0.)}
            for view, (target, distance, angle) in targets.items():
                position = target + c4d.Vector(math.sin(angle)*distance, 0., -math.cos(angle)*distance)
                camera.SetAbsPos(position)
                camera.SetAbsRot(c4d.utils.VectorToHPB(target-position))
                scene.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
                row = render_image(scene, material_type, view)
                row.update(camera_target=[target.x, target.y, target.z], distance=distance, angle=angle)
                if view == "front":
                    saved = output / (material_type + ".c4d")
                    if not c4d.documents.SaveDocument(scene, str(saved), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
                        raise RuntimeError("Could not save real-model scene")
                    reopened = c4d.documents.LoadDocument(str(saved), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
                    suite.register_document(reopened, "real-model reopened " + material_type)
                    repeated = render_image(reopened, material_type, "front-reopen")
                    repeated["same_png_after_reopen"] = row["sha256"] == repeated["sha256"]
            cleanup = suite.close()
            if guard is not None and cleanup["original_document_restored"]:
                guard.Remove()
                guard = None
            receipt["cleanup"].append(cleanup)
            if cleanup["errors"] or cleanup["remaining_owned_documents"] or not cleanup["original_document_restored"]:
                raise RuntimeError("Real-model document cleanup incomplete")
            suite = None
        receipt["status"] = "renders_complete_pending_visual_review"
    except Exception as error:
        receipt.update(status="failed", error=str(error))
        raise
    finally:
        if suite is not None:
            cleanup = suite.close()
            receipt["cleanup"].append(cleanup)
            if guard is not None and cleanup["original_document_restored"]:
                guard.Remove()
        for key, value in prior.items():
            prefs[key] = value
        receipt["device_settings_restored"] = all(prefs[key] == value for key, value in prior.items())
        persist()
    return receipt
