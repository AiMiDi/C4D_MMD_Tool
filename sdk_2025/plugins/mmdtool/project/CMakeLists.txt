# Custom CMakeLists.txt for mmdtool plugin.
# When this file exists, the build system uses it directly and does NOT parse projectdefinition.txt.

include(${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include(${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)

set(PROJECT_ROOT_DIR ${MAXON_SDK_ROOT_DIR}/..)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH MODULE_ROOT_DIR)

include(${PROJECT_ROOT_DIR}/cmake/mmdtool_plugin_dependencies.cmake)
mmdtool_plugin_dependencies_add(${PROJECT_ROOT_DIR})

include(${PROJECT_ROOT_DIR}/cmake/mmdtool_plugin_common.cmake)

cmt_setup_mmdtool_plugin(
  PROJECT_ROOT_DIR ${PROJECT_ROOT_DIR}
  MODULE_ROOT_DIR ${MODULE_ROOT_DIR}
  SOURCE_ROOT ${PROJECT_ROOT_DIR}/source
  RESOURCE_ROOT ${PROJECT_ROOT_DIR}/res/S24_up
  DEPENDENCY_MODE SUBDIR
)
