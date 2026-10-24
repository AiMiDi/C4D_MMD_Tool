> 本文只保留结论。逐次测量日志、原始记录与脚本已从版本库移出，归档在 `S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\` 下同名目录。

# VMD 播放：合并控制器查找与材质归属扫描

本轮在上一轮权重通知优化之上，减少四肢控制器和材质表情求值中的重复遍历。物理参数、求解器、步进、矩阵算法均未改动；同场景骨骼矩阵和实际变形顶点精确一致。尚未达到 60 FPS。

宏关闭的 Release 复测中，主线程 CPU 时间：开启物理旧版 **70.05 ms/帧**，新版两次 **65.10 / 63.02 ms/帧**；关闭物理旧版 **41.67 ms/帧**，新版 **29.17 / 30.73 ms/帧**。这是 OS CPU 时间，不能换算为视口播放 FPS。后台编译使早先第二轮墙钟时间明显失真，所有原始数据均保留，不报告合并的固定加速比例。

## 修改范围

- `source/utils/mmd_control_workflow.cpp`：`CollectExtraControls` 和 `SolveLayer` 各自在一次调用内用 `FindLimbChains` 集中查找左右手脚，复用名称转换和分类。保留骨骼顺序、链骨骼取最后一个、足 IK 目标取第一个、secondary 与本地/通用名称优先级。
- `source/module/tools/object/mmd_model_morph_runtime.cpp`：一次材质运行时求值内集中统计场景中的材质绑定次数，替代每个材质分别遍历整棵场景树；仍逐材质验证 owner 与 shader/graph。
- `source/utils/mmd_bone_control_util.cpp`、`source/utils/cmt_runtime_profile.hpp`：补充控制器链查找、输入校验、活动输入、姿态同步及材质归属阶段。

结果只在一次调用内共享，不跨调用/帧缓存。同帧修改名称、IK 标志、控制器或材质链接仍重新读取。控制器求解顺序和浮点计算没有改动。

## 同场景与计时方法

Cinema 4D 2027.0.0，MSVC v143 Release；场景快照含 625 骨骼、479 刚体、748 约束、35 网格、70,222 顶点，时间轴 30 FPS。使用独立宿主配置和 MCP 5557；各次重新加载快照，先求值帧 0、预热 540–559，再计时 560–619 共 60 帧。

`ExecutePasses` 包含缓存/蒙皮求值，排除采样、文件写入和视口绘制。所有性能轮关闭几何采集；效果对比独立进行。冻结前后源代码，运行时源码仅上述四个文件不同。原文档状态检查均通过。

### 墙钟原始结果

| 轮次顺序 | 版本 | 物理开 ms/帧 | 物理关 ms/帧 |
| --- | --- | ---: | ---: |
| A1 | 旧 | 74.78 | 40.35 |
| B1 | 新 | 60.64 | 29.68 |
| A2 | 旧 | 108.92 | 71.91 |
| B2 | 新 | 148.41 | 81.44 |
| B3 | 新 | 67.42 | 30.32 |
| A3 | 旧 | 72.63 | 41.85 |
| B4 | 新 | 64.25 | 31.16 |

A2/B2 期间存在多个 MSBuild/cl 后台进程，顺序甚至反转；没有删除这组数据或据此宣称稳定整帧加速。后续 B3 → A3 → B4 在同一调用线程用 `time.thread_time_ns()` 补充 CPU 时间，减少等待调度的影响，原始每帧数组及进程 CPU 时间也保存在 receipt 中。OS 计数有量化误差，以下为 60 帧均值。

| 主线程 CPU | B3 新版 | A3 旧版 | B4 新版 |
| --- | ---: | ---: | ---: |
| 开启物理 ms/帧 | 65.10 | 70.05 | 63.02 |
| 关闭物理 ms/帧 | 29.17 | 41.67 | 30.73 |

### 分阶段插桩

单独使用 ON 构建定位；每种状态选取最后两次完整 560–619 连续区间，共 120 帧。以下均为 inclusive ms/帧：

| 阶段 | 物理开旧 → 新 | 物理关旧 → 新 |
| --- | ---: | ---: |
| `control.solve` | 5.778 → 1.956 | 6.041 → 1.893 |
| `material.sync` | 4.977 → 2.963 | 5.793 → 2.987 |

新阶段 `control.chains` 为 3.876 / 3.594 ms/帧，涵盖每帧六次查找调用，是多个父阶段的子项，不能与父阶段相加。材质归属总查询为 0.244 / 0.219 ms/帧；每次求值首个查询执行场景扫描，后续使用该次局部计数。

新增子阶段改变了 `model.execute` 的 self 统计边界，不能把旧/新 self 差额当作优化收益。Bullet 未修改，其本次 ON 耗时 36.82 → 29.89 ms/帧的变化不能归因于本轮代码；也说明阶段墙钟值会随环境漂移。新版 Bullet 单项仍高于 60 FPS 的 16.67 ms 预算。

## 效果与构建验证

- ON/OFF 两个候选各通过 112 个样本：连续播放 60、跳帧 13、混合物理阶段 13、全部 after-physics 13、关闭物理 13。625 骨骼的世界/局部矩阵及 70,222 个实际变形顶点全部精确相同，最大误差 0。
- 额外 17 个边界场景在旧版 OFF、新版 OFF、新版 ON 中精确相同：创建控制器、强制 IK/FK、移动目标与同帧保持、本地/通用名称替换、缺失/恢复链骨骼和目标链接、IK 标志切换，以及重复/缺失/共享材质绑定。还比较可访问的材质 UserData 值和诊断状态。
- 原生控制器工作流旧/新版各通过 72 项检查，包含保存重开。
- 第 619 帧 960×720 视口截图与原基线 PNG 字节完全一致；姿态最终哈希也一致。
- Release ON/OFF 构建通过；`control_role_test`、`control_workflow_test`、`material_morph_runtime_test`、`runtime_profile_test`、`runtime_profile_disabled_test`、`runtime_profile_report_test`、`profile_package_guard_test` 七项通过。
- 最终实际 OFF 模块通过出包标记检查；即使环境变量开启 profiling，也未生成 profile 日志。未制作安装包，未提交 Git。

## 证据

- [receipt.json](receipt.json)：源文件和模块哈希、所有计时数组、阶段统计、精确对比及原生测试结果。
- [viewport-frame619.png](viewport-frame619.png)：最终视口；[final-host.json](final-host.json) 记录最终宿主、场景与帧号；[tests.log](tests.log) 保存七项测试结果。
- `boundaries.py`：本轮控制器与材质边界场景；`compare_cpu.py`：补充 CPU 计时采样；`summarize_profiles.py`：阶段窗口筛选；`collect_receipt.py`：证据归集和一致性断言。
- 完整原始模型、几何数组、日志和 ON/OFF 运行目录位于 `S:/tmp/cmt_vmd_profile_20261019`；不复制资产进入仓库。

验证范围为当前场景及上述有限边界，不代表全部 PMX 模型或多模型性能。最终预览使用宏关闭的候选 Release。
独立测试宿主 PID 64960 加载 `S:/tmp/cmt_vmd_profile_20261019/profiler-build/bin/Release/plugins/mmdtool/mmdtool.xdl64`，
活动文档为 `CMT VMD preview`，帧 619；副本保存为 `S:/tmp/cmt_vmd_profile_20261019/optimized_control_material_preview.c4d`。
