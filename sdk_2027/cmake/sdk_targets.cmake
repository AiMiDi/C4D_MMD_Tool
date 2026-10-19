if(MAXONTARGETS_INCLUDED)
	return()
endif()

function (MaxonTargets_HasGeneratorPrebuildEvents)
	set(options)
	set(oneValueArgs Value)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	set (value FALSE)
	if (${CMAKE_GENERATOR} MATCHES "Ninja")
		set(value FALSE)
	elseif(${CMAKE_GENERATOR} MATCHES "Visual Studio")
		set(value TRUE)
	elseif(${CMAKE_GENERATOR} MATCHES "Xcode")
		set(value TRUE)
	else()
	endif()

	# Return Values.
	set(${arg_Value} ${value} PARENT_SCOPE)
endfunction()


function (MaxonTargets_GetVersionAPIBase)
	set(options)
	set(oneValueArgs FrameworksRoot Type Version)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	set (Version "Unknown")
	string (TOUPPER "${arg_Type}" Type)
	if (Type STREQUAL "MAXON_API_ABI_VERSION")
		if (EXISTS ${arg_FrameworksRoot}/core.framework/source/maxon/apibase_version.h)
			file(READ ${arg_FrameworksRoot}/core.framework/source/maxon/apibase_version.h apibaseContents)
			string(REGEX MATCH ".*#define[ \t]+MAXON_API_ABI_VERSION[ \t]+([0-9]+).*" _ ${apibaseContents}) # _ would contain the entire file in case if mismatch
			if (CMAKE_MATCH_1) # this only exists for a match
				set (Version ${CMAKE_MATCH_1})
			endif()
		endif()
	elseif (Type STREQUAL "MAXON_CORE_FRAMEWORK_VERSION")
		if (EXISTS ${arg_FrameworksRoot}/core.framework/source/maxon/apibase_version.h)
			file(READ ${arg_FrameworksRoot}/core.framework/source/maxon/apibase_version.h apibaseContents)
			string(REGEX MATCH ".*#define[ \t]+MAXON_CORE_FRAMEWORK_VERSION[ \t]+([0-9]+).*" _ ${apibaseContents}) # _ would contain the entire file in case if mismatch
			if (CMAKE_MATCH_1) # this only exists for a match
				set (Version ${CMAKE_MATCH_1})
			endif()
		endif()
	elseif (Type STREQUAL "API_VERSION")
		if (EXISTS ${arg_FrameworksRoot}/cinema.framework/source/operatingsystem.h)
			file(READ ${arg_FrameworksRoot}/cinema.framework/source/operatingsystem.h apibaseContents)
			string(REGEX MATCH ".*#define[ \t]+API_VERSION[ \t]+([0-9]+).*" _ ${apibaseContents}) # _ would contain the entire file in case if mismatch
			if (CMAKE_MATCH_1) # this only exists for a match
				set (Version ${CMAKE_MATCH_1})
			endif()
		endif()
	endif()

	# Return Values.
	set(${arg_Version} ${Version} PARENT_SCOPE)
endfunction()


function (MaxonTargets_CreateDirectoryLink)
	set(options)
	set(oneValueArgs PATH TARGET)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if(NOT arg_PATH OR NOT arg_TARGET)
		message(FATAL_ERROR "Invalid parameters.")
	endif()

	string(REGEX REPLACE "/$" "" arg_TARGET "${arg_TARGET}") # Remove trailing slash, e.g. from 'CMAKE_RUNTIME_OUTPUT_DIRECTORY'

	# We test whether the existing symlink points to the correct location already.
	if(EXISTS ${arg_PATH})
		if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
			# The following CMake issue prohibits us from simply checking whether the symlink already points to the correct location.
			# https://gitlab.kitware.com/cmake/cmake/-/issues/17206
					
			# It's actually not even implemented! https://gitlab.kitware.com/cmake/cmake/-/issues/17206
			#file(READ_SYMLINK ${arg_PATH} oldTargetLink)
			
			# This command does not resolve the symlink on Windows 10, despite the 'REALPATH' argument.
			#get_filename_component(oldTargetReal ${arg_PATH} REALPATH ABSOLUTE)

			execute_process(COMMAND powershell Get-Item "${arg_PATH}" | Select-Object -ExpandProperty Target OUTPUT_VARIABLE oldTarget)
			string(REPLACE "\n" "" oldTarget "${oldTarget}") # Remove the line ending
			file(TO_CMAKE_PATH "${oldTarget}" oldTarget) # Replace \ with /

			if (NOT ${oldTarget} STREQUAL ${arg_TARGET})
				# We remove the old symlink, because it points to something else.
				file(REMOVE ${arg_PATH})
			endif()
		else()
			# TODO: We should test whether this does the job on Linux and macOS!
			#file(READ_SYMLINK ${arg_PATH} oldTarget)

			get_filename_component(oldTarget ${arg_PATH} REALPATH ABSOLUTE)

			if (NOT ${oldTarget} STREQUAL ${arg_TARGET})
				# We remove the old symlink, because it points to something else.
				file(REMOVE ${arg_PATH})
			endif()
		endif()
	elseif(IS_SYMLINK ${arg_PATH})
		# We are dealing with a dead symlink pointing to a non-existing path. Let's delete it.
		file(REMOVE ${arg_PATH})
	endif()

	# We are done!
	if(EXISTS ${arg_PATH})
				return()
	endif()

	get_filename_component(arg_PATH ${arg_PATH} ABSOLUTE)
	get_filename_component(arg_TARGET ${arg_TARGET} ABSOLUTE)
	file(MAKE_DIRECTORY "${arg_TARGET}")
	get_filename_component(arg_PATH_DIR ${arg_PATH} DIRECTORY)
	file(MAKE_DIRECTORY "${arg_PATH_DIR}")

	get_filename_component(arg_PATH_DIR ${arg_PATH} DIRECTORY)

	if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
		# We cannot just call CREATE_LINK since this will require adminstrative rights. We can avoid this by using mklink /J .
		file(TO_NATIVE_PATH "${arg_PATH}" native_PATH)
		file(TO_NATIVE_PATH "${arg_TARGET}" native_TARGET)
		string(REPLACE "\\" "\\\\" native_PATH "${native_PATH}")
		string(REPLACE "\\" "\\\\" native_TARGET "${native_TARGET}")
		execute_process(COMMAND cmd /c mklink /J "${native_PATH}" "${native_TARGET}")
	else()
				file(CREATE_LINK "${arg_TARGET}" "${arg_PATH}" SYMBOLIC)
	endif()
endfunction()


function (MaxonTargets_CreateFile)
	set(options)
	set(oneValueArgs PATH)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if (NOT arg_PATH)
		message(FATAL_ERROR "Empty Path")
	endif()

	if (EXISTS ${arg_PATH})
		return() # we must not touch an existing file. this would invalidate its timestamp.
	endif()

	if(arg_PATH)
		get_filename_component(FILEPATH_DIR ${arg_PATH} DIRECTORY)
		file(MAKE_DIRECTORY "${FILEPATH_DIR}")
		file (TOUCH "${arg_PATH}")
	endif()
endfunction()


function (MaxonTargets_CreateFileList)
	set(options)
	set(oneValueArgs BaseDirectory)
	set(multiValueArgs SearchDirectories FileList)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	foreach(relative_folder IN LISTS arg_SearchDirectories)
		file(GLOB_RECURSE GLOB_SOURCE_FILES FOLLOW_SYMLINKS "${arg_BaseDirectory}/${relative_folder}/*")
		foreach(abs_source_file IN LISTS GLOB_SOURCE_FILES)
			file(RELATIVE_PATH rel_source_file ${arg_BaseDirectory} ${abs_source_file})
			list(APPEND collectedFile ${rel_source_file})
		endforeach()

	endforeach()

	list(SORT collectedFile)

	# Return Values.
	set(${arg_FileList} ${collectedFile} PARENT_SCOPE)
endfunction()


function (MaxonTargets_SaveFileList)
	set(options SaveAlways)
	set(oneValueArgs File ErrorOnWrite)
	set(multiValueArgs FileList)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	list(JOIN arg_FileList "\n" fileListString)

	if (arg_SaveAlways)
		set(needsUpdate TRUE)
	else()
		# We load the current file and compare its content with the new filelist.
		MaxonTargets_CreateFile(PATH ${arg_File}) # We force the creation of the folders.
		file(READ ${arg_File} savedFilelistString)
		string(COMPARE NOTEQUAL "${savedFilelistString}" "${fileListString}" differ)

		if (differ)
			set(needsUpdate TRUE)
		endif()
	endif()

	if (needsUpdate)
		message(STATUS "Saving Maxon Generated File List to '${arg_File}'.")
		file(WRITE ${arg_File} "${fileListString}")
		if (arg_ErrorOnWrite)
			message(FATAL_ERROR "File List has changed, rerun build to rerun CMake!")
		endif()
	endif()
endfunction()


function (MaxonTargets_UpdateFileList)
	set(options)
	set(oneValueArgs File BaseDirectory ErrorOnWrite)
	set(multiValueArgs SearchDirectories)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if(NOT arg_File OR NOT arg_BaseDirectory OR NOT arg_SearchDirectories)
		message("arg_File=${arg_File}")
		message("arg_BaseDirectory=${arg_BaseDirectory}")
		message("arg_SearchDirectories=${arg_SearchDirectories}")
		message(FATAL_ERROR "Invalid parameters.")
	endif()

	MaxonTargets_CreateFileList(BaseDirectory ${arg_BaseDirectory} SearchDirectories ${arg_SearchDirectories} FileList collectedFiles)
	MaxonTargets_SaveFileList(File ${arg_File} FileList ${collectedFiles} ErrorOnWrite ${arg_ErrorOnWrite})
endfunction()


function (MaxonTargets_LoadFileList)
	set(options)
	set(oneValueArgs File)
	set(multiValueArgs FileList)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	file(READ ${arg_File} fileListString)
	if (fileListString)
		string(REPLACE "\n" ";" fileList ${fileListString})
	endif()

	# Return Values.
	set(${arg_FileList} ${fileList} PARENT_SCOPE)

endfunction()

function (MaxonTargets_CollectIncludeDirectories)
	set(options)
	set(oneValueArgs RootDir)
	set(multiValueArgs SourceFilesRelative SearchDirectories IncludeDirectories)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
	
	# We collect the unique list of directories containing source files.
	foreach(sourceFileRelative IN LISTS arg_SourceFilesRelative)
		# We must filter with the relative path to avoid false positives.
		cmake_path(ABSOLUTE_PATH sourceFileRelative BASE_DIRECTORY "${arg_RootDir}" NORMALIZE OUTPUT_VARIABLE sourceFileAbsolute)
		cmake_path(GET sourceFileAbsolute PARENT_PATH sourceFileDirectory)
		list(APPEND sourceDirectories ${sourceFileDirectory})
	endforeach()
	list(REMOVE_DUPLICATES sourceDirectories)

	# We collect all include directories, which are of three types:
	# 1. The source file directories,
	# 2. The search directories,
	# 3. The directories 'between' search and source file directories.
	
	foreach(sourceDirectory IN LISTS sourceDirectories)
		# 1. The source file directories.
		list(APPEND includeDirectories ${sourceDirectory})
		foreach(searchDirectoryRelative IN LISTS arg_SearchDirectories)
			cmake_path(ABSOLUTE_PATH searchDirectoryRelative BASE_DIRECTORY "${arg_RootDir}" NORMALIZE OUTPUT_VARIABLE searchDirectoryAbsolute)
			# 2. The search directories.
			list(APPEND includeDirectories ${searchDirectoryAbsolute})
			# 3. We collect the directories between search and source directory.
			cmake_path(RELATIVE_PATH sourceDirectory BASE_DIRECTORY "${searchDirectoryAbsolute}" OUTPUT_VARIABLE sourceRelativeDirectory)
			if(sourceRelativeDirectory MATCHES "^\\.\\./") # starts with "../" and is no direct sub directory.
				continue()
			endif()

			while(sourceRelativeDirectory)
				cmake_path(ABSOLUTE_PATH sourceRelativeDirectory BASE_DIRECTORY "${searchDirectoryAbsolute}" NORMALIZE OUTPUT_VARIABLE intermediateDir)
				list(APPEND includeDirectories ${intermediateDir})
				cmake_path(GET sourceRelativeDirectory PARENT_PATH sourceRelativeDirectory)
			endwhile()
		endforeach()
	endforeach()
	list(REMOVE_DUPLICATES includeDirectories)
	list(SORT includeDirectories)
	
	# Return Values.
	set(${arg_IncludeDirectories} ${includeDirectories} PARENT_SCOPE)
endfunction()


function (MaxonTargets_FilterFile)
	set(options)
	set(oneValueArgs File Result)
	set(multiValueArgs Filters)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
 
	# We hardcode a filter for _unity*.cpp files. 
	string(REGEX MATCH "_unity[0-9]+\.cpp$" isUnityFile "${arg_File}") # starts with "../" and is no direct sub directory.
	if (isUnityFile)
		set(${arg_Result} true PARENT_SCOPE)
		return()
	endif()

	if(g_maxonTargetOS STREQUAL "WINDOWS" OR g_maxonTargetOS STREQUAL "LINUX")
		if(g_maxonTargetOS STREQUAL "WINDOWS")    
			set(whitelist ".cpp" ".hxx" ".h" ".c" ".manifest" ".rc")
		elseif(g_maxonTargetOS STREQUAL "LINUX")
			set(whitelist ".cpp" ".hxx" ".h" ".c")
		endif()

		cmake_path(GET arg_File EXTENSION LAST_ONLY fileExtension)

		if("${fileExtension}" STREQUAL "")
			set(${arg_Result} true PARENT_SCOPE)
			return()
		endif()

		list(FIND whitelist ${fileExtension} extensionIndex)
		if (extensionIndex EQUAL -1)
			set(${arg_Result} true PARENT_SCOPE)
			return()
		endif()
	endif()

	set(fileForFiltering "/${arg_File}")

	foreach(filter IN LISTS arg_Filters)
		string(FIND ${fileForFiltering} ${filter} filter_find)
		if (NOT filter_find EQUAL -1)
			#Return Values.
			set(${arg_Result} true PARENT_SCOPE) # yes it was found hence set return value 'isFileFiltered' to true
			#message(INFO " YES: ${arg_File}")
			return()
		else()
			#message(INFO " NO: ${arg_File}")
		endif()
	endforeach()

	# Return Values.
	set(${arg_Result} false PARENT_SCOPE)
	
endfunction()

function (MaxonTargets_IgnoreFile)
	set(options print)
	set(oneValueArgs File Result)
	set(multiValueArgs Ignores)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
	
	
	# HARD-CODED RULE
	# In OSX there are .DS_Store files, that should not become part of the solution.
	# We filter them here.
	cmake_path(GET arg_File FILENAME filename)

	if (filename STREQUAL ".DS_Store")
		set(${arg_Result} true PARENT_SCOPE)
		return()
	endif()
	
	set(fileForFiltering "/${arg_File}")
	if(${arg_print})
		message(INFO " ${fileForFiltering}")
	endif(${arg_print})
	
	foreach(filter IN LISTS arg_Ignores)
		string(FIND ${fileForFiltering} ${filter} filter_find)
		if (NOT filter_find EQUAL -1)
			#Return Values.
			set(${arg_Result} true PARENT_SCOPE)
			return()
		endif()
	endforeach()

	# Return Values.
	set(${arg_Result} false PARENT_SCOPE)
	
endfunction()

function (MaxonTargets_FilterFiles)
	set(options print)
	set(oneValueArgs)
	set(multiValueArgs Files Filters Ignores FilesAllowed FilesDenied)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
	
	foreach(file IN LISTS arg_Files)
		if(${arg_print})
			message(INFO " tested File: ${file}")
			MaxonTargets_IgnoreFile(print File ${file} Ignores ${arg_Ignores} Result isFileIgnored)
		else()
			MaxonTargets_IgnoreFile(File ${file} Ignores ${arg_Ignores} Result isFileIgnored)
		endif()

		
		if (isFileIgnored)
			if(${arg_print})
				message(INFO " ignored File: ${file}")
			endif()
			
			continue()
		endif()
	
		MaxonTargets_FilterFile(File ${file} Filters ${arg_Filters} Result isFileFiltered)
		
		if (NOT isFileFiltered)
			list(APPEND allowedFiles ${file})
		else()
			list(APPEND deniedFiles ${file})
			if(${arg_print})
				message(INFO " denied File: ${file}")
			endif()
		endif()
	endforeach()
	
	# Return Values.
	set(${arg_FilesAllowed} ${allowedFiles} PARENT_SCOPE)
	set(${arg_FilesDenied} ${deniedFiles} PARENT_SCOPE)

endfunction()

function (MaxonTargets_MakeRelativePathsAbsolute)
	set(options)
	set(oneValueArgs BaseDirectory)
	set(multiValueArgs RelativeFiles AbsoluteFiles)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
	
	
	if(NOT arg_BaseDirectory)
		message(FATAL_ERROR "Invalid base directory.")
	endif()
	
	foreach(relativeFile IN LISTS arg_RelativeFiles)
		cmake_path(IS_RELATIVE relativeFile isRelative)
		if(isRelative)
			get_filename_component(absoluteFile ${arg_BaseDirectory}/${relativeFile} ABSOLUTE)
			list(APPEND absoluteFiles ${absoluteFile})
		else()
			list(APPEND absoluteFiles ${relativeFile})
		endif()
	endforeach()
	
	# Return Values.
	set(${arg_AbsoluteFiles} ${absoluteFiles} PARENT_SCOPE)
	
endfunction()

function(MaxonTargets_SetupPrebuildEvents)
	set(options)
	set(oneValueArgs TargetName TargetFolderName)
	set(multiValueArgs PrebuildEvents.DEBUG PrebuildEvents.RELEASE)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	set(additionalPrebuildSuffix 0)
	set(prebuildStampIndex 0)
	foreach(prebuild.DEBUG prebuild.RELEASE IN ZIP_LISTS arg_PrebuildEvents.DEBUG arg_PrebuildEvents.RELEASE)
		MATH(EXPR additionalPrebuildSuffix "${additionalPrebuildSuffix}+1")
		foreach(config IN ITEMS DEBUG RELEASE)
			set(targetCommand.${config} "")
			set(script.${config} "")
			set(params.${config} "")
			# Replace any gaps between parts of the command line args with commas. These spaces might have been introduced when splitting the prebuild events command over multiple lines with line continuations.
			string(REGEX REPLACE " +" ";" prebuild.${config} "${prebuild.${config}}")
			string(REPLACE "\\\\;" "\\\\ " prebuild.${config} "${prebuild.${config}}")
			#message(INFO "prebuildEventsSplit: ${prebuild.${config}}")

			foreach(element ${prebuild.${config}})
				if(element MATCHES "call") # The call is part of the updateprojects command that we don't need here.
					continue()
				elseif((element MATCHES "\\.exe" OR NOT g_maxonTargetOS STREQUAL WINDOWS) AND "${targetCommand.${config}}" STREQUAL "") # If we have not seen a command executable yet
					set(targetCommand.${config} ${element})
				elseif(element MATCHES "\\.py" AND "${script.${config}}" STREQUAL "" AND "${params.${config}}" STREQUAL "") # if we have not seen a python script yet.
					set(script.${config} ${element})
				else()
					set(params.${config} "${params.${config}}${element} ") # Otherwise concat the current element to the command parameter string.
					if(targetCommand.${config} STREQUAL "mkdir")
						#message("Parammm: ${params.${config}}")
					endif()
				endif()
			endforeach()

			string(STRIP "${params.${config}}" params.${config})
			string(REPLACE "#" "\\;" params.${config} "${params.${config}}") # Now that we have iterated over the tokens, we can replace the hash symbol with semicolons again.
			string(REPLACE " " ";" params.${config} "${params.${config}}") # we had previously turned semi-colons into token dividers, which were then turned into spaces during appending. We transform them back now.
			string(REPLACE "\\\\;" " " params.${config} "${params.${config}}") # we had previously turned semi-colons into token dividers, which were then turned into spaces during appending. We transform them back now.
			string(REPLACE "\\\"" "\"" params.${config} "${params.${config}}") # we had previously turned semi-colons into token dividers, which were then turned into spaces during appending. We transform them back now.
			#message("Parammmfinal: ${params.${config}}")
		endforeach()

		MaxonTargets_HasGeneratorPrebuildEvents(Value hasPrebuildEvents)
		MATH(EXPR prebuildStampIndex "${prebuildStampIndex}+1")
		set(stampName prebuildEventStamp${prebuildStampIndex} )
		if(hasPrebuildEvents)

			if (CMAKE_GENERATOR MATCHES "Xcode")
				get_filename_component(prebuildInput ${CMAKE_BINARY_DIR}/generated/${arg_TargetFolderName}/prebuildEventInput ABSOLUTE)
				get_filename_component(prebuildStamp ${CMAKE_BINARY_DIR}/generated/${arg_TargetFolderName}/${stampName} ABSOLUTE)
				MaxonTargets_CreateFile(PATH ${prebuildInput})

				target_sources(${arg_TargetName} PRIVATE ${prebuildStamp})
				source_group("generated" FILES ${prebuildStamp})
			
				set_source_files_properties(${prebuildStamp} PROPERTIES HEADER_FILE_ONLY TRUE)

				add_custom_command(
					COMMAND $<IF:$<CONFIG:DEBUG>,${targetCommand.DEBUG},${targetCommand.RELEASE}>
					ARGS "$<IF:$<CONFIG:DEBUG>,${script.DEBUG};${params.DEBUG},${script.RELEASE};${params.RELEASE}>" 
					COMMAND touch 
					ARGS ${prebuildStamp}
					OUTPUT ${prebuildStamp}
					WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
					COMMENT "Maxon custom command"
					COMMAND_EXPAND_LISTS)

			else()
				# The ARGS parameter needs to be wrapped in quotes, otherwise the generator expression is not recognized because the spaces within it are interpreted as parameter separators to the ARGS parameter
				# The double quotes around the params part are necessary, so that the semicolons in the params string are not interpreted as parameter separators for the ARGS parameter.
				add_custom_command(
					TARGET ${arg_TargetName} PRE_BUILD 
					COMMAND $<IF:$<CONFIG:DEBUG>,${targetCommand.DEBUG},${targetCommand.RELEASE}>
					ARGS "$<IF:$<CONFIG:DEBUG>,${script.DEBUG};${params.DEBUG},${script.RELEASE};${params.RELEASE}>"
					WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
					COMMENT "Maxon custom command"
					COMMAND_EXPAND_LISTS
					#VERBATIM
				)
			endif()

		else()

			add_custom_target(
				${arg_TargetName}_prebuildEvents${additionalPrebuildSuffix}
				COMMAND $<IF:$<CONFIG:DEBUG>,${targetCommand.DEBUG},${targetCommand.RELEASE}> "$<IF:$<CONFIG:DEBUG>,${script.DEBUG};${params.DEBUG},${script.RELEASE};${params.RELEASE}>"
				WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
				COMMENT "Maxon prebuild events"
				COMMAND_EXPAND_LISTS
			)
			add_dependencies(${arg_TargetName} ${arg_TargetName}_prebuildEvents${additionalPrebuildSuffix})

		endif()
	endforeach()

	if(additionalPrebuildSuffix GREATER_EQUAL 2 AND NOT hasPrebuildEvents)
		foreach(index RANGE ${additionalPrebuildSuffix} 2)
			MATH(EXPR nextAdditionalPrebuildSuffix "${additionalPrebuildSuffix}-1")
			add_dependencies(${arg_TargetName}_prebuildEvents${additionalPrebuildSuffix} ${arg_TargetName}_prebuildEvents${nextAdditionalPrebuildSuffix})
			set(additionalPrebuildSuffix ${nextAdditionalPrebuildSuffix})
		endforeach()
	endif()

endfunction()


function (MaxonTargets_ConfigureLibrary)
	set(options)
	set(oneValueArgs TargetName TargetRootDir FileListPath)
	set(multiValueArgs SearchDirectories SourceFilters FrameworkDependencies RegisterGeneratedFileNames TypeViewerFiles IgnorePaths AdditionalSourceFiles)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
	
	if(NOT arg_TargetName OR NOT arg_TargetRootDir OR NOT arg_FileListPath)
		message(FATAL_ERROR "Invalid project directory.")
	endif()

	#set_target_properties(${arg_TargetName} PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP NO)
	#set_target_properties(${arg_TargetName} PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS NO)

	set_target_properties(${arg_TargetName} PROPERTIES LINKER_LANGUAGE CXX)
	
	if(g_maxonTargetOS STREQUAL "MACOS")
	endif()
	
	#################################################
	# Set up the listing file.
	#################################################
	set (fileListPath ${arg_FileListPath})
	
	MaxonTargets_UpdateFileList(File ${fileListPath} BaseDirectory ${arg_TargetRootDir} SearchDirectories ${arg_SearchDirectories} ErrorOnWrite FALSE)
	
	set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${fileListPath}) # Changes to the file trigger a reconfigure
	
	# We add the list file as a non-compiled file in the generated folder.
	target_sources(${arg_TargetName} PRIVATE ${fileListPath})
	set_source_files_properties(${fileListPath} PROPERTIES HEADER_FILE_ONLY TRUE)
	source_group("generated" FILES ${fileListPath})
	
	#################################################
	# Set up the header and source files.
	#################################################
	
	# We load the file and process its contents.
	MaxonTargets_LoadFileList(File ${fileListPath} FileList sourceFilesRelative)
	MaxonTargets_FilterFiles(Files ${sourceFilesRelative} Filters ${arg_SourceFilters} Ignores ${arg_IgnorePaths} FilesAllowed sourceFilesAllowed FilesDenied sourceFilesDenied) # Results are relative.

	# We must make these paths absolute for projects that are not truly associated with CMAKE_CURRENT_SOURCE_DIR
	MaxonTargets_MakeRelativePathsAbsolute(BaseDirectory ${arg_TargetRootDir} RelativeFiles ${sourceFilesAllowed} AbsoluteFiles sourceFilesAllowed)
	MaxonTargets_MakeRelativePathsAbsolute(BaseDirectory ${arg_TargetRootDir} RelativeFiles ${sourceFilesDenied} AbsoluteFiles sourceFilesDenied)
	MaxonTargets_MakeRelativePathsAbsolute(BaseDirectory ${arg_TargetRootDir} RelativeFiles ${arg_AdditionalSourceFiles} AbsoluteFiles arg_AdditionalSourceFiles)
	
	# We add the globbed source files.
	target_sources(${arg_TargetName} PRIVATE ${sourceFilesAllowed} ${arg_AdditionalSourceFiles} ${sourceFilesDenied})

	set_source_files_properties(${sourceFilesDenied} PROPERTIES HEADER_FILE_ONLY TRUE)
	if(CMAKE_GENERATOR MATCHES "Visual Studio")
		# With CMake 3.22 onwards we can add the stop sign to files and exclude them.
		# We must cheat a bit, at least for Visual Studio 2019. The UI only properly adds the stop signs if the .vcxproj file contains configuration conditions.
		# Hence, a configuration-independent setting will work in terms of exclusion, but no stop sign is shown:
		# set_property(SOURCE ${sourceFilesDenied} PROPERTY VS_SETTINGS "ExcludedFromBuild=true")
		# or equally
		# set_source_files_properties(${sourceFilesDenied} PROPERTIES VS_SETTINGS "ExcludedFromBuild=true")

		# We therefore use a generator expression that is effectively always true/True, which is both consumed properly by Visual Studio.
		# Using two different values forces the generator expression to create the designed conditions that Visual Studio then appears to evaluate.
		set_source_files_properties(${sourceFilesDenied} PROPERTIES VS_SETTINGS "$<IF:$<CONFIG:DEBUG>,ExcludedFromBuild=true,ExcludedFromBuild=True>")
	endif()
	
	# We structure source files in Visual Studio, e.g. Solution/frameworks/core.framework/source/maxon/application.h
	source_group(TREE ${arg_TargetRootDir} FILES ${sourceFilesAllowed} ${sourceFilesDenied})

	if (g_maxonTargetOS STREQUAL "WINDOWS")
		target_sources(${arg_TargetName} PRIVATE ${additional_solution_files.WINDOWS})
		source_group("additional" FILES ${additional_solution_files.WINDOWS})
	endif()

	# Set the standard warning settings.
	MaxonCompilerHelper_SetMaxonDefaultWarnings(${arg_TargetName} PRIVATE)
	# Todo: Investigate if we need to always set this, or if it should be configurable.
	MaxonCompilerHelper_SetISA(${arg_TargetName} PRIVATE)
	MaxonCompilerHelper_SetCompileDefinitions(${arg_TargetName} PRIVATE)
	MaxonCompilerHelper_SetBaseLinkOptions(${arg_TargetName} PRIVATE)
	
	# We setup the include directories.
	set(includedSourceFilesRelative "${sourceFilesAllowed};${sourceFilesDenied}")
	MaxonTargets_CollectIncludeDirectories(RootDir ${arg_TargetRootDir} SourceFilesRelative ${includedSourceFilesRelative} SearchDirectories ${arg_SearchDirectories} IncludeDirectories includeDirectories)

	# We need to exclude the source/maxon folder to allow disambiguation between filenames with external souce.
	# This way, you need to explicitly include via maxon/<filename>.
	list(FILTER includeDirectories EXCLUDE REGEX "source/maxon$")
	target_include_directories(${arg_TargetName} PUBLIC ${includeDirectories})
	
	#################################################
	# Set up the framework dependencies.
	#################################################
	
	# CMake target names carry the optional MAXON_TARGET_SUFFIX target-name suffix, while
	# the source processor keeps working with the base framework names (its directory layout).
	set(frameworkDependencyTargets ${arg_FrameworkDependencies})
	if (MAXON_TARGET_SUFFIX)
		list(TRANSFORM frameworkDependencyTargets APPEND "${MAXON_TARGET_SUFFIX}")
	endif()

	MaxonCompilerHelper_LinkFrameworks(TARGET ${arg_TargetName} DEPENDENCIES ${frameworkDependencyTargets})

	# Set up the source processor.
	set(sourceProcessorDirectory ${CMAKE_BINARY_DIR}/generated${MAXON_TARGET_SUFFIX}) # must be common across all targets (of the same target-name suffix)!
	# We add an execution step for the source processor and add its products to the target.
	MaxonTargets_ConfigureSourceProcessor(TargetName ${arg_TargetName} RootDir ${arg_TargetRootDir} GeneratedDir ${sourceProcessorDirectory} RegisterGeneratedFileNames ${arg_RegisterGeneratedFileNames} FrameworkDependencies ${arg_FrameworkDependencies})

	#################################################
	# Set up the prebuild events and custom commands.
	#################################################

	set(divertPycFilesFlag "")
	if(g_pythonSupportsPycDir)
		set(pycSubDirectory "python_cache/")
		cmake_path(ABSOLUTE_PATH pycSubDirectory BASE_DIRECTORY "${CMAKE_BINARY_DIR}" NORMALIZE OUTPUT_VARIABLE pycCachePath)
		set(divertPycFilesFlag "-X pycache_prefix=\"${pycCachePath}\"")
	endif()

	# We do not support the split of the register.cpp. Their amount seems to differ based on the content of the framework. We could handle that by
	# conservatively creating multiple empty registerN.cpp files.
	set(sourceProcessorArgs ${divertPycFilesFlag} ${g_sourceProcessorPythonPy} --platform-name ${g_maxonTargetOS} --option stylecheck.aswarnings=true --quiet --generatedroot \"${sourceProcessorDirectory}\" --frameworkroot \"${g_frameworkRootDirectory}\" \"${arg_TargetRootDir}\")
	
	get_filename_component(generatedDir "${sourceProcessorDirectory}" ABSOLUTE)
	
	get_filename_component(targetDirName ${arg_TargetRootDir} NAME) # support cases where the target is named differently than the directory. The source processor will also stick to directory names, e.g. generatedroot/${arg_TargetDirName}
	
	# We create these files if they do not exist so that they can be included right away.
	foreach(registerFileName IN LISTS arg_RegisterGeneratedFileNames)
		get_filename_component(registerFilePath ${generatedDir}/${targetDirName}/hxx/${registerFileName} ABSOLUTE)
		list(APPEND registerGeneratedFileNames ${registerFilePath})
	endforeach()
	list(SORT registerGeneratedFileNames)

	get_filename_component(stampFilePath ${generatedDir}/${targetDirName}/sourceprocessor.stamp ABSOLUTE)

	target_sources(${arg_TargetName} PRIVATE ${stampFilePath})
	source_group("generated" FILES ${stampFilePath})

	set_source_files_properties(${stampFilePath} PROPERTIES HEADER_FILE_ONLY TRUE)
	if(CMAKE_GENERATOR MATCHES "Visual Studio") # With CMake 3.22 onwards we can add the stop sign to files and exclude them.
		set_source_files_properties(${stampFilePath} PROPERTIES VS_SETTINGS "$<IF:$<CONFIG:DEBUG>,ExcludedFromBuild=true,ExcludedFromBuild=True>")
	endif()

	foreach(a IN LISTS arg_SearchDirectories)
		set(searchArg ${searchArg}|\"${a}\") # We must properly escape this list, e.g. with a|b|
	endforeach()
	string(REPLACE ";" "#" arg_SearchDirectories ${arg_SearchDirectories})
	set(fileListArgs "-Dmaxon_File=\"${fileListPath}\"" "-Dmaxon_BaseDirectory=\"${arg_TargetRootDir}\"" "-Dmaxon_SearchDirectories=\"${searchArg}\"" "-P" "${MAXON_TOOLING_DIR}/commands/update_filelist.cmake")

	MaxonTargets_HasGeneratorPrebuildEvents(Value maxon_hasPrebuildEvents)

	if (maxon_hasPrebuildEvents)
		if (CMAKE_GENERATOR MATCHES "Xcode")

			# File List
			add_custom_command(
				COMMAND ${CMAKE_COMMAND}
				ARGS ${fileListArgs}
				COMMAND ${CMAKE_COMMAND} -E touch ${sourceProcessorDirectory}/fileListCommandInput
				DEPENDS ${sourceProcessorDirectory}/fileListCommandInput
				OUTPUT ${fileListPath}
				COMMENT "Maxon Generate File List")

			# Source Processor

			# We need to add the source processor output of our framework dependencies to the input dependencies for the source processor command. 
			# Otherwise changing the interface in a framework dependency will not make the module source processors pick up these changes and run again.
			list(TRANSFORM arg_FrameworkDependencies APPEND "/sourceprocessor.stamp" OUTPUT_VARIABLE frameworkDependenciesSourceProcessorOutput)
			list(TRANSFORM frameworkDependenciesSourceProcessorOutput PREPEND "${generatedDir}/" OUTPUT_VARIABLE frameworkDependenciesSourceProcessorOutput)

			add_custom_command(
				COMMAND ${g_pythonBin}
				ARGS ${sourceProcessorArgs}
				DEPENDS ${sourceFilesAllowed} ${frameworkDependenciesSourceProcessorOutput}
				OUTPUT ${stampFilePath}
				BYPRODUCTS ${registerGeneratedFileNames}
				COMMENT "Maxon Source Processor")

		else()

			# File List
			add_custom_command(
				TARGET ${arg_TargetName} PRE_BUILD
				COMMAND ${CMAKE_COMMAND}
				ARGS ${fileListArgs}
				COMMENT "Maxon Generate File List")

			# Source Processor
			add_custom_command(
				TARGET ${arg_TargetName}
				PRE_BUILD
				COMMAND ${g_pythonBin}
				ARGS ${sourceProcessorArgs}
				BYPRODUCTS ${registerGeneratedFileNames} ${stampFilePath}
				COMMENT "Maxon Source Processor")
		endif()
	else()
		# Source Processor
	
		# We must correctly model the dependencies, e.g.
		# Target: image.framework <- core.framework, image.framework_SourceProcessor
		# Target: image.framework_SourceProcessor <- core.framework_SourceProcessor
		# Target: core.framework <- core.framework_SourceProcessor
		list(TRANSFORM frameworkDependencyTargets APPEND "_SourceProcessor" OUTPUT_VARIABLE frameWorkDependencies_SourceProcessor)
		# can not use the string from above here due to a quoting issue

		add_custom_target(
			${arg_TargetName}_SourceProcessor
			COMMAND ${g_pythonBin} ${g_sourceProcessorPythonPy} --platform-name ${g_maxonTargetOS} --option stylecheck.aswarnings=true --quiet --generatedroot ${sourceProcessorDirectory} --frameworkroot ${g_frameworkRootDirectory} ${arg_TargetRootDir}
			BYPRODUCTS ${registerGeneratedFileNames} ${stampFilePath}
			)
		set_target_properties(${arg_TargetName}_SourceProcessor PROPERTIES FOLDER "CMake/Maxon/Source Processor")
		#message("A=${arg_TargetName}\nB=${arg_TargetName}_SourceProcessor\nC=${frameWorkDependencies_SourceProcessor}")
		add_dependencies(${arg_TargetName} ${arg_TargetName}_SourceProcessor)
		if (frameWorkDependencies_SourceProcessor)
			add_dependencies(${arg_TargetName}_SourceProcessor ${frameWorkDependencies_SourceProcessor})
		endif()
		# Alternatively, we could blockingly call the source processor now. But that would be slower, because configure is single-threaded.
		#exec_program(${g_pythonBin} ARGS ${sourceProcessorArgs})
		
		
		# File List
		add_custom_target(${arg_TargetName}_FileList COMMAND ${CMAKE_COMMAND} ${fileListArgs})
		set_target_properties(${arg_TargetName}_FileList PROPERTIES FOLDER "CMake/Maxon/File List")
		add_dependencies(${arg_TargetName}_SourceProcessor ${arg_TargetName}_FileList)
	endif()

	get_target_property(targetType ${arg_TargetName} TYPE)
	
	#################################################
	# SDK plugin examples come with separate resource directories. 
	#################################################
	MaxonTargets_IsPluginModulePath("${CMAKE_CURRENT_SOURCE_DIR}" isPluginModule)
	if(isPluginModule)
		get_filename_component(resourceDirectory ${arg_TargetRootDir}/res ABSOLUTE)
		if(EXISTS ${resourceDirectory})
			add_custom_command(
			TARGET ${arg_TargetName} POST_BUILD
			COMMAND ${CMAKE_COMMAND}
			ARGS
				"-Dmaxon_Path=$<TARGET_FILE_DIR:${target_name}>/res"
				"-Dmaxon_Target=${resourceDirectory}"
				"-P" "${MAXON_TOOLING_DIR}/commands/create_directory_symlink.cmake"
			COMMENT "Create symlinks to runtime resources for plugins.")
		endif()
	endif()

	#################################################
	# Set up file extension.
	#################################################
	if (targetType STREQUAL SHARED_LIBRARY OR targetType STREQUAL MODULE_LIBRARY)
		if (g_maxonTargetOS STREQUAL "WINDOWS")
			set_target_properties(${arg_TargetName} PROPERTIES SUFFIX ".xdl64")
		elseif(g_maxonTargetOS STREQUAL "MACOS")
			set_target_properties(${arg_TargetName} PROPERTIES SUFFIX ".xlib")
		elseif(g_maxonTargetOS STREQUAL "LINUX")
			set_target_properties(${arg_TargetName} PROPERTIES SUFFIX ".xso64")
		endif()
	endif()

	#################################################
	# Set up type viewer files, e.g. for better type inspection when debugging in Visual Studio
	#################################################
	
	if (arg_TypeViewerFiles)
		target_sources(${arg_TargetName} PRIVATE ${arg_TypeViewerFiles})
	endif()

	#################################################
	# Set up Visual Studio and Xcode Debugger Path.
	#################################################
	if(MAXON_C4D_EXECUTABLE AND (targetType STREQUAL SHARED_LIBRARY OR targetType STREQUAL MODULE_LIBRARY))
			if(CMAKE_GENERATOR MATCHES "Visual Studio")
				# This reportedly does not work as expected since VS does not expand the variables properly:

				# We ease debugging a plugin by adding the appropriate additional module path to the Cinema4D call.
				# set_target_properties(${arg_TargetName} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "g_console=true g_additionalModulePath=$(TargetDir)")
				
				# https://gitlab.kitware.com/cmake/cmake/-/issues/21751
				# https://gitlab.kitware.com/cmake/cmake/-/issues/18094
				# https://developercommunity.visualstudio.com/t/debugger-no-longer-respects-localdebuggerworkingdi/268817
				
				# An alternative workaround would be to configure a vcxproj.user file based on a template.
				# https://gist.github.com/UnaNancyOwen/665b3d7993785749b1033217d73540fa
				# We decide against that, because if not done right this might overwrite user edits.
				
				# Instead we determine '$(TargetDir)' on our own and chain nested generator expressions.
				set(COMMAND_TEMPLATE "$<IF:$<CONFIG:!CONF!>,!TRUE!,!FALSE!>") 
				set(COMMAND_NESTED "${COMMAND_TEMPLATE}")
				
				foreach(outputConfig ${CMAKE_CONFIGURATION_TYPES})

					string( TOUPPER ${outputConfig} outputConfigUpper)
					get_target_property(library_output_path ${arg_TargetName} LIBRARY_OUTPUT_DIRECTORY_${outputConfigUpper})

					# (SDK Difference): The SDK must load the /plugins directory, not just one module.
					get_filename_component(additional_module_path "${library_output_path}" DIRECTORY)
					set(configTargetDir "g_additionalModulePath=${additional_module_path}/")
					set(CONF_COMMAND "${COMMAND_TEMPLATE}")
					string(REPLACE "!CONF!" "${outputConfig}" CONF_COMMAND "${CONF_COMMAND}")
					string(REPLACE "!TRUE!" "${configTargetDir}" CONF_COMMAND "${CONF_COMMAND}")
					string(REPLACE "!FALSE!" "${CONF_COMMAND}" COMMAND_NESTED "${COMMAND_NESTED}")        
				endforeach()
				string(REPLACE "!CONF!" "DUMMY" COMMAND_NESTED "${COMMAND_NESTED}")
				string(REPLACE "!FALSE!" "" COMMAND_NESTED "${COMMAND_NESTED}")
				string(REPLACE "!TRUE!" "" COMMAND_NESTED "${COMMAND_NESTED}")

				set_target_properties(${arg_TargetName} PROPERTIES VS_DEBUGGER_COMMAND "${MAXON_C4D_EXECUTABLE}")
				set_target_properties(${arg_TargetName} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "g_console=true ${COMMAND_NESTED}")
			elseif(CMAKE_GENERATOR STREQUAL "Xcode")
				set_target_properties(${arg_TargetName} PROPERTIES XCODE_GENERATE_SCHEME TRUE)
				set_target_properties(${arg_TargetName} PROPERTIES XCODE_SCHEME_EXECUTABLE ${MAXON_C4D_EXECUTABLE})

				# Sadly, the documentation https://cmake.org/cmake/help/latest/prop_tgt/XCODE_GENERATE_SCHEME.html
				# states that only XCODE_SCHEME_WORKING_DIRECTORY supports generator expressions.
				# We therefore hard-code to the Debug binary path. This can be verify by the following:
				# The related issue: https://gitlab.kitware.com/cmake/cmake/-/issues/22981
				# set_target_properties(${arg_TargetName} PROPERTIES XCODE_SCHEME_ARGUMENTS "blub/$<CONFIG>") # Is taken over literally.
				# set_target_properties(${arg_TargetName} PROPERTIES XCODE_SCHEME_WORKING_DIRECTORY "blub/$<CONFIG>") # Generator expression is resolved.
				
				get_target_property(library_output_path_debug ${arg_TargetName} LIBRARY_OUTPUT_DIRECTORY_DEBUG)
				set_target_properties(${arg_TargetName} PROPERTIES XCODE_SCHEME_ARGUMENTS "g_additionalModulePath=${library_output_path_debug}") # Does not support generator expressions.
			endif()
	endif()

	MaxonCompilerHelper_EnableParallelBuildsForTarget(${arg_TargetName})

endfunction()

function (MaxonTargets_ConfigureSourceProcessor)
	set(options)
	set(oneValueArgs TargetName RootDir GeneratedDir)
	set(multiValueArgs RegisterGeneratedFileNames FrameworkDependencies )
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if(NOT arg_TargetName OR NOT arg_RootDir OR NOT arg_GeneratedDir)
		message(FATAL_ERROR "Invalid arguments.")
	endif()
	
	get_filename_component(arg_RootDir "${arg_RootDir}" ABSOLUTE)
	get_filename_component(arg_GeneratedDir "${arg_GeneratedDir}" ABSOLUTE)
	
	get_filename_component(arg_TargetDirName ${arg_RootDir} NAME) # support cases where the target is named differently than the directory. The source processor will also stick to directory names, e.g. generatedroot/${arg_TargetDirName}
	# We create these files if they do not exist so that they can be included right away.
	foreach(registerFileName IN LISTS arg_RegisterGeneratedFileNames)
		get_filename_component(registerFilePath ${arg_GeneratedDir}/${arg_TargetDirName}/hxx/${registerFileName} ABSOLUTE)
		#MaxonTargets_CreateFile(PATH ${registerFilePath})
		list(APPEND registerGeneratedFileNames ${registerFilePath})
	endforeach()
	list(SORT registerGeneratedFileNames)
	
	# We add the files to the target.
	target_sources(${arg_TargetName} PRIVATE ${registerGeneratedFileNames})
	source_group("generated" FILES ${registerGeneratedFileNames})
	
	# We add the directories to the include list.
	foreach(registerFile IN LISTS registerGeneratedFileNames)
		get_filename_component(registerFileDirectory ${registerFile} DIRECTORY)
		target_include_directories(${arg_TargetName} PUBLIC ${registerFileDirectory})
	endforeach()
	
endfunction()

macro(MaxonTargets_ConfigurePythonPaths)
	# We set up the source processor environment.
	get_filename_component(g_sourceProcessorPythonPy "${CMAKE_SOURCE_DIR}/${MAXON_CORE_SUBDIR}/tools/sourceprocessor/sourceprocessor.py" ABSOLUTE)
	get_filename_component(g_frameworkRootDirectory "${MAXON_FRAMEWORKS_DIR}" ABSOLUTE)

	set(pythonSupportsPycDir OFF)
	#this will result in an error if not found (which is correct for us)
	# on osx python 3.9 does not work!
	if(NOT DEFINED MAXON_SOURCEPROCESSOR_PYTHON)
		find_package(
				Python3
				REQUIRED
				COMPONENTS Interpreter
		)
		set(g_pythonBin ${Python3_EXECUTABLE})
	else()
		set(g_pythonBin ${MAXON_SOURCEPROCESSOR_PYTHON})
	endif()
	
	# Starting with version 8 python allows us to set a specific directory for .pyc files.
	if(Python3_VERSION_MINOR GREATER_EQUAL 8)
		set(g_pythonSupportsPycDir ON)
	endif()
endmacro()

macro(MaxonTargets_SetupOSIdentifierGlobals)
	if(WIN32)
		set(g_maxonTargetOS WINDOWS)
	else()
		if(APPLE)
			set(g_maxonTargetOS MACOS)
		endif()
		if(UNIX AND NOT APPLE)
			set(g_maxonTargetOS LINUX)
		endif()
	endif()

	string(TOLOWER "${CMAKE_SYSTEM_NAME}" g_maxonTargetPlatformSystem)
	string(REPLACE "darwin" "macos" g_maxonTargetPlatformSystem ${g_maxonTargetPlatformSystem})

	string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" g_maxonTargetPlatformArchitecture)
	string(REPLACE "aarch64" "arm64" g_maxonTargetPlatformArchitecture ${g_maxonTargetPlatformArchitecture})
	string(REPLACE "amd64" "x64" g_maxonTargetPlatformArchitecture ${g_maxonTargetPlatformArchitecture})
	string(REPLACE "x86_64" "x64" g_maxonTargetPlatformArchitecture ${g_maxonTargetPlatformArchitecture})

	# At this point we obtain a system specifier ${g_maxonTargetPlatformSystem}-${g_maxonTargetPlatformArchitecture}, for example
	# windows-arm64
	# windows-x64
	# linux-arm64
	# ..
endmacro()

function (MaxonTargets_IsPlatformSupported)
	set(options)
	set(oneValueArgs SUPPORTED)
	set(multiValueArgs PLATFORMS)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	set(platforms ${arg_PLATFORMS})
	set(platform_supported FALSE)
	foreach(platform IN LISTS platforms)
		if (platform STREQUAL g_maxonTargetPlatformSystem)
			# This is a system-wide match, e.g. 'windows'
			set(platform_supported TRUE)
		endif()
		if (platform STREQUAL "${g_maxonTargetPlatformSystem}-${g_maxonTargetPlatformArchitecture}")
			# This is a system-wide match, e.g. 'windows-arm64'
			set(platform_supported TRUE)
		endif()
		# We may have two types 
	endforeach()
	set(${arg_SUPPORTED} ${platform_supported} PARENT_SCOPE)
endfunction()

function(MaxonTargets_SetCustomOutputDirectory target_name type directory)
	foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
		string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
		set_target_properties(${target_name} PROPERTIES ${type}_${OUTPUTCONFIG_UPPER} "${directory}")
	endforeach()
endfunction()


function(MaxonTargets_AddMaxonFrameworkTarget target_name customOutputDirectory)

	# We add a C++ static library target and make it show up in Visual Studio under the frameworks and modules folders.
	add_library(${target_name} STATIC)
	set_target_properties(${target_name} PROPERTIES FOLDER "frameworks")

	cmake_path (GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH targetSourceRoot)
	get_filename_component(targetDirName ${targetSourceRoot} NAME)

endfunction()

function(MaxonTargets_AddMaxonModuleTarget target_name customOutputDirectory)

	add_library(${target_name} MODULE)
	set_target_properties(${target_name} PROPERTIES PREFIX "") # Ensure there's no 'lib' prefix for dlls / modules.

	# Plugins have a different binary output dir. We need to set that for easy plugin target to change the default.
	MaxonTargets_IsPluginModulePath("${CMAKE_CURRENT_SOURCE_DIR}" isPluginModule)
	if(isPluginModule)
		foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
			string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
			set(currentPluginBinaryDir "${CMAKE_PLUGINS_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER}}/${target_name}")
			set_target_properties(${target_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} "${currentPluginBinaryDir}")
		endforeach()
		set_target_properties(${target_name} PROPERTIES FOLDER "plugins")
	else()
		set_target_properties(${target_name} PROPERTIES FOLDER "modules")
	endif()
	
	if(APPLE)
		set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT dwarf)
	endif()

	if(g_maxonTargetOS STREQUAL "MACOS")
		set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_OTHER_SWIFT_FLAGS "")
		set_target_properties(${target_name} PROPERTIES BUNDLE FALSE) 
		set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_MACH_O_TYPE mh_dylib) #staticlib)

		if ("${c4d_version}")
			# Make sure 'otool -L' reports the correct name.
			string(REPLACE "." ";" c4d_version_split ${c4d_version})
			list(GET c4d_version_split 0 c4d_version_major)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_LD_DYLIB_INSTALL_NAME "/R${c4d_version_major}/$<TARGET_FILE_NAME:${target_name}>")
		endif()

	endif()

	if (customOutputDirectory)
		MaxonTargets_SetCustomOutputDirectory(${target_name} LIBRARY_OUTPUT_DIRECTORY ${customOutputDirectory})
	endif()

endfunction()

function(MaxonTargets_EnableDebugSymbolStripping target_name)
	if(g_maxonTargetOS STREQUAL "MACOS")
		set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT $<IF:$<CONFIG:DEBUG>,dwarf,dwarf-with-dsym>)
	endif()
endfunction()

# Returns if the given #path_ lies within one of the #MAXON_SDK_MODULE_PATHS. 
function(MaxonTargets_IsPluginModulePath path_ result)
    set(${result} FALSE PARENT_SCOPE)
    foreach(moduleRoot ${MAXON_SDK_MODULE_PATHS})
        string(FIND "${path_}" "${moduleRoot}" pos)
        if(pos EQUAL 0)
            set(${result} TRUE PARENT_SCOPE)
            return()
        endif()
    endforeach()
endfunction()

macro(MaxonTargets_ProcessCinemaTargetVars)

	if (NOT target_base_name)
		message(FATAL_ERROR "Target descriptor '${CMAKE_CURRENT_SOURCE_DIR}' must set 'target_base_name' (the former 'target_name' descriptor variable was renamed).")
	endif()

	# Optional target-name suffix: when MAXON_TARGET_SUFFIX is set (e.g. '_2027' for unified
	# builds of several SDK generations in one build tree), every CMake target name gets
	# the suffix so the target names stay unique. Module ids, resource paths and the
	# source-processor directory layout keep the base name. Since this is a macro,
	# ${target_name} refers to the (possibly suffixed) name in descriptor code after this call.
	set(target_name ${target_base_name}${MAXON_TARGET_SUFFIX})

	MaxonSourceProcessor_ParseTargetSettings(JSON "${target_settings}" OS "${g_maxonTargetOS}")

	# We collect direct framework dependencies for the MAXON_FILTER_UNUSED_FRAMEWORKS option.
	list(APPEND maxon_usedFrameworks ${target_apis})
	set(maxon_usedFrameworks "${maxon_usedFrameworks}" PARENT_SCOPE)

	# We check if the specified platform is supported, either for the current system or for a particular architecture of the current system.
	# We skip this target if the platform is not supported.
	MaxonTargets_IsPlatformSupported(PLATFORMS ${target_platforms} SUPPORTED platform_supported)
	if (MAXON_FILTER_TARGET_PLATFORMS AND NOT platform_supported)
		message(STATUS "Skipping ${target_name} because ${g_maxonTargetPlatformSystem}-${g_maxonTargetPlatformArchitecture} is not supported.")
		return()
	endif()

	
	if (NOT subsystem.WINDOWS)
		set(subsystem.WINDOWS WINDOWS) # default
	endif()

	if (target_type STREQUAL "Lib")
		MaxonTargets_AddMaxonFrameworkTarget(${target_name} "${customOutputDirectory}")
	elseif (target_type STREQUAL "DLL")
		MaxonTargets_AddMaxonModuleTarget(${target_name} "${customOutputDirectory}")
	else()
		message(FATAL_ERROR "Target '${target_name}' has unsupported type '${target_type}'")
	endif()

	if(g_maxonTargetOS STREQUAL "MACOS")
		if (target_type STREQUAL "Lib")
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_DEPLOYMENT_POSTPROCESSING NO)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_STRIP_INSTALLED_PRODUCT NO)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_STRIP_STYLE debugging)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES)
		else()
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_DEPLOYMENT_POSTPROCESSING $<IF:$<CONFIG:Debug>,NO,YES>)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_STRIP_INSTALLED_PRODUCT $<IF:$<CONFIG:Debug>,NO,YES>)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_STRIP_STYLE $<IF:$<CONFIG:Debug>,debugging,non-global>)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES)
		endif()
	endif()


	if (APPLE) 
		set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_ARCHS "$(ARCHS_STANDARD)")
		if(NOT DEFINED CMAKE_XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH)
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "YES")
		endif()
	endif()

	if(MAXON_STRIP_DEBUG_SYMBOLS_IN_RELEASE)
		MaxonTargets_EnableDebugSymbolStripping(${target_name})
	endif()

	if(target_c4d)
		target_compile_definitions(${target_name} PUBLIC "USE_API_MAXON")
	endif()
	target_compile_definitions(${target_name} PRIVATE "MAXON_CMAKE_BUILD")

	if(target_type STREQUAL "Lib" AND NOT target_omitapidefine)
		target_compile_definitions(${target_name} PRIVATE "MAXON_API")
	endif()

	# If provided, we take the defined MODULEID, otherwise we auto-generate it.
	if (NOT target_moduleid)
		if (target_c4d) # This prevents moduleid collisions when there exists a module with the same name as another module with only ".module" appended.
			set(c4d_token "c4d.")
		endif()
		set(target_moduleid net.maxon.${c4d_token}${target_base_name})
		string(REGEX REPLACE ".module$" "" target_moduleid "${target_moduleid}")
	endif()
	target_compile_definitions(${target_name} PRIVATE MAXON_MODULE_ID=\"${target_moduleid}\")

	string(REPLACE "." "_" target_private_moduleid ${target_moduleid})
	if (target_type STREQUAL "DLL" OR target_type STREQUAL "AppDLL" OR target_type STREQUAL "App" OR target_base_name STREQUAL "kernel.framework")
		target_compile_definitions(${target_name} PRIVATE PRIVATE_MODULE_${target_private_moduleid})
	endif()

	target_compile_definitions(${target_name} PRIVATE ${additional_definitions.${g_maxonTargetOS}})
	target_compile_definitions(${target_name} PRIVATE ${additional_definitions})

	string(TOUPPER ${CMAKE_CXX_COMPILER_ID} CMAKE_CXX_COMPILER_ID_UPPER)

	target_link_options(${target_name} PRIVATE "$<IF:$<CONFIG:DEBUG>,${additional_linker_options.${CMAKE_CXX_COMPILER_ID_UPPER}.DEBUG},${additional_linker_options.${CMAKE_CXX_COMPILER_ID_UPPER}.RELEASE}>" )

	if(APPLE)
		if (XCODE_VERSION VERSION_GREATER_EQUAL 15)
			# This is needed to silence ld: warning: ignoring duplicate libraries: '-lobjc'
			target_link_options(${target_name} PRIVATE LINKER:-no_warn_duplicate_libraries)

			# Do not warn about object files without symbols.
			set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_OTHER_LIBTOOLFLAGS -no_warning_for_no_symbols)
		endif()
	endif()

	MaxonCompilerHelper_SetCompileOptionsRTTI(${target_name} PRIVATE  ${enable_rtti})

	MaxonCompilerHelper_SetCompileOptionsExceptions(${target_name} PRIVATE ${enable_exception_handling})

	if (NOT "${target_name}" MATCHES ".framework")
		target_include_directories(${target_name} PRIVATE "${CMAKE_SOURCE_DIR}/resource/modules/${target_base_name}") # This is needed for resource includes.
	endif()

	if(g_maxonTargetOS STREQUAL "WINDOWS" AND CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM64")
		# For now, windows-arm64 is not a proper g_maxonTargetOS and we just hack in the arm64 variables.
		target_include_directories(${target_name} PRIVATE ${additional_include_directories.WINDOWS.ARM})
		target_link_directories(${target_name} PUBLIC ${additional_link_directories.WINDOWS.ARM})
		target_link_libraries(${target_name} PUBLIC "$<IF:$<CONFIG:DEBUG>,${link_libraries.WINDOWS.ARM.DEBUG},${link_libraries.WINDOWS.ARM.RELEASE}>")

	else()
		target_include_directories(${target_name} PRIVATE ${additional_include_directories.${g_maxonTargetOS}})

		if (g_maxonTargetOS STREQUAL "LINUX")
			target_include_directories(${target_name} SYSTEM PRIVATE ${system_include_paths})
		endif()

		set (additional_link_directories ${additional_link_directories.${g_maxonTargetOS}})

		if (APPLE)
			target_link_libraries(${target_name} PRIVATE "${link_frameworks.${g_maxonTargetOS}}")
		endif()

		if(g_maxonTargetOS STREQUAL "WINDOWS" OR g_maxonTargetOS STREQUAL "LINUX") 
			target_link_directories(${target_name} PUBLIC "$<IF:$<CONFIG:DEBUG>,${additional_link_directories.${g_maxonTargetOS}.DEBUG},${additional_link_directories.${g_maxonTargetOS}.RELEASE}>")
		endif()

		target_link_libraries(${target_name} PUBLIC "$<IF:$<CONFIG:DEBUG>,${link_libraries.${g_maxonTargetOS}.DEBUG},${link_libraries.${g_maxonTargetOS}.RELEASE}>")
	endif()

	cmake_path (GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH targetSourceRoot)
	get_filename_component(targetDirName ${targetSourceRoot} NAME)

	MaxonTargets_SetupPrebuildEvents(
		PrebuildEvents.DEBUG "${prebuild_event.${g_maxonTargetOS}.DEBUG}"
		PrebuildEvents.RELEASE "${prebuild_event.${g_maxonTargetOS}.RELEASE}"
		TargetName ${target_name}
		TargetFolderName ${targetDirName})
	
	####################################################################################
	# Exported Symbols
	####################################################################################
	if(APPLE)
		# For Apple platforms we must provide hand-crafted minimal lists of symbols to be exported.
		# For the Cinema4D executable and non-plugin shared libraries we expect these files to be defined for security purposes.
		get_filename_component(exportedSymbolsFile "${CMAKE_CURRENT_SOURCE_DIR}/exportedsymbols.txt"  ABSOLUTE) 
		if (EXISTS ${exportedSymbolsFile})
			# The non Xcode-specific way would be to use ${CMAKE_STRIP} to perform the symbol removal. For now we stick with Xcode for ease of use.
			if (CMAKE_GENERATOR STREQUAL "Xcode")
				# We tell linker to keep all symbols listed in exportedsymbols.txt
				set_target_properties(${target_name} PROPERTIES XCODE_ATTRIBUTE_EXPORTED_SYMBOLS_FILE "${exportedSymbolsFile}")
			endif()
			# Use 'nm -gU <dylib-file>' to inspect the produced set of exported symbols.
		elseif (target_base_name STREQUAL "application" OR CMAKE_CURRENT_SOURCE_DIR MATCHES "/modules/")
			message(FATAL_ERROR "Could not find list of exported symbols at ${exportedSymbolsFile}.") # TODO: test with cineware and cinetester
		endif()
	endif()

	list(APPEND targetRegisterGeneratedFileNames register.cpp)
	if((target_type STREQUAL "DLL") OR target_frameworkregistration)
		list(APPEND targetRegisterGeneratedFileNames interface_registration.cpp)
		if (target_frameworkregistration)
			list(APPEND targetRegisterGeneratedFileNames reflection_registration.cpp)
			list(APPEND targetRegisterGeneratedFileNames reflection_virtual_registration.cpp)
		endif()
	endif()

	MaxonTargets_ConfigureLibrary(
		TargetName ${target_name}
		TargetRootDir ${targetSourceRoot}
		FileListPath ${CMAKE_CURRENT_BINARY_DIR}/MaxonFileList.txt
		SearchDirectories ${source_directories}
		SourceFilters ${exclude_from_build.${g_maxonTargetOS}}
		FrameworkDependencies ${target_apis}
		RegisterGeneratedFileNames ${targetRegisterGeneratedFileNames}
		TypeViewerFiles ${type_viewer_files}
		IgnorePaths ${exclude.${g_maxonTargetOS}}
		AdditionalSourceFiles ${additional_source_files.${g_maxonTargetOS}}
	)
	
	# These need to be set at the very end because in order to differentiate between c and c++ files we already need to know which files were added to the target. The files are added during the ConfigureLibrary() call.
	MaxonCompilerHelper_GetCompilerId(TARGET ${target_name} ID compilerId FRONTEND compilerFrontend)
	string(TOUPPER "${compilerId}" COMPILERID)
	set(additional_compile_optionsC additional_compile_options.${COMPILERID}.C)
	set(additional_compile_optionsCPP additional_compile_options.${COMPILERID}.CPP)
	MaxonCompilerHelper_SetAdditionalCompileOptions(${target_name} ${additional_compile_optionsCPP}  ${additional_compile_optionsC})

	if(COMMAND MaxonTargets_OnTargetCreated)
		MaxonTargets_OnTargetCreated(${target_name})
	endif()

endmacro()

function (MaxonTargets_CollectFrameworkDependencies)
	set(options)
	set(oneValueArgs RESULT)
	set(multiValueArgs FRAMEWORKS BASE_DIRECTORIES)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	set (frameworks_to_process ${arg_FRAMEWORKS})

	while (frameworks_to_process)

		# We add the frameworks and collect their dependencies for the next iteration, to resolve transitive dependencies.
		set(new_maxon_usedFrameworks "")
		foreach(framework IN LISTS frameworks_to_process)

			# We only process each framework once
			if ("${framework}" IN_LIST processed_frameworks)
				continue()
			endif()

			# We determine the disk location of the framework within any of the given base directories.
			unset(framework_cmake_dir)
			foreach(basedir IN LISTS arg_BASE_DIRECTORIES)
				set(framework_project_dir "${basedir}/${framework}/project")
				set(framework_cmake_file "${framework_project_dir}/CMakeLists.txt")
				
				if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${framework_project_dir}/CMakeLists.txt")
					set (framework_cmake_dir "${framework_project_dir}")
					break()
				endif()
			endforeach()

			if (NOT framework_cmake_dir)
				message(FATAL_ERROR "Could not find the location of framework '${framework}' among base directories ${arg_BASE_DIRECTORIES}")
			endif()

			# keep track or processed collection for early-out.
			list(APPEND processed_frameworks "${framework}")

			# maintain sortable list of framework names and paths
			list(APPEND framework_names_and_paths "${framework}|${framework_cmake_dir}")

			# we obtain the list of the frameworks onto which the framework depends upon and add it for processing.
			MaxonSourceProcessor_ReadTargetSettingsFromCMake(FILE "${framework_cmake_dir}/CMakeLists.txt" KEY "apis" OS "${g_maxonTargetOS}" RESULT target_apis)
			list(APPEND new_maxon_usedFrameworks ${target_apis})
		endforeach()
		set(frameworks_to_process ${new_maxon_usedFrameworks})
	endwhile()

	set(${arg_RESULT} ${framework_names_and_paths} PARENT_SCOPE)
endfunction()

function (MaxonTargets_CollectAllFrameworks)
	set(options)
	set(oneValueArgs RESULT)
	set(multiValueArgs BASE_DIRECTORIES)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	foreach(basedir IN LISTS arg_BASE_DIRECTORIES)
		file(GLOB framework_cmake_files ${basedir}/*.framework/project/CMakeLists.txt ${basedir}/*/*.framework/project/CMakeLists.txt ${basedir}/*/*/*.framework/project/CMakeLists.txt)

		foreach(framework_cmake_file IN LISTS framework_cmake_files)
			# '<basedir>/<name>.framework/project/CMakeLists.txt' -> '<name>.framework'
			cmake_path(GET framework_cmake_file PARENT_PATH framework_project_dir)
			cmake_path(GET framework_project_dir PARENT_PATH framework_dir)
			cmake_path(GET framework_dir FILENAME framework)

			# We only process each framework once
			if ("${framework}" IN_LIST processed_frameworks)
				continue()
			endif()

			# keep track or processed collection for early-out.
			list(APPEND processed_frameworks "${framework}")

			# maintain sortable list of framework names and paths
			list(APPEND framework_names_and_paths "${framework}|${framework_project_dir}")

		endforeach()
	endforeach()
	set(${arg_RESULT} ${framework_names_and_paths} PARENT_SCOPE)
endfunction()

function (MaxonTargets_CreateFrameworkTargets)
	set(options)
	set(oneValueArgs)
	set(multiValueArgs FRAMEWORKS BASE_DIRECTORIES)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if (arg_FRAMEWORKS STREQUAL "ALL")
		# We glob all frameworks inside the base directories.
		MaxonTargets_CollectAllFrameworks(BASE_DIRECTORIES ${arg_BASE_DIRECTORIES} RESULT framework_names_and_paths)
	else()
		# We introspect the frameworks for their framework dependencies.
		MaxonTargets_CollectFrameworkDependencies(FRAMEWORKS ${arg_FRAMEWORKS} BASE_DIRECTORIES ${arg_BASE_DIRECTORIES} RESULT framework_names_and_paths)
	endif()

	# We sort the frameworks for proper ordering in XCode and generate them.
	list(SORT framework_names_and_paths COMPARE STRING CASE INSENSITIVE ORDER ASCENDING)
	foreach(framework_name_and_path IN LISTS framework_names_and_paths)
		string(REPLACE "|" ";" tokens ${framework_name_and_path})
		list (GET tokens 0 framework)
		list (GET tokens 1 framework_cmake_dir)
		add_subdirectory(${framework_cmake_dir})
	endforeach()
endfunction()

set(MAXONTARGETS_INCLUDED ON)
