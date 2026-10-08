"""Native C4D presentation regression; run against an imported PMX document.

The caller owns import, the loaded plugin build, and viewport evidence. This
suite clones the source, exercises real description parameters and Undo, and
leaves the source untouched. It does not substitute for visual inspection.
"""

import json
from pathlib import Path

import c4d


def walk(obj):
    while obj:
        yield obj
        yield from walk(obj.GetDown())
        obj = obj.GetNext()


def vector_values(vector):
    return [float(vector.x), float(vector.y), float(vector.z)]


def transform_values(obj):
    return [value for vector in (obj.GetRelPos(), obj.GetRelRot(), obj.GetRelScale(),
                                obj.GetFrozenPos(), obj.GetFrozenRot(), obj.GetFrozenScale())
            for value in vector_values(vector)]


def run(source, ids, output):
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    result = {"checks": []}
    original = c4d.documents.GetActiveDocument()
    doc = source.GetClone(c4d.COPYFLAGS_0)
    c4d.documents.InsertBaseDocument(doc)
    c4d.documents.SetActiveDocument(doc)

    def check(name, passed, **evidence):
        result["checks"].append({"name": name, "passed": bool(passed), **evidence})

    def evaluate():
        doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)

    def model_object():
        return next(obj for obj in walk(doc.GetFirstObject()) if obj.GetType() == 1056724)

    def controls():
        rows = {}
        for bone in walk(model_object().GetDown()):
            tag = bone.GetTag(1056720)
            control = tag[ids["PMX_BONE_CONTROL_LINK"]] if tag else None
            if control:
                rows[bone.GetName()] = (bone, tag, control)
        return rows

    def visible_count():
        return sum(control.GetEditorMode() != c4d.MODE_OFF for _, _, control in controls().values())

    def set_display(value):
        model_object()[ids["MODEL_CONTROLS_DISPLAY"]] = value
        evaluate()

    try:
        evaluate()
        model = model_object()
        model[ids["MODEL_PHYSICS_ENABLED"]] = False
        bounds = model.GetDescription(c4d.DESCFLAGS_DESC_0).GetParameter(c4d.DescID(ids["MODEL_CONTROLS_SIZE"]), None)
        check("size_description_bounds", bounds[c4d.DESC_MIN] == 0.25 and bounds[c4d.DESC_MAX] == 3.0)
        bind = {obj.GetName(): [vector_values(obj.GetFrozenPos()), vector_values(obj.GetFrozenRot()), vector_values(obj.GetFrozenScale())]
                for obj in walk(model.GetDown()) if obj.GetTag(1056720)}
        old_transforms = {name: transform_values(row[2]) for name, row in controls().items()}
        c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
        rows = controls()
        expected_primary = sum(bool(tag[ids["PMX_BONE_VISIBLE"]]) and bool(tag[ids["PMX_BONE_ENABLED"]])
                               for _, tag, _ in rows.values())
        check("refresh_preserves_existing_transforms", old_transforms == {
            name: transform_values(rows[name][2]) for name in old_transforms})
        check("generation_is_idempotent", len(rows) == len(old_transforms), count=len(rows))
        check("native_splines_with_axis_marker", all(control.GetSegmentCount() == 2 for _, _, control in rows.values()))
        for display, count, label in [(0, expected_primary, "primary"), (1, len(rows), "all"), (2, 0, "hidden")]:
            set_display(display)
            check("display_" + label, visible_count() == count, actual=visible_count(), expected=count)
        set_display(0)
        c4d.CallButton(model, ids["MODEL_CONTROLS_SELECT"])
        selection = doc.GetActiveObjects(c4d.GETACTIVEOBJECTFLAGS_NONE)
        check("select_visible", len(selection) == expected_primary and all(
            control in selection for _, _, control in rows.values() if control.GetEditorMode() != c4d.MODE_OFF))
        rows["左腕"][2].SetEditorMode(c4d.MODE_OFF)
        c4d.CallButton(model, ids["MODEL_CONTROLS_SELECT"])
        check("select_respects_individual_visibility", rows["左腕"][2] not in doc.GetActiveObjects(c4d.GETACTIVEOBJECTFLAGS_NONE))
        rows["左腕"][2].SetEditorMode(c4d.MODE_ON)

        control = rows["左腕"][2]
        model[ids["MODEL_CONTROLS_SIZE"]] = 1.0
        evaluate()
        radius = control.GetRad().x
        transforms = {name: transform_values(row[2]) for name, row in rows.items()}
        for size in (0.5, 1.5, 2.0):
            model[ids["MODEL_CONTROLS_SIZE"]] = size
            evaluate()
            check("size_" + str(size), abs(control.GetRad().x / radius - size) < 1e-6,
                  parameter=model[ids["MODEL_CONTROLS_SIZE"]], ratio=control.GetRad().x / radius)
        check("size_preserves_transforms", transforms == {name: transform_values(row[2]) for name, row in rows.items()})
        check("presentation_keeps_bind_pose", bind == {
            obj.GetName(): [vector_values(obj.GetFrozenPos()), vector_values(obj.GetFrozenRot()), vector_values(obj.GetFrozenScale())]
            for obj in walk(model.GetDown()) if obj.GetTag(1056720)})
        model[ids["MODEL_CONTROLS_SIZE"]] = 1.0
        evaluate()
        doc.StartUndo()
        doc.AddUndo(c4d.UNDOTYPE_CHANGE_SMALL, model)
        model[ids["MODEL_CONTROLS_SIZE"]] = 1.5
        doc.EndUndo()
        doc.DoUndo()
        evaluate()
        model = model_object()
        rows = controls()
        control = rows["左腕"][2]
        check("undo_size_restores_geometry", abs(control.GetRad().x - radius) < 1e-6
              and model[ids["MODEL_CONTROLS_SIZE"]] == 1.0)
        doc.DoRedo()
        evaluate()
        check("redo_size_restores_geometry", abs(controls()["左腕"][2].GetRad().x / radius - 1.5) < 1e-6)
        model = model_object()
        model[ids["MODEL_CONTROLS_SIZE"]] = 1.0
        set_display(0)
        doc.StartUndo()
        doc.AddUndo(c4d.UNDOTYPE_CHANGE_SMALL, model)
        set_display(2)
        doc.EndUndo()
        doc.DoUndo()
        evaluate()
        check("undo_display_restores_visibility", visible_count() == expected_primary, actual=visible_count())

        model = model_object()
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
        set_display(0)
        rows = controls()
        bone, _, control = rows["左腕"]
        evaluate()
        before = bone.GetMg()
        control.SetRelRot(c4d.Vector(0, 0, 0.18))
        evaluate()
        after = bone.GetMg()
        check("rotation_drives_bone", (after.v1 - before.v1).GetLength() > 0.01)
        posed = transform_values(control)
        c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
        evaluate()
        check("refresh_keeps_unkeyed_pose", transform_values(control) == posed)
        set_display(2)
        check("hiding_keeps_pose", (bone.GetMg().v1 - after.v1).GetLength() < 1e-5)
        set_display(0)

        track_id = c4d.DescID(c4d.DescLevel(c4d.ID_BASEOBJECT_REL_ROTATION, c4d.DTYPE_VECTOR, 0),
                             c4d.DescLevel(c4d.VECTOR_Z, c4d.DTYPE_REAL, 0))
        track = c4d.CTrack(control, track_id)
        control.InsertTrackSorted(track)
        curve = track.GetCurve()
        for frame, value in ((0, 0.18), (30, 0.3)):
            curve.AddKey(c4d.BaseTime(frame, 30))["key"].SetValue(curve, value)
        evaluate()
        posed = transform_values(control)
        c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
        model[ids["MODEL_CONTROLS_SIZE"]] = 1.25
        evaluate()
        check("refresh_keeps_keyframes", curve.GetKeyCount() == 2 and transform_values(control) == posed)
        model[ids["MODEL_CONTROLS_OCCLUDED"]] = False
        set_display(1)
        path = output / "controller-settings-roundtrip.c4d"
        check("save", c4d.documents.SaveDocument(doc, str(path), c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT))
        reloaded = c4d.documents.LoadDocument(str(path), c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
        assert reloaded
        c4d.documents.InsertBaseDocument(reloaded)
        old_doc, doc = doc, reloaded
        c4d.documents.SetActiveDocument(doc)
        evaluate()
        model = model_object()
        check("reload_settings", model[ids["MODEL_CONTROLS_SIZE"]] == 1.25 and
              not model[ids["MODEL_CONTROLS_OCCLUDED"]] and model[ids["MODEL_CONTROLS_DISPLAY"]] == 1)
        check("reload_visibility", visible_count() == len(rows), actual=visible_count())
        check("reload_geometry", abs(controls()["左腕"][2].GetRad().x / radius - 1.25) < 1e-6)
        check("reload_tracks", controls()["左腕"][2].GetFirstCTrack().GetCurve().GetKeyCount() == 2)
        _, tag, original_control = controls()["左腕"]
        external = original_control.GetClone(c4d.COPYFLAGS_0)
        doc.InsertObject(external)
        external.SetName("Artist supplied external control")
        external_points = [vector_values(point) for point in external.GetAllPoints()]
        external_transform = transform_values(external)
        tag[ids["PMX_BONE_CONTROL_LINK"]] = external
        c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
        model[ids["MODEL_CONTROLS_SIZE"]] = 2.0
        check("external_control_not_restyled", external_points == [vector_values(point) for point in external.GetAllPoints()]
              and external_transform == transform_values(external) and external.GetUp() is None)
        c4d.documents.KillDocument(old_doc)
    finally:
        result["passed"] = all(row["passed"] for row in result["checks"])
        (output / "receipt.json").write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
        c4d.documents.SetActiveDocument(original)
        c4d.documents.KillDocument(doc)
    return result
