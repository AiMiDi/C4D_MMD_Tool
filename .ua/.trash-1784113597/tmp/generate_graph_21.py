import json
import math
import re
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"
BATCH_INDEX = 21


BASE_SETTINGS = {
    "compile_definitions.cmake": (
        "Defines shared SDK 2026 preprocessor symbols for 64-bit, debug/release, and Windows plugin builds. / 定义 SDK 2026 的共享预处理符号，用于 64 位、调试/发布及 Windows 插件构建。",
        ["cmake", "sdk-2026", "compiler-configuration", "preprocessor"],
    ),
    "compile_options.cmake": (
        "Defines SDK 2026 compiler and ISA options for MSVC, ClangCL, Apple Clang, GCC, Objective-C, debug/release modes, x64, and ARM64. / 定义 SDK 2026 面向 MSVC、ClangCL、Apple Clang、GCC、Objective-C、调试/发布模式、x64 与 ARM64 的编译器和 ISA 选项。",
        ["cmake", "sdk-2026", "compiler-configuration", "toolchain", "isa"],
    ),
    "link_options.cmake": (
        "Defines SDK 2026 platform and configuration-specific linker options, debug information policy, and Linux linker selection. / 定义 SDK 2026 的平台与配置特定链接器选项、调试信息策略及 Linux 链接器选择。",
        ["cmake", "sdk-2026", "linking", "toolchain"],
    ),
    "sanitize.cmake": (
        "Defines SDK 2026 AddressSanitizer compile definitions, compiler flags, and linker options for supported release-mode toolchains. / 定义 SDK 2026 在受支持发布模式工具链中的 AddressSanitizer 编译定义、编译器标志与链接器选项。",
        ["cmake", "sdk-2026", "sanitizer", "security", "toolchain"],
    ),
    "warnings.clang.cmake": (
        "Defines the SDK 2026 Clang warning policy, separating enabled diagnostics from explicitly muted compatibility warnings. / 定义 SDK 2026 的 Clang 警告策略，将启用的诊断与显式屏蔽的兼容性警告分开。",
        ["cmake", "sdk-2026", "clang", "compiler-warnings"],
    ),
    "warnings.gcc.cmake": (
        "Defines the SDK 2026 GCC warning flags and targeted suppressions used by shared plugin targets. / 定义 SDK 2026 的 GCC 警告标志与定向抑制项，供共享插件目标使用。",
        ["cmake", "sdk-2026", "gcc", "compiler-warnings"],
    ),
    "warnings.msvc.cmake": (
        "Defines the SDK 2026 MSVC warning level, conformance diagnostics, and compatibility suppressions for Windows builds. / 定义 SDK 2026 的 MSVC 警告级别、标准一致性诊断与 Windows 构建兼容性抑制项。",
        ["cmake", "sdk-2026", "msvc", "compiler-warnings"],
    ),
}


VERBS = [
    ("Initialize", "initializes", "初始化"), ("Configure", "configures", "配置"),
    ("Transform", "transforms", "转换"), ("Normalize", "normalizes", "规范化"),
    ("Replace", "replaces", "替换"), ("Collect", "collects", "收集"),
    ("Compose", "composes", "组合"), ("Combine", "combines", "组合"),
    ("Process", "processes", "处理"), ("Execute", "executes", "执行"),
    ("Create", "creates", "创建"), ("Update", "updates", "更新"),
    ("Save", "saves", "保存"), ("Load", "loads", "加载"),
    ("Filter", "filters", "过滤"), ("Ignore", "excludes", "排除"),
    ("Strip", "strips", "清理"), ("Parse", "parses", "解析"),
    ("Fix", "fixes", "修正"), ("Setup", "sets up", "设置"),
    ("Enable", "enables", "启用"), ("Set", "sets", "设置"),
    ("Get", "retrieves", "获取"), ("Has", "checks", "检查"),
    ("Is", "checks", "检查"), ("Make", "makes", "生成"),
    ("Add", "adds", "添加"), ("Read", "reads", "读取"),
    ("Link", "links", "链接"),
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


def version_for(path):
    if path.startswith("sdk_2025/"):
        return "SDK 2025", "SDK 2025", "sdk-2025"
    if path.startswith("sdk_2026/"):
        return "SDK 2026", "SDK 2026", "sdk-2026"
    return "Cinema 4D R20 SDK", "Cinema 4D R20 SDK", "sdk-r20"


def file_info(path):
    version_en, version_zh, version_tag = version_for(path)
    name = Path(path).name
    if "/base_settings/" in path:
        return BASE_SETTINGS[name]
    if path.endswith("cmake/sdk_library_template.cmake"):
        return (
            f"Template for generated {version_en} library projects, exposing platform, compiler, linker, source, framework, and prebuild placeholders before target configuration. / {version_zh} 库项目生成模板，在配置目标前提供平台、编译器、链接器、源码、框架与预构建占位符。",
            ["cmake", version_tag, "template", "target-configuration"],
        )
    if path.endswith("cmake/sdk_targets.cmake"):
        return (
            f"Implements {version_en} target construction, source discovery and filtering, generated file lists, prebuild events, platform paths, framework/module targets, and output rules. / 实现 {version_zh} 的目标构建、源码发现与过滤、生成文件列表、预构建事件、平台路径、框架与模块目标及输出规则。",
            ["cmake", version_tag, "target-configuration", "source-discovery", "prebuild"],
        )
    if path.endswith("cmake/sdk_update_projects.cmake"):
        return (
            f"Parses {version_en} project definitions and templates, resolves framework and custom paths, substitutes platform/configuration values, and generates or updates CMake projects. / 解析 {version_zh} 项目定义与模板，解析框架及自定义路径，替换平台与配置值，并生成或更新 CMake 项目。",
            ["cmake", version_tag, "project-generation", "template-processing", "frameworks"],
        )
    if path.endswith("cmake/sdk_compiler_helper.cmake"):
        return (
            f"Centralizes compiler detection, warning policies, ISA flags, compile definitions, RTTI and exception settings, link options, and framework linkage for {version_en} targets. / 集中管理 {version_zh} 目标的编译器检测、警告策略、ISA 标志、编译定义、RTTI 与异常设置、链接选项及框架链接。",
            ["cmake", version_tag, "compiler-configuration", "toolchain", "linking"],
        )
    if path.endswith("cmake/commands/create_directory_symlink.cmake"):
        return (
            f"Provides a {version_en} CMake script-mode entry point that validates arguments and delegates directory-link creation to shared target helpers. / 提供 {version_zh} CMake 脚本模式入口，校验参数后将目录链接创建委托给共享目标辅助函数。",
            ["cmake", version_tag, "script-entry-point", "filesystem"],
        )
    if path.endswith("cmake/commands/update_filelist.cmake"):
        return (
            f"Provides a {version_en} CMake script-mode entry point that normalizes search directories and refreshes generated source file lists. / 提供 {version_zh} CMake 脚本模式入口，规范化搜索目录并刷新生成的源文件列表。",
            ["cmake", version_tag, "script-entry-point", "source-discovery"],
        )
    if path.endswith("plugins/mmdtool/project/CMakeLists.txt"):
        if version_tag == "sdk-r20":
            detail_en = "selects the R20-S24 resource tree, narrows generated registration sources, and adds legacy framework headers"
            detail_zh = "选择 R20-S24 资源树，收窄生成的注册源码，并加入旧版框架头文件"
        else:
            detail_en = "uses the shared source and S24+ resource trees"
            detail_zh = "使用共享源码树与 S24+ 资源树"
        return (
            f"Thin {version_en} mmdtool wrapper that adds shared dependencies and plugin setup, resolves the project/module roots, and {detail_en}. / 精简的 {version_zh} mmdtool 包装层，引入共享依赖与插件设置，解析项目及模块根目录，并{detail_zh}。",
            ["documentation", "cmake", version_tag, "plugin-build", "thin-wrapper"],
        )
    if path.endswith("plugins/mmdtool/project/projectdefinition.txt"):
        return (
            f"Maxon project metadata for the {version_en} mmdtool DLL, declaring supported platforms, Cinema 4D framework dependencies, component status, module ID, and style-check policy. / {version_zh} mmdtool DLL 的 Maxon 项目元数据，声明支持平台、Cinema 4D 框架依赖、组件状态、模块 ID 与样式检查策略。",
            ["documentation", version_tag, "project-metadata", "frameworks", "plugin-build"],
        )
    if path.endswith("sdk_r20/cmake/sdk_compat_r20.cmake"):
        return (
            "Defines conservative R20 compatibility defaults: C++17, parallel and permissive MSVC compilation, AVX baseline instructions, and reduced warning noise. / 定义保守的 R20 兼容默认值：C++17、MSVC 并行与宽松编译、AVX 基线指令以及降低警告噪声。",
            ["cmake", "sdk-r20", "compatibility", "msvc", "toolchain"],
        )
    if path.endswith("sdk_r20/CMakeLists.txt"):
        return (
            "R20 bridge build definition that reuses shared Maxon tooling, discovers plugin module paths, configures output directories, and loads only frameworks required by participating modules. / R20 桥接构建定义，复用共享 Maxon 工具链，发现插件模块路径，配置输出目录，并仅加载参与模块所需框架。",
            ["documentation", "cmake", "sdk-r20", "build-system", "frameworks"],
        )
    if path.endswith("sdk_r20/CMakePresets.json"):
        return (
            "Defines R20 configure presets for Linux Ninja, x86_64 macOS Xcode, Visual Studio 2022 v143, and Visual Studio ClangCL builds. / 定义 R20 的 Linux Ninja、x86_64 macOS Xcode、Visual Studio 2022 v143 与 Visual Studio ClangCL 配置预设。",
            ["configuration", "cmake-presets", "sdk-r20", "cross-platform"],
        )
    raise KeyError(path)


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


def humanize(text):
    text = text.replace("_", " ").strip()
    words = re.findall(r"[A-Z]+(?=[A-Z][a-z]|\d|$)|[A-Z]?[a-z]+|\d+", text)
    return " ".join(words).lower() if words else text.lower()


def function_summary(name, path):
    version_en, version_zh, _ = version_for(path)
    if "sdk_compiler_helper" in path:
        domain_en, domain_zh = f"{version_en} compiler and linker configuration", f"{version_zh} 编译器与链接器配置"
    elif "sdk_targets" in path:
        domain_en, domain_zh = f"{version_en} target and source orchestration", f"{version_zh} 目标与源码编排"
    else:
        domain_en, domain_zh = f"{version_en} project parsing and CMake generation", f"{version_zh} 项目解析与 CMake 生成"
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


def function_tags(path, definition):
    _, _, version_tag = version_for(path)
    name = definition["name"].lower()
    tags = ["cmake", version_tag, "macro" if definition["kind"] == "macro" else "function"]
    if "compiler" in name or "compile" in name:
        tags.append("compiler-configuration")
    elif "framework" in name or "link" in name:
        tags.append("linking")
    elif "file" in name or "source" in name:
        tags.append("source-discovery")
    elif "project" in name or "template" in name:
        tags.append("project-generation")
    else:
        tags.append("target-configuration")
    return tags[:5]


def main():
    batches_doc = json.loads((INTERMEDIATE / "batches.json").read_text(encoding="utf-8-sig"))
    batch = next(item for item in batches_doc["batches"] if int(item["batchIndex"]) == BATCH_INDEX)
    extracted = json.loads((UA / "tmp" / "ua-file-extract-results-21.json").read_text(encoding="utf-8-sig"))
    if not extracted.get("scriptCompleted") or len(extracted.get("results", [])) != len(batch["files"]):
        raise RuntimeError("Batch 21 extraction completeness check failed")
    result_by_path = {item["path"]: item for item in extracted["results"]}

    nodes = []
    edges = []
    ids = set()
    for spec in batch["files"]:
        path = spec["path"]
        result = result_by_path[path]
        summary, tags = file_info(path)
        if spec["fileCategory"] == "docs":
            node_type, node_id = "document", f"document:{path}"
        elif spec["fileCategory"] == "config":
            node_type, node_id = "config", f"config:{path}"
        else:
            node_type, node_id = "file", f"file:{path}"
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
            node["languageNotes"] = "CMake functions pass results through scoped variables and PARENT_SCOPE while coordinating generator-, platform-, and configuration-specific behavior. / CMake 函数通过作用域变量与 PARENT_SCOPE 传递结果，并协调生成器、平台与配置特定行为。"
        nodes.append(node)
        ids.add(node_id)

        if path.endswith(("sdk_compiler_helper.cmake", "sdk_targets.cmake", "sdk_update_projects.cmake")):
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
                    "tags": function_tags(path, definition),
                    "complexity": symbol_complexity(span),
                })
                ids.add(function_id)
                edges.append({"source": node_id, "target": function_id, "type": "contains", "direction": "forward", "weight": 1.0})
                edges.append({"source": node_id, "target": function_id, "type": "exports", "direction": "forward", "weight": 0.8})

    expected_imports = sum(len(batch["batchImportData"].get(spec["path"], [])) for spec in batch["files"])
    for spec in batch["files"]:
        path = spec["path"]
        if spec["fileCategory"] == "docs":
            prefix = "document"
        elif spec["fileCategory"] == "config":
            prefix = "config"
        else:
            prefix = "file"
        for target in batch["batchImportData"].get(path, []):
            edges.append({"source": f"{prefix}:{path}", "target": f"file:{target}", "type": "imports", "direction": "forward", "weight": 0.7})
    actual_imports = sum(edge["type"] == "imports" for edge in edges)
    if actual_imports != expected_imports:
        raise RuntimeError(f"Import mismatch: {actual_imports} != {expected_imports}")

    node_count, edge_count = len(nodes), len(edges)
    parts = 1 if node_count <= 60 and edge_count <= 120 else math.ceil(max(node_count / 60, edge_count / 120))
    sorted_paths = sorted(spec["path"] for spec in batch["files"])
    chunk_size = math.ceil(len(sorted_paths) / parts)
    groups = [sorted_paths[i:i + chunk_size] for i in range(0, len(sorted_paths), chunk_size)]

    for old in INTERMEDIATE.glob("batch-21.json"):
        old.unlink()
    for old in INTERMEDIATE.glob("batch-21-part-*.json"):
        old.unlink()

    written = []
    for number, group in enumerate(groups, start=1):
        group_set = set(group)
        part_nodes = [node for node in nodes if node.get("filePath") in group_set]
        part_ids = {node["id"] for node in part_nodes}
        part_edges = [edge for edge in edges if edge["source"] in part_ids]
        for edge in part_edges:
            if edge["source"] not in part_ids or edge["target"] not in part_ids:
                raise RuntimeError(f"Invalid edge in batch 21 part {number}: {edge}")
        output = INTERMEDIATE / ("batch-21.json" if len(groups) == 1 else f"batch-21-part-{number}.json")
        output.write_text(json.dumps({"nodes": part_nodes, "edges": part_edges}, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        checked = json.loads(output.read_text(encoding="utf-8"))
        if not isinstance(checked.get("nodes"), list) or not isinstance(checked.get("edges"), list):
            raise RuntimeError(f"JSON validation failed for {output.name}")
        written.append({"name": output.name, "nodes": len(part_nodes), "edges": len(part_edges)})

    print(json.dumps({
        "batch": BATCH_INDEX,
        "files": len(batch["files"]),
        "nodes": node_count,
        "edges": edge_count,
        "imports": actual_imports,
        "parts": written,
        "skipped": extracted.get("filesSkipped", []),
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
