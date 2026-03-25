## 1. Group/Flip Morph 叠加语义改造

- [x] 1.1 修改 `GroupMorph::UpdateMorph`（mmd_morph.cpp）：将 `SetStrength(node, GetStrength(node) * data.GetValue())` 改为叠加语义 `SetStrength(node, GetStrength(node) + self_strength * data.GetValue())`，先读取子 morph 当前值再加上 group 的贡献
- [x] 1.2 修改 `FlipMorph::UpdateMorph`（mmd_morph.cpp）：将覆写改为叠加语义，当 `GetStrength >= 0.5` 时将 `data.GetValue()` 叠加到子 morph 当前强度上
- [x] 1.3 修改 `MMDModelManagerObject::Execute` 中的 `UpdateMorph` 循环（mmd_model_manager.cpp:885-891）：分两轮遍历 — 第一轮只执行 Group/Flip 类型的 `UpdateMorph`（传播到子 morph），第二轮执行其余类型（Mesh/UV/Bone/Material/Impulse）

## 2. VMD 导入时创建 CTrack 关键帧

- [x] 2.1 在 `MMDModelManagerObject` 中实现 `SetMorphAnimation` 方法（参考注释代码 1611-1649 行），接受 morph 名称、帧号、权重，通过 `morph_name_` 查找 index → `morph_data_[index].GetStrengthDescID()` → 创建/复用 CTrack → 添加 CKey 并设置 `CINTERPOLATION_LINEAR`
- [x] 2.2 在 `LoadVMDMotion` 中，`VMDAnimation::Add` 完成后，遍历 `vmd_file.m_morphs` 调用 `SetMorphAnimation`，将每个 morph 关键帧写入 CTrack
- [x] 2.3 未匹配的 morph 名称收集到 `std::set` 或类似容器，导入完成后赋值给 `LoadVmdMotionLog::not_find_morph_name_list`

## 3. 导入日志反馈

- [x] 3.1 确认 `LoadVmdMotionLog::not_find_morph_name_list` 成员存在且类型合适，必要时调整或补充声明
- [x] 3.2 在导入报告对话框中展示未匹配 morph 名称列表（当 `detail_report` 为 true 且列表非空时），参考已有的骨骼未匹配报告格式

## 4. 取消 VMD 模式表情 UI 隐藏

- [x] 4.1 修改 `MMDModelManagerObject::GetDDescription`（mmd_model_manager.cpp:2058-2062）：移除 `MODEL_MODE_VMD` 下对 `MODEL_MORPH_GRP` 的 `DESC_HIDE` 设置
- [x] 4.2 将 VMD 模式的 morph UI 可见性逻辑与非编辑模式统一 — 隐藏添加/删除/重命名按钮，保留强度滑块可见

## 5. 移除 MeshManager 的 VMD morph 覆盖路径

- [x] 5.1 移除 `MMDMeshManagerObject::Execute` 中 `MESH_MODE_VMD && mmd_morph_manager_` 的 morph 权重读取块（mmd_mesh_manager.cpp:283-301）
- [x] 5.2 移除 `mmd_morph_manager_` 成员变量及其赋值/初始化逻辑
- [x] 5.3 移除 `morph_manager_index_` 成员变量及其在 `RefreshMeshMorphData` 等位置的构建逻辑
- [x] 5.4 清理 `mmd_mesh_manager.h` 中对应的成员声明和相关 include

## 6. 清理注释代码

- [x] 6.1 移除 `SetMeshMorphAnimation` 的旧注释代码（mmd_model_manager.cpp:1611-1649），替换为新实现
- [x] 6.2 移除 `SetModelControllerAnimation` 的旧注释代码（mmd_model_manager.cpp:1651+），如果不在本次范围内则保留但添加 TODO 注释
