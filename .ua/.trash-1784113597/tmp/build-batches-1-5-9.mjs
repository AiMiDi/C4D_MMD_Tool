import fs from 'node:fs';
import path from 'node:path';

const ROOT = 'E:/code/C4D_MMD_Tool';
const UA = path.join(ROOT, '.ua');
const INTERMEDIATE = path.join(UA, 'intermediate');
const TMP = path.join(UA, 'tmp');
const batchData = JSON.parse(fs.readFileSync(path.join(INTERMEDIATE, 'batches.json'), 'utf8'));

const bi = (en, zh) => `${en} / ${zh}`;

const fileSummaries = {
  'source/CMTSceneManager.h': bi('Declares the scene-level PMX, VMD, and VPD orchestration API together with structured result logs for import and export operations.', '声明场景级 PMX、VMD 与 VPD 编排 API，并定义导入导出操作的结构化结果日志。'),
  'source/cmt_tools_config_manager.cpp': bi('Implements configuration loading, default initialization, dialog synchronization, and JSON persistence for tool settings.', '实现工具设置的配置加载、默认值初始化、对话框同步与 JSON 持久化。'),
  'source/cmt_tools_config_manager.h': bi('Defines the singleton configuration manager and its typed configuration table used by plugin dialogs and startup code.', '定义单例配置管理器及其类型化配置表，供插件对话框和启动代码使用。'),
  'source/cmt_tools_manager.cpp': bi('Implements the high-level commands that import and export VMD cameras, motions, VPD poses, and PMX models through libMMD and the scene manager.', '实现通过 libMMD 与场景管理器导入导出 VMD 相机、动作、VPD 姿势和 PMX 模型的高层命令。'),
  'source/cmt_tools_manager.h': bi('Declares the public tool-command surface for camera, motion, pose, and model import and export.', '声明相机、动作、姿势与模型导入导出的公共工具命令接口。'),
  'source/cmt_tools_setting.h': bi('Defines document-bound option structures for every camera, motion, pose, and model conversion workflow.', '定义绑定到文档的选项结构，覆盖所有相机、动作、姿势与模型转换流程。'),
  'source/main.cpp': bi('Provides the Cinema 4D plugin lifecycle entry points, registering components and initializing or saving shared configuration.', '提供 Cinema 4D 插件生命周期入口，负责注册组件并初始化或保存共享配置。'),
  'source/module/core/cmt_marco.h': bi('Collects cross-SDK compatibility macros, constants, type helpers, parameter accessors, and Cinema 4D utility functions.', '汇集跨 SDK 兼容宏、常量、类型辅助、参数访问器与 Cinema 4D 工具函数。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp': bi('Implements the name-conversion dialog, mapping-file discovery, editable mappings, conversion lookup, and automatic scene-name updates.', '实现名称转换对话框、映射文件发现、可编辑映射、转换查询与场景名称自动更新。'),
  'source/module/ui/cmt_name_conversion_dialog.h': bi('Declares the reusable name-mapping engine and Cinema 4D dialog used to edit and apply local-to-universal name conversions.', '声明可复用的名称映射引擎及 Cinema 4D 对话框，用于编辑并应用本地名到通用名的转换。'),
  'source/register_entity.h': bi('Declares the central registration routine that exposes all MMD Tool plugins to Cinema 4D.', '声明中央注册例程，将所有 MMD Tool 插件注册到 Cinema 4D。'),
  'source/utils/filename_util.hpp': bi('Provides binary file reading, suffix validation, and Cinema 4D import/export file-selection helpers.', '提供二进制文件读取、后缀校验及 Cinema 4D 导入导出文件选择辅助。'),
  'source/utils/json_util.hpp': bi('Implements a compact JSON parser, serializer, and file I/O layer for the plugin configuration variant model.', '为插件配置的变体数据模型实现轻量 JSON 解析、序列化与文件读写层。'),
  'source/utils/string_util.hpp': bi('Converts Cinema 4D strings to UTF-8 standard strings for library and filesystem boundaries.', '将 Cinema 4D 字符串转换为 UTF-8 标准字符串，用于库与文件系统边界。'),
  'source/CMTSceneManager.cpp': bi('Implements scene orchestration for MMD cameras, model managers, VMD motion, VPD poses, and localized operation reports.', '实现场景中的 MMD 相机、模型管理器、VMD 动作、VPD 姿势编排以及本地化操作报告。'),
  'source/module/tools/object/mmd_camera.cpp': bi('Implements the MMD camera object, translating VMD camera samples to and from Cinema 4D animation tracks with optional baking.', '实现 MMD 相机对象，在 VMD 相机采样与 Cinema 4D 动画轨道之间双向转换，并支持可选烘焙。'),
  'source/module/tools/object/mmd_camera.h': bi('Declares the Cinema 4D MMD camera object, its animation conversion API, execution hooks, and managed child objects.', '声明 Cinema 4D MMD 相机对象、动画转换 API、执行钩子与受管理子对象。'),
  'source/plugin_resource.h': bi('Aggregates generated Cinema 4D description IDs and resource symbols used when registering and operating plugin entities.', '聚合注册和运行插件实体时使用的 Cinema 4D 描述 ID 与资源符号。'),
  'AGENTS.md': bi('Repository-wide agent guidance covering maintained source layout, build validation, runtime resources, LLDB-DAP debugging, and diagnostic logging.', '仓库级智能体指南，涵盖维护中的源码布局、构建验证、运行时资源、LLDB-DAP 调试与诊断日志。'),
  'CMakeLists.txt': bi('Root CMake orchestration for dependency builds, multi-SDK configuration, cleanup, tests, runtime synchronization, and Windows packaging.', '根级 CMake 编排，负责依赖构建、多 SDK 配置、清理、测试、运行时同步与 Windows 打包。'),
  'CMakePresets.json': bi('Defines root configure and build presets for development, dependency smoke tests, all-SDK workflows, cleanup, and installer packaging.', '定义根级配置与构建预设，覆盖开发、依赖冒烟测试、全 SDK 工作流、清理和安装包打包。'),
  'CMakeUserPresets.SAMPLE.json': bi('Provides a user-local preset template for selecting a Cinema 4D SDK root without committing workstation-specific paths.', '提供用户本地预设模板，用于选择 Cinema 4D SDK 根目录且不提交工作站特定路径。'),
  'DEVELOPMENT.md': bi('English development guide explaining prerequisites, dependency and SDK builds, repository structure, include conventions, and generated outputs.', '英文开发指南，说明前置条件、依赖与 SDK 构建、仓库结构、包含约定及生成输出。'),
  'DEVELOPMENT_zh.md': bi('Chinese development guide with expanded coverage of multi-SDK builds, dependency topology, source discovery, and configuration files.', '中文开发指南，扩展说明多 SDK 构建、依赖拓扑、源码发现与配置文件。'),
  'LICENSE.md': bi('GNU General Public License version 3 text governing redistribution, modification, warranty, and source-disclosure obligations.', 'GNU 通用公共许可证第 3 版全文，规定再分发、修改、担保与源码披露义务。'),
  'README.md': bi('English project overview documenting installation, user-facing PMX and VMD features, version history, and authorship.', '英文项目概览，记录安装方式、面向用户的 PMX 与 VMD 功能、版本历史和作者信息。'),
  'README_zh.md': bi('Chinese project overview documenting releases, multi-SDK developer setup, interface usage, feature history, and authorship.', '中文项目概览，记录发行版、多 SDK 开发环境、界面使用、功能历史与作者信息。'),
  'configure_sdk.bat': bi('Validates an SDK directory, selects a preset, and runs CMake configuration from that SDK tree while preserving the exit code.', '校验 SDK 目录、选择预设，并在该 SDK 树中运行 CMake 配置，同时保留退出码。'),
};

const fileTags = {
  'source/CMTSceneManager.h': ['scene-management', 'import-export', 'api', 'diagnostics'],
  'source/cmt_tools_config_manager.cpp': ['configuration', 'persistence', 'singleton', 'ui'],
  'source/cmt_tools_config_manager.h': ['configuration', 'singleton', 'data-model', 'api'],
  'source/cmt_tools_manager.cpp': ['import-export', 'orchestration', 'libmmd', 'service'],
  'source/cmt_tools_manager.h': ['import-export', 'api', 'type-definition'],
  'source/cmt_tools_setting.h': ['configuration', 'data-model', 'serialization', 'type-definition'],
  'source/main.cpp': ['entry-point', 'plugin-lifecycle', 'registration'],
  'source/module/core/cmt_marco.h': ['compatibility', 'utility', 'macros', 'cinema-4d'],
  'source/module/ui/cmt_name_conversion_dialog.cpp': ['ui', 'name-conversion', 'configuration', 'event-handler'],
  'source/module/ui/cmt_name_conversion_dialog.h': ['ui', 'name-conversion', 'data-model', 'type-definition'],
  'source/register_entity.h': ['registration', 'entry-point', 'api'],
  'source/utils/filename_util.hpp': ['utility', 'file-io', 'validation'],
  'source/utils/json_util.hpp': ['serialization', 'parser', 'file-io', 'utility'],
  'source/utils/string_util.hpp': ['utility', 'string-conversion', 'utf-8'],
  'source/CMTSceneManager.cpp': ['scene-management', 'import-export', 'diagnostics', 'orchestration'],
  'source/module/tools/object/mmd_camera.cpp': ['camera-animation', 'serialization', 'cinema-4d', 'object-plugin'],
  'source/module/tools/object/mmd_camera.h': ['camera-animation', 'object-plugin', 'api', 'type-definition'],
  'source/plugin_resource.h': ['resources', 'descriptions', 'registration'],
  'AGENTS.md': ['documentation', 'development', 'debugging', 'build-system'],
  'CMakeLists.txt': ['build-system', 'cmake', 'multi-sdk', 'packaging'],
  'CMakePresets.json': ['configuration', 'cmake', 'build-system', 'multi-sdk'],
  'CMakeUserPresets.SAMPLE.json': ['configuration', 'cmake', 'template'],
  'DEVELOPMENT.md': ['documentation', 'development', 'build-system', 'architecture'],
  'DEVELOPMENT_zh.md': ['documentation', 'development', 'build-system', 'architecture'],
  'LICENSE.md': ['documentation', 'license', 'gpl-3'],
  'README.md': ['documentation', 'entry-point', 'usage', 'release-notes'],
  'README_zh.md': ['documentation', 'entry-point', 'usage', 'release-notes'],
  'configure_sdk.bat': ['build-system', 'cmake', 'automation', 'validation'],
};

const languageNotes = {
  'source/cmt_tools_config_manager.h': bi('Uses a C++ variant-backed table with templated getters and setters to keep heterogeneous settings type-safe.', '使用基于 C++ variant 的表和模板化读写接口，使异构设置保持类型安全。'),
  'source/module/core/cmt_marco.h': bi('Centralizes Cinema 4D SDK-version conditionals so the maintained source can compile across multiple SDK trees.', '集中封装 Cinema 4D SDK 版本条件，使同一套维护源码可在多个 SDK 树中编译。'),
  'source/utils/json_util.hpp': bi('A header-only recursive-descent parser serializes the project-specific variant model without an external JSON dependency.', '采用仅头文件的递归下降解析器，在不依赖外部 JSON 库的情况下序列化项目专用变体模型。'),
  'source/module/tools/object/mmd_camera.cpp': bi('Uses Cinema 4D CTrack/CCurve APIs and frame-domain VMD evaluation, with separate baked and sparse export paths.', '使用 Cinema 4D 的 CTrack/CCurve API 与 VMD 帧域求值，并区分烘焙和稀疏导出路径。'),
  'CMakeLists.txt': bi('The root project acts as a workflow coordinator; each sdk_* project remains the actual plugin compilation context.', '根工程充当工作流协调器，各 sdk_* 工程仍是插件实际编译上下文。'),
  'configure_sdk.bat': bi('Uses delayed-free batch parameter expansion conservatively and returns CMake\'s original ERRORLEVEL.', '保守使用批处理参数展开，并原样返回 CMake 的 ERRORLEVEL。'),
};

const fnOverrides = new Map(Object.entries({
  'source/cmt_tools_config_manager.cpp:InitDialog': bi('Copies typed configuration values into matching Cinema 4D dialog controls.', '将类型化配置值复制到对应的 Cinema 4D 对话框控件。'),
  'source/cmt_tools_config_manager.cpp:InitConfig': bi('Seeds a configuration entry from its declared default while preserving any compatible persisted value.', '从声明的默认值初始化配置项，同时保留类型兼容的持久化值。'),
  'source/cmt_tools_config_manager.cpp:InitConfigManager': bi('Loads the JSON configuration, initializes the full setting table, and writes defaults when no file exists.', '加载 JSON 配置、初始化完整设置表，并在文件不存在时写入默认值。'),
  'source/cmt_tools_config_manager.cpp:SaveConfig': bi('Serializes the current configuration table to the configured JSON file.', '将当前配置表序列化到指定 JSON 文件。'),
  'source/main.cpp:PluginStart': bi('Registers all plugin entities and initializes name-conversion and configuration services at startup.', '在启动时注册全部插件实体，并初始化名称转换与配置服务。'),
  'source/main.cpp:PluginEnd': bi('Persists shared tool configuration during plugin shutdown.', '在插件关闭时持久化共享工具配置。'),
  'source/main.cpp:PluginMessage': bi('Handles Cinema 4D system messages required for resource initialization and plugin integration.', '处理资源初始化与插件集成所需的 Cinema 4D 系统消息。'),
  'source/module/core/cmt_marco.h:MakeObjectColorProperties': bi('Builds a color-property bundle used to apply display color, color mode, and X-ray state together.', '构建颜色属性组合，用于统一应用显示颜色、颜色模式与 X-ray 状态。'),
  'source/module/core/cmt_marco.h:MakeDescIDGeData': bi('Wraps a description ID as GeData for Cinema 4D parameter APIs.', '将描述 ID 封装为 GeData，供 Cinema 4D 参数 API 使用。'),
  'source/module/core/cmt_marco.h:GetDocumentTime': bi('Returns the active document time with a zero-time fallback for null documents.', '返回活动文档时间，并在文档为空时回退到零时间。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:UpdateNameConversionDialog': bi('Discovers mapping files, initializes the dialog state, and selects the requested conversion table.', '发现映射文件、初始化对话框状态，并选择请求的转换表。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:CreateLayout': bi('Constructs the scrollable mapping editor, controls, and conversion actions in the Cinema 4D dialog.', '在 Cinema 4D 对话框中构建可滚动映射编辑器、控件与转换操作。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:InitValues': bi('Populates initial control values after the dialog layout has been created.', '在对话框布局创建后填充控件初始值。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:LoadNameMappingConfig': bi('Loads the selected mapping configuration and refreshes editable name pairs.', '加载选定的映射配置并刷新可编辑名称对。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:Command': bi('Dispatches dialog commands for editing mappings, selecting presets, converting names, and saving changes.', '分派对话框命令，处理映射编辑、预设选择、名称转换与更改保存。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:Init': bi('Initializes the shared name-conversion service from available mapping data.', '使用可用映射数据初始化共享名称转换服务。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:LoadConfig': bi('Reads a name-mapping file and rebuilds the local and universal lookup tables.', '读取名称映射文件，并重建本地名与通用名查询表。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:InitConver': bi('Traverses a scene hierarchy and prepares object names for conversion.', '遍历场景层级并准备待转换的对象名称。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:Conver': bi('Looks up a source name in the selected conversion direction and returns the mapped result.', '按选定转换方向查找源名称并返回映射结果。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:CheckUpdate': bi('Checks whether automatic name conversion should run for the current scene state.', '检查当前场景状态是否应执行自动名称转换。'),
  'source/module/ui/cmt_name_conversion_dialog.cpp:AutoUpdate': bi('Applies configured automatic name conversion when the tracked scene state changes.', '在被跟踪的场景状态变化时应用已配置的自动名称转换。'),
  'source/utils/filename_util.hpp:ReadFileData': bi('Reads an entire binary file into a byte buffer with explicit failure reporting.', '将完整二进制文件读入字节缓冲区，并显式报告失败。'),
  'source/utils/filename_util.hpp:CheckSuffix': bi('Checks a filename against an expected extension without changing the path.', '检查文件名是否匹配预期扩展名且不修改路径。'),
  'source/utils/filename_util.hpp:SelectSuffixImportFile': bi('Opens a Cinema 4D import selector constrained to the requested suffix.', '打开受指定后缀约束的 Cinema 4D 导入文件选择器。'),
  'source/utils/filename_util.hpp:SelectSuffixExportFile': bi('Opens a Cinema 4D export selector constrained to the requested suffix.', '打开受指定后缀约束的 Cinema 4D 导出文件选择器。'),
  'source/utils/json_util.hpp:SkipWhitespace': bi('Advances the parser cursor past JSON whitespace.', '将解析游标推进到 JSON 空白之后。'),
  'source/utils/json_util.hpp:Peek': bi('Returns the next non-whitespace JSON character without consuming a value.', '返回下一个非空白 JSON 字符，但不消费值。'),
  'source/utils/json_util.hpp:Expect': bi('Consumes a required JSON token and raises a parse error when it is absent.', '消费必需的 JSON 标记，并在缺失时抛出解析错误。'),
  'source/utils/json_util.hpp:ParseString': bi('Parses a quoted JSON string including supported escape sequences.', '解析带引号的 JSON 字符串及其支持的转义序列。'),
  'source/utils/json_util.hpp:ParseValue': bi('Dispatches recursive parsing for JSON strings, numbers, booleans, nulls, and objects.', '递归分派 JSON 字符串、数字、布尔值、null 与对象的解析。'),
  'source/utils/json_util.hpp:ParseObject': bi('Parses a JSON object into the configuration object representation.', '将 JSON 对象解析为配置对象表示。'),
  'source/utils/json_util.hpp:EscapeString': bi('Escapes control characters and quotes for valid JSON string output.', '转义控制字符与引号以生成合法 JSON 字符串。'),
  'source/utils/json_util.hpp:SerializeValue': bi('Serializes one variant-held configuration value to JSON.', '将一个由 variant 保存的配置值序列化为 JSON。'),
  'source/utils/json_util.hpp:Parse': bi('Parses a complete JSON string and rejects trailing content.', '解析完整 JSON 字符串并拒绝尾随内容。'),
  'source/utils/json_util.hpp:Serialize': bi('Serializes a complete configuration object to JSON text.', '将完整配置对象序列化为 JSON 文本。'),
  'source/utils/json_util.hpp:ReadJsonFile': bi('Reads and parses a JSON configuration file with safe fallback behavior.', '读取并解析 JSON 配置文件，并提供安全回退行为。'),
  'source/utils/json_util.hpp:WriteJsonFile': bi('Serializes and writes a configuration object to disk.', '将配置对象序列化并写入磁盘。'),
  'source/utils/string_util.hpp:GetStdString': bi('Encodes a Cinema 4D String as a UTF-8 std::string.', '将 Cinema 4D String 编码为 UTF-8 std::string。'),
  'source/CMTSceneManager.cpp:AppendVpdUnmatchedNames': bi('Appends labeled unmatched VPD bone or morph names to an operation report.', '把带标签的未匹配 VPD 骨骼或变形名称追加到操作报告。'),
  'source/CMTSceneManager.cpp:LogOK': bi('Formats operation-specific success dialogs with counts, model metadata, and elapsed timing.', '使用数量、模型元数据与耗时格式化各类操作成功对话框。'),
  'source/CMTSceneManager.cpp:Set': bi('Copies PMX metadata and enabled element counts into model import or export log state.', '将 PMX 元数据与已启用元素数量复制到模型导入或导出日志状态。'),
  'source/module/tools/object/mmd_camera.cpp:MMDCamera': bi('Copies MMD camera object state while retaining Cinema 4D object ownership rules.', '在遵守 Cinema 4D 对象所有权规则的同时复制 MMD 相机对象状态。'),
  'source/module/tools/object/mmd_camera.cpp:InitCamera': bi('Finds or creates the managed camera child and protection tag for an MMD camera object.', '为 MMD 相机对象查找或创建受管理的相机子对象与保护标签。'),
  'source/module/tools/object/mmd_camera.cpp:LoadVMDCamera': bi('Evaluates VMD camera frames and writes position, rotation, distance, and field-of-view tracks into Cinema 4D.', '求值 VMD 相机帧，并将位置、旋转、距离与视野轨道写入 Cinema 4D。'),
  'source/module/tools/object/mmd_camera.cpp:SaveVMDCamera': bi('Samples Cinema 4D camera tracks into VMD camera keyframes using baked or sparse export.', '通过烘焙或稀疏导出将 Cinema 4D 相机轨道采样为 VMD 相机关键帧。'),
  'source/module/tools/object/mmd_camera.cpp:ConversionCamera': bi('Runs camera conversion and reports unsupported or invalid conversion state.', '执行相机转换并报告不支持或无效的转换状态。'),
  'source/module/tools/object/mmd_camera.cpp:SDK2024_Init': bi('Initializes SDK-specific object state through the compatible superclass path.', '通过兼容的父类路径初始化特定 SDK 的对象状态。'),
  'source/module/tools/object/mmd_camera.cpp:SDK2024_CopyTo': bi('Clones managed camera children and tags when copying the object on newer SDKs.', '在较新 SDK 中复制对象时克隆受管理的相机子对象与标签。'),
  'source/module/tools/object/mmd_camera.cpp:Message': bi('Handles Cinema 4D object messages and reports unsupported operations.', '处理 Cinema 4D 对象消息并报告不支持的操作。'),
  'source/module/tools/object/mmd_camera.cpp:Execute': bi('Ensures camera initialization during scene evaluation before delegating execution.', '在场景求值期间确保相机完成初始化，然后委托执行。'),
  'source/module/tools/object/mmd_camera.cpp:AddToExecution': bi('Adds the camera object to Cinema 4D execution ordering.', '将相机对象加入 Cinema 4D 执行顺序。'),
  'source/module/tools/object/mmd_camera.cpp:GetTrackDescIDs': bi('Returns the description IDs for all camera animation channels managed by the object.', '返回该对象管理的全部相机动画通道描述 ID。'),
  'source/module/tools/object/mmd_camera.cpp:AddToSceneManager': bi('Registers an MMD camera object with the document scene manager.', '将 MMD 相机对象注册到文档场景管理器。'),
  'source/module/tools/object/mmd_camera.cpp:GetTrackObjects': bi('Maps managed animation channels to their owning Cinema 4D objects.', '把受管理的动画通道映射到其所属的 Cinema 4D 对象。'),
}));

const classOverrides = new Map(Object.entries({
  'source/CMTSceneManager.h:IOLog': bi('Base diagnostic state providing shared memory and file I/O error dialogs with operation timing.', '基础诊断状态，提供共享的内存与文件读写错误对话框及操作计时。'),
  'source/CMTSceneManager.h:LoadVmdCameraLog': bi('Tracks imported VMD camera frame counts and reports camera-specific success or validation failures.', '跟踪导入的 VMD 相机帧数，并报告相机相关成功或校验失败。'),
  'source/CMTSceneManager.h:SaveVmdCameraLog': bi('Reports VMD camera export completion and elapsed time.', '报告 VMD 相机导出完成状态与耗时。'),
  'source/CMTSceneManager.h:ConversionVmdCameraLog': bi('Carries timing state for camera conversion reporting.', '保存相机转换报告所需的计时状态。'),
  'source/CMTSceneManager.h:LoadVmdMotionLog': bi('Accumulates imported motion counts and unmatched bone or morph names for detailed VMD reports.', '累积导入动作数量及未匹配骨骼或变形名称，用于详细 VMD 报告。'),
  'source/CMTSceneManager.h:SaveVmdMotionLog': bi('Tracks exported VMD bone, morph, and frame counts and exposes validation error reports.', '跟踪导出的 VMD 骨骼、变形与帧数量，并提供校验错误报告。'),
  'source/CMTSceneManager.h:LoadVpdPoseLog': bi('Tracks matched and unmatched VPD pose bones and morphs for import diagnostics.', '跟踪 VPD 姿势导入中匹配与未匹配的骨骼和变形。'),
  'source/CMTSceneManager.h:SaveVpdPoseLog': bi('Tracks exported VPD bone and morph counts and reports selection or model errors.', '跟踪导出的 VPD 骨骼与变形数量，并报告选择或模型错误。'),
  'source/CMTSceneManager.h:LoadModelLog': bi('Captures imported PMX metadata and enabled element counts for the completion report.', '捕获导入的 PMX 元数据与已启用元素数量，用于完成报告。'),
  'source/CMTSceneManager.h:SavePmxModelLog': bi('Captures exported PMX metadata and element counts for the completion report.', '捕获导出的 PMX 元数据与元素数量，用于完成报告。'),
  'source/CMTSceneManager.h:CMTSceneManager': bi('Per-document singleton that coordinates MMD model managers and camera objects across import and export workflows.', '按文档存在的单例，负责在导入导出流程中协调 MMD 模型管理器与相机对象。'),
  'source/cmt_tools_config_manager.h:CMTToolConfigManager': bi('Singleton service that owns typed tool settings, default declarations, dialog binding, and JSON persistence.', '单例服务，负责类型化工具设置、默认值声明、对话框绑定与 JSON 持久化。'),
  'source/module/ui/cmt_name_conversion_dialog.h:NameConversion': bi('Owns bidirectional local and universal name maps and applies them to scene object hierarchies.', '维护本地名与通用名的双向映射，并将其应用到场景对象层级。'),
  'source/module/ui/cmt_name_conversion_dialog.h:UpdateNameConversionDialog': bi('Cinema 4D dialog for selecting, editing, saving, and applying name-conversion mappings.', '用于选择、编辑、保存并应用名称转换映射的 Cinema 4D 对话框。'),
  'source/module/tools/object/mmd_camera.h:MMDCamera': bi('Cinema 4D object plugin that owns a camera rig and converts animation between VMD frames and C4D tracks.', 'Cinema 4D 对象插件，拥有相机装配并在 VMD 帧与 C4D 轨道之间转换动画。'),
}));

function nounFromOperation(name) {
  return name
    .replace(/^Import/, '')
    .replace(/^Export/, '')
    .replace(/^Load/, '')
    .replace(/^Save/, '')
    .replace(/([a-z])([A-Z])/g, '$1 $2')
    .trim();
}

function functionSummary(filePath, name) {
  const key = `${filePath}:${name}`;
  if (fnOverrides.has(key)) return fnOverrides.get(key);
  if (filePath === 'source/cmt_tools_manager.cpp') {
    const subject = nounFromOperation(name);
    if (name.startsWith('Import')) return bi(`Reads and imports ${subject} data into the active Cinema 4D document through the scene manager.`, `读取 ${subject} 数据，并通过场景管理器导入当前 Cinema 4D 文档。`);
    if (name.startsWith('Export')) return bi(`Collects ${subject} data from the active scene and writes it through the matching MMD serializer.`, `从当前场景收集 ${subject} 数据，并通过对应的 MMD 序列化器写出。`);
    return bi('Converts the selected Cinema 4D camera representation through the scene manager.', '通过场景管理器转换选定的 Cinema 4D 相机表示。');
  }
  if (filePath === 'source/cmt_tools_setting.h') return bi(`Constructs ${name} workflow options from the active Cinema 4D document.`, `从当前 Cinema 4D 文档构造 ${name} 工作流选项。`);
  if (filePath === 'source/CMTSceneManager.h') {
    if (name.startsWith('~')) return bi('Releases the per-document scene manager and its tracked runtime state.', '释放按文档存在的场景管理器及其跟踪的运行时状态。');
    return bi('Constructs the per-document scene manager used by MMD import and export workflows.', '构造供 MMD 导入导出流程使用的按文档场景管理器。');
  }
  if (filePath === 'source/cmt_tools_config_manager.h') {
    if (name === 'operator =') return bi('Disables or controls assignment for the singleton configuration manager.', '禁用或控制单例配置管理器的赋值。');
    if (name.startsWith('~')) return bi('Finalizes the singleton configuration manager.', '析构单例配置管理器。');
    return bi('Constructs the singleton configuration manager and its default setting table.', '构造单例配置管理器及其默认设置表。');
  }
  if (filePath === 'source/module/ui/cmt_name_conversion_dialog.h') {
    if (name.startsWith('~')) return bi('Closes the name-conversion dialog and releases dialog-owned state.', '关闭名称转换对话框并释放对话框持有的状态。');
    return bi('Constructs the name-conversion mapping engine from the selected data source.', '从选定数据源构造名称转换映射引擎。');
  }
  if (filePath === 'source/CMTSceneManager.cpp') {
    if (name === 'LogOutMem') return bi('Reports an out-of-memory failure through a localized Cinema 4D dialog.', '通过本地化 Cinema 4D 对话框报告内存不足。');
    if (name === 'LogReadFileErr') return bi('Reports a file-read failure through a localized Cinema 4D dialog.', '通过本地化 Cinema 4D 对话框报告文件读取失败。');
    if (name === 'LogWriteFileErr') return bi('Reports a file-write failure through a localized Cinema 4D dialog.', '通过本地化 Cinema 4D 对话框报告文件写入失败。');
    if (name.startsWith('LogNot')) return bi('Reports an operation-specific validation failure through a localized dialog.', '通过本地化对话框报告特定操作的校验失败。');
    if (name === 'LogSelectError') return bi('Reports that the required scene object selection is missing or invalid.', '报告所需场景对象选择缺失或无效。');
    if (name === 'LogNoAnimationError') return bi('Reports that no exportable animation was found.', '报告未找到可导出的动画。');
    if (name.startsWith('Load')) return bi(`Delegates ${nounFromOperation(name)} import to the selected MMD model manager and records detailed results.`, `把 ${nounFromOperation(name)} 导入委托给选定的 MMD 模型管理器并记录详细结果。`);
    if (name.startsWith('Save')) return bi(`Collects ${nounFromOperation(name)} export data from the selected MMD model manager.`, `从选定的 MMD 模型管理器收集 ${nounFromOperation(name)} 导出数据。`);
    if (name === 'AddMMDCamera') return bi('Adds an MMD camera object to the scene manager tracking set.', '将 MMD 相机对象加入场景管理器跟踪集合。');
  }
  if (filePath === 'source/module/tools/object/mmd_camera.h') {
    if (name.startsWith('~')) return bi('Releases the MMD camera object and its managed runtime references.', '释放 MMD 相机对象及其管理的运行时引用。');
    return bi('Constructs or copies an MMD camera object wrapper.', '构造或复制 MMD 相机对象包装。');
  }
  return bi(`Implements the ${name} operation within this file's primary responsibility.`, `在该文件的主要职责范围内实现 ${name} 操作。`);
}

function classSummary(filePath, name) {
  const key = `${filePath}:${name}`;
  if (classOverrides.has(key)) return classOverrides.get(key);
  if (filePath === 'source/cmt_tools_setting.h') return bi(`Stores ${name} conversion options initialized from a Cinema 4D document.`, `保存从 Cinema 4D 文档初始化的 ${name} 转换选项。`);
  return bi(`Defines the ${name} type used by this file's plugin workflow.`, `定义该文件插件工作流使用的 ${name} 类型。`);
}

function symbolTags(filePath, name, type) {
  if (type === 'class') {
    if (name.endsWith('Log') || name === 'IOLog') return ['diagnostics', 'data-model', 'localization'];
    if (filePath === 'source/cmt_tools_setting.h') return ['configuration', 'data-model', 'serialization'];
    if (name === 'MMDCamera') return ['object-plugin', 'camera-animation', 'cinema-4d'];
    if (name.includes('Conversion')) return ['ui', 'name-conversion', 'data-model'];
    return ['service', 'orchestration', 'data-model'];
  }
  if (filePath.includes('json_util')) return ['serialization', 'parser', 'utility'];
  if (filePath.includes('filename_util')) return ['file-io', 'utility', 'validation'];
  if (filePath.includes('string_util')) return ['string-conversion', 'utf-8', 'utility'];
  if (filePath.includes('name_conversion')) return ['ui', 'name-conversion', 'event-handler'];
  if (filePath.includes('mmd_camera')) return ['camera-animation', 'cinema-4d', 'object-plugin'];
  if (name.startsWith('Log') || name === 'AppendVpdUnmatchedNames') return ['diagnostics', 'localization', 'error-handling'];
  if (filePath.includes('setting') || filePath.includes('config_manager')) return ['configuration', 'data-model', 'persistence'];
  if (name.startsWith('Plugin')) return ['entry-point', 'plugin-lifecycle', 'event-handler'];
  if (/^(Import|Export|Load|Save|Conversion)/.test(name)) return ['import-export', 'orchestration', 'serialization'];
  return ['utility', 'cinema-4d', 'plugin-runtime'];
}

function complexity(lines) {
  if (lines < 50) return 'simple';
  if (lines <= 200) return 'moderate';
  return 'complex';
}

function fileNodeType(file) {
  if (file.fileCategory === 'config') return ['config', `config:${file.path}`];
  if (file.fileCategory === 'docs') return ['document', `document:${file.path}`];
  if (file.fileCategory === 'infra') return ['service', `service:${file.path}`];
  if (file.fileCategory === 'data') return ['schema', `schema:${file.path}`];
  return ['file', `file:${file.path}`];
}

function chooseRepresentative(items) {
  return [...items].sort((a, b) => ((b.endLine - b.startLine) - (a.endLine - a.startLine)) || (a.startLine - b.startLine))[0];
}

function graphForBatch(index) {
  const descriptor = batchData.batches.find((item) => item.batchIndex === index);
  if (!descriptor) throw new Error(`Missing batch ${index}`);
  const extracted = JSON.parse(fs.readFileSync(path.join(TMP, `ua-file-extract-results-${index}.json`), 'utf8'));
  if (!extracted.scriptCompleted || extracted.results.length !== descriptor.files.length) throw new Error(`Incomplete extraction for batch ${index}`);
  const resultByPath = new Map(extracted.results.map((item) => [item.path, item]));
  const nodes = [];
  const edges = [];

  for (const file of descriptor.files) {
    const result = resultByPath.get(file.path);
    if (!result) throw new Error(`Missing extraction result for ${file.path}`);
    const [type, id] = fileNodeType(file);
    const node = {
      id,
      type,
      name: path.posix.basename(file.path),
      filePath: file.path,
      summary: fileSummaries[file.path],
      tags: fileTags[file.path],
      complexity: complexity(result.nonEmptyLines),
    };
    if (!node.summary || !node.tags) throw new Error(`Missing file semantics for ${file.path}`);
    if (languageNotes[file.path]) node.languageNotes = languageNotes[file.path];
    nodes.push(node);

    if (file.fileCategory === 'code') {
      const exports = new Set((result.exports || []).map((item) => item.name));
      for (const [symbolType, collection] of [['function', result.functions || []], ['class', result.classes || []]]) {
        const grouped = new Map();
        for (const item of collection) {
          if (!grouped.has(item.name)) grouped.set(item.name, []);
          grouped.get(item.name).push(item);
        }
        for (const [name, items] of grouped) {
          const representative = chooseRepresentative(items);
          const span = representative.endLine - representative.startLine + 1;
          const methodCount = symbolType === 'class' ? (representative.methods || []).length : 0;
          const significant = span >= (symbolType === 'function' ? 10 : 20) || methodCount >= 2 || exports.has(name);
          if (!significant) continue;
          const symbolId = `${symbolType}:${file.path}:${name}`;
          nodes.push({
            id: symbolId,
            type: symbolType,
            name,
            filePath: file.path,
            lineRange: [representative.startLine, representative.endLine],
            summary: symbolType === 'function' ? functionSummary(file.path, name) : classSummary(file.path, name),
            tags: symbolTags(file.path, name, symbolType),
            complexity: complexity(span),
          });
          edges.push({ source: id, target: symbolId, type: 'contains', direction: 'forward', weight: 1.0 });
          if (exports.has(name)) edges.push({ source: id, target: symbolId, type: 'exports', direction: 'forward', weight: 0.8 });
        }
      }

      const imports = descriptor.batchImportData[file.path] || [];
      for (const importedPath of imports) {
        edges.push({ source: id, target: `file:${importedPath}`, type: 'imports', direction: 'forward', weight: 0.7 });
      }
    }
  }

  if (index === 9) {
    const add = (source, target, type, weight) => edges.push({ source, target, type, direction: 'forward', weight });
    add('document:AGENTS.md', 'document:DEVELOPMENT.md', 'documents', 0.5);
    add('document:AGENTS.md', 'document:CMakeLists.txt', 'documents', 0.5);
    add('document:CMakeLists.txt', 'config:CMakePresets.json', 'related', 0.5);
    add('config:CMakePresets.json', 'document:CMakeLists.txt', 'configures', 0.6);
    add('config:CMakeUserPresets.SAMPLE.json', 'config:CMakePresets.json', 'depends_on', 0.6);
    add('document:DEVELOPMENT.md', 'document:CMakeLists.txt', 'documents', 0.5);
    add('document:DEVELOPMENT_zh.md', 'document:CMakeLists.txt', 'documents', 0.5);
    add('document:LICENSE.md', 'document:README.md', 'related', 0.5);
    add('document:README.md', 'document:DEVELOPMENT.md', 'related', 0.5);
    add('document:README_zh.md', 'document:DEVELOPMENT_zh.md', 'related', 0.5);
    add('file:configure_sdk.bat', 'config:CMakePresets.json', 'depends_on', 0.6);
    add('file:configure_sdk.bat', 'document:CMakeLists.txt', 'depends_on', 0.6);
  }

  return { descriptor, nodes, edges };
}

function validateWhole(index, graph) {
  const ids = new Set();
  for (const node of graph.nodes) {
    if (ids.has(node.id)) throw new Error(`Duplicate node ${node.id} in batch ${index}`);
    ids.add(node.id);
    if (!node.summary.includes(' / ')) throw new Error(`Non-bilingual summary ${node.id}`);
    if (!Array.isArray(node.tags) || node.tags.length < 3 || node.tags.length > 5) throw new Error(`Bad tags ${node.id}`);
    if (!['simple', 'moderate', 'complex'].includes(node.complexity)) throw new Error(`Bad complexity ${node.id}`);
  }
  for (const file of graph.descriptor.files) {
    const fileNodes = graph.nodes.filter((node) => node.filePath === file.path && ['file', 'config', 'document', 'service', 'pipeline', 'schema', 'resource'].includes(node.type));
    if (fileNodes.length !== 1) throw new Error(`Expected one file node for ${file.path}, got ${fileNodes.length}`);
  }
  const expectedImports = graph.descriptor.files
    .filter((file) => file.fileCategory === 'code')
    .reduce((sum, file) => sum + (graph.descriptor.batchImportData[file.path] || []).length, 0);
  const actualImports = graph.edges.filter((edge) => edge.type === 'imports').length;
  if (expectedImports !== actualImports) throw new Error(`Batch ${index} imports ${actualImports}/${expectedImports}`);
}

function writeGraph(index, graph) {
  validateWhole(index, graph);
  const parts = Math.ceil(Math.max(graph.nodes.length / 60, graph.edges.length / 120));
  const partCount = Math.max(1, parts);
  const files = [...graph.descriptor.files].sort((a, b) => a.path.localeCompare(b.path));
  const chunkSize = Math.ceil(files.length / partCount);
  const written = [];
  for (let i = 0; i < partCount; i += 1) {
    const partFiles = new Set(files.slice(i * chunkSize, (i + 1) * chunkSize).map((file) => file.path));
    const partNodes = graph.nodes.filter((node) => partFiles.has(node.filePath));
    const sourceIds = new Set(partNodes.map((node) => node.id));
    const partEdges = graph.edges.filter((edge) => sourceIds.has(edge.source));
    const payload = { nodes: partNodes, edges: partEdges };
    const filename = partCount === 1 ? `batch-${index}.json` : `batch-${index}-part-${i + 1}.json`;
    const outputPath = path.join(INTERMEDIATE, filename);
    fs.writeFileSync(outputPath, `${JSON.stringify(payload, null, 2)}\n`);
    JSON.parse(fs.readFileSync(outputPath, 'utf8'));
    written.push({ filename, nodes: partNodes.length, edges: partEdges.length });
  }
  return { partCount, nodes: graph.nodes.length, edges: graph.edges.length, written };
}

const totals = {};
for (const index of [1, 5, 9]) totals[index] = writeGraph(index, graphForBatch(index));
console.log(JSON.stringify(totals, null, 2));
