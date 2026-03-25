# mmdtool_plugin_dependencies.cmake — Add Bullet3 + libMMD as subdirectories (no dependency/install).
# Call after project() and before defining the mmdtool plugin: mmdtool_plugin_dependencies_add(<repo root>)
#
# When CMT_DEPS_PREBUILT_DIR is set (absolute path to a directory containing lib/*.lib),
# add_subdirectory is skipped and cmt_setup_mmdtool_plugin() links pre-built libs instead.
#
include_guard(GLOBAL)

set(CMT_DEPS_PREBUILT_DIR "" CACHE PATH
  "Pre-built dependency lib directory (contains lib/*.lib). When set, skip add_subdirectory for bullet3/libMMD.")

function(mmdtool_plugin_dependencies_add PROJECT_ROOT_DIR)
  if(NOT CMT_DEPS_PREBUILT_DIR STREQUAL "")
    return()
  endif()
  cmake_path(ABSOLUTE_PATH PROJECT_ROOT_DIR NORMALIZE OUTPUT_VARIABLE _root)
  set(_bullet "${_root}/dependency/bullet3")
  set(_libmmd "${_root}/dependency/libMMD")
  if(NOT EXISTS "${_bullet}/CMakeLists.txt")
    message(FATAL_ERROR "mmdtool_plugin_dependencies: bullet3 not found at ${_bullet}")
  endif()
  if(NOT EXISTS "${_libmmd}/CMakeLists.txt")
    message(FATAL_ERROR "mmdtool_plugin_dependencies: libMMD not found at ${_libmmd}")
  endif()

  set(_bul_bin "${CMAKE_BINARY_DIR}/cmt_deps/bullet3")
  set(_lm_bin "${CMAKE_BINARY_DIR}/cmt_deps/libMMD")

  # Bullet: static libs, no demos (aligned with historical standalone build options)
  # Single precision (float) — must match plugin BT_USE_DOUBLE_PRECISION (off) and libMMD Bullet ABI.
  set(USE_DOUBLE_PRECISION OFF CACHE BOOL "" FORCE)
  if(MSVC)
    # Bullet CMake: add_definitions(/arch:AVX) for LinearMath/Collision/Dynamics (MSVC x64 only path).
    set(USE_MSVC_AVX ON CACHE BOOL "" FORCE)
  endif()
  set(USE_MSVC_RUNTIME_LIBRARY_DLL ON CACHE BOOL "" FORCE)
  set(BUILD_CPU_DEMOS OFF CACHE BOOL "" FORCE)
  set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "" FORCE)
  set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "" FORCE)
  set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
  set(BUILD_BULLET3 OFF CACHE BOOL "" FORCE)
  set(BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
  set(USE_GRAPHICAL_BENCHMARK OFF CACHE BOOL "" FORCE)
  set(BUILD_PYBULLET OFF CACHE BOOL "" FORCE)
  set(INSTALL_LIBS ON CACHE BOOL "" FORCE)
  set(CMAKE_DEBUG_POSTFIX "_Debug" CACHE STRING "" FORCE)

  add_subdirectory("${_bullet}" "${_bul_bin}" EXCLUDE_FROM_ALL)

  # libMMD: link Bullet targets from the same graph (see LIBMMD_BULLET_USE_SUBDIRECTORY in libMMD/CMakeLists.txt)
  set(LIBMMD_BULLET_SOURCE_DIR "${_bullet}" CACHE PATH "Bullet source root (for includes)" FORCE)
  set(LIBMMD_BULLET_USE_SUBDIRECTORY ON CACHE BOOL "Bullet provided by parent add_subdirectory" FORCE)
  # Enable CTest only when CMT_DEPS_ENABLE_LIBMMD_TESTS is set in cache (root dependency/); sdk_* plugin projects do not set it.
  if(CMT_DEPS_ENABLE_LIBMMD_TESTS)
    set(LIBMMD_ENABLE_TEST ON CACHE BOOL "" FORCE)
  else()
    set(LIBMMD_ENABLE_TEST OFF CACHE BOOL "" FORCE)
  endif()
  set(LIBMMD_INSTALL OFF CACHE BOOL "" FORCE)
  set(LIBMMD_ENABLE_AVX2 ON CACHE BOOL "" FORCE)
  set(CMAKE_DEBUG_POSTFIX "_Debug" CACHE STRING "" FORCE)

  add_subdirectory("${_libmmd}" "${_lm_bin}" EXCLUDE_FROM_ALL)
endfunction()
