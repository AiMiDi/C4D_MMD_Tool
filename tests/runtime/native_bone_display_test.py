"""Focused native checks for BoneManager's stored display choice.

Call run(suite, import_model=None) inside Cinema 4D. A normal Release caller
supplies import_model(suite, path), which uses the production PMX importer and
may return its BaseObject. The optional legacy Suite bridge is only for a build
with runtime regression enabled. The caller owns original-document restoration
and receipt/loaded-module identity. This test never changes a global layer/tag.
"""

import math

MODEL_ID = 1056724
MANAGER_ID = 1057944
TAG_ID = 1056720


def _new_model(suite, import_model):
    suite.close()
    suite.new_document("bone display")
    if import_model is None:
        suite.call("import_model", suite.fixture("model.pmx"))
        suite.model = suite.doc.GetActiveObject()
    else:
        imported = import_model(suite, suite.fixture("model.pmx"))
        suite.model = imported if imported is not None else suite.doc.GetActiveObject()
    if suite.model is None or suite.model.GetType() != MODEL_ID:
        raise AssertionError("PMX import did not create the native MMD model")
    suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False


def _manager(suite):
    managers = [node for node in suite.walk(suite.model.GetDown()) if node.GetType() == MANAGER_ID]
    if len(managers) != 1:
        raise AssertionError("Expected one BoneManager for the owned model")
    return managers[0]


def _vectors(matrix):
    result = [float(value) for vector in (matrix.off, matrix.v1, matrix.v2, matrix.v3)
              for value in (vector.x, vector.y, vector.z)]
    if any(not math.isfinite(value) for value in result):
        raise AssertionError("Changing display produced a non-finite bone/control matrix")
    return result


def snapshot(suite):
    c4d, ids = suite.c4d, suite.ids
    manager = _manager(suite)
    bones = []
    for bone in suite.walk(manager.GetDown()):
        tag = bone.GetTag(TAG_ID)
        if tag is None:
            continue
        control = tag[ids["PMX_BONE_CONTROL_LINK"]]
        bones.append({"name": bone.GetName(), "editor": bone.GetEditorMode(), "render": bone.GetRenderMode(),
                      "joint_display": int(bone[c4d.ID_CA_JOINT_OBJECT_JOINT_DISPLAY]),
                      "bone_display": int(bone[c4d.ID_CA_JOINT_OBJECT_BONE_DISPLAY]),
                      "world": _vectors(bone.GetMg()), "frozen": _vectors(bone.GetFrozenMln()),
                      "flags": {name: bool(tag[ids[name]]) for name in
                                ("PMX_BONE_TRANSLATABLE", "PMX_BONE_ROTATABLE", "PMX_BONE_VISIBLE",
                                 "PMX_BONE_ENABLED", "PMX_BONE_IS_IK")},
                      "control": None if control is None else {"editor": control.GetEditorMode(),
                                  "render": control.GetRenderMode(), "world": _vectors(control.GetMg()),
                                  "owned_document": control.GetDocument() == suite.doc}})
    mesh_points = []
    for node in suite.walk(suite.model.GetDown()):
        if isinstance(node, c4d.PolygonObject):
            evaluated = node.GetDeformCache() or node.GetCache() or node
            if not isinstance(evaluated, c4d.PolygonObject):
                evaluated = node
            mesh_points.extend([[float(point.x), float(point.y), float(point.z)] for point in evaluated.GetAllPoints()])
    return {"selected_display": int(manager[ids["BONE_DISPLAY_TYPE"]]),
            "manager_editor": manager.GetEditorMode(), "manager_render": manager.GetRenderMode(),
            "bone_mode": int(manager[ids["BONE_MODE"]]), "bones": bones, "mesh_points": mesh_points}


def _assert_display(suite, actual, display, *, require_controls=True):
    c4d, ids = suite.c4d, suite.ids
    if actual["selected_display"] != display:
        raise AssertionError("Applying visibility changed the user's selected display option")
    off = display == ids["BONE_DISPLAY_TYPE_OFF"]
    expected_manager = c4d.MODE_OFF if off else c4d.MODE_UNDEF
    if (actual["manager_editor"], actual["manager_render"]) != (expected_manager, expected_manager):
        raise AssertionError("BoneManager traffic lights disagree with the display selector")
    flag_by_mode = {ids["BONE_DISPLAY_TYPE_MOVABLE"]: "PMX_BONE_TRANSLATABLE",
                    ids["BONE_DISPLAY_TYPE_ROTATABLE"]: "PMX_BONE_ROTATABLE",
                    ids["BONE_DISPLAY_TYPE_VISIBLE"]: "PMX_BONE_VISIBLE",
                    ids["BONE_DISPLAY_TYPE_ENABLED"]: "PMX_BONE_ENABLED",
                    ids["BONE_DISPLAY_TYPE_IK"]: "PMX_BONE_IS_IK"}
    controls = 0
    for bone in actual["bones"]:
        expected_bone = c4d.MODE_UNDEF
        if display in flag_by_mode:
            expected_bone = c4d.MODE_ON if bone["flags"][flag_by_mode[display]] else c4d.MODE_OFF
        if (bone["editor"], bone["render"]) != (expected_bone, expected_bone):
            raise AssertionError("A bone did not receive its manager's selected visibility filter")
        control = bone["control"]
        if control is not None:
            controls += 1
            if not control["owned_document"]:
                raise AssertionError("Visibility synchronization crossed document ownership")
            expected_control = c4d.MODE_OFF if off else c4d.MODE_ON
            if (control["editor"], control["render"]) != (expected_control, expected_control):
                raise AssertionError("Bone controller display disagrees with its manager's selector")
        if display == ids["BONE_DISPLAY_TYPE_CONTROLS"]:
            if bone["joint_display"] != c4d.ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE or bone["bone_display"] != c4d.ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE:
                raise AssertionError("Controls-only mode left joint/bone geometry visible")
        elif bone["flags"]["PMX_BONE_VISIBLE"]:
            if bone["joint_display"] != c4d.ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS or bone["bone_display"] != c4d.ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD:
                raise AssertionError("Restoring bone display failed to restore the joint visual settings")
    if not actual["bones"] or (require_controls and controls == 0):
        raise AssertionError("Fixture must exercise both bones and generated controllers")


def _near(left, right, label):
    if len(left) != len(right) or any(abs(a - b) > 1e-5 for a, b in zip(left, right)):
        raise AssertionError(label + " changed while only the display option changed")


def _assert_pose_unchanged(before, after):
    if [bone["name"] for bone in before["bones"]] != [bone["name"] for bone in after["bones"]]:
        raise AssertionError("Display option changed the owned bone hierarchy")
    for left, right in zip(before["bones"], after["bones"]):
        _near(left["world"], right["world"], "Bone pose")
        _near(left["frozen"], right["frozen"], "Bind pose")
        if left["control"] is not None and right["control"] is not None:
            _near(left["control"]["world"], right["control"]["world"], "Control pose")
    if len(before["mesh_points"]) != len(after["mesh_points"]):
        raise AssertionError("Display option changed mesh topology")
    for left, right in zip(before["mesh_points"], after["mesh_points"]):
        _near(left, right, "Mesh point")


def run(suite, import_model=None):
    c4d, ids = suite.c4d, suite.ids
    _new_model(suite, import_model)
    # Check before ExecutePasses: import defaults must already match the UI.
    imported = snapshot(suite)
    _assert_display(suite, imported, ids["BONE_DISPLAY_TYPE_OFF"], require_controls=False)
    suite.evaluate(0)
    baseline = snapshot(suite)
    _assert_display(suite, baseline, ids["BONE_DISPLAY_TYPE_OFF"], require_controls=False)

    # The maintained tiny PMX has no local/fixed-axis bones. Production control
    # creation intentionally serves only those eligible bones; make one owned
    # fixture bone eligible without changing its bind transform or source input.
    first_bone = next(bone for bone in suite.walk(_manager(suite).GetDown()) if bone.GetTag(TAG_ID))
    first_tag = first_bone.GetTag(TAG_ID)
    first_tag[ids["PMX_BONE_LOCAL_X"]] = c4d.Vector(1., 0., 0.)
    first_tag[ids["PMX_BONE_LOCAL_Z"]] = c4d.Vector(0., 0., 1.)
    first_tag[ids["PMX_BONE_LOCAL_IS_COORDINATE"]] = True
    suite.evaluate(0)
    # Eligibility setup is a separate authoring action, so display-only pose
    # comparisons start after that setup has been evaluated.
    baseline = snapshot(suite)
    manager = _manager(suite)
    manager[ids["BONE_DISPLAY_TYPE"]] = ids["BONE_DISPLAY_TYPE_OFF"]
    manager.Message(c4d.MSG_DESCRIPTION_COMMAND, {"id": c4d.DescID(c4d.DescLevel(ids["BONE_CONTROLS_CREATE_BUTTON"]))})
    controls_refreshed = snapshot(suite)
    _assert_display(suite, controls_refreshed, ids["BONE_DISPLAY_TYPE_OFF"])
    _assert_pose_unchanged(baseline, controls_refreshed)

    results = []
    mode_names = ("ON", "OFF", "MOVABLE", "ROTATABLE", "VISIBLE", "ENABLED", "IK", "CONTROLS")
    for name in mode_names:
        display = ids["BONE_DISPLAY_TYPE_" + name]
        manager = _manager(suite)
        before = snapshot(suite)
        manager[ids["BONE_DISPLAY_TYPE"]] = display
        suite.evaluate(0)
        changed = snapshot(suite)
        _assert_display(suite, changed, display)
        _assert_pose_unchanged(before, changed)
        suite.reopen("bone_display_" + name.lower())
        suite.evaluate(0)
        reopened = snapshot(suite)
        _assert_display(suite, reopened, display)
        _assert_pose_unchanged(changed, reopened)
        results.append({"mode": name, "before_reopen": changed, "after_reopen": reopened})

    _manager(suite)[ids["BONE_DISPLAY_TYPE"]] = ids["BONE_DISPLAY_TYPE_ON"]
    source_document, source_model = suite.doc, suite.model
    source_before = snapshot(suite)
    translator = c4d.AliasTrans()
    if not translator.Init(source_document):
        raise AssertionError("Visibility clone alias translation initialization failed")
    clone = source_document.GetClone(c4d.COPYFLAGS_NONE, translator)
    if clone is None:
        raise AssertionError("Visibility document clone failed")
    suite.register_document(clone, "bone display clone")
    # The clone's CopyTo/menu preparation must not follow untranslated control
    # links into the source; inspect source before translating/inserting clone.
    if snapshot(suite) != source_before:
        raise AssertionError("Clone initialization changed source visibility before AliasTrans")
    translator.Translate(True)
    c4d.documents.InsertBaseDocument(clone)
    try:
        suite.doc = clone
        suite.model = next(node for node in suite.walk(clone.GetFirstObject()) if node.GetType() == MODEL_ID)
        c4d.documents.SetActiveDocument(clone)
        suite.evaluate(0)
        _assert_display(suite, snapshot(suite), ids["BONE_DISPLAY_TYPE_ON"])
        _manager(suite)[ids["BONE_DISPLAY_TYPE"]] = ids["BONE_DISPLAY_TYPE_OFF"]
        suite.evaluate(0)
        clone_off = snapshot(suite)
        _assert_display(suite, clone_off, ids["BONE_DISPLAY_TYPE_OFF"])
        suite.doc, suite.model = source_document, source_model
        if snapshot(suite) != source_before:
            raise AssertionError("Changing a clone's display changed the source bones/controllers")
        _manager(suite)[ids["BONE_DISPLAY_TYPE"]] = ids["BONE_DISPLAY_TYPE_CONTROLS"]
        source_controls = snapshot(suite)
        _assert_display(suite, source_controls, ids["BONE_DISPLAY_TYPE_CONTROLS"])
        suite.doc = clone
        suite.model = next(node for node in suite.walk(clone.GetFirstObject()) if node.GetType() == MODEL_ID)
        if snapshot(suite) != clone_off:
            raise AssertionError("Changing source display changed the clone bones/controllers")
    finally:
        suite.doc, suite.model = source_document, source_model
        c4d.documents.SetActiveDocument(source_document)
        c4d.documents.KillDocument(clone)

    manager = _manager(suite)
    manager[ids["BONE_DISPLAY_TYPE"]] = ids["BONE_DISPLAY_TYPE_OFF"]
    manager.Message(c4d.MSG_DESCRIPTION_COMMAND, {"id": c4d.DescID(c4d.DescLevel(ids["ADD_BONE_BUTTON"]))})
    added = snapshot(suite)
    _assert_display(suite, added, ids["BONE_DISPLAY_TYPE_OFF"])
    suite.model[ids["MODEL_MODE"]] = ids["MODEL_MODE_ANIM"]
    suite.evaluate(0)
    _assert_display(suite, snapshot(suite), ids["BONE_DISPLAY_TYPE_OFF"])
    suite.model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    suite.evaluate(0)
    editable = snapshot(suite)
    _assert_display(suite, editable, ids["BONE_DISPLAY_TYPE_ON"])
    return {"imported_before_evaluation": imported, "controls_refreshed": controls_refreshed,
            "saved_display_modes": results, "clone_display_isolation": True,
            "added_bone_off": added, "explicit_edit_anim_policy_preserved": True,
            "final_edit_display": editable, "native_executed": True,
            "display_changes_preserved_pose_and_mesh": True}
