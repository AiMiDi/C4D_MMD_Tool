# Native verification pending reload

Build: `_build_msvc/vmd-sizing-ui-sync-sdk/bin/Release/plugins/mmdtool/mmdtool.xdl64`.
This checklist is not a passing receipt. The running pre-fix binary cannot validate these scenarios.

- Start via production MCP with the panel closed; open it and inspect source PMX, file/slot selection, target and non-default numeric/boolean options.
- Start with the panel already open; confirm input reflection does not enqueue a duplicate job or auto-open a second preview.
- Use two members with different effective options; switch members and inspect each set, including a stable slot input on one member.
- Preview through MCP with an explicit member, stage and overlay; confirm the controls and displayed result refer to that same job.
- Poll from MCP while the panel is open; confirm completion appears even when MCP consumed the HostSession Poll transition first.
- Close and reopen the panel; verify the MCP job remains valid and is not cancelled or released.
- Edit one member through the UI; verify a separate calculation preserves other members and hidden settings without changing the original MCP job.
- Release the observed job; confirm result controls disable and only its owned preview closes.
- Rerun the production native runner and record original-document restoration and owned-document cleanup independently from retained demo documents.
