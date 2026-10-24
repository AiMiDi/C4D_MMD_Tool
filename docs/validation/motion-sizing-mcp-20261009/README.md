# VMD 动作适配 MCP 合成验证（20261009）

结论：MCP 侧的 stdio sizing 发现链路通过，但**原生执行未发生**——当时的插件构建没有暴露 sizing 入口。
`native-preflight.json` 记为 `status=blocked`、`native_executed=false`、原因
`Loaded plugin does not expose sizing; load the new ordinary Release first.`。

因此该目录只作为「MCP 适配器可用、需换用暴露 sizing 的 Release 才能跑原生轮」的记录。
原始日志与 JSON 收据已移出版本库，归档在
`S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\docs-validation\motion-sizing-mcp-20261009\`。
