import fs from 'node:fs';
import path from 'node:path';

const ROOT = 'E:/code/C4D_MMD_Tool';
const BASE = path.join(ROOT, '.ua', 'intermediate');
const TMP = path.join(ROOT, '.ua', 'tmp');
const catalog = JSON.parse(fs.readFileSync(path.join(BASE, 'batches.json'), 'utf8'));
const batch = catalog.batches.find((entry) => entry.batchIndex === 20);
if (!batch) throw new Error('Missing current batch 20');
const extracted = JSON.parse(fs.readFileSync(path.join(TMP, 'ua-file-extract-results-20.json'), 'utf8'));
if (!extracted.scriptCompleted || extracted.filesSkipped.length || extracted.results.length !== batch.files.length) {
  throw new Error('Incomplete extraction for batch 20');
}
const results = new Map(extracted.results.map((result) => [result.path, result]));
const bi = (en, zh) => `${en} / ${zh}`;

const semantics = {
  'sdk_2024/cmake/sdk_compiler_helper.cmake': [bi('Cinema 4D 2024 compatibility shim that forwards compiler-helper behavior to the shared stable SDK toolchain.', 'Cinema 4D 2024 兼容垫片，将编译器辅助行为转发到共享的稳定 SDK 工具链。'), ['cmake', 'compatibility', 'compiler', 'wrapper']],
  'sdk_2024/cmake/sdk_library_template.cmake': [bi('Auto-generated cross-platform target template that expands projectdefinition metadata into Maxon SDK target variables and target processing.', '自动生成的跨平台目标模板，将 projectdefinition 元数据展开为 Maxon SDK 目标变量并执行目标处理。'), ['cmake', 'template', 'target-configuration', 'cross-platform']],
  'sdk_2024/cmake/sdk_targets.cmake': [bi('Cinema 4D 2024 compatibility shim that forwards target creation and resource logic to the shared stable SDK implementation.', 'Cinema 4D 2024 兼容垫片，将目标创建与资源逻辑转发到共享的稳定 SDK 实现。'), ['cmake', 'compatibility', 'targets', 'wrapper']],
  'sdk_2024/cmake/sdk_update_projects.cmake': [bi('Cinema 4D 2024 compatibility shim that forwards module discovery and project-update logic to the shared SDK implementation.', 'Cinema 4D 2024 兼容垫片，将模块发现与工程更新逻辑转发到共享 SDK 实现。'), ['cmake', 'compatibility', 'module-discovery', 'wrapper']],
  'sdk_2024/CMakeLists.txt': [bi('Cinema 4D 2024 bridge root that configures C++20, loads compatibility tooling, discovers modules, and prepares framework and plugin outputs.', 'Cinema 4D 2024 桥接根工程，负责配置 C++20、加载兼容工具、发现模块并准备框架与插件输出。'), ['build-system', 'cmake', 'compatibility', 'sdk']],
  'sdk_2024/CMakePresets.json': [bi('Cross-platform Cinema 4D 2024 configure presets for Ninja, universal Xcode, Visual Studio v143, and ClangCL build trees.', 'Cinema 4D 2024 的跨平台配置预设，覆盖 Ninja、通用 Xcode、Visual Studio v143 与 ClangCL 构建树。'), ['configuration', 'cmake', 'cross-platform', 'sdk']],
  'sdk_2024/plugins/mmdtool/mmdtool.xdl64.manifest': [bi('Windows plugin manifest requesting as-invoker execution and per-monitor DPI awareness for the 2024 xdl64 binary.', 'Windows 插件清单，为 2024 xdl64 二进制声明普通用户权限与按显示器 DPI 感知。'), ['manifest', 'windows', 'dpi-awareness', 'plugin']],
  'sdk_2024/plugins/mmdtool/project/CMakeLists.txt': [bi('Thin Cinema 4D 2024 plugin wrapper that reuses the shared dependency layer, canonical source tree, current resources, and common plugin setup.', '精简的 Cinema 4D 2024 插件包装层，复用共享依赖层、规范源码树、当前资源与公共插件设置。'), ['build-system', 'cmake', 'plugin-wrapper', 'compatibility']],
  'sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj': [bi('Generated Visual Studio dynamic-library project listing MMD Tool sources, Maxon framework imports, build configurations, and framework project references.', '生成的 Visual Studio 动态库工程，列出 MMD Tool 源码、Maxon 框架导入、构建配置与框架工程引用。'), ['build-system', 'visual-studio', 'generated', 'plugin']],
  'sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj.filters': [bi('Visual Studio filter map organizing the generated MMD Tool source and header entries into IDE folders.', 'Visual Studio 筛选器映射，将生成的 MMD Tool 源码与头文件条目组织到 IDE 文件夹中。'), ['build-system', 'visual-studio', 'generated', 'ide-organization']],
  'sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj.user': [bi('Workstation-local Visual Studio debugger settings that launch Cinema 4D 2024 with the plugin module path.', '工作站本地 Visual Studio 调试设置，用指定插件模块路径启动 Cinema 4D 2024。'), ['configuration', 'visual-studio', 'debugging', 'local-settings']],
  'sdk_2024/plugins/mmdtool/project/mmdtool.xcodeproj/project.pbxproj': [bi('Generated Xcode project for the macOS mmdtool dynamic library, including source groups, Maxon framework projects, configurations, and products.', '生成的 macOS mmdtool 动态库 Xcode 工程，包含源码分组、Maxon 框架工程、构建配置与产品。'), ['build-system', 'xcode', 'generated', 'plugin']],
  'sdk_2024/plugins/mmdtool/project/projectdefinition.txt': [bi('Reference-only Maxon plugin metadata recording platforms, DLL type, framework APIs, module identity, encoding, and exception settings.', '仅供参考的 Maxon 插件元数据，记录平台、DLL 类型、框架 API、模块标识、编码与异常设置。'), ['documentation', 'project-metadata', 'plugin', 'reference']],
  'sdk_2024/plugins/mmdtool/project/projectsettings.props': [bi('MSBuild property sheet defining the Maxon SDK root macro and USE_API_MAXON preprocessor definition for the generated project.', 'MSBuild 属性表，为生成工程定义 Maxon SDK 根目录宏与 USE_API_MAXON 预处理定义。'), ['build-system', 'msbuild', 'configuration', 'plugin']],
  'sdk_2024/plugins/project/projectdefinition.txt': [bi('Maxon solution metadata selecting the mmdtool plugin project for Win64 and macOS generation.', 'Maxon 解决方案元数据，选择在 Win64 与 macOS 上生成 mmdtool 插件工程。'), ['documentation', 'project-metadata', 'solution', 'sdk']],
  'sdk_2025/cmake/base_settings/compile_definitions.cmake': [bi('Defines common, debug, release, and Windows Maxon SDK preprocessor symbols for 64-bit plugin targets.', '定义 64 位插件目标使用的通用、调试、发布与 Windows Maxon SDK 预处理符号。'), ['cmake', 'compiler', 'preprocessor', 'configuration']],
  'sdk_2025/cmake/base_settings/compile_options.cmake': [bi('Defines compiler- and platform-specific optimization, debugging, ISA, language, visibility, and reproducibility options for SDK targets.', '定义 SDK 目标按编译器与平台区分的优化、调试、指令集、语言、可见性与可复现性选项。'), ['cmake', 'compiler', 'optimization', 'cross-platform']],
  'sdk_2025/cmake/base_settings/link_options.cmake': [bi('Defines shared Windows and Linux linker flags, debug information policy, ASLR, and dead-code folding behavior.', '定义共享的 Windows 与 Linux 链接器标志、调试信息策略、ASLR 与无用代码折叠行为。'), ['cmake', 'linker', 'configuration', 'cross-platform']],
  'sdk_2025/cmake/base_settings/sanitize.cmake': [bi('Defines AddressSanitizer compile definitions and compile or link options for supported release-mode sanitizer builds.', '定义受支持发布模式消毒构建的 AddressSanitizer 编译定义及编译或链接选项。'), ['cmake', 'address-sanitizer', 'debugging', 'configuration']],
  'sdk_2025/cmake/base_settings/warnings.clang.cmake': [bi('Defines Clang warnings promoted to errors plus version-specific warning suppressions required by the Maxon SDK codebase.', '定义提升为错误的 Clang 警告，以及 Maxon SDK 代码库所需的按版本警告抑制项。'), ['cmake', 'clang', 'warnings', 'compiler']],
  'sdk_2025/cmake/base_settings/warnings.gcc.cmake': [bi('Defines GCC warning suppressions and selected error-level diagnostics for C and C++ SDK targets.', '定义 C 与 C++ SDK 目标的 GCC 警告抑制项及选定的错误级诊断。'), ['cmake', 'gcc', 'warnings', 'compiler']],
  'sdk_2025/cmake/base_settings/warnings.msvc.cmake': [bi('Defines the MSVC warning suppression set and selected warnings promoted to errors for SDK compilation.', '定义 SDK 编译使用的 MSVC 警告抑制集合及提升为错误的选定警告。'), ['cmake', 'msvc', 'warnings', 'compiler']],
  'sdk_2025/cmake/commands/create_directory_symlink.cmake': [bi('Script-mode CMake command that validates path arguments and delegates creation of a directory link to the SDK target utilities.', '脚本模式 CMake 命令，校验路径参数并委托 SDK 目标工具创建目录链接。'), ['cmake', 'script', 'symlink', 'utility']],
  'sdk_2025/cmake/commands/update_filelist.cmake': [bi('Script-mode CMake command that normalizes search directories and refreshes generated source file lists, with stricter Xcode change handling.', '脚本模式 CMake 命令，规范化搜索目录并刷新生成的源码文件列表，同时对 Xcode 变更采用更严格处理。'), ['cmake', 'script', 'file-discovery', 'utility']],
  'sdk_2025/cmake/sdk_compiler_helper.cmake': [bi('Central Maxon SDK compiler helper that identifies toolchains and applies warning policy, ISA flags, compile definitions, RTTI, exceptions, linker options, and framework links.', 'Maxon SDK 中央编译器辅助层，负责识别工具链并应用警告策略、指令集标志、编译定义、RTTI、异常、链接选项与框架链接。'), ['cmake', 'compiler', 'cross-platform', 'build-system']],
};

const complexity = (lines) => lines < 50 ? 'simple' : lines <= 200 ? 'moderate' : 'complex';
function identity(file) {
  if (file.fileCategory === 'config') return ['config', `config:${file.path}`];
  if (file.fileCategory === 'docs') return ['document', `document:${file.path}`];
  return ['file', `file:${file.path}`];
}

const nodes = [];
for (const file of batch.files) {
  const result = results.get(file.path);
  const [summary, tags] = semantics[file.path] || [];
  if (!result || !summary || !tags) throw new Error(`Missing analysis input for ${file.path}`);
  const [type, id] = identity(file);
  nodes.push({ id, type, name: path.posix.basename(file.path), filePath: file.path, summary, tags, complexity: complexity(result.nonEmptyLines) });
}

const edges = [];
const add = (source, target, type = 'depends_on', weight = 0.6) => edges.push({ source, target, type, direction: 'forward', weight });
const sdkRoot = 'document:sdk_2024/CMakeLists.txt';
add(sdkRoot, 'file:sdk_2024/cmake/sdk_compiler_helper.cmake');
add(sdkRoot, 'file:sdk_2024/cmake/sdk_targets.cmake');
add(sdkRoot, 'file:sdk_2024/cmake/sdk_update_projects.cmake');
add('config:sdk_2024/CMakePresets.json', sdkRoot, 'configures', 0.6);
add('document:sdk_2024/plugins/mmdtool/project/CMakeLists.txt', sdkRoot);
add('document:sdk_2024/plugins/mmdtool/project/projectdefinition.txt', 'document:sdk_2024/plugins/mmdtool/project/CMakeLists.txt', 'related', 0.5);
add('document:sdk_2024/plugins/project/projectdefinition.txt', 'document:sdk_2024/plugins/mmdtool/project/projectdefinition.txt');
add('file:sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj', 'file:sdk_2024/plugins/mmdtool/project/projectsettings.props');
add('file:sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj.filters', 'file:sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj');
add('file:sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj.user', 'file:sdk_2024/plugins/mmdtool/project/mmdtool.vcxproj');
add('file:sdk_2024/plugins/mmdtool/project/mmdtool.xcodeproj/project.pbxproj', 'document:sdk_2024/plugins/mmdtool/project/projectdefinition.txt');

const helper = 'file:sdk_2025/cmake/sdk_compiler_helper.cmake';
for (const setting of ['compile_definitions.cmake', 'compile_options.cmake', 'link_options.cmake', 'warnings.clang.cmake', 'warnings.gcc.cmake', 'warnings.msvc.cmake']) {
  add(helper, `file:sdk_2025/cmake/base_settings/${setting}`);
}

const ids = new Set(nodes.map((node) => node.id));
if (ids.size !== nodes.length) throw new Error('Duplicate node IDs');
for (const file of batch.files) {
  if (nodes.filter((node) => node.filePath === file.path).length !== 1) throw new Error(`Coverage failure ${file.path}`);
}
for (const node of nodes) {
  if (!node.summary.includes(' / ')) throw new Error(`Non-bilingual summary ${node.id}`);
  if (!Array.isArray(node.tags) || node.tags.length < 3 || node.tags.length > 5) throw new Error(`Invalid tags ${node.id}`);
}
for (const edge of edges) {
  if (!ids.has(edge.source) || !ids.has(edge.target)) throw new Error(`Dangling edge ${edge.source} -> ${edge.target}`);
}
const expectedImports = batch.files.filter((file) => file.fileCategory === 'code')
  .reduce((count, file) => count + (batch.batchImportData[file.path] || []).length, 0);
const actualImports = edges.filter((edge) => edge.type === 'imports').length;
if (actualImports !== expectedImports) throw new Error(`Import mismatch ${actualImports}/${expectedImports}`);

const output = path.join(BASE, 'batch-20.json');
fs.writeFileSync(output, `${JSON.stringify({ nodes, edges }, null, 2)}\n`);
JSON.parse(fs.readFileSync(output, 'utf8'));
console.log(JSON.stringify({ parts: 1, nodes: nodes.length, edges: edges.length, imports: actualImports, skipped: 0 }, null, 2));
