import fs from 'node:fs';
import path from 'node:path';

const ROOT = 'E:/code/C4D_MMD_Tool';
const BASE = path.join(ROOT, '.ua', 'intermediate');
const TMP = path.join(ROOT, '.ua', 'tmp');
const catalog = JSON.parse(fs.readFileSync(path.join(BASE, 'batches.json'), 'utf8'));
const batch = catalog.batches.find((entry) => entry.batchIndex === 22);
if (!batch) throw new Error('Missing current batch 22');
const extracted = JSON.parse(fs.readFileSync(path.join(TMP, 'ua-file-extract-results-22.json'), 'utf8'));
if (!extracted.scriptCompleted || extracted.filesSkipped.length || extracted.results.length !== batch.files.length) {
  throw new Error('Incomplete extraction for batch 22');
}
const results = new Map(extracted.results.map((result) => [result.path, result]));
const bi = (en, zh) => `${en} / ${zh}`;

const sourceSemantics = {
  'source/module/core/cmt_debug_log.h': [bi('Provides a no-op debug logging sink that keeps debug-only values referenced without producing output in normal builds.', '提供无输出的调试日志接收器，使仅调试值在普通构建中保持被引用而不产生输出。'), ['diagnostics', 'utility', 'warning-suppression', 'header-only']],
  'source/module/core/cmt_old_sdk_stl_preload.h': [bi('Preloads standard-library headers before old Windows Cinema 4D SDK headers disable exceptions, avoiding MSVC STL incompatibilities in R20 and R21 builds.', '在旧版 Windows Cinema 4D SDK 头文件禁用异常前预加载标准库头，以避免 R20 与 R21 构建中的 MSVC STL 不兼容。'), ['compatibility', 'old-sdk', 'msvc', 'standard-library']],
  'source/module/ui/vmd_loader_camera_dialog.cpp': [bi('Implements the focused VMD camera-import dialog, resource layout initialization, default scale and offset values, and import or cancel command handling.', '实现精简的 VMD 相机导入对话框、资源布局初始化、默认缩放与偏移值以及导入或取消命令处理。'), ['ui', 'vmd-camera', 'import', 'event-handler']],
  'source/module/ui/vmd_loader_camera_dialog.h': [bi('Declares the Cinema 4D VMD camera-import dialog and its filename, document, and image-area state.', '声明 Cinema 4D VMD 相机导入对话框及其文件名、文档与图像区域状态。'), ['ui', 'vmd-camera', 'type-definition', 'dialog']],
  'source/utils/cmt_anim_flow_debug.hpp': [bi('Provides environment-controlled animation, IK, and physics flow diagnostics with a cached enable switch, optional bone filter, and Cinema 4D logging macros.', '提供由环境变量控制的动画、IK 与物理流程诊断，包含缓存开关、可选骨骼筛选与 Cinema 4D 日志宏。'), ['diagnostics', 'animation-flow', 'ik', 'environment-config']],
  'source/utils/images_user_area_util.hpp': [bi('Defines a Cinema 4D user area that loads and draws a scaled alpha-capable bitmap off-screen for flicker-free dialog imagery.', '定义 Cinema 4D 用户区域，通过离屏绘制加载并显示支持 Alpha 的缩放位图，避免对话框图像闪烁。'), ['ui', 'image-rendering', 'utility', 'user-area']],
};

function sdkSemantics(filePath) {
  if (filePath === 'sdk_r20/plugins/project/projectdefinition.txt') {
    return [bi('Cinema 4D R20 solution metadata selecting the mmdtool project and adding Maxon and C4D debugger visualization files.', 'Cinema 4D R20 解决方案元数据，选择 mmdtool 工程并加入 Maxon 与 C4D 调试可视化文件。'), ['documentation', 'project-metadata', 'solution', 'old-sdk']];
  }
  const match = filePath.match(/^sdk_(r21|r23|r25)\/(.+)$/);
  if (!match) return undefined;
  const version = match[1].toUpperCase();
  const tail = match[2];
  if (tail === `cmake/sdk_compat_${match[1]}.cmake`) {
    return [bi(`Cinema 4D ${version} compatibility settings forcing C++20, AVX-era MSVC flags, permissive mode, parallel compilation, and reduced warning strictness.`, `Cinema 4D ${version} 兼容设置，强制使用 C++20、AVX 级 MSVC 标志、宽松模式、并行编译与较低的警告严格度。`), ['cmake', 'compatibility', 'compiler', 'old-sdk']];
  }
  if (tail === 'CMakeLists.txt') {
    return [bi(`Cinema 4D ${version} bridge root that reuses shared SDK tooling, applies version compatibility settings, discovers modules, and prepares plugin outputs.`, `Cinema 4D ${version} 桥接根工程，复用共享 SDK 工具、应用版本兼容设置、发现模块并准备插件输出。`), ['build-system', 'cmake', 'compatibility', 'sdk']];
  }
  if (tail === 'CMakePresets.json') {
    const mac = version === 'R25' ? 'universal macOS' : 'x86_64 macOS';
    const macZh = version === 'R25' ? '通用 macOS' : 'x86_64 macOS';
    return [bi(`Cross-platform ${version} configure presets for Ninja, ${mac}, Visual Studio v143, and ClangCL build trees.`, `${version} 的跨平台配置预设，覆盖 Ninja、${macZh}、Visual Studio v143 与 ClangCL 构建树。`), ['configuration', 'cmake', 'cross-platform', 'sdk']];
  }
  if (tail === 'plugins/mmdtool/project/CMakeLists.txt') {
    const resource = version === 'R25' ? 'current S24+ resources' : 'legacy R20–S24 resources';
    const resourceZh = version === 'R25' ? '当前 S24+ 资源' : '旧版 R20–S24 资源';
    return [bi(`Thin ${version} plugin wrapper that builds the canonical shared source with ${resource} and the framework set required by older SDKs.`, `精简的 ${version} 插件包装层，使用规范共享源码、${resourceZh}及旧 SDK 所需框架集合进行构建。`), ['build-system', 'cmake', 'plugin-wrapper', 'compatibility']];
  }
  if (tail === 'plugins/mmdtool/project/projectdefinition.txt') {
    return [bi(`Reference Maxon metadata for the ${version} mmdtool DLL, recording platforms, framework APIs, module identity, style policy, and encoding.`, `${version} mmdtool DLL 的参考 Maxon 元数据，记录平台、框架 API、模块标识、样式策略与编码。`), ['documentation', 'project-metadata', 'plugin', 'reference']];
  }
  if (tail === 'plugins/project/projectdefinition.txt') {
    const hasNatvis = version !== 'R23';
    return [bi(`Maxon ${version} solution metadata selecting the mmdtool plugin${hasNatvis ? ' and debugger visualization files' : ''}.`, `Maxon ${version} 解决方案元数据，选择 mmdtool 插件${hasNatvis ? '与调试可视化文件' : ''}。`), ['documentation', 'project-metadata', 'solution', 'sdk']];
  }
  return undefined;
}

const fnSummaries = {
  'source/module/core/cmt_debug_log.h:Log': bi('Accepts debug context and message data as a deliberate no-op so strict builds still consider the values used.', '以刻意的空操作接收调试上下文与消息数据，使严格构建仍将这些值视为已使用。'),
  'source/module/ui/vmd_loader_camera_dialog.cpp:~VMDLoaderCameraDialog': bi('Releases the dialog-owned image user area.', '释放对话框持有的图像用户区域。'),
  'source/module/ui/vmd_loader_camera_dialog.cpp:CreateLayout': bi('Loads the VMD import dialog resource and attaches the MMD Tool banner image.', '加载 VMD 导入对话框资源并附加 MMD Tool 横幅图像。'),
  'source/module/ui/vmd_loader_camera_dialog.cpp:InitValues': bi('Initializes camera import scale and frame offset controls with their defaults.', '使用默认值初始化相机导入缩放与帧偏移控件。'),
  'source/module/ui/vmd_loader_camera_dialog.cpp:Command': bi('Handles import and cancel actions, constructs camera-import settings, and dispatches VMD camera loading.', '处理导入与取消操作，构造相机导入设置并分派 VMD 相机加载。'),
  'source/module/ui/vmd_loader_camera_dialog.h:VMDLoaderCameraDialog': bi('Constructs the camera-import dialog with the selected VMD filename and target document.', '使用选定的 VMD 文件名与目标文档构造相机导入对话框。'),
  'source/utils/cmt_anim_flow_debug.hpp:ParseTruthyEnv': bi('Interprets an environment variable as a boolean diagnostic switch.', '将环境变量解释为布尔诊断开关。'),
  'source/utils/cmt_anim_flow_debug.hpp:ParseInt32Env': bi('Parses an integer environment variable with a caller-provided fallback.', '解析整数环境变量，并在缺失时使用调用方提供的回退值。'),
  'source/utils/cmt_anim_flow_debug.hpp:IsAnimationFlowDebugEnabled': bi('Caches and returns whether animation-flow diagnostics were enabled at process start.', '缓存并返回进程启动时是否启用了动画流程诊断。'),
  'source/utils/cmt_anim_flow_debug.hpp:GetAnimationFlowDebugBoneFilter': bi('Caches and returns the optional bone index selected for focused diagnostic output.', '缓存并返回用于聚焦诊断输出的可选骨骼索引。'),
  'source/utils/cmt_anim_flow_debug.hpp:ShouldLogAnimationFlow': bi('Reports whether general animation-flow diagnostics should be emitted.', '返回是否应输出通用动画流程诊断。'),
  'source/utils/cmt_anim_flow_debug.hpp:ShouldLogAnimationFlowForBone': bi('Combines the global diagnostic switch with the optional bone-index filter.', '将全局诊断开关与可选骨骼索引筛选结合。'),
  'source/utils/images_user_area_util.hpp:ImagesUserArea': bi('Constructs an image user area with a bitmap resource and source dimensions.', '使用位图资源与源尺寸构造图像用户区域。'),
  'source/utils/images_user_area_util.hpp:~ImagesUserArea': bi('Finalizes the image user area through its default resource-owning destructor.', '通过默认的资源持有析构函数释放图像用户区域。'),
  'source/utils/images_user_area_util.hpp:DrawMsg': bi('Draws the bitmap off-screen with scaling and alpha support to prevent flicker.', '通过离屏绘制以缩放和 Alpha 支持显示位图，从而避免闪烁。'),
};

const classSummaries = {
  'source/module/ui/vmd_loader_camera_dialog.h:VMDLoaderCameraDialog': bi('Cinema 4D dialog coordinating VMD camera import inputs, banner rendering, and command dispatch.', '协调 VMD 相机导入输入、横幅渲染与命令分派的 Cinema 4D 对话框。'),
  'source/utils/images_user_area_util.hpp:ImagesUserArea': bi('Cinema 4D GeUserArea specialization for rendering a fixed bitmap inside plugin dialogs.', '用于在插件对话框中渲染固定图像的 Cinema 4D GeUserArea 特化。'),
};

function identity(file) {
  if (file.fileCategory === 'config') return ['config', `config:${file.path}`];
  if (file.fileCategory === 'docs') return ['document', `document:${file.path}`];
  return ['file', `file:${file.path}`];
}
const complexity = (lines) => lines < 50 ? 'simple' : lines <= 200 ? 'moderate' : 'complex';
const symbolTags = (filePath, name, type) => {
  if (type === 'class' && name === 'VMDLoaderCameraDialog') return ['ui', 'dialog', 'vmd-camera'];
  if (type === 'class') return ['ui', 'image-rendering', 'user-area'];
  if (filePath.includes('cmt_anim_flow_debug')) return ['diagnostics', 'animation-flow', 'utility'];
  if (filePath.includes('vmd_loader_camera_dialog')) return ['ui', 'vmd-camera', 'event-handler'];
  if (filePath.includes('images_user_area')) return ['ui', 'image-rendering', 'utility'];
  return ['diagnostics', 'utility', 'warning-suppression'];
};

const nodes = [];
const edges = [];
for (const file of batch.files) {
  const result = results.get(file.path);
  const semantic = sourceSemantics[file.path] || sdkSemantics(file.path);
  if (!result || !semantic) throw new Error(`Missing analysis data for ${file.path}`);
  const [type, id] = identity(file);
  nodes.push({ id, type, name: path.posix.basename(file.path), filePath: file.path, summary: semantic[0], tags: semantic[1], complexity: complexity(result.nonEmptyLines) });
  if (file.fileCategory !== 'code') continue;
  const exported = new Set((result.exports || []).map((entry) => entry.name));
  for (const [kind, items] of [['function', result.functions || []], ['class', result.classes || []]]) {
    const seen = new Set();
    for (const item of items) {
      if (seen.has(item.name)) continue;
      seen.add(item.name);
      const span = item.endLine - item.startLine + 1;
      const significant = exported.has(item.name) || span >= (kind === 'function' ? 10 : 20) || (item.methods || []).length >= 2;
      if (!significant) continue;
      const key = `${file.path}:${item.name}`;
      const summary = kind === 'function' ? fnSummaries[key] : classSummaries[key];
      if (!summary) throw new Error(`Missing symbol summary ${kind}:${key}`);
      const symbolId = `${kind}:${file.path}:${item.name}`;
      nodes.push({ id: symbolId, type: kind, name: item.name, filePath: file.path, lineRange: [item.startLine, item.endLine], summary, tags: symbolTags(file.path, item.name, kind), complexity: complexity(span) });
      edges.push({ source: id, target: symbolId, type: 'contains', direction: 'forward', weight: 1.0 });
      if (exported.has(item.name)) edges.push({ source: id, target: symbolId, type: 'exports', direction: 'forward', weight: 0.8 });
    }
  }
  for (const imported of batch.batchImportData[file.path] || []) {
    edges.push({ source: id, target: `file:${imported}`, type: 'imports', direction: 'forward', weight: 0.7 });
  }
}

const add = (source, target, type = 'depends_on', weight = 0.6) => edges.push({ source, target, type, direction: 'forward', weight });
for (const version of ['r21', 'r23', 'r25']) {
  const root = `document:sdk_${version}/CMakeLists.txt`;
  add(root, `file:sdk_${version}/cmake/sdk_compat_${version}.cmake`);
  add(`config:sdk_${version}/CMakePresets.json`, root, 'configures', 0.6);
  add(`document:sdk_${version}/plugins/mmdtool/project/CMakeLists.txt`, root);
  add(`document:sdk_${version}/plugins/mmdtool/project/projectdefinition.txt`, `document:sdk_${version}/plugins/mmdtool/project/CMakeLists.txt`, 'related', 0.5);
  add(`document:sdk_${version}/plugins/project/projectdefinition.txt`, `document:sdk_${version}/plugins/mmdtool/project/projectdefinition.txt`);
}
add('file:source/module/ui/vmd_loader_camera_dialog.h', 'file:source/utils/images_user_area_util.hpp');
add('function:source/module/ui/vmd_loader_camera_dialog.cpp:CreateLayout', 'function:source/utils/images_user_area_util.hpp:ImagesUserArea', 'calls', 0.8);
add('function:source/utils/cmt_anim_flow_debug.hpp:ShouldLogAnimationFlow', 'function:source/utils/cmt_anim_flow_debug.hpp:IsAnimationFlowDebugEnabled', 'calls', 0.8);
add('function:source/utils/cmt_anim_flow_debug.hpp:ShouldLogAnimationFlowForBone', 'function:source/utils/cmt_anim_flow_debug.hpp:IsAnimationFlowDebugEnabled', 'calls', 0.8);
add('function:source/utils/cmt_anim_flow_debug.hpp:ShouldLogAnimationFlowForBone', 'function:source/utils/cmt_anim_flow_debug.hpp:GetAnimationFlowDebugBoneFilter', 'calls', 0.8);

const ids = new Set(nodes.map((node) => node.id));
if (ids.size !== nodes.length) throw new Error('Duplicate node IDs');
for (const file of batch.files) {
  const count = nodes.filter((node) => node.filePath === file.path && ['file', 'config', 'document', 'service', 'pipeline', 'schema', 'resource'].includes(node.type)).length;
  if (count !== 1) throw new Error(`File coverage failure ${file.path}: ${count}`);
}
for (const node of nodes) {
  if (!node.summary.includes(' / ')) throw new Error(`Non-bilingual summary ${node.id}`);
  if (!Array.isArray(node.tags) || node.tags.length < 3 || node.tags.length > 5) throw new Error(`Invalid tags ${node.id}`);
}
for (const edge of edges) {
  if (!ids.has(edge.source) || !ids.has(edge.target)) throw new Error(`Dangling edge ${edge.source} -> ${edge.target}`);
}
const expectedImports = batch.files.filter((file) => file.fileCategory === 'code').reduce((count, file) => count + (batch.batchImportData[file.path] || []).length, 0);
const actualImports = edges.filter((edge) => edge.type === 'imports').length;
if (actualImports !== expectedImports) throw new Error(`Import mismatch ${actualImports}/${expectedImports}`);
const parts = Math.ceil(Math.max(nodes.length / 60, edges.length / 120));
if (parts !== 1) throw new Error(`Unexpected split requirement: ${parts}`);

const output = path.join(BASE, 'batch-22.json');
fs.writeFileSync(output, `${JSON.stringify({ nodes, edges }, null, 2)}\n`);
JSON.parse(fs.readFileSync(output, 'utf8'));
console.log(JSON.stringify({ parts: 1, nodes: nodes.length, edges: edges.length, imports: actualImports, skipped: 0 }, null, 2));
