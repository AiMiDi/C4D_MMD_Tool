import fs from 'node:fs';
import path from 'node:path';

const ROOT = 'E:/code/C4D_MMD_Tool';
const BASE = path.join(ROOT, '.ua', 'intermediate');
const TMP = path.join(ROOT, '.ua', 'tmp');
const batches = JSON.parse(fs.readFileSync(path.join(BASE, 'batches.json'), 'utf8'));
const bi = (en, zh) => `${en} / ${zh}`;

const summaries = {
  '.cursor/commands/opsx-apply.md': bi('Cursor command specification for selecting an OpenSpec change, reading apply instructions, implementing remaining tasks, and updating completion state.', 'Cursor 命令规范，用于选择 OpenSpec 变更、读取应用指令、实现剩余任务并更新完成状态。'),
  '.cursor/commands/opsx-archive.md': bi('Cursor command specification for validating artifact and task completion, synchronizing specifications, and archiving an OpenSpec change with confirmation gates.', 'Cursor 命令规范，用于校验产物与任务完成度、同步规范，并通过确认门槛归档 OpenSpec 变更。'),
  '.cursor/commands/opsx-explore.md': bi('Cursor exploration-mode guidance for investigating code and requirements as a read-only thinking partner while remaining aware of OpenSpec context.', 'Cursor 探索模式指南，要求以只读思考伙伴身份调查代码与需求，同时关注 OpenSpec 上下文。'),
  '.cursor/commands/opsx-propose.md': bi('Cursor command specification for deriving a change name and generating the complete OpenSpec proposal, design, specifications, and task artifacts.', 'Cursor 命令规范，用于推导变更名称并生成完整的 OpenSpec 提案、设计、规范与任务产物。'),
  '.github/prompts/opsx-apply.prompt.md': bi('GitHub prompt for selecting an OpenSpec change, following dynamic apply instructions, implementing remaining tasks, and recording progress.', 'GitHub 提示词，用于选择 OpenSpec 变更、遵循动态应用指令、实现剩余任务并记录进度。'),
  '.github/prompts/opsx-archive.prompt.md': bi('GitHub prompt for checking completion, warning about unfinished work, synchronizing specifications, and archiving an OpenSpec change.', 'GitHub 提示词，用于检查完成状态、警告未完成工作、同步规范并归档 OpenSpec 变更。'),
  '.github/prompts/opsx-explore.prompt.md': bi('GitHub exploration prompt that frames read-only code and requirement discovery as an adaptive, visualization-friendly thinking mode.', 'GitHub 探索提示词，将只读代码与需求调查定义为自适应且鼓励可视化的思考模式。'),
  '.github/prompts/opsx-propose.prompt.md': bi('GitHub prompt for turning a requested change into a scaffold and generating all required OpenSpec artifacts in dependency order.', 'GitHub 提示词，用于将变更请求转为脚手架，并按依赖顺序生成全部必需的 OpenSpec 产物。'),
  'sdk_2025/CMakeLists.txt': bi('Cinema 4D 2025 SDK root build configuration that initializes compiler settings, discovers plugin modules, loads frameworks, and defines output directories.', 'Cinema 4D 2025 SDK 根构建配置，负责初始化编译器设置、发现插件模块、加载框架并定义输出目录。'),
  'sdk_2025/CMakePresets.json': bi('Cross-platform configure presets for building the Cinema 4D 2025 SDK tree with Ninja, Xcode, Visual Studio v143, or ClangCL.', '用于通过 Ninja、Xcode、Visual Studio v143 或 ClangCL 构建 Cinema 4D 2025 SDK 树的跨平台配置预设。'),
  'sdk_2025/custom_paths.txt': bi('Documented Cinema 4D SDK custom-path template describing ROOT, MODULE, and ALIAS commands for optional module discovery and path aliases.', '带说明的 Cinema 4D SDK 自定义路径模板，描述用于可选模块发现与路径别名的 ROOT、MODULE 和 ALIAS 命令。'),
  'sdk_2026/CMakeLists.txt': bi('Cinema 4D 2026 SDK root build configuration that initializes C++20 tooling, discovers plugin modules, loads frameworks, and defines build outputs.', 'Cinema 4D 2026 SDK 根构建配置，负责初始化 C++20 工具链、发现插件模块、加载框架并定义构建输出。'),
  'sdk_2026/CMakePresets.json': bi('Cross-platform configure presets for the Cinema 4D 2026 SDK tree, including Visual Studio 2022 v143, Visual Studio 2026 v145, and ClangCL.', 'Cinema 4D 2026 SDK 树的跨平台配置预设，包含 Visual Studio 2022 v143、Visual Studio 2026 v145 与 ClangCL。'),
  'sdk_2026/sdk_modules.txt': bi('SDK module-list configuration that selects plugins/mmdtool as the module loaded by the Cinema 4D 2026 build system.', 'SDK 模块列表配置，指定 Cinema 4D 2026 构建系统加载 plugins/mmdtool 模块。'),
};

const tags = {
  '.cursor/commands/opsx-apply.md': ['documentation', 'openspec', 'workflow', 'implementation'],
  '.cursor/commands/opsx-archive.md': ['documentation', 'openspec', 'workflow', 'archival'],
  '.cursor/commands/opsx-explore.md': ['documentation', 'openspec', 'exploration', 'read-only'],
  '.cursor/commands/opsx-propose.md': ['documentation', 'openspec', 'workflow', 'proposal'],
  '.github/prompts/opsx-apply.prompt.md': ['documentation', 'openspec', 'prompt', 'implementation'],
  '.github/prompts/opsx-archive.prompt.md': ['documentation', 'openspec', 'prompt', 'archival'],
  '.github/prompts/opsx-explore.prompt.md': ['documentation', 'openspec', 'prompt', 'exploration'],
  '.github/prompts/opsx-propose.prompt.md': ['documentation', 'openspec', 'prompt', 'proposal'],
  'sdk_2025/CMakeLists.txt': ['build-system', 'cmake', 'sdk', 'module-discovery'],
  'sdk_2025/CMakePresets.json': ['configuration', 'cmake', 'cross-platform', 'sdk'],
  'sdk_2025/custom_paths.txt': ['configuration', 'module-discovery', 'path-alias', 'sdk'],
  'sdk_2026/CMakeLists.txt': ['build-system', 'cmake', 'sdk', 'module-discovery'],
  'sdk_2026/CMakePresets.json': ['configuration', 'cmake', 'cross-platform', 'sdk'],
  'sdk_2026/sdk_modules.txt': ['configuration', 'module-discovery', 'sdk', 'plugin'],
};

const notes = {
  'sdk_2025/CMakeLists.txt': bi('Uses Maxon SDK helper modules and custom-path parsing rather than compiling the shared plugin source directly at the root.', '使用 Maxon SDK 辅助模块与自定义路径解析，而不是在根目录直接编译共享插件源码。'),
  'sdk_2026/CMakeLists.txt': bi('Uses Maxon SDK helper modules and custom-path parsing rather than compiling the shared plugin source directly at the root.', '使用 Maxon SDK 辅助模块与自定义路径解析，而不是在根目录直接编译共享插件源码。'),
};

const complexity = (lines) => lines < 50 ? 'simple' : lines <= 200 ? 'moderate' : 'complex';
const nodeIdentity = (file) => file.fileCategory === 'config'
  ? ['config', `config:${file.path}`]
  : ['document', `document:${file.path}`];

function build(index) {
  const batch = batches.batches.find((entry) => entry.batchIndex === index);
  if (!batch) throw new Error(`Missing current batch ${index}`);
  if (batch.files.some((file) => file.path.startsWith('openspec/'))) throw new Error(`Excluded openspec path in batch ${index}`);
  const extracted = JSON.parse(fs.readFileSync(path.join(TMP, `ua-file-extract-results-${index}.json`), 'utf8'));
  if (!extracted.scriptCompleted || extracted.filesSkipped.length || extracted.results.length !== batch.files.length) {
    throw new Error(`Incomplete structural extraction for batch ${index}`);
  }
  const resultByPath = new Map(extracted.results.map((result) => [result.path, result]));
  const nodes = batch.files.map((file) => {
    const result = resultByPath.get(file.path);
    if (!result) throw new Error(`Missing extraction for ${file.path}`);
    const [type, id] = nodeIdentity(file);
    const node = {
      id,
      type,
      name: path.posix.basename(file.path),
      filePath: file.path,
      summary: summaries[file.path],
      tags: tags[file.path],
      complexity: complexity(result.nonEmptyLines),
    };
    if (!node.summary || !node.tags) throw new Error(`Missing semantics for ${file.path}`);
    if (notes[file.path]) node.languageNotes = notes[file.path];
    return node;
  });
  const edges = [];
  const edge = (source, target, type, weight) => edges.push({ source, target, type, direction: 'forward', weight });
  if (index === 7) {
    edge('document:.cursor/commands/opsx-explore.md', 'document:.cursor/commands/opsx-propose.md', 'related', 0.5);
    edge('document:.cursor/commands/opsx-propose.md', 'document:.cursor/commands/opsx-apply.md', 'related', 0.5);
    edge('document:.cursor/commands/opsx-apply.md', 'document:.cursor/commands/opsx-archive.md', 'related', 0.5);
  } else if (index === 8) {
    edge('document:.github/prompts/opsx-explore.prompt.md', 'document:.github/prompts/opsx-propose.prompt.md', 'related', 0.5);
    edge('document:.github/prompts/opsx-propose.prompt.md', 'document:.github/prompts/opsx-apply.prompt.md', 'related', 0.5);
    edge('document:.github/prompts/opsx-apply.prompt.md', 'document:.github/prompts/opsx-archive.prompt.md', 'related', 0.5);
  } else if (index === 11) {
    edge('config:sdk_2025/CMakePresets.json', 'document:sdk_2025/CMakeLists.txt', 'configures', 0.6);
    edge('document:sdk_2025/CMakeLists.txt', 'document:sdk_2025/custom_paths.txt', 'depends_on', 0.6);
  } else if (index === 12) {
    edge('config:sdk_2026/CMakePresets.json', 'document:sdk_2026/CMakeLists.txt', 'configures', 0.6);
    edge('document:sdk_2026/sdk_modules.txt', 'document:sdk_2026/CMakeLists.txt', 'related', 0.5);
  }
  return { batch, nodes, edges };
}

function validateAndWrite(index, graph) {
  const ids = new Set(graph.nodes.map((node) => node.id));
  if (ids.size !== graph.nodes.length) throw new Error(`Duplicate node in batch ${index}`);
  for (const file of graph.batch.files) {
    if (graph.nodes.filter((node) => node.filePath === file.path).length !== 1) throw new Error(`File coverage failure ${file.path}`);
  }
  for (const node of graph.nodes) {
    if (!node.summary.includes(' / ')) throw new Error(`Non-bilingual summary ${node.id}`);
    if (!Array.isArray(node.tags) || node.tags.length < 3 || node.tags.length > 5) throw new Error(`Invalid tags ${node.id}`);
  }
  for (const edge of graph.edges) {
    if (!ids.has(edge.source) || !ids.has(edge.target)) throw new Error(`Dangling edge ${edge.source} -> ${edge.target}`);
  }
  const expectedImports = graph.batch.files.filter((file) => file.fileCategory === 'code')
    .reduce((count, file) => count + (graph.batch.batchImportData[file.path] || []).length, 0);
  const actualImports = graph.edges.filter((edge) => edge.type === 'imports').length;
  if (actualImports !== expectedImports) throw new Error(`Import mismatch batch ${index}: ${actualImports}/${expectedImports}`);
  const output = path.join(BASE, `batch-${index}.json`);
  fs.writeFileSync(output, `${JSON.stringify({ nodes: graph.nodes, edges: graph.edges }, null, 2)}\n`);
  JSON.parse(fs.readFileSync(output, 'utf8'));
  return { parts: 1, nodes: graph.nodes.length, edges: graph.edges.length, imports: actualImports };
}

const totals = {};
for (const index of [7, 8, 11, 12]) totals[index] = validateAndWrite(index, build(index));
console.log(JSON.stringify(totals, null, 2));
