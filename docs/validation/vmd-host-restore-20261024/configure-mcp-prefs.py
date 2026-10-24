# 在 Cinema 4D 进程内执行（经 MCP exec_python 注入）：把 MCP 适配器的偏好写进
# 世界插件偏好容器并立刻落盘，使下次启动监听 __PORT__ 而不是适配器内置默认 5556。
#
# 由 configure-mcp-prefs.ps1 读取本文件、把占位符 __PORT__ 替换为目标端口后发送；
# 单独执行本文件没有意义（__PORT__ 未替换会 NameError，属于有意的显式失败）。
#
# 参数 ID 与 GUI「偏好设置 → MCP」页一致（见 mcp_adapter/ui/preferences.py）：
#   1001 ENABLED / 1002 ALLOW_REMOTE / 1003 HOST / 1004 PORT / 1006 REQUEST_TIMEOUT
#   1011 ENABLE_EXEC_PYTHON / 1012 ENABLE_PYTHON_OPS / 1031 ENABLE_LOGGING
import traceback

try:
    import c4d
    from mcp_adapter.ui import preferences as P
    from mcp_adapter.config.settings import load_adapter_config

    target_port = __PORT__
    plugin_id = P.PLUGIN_ID_PREFERENCES

    container = c4d.plugins.GetWorldPluginData(plugin_id)
    if container is None:
        container = P._get_or_create_preference_container()
    before = {k: (container[k] if container.GetType(k) != c4d.DA_NIL else "unset") for k in (1001, 1003, 1004, 1006, 1011, 1012)}
    print("PREF_BEFORE", before, flush=True)

    container[1001] = True      # ENABLED
    container[1002] = False     # ALLOW_REMOTE（保持仅本机）
    container[1003] = "127.0.0.1"
    container[1004] = target_port
    container[1006] = 60        # REQUEST_TIMEOUT 秒
    container[1011] = True      # ENABLE_EXEC_PYTHON
    container[1012] = True      # ENABLE_PYTHON_OPS

    print("PREF_SET", c4d.plugins.SetWorldPluginData(plugin_id, container), flush=True)
    c4d.SaveWorldPreferences()
    print("PREF_SAVED", True, flush=True)

    reread = c4d.plugins.GetWorldPluginData(plugin_id)
    print("PREF_AFTER", {k: reread[k] for k in (1001, 1003, 1004, 1006, 1011, 1012) if reread.GetType(k) != c4d.DA_NIL}, flush=True)
    print("PREF_RESOLVED_PORT", load_adapter_config().port, flush=True)
    print("PREF_NOTE 端口改动需重启 Cinema 4D 才生效（适配器在启动时绑定）", flush=True)
except Exception:
    traceback.print_exc()
    raise
