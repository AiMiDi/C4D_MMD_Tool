const fs = require('fs');

const inputPath = process.argv[2];
const structuralPath = process.argv[3];
const outputPath = process.argv[4];
if (!inputPath || !structuralPath || !outputPath) {
  throw new Error('Usage: node ua-build-layers.js <arch-input> <arch-results> <layers-output>');
}

const input = JSON.parse(fs.readFileSync(inputPath, 'utf8'));
const structural = JSON.parse(fs.readFileSync(structuralPath, 'utf8'));
if (!structural.scriptCompleted) throw new Error('Structural analysis did not complete');
if (structural.fileStats.totalFileNodes !== 343 || input.fileNodes.length !== 343) {
  throw new Error(`Expected 343 file nodes, got ${structural.fileStats.totalFileNodes}/${input.fileNodes.length}`);
}

const definitions = [
  {
    id: 'layer:plugin-orchestration',
    name: 'Plugin Entry & Orchestration / 插件入口与编排',
    description: 'Cinema 4D lifecycle entry points, entity registration, scene-level PMX/VMD coordination, command dispatch, settings, and shared plugin configuration. / 负责 Cinema 4D 生命周期入口、实体注册、场景级 PMX/VMD 协调、命令分派、设置与共享插件配置。',
  },
  {
    id: 'layer:user-interface-import',
    name: 'User Interface & Import / 用户界面与导入',
    description: 'Cinema 4D dialogs and loader plugins that collect user options and initiate camera, motion, pose, model, and name-conversion workflows. / 提供 Cinema 4D 对话框与加载器插件，用于收集用户选项并启动相机、动作、姿势、模型与名称转换流程。',
  },
  {
    id: 'layer:model-runtime',
    name: 'MMD Model Runtime / MMD 模型运行时',
    description: 'Runtime object and tag plugins for model, mesh, bone, camera, rigid-body, joint, morph, display-frame, IK, animation, and physics behavior. / 实现模型、网格、骨骼、相机、刚体、关节、变形、表示框、IK、动画与物理行为的运行时对象和标签插件。',
  },
  {
    id: 'layer:materials-rendering',
    name: 'Materials & Rendering / 材质与渲染',
    description: 'MMD material translation, material-morph shading, and renderer adapters for Cinema 4D Standard, Redshift, Octane, and Corona. / 负责 MMD 材质转换、材质变形着色，以及 Cinema 4D Standard、Redshift、Octane 与 Corona 渲染器适配。',
  },
  {
    id: 'layer:shared-utilities',
    name: 'Shared Core & Utilities / 共享核心与工具',
    description: 'Cross-SDK compatibility, diagnostics, JSON and file I/O, math, time, identifiers, PMX helpers, bone controls, morph UI data, and reusable image widgets. / 提供跨 SDK 兼容、诊断、JSON 与文件 I/O、数学、时间、标识符、PMX 辅助、骨骼控制、变形 UI 数据与可复用图像控件。',
  },
  {
    id: 'layer:runtime-resources',
    name: 'Runtime Resources & Localization / 运行时资源与本地化',
    description: 'Current S24+ and compatibility R20–S24 Cinema 4D descriptions, dialogs, symbols, localized strings, name maps, palettes, and MMD toon textures. / 包含当前 S24+ 与兼容 R20–S24 的 Cinema 4D 描述、对话框、符号、本地化字符串、名称映射、调色板与 MMD 卡通纹理。',
  },
  {
    id: 'layer:build-sdk-integration',
    name: 'Build & SDK Integration / 构建与 SDK 集成',
    description: 'Root CMake workflows, shared dependency and plugin setup, packaging helpers, platform scripts, Git metadata, and thin Cinema 4D SDK compatibility projects from R20 through 2026. / 负责根级 CMake 工作流、共享依赖与插件设置、打包辅助、平台脚本、Git 元数据，以及从 R20 到 2026 的精简 Cinema 4D SDK 兼容工程。',
  },
  {
    id: 'layer:ci-cd',
    name: 'CI/CD Automation / CI/CD 自动化',
    description: 'GitHub Actions pipelines that build the supported SDK matrix and produce packaged plugin releases. / 通过 GitHub Actions 流水线构建受支持的 SDK 矩阵并生成插件发布包。',
  },
  {
    id: 'layer:developer-workflows',
    name: 'Agent & Developer Workflows / 智能体与开发工作流',
    description: 'Repository guidance, OpenSpec agent skills and commands, Cursor rules, prompt mirrors, and tool-specific ignore configuration used during development. / 汇集开发期间使用的仓库指南、OpenSpec 智能体技能与命令、Cursor 规则、提示词镜像及工具专用忽略配置。',
  },
  {
    id: 'layer:documentation',
    name: 'Documentation / 文档',
    description: 'English and Chinese project overviews, development guidance, licensing, and detailed PMX/VMD import, export, runtime, and animation-debug flow documentation. / 包含中英文项目概览、开发指南、许可证，以及 PMX/VMD 导入、导出、运行时与动画调试流程详解。',
  },
];

const layers = definitions.map((definition) => ({ ...definition, nodeIds: [] }));
const layerById = new Map(layers.map((layer) => [layer.id, layer]));
const normalize = (value) => String(value).replace(/\\/g, '/');

function classify(filePath) {
  const p = normalize(filePath);
  if (p.startsWith('res/')) return 'layer:runtime-resources';

  if (p.startsWith('source/')) {
    if (p.startsWith('source/module/tools/material/')) return 'layer:materials-rendering';
    if (p.startsWith('source/module/tools/object/') || p.startsWith('source/module/tools/tag/')) return 'layer:model-runtime';
    if (p.startsWith('source/module/ui/') || p.startsWith('source/module/tools/loader/')) return 'layer:user-interface-import';
    if (p.startsWith('source/module/core/') || p.startsWith('source/utils/')) return 'layer:shared-utilities';
    if (p.slice('source/'.length).includes('/')) throw new Error(`Unclassified source subsystem: ${p}`);
    return 'layer:plugin-orchestration';
  }

  if (p.startsWith('.github/workflows/')) return 'layer:ci-cd';
  if (
    p === 'AGENTS.md' ||
    p === '.cursorignore' ||
    p.startsWith('.codex/') ||
    p.startsWith('.cursor/') ||
    p.startsWith('.github/prompts/') ||
    p.startsWith('.github/skills/')
  ) return 'layer:developer-workflows';

  if (
    p.startsWith('docs/') ||
    /^(README|README_zh|DEVELOPMENT|DEVELOPMENT_zh|LICENSE)\.md$/.test(p)
  ) return 'layer:documentation';

  if (
    p.startsWith('cmake/') ||
    p.startsWith('dependency/') ||
    p.startsWith('scripts/') ||
    /^sdk_(2023|2024|2025|2026|r20|r21|r23|r25)\//.test(p) ||
    /^(CMakeLists\.txt|CMakePresets\.json|CMakeUserPresets\.SAMPLE\.json|configure_sdk\.bat|\.gitattributes|\.gitmodules)$/.test(p)
  ) return 'layer:build-sdk-integration';

  throw new Error(`Unclassified file: ${p}`);
}

for (const node of input.fileNodes) {
  const layerId = classify(node.filePath);
  layerById.get(layerId).nodeIds.push(node.id);
}
for (const layer of layers) layer.nodeIds.sort();

if (layers.length < 3 || layers.length > 10) throw new Error(`Invalid layer count ${layers.length}`);
if (layers.some((layer) => layer.nodeIds.length === 0)) throw new Error('Layer with no nodes');
const allAssigned = layers.flatMap((layer) => layer.nodeIds);
const assignedSet = new Set(allAssigned);
const inputSet = new Set(input.fileNodes.map((node) => node.id));
if (allAssigned.length !== 343 || assignedSet.size !== 343 || inputSet.size !== 343) {
  throw new Error(`Assignment count mismatch total=${allAssigned.length} unique=${assignedSet.size} input=${inputSet.size}`);
}
for (const id of inputSet) if (!assignedSet.has(id)) throw new Error(`Missing assignment ${id}`);
for (const id of assignedSet) if (!inputSet.has(id)) throw new Error(`Invented assignment ${id}`);
for (const layer of layers) {
  if (!/^layer:[a-z0-9]+(?:-[a-z0-9]+)*$/.test(layer.id)) throw new Error(`Invalid layer ID ${layer.id}`);
  if (!layer.name.includes(' / ') || !layer.description.includes(' / ')) throw new Error(`Non-bilingual layer ${layer.id}`);
}

fs.writeFileSync(outputPath, `${JSON.stringify(layers, null, 2)}\n`);
JSON.parse(fs.readFileSync(outputPath, 'utf8'));
process.stdout.write(`${JSON.stringify(Object.fromEntries(layers.map((layer) => [layer.id, layer.nodeIds.length])), null, 2)}\n`);
