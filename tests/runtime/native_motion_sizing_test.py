"""Bounded main-thread stages for a task-owned C4D process (regression build).

Call begin(), poll(), preview(), persistence(), stale(), cancel(), cleanup() in
separate exec_python requests. Do not wait for the C++ worker on the UI thread.
"""
import json
import os
from pathlib import Path
import sys
import c4d

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'scripts'))
from c4d_runtime_regression import load_resource_ids
from c4d_regression_fixtures import read_vmd


def walk(node):
    while node:
        yield node
        yield from walk(node.GetDown())
        node = node.GetNext()


class NativeSizingTest:
    def __init__(self, output):
        self.output = Path(output)
        self.output.mkdir(parents=True, exist_ok=True)
        self.ids = load_resource_ids(ROOT)
        self.original = c4d.documents.GetActiveDocument()
        self.doc = None
        self.reopened = None
        self.receipt = {'pid': os.getpid(), 'c4d': c4d.GetC4DVersion(), 'kind': 'synthetic-native', 'checks': []}

    def check(self, name, passed, **details):
        self.receipt['checks'].append(dict(name=name, passed=bool(passed), **details))
        self.save()
        if not passed:
            raise AssertionError(name)

    def save(self):
        (self.output/'native.json').write_text(json.dumps(self.receipt, ensure_ascii=False, indent=2), encoding='utf-8')

    def request(self, action, path='', stage=2, **kwargs):
        hook = self.doc.FindSceneHook(1057017)
        hook[1000000] = 1
        hook[1000001] = action
        hook[1000002] = str(path)
        hook[1000020] = str(ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing/source.pmx')
        hook[1000021] = stage
        hook[1000022] = kwargs.get('overlay', False)
        hook[1000026] = 8.5  # test non-unit PMX import scale
        hook[1000007] = False  # sparse export
        hook[1000009] = False  # import all physical channels
        hook.Message(1057017)
        return {'ok': bool(hook[1000100]), 'error': hook[1000101],
                'running': bool(hook[1000023]), 'ready': bool(hook[1000024]), 'summary': hook[1000025]}

    def begin(self):
        self.doc = c4d.documents.BaseDocument()
        self.doc.SetDocumentName('Sizing native owned source')
        c4d.documents.InsertBaseDocument(self.doc)
        c4d.documents.SetActiveDocument(self.doc)
        result = self.request(1, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing/target.pmx')
        self.check('native_target_import', result['ok'], result=result)
        self.model = self.doc.GetFirstObject()
        self.model[self.ids['MODEL_PHYSICS_ENABLED']] = False
        self.doc.SetActiveObject(self.model)
        result = self.request(2, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing/motion.vmd')
        self.check('original_motion_import', result['ok'], result=result)
        self.original_slot = self.model[self.ids['MODEL_ANIM_LIST']]
        self.doc.SetTime(c4d.BaseTime(15, 30))
        self.doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)
        self.bind_before = self.binds()
        self.time_before = self.doc.GetTime().Get()
        result = self.request(20, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing/motion.vmd')
        self.check('background_started', result['ok'], result=result)
        return result

    def binds(self):
        def xyz(value):
            return (value.x, value.y, value.z)
        return {obj.GetName(): xyz(obj.GetTag(1056720)[self.ids['PMX_BONE_POSITION']])
                for obj in walk(self.doc.GetFirstObject()) if obj.GetTag(1056720)}

    def poll(self):
        return self.request(21)

    def preview(self):
        status = self.poll()
        self.check('background_completed', status['ready'] and not status['running'], result=status)
        for stage in (0, 1, 2, 0, 2):
            result = self.request(22, stage=stage)
            self.check(f'preview_stage_{stage}', result['ok'], result=result)
            preview = c4d.documents.GetActiveDocument()
            self.check(f'preview_isolated_{stage}', preview != self.doc and preview.GetFirstObject().GetNext() is not None)
            for frame in (0, 7, 15, 23, 30):
                preview.SetTime(c4d.BaseTime(frame, 30))
                preview.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)
            self.check(f'preview_preserves_source_{stage}', self.binds() == self.bind_before and
                       self.doc.GetTime().Get() == self.time_before and self.model[self.ids['MODEL_ANIM_LIST']] == self.original_slot)
        # Frame native viewport for a truthful before/after capture.
        bd = preview.GetActiveBaseDraw()
        target = c4d.Vector(45, 95, -10)
        pos = target+c4d.Vector(0, 25, -650)
        z = (target-pos).GetNormalized()
        x = c4d.Vector(0, 1, 0).Cross(z).GetNormalized()
        y = z.Cross(x).GetNormalized()
        bd.GetEditorCamera().SetMg(c4d.Matrix(pos, x, y, z))
        bd.SetSceneCamera(None)
        preview.SetActiveObject(None)
        c4d.EventAdd()
        self.check('export_stage', self.request(24, self.output/'adjusted.vmd')['ok'])
        exported = read_vmd(self.output/'adjusted.vmd')
        expected = {}
        for row in (ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing/baseline/reference.tsv').read_text(encoding='utf-8').splitlines():
            name, frame, *pos = row.split('\t')
            expected[(name, int(frame))] = tuple(map(float, pos))
        error = max(abs(value-reference) for key in exported['motions']
                    for value, reference in zip(key['translation'], expected[(key['name'], key['frame'])]))
        self.check('native_scale_8_5_matches_upstream', error < 2e-5, max_error=error)
        return status

    def export_motion(self, suffix):
        path = self.output/(suffix+'.vmd')
        self.doc.SetActiveObject(self.model)
        self.check('export_'+suffix, self.request(4, path)['ok'])
        return read_vmd(path)

    def persistence(self):
        self.request(26)
        self.check('new_slot_apply', self.request(23)['ok'])
        selected = self.model[self.ids['MODEL_ANIM_LIST']]
        self.check('new_slot_selected', selected != self.original_slot, before=self.original_slot, after=selected)
        self.check('bind_preserved_on_apply', self.binds() == self.bind_before)
        self.check('undo', self.doc.DoUndo())
        self.model = self.doc.GetFirstObject()
        self.check('undo_restores_slot', self.model[self.ids['MODEL_ANIM_LIST']] == self.original_slot)
        self.check('redo', self.doc.DoRedo())
        self.model = self.doc.GetFirstObject()
        self.check('redo_restores_adjusted_slot', self.model[self.ids['MODEL_ANIM_LIST']] == selected)
        adjusted = self.export_motion('applied')
        self.model[self.ids['MODEL_ANIM_LIST']] = self.original_slot
        original = self.export_motion('original')
        self.check('slots_independent', adjusted['motions'] != original['motions'])
        self.model[self.ids['MODEL_ANIM_LIST']] = selected
        path = self.output/'sizing-roundtrip.c4d'
        self.check('save', c4d.documents.SaveDocument(self.doc, str(path), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT))
        self.reopened = c4d.documents.LoadDocument(str(path), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
        self.check('reopen', self.reopened is not None)
        c4d.documents.InsertBaseDocument(self.reopened)
        self.check('reopened_adjusted_slot', self.reopened.GetFirstObject()[self.ids['MODEL_ANIM_LIST']] == selected)
        saved_doc, saved_model = self.doc, self.model
        try:
            self.doc, self.model = self.reopened, self.reopened.GetFirstObject()
            readback = self.export_motion('reopened')
            self.check('reopened_keys_equal', readback['motions'] == adjusted['motions'])
            self.model[self.ids['MODEL_ANIM_LIST']] = self.original_slot
            original_readback = self.export_motion('reopened-original')
            self.check('reopened_original_equal', original_readback['motions'] == original['motions'])
        finally:
            self.doc, self.model = saved_doc, saved_model
        return self.receipt

    def stale(self):
        bone = next(obj for obj in walk(self.model) if obj.GetTag(1056720) and obj.GetName() == '左足')
        tag = bone.GetTag(1056720)
        old = tag[self.ids['PMX_BONE_POSITION']]
        try:
            tag[self.ids['PMX_BONE_POSITION']] = old+c4d.Vector(.1, 0, 0)
            result = self.request(23)
            self.check('stale_bind_rejected', not result['ok'], result=result)
        finally:
            tag[self.ids['PMX_BONE_POSITION']] = old
        self.model.Remove()
        try:
            result = self.request(23)
            self.check('removed_target_rejected', not result['ok'], result=result)
        finally:
            self.doc.InsertObject(self.model)
            self.doc.SetActiveObject(self.model)
        return self.receipt

    def overlay(self):
        self.check('overlay_preview', self.request(22, overlay=True)['ok'])
        preview = c4d.documents.GetActiveDocument()
        before = preview.GetFirstObject()
        after = before.GetNext()
        self.check('overlay_shared_origin', before.GetRelPos() == after.GetRelPos())
        before_mesh = next(obj for obj in walk(before.GetDown()) if obj.CheckType(c4d.Opolygon))
        after_mesh = next(obj for obj in walk(after.GetDown()) if obj.CheckType(c4d.Opolygon))
        self.check('preview_color_separation', before_mesh[c4d.ID_BASEOBJECT_COLOR] != after_mesh[c4d.ID_BASEOBJECT_COLOR])
        self.check('original_ghost', before_mesh[c4d.ID_BASEOBJECT_XRAY] and not after_mesh[c4d.ID_BASEOBJECT_XRAY])
        c4d.EventAdd()

    def ui(self):
        self.check('native_dialog_layout_open', self.request(27)['ok'])

    def close_ui(self):
        self.check('native_dialog_closed', self.request(28)['ok'])

    def cancel(self):
        self.doc.SetActiveObject(self.model)
        self.slot_before_cancel = self.model[self.ids['MODEL_ANIM_LIST']]
        self.check('cancel_job_start', self.request(20, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing/motion.vmd')['ok'])
        return self.request(25)

    def cancelled(self):
        result = self.poll()
        self.check('cancel_does_not_publish', not result['running'] and not result['ready'], result=result)
        self.check('cancel_preserves_slot', self.model[self.ids['MODEL_ANIM_LIST']] == self.slot_before_cancel)
        return self.receipt

    def cleanup(self):
        if self.doc:
            self.request(28)
            self.request(26)
        for doc in (self.reopened, self.doc):
            if doc:
                c4d.documents.KillDocument(doc)
        c4d.documents.SetActiveDocument(self.original)
        self.receipt['original_document_restored'] = c4d.documents.GetActiveDocument() == self.original
        remaining = []
        document = c4d.documents.GetFirstDocument()
        while document:
            if document.GetDocumentName().startswith(('Sizing native', 'VMD Sizing Preview', 'sizing-roundtrip')):
                remaining.append(document.GetDocumentName())
            document = document.GetNext()
        self.receipt['remaining_owned_documents'] = remaining
        self.save()
        return self.receipt
