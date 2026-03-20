# Cinema 4D SDK root level CMakeLists.txt
#
# This file is usually not meant to be modified, all problems arising from modifications are
# out of scope of support.

cmake_minimum_required(VERSION 3.30)

# Initialize the C++ project.
set(CMAKE_CXX_STANDARD "20" CACHE STRING "C++ Standard.")
set_property(CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS "17" "20")
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
project(c4d-sdk LANGUAGES CXX)

# The folders which must be placed in relation to the SDK and cannot be relocated.
set(MAXON_SDK_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}") 
set(MAXON_FRAMEWORKS_DIR "${MAXON_SDK_ROOT_DIR}/frameworks")
set(MAXON_TOOLING_DIR "${MAXON_SDK_ROOT_DIR}/cmake")
set(MAXON_BASE_SETTINGS_DIR "${MAXON_TOOLING_DIR}/base_settings")

# The overwhelming majority of plugin developers will never need these.
# mark_as_advanced(CMAKE_CXX_STANDARD) 
mark_as_advanced(CMAKE_INSTALL_PREFIX)
mark_as_advanced(CMAKE_OSX_DEPLOYMENT_TARGET)
mark_as_advanced(CMAKE_OSX_SYSROOT)

# The plugins folder of the project, usually located in the project root.
set(MAXON_SDK_MODULES_DIR "${MAXON_SDK_ROOT_DIR}/plugins" CACHE PATH "Path to the modules folder of the project. Usually does not have to be adjusted.")
# The file containing a list of module paths. When not set, MAXON_SDK_MODULES_DIR is used to search for modules. When set, MAXON_SDK_MODULES_DIR is ignored.
set(MAXON_SDK_CUSTOM_PATHS_FILE "${MAXON_SDK_ROOT_DIR}/custom_paths.txt" CACHE FILEPATH "Path to a file containing a list of module paths. When not set, MAXON_SDK_MODULES_DIR is used to search for modules. When set, MAXON_SDK_MODULES_DIR is ignored.")
# The path to the global external libs folder used by the project.
set(MAXON_SDK_EXTERNAL_LIBS_DIR "${MAXON_SDK_ROOT_DIR}/libs" CACHE PATH "Path to the global external libs folder used by the project.")
# The path to a Cinema 4D executable which shall be used for debugging.
set(MAXON_C4D_EXECUTABLE "" CACHE FILEPATH "Path to Cinema 4D executable used as a debug application when debugging.")
# Slight optimization setting to exclude frameworks from the project which are not referenced by projectdefinition.txt files of any modules.
option(MAXON_FILTER_UNUSED_FRAMEWORKS "Ignore frameworks that are not used by any modules." ON)

include (${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)
include (${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include (${MAXON_TOOLING_DIR}/sdk_update_projects.cmake)

# Configure the the project.
MaxonTargets_SetupOSIdentifierGlobals()
MaxonCompilerHelper_SetConfigurations()
MaxonTargets_ConfigurePythonPaths()

# Define build output directories. res directories will be symlinked for each plugin.
foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
	string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG}/libs)
	set(CMAKE_PLUGINS_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG}/plugins)
endforeach()

# Parse the custom paths file and add the modules to the project.
set(MAXON_SDK_MODULE_PATHS "")
set(MAXON_SDK_PATH_ALIASES "") 
set(MAXON_SDK_CURRENT_MODULE "" CACHE INTERNAL "The currently processed module.")

if(EXISTS "${MAXON_SDK_CUSTOM_PATHS_FILE}")
	ReadCustomPaths(${MAXON_SDK_CUSTOM_PATHS_FILE} MAXON_SDK_MODULE_PATHS MAXON_SDK_PATH_ALIASES)
endif()

if (NOT MAXON_SDK_MODULE_PATHS)
	file(GLOB TOP_LEVEL_DIRS RELATIVE ${MAXON_SDK_MODULES_DIR} ${MAXON_SDK_MODULES_DIR}/*)
	foreach(dir ${TOP_LEVEL_DIRS})
		if(IS_DIRECTORY "${MAXON_SDK_MODULES_DIR}/${dir}" AND 
			NOT EXISTS "${MAXON_SDK_MODULES_DIR}/${dir}/projectdefinition.txt")
			list(APPEND MAXON_SDK_MODULE_PATHS "${MAXON_SDK_MODULES_DIR}/${dir}")
		endif()
	endforeach()
endif()

MaxonUpdateProjects_Initialize(usedFrameworks usedFrameworkPaths "${MAXON_SDK_MODULE_PATHS}")

# Add the modules and frameworks to the project, optionally ignoring frameworks not use by any modules.
if (MAXON_FILTER_UNUSED_FRAMEWORKS) 
	MaxonUpdateProjects_GetUsedFrameworks("${usedFrameworks}")
	MaxonUpdateProjects_LoadFrameworks("${fullSortedFrameworksList}")
else()
	MaxonUpdateProjects_Initialize(usedFrameworks usedFrameworkPaths "${MAXON_FRAMEWORKS_DIR}")
endif()
