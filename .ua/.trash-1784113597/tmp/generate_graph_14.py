import json
import math
import re
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"
BATCH_INDEX = 14


FILE_INFO = {
    "cmake/sdk/base_settings/warnings.clang.cmake": (
        "Defines the Maxon SDK's Clang warning policy, separating enabled diagnostics from explicitly muted warnings for consistent plugin builds. / 定义 Maxon SDK 的 Clang 警告策略，将启用的诊断与显式屏蔽的警告分开，以保证插件构建一致性。",
        ["cmake", "build-system", "clang", "compiler-warnings"],
    ),
    "cmake/sdk/base_settings/warnings.gcc.cmake": (
        "Defines the Maxon SDK's GCC warning flags and targeted suppressions used by shared plugin targets. / 定义 Maxon SDK 的 GCC 警告标志与定向抑制项，供共享插件目标使用。",
        ["cmake", "build-system", "gcc", "compiler-warnings"],
    ),
    "cmake/sdk/base_settings/warnings.msvc.cmake": (
        "Defines the Maxon SDK's MSVC warning level, conformance diagnostics, and compatibility suppressions for Windows builds. / 定义 Maxon SDK 的 MSVC 警告级别、标准一致性诊断与 Windows 构建兼容性抑制项。",
        ["cmake", "build-system", "msvc", "compiler-warnings"],
    ),
    "cmake/sdk/commands/create_directory_symlink.cmake": (
        "Provides a CMake script-mode entry point that validates arguments and delegates directory-link creation to the shared target helpers. / 提供 CMake 脚本模式入口，校验参数后将目录链接创建委托给共享目标辅助函数。",
        ["cmake", "build-system", "script-entry-point", "filesystem"],
    ),
    "cmake/sdk/commands/update_filelist.cmake": (
        "Provides a CMake script-mode entry point that normalizes search directories and refreshes generated source file lists, with Xcode-specific change handling. / 提供 CMake 脚本模式入口，规范化搜索目录并刷新生成的源文件列表，同时处理 Xcode 特有的变更行为。",
        ["cmake", "build-system", "script-entry-point", "source-discovery"],
    ),
    "cmake/sdk/sdk_compiler_helper.cmake": (
        "Centralizes compiler detection, warning policies, ISA flags, compile definitions, RTTI and exception settings, link options, and framework linkage for Maxon SDK targets. / 集中管理 Maxon SDK 目标的编译器检测、警告策略、ISA 标志、编译定义、RTTI 与异常设置、链接选项及框架链接。",
        ["cmake", "build-system", "compiler-configuration", "toolchain", "linking"],
    ),
    "cmake/sdk/sdk_library_template.cmake": (
        "Template for generated Maxon SDK library projects, exposing platform, compiler, linker, source, framework, and prebuild placeholders before target configuration. / Maxon SDK 库项目生成模板，在配置目标前提供平台、编译器、链接器、源码、框架与预构建占位符。",
        ["cmake", "build-system", "template", "target-configuration"],
    ),
    "cmake/sdk/sdk_targets.cmake": (
        "Implements shared Maxon SDK target construction, source discovery and filtering, generated file lists, prebuild events, platform paths, framework/module targets, and output rules. / 实现共享 Maxon SDK 目标构建、源码发现与过滤、生成文件列表、预构建事件、平台路径、框架与模块目标及输出规则。",
        ["cmake", "build-system", "target-configuration", "source-discovery", "prebuild"],
    ),
    "cmake/sdk/sdk_update_projects.cmake": (
        "Parses Maxon project definitions and Bazel templates, resolves framework and custom paths, substitutes platform/configuration values, and generates or updates CMake projects. / 解析 Maxon 项目定义与 Bazel 模板，解析框架及自定义路径，替换平台与配置值，并生成或更新 CMake 项目。",
        ["cmake", "build-system", "project-generation", "template-processing", "frameworks"],
    ),
    "dependency/CMakeLists.txt": (
        "Defines the standalone dependency workflow that adds Bullet3 and libMMD, exposes a build aggregate, and optionally runs the focused libMMD CTest targets. / 定义独立依赖工作流，引入 Bullet3 与 libMMD，提供聚合构建目标，并可选运行聚焦的 libMMD CTest 目标。",
        ["build-system", "dependency-management", "libmmd", "bullet", "testing"],
    ),
    "res/R20-S24/c4d_symbols.h": (
        "Declares legacy R20-S24 Cinema 4D string, command, dialog, and plugin symbol identifiers shared by the resource system. / 声明旧版 R20-S24 Cinema 4D 资源系统共享的字符串、命令、对话框与插件符号标识符。",
        ["cinema-4d", "resource-id", "legacy-sdk", "localization"],
    ),
    "res/R20-S24/description/OMMDBoneManager.h": (
        "Declares legacy description identifiers for bone-manager display controls, hierarchy refresh, and bone mode parameters. / 声明骨骼管理器显示控制、层级刷新与骨骼模式参数的旧版描述标识符。",
        ["cinema-4d", "resource-id", "bone-manager", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDBoneManager.res": (
        "Defines the legacy Cinema 4D description layout for bone-manager display, hierarchy, and mode controls. / 定义骨骼管理器显示、层级与模式控制的旧版 Cinema 4D 描述布局。",
        ["cinema-4d", "resource-definition", "bone-manager", "ui", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDCamera.h": (
        "Declares legacy description identifiers for the MMD camera object's parameters. / 声明 MMD 相机对象参数的旧版描述标识符。",
        ["cinema-4d", "resource-id", "camera", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDCamera.res": (
        "Defines the minimal legacy Cinema 4D description container for the MMD camera object. / 定义 MMD 相机对象的最小旧版 Cinema 4D 描述容器。",
        ["cinema-4d", "resource-definition", "camera", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDJoint.h": (
        "Declares legacy description identifiers for joint transforms, constraint limits, spring parameters, display, and physics modes. / 声明关节变换、约束限制、弹簧参数、显示与物理模式的旧版描述标识符。",
        ["cinema-4d", "resource-id", "joint", "physics", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDJoint.res": (
        "Defines the legacy joint-object UI for transforms, linear and angular limits, spring settings, display options, and physics behavior. / 定义旧版关节对象 UI，包括变换、线性与角度限制、弹簧设置、显示选项及物理行为。",
        ["cinema-4d", "resource-definition", "joint", "physics", "ui"],
    ),
    "res/R20-S24/description/OMMDJointManager.h": (
        "Declares legacy description identifiers for joint-manager list, display, and mode controls. / 声明关节管理器列表、显示与模式控制的旧版描述标识符。",
        ["cinema-4d", "resource-id", "joint-manager", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDJointManager.res": (
        "Defines the legacy Cinema 4D description layout for joint-manager list, display, and mode controls. / 定义关节管理器列表、显示与模式控制的旧版 Cinema 4D 描述布局。",
        ["cinema-4d", "resource-definition", "joint-manager", "ui", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDMeshManager.h": (
        "Declares legacy description identifiers for mesh-manager display, mesh mode, and morph mode controls. / 声明网格管理器显示、网格模式与变形模式控制的旧版描述标识符。",
        ["cinema-4d", "resource-id", "mesh-manager", "morph", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDMeshManager.res": (
        "Defines the legacy Cinema 4D description layout for mesh-manager display, edit mode, and morph controls. / 定义网格管理器显示、编辑模式与变形控制的旧版 Cinema 4D 描述布局。",
        ["cinema-4d", "resource-definition", "mesh-manager", "morph", "ui"],
    ),
    "res/R20-S24/description/OMMDModelManager.h": (
        "Declares legacy description identifiers for model metadata, animation slots, morph/material editing, display frames, physics, and import/export controls. / 声明模型元数据、动画槽、变形与材质编辑、显示框、物理及导入导出控制的旧版描述标识符。",
        ["cinema-4d", "resource-id", "model-manager", "animation", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDModelManager.res": (
        "Defines the comprehensive legacy model-manager UI for metadata, animation, morphs, materials, display frames, physics, and model operations. / 定义完整的旧版模型管理器 UI，涵盖元数据、动画、变形、材质、显示框、物理与模型操作。",
        ["cinema-4d", "resource-definition", "model-manager", "animation", "ui"],
    ),
    "res/R20-S24/description/OMMDRigid.h": (
        "Declares legacy description identifiers for rigid-body naming, transforms, shapes, collision groups, dynamics, display, and modes. / 声明刚体命名、变换、形状、碰撞组、动力学、显示与模式的旧版描述标识符。",
        ["cinema-4d", "resource-id", "rigid-body", "physics", "legacy-sdk"],
    ),
    "res/R20-S24/description/OMMDRigid.res": (
        "Defines the legacy rigid-body object UI for transforms, collision shapes and groups, dynamics, display options, and editing modes. / 定义旧版刚体对象 UI，包括变换、碰撞形状与分组、动力学、显示选项及编辑模式。",
        ["cinema-4d", "resource-definition", "rigid-body", "physics", "ui"],
    ),
}


DOMAINS = {
    "cmake/sdk/sdk_compiler_helper.cmake": ("shared compiler and linker configuration", "共享编译器与链接器配置"),
    "cmake/sdk/sdk_targets.cmake": ("Maxon SDK target and source orchestration", "Maxon SDK 目标与源码编排"),
    "cmake/sdk/sdk_update_projects.cmake": ("Maxon project parsing and CMake generation", "Maxon 项目解析与 CMake 生成"),
}


VERBS = [
    ("Initialize", "initializes", "初始化"), ("Configure", "configures", "配置"),
    ("Transform", "transforms", "转换"), ("Normalize", "normalizes", "规范化"),
    ("Replace", "replaces", "替换"), ("Collect", "collects", "收集"),
    ("Compose", "composes", "组合"), ("Combine", "combines", "组合"),
    ("Process", "processes", "处理"), ("Execute", "executes", "执行"),
    ("Configure", "configures", "配置"), ("Create", "creates", "创建"),
    ("Update", "updates", "更新"), ("Save", "saves", "保存"),
    ("Load", "loads", "加载"), ("Filter", "filters", "过滤"),
    ("Ignore", "excludes", "排除"), ("Strip", "strips", "清理"),
    ("Parse", "parses", "解析"), ("Fix", "fixes", "修正"),
    ("Setup", "sets up", "设置"), ("Enable", "enables", "启用"),
    ("Set", "sets", "设置"), ("Get", "retrieves", "获取"),
    ("Has", "checks", "检查"), ("Is", "checks", "检查"),
    ("Make", "makes", "生成"), ("Add", "adds", "添加"),
    ("Read", "reads", "读取"), ("Link", "links", "链接"),
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


def parse_cmake_functions(path):
    lines = (ROOT / path).read_text(encoding="utf-8-sig", errors="replace").splitlines()
    starts = re.compile(r"^\s*(function|macro)\s*\(\s*([^\s\)]+)", re.IGNORECASE)
    ends = {"function": re.compile(r"^\s*endfunction\b", re.IGNORECASE), "macro": re.compile(r"^\s*endmacro\b", re.IGNORECASE)}
    found = []
    active = None
    for index, line in enumerate(lines, start=1):
        match = starts.search(line)
        if match:
            if active is not None:
                raise RuntimeError(f"Nested CMake definition in {path}:{index}")
            active = {"kind": match.group(1).lower(), "name": match.group(2), "startLine": index}
            continue
        if active and ends[active["kind"]].search(line):
            active["endLine"] = index
            found.append(active)
            active = None
    if active:
        raise RuntimeError(f"Unclosed CMake definition in {path}:{active['startLine']}")
    return found


def function_summary(name, path):
    domain_en, domain_zh = DOMAINS[path]
    short = name
    for prefix in ("MaxonCompilerHelper_", "MaxonTargets_", "MaxonUpdateProjects_"):
        if short.startswith(prefix):
            short = short[len(prefix):]
            break
    for prefix, en_verb, zh_verb in VERBS:
        if short.startswith(prefix):
            topic = humanize(short[len(prefix):]) or "shared state"
            return f"{name} {en_verb} {topic} for {domain_en}. / {name} 为{domain_zh}{zh_verb} {topic}。"
    return f"{name} performs a focused operation for {domain_en}. / {name} 为{domain_zh}执行专用操作。"


def function_tags(path, name, kind):
    tags = ["cmake", "build-system", "macro" if kind == "macro" else "function"]
    low = name.lower()
    if "compiler" in low or "compile" in low:
        tags.append("compiler-configuration")
    elif "framework" in low or "link" in low:
        tags.append("linking")
    elif "file" in low or "source" in low:
        tags.append("source-discovery")
    elif "project" in low or "template" in low:
        tags.append("project-generation")
    else:
        tags.append("target-configuration")
    return tags[:5]


def main():
    batches_doc = json.loads((INTERMEDIATE / "batches.json").read_text(encoding="utf-8-sig"))
    batch = next(item for item in batches_doc["batches"] if int(item["batchIndex"]) == BATCH_INDEX)
    extracted = json.loads((UA / "tmp" / "ua-file-extract-results-14.json").read_text(encoding="utf-8-sig"))
    if not extracted.get("scriptCompleted") or len(extracted.get("results", [])) != len(batch["files"]):
        raise RuntimeError("Batch 14 extraction completeness check failed")
    result_by_path = {item["path"]: item for item in extracted["results"]}

    nodes = []
    edges = []
    ids = set()
    for spec in batch["files"]:
        path = spec["path"]
        result = result_by_path[path]
        summary, tags = FILE_INFO[path]
        if spec["fileCategory"] == "docs":
            node_type = "document"
            node_id = f"document:{path}"
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
            if path.endswith(".cmake"):
                node["languageNotes"] = "CMake functions pass results through scoped variables and PARENT_SCOPE while coordinating generator- and platform-specific behavior. / CMake 函数通过作用域变量与 PARENT_SCOPE 传递结果，并协调生成器及平台特定行为。"
            else:
                node["languageNotes"] = "Cinema 4D resource syntax separates numeric identifiers from declarative description layouts consumed by legacy SDK versions. / Cinema 4D 资源语法将数值标识符与旧版 SDK 使用的声明式描述布局分离。"
        nodes.append(node)
        ids.add(node_id)

        if path in DOMAINS:
            for definition in parse_cmake_functions(path):
                name = definition["name"]
                function_id = f"function:{path}:{name}"
                if function_id in ids:
                    raise RuntimeError(f"Duplicate node id: {function_id}")
                span = definition["endLine"] - definition["startLine"] + 1
                nodes.append({
                    "id": function_id,
                    "type": "function",
                    "name": name,
                    "filePath": path,
                    "lineRange": [definition["startLine"], definition["endLine"]],
                    "summary": function_summary(name, path),
                    "tags": function_tags(path, name, definition["kind"]),
                    "complexity": symbol_complexity(span),
                })
                ids.add(function_id)
                edges.append({"source": node_id, "target": function_id, "type": "contains", "direction": "forward", "weight": 1.0})
                edges.append({"source": node_id, "target": function_id, "type": "exports", "direction": "forward", "weight": 0.8})

    expected_imports = sum(len(batch["batchImportData"].get(spec["path"], [])) for spec in batch["files"])
    for spec in batch["files"]:
        path = spec["path"]
        source_prefix = "document" if spec["fileCategory"] == "docs" else "file"
        for target in batch["batchImportData"].get(path, []):
            edges.append({"source": f"{source_prefix}:{path}", "target": f"file:{target}", "type": "imports", "direction": "forward", "weight": 0.7})
    actual_imports = sum(edge["type"] == "imports" for edge in edges)
    if actual_imports != expected_imports:
        raise RuntimeError(f"Import mismatch: {actual_imports} != {expected_imports}")

    parts = 1 if len(nodes) <= 60 and len(edges) <= 120 else math.ceil(max(len(nodes) / 60, len(edges) / 120))
    sorted_paths = sorted(spec["path"] for spec in batch["files"])
    chunk_size = math.ceil(len(sorted_paths) / parts)
    groups = [sorted_paths[i:i + chunk_size] for i in range(0, len(sorted_paths), chunk_size)]

    for old in INTERMEDIATE.glob("batch-14.json"):
        old.unlink()
    for old in INTERMEDIATE.glob("batch-14-part-*.json"):
        old.unlink()

    written = []
    for number, group in enumerate(groups, start=1):
        group_set = set(group)
        part_nodes = [node for node in nodes if node.get("filePath") in group_set]
        part_ids = {node["id"] for node in part_nodes}
        part_edges = [edge for edge in edges if edge["source"] in part_ids]
        for edge in part_edges:
            if edge["source"] not in part_ids or edge["target"] not in part_ids:
                raise RuntimeError(f"Invalid edge in batch 14 part {number}: {edge}")
        payload = {"nodes": part_nodes, "edges": part_edges}
        output = INTERMEDIATE / ("batch-14.json" if len(groups) == 1 else f"batch-14-part-{number}.json")
        output.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        checked = json.loads(output.read_text(encoding="utf-8"))
        if not isinstance(checked.get("nodes"), list) or not isinstance(checked.get("edges"), list):
            raise RuntimeError(f"JSON validation failed for {output.name}")
        written.append({"name": output.name, "nodes": len(part_nodes), "edges": len(part_edges)})

    report = {
        "batch": BATCH_INDEX,
        "files": len(batch["files"]),
        "nodes": len(nodes),
        "edges": len(edges),
        "imports": actual_imports,
        "parts": written,
        "skipped": extracted.get("filesSkipped", []),
    }
    print(json.dumps(report, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
