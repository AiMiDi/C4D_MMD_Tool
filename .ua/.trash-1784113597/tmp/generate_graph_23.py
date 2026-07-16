import json
import math
import re
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"
BATCH_INDEX = 23


FILE_INFO = {
    "source/utils/io_util.hpp": (
        "Provides generic Cinema 4D HyperFile serialization templates for custom values, linear containers, hash maps, BaseList2D links, SDK-native types, and strong link references. / 提供通用 Cinema 4D HyperFile 序列化模板，覆盖自定义值、线性容器、哈希表、BaseList2D 链接、SDK 原生类型与强链接引用。",
        "HyperFile serialization", "HyperFile 序列化",
        ["utility", "serialization", "hyperfile", "template"],
    ),
    "source/utils/math_util.hpp": (
        "Converts between Cinema 4D Euler/HPB rotations and quaternion arrays while handling axis conventions and singularity corrections. / 在 Cinema 4D 欧拉/HPB 旋转与四元数数组之间转换，并处理轴约定与奇异点修正。",
        "Euler and quaternion conversion", "欧拉角与四元数转换",
        ["utility", "math", "quaternion", "rotation"],
    ),
    "source/utils/mmd_bone_control_util.cpp": (
        "Implements generation and refresh of visual bone controls, hierarchy-aware shapes and colors, protected transform axes, pose synchronization, checksums, and control-to-bone delta extraction. / 实现可视化骨骼控制器的生成与刷新、层级感知形状和颜色、受保护变换轴、姿态同步、校验和及控制器到骨骼的增量提取。",
        "MMD visual bone-control runtime", "MMD 可视化骨骼控制运行时",
        ["utility", "bone-control", "runtime", "transforms", "ui"],
    ),
    "source/utils/mmd_bone_control_util.hpp": (
        "Declares the public bone-control lifecycle, pose synchronization, active-delta detection, state checksum, bone-space delta, and reset API. / 声明骨骼控制器生命周期、姿态同步、活动增量检测、状态校验和、骨骼空间增量与重置 API。",
        "bone-control API", "骨骼控制 API",
        ["utility", "bone-control", "api", "transforms"],
    ),
    "source/utils/morph_ui_data_util.hpp": (
        "Defines a persistent morph-UI binding between a Cinema 4D tag and strength parameter, with HyperFile serialization, identity comparison, and safe strength access. / 定义 Cinema 4D 标签与强度参数之间的持久变形 UI 绑定，并提供 HyperFile 序列化、身份比较与安全强度访问。",
        "morph UI binding and persistence", "变形 UI 绑定与持久化",
        ["utility", "morph", "ui", "serialization", "data-model"],
    ),
    "source/utils/pmx_util.hpp": (
        "Defines configurable PMX text, signed-index, and unsigned-index readers that handle variable encoding and one-, two-, or four-byte index widths. / 定义可配置的 PMX 文本、有符号索引与无符号索引读取器，处理可变编码以及一、二或四字节索引宽度。",
        "PMX binary field reading", "PMX 二进制字段读取",
        ["utility", "pmx", "binary-io", "parser", "data-model"],
    ),
    "source/utils/time_util.hpp": (
        "Defines a hashable BaseTime subtype that preserves Cinema 4D time semantics while deriving a stable hash from numerator and denominator. / 定义可哈希的 BaseTime 子类型，在保留 Cinema 4D 时间语义的同时，根据分子与分母生成稳定哈希。",
        "hashable Cinema 4D time values", "可哈希的 Cinema 4D 时间值",
        ["utility", "time", "hashing", "data-model"],
    ),
    "source/utils/unique_id_util.hpp": (
        "Provides helpers for reading, testing, and writing UTF-8 application-specific unique IDs on Cinema 4D BaseList2D objects. / 提供在 Cinema 4D BaseList2D 对象上读取、检测与写入 UTF-8 应用专用唯一 ID 的辅助工具。",
        "Cinema 4D object unique IDs", "Cinema 4D 对象唯一 ID",
        ["utility", "unique-id", "cinema-4d", "serialization"],
    ),
}


IO_FUNCTIONS = [
    ("ReadData", 17, 20),
    ("WriteData", 31, 38),
    ("ReadLinearContainer", 49, 64),
    ("WriteLinearContainer", 75, 88),
    ("ReadHashMap", 101, 120),
    ("WriteHashMap", 132, 147),
    ("WriteBaseList2D", 158, 167),
    ("ReadBaseList2D", 178, 188),
    ("ReadData<AutoAlloc<BaseLink>>", 227, 231),
    ("ReadData<maxon::StrongRef<AutoAlloc<BaseLink>>>", 232, 250),
    ("WriteData<AutoAlloc<BaseLink>>", 277, 281),
    ("WriteData<maxon::StrongRef<AutoAlloc<BaseLink>>>", 282, 290),
    ("ResolveObjectLink", 292, 295),
]


PUBLIC_BONE_FUNCTIONS = {
    "CreateOrRefreshControls", "HasActiveControlDelta", "GetControlStateChecksum",
    "SyncControlsToCurrentPose", "GetControlDeltaInBoneSpace", "ResetControlRelativeTransform",
}


VERBS = [
    ("Normalize", "normalizes", "规范化"), ("Transform", "transforms", "转换"),
    ("Extract", "extracts", "提取"), ("Create", "creates", "创建"),
    ("Refresh", "refreshes", "刷新"), ("Configure", "configures", "配置"),
    ("Project", "projects", "投影"), ("Commit", "commits", "提交"),
    ("Apply", "applies", "应用"), ("Move", "moves", "移动"),
    ("Reset", "resets", "重置"), ("Sync", "synchronizes", "同步"),
    ("Build", "builds", "构建"), ("Make", "creates", "创建"),
    ("Resolve", "resolves", "解析"), ("Read", "reads", "读取"),
    ("Write", "writes", "写入"), ("Set", "sets", "设置"),
    ("Get", "retrieves", "获取"), ("Find", "finds", "查找"),
    ("Clear", "clears", "清除"), ("Mark", "marks", "标记"),
    ("Hash", "hashes", "计算哈希"), ("Mix", "mixes", "混合"),
    ("Has", "checks", "检查"), ("Is", "checks", "检查"),
    ("Should", "decides", "判定"), ("Try", "attempts", "尝试"),
    ("Compare", "compares", "比较"), ("Add", "adds", "添加"),
]


def complexity(non_empty):
    if non_empty < 50:
        return "simple"
    if non_empty <= 200:
        return "moderate"
    return "complex"


def symbol_complexity(span):
    if span <= 20:
        return "simple"
    if span <= 80:
        return "moderate"
    return "complex"


def humanize(text):
    text = text.replace("_", " ").strip()
    words = re.findall(r"[A-Z]+(?=[A-Z][a-z]|\d|$)|[A-Z]?[a-z]+|\d+", text)
    return " ".join(words).lower() if words else text.lower()


def function_summary(name, domain_en, domain_zh, path):
    leaf = name.split("::")[-1]
    if "operator()" in leaf:
        return f"{name} reads or skips a PMX field using the configured encoding or index width. / {name} 使用已配置的编码或索引宽度读取或跳过 PMX 字段。"
    owner = name.split("::")[-2] if "::" in name else ""
    if leaf == owner:
        return f"{name} initializes a helper used by {domain_en}. / {name} 初始化{domain_zh}所使用的辅助对象。"
    special = {
        "ReadData": ("deserializes a custom value through its Read contract", "通过 Read 协议反序列化自定义值"),
        "WriteData": ("serializes a custom value through its Write contract", "通过 Write 协议序列化自定义值"),
        "ReadLinearContainer": ("reads a sized linear container element by element", "逐元素读取带长度的线性容器"),
        "WriteLinearContainer": ("writes a linear container count and elements", "写入线性容器的数量与元素"),
        "ReadHashMap": ("reconstructs hash-map key/value entries from HyperFile", "从 HyperFile 重建哈希表键值项"),
        "WriteHashMap": ("serializes hash-map key/value entries to HyperFile", "将哈希表键值项序列化到 HyperFile"),
        "ReadBaseList2D": ("restores a BaseList2D-derived object through a BaseLink", "通过 BaseLink 恢复 BaseList2D 派生对象"),
        "WriteBaseList2D": ("serializes a BaseList2D-derived object through a BaseLink", "通过 BaseLink 序列化 BaseList2D 派生对象"),
        "ResolveObjectLink": ("resolves an AutoAlloc BaseLink to a BaseObject", "将 AutoAlloc BaseLink 解析为 BaseObject"),
    }
    if name in special:
        en, zh = special[name]
        return f"{name} {en} for {domain_en}. / {name} 为{domain_zh}{zh}。"
    if name.startswith("ReadData<"):
        return f"{name} restores a managed Cinema 4D link reference from HyperFile. / {name} 从 HyperFile 恢复受管理的 Cinema 4D 链接引用。"
    if name.startswith("WriteData<"):
        return f"{name} writes a managed Cinema 4D link reference to HyperFile. / {name} 将受管理的 Cinema 4D 链接引用写入 HyperFile。"
    for prefix, en_verb, zh_verb in VERBS:
        if leaf.startswith(prefix):
            topic = humanize(leaf[len(prefix):]) or "runtime state"
            return f"{name} {en_verb} {topic} for {domain_en}. / {name} 为{domain_zh}{zh_verb} {topic}。"
    return f"{name} performs a focused operation for {domain_en}. / {name} 为{domain_zh}执行专用操作。"


def function_tags(name, file_tags):
    low = name.lower()
    tags = []
    if "read" in low or "write" in low:
        tags.append("serialization")
    if "matrix" in low or "rotation" in low or "axis" in low:
        tags.append("transforms")
    if "control" in low:
        tags.append("bone-control")
    if "hash" in low or "checksum" in low:
        tags.append("hashing")
    if "pmx" in low or "index" in low or "text" in low:
        tags.append("pmx")
    for tag in file_tags:
        if tag not in tags:
            tags.append(tag)
        if len(tags) >= 3:
            break
    while len(tags) < 3:
        tags.append("utility")
    return tags[:5]


def class_summary(name, domain_en, domain_zh):
    if "Reader" in name:
        action_en, action_zh = "encapsulates configured binary-field reading", "封装可配置的二进制字段读取"
    elif name == "MorphUIData":
        action_en, action_zh = "binds a morph strength parameter to its owning tag", "将变形强度参数绑定到所属标签"
    elif name == "HashTime":
        action_en, action_zh = "extends BaseTime with stable hash semantics", "为 BaseTime 扩展稳定哈希语义"
    else:
        action_en, action_zh = "encapsulates application-specific unique-ID access", "封装应用专用唯一 ID 访问"
    return f"{name} {action_en} for {domain_en}. / {name} 为{domain_zh}{action_zh}。"


def qualify_function(fn, classes):
    start = int(fn["startLine"])
    enclosing = [c for c in classes if int(c["startLine"]) <= start <= int(c["endLine"])]
    if enclosing:
        enclosing.sort(key=lambda c: int(c["endLine"]) - int(c["startLine"]))
        return f"{enclosing[0]['name']}::{fn['name']}"
    return fn["name"]


def main():
    batches = json.loads((INTERMEDIATE / "batches.json").read_text(encoding="utf-8-sig"))
    batch = next(item for item in batches["batches"] if int(item["batchIndex"]) == BATCH_INDEX)
    extracted = json.loads((UA / "tmp" / "ua-file-extract-results-23.json").read_text(encoding="utf-8-sig"))
    batch_paths = {item["path"] for item in batch["files"]}
    result_paths = {item["path"] for item in extracted.get("results", [])}
    if not extracted.get("scriptCompleted") or batch_paths != result_paths or extracted.get("filesSkipped"):
        raise RuntimeError("Batch 23 extraction does not exactly match the current batch")
    result_by_path = {item["path"]: item for item in extracted["results"]}

    nodes = []
    edges = []
    ids = set()
    for spec in batch["files"]:
        path = spec["path"]
        result = result_by_path[path]
        summary, domain_en, domain_zh, file_tags = FILE_INFO[path]
        file_id = f"file:{path}"
        node = {
            "id": file_id, "type": "file", "name": Path(path).name, "filePath": path,
            "summary": summary, "tags": file_tags,
            "complexity": complexity(int(result.get("nonEmptyLines", spec["sizeLines"]))),
        }
        if node["complexity"] == "complex":
            node["languageNotes"] = "C++ combines Cinema 4D SDK ownership conventions with explicit templates, matrices, and persisted runtime state. / C++ 将 Cinema 4D SDK 所有权约定与显式模板、矩阵及持久运行时状态结合。"
        nodes.append(node)
        ids.add(file_id)

        classes = result.get("classes", []) or []
        exports = {item["name"] for item in (result.get("exports", []) or [])}
        for cls in classes:
            span = int(cls["endLine"]) - int(cls["startLine"]) + 1
            if span < 20 and len(cls.get("methods", []) or []) < 2:
                continue
            name = cls["name"]
            class_id = f"class:{path}:{name}"
            nodes.append({
                "id": class_id, "type": "class", "name": name, "filePath": path,
                "lineRange": [int(cls["startLine"]), int(cls["endLine"])],
                "summary": class_summary(name, domain_en, domain_zh),
                "tags": function_tags(name, file_tags), "complexity": symbol_complexity(span),
            })
            ids.add(class_id)
            edges.append({"source": file_id, "target": class_id, "type": "contains", "direction": "forward", "weight": 1.0})
            if name in exports:
                edges.append({"source": file_id, "target": class_id, "type": "exports", "direction": "forward", "weight": 0.8})

        if path == "source/utils/io_util.hpp":
            selected = [{"name": n, "startLine": s, "endLine": e, "manual": True} for n, s, e in IO_FUNCTIONS]
        else:
            selected = []
            for fn in result.get("functions", []) or []:
                span = int(fn["endLine"]) - int(fn["startLine"]) + 1
                if path == "source/utils/mmd_bone_control_util.cpp":
                    if span < 10 and fn["name"] not in PUBLIC_BONE_FUNCTIONS:
                        continue
                elif span < 3:
                    continue
                selected.append(dict(fn))

        used_ids = set()
        for fn in selected:
            qualified = fn["name"] if fn.get("manual") else qualify_function(fn, classes)
            function_id = f"function:{path}:{qualified}"
            if function_id in ids or function_id in used_ids:
                function_id = f"{function_id}@{int(fn['startLine'])}"
            used_ids.add(function_id)
            span = int(fn["endLine"]) - int(fn["startLine"]) + 1
            nodes.append({
                "id": function_id, "type": "function", "name": qualified, "filePath": path,
                "lineRange": [int(fn["startLine"]), int(fn["endLine"])],
                "summary": function_summary(qualified, domain_en, domain_zh, path),
                "tags": function_tags(qualified, file_tags), "complexity": symbol_complexity(span),
            })
            ids.add(function_id)
            edges.append({"source": file_id, "target": function_id, "type": "contains", "direction": "forward", "weight": 1.0})
            exported = path == "source/utils/io_util.hpp" or fn["name"] in exports
            if path == "source/utils/mmd_bone_control_util.cpp":
                exported = fn["name"] in PUBLIC_BONE_FUNCTIONS
            if exported:
                edges.append({"source": file_id, "target": function_id, "type": "exports", "direction": "forward", "weight": 0.8})

    expected_imports = sum(len(batch["batchImportData"].get(spec["path"], [])) for spec in batch["files"])
    for spec in batch["files"]:
        path = spec["path"]
        for target in batch["batchImportData"].get(path, []):
            edges.append({"source": f"file:{path}", "target": f"file:{target}", "type": "imports", "direction": "forward", "weight": 0.7})
    actual_imports = sum(edge["type"] == "imports" for edge in edges)
    if actual_imports != expected_imports:
        raise RuntimeError(f"Import mismatch: {actual_imports} != {expected_imports}")

    parts = 1 if len(nodes) <= 60 and len(edges) <= 120 else math.ceil(max(len(nodes) / 60, len(edges) / 120))
    paths = sorted(batch_paths)
    chunk_size = math.ceil(len(paths) / parts)
    groups = [paths[i:i + chunk_size] for i in range(0, len(paths), chunk_size)]
    for old in INTERMEDIATE.glob("batch-23.json"):
        old.unlink()
    for old in INTERMEDIATE.glob("batch-23-part-*.json"):
        old.unlink()
    written = []
    for number, group in enumerate(groups, start=1):
        group_set = set(group)
        part_nodes = [node for node in nodes if node.get("filePath") in group_set]
        part_ids = {node["id"] for node in part_nodes}
        part_edges = [edge for edge in edges if edge["source"] in part_ids]
        for edge in part_edges:
            if edge["source"] not in part_ids or edge["target"] not in part_ids:
                raise RuntimeError(f"Invalid edge in batch 23 part {number}: {edge}")
        output = INTERMEDIATE / ("batch-23.json" if len(groups) == 1 else f"batch-23-part-{number}.json")
        output.write_text(json.dumps({"nodes": part_nodes, "edges": part_edges}, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        json.loads(output.read_text(encoding="utf-8"))
        written.append({"name": output.name, "nodes": len(part_nodes), "edges": len(part_edges)})
    print(json.dumps({"batch": 23, "files": len(batch_paths), "nodes": len(nodes), "edges": len(edges), "imports": actual_imports, "parts": written, "skipped": []}, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
