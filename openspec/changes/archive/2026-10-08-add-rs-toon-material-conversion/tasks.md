# RS Toon 实施任务

## 1. 原生图与画面原型

- [x] 1.1 固定当前 Morph 依赖切片、宿主/RS 版本与所用模块；交付可追溯的原型环境记录，不复用其他模块的通过结论。
- [x] 1.2 探测 Toon、Contour、Tonemap、User Data 资产及端口；在任务自有文档创建最小图，读回角色/连接并渲染实际图片，记录可用能力与失败原因。
- [x] 1.3 用普通 UV 验证共用 Toon、独立 Toon、无 Toon 默认 Ramp、主贴图 RGB/RGBA、透明切口与描边；输出对照图片，确认不需要 Additional UV。
- [x] 1.4 校准 Toon 取样方向、默认 Ramp、高光 power 映射、Contour 线宽缩放和颜色空间；将参数及近似边界写入 profile v1 说明，并用固定灯光图片验证高光与描边响应。revision 2 的已有证据保留；revision 3 新增高光遮罩后需重新完成画面校准。

## 2. 类型、图配方与能力判断

- [x] 2.1 追加 RS Toon 类型并集中导入/UI/adapter 映射；用旧配置和枚举回归验证原值不变、默认仍为 Standard，旧 SDK 的未知/不可用分支可解释。
- [x] 2.2 提取完整 MMD 基础材质解析入口，新增 Toon adapter 与窄 RS 公共工具；验证导入/条目创建得到相同 Toon 路径和图角色，Standard/RS Standard 原有图保持兼容。
- [x] 2.3 实现有版本的 profile 元数据、surface/output 身份验证及无文档副作用的能力探测；验证多 surface、缺失端口与节点不可用时不错误认领或降级。
- [x] 2.4 完成普通 UV 主贴图、Toon、风格化高光和逐材质 Contour 图；原生读回加实际图像覆盖 edge 开关、零宽度、零 specular、全局 contour 和合并/拆网格差异，更新材质支持说明。

## 3. Morph 绑定与编辑

- [x] 3.1 用字段描述表扩展创建、验证、发布、清理和复制，保留旧四字段编号；测试 Toon RGB 与 edge 字段及缺失元数据情形，确认不存在 key 碰撞和遗留属性。
- [x] 3.2 接入 Material/Group/Flip、混合预览和文档局部求值；用 0/15/30/0 与重复求值验证画面复现、重置和节点数量稳定。
- [x] 3.3 支持主贴图及 Toon 角色的显式路径编辑；原生验证 RGB/RGBA/空路径、共用/独立 Toon、坏文件诊断、采样设置保留及手工连接保护，更新 Morph 使用说明。
- [x] 3.4 输出按实际使用情况生成的兼容诊断；验证默认模型没有 Additional UV 告警，明确使用 SubTexture/额外 UV Morph 时有对应提示且仍可转换受支持部分。

## 4. 转换事务与使用入口

- [x] 4.1 实现当前条目的分配解析和原子转换；验证 TextureTag 与模型链接共同切换，共享旧材质、多个选区和其他模型不被误改，原材质保留。
- [x] 4.2 将绑定准备失败、歧义目标和中途失败纳入回滚；失败注入检查材质、Tag、User Data 与链接完全恢复，成功转换三轮 Undo/Redo 后每一步立即保存重开。
- [x] 4.3 在导入和材质管理 UI 增加 RS Toon 选项、转换当前材质动作、支持诊断及中英文资源；验证 EDIT/预览门控、旧选择持久化、不可用原因和界面可操作性，更新导入文档。
- [x] 4.4 生产导入协议、能力列表、维护中的 MCP schema 同步 `redshift_toon`；从正式接口验证与 UI 导入一致，禁用材质时无需 Toon 能力，启用但不支持时不产生半导入场景。
- [x] 4.5 对复制模型、独立材质和手工图编辑完成原生回归；验证所有权隔离、显式修复和普通重开恢复，并补齐转换使用与回退说明。

## 5. 集成验收

- [x] 5.1 构建 SDK 2026、2024、R20 并执行受影响的现有材质/Morph 回归；记录准确构建配置，编译通过与运行时可用性分别登记。
- [x] 5.2 在新模块上执行 RS GPU 与 CPU 的 Toon/Morph 图片矩阵及保存重开后的复验；记录模块/profile 身份、灯光、色彩管理、像素与结构，资源失败不算画面通过。
- [x] 5.3 制作一个代表性模型的 RS Standard/RS Toon 并排结果；有 MMD 原生参考时加入同条件对照，否则标明参考缺失，记录分层、脸部阴影、透明发丝和轮廓的外观判断及剩余差异。
- [x] 5.4 汇总规范场景的完成状态、未支持功能和精确证据，核对提案/设计/支持文档一致，严格 OpenSpec 校验及额外验证按用户 2026-10-08 要求跳过，不报告为通过；不得把实施任务或图像验收提前标为完成。

完成与部分验证的精确范围见 [validation.md](validation.md)。未勾选项保留完整验收要求，不代表对应代码尚未实现。

## 6. 实际丝袜对齐（用户后续范围）

- [x] 6.1 接入普通 Sphere Multiply/Add、独立 Mul/Add RGBA 与受控路径/模式编辑；原生验证坏文件、艺术家连接、Undo/Redo 和立即保存重开，保留 SubTexture/Additional UV 诊断。
- [x] 6.2 在实际阿芙模型单方向光下对照 Sphere 亮带、Toon 偏移和数值颜色解释，记录新候选的 CPU/GPU 图像及重开结果；保留与 PmxView 参考的剩余差异。

本轮原生范围与 GUI 加载状态见 [sphere-production-validation.md](sphere-production-validation.md)。

## 7. RS Standard 与默认材质的 Matcap Sphere（用户后续范围）

- [x] 7.1 接入两种材质的相机法线 Matcap 加/乘，独立 Sphere RGBA Morph 与路径/模式编辑；保留旧场景与艺术家图并避免 Alpha 污染。
- [x] 7.2 用原生导入、编辑、Undo/Redo、重开和受控渲染验证两条路径，构建兼容 SDK 并记录剩余外观差异。

本轮 Matcap Sphere 的最终候选、旧绑定迁移与 11 张图片见 [standard-sphere-validation.md](standard-sphere-validation.md)。

本轮最终模块、原生故障回滚、51 张图片与高光校准见 [completion-validation.md](completion-validation.md)。严格校验按用户明确要求跳过。
