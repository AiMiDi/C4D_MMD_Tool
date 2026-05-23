# =============================================================================
# C4D_MMD_Tool — Repository root workflow (dependencies + selected SDK plugin + optional installer)
# =============================================================================
# Typical usage (from repository root):
#   Recommended: CMake presets (see CMakePresets.json in this directory)
#     cmake --preset dev-windows
#     cmake --build --preset workflow-dev
#     cmake --preset package-windows
#     cmake --build --preset inno-installer
#   Or initial cache: cmake -S . -B _build_msvc -C cmake/initial_cache/dev.example.cmake
#   Manual:
#   cmake -S . -B _build_msvc -G "Ninja"
#   cmake --build _build_msvc --target cmt-deps-build
#   cmake --build _build_msvc --target cmt-sdk-configure
#   cmake --build _build_msvc --target cmt-sdk-build
# One-shot (configure + build plugin):
#   cmake --build _build_msvc --target cmt-workflow
#
# Root targets cmt-sdk-* / cmt-workflow do NOT use sdk_*/CMakePresets.json — they run
#   cmake -S <sdk> -B <binaryDir> -G ... and cmake --build <binaryDir> ...
# You may still use presets manually inside sdk_* (e.g. cmake --preset windows_vs2022_v143).
#
# Optional cache: CMT_SDK_DIR, CMT_SDK_BINARY_DIR, CMT_SDK_GENERATOR, CMT_SDK_MSVC_ARCH, CMT_SDK_TOOLSET,
#   CMT_SDK_SKIP_VS_A_AND_T (ON for Ninja/Xcode on Linux/macOS)
#
# Windows installer: cmt-package configures + Release-builds mmdtool in ALL sdk_* required by
# installer_script.iss, then runs ISCC. One command: cmake --build --preset inno-installer.
#
# Requires CMake 3.23+ (--build --preset for root repo presets). sdk_* may use a newer CMake.
# =============================================================================

cmake_minimum_required(VERSION 3.23)
project(CMT_Project_Workflow LANGUAGES NONE)

option(CMT_WITH_DEPENDENCY_SUBDIR "Add dependency/ and register cmt-deps-build and related targets" ON)
option(CMT_DEPS_ENABLE_LIBMMD_TESTS "Enable libMMD CTest in root dependency/ subproject (cache or preset dev-windows-deps-test)" OFF)

# --- Dependencies (bullet3 + libMMD as CMake subdirectories; no dependency/install) ---
if(CMT_WITH_DEPENDENCY_SUBDIR)
  add_subdirectory(dependency)
endif()

# --- Cinema SDK and plugin (no sdk_* --preset; explicit -S/-B/--build) ---
set(CMT_SDK_DIR "${CMAKE_SOURCE_DIR}/sdk_2026" CACHE PATH "Path to sdk_* tree (must contain top-level CMakeLists.txt)")
set(CMT_SDK_BINARY_DIR "" CACHE PATH "SDK CMake build directory (-B); empty defaults to <repo>/_build_msvc/<sdk_name>")
set(CMT_SDK_GENERATOR "Visual Studio 17 2022" CACHE STRING "CMake -G when configuring the SDK (e.g. Ninja Multi-Config, Xcode)")
set(CMT_SDK_MSVC_ARCH "x64" CACHE STRING "Windows Visual Studio -A (ignored when CMT_SDK_SKIP_VS_A_AND_T is ON)")
set(CMT_SDK_TOOLSET "v143" CACHE STRING "Windows Visual Studio -T toolset (ignored when CMT_SDK_SKIP_VS_A_AND_T is ON)")
option(CMT_SDK_SKIP_VS_A_AND_T "Do not pass -A/-T when configuring the SDK (use for Ninja/Xcode on Linux/macOS)" OFF)
set(CMT_SDK_BUILD_CONFIG "Debug" CACHE STRING "Build configuration: Debug | Release | RelWithDebInfo | MinSizeRel")
set(CMT_SDK_BUILD_TARGET "mmdtool" CACHE STRING "Build only this target; empty = default/all targets")

# All sdk_* trees for cmt-package / cmt-sdk-configure-all (matches installer XdlSdkRel, deduplicated)
set(_CMT_ALL_SDK_TREES sdk_r20 sdk_r21 sdk_r23 sdk_r25 sdk_2023 sdk_2024 sdk_2025 sdk_2026)

cmake_path(ABSOLUTE_PATH CMT_SDK_DIR NORMALIZE OUTPUT_VARIABLE CMT_SDK_DIR_ABS)
if(CMT_SDK_BINARY_DIR STREQUAL "")
  cmake_path(GET CMT_SDK_DIR_ABS FILENAME _CMT_SDK_DIRNAME)
  set(CMT_SDK_BINARY_DIR "${CMAKE_SOURCE_DIR}/_build_msvc/${_CMT_SDK_DIRNAME}" CACHE PATH "SDK CMake build directory (-B)" FORCE)
endif()
cmake_path(ABSOLUTE_PATH CMT_SDK_BINARY_DIR NORMALIZE OUTPUT_VARIABLE CMT_SDK_BINARY_DIR_ABS)

set(_CMT_SDK_CONFIGURE_ARGS -S "${CMT_SDK_DIR_ABS}" -B "${CMT_SDK_BINARY_DIR_ABS}" -G "${CMT_SDK_GENERATOR}")
if(NOT CMT_SDK_SKIP_VS_A_AND_T)
  if(NOT CMT_SDK_MSVC_ARCH STREQUAL "")
    list(APPEND _CMT_SDK_CONFIGURE_ARGS -A "${CMT_SDK_MSVC_ARCH}")
  endif()
  if(NOT CMT_SDK_TOOLSET STREQUAL "")
    list(APPEND _CMT_SDK_CONFIGURE_ARGS -T "${CMT_SDK_TOOLSET}")
  endif()
endif()
# macOS architecture for SDK configure; override with x86_64 for older SDKs (R20–R23) that lack ARM support
set(CMT_SDK_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "macOS architectures for SDK build (e.g. x86_64 for pre-S24 SDKs)")
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin" AND CMT_SDK_GENERATOR STREQUAL "Xcode")
  list(APPEND _CMT_SDK_CONFIGURE_ARGS "-DCMAKE_OSX_ARCHITECTURES=${CMT_SDK_OSX_ARCHITECTURES}")
endif()
set(_CMT_SDK_NATIVE_BUILD_ARGS "")
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin" AND CMT_SDK_GENERATOR STREQUAL "Xcode")
  # Maxon SDK Xcode targets set ARCHS/ONLY_ACTIVE_ARCH themselves, so pass the
  # native xcodebuild override at build time as well as CMAKE_OSX_ARCHITECTURES.
  set(_CMT_SDK_XCODE_ARCHS "${CMT_SDK_OSX_ARCHITECTURES}")
  string(REPLACE ";" " " _CMT_SDK_XCODE_ARCHS "${_CMT_SDK_XCODE_ARCHS}")
  list(APPEND _CMT_SDK_NATIVE_BUILD_ARGS -- "ARCHS=${_CMT_SDK_XCODE_ARCHS}" "ONLY_ACTIVE_ARCH=NO")
endif()
# Forward pre-built dependency dir to SDK configure so it skips add_subdirectory for deps
if(NOT CMT_DEPS_PREBUILT_DIR STREQUAL "")
  cmake_path(ABSOLUTE_PATH CMT_DEPS_PREBUILT_DIR NORMALIZE OUTPUT_VARIABLE _CMT_DEPS_PREBUILT_ABS)
  list(APPEND _CMT_SDK_CONFIGURE_ARGS "-D" "CMT_DEPS_PREBUILT_DIR:PATH=${_CMT_DEPS_PREBUILT_ABS}")
else()
  # SDK CMakeCache may still hold CMT_DEPS_PREBUILT_DIR from a previous cmt-package / manual run.
  # That skips add_subdirectory(libMMD) and breaks mmdtool linking (LNK2019) when prebuilt/lib is empty.
  list(APPEND _CMT_SDK_CONFIGURE_ARGS "-U" "CMT_DEPS_PREBUILT_DIR")
endif()

# --- Packaging (Inno Setup, optional) ---
set(CMT_INNO_SETUP_ISCC "" CACHE FILEPATH "Path to Inno Setup ISCC.exe; empty disables cmt-package")
set(CMT_ISS_MAIN "${CMAKE_SOURCE_DIR}/setup/Common/installer_script.iss" CACHE FILEPATH "Main .iss script")
set(CMT_ISS_EXTRA_ARGS "" CACHE STRING "Extra arguments for ISCC, e.g. /DPluginVersion=0.5.0 /DSdkBuildDir=_build_msvc")

# -----------------------------------------------------------------------------
# cmt-sdk-configure — Configure the selected SDK (same as cmake -S/-B, not sdk presets)
# -----------------------------------------------------------------------------
add_custom_target(cmt-sdk-configure
  COMMAND ${CMAKE_COMMAND} ${_CMT_SDK_CONFIGURE_ARGS}
  USES_TERMINAL
  COMMENT "Configure SDK: -S ${CMT_SDK_DIR_ABS} -B ${CMT_SDK_BINARY_DIR_ABS}"
)

# -----------------------------------------------------------------------------
# cmt-sdk-configure-all — Configure every sdk_* (same -G/-A/-T as single-SDK path)
# SDK build dirs: <repo>/<root-build-dir-name>/<sdk> (e.g. _build_msvc/sdk_2026)
# -----------------------------------------------------------------------------
cmake_path(GET CMAKE_BINARY_DIR FILENAME _CMT_ROOT_BUILDDIR_NAME)
set(_CMT_SDK_CONFIGURE_ALL_COMMANDS "")
foreach(_sdk_dir IN LISTS _CMT_ALL_SDK_TREES)
  set(_sdk_src "${CMAKE_SOURCE_DIR}/${_sdk_dir}")
  set(_sdk_bin "${CMAKE_SOURCE_DIR}/${_CMT_ROOT_BUILDDIR_NAME}/${_sdk_dir}")
  set(_sdk_cfg -S "${_sdk_src}" -B "${_sdk_bin}" -G "${CMT_SDK_GENERATOR}")
  if(NOT CMT_SDK_SKIP_VS_A_AND_T)
    if(NOT CMT_SDK_MSVC_ARCH STREQUAL "")
      list(APPEND _sdk_cfg -A "${CMT_SDK_MSVC_ARCH}")
    endif()
    if(NOT CMT_SDK_TOOLSET STREQUAL "")
      list(APPEND _sdk_cfg -T "${CMT_SDK_TOOLSET}")
    endif()
  endif()
  if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin" AND CMT_SDK_GENERATOR STREQUAL "Xcode")
    list(APPEND _sdk_cfg "-DCMAKE_OSX_ARCHITECTURES=${CMT_SDK_OSX_ARCHITECTURES}")
  endif()
  if(NOT CMT_DEPS_PREBUILT_DIR STREQUAL "")
    cmake_path(ABSOLUTE_PATH CMT_DEPS_PREBUILT_DIR NORMALIZE OUTPUT_VARIABLE _CMT_DEPS_PREBUILT_ABS)
    list(APPEND _sdk_cfg "-D" "CMT_DEPS_PREBUILT_DIR:PATH=${_CMT_DEPS_PREBUILT_ABS}")
  else()
    list(APPEND _sdk_cfg "-U" "CMT_DEPS_PREBUILT_DIR")
  endif()
  list(APPEND _CMT_SDK_CONFIGURE_ALL_COMMANDS COMMAND ${CMAKE_COMMAND} ${_sdk_cfg})
endforeach()
add_custom_target(cmt-sdk-configure-all
  ${_CMT_SDK_CONFIGURE_ALL_COMMANDS}
  USES_TERMINAL
  VERBATIM
  COMMENT "Configure all sdk_* under ${CMAKE_SOURCE_DIR}/${_CMT_ROOT_BUILDDIR_NAME}/<sdk>"
)

# -----------------------------------------------------------------------------
# cmt-sdk-build — Build the plugin in the selected SDK
# -----------------------------------------------------------------------------
if(NOT CMT_SDK_BUILD_TARGET STREQUAL "")
  add_custom_target(cmt-sdk-build
    COMMAND ${CMAKE_COMMAND} --build "${CMT_SDK_BINARY_DIR_ABS}" --config "${CMT_SDK_BUILD_CONFIG}" --target "${CMT_SDK_BUILD_TARGET}" ${_CMT_SDK_NATIVE_BUILD_ARGS}
    USES_TERMINAL
    COMMENT "Build plugin (${CMT_SDK_BUILD_CONFIG}, target=${CMT_SDK_BUILD_TARGET})"
  )
else()
  add_custom_target(cmt-sdk-build
    COMMAND ${CMAKE_COMMAND} --build "${CMT_SDK_BINARY_DIR_ABS}" --config "${CMT_SDK_BUILD_CONFIG}" ${_CMT_SDK_NATIVE_BUILD_ARGS}
    USES_TERMINAL
    COMMENT "Build SDK default targets (${CMT_SDK_BUILD_CONFIG})"
  )
endif()

# -----------------------------------------------------------------------------
# cmt-workflow — Configure SDK then build plugin
# -----------------------------------------------------------------------------
if(CMT_SDK_BUILD_TARGET STREQUAL "")
  add_custom_target(cmt-workflow
    COMMAND ${CMAKE_COMMAND} ${_CMT_SDK_CONFIGURE_ARGS}
    COMMAND ${CMAKE_COMMAND} --build "${CMT_SDK_BINARY_DIR_ABS}" --config "${CMT_SDK_BUILD_CONFIG}" ${_CMT_SDK_NATIVE_BUILD_ARGS}
    USES_TERMINAL
    COMMENT "configure + build SDK (${CMT_SDK_BUILD_CONFIG})"
  )
else()
  add_custom_target(cmt-workflow
    COMMAND ${CMAKE_COMMAND} ${_CMT_SDK_CONFIGURE_ARGS}
    COMMAND ${CMAKE_COMMAND} --build "${CMT_SDK_BINARY_DIR_ABS}" --config "${CMT_SDK_BUILD_CONFIG}" --target "${CMT_SDK_BUILD_TARGET}" ${_CMT_SDK_NATIVE_BUILD_ARGS}
    USES_TERMINAL
    COMMENT "configure + build target ${CMT_SDK_BUILD_TARGET} (${CMT_SDK_BUILD_CONFIG})"
  )
endif()

if(CMT_WITH_DEPENDENCY_SUBDIR)
  add_dependencies(cmt-workflow cmt-deps-build)
endif()

# -----------------------------------------------------------------------------
# cmt-package — Build ALL SDKs (Release) + Inno Setup installer (one-click)
# SDK list matches XdlSdkRel in installer_script.iss (deduplicated).
# -----------------------------------------------------------------------------
if(NOT CMT_INNO_SETUP_ISCC STREQUAL "")
  cmake_path(ABSOLUTE_PATH CMT_INNO_SETUP_ISCC NORMALIZE OUTPUT_VARIABLE _CMT_ISCC_ABS)
  cmake_path(ABSOLUTE_PATH CMT_ISS_MAIN NORMALIZE OUTPUT_VARIABLE _CMT_ISS_ABS)
  if(NOT EXISTS "${_CMT_ISCC_ABS}")
    message(WARNING
      "CMT_INNO_SETUP_ISCC not found: ${_CMT_ISCC_ABS}\n"
      "Set the cache to your ISCC.exe. Common locations:\n"
      "  C:/Program Files/Inno Setup 6/ISCC.exe\n"
      "  C:/Program Files (x86)/Inno Setup 6/ISCC.exe"
    )
  endif()
  if(NOT EXISTS "${_CMT_ISS_ABS}")
    message(FATAL_ERROR "Installer script not found: ${_CMT_ISS_ABS}")
  endif()
  if(NOT CMT_ISS_EXTRA_ARGS STREQUAL "")
    separate_arguments(_CMT_ISS_EXTRA NATIVE_COMMAND "${CMT_ISS_EXTRA_ARGS}")
  endif()

  # Build shared deps (bullet3 + libMMD) once; all SDKs link pre-built .libs.
  set(_cmt_deps_prebuilt "${CMAKE_SOURCE_DIR}/_build_msvc/cmt_deps_prebuilt")
  set(_cmt_deps_bin "${CMAKE_SOURCE_DIR}/_build_msvc/cmt_deps")
  set(_cmt_deps_cfg
    -S "${CMAKE_SOURCE_DIR}/dependency"
    -B "${_cmt_deps_bin}"
    -G "${CMT_SDK_GENERATOR}"
    "-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=${_cmt_deps_prebuilt}/lib"
    "-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=${_cmt_deps_prebuilt}/lib"
  )
  if(NOT CMT_SDK_SKIP_VS_A_AND_T)
    if(NOT CMT_SDK_MSVC_ARCH STREQUAL "")
      list(APPEND _cmt_deps_cfg -A "${CMT_SDK_MSVC_ARCH}")
    endif()
    if(NOT CMT_SDK_TOOLSET STREQUAL "")
      list(APPEND _cmt_deps_cfg -T "${CMT_SDK_TOOLSET}")
    endif()
  endif()

  set(_CMT_PACKAGE_COMMANDS
    COMMAND ${CMAKE_COMMAND} ${_cmt_deps_cfg}
    COMMAND ${CMAKE_COMMAND} --build "${_cmt_deps_bin}" --config Release
    COMMAND ${CMAKE_COMMAND} --build "${_cmt_deps_bin}" --config Debug
  )

  foreach(_sdk IN LISTS _CMT_ALL_SDK_TREES)
    set(_sdk_src "${CMAKE_SOURCE_DIR}/${_sdk}")
    set(_sdk_bin "${CMAKE_SOURCE_DIR}/_build_msvc/${_sdk}")
    set(_sdk_cfg -S "${_sdk_src}" -B "${_sdk_bin}" -G "${CMT_SDK_GENERATOR}"
      "-DCMT_DEPS_PREBUILT_DIR:PATH=${_cmt_deps_prebuilt}"
    )
    if(NOT CMT_SDK_SKIP_VS_A_AND_T)
      if(NOT CMT_SDK_MSVC_ARCH STREQUAL "")
        list(APPEND _sdk_cfg -A "${CMT_SDK_MSVC_ARCH}")
      endif()
      if(NOT CMT_SDK_TOOLSET STREQUAL "")
        list(APPEND _sdk_cfg -T "${CMT_SDK_TOOLSET}")
      endif()
    endif()
    list(APPEND _CMT_PACKAGE_COMMANDS
      COMMAND ${CMAKE_COMMAND} ${_sdk_cfg}
      COMMAND ${CMAKE_COMMAND} --build "${_sdk_bin}" --config Release --target mmdtool
    )
  endforeach()

  if(CMT_ISS_EXTRA_ARGS STREQUAL "")
    add_custom_target(cmt-package
      ${_CMT_PACKAGE_COMMANDS}
      COMMAND "${_CMT_ISCC_ABS}" "${_CMT_ISS_ABS}"
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      USES_TERMINAL
      VERBATIM
      COMMENT "Build all SDKs (Release) + Inno Setup installer"
    )
  else()
    add_custom_target(cmt-package
      ${_CMT_PACKAGE_COMMANDS}
      COMMAND "${_CMT_ISCC_ABS}" ${_CMT_ISS_EXTRA} "${_CMT_ISS_ABS}"
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      USES_TERMINAL
      VERBATIM
      COMMENT "Build all SDKs (Release) + Inno Setup installer"
    )
  endif()
  if(CMT_WITH_DEPENDENCY_SUBDIR)
    add_dependencies(cmt-package cmt-deps-build)
  endif()
endif()

# -----------------------------------------------------------------------------
# cmt-clean — Remove root _build_msvc directory (root project + all SDK build trees)
# -----------------------------------------------------------------------------
add_custom_target(cmt-clean
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/_build_msvc"
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/_build_clangcl"
  COMMENT "Remove _build_msvc and _build_clangcl (root project + all SDK build trees)"
)

# -----------------------------------------------------------------------------
# cmt-clean-deps — Remove legacy third-party dirs and all cmt_deps trees
#
# Plugin builds (sdk_* with mmdtool_plugin_dependencies_add) place Bullet/libMMD under
#   <repo>/_build_msvc/sdk_2026/cmt_deps  (CMAKE_BINARY_DIR of the SDK project)
# Root "dependency/" workflow uses <repo>/_build_msvc/cmt_deps
# The old target only removed ${CMAKE_BINARY_DIR}/cmt_deps (root configure), so SDK
# builds were never cleaned — we glob common _build_*/*/cmt_deps patterns below.
# -----------------------------------------------------------------------------
set(_CMT_CLEAN_DEPS_EXTRA_COMMANDS "")
file(GLOB _CMT_CMT_DEPS_SDK_GLOB
  "${CMAKE_SOURCE_DIR}/_build_msvc/*/cmt_deps"
  "${CMAKE_SOURCE_DIR}/_build_ninja/*/cmt_deps"
  "${CMAKE_SOURCE_DIR}/_build_clangcl/*/cmt_deps"
  "${CMAKE_SOURCE_DIR}/_build_xcode/*/cmt_deps"
)
foreach(_d IN LISTS _CMT_CMT_DEPS_SDK_GLOB)
  list(APPEND _CMT_CLEAN_DEPS_EXTRA_COMMANDS COMMAND ${CMAKE_COMMAND} -E rm -rf "${_d}")
endforeach()

add_custom_target(cmt-clean-deps
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/dependency/bullet3/build"
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/dependency/libMMD/build"
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/dependency/install"
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_BINARY_DIR}/cmt_deps"
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/_build_msvc/cmt_deps"
  ${_CMT_CLEAN_DEPS_EXTRA_COMMANDS}
  COMMENT "Remove legacy dependency/*build, dependency/install, root cmt_deps, and sdk_* cmt_deps under _build_*"
)
