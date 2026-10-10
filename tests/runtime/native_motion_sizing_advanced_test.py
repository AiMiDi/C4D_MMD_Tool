"""P2-P4 native checks, in separate calls so the UI thread never waits on a job.

Use begin(), poll(), preview(), results(), cleanup() on an owned C4D instance.
The harness never closes a process or a document it did not create.
"""
import json
from pathlib import Path
import c4d
from native_motion_sizing_test import NativeSizingTest, ROOT


class NativeAdvancedSizingTest(NativeSizingTest):
    def request(self, action, path='', stage=7, **kwargs):
        hook = self.doc.FindSceneHook(1057017)
        hook[1000040] = 127
        hook[1000041] = str(ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing-advanced/camera.vmd')
        hook[1000042] = kwargs.get('member', 0)
        # The base method sets the old fixture path; replace it before Message.
        hook[1000000] = 1
        hook[1000001] = action
        hook[1000002] = str(path)
        hook[1000020] = str(ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing-advanced/source.pmx')
        hook[1000021] = stage
        hook[1000022] = kwargs.get('overlay', False)
        hook[1000026] = 8.5
        hook[1000007] = False
        hook[1000009] = False
        hook.Message(1057017)
        return {'ok': bool(hook[1000100]), 'error': hook[1000101],
                'running': bool(hook[1000023]), 'ready': bool(hook[1000024]), 'summary': hook[1000025]}

    def begin(self):
        self.doc = c4d.documents.BaseDocument()
        self.doc.SetDocumentName('Sizing native advanced source')
        c4d.documents.InsertBaseDocument(self.doc)
        c4d.documents.SetActiveDocument(self.doc)
        self.models = []
        for i in range(2):
            result = self.request(1, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing-advanced/target.pmx')
            self.check(f'batch_target_import_{i}', result['ok'], result=result)
            model = self.doc.GetFirstObject()
            model.SetName(f'Sizing actor {i+1}')
            model[self.ids['MODEL_PHYSICS_ENABLED']] = False
            self.doc.SetActiveObject(model)
            self.check(f'batch_original_import_{i}', self.request(2, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing-advanced/motion.vmd')['ok'])
            self.models.append(model)
        self.original_slots = [m[self.ids['MODEL_ANIM_LIST']] for m in self.models]
        self.doc.SetTime(c4d.BaseTime(7, 30))
        self.bind_before = self.binds()
        result = self.request(40, ROOT/'dependency/libMMD/tests/fixtures/vmd-sizing-advanced/motion.vmd')
        self.check('batch_background_start', result['ok'], result=result)
        return result

    def preview(self):
        result = self.poll()
        self.check('batch_background_complete', result['ready'] and not result['running'], result=result)
        self.check('localized_status', '已完成角色' in result['summary'])
        for stage in (0, 1, 2, 3, 4, 5, 6, 7, 3, 7):
            result = self.request(22, stage=stage, overlay=True)
            self.check(f'batch_preview_{stage}', result['ok'], result=result)
            preview = c4d.documents.GetActiveDocument()
            models = [o for o in preview.GetObjects() if o.GetType() == self.models[0].GetType()]
            self.check(f'four_preview_models_{stage}', len(models) == 4)
            for frame in (0, 7, 15, 23, 30):
                preview.SetTime(c4d.BaseTime(frame, 30))
                preview.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)
            self.check(f'preview_preserves_source_{stage}', self.bind_before == self.binds() and
                       self.doc.GetTime().GetFrame(30) == 7 and
                       self.original_slots == [m[self.ids['MODEL_ANIM_LIST']] for m in self.models])
        camera = next(o for o in preview.GetObjects() if not o.GetType() == self.models[0].GetType())
        self.check('preview_camera_exists', camera is not None)
        self.check('preview_localized_name', '动作适配预览' in preview.GetDocumentName())
        bd = preview.GetActiveBaseDraw()
        target = c4d.Vector(0, 90, 0)
        pos = target + c4d.Vector(0, 15, -420)
        z = (target-pos).GetNormalized(); x = c4d.Vector(0, 1, 0).Cross(z).GetNormalized(); y = z.Cross(x).GetNormalized()
        bd.GetEditorCamera().SetMg(c4d.Matrix(pos, x, y, z))
        bd.SetSceneCamera(None)
        preview.SetTime(c4d.BaseTime(15, 30))
        preview.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)
        c4d.EventAdd()
        return {'checks': len(self.receipt['checks'])}

    def results(self):
        def refresh_models():
            # C4D undo restores model objects; old Python wrappers can still
            # reference the detached pre-undo instances.
            roots = {o.GetName(): o for o in self.doc.GetObjects()}
            self.models = [roots[f'Sizing actor {i+1}'] for i in range(2)]

        for member in (0, 1):
            self.check(f'select_character_{member}', self.request(41, member=member)['ok'])
            self.check(f'export_character_{member}', self.request(24, self.output/f'actor-{member}.vmd')['ok'])
            # Snapshot root order is reverse insertion order.
            model = self.models[1-member]
            original = model[self.ids['MODEL_ANIM_LIST']]
            self.check(f'apply_character_{member}', self.request(23)['ok'])
            adjusted = model[self.ids['MODEL_ANIM_LIST']]
            self.check(f'new_slot_{member}', adjusted != original)
            self.check(f'undo_{member}', self.doc.DoUndo())
            refresh_models()
            self.check(f'undo_slot_{member}', self.models[1-member][self.ids['MODEL_ANIM_LIST']] == original)
            self.check(f'redo_{member}', self.doc.DoRedo())
            refresh_models()
            self.check(f'redo_slot_{member}', self.models[1-member][self.ids['MODEL_ANIM_LIST']] == adjusted)
        self.check('export_camera', self.request(42, self.output/'camera.vmd')['ok'])
        before = len(self.doc.GetObjects())
        self.check('apply_camera', self.request(43)['ok'])
        self.check('camera_added', len(self.doc.GetObjects()) == before+1)
        self.check('camera_undo', self.doc.DoUndo() and len(self.doc.GetObjects()) == before)
        self.check('camera_redo', self.doc.DoRedo() and len(self.doc.GetObjects()) == before+1)
        refresh_models()
        path = self.output/'advanced-roundtrip.c4d'
        self.check('batch_save', c4d.documents.SaveDocument(self.doc, str(path), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT))
        self.reopened = c4d.documents.LoadDocument(str(path), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS)
        self.check('batch_reopen', self.reopened is not None)
        c4d.documents.InsertBaseDocument(self.reopened)
        self.check('batch_reopened_model_camera_count', len(self.reopened.GetObjects()) == before+1)
        self.check('batch_reopened_slots', sorted(o[self.ids['MODEL_ANIM_LIST']] for o in self.reopened.GetObjects()
                   if o.GetType() == self.models[0].GetType()) == sorted(m[self.ids['MODEL_ANIM_LIST']] for m in self.models))
        self.save()
        return {'checks': len(self.receipt['checks'])}

    def scene_slot_start(self):
        c4d.documents.SetActiveDocument(self.doc)
        self.doc.SetActiveObject(self.models[0])
        self.scene_slot_before = self.models[0][self.ids['MODEL_ANIM_LIST']]
        self.scene_time_before = self.doc.GetTime().Get()
        self.check('scene_slot_start', self.request(44, member=0)['ok'])

    def scene_slot_finish(self):
        result = self.poll()
        self.check('scene_slot_complete', result['ready'] and not result['running'], result=result)
        self.check('scene_slot_does_not_select_source', self.models[0][self.ids['MODEL_ANIM_LIST']] == self.scene_slot_before)
        self.check('scene_slot_preserves_time', self.doc.GetTime().Get() == self.scene_time_before)
        self.check('scene_slot_export', self.request(24, self.output/'scene-slot-original.vmd', stage=0)['ok'])
        self.check('scene_slot_preview', self.request(22, stage=7)['ok'])
        return {'checks': len(self.receipt['checks'])}

    def cleanup(self):
        result = super().cleanup()
        names = []
        document = c4d.documents.GetFirstDocument()
        while document:
            names.append(document.GetDocumentName())
            document = document.GetNext()
        result['documents_after_cleanup'] = names
        result['remaining_owned_documents'] = [n for n in names if n.startswith(('Sizing native', 'advanced-roundtrip', 'VMD 动作适配预览'))]
        self.save()
        return {'original_document_restored': result['original_document_restored'],
                'remaining_owned_documents': result['remaining_owned_documents'], 'checks': len(result['checks'])}
