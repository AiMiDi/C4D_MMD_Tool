include_guard()

include(${MAXON_BASE_SETTINGS_DIR}/warnings.clang.cmake)
include(${MAXON_BASE_SETTINGS_DIR}/warnings.gcc.cmake)
include(${MAXON_BASE_SETTINGS_DIR}/warnings.msvc.cmake)
include(${MAXON_BASE_SETTINGS_DIR}/compile_options.cmake)
include(${MAXON_BASE_SETTINGS_DIR}/link_options.cmake)
include(${MAXON_BASE_SETTINGS_DIR}/compile_definitions.cmake)

option(MAXON_ENABLE_ALL_WARNINGS "Enables all compiler's warning messages (Wall)" ON)
mark_as_advanced(MAXON_ENABLE_ALL_WARNINGS)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(ClangArgs /clang:)
	set(XClangArgs -Xclang )
else()
	set(ClangArgs "")
	set(XClangArgs "")
endif()

function(MaxonCompilerHelper_GetCompilerId)
	# TODO: The current logic does not support per-config settings.

	set(options)
	set(oneValueArgs TARGET ID FRONTEND VERSION)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if(arg_VERSION)
		set(${arg_VERSION} "${CMAKE_CXX_COMPILER_VERSION}" PARENT_SCOPE) # This may be overriden further down.
	endif()

	if(CMAKE_GENERATOR MATCHES "Visual Studio")
		get_target_property(vsPlatformToolset ${arg_TARGET} VS_PLATFORM_TOOLSET)

		if(vsPlatformToolset)
		
			if (arg_VERSION)
				# In order to add support, we need to invoke cl.exe for the currently selected toolset and parse the returned version string.
				message(FATAL_ERROR "Version query is not supported for this toolset.")
			endif()

			if(vsPlatformToolset STREQUAL "ClangCL")
				set(${arg_ID} "clang" PARENT_SCOPE)
				set(${arg_FRONTEND} "msvc" PARENT_SCOPE)
			else()
				set(${arg_ID} "msvc" PARENT_SCOPE)
				set(${arg_FRONTEND} "msvc" PARENT_SCOPE)
			endif()
			return()
		endif()
	endif()

	if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
		set(${arg_ID} "clang" PARENT_SCOPE)
		set(${arg_FRONTEND} "gnu" PARENT_SCOPE)
		return()

	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(${arg_ID} "clang" PARENT_SCOPE)
		if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
			set(${arg_FRONTEND} "msvc" PARENT_SCOPE)
		else()
			set(${arg_FRONTEND} "gnu" PARENT_SCOPE)
		endif()
		return()

	elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(${arg_ID} "msvc" PARENT_SCOPE)
		set(${arg_FRONTEND} "msvc" PARENT_SCOPE)
		return()

	elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(${arg_ID} "gnu" PARENT_SCOPE)
		set(${arg_FRONTEND} "gnu" PARENT_SCOPE)
		return()

	else()
		set(${arg_ID} "${CMAKE_CXX_COMPILER_ID}" PARENT_SCOPE)
		set(${arg_FRONTEND} "${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}" PARENT_SCOPE)
		return()

	endif()
endfunction()


function(MaxonCompilerHelper_SetMutedWarningsFlags)
	set(options)
	set(oneValueArgs Target Visibility)
	set(multiValueArgs Warnings)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	if (compilerId STREQUAL "clang")
		foreach(wno ${arg_Warnings})
			if(CMAKE_GENERATOR STREQUAL "Xcode")
				target_compile_options(${arg_Target} ${arg_Visibility} $<$<COMPILE_LANGUAGE:CXX>:${wno}>)
				target_compile_options(${arg_Target} ${arg_Visibility} $<$<COMPILE_LANGUAGE:C>:${wno}>)
				# Xcode has a separate list of default settings that are added at the beginning of the compile call.
				# To avoid confusion about why there are conflicting arguments passed to the compiler, we can align the flags here
				# by setting the Xcode-specific attributes for these arguments. This will still lead to duplicate arguments passed to
				# the compiler, but at least they will match.
				# The list of Xcode arguments can be found here: https://gist.github.com/tkersey/39b4fe69e14b859889ffadccb009e397
				if(wno STREQUAL "-Wno-switch")
					set_target_properties(${arg_Target} PROPERTIES XCODE_ATTRIBUTE_GCC_WARN_CHECK_SWITCH_STATEMENTS NO)
				endif()
				# We are hard coding this here, because Xcode automatically sets this to yes, and I am not sure, if it is needed, but it certainly spams the build output.
				set_target_properties(${arg_Target} PROPERTIES XCODE_ATTRIBUTE_GCC_WARN_ABOUT_DEPRECATED_FUNCTIONS NO)
			
			else()
				# currently only the windows clang version has the additional warning settings to allow us to apply the general warning settings to C files as well.
				target_compile_options(${arg_Target} BEFORE ${arg_Visibility} ${XClangArgs} $<$<COMPILE_LANGUAGE:CXX,C>:${wno}>)
			endif()
		endforeach()
	elseif(compilerId STREQUAL "msvc")
		foreach(wno ${arg_Warnings})
			target_compile_options(${arg_Target} BEFORE ${arg_Visibility} ${wno})
		endforeach()

	elseif(compilerId STREQUAL "gnu")
		list(APPEND all_Warnings ${arg_Warnings} ${MUTED_WARNINGS_GCC_C})
		foreach(wno ${all_Warnings})
			target_compile_options(${arg_Target} BEFORE ${arg_Visibility} $<$<COMPILE_LANGUAGE:C>:${wno}>)
		endforeach()
		set(all_Warnings "")
		list(APPEND all_Warnings ${arg_Warnings} ${MUTED_WARNINGS_GCC_CXX})
		foreach(wno ${all_Warnings})
			target_compile_options(${arg_Target} BEFORE ${arg_Visibility} $<$<COMPILE_LANGUAGE:CXX>:${wno}>)
		endforeach()
	else()
		message(ERROR " Unsupported compiler id: ${compilerId}")
	endif()
endfunction()


# For the given target this will deactivate the "standard" list of warnings
# Standard here means the warnings which the maxon code disables plus more for the kernel code
# This makes the compile option public! This is because it is assumed that the warnings can be generated in a header
function(MaxonCompilerHelper_SetMaxonDefaultWarnings target visibility)
	MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	if (compilerId STREQUAL "clang")
		MaxonCompilerHelper_ComposeClangWarningStrings(clangWarningFlagsCombined)
		set(WARNINGS_CLANG "${WARNINGS_AS_ERRORS_CLANG_BASE};${clangWarningFlagsCombined}")
		MaxonCompilerHelper_SetMutedWarningsFlags(Target ${target} Visibility ${visibility} Warnings ${WARNINGS_CLANG}) 
	elseif(compilerId STREQUAL "msvc")
		MaxonCompilerHelper_SetMutedWarningsFlags(Target ${target} Visibility ${visibility} Warnings ${MUTED_WARNINGS_MSVC})
	elseif(compilerId STREQUAL "gnu")
		MaxonCompilerHelper_SetMutedWarningsFlags(Target ${target} Visibility ${visibility} Warnings ${MUTED_WARNINGS_GCC_C_CXX})
	else()
		message(ERROR " Unsupported compiler id: ${compilerId}")
	endif()

	if(MAXON_ENABLE_ALL_WARNINGS)
		if (compilerId STREQUAL "msvc")
			target_compile_options(${target} BEFORE ${visibility} /Wall) # enable all warnings that are disabled by default.
		else()
			# BEFORE switch is necessary here, to make sure that the individual warning switches are supplied afterwards and are not overridden by this.
			target_compile_options(${target} BEFORE ${visibility} -Wall)
			set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE ON)
		endif()
	endif()

endfunction()

function(MaxonCompilerHelper_SetISA target visibility)

MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	if (compilerId STREQUAL "msvc")
		target_compile_options(${target} ${visibility} ${MAXON_COMPILE_OPTIONS_WINDOWS_MSVC_X64_ISA})
	elseif(compilerId STREQUAL "clang" AND compilerFrontend STREQUAL "msvc")
		# For ClangCL the support is a bit consistent at the moment.
		target_compile_options(${target} ${visibility} ${MAXON_COMPILE_OPTIONS_WINDOWS_MSVC_X64_ISA})   # This is only eye-candy for the IDE project properties.
		target_compile_options(${target} ${visibility} ${MAXON_COMPILE_OPTIONS_WINDOWS_CLANGCL_X64_ISA} -maes) # This is needed for the compiler.
	else()
		# Xcode does not support setting different compile options for different languages on a target basis.
		if(CMAKE_GENERATOR MATCHES "Xcode")
			if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
				target_compile_options(${target} ${visibility} ${MAXON_COMPILE_OPTIONS_LINUX_X64_ISA})
			elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
				target_compile_options(${target} ${visibility} ${MAXON_COMPILE_OPTIONS_WINDOWS_CLANGCL_X64_ISA})
			elseif(APPLE)
				target_compile_options(${target} ${visibility} "-Xarch_x86_64 ${MAXON_COMPILE_OPTIONS_MACOS_X64_ISA}")
			else()
				message(ERROR " Unsupported platform: ${CMAKE_SYSTEM_NAME}")
			endif()
		else()
			# Other generators support setting different compile options per file via generators on a per target basis.
			if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
				target_compile_options(${target} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${MAXON_COMPILE_OPTIONS_LINUX_X64_ISA}>)
			elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
				target_compile_options(${target} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${MAXON_COMPILE_OPTIONS_WINDOWS_CLANGCL_X64_ISA}>)
			elseif(APPLE)
				target_compile_options(${target} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:"-Xarch_x86_64 ${MAXON_COMPILE_OPTIONS_MACOS_X64_ISA}">)
			else()
				message(ERROR " Unsupported platform: ${CMAKE_SYSTEM_NAME}")
			endif()
		endif()
	endif()
endfunction()


function(MaxonCompilerHelper_SetAdditionalCompileOptions target cppOptionsVar cOptionsVar)
	set(cppOptions "${${cppOptionsVar}}")
	set(cOptions "${${cOptionsVar}}")
	set(mmOptions ${MAXON_COMPILE_OPTIONS_OBJECTIVE_C})
	
	# Visual studio and Xcode do not support setting different compile options for different languages on a target basis.
	# We need to iterate over the sources and set the flags per source.
	if(CMAKE_GENERATOR MATCHES "Visual Studio" OR CMAKE_GENERATOR MATCHES "Xcode")
		set(targetSources "")
		get_target_property(targetSources ${target} SOURCES)

		set(cFiles "")
		set(cppFiles "")
		set(mmFiles "")
		foreach(file ${targetSources})
			cmake_path(GET file EXTENSION LAST_ONLY fileExtension)
			if(fileExtension STREQUAL ".c")
				list(APPEND cFiles ${file})
			elseif(fileExtension STREQUAL ".mm" AND APPLE)
				list(APPEND mmFiles ${file})
			elseif(fileExtension STREQUAL ".cpp")
				list(APPEND cppFiles ${file})
			endif()
		endforeach()

		if(cFiles STREQUAL "" AND mmFiles STREQUAL "")
			# If there are no c and mm files in the target, we can revert back to the per-target setting of cxx compile flags.
			target_compile_options(${target} PRIVATE ${cppOptions})
		elseif(mmFiles STREQUAL "" AND "${cOptions}" STREQUAL "${cppOptions}")
			# If there are no mm files (on Apple) in the target and C and CPP options match, we can revert back to the per-target setting of cxx compile flags.
			target_compile_options(${target} PRIVATE ${cppOptions})
		else()
			set_property(SOURCE ${cFiles} APPEND PROPERTY COMPILE_OPTIONS ${cOptions})
			set_property(SOURCE ${mmFiles} APPEND PROPERTY COMPILE_OPTIONS ${mmOptions})
			set_property(SOURCE ${cppFiles} APPEND PROPERTY COMPILE_OPTIONS ${cppOptions})
		endif()
	else()
		# Other generators support setting different compile options per file via generators on a per target basis.
		target_compile_options(${target} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${cppOptions}> $<$<COMPILE_LANGUAGE:C>:${cOptions}> )
	endif()
endfunction()


function(MaxonCompilerHelper_SetBaseLinkOptions target visibility)
	MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	if(compilerFrontend STREQUAL "msvc")
		target_link_options(${target} ${visibility} ${MAXON_LINK_OPTIONS_CLANGCL_MSVC} $<IF:$<CONFIG:Debug>,${MAXON_LINK_OPTIONS_CLANGCL_MSVC_DEBUG},${MAXON_LINK_OPTIONS_CLANGCL_MSVC_RELEASE}>)
	endif()

	if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
		target_link_options(${target} ${visibility} ${MAXON_LINK_OPTIONS_LINUX_CLANG_GCC})
	endif()

endfunction()


function(MaxonCompilerHelper_SetAdditionalLinkOptions target visibility configuration options)
	target_link_options(${target} ${visibility} $<$<CONFIG:${configuration}>:${options}>)
endfunction()

# release optimizations, debug info etc
function(MaxonCompilerHelper_SetBaseCompileOptions target visibility)

	MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	set(shared_options "")
	set(debug_options "")
	set(release_options "")

	# MSVC will evaluate to true if either the MSVC compiler is used or clang-cl
	# this is independent of whether msbuild or ninja is used
	if(compilerFrontend STREQUAL "msvc")
		if(MAXON_DEBUG_INFO_IN_RELEASE)
			target_link_options(${target} PRIVATE $<IF:$<CONFIG:Debug>,/DEBUG,/DEBUG:FULL>)
		endif()
		set(debugFormat ${MAXON_MSVC_DEBUG_FORMAT})
		set_property(TARGET ${target} PROPERTY MSVC_DEBUG_INFORMATION_FORMAT ${debugFormat})

		if(compilerId STREQUAL "clang")
			list(APPEND shared_options ${MAXON_COMPILE_OPTIONS_CLANGCL})
		endif()

		list(APPEND shared_options ${MAXON_COMPILE_OPTIONS_CLANGCL_MSVC})
		list(APPEND debug_options ${MAXON_COMPILE_OPTIONS_CLANGCL_MSVC_DEBUG})
		list(APPEND release_options ${MAXON_COMPILE_OPTIONS_CLANGCL_MSVC_RELEASE})
		
		#set_property(TARGET ${target} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
	else()
		if(MAXON_DEBUG_INFO_IN_RELEASE)
			target_link_options(${target} PRIVATE $<$<CONFIG:Release>:-g>)
		endif()
		set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE ON)
		list(APPEND debug_options ${MAXON_COMPILE_OPTIONS_CLANG_APPLECLANG_GCC_DEBUG})
	endif()

	if(compilerId STREQUAL "msvc")
		list(APPEND shared_options ${MAXON_COMPILE_OPTIONS_MSVC})
		list(APPEND release_options ${MAXON_COMPILE_OPTIONS_MSVC_RELEASE})
	elseif (compilerId STREQUAL "clang" OR compilerId STREQUAL "gnu")
		# When applying clang parameters to any clang compiler we need to make sure that the parameters are passed in with the
		# argument that allows passing non-MSVC syntax arguments to ClangCL. We append that token here.
		list(TRANSFORM MAXON_COMPILE_OPTIONS_ANYCLANG_GCC PREPEND "${ClangArgs}" OUTPUT_VARIABLE nonMSVCOpts)
		list(TRANSFORM MAXON_COMPILE_OPTIONS_ANYCLANG_GCC_RELEASE PREPEND "${ClangArgs}" OUTPUT_VARIABLE nonMSVCOptsRelease)
		list(APPEND shared_options ${nonMSVCOpts})
		list(APPEND release_options ${nonMSVCOptsRelease})
	else()
		message(ERROR " Unsupported compiler id: ${compilerId}")
	endif()

	if(compilerId STREQUAL "gnu")
		list(APPEND shared_options ${MAXON_COMPILE_OPTIONS_GCC})
	endif()

	target_compile_options(${target} ${visibility} ${shared_options} "$<$<CONFIG:Debug>:${debug_options}>")
	target_compile_options(${target} ${visibility} ${shared_options} "$<$<CONFIG:Release>:${release_options}>")
	
	set_target_properties(${target} PROPERTIES CXX_VISIBILITY_PRESET hidden)

endfunction()

function(MaxonCompilerHelper_SetCompileDefinitions target visibility)

	target_compile_definitions(${target} ${visibility} ${MAXON_COMPILE_DEFINITIONS} $<IF:$<CONFIG:Debug>, ${MAXON_COMPILE_DEFINITIONS_DEBUG}, ${MAXON_COMPILE_DEFINITIONS_RELEASE}>)
	# unclear about the visibility of these
	if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
		target_compile_definitions(${target} ${visibility} ${MAXON_COMPILE_DEFINITIONS_WIN} $<IF:$<CONFIG:Debug>, ${MAXON_COMPILE_DEFINITIONS_WIN_DEBUG}, ${MAXON_COMPILE_DEFINITIONS_WIN_RELEASE}>)
	endif()

	if (MAXON_ENABLE_STANDALONE)
		target_compile_definitions(${target} ${visibility} __STANDALONEAPP)
	endif()
	target_compile_definitions(${target} ${visibility} MAXON_TARGET_${g_maxonTargetOS})

	MaxonCompilerHelper_SetBaseCompileOptions(${target} ${visibility})
endfunction()


function(MaxonCompilerHelper_SetCompileOptionsRTTI target visibility enabled)

MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	if (enabled)
		if(compilerFrontend STREQUAL "msvc")
			target_compile_options(${target} ${visibility} /GR) 
		else()
			target_compile_options(${target} ${visibility} $<$<COMPILE_LANGUAGE:CXX>:-frtti>)
		endif()
	else()
		if(compilerFrontend STREQUAL "msvc")
			target_compile_options(${target} ${visibility} /GR-)
		else()
			target_compile_options(${target} ${visibility} $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
		endif()
	endif()
endfunction()

function(MaxonCompilerHelper_SetCompileOptionsExceptions target visibility enabled)

MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend)

	# Unfortunately, disabling exceptions for MSVC is non-trivial.
	# https://gitlab.kitware.com/cmake/cmake/-/issues/20610
	if (enabled)
		if(compilerFrontend STREQUAL "msvc")
			target_compile_definitions(${target} ${visibility} _HAS_EXCEPTIONS=1)
			target_compile_options(${target} ${visibility} /EHsc)
		else()
			target_compile_options(${target} ${visibility} $<$<COMPILE_LANGUAGE:CXX>:-fexceptions>)
		endif()
	else()
		if(compilerFrontend STREQUAL "msvc")
			target_compile_definitions(${target} ${visibility} _HAS_EXCEPTIONS=0)
			target_compile_options(${target} ${visibility} /EHs-c-)
		else()
			target_compile_options(${target} ${visibility} $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)
		endif()
	endif()
endfunction()


# This is a macro to affect the PARENT_SCOPE of the caller.
macro(MaxonCompilerHelper_SetConfigurations)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "We support Release and Debug configurations." FORCE)
	mark_as_advanced(CMAKE_CONFIGURATION_TYPES)

	# We start from fresh without any default flags.
	# Important is the disabling of RTTI and exceptions.
	# If you prefer a more selective approach, have a look at https://chromium.googlesource.com/external/github.com/google/crc32c/+/refs/tags/1.0.5/CMakeLists.txt
	set(CMAKE_CXX_FLAGS "")
	foreach(config ${CMAKE_CONFIGURATION_TYPES})
		string(TOUPPER ${config} config)
		set(CMAKE_CXX_FLAGS_${config} "")
	endforeach(config)
	
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
	set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")
	
endmacro()


function(MaxonCompilerHelper_ComposeClangWarningStrings clangWarningStringsCombined)

	MaxonCompilerHelper_GetCompilerId(TARGET ${target} ID compilerId FRONTEND compilerFrontend VERSION compilerVersion)

	if (NOT compilerVersion)
		message(FATAL_ERROR "Could not determine Clang compiler version.")
	endif()

	set(MUTED_WARNINGS_CLANG "${MUTED_WARNINGS_CLANG_BASE}")

	if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 11.0)
		list(APPEND MUTED_WARNINGS_CLANG ${MUTED_WARNINGS_CLANG_11})
	endif()
	if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12.0)
		list(APPEND MUTED_WARNINGS_CLANG ${MUTED_WARNINGS_CLANG_12})
	endif()
	if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 13.0)
		list(APPEND MUTED_WARNINGS_CLANG ${MUTED_WARNINGS_CLANG_13})
	endif()
	if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 16.0)
		list(APPEND MUTED_WARNINGS_CLANG ${MUTED_WARNINGS_CLANG_16})
	endif()
	if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 17.0)
		list(APPEND MUTED_WARNINGS_CLANG ${MUTED_WARNINGS_CLANG_17})
	endif()

	set(${clangWarningStringsCombined} ${MUTED_WARNINGS_CLANG} PARENT_SCOPE)
endfunction()

function (MaxonCompilerHelper_LinkFrameworks)
	set(options)
	set(oneValueArgs TARGET)
	set(multiValueArgs DEPENDENCIES)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	MaxonCompilerHelper_GetCompilerId(TARGET ${arg_TARGET} ID compilerId FRONTEND compilerFrontend)

	if(compilerId STREQUAL "gnu" AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
		target_link_libraries(${arg_TARGET} PUBLIC "$<LINK_GROUP:RESCAN,${arg_DEPENDENCIES}>")
	else()
		target_link_libraries(${arg_TARGET} PUBLIC ${arg_DEPENDENCIES})
	endif()

endfunction()


function(MaxonCompilerHelper_EnableParallelBuildsForTarget targetName)
	if (CMAKE_GENERATOR MATCHES "Visual Studio")
		set_target_properties(${targetName} PROPERTIES VS_GLOBAL_UseMultiToolTask true)
	endif()
endfunction()
