# 插件更新提醒原生验收

2026-10-14，Windows Cinema 4D 2026.4.0。设置和中英文更新弹窗已通过原生验证。

测试使用 `S:\tmp\cmt-update-native-20261014\artifact-accepted` 的插件副本以及独立中英文偏好目录。只把副本的 `res/cmt_version.txt` 设为 `0.9.3.0`，以真实 GitHub 最新正式版 `v0.9.3.8` 验证提示；仓库资源保持 `0.9.3.8`。

最终二进制 SHA-256：`A955AE0B789338E56ED3E37F917E21BED765CB61D8562BE5DBE7387B35DAFC22`，见 [哈希记录](accepted-artifact-hash.json)。

原生测试的共享工作区同时包含既有的独立动作适配命令改动。本次更新提醒提交保留 `main` 原有的动作适配菜单入口，并在该入口调用相同的 `OnToolUse()`；独立命令重构未纳入本提交。入库日志仅去除了行尾空白，原始文件保留在上述临时目录。

## 界面与交互

| 验证项 | 原生观察与证据 |
| --- | --- |
| 中文设置 | PID 55564，首选项插件 1056725，版本号完整显示；[设置截图](settings-zh.png)、[原生回执](zh-final-settings-receipt.json) |
| 中文弹窗 | PID 55564，工具命令 1056563 触发；中文说明完整折行，查看更新／稍后／忽略此版本均为中文；[弹窗截图](popup-zh.png) |
| 英文设置及弹窗 | PID 81228，按英文资源显示说明及按钮，排除中文和构建元数据；[设置截图](settings-en.png)、[弹窗截图](popup-en.png) |
| 后台检查 | 启动无弹窗；SDK HTTPS 请求得到最新版本和 4716 字节说明；[联网回执](en-live-update-receipt.json) |
| 自动检查关闭 | 关闭后使用工具不弹窗，手动检查仍能提示；[关闭回执](disabled-setting-receipt.json) |
| 关闭设置跨重启保留 | PID 91268 关闭，正常退出后 PID 81228 仍为 false；[关闭前回执](en-disabled-receipt.json)、[重启回执](en-disabled-restart-receipt.json) |
| 稍后 | PID 40408 点击稍后后重新打开工具，同版本不重复提醒；[回执](later-suppressed-receipt.json)（不弹窗由界面观察确认） |
| 忽略此版本跨重启保留 | PID 81228 忽略后，PID 92464 仍保留 `v0.9.3.8`，自动检查开启且使用工具无弹窗；[忽略回执](en-ignored-receipt.json)、[重启回执](en-ignored-restart-receipt.json)、[使用回执](en-ignored-use-receipt.json) |
| 查看更新 | 中文弹窗按钮打开对应 GitHub 发布页，浏览器标题和可见版本一致；[浏览器回执](view-release-receipt.json) |
| 正常退出 | PID 55564 经 C4D Quit 正常退出；[退出前回执](final-shutdown-receipt.json)、[外部进程确认](external-exit-receipt.json) |

回执记录主线程读取的插件偏好和注册状态；界面是否出现、语言和文本布局通过加载后截图及现场观察确认。回执中的 `preference_command: null` 和空的命令 12200 是早期探测字段；实际设置入口使用 `c4d.PrefsLib_OpenDialog(1056725)`。

## 编译与修复

SDK 2026 和 R20 Debug 编译通过，最终资源同步通过。保留 [2026 编译日志](cmt-update-accepted-build.log)、[R20 编译日志](cmt-update-accepted-build-r20.log)、[2026 资源同步日志](cmt-update-final-resource-build.log)、[R20 资源同步日志](cmt-update-final-resource-build-r20.log)。独立更新策略测试通过，包含版本比较、节流、忽略、手动检查、严格 JSON、语言分段和中文折行；另使用完整真实发布响应验证解析。

原生测试发现并修复：全局静态 GeDialog 导致 DLL 初始化失败；全局字符串与局部资源表不匹配导致 `StrNotFound` 和错误英文回退；长中文段落未折行；设置里的长标签挤压版本状态。

[native-probe.py](native-probe.py) 为本次测试的临时 Python 消息插件，只支持读取、打开设置、调用工具命令和正常退出。它仅处置名为 `MMD-Update-Validation.c4d` 的测试文档，不属于发布插件。最终启动日志：[中文](startup-complete-zh.log)、[英文](startup-accepted-en.log)、[英文忽略后重启](startup-ignored-en.log)。

本次原生验收范围为 Windows C4D 2026.4.0。R20 仅编译验证，macOS 未进行原生测试。
