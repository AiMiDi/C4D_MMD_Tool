## 1. Runtime integration

- [x] 1.1 Add evaluation-local native PSR input discovery and phased evaluation; verify enabled/disabled targets and priority bounds.
- [x] 1.2 Feed driven channels to append/IK/physics without changing bind state; verify goal motion and partial-channel constraints.
- [x] 1.3 Clear transient input on lifecycle changes and restore ordinary animation when constraints disappear; verify same-frame repeat and reload.

## 2. Native validation and documentation

- [x] 2.1 Add repeatable native PSR regression coverage and build the SDK 2026 plugin.
- [x] 2.2 Run MCP regressions on the supplied Afu PMX/VMD and saved reproduction, recording the loaded binary and numerical results.
- [x] 2.3 Document the supported constraint workflow and execution limits; validate OpenSpec and inspect the final diff.

验证回执：`output/psr-fix-20261008/receipt.json`。SDK 2026 / R20 Release 编译通过；
C4D 2026.4 已加载最终二进制 ED2F4DF276AB807D69B68109944CFDE016A86B0FD6F89DE0B39C7DD1C691EFB1。
阿芙 PMX 90 项、阿芙 PMX+VMD 90 项、可再分发小模型 62 项检查通过；补充蒙皮缓存和直接 FK 旋转检查通过。
原始关键帧复现场景直接重开后，控制器位移 10/20 时，脚踝分别响应约 9.90/19.36。
以上为早期修复回执；R20 仅编译验证，未进行 R20 现场测试。

最终与控制器改进合并交付 Windows 0.9.2.3 本地安装包，8 个 SDK 编译通过，最终模块上 PMX / PMX+VMD PSR 各 90 项重新通过。参见 `docs/dev/controllers-acceptance-20261008.md`；没有发布远端版本。
