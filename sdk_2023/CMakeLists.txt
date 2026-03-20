cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD "20" CACHE STRING "C++ Standard.")
set_property(CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS "17" "20")
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
project(c4d-sdk-2023-bridge LANGUAGES CXX)

set(MAXON_SDK_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MAXON_FRAMEWORKS_DIR "${MAXON_SDK_ROOT_DIR}/frameworks")

# 2023 bridge: reuse 2026 CMake tooling directly.
set(MAXON_TOOLING_DIR "${MAXON_SDK_ROOT_DIR}/../cmake/sdk")
set(MAXON_BASE_SETTINGS_DIR "${MAXON_SDK_ROOT_DIR}/../cmake/sdk/base_settings")

mark_as_advanced(CMAKE_INSTALL_PREFIX)
mark_as_advanced(CMAKE_OSX_DEPLOYMENT_TARGET)
mark_as_advanced(CMAKE_OSX_SYSROOT)

set(MAXON_SDK_MODULES_DIR "${MAXON_SDK_ROOT_DIR}/plugins" CACHE PATH "Path to modules folder.")
set(MAXON_SDK_CUSTOM_PATHS_FILE "${MAXON_SDK_ROOT_DIR}/custom_paths.txt" CACHE FILEPATH "Optional custom module path file.")
set(MAXON_SDK_EXTERNAL_LIBS_DIR "${MAXON_SDK_ROOT_DIR}/libs" CACHE PATH "Path to external libs folder.")
set(MAXON_C4D_EXECUTABLE "" CACHE FILEPATH "Path to Cinema 4D executable used for debugging.")
option(MAXON_FILTER_UNUSED_FRAMEWORKS "Ignore frameworks not referenced by modules." ON)

include(${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)
include(${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include(${MAXON_TOOLING_DIR}/sdk_update_projects.cmake)
include(${MAXON_SDK_ROOT_DIR}/cmake/sdk_compat_2023.cmake)

MaxonTargets_SetupOSIdentifierGlobals()
MaxonCompilerHelper_SetConfigurations()
MaxonTargets_ConfigurePythonPaths()

foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
  string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG}/libs)
  set(CMAKE_PLUGINS_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG}/plugins)
endforeach()

set(MAXON_SDK_MODULE_PATHS "")
set(MAXON_SDK_PATH_ALIASES "")
set(MAXON_SDK_CURRENT_MODULE "" CACHE INTERNAL "Currently processed module.")

if(EXISTS "${MAXON_SDK_CUSTOM_PATHS_FILE}")
  ReadCustomPaths(${MAXON_SDK_CUSTOM_PATHS_FILE} MAXON_SDK_MODULE_PATHS MAXON_SDK_PATH_ALIASES)
endif()

if(NOT MAXON_SDK_MODULE_PATHS)
  file(GLOB TOP_LEVEL_DIRS RELATIVE ${MAXON_SDK_MODULES_DIR} ${MAXON_SDK_MODULES_DIR}/*)
  foreach(dir ${TOP_LEVEL_DIRS})
    if(IS_DIRECTORY "${MAXON_SDK_MODULES_DIR}/${dir}" AND
      NOT EXISTS "${MAXON_SDK_MODULES_DIR}/${dir}/projectdefinition.txt")
      list(APPEND MAXON_SDK_MODULE_PATHS "${MAXON_SDK_MODULES_DIR}/${dir}")
    endif()
  endforeach()
endif()

MaxonUpdateProjects_Initialize(usedFrameworks usedFrameworkPaths "${MAXON_SDK_MODULE_PATHS}")

if(MAXON_FILTER_UNUSED_FRAMEWORKS)
  MaxonUpdateProjects_GetUsedFrameworks("${usedFrameworks}")
  MaxonUpdateProjects_LoadFrameworks("${fullSortedFrameworksList}")
else()
  MaxonUpdateProjects_Initialize(usedFrameworks usedFrameworkPaths "${MAXON_FRAMEWORKS_DIR}")
endif()
