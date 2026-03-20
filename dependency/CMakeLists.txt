# Third-party deps: cmake/mmdtool_plugin_dependencies.cmake adds Bullet3 + libMMD (no dependency/install).
# Optional: set CMT_DEPS_ENABLE_LIBMMD_TESTS=ON in root CMake cache/preset for libMMD CTest; plugin builds use add_subdirectory in each sdk_*.

cmake_minimum_required(VERSION 3.22)
project(cmt_dependency_workflow LANGUAGES CXX)

option(CMT_DEPS_BUILD_DEBUG "Legacy compatibility flag; subdirectory mode uses comments/extensions only" ON)
option(CMT_DEPS_BUILD_RELEASE "Legacy compatibility flag" ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/mmdtool_plugin_dependencies.cmake)
mmdtool_plugin_dependencies_add(${CMAKE_CURRENT_SOURCE_DIR}/..)

if(NOT CMT_DEPS_BUILD_DEBUG AND NOT CMT_DEPS_BUILD_RELEASE)
  message(FATAL_ERROR "At least one of CMT_DEPS_BUILD_DEBUG/CMT_DEPS_BUILD_RELEASE must be ON.")
endif()

add_custom_target(cmt-deps-build ALL DEPENDS libMMD
  COMMENT "Bullet3+libMMD via add_subdirectory (no dependency/install); SDK mmdtool build uses the same targets"
)

if(CMT_DEPS_ENABLE_LIBMMD_TESTS)
  add_custom_target(cmt-deps-test
    COMMAND ${CMAKE_CTEST_COMMAND} --test-dir "${CMAKE_BINARY_DIR}/cmt_deps/libMMD" -C Debug --output-on-failure
    DEPENDS libMMD
    USES_TERMINAL
    COMMENT "Run libMMD CTest (Debug); enable with -D CMT_DEPS_ENABLE_LIBMMD_TESTS=ON or preset dev-windows-deps-test"
  )
endif()
