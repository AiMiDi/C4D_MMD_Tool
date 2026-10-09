"""Run in an owned, freshly imported PMX document (regression bridge enabled).

Checks real spline positions and the SceneHook cursor callback without moving
the operating-system pointer. A captured tooltip still needs UI inspection.
"""
import json
from pathlib import Path

import c4d


def walk(obj):
    while obj:
        yield obj
        yield from walk(obj.GetDown())
        obj = obj.GetNext()


def run(doc, ids, output):
    result = {"checks": []}
    model = next(o for o in walk(doc.GetFirstObject()) if o.GetType() == 1056724)
    rows = {}
    for bone in walk(model.GetDown()):
        tag = bone.GetTag(1056720)
        if tag and tag[ids["PMX_BONE_CONTROL_LINK"]]:
            rows[bone.GetName()] = (bone, tag, tag[ids["PMX_BONE_CONTROL_LINK"]])

    def check(name, passed, **evidence):
        result["checks"].append({"name": name, "passed": bool(passed), **evidence})

    def evaluate():
        doc.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_0)

    def visible():
        return sum(control.GetEditorMode() != c4d.MODE_OFF for _, _, control in rows.values())

    def center(control):
        points = control.GetAllPoints()[:control.GetSegment(0)["cnt"]-1]
        return control.GetMg() * (sum(points, c4d.Vector()) / len(points))

    def hint(point):
        hook = doc.FindSceneHook(1057017)
        hook[1000000], hook[1000001] = 1, 30
        hook[1000030], hook[1000031] = float(point.x), float(point.y)
        hook[1000032] = "unhandled"
        hook.Message(1057017)
        return hook[1000032]

    evaluate()
    eye_midpoint = (rows["左目"][0].GetMg().off + rows["右目"][0].GetMg().off) * 0.5
    inverse_model = ~model.GetMg()
    for name in ("左目", "右目", "両目"):
        bone, _, control = rows[name]
        actual = inverse_model * center(control)
        expected = inverse_model * (eye_midpoint if name == "両目" else bone.GetMg().off)
        check(name + "_fresh_import_pivot", (control.GetMg().off-bone.GetMg().off).GetLength() < 1e-4)
        check(name + "_outline_at_eye_height", abs(actual.y-expected.y) < 1e-5
              and abs(actual.x-expected.x) < 1e-5 and actual.z < expected.z,
              actual=[actual.x, actual.y, actual.z], expected=[expected.x, expected.y, expected.z])

    check("edit_mode_hides_controls", visible() == 0, actual=visible())
    model[ids["MODEL_PHYSICS_ENABLED"]] = False
    model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
    model[ids["MODEL_CONTROLS_DISPLAY"]] = 0
    evaluate()
    check("animation_mode_shows_primary", visible() > 0, actual=visible())
    for name in ("左腕", "右腕", "左ひじ", "右ひじ"):
        control = rows[name][2]
        check(name + "_plain_closed_ring", control.GetSegmentCount() == 1 and
              (control.GetAllPoints()[0]-control.GetAllPoints()[-1]).GetLength() < 1e-5)

    # Isolate an arm from overlapping outlines without changing its rig input.
    control = rows["左腕"][2]
    old_modes = {name: row[2].GetEditorMode() for name, row in rows.items()}
    for _, _, candidate in rows.values():
        candidate.SetEditorMode(c4d.MODE_ON if candidate == control else c4d.MODE_OFF)
    bd = doc.GetActiveBaseDraw()
    camera = bd.GetEditorCamera()
    old_camera = camera.GetMg()
    old_projection = bd[c4d.BASEDRAW_DATA_PROJECTION]
    target = center(control)
    try:
        for projection in (c4d.Pperspective, c4d.Pfront):
            bd[c4d.BASEDRAW_DATA_PROJECTION] = projection
            for distance in (40, 100):
                camera.SetMg(c4d.Matrix(target + c4d.Vector(0, 0, -distance)))
                c4d.DrawViews(c4d.DRAWFLAGS_ONLY_ACTIVE_VIEW | c4d.DRAWFLAGS_NO_THREAD | c4d.DRAWFLAGS_NO_ANIMATION)
                point = bd.WS(control.GetMg() * control.GetAllPoints()[0])
                check(f"hover_{projection}_{distance}", hint(point) == "左腕", returned=hint(point))
        check("empty_view_has_no_hint", hint(c4d.Vector(-100, -100, 0)) == "")
        old_spline_filter = bd[c4d.BASEDRAW_DISPLAYFILTER_SPLINE]
        bd[c4d.BASEDRAW_DISPLAYFILTER_SPLINE] = False
        check("disabled_spline_filter_has_no_hint", hint(point) == "")
        bd[c4d.BASEDRAW_DISPLAYFILTER_SPLINE] = old_spline_filter
        control.SetEditorMode(c4d.MODE_OFF)
        check("hidden_control_has_no_hint", hint(point) == "")
        control.SetEditorMode(c4d.MODE_ON)
        parent = control.GetUp()
        old_parent_mode = parent.GetEditorMode()
        parent.SetEditorMode(c4d.MODE_OFF)
        check("hidden_ancestor_has_no_hint", hint(point) == "")
        parent.SetEditorMode(old_parent_mode)
        _, tag, _ = rows["左腕"]
        old_name_mode = tag[ids["PMX_BONE_NAME_IS"]]
        old_universal_name = tag[ids["PMX_BONE_NAME_UNIVERSAL"]]
        tag[ids["PMX_BONE_NAME_UNIVERSAL"]] = "Left arm hover test"
        tag[ids["PMX_BONE_NAME_IS"]] = ids["PMX_BONE_NAME_IS_UNIVERSAL"]
        check("hover_uses_selected_name", hint(point) == "Left arm hover test", returned=hint(point))
        tag[ids["PMX_BONE_NAME_UNIVERSAL"]] = old_universal_name
        tag[ids["PMX_BONE_NAME_IS"]] = old_name_mode
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
        evaluate()
        check("edit_mode_has_no_hint", hint(point) == "")
    finally:
        camera.SetMg(old_camera)
        bd[c4d.BASEDRAW_DATA_PROJECTION] = old_projection
        for name, mode in old_modes.items():
            rows[name][2].SetEditorMode(mode)

    for display in (0, 1, 2):
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
        model[ids["MODEL_CONTROLS_DISPLAY"]] = display
        evaluate()
        count = visible()
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
        evaluate()
        check(f"edit_hides_setting_{display}", visible() == 0)
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
        evaluate()
        check(f"animation_restores_setting_{display}", visible() == count
              and model[ids["MODEL_CONTROLS_DISPLAY"]] == display, expected=count, actual=visible())

    result["passed"] = all(item["passed"] for item in result["checks"])
    output = Path(output)
    output.mkdir(parents=True, exist_ok=True)
    (output/"interaction-receipt.json").write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    return result
