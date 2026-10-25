# 插件更新提醒

设置入口：C4D **编辑 → 首选项 → MMD Tools → 更新**。

- **自动检查更新**默认开启，每 24 小时最多请求一次 GitHub 最新正式版；网络失败也计入间隔，避免重复请求。关闭后停止后续自动检查和自动弹窗，仍可手动检查。
- 启动只在后台检查。打开 MMD Tools、打开动作适配，或执行插件导入导出时，有更新才弹出说明；工具面板不占用更新提示区域。
- 弹窗按 C4D 当前资源语言选择发布说明中的 `## 中文` 或 `## English` 段落。语言段落缺失时显示本语言的发布页引导；旧的单语言说明保留原文。窗口可以滚动、调整尺寸，内容只读。
- **查看更新**打开该版本的 GitHub 发布页，由用户下载安装；**稍后**在本次 C4D 会话中不再提醒该版本；**忽略此版本**跨重启屏蔽该版本，后续新版本仍会提醒。
- **检查更新**在首选项中手动请求，绕过自动检查间隔和忽略设置；未发现更新或请求失败时可以查看设置里的版本状态。

## 实现边界

`CMTUpdateManager` 在主线程读取/写入 C4D 用户偏好，单个 worker 使用 SDK HTTPS 输入流取得版本和说明。请求连接与会话超时分别为 5 秒，读取总期限为 15 秒，响应不超过 1 MiB，JSON 嵌套不超过 32 层；保留默认 TLS 证书校验。主线程消息插件每秒收取结果，仅在发生功能使用后展示弹窗。卸载先关闭弹窗，再取消并等待 worker，最后保存尚未收取的结果。

偏好在现有工具命令 ID 1056563 的 WorldPluginData 中，字段从 2000000 起，合并保存，不覆盖其他字段。首选项和消息插件复用项目此前未注册的预留 ID 1056725 和 1056721。

`res/cmt_version.txt` 为安装版本。开发资源目前与发布日志的 0.9.3.11 一致；以后更新开发版本时需要同时维护两个资源树中的此文件。缺失或无效时显示版本未知并禁用“新于当前版本”的判定。

发布包在打包时重新写入最终版本：Windows CI 在 ISCC 前覆盖八个 SDK 的资源版本，macOS ZIP 在压缩前覆盖；本地 root CMake 打包使用 `/DPluginVersion=` 参数，默认与安装器的 `0.0.0.0` 一致。该标记独立于二进制，兼容复用历史构建。`cmake/stamp_package_version.cmake` 验证版本和资源路径后写入；不支持预发布字符串。

## 聚焦验证

```powershell
cmake -S tests -B S:\tmp\cmt-update-tests-v18 -G 'Visual Studio 18 2026' -A x64
cmake --build S:\tmp\cmt-update-tests-v18 --config Debug --target update_policy_test
ctest --test-dir S:\tmp\cmt-update-tests-v18 -C Debug -R update_policy_test --output-on-failure
```

测试覆盖三/四段数字版本、数字溢出、忽略版本、手动检查、检查节流、时钟回拨、嵌套 JSON、转义中文、非法/重复字段、预发布、限流响应、中英文说明分段和中文折行。Windows C4D 2026.4.0 已完成中英文设置、弹窗、关闭/忽略跨重启保留、稍后和发布页跳转的原生验证，见 [验收证据](https://github.com/AiMiDi/C4D_MMD_Tool/blob/32753932d529ce82677538d109d0709fec8be520/docs/validation/plugin-update-reminder/20261014/README.md)。SDK 编译通过不代表其他宿主或 macOS 已完成原生验收。

接口依据：[GitHub Releases REST API](https://docs.github.com/en/rest/releases/releases)、[C4D 首选项插件接口](https://developers.maxon.net/docs/cpp/2025_2_0/classcinema_1_1_prefs_dialog_object.html)。
