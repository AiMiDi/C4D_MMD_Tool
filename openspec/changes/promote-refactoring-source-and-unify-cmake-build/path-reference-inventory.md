# Path Reference Inventory

## Scope

Inventory target patterns:

- `refactoring/`
- `source/`
- `res/S24_up`
- `dependency/install`

Scanned locations:

- `sdk_2025/plugins/mmdtool/project`
- `sdk_2026/plugins/mmdtool/project`
- `DEVELOPMENT.md`（英文开发文档）
- `DEVELOPMENT_zh.md`（中文开发文档）
- `init.bat`

## Findings

### `sdk_2026/plugins/mmdtool/project/CMakeLists.txt`

- `DEPENDENCY_INSTALL_DIR` -> `${PROJECT_ROOT_DIR}/dependency/install`
- Resource root -> `${PROJECT_ROOT_DIR}/res/S24_up`
- Canonical source root is now wired via shared module (`${PROJECT_ROOT_DIR}/source`)

### `sdk_2025/plugins/mmdtool/project/CMakeLists.txt`

- `DEPENDENCY_INSTALL_DIR` -> `${PROJECT_ROOT_DIR}/dependency/install`
- Resource root -> `${PROJECT_ROOT_DIR}/res/S24_up`
- Canonical source root is now wired via shared module (`${PROJECT_ROOT_DIR}/source`)

### `DEVELOPMENT.md` / `DEVELOPMENT_zh.md`

- Build/install outputs documented under `dependency/install`
- Active source directory documented as `source/`
- Resource mapping documented as `res/S24_up`

### `init.bat`

- No hardcoded `refactoring/`/`source/`/`res/S24_up`/`dependency/install` path literals remain
- Script now forwards to `dependency/CMakeLists.txt` workflow

## Notes

- `openspec/` files still contain historical `refactoring/` references by design to track migration context.
- Legacy SDK `*.vcxproj` references are intentionally not rewritten in this step; they are migration baselines for later tasks.
