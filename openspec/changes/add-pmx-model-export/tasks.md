## 1. 导出入口与 UI

- [x] 1.1 阅读 `module/core/cmt_marco.h` 和现有 camera/motion 导出代码，确认 SDK 兼容写法和文件选择流程
- [x] 1.2 在模型工具页新增 PMX 导出分组、按钮、选项资源、字符串和默认配置
- [x] 1.3 在 `CMTToolDialog::Command` 中读取 `ModelExport` 设置，调用 `SelectSuffixExportFile(..., "pmx")` 和 `CMTToolsManager::ExportPMXModel`
- [x] 1.4 接通 `CMTToolsManager::ExportPMXModel`，创建 `libmmd::PMXFile`、调用场景保存入口并用 `WritePMXFile` 写出
- [x] 1.5 修正 `CMTSceneManager::SavePMXModel` 成功路径，确保非 MMD 选择、无选择和保存失败都返回明确错误

## 2. 导出前状态同步

- [x] 2.1 抽出或复用 EDIT -> ANIM 的编辑态提交逻辑，供 PMX 导出前调用
- [x] 2.2 确保导出前同步骨骼 frozen/bind 状态、`PMX_BONE_POSITION` 和 mesh bind pose
- [x] 2.3 确保导出前同步刚体和关节的当前编辑 transform 与 PMX 参数
- [x] 2.4 在导出前刷新 bone manager 层级索引，保证 parent index、bone list 和下拉缓存一致

## 3. PMX Section 重建

- [x] 3.1 在 `MMDModelManagerObject::SavePMX` 写入 header/info、PMX version、模型名、注释和 section 调用顺序
- [x] 3.2 补齐 `MMDBoneManagerObject::SavePMX`，导出完整骨骼 flags、tail、append、axis、IK target/link/limit 和层级数据
- [x] 3.3 实现 `MMDMeshManagerObject::SavePMX`，导出 vertices、faces、normals、UVs、edge scale、weights 和材质 face ranges
- [x] 3.4 实现材质和贴图表导出，先构建去重 `m_textures`，再把材质 texture/sphere/toon 路径映射为 PMX indices
- [x] 3.5 导出 display frames 和插件已持久化的支持 morph，并保证 target indices 指向已导出的 bone/morph
- [x] 3.6 为 rigid manager 和 joint manager 增加 `SavePMX`，导出 rigid body bone binding、物理参数和 joint rigid references
- [x] 3.7 对 unsupported softbody、未知扩展和不可恢复的 SDEF/QDEF 辅助数据保持明确的 best-effort/unsupported 行为

## 4. 验证与测试

- [x] 4.1 增加 focused PMX export round-trip 测试：构造或加载小模型，导出后用 `ReadPMXFile` 重读
- [x] 4.2 测试 metadata、section counts、材质 face vertex 总数、bone parent/IK links、rigid/joint indices 等不变量
- [x] 4.3 增加失败场景测试或可验证路径：无选择、非 MMD 选择、取消保存路径、不可写路径
- [x] 4.4 运行 focused libMMD/plugin 测试并确认新增测试通过
- [x] 4.5 运行 `cmake --build --preset workflow-dev` 验证插件构建
- [x] 4.6 根据手动导出反馈修正动画表情烘焙、跨材质顶点去重、IK link fallback 和非 link `GeData::GetBaseLink()` Debug 断点

## 5. 手动验收与收尾

- [ ] 5.1 在 Cinema 4D 中导入一个 PMX，选择 ModelManager 导出 PMX，并确认导出的文件可重新导入
- [ ] 5.2 手动编辑骨骼、刚体或关节后导出，确认导出 PMX 反映编辑态而不是旧导入态
- [ ] 5.3 检查中英文 UI 文案、默认配置和资源同步后的运行时资源输出
- [x] 5.4 更新开发文档或导入/导出流程说明，记录 v1 不支持任意 C4D 转 PMX 和不保证 softbody/SDEF/QDEF 无损
- [x] 5.5 运行 `openspec status --change add-pmx-model-export` 并确认 artifacts 和任务清单可被 OpenSpec 识别
