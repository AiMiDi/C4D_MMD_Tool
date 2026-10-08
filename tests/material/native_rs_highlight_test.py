"""Asynchronous, ordinary RS highlight response test using imported MMD data.

This fixture records highlight response for later analysis, not MMD/RS BRDF
equivalence. Use create_session/active_session across MCP callbacks. Run only in
an exclusively allocated host; its registry cannot lock unrelated test scripts.
"""
from pathlib import Path
import hashlib
import json

CASES = {
    "white_broad": ((1., 1., 1.), 2.),
    "white_narrow": ((1., 1., 1.), 510.),
    "red": ((1., 0., 0.), 30.),
    "zero": ((0., 0., 0.), 30.),
}

# MCP callbacks have separate globals. Retain the worker and all document
# ownership in this imported module until explicit cleanup has completed.
_active_session = None


def create_session(c4d, output):
    global _active_session
    if _active_session is not None:
        raise RuntimeError("Close the active highlight session before creating another")
    _active_session = _Session(c4d, output)
    return _active_session


def active_session():
    if _active_session is None:
        raise RuntimeError("No retained highlight session")
    return _active_session


class _Session:
    def __init__(self, c4d, output):
        import maxon
        import redshift
        import shader_binding_test as binding
        from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

        self.c4d = c4d
        self.output = Path(output).resolve()
        self.output.mkdir(parents=True, exist_ok=False)
        self.worker = None
        self.guard = None
        self.rows = []
        self.sequence = 0
        self.prefs = c4d.plugins.FindPlugin(1036220, c4d.PLUGINTYPE_PREFS)
        self.devices = []
        for data, identifier, group in self.prefs.GetDescription(c4d.DESCFLAGS_DESC_0):
            key = identifier[0].id
            if c4d.PREFS_REDSHIFT_FIRST_DEVICE <= key <= c4d.PREFS_REDSHIFT_LAST_DEVICE:
                self.devices.append((key, data.GetString(c4d.DESC_NAME), self.prefs[key]))
        self.hybrid = self.prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING]
        self.suite = binding.production_suite(c4d, {
            "resource_ids": load_resource_ids(Path(__file__).resolve().parents[2]),
            "output": str(self.output)}, material_type="redshift")
        self.identity = {"c4d": c4d.GetC4DVersion(), "rs": redshift.GetCoreVersion(),
                         "fixture_profile": "ordinary-rs-highlight-v1",
                         "module": loaded_plugin_binary(), "devices_before": self.devices,
                         "hybrid_before": self.hybrid, "native_mmd_reference": False,
                         "resolution": [256, 256], "view_transform_baked": False}
        self._write("identity.json", self.identity)
        try:
            original = self.suite.original_document
            if original and original.GetFirstObject() is None and original.GetFirstMaterial() is None:
                self.guard = c4d.BaseObject(c4d.Onull)
                self.guard.SetName("CMT highlight original-document guard")
                original.InsertObject(self.guard)
            fixture = binding.prepare(self.output)
            self.suite.new_document("CMT RS highlight validation")
            self.suite.call("import_model", fixture["binding.pmx"]["path"])
            self.suite.model = self.suite.nodes(1056724)[0]
            model, ids = self.suite.model, self.suite.ids
            model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
            model[ids["MODEL_MATERIAL_LIST"]] = 0
            material = model[ids["MODEL_MATERIAL_LINK"]]
            graph = material.GetNodeMaterialReference().GetGraph(
                maxon.Id("com.redshift3d.redshift4c4d.class.nodespace"))
            with graph.BeginTransaction() as transaction:
                for node in list(graph.GetNode(maxon.NodePath()).GetChildren()):
                    if str(node.GetId()).startswith(("cmt_morph_", "cmt_texture_")):
                        node.Remove()
                transaction.Commit()
            metadata = c4d.BaseContainer()
            metadata.SetBool(90, True)
            material.GetDataInstance().SetContainer(1068715, metadata)
            model.SetRenderMode(c4d.MODE_OFF)
            document = self.suite.doc
            sphere = c4d.BaseObject(c4d.Osphere)
            sphere[c4d.PRIM_SPHERE_RAD] = 60.
            sphere[c4d.PRIM_SPHERE_SUB] = 96
            document.InsertObject(sphere)
            tag = c4d.TextureTag()
            tag.SetMaterial(material)
            sphere.InsertTag(tag)
            camera = c4d.BaseObject(c4d.Ocamera)
            camera.SetAbsPos(c4d.Vector(0., 0., -300.))
            document.InsertObject(camera)
            document.GetRenderBaseDraw().SetSceneCamera(camera)
            light = c4d.BaseObject(1036751)
            light[c4d.REDSHIFT_LIGHT_TYPE] = c4d.REDSHIFT_LIGHT_TYPE_PHYSICAL_INFINITE
            light[c4d.REDSHIFT_LIGHT_PHYSICAL_INTENSITY] = 1.
            light.SetAbsPos(c4d.Vector(0., 0., -200.))
            document.InsertObject(light)
            rd = document.GetActiveRenderData()
            for key, value in ((c4d.RDATA_RENDERENGINE, 1036219), (c4d.RDATA_XRES, 256),
                               (c4d.RDATA_YRES, 256), (c4d.RDATA_ALPHACHANNEL, True),
                               (c4d.RDATA_STRAIGHTALPHA, True), (c4d.RDATA_SAVEIMAGE, False),
                               (c4d.RDATA_BAKE_OCIO_VIEW_TRANSFORM_RENDER, False)):
                rd[key] = value
            from native_render_matrix import ensure_redshift_post
            post = ensure_redshift_post(c4d, rd)
            post[c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES] = 16
            post[c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES] = 64
            post[c4d.REDSHIFT_RENDERER_DENOISE_ENABLED] = False
            c4d.documents.SetActiveDocument(self.suite.original_document)
        except Exception:
            self.close()
            raise

    def _write(self, name, data):
        (self.output / name).write_text(json.dumps(data, indent=2), encoding="utf-8")

    def start(self, case, device="cpu", reopen=False):
        try:
            return self._start(case, device, reopen)
        except Exception:
            # A live worker owns the device window until collected or stopped.
            if self.worker is None:
                self._restore_devices()
            raise

    def _start(self, case, device, reopen):
        import native_render_matrix as render
        c4d = self.c4d
        if self.worker is not None:
            raise RuntimeError("Collect the previous worker first")
        if device not in ("cpu", "gpu") or case not in CASES:
            raise ValueError("Unknown case or device")
        selected = [key for key, name, prior in self.devices if ("CPU" in name) == (device == "cpu")]
        if not selected:
            raise RuntimeError("Requested device is unavailable")
        for key, name, prior in self.devices:
            self.prefs[key] = key in selected
        self.prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = False
        self.current = {"case": case, "device": device, "reopen": reopen,
                        "devices": [(name, bool(self.prefs[key])) for key, name, prior in self.devices]}
        model, ids = self.suite.model, self.suite.ids
        model[ids["MODEL_MATERIAL_LIST"]] = 0
        model[ids["MODEL_MATERIAL_DIFFUSE_COLOR"]] = c4d.Vector(0.)
        model[ids["MODEL_MATERIAL_DIFFUSE_ALPHA"]] = 1.
        color, power = CASES[case]
        self.current.update(specular_color=list(color), specular_power=power)
        model[ids["MODEL_MATERIAL_SPECULAR_COLOR"]] = c4d.Vector(*color)
        model[ids["MODEL_MATERIAL_SPECULAR_POWER"]] = power
        c4d.CallButton(model, ids["MODEL_MATERIAL_SYNC_BUTTON"])
        if reopen:
            self.suite.reopen("highlight-" + case)
        self.sequence += 1
        label = f"{self.sequence:03d}-" + device + "-" + case + ("-reopen" if reopen else "")
        scene = self.output / (label + ".c4d")
        if not c4d.documents.SaveDocument(self.suite.doc, str(scene), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
            raise RuntimeError("Cannot save highlight fixture")
        self.current["label"] = label
        translator = c4d.AliasTrans()
        if not translator.Init(self.suite.doc):
            raise RuntimeError("Cannot initialize private clone translation")
        clone = self.suite.doc.GetClone(c4d.COPYFLAGS_NONE, translator)
        translator.Translate(True)
        clone.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
        bitmap = c4d.bitmaps.MultipassBitmap(256, 256, c4d.COLORMODE_RGB)
        if bitmap is None or bitmap.AddChannel(True, True) is None:
            raise MemoryError("Cannot allocate RGBA target")
        self.worker = render._worker(c4d, clone, bitmap)
        if not self.worker.Start(c4d.THREADMODE_ASYNC):
            self.worker = None
            raise RuntimeError("Render worker did not start")
        c4d.documents.SetActiveDocument(self.suite.original_document)
        return self.current

    def collect(self):
        worker, c4d = self.worker, self.c4d
        if worker is None:
            raise RuntimeError("No worker to collect")
        if worker.IsRunning():
            return {"running": True, "progress": worker.progress}
        worker.End(True)
        row = dict(self.current, result=worker.result, error=worker.error, status="failed")
        try:
            path = self.output / (row["label"] + ".png")
            if worker.bitmap.Save(str(path), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA) != c4d.IMAGERESULT_OK:
                raise RuntimeError("Cannot save render evidence")
            row.update(image=str(path), sha256=hashlib.sha256(path.read_bytes()).hexdigest())
            if worker.result != c4d.RENDERRESULT_OK or worker.error:
                raise AssertionError("Render failed: " + str(row))
            row["status"] = "rendered_pending_analysis"
            return row
        finally:
            self.rows.append(row)
            self._write("renders.json", self.rows)
            worker.document = worker.bitmap = None
            self.worker = None
            self._restore_devices()

    def _restore_devices(self):
        for key, name, prior in self.devices:
            self.prefs[key] = prior
        self.prefs[self.c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = self.hybrid

    def close(self):
        global _active_session
        if self.worker is not None:
            if self.worker.IsRunning():
                self.worker.End(False)
                return {"cleanup_pending": True}
            self.worker.End(True)
            self.worker.document = self.worker.bitmap = None
            self.worker = None
        self._restore_devices()
        cleanup = self.suite.close()
        if self.guard is not None and cleanup["original_document_restored"]:
            self.guard.Remove()
            self.guard = None
        cleanup["devices_restored"] = all(self.prefs[key] == prior for key, name, prior in self.devices)
        cleanup["hybrid_restored"] = self.prefs[self.c4d.PREFS_REDSHIFT_HYBRID_RENDERING] == self.hybrid
        self._write("cleanup.json", cleanup)
        if (not cleanup["errors"] and not cleanup["remaining_owned_documents"]
                and cleanup["original_document_restored"] and cleanup["devices_restored"]
                and cleanup["hybrid_restored"]):
            if _active_session is self:
                _active_session = None
        return cleanup
