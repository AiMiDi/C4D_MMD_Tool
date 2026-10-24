# VMD 播放优化交接（2026-10-20）

继续优化 `C:/code/C4D_MMD_Tool` 的 VMD 视口播放，目标是在保持已接受的物理效果下接近 60 fps。
本次阶段提交包含累计播放优化、可复用插桩、发布防护、物理子步设置与验证记录。
工作区另有动作适配、UI、图标和本机配置改动，不属于此次提交；先看 `git status`，不要覆盖或整体暂存。

## 已保留的实现

- 单次模型求值复用执行计划和控制器骨骼分类，跳过空的物理后层；同帧重新求值仍重新检查。
- 材质所有权计数仅在一次求值内复用；纯姿态播放不再向未修改的权重标签发送重复 `MSG_UPDATE`。
- `CMT_ENABLE_RUNTIME_PROFILING` 默认 OFF；分析版按文档、时间、线程聚合 JSONL，细分 Bullet 内部阶段。
  Release/package presets、CI 和实际模块检查共同防止插桩进入发布包。
- 每动画帧物理子步数默认 3，范围 1–10，频率 = 文档 fps × 子步数；当前 30 fps 场景为 90 Hz。
  这已取代此前固定 60 Hz 的方案。修改子步数会改变物理轨迹；fps/子步变化会冷重置，含同帧原始容器写入。
- MSVC SDK Release 的 7 个 Bullet/libMMD 目标使用 `/O2 /fp:strict /Ob0 /Oi-`。
  Maxon SDK 清空全局 Release flags，原始 214 条依赖编译命令没有优化选项。
  普通 `/O2` 和 `/O2 /fp:precise` 均产生轨迹偏差，已排除；不应直接重新启用。

## 当前证据与限制

最新依赖优化对照：关闭插桩的整帧 `ExecutePasses` 均值 **53.00 → 43.45 ms（-18.0%）**，
双方各 240 帧且换回基线复测。开启插桩时 Bullet **23.06 → 13.77 ms（-40.3%）**。
这两个口径不可直接相减；`ExecutePasses` 包含 Skin/缓存求值但不含视口绘制，不是播放 FPS。
关闭物理仍为 **27–31 ms/帧**，本轮没有确认提速，仍未达到 16.67 ms 的预算。

最终 OFF Release 在 C4D 2027 通过 112 个骨骼矩阵/实际变形网格精确对照，
完整 620 帧骨骼位置、12 个完整几何检查点和末帧 PNG 均与本轮基线逐字节一致。
子步数默认/范围/旧文件、撤销、克隆、保存重开、同帧冷重置验证通过。
14 项相关依赖测试通过；额外动作适配高级测试运行约 290 秒仍未结束后中止，不能声称全套通过。
此前重型 Python 网格导出造成的宿主崩溃尚未解决，轻量回放成功不代表崩溃已修复。
这些结论有场景和版本边界，旧 SDK 资源同步不等于旧版宿主验收。

## 接下来做什么

1. 优先细分关闭物理时的 C4D 求值、Skin/变形缓存及重复更新；这部分已超过 60 fps 帧预算。
2. 物理侧可继续拆分 AABB 纯计算与 broadphase 提交，再根据实测决定是否并行。
   共享动态树不能直接并行写，C4D 对象访问也不能直接搬到工作线程。
3. MT world 曾在隔离实验运行，但相对正式版改变轨迹，且未建立可信提速；正式版仍是串行世界。
   上一轮混入依赖 flags 变化的计时不能用于归因多线程收益。
4. 每轮保持相同输入、子步数、编译选项并进行前后/反向复测；计时关闭导出与插桩，
   效果单独比较骨骼及实际变形网格，保留所有样本。

## 入口与现场

- 最新完整报告：[Release 依赖优化验证](../validation/vmd-dependency-release-20261020/README.md)；
  同目录 `receipt.json` 保存身份、原始采样与验收回执。
- [插桩用法](runtime-profile.md)、[运行流程](runtime-flow.md)、
  [Bullet/控制器及 MT 实验](../validation/vmd-bullet-controller-performance-20261019/README.md)。
- 原始现场：`S:/tmp/cmt_vmd_profile_20261019`，最新实验在 `optimization_round8`；
  可清理的临时目录，不是永久资产备份。
- 预览：`S:/tmp/cmt_vmd_profile_20261019/optimized_release_playback_preview.c4d`。
  隔离插件：`S:/tmp/cmt_vmd_profile_20261019/profiler-build/bin/Release/plugins/mmdtool/mmdtool.xdl64`。
- 宿主操作只用原生 MCP，不用电脑操控。现有入口是
  `python S:/tmp/cmt_vmd_profile_20261019/host_call.py`，连接 `http://127.0.0.1:5557/mcp`；
  无参数只读 PID、版本和活动文档。先重新核实进程和加载模块，历史 PID 不能作为当前身份。
- 隔离构建源在 `S:/tmp/cmt_vmd_profile_20261019/frozen`；修改工作区后必须显式同步相关文件、
  构建并核实实际加载模块，不能假定临时源码会自动跟随工作区。
- 保留用户原场景、其他宿主进程和共享安装。出包必须确认 profiling 宏 OFF 并检查实际二进制。
