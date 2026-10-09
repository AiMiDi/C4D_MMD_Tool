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


def control_curve_checks(control):
    """Check actual native sampling, not just per-segment closed metadata."""
    if control.GetSegmentCount() not in (1, 2, 6):
        return {"outline_closed": False, "marker_triangle": False, "marker_at_rim": False}
    outline = control.GetSegment(0)
    points = control.GetAllPoints()
    marker_start = outline["cnt"]
    has_fin = control.GetSegmentCount() == 2 and control.GetSegment(1)["cnt"] == 4
    valid_counts = marker_start >= 4 and len(points) == marker_start + (4 if has_fin else 13 if control.GetSegmentCount() == 6 else 2 if control.GetSegmentCount() == 2 else 0)
    if not valid_counts:
        return {"outline_closed": False, "marker_triangle": False, "marker_at_rim": False}
    tolerance = max(1.0, control.GetRad().GetLength()) * 1e-5
    outline_closed = (points[0] - points[marker_start-1]).GetLength() < tolerance
    outline_closed &= (control.GetSplinePoint(0, 0) - control.GetSplinePoint(1, 0)).GetLength() < tolerance
    if not has_fin:
        return {"outline_closed": bool(outline_closed), "marker_triangle": True, "marker_at_rim": True}
    marker = control.GetSegment(1)
    a, b, tip, close = points[marker_start:]
    center = (a+b)*0.5
    base, height = (b-a).GetLength(), (tip-center).GetLength()
    marker_triangle = marker["cnt"] == 4 and not control[c4d.SPLINEOBJECT_CLOSED] and not marker["closed"]
    marker_triangle &= (a-close).GetLength() < tolerance
    marker_triangle &= (control.GetSplinePoint(0, 1)-control.GetSplinePoint(1, 1)).GetLength() < tolerance
    marker_triangle &= base > tolerance and height > base * 0.5 and height < base
    marker_triangle &= (b-a).Cross(tip-a).GetLength() > base * height * 0.99
    center = (a+b)*0.5
    edge = max(p.x for p in points[:marker_start])
    radius = max(abs(p.y) for p in points[:marker_start])
    gap = center.x - edge
    marker_at_rim = radius * 0.05 < gap < radius * 0.25 and abs(center.y) < tolerance
    marker_at_rim &= abs(center.z-points[0].z) < tolerance and tip.z > center.z
    marker_at_rim &= max(abs(p.x-center.x) for p in (a,b,tip)) < tolerance
    marker_at_rim &= abs(tip.y-center.y) < tolerance
    return {"outline_closed": bool(outline_closed), "marker_triangle": bool(marker_triangle),
            "marker_at_rim": bool(marker_at_rim)}


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
        # Explicit fixture expectations, independent of the production classifier.
        secondary_names = {side + name for side in ("左", "右") for name in ("腕捩", "手捩", "ひじ補助")}
        secondary_names.update(("+左ひじ補助", "+右ひじ補助", "メガネ"))
        expected_primary = sum(bool(tag[ids["PMX_BONE_VISIBLE"]]) and bool(tag[ids["PMX_BONE_ENABLED"]])
                               and name not in secondary_names for name, (_, tag, _) in rows.items())
        check("refresh_preserves_existing_transforms", old_transforms == {
            name: transform_values(rows[name][2]) for name in old_transforms})
        first_count = len(rows)
        c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
        rows = controls()
        check("generation_is_idempotent", len(rows) == first_count and set(old_transforms).issubset(rows), count=len(rows))
        check("rotation_rings_have_fins", all(rows[side + name][2].GetSegmentCount() == 2
                                              for side in ("左", "右") for name in ("腕", "ひじ")))
        check("hand_controls_are_wire_boxes", all(rows[side + "手首"][2].GetSegmentCount() == 6
              and rows[side + "手首"][2].GetPointCount() == 18 for side in ("左", "右")))
        body_names = ("全ての親", "センター", "グルーブ", "上半身", "上半身2", "下半身", "首", "頭")
        check("central_body_coverage", all(name in rows for name in body_names), missing=[name for name in body_names if name not in rows])
        check("central_body_rings", all(rows[name][2].GetSegmentCount() == 1
              and rows[name][2].GetSegment(0)["cnt"] == 49 for name in body_names if name in rows and name not in ("センター", "下半身")))
        check("central_purpose_shapes", rows["センター"][2].GetSegment(0)["cnt"] == 25
              and rows["腰"][2].GetSegment(0)["cnt"] == 4
              and rows["下半身"][2].GetSegment(0)["cnt"] == 4
              and rows["センター"][2].GetRad().x > rows["グルーブ"][2].GetRad().x * 1.1)
        check("shoulders_have_offset_handles", all(rows[side + "肩"][2].GetSegmentCount() == 2
              and rows[side + "肩"][2].GetSegment(1)["cnt"] == 2 for side in ("左", "右")))
        check("eyes_have_small_planar_handles", all(rows[name][2].GetSegmentCount() == 1
              and rows[name][2].GetRad().x < rows["頭"][2].GetRad().x for name in ("左目", "右目", "両目")))
        geometry = [control_curve_checks(control) for _, _, control in rows.values()]
        check("native_outline_closed", all(item["outline_closed"] for item in geometry))
        check("native_marker_triangle", all(item["marker_triangle"] for item in geometry))
        check("native_marker_at_rim", all(item["marker_at_rim"] for item in geometry))
        foot_controls = [rows[side + suffix][2] for side in ("左", "右")
                         for suffix in ("足ＩＫ", "つま先ＩＫ", "足IK親")]
        check("ik_outlines_stay_planar_without_fins", all(control.GetSegmentCount() == 1
              and max(p.z for p in control.GetAllPoints())-min(p.z for p in control.GetAllPoints()) < 1e-6
              for control in foot_controls))
        check("foot_frames_are_narrow", all(rows[side + name][2].GetRad().x < rows[side + name][2].GetRad().y * 0.55
              for side in ("左", "右") for name in ("足ＩＫ", "足IK親")))
        for display, count, label in [(0, expected_primary, "primary"), (1, len(rows), "all"), (2, 0, "hidden")]:
            set_display(display)
            check("display_" + label, visible_count() == count, actual=visible_count(), expected=count)
        set_display(0)
        c4d.CallButton(model, ids["MODEL_CONTROLS_SELECT"])
        check("primary_hides_auxiliary_and_twist", all(rows[name][2].GetEditorMode() == c4d.MODE_OFF
                                                      for name in secondary_names))
        check("primary_keeps_main_elbows", all(rows[side + "ひじ"][2].GetEditorMode() != c4d.MODE_OFF
                                               for side in ("左", "右")))
        for side in ("左", "右"):
            elbow = rows[side + "ひじ"][2]
            helper = rows["+" + side + "ひじ補助"][2]
            twist = rows[side + "腕捩"][2]
            arm = rows[side + "腕"][2]
            check(side + "_helper_is_subordinate", helper.GetRad().x < elbow.GetRad().x * 0.5,
                  ratio=helper.GetRad().x / elbow.GetRad().x)
            check(side + "_twist_is_subordinate", twist.GetRad().x < arm.GetRad().x * 0.4,
                  ratio=twist.GetRad().x / arm.GetRad().x)
            radii = [rows[side + name][2].GetRad().x for name in ("腕", "ひじ", "手首")]
            check(side + "_joint_size_hierarchy", all(a > b for a, b in zip(radii, radii[1:])), radii=radii)
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
        for name, translation in (("センター", True), ("上半身", False), ("頭", False)):
            body_bone, _, body_control = rows[name]
            evaluate()
            before = body_bone.GetMg()
            old_pos, old_rot = body_control.GetRelPos(), body_control.GetRelRot()
            if translation:
                body_control.SetRelPos(old_pos + c4d.Vector(1.5, 0, 0))
            else:
                body_control.SetRelRot(old_rot + c4d.Vector(0, 0, 0.12))
            evaluate()
            after = body_bone.GetMg()
            changed = (after.off-before.off).GetLength() if translation else (after.v1-before.v1).GetLength()
            check(name + "_control_drives_bone", changed > 0.01)
            body_control.SetRelPos(old_pos)
            body_control.SetRelRot(old_rot)
            evaluate()
        for name in ("左肩", "両目"):
            handle = rows[name][2]
            points_before = [vector_values(p) for p in handle.GetAllPoints()]
            old_rot = handle.GetRelRot()
            handle.SetRelRot(old_rot + c4d.Vector(0.08, 0.04, 0))
            evaluate()
            c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
            evaluate()
            differences = [abs(a-b) for old, new in zip(points_before, [vector_values(p) for p in handle.GetAllPoints()])
                           for a,b in zip(old,new)]
            check(name + "_layout_stays_in_frozen_frame", max(differences) < 1e-5
                  and (handle.GetRelRot()-old_rot).GetLength() > 0.01)
            handle.SetRelRot(old_rot)
            evaluate()
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
        # Hidden helper animation remains authored and linked after restyling.
        helper = rows["+左ひじ補助"][2]
        helper_track = c4d.CTrack(helper, track_id)
        helper.InsertTrackSorted(helper_track)
        helper_curve = helper_track.GetCurve()
        for frame, value in ((0, 0.025), (30, 0.04)):
            helper_curve.AddKey(c4d.BaseTime(frame, 30))["key"].SetValue(helper_curve, value)
        evaluate()
        helper_pose = transform_values(helper)
        helper_bone_matrix = rows["+左ひじ補助"][0].GetMg()
        c4d.CallButton(model, ids["MODEL_CONTROLS_CREATE"])
        set_display(1)
        check("helper_refresh_preserves_identity_animation", controls()["+左ひじ補助"][2] == helper
              and helper_curve.GetKeyCount() == 2 and transform_values(helper) == helper_pose)
        set_display(0)
        check("hidden_helper_keeps_pose", helper.GetEditorMode() == c4d.MODE_OFF
              and (rows["+左ひじ補助"][0].GetMg().v1 - helper_bone_matrix.v1).GetLength() < 1e-5)
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
        helper = controls()["+左ひじ補助"][2]
        check("reload_helper_tracks", helper.GetFirstCTrack().GetCurve().GetKeyCount() == 2)
        set_display(0)
        check("reload_primary_hides_helpers", helper.GetEditorMode() == c4d.MODE_OFF
              and controls()["左ひじ"][2].GetEditorMode() != c4d.MODE_OFF)
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
