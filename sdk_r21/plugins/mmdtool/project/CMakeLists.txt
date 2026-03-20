include(${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include(${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)

set(PROJECT_ROOT_DIR ${MAXON_SDK_ROOT_DIR}/..)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH MODULE_ROOT_DIR)

include(${PROJECT_ROOT_DIR}/cmake/mmdtool_plugin_dependencies.cmake)
mmdtool_plugin_dependencies_add(${PROJECT_ROOT_DIR})

include(${PROJECT_ROOT_DIR}/cmake/mmdtool_plugin_common.cmake)

file(GLOB _FRAMEWORK_SOURCE_DIRS "${MAXON_SDK_ROOT_DIR}/frameworks/*.framework/source")

if(EXISTS "${MODULE_ROOT_DIR}/res" AND NOT IS_SYMLINK "${MODULE_ROOT_DIR}/res")
  file(REMOVE_RECURSE "${MODULE_ROOT_DIR}/res")
endif()

cmt_setup_mmdtool_plugin(
  PROJECT_ROOT_DIR ${PROJECT_ROOT_DIR}
  MODULE_ROOT_DIR ${MODULE_ROOT_DIR}
  SOURCE_ROOT ${PROJECT_ROOT_DIR}/source
  RESOURCE_ROOT ${PROJECT_ROOT_DIR}/res/R20-S24
  DEPENDENCY_MODE SUBDIR
  EXTRA_INCLUDE_DIRS ${_FRAMEWORK_SOURCE_DIRS}
  FRAMEWORK_DEPENDENCIES
    cinema.framework
    core.framework
    image.framework
    math.framework
    mesh_misc.framework
    command.framework
    crypt.framework
    geom.framework
    python.framework
)
