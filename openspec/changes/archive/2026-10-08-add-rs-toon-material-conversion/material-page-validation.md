# MMD 材质页读取检查

日期：2026-10-07。用户报告打开“模型信息 → MMD 材质”后卡住并退出。

后续用户反馈“现在不崩了好像”，同意继续材质工作。这作为一次 GUI 复测暂未复现记录，不提升为已经证明原始终止机制的结论。

## 代码路径

- `OMMDModelManager.res` 的 `MODEL_MATERIAL_GRP` 定义材质列表、原生材质链接、基础参数、纹理路径和转换按钮。
- `MMDModelManagerObject::GetDDescription` 生成动态列表，同时更新材质 Morph、展示枠等其他属性组；材质/偏移索引读取有范围检查。
- `GetDParameter` 读取所选基础数据及链接；颜色子通道沿用 SDK `HandleDescGetVector`。这一读路径不调用材质属性同步。
- `GetDEnabling` 计算转换按钮等控件是否可用。
- 原先状态和按钮回调都调用 `IsAvailable`。进程冷启动时会创建、验证并释放完整临时 Toon 图；能力缓存直到完成后才标为已检查。读页因此具有节点初始化副作用，而且缺少重复进入保护。
- 基础参数编辑才进入 `SetDParameter → SyncToMaterial → RefreshMaterialMorphPreview`；没有证据表明单纯切页必然执行这条写路径。

## 修改与测试

状态和转换按钮改为 `AvailabilityForUi`，只读取能力缓存。未检查时显示将在导入或转换时检查；按钮保留操作入口，真实转换仍调用 `IsAvailable` 并在不支持时返回诊断。显式能力探测增加重复进入保护，不更改材质图配方 revision。

SDK 2026、2024、R20 Release 编译通过。SDK 2026 候选 SHA256：
`6964159ad4c06b62553184b937687765472caf3f73dadb79dcb7ea629a86b29f`。

`tests/material/native_material_page_test.py` 在新 c4dpy 进程先加载实际阿芙保存场景，未先调用导入或能力列表。原生读取冷缓存状态，依次选择 0、13、34、-1、0，读取动态描述和有效条目的 27 个参数。每次得到 390 个描述条目；状态保持“将在导入或转换时检查”，材质数保持 35。收据明确 `gui_tab_switch_verified=false`。

证据：`_build_msvc/validation/rs-toon-material/material-page-20261007-6964159a/`。

## 崩溃证据与限制

- Windows 转储 `C:\Users\happyelements\AppData\Local\CrashDumps\Cinema 4D.exe.75960.dmp`，文件时间 16:39:45，对应先前候选 GUI 进程。
- 异常 `0xc0000409`，记录位置为 `ucrtbase.dll + 0xa502e`。转储符号不完整，不能仅凭这个状态称为越界或认定插件根因。
- Rider 尝试 Release 和 Debug 正常启动后附加；会话创建成功，但源断点报告无关联可执行代码，暂停请求超时。转储会话也未进入可读栈的暂停状态。临时断点和会话均已清理，未修改用户异常断点。
- 使用 Rider 随带的 LLDB 批处理加载转储成功并保存全部线程栈。异常附近可见 C4D/运行库终止路径，另有 RS 插件工作线程；当前没有把 `mmdtool` 的具体源码行连接到原始故障。
- 本修改移除已经确认的属性回调副作用，是针对这条路径的防护；尚未证明它就是该次 GUI 退出的充分修复。仍需真实 GUI 切页和材质预览复验。

丝袜 Sphere/Toon/色彩对照已保存为独立实验；本轮未将其并入生产图，以免混淆崩溃检查和画面修改。
