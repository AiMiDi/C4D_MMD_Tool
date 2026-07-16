import fs from 'node:fs';
import path from 'node:path';

const ROOT = 'E:/code/C4D_MMD_Tool';
const BASE = path.join(ROOT, '.ua', 'intermediate');
const TMP = path.join(ROOT, '.ua', 'tmp');
const data = JSON.parse(fs.readFileSync(path.join(BASE, 'batches.json'), 'utf8'));
const batch = data.batches.find((entry) => entry.batchIndex === 17);
if (!batch) throw new Error('Missing current batch 17');
const extracted = JSON.parse(fs.readFileSync(path.join(TMP, 'ua-file-extract-results-17.json'), 'utf8'));
if (!extracted.scriptCompleted || extracted.filesSkipped.length || extracted.results.length !== batch.files.length) {
  throw new Error('Incomplete extraction for batch 17');
}
const results = new Map(extracted.results.map((result) => [result.path, result]));
const bi = (en, zh) => `${en} / ${zh}`;
const prefix = 'res/S24_up/';

const semantics = {
  'description/OMMDBoneManager.res': [
    bi('Defines the current MMD Bone Manager Attribute Manager layout with display filters, edit or animation mode, bone creation, and control generation.', '定义当前 MMD 骨骼管理器属性面板布局，包含显示筛选、编辑或动画模式、骨骼创建与控制器生成。'),
    ['resource-definition', 'bone-manager', 'ui', 'current-sdk'],
  ],
  'description/OMMDCamera.h': [
    bi('Provides the current MMD Camera description header placeholder, reserving the generated-ID boundary for the object resource.', '提供当前 MMD 相机描述头文件占位，保留对象资源的生成 ID 边界。'),
    ['resource-definition', 'camera', 'type-definition', 'current-sdk'],
  ],
  'description/OMMDCamera.res': [
    bi('Defines the current MMD Camera object description as a minimal extension of Cinema 4D base-object attributes.', '将当前 MMD 相机对象描述定义为 Cinema 4D 基础对象属性的最小扩展。'),
    ['resource-definition', 'camera', 'object-plugin', 'current-sdk'],
  ],
  'description/OMMDJoint.h': [
    bi('Declares current PMX joint description IDs for names, rigid-body links, transforms, limits, springs, and joint-type choices.', '声明当前 PMX 关节描述 ID，覆盖名称、刚体链接、变换、限制、弹簧与关节类型选项。'),
    ['resource-definition', 'pmx-joint', 'type-definition', 'physics'],
  ],
  'description/OMMDJoint.res': [
    bi('Defines the current PMX joint Attribute Manager layout for linked rigid bodies, position and rotation, motion limits, spring values, and reset actions.', '定义当前 PMX 关节属性面板布局，包含关联刚体、位置与旋转、运动限制、弹簧参数及重置操作。'),
    ['resource-definition', 'pmx-joint', 'physics', 'ui'],
  ],
  'description/OMMDJointManager.h': [
    bi('Declares current joint-manager description IDs for display style, edit or animation mode, and joint creation.', '声明当前关节管理器描述 ID，覆盖显示样式、编辑或动画模式与关节创建。'),
    ['resource-definition', 'joint-manager', 'type-definition', 'physics'],
  ],
  'description/OMMDJointManager.res': [
    bi('Defines the current joint-manager Attribute Manager layout with display and mode quick tabs plus an add-joint action.', '定义当前关节管理器属性面板布局，包含显示与模式快速选项卡以及添加关节操作。'),
    ['resource-definition', 'joint-manager', 'physics', 'ui'],
  ],
  'description/OMMDMeshManager.h': [
    bi('Declares current mesh-manager description IDs for viewport display modes and edit or animation state.', '声明当前网格管理器描述 ID，覆盖视口显示模式与编辑或动画状态。'),
    ['resource-definition', 'mesh-manager', 'type-definition', 'viewport'],
  ],
  'description/OMMDMeshManager.res': [
    bi('Defines the current mesh-manager Attribute Manager layout for choosing viewport display style and model mode.', '定义当前网格管理器属性面板布局，用于选择视口显示样式与模型模式。'),
    ['resource-definition', 'mesh-manager', 'viewport', 'ui'],
  ],
  'description/OMMDModelManager.h': [
    bi('Declares the current model-manager parameter ID surface for model metadata, animation slots, physics, materials, morph categories, display frames, IK, and material-morph editing.', '声明当前模型管理器参数 ID 接口，覆盖模型元数据、动画槽、物理、材质、变形分类、表示框、IK 与材质变形编辑。'),
    ['resource-definition', 'model-manager', 'type-definition', 'pmx'],
  ],
  'description/OMMDModelManager.res': [
    bi('Defines the comprehensive current PMX model-manager Attribute Manager UI for animation, physics, material synchronization, all morph families, editable display frames, IK, and material-morph offsets.', '定义全面的当前 PMX 模型管理器属性面板 UI，覆盖动画、物理、材质同步、全部变形类型、可编辑表示框、IK 与材质变形偏移。'),
    ['resource-definition', 'model-manager', 'pmx', 'ui'],
  ],
  'description/OMMDRigid.h': [
    bi('Declares current PMX rigid-body description IDs for identity, collision groups, shape, bone binding, physics mode, transform, mass, friction, restitution, and damping.', '声明当前 PMX 刚体描述 ID，覆盖身份、碰撞组、形状、骨骼绑定、物理模式、变换、质量、摩擦、弹性与阻尼。'),
    ['resource-definition', 'rigid-body', 'type-definition', 'physics'],
  ],
  'description/OMMDRigid.res': [
    bi('Defines the current PMX rigid-body Attribute Manager layout for shape and pose, collision masks, bone binding, simulation mode, and physical parameters.', '定义当前 PMX 刚体属性面板布局，包含形状与姿态、碰撞掩码、骨骼绑定、模拟模式与物理参数。'),
    ['resource-definition', 'rigid-body', 'physics', 'ui'],
  ],
  'description/OMMDRigidManager.h': [
    bi('Declares current rigid-manager description IDs for display style, edit or animation mode, and rigid-body creation.', '声明当前刚体管理器描述 ID，覆盖显示样式、编辑或动画模式与刚体创建。'),
    ['resource-definition', 'rigid-manager', 'type-definition', 'physics'],
  ],
  'description/OMMDRigidManager.res': [
    bi('Defines the current rigid-manager Attribute Manager layout with display and mode quick tabs plus an add-rigid-body action.', '定义当前刚体管理器属性面板布局，包含显示与模式快速选项卡以及添加刚体操作。'),
    ['resource-definition', 'rigid-manager', 'physics', 'ui'],
  ],
  'description/TMMDBone.h': [
    bi('Declares current PMX bone-tag parameter IDs for metadata, flags, inheritance, axes, IK, morphs, control links, and animation editing.', '声明当前 PMX 骨骼标签参数 ID，覆盖元数据、标志、继承、坐标轴、IK、变形、控制链接与动画编辑。'),
    ['resource-definition', 'pmx-bone', 'type-definition', 'ik'],
  ],
  'description/TMMDBone.res': [
    bi('Defines the current PMX bone-tag Attribute Manager layout for identity, deform flags, tails, inheritance, axes, control links, IK chains, morph creation, and keyframe curves.', '定义当前 PMX 骨骼标签属性面板布局，覆盖身份、变形标志、骨骼末端、继承、坐标轴、控制链接、IK 链、变形创建与关键帧曲线。'),
    ['resource-definition', 'pmx-bone', 'ik', 'ui'],
  ],
  'description/Xmmdmaterialmorphshader.h': [
    bi('Declares current description IDs for the material-morph shader color and alpha factors.', '声明当前材质变形着色器颜色与 Alpha 因子的描述 ID。'),
    ['resource-definition', 'material-morph', 'shader', 'type-definition'],
  ],
  'description/Xmmdmaterialmorphshader.res': [
    bi('Defines the current Cinema 4D shader description exposing material-morph color and nonnegative alpha factors.', '定义当前 Cinema 4D 着色器描述，公开材质变形颜色与非负 Alpha 因子。'),
    ['resource-definition', 'material-morph', 'shader', 'ui'],
  ],
  'dialogs/DLG_CMT_TOOL.res': [
    bi('Defines the current main MMD Tool dialog with camera, motion, pose, and PMX model import, export, conversion, and workflow options.', '定义当前主 MMD Tool 对话框，包含相机、动作、姿势与 PMX 模型的导入、导出、转换及工作流选项。'),
    ['resource-definition', 'dialog', 'import-export', 'ui'],
  ],
  'dialogs/DLG_CMT_VMD_IMPORT.res': [
    bi('Defines a focused current VMD camera-import dialog with scale, frame-offset, import, and cancel controls.', '定义精简的当前 VMD 相机导入对话框，包含缩放、帧偏移、导入与取消控件。'),
    ['resource-definition', 'dialog', 'vmd-camera', 'ui'],
  ],
  'mikumikudance_data/color.txt': [
    bi('MikuMikuDance palette data listing ordered RGB values for viewport panels, timeline states, selection, and shadow colors.', 'MikuMikuDance 调色板数据，按顺序列出视口面板、时间轴状态、选择与阴影颜色的 RGB 值。'),
    ['documentation', 'palette', 'mmd-data', 'rgb'],
  ],
};

const complexity = (lines) => lines < 50 ? 'simple' : lines <= 200 ? 'moderate' : 'complex';
const nodes = [];
for (const file of batch.files) {
  const result = results.get(file.path);
  if (!result) throw new Error(`Missing extraction for ${file.path}`);
  const relative = file.path.slice(prefix.length);
  const toon = relative.match(/^mikumikudance_data\/toon(\d\d)\.bmp$/i);
  const [summary, tags] = toon
    ? [bi(`Standard MMD toon-shading texture ${toon[1]}, stored as a 32×32 24-bit RGB bitmap gradient.`, `标准 MMD 卡通着色纹理 ${toon[1]}，以 32×32、24 位 RGB 位图渐变存储。`), ['texture', 'toon-shading', 'mmd-data', 'bitmap']]
    : (semantics[relative] || []);
  if (!summary || !tags) throw new Error(`Missing semantics for ${file.path}`);
  const type = file.fileCategory === 'docs' ? 'document' : 'file';
  const id = `${type}:${file.path}`;
  nodes.push({ id, type, name: path.posix.basename(file.path), filePath: file.path, summary, tags, complexity: complexity(result.nonEmptyLines) });
}

const pairs = [
  'OMMDCamera',
  'OMMDJoint',
  'OMMDJointManager',
  'OMMDMeshManager',
  'OMMDModelManager',
  'OMMDRigid',
  'OMMDRigidManager',
  'TMMDBone',
  'Xmmdmaterialmorphshader',
];
const edges = pairs.map((name) => ({
  source: `file:${prefix}description/${name}.res`,
  target: `file:${prefix}description/${name}.h`,
  type: 'depends_on',
  direction: 'forward',
  weight: 0.6,
}));

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

const output = path.join(BASE, 'batch-17.json');
fs.writeFileSync(output, `${JSON.stringify({ nodes, edges }, null, 2)}\n`);
JSON.parse(fs.readFileSync(output, 'utf8'));
console.log(JSON.stringify({ parts: 1, nodes: nodes.length, edges: edges.length, imports: actualImports, skipped: 0 }, null, 2));
