# MCP 端口 5557 丢失后的恢复步骤

## 症状

- `launch-host.ps1 -Execute` 报 `host_ready_timeout: 240s（端口 5557 未由 pid ... 监听）`，`launch-failure.json` 里 `reason=host_ready_timeout`。
- 进程其实起来了（`Cinema 4D首页` 与主窗口都在），但 `Get-NetTCPConnection -State Listen` 里只有两个**动态端口**（如 58214/58216、52657/52660），**5556 与 5557 都没有**。
- `<prefsPath>\prefs\mcp\audit.log` 仍然有 `STARTUP mcp_adapter 1.0.0.26` 与 `DRAIN_TICK`，`token` 也在 —— 适配器加载了，只是没绑定端口。
- 全新空 profile 启动同样只有动态端口 ⇒ **适配器的出厂默认是不监听**，不是本 profile 独有故障。

## 根因

收尾时用 `Stop-Process -Force` 强杀 Cinema 4D，`prefs\Cinema 4D.prf` 没写完就被打断，MCP 适配器的世界插件偏好（`PLUGIN_ID_PREFERENCES = 1070225`，键 1001 ENABLED / 1003 HOST / 1004 PORT / 1006 TIMEOUT）随之回到默认（关闭），首页窗口也按出厂默认重新出现。

首选项只存在于 `prefs\Cinema 4D.prf` 里，且值不是裸 int32（不能靠改字节注入）；唯一的写入通道是宿主自己的偏好容器 API：

```python
c4d.plugins.SetWorldPluginData(1070225, bc)
c4d.SaveWorldPreferences()
```

## 恢复步骤（不需要点桌面）

1. 用**任意一个还能连上 MCP 的 profile**（默认 5556，或用户默认 profile 的 prf 只读副本）当跳板。把用户默认 profile 的 `prefs\Cinema 4D.prf` 与 `prefs\mcp\` 只读复制到隔离目录，例如
   `S:\tmp\cmt_vmd_profile_20261019\probe_profile\prefs\`，用 `g_prefsPath` 指向 `...\probe_profile` 启动；此时适配器按用户偏好监听 **5556**。
2. 借 5556 写入目标端口：

   ```powershell
   pwsh -NoProfile -File docs\validation\vmd-host-restore-20261024\configure-mcp-prefs.ps1 `
       -EndpointPort 5556 -TargetPort 5557 `
       -TokenPath 'S:\tmp\cmt_vmd_profile_20261019\probe_profile\prefs\mcp\token' -Execute
   ```

   正常输出含 `PREF_AFTER {1001: 1, ..., 1004: 5557}` 与 `PREF_RESOLVED_PORT 5557`。
3. **干净退出**探测宿主（`CloseMainWindow()` + 等待，不要 `Stop-Process`），让 prf 落盘：文件大小会变（本次 620,021 → 620,854 B）。
4. 把写好的 `Cinema 4D.prf` 复制回私有 profile：
   `Copy-Item ...\probe_profile\prefs\Cinema 4D.prf ...\host_profile\prefs\Cinema 4D.prf -Force`
   （`host_profile\prefs\mcp\token` 保持不动，harness 用的是它。）
5. 用 `host_profile` 启动复验：本次 12 s 就绪并监听 5557。

## 教训

- **收尾一律先 `CloseMainWindow()`**，只有超时才 `Stop-Process`；强杀之后必须假定偏好可能已被重置。
- 计时/语义跑完后 `host_clean` 只检查「C4D=0 且端口无监听」，**不检查偏好是否完好**；出问题后的第一现场取证点是 `audit.log` 有没有 `STARTUP`、以及 5556/5557 是否在 `Get-NetTCPConnection` 里。
- `MMDPhysics`/产品代码与此无关，不要往插件方向查。
