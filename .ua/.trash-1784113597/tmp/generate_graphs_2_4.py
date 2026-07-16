import json
import math
import re
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"


FILE_INFO = {
    "source/module/tools/object/mmd_bone_manager.cpp": (
        "Implements bone hierarchy import/export, append and IK execution ordering, bind-state transitions, animation slots, and physics-playback coordination. / 实现骨骼层级导入导出、附加变换与 IK 执行排序、绑定状态切换、动画槽以及物理播放协调。",
        "bone hierarchy and runtime coordination", "骨骼层级与运行时协调",
        ["object-manager", "pmx-import", "pmx-export", "ik", "physics"],
    ),
    "source/module/tools/object/mmd_bone_manager.h": (
        "Declares the bone-manager object, its scene message contract, hierarchy indices, animation-slot controls, and physics-override API. / 声明骨骼管理器对象、场景消息协议、层级索引、动画槽控制以及物理覆盖 API。",
        "bone-manager API", "骨骼管理器 API",
        ["object-manager", "api", "bone-hierarchy", "animation", "physics"],
    ),
    "source/module/tools/object/mmd_display_frame.cpp": (
        "Converts PMX display-frame records to persistent Cinema 4D data and implements HyperFile serialization and copying. / 将 PMX 显示框记录转换为 Cinema 4D 持久数据，并实现 HyperFile 序列化与复制。",
        "PMX display-frame persistence", "PMX 显示框持久化",
        ["serialization", "pmx", "display-frame", "data-model"],
    ),
    "source/module/tools/object/mmd_manager.hpp": (
        "Defines the shared base for MMD manager objects, including protection/display tag creation and common persisted links. / 定义 MMD 管理器对象的共享基类，包括保护与显示标签创建以及通用持久链接。",
        "shared MMD manager behavior", "共享 MMD 管理器行为",
        ["object-manager", "base-class", "serialization", "cinema-4d"],
    ),
    "source/module/tools/object/mmd_mesh_manager.cpp": (
        "Implements PMX mesh import/export, polygon and vertex remapping, BDEF/SDEF weight conversion, morph-tag binding, and runtime morph refresh. / 实现 PMX 网格导入导出、多边形与顶点重映射、BDEF/SDEF 权重转换、变形标签绑定以及运行时变形刷新。",
        "mesh, skin-weight, and morph management", "网格、蒙皮权重与变形管理",
        ["object-manager", "pmx-import", "pmx-export", "skinning", "morph"],
    ),
    "source/module/tools/object/mmd_mesh_manager.h": (
        "Declares the mesh-manager object and its PMX loading, export, morph-strength, bind-pose, and refresh interfaces. / 声明网格管理器对象及其 PMX 加载、导出、变形强度、绑定姿态与刷新接口。",
        "mesh-manager API", "网格管理器 API",
        ["object-manager", "api", "skinning", "morph", "pmx"],
    ),
    "source/module/tools/object/mmd_model_manager.cpp": (
        "Implements the central model workflow for PMX, VMD, and VPD import/export, dynamic morph and material UI, animation slots, standalone IK, and physics playback. / 实现 PMX、VMD 与 VPD 导入导出的核心模型流程，以及动态变形和材质 UI、动画槽、独立 IK 与物理播放。",
        "central model, animation, IK, and physics orchestration", "核心模型、动画、IK 与物理编排",
        ["object-manager", "pmx", "vmd-animation", "morph", "physics"],
    ),
    "source/module/tools/object/mmd_model_manager.h": (
        "Declares the central model-manager state, display-frame and animation-slot data, morph/material editing APIs, and standalone IK/physics runtime interfaces. / 声明核心模型管理器状态、显示框与动画槽数据、变形和材质编辑 API，以及独立 IK/物理运行时接口。",
        "model-manager API and persistent state", "模型管理器 API 与持久状态",
        ["object-manager", "api", "data-model", "animation", "physics"],
    ),
    "source/module/tools/object/mmd_morph.cpp": (
        "Implements group, flip, mesh, UV, bone, material, and impulse morph persistence, UI editing, PMX conversion, and runtime updates. / 实现组、翻转、网格、UV、骨骼、材质与冲量变形的持久化、UI 编辑、PMX 转换及运行时更新。",
        "MMD morph data and editing", "MMD 变形数据与编辑",
        ["morph", "data-model", "serialization", "ui", "pmx"],
    ),
    "source/module/tools/object/mmd_morph.h": (
        "Defines the polymorphic MMD morph model and concrete group, flip, mesh, UV, bone, material, and impulse morph types. / 定义多态 MMD 变形模型，以及组、翻转、网格、UV、骨骼、材质和冲量等具体变形类型。",
        "MMD morph type system", "MMD 变形类型体系",
        ["morph", "data-model", "polymorphism", "type-definition", "pmx"],
    ),
    "source/module/tools/object/mmd_rigid.cpp": (
        "Implements the per-rigid-body Cinema 4D object, including shape parameters, viewport drawing, manager linkage, transform tracking, and execution behavior. / 实现单个刚体的 Cinema 4D 对象，包括形状参数、视口绘制、管理器关联、变换跟踪与执行行为。",
        "per-rigid-body object behavior", "单刚体对象行为",
        ["rigid-body", "physics", "object-plugin", "viewport", "runtime"],
    ),
    "source/module/tools/object/mmd_rigid.h": (
        "Declares the MMD rigid-body object plugin and its parameter, drawing, execution, serialization, and mode-transition hooks. / 声明 MMD 刚体对象插件及其参数、绘制、执行、序列化与模式切换钩子。",
        "rigid-body object API", "刚体对象 API",
        ["rigid-body", "physics", "api", "object-plugin", "serialization"],
    ),
    "source/module/tools/object/mmd_rigid_manager.cpp": (
        "Implements rigid-body collection management, PMX import/export, edit/runtime transform transitions, collision settings, and standalone physics-body construction. / 实现刚体集合管理、PMX 导入导出、编辑与运行时变换切换、碰撞设置以及独立物理刚体构建。",
        "rigid-body collection and physics setup", "刚体集合与物理设置",
        ["object-manager", "rigid-body", "pmx", "physics", "serialization"],
    ),
    "source/module/tools/object/mmd_rigid_manager.h": (
        "Declares the rigid-body manager, scene message contract, PMX conversion API, and standalone physics-body lifecycle. / 声明刚体管理器、场景消息协议、PMX 转换 API 与独立物理刚体生命周期。",
        "rigid-manager API", "刚体管理器 API",
        ["object-manager", "rigid-body", "api", "physics", "pmx"],
    ),
    "source/module/tools/loader/vmd_loader.cpp": (
        "Implements the Cinema 4D scene-loader entry point that validates VMD files and delegates motion import to the scene manager. / 实现 Cinema 4D 场景加载器入口，负责校验 VMD 文件并将动作导入委托给场景管理器。",
        "VMD scene loading", "VMD 场景加载",
        ["scene-loader", "vmd-animation", "entry-point", "import"],
    ),
    "source/module/tools/loader/vmd_loader.h": (
        "Declares the Cinema 4D VMD scene-loader plugin interface. / 声明 Cinema 4D VMD 场景加载器插件接口。",
        "VMD loader API", "VMD 加载器 API",
        ["scene-loader", "vmd-animation", "api", "plugin"],
    ),
    "source/module/tools/object/mmd_joint.cpp": (
        "Implements the per-joint constraint object, including PMX parameter mapping, constraint visualization, mode changes, and runtime physics execution. / 实现单个关节约束对象，包括 PMX 参数映射、约束可视化、模式切换与运行时物理执行。",
        "per-joint constraint behavior", "单关节约束行为",
        ["joint", "physics", "object-plugin", "viewport", "pmx"],
    ),
    "source/module/tools/object/mmd_joint.h": (
        "Declares the MMD joint object plugin and its parameter, drawing, execution, serialization, and mode-transition hooks. / 声明 MMD 关节对象插件及其参数、绘制、执行、序列化与模式切换钩子。",
        "joint object API", "关节对象 API",
        ["joint", "physics", "api", "object-plugin", "serialization"],
    ),
    "source/module/tools/object/mmd_joint_manager.cpp": (
        "Implements joint collection management, PMX import/export, editor-transform transitions, rigid-index remapping, and standalone physics-constraint construction. / 实现关节集合管理、PMX 导入导出、编辑器变换切换、刚体索引重映射与独立物理约束构建。",
        "joint collection and physics-constraint setup", "关节集合与物理约束设置",
        ["object-manager", "joint", "pmx", "physics", "serialization"],
    ),
    "source/module/tools/object/mmd_joint_manager.h": (
        "Declares the joint manager, scene message contract, PMX conversion API, and standalone constraint lifecycle. / 声明关节管理器、场景消息协议、PMX 转换 API 与独立约束生命周期。",
        "joint-manager API", "关节管理器 API",
        ["object-manager", "joint", "api", "physics", "pmx"],
    ),
    "source/module/tools/tag/mmd_bone.cpp": (
        "Implements the MMD bone tag runtime, including bind-state persistence, append transforms, layered IK evaluation, animation interpolation, and physics handoff. / 实现 MMD 骨骼标签运行时，包括绑定状态持久化、附加变换、分层 IK 求解、动画插值与物理交接。",
        "bone-tag animation, IK, and physics runtime", "骨骼标签动画、IK 与物理运行时",
        ["tag-plugin", "bone-animation", "ik", "physics", "runtime"],
    ),
    "source/module/tools/tag/mmd_bone.h": (
        "Declares bone-tag state, animation keyframes, IK-chain adapters and solvers, append-transform data, and runtime evaluation interfaces. / 声明骨骼标签状态、动画关键帧、IK 链适配器与求解器、附加变换数据及运行时求值接口。",
        "bone-tag runtime API and data model", "骨骼标签运行时 API 与数据模型",
        ["tag-plugin", "api", "bone-animation", "ik", "data-model"],
    ),
    "source/module/ui/cmt_tools_dialog.cpp": (
        "Implements the main MMD tool dialog layout and command routing for PMX, VMD, VPD, camera, and model operations. / 实现 MMD 工具主对话框布局，以及 PMX、VMD、VPD、相机与模型操作的命令路由。",
        "main tool dialog and command routing", "主工具对话框与命令路由",
        ["ui", "dialog", "command-routing", "import", "export"],
    ),
    "source/module/ui/cmt_tools_dialog.h": (
        "Declares the tool dialog and command plugin used to expose MMD import/export workflows in Cinema 4D. / 声明在 Cinema 4D 中提供 MMD 导入导出流程的工具对话框与命令插件。",
        "tool-dialog API", "工具对话框 API",
        ["ui", "dialog", "api", "command-plugin"],
    ),
    "source/register_entity.cpp": (
        "Registers the scene manager, loaders, object and tag plugins, and the user-facing MMD tool command with Cinema 4D. / 向 Cinema 4D 注册场景管理器、加载器、对象与标签插件，以及面向用户的 MMD 工具命令。",
        "Cinema 4D plugin registration", "Cinema 4D 插件注册",
        ["plugin-registration", "entry-point", "cinema-4d", "factory"],
    ),
}


VERBS = [
    ("Normalize", "normalizes", "规范化"), ("Configure", "configures", "配置"),
    ("Initialize", "initializes", "初始化"), ("Init", "initializes", "初始化"),
    ("Validate", "validates", "校验"), ("Resolve", "resolves", "解析"),
    ("Evaluate", "evaluates", "求值"), ("Calculate", "calculates", "计算"),
    ("Compute", "computes", "计算"), ("Build", "builds", "构建"),
    ("Create", "creates", "创建"), ("Refresh", "refreshes", "刷新"),
    ("Synchronize", "synchronizes", "同步"), ("Sync", "synchronizes", "同步"),
    ("Import", "imports", "导入"), ("Export", "exports", "导出"),
    ("Convert", "converts", "转换"), ("Remap", "remaps", "重映射"),
    ("Reconnect", "reconnects", "重新连接"), ("Find", "finds", "查找"),
    ("Collect", "collects", "收集"), ("Ensure", "ensures", "确保"),
    ("Prepare", "prepares", "准备"), ("Capture", "captures", "捕获"),
    ("Rebuild", "rebuilds", "重建"), ("Register", "registers", "注册"),
    ("Apply", "applies", "应用"), ("Update", "updates", "更新"),
    ("Reset", "resets", "重置"), ("Commit", "commits", "提交"),
    ("Restore", "restores", "恢复"), ("Invalidate", "invalidates", "使失效"),
    ("Append", "appends", "追加"), ("Add", "adds", "添加"),
    ("Delete", "deletes", "删除"), ("Remove", "removes", "移除"),
    ("Clear", "clears", "清除"), ("Strip", "strips", "移除"),
    ("Mark", "marks", "标记"), ("Handle", "handles", "处理"),
    ("Load", "loads", "加载"), ("Save", "saves", "保存"),
    ("Read", "reads", "读取"), ("Write", "writes", "写入"),
    ("Copy", "copies", "复制"), ("Set", "sets", "设置"),
    ("Get", "retrieves", "获取"), ("Is", "checks", "检查"),
    ("Has", "checks", "检查"), ("Should", "decides", "判定"),
    ("Make", "creates", "创建"), ("Draw", "draws", "绘制"),
    ("Execute", "executes", "执行"), ("Command", "dispatches", "分发"),
    ("Message", "handles", "处理"), ("Begin", "begins", "开始"),
    ("Finish", "finishes", "完成"), ("Prune", "prunes", "清理"),
]


def complexity(lines):
    if lines < 50:
        return "simple"
    if lines <= 200:
        return "moderate"
    return "complex"


def symbol_complexity(span):
    if span <= 20:
        return "simple"
    if span <= 80:
        return "moderate"
    return "complex"


def humanize(text):
    text = text.replace("_", " ").replace("::", " ").strip()
    words = re.findall(r"[A-Z]+(?=[A-Z][a-z]|\d|$)|[A-Z]?[a-z]+|\d+", text)
    return " ".join(words) if words else text


def function_summary(name, domain_en, domain_zh):
    leaf = name.split("::")[-1]
    if leaf.startswith("~"):
        return f"{name} releases scoped state for {domain_en}. / {name} 释放{domain_zh}中的作用域状态。"
    owner = name.split("::")[-2] if "::" in name else ""
    if leaf == owner or leaf.split("@", 1)[0] == owner:
        return f"{name} initializes an object used by {domain_en}. / {name} 初始化{domain_zh}所使用的对象。"
    if leaf.startswith("operator"):
        return f"{name} implements value semantics required by {domain_en}. / {name} 实现{domain_zh}所需的值语义。"
    special = {
        "Read": ("reads persistent state", "读取持久状态"),
        "Write": ("writes persistent state", "写入持久状态"),
        "CopyTo": ("copies persistent state to another instance", "将持久状态复制到另一实例"),
        "Execute": ("runs the Cinema 4D evaluation-stage behavior", "执行 Cinema 4D 求值阶段行为"),
        "AddToExecution": ("registers the object in Cinema 4D execution order", "将对象注册到 Cinema 4D 执行顺序"),
        "Message": ("dispatches Cinema 4D messages and state transitions", "分发 Cinema 4D 消息与状态切换"),
        "SetDParameter": ("applies parameter changes and their runtime side effects", "应用参数变更及其运行时副作用"),
        "CreateLayout": ("builds the interactive dialog layout", "构建交互式对话框布局"),
        "InitValues": ("initializes dialog values from current scene state", "根据当前场景状态初始化对话框数值"),
        "Command": ("routes user commands to MMD import and export workflows", "将用户命令路由到 MMD 导入导出流程"),
        "Draw": ("renders the plugin's viewport representation", "绘制插件的视口表示"),
    }
    if leaf in special:
        en, zh = special[leaf]
        return f"{name} {en} for {domain_en}. / {name} 为{domain_zh}{zh}。"
    if leaf.startswith("SDK2024_"):
        topic = humanize(leaf[len("SDK2024_"):]).lower() or "lifecycle state"
        return f"{name} implements the Cinema 4D SDK lifecycle hook for {topic} in {domain_en}. / {name} 实现{domain_zh}中用于 {topic} 的 Cinema 4D SDK 生命周期钩子。"
    for prefix, en_verb, zh_verb in VERBS:
        if leaf.startswith(prefix):
            remainder = leaf[len(prefix):]
            topic = humanize(remainder).lower() or "runtime state"
            return f"{name} {en_verb} {topic} for {domain_en}. / {name} 为{domain_zh}{zh_verb} {topic}。"
    return f"{name} implements a focused operation in {domain_en}. / {name} 实现{domain_zh}中的专用操作。"


def function_tags(name, file_tags):
    leaf = name.split("::")[-1].lower()
    tags = []
    if any(x in leaf for x in ("read", "write", "copy")):
        tags.append("serialization")
    if "pmx" in leaf:
        tags.append("pmx")
    if "vmd" in leaf or "animation" in leaf or "keyframe" in leaf:
        tags.append("vmd-animation")
    if "ik" in leaf:
        tags.append("ik")
    if "physics" in leaf or "rigid" in leaf or "joint" in leaf:
        tags.append("physics")
    if "morph" in leaf:
        tags.append("morph")
    if any(x in leaf for x in ("layout", "dialog", "command", "ui", "description")):
        tags.append("ui")
    if any(x in leaf for x in ("load", "import", "frompmx")):
        tags.append("import")
    if any(x in leaf for x in ("save", "export", "topmx")):
        tags.append("export")
    if any(x in leaf for x in ("execute", "runtime", "evaluate", "apply")):
        tags.append("runtime")
    for tag in file_tags:
        if tag not in tags:
            tags.append(tag)
        if len(tags) >= 3:
            break
    while len(tags) < 3:
        tags.append("utility")
    return tags[:5]


def class_summary(name, domain_en, domain_zh):
    low = name.lower()
    if "manager" in low:
        en = "coordinates owned objects, persistent state, and lifecycle operations"
        zh = "协调所管理对象、持久状态与生命周期操作"
    elif "morph" in low:
        en = "represents a concrete MMD morph type and its editing/runtime state"
        zh = "表示具体 MMD 变形类型及其编辑与运行时状态"
    elif "adapter" in low:
        en = "adapts Cinema 4D scene data to the runtime solver interface"
        zh = "将 Cinema 4D 场景数据适配到运行时求解器接口"
    elif "dialog" in low:
        en = "implements a user-facing editing dialog"
        zh = "实现面向用户的编辑对话框"
    elif "guard" in low:
        en = "provides scoped state restoration through RAII"
        zh = "通过 RAII 提供作用域状态恢复"
    elif "data" in low or "metadata" in low or "keyframe" in low:
        en = "stores structured persistent and runtime data"
        zh = "保存结构化持久数据与运行时数据"
    else:
        en = "encapsulates a major runtime responsibility"
        zh = "封装主要运行时职责"
    return f"{name} {en} for {domain_en}. / {name} 为{domain_zh}{zh}。"


def class_tags(name, file_tags):
    low = name.lower()
    tags = []
    if "manager" in low:
        tags.append("object-manager")
    if "morph" in low:
        tags.append("morph")
    if "adapter" in low:
        tags.append("adapter")
    if "dialog" in low:
        tags.append("ui")
    if "guard" in low:
        tags.append("raii")
    if "data" in low or "metadata" in low:
        tags.append("data-model")
    for tag in file_tags:
        if tag not in tags:
            tags.append(tag)
        if len(tags) >= 3:
            break
    while len(tags) < 3:
        tags.append("runtime")
    return tags[:5]


def recover_function_name(path, fn, classes, lines):
    raw = fn["name"]
    if "::" in raw:
        return raw
    start = int(fn["startLine"])
    end = min(len(lines), start + 6)
    snippet = " ".join(lines[start - 1:end])
    for match in re.finditer(r"([~A-Za-z_]\w*(?:::[~A-Za-z_]\w*)+)\s*\(", snippet):
        candidate = match.group(1)
        if candidate.split("::")[-1] == raw:
            return candidate
    enclosing = [c for c in classes if int(c["startLine"]) <= start <= int(c["endLine"])]
    if enclosing:
        enclosing.sort(key=lambda c: int(c["endLine"]) - int(c["startLine"]))
        return f"{enclosing[0]['name']}::{raw}"
    return raw


def build_batch(batch_index, batch):
    extract_path = UA / "tmp" / f"ua-file-extract-results-{batch_index}.json"
    extracted = json.loads(extract_path.read_text(encoding="utf-8-sig"))
    if not extracted.get("scriptCompleted") or len(extracted.get("results", [])) != len(batch["files"]):
        raise RuntimeError(f"Extraction completeness check failed for batch {batch_index}")

    nodes = []
    edges = []
    seen_ids = set()
    result_by_path = {item["path"]: item for item in extracted["results"]}

    for file_spec in batch["files"]:
        path = file_spec["path"]
        result = result_by_path[path]
        summary, domain_en, domain_zh, file_tags = FILE_INFO[path]
        file_id = f"file:{path}"
        file_node = {
            "id": file_id,
            "type": "file",
            "name": Path(path).name,
            "filePath": path,
            "summary": summary,
            "tags": file_tags,
            "complexity": complexity(int(result.get("nonEmptyLines", file_spec["sizeLines"]))),
        }
        if file_node["complexity"] == "complex":
            file_node["languageNotes"] = "C++ integrates Cinema 4D SDK lifecycle hooks with explicit PMX/VMD conversion and runtime state management. / C++ 将 Cinema 4D SDK 生命周期钩子与显式 PMX/VMD 转换及运行时状态管理结合。"
        nodes.append(file_node)
        seen_ids.add(file_id)

        exported = {item["name"] for item in result.get("exports", [])}
        classes = result.get("classes", [])
        selected_classes = []
        for cls in classes:
            span = int(cls["endLine"]) - int(cls["startLine"]) + 1
            methods = cls.get("methods", []) or []
            if span >= 20 or len(methods) >= 2:
                selected_classes.append(cls)
        for cls in selected_classes:
            name = cls["name"]
            node_id = f"class:{path}:{name}"
            if node_id in seen_ids:
                raise RuntimeError(f"Duplicate class node id: {node_id}")
            span = int(cls["endLine"]) - int(cls["startLine"]) + 1
            nodes.append({
                "id": node_id,
                "type": "class",
                "name": name,
                "filePath": path,
                "lineRange": [int(cls["startLine"]), int(cls["endLine"])],
                "summary": class_summary(name, domain_en, domain_zh),
                "tags": class_tags(name, file_tags),
                "complexity": symbol_complexity(span),
            })
            seen_ids.add(node_id)
            edges.append({"source": file_id, "target": node_id, "type": "contains", "direction": "forward", "weight": 1.0})
            if name in exported:
                edges.append({"source": file_id, "target": node_id, "type": "exports", "direction": "forward", "weight": 0.8})

        source_lines = (ROOT / path).read_text(encoding="utf-8-sig", errors="replace").splitlines()
        used_function_ids = set()
        for fn in result.get("functions", []):
            span = int(fn["endLine"]) - int(fn["startLine"]) + 1
            is_exported = fn["name"] in exported
            if not (span >= 10 or (is_exported and span >= 3)):
                continue
            qualified = recover_function_name(path, fn, classes, source_lines)
            node_id = f"function:{path}:{qualified}"
            if node_id in used_function_ids or node_id in seen_ids:
                node_id = f"{node_id}@{int(fn['startLine'])}"
            used_function_ids.add(node_id)
            if node_id in seen_ids:
                raise RuntimeError(f"Duplicate function node id: {node_id}")
            nodes.append({
                "id": node_id,
                "type": "function",
                "name": qualified,
                "filePath": path,
                "lineRange": [int(fn["startLine"]), int(fn["endLine"])],
                "summary": function_summary(qualified, domain_en, domain_zh),
                "tags": function_tags(qualified, file_tags),
                "complexity": symbol_complexity(span),
            })
            seen_ids.add(node_id)
            edges.append({"source": file_id, "target": node_id, "type": "contains", "direction": "forward", "weight": 1.0})
            if is_exported:
                edges.append({"source": file_id, "target": node_id, "type": "exports", "direction": "forward", "weight": 0.8})

    expected_imports = 0
    for file_spec in batch["files"]:
        path = file_spec["path"]
        for target in batch["batchImportData"].get(path, []):
            edges.append({
                "source": f"file:{path}",
                "target": f"file:{target}",
                "type": "imports",
                "direction": "forward",
                "weight": 0.7,
            })
            expected_imports += 1
    actual_imports = sum(1 for edge in edges if edge["type"] == "imports")
    if actual_imports != expected_imports:
        raise RuntimeError(f"Batch {batch_index} import mismatch: {actual_imports} != {expected_imports}")

    node_count = len(nodes)
    edge_count = len(edges)
    parts = 1 if node_count <= 60 and edge_count <= 120 else math.ceil(max(node_count / 60, edge_count / 120))
    sorted_paths = sorted(item["path"] for item in batch["files"])
    chunk_size = math.ceil(len(sorted_paths) / parts)
    groups = [sorted_paths[i:i + chunk_size] for i in range(0, len(sorted_paths), chunk_size)]

    for old in INTERMEDIATE.glob(f"batch-{batch_index}.json"):
        old.unlink()
    for old in INTERMEDIATE.glob(f"batch-{batch_index}-part-*.json"):
        old.unlink()

    allowed_file_targets = {
        target
        for values in batch["batchImportData"].values()
        for target in values
    }
    written = []
    for part_number, group in enumerate(groups, start=1):
        group_set = set(group)
        part_nodes = [node for node in nodes if node.get("filePath") in group_set]
        part_ids = {node["id"] for node in part_nodes}
        part_edges = [edge for edge in edges if edge["source"] in part_ids]
        for edge in part_edges:
            if edge["source"] not in part_ids:
                raise RuntimeError(f"Batch {batch_index} part {part_number} has external source: {edge}")
            if edge["target"] in part_ids:
                continue
            if edge["target"].startswith("file:") and edge["target"][5:] in allowed_file_targets:
                continue
            raise RuntimeError(f"Batch {batch_index} part {part_number} has invalid target: {edge}")
        payload = {"nodes": part_nodes, "edges": part_edges}
        if len(groups) == 1:
            output = INTERMEDIATE / f"batch-{batch_index}.json"
        else:
            output = INTERMEDIATE / f"batch-{batch_index}-part-{part_number}.json"
        output.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        reloaded = json.loads(output.read_text(encoding="utf-8"))
        if not isinstance(reloaded.get("nodes"), list) or not isinstance(reloaded.get("edges"), list):
            raise RuntimeError(f"Batch {batch_index} part {part_number} JSON validation failed")
        written.append((output.name, len(part_nodes), len(part_edges)))

    return {
        "batch": batch_index,
        "files": len(batch["files"]),
        "nodes": node_count,
        "edges": edge_count,
        "imports": actual_imports,
        "parts": written,
        "skipped": extracted.get("filesSkipped", []),
    }


def main():
    batches_doc = json.loads((INTERMEDIATE / "batches.json").read_text(encoding="utf-8-sig"))
    batch_by_index = {int(item["batchIndex"]): item for item in batches_doc["batches"]}
    reports = [build_batch(index, batch_by_index[index]) for index in (2, 4)]
    print(json.dumps(reports, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
