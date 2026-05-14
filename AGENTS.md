# Repository Guidance

## Scope

This file applies to the whole repository. Keep deeper workflow details in `DEVELOPMENT.md` / `DEVELOPMENT_zh.md` unless they are agent-specific.

## Project Structure

- `source/` is the active plugin source tree. `old/` is a legacy archive; do not modify it for normal work.
- `res/S24_up/` is the current plugin resource tree. Older SDK resource layouts may mirror or adapt these files.
- All `sdk_*` trees share the same maintained `source/` and `res/` content. `sdk_2026/` is the primary SDK project; `sdk_r20` through `sdk_2025` are compatibility SDK projects.
- Each `sdk_*/plugins/mmdtool/project/CMakeLists.txt` should stay a thin SDK wrapper over the common CMake layer in `cmake/`.
- `projectdefinition.txt` is reference metadata when a custom project `CMakeLists.txt` exists; do not treat it as the active build source.
- Main code areas:
  - `source/main.cpp`, `source/register_entity.cpp` for plugin startup and registration.
  - `source/CMTSceneManager.*` for PMX/VMD import orchestration.
  - `source/module/tools/object/` for C4D object manager plugins.
  - `source/module/tools/tag/mmd_bone.*` for MMD bone tags.
  - `source/module/tools/loader/vmd_loader.*` for VMD loading.
  - `source/module/tools/material/` for standard and renderer-specific material handling.
  - `source/module/ui/` for dialogs and UI flows.
  - `source/utils/` for header-only helpers.

## Build And Validation

- Prefer the root CMake workflow for normal Windows development:
  - `cmake --preset dev-windows`
  - `cmake --build --preset workflow-dev`
- To build the current SDK project directly, use the SDK preset and the root build directory:
  - `cmake --preset windows_vs2022_v143 -S sdk_2026 -B _build_msvc/sdk_2026`
  - `cmake --build _build_msvc/sdk_2026 --config Debug --target mmdtool`
- Use `cmake --build --preset workflow-configure-all-sdks` when you only need to configure all SDK trees.
- Dependency smoke tests require the dedicated preset:
  - `cmake --preset dev-windows-deps-test`
  - `cmake --build --preset cmt-deps-test`
- For VMD interpolation or camera interpolation changes, use the focused libMMD test before a full plugin run:
  - `cmake --build _build_msvc\cmt_deps\libMMD\tests --config Debug --target vmd_interpolation_test`
  - `ctest --test-dir _build_msvc\cmt_deps\libMMD\tests -C Debug -R vmd_interpolation_test --output-on-failure`
  `VMDCameraAnimation::Evaluate(float)` expects VMD frame numbers, not C4D seconds.
- Windows packaging is driven by Inno through the root preset:
  - `cmake --preset package-windows`
  - `cmake --build --preset inno-installer`
- CMake dependency integration lives in `cmake/mmdtool_plugin_dependencies.cmake`; shared plugin setup lives in `cmake/mmdtool_plugin_common.cmake`.
- To clean dependency build artifacts through root CMake, configure the repo root with `-B _build_msvc` and build `cmt-clean-deps`. Use `cmt-clean` only when a full generated-output wipe is intended.

## Include Conventions

- libMMD: `#include "libMMD/Model/MMD/..."`
- C4D descriptions: `#include "description/..."`
- C4D symbols: `#include <c4d_symbols.h>`
- Bullet is consumed through libMMD; plugin code should not include Bullet directly unless the dependency boundary changes intentionally.

## Runtime Resource Layout

- Windows plugin builds run `cmake/sync_runtime_resources.ps1` as a post-build step. It replaces the output `plugins/mmdtool/res` directory with a real copied resource tree and verifies `cmt_config.json`.
- If Cinema 4D fails to load the plugin or resources look stale, check the built output under `_build_msvc/<sdk>/bin/<Config>/plugins/mmdtool/res` before debugging runtime code.
- Do not recreate the old linked-resource output layout unless there is a specific reason; linked `res` trees have caused unreliable plugin startup.

## Cinema 4D LLDB-DAP Debugging

- Do not start Cinema 4D 2026 through LLDB/DAP direct launch. It can trigger Cinema 4D's startup library validation and show a false "The following libraries are broken" dialog before the plugin is involved.
- `g_console=true` is not required for debugging and is not the root cause of the false library-corruption dialog. Removing it, extra environment variables, and stdio suppression did not make direct LLDB launch reliable.
- Reliable live-debug startup sequence:
  1. Start Cinema 4D normally with the built plugin path, for example:
     `Cinema 4D.exe g_additionalModulePath=D:\code\C4D_MMD_Tool\_build_msvc\sdk_2026\bin\Debug\plugins`
  2. Wait for Cinema 4D to finish startup and for `mmdtool_Debug.xdl64` to load.
  3. Attach with CLI-Anything's `cli-anything-lldb-dap` to the running Cinema 4D process; do not use the old project harness or direct-launch wrapper.
  4. If attach reports an initial `stopped` event, immediately issue DAP `continue` so the C4D UI is usable again.
- Before relying on newly changed LLDB-DAP behavior, restart the DAP process and re-attach. Running DAP sessions do not hot-load Python adapter changes or new stop-filter settings.
- For C4D attach sessions, pass auto-continue behavior as DAP arguments instead of relying on generic LLDB defaults. Generic C4D/NVIDIA patterns must stay out of the CLI-Anything LLDB defaults because that tool is shared by other targets. Use this shape:
  ```json
  {
    "program": "D:\\Program Files\\Maxon Cinema 4D 2026\\Cinema 4D.exe",
    "pid": 65108,
    "autoContinueInternalBreakpoints": true,
    "autoContinueStopPatterns": [
      "nvgpucomp64.dll`destroyFinalizer",
      "jit-debug-register",
      "__jit_debug_register_code"
    ]
  }
  ```
- `autoContinueInternalBreakpoints=true` is only for generic trap stops such as `Exception 0x80000003` / `ntdll.dll\`DbgBreakPoint`. Target-specific module or symbol noise belongs in `autoContinueStopPatterns`, whose default should remain empty in the generic LLDB tool.
- DAP pause should use LLDB's async interrupt path (`SendAsyncInterrupt()`), and the next stop should be reported as `pause`; do not auto-continue explicit user pauses, even if the stopped stack matches an auto-continue pattern.
- If an explicit pause reports an NVIDIA `nvgpucomp64.dll` thread, do not treat that as the UI thread. On Windows, query the Cinema 4D main window thread with `GetWindowThreadProcessId` and request `stackTrace` for that thread id directly.
- Use DAP logs/state under `D:\TEMP\c4d_cli_anything_lldb_dap_*` for live-session evidence. The useful files are `*_state.json`, `*_transcript.jsonl`, `*_commands.jsonl`, `*_adapter.log`, and `*_controller.log`.
- If C4D-specific LLDB ergonomics need more behavior than `autoContinueStopPatterns`, propose a configurable CLI-Anything requirement first instead of hardcoding C4D/NVIDIA rules into the generic LLDB adapter.
- For source breakpoints in the plugin, prefer the SDK junction source path used by generated projects, for example:
  `D:\code\C4D_MMD_Tool\sdk_2026\plugins\mmdtool\source\...`
  Root `source\...` paths can remain pending because the PDB records the SDK project path.
- If a rebuild fails with `LNK1104` on `_build_msvc\sdk_2026\bin\Debug\plugins\mmdtool\mmdtool_Debug.xdl64`, a live Cinema 4D or LLDB session is probably still holding the plugin binary.

## Capturing Plugin Diagnostic Logs

- Plugin code uses `DebugOutput(maxon::OUTPUT::DIAGNOSTIC, ...)` and the `CMT_ANIM_FLOW_LOG` / `CMT_ANIM_FLOW_LOG_BONE` macros from `source/utils/cmt_anim_flow_debug.hpp`. These write to C4D's console, which is only visible when `g_console=true` is passed as a launch argument.
- Directly launching C4D via `Start-Process` does not capture console output. Use LLDB to launch C4D so that stdout/stderr (including `g_console=true` output) streams into the terminal and can be read back.
- The repo keeps a reusable LLDB command script at `_lldb_c4d_run.txt`. Launch with:
  ```
  lldb -s D:\code\C4D_MMD_Tool\_lldb_c4d_run.txt -- "D:\Program Files\Maxon Cinema 4D 2026\Cinema 4D.exe" 2>&1
  ```
- The script sets `g_additionalModulePath`, `g_console=true`, environment variables (`CMT_ANIM_FLOW_DEBUG`, `CMT_ANIM_FLOW_BONE`), auto-continue breakpoints for common debug traps, and runs the target.
- Use `block_until_ms: 0` when launching via the Shell tool so the LLDB+C4D session runs in the background. The terminal output file will contain all diagnostic logs after C4D exits.
- To filter IK-specific logs after a run: search the terminal output for `AnimFlow.*IK iter` to find per-frame IK solver stats, or `ExecOrder` for execution priority logs.
- Always kill any existing Cinema 4D process before launching via LLDB; the plugin DLL will be locked by a running instance and cause `LNK1104` on the next rebuild.

## Working Notes

- `rg.exe` can fail with `Access is denied` in some PowerShell sessions on this machine. Fall back to `Select-String`, `Get-ChildItem`, or `git grep` quickly.
- The worktree may contain unrelated local edits. Inspect `git status --short` before changing files and do not revert user changes unless explicitly asked.
