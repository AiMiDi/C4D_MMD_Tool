"""Saved/reopened GPU and CPU acceptance for the managed Toon recipe.

Run only in a private c4dpy process. This renders real MMD-owned attributes;
reader-default substitutions are limited to the separate global Contour control.
"""
from pathlib import Path
import json


def run(c4d, output, pmx_path, groups=None, compute_devices=('gpu','cpu')):
    import maxon, redshift
    import shader_binding_test as binding
    import native_toon_test as toon
    import native_render_matrix as render
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    groups = set(groups or ('morph','character-False','character-True','actual'))
    ids = load_resource_ids(Path(__file__).resolve().parents[2])
    prefs = c4d.plugins.FindPlugin(1036220, c4d.PLUGINTYPE_PREFS)
    devices = [(did[0].id, bc.GetString(c4d.DESC_NAME), prefs[did])
               for bc, did, _ in prefs.GetDescription(c4d.DESCFLAGS_DESC_0)
               if c4d.PREFS_REDSHIFT_FIRST_DEVICE <= did[0].id <= c4d.PREFS_REDSHIFT_LAST_DEVICE]
    previous = (prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING], prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE])
    receipt = {'module':loaded_plugin_binary(), 'rs':redshift.GetCoreVersion(),
               'c4d':c4d.GetC4DVersion(), 'cases':[], 'passed':False,
               'light':[.25,-.65,1.], 'gi':[0,0], 'samples':[16,64],
               'native_mmd_reference_same_conditions':False, 'groups':sorted(groups),
               'compute_devices':list(compute_devices)}
    guard = c4d.documents.BaseDocument()
    guard.SetDocumentName('Unrelated active document during Toon evaluation')
    guard.SetTime(c4d.BaseTime(99,30))
    # C4D closes an untouched empty document when the first fixture opens.
    guard.InsertObject(c4d.BaseObject(c4d.Onull))
    c4d.documents.InsertBaseDocument(guard)

    def record():
        (output/'receipt.json').write_text(json.dumps(receipt,indent=2,default=str),encoding='utf8')

    def scene_setup(scene, position, width, height):
        camera = c4d.BaseObject(c4d.Ocamera)
        camera.SetName('Acceptance camera')
        camera.SetAbsPos(c4d.Vector(*position))
        scene.InsertObject(camera)
        scene.GetRenderBaseDraw().SetSceneCamera(camera)
        light = c4d.BaseObject(c4d.Olight)
        light[c4d.LIGHT_TYPE], light[c4d.LIGHT_BRIGHTNESS] = c4d.LIGHT_TYPE_DISTANT, 1.
        light.SetAbsRot(c4d.utils.VectorToHPB(c4d.Vector(*receipt['light'])))
        scene.InsertObject(light)
        rd = scene.GetActiveRenderData()
        for key,value in ((c4d.RDATA_RENDERENGINE,1036219),(c4d.RDATA_XRES,width),
                          (c4d.RDATA_YRES,height),(c4d.RDATA_ALPHACHANNEL,True),
                          (c4d.RDATA_STRAIGHTALPHA,True),(c4d.RDATA_SAVEIMAGE,False)):
            rd[key] = value
        post = render.ensure_redshift_post(c4d,rd)
        settings = post.GetDataInstance()
        for key,value in ((c4d.REDSHIFT_RENDERER_PRIMARY_GI_ENGINE,0),
                          (c4d.REDSHIFT_RENDERER_SECONDARY_GI_ENGINE,0),
                          (c4d.REDSHIFT_RENDERER_UNIFIED_MIN_SAMPLES,16),
                          (c4d.REDSHIFT_RENDERER_UNIFIED_MAX_SAMPLES,64)):
            settings.SetInt32(key,value)
        settings.SetBool(c4d.REDSHIFT_RENDERER_DENOISE_ENABLED,False)
        return camera,post

    def image(scene, name, device, reopen=True):
        selected = [key for key,label,_ in devices if ('CPU' in label.upper()) == (device=='cpu')]
        if not selected:
            raise AssertionError('No compute device: '+device)
        for key,_,_ in devices:
            prefs[key] = key in selected
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING] = False
        prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = 0
        path = output/(name+'.c4d')
        if reopen:
            assert c4d.documents.SaveDocument(scene,str(path),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT)
            document = c4d.documents.LoadDocument(str(path),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
            assert document
        else:
            translator = c4d.AliasTrans()
            assert translator.Init(scene)
            document = scene.GetClone(c4d.COPYFLAGS_NONE,translator)
            translator.Translate(True)
        try:
            camera = next(node for node in walk(document.GetFirstObject()) if node.CheckType(c4d.Ocamera))
            document.GetRenderBaseDraw().SetSceneCamera(camera)
            original_active = c4d.documents.GetActiveDocument()
            c4d.documents.SetActiveDocument(guard)
            document.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_NONE)
            rd = document.GetActiveRenderData()
            bitmap = c4d.bitmaps.MultipassBitmap(int(rd[c4d.RDATA_XRES]),int(rd[c4d.RDATA_YRES]),c4d.COLORMODE_RGB)
            bitmap.AddChannel(True,True)
            result = c4d.documents.RenderDocument(document,rd.GetDataInstance(),bitmap,c4d.RENDERFLAGS_EXTERNAL)
            c4d.documents.SetActiveDocument(original_active)
            if result != c4d.RENDERRESULT_OK:
                receipt['failed_render']={'name':name,'result':int(result)}
                record()
                raise AssertionError((name,result))
            assert bitmap.Save(str(output/(name+'.png')),c4d.FILTER_PNG,savebits=c4d.SAVEBIT_ALPHA)==c4d.IMAGERESULT_OK
            models = [node for node in walk(document.GetFirstObject()) if node.CheckType(1056724)]
            snapshot = []
            if models:
                shadow = type('ReadOnlySuite',(),{})()
                shadow.c4d,shadow.doc = c4d,document
                shadow.nodes = lambda kind:[n for n in walk(document.GetFirstObject()) if n.GetType()==kind]
                snapshot = toon.binding_snapshot(shadow)
            receipt['cases'].append({'name':name,'device':device,'selected':selected,'save_reopen':reopen,
                                     'binding':snapshot,'result':int(result),'unrelated_document_active_during_evaluation':True})
            record()
            return bitmap
        finally:
            c4d.documents.KillDocument(document)

    def walk(root):
        while root:
            yield root
            yield from walk(root.GetDown())
            root = root.GetNext()

    def fixture(label, renderer='redshift_toon', multipart=False, actual=False):
        folder = output/label
        folder.mkdir(exist_ok=True)
        fixtures = toon.prepare_character(folder) if label.startswith('character') else toon.prepare(folder)
        suite = binding.production_suite(c4d,{'output':str(folder),'fixtures':fixtures,'resource_ids':ids},
                                         material_type=renderer,import_options={'multipart':multipart})
        suite.new_document(label)
        path = pmx_path if actual else folder/('toon-character.pmx' if label.startswith('character') else 'toon-binding.pmx')
        suite.call('import_model',str(path))
        suite.model = suite.nodes(1056724)[0]
        suite.model[ids['MODEL_PHYSICS_ENABLED']] = False
        suite.model[ids['MODEL_MODE']] = ids['MODEL_MODE_EDIT']
        suite.evaluate(0)
        return suite

    try:
        if 'morph' in groups:
            suite = fixture('morph')
            try:
                model = suite.model
                scene_setup(suite.doc,(0.,0.,-8.),320,180)
                model.GetDescription(c4d.DESCFLAGS_DESC_0)
                strengths = {bc.GetString(c4d.DESC_NAME):did for did,bc in model.GetUserDataContainer()
                             if did[-1].dtype==c4d.DTYPE_REAL and bc.GetString(c4d.DESC_NAME) in ('Tint','Multiply','Group','Flip')}
                if set(strengths) != {'Tint','Multiply','Group','Flip'}:
                    raise AssertionError('Missing formal Morph attributes: '+str(strengths))
                model[ids['MODEL_MODE']] = ids['MODEL_MODE_ANIM']
                for name,values in {'Tint':(0.,.2,.4),'Multiply':(0.,.5,0.),'Group':(0.,1.,0.),'Flip':(0.,0.,1.)}.items():
                    track = c4d.CTrack(model,strengths[name])
                    model.InsertTrackSorted(track)
                    curve = track.GetCurve()
                    for frame,value in zip((0,15,30),values):
                        key = curve.AddKey(c4d.BaseTime(frame,30))['key']
                        key.SetValue(curve,value)
                        key.SetInterpolation(curve,c4d.CINTERPOLATION_LINEAR)
                for device in compute_devices:
                    for step,frame in enumerate((0,15,30,0,30,15,0)):
                        suite.evaluate(frame)
                        image(suite.doc,f'morph-{device}-{step}-{frame}',device)
                model[ids['MODEL_MODE']] = ids['MODEL_MODE_EDIT']
                model[ids['MODEL_MATMORPH_PREVIEW_ENABLED']] = True
                for index,weight in ((0,.5),(2,1.)):
                    model[ids['MODEL_MATMORPH_PREVIEW_LIST']] = index
                    model[ids['MODEL_MATMORPH_PREVIEW_WEIGHT']] = weight
                preview_device = compute_devices[0]
                image(suite.doc,'preview-mixed',preview_device,reopen=False)
                model[ids['MODEL_MATMORPH_PREVIEW_ENABLED']] = False
                image(suite.doc,'preview-off',preview_device,reopen=False)
                model[ids['MODEL_MATMORPH_PREVIEW_ENABLED']] = True
                image(suite.doc,'preview-reopen',preview_device)
            finally:
                suite.close()

        for multipart in (False,True):
            if 'character-'+str(multipart) not in groups:
                continue
            suite = fixture('character-'+str(multipart),multipart=multipart)
            try:
                camera,post = scene_setup(suite.doc,(0.,.7,-7.),320,320)
                for case,edge,size,specular in (('base',1,1.,.15),('off',0,1.,.15),
                                                ('zero-width',1,0.,.15),('wide',1,3.,.15),('zero-spec',1,1.,0.)):
                    for index in range(5):
                        suite.model[ids['MODEL_MATERIAL_LIST']] = index
                        suite.model[ids['MODEL_MATERIAL_EDGE_ENABLED']] = edge
                        suite.model[ids['MODEL_MATERIAL_EDGE_SIZE']] = size
                        suite.model[ids['MODEL_MATERIAL_SPECULAR_COLOR']] = c4d.Vector(specular)
                    suite.evaluate(0)
                    for device in compute_devices:
                        image(suite.doc,f'character-{multipart}-{case}-{device}',device)
                # A global material with a conspicuous magenta Contour is an
                # independent positive control. Per-material profiles remain connected.
                global_material = suite.doc.GetFirstMaterial().GetClone(c4d.COPYFLAGS_NONE)
                global_material.SetName('Global contour positive control')
                suite.doc.InsertMaterial(global_material)
                graph = global_material.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
                with graph.BeginTransaction() as transaction:
                    contour = graph.GetRoot().FindChild('cmt_toon_contour')
                    contour.GetInputs().FindChild(toon.PREFIX+'contour.externalenable').SetPortValue(True)
                    for role,value in (('edge_color',maxon.Color(1.,0.,1.)),('edge_alpha',1.),('edge_width',.03)):
                        asset = 'rsuserdatacolor' if role=='edge_color' else 'rsuserdatascalar'
                        graph.GetRoot().FindChild('cmt_morph_'+role).GetInputs().FindChild(toon.PREFIX+asset+'.default').SetPortValue(value)
                    transaction.Commit()
                post[c4d.REDSHIFT_RENDERER_GLOBAL_CONTOUR] = global_material
                if post[c4d.REDSHIFT_RENDERER_GLOBAL_CONTOUR] != global_material:
                    raise AssertionError('Global Contour link rejected')
                for index in range(5):
                    suite.model[ids['MODEL_MATERIAL_LIST']] = index
                    suite.model[ids['MODEL_MATERIAL_EDGE_ENABLED']] = 0
                    suite.model[ids['MODEL_MATERIAL_SPECULAR_COLOR']] = c4d.Vector(.15)
                for device in compute_devices:
                    image(suite.doc,f'character-{multipart}-global-off-{device}',device)
                # Unmanaged control actually proves that the global link draws.
                sphere = c4d.BaseObject(c4d.Osphere)
                sphere[c4d.PRIM_SPHERE_RAD] = .3
                sphere.SetAbsPos(c4d.Vector(1.4,.7,0.))
                suite.doc.InsertObject(sphere)
                sphere.MakeTag(c4d.Tphong)
                for device in compute_devices:
                    image(suite.doc,f'character-{multipart}-global-control-{device}',device)
            finally:
                suite.close()

        for renderer in ('redshift','redshift_toon'):
            if 'actual' not in groups:
                continue
            suite = fixture('actual-'+renderer,renderer=renderer,actual=True)
            try:
                camera,_ = scene_setup(suite.doc,(0.,9.521,-25.356),480,640)
                image(suite.doc,'actual-full-'+renderer,compute_devices[0])
                camera.SetAbsPos(c4d.Vector(0.,4.4,-13.5))
                rd = suite.doc.GetActiveRenderData()
                rd[c4d.RDATA_XRES],rd[c4d.RDATA_YRES] = 320,560
                for device in compute_devices:
                    image(suite.doc,'actual-stockings-'+renderer+'-'+device,device)
            finally:
                suite.close()
        receipt['passed'] = True
        return receipt
    finally:
        for key,_,value in devices:
            prefs[key] = value
        prefs[c4d.PREFS_REDSHIFT_HYBRID_RENDERING],prefs[c4d.PREFS_REDSHIFT_MATPREVIEW_MODE] = previous
        record()
        c4d.documents.KillDocument(guard)
