import json
import re
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"
BATCH_INDEX = 16


COMPONENTS = {
    "OMMDBoneManager": ("bone-manager display, hierarchy, refresh, and mode controls", "骨骼管理器的显示、层级、刷新与模式控制", "bone-manager"),
    "OMMDCamera": ("MMD camera object labels", "MMD 相机对象标签", "camera"),
    "OMMDJoint": ("joint transforms, limits, springs, display options, and physics modes", "关节变换、限制、弹簧、显示选项与物理模式", "joint"),
    "OMMDJointManager": ("joint-manager list, display, and mode controls", "关节管理器的列表、显示与模式控制", "joint-manager"),
    "OMMDMeshManager": ("mesh-manager display, mesh-mode, and morph-mode controls", "网格管理器的显示、网格模式与变形模式控制", "mesh-manager"),
    "OMMDModelManager": ("model metadata, animation slots, physics, IK, morphs, materials, display frames, and model operations", "模型元数据、动画槽、物理、IK、变形、材质、显示框与模型操作", "model-manager"),
    "OMMDRigid": ("rigid-body transforms, shapes, collision groups, dynamics, display, and modes", "刚体变换、形状、碰撞组、动力学、显示与模式", "rigid-body"),
    "OMMDRigidManager": ("rigid-manager list, display, and mode controls", "刚体管理器的列表、显示与模式控制", "rigid-manager"),
    "TMMDBone": ("bone-tag PMX properties, append transforms, IK links, animation curves, and bone morphs", "骨骼标签的 PMX 属性、附加变换、IK 链接、动画曲线与骨骼变形", "bone-tag"),
    "Xmmdmaterialmorphshader": ("material-morph shader parameters and display names", "材质变形着色器参数与显示名称", "material-morph"),
    "DLG_CMT_TOOL": ("the main tool dialog's camera, motion, and model import/export options", "主工具对话框中的相机、动作与模型导入导出选项", "tool-dialog"),
    "DLG_CMT_VMD_IMPORT": ("the focused VMD import dialog and its model-selection controls", "聚焦的 VMD 导入对话框及其模型选择控制", "vmd-import"),
}


def complexity(non_empty):
    if non_empty < 50:
        return "simple"
    if non_empty <= 200:
        return "moderate"
    return "complex"


def string_info(path):
    filename = Path(path).stem
    component_en, component_zh, component_tag = COMPONENTS[filename]
    if "strings_en-US" in path:
        locale_en, locale_zh, locale_tag = "English", "英语", "en-us"
    else:
        locale_en, locale_zh, locale_tag = "Simplified Chinese", "简体中文", "zh-cn"
    summary = (
        f"Provides {locale_en} Cinema 4D resource labels for {component_en}. / "
        f"为{component_zh}提供{locale_zh} Cinema 4D 资源标签。"
    )
    tags = ["localization", locale_tag, "cinema-4d", component_tag, "legacy-sdk"]
    return summary, tags


def file_info(path):
    if path.endswith("strings_zh-CN/c4d_strings.str"):
        return (
            "Provides Simplified Chinese messages, confirmations, plugin names, shared morph labels, and runtime status strings for the legacy Cinema 4D resource set. / 为旧版 Cinema 4D 资源集提供简体中文消息、确认提示、插件名称、共享变形标签与运行时状态文本。",
            ["localization", "zh-cn", "cinema-4d", "shared-strings", "legacy-sdk"],
        )
    if path.endswith(".str"):
        return string_info(path)
    if path.endswith("res/S24_up/c4d_symbols.h"):
        return (
            "Declares S24-and-newer Cinema 4D string, command, dialog, plugin, and shared runtime symbol identifiers consumed by the current resource tree. / 声明 S24 及更新版本 Cinema 4D 当前资源树使用的字符串、命令、对话框、插件与共享运行时符号标识符。",
            ["cinema-4d", "resource-id", "current-sdk", "localization"],
        )
    if path.endswith("res/S24_up/cmt_config.json"):
        return (
            "Stores default user-facing import/export settings for camera, motion, and model workflows, including scale, offsets, baking, geometry, materials, IK, physics, and morph options. / 保存相机、动作与模型工作流的默认导入导出设置，包括缩放、偏移、烘焙、几何、材质、IK、物理与变形选项。",
            ["configuration", "import", "export", "workflow-defaults", "cinema-4d"],
        )
    if path.endswith("res/S24_up/description/OMMDBoneManager.h"):
        return (
            "Declares S24-and-newer description identifiers for bone-manager display controls, hierarchy refresh, and bone modes. / 声明 S24 及更新版本骨骼管理器显示控制、层级刷新与骨骼模式的描述标识符。",
            ["cinema-4d", "resource-id", "bone-manager", "current-sdk"],
        )
    raise KeyError(path)


def main():
    batches = json.loads((INTERMEDIATE / "batches.json").read_text(encoding="utf-8-sig"))
    batch = next(item for item in batches["batches"] if int(item["batchIndex"]) == BATCH_INDEX)
    extracted = json.loads((UA / "tmp" / "ua-file-extract-results-16.json").read_text(encoding="utf-8-sig"))
    if not extracted.get("scriptCompleted") or len(extracted.get("results", [])) != len(batch["files"]):
        raise RuntimeError("Batch 16 extraction completeness check failed")
    result_by_path = {item["path"]: item for item in extracted["results"]}

    nodes = []
    edges = []
    for spec in batch["files"]:
        path = spec["path"]
        result = result_by_path[path]
        summary, tags = file_info(path)
        if spec["fileCategory"] == "config":
            node_type = "config"
            node_id = f"config:{path}"
        else:
            node_type = "file"
            node_id = f"file:{path}"
        node = {
            "id": node_id,
            "type": node_type,
            "name": Path(path).name,
            "filePath": path,
            "summary": summary,
            "tags": tags,
            "complexity": complexity(int(result.get("nonEmptyLines", spec["sizeLines"]))),
        }
        if node["complexity"] == "complex":
            node["languageNotes"] = "Cinema 4D resources keep stable symbolic identifiers separate from locale-specific STRINGTABLE values. / Cinema 4D 资源将稳定的符号标识符与特定语言区域的 STRINGTABLE 文本值分离。"
        nodes.append(node)

    expected_imports = sum(len(batch["batchImportData"].get(spec["path"], [])) for spec in batch["files"])
    for spec in batch["files"]:
        path = spec["path"]
        source_prefix = "config" if spec["fileCategory"] == "config" else "file"
        for target in batch["batchImportData"].get(path, []):
            edges.append({
                "source": f"{source_prefix}:{path}",
                "target": f"file:{target}",
                "type": "imports",
                "direction": "forward",
                "weight": 0.7,
            })
    if len(edges) != expected_imports:
        raise RuntimeError(f"Import mismatch: {len(edges)} != {expected_imports}")

    for old in INTERMEDIATE.glob("batch-16.json"):
        old.unlink()
    for old in INTERMEDIATE.glob("batch-16-part-*.json"):
        old.unlink()

    payload = {"nodes": nodes, "edges": edges}
    output = INTERMEDIATE / "batch-16.json"
    output.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    checked = json.loads(output.read_text(encoding="utf-8"))
    if not isinstance(checked.get("nodes"), list) or not isinstance(checked.get("edges"), list):
        raise RuntimeError("Batch 16 JSON validation failed")
    print(json.dumps({
        "batch": BATCH_INDEX,
        "files": len(batch["files"]),
        "nodes": len(nodes),
        "edges": len(edges),
        "imports": len(edges),
        "parts": [{"name": output.name, "nodes": len(nodes), "edges": len(edges)}],
        "skipped": extracted.get("filesSkipped", []),
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
