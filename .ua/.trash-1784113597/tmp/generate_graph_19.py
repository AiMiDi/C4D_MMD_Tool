import json
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"
BATCH_INDEX = 19


COMPONENTS = {
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


FILE_INFO = {
    "scripts/build_macos.sh": (
        "Builds one or all supported Cinema 4D SDK plugin variants on macOS by validating the Xcode toolchain, staging SDK sources, selecting architectures, recovering libMMD when needed, configuring CMake, and invoking cmt-workflow. / 在 macOS 上构建一个或全部受支持的 Cinema 4D SDK 插件版本，负责校验 Xcode 工具链、暂存 SDK 源码、选择架构、按需恢复 libMMD、配置 CMake 并调用 cmt-workflow。",
        ["build-script", "macos", "cmake", "multi-sdk", "dependency-management"],
    ),
    "sdk_2023/cmake/sdk_compat_2023.cmake": (
        "Defines conservative SDK 2023 compatibility defaults: C++20, parallel and permissive MSVC compilation, AVX baseline instructions, and reduced warning noise. / 定义保守的 SDK 2023 兼容默认值：C++20、MSVC 并行与宽松编译、AVX 基线指令以及降低警告噪声。",
        ["cmake", "sdk-2023", "compatibility", "msvc", "toolchain"],
    ),
    "sdk_2023/CMakeLists.txt": (
        "SDK 2023 bridge build definition that reuses the shared Maxon tooling, discovers plugin module paths, configures output directories, and loads only the frameworks required by participating modules. / SDK 2023 桥接构建定义，复用共享 Maxon 工具链，发现插件模块路径，配置输出目录，并仅加载参与模块所需的框架。",
        ["documentation", "cmake", "sdk-2023", "build-system", "frameworks"],
    ),
    "sdk_2023/CMakePresets.json": (
        "Defines SDK 2023 configure presets for Linux Ninja, universal macOS Xcode, Visual Studio 2022 v143, and Visual Studio ClangCL builds. / 定义 SDK 2023 的 Linux Ninja、macOS 通用 Xcode、Visual Studio 2022 v143 与 Visual Studio ClangCL 配置预设。",
        ["configuration", "cmake-presets", "sdk-2023", "cross-platform"],
    ),
    "sdk_2023/plugins/mmdtool/project/CMakeLists.txt": (
        "Thin SDK 2023 plugin wrapper that resolves the shared project root, adds libMMD dependencies, includes common plugin setup, and supplies SDK framework source paths and dependencies. / 精简的 SDK 2023 插件包装层，解析共享项目根目录，引入 libMMD 依赖，包含通用插件设置，并提供 SDK 框架源码路径与依赖项。",
        ["documentation", "cmake", "sdk-2023", "plugin-build", "thin-wrapper"],
    ),
    "sdk_2023/plugins/mmdtool/project/mmdtool.vcxproj": (
        "Generated Visual Studio project for the SDK 2023 mmdtool module, defining configurations, toolsets, SDK properties, source items, framework references, and plugin outputs. / 为 SDK 2023 mmdtool 模块生成的 Visual Studio 项目，定义配置、工具集、SDK 属性、源码项、框架引用与插件输出。",
        ["visual-studio", "sdk-2023", "generated-project", "msbuild", "plugin-build"],
    ),
    "sdk_2023/plugins/mmdtool/project/mmdtool.vcxproj.filters": (
        "Defines Visual Studio Solution Explorer filters that group the generated SDK 2023 plugin sources and resources. / 定义 Visual Studio 解决方案资源管理器筛选器，用于组织生成的 SDK 2023 插件源码与资源。",
        ["visual-studio", "sdk-2023", "generated-project", "ide-metadata"],
    ),
    "sdk_2023/plugins/mmdtool/project/mmdtool.vcxproj.user": (
        "Provides an intentionally empty per-user Visual Studio settings file for the SDK 2023 plugin project. / 为 SDK 2023 插件项目提供刻意留空的 Visual Studio 用户级设置文件。",
        ["visual-studio", "sdk-2023", "user-settings", "ide-metadata"],
    ),
    "sdk_2023/plugins/mmdtool/project/mmdtool.xcodeproj/project.pbxproj": (
        "Generated Xcode project model for the SDK 2023 plugin, including file references, build phases, target dependencies, configurations, architecture settings, and plugin product output. / 为 SDK 2023 插件生成的 Xcode 项目模型，包含文件引用、构建阶段、目标依赖、配置、架构设置与插件产品输出。",
        ["xcode", "sdk-2023", "generated-project", "macos", "plugin-build"],
    ),
    "sdk_2023/plugins/mmdtool/project/projectdefinition.txt": (
        "Maxon project metadata for the SDK 2023 mmdtool DLL, declaring Windows/macOS platforms, required Cinema 4D frameworks, component status, module ID, and style-check policy. / SDK 2023 mmdtool DLL 的 Maxon 项目元数据，声明 Windows/macOS 平台、所需 Cinema 4D 框架、组件状态、模块 ID 与样式检查策略。",
        ["documentation", "sdk-2023", "project-metadata", "frameworks", "plugin-build"],
    ),
    "sdk_2023/plugins/mmdtool/project/projectsettings.props": (
        "MSBuild property sheet that anchors the SDK 2023 Maxon root directory and injects the USE_API_MAXON preprocessor definition. / MSBuild 属性表，用于定位 SDK 2023 Maxon 根目录并注入 USE_API_MAXON 预处理定义。",
        ["msbuild", "sdk-2023", "project-settings", "compiler-configuration"],
    ),
    "sdk_2023/plugins/project/projectdefinition.txt": (
        "Solution-level Maxon project metadata that groups the SDK 2023 mmdtool plugin for Windows and macOS generation. / 解决方案级 Maxon 项目元数据，用于在 Windows 与 macOS 生成流程中组织 SDK 2023 mmdtool 插件。",
        ["documentation", "sdk-2023", "solution-metadata", "project-generation"],
    ),
    "sdk_2024/cmake/commands/create_directory_symlink.cmake": (
        "Compatibility forwarding shim that includes the shared directory-symlink CMake script for SDK 2024. / 兼容性转发垫片，为 SDK 2024 引入共享目录符号链接 CMake 脚本。",
        ["cmake", "sdk-2024", "compatibility", "filesystem"],
    ),
    "sdk_2024/cmake/commands/update_filelist.cmake": (
        "Compatibility forwarding shim that includes the shared generated-file-list updater for SDK 2024. / 兼容性转发垫片，为 SDK 2024 引入共享生成文件列表更新器。",
        ["cmake", "sdk-2024", "compatibility", "source-discovery"],
    ),
    "sdk_2024/cmake/sdk_compat_2024.cmake": (
        "Defines conservative SDK 2024 compatibility defaults: C++20, permissive parallel MSVC compilation, AVX baseline instructions, and reduced warning noise. / 定义保守的 SDK 2024 兼容默认值：C++20、MSVC 宽松并行编译、AVX 基线指令以及降低警告噪声。",
        ["cmake", "sdk-2024", "compatibility", "msvc", "toolchain"],
    ),
}


FUNCTION_INFO = {
    "usage": (
        "Prints the macOS build command syntax and supported environment overrides, including SDK, generator, architecture, compiler, build directory, and libMMD options. / 输出 macOS 构建命令语法与支持的环境变量覆盖项，包括 SDK、生成器、架构、编译器、构建目录与 libMMD 选项。",
        ["cli", "help", "build-script"],
    ),
    "prepare_sdk_source": (
        "Stages an SDK tree under the build directory, links the shared CMake tooling, excludes tracked plugin source/resource links, and returns the isolated SDK path. / 将 SDK 树暂存到构建目录，链接共享 CMake 工具链，排除受版本控制的插件源码与资源链接，并返回隔离后的 SDK 路径。",
        ["sdk-staging", "filesystem", "build-script"],
    ),
    "reset_sdk_build_dir_if_needed": (
        "Compares the cached CMake source directory with the staged SDK path and removes stale generated output when the source location changes. / 比较缓存的 CMake 源目录与暂存 SDK 路径，并在源码位置变化时移除过期生成输出。",
        ["cmake-cache", "build-directory", "validation"],
    ),
    "build_sdk": (
        "Configures a staged SDK with the selected macOS toolchain, architecture, generator, and libMMD source, then builds the mmdtool target through the root cmt-workflow. / 使用选定的 macOS 工具链、架构、生成器与 libMMD 源码配置暂存 SDK，随后通过根级 cmt-workflow 构建 mmdtool 目标。",
        ["cmake", "macos", "multi-sdk", "build-orchestration"],
    ),
}


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


def localized_info(path):
    filename = Path(path).stem
    component_en, component_zh, tag = COMPONENTS[filename]
    return (
        f"Provides Simplified Chinese Cinema 4D resource labels for {component_en} in the S24-and-newer resource tree. / 为 S24 及更新版本资源树中的{component_zh}提供简体中文 Cinema 4D 资源标签。",
        ["localization", "zh-cn", "cinema-4d", tag, "current-sdk"],
    )


def file_info(path):
    if path.startswith("res/S24_up/strings_zh-CN/"):
        return localized_info(path)
    return FILE_INFO[path]


def main():
    batches = json.loads((INTERMEDIATE / "batches.json").read_text(encoding="utf-8-sig"))
    batch = next(item for item in batches["batches"] if int(item["batchIndex"]) == BATCH_INDEX)
    extracted = json.loads((UA / "tmp" / "ua-file-extract-results-19.json").read_text(encoding="utf-8-sig"))
    if not extracted.get("scriptCompleted") or len(extracted.get("results", [])) != len(batch["files"]):
        raise RuntimeError("Batch 19 extraction completeness check failed")
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
            if path.endswith(".sh"):
                node["languageNotes"] = "The Bash workflow uses strict error handling, array-safe argument construction, isolated SDK staging, and build-only Git worktrees for dependency recovery. / 该 Bash 工作流使用严格错误处理、数组安全的参数构造、隔离 SDK 暂存以及仅用于构建的 Git worktree 来恢复依赖。"
            elif path.endswith(".pbxproj") or path.endswith(".vcxproj"):
                node["languageNotes"] = "Generated IDE metadata mirrors build configurations and file references and should follow the shared CMake source of truth. / 生成的 IDE 元数据镜像构建配置与文件引用，应以共享 CMake 配置为事实来源。"
        nodes.append(node)
        ids.add(node_id)

        if path == "scripts/build_macos.sh":
            for fn in result.get("functions", []):
                span = int(fn["endLine"]) - int(fn["startLine"]) + 1
                if span < 10:
                    continue
                name = fn["name"]
                function_id = f"function:{path}:{name}"
                if function_id in ids:
                    raise RuntimeError(f"Duplicate node id: {function_id}")
                fn_summary, fn_tags = FUNCTION_INFO[name]
                nodes.append({
                    "id": function_id,
                    "type": "function",
                    "name": name,
                    "filePath": path,
                    "lineRange": [int(fn["startLine"]), int(fn["endLine"])],
                    "summary": fn_summary,
                    "tags": fn_tags,
                    "complexity": symbol_complexity(span),
                })
                ids.add(function_id)
                edges.append({"source": node_id, "target": function_id, "type": "contains", "direction": "forward", "weight": 1.0})

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
    if sum(edge["type"] == "imports" for edge in edges) != expected_imports:
        raise RuntimeError("Batch 19 import count mismatch")

    for old in INTERMEDIATE.glob("batch-19.json"):
        old.unlink()
    for old in INTERMEDIATE.glob("batch-19-part-*.json"):
        old.unlink()
    output = INTERMEDIATE / "batch-19.json"
    output.write_text(json.dumps({"nodes": nodes, "edges": edges}, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    checked = json.loads(output.read_text(encoding="utf-8"))
    if not isinstance(checked.get("nodes"), list) or not isinstance(checked.get("edges"), list):
        raise RuntimeError("Batch 19 JSON validation failed")
    print(json.dumps({
        "batch": BATCH_INDEX,
        "files": len(batch["files"]),
        "nodes": len(nodes),
        "edges": len(edges),
        "imports": expected_imports,
        "parts": [{"name": output.name, "nodes": len(nodes), "edges": len(edges)}],
        "skipped": extracted.get("filesSkipped", []),
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
