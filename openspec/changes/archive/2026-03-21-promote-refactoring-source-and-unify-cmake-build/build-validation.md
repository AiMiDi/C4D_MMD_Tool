# Build Validation Log

## 2026 plugin configure

Command:

`cmake --preset windows_vs2022_v143` (in `sdk_2026`)

Result:

- Configure succeeded
- Junction target:
  - `sdk_2026/plugins/mmdtool/source` -> `source/`
  - `sdk_2026/plugins/mmdtool/res` -> `res/S24_up`

## 2025 plugin configure

Command:

`cmake -S . -B _build_v143_verify -G "Visual Studio 17 2022" -T v143` (in `sdk_2025`)

Result:

- Configure succeeded in isolated verify build dir
- Junction target:
  - `sdk_2025/plugins/mmdtool/source` -> `source/`
  - `sdk_2025/plugins/mmdtool/res` -> `res/S24_up`

## 2024 plugin configure (new bridge)

Command:

`cmake -S . -B _build_v143_bridge -G "Visual Studio 17 2022" -T v143` (in `sdk_2024`)

Result:

- Configure succeeded with bridge root `sdk_2024/CMakeLists.txt`
- Plugin CMake loaded from `sdk_2024/plugins/mmdtool/project/CMakeLists.txt`
- Junction target:
  - `sdk_2024/plugins/mmdtool/source` -> `source/`
  - resource mapping to `res/S24_up` configured in plugin CMake

## Dependency workflow configure

Command:

`cmake -S dependency -B _build_workflow_verify -G "Visual Studio 17 2022" -T v143 -D CMT_DEPS_BUILD_DEBUG=ON -D CMT_DEPS_BUILD_RELEASE=OFF -D CMT_DEPS_ENABLE_LIBMMD_TESTS=OFF`

Result:

- Configure succeeded

Follow-up command:

`cmake --build _build_workflow_verify --target cmt-deps-configure-bullet3`

Result:

- `cmt-deps-configure-bullet3` target succeeded
- Bullet3 sub-configure completed and generated build files

## Cross-SDK plugin build attempt (task 4.3 evidence)

Commands:

- `cmake --build _build_v143 --config Debug --target mmdtool` (in `sdk_2026`)
- `cmake --build _build_v143_verify --config Debug --target mmdtool` (in `sdk_2025`)
- `cmake --build _build_v143_bridge --config Debug --target mmdtool` (in `sdk_2024`)

Result:

- All three builds currently fail in this workspace snapshot.
- 2026 / 2025 fail at compile stage with missing `c4d.h`.
- 2024 first hit sourceprocessor arg compatibility (`--quiet`), then after compatibility patch fails with missing generated framework header `system1.hxx`.
- These failures indicate framework/header generation chain is not yet in a fully healthy baseline state, so task 4.3 remains pending.

## Baseline deep-dive (option 3: start from 2026)

Actions:

1. Re-ran 2026 configure/build repeatedly while isolating missing-header chain.
2. Confirmed `c4d.h` exists in SDK source tree and injected framework source include roots in common plugin module.
3. Built `core.framework` subproject directly to force sourceprocessor output generation.

Observed error progression:

- Stage A: `c4d.h` not found (plugin compile include root issue).
- Stage B: after include-root patch, `system1.hxx` not found (generated framework header chain issue).
- Stage C: after generated include expansion, `c4d_graphview_enum.h` not found (nested framework include dir issue).
- Stage D: after nested include expansion, compile proceeds deeper but fails inside `core.framework` headers (`entity.h`, `private_atomic_core.h`) with template/macro-level cascade errors.

Current conclusion:

- The 2026 baseline in this workspace is still not in a "default documented workflow can compile plugin" state.
- Task 4.3 remains blocked and requires dedicated framework/header-generation compatibility cleanup before it can be marked complete.

## Baseline re-validation (2026 tooling-first)

Actions:

1. Switched 2024 bridge to use `sdk_2026/cmake` directly.
2. Kept shared plugin CMake module focused on plugin/dependency configuration (removed temporary broad include-dir probing).
3. Applied compatibility patch in `sdk_2026/cmake/sdk_targets.cmake` to drop `--quiet` for older sourceprocessor compatibility.

Results:

- `sdk_2026`:
  - `cmake --preset windows_vs2022_v143` passed.
  - `cmake --build _build_v143 --config Debug --target mmdtool` passed.
- `sdk_2025`:
  - `cmake -S . -B _build_v143_verify -G "Visual Studio 17 2022" -T v143` passed.
  - `cmake --build _build_v143_verify --config Debug --target mmdtool` passed.
- `sdk_2024`:
  - Configure passed with 2026 tooling bridge.
  - Build still fails in `core.framework` (`datatypelib.h` overload/template resolution errors), even after trying C++17 baseline.

Conclusion update:

- 2026 baseline is now healthy, and 2025 is also healthy in this workspace.
- 2024 remains the only blocker for task 4.3.

## 2024 compatibility tool attempt (based on 2026 CMake tooling)

Implementation:

- Added local compatibility tooling under `sdk_2024/cmake`:
  - `sdk_compiler_helper.cmake` (wrapper to 2026 helper)
  - `sdk_targets.cmake` (wrapper to 2026 targets logic)
  - `sdk_update_projects.cmake` (wrapper to 2026 update logic)
  - `sdk_library_template.cmake` (2026 template-compatible local copy for token substitution)
  - `commands/update_filelist.cmake` and `commands/create_directory_symlink.cmake` wrappers
  - `sdk_compat_2024.cmake` for 2024 baseline compatibility switches
- Updated `sdk_2024/CMakeLists.txt` to use local `sdk_2024/cmake` compatibility tooling.

Validation:

- `cmake -S . -B _build_v143_bridge -G "Visual Studio 17 2022" -T v143` passed.
- `cmake --build _build_v143_bridge --config Debug --target mmdtool` still fails.

Current failure class:

- No longer path/tool bootstrapping failures.
- Fails in `frameworks/core.framework/source/maxon/datatypelib.h` with operator/template overload resolution errors (e.g. `C7692`), indicating deeper 2024 framework/toolchain semantic compatibility gaps remain.

## 2024/2025/2026 default workflow re-validation (passed)

Commands:

- `cmake -S . -B _build_v143_bridge -G "Visual Studio 17 2022" -T v143 && cmake --build _build_v143_bridge --config Debug --target mmdtool` (in `sdk_2024`, executed with PowerShell-safe sequential chaining)
- `cmake -S . -B _build_v143_verify -G "Visual Studio 17 2022" -T v143 && cmake --build _build_v143_verify --config Debug --target mmdtool` (in `sdk_2025`)
- `cmake -S . -B _build_v143 -G "Visual Studio 17 2022" -T v143 && cmake --build _build_v143 --config Debug --target mmdtool` (in `sdk_2026`)

Result:

- All three SDKs now configure and build `mmdtool` successfully in Debug.
- `sdk_2024` no longer blocks in `nodes.framework`; sourceprocessor generator compatibility patch resolved the previous `decltype` nested-name error class.
- Task 4.3 is now satisfied in current workspace snapshot.

## 2023 minimal bridge bring-up (in progress)

Implementation:

- Added bridge entry files:
  - `sdk_2023/CMakeLists.txt`
  - `sdk_2023/CMakePresets.json`
  - `sdk_2023/cmake/sdk_compat_2023.cmake`
  - `sdk_2023/plugins/mmdtool/project/CMakeLists.txt`
- Patched `sdk_2023/frameworks/settings/sourceprocessor/generators/cppgenerator.py` with the same alias-based `decltype` compatibility fix used for 2024.
- Extended shared plugin module to allow per-SDK `FRAMEWORK_DEPENDENCIES` override.

Validation:

- `cmake -S . -B _build_v143 -G "Visual Studio 17 2022" -T v143` (in `sdk_2023`) passed.
- `cmake --build _build_v143 --config Debug --target mmdtool` failed in plugin business code/API compatibility layer (not CMake bootstrapping), e.g.:
  - const-correctness/API signature mismatches in `io_util.hpp` / `mmd_model_manager.cpp`
  - missing/renamed members in `MMDModelManagerObject`

Conclusion:

- 2023 bridge scaffolding is operational, but source compatibility adaptation is still required before build can pass.

## S26 minimal bridge bring-up (in progress)

Implementation:

- Added bridge entry files:
  - `sdk_s26/CMakeLists.txt`
  - `sdk_s26/CMakePresets.json`
  - `sdk_s26/cmake/sdk_compat_s26.cmake`
  - `sdk_s26/plugins/mmdtool/project/CMakeLists.txt`
- Patched `sdk_s26/frameworks/settings/sourceprocessor/generators/cppgenerator.py` with alias-based `decltype` compatibility fix.

Validation:

- `cmake -S . -B _build_v143 -G "Visual Studio 17 2022" -T v143` (in `sdk_s26`) passed.
- `cmake --build _build_v143 --config Debug --target mmdtool` failed in plugin business/source compatibility, e.g.:
  - unresolved description IDs and missing description headers
  - const/API signature differences in legacy Cinema API usage
  - plugin source-level incompatibilities in dialogs/manager modules

Conclusion:

- S26 bridge bootstrapping is functional; remaining blockers are source compatibility and resource/header mapping details.
