# Cinema 4D 2027 SDK

The vendor `frameworks/`, `cmake/`, `tools/`, and root `CMakeLists.txt` were
extracted from the `sdk.zip` distributed with the local Cinema 4D 2027
installation on 2026-10-19.

- SDK archive SHA-256: `A3704A7C7D87D1EA000615AC63EFBB28A033EA69F0D51FA4F72F82CE39073DAF`
- Cinema API version: `2027000` (`frameworks/cinema.framework/source/operatingsystem.h`)
- Minimum CMake: 3.30; C++ standard: 20.

Example plugins are omitted. The `plugins/mmdtool/project/CMakeLists.txt`
wrapper and `CMakePresets.json` belong to this repository. Framework code and
SDK build tools retain their original Maxon notices.

The 2027 Source Processor reads `target_settings` literally from the plugin
wrapper. Keep its bracket-quoted JSON descriptor there; shared build settings
live in `../cmake/mmdtool_plugin_common.cmake`.

See `../DEVELOPMENT.md` or `../DEVELOPMENT_zh.md` for build commands and host
validation boundaries. Building this SDK does not launch Cinema 4D.
