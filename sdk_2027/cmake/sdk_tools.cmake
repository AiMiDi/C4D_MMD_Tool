if(MAXONSDKTOOLS_INCLUDED)
	return()
endif()

# --- Functions ------------------------------------------------------------------------------------

# Runs the boilerplate code for setting up the Visual Studio system processor.
function(MaxonSDKTools_SetupVisualStudioSystemProcessor)
	if(NOT CMAKE_GENERATOR MATCHES "Visual Studio")
		return()
	endif()

	# Visual Studio generators may not set CMAKE_SYSTEM_PROCESSOR correctly when cross-compiling.
	# This must run after project(), which otherwise overwrites the correction.
	# https://gitlab.kitware.com/cmake/cmake/-/issues/15170
	if(CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE STREQUAL CMAKE_VS_PLATFORM_NAME)
		message(STATUS "Detected native compilation on ${CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE}")
	else()
		message(STATUS "Detected cross compilation on ${CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE} for ${CMAKE_VS_PLATFORM_NAME}")
		set(CMAKE_SYSTEM_PROCESSOR "${CMAKE_VS_PLATFORM_NAME}" PARENT_SCOPE)
	endif()
endfunction()

# Runs the migration of legacy project definitions if enabled.
function(MaxonSDKTools_MigrateLegacyProjects)
	if(NOT MAXON_MIGRATE_LEGACY_PROJECTS)
		message(STATUS "Legacy project migration is disabled.")
		return()
	endif()

	message(STATUS "Checking '${MAXON_SDK_MODULES_DIR}' for legacy project definitions.")
	file(GLOB module_paths LIST_DIRECTORIES true "${MAXON_SDK_MODULES_DIR}/*")
	set(migrated_module_count 0)
	foreach(module_path IN LISTS module_paths)
		if(NOT IS_DIRECTORY "${module_path}")
			continue()
		endif()

		set(project_path "${module_path}/project")
		set(cmake_file "${project_path}/CMakeLists.txt")
		set(project_definition "${project_path}/projectdefinition.txt")
		if(EXISTS "${cmake_file}" OR NOT EXISTS "${project_definition}")
			continue()
		endif()

		get_filename_component(target_name "${module_path}" NAME)
		message(STATUS "Migrating legacy module '${target_name}'.")
		MigrateProjectDefinition_UpdateProject(
			TargetName "${target_name}"
			ProjectFile "${project_definition}"
			CMakeFile "${cmake_file}"
			Status migration_status
		)
		if(NOT migration_status OR NOT EXISTS "${cmake_file}")
			message(FATAL_ERROR "Could not migrate module '${module_path}'.")
		endif()
		math(EXPR migrated_module_count "${migrated_module_count} + 1")
	endforeach()
	message(STATUS "Legacy project migration complete. Migrated ${migrated_module_count} module(s).")
endfunction()

# Discovers and includes all SDK modules in the specified modules directory.
function(MaxonSDKTools_DiscoverModules)
	set(options)
	set(oneValueArgs MODULES_DIR)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "" ${ARGN})
	if(NOT arg_MODULES_DIR)
		set(arg_MODULES_DIR "${MAXON_SDK_ROOT_DIR}/plugins")
	endif()
	set(MAXON_SDK_MODULE_PATHS "${arg_MODULES_DIR}")

	message(STATUS "Discovering SDK modules in '${arg_MODULES_DIR}'.")
	file(GLOB module_paths LIST_DIRECTORIES true "${arg_MODULES_DIR}/*")
	set(discovered_module_count 0)

	foreach(module_path IN LISTS module_paths)
		if(NOT IS_DIRECTORY "${module_path}")
			continue()
		endif()
		set(cmake_file "${module_path}/project/CMakeLists.txt")
		if(NOT EXISTS "${cmake_file}")
			message(NOTICE "Module '${module_path}' has no native CMakeLists.txt. Enable MAXON_MIGRATE_LEGACY_PROJECTS to convert legacy modules or provide a valid CMakeLists.txt. Skipping module.")
			continue()
		endif()
		get_filename_component(module_name "${module_path}" NAME)
		string(SHA256 module_hash "${module_path}")
		string(SUBSTRING "${module_hash}" 0 12 module_hash)
		string(REGEX REPLACE "[^A-Za-z0-9_]" "_" binary_name "${module_name}")
		message(STATUS "Adding SDK module '${module_name}'.")
		add_subdirectory("${module_path}/project" "${CMAKE_BINARY_DIR}/modules/${binary_name}_${module_hash}")
		math(EXPR discovered_module_count "${discovered_module_count} + 1")
	endforeach()

	message(STATUS "SDK module discovery complete. Added ${discovered_module_count} module(s).")
	set(maxon_usedFrameworks "${maxon_usedFrameworks}" PARENT_SCOPE)
endfunction()

# --- Macros ---------------------------------------------------------------------------------------

# Sets up the SDK environment, including optional migration of legacy project definitions.
macro(MaxonSDKTools_Setup)
	MaxonSDKTools_SetupVisualStudioSystemProcessor()
	MaxonTargets_SetupOSIdentifierGlobals()
	MaxonCompilerHelper_SetConfigurations()
	MaxonTargets_ConfigurePythonPaths()

	foreach(output_config IN LISTS CMAKE_CONFIGURATION_TYPES)
		string(TOUPPER "${output_config}" output_config_upper)
		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${output_config_upper} "${CMAKE_BINARY_DIR}/bin/${output_config}/libs")
		set(CMAKE_PLUGINS_OUTPUT_DIRECTORY_${output_config_upper} "${CMAKE_BINARY_DIR}/bin/${output_config}/plugins")
	endforeach()

	MaxonSDKTools_MigrateLegacyProjects()
endmacro()

# Finalizes the SDK setup by creating and including all necessary framework targets.
macro(MaxonSDKTools_Finalize)
	if(NOT MAXON_FILTER_UNUSED_FRAMEWORKS)
		set(maxon_usedFrameworks ALL)
	endif()
	MaxonTargets_CreateFrameworkTargets(FRAMEWORKS ${maxon_usedFrameworks} BASE_DIRECTORIES "frameworks")
endmacro()

set(MAXONSDKTOOLS_INCLUDED ON)