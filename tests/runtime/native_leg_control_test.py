"""Native Afu lower-body controls: original PMX IK is the solver, not a mock.

The caller supplies an imported source and resource IDs. Each run is private;
repeat against PMX-only and PMX+VMD source documents with the production plugin.
"""
import json
from pathlib import Path
import c4d


def walk(obj):
    while obj:
        yield obj
        yield from walk(obj.GetDown())
        obj = obj.GetNext()


def matrix_values(matrix):
    return [float(x) for v in (matrix.off, matrix.v1, matrix.v2, matrix.v3) for x in (v.x, v.y, v.z)]


def error(a, b):
    return max(abs(x-y) for x, y in zip(matrix_values(a), matrix_values(b)))


def run(source, ids, output, base_frame=0, physics_enabled=False):
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    result = {'checks': [], 'base_frame': base_frame, 'physics_enabled': physics_enabled}
    original = c4d.documents.GetActiveDocument()
    doc = source.GetClone(c4d.COPYFLAGS_0)
    c4d.documents.InsertBaseDocument(doc)
    c4d.documents.SetActiveDocument(doc)

    def check(name, passed, **evidence):
        result['checks'].append(dict(name=name, passed=bool(passed), **evidence))

    def evaluate(frame=None):
        frame = base_frame if frame is None else frame
        doc.SetTime(c4d.BaseTime(frame, 30))
        doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)

    def get_bones():
        return {o.GetName(): o for o in walk(doc.GetFirstObject()) if o.GetTag(1056720)}

    def get_control(bone):
        return bone.GetTag(1056720)[ids['PMX_BONE_CONTROL_LINK']]

    try:
        evaluate()
        model = next(o for o in walk(doc.GetFirstObject()) if o.GetType() == 1056724)
        model[ids['MODEL_PHYSICS_ENABLED']] = physics_enabled
        model[ids['MODEL_MODE']] = ids['MODEL_MODE_ANIM']
        c4d.CallButton(model, ids['MODEL_CONTROLS_CREATE'])
        evaluate()
        bones = get_bones()
        controls = {name: get_control(bone) for name, bone in bones.items() if get_control(bone)}
        required = [side+suffix for side in ('左', '右') for suffix in
                    ('足', 'ひざ', '足首', 'つま先', '足先EX', '足IK親', '足ＩＫ', 'つま先ＩＫ')]
        check('lower_body_coverage', all(name in controls for name in required), total=len(controls), missing=[name for name in required if name not in controls])
        check('deformation_duplicates_excluded', not any(side+suffix+'D' in controls for side in ('左','右') for suffix in ('足','ひざ','足首')))
        # Outline counts include the explicit closing point; do not confuse
        # the orientation fin with the foot/toe/parent silhouette itself.
        check('lower_body_shapes', controls['左足ＩＫ'].GetSegment(0)['cnt'] == 7
              and controls['左つま先ＩＫ'].GetSegment(0)['cnt'] == 27
              and controls['左足IK親'].GetSegment(0)['cnt'] == 33)
        bind = {name: matrix_values(bone.GetFrozenMln()) for name, bone in bones.items()}

        # Moving each native IK target must reach its solver and the deformed
        # limb, and repeated same-frame evaluation must not accumulate input.
        for side in ('左', '右'):
            for suffix, effector in [('足ＩＫ', '足首'), ('つま先ＩＫ', 'つま先'), ('足IK親', '足首')]:
                control, target = controls[side+suffix], bones[side+effector]
                evaluate()
                baseline = target.GetMg()
                control.SetRelPos(c4d.Vector(0, 0, 0.8))
                evaluate()
                moved = target.GetMg()
                displacement = (moved.off-baseline.off).GetLength()
                check(side+suffix+'_drives_limb', displacement > 0.1, displacement=displacement)
                for _ in range(8): evaluate()
                check(side+suffix+'_same_frame_stable', error(moved, target.GetMg()) < 1e-4, error=error(moved,target.GetMg()))
                control.SetRelPos(c4d.Vector())
                evaluate()
                check(side+suffix+'_neutral_recovery', error(baseline, target.GetMg()) < 1e-4, error=error(baseline,target.GetMg()))

            for suffix in ('足','ひざ','足首','足先EX'):
                control, bone = controls[side+suffix], bones[side+suffix]
                baseline = bone.GetMg()
                control.SetRelRot(c4d.Vector(0, 0, 0.22))
                evaluate()
                posed = bone.GetMg()
                check(side+suffix+'_fk_drives_rotation', (posed.v1-baseline.v1).GetLength()+(posed.v2-baseline.v2).GetLength()>0.02)
                for _ in range(8): evaluate()
                check(side+suffix+'_fk_same_frame_stable', error(posed,bone.GetMg()) < 1e-4, error=error(posed,bone.GetMg()))
                c4d.CallButton(model, ids['MODEL_CONTROLS_CREATE'])
                evaluate()
                check(side+suffix+'_refresh_keeps_fk', error(posed,bone.GetMg()) < 1e-4)
                control.SetRelRot(c4d.Vector())
                evaluate()
                check(side+suffix+'_fk_neutral_restores_ik', error(baseline,bone.GetMg()) < 1e-4, error=error(baseline,bone.GetMg()))

        check('bind_unchanged', bind == {name:matrix_values(bone.GetFrozenMln()) for name,bone in bones.items()})
        control=controls['左足ＩＫ']
        track=c4d.CTrack(control,c4d.DescID(c4d.DescLevel(c4d.ID_BASEOBJECT_REL_POSITION,c4d.DTYPE_VECTOR,0),c4d.DescLevel(c4d.VECTOR_Z,c4d.DTYPE_REAL,0)))
        control.InsertTrackSorted(track)
        curve=track.GetCurve()
        for frame,value in [(base_frame,0.0),(base_frame+30,0.8)]:
            curve.AddKey(c4d.BaseTime(frame,30))['key'].SetValue(curve,value)
        evaluate(base_frame+30)
        expected={name:matrix_values(bones[name].GetMg()) for name in required}
        c4d.CallButton(model,ids['MODEL_CONTROLS_CREATE'])
        evaluate(base_frame+30)
        refresh_error=max(max(abs(a-b) for a,b in zip(expected[name],matrix_values(bones[name].GetMg()))) for name in required)
        check('ik_track_refresh', curve.GetKeyCount()==2 and refresh_error<1e-4, error=refresh_error)
        path=output/'leg-ik-keyframed.c4d'
        assert c4d.documents.SaveDocument(doc,str(path),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT)
        reloaded=c4d.documents.LoadDocument(str(path),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
        assert reloaded
        c4d.documents.InsertBaseDocument(reloaded)
        previous,doc=doc,reloaded
        c4d.documents.SetActiveDocument(doc)
        evaluate(base_frame+30)
        bones=get_bones()
        max_error=max(max(abs(a-b) for a,b in zip(expected[name],matrix_values(bones[name].GetMg()))) for name in required)
        check('ik_track_reload',max_error<1e-4,error=max_error)
        check('ik_track_reload_keys',get_control(bones['左足ＩＫ']).GetFirstCTrack().GetCurve().GetKeyCount()==2)
        c4d.documents.KillDocument(previous)

        # Register a visible FK adjustment into native MMD animation, not only
        # C4D controller tracks. The neutralized control must leave its pose.
        model = next(o for o in walk(doc.GetFirstObject()) if o.GetType() == 1056724)
        control = get_control(bones['左足'])
        control.SetRelRot(c4d.Vector(0, 0, 0.22))
        evaluate(base_frame+30)
        registered_pose = bones['左足'].GetMg()
        # The native model command intentionally asks for an animation name
        # when no slot exists. Automation must select a VMD slot beforehand.
        active_slot = model[ids['MODEL_ANIM_LIST']]
        check('registration_fixture_has_active_slot', active_slot is not None and active_slot >= 0, active_slot=active_slot)
        if active_slot is None or active_slot < 0:
            raise RuntimeError('Select an animation slot before the native registration regression.')
        c4d.CallButton(model, ids['MODEL_ANIM_REGISTER_CURRENT_BUTTON'])
        evaluate(base_frame+30)
        check('fk_register_resets_input', control.GetRelRot().GetLength()<1e-6)
        check('fk_register_preserves_pose', error(registered_pose,bones['左足'].GetMg())<1e-4,
              error=error(registered_pose,bones['左足'].GetMg()))
        control.SetRelRot(c4d.Vector(0, 0, 0.1))
        evaluate(base_frame+30)
        edited_pose = bones['左足'].GetMg()
        check('registered_fk_remains_editable', error(registered_pose,edited_pose)>0.01)
        for _ in range(8): evaluate(base_frame+30)
        check('registered_fk_edit_stable', error(edited_pose,bones['左足'].GetMg())<1e-4)
        control.SetRelRot(c4d.Vector())
        evaluate(base_frame+30)
        check('registered_fk_neutral_returns_key', error(registered_pose,bones['左足'].GetMg())<1e-4)
        registered_path=output/'leg-fk-registered.c4d'
        assert c4d.documents.SaveDocument(doc,str(registered_path),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT)
        reloaded=c4d.documents.LoadDocument(str(registered_path),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
        assert reloaded
        c4d.documents.InsertBaseDocument(reloaded)
        previous,doc=doc,reloaded
        c4d.documents.SetActiveDocument(doc)
        evaluate(base_frame+30)
        bones=get_bones()
        check('registered_fk_reload',error(registered_pose,bones['左足'].GetMg())<1e-4)
        c4d.documents.KillDocument(previous)
    finally:
        result['passed']=bool(result['checks']) and all(c['passed'] for c in result['checks'])
        (output/'receipt.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8')
        c4d.documents.SetActiveDocument(original)
        c4d.documents.KillDocument(doc)
    return result
