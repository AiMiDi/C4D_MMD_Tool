"""Asynchronous native Standard/Redshift image regression.

Keep the session in a persistent host module between ``start``, ``status`` and
``collect`` calls. No method blocks waiting for a live worker. RenderDocument
runs only on a private AliasTrans clone; the user's document is never rendered
or modified. ``close`` requests cancellation and reports cleanup_pending until
the worker actually stops, so callers must retain and poll that session.

The isolated_channels pass copies the imported color path to emission/luminance
on that clone, while preserving the imported opacity path. It tests sampling
and coefficients without depending on BRDF/light settings. The default pass
renders the unchanged imported material; alpha is asserted, RGB is recorded for
visual inspection. These two kinds of evidence must not be conflated.
"""

from pathlib import Path
import hashlib
import json
import math

import material_fixture_matrix as matrix
import native_diffuse_test as diffuse


def _main_thread(c4d):
    if not c4d.threading.GeIsMainThread():
        raise RuntimeError("Render session coordination must run on the Cinema 4D main thread")


def _restore(suite):
    from c4d_runtime_regression import restore_active_document
    return restore_active_document(suite.c4d, suite.original_document)


def _worker(c4d, document, bitmap):
    class RenderWorker(c4d.threading.C4DThread):
        def __init__(self):
            super().__init__()
            self.document, self.bitmap = document, bitmap
            self.result = self.error = None
            self.progress = self.progress_type = None

        def progress_callback(self, progress, progress_type):
            self.progress, self.progress_type = float(progress), int(progress_type)

        def Main(self):
            # All file I/O, hashing, registry changes and scene setup happen on
            # the main thread. This thread owns only SDK rendering and memory.
            try:
                self.result = c4d.documents.RenderDocument(
                    self.document, self.document.GetActiveRenderData().GetData(), self.bitmap,
                    c4d.RENDERFLAGS_EXTERNAL | c4d.RENDERFLAGS_NODOCUMENTCLONE,
                    th=self.Get(), prog=self.progress_callback)
            except Exception as error:
                self.error = (type(error).__name__, str(error))
    return RenderWorker()


def _redshift_graph(material):
    import maxon
    import native_redshift_test as redshift
    node_material = material.GetNodeMaterialReference()
    if node_material is None or not node_material.HasSpace(maxon.Id(redshift.SPACE)):
        raise AssertionError("Private render clone has no Redshift material graph")
    graph = node_material.GetGraph(maxon.Id(redshift.SPACE))
    nodes = maxon.GraphModelHelper.FindNodesByAssetId(
        graph, maxon.Id(redshift.PREFIX + "standardmaterial"), True)
    if len(nodes) != 1:
        raise AssertionError("Expected exactly one Standard Material node")
    return graph, nodes[0]


def inspect_isolation_ports(material):
    """Read-only port inventory for the caller's native preflight."""
    _, standard = _redshift_graph(material)
    return [{"id": str(port.GetId()), "value": str(port.GetPortValue())}
            for port in standard.GetInputs().GetChildren()]


def _isolate_color(c4d, material, renderer):
    if renderer == "standard":
        shader = material[c4d.MATERIAL_COLOR_SHADER]
        if shader is None:
            raise AssertionError("Imported color shader is missing")
        material[c4d.MATERIAL_LUMINANCE_SHADER] = shader
        material[c4d.MATERIAL_LUMINANCE_COLOR] = c4d.Vector(1.)
        material[c4d.MATERIAL_LUMINANCE_BRIGHTNESS] = 1.
        material[c4d.MATERIAL_USE_LUMINANCE] = True
        material[c4d.MATERIAL_USE_COLOR] = False
        material[c4d.MATERIAL_USE_REFLECTION] = False
        material[c4d.MATERIAL_USE_SPECULAR] = False
        return
    import native_redshift_test as redshift
    import maxon
    graph, standard = _redshift_graph(material)
    with graph.BeginTransaction() as transaction:
        ports = {}
        for suffix in ("emission_color", "emission_weight", "base_color_weight", "refl_weight", "base_color"):
            ports[suffix] = redshift._port(standard, "input", redshift.PREFIX + "standardmaterial." + suffix)
        # An absent FindChild result has no graph model; Python IsValid() can
        # itself raise ValueError on that empty handle. Enumerate valid asset
        # nodes first and match the importer-owned ID instead.
        texture_nodes = maxon.GraphModelHelper.FindNodesByAssetId(
            graph, maxon.Id(redshift.PREFIX + "texturesampler"), True)
        owned_textures = [node for node in texture_nodes if str(node.GetId()) == "cmt_diffuse_texture"]
        if len(owned_textures) > 1:
            raise AssertionError("Imported render color path has duplicate texture nodes")
        texture = owned_textures[0] if owned_textures else None
        if texture is not None:
            redshift._port(texture, "output", redshift.PREFIX + "texturesampler.outcolor").Connect(
                ports["emission_color"])
        else:
            ports["emission_color"].SetPortValue(ports["base_color"].GetPortValue())
        for name, value in (("emission_weight", 1.), ("base_color_weight", 0.), ("refl_weight", 0.)):
            ports[name].SetPortValue(value)
        transaction.Commit()


def _configure_scene(suite, document, renderer, shading, width, height):
    c4d = suite.c4d
    document.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
    material = document.GetFirstMaterial()
    if material is None:
        raise AssertionError("Private render clone has no imported material")
    if shading == "isolated_channels":
        _isolate_color(c4d, material, renderer)
    camera = c4d.BaseObject(c4d.Ocamera)
    if camera is None:
        raise MemoryError("Could not allocate the private render camera")
    camera.SetName("Material fixture camera")
    camera[c4d.CAMERA_PROJECTION] = c4d.Pperspective
    camera[c4d.CAMERA_FOCUS] = 36.
    camera[c4d.CAMERAOBJECT_APERTURE] = 36.
    points = [node.GetMg() * point for node in suite.walk(document.GetFirstObject())
              if isinstance(node, c4d.PolygonObject) for point in node.GetAllPoints()]
    if not points:
        raise AssertionError("Render fixture has no polygon geometry")
    minimum = [min(getattr(point, axis) for point in points) for axis in ("x", "y", "z")]
    maximum = [max(getattr(point, axis) for point in points) for axis in ("x", "y", "z")]
    position = frame_camera_position(minimum, maximum, width, height)
    camera.SetRelPos(c4d.Vector(*position))
    document.InsertObject(camera)
    document.GetRenderBaseDraw().SetSceneCamera(camera)
    render_data = document.GetActiveRenderData()
    for identifier, value in (
        (c4d.RDATA_XRES, width), (c4d.RDATA_YRES, height),
        (c4d.RDATA_ALPHACHANNEL, True), (c4d.RDATA_STRAIGHTALPHA, True),
        (c4d.RDATA_SAVEIMAGE, False), (c4d.RDATA_MULTIPASS_ENABLE, False),
    ):
        render_data[identifier] = value
    if hasattr(c4d, "RDATA_BAKE_OCIO_VIEW_TRANSFORM_RENDER"):
        render_data[c4d.RDATA_BAKE_OCIO_VIEW_TRANSFORM_RENDER] = False
    if renderer == "redshift":
        engine = getattr(c4d, "VPrsrenderer", 1036219)
        if c4d.plugins.FindPlugin(engine, c4d.PLUGINTYPE_VIDEOPOST) is None:
            raise RuntimeError("Redshift renderer is unavailable; no fallback is allowed")
        post = render_data.GetFirstVideoPost()
        while post is not None and post.GetType() != engine:
            post = post.GetNext()
        if post is None:
            post = c4d.documents.BaseVideoPost(engine)
            if post is None:
                raise RuntimeError("Could not allocate the Redshift video post")
            render_data.InsertVideoPost(post)
    else:
        engine = c4d.RDATA_RENDERENGINE_STANDARD
    render_data[c4d.RDATA_RENDERENGINE] = engine
    return {"render_engine": int(engine), "shading": shading, "resolution": [width, height],
            "geometry_world_bounds": [minimum, maximum], "camera_position": position,
            "view_transform_baked_in_render": False,
            "document_fps": int(document.GetFps()), "ocio_rgb_expectation": "recorded; no sRGB-as-linear equality"}


def frame_camera_position(minimum, maximum, width, height):
    """Fit world geometry to a 36mm lens and aperture with a 1.6 margin."""
    half_width, half_height = (maximum[0] - minimum[0]) * .5, (maximum[1] - minimum[1]) * .5
    if not all(math.isfinite(value) for value in minimum + maximum) or min(half_width, half_height) <= 0.:
        raise AssertionError("Render fixture must contain a finite quad with width and height")
    # Match the actual world scale used by the caller's import. Production
    # tests can choose 1 rather than the UI default 8.5; a fixed camera distance
    # would produce a tiny quad and make the four sampling regions overlap.
    distance = max(half_width, half_height * width / height) * 2. * 36. / 36. * 1.6
    return [(minimum[0] + maximum[0]) * .5, (minimum[1] + maximum[1]) * .5, minimum[2] - distance]


def _sample_regions(bitmap, alpha, coordinates):
    result = []
    for x, y in coordinates:
        pixels = [(px, py) for px in range(x - 2, x + 3) for py in range(y - 2, y + 3)]
        rgb = [0.] * 3
        opacity = 0.
        for px, py in pixels:
            pixel = bitmap.GetPixel(px, py)
            for channel in range(3):
                rgb[channel] += float(pixel[channel]) / (255. * len(pixels))
            opacity += float(bitmap.GetAlphaPixel(alpha, px, py)) / (255. * len(pixels))
        result.append({"xy": [x, y], "rgb": rgb, "alpha": opacity})
    return result


def reference_regions(bitmap, alpha, width, height):
    """Find the opaque calibration quad, then orient U using its gray stripes."""
    occupied = [(x, y) for y in range(height) for x in range(width)
                if bitmap.GetAlphaPixel(alpha, x, y) >= 250]
    if not occupied:
        raise AssertionError("Opaque calibration rendered no visible geometry")
    left, right = min(p[0] for p in occupied), max(p[0] for p in occupied)
    top, bottom = min(p[1] for p in occupied), max(p[1] for p in occupied)
    if right - left < 32 or bottom - top < 16 or left < 3 or top < 3 or right >= width - 3 or bottom >= height - 3:
        raise AssertionError("Calibration quad must be visible with an unoccupied image border")
    coordinates = [(round(left + (right - left) * u), round((top + bottom) / 2.)) for u in matrix.SAMPLE_U]
    values = [sum(p["rgb"]) for p in _sample_regions(bitmap, alpha, coordinates)]
    if values[-1] < values[0]:
        coordinates.reverse()
    values = [sum(p["rgb"]) for p in _sample_regions(bitmap, alpha, coordinates)]
    if any(b <= a for a, b in zip(values, values[1:])):
        raise AssertionError("Calibration RGB stripe ordering is missing or cannot establish UV orientation")
    return {"bbox": [left, top, right, bottom], "coordinates": coordinates}


def image_alpha_statistics(bitmap, alpha, width, height):
    """Save geometry-independent diagnostics before any calibration assertion."""
    minimum, maximum = 255, 0
    nonzero = opaque = 0
    bounds = [width, height, -1, -1]
    opaque_bounds = [width, height, -1, -1]
    for y in range(height):
        for x in range(width):
            value = int(bitmap.GetAlphaPixel(alpha, x, y))
            minimum, maximum = min(minimum, value), max(maximum, value)
            if value > 0:
                nonzero += 1
                bounds = [min(bounds[0], x), min(bounds[1], y), max(bounds[2], x), max(bounds[3], y)]
            if value >= 250:
                opaque += 1
                opaque_bounds = [min(opaque_bounds[0], x), min(opaque_bounds[1], y),
                                 max(opaque_bounds[2], x), max(opaque_bounds[3], y)]
    return {"minimum": minimum, "maximum": maximum, "nonzero_pixels": nonzero, "opaque_pixels": opaque,
            "nonzero_bbox": bounds if nonzero else None, "opaque_bbox": opaque_bounds if opaque else None,
            "corner_alpha": [bitmap.GetAlphaPixel(alpha, x, y)
                             for x, y in ((0, 0), (width - 1, 0), (0, height - 1), (width - 1, height - 1))]}


class RenderMatrixSession:
    def __init__(self, suite, import_model, set_strength=None, *, renderer="standard", width=256, height=256):
        _main_thread(suite.c4d)
        if renderer not in ("standard", "redshift") or not 128 <= width <= 512 or not 128 <= height <= 512:
            raise ValueError("Choose Standard/Redshift and a 128..512 pixel focused render")
        self.suite, self.import_model, self.set_strength = suite, import_model, set_strength
        self.renderer, self.width, self.height = renderer, int(width), int(height)
        self.worker = self.current = None
        self.references = {}
        self.receipts = []
        self.closed = False
        self.cancel_requested = False
        try:
            self.prepared = matrix.prepare(suite.output / (renderer + "-render-inputs"))
            matrix.add_native_jpeg(suite, self.prepared)
            suite.manifest["fixtures"].update(self.prepared["fixtures"])
        except Exception:
            suite.close()
            raise

    def start(self, name, strength=0., *, shading="isolated_channels", reopen=False):
        _main_thread(self.suite.c4d)
        if self.closed or self.worker is not None:
            raise RuntimeError("Collect/close the previous owned worker before starting another render")
        if shading not in ("isolated_channels", "default") or not math.isfinite(strength) or not 0. <= strength <= 1.:
            raise ValueError("Invalid material render step")
        case = next((item for item in self.prepared["cases"] if item["name"] == name), None)
        if case is None:
            raise ValueError("Unknown fixture name")
        if name != "alpha_full" and shading not in self.references:
            raise RuntimeError("Render and collect alpha_full calibration first for this shading pass")
        c4d, suite = self.suite.c4d, self.suite
        self.cancel_requested = False
        try:
            diffuse.load_matrix_model(suite, case, self.import_model)
            if case["morph"]:
                # Repeat and reset on the same model before rendering, so an
                # accumulated factor cannot be hidden by reimporting the case.
                for step in (0., 1., .5, 0., strength):
                    diffuse.apply_matrix_strength(suite, step, self.set_strength)
            elif strength != 0.:
                raise ValueError("This fixture has no morph")
            if reopen:
                suite.reopen("render_" + self.renderer + "_" + name + "_reopen")
                suite.evaluate(0)
            if self.renderer == "standard":
                source_snapshot = diffuse.snapshot_matrix(suite, case, strength)
            else:
                import native_redshift_test as redshift
                source_snapshot = redshift.snapshot_matrix(suite, case, strength)
            translator = c4d.AliasTrans()
            if not translator.Init(suite.doc):
                raise RuntimeError("Could not initialize render clone link translation")
            clone = suite.doc.GetClone(c4d.COPYFLAGS_NONE, translator)
            if clone is None:
                raise MemoryError("Could not clone the private material scene")
            suite.register_document(clone, "private render clone")
            translator.Translate(True)
            configuration = _configure_scene(suite, clone, self.renderer, shading, self.width, self.height)
            bitmap = c4d.bitmaps.MultipassBitmap(self.width, self.height, c4d.COLORMODE_RGB)
            if bitmap is None or bitmap.AddChannel(True, True) is None:
                raise MemoryError("Could not allocate rendered RGB and straight alpha")
            self.current = {"case": case, "strength": strength, "reopen": reopen,
                            "configuration": configuration, "source_snapshot": source_snapshot}
            self.worker = _worker(c4d, clone, bitmap)
            # Restore the user's live document before the async call returns.
            # Keep strong references to clone/bitmap until the thread has ended.
            _restore(suite)
            if not self.worker.Start(c4d.THREADMODE_ASYNC):
                raise RuntimeError("Native render worker did not start")
            return self.status()
        except Exception:
            if self.worker is None or not self.worker.IsRunning():
                self._release_worker()
                suite.close()
            else:
                self.worker.End(False)
                self.cancel_requested = True
            raise
        finally:
            _restore(suite)

    def status(self):
        _main_thread(self.suite.c4d)
        if self.worker is None:
            return {"state": "closed" if self.closed else "idle", "cleanup_pending": False}
        running = bool(self.worker.IsRunning())
        return {"state": "running" if running else "ready", "cleanup_pending": running and self.cancel_requested,
                "cancel_requested": self.cancel_requested, "progress": self.worker.progress,
                "progress_type": self.worker.progress_type, "case": self.current["case"]["name"],
                "renderer": self.renderer, "shading": self.current["configuration"]["shading"]}

    def _release_worker(self):
        if self.worker is not None:
            if self.worker.IsRunning():
                raise RuntimeError("A running native worker still owns its document and bitmap")
            self.worker.End(True)  # Already stopped; this does not wait on a live render.
            self.worker.document = self.worker.bitmap = None
            self.worker = None

    def collect(self):
        _main_thread(self.suite.c4d)
        if self.worker is None:
            raise RuntimeError("No render result to collect")
        if self.worker.IsRunning():
            return self.status()
        suite, c4d = self.suite, self.suite.c4d
        current, worker = self.current, self.worker
        case, strength = current["case"], current["strength"]
        receipt = {"case": case["name"], "strength": strength, "renderer": self.renderer,
                   "reopen": current["reopen"], "configuration": current["configuration"],
                   "source_snapshot": current["source_snapshot"],
                   "native_image_render": True, "status": "failed", "render_result": worker.result}
        index = len(self.receipts)
        base = suite.output / ("render_" + self.renderer + "_" + str(index) + "_" + case["name"])
        try:
            if worker.error is not None:
                raise RuntimeError("Native render worker: " + repr(worker.error))
            if self.cancel_requested or worker.result != c4d.RENDERRESULT_OK:
                raise RuntimeError("Native render did not complete successfully: " + str(worker.result))
            bitmap = worker.bitmap
            # Persist the actual image before alpha, calibration or ROI checks.
            # A calibration failure must retain the image which caused it.
            image = base.with_suffix(".png")
            if bitmap.Save(str(image), c4d.FILTER_PNG, None, c4d.SAVEBIT_ALPHA) != c4d.IMAGERESULT_OK:
                raise RuntimeError("Could not save the native render evidence")
            receipt["image"] = {"path": str(image), "sha256": hashlib.sha256(image.read_bytes()).hexdigest()}
            alpha = bitmap.GetInternalChannel()
            if alpha is None:
                raise AssertionError("Renderer did not return an actual alpha channel")
            receipt["image_alpha"] = image_alpha_statistics(bitmap, alpha, self.width, self.height)
            shading = current["configuration"]["shading"]
            if case["name"] == "alpha_full":
                if shading == "default" and "isolated_channels" in self.references:
                    self.references[shading] = self.references["isolated_channels"]
                else:
                    self.references[shading] = reference_regions(bitmap, alpha, self.width, self.height)
            reference = self.references[shading]
            receipt["reference"] = reference
            samples = _sample_regions(bitmap, alpha, reference["coordinates"])
            receipt["samples"] = samples
            receipt["oracle"] = matrix.verify_render_samples(case, strength, samples,
                check_rgb=shading == "isolated_channels")
            receipt["default_rgb_visual_acceptance"] = False
            receipt["status"] = "passed"
            return receipt
        except Exception as error:
            receipt["error"] = {"type": type(error).__name__, "message": str(error)}
            raise
        finally:
            self._release_worker()
            receipt["cleanup"] = suite.close()
            self.current = None
            self.receipts.append(receipt)
            base.with_suffix(".json").write_text(json.dumps(receipt, indent=2, ensure_ascii=False), encoding="utf-8")

    def close(self):
        _main_thread(self.suite.c4d)
        if self.worker is not None and self.worker.IsRunning():
            self.cancel_requested = True
            self.worker.End(False)
            _restore(self.suite)
            return {**self.status(), "cleanup_pending": True}
        self._release_worker()
        cleanup = self.suite.close()
        self.current = None
        self.closed = not bool(cleanup["errors"])
        return {"state": "closed" if self.closed else "cleanup_pending", "cleanup_pending": not self.closed,
                "cleanup": cleanup}
