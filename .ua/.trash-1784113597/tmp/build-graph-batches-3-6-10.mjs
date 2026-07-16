import fs from 'node:fs';
import path from 'node:path';

const root = 'E:/code/C4D_MMD_Tool';
const ua = path.join(root, '.ua');
const intermediate = path.join(ua, 'intermediate');
const tmp = path.join(ua, 'tmp');
const requested = [3, 6, 10];

const readJson = (p) => JSON.parse(fs.readFileSync(p, 'utf8'));
const bi = (english, chinese) => `${english} / ${chinese}`;
const tag = bi;
const complexityFor = (nonEmptyLines) => nonEmptyLines > 200 ? 'complex' : nonEmptyLines >= 50 ? 'moderate' : 'simple';

const batchCatalog = readJson(path.join(intermediate, 'batches.json')).batches;
for (const batchIndex of requested) {
  const canonical = batchCatalog.find((item) => item.batchIndex === batchIndex);
  const input = readJson(path.join(tmp, `ua-file-analyzer-input-${batchIndex}.json`));
  if (!canonical) throw new Error(`Missing canonical batch ${batchIndex}`);
  if (JSON.stringify(input.batchFiles) !== JSON.stringify(canonical.files)) {
    throw new Error(`batchFiles mismatch for batch ${batchIndex}`);
  }
  if (JSON.stringify(input.batchImportData) !== JSON.stringify(canonical.batchImportData)) {
    throw new Error(`batchImportData mismatch for batch ${batchIndex}`);
  }
}

const materialFileInfo = {
  'source/module/tools/material/mmd_corona_material.cpp': {
    summary: bi('Implements conversion between persistent MMD material data and Corona materials, including renderer-specific texture and channel wiring.', '实现持久化 MMD 材质数据与 Corona 材质之间的转换，包括渲染器专用的贴图与通道连接。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('corona', 'Corona'), tag('material-sync', '材质同步'), tag('cinema-4d', 'Cinema 4D')]
  },
  'source/module/tools/material/mmd_corona_material.h': {
    summary: bi('Declares the final Corona material adapter that creates, synchronizes, and reads Corona materials through the shared MMD adapter interface.', '声明最终的 Corona 材质适配器，通过共享 MMD 适配器接口创建、同步并读取 Corona 材质。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('corona', 'Corona'), tag('interface', '接口'), tag('type-definition', '类型定义')]
  },
  'source/module/tools/material/mmd_material.cpp': {
    summary: bi('Implements the renderer-agnostic MMD material data model, adapter factory and dispatch, PMX conversion, persistence, runtime-state checksums, and texture loading.', '实现与渲染器无关的 MMD 材质数据模型、适配器工厂与分发、PMX 转换、持久化、运行时状态校验和及贴图加载。'),
    tags: [tag('material-system', '材质系统'), tag('adapter-factory', '适配器工厂'), tag('serialization', '序列化'), tag('pmx-conversion', 'PMX 转换'), tag('runtime-state', '运行时状态')]
  },
  'source/module/tools/material/mmd_material.h': {
    summary: bi('Defines persistent and runtime MMD material state, the renderer adapter abstraction and factory surface, and the texture-aware material manager.', '定义持久化与运行时 MMD 材质状态、渲染器适配器抽象与工厂接口，以及感知贴图的材质管理器。'),
    tags: [tag('material-model', '材质模型'), tag('renderer-abstraction', '渲染器抽象'), tag('runtime-state', '运行时状态'), tag('type-definition', '类型定义')]
  },
  'source/module/tools/material/mmd_material_morph_shader.cpp': {
    summary: bi('Implements a Cinema 4D wrapper shader that applies precomputed PMX texture-morph factors to a child shader without reading mutable scene state during rendering.', '实现 Cinema 4D 包装 Shader，将预计算的 PMX 贴图表情系数应用于子 Shader，并在渲染期间避免读取可变场景状态。'),
    tags: [tag('shader', '着色器'), tag('material-morph', '材质表情'), tag('render-runtime', '渲染运行时'), tag('plugin-registration', '插件注册')]
  },
  'source/module/tools/material/mmd_material_morph_shader.h': {
    summary: bi('Declares the texture-morph ShaderData plugin, its render-time factor snapshot, child-shader sampling hooks, and registration entry point.', '声明贴图表情 ShaderData 插件、渲染时系数快照、子 Shader 采样钩子及注册入口。'),
    tags: [tag('shader', '着色器'), tag('material-morph', '材质表情'), tag('type-definition', '类型定义'), tag('plugin-api', '插件接口')]
  },
  'source/module/tools/material/mmd_octane_material.cpp': {
    summary: bi('Implements MMD data synchronization for Octane universal materials and translates renderer node parameters back into the common material model.', '实现 MMD 数据与 Octane Universal 材质的同步，并将渲染器节点参数反向转换为通用材质模型。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('octane', 'Octane'), tag('node-material', '节点材质'), tag('material-sync', '材质同步')]
  },
  'source/module/tools/material/mmd_octane_material.h': {
    summary: bi('Declares the final Octane adapter for creating, writing, and reading Octane materials through the shared MMD interface.', '声明最终的 Octane 适配器，通过共享 MMD 接口创建、写入并读取 Octane 材质。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('octane', 'Octane'), tag('interface', '接口'), tag('type-definition', '类型定义')]
  },
  'source/module/tools/material/mmd_redshift_material.cpp': {
    summary: bi('Implements Redshift material creation and bidirectional property synchronization, including renderer-specific node and texture handling.', '实现 Redshift 材质创建与属性双向同步，包括渲染器专用的节点和贴图处理。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('redshift', 'Redshift'), tag('node-material', '节点材质'), tag('material-sync', '材质同步')]
  },
  'source/module/tools/material/mmd_redshift_material.h': {
    summary: bi('Declares the final Redshift adapter, which uses renderer-specific alpha inspection while sharing the common MMD material contract.', '声明最终的 Redshift 适配器，在共享通用 MMD 材质契约的同时采用渲染器专用的 Alpha 检测。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('redshift', 'Redshift'), tag('interface', '接口'), tag('type-definition', '类型定义')]
  },
  'source/module/tools/material/mmd_standard_material.cpp': {
    summary: bi('Implements Standard-material creation and round-trip synchronization, toon and texture resolution, and non-accumulating runtime texture-morph wrapper updates.', '实现 Standard 材质创建与往返同步、Toon 与贴图解析，以及非累积的运行时贴图表情包装 Shader 更新。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('standard-material', '标准材质'), tag('material-morph', '材质表情'), tag('texture-pipeline', '贴图流水线'), tag('runtime-sync', '运行时同步')]
  },
  'source/module/tools/material/mmd_standard_material.h': {
    summary: bi('Declares the Standard material adapter and its runtime-state override for texture-morph wrapper shaders.', '声明 Standard 材质适配器及其用于贴图表情包装 Shader 的运行时状态覆盖。'),
    tags: [tag('renderer-adapter', '渲染器适配器'), tag('standard-material', '标准材质'), tag('runtime-state', '运行时状态'), tag('type-definition', '类型定义')]
  }
};

const classInfo = {
  ModelImport: [bi('Forward declaration for the model-import settings consumed by material loading.', '模型导入设置的前置声明，供材质加载流程使用。'), [tag('type-definition', '类型定义'), tag('import-settings', '导入设置'), tag('forward-declaration', '前置声明')]],
  MMDMaterialData: [bi('Stores the complete PMX material fields plus Cinema 4D material and mesh links for persistence, editing, and round-trip export.', '保存完整 PMX 材质字段以及 Cinema 4D 材质与网格链接，用于持久化、编辑和往返导出。'), [tag('data-model', '数据模型'), tag('pmx-material', 'PMX 材质'), tag('serialization', '序列化'), tag('round-trip', '往返转换')]],
  MMDMaterialRuntimeState: [bi('Represents a per-frame material-morph composition rebuilt from base data, with texture factors and a checksum for dirty-state suppression.', '表示每帧由基础数据重新合成的材质表情状态，包含贴图系数与用于抑制无效更新的校验和。'), [tag('runtime-state', '运行时状态'), tag('material-morph', '材质表情'), tag('checksum', '校验和'), tag('non-accumulating', '非累积')]],
  MMDMaterialAdapter: [bi('Defines the polymorphic renderer adapter contract and factories used to create, synchronize, and inspect Cinema 4D materials.', '定义多态渲染器适配器契约与工厂，用于创建、同步和检查 Cinema 4D 材质。'), [tag('interface', '接口'), tag('factory', '工厂'), tag('renderer-abstraction', '渲染器抽象'), tag('material-sync', '材质同步')]],
  MMDMaterialManager: [bi('Owns resolved PMX texture paths and creates imported materials using the selected renderer adapter.', '持有解析后的 PMX 贴图路径，并通过所选渲染器适配器创建导入材质。'), [tag('service', '服务'), tag('texture-loading', '贴图加载'), tag('material-import', '材质导入'), tag('resource-management', '资源管理')]],
  MMDMaterialTextureMorphShader: [bi('Wraps a child shader and applies immutable render-time RGB and alpha morph factors to its sampled output.', '包装子 Shader，并将不可变的渲染时 RGB 与 Alpha 表情系数应用于其采样输出。'), [tag('shader', '着色器'), tag('material-morph', '材质表情'), tag('render-runtime', '渲染运行时'), tag('wrapper', '包装器')]],
  MMDCoronaMaterialAdapter: [bi('Adapts Corona materials to the shared MMD material creation and synchronization contract.', '将 Corona 材质适配到共享的 MMD 材质创建与同步契约。'), [tag('renderer-adapter', '渲染器适配器'), tag('corona', 'Corona'), tag('material-sync', '材质同步')]],
  MMDOctaneMaterialAdapter: [bi('Adapts Octane materials to the shared MMD material creation and synchronization contract.', '将 Octane 材质适配到共享的 MMD 材质创建与同步契约。'), [tag('renderer-adapter', '渲染器适配器'), tag('octane', 'Octane'), tag('material-sync', '材质同步')]],
  MMDRedShiftMaterialAdapter: [bi('Adapts Redshift materials to the shared MMD contract with renderer-specific alpha handling.', '以渲染器专用 Alpha 处理将 Redshift 材质适配到共享 MMD 契约。'), [tag('renderer-adapter', '渲染器适配器'), tag('redshift', 'Redshift'), tag('alpha-detection', 'Alpha 检测')]],
  MMDStandardMaterialAdapter: [bi('Adapts Cinema 4D Standard materials and additionally applies runtime texture-morph state.', '适配 Cinema 4D Standard 材质，并额外应用运行时贴图表情状态。'), [tag('renderer-adapter', '渲染器适配器'), tag('standard-material', '标准材质'), tag('runtime-sync', '运行时同步')]]
};

function rendererFor(filePath) {
  if (filePath.includes('corona')) return ['Corona', 'Corona'];
  if (filePath.includes('octane')) return ['Octane', 'Octane'];
  if (filePath.includes('redshift')) return ['Redshift', 'Redshift'];
  if (filePath.includes('standard')) return ['Standard', 'Standard'];
  return ['Cinema 4D', 'Cinema 4D'];
}

function functionInfo(filePath, name) {
  const [rendererEn, rendererZh] = rendererFor(filePath);
  const commonTags = [tag('function', '函数'), tag('material-system', '材质系统'), tag('cinema-4d', 'Cinema 4D')];
  const specific = {
    DetectType: [bi('Detects which supported renderer material type a Cinema 4D material uses.', '检测 Cinema 4D 材质所属的受支持渲染器材质类型。'), [tag('type-detection', '类型检测'), tag('renderer-dispatch', '渲染器分发'), tag('validation', '验证')]],
    DetectTextureFromPMX: [bi('Resolves PMX texture metadata and determines whether the referenced texture provides alpha.', '解析 PMX 贴图元数据，并判断引用贴图是否提供 Alpha。'), [tag('texture-detection', '贴图检测'), tag('pmx-import', 'PMX 导入'), tag('alpha-detection', 'Alpha 检测')]],
    DetectTextureFromData: [bi('Inspects stored MMD material texture data to derive texture and alpha availability.', '检查已存储的 MMD 材质贴图数据，以确定贴图与 Alpha 可用性。'), [tag('texture-detection', '贴图检测'), tag('material-data', '材质数据'), tag('alpha-detection', 'Alpha 检测')]],
    Create: [bi('Constructs the concrete material adapter for a requested renderer type.', '为请求的渲染器类型构造具体材质适配器。'), [tag('factory', '工厂'), tag('renderer-adapter', '渲染器适配器'), tag('object-creation', '对象创建')]],
    CreateFor: [bi('Detects a material renderer and returns the matching concrete adapter.', '检测材质渲染器并返回匹配的具体适配器。'), [tag('factory', '工厂'), tag('renderer-dispatch', '渲染器分发'), tag('material-detection', '材质检测')]],
    SyncToMaterial: [bi('Dispatches persistent MMD material data to the renderer adapter matching the target material.', '将持久化 MMD 材质数据分发给与目标材质匹配的渲染器适配器。'), [tag('material-sync', '材质同步'), tag('renderer-dispatch', '渲染器分发'), tag('adapter', '适配器')]],
    ReadFromMaterial: [bi('Dispatches reverse synchronization from a Cinema 4D material into the common MMD data model.', '将 Cinema 4D 材质的反向同步分发到通用 MMD 数据模型。'), [tag('material-sync', '材质同步'), tag('reverse-mapping', '反向映射'), tag('adapter', '适配器')]],
    SyncRuntimeStateToMaterial: [bi('Dispatches composed runtime material-morph state to the adapter for the target material.', '将合成后的运行时材质表情状态分发给目标材质的适配器。'), [tag('runtime-sync', '运行时同步'), tag('material-morph', '材质表情'), tag('renderer-dispatch', '渲染器分发')]],
    FromPMX: [bi('Populates the persistent material data model from a PMX material record.', '从 PMX 材质记录填充持久化材质数据模型。'), [tag('pmx-import', 'PMX 导入'), tag('data-mapping', '数据映射'), tag('material-data', '材质数据')]],
    ToPMX: [bi('Writes persistent material data back to PMX fields and resolved texture indices.', '将持久化材质数据写回 PMX 字段及解析后的贴图索引。'), [tag('pmx-export', 'PMX 导出'), tag('data-mapping', '数据映射'), tag('round-trip', '往返转换')]],
    Read: [bi('Deserializes persistent MMD material fields and links from a Cinema 4D HyperFile.', '从 Cinema 4D HyperFile 反序列化持久化 MMD 材质字段与链接。'), [tag('deserialization', '反序列化'), tag('persistence', '持久化'), tag('material-data', '材质数据')]],
    Write: [bi('Serializes persistent MMD material fields and links to a Cinema 4D HyperFile.', '将持久化 MMD 材质字段与链接序列化到 Cinema 4D HyperFile。'), [tag('serialization', '序列化'), tag('persistence', '持久化'), tag('material-data', '材质数据')]],
    CopyTo: [bi('Copies the full persistent material record, preserving managed Cinema 4D links.', '复制完整持久化材质记录，并保留受管理的 Cinema 4D 链接。'), [tag('copying', '复制'), tag('material-data', '材质数据'), tag('resource-management', '资源管理')]],
    FromBase: [bi('Initializes a fresh non-accumulating runtime state from base material values.', '从基础材质值初始化新的非累积运行时状态。'), [tag('runtime-state', '运行时状态'), tag('material-morph', '材质表情'), tag('initialization', '初始化')]],
    WriteSupportedFieldsTo: [bi('Projects runtime-composed fields supported by the material system into a material-data copy.', '将材质系统支持的运行时合成字段投影到材质数据副本。'), [tag('runtime-state', '运行时状态'), tag('data-mapping', '数据映射'), tag('material-sync', '材质同步')]],
    Checksum: [bi('Hashes the effective runtime material state so unchanged frames can skip renderer synchronization.', '哈希有效运行时材质状态，使未变化帧可跳过渲染器同步。'), [tag('checksum', '校验和'), tag('dirty-detection', '脏状态检测'), tag('performance', '性能')]],
    SetTextureRelativePath: [bi('Sets the base path used to resolve PMX texture references during import.', '设置导入期间用于解析 PMX 贴图引用的基础路径。'), [tag('path-resolution', '路径解析'), tag('texture-loading', '贴图加载'), tag('configuration', '配置')]],
    LoadPMXTextures: [bi('Resolves and stores the PMX texture table as Cinema 4D filenames for later material creation.', '将 PMX 贴图表解析并保存为 Cinema 4D 文件名，供后续材质创建使用。'), [tag('texture-loading', '贴图加载'), tag('pmx-import', 'PMX 导入'), tag('resource-management', '资源管理')]],
    SDK2024_Init: [bi('Initializes the ShaderData instance using the SDK-appropriate initialization contract.', '使用适配当前 SDK 的初始化契约初始化 ShaderData 实例。'), [tag('initialization', '初始化'), tag('shader', '着色器'), tag('sdk-compatibility', 'SDK 兼容')]],
    InitRender: [bi('Snapshots morph factors and initializes the wrapped child shader for a render session.', '为渲染会话快照表情系数并初始化被包装的子 Shader。'), [tag('render-lifecycle', '渲染生命周期'), tag('shader', '着色器'), tag('material-morph', '材质表情')]],
    FreeRender: [bi('Releases render-session state held by the wrapped child shader.', '释放被包装子 Shader 持有的渲染会话状态。'), [tag('render-lifecycle', '渲染生命周期'), tag('shader', '着色器'), tag('resource-management', '资源管理')]],
    Output: [bi('Samples the child shader and applies the immutable RGB and alpha morph factors to its result.', '采样子 Shader，并将不可变的 RGB 与 Alpha 表情系数应用于结果。'), [tag('shader-evaluation', '着色器求值'), tag('material-morph', '材质表情'), tag('render-runtime', '渲染运行时')]],
    RegisterMMDMaterialTextureMorphShader: [bi('Registers the MMD texture-morph ShaderData plugin with Cinema 4D.', '向 Cinema 4D 注册 MMD 贴图表情 ShaderData 插件。'), [tag('plugin-registration', '插件注册'), tag('shader', '着色器'), tag('entry-point', '入口点')]],
    IsIdentityFactor: [bi('Checks whether texture-morph RGB and alpha factors leave a sampled texture unchanged.', '检查贴图表情的 RGB 与 Alpha 系数是否保持采样贴图不变。'), [tag('validation', '验证'), tag('material-morph', '材质表情'), tag('utility', '工具函数')]],
    ComponentMultiply: [bi('Multiplies two Cinema 4D vectors component by component for morph-factor composition.', '对两个 Cinema 4D 向量逐分量相乘，用于表情系数组合。'), [tag('math', '数学'), tag('material-morph', '材质表情'), tag('utility', '工具函数')]],
    ResolveToonTexturePath: [bi('Resolves shared or per-material PMX toon texture references to a concrete path.', '将共享或材质独立的 PMX Toon 贴图引用解析为具体路径。'), [tag('path-resolution', '路径解析'), tag('toon-texture', 'Toon 贴图'), tag('pmx-import', 'PMX 导入')]],
    SetChannelTexture: [bi('Installs a bitmap texture shader into a Standard material channel.', '将位图贴图 Shader 安装到 Standard 材质通道。'), [tag('texture-binding', '贴图绑定'), tag('standard-material', '标准材质'), tag('shader', '着色器')]],
    SetChannelTextureIfUnwrapped: [bi('Assigns a channel texture only when the channel is not already wrapped by the morph shader.', '仅在通道尚未被表情 Shader 包装时分配通道贴图。'), [tag('texture-binding', '贴图绑定'), tag('material-morph', '材质表情'), tag('guard', '保护逻辑')]],
    SetTextureMorphShaderFactor: [bi('Writes precomputed RGB and alpha factors into a texture-morph wrapper shader.', '将预计算的 RGB 与 Alpha 系数写入贴图表情包装 Shader。'), [tag('runtime-sync', '运行时同步'), tag('shader-parameters', '着色器参数'), tag('material-morph', '材质表情')]],
    SyncTextureMorphChannel: [bi('Creates, updates, or removes a Standard-channel wrapper shader to represent the effective texture-morph factor without nesting repeatedly.', '创建、更新或移除 Standard 通道包装 Shader，以表达有效贴图表情系数且避免重复嵌套。'), [tag('runtime-sync', '运行时同步'), tag('shader-wrapper', '着色器包装器'), tag('material-morph', '材质表情'), tag('non-accumulating', '非累积')]],
    SyncRuntimeState: filePath.endsWith('.h')
      ? [bi('Provides the base adapter no-op hook for renderer-specific runtime material state.', '提供基础适配器的空操作钩子，用于渲染器专用运行时材质状态。'), [tag('extension-point', '扩展点'), tag('runtime-state', '运行时状态'), tag('renderer-adapter', '渲染器适配器')]]
      : [bi('Applies composed runtime texture factors to Standard material channels through morph wrapper shaders.', '通过表情包装 Shader 将合成后的运行时贴图系数应用到 Standard 材质通道。'), [tag('runtime-sync', '运行时同步'), tag('standard-material', '标准材质'), tag('material-morph', '材质表情')]],
    '~MMDMaterialAdapter': [bi('Provides a virtual default destructor for polymorphic renderer adapters.', '为多态渲染器适配器提供虚默认析构函数。'), [tag('lifecycle', '生命周期'), tag('interface', '接口'), tag('renderer-adapter', '渲染器适配器')]],
    MMDMaterialManager: [bi('Default-constructs the texture-aware MMD material manager.', '默认构造感知贴图的 MMD 材质管理器。'), [tag('constructor', '构造函数'), tag('material-manager', '材质管理器'), tag('lifecycle', '生命周期')]],
    '~MMDMaterialManager': [bi('Default-destroys the MMD material manager and its managed texture-path storage.', '默认析构 MMD 材质管理器及其受管理的贴图路径存储。'), [tag('destructor', '析构函数'), tag('material-manager', '材质管理器'), tag('lifecycle', '生命周期')]]
  };

  if (specific[name]) return specific[name];
  if (name === 'SyncTo') {
    return [bi(`Writes common MMD material values into a ${rendererEn} material using renderer-specific parameters.`, `使用渲染器专用参数将通用 MMD 材质值写入 ${rendererZh} 材质。`), [tag('material-sync', '材质同步'), tag('renderer-adapter', '渲染器适配器'), tag('forward-mapping', '正向映射')]];
  }
  if (name === 'ReadFrom') {
    return [bi(`Reads a ${rendererEn} material back into the common MMD material data model.`, `将 ${rendererZh} 材质反向读取到通用 MMD 材质数据模型。`), [tag('material-sync', '材质同步'), tag('renderer-adapter', '渲染器适配器'), tag('reverse-mapping', '反向映射')]];
  }
  return [bi(`Implements ${name} as part of the MMD material subsystem.`, `作为 MMD 材质子系统的一部分实现 ${name}。`), commonTags];
}

function makeMaterialBatch() {
  const batchIndex = 3;
  const input = readJson(path.join(tmp, `ua-file-analyzer-input-${batchIndex}.json`));
  const extraction = readJson(path.join(tmp, `ua-file-extract-results-${batchIndex}.json`));
  if (!extraction.scriptCompleted || extraction.filesAnalyzed !== input.batchFiles.length) {
    throw new Error('Batch 3 extraction did not complete for every file');
  }
  const nodes = [];
  const edges = [];
  for (const result of extraction.results) {
    const info = materialFileInfo[result.path];
    if (!info) throw new Error(`Missing material file semantics for ${result.path}`);
    const fileId = `file:${result.path}`;
    nodes.push({
      id: fileId,
      type: 'file',
      name: path.posix.basename(result.path),
      filePath: result.path,
      summary: info.summary,
      tags: info.tags,
      complexity: complexityFor(result.nonEmptyLines)
    });
    const exported = new Set((result.exports ?? []).map((item) => item.name));
    for (const fn of result.functions ?? []) {
      const lineCount = fn.endLine - fn.startLine + 1;
      if (lineCount < 10 && !exported.has(fn.name)) continue;
      const [summary, tags] = functionInfo(result.path, fn.name);
      const id = `function:${result.path}:${fn.name}`;
      nodes.push({id, type: 'function', name: fn.name, filePath: result.path, lineRange: [fn.startLine, fn.endLine], summary, tags, complexity: complexityFor(lineCount)});
      edges.push({source: fileId, target: id, type: 'contains', direction: 'forward', weight: 1.0});
      if (exported.has(fn.name)) edges.push({source: fileId, target: id, type: 'exports', direction: 'forward', weight: 0.8});
    }
    for (const cls of result.classes ?? []) {
      const lineCount = cls.endLine - cls.startLine + 1;
      if (lineCount < 20 && (cls.methods ?? []).length < 2 && !exported.has(cls.name)) continue;
      const infoPair = classInfo[cls.name];
      if (!infoPair) throw new Error(`Missing class semantics for ${cls.name}`);
      const [summary, tags] = infoPair;
      const id = `class:${result.path}:${cls.name}`;
      nodes.push({id, type: 'class', name: cls.name, filePath: result.path, lineRange: [cls.startLine, cls.endLine], summary, tags, complexity: complexityFor(lineCount)});
      edges.push({source: fileId, target: id, type: 'contains', direction: 'forward', weight: 1.0});
      if (exported.has(cls.name)) edges.push({source: fileId, target: id, type: 'exports', direction: 'forward', weight: 0.8});
    }
    for (const targetPath of input.batchImportData[result.path]) {
      edges.push({source: fileId, target: `file:${targetPath}`, type: 'imports', direction: 'forward', weight: 0.7});
    }
  }
  return {batchIndex, files: input.batchFiles.map((item) => item.path), input, nodes, edges, skipped: extraction.filesSkipped ?? []};
}

function makePipelineBatch() {
  const batchIndex = 6;
  const extraction = readJson(path.join(tmp, `ua-file-extract-results-${batchIndex}.json`));
  const nodes = [
    {
      id: 'pipeline:.github/workflows/build.yml', type: 'pipeline', name: 'build.yml', filePath: '.github/workflows/build.yml',
      summary: bi('Reusable GitHub Actions build pipeline that compiles eight Cinema 4D SDK targets on Windows and macOS, caches shared dependencies, and uploads per-platform plugin artifacts.', '可复用的 GitHub Actions 构建流水线，在 Windows 与 macOS 上编译八个 Cinema 4D SDK 目标，缓存共享依赖并上传逐平台插件产物。'),
      tags: [tag('ci-cd', '持续集成与交付'), tag('matrix-build', '矩阵构建'), tag('cross-platform', '跨平台'), tag('cmake', 'CMake'), tag('artifact', '构建产物')],
      complexity: complexityFor(extraction.results.find((item) => item.path.endsWith('build.yml')).nonEmptyLines)
    },
    {
      id: 'pipeline:.github/workflows/package.yml', type: 'pipeline', name: 'package.yml', filePath: '.github/workflows/package.yml',
      summary: bi('Tag-triggered release pipeline that reuses the build workflow, assembles a Windows Inno installer and per-SDK macOS archives, then publishes all assets to a GitHub Release.', '由版本标签触发的发布流水线，复用构建工作流，组装 Windows Inno 安装包与逐 SDK macOS 压缩包，并将全部资产发布到 GitHub Release。'),
      tags: [tag('ci-cd', '持续集成与交付'), tag('release', '发布'), tag('packaging', '打包'), tag('inno-setup', 'Inno Setup'), tag('github-release', 'GitHub 发布')],
      complexity: complexityFor(extraction.results.find((item) => item.path.endsWith('package.yml')).nonEmptyLines)
    }
  ];
  const edges = [{source: 'pipeline:.github/workflows/package.yml', target: 'pipeline:.github/workflows/build.yml', type: 'depends_on', direction: 'forward', weight: 0.6}];
  return {batchIndex, files: extraction.results.map((item) => item.path), input: readJson(path.join(tmp, `ua-file-analyzer-input-${batchIndex}.json`)), nodes, edges, skipped: extraction.filesSkipped ?? []};
}

function makeDocsBatch() {
  const batchIndex = 10;
  const extraction = readJson(path.join(tmp, `ua-file-extract-results-${batchIndex}.json`));
  const nonEmpty = Object.fromEntries(extraction.results.map((item) => [item.path, item.nonEmptyLines]));
  const defs = [
    ['anim-flow-debug.md', 'docs/dev/anim-flow-debug.md', bi('Diagnostic guide for the animation, IK, and physics execution pipeline, covering debug environment variables, structured log fields, fault hypotheses, LLDB data capture, and cleanup.', '动画、IK 与物理执行流水线诊断指南，涵盖调试环境变量、结构化日志字段、故障假设、LLDB 数据采集与收尾。'), [tag('documentation', '文档'), tag('debugging', '调试'), tag('animation-pipeline', '动画流水线'), tag('ik', 'IK'), tag('physics', '物理')]],
    ['export-flow.md', 'docs/dev/export-flow.md', bi('Developer map of PMX model and VPD pose export, including orchestration, pre-export state synchronization, known v1 limits, failure paths, and manual acceptance checks.', 'PMX 模型与 VPD 姿势导出的开发者代码地图，包括编排、导出前状态同步、已知 v1 限制、失败路径与手动验收检查。'), [tag('documentation', '文档'), tag('export-flow', '导出流程'), tag('pmx', 'PMX'), tag('vpd', 'VPD'), tag('validation', '验证')]],
    ['import-flow.md', 'docs/dev/import-flow.md', bi('Developer map of PMX model, VMD motion, VPD pose, and VMD camera import, with detailed ownership, material-morph persistence and runtime composition, UI entry points, and troubleshooting.', 'PMX 模型、VMD 动作、VPD 姿势与 VMD 相机导入的开发者代码地图，详述所有权、材质表情持久化与运行时合成、UI 入口及故障定位。'), [tag('documentation', '文档'), tag('import-flow', '导入流程'), tag('pmx', 'PMX'), tag('vmd', 'VMD'), tag('material-morph', '材质表情')]],
    ['runtime-flow.md', 'docs/dev/runtime-flow.md', bi('Runtime architecture guide describing ownership boundaries, standalone bone, IK, and physics reconstruction, per-frame execution layers, mode transitions, invalidation points, and troubleshooting.', '运行时架构指南，描述所有权边界、独立骨骼、IK 与物理重建、逐帧执行分层、模式切换、失效点及故障定位。'), [tag('documentation', '文档'), tag('runtime-flow', '运行时流程'), tag('ownership', '所有权'), tag('animation', '动画'), tag('physics', '物理')]]
  ];
  const nodes = defs.map(([name, filePath, summary, tags]) => ({id: `document:${filePath}`, type: 'document', name, filePath, summary, tags, complexity: complexityFor(nonEmpty[filePath])}));
  const edges = [
    {source: 'document:docs/dev/anim-flow-debug.md', target: 'document:docs/dev/runtime-flow.md', type: 'related', direction: 'forward', weight: 0.5},
    {source: 'document:docs/dev/export-flow.md', target: 'document:docs/dev/import-flow.md', type: 'related', direction: 'forward', weight: 0.5},
    {source: 'document:docs/dev/import-flow.md', target: 'document:docs/dev/runtime-flow.md', type: 'related', direction: 'forward', weight: 0.5}
  ];
  return {batchIndex, files: extraction.results.map((item) => item.path), input: readJson(path.join(tmp, `ua-file-analyzer-input-${batchIndex}.json`)), nodes, edges, skipped: extraction.filesSkipped ?? []};
}

function validateFragment(fragment, batch, allNodeIds) {
  if (!Array.isArray(fragment.nodes) || !Array.isArray(fragment.edges)) throw new Error(`Malformed fragment for batch ${batch.batchIndex}`);
  const ids = new Set(fragment.nodes.map((node) => node.id));
  if (ids.size !== fragment.nodes.length) throw new Error(`Duplicate node id in batch ${batch.batchIndex}`);
  const importPaths = new Set(Object.values(batch.input.batchImportData).flat());
  for (const edge of fragment.edges) {
    if (!ids.has(edge.source)) throw new Error(`Unknown source ${edge.source} in batch ${batch.batchIndex}`);
    const targetFile = edge.target.startsWith('file:') ? edge.target.slice(5) : null;
    if (!ids.has(edge.target) && !allNodeIds.has(edge.target) && !(targetFile && importPaths.has(targetFile))) {
      throw new Error(`Unknown target ${edge.target} in batch ${batch.batchIndex}`);
    }
    if (edge.source === edge.target) throw new Error(`Self edge ${edge.source}`);
  }
}

function writeBatch(batch) {
  const nodeCount = batch.nodes.length;
  const edgeCount = batch.edges.length;
  const partCount = nodeCount <= 60 && edgeCount <= 120 ? 1 : Math.ceil(Math.max(nodeCount / 60, edgeCount / 120));
  const sortedFiles = [...batch.files].sort((a, b) => a.localeCompare(b));
  const chunkSize = Math.ceil(sortedFiles.length / partCount);
  const allNodeIds = new Set(batch.nodes.map((node) => node.id));
  const written = [];
  for (let index = 0; index < partCount; index += 1) {
    const partFiles = new Set(sortedFiles.slice(index * chunkSize, (index + 1) * chunkSize));
    const nodes = batch.nodes.filter((node) => partFiles.has(node.filePath));
    const nodeIds = new Set(nodes.map((node) => node.id));
    const edges = batch.edges.filter((edge) => nodeIds.has(edge.source));
    const fragment = {nodes, edges};
    validateFragment(fragment, batch, allNodeIds);
    const filename = partCount === 1 ? `batch-${batch.batchIndex}.json` : `batch-${batch.batchIndex}-part-${index + 1}.json`;
    fs.writeFileSync(path.join(intermediate, filename), `${JSON.stringify(fragment, null, 2)}\n`, 'utf8');
    JSON.parse(fs.readFileSync(path.join(intermediate, filename), 'utf8'));
    written.push(filename);
  }
  const importsExpected = Object.values(batch.input.batchImportData).flat().length;
  const importsActual = batch.edges.filter((edge) => edge.type === 'imports').length;
  if (importsActual !== importsExpected) throw new Error(`Batch ${batch.batchIndex} import edge mismatch: ${importsActual}/${importsExpected}`);
  return {batchIndex: batch.batchIndex, written, nodeCount, edgeCount, skipped: batch.skipped};
}

const reports = [makeMaterialBatch(), makePipelineBatch(), makeDocsBatch()].map(writeBatch);
process.stdout.write(JSON.stringify(reports));
