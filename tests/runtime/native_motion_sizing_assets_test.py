"""User-supplied PMX/VMD integration checks; no assets are copied into the repo.

Run begin(), then poll(), preview(), persistence(), cleanup() in separate
C4D main-thread requests. Source and target paths are explicit caller inputs.
"""
import c4d
from pathlib import Path
from native_motion_sizing_test import NativeSizingTest, walk


class NativeAssetSizingTest(NativeSizingTest):
    def __init__(self, output, source, target, motion, camera):
        super().__init__(output)
        self.source_path, self.target_path = Path(source), Path(target)
        self.motion_path, self.camera_path = Path(motion), Path(camera)
        self.flags = 3
        self.receipt['kind'] = 'user-assets-native'
        self.receipt['inputs'] = dict(source=str(source), target=str(target), motion=str(motion), camera=str(camera))

    def request(self, action, path='', stage=7, **kwargs):
        hook = self.doc.FindSceneHook(1057017)
        for key, value in {1000000:1,1000001:action,1000002:str(path),1000020:str(self.source_path),
                           1000021:stage,1000022:kwargs.get('overlay',False),1000026:1.0,
                           1000007:False,1000009:False,1000040:self.flags,
                           1000041:str(self.camera_path),1000042:kwargs.get('member',0)}.items():
            hook[key]=value
        hook.Message(1057017)
        return {'ok':bool(hook[1000100]),'error':hook[1000101], 'running':bool(hook[1000023]),
                'ready':bool(hook[1000024]),'summary':hook[1000025]}

    def begin(self):
        self.doc=c4d.documents.BaseDocument()
        self.doc.SetDocumentName('Sizing native real assets')
        c4d.documents.InsertBaseDocument(self.doc);c4d.documents.SetActiveDocument(self.doc)
        self.check('real_model_import',self.request(1,self.target_path)['ok'])
        self.model=self.doc.GetFirstObject()
        self.model[self.ids['MODEL_PHYSICS_ENABLED']]=False
        self.check('real_motion_import',self.request(2,self.motion_path)['ok'])
        self.original_slot=self.model[self.ids['MODEL_ANIM_LIST']]
        self.doc.SetTime(c4d.BaseTime(400,30))
        self.doc.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_0)
        self.bind_before=self.binds();self.time_before=self.doc.GetTime().Get()
        r=self.request(40,self.motion_path)
        self.check('real_background_start',r['ok'],result=r)
        return r

    def preview(self):
        r=self.poll();self.check('real_background_complete',r['ready'] and not r['running'],result=r)
        for stage in range(8):
            r=self.request(22,stage=stage,overlay=False)
            self.check('real_stage_'+str(stage),r['ok'],result=r)
            preview=c4d.documents.GetActiveDocument()
            for frame in (0,400,800,1200,1690):
                preview.SetTime(c4d.BaseTime(frame,30))
                preview.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_0)
            self.check('real_source_unchanged_'+str(stage),self.bind_before==self.binds() and
                       self.doc.GetTime().Get()==self.time_before and self.model[self.ids['MODEL_ANIM_LIST']]==self.original_slot)
        self.check('real_export_motion',self.request(24,self.output/'adjusted.vmd')['ok'])
        self.check('real_export_camera',self.request(42,self.output/'adjusted-camera.vmd')['ok'])
        preview.SetTime(c4d.BaseTime(400,30))
        bd=preview.GetActiveBaseDraw();target=c4d.Vector(0,9,0);pos=target+c4d.Vector(0,2,-60)
        z=(target-pos).GetNormalized();x=c4d.Vector(0,1,0).Cross(z).GetNormalized();y=z.Cross(x).GetNormalized()
        bd.GetEditorCamera().SetMg(c4d.Matrix(pos,x,y,z));bd.SetSceneCamera(None)
        preview.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_0);c4d.EventAdd()
        return {'checks':len(self.receipt['checks'])}

    def apply_roundtrip(self):
        self.check('real_apply',self.request(23)['ok'])
        adjusted=self.model[self.ids['MODEL_ANIM_LIST']]
        self.check('real_new_slot',adjusted!=self.original_slot)
        self.check('real_undo',self.doc.DoUndo());self.model=self.doc.GetFirstObject()
        self.check('real_undo_slot',self.model[self.ids['MODEL_ANIM_LIST']]==self.original_slot)
        self.check('real_redo',self.doc.DoRedo());self.model=self.doc.GetFirstObject()
        self.check('real_redo_slot',self.model[self.ids['MODEL_ANIM_LIST']]==adjusted)
        p=self.output/'real-roundtrip.c4d'
        self.check('real_save',c4d.documents.SaveDocument(self.doc,str(p),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT))
        self.reopened=c4d.documents.LoadDocument(str(p),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS)
        self.check('real_reopen',self.reopened is not None)
        c4d.documents.InsertBaseDocument(self.reopened)
        self.check('real_reopened_slot',self.reopened.GetFirstObject()[self.ids['MODEL_ANIM_LIST']]==adjusted)
        return {'checks':len(self.receipt['checks'])}
