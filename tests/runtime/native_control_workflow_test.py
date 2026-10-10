"""Exercise animator controls in the loaded plugin, in a private source clone.

Use an imported PMX document, and repeat with VMD and a transformed model root.
Receipts and saved fixture documents belong in a caller-owned temporary folder.
"""
import json
from pathlib import Path
import c4d


def walk(obj):
    while obj:
        yield obj
        yield from walk(obj.GetDown())
        obj = obj.GetNext()


def matrix_error(a, b):
    return max((getattr(a, component) - getattr(b, component)).GetLength()
               for component in ('off', 'v1', 'v2', 'v3'))


def run(source, ids, output, frame=0):
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    original = c4d.documents.GetActiveDocument()
    doc = source.GetClone(c4d.COPYFLAGS_0)
    c4d.documents.InsertBaseDocument(doc)
    c4d.documents.SetActiveDocument(doc)
    result = {'frame': frame, 'checks': []}

    def check(name, passed, **evidence):
        result['checks'].append(dict(name=name, passed=bool(passed), **evidence))

    def evaluate():
        doc.SetTime(c4d.BaseTime(frame, doc.GetFps()))
        # Additional passes test the held-input contract as well as dependencies.
        for _ in range(3):
            doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)

    def pose(chain):
        return {name: bones[name].GetMg() for name in chain}

    def pose_error(expected):
        return max(matrix_error(matrix, bones[name].GetMg())
                   for name, matrix in expected.items())

    try:
        model = next(o for o in walk(doc.GetFirstObject()) if o.GetType() == 1056724)
        model[ids['MODEL_PHYSICS_ENABLED']] = False
        model[ids['MODEL_MODE']] = ids['MODEL_MODE_ANIM']
        c4d.CallButton(model, ids['MODEL_CONTROLS_CREATE'])
        evaluate()
        bones = {o.GetName(): o for o in walk(doc.GetFirstObject()) if o.GetTag(1056720)}
        control = lambda name: bones[name].GetTag(1056720)[ids['PMX_BONE_CONTROL_LINK']]
        named = lambda name: next(o for o in walk(doc.GetFirstObject()) if o.GetName() == name)
        extras = [named(side + suffix) for side in ('左', '右')
                  for suffix in ('手IK_ctrl', '腕方向_ctrl', '膝方向_ctrl')]
        check('extra_handle_coverage', len(extras) == 6)
        for side in ('左','右'):
            length = (bones[side+'ひじ'].GetMg().off-bones[side+'腕'].GetMg().off).GetLength() + (bones[side+'手首'].GetMg().off-bones[side+'ひじ'].GetMg().off).GetLength()
            goal = named(side+'手IK_ctrl')
            width = goal.GetRad().x*goal.GetMg().v1.GetLength()*2
            check(side+'_goal_size_matches_limb', width < length*0.12, width=width, limb_length=length)
        check('fingers_generated', all(control(side + finger + digit)
              for side in ('左', '右') for finger, digits in
              [('親指', '０１２'), ('人指', '１２３'), ('中指', '１２３'),
               ('薬指', '１２３'), ('小指', '１２３')] for digit in digits))
        count = len(list(walk(doc.GetFirstObject())))
        c4d.CallButton(model, ids['MODEL_CONTROLS_CREATE'])
        evaluate()
        check('refresh_is_idempotent', len(list(walk(doc.GetFirstObject()))) == count)

        # Groups and solo affect native presentation and native selection together.
        model[ids['MODEL_CONTROLS_SOLO']] = ids['MODEL_CONTROLS_SOLO_FACE']
        evaluate()
        c4d.CallButton(model, ids['MODEL_CONTROLS_SELECT'])
        selected = doc.GetActiveObjects(c4d.GETACTIVEOBJECTFLAGS_NONE)
        check('face_solo_selection', len(selected) > 0 and all(
              any(token in o.GetName() for token in ('目', '頭', 'メガネ')) for o in selected),
              names=[o.GetName() for o in selected])
        model[ids['MODEL_CONTROLS_FACE']] = False
        evaluate()
        c4d.CallButton(model, ids['MODEL_CONTROLS_SELECT'])
        check('disabled_solo_is_empty', not doc.GetActiveObjects(c4d.GETACTIVEOBJECTFLAGS_NONE))
        model[ids['MODEL_CONTROLS_FACE']] = True
        model[ids['MODEL_CONTROLS_SOLO']] = 0
        evaluate()

        for side, side_id in (('左', 'L'), ('右', 'R')):
            for limb, chain, goal_name in (
                    ('ARM', [side+'腕', side+'ひじ', side+'手首'], side+'手IK_ctrl'),
                    ('LEG', [side+'足', side+'ひざ', side+'足首'], side+'足ＩＫ_ctrl')):
                label = limb + '_' + side_id
                parameter = ids['MODEL_CONTROLS_' + label + '_MODE']
                evaluate()
                baseline = pose(chain)
                model[parameter] = ids['MODEL_CONTROLS_LIMB_IK']
                evaluate()
                error = pose_error(baseline)
                check(label+'_switch_to_ik_matches', error < 0.02, error=error)
                goal = named(goal_name)
                target = goal.GetMg()
                target.off += c4d.Vector(0, 5, -4)
                goal.SetMg(target)
                evaluate()
                posed = pose(chain)
                displacement = (bones[chain[-1]].GetMg().off-baseline[chain[-1]].off).GetLength()
                target_error = (bones[chain[-1]].GetMg().off-goal.GetMg().off).GetLength()
                check(label+'_goal_moves_effector', displacement > 1, displacement=displacement)
                check(label+'_reachable_target', target_error < 0.02, error=target_error)
                evaluate()
                check(label+'_held_input_stable', pose_error(posed) < 0.001, error=pose_error(posed))
                # Hidden FK inputs must not compete with explicit IK.
                fk = control(chain[0])
                fk.SetRelRot(c4d.Vector(0.2, 0.1, 0.15))
                evaluate()
                check(label+'_inactive_fk_ignored', pose_error(posed) < 0.001)
                fk.SetRelRot(c4d.Vector())
                for iteration in range(3):
                    before = pose(chain)
                    model[parameter] = ids['MODEL_CONTROLS_LIMB_FK']
                    evaluate()
                    error = pose_error(before)
                    check(label+'_to_fk_'+str(iteration), error < 0.02, error=error)
                    model[parameter] = ids['MODEL_CONTROLS_LIMB_IK']
                    evaluate()
                    error = pose_error(before)
                    check(label+'_back_ik_'+str(iteration), error < 0.02, error=error)
                c4d.CallButton(model, ids['MODEL_CONTROLS_CREATE'])
                evaluate()
                check(label+'_refresh_keeps_pose', pose_error(before) < 0.02)

        # New handles use native relative tracks and participate in Undo.
        doc.SetActiveObject(extras[0], c4d.SELECTION_NEW)
        c4d.CallButton(model, ids['MODEL_CONTROLS_KEY_SELECTED'])
        tracks = extras[0].GetCTracks()
        check('goal_native_keys', len(tracks) == 6 and all(t.GetCurve().GetKeyCount() == 1 for t in tracks))
        doc.DoUndo()
        check('goal_key_undo', not extras[0].GetCTracks())
        before = extras[0].GetRelMl()
        c4d.CallButton(model, ids['MODEL_CONTROLS_RESET_SELECTED'])
        check('reset_selected_neutral', matrix_error(extras[0].GetRelMl(), c4d.Matrix()) < 1e-8)
        doc.DoUndo()
        extras[0] = named('左手IK_ctrl')
        check('reset_undo', matrix_error(extras[0].GetRelMl(), before) < 1e-8,
              error=matrix_error(extras[0].GetRelMl(), before),
              before=str(before), after=str(extras[0].GetRelMl()))
        model[ids['MODEL_CONTROLS_SOLO']] = ids['MODEL_CONTROLS_SOLO_ARM_L']
        model[ids['MODEL_CONTROLS_FINGERS']] = False
        evaluate()
        c4d.CallButton(model, ids['MODEL_CONTROLS_KEY_SELECTED'])
        original_goal_keys = [t.GetCurve().GetKey(0).GetValue() for t in extras[0].GetCTracks()]
        frame += 10
        evaluate()
        model[ids['MODEL_CONTROLS_ARM_L_MODE']] = ids['MODEL_CONTROLS_LIMB_FK']
        evaluate()
        fk = control('左腕')
        doc.SetActiveObject(fk, c4d.SELECTION_NEW)
        fk.SetRelRot(fk.GetRelRot()+c4d.Vector(0.1,0.05,0))
        c4d.CallButton(model, ids['MODEL_CONTROLS_KEY_SELECTED'])
        evaluate()
        check('fk_native_keys', len(fk.GetCTracks()) == 6)
        keyed_pose = pose(['左腕','左ひじ','左手首'])
        model[ids['MODEL_CONTROLS_ARM_L_MODE']] = ids['MODEL_CONTROLS_LIMB_IK']
        evaluate()
        check('keyed_switch_matches', pose_error(keyed_pose) < 0.02, error=pose_error(keyed_pose))
        check('match_preserves_other_keys', original_goal_keys == [t.GetCurve().GetKey(0).GetValue() for t in extras[0].GetCTracks()])
        check('match_inserts_current_key', all(t.GetCurve().GetKeyCount() == 2 for t in extras[0].GetCTracks()))
        doc.DoUndo()
        evaluate()
        check('switch_undo_mode', model[ids['MODEL_CONTROLS_ARM_L_MODE']] == ids['MODEL_CONTROLS_LIMB_FK'])
        check('switch_undo_pose', pose_error(keyed_pose) < 0.02, error=pose_error(keyed_pose))
        check('switch_undo_keys', all(t.GetCurve().GetKeyCount() == 1 for t in extras[0].GetCTracks()))
        model[ids['MODEL_CONTROLS_ARM_L_MODE']] = ids['MODEL_CONTROLS_LIMB_IK']
        evaluate()
        saved_pose = pose(['左腕','左ひじ','左手首','左足','左ひざ','左足首'])
        path = output/'workflow.c4d'
        check('save', c4d.documents.SaveDocument(doc, str(path), c4d.SAVEDOCUMENTFLAGS_0, c4d.FORMAT_C4DEXPORT))
        loaded = c4d.documents.LoadDocument(str(path), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
        check('reload', loaded is not None)
        if loaded:
            c4d.documents.InsertBaseDocument(loaded)
            saved_model = next(o for o in walk(loaded.GetFirstObject()) if o.GetType() == 1056724)
            saved_goal = next(o for o in walk(loaded.GetFirstObject()) if o.GetName() == '左手IK_ctrl')
            saved_upper = next(o for o in walk(loaded.GetFirstObject()) if o.GetName() == '左腕' and o.GetTag(1056720))
            check('settings_persist', saved_model[ids['MODEL_CONTROLS_SOLO']] == 4 and not saved_model[ids['MODEL_CONTROLS_FINGERS']])
            check('goal_links_persist', saved_upper.GetTag(1056720)[4900] == saved_goal)
            check('goal_tracks_persist', len(saved_goal.GetCTracks()) == 6)
            c4d.documents.SetActiveDocument(loaded)
            loaded.SetTime(c4d.BaseTime(frame, loaded.GetFps()))
            for _ in range(3): loaded.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_0)
            saved_bones = {o.GetName():o for o in walk(loaded.GetFirstObject()) if o.GetTag(1056720)}
            reload_error = max(matrix_error(matrix, saved_bones[name].GetMg()) for name,matrix in saved_pose.items())
            check('reload_pose', reload_error < 0.02, error=reload_error)
            c4d.documents.SetActiveDocument(doc)
            c4d.documents.KillDocument(loaded)
    finally:
        result['passed'] = bool(result['checks']) and all(row['passed'] for row in result['checks'])
        (output/'receipt.json').write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding='utf8')
        c4d.documents.SetActiveDocument(original)
        c4d.documents.KillDocument(doc)
    return result
