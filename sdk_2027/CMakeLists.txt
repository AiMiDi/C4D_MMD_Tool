# Contains the main CMake configuration for the Cinema 4D SDK project.
#
# This CMakeLists.txt file contains the main configuration for the Cinema 4D SDK project. Other than
# the module project files, it is not meant to be heavily modified. You can change the markup between
# the "Customization Start" and "Customization End" sections to adjust the SDK setup to your needs 
# but in general, the SDK is designed to work out of the box without requiring modifications. You
# can simply rely on module auto discovery and never need to manually modify this file.
#
# WARNING: Removing pr modifying build system setup calls made by this file may break the SDK build 
# process and are out of scope of support.
#
# Copyright (c) 2026 Maxon Computer GmbH. All rights reserved.

cmake_minimum_required(VERSION 3.30)

project(c4d-sdk LANGUAGES CXX)

# Define the basic project settings, these should never be modified.
set(CMAKE_CXX_STANDARD "20" CACHE STRING "C++ Standard.")
set_property(CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS "17" "20")
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# Define path variables, these should not be modified either.
set(MAXON_SDK_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MAXON_FRAMEWORKS_DIR "${MAXON_SDK_ROOT_DIR}/frameworks")
set(MAXON_TOOLING_DIR "${MAXON_SDK_ROOT_DIR}/cmake")
set(MAXON_BASE_SETTINGS_DIR "${MAXON_TOOLING_DIR}/base_settings")

# Define configurable options for the SDK.
set(MAXON_SDK_MODULES_DIR "${MAXON_SDK_ROOT_DIR}/plugins" CACHE PATH "Path to the modules folder of the project.")
set(MAXON_SDK_EXTERNAL_LIBS_DIR "${MAXON_SDK_ROOT_DIR}/libs" CACHE PATH "Path to the global external libs folder used by the project.")
set(MAXON_C4D_EXECUTABLE "" CACHE FILEPATH "Path to Cinema 4D executable used as a debug application when debugging.")
option(MAXON_FILTER_UNUSED_FRAMEWORKS "Ignore frameworks that are not used by any modules." ON)
option(MAXON_MIGRATE_LEGACY_PROJECTS "Migrate legacy project definition projects." OFF)

# The average user does not have to see these.
mark_as_advanced(
	CMAKE_INSTALL_PREFIX
	CMAKE_OSX_DEPLOYMENT_TARGET
	CMAKE_OSX_SYSROOT
)

# Include the necessary SDK helper scripts. Never modify these files.
include (${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)
include (${MAXON_TOOLING_DIR}/sdk_sourceprocessor.cmake)
include (${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include (${MAXON_TOOLING_DIR}/sdk_tools.cmake)
include (${MAXON_TOOLING_DIR}/sdk_migrate_projectdefinition.cmake)

# Setup the SDK environment, including optional migration of legacy project definitions.
MaxonSDKTools_Setup()

# --- Customization Start --------------------------------------------------------------------------

# In this section you can customize the SDK setup, such as adding additional modules or modifying 
# project settings.

# By default we use this function to discover and include all modules in the specified modules directory.
MaxonSDKTools_DiscoverModules(MODULES_DIR "${MAXON_SDK_MODULES_DIR}")

# Alternatively, when you do not like this auto globbing behavior, you can also manually specify 
# individual modules using the standard CMake `add_subdirectory` command. Note that the SDK build
# system relies on modules being located in #MAXON_SDK_MODULES_DIR. So, you cannot just add paths
# from arbitrary locations. If you want to link modules from other paths, you must create a symbolic 
# link inside the MAXON_SDK_MODULES_DIR pointing to the external module location and then either
# auto glob them or manually add them using `add_subdirectory`.

# add_subdirectory(plugins/example.assets/project)
# add_subdirectory(plugins/example.build/project)
# add_subdirectory(plugins/example.image/project)
# add_subdirectory(plugins/example.migrate_projectdefinition/project)
# ...

# --- Customization End ----------------------------------------------------------------------------

# Finalize the SDK setup by creating and including all necessary framework targets.
MaxonSDKTools_Finalize()
