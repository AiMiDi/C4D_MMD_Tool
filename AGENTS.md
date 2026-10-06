# Repository Guidance

## Scope

This file applies to the whole repository. Keep deeper workflow details in `DEVELOPMENT.md` / `DEVELOPMENT_zh.md` unless they are agent-specific.

## Project Structure

- `source/` is the active plugin source tree. `old/` is a legacy archive; do not modify it for normal work.
- `res/S24_up/` is the current plugin resource tree. Older SDK resource layouts may mirror or adapt these files.
- `docs/dev/import-flow.md`, `docs/dev/runtime-flow.md`, and `docs/dev/anim-flow-debug.md` are the current deep dives for PMX/VMD import, runtime execution, and animation/IK/physics diagnostics.
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
  - `source/utils/` for shared helpers; most are header-only, but runtime utilities can have `.cpp` implementations.

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
  - `cmake --build --preset cmt-plugin-tests`
  Functional CTest excludes benchmark/performance labels. Run benchmarks explicitly with `cmake --build --preset cmt-deps-benchmark`. `CMT_DEPS_TEST_CONFIG` must match the build configuration (Debug by default).
- Release plugin builds require the Release configure preset: `cmake --preset release-windows` followed by `cmake --build --preset workflow-release` (macOS: `release-macos` / `workflow-release-macos`). A build preset does not change an existing cache's `CMT_SDK_BUILD_CONFIG`.
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
- The shared layer also synchronizes resources through `mmdtool-runtime-resources` before every plugin build, including resource-only changes. macOS uses `cmake/sync_runtime_resources.cmake`; artifacts contain real resource copies on both platforms.
- `CMT_RUNTIME_RESOURCE_CONFIG_POLICY=reset` is the reproducible default. `preserve` keeps valid preferences from an existing real output directory. Old SDK resources without `cmt_config.json` receive the default from `res/S24_up`; a stale output junction is removed without following its source target.
- Run `pwsh -NoProfile -File scripts/check_runtime_resources.ps1` for focused copy, config, and junction-safety fixtures. Temporary evidence is written below `S:\tmp`.
- If Cinema 4D fails to load the plugin or resources look stale, check the built output under `_build_msvc/<sdk>/bin/<Config>/plugins/mmdtool/res` before debugging runtime code.
- Do not recreate the old linked-resource output layout unless there is a specific reason; linked `res` trees have caused unreliable plugin startup.

## Cinema 4D LLDB-DAP Debugging

- Do not start Cinema 4D 2026 through LLDB/DAP direct launch. It can trigger Cinema 4D's startup library validation and show a false "The following libraries are broken" dialog before the plugin is involved.
- `g_console=true` is not required for debugging and is not the root cause of the false library-corruption dialog. Removing it, extra environment variables, and stdio suppression did not make direct LLDB launch reliable.
- Reliable live-debug startup sequence:
  1. Start Cinema 4D normally with the built plugin path, for example:
     `Cinema 4D.exe g_additionalModulePath=C:\code\C4D_MMD_Tool\_build_msvc\sdk_2026\bin\Debug\plugins`
  2. Wait for Cinema 4D to finish startup and for `mmdtool_Debug.xdl64` to load.
  3. Attach with CLI-Anything's `cli-anything-lldb-dap` to the running Cinema 4D process; do not use the old project harness or direct-launch wrapper.
  4. If attach reports an initial `stopped` event, immediately issue DAP `continue` so the C4D UI is usable again.
- Before relying on newly changed LLDB-DAP behavior, restart the DAP process and re-attach. Running DAP sessions do not hot-load Python adapter changes or new stop-filter settings.
- For C4D attach sessions, pass auto-continue behavior as DAP arguments instead of relying on generic LLDB defaults. Generic C4D/NVIDIA patterns must stay out of the CLI-Anything LLDB defaults because that tool is shared by other targets. Use this shape:
  ```json
  {
    "program": "C:\\Program Files\\Maxon Cinema 4D 2026\\Cinema 4D.exe",
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
- Keep task-owned DAP logs/state below `S:\tmp\c4d_cli_anything_lldb_dap_*`. The useful files are `*_state.json`, `*_transcript.jsonl`, `*_commands.jsonl`, `*_adapter.log`, and `*_controller.log`; inspect the actual session output to locate them.
- If C4D-specific LLDB ergonomics need more behavior than `autoContinueStopPatterns`, propose a configurable CLI-Anything requirement first instead of hardcoding C4D/NVIDIA rules into the generic LLDB adapter.
- For source breakpoints in the plugin, prefer the SDK junction source path used by generated projects, for example:
  `C:\code\C4D_MMD_Tool\sdk_2026\plugins\mmdtool\source\...`
  Root `source\...` paths can remain pending because the PDB records the SDK project path.
- If a rebuild fails with `LNK1104` on `_build_msvc\sdk_2026\bin\Debug\plugins\mmdtool\mmdtool_Debug.xdl64`, a live Cinema 4D or LLDB session is probably still holding the plugin binary.

## Capturing Plugin Diagnostic Logs

- Plugin code uses `DebugOutput(maxon::OUTPUT::DIAGNOSTIC, ...)` and the `CMT_ANIM_FLOW_LOG` / `CMT_ANIM_FLOW_LOG_BONE` macros from `source/utils/cmt_anim_flow_debug.hpp`. These write to C4D's console, which is only visible when `g_console=true` is passed as a launch argument.
- Use `docs/dev/anim-flow-debug.md` as the reference for animation/IK/physics diagnostics. It documents `CMT_ANIM_FLOW_DEBUG`, `CMT_ANIM_FLOW_BONE`, `CMT_INITIAL_STATE_DEBUG`, and the expected `[CMT][AnimFlow]` log fields.
- Launch Cinema 4D normally with `g_console=true` and diagnostic environment variables set, then attach as described above. `Start-Process` alone does not capture the C4D console; save or copy the console output into a task-owned log below `S:\tmp` and record the build and scene used.
- `_lldb_c4d_run.txt` is not a maintained repository entry point. Do not use direct LLDB/DAP launch as a workaround for console capture.
- To filter IK-specific logs after a run: search the terminal output for `AnimFlow.*IK iter` to find per-frame IK solver stats, or `ExecOrder` for execution priority logs.
- Inspect running Cinema 4D sessions before rebuilding. Preserve user-owned sessions; close only a task-owned test session after its evidence has been saved. A process holding the plugin DLL can cause `LNK1104` on the next rebuild.

## Working Notes

- For import/runtime questions, start from `docs/dev/import-flow.md` or `docs/dev/runtime-flow.md` before broad code searches. For EDIT/ANIM mode regressions, `MODEL_MODE` changes are explicit state boundaries: EDIT -> ANIM commits bind state, and ANIM -> EDIT restores bind state for editing.
- `rg.exe` can fail with `Access is denied` in some PowerShell sessions on this machine. Fall back to `Select-String`, `Get-ChildItem`, or `git grep` quickly.
- If Git reports dubious ownership under the Codex sandbox user, use per-command inspection such as `git -c safe.directory=D:/code/C4D_MMD_Tool status --short`; do not change global Git config unless the user asks.
- The worktree may contain unrelated local edits. Inspect `git status --short` before changing files and do not revert user changes unless explicitly asked.
