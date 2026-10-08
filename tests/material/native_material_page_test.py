"""Read a saved model's material page before the RS capability cache is warm.

Run in a fresh task-owned c4dpy process. Production import checks RS capability,
so importing first would hide a graph probe caused by an attribute-page read.
This checks native description/parameter callbacks, not a GUI tab-switch claim.
"""

from pathlib import Path


def run(c4d, scene_path):
    from c4d_runtime_regression import load_resource_ids, loaded_plugin_binary

    ids = load_resource_ids(Path(__file__).resolve().parents[2])
    document = c4d.documents.LoadDocument(str(scene_path),
        c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
    if document is None:
        raise AssertionError("Material-page test scene could not be loaded")
    c4d.documents.InsertBaseDocument(document)
    c4d.documents.SetActiveDocument(document)

    def walk(node):
        while node:
            yield node
            yield from walk(node.GetDown())
            node = node.GetNext()

    model = next(node for node in walk(document.GetFirstObject()) if node.GetType() == 1056724)
    material_count = len(document.GetMaterials())
    status = model[ids["MODEL_MATERIAL_TOON_STATUS"]]
    if "will be checked" not in status:
        raise AssertionError("A fresh material-page read warmed the RS cache: " + status)
    snapshots = []
    fields = ("LINK", "NAME_LOCAL", "NAME_UNIVERSAL", "DIFFUSE_COLOR", "DIFFUSE_ALPHA",
              "SPECULAR_COLOR", "SPECULAR_POWER", "AMBIENT_COLOR", "DRAW_BOTH_FACE",
              "DRAW_GROUND_SHADOW", "DRAW_CAST_SELF_SHADOW", "DRAW_RECEIVE_SELF_SHADOW",
              "DRAW_VERTEX_COLOR", "EDGE_ENABLED", "EDGE_SIZE", "EDGE_COLOR", "EDGE_ALPHA",
              "TEXTURE_PATH", "SPHERE_TEXTURE_PATH", "SPHERE_MODE", "TOON_MODE",
              "TOON_TEXTURE_INDEX", "TOON_TEXTURE_PATH", "MEMO", "FACE_COUNT", "MESH_LINK",
              "SELECTION")
    for index in (0, 13, 34, -1, 0):
        model[ids["MODEL_MATERIAL_LIST"]] = index
        description = model.GetDescription(c4d.DESCFLAGS_DESC_0)
        parameters = list(description)
        if index >= 0:
            for field in fields:
                model.GetParameter(c4d.DescID(ids["MODEL_MATERIAL_" + field]), c4d.DESCFLAGS_GET_0)
        snapshots.append({"selection": index, "description_parameters": len(parameters),
                          "status": model[ids["MODEL_MATERIAL_TOON_STATUS"]]})
    if len(document.GetMaterials()) != material_count:
        raise AssertionError("Reading the page changed document materials")
    result = {"module": loaded_plugin_binary(), "cold_cache_status": status,
              "scene": str(scene_path), "materials": material_count,
              "selections": snapshots, "passed": True, "gui_tab_switch_verified": False}
    c4d.documents.KillDocument(document)
    return result
