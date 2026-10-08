"""Run in native Cinema 4D against an imported PMX document (optionally with VMD).

run(source, ids, output, names, displacement) clones the supplied document and
never edits it. `names` maps goal/effector/joint to model bone names. The caller
owns production import, loaded-binary provenance, and MCP execution. Both the
redistributable model.pmx fixture and user-provided models are supported.
Ordinary C4D constraints are the oracle for weighted and masked PSR results.
Set physics_modes=(False, True) for a model whose test limb is IK-owned even
with physics enabled. The tiny fixture has a physics-owned hinge, so its IK
response is tested with physics off. Choose a direction that changes the limb
angle instead of extending an already fully stretched one-link chain.
"""

import json
from pathlib import Path

import c4d


def walk(obj):
    while obj:
        yield obj
        yield from walk(obj.GetDown())
        obj = obj.GetNext()


def evaluate(doc, frame):
    doc.SetTime(c4d.BaseTime(frame, 30))
    doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)


def matrix_values(matrix):
    return [float(x) for v in (matrix.off, matrix.v1, matrix.v2, matrix.v3) for x in (v.x, v.y, v.z)]


def matrix_error(a, b):
    return max(abs(x - y) for x, y in zip(matrix_values(a), matrix_values(b)))


def constraint(bone, target, priority=0, position=True, rotation=True):
    tag = c4d.BaseTag(c4d.Tcaconstraint)
    bone.InsertTag(tag)
    tag[c4d.ID_CA_CONSTRAINT_TAG_PSR] = True
    # Native dynamic row: target, weight, P, S, R.
    tag[10001], tag[10002] = target, 1.0
    tag[10005], tag[10006], tag[10007] = position, False, rotation
    pd = tag[c4d.EXPRESSION_PRIORITY]
    pd.SetPriorityValue(c4d.PRIORITYVALUE_MODE, c4d.CYCLE_EXPRESSION)
    pd.SetPriorityValue(c4d.PRIORITYVALUE_PRIORITY, priority)
    tag[c4d.EXPRESSION_PRIORITY] = pd
    return tag


def run(source, ids, output, names=None, displacement=0.2, direction=(0, 1, 0), physics_modes=(False,)):
    names = names or {"goal": "goal", "effector": "tip", "joint": "root"}
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    result = {"checks": [], "samples": []}
    original_active = c4d.documents.GetActiveDocument()
    completed = False
    offset = c4d.Vector(*direction).GetNormalized() * displacement
    source_pose = [(obj, matrix_values(obj.GetMg()), matrix_values(obj.GetFrozenMln()))
                   for obj in walk(source.GetFirstObject()) if obj.GetTag(1056720)]

    def check(label, value, **evidence):
        result["checks"].append({"name": label, "passed": bool(value), **evidence})

    def clone():
        doc = source.GetClone(c4d.COPYFLAGS_0)
        c4d.documents.InsertBaseDocument(doc)
        model = next(o for o in walk(doc.GetFirstObject()) if o.GetType() == 1056724)
        model[ids["MODEL_PHYSICS_ENABLED"]] = False
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
        bones = {o.GetName(): o for o in walk(model.GetDown()) if o.GetTag(1056720)}
        return doc, model, bones

    def controller(doc, bone):
        target = c4d.BaseObject(c4d.Onull)
        target.SetName("CTRL_native_PSR")
        doc.InsertObject(target)
        target.SetMg(bone.GetMg())
        return target

    try:
        for physics in physics_modes:
            priority_results = []
            for priority in (-100, 0, 100):
                doc, model, bones = clone()
                try:
                    model[ids["MODEL_PHYSICS_ENABLED"]] = physics
                    goal, effector = bones[names["goal"]], bones[names["effector"]]
                    frozen = {name: matrix_values(b.GetFrozenMln()) for name, b in bones.items()}
                    evaluate(doc, 0)
                    target = controller(doc, goal)
                    tag = constraint(goal, target, priority)
                    evaluate(doc, 0)
                    baseline = c4d.Vector(effector.GetMg().off)
                    target.SetAbsPos(target.GetAbsPos() + offset)
                    evaluate(doc, 0)
                    moved = c4d.Vector(effector.GetMg().off)
                    distance = (moved - baseline).GetLength()
                    moved_pose = {name: c4d.Matrix(b.GetMg()) for name, b in bones.items()}
                    label = f"physics={physics},priority={priority}"
                    check(label + "/IK responds", distance > displacement * 0.25, effector_delta=distance)
                    check(label + "/goal follows", matrix_error(goal.GetMg(), target.GetMg()) < 1e-4)
                    for _ in range(5):
                        evaluate(doc, 0)
                    check(label + "/same-frame stable", (effector.GetMg().off - moved).GetLength() < 1e-4)
                    repeat_error = max(matrix_error(b.GetMg(), moved_pose[name]) for name, b in bones.items())
                    check(label + "/whole skeleton stable", repeat_error < 1e-4, error=repeat_error)
                    priority_results.append(matrix_values(effector.GetMg()))
                    for frame in (1, 30, 90, 0):
                        evaluate(doc, frame)
                        check(label + f"/frame {frame}", matrix_error(goal.GetMg(), target.GetMg()) < 1e-4)
                    check(label + "/bind unchanged", all(matrix_values(b.GetFrozenMln()) == frozen[n] for n, b in bones.items()))
                    result["samples"].append({"case": label, "effector_delta": distance,
                                               "effector": matrix_values(effector.GetMg())})
                finally:
                    c4d.documents.KillDocument(doc)
            check(f"physics={physics}/priority equivalence",
                  max(abs(a-b) for row in priority_results[1:] for a, b in zip(row, priority_results[0])) < 1e-4)

        # Same-frame removal must restore the original animation, not the last
        # solved pose. Re-enable each time so every transition starts driven.
        doc, model, bones = clone()
        try:
            goal, effector = bones[names["goal"]], bones[names["effector"]]
            evaluate(doc, 30)
            baseline_goal, baseline_effector = c4d.Matrix(goal.GetMg()), c4d.Matrix(effector.GetMg())
            target = controller(doc, goal)
            target.SetAbsPos(target.GetAbsPos() + offset)
            tag = constraint(goal, target)
            for transition in ("disable", "missing target", "zero weight", "delete", "undo"):
                evaluate(doc, 30)
                if transition == "disable":
                    tag[c4d.EXPRESSION_ENABLE] = False
                elif transition == "missing target":
                    tag[10001] = None
                elif transition == "zero weight":
                    tag[c4d.ID_CA_CONSTRAINT_TAG_PSR_TWEIGHT] = 0.0
                elif transition == "delete":
                    tag.Remove()
                else:
                    doc.StartUndo()
                    doc.AddUndo(c4d.UNDOTYPE_CHANGE, tag)
                    tag[c4d.EXPRESSION_ENABLE] = False
                    doc.EndUndo()
                evaluate(doc, 30)
                check(transition + "/restore animation", matrix_error(goal.GetMg(), baseline_goal) < 1e-4
                      and matrix_error(effector.GetMg(), baseline_effector) < 1e-4)
                if transition == "delete":
                    tag = constraint(goal, target)
                elif transition == "undo":
                    doc.DoUndo()
                    tag = goal.GetTag(c4d.Tcaconstraint)
                else:
                    tag[c4d.EXPRESSION_ENABLE] = True
                    tag[10001] = target
                    tag[c4d.ID_CA_CONSTRAINT_TAG_PSR_TWEIGHT] = 1.0
                evaluate(doc, 30)
                check(transition + "/resume driven", matrix_error(goal.GetMg(), target.GetMg()) < 1e-4
                      and (effector.GetMg().off - baseline_effector.off).GetLength() > displacement * 0.25)

            # Saved/reloaded and copied object trees must resolve their own links.
            axis = max(range(3), key=lambda index: abs(offset[index]))
            component = (c4d.VECTOR_X, c4d.VECTOR_Y, c4d.VECTOR_Z)[axis]
            did = c4d.DescID(c4d.DescLevel(c4d.ID_BASEOBJECT_REL_POSITION, c4d.DTYPE_VECTOR, 0),
                             c4d.DescLevel(component, c4d.DTYPE_REAL, 0))
            track = c4d.CTrack(target, did)
            target.InsertTrackSorted(track)
            curve = track.GetCurve()
            for frame, x in ((0, target.GetRelPos()[axis] - offset[axis]), (30, target.GetRelPos()[axis])):
                key = curve.AddKey(c4d.BaseTime(frame, 30))["key"]
                key.SetValue(curve, x)
                key.SetInterpolation(curve, c4d.CINTERPOLATION_LINEAR)
            scene_path = output / "native_psr_keyframed.c4d"
            check("save", c4d.documents.SaveDocument(doc, str(scene_path), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT))
            for kind in ("clone", "reload"):
                copied = doc.GetClone(c4d.COPYFLAGS_0) if kind == "clone" else c4d.documents.LoadDocument(
                    str(scene_path), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
                assert copied is not None
                c4d.documents.InsertBaseDocument(copied)
                try:
                    objects = list(walk(copied.GetFirstObject()))
                    copied_goal = next(o for o in objects if o.GetName() == names["goal"] and o.GetTag(1056720))
                    copied_target = next(o for o in objects if o.GetName() == "CTRL_native_PSR")
                    check(kind + "/own link", copied_goal.GetTag(c4d.Tcaconstraint)[10001] == copied_target)
                    for frame in (0, 15, 30, 0):
                        evaluate(copied, frame)
                        evaluate(doc, frame)
                        copied_effector = next(o for o in objects if o.GetName() == names["effector"] and o.GetTag(1056720))
                        check(kind + f"/frame {frame}", matrix_error(copied_goal.GetMg(), copied_target.GetMg()) < 1e-4
                              and matrix_error(copied_effector.GetMg(), effector.GetMg()) < 1e-4)
                finally:
                    c4d.documents.KillDocument(copied)
        finally:
            c4d.documents.KillDocument(doc)

        # Compare native constraints on a plain joint with identical frozen and
        # relative baseline. Mixed channels, weights and masks stay C4D-owned.
        for position, rotation, weight, mask in ((True, False, 1.0, False), (False, True, 1.0, False),
                                                  (True, True, 0.5, False), (True, True, 1.0, True)):
            doc, model, bones = clone()
            try:
                bone = bones[names["joint"]]
                evaluate(doc, 30)
                target = controller(doc, bone)
                target.SetAbsPos(target.GetAbsPos() + c4d.Vector(displacement, displacement / 2, 0))
                target.SetAbsRot(target.GetAbsRot() + c4d.Vector(0.15, 0.1, 0.25))
                native = c4d.BaseObject(c4d.Ojoint)
                doc.InsertObject(native, bone.GetUp())
                native.SetFrozenPos(bone.GetFrozenPos())
                native.SetFrozenRot(bone.GetFrozenRot())
                native.SetFrozenScale(bone.GetFrozenScale())
                baseline = c4d.Matrix(bone.GetRelMl())
                for obj in (bone, native):
                    tag = constraint(obj, target, position=position, rotation=rotation)
                    tag[c4d.ID_CA_CONSTRAINT_TAG_PSR_TWEIGHT] = weight
                    if mask:
                        tag[c4d.ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_P_Y] = False
                        tag[c4d.ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_R_Z] = False
                for iteration in range(3):
                    native.SetRelMl(baseline)
                    evaluate(doc, 30)
                    error = matrix_error(bone.GetMg(), native.GetMg())
                    check(f"native oracle/P={position},R={rotation},weight={weight},mask={mask}/{iteration}", error < 1e-4, error=error)
            finally:
                c4d.documents.KillDocument(doc)
        check("source document unchanged", all(matrix_values(obj.GetMg()) == world
              and matrix_values(obj.GetFrozenMln()) == frozen for obj, world, frozen in source_pose))
        completed = True
    finally:
        c4d.documents.SetActiveDocument(original_active)
        result["passed"] = completed and bool(result["checks"]) and all(row["passed"] for row in result["checks"])
        (output / "native-psr-results.json").write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    return result
