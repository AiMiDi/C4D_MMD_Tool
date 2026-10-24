# 运行时阶段性能分析

`CMT_ENABLE_RUNTIME_PROFILING` 默认 `OFF`。这是用于定位开销的诊断构建；日志改变运行成本，不能直接拿插桩耗时当成正式版本帧率。

## 启用与出包约束

```powershell
cmake --preset release-windows -DCMT_ENABLE_RUNTIME_PROFILING=ON
cmake --build --preset workflow-release
$env:CMT_RUNTIME_PROFILE = '1'
$env:CMT_PROFILE_LOG = 'S:/tmp/cmt-runtime-profile.jsonl'
# 正常启动 C4D，并指定上面构建的 plugins 目录。
```

直接配置某个 SDK 时也可以传 `-DCMT_ENABLE_RUNTIME_PROFILING=ON`。开关只影响插件目标，不改变 Bullet、libMMD 和 SDK 的编译选项。
运行时环境变量首次使用后缓存；更换开关或文件路径需要重新启动该宿主。日志目录必须预先存在。
未配置日志文件或无法写入时，退回 C4D 的 `[CMT][Profile]` 控制台输出。

Release 和 package presets 显式设置 `OFF`，`cmt-package` 为每个 SDK 再次强制传 `OFF`，覆盖旧缓存。
CI 的生产构建也显式关闭。`cmake/check_profiling_disabled.cmake` 检查实际模块中的保留标记，
Windows Inno 和 macOS ZIP 包装前均执行，拒绝包含分析插桩的模块，包括下载复用的 CI 模块。
`scripts/check_release_artifacts.py` 同时检查缓存为明确的 OFF 和实际模块标记。
启用构建会导出 `CmtRuntimeProfilingBuildMarker`，返回 `CMT_RUNTIME_PROFILING=1`；关闭构建不包含此函数。

## 插入新的阶段

SDK 无关的计时核心在 `source/utils/cmt_runtime_profile.hpp`，聚合和 JSON 格式在 `cmt_runtime_profile_report.hpp`。
在 `RuntimeStage` 与对应名称表中添加阶段。名称表的编译断言防止数量不匹配。

```cpp
#include "utils/cmt_runtime_profile_c4d.hpp"

// C4D 回调或其他入口：能够建立根统计；子调用复用同一文档/时间的根。
CMT_PROFILE_FUNCTION(cmt_runtime::RuntimeStage::ModelExecute, doc);

// 已有统计上下文中的代码块：无需依赖 SDK。
{
    CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::PhysicsStep);
    physics->Update(elapsed);
}
```

独立工具可以用 `FrameMetrics(true)` 和 `ScopedFrameMetrics` 建立根，无需引入 C4D。
编译宏关闭时，两个 scope 宏都移除参数求值和时钟读取。运行时关闭仍有入口开关判断，但不初始化统计数组、不读取时钟、不输出。
核心允许注入时钟，测试嵌套、递归、自身时间与线程隔离，不依赖 sleep。

显式微基准（不属于 CTest，也不设置与机器速度有关的通过阈值）：

```powershell
cmake --build <tests-build> --config Release --target runtime_profile_benchmark runtime_profile_disabled_benchmark
<tests-build>/Release/runtime_profile_disabled_benchmark.exe
<tests-build>/Release/runtime_profile_benchmark.exe
```

该基准只比较核心嵌套 scope 的成本，不包含 SDK 上下文、根统计合并、日志格式化和磁盘写入。

## 日志与汇总

```powershell
python scripts/analyze_runtime_profile.py S:/tmp/cmt-runtime-profile.jsonl --frame-min 560 --frame-max 619 --json S:/tmp/profile-summary.json
```

每行是 schema 1 JSON 对象，包含 session/thread/document/marker、C4D 帧号/FPS/秒数、batch，以及 stages 数组：

| 字段 | 含义 |
| --- | --- |
| `calls` | 该阶段实际进入次数，包含提前返回和递归 |
| `inclusive_ms` | 包含被插桩子调用的经过时间 |
| `self_ms` | 扣除被插桩子调用，仍包含未插桩的工作 |
| `max_ms` | 单次 inclusive 耗时峰值；合并时取最大值 |
| `root_ms` / `root_calls` | 根调用经过时间和数量，不是整个 C4D 帧时间 |

内存中合并同文档/时间/线程的根调用，时间或文档变化时写一行；停止在最后一帧时，最后一批暂存到下一次上下文变化或显式 flush。
同一帧可能有多批，同一时间的重新求值也会累计。汇总工具先按 session/thread/document/marker/秒数/帧号/FPS 合并，
再给出 self 时间排名、每个时间桶均值/P95 和调用峰值。不同文档和线程不会误并成同一帧；`--document` 可以选定单个文档指针 ID。
指针 ID 只用于该进程会话内的分析，不是持久文档标识。

线程使用独立统计栈。嵌套文档恢复外层上下文，子调用从外层 self 时间扣除；跨文档的 root 时间可能重叠。
不同线程的经过时间也不能当作串行整帧时间相加。没有 spdlog 依赖；热回调只做时钟和统计，
格式化和文件锁/I/O 在最外层计时 scope 结束后执行；嵌套文档产生的输出会延后到外层结束。

`CMT_PROFILE_FLUSH()` 刷新调用线程。插件退出会刷新主线程；其他线程的最后一批需要在线程自身显式刷新。
不要在计时 scope 内 flush。诊断输出异常不会传播到 C4D，但可能丢失该批数据。
日志无限追加，需要由调用方选择本次运行的独立路径与保留范围。

## 当前覆盖与边界

已覆盖模型执行/管理器更新、动画层、骨骼标签回调与动画、层级/执行计划/附加顺序、控制器与 IK、
骨骼场景矩阵同步、物理输入/Bullet/写回、Morph 权重/应用/预览、材质同步、mesh 管理器，以及模型/骨骼 SetDParameter。
`mesh.invalidate` 统计网格和变形器更新，`mesh.weight_update` 单独统计权重标签更新；后者仅在绑定数据切换等完整刷新路径中触发。
`control.chains` 统计单次调用中的四肢链查找；`control.checksum`、`control.delta`、`control.sync`
分别覆盖控制器输入校验、活动输入检查及姿态同步。`material.ownership` 覆盖当前求值中的材质绑定计数和查找。
参数动画在 ModelManager::Execute 之前触发的预览也能建立根统计。

Bullet 通过已有 `BT_PROFILE` 回调接入：`bullet.substep` 包含预测、碰撞、岛构建、求解、积分及激活更新；
`bullet.collision` 下细分 `bullet.aabb`、`bullet.broadphase`、`bullet.dispatch`，
`bullet.solve` 下细分 setup/bodies/joints/iterations/split_impulse/finish。
父子阶段的 inclusive 时间不能相加；每帧可能执行多个物理子步，`calls` 不等于帧数。
桥接在 PluginStart 安装、PluginEnd 恢复并串接已有回调；编译关闭时不注册，运行时关闭时也不注册。
热路径使用固定容量 TLS 栈及字符串指针缓存，不分配、不加共享锁、不写日志；未知和超深区域保持配对。
仅当前线程已有统计上下文的区域会被记录。多线程物理工作线程没有根上下文时不会归入这些数据，
因此不能把串行测试的子阶段统计当成多线程世界的完整统计。

C4D 自身的 Skin 求值、视口绘制、调度和未插桩插件不在覆盖内。使用外部 `ExecutePasses` 耗时或原生分析器补全，
不要用 `root_ms` 或各阶段之和声称获得真实视口 FPS。插桩本身的影响需用编译移除、运行时关闭、运行时开启三组对照。
