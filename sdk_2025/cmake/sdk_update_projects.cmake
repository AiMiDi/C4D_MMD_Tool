
if(MAXONUPDATEPROJECTS_INCLUDED)
		return()
endif()

#-----------------------------------------------------------------------------
# Combine2Variables
#
# Function for handling the setting of a projectdefinition variable by either 0, 1 or 2 projectdefinition arguments properly
# [Previously set(${varResult} "${v1};${v2}") was used but that leaves a non empty string ";" if v1 and v2 are empty and that confuses code lines where there are checks for emptyness e.g. if(varResult STREQUAL "")]
# e.g. case 1: nothing is set
# e.g. case 3: HEADER_SEARCH_PATHS is not set but USER_HEADER_SEARCH_PATHS
# e.g. case 2: HEADER_SEARCH_PATHS is set but not USER_HEADER_SEARCH_PATHS
# e.g. case 4: HEADER_SEARCH_PATHS and USER_HEADER_SEARCH_PATHS is set
#-----------------------------------------------------------------------------
function(Combine2Variables varResult var1 var2)
	set(v1 "${${var1}}")
	set(v2 "${${var2}}")
	# MESSAGE(STATUS " in:  ${${varResult}} ${v1} ${v2}")

	if (NOT DEFINED ${var1})
	 if (NOT DEFINED ${var2})
			set(${varResult} "" PARENT_SCOPE) #case 1
		else()
			set(${varResult} "${v2}" PARENT_SCOPE) #case 2
		endif()
	else()
		if (NOT DEFINED ${var2})
			set(${varResult} "${v1}" PARENT_SCOPE) #case 3
		else()
			set(${varResult} "${v1};${v2}" PARENT_SCOPE) #case 4: concatenate both data
		endif()
	endif()
endfunction()

function(CombineVariables resultVar)
	set(resultValue "")
	foreach(arg IN LISTS ARGN)
		if(NOT "${${arg}}" STREQUAL "")
			list(APPEND resultValue "${${arg}}")
		endif()
	endforeach()
	set(${resultVar} "${resultValue}" PARENT_SCOPE)
endfunction()

function (MaxonUpdateProjects_Initialize arg_UsedFrameworks arg_FrameworkPaths arg_ProjectDirectories)
	file(READ ${MAXON_TOOLING_DIR}/sdk_library_template.cmake g_libraryTemplate)
	set(usedFrameworks "")
	set(frameworkPaths "")
	MaxonUpdateProjects_Execute(usedFrameworks frameworkPaths "${arg_ProjectDirectories}")
	set(${arg_UsedFrameworks} "${usedFrameworks}" PARENT_SCOPE)
	set(${arg_FrameworkPaths} "${frameworkPaths}" PARENT_SCOPE)
endfunction()

function (MaxonUpdateProjects_CollectProjectDefinitionFiles)
	set(options)
	set(oneValueArgs ProjectDefinitionFiles)
	set(multiValueArgs ProjectDirectories)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	set(result "")

	foreach(projectDirectory IN LISTS arg_ProjectDirectories)
		if (NOT EXISTS ${projectDirectory})
			message(WARNING "Update Projects was provided with a non-existent directory location '${projectDirectory}'")
		endif()
		
		get_filename_component(projectParentDirectory "${projectDirectory}/.." ABSOLUTE)
		
		# We limit globbing to 3 levels of depths.
		file(GLOB filePaths ${projectDirectory}/* ${projectDirectory}/*/* ${projectDirectory}/*/*/*)
		foreach(filePath IN LISTS filePaths)
			get_filename_component(projectDefinitionFile "${filePath}" NAME)
			if (NOT projectDefinitionFile MATCHES "projectdefinition.txt")
				continue()
			endif()

			cmake_path(GET projectParentDirectory PARENT_PATH parentparentProjectDirectory)
			cmake_path(RELATIVE_PATH projectParentDirectory BASE_DIRECTORY ${parentparentProjectDirectory} OUTPUT_VARIABLE parentDirectoryName)

			if(parentDirectoryName STREQUAL "modules" OR parentDirectoryName STREQUAL "plugins" OR parentDirectoryName STREQUAL "frameworks")
				set(projectParentDirectory ${parentparentProjectDirectory})
			endif()
		
			file(RELATIVE_PATH relativeFilePath "${projectParentDirectory}" ${filePath})
			
			list(APPEND FileList ${relativeFilePath})
			
		endforeach()
		
		list(TRANSFORM FileList PREPEND "${projectParentDirectory}#")
		list(APPEND result ${FileList})
		set(FileList) 
		
	endforeach()
	
	# Return Values.
	list(SORT result) # Ensured ordering in Xcode.
	set(ProjectDefinitionFiles ${result} PARENT_SCOPE)

endfunction()

function(MaxonUpdateProjects_StripStrings list result)
	foreach(s IN LISTS list)
		if(s STREQUAL "")
			list(APPEND strippedList "") # Prevent the skipping of double-semicolons in the tokens by also adding an empty entry when we find an empty entry.
		else()
			string(STRIP "${s}" s)
			list(APPEND strippedList "${s}")
		endif()
	endforeach()
	set(${result} "${strippedList}" PARENT_SCOPE)
endfunction()

function (MaxonUpdateProjects_ParseProjectDefinitionFile)
	set(options VERBOSE)
	set(options DONTFAILONMISSINGDEF)
	set(oneValueArgs PATH)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	# Drop the projectdefinition.txt component of the file, and move up the 'project' folder, e.g.
	# 'C:/sdk/frameworks/core.framework/project/projectdefinition.txt' -> 'C:/sdk/frameworks/core.framework/'
	set(modulePath "")
	get_filename_component(modulePath "${arg_PATH}" DIRECTORY)
	get_filename_component(modulePath "${modulePath}" DIRECTORY)
	set(MAXON_SDK_CURRENT_MODULE "${modulePath}" CACHE INTERNAL "The current module being processed.")
	# message(STATUS "Processing project definition file '${arg_PATH}' for module '${MAXON_SDK_CURRENT_MODULE}'.")

	if (NOT EXISTS ${arg_PATH})
		# Allow to go on for cases of personal definitions.
		if(arg_DONTFAILONMISSINGDEF)
			message(INFO " Project Definition File does not exist at location '${arg_PATH}'")
			return()
		else()
			message(FATAL_ERROR "Project Definition File does not exist at location '${arg_PATH}'")
		endif()
	endif()
	
	if(arg_VERBOSE)
			message(STATUS "\nParsing project definition file '${arg_PATH}'.")
	endif()
	
	file(READ ${arg_PATH} lines)

	string(REGEX REPLACE "\\\\\n[ \t]*" "" lines "${lines}") # Remove the line continuations and following indentation whitespace.
	STRING(REPLACE "&amp;&amp;" "&&" lines "${lines}") #This enables the additional "#define AND=&amp;&amp;"
	string(REGEX REPLACE "\/\/[^\n.]*\n" "\n" lines "${lines}") # Strip inline comments like '// strip me'
	string(REGEX REPLACE ";[ \t]*\n" "\n" lines "${lines}") # Remove trailing semi-colons at the end of token lists and additional trailing whitespace.
	string(REGEX REPLACE ";" "#" lines "${lines}") # Prevent semicolons in token lists from being interpreted as list item separators.
	string(REGEX REPLACE "\n" ";" lines "${lines}") # Turn line breaks into list separators so we can iterate over individual lines.
	foreach(line ${lines})
		string(STRIP "${line}" line) # Strip leading and trailing whitespace in line.

		# We ignore empty lines and stripped comments.
		if ("${line}" STREQUAL "")
			continue()
		endif()

		# We extract the left and right sides of the assignment = operation as a list.
		STRING(FIND "${line}" "=" equalIndex)
		if (equalIndex EQUAL -1)
			continue()
		endif()

		string(SUBSTRING "${line}" 0 ${equalIndex} TOKEN_ID)
		MATH(EXPR equalIndexPlus "${equalIndex}+1")
		string(SUBSTRING "${line}" ${equalIndexPlus} -1 TOKEN_VALUES)
		string(TOUPPER ${TOKEN_ID} TOKEN_ID)
		string(STRIP "${TOKEN_ID}" TOKEN_ID) # Remove leading and trailing whitespace
		
		# We should now have two tokens. The first one is the left side of =, the second is the # separated list of arguments.
		if(NOT ${TOKEN_ID} MATCHES "PREBUILDEVENT" AND NOT ${TOKEN_ID} MATCHES "SHELLSCRIPT") # We don't want to strip the prebuild events string because the function might mess up the formatting of the parameter strings.
			# We replace # with ; making the right side a list as well.
			string(REPLACE "#" ";" TOKEN_VALUES "${TOKEN_VALUES}")
			MaxonUpdateProjects_StripStrings("${TOKEN_VALUES}" TOKEN_VALUES) # We now strip the leading and trailing whitespace for each value in the list.
			set(MAXON_PROJECTOOL_${TOKEN_ID} "${TOKEN_VALUES}" PARENT_SCOPE)
		
		# Filter out the source processor call from the prebuild events since we are already always doing the source processor anyways.
		else()
			string(STRIP "${TOKEN_VALUES}" TOKEN_VALUES)
			string(REPLACE "&&" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			string(REPLACE "&" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			string(REPLACE ";amp#;amp#" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			string(REPLACE ";amp#" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			set(prebuildEventsNoSourceProcessor "")
			foreach(token IN LISTS TOKEN_VALUES)
				if(token MATCHES "sourceprocessor\.py") # Skip the source processor entry
					continue()
				endif()
				list(APPEND prebuildEventsNoSourceProcessor "${token}")
			endforeach()
			set(TOKEN_VALUES "${prebuildEventsNoSourceProcessor}")
			set(MAXON_PROJECTOOL_${TOKEN_ID} "${TOKEN_VALUES}" PARENT_SCOPE)
		endif()
		
		if(arg_VERBOSE)
			message(STATUS "Line: '${TOKEN_ID}=${TOKEN_VALUES}'")
		endif()

	endforeach()

	if(arg_VERBOSE)
			message(STATUS "")
	endif()

endfunction()

function(MaxonUpdateProjects_SetBool placeholder value content)
	if (${value})
		set(value ON)
	else()
		set(value OFF)
	endif()
	string(REPLACE "<<${placeholder}>>" "${value}" newContent "${${content}}")
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_SetValues placeholder values content)
	list(REMOVE_DUPLICATES values)
	list(LENGTH values numValues)
	if (numValues GREATER 1) # add line breaks if there's multiple items
		list(TRANSFORM values PREPEND "\n  ")
		list(APPEND values "\n")
	endif()
	list(JOIN values "" values)
	string(REPLACE "<<${placeholder}>>" "${values}" newContent "${${content}}")
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()


function(MaxonUpdateProjects_ReplacePathPlaceholders values output)
	# We should NOT escape the string interpolation for MAXON_SDK_CURRENT_MODULE, i.e., evaluate it
	# right here and now, as the value of the variable changes during the processing of the 
	# projectdefinition.txt files.
	string(REGEX REPLACE "\\$\\(\\MAXON_ROOTDIR\\)([/]*)" "\${MAXON_SDK_ROOT_DIR}/" values "${values}")
	string(REGEX REPLACE "\\$\\{\\MAXON_ROOTDIR\\}([/]*)" "\${MAXON_SDK_ROOT_DIR}/" values "${values}")
	string(REGEX REPLACE "\\$\\(\\MAXON_SDK_ROOT_DIR\\)([/]*)" "\${MAXON_SDK_ROOT_DIR}/" values "${values}")
	string(REGEX REPLACE "\\$\\(\\MAXON_SDK_BUILD_DIR\\)([/]*)" "\${CMAKE_BINARY_DIR}/" values "${values}")
	string(REGEX REPLACE "\\$\\(\\MAXON_SDK_CURRENT_MODULE_DIR\\)([/]*)" "${MAXON_SDK_CURRENT_MODULE}/" values "${values}")
	foreach(alias IN LISTS MAXON_SDK_PATH_ALIASES)
		string(REGEX REPLACE "\\$\\(\\${alias}\\)([/]*)" "${USER_${alias}}/" values "${values}")
	endforeach()

	# Handle when a config references the MAXON_SDK_EXTERNAL_LIBS_DIR without it being set to a valid path.
	if (values MATCHES "\\$\\(\\MAXON_SDK_EXTERNAL_LIBS_DIR\\)")
		if (NOT EXISTS ${MAXON_SDK_EXTERNAL_LIBS_DIR})
			message(FATAL_ERROR "MAXON_SDK_EXTERNAL_LIBS_DIR is not a valid path: ${MAXON_SDK_EXTERNAL_LIBS_DIR}")
		endif()
		string(REGEX REPLACE "\\$\\(\\MAXON_SDK_EXTERNAL_LIBS_DIR\\)([/]*)" "\${MAXON_SDK_EXTERNAL_LIBS_DIR}/" values "${values}")
	endif()

	# Throw an error when the user uses an undefined alias.
	if (values MATCHES "\\$\\([a-zA-Z0-9_]+\\)")
		message(FATAL_ERROR "Invalid alias reference ${values}, alias is not defined.")
	endif()

	set(${output} "${values}" PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_FixRPaths values output)
	# We are facing the problem that the values that belong together are separate in the values list, e.g.
	# "-rpath;@executable_path/../../../resource/modules/io_skp/Framework/" from application
	# We must join them and separate them with a space, otherwise we keep separating with a semicolon.
	set (new_values)
	set (is_rpath OFF)
	foreach(p IN LISTS values)
			if (is_rpath)
				set(new_values "${new_values} ${p}")
			else()
				set(new_values "${new_values};${p}")
			endif()
			if (p STREQUAL -rpath)
				set (is_rpath ON)
			else()
				set (is_rpath OFF)
			endif()
	endforeach()
	set(${output} "${new_values}" PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_SetPaths placeholder values content)
	list(REMOVE_DUPLICATES values)
	MaxonUpdateProjects_FixRPaths("${values}" values)
	set(escapesValues)
	foreach(p IN LISTS values)
		if(NOT p STREQUAL "" AND NOT "${p}" MATCHES "^(@|-rpath)")
			cmake_path(SET p NORMALIZE "${p}")
		endif()
		string(FIND "${p}" " " containsSpaces)
		if (NOT containsSpaces EQUAL -1)
			set(p "\"${p}\"")
		endif()
		if ("${p}" MATCHES "^../../") # c4dplugin makes includes to other frameworks and modules. We must root these relative paths.
			set(p "\$\{CMAKE_CURRENT_SOURCE_DIR}/${p}")
		endif()
		list(APPEND escapesValues "${p}")
	endforeach()
	set(values ${escapesValues})
	list(LENGTH values numValues)
	if (numValues GREATER 1) # add line breaks if there's multiple items
		list(TRANSFORM values PREPEND "\n  ")
		list(APPEND values "\n")
	endif()
	list(JOIN values "" values)

	MaxonUpdateProjects_ReplacePathPlaceholders("${values}" values)
	string(REPLACE "<<${placeholder}>>" "${values}" newContent "${${content}}")

	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_SetSpecializedPaths placeholder specialized baseValues specializedValues content)
	if(specializedValues AND NOT "${baseValues}" STREQUAL "${specializedValues}")
		MaxonUpdateProjects_SetPaths(${placeholder}${specialized} "${specializedValues}" generatedContent)
	elseif(baseValues)
		MaxonUpdateProjects_SetValues(${placeholder}${specialized} "\$\{${placeholder}}" generatedContent)
	else()
		MaxonUpdateProjects_SetValues(${placeholder}${specialized} "" generatedContent)
	endif()
	set(${content} ${generatedContent} PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_ReplaceConfigurationSpecificTokens configuration pathStrings output)
	#message("replacement function input: ${pathStrings}")
	string(REGEX REPLACE "\\$\\(\\MAXON_BIN_PATH\\)" "\${CMAKE_BINARY_DIR}/bin/${configuration}" pathStrings "${pathStrings}")
	string(REPLACE "\$CONFIGURATION" ${configuration} pathStrings "${pathStrings}")
	set(${output} "${pathStrings}" PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_SetSpecializedPaths2)
	set(options)
	set(oneValueArgs placeholder content)
	set(multiValueArgs baseValues specializations specializedValues)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	#message("")
	#message(" arg_specializations  : ${arg_specializations}")
	#message(" arg_baseValues       : ${arg_baseValues}")
	#message(" arg_specializedValues: _${arg_specializedValues}_")

	if (DEFINED arg_UNPARSED_ARGUMENTS)
		message(FATAL_ERROR "Unparsed Arguments in MaxonUpdateProjects_SetSpecializedPaths2: ${arg_UNPARSED_ARGUMENTS}\n")
	endif()

	foreach(specialization specializedValue IN ZIP_LISTS arg_specializations arg_specializedValues)
		#message(" spec: ${specialization}")
		#message(" specializedValue: _${specializedValue}_")
		#message(" arg_baseValues  : _${arg_baseValues}_")
		string(REPLACE "\"" "" specializedValue "${specializedValue}")
		if ("${specializedValue}" STREQUAL "")
			#message(" if 1")
			if (NOT "${arg_baseValues}" STREQUAL "")
				#message(" if 2")
				set (specializedValue "${arg_baseValues}")
			endif()
		endif()

		MaxonUpdateProjects_ReplaceConfigurationSpecificTokens(${specialization} "${specializedValue}" specializedValue)

		string(REPLACE "#" ";" specializedValue "${specializedValue}")
		string(TOUPPER ${specialization} specialization_upper)

		#message(" paths: ${arg_placeholder}.${specialization_upper}: ${specializedValue}")
		MaxonUpdateProjects_SetPaths(${arg_placeholder}.${specialization_upper} "${specializedValue}" generatedContent)
	endforeach()

	set(${arg_content} ${generatedContent} PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_SetFrameworks placeholder values content)
	list(REMOVE_DUPLICATES values)
	set(escapesValues)

	foreach(p IN LISTS values)
		string(FIND "${p}" " " containsSpaces)
		if (NOT containsSpaces EQUAL -1)
			set(p "\"${p}\"")
		endif()

		MaxonUpdateProjects_ReplacePathPlaceholders("${p}" p)  
		cmake_path(GET p STEM LAST_ONLY p)
		list(APPEND escapesValues \"-framework\ ${p}\")
	endforeach()
	set(values ${escapesValues})
	list(LENGTH values numValues)
	if (numValues GREATER 1) # add line breaks if there's multiple items
		list(TRANSFORM values PREPEND "\n  ")
		list(APPEND values "\n")
	endif()
	list(JOIN values "" values)

	string(REPLACE "<<${placeholder}>>" "${values}" newContent "${${content}}")
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MaxonUpdateProjects_TransformAdditionalSourcePaths additionalSourcePaths)
	# Note (Ferdinand) I do not see the point of this function in the SDK, as it just makes the 
	# Include.{OS} command "extra" compared to the other projectdefinition.txt commands, as this 
	# function is only called for Include.{OS} and not for the other commands.

	set(sourceDirectory "source/")
	foreach(sourcePath IN LISTS ${additionalSourcePaths})
		if (${sourcePath} MATCHES "(EXTERNAL_LIBS)")
			list(APPEND transformedPaths ${sourcePath})
		else()
			cmake_path(IS_RELATIVE sourcePath isRelative)
			if(isRelative)
				cmake_path(GET sourcePath RELATIVE_PART sourcePath)
				cmake_path(APPEND sourceDirectory ${sourcePath} OUTPUT_VARIABLE prependedPath)
				list(APPEND transformedPaths ${prependedPath})
			else()
				list(APPEND transformedPaths ${sourcePath})
			endif()
		endif()
	endforeach()
	set(${additionalSourcePaths} ${transformedPaths} PARENT_SCOPE)
endfunction()


function(MaxonUpdateProjects_ParseBazelTemplateFileForWarnings)
	set(options)
	set(oneValueArgs PATH CLANGCL MSVC)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	if (NOT EXISTS ${arg_PATH})
		return()
	endif()

	file(READ ${arg_PATH} fileContent)

	set(has_clangcl_settings OFF)
	set(has_msvc_settings OFF)

	string(REGEX MATCH ".*(@cinemake//config:win_x64_clang).*" _ ${fileContent})
	if (NOT CMAKE_MATCH_1 STREQUAL "") # this only exists for a match
		set(has_clangcl_settings ON)
	endif()
	
	string(REGEX MATCH ".*(@cinemake//config:win_x64_msvc).*" _ ${fileContent})
	if (NOT CMAKE_MATCH_1 STREQUAL "") # this only exists for a match
		set(has_msvc_settings ON)
	endif()

	if (NOT has_clangcl_settings AND NOT has_msvc_settings)
		# There's nothing of our interest in the bazel template file.
		return()
	endif()
	
	# Sadly, CMake's regex parser is ancient and doesn't support many modern features, including non-greedy match.
	# For example, this doesn't work "\\[([^()].*?)\\]" which would allow us to better match anything between [ and the next ].
	# Note that "\\[([^]]+)\\]" may not match the next ] but another closing ] later.

	string(REGEX MATCHALL "cinemake//config:win_x64_clang\"[:,\\r\\n\\t ]([^]]+)\\]" MATCHED_ALL "${fileContent}")
	if (MATCHED_ALL)
		if (NOT has_clangcl_settings)
			# We assert the proper regex match as we are a bit paranoid about the starlark syntax complexity and CMake's ancient regex parser.
			message(FATAL_ERROR "Error parsing clangcl settings from ${arg_PATH}")
		endif()
		string(REGEX MATCHALL "\\[([^]]+)\\]" MATCHED_ALL "${MATCHED_ALL}")			# Remove everything surrounding [ ]
		string(REGEX REPLACE "," ";" MATCHED_ALL "${MATCHED_ALL}") # transform into a ; separated list
		string(REGEX REPLACE "\n|\\[|\\]|\"" "" MATCHED_ALL "${MATCHED_ALL}") # Remove the newlines, brackets, quotes, ...
		set(MATCHED_ALL_CLEAN) # We must not take over MODULE ids, e.g. from cinetester
		foreach(match IN LISTS MATCHED_ALL)
			if (match MATCHES "MAXON_MODULE_ID" OR match MATCHES "PRIVATE_MODULE" OR NOT match)
				continue()
			endif()
			string(REGEX REPLACE " if .*" "" match "${match}") # We just strip out Bazel's if conditional, possibly targetting a particular compiler version.
			list(APPEND MATCHED_ALL_CLEAN ${match})
		endforeach()
		string(REGEX REPLACE "\t| " "" MATCHED_ALL_CLEAN "${MATCHED_ALL_CLEAN}") # Remove the spaces, tabs, ...

		set(${arg_CLANGCL} "${MATCHED_ALL_CLEAN}")
	endif()

	string(REGEX MATCHALL "cinemake//config:win_x64_msvc\":[\\r\\n\\t ]([^]]+)\\]" MATCHED_ALL "${fileContent}")
	if (MATCHED_ALL)
		if (NOT has_msvc_settings)
			# We assert the proper regex match as we are a bit paranoid about the starlark syntax complexity and CMake's ancient regex parser.
			message(FATAL_ERROR "Error parsing msvc settings from ${arg_PATH}")
		endif()
		string(REGEX MATCHALL "\\[([^]]+)\\]" MATCHED_ALL "${MATCHED_ALL}")			# Remove everything surrounding [ ]
		string(REGEX REPLACE "," ";" MATCHED_ALL "${MATCHED_ALL}") # transform into a ; separated list
		string(REGEX REPLACE "\n|\\[|\\]|\"" "" MATCHED_ALL "${MATCHED_ALL}") # Remove the newlines, brackets, quotes, ...
		set(MATCHED_ALL_CLEAN) # We must not take over MODULE ids, e.g. from cinetester
		foreach(match IN LISTS MATCHED_ALL)
			if (match MATCHES "MAXON_MODULE_ID" OR match MATCHES "PRIVATE_MODULE" OR NOT match)
				continue()
			endif()
			string(REGEX REPLACE " if .*" "" match "${match}") # We just strip out Bazel's if conditional, possibly targetting a particular compiler version.
			list(APPEND MATCHED_ALL_CLEAN ${match})
		endforeach()
		string(REGEX REPLACE "\t| " "" MATCHED_ALL_CLEAN "${MATCHED_ALL_CLEAN}") # Remove the spaces, tabs, ...
		
		set(${arg_MSVC} "${MATCHED_ALL_CLEAN}")
	endif()

	return(PROPAGATE ${arg_CLANGCL} ${arg_MSVC})
endfunction()


function (MaxonUpdateProjects_UpdateCMake)
	set(options)
	set(oneValueArgs TargetName ProjectFile CMakeFile Status)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	MaxonUpdateProjects_ParseProjectDefinitionFile(PATH ${arg_ProjectFile}) # Add VERBOSE for print outs.
	
	# Validate Input.
	if (NOT arg_TargetName)
		message(FATAL_ERROR "No target name provided for project file '${ProjectFile}'")
	endif()

	# Load the appropriate template.
	if ("${MAXON_PROJECTOOL_TYPE}" STREQUAL "Lib" OR 
		"${MAXON_PROJECTOOL_TYPE}" STREQUAL "DLL")
		set (generatedContent ${g_libraryTemplate})
	endif()
	
	if(NOT generatedContent)
		# We skip solutions and applications for now.
		message("Skipping target '${arg_TargetName}' because it is of unsupported type '${MAXON_PROJECTOOL_TYPE}'")
		set(${arg_Status} "" PARENT_SCOPE)
		return()
	endif()
	
	# Fill the appropriate template.
	###############################

	get_filename_component(targetSourceDir ${arg_ProjectFile}/.. ABSOLUTE) # 'C:/sdk/frameworks/core.framework/project'
	MaxonUpdateProjects_SetPaths(CMAKE_CURRENT_SOURCE_DIR "${targetSourceDir}" generatedContent)
	
	# --- general ---
	MaxonUpdateProjects_SetValues(maxon_targetName "${arg_TargetName}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_targetType "${MAXON_PROJECTOOL_TYPE}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_targetFrameworkDependencies "${MAXON_PROJECTOOL_APIS}" generatedContent)

	set(targetPublicCompileDefinitions "")
	if (${MAXON_PROJECTOOL_C4D} MATCHES "true")
		list(APPEND targetPublicCompileDefinitions "USE_API_MAXON")
	endif()

	MaxonUpdateProjects_SetValues(maxon_targetPublicCompileDefinitions "${targetPublicCompileDefinitions}" generatedContent)
	
	set(targetPrivateCompileDefinitions "MAXON_CMAKE_BUILD")
	if ((MAXON_PROJECTOOL_TYPE STREQUAL Lib)  AND NOT (${MAXON_PROJECTOOL_OMITAPIDEFINE} MATCHES "true"))
		list(APPEND targetPrivateCompileDefinitions "MAXON_API")
	endif()

	# If provided, we take the defined MODULEID, otherwise we auto-generate it.
	if (NOT MAXON_PROJECTOOL_MODULEID)
		if (${MAXON_PROJECTOOL_C4D} MATCHES "true") # This prevents moduleid collisions when there exists a module with the same name as another module with only ".module" appended.
			set(c4dToken "c4d.")
		endif()
		set(MAXON_PROJECTOOL_MODULEID net.maxon.${c4dToken}${arg_TargetName})
		string(REGEX REPLACE ".module$" "" MAXON_PROJECTOOL_MODULEID "${MAXON_PROJECTOOL_MODULEID}")
	endif()
	if (MAXON_PROJECTOOL_MODULEID)
		list(APPEND targetPrivateCompileDefinitions MAXON_MODULE_ID=\"${MAXON_PROJECTOOL_MODULEID}\")
		string(REPLACE "." "_" targetPrivateModuleId ${MAXON_PROJECTOOL_MODULEID})
	endif()
	MaxonUpdateProjects_SetValues(maxon_targetPrivateCompileDefinitions "${targetPrivateCompileDefinitions}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_targetPlatforms "${MAXON_PROJECTOOL_PLATFORM}" generatedContent)

	list(APPEND targetSourceDirectories source)
	if(${MAXON_PROJECTOOL_TYPE} MATCHES "DLL")
		list(APPEND targetSourceDirectories res)
	endif()
	MaxonUpdateProjects_SetPaths(maxon_targetSourceDirectories "${targetSourceDirectories}" generatedContent)

	list(APPEND targetRegisterGeneratedFileNames register.cpp)
	if(("${MAXON_PROJECTOOL_TYPE}" STREQUAL "DLL") OR (MAXON_PROJECTOOL_FRAMEWORKREGISTRATION))
		list(APPEND targetRegisterGeneratedFileNames interface_registration.cpp)
		if (MAXON_PROJECTOOL_FRAMEWORKREGISTRATION)
			list(APPEND targetRegisterGeneratedFileNames reflection_registration.cpp)
			list(APPEND targetRegisterGeneratedFileNames reflection_virtual_registration.cpp)
		endif()
	endif()
	MaxonUpdateProjects_SetPaths(maxon_targetRegisterGeneratedFileNames "${targetRegisterGeneratedFileNames}" generatedContent)


	# according to documentation if preprocessor values are specified for a platform they overwrite the base values
	set(preprocessorDefinitions       "${MAXON_PROJECTOOL_ADDITIONALPREPROCESSORDEFINITIONS}")
	set(preprocessorDefinitions.WINDOWS   "${MAXON_PROJECTOOL_ADDITIONALPREPROCESSORDEFINITIONS.WIN}")
	set(preprocessorDefinitions.MACOS "${MAXON_PROJECTOOL_ADDITIONALPREPROCESSORDEFINITIONS.OSX}")
	set(preprocessorDefinitions.LINUX   "${MAXON_PROJECTOOL_ADDITIONALPREPROCESSORDEFINITIONS.LINUX}")

	if(NOT preprocessorDefinitions STREQUAL "")
		if (preprocessorDefinitions.WINDOWS STREQUAL "")
			set(preprocessorDefinitions.WINDOWS "${preprocessorDefinitions}")
		elseif(preprocessorDefinitions.MACOS STREQUAL "")
			set(preprocessorDefinitions.MACOS "${preprocessorDefinitions}")
		elseif(preprocessorDefinitions.LINUX STREQUAL "")
			set(preprocessorDefinitions.LINUX "${preprocessorDefinitions}")
		endif()
	elseif(NOT preprocessorDefinitions.${g_maxonTargetOS} STREQUAL "")
		set(preprocessorDefinitions "${preprocessorDefinitions.${g_maxonTargetOS}}")
	endif()

	if (CMAKE_GENERATOR MATCHES "Visual Studio")
		file(GLOB natvisFiles "${targetSourceDir}/*.natvis" "${targetSourceDir}/*/*.natvis" "${targetSourceDir}/*/*/*.natvis") # We limit globbing to 3 levels of depths.
		file(GLOB natjmcFiles "${targetSourceDir}/*.natjmc" "${targetSourceDir}/*/*.natjmc" "${targetSourceDir}/*/*/*.natjmc") # We limit globbing to 3 levels of depths.
		file(GLOB natstepfilterFiles "${targetSourceDir}/*.natstepfilter" "${targetSourceDir}/*/*.natstepfilter" "${targetSourceDir}/*/*/*.natstepfilter") # We limit... yes we know.
		
		list(APPEND typeviewerFiles ${natvisFiles})
		list(APPEND typeviewerFiles ${natjmcFiles})
		list(APPEND typeviewerFiles ${natstepfilterFiles})
	endif()
	MaxonUpdateProjects_SetPaths(maxon_targetTypeViewerFiles "${typeviewerFiles}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalDefinitions "${preprocessorDefinitions}" generatedContent)
	MaxonUpdateProjects_SetBool(maxon_enableExceptionHandling "${MAXON_PROJECTOOL_EXCEPTIONHANDLING}" generatedContent)
	MaxonUpdateProjects_SetBool(maxon_enableRTTI "${MAXON_PROJECTOOL_RUNTIMETYPEINFO}" generatedContent)

	set(MAXON_PROJECTOOL_PREBUILDEVENT.MACOS "${MAXON_PROJECTOOL_SHELLSCRIPT.OSX}")
	set(MAXON_PROJECTOOL_PREBUILDEVENT.WINDOWS "${MAXON_PROJECTOOL_PREBUILDEVENT}")
	set(MAXON_PROJECTOOL_PREBUILDEVENT.WINDOWS.DEBUG "${MAXON_PROJECTOOL_PREBUILDEVENT.DEBUG}")
	set(MAXON_PROJECTOOL_PREBUILDEVENT.WINDOWS.RELEASE "${MAXON_PROJECTOOL_PREBUILDEVENT.RELEASE}")

	set(supportedPlatformSuffixes WINDOWS MACOS LINUX)
	foreach(platform ${supportedPlatformSuffixes})
		foreach(config ${CMAKE_CONFIGURATION_TYPES})
			string(TOUPPER ${config} config_upper)
			set(currentPrebuildEvent ${MAXON_PROJECTOOL_PREBUILDEVENT.${platform}.${config_upper}})
			if("${currentPrebuildEvent}" STREQUAL "")
				if(NOT "${MAXON_PROJECTOOL_PREBUILDEVENT.${platform}}" STREQUAL "")
					set(currentPrebuildEvent "${MAXON_PROJECTOOL_PREBUILDEVENT.${platform}}")
				endif()
			endif()
			#message(INFO "prebuild event for: event ${platform} ${config_upper}: ${currentPrebuildEvent}")
			string(REPLACE "\$CONFIGURATION" ${config_upper} currentPrebuildEvent "${currentPrebuildEvent}")
			MaxonUpdateProjects_ReplacePathPlaceholders("${currentPrebuildEvent}" currentPrebuildEvent)
			string(REPLACE "\\" "\\\\" currentPrebuildEvent "${currentPrebuildEvent}") # Backslashes will be interpreted as escape characters if we don't escape them first.
			string(REPLACE "\"" "\\\"" currentPrebuildEvent "${currentPrebuildEvent}") # Double quotes need to be escaped, so they don't break up the string.
			MaxonUpdateProjects_ReplaceConfigurationSpecificTokens(${config} "${currentPrebuildEvent}" currentPrebuildEvent)
			cmake_language(EVAL CODE "set(currentPrebuildEvent \"${currentPrebuildEvent}\")") # This will evaluate the path variables in our parameter strings.
			string(REPLACE "<<maxon_prebuildEvents.${platform}.${config_upper}>>" "${currentPrebuildEvent}" generatedContent "${generatedContent}") # Add the prebuild events to the cmakelists file.
		endforeach()
	endforeach()

	
	# (FH) Plugins have no external resources, so manually including them is not uncessary but wrong. But we can also not
	# remove all this due to the #c4d_base hack below, so we just keep #resourceIncludePath the empty string and include
	# the empty string below.
	if (NOT "${arg_TargetName}" MATCHES ".framework")
		set(resourceIncludePath "") # Should not have to be explicitly set to empty, but we do it for clarity.
	endif()
	# Sadly this is needed because c4dplugin wants to include hxx files from a framework that it doesn't have a framework dependency.
	# With updateprojects build the generated hxx files are always in a constant location that is used hardcoded in the source. We need to provide an include path instead, since the generated folder could be anywhere.
	if (arg_TargetName STREQUAL "c4d_base")
		message(AUTHOR_WARNING " Adding cinema.framework hxx directory to includes")
		set(cinemaFrameworkHxxDir "${CMAKE_BINARY_DIR}/generated/cinema.framework/hxx")
		Combine2Variables(resourceIncludePath resourceIncludePath cinemaFrameworkHxxDir)
	endif()


	# --- WINDOWS specific ---
	MaxonUpdateProjects_SetPaths(maxon_excludeFromBuild.WINDOWS "${MAXON_PROJECTOOL_EXCLUDEFROMBUILD.WIN}" generatedContent)
	MaxonUpdateProjects_SetPaths(maxon_exclude.WINDOWS "${MAXON_PROJECTOOL_EXCLUDE.WIN}" generatedContent)
	
	MaxonUpdateProjects_SetValues(maxon_additionalDefinitions.WINDOWS "${preprocessorDefinitions.WINDOWS}" generatedContent)

	Combine2Variables(MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES resourceIncludePath)
	string(REPLACE "%(AdditionalIncludeDirectories)" "" MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES "${MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES}")
	MaxonUpdateProjects_SetPaths(maxon_additionalIncludeDirectories.WINDOWS "${MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES}" generatedContent)

	if(DEFINED MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64)
		Combine2Variables(MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64 MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64 resourceIncludePath)
	else()
		set(MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64 ${MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES})
	endif()
	string(REPLACE "%(AdditionalIncludeDirectories)" "" MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64 "${MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64}")
	MaxonUpdateProjects_SetPaths(maxon_additionalIncludeDirectories.WINDOWS.ARM "${MAXON_PROJECTOOL_ADDITIONALINCLUDEDIRECTORIES.WINARM64}" generatedContent)

	Combine2Variables(MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.WIN64)
	Combine2Variables(MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.DEBUG MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.DEBUG MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.WIN64.DEBUG)
	Combine2Variables(MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.RELEASE MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.RELEASE MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.WIN64.RELEASE)

	string(REPLACE ";" "#" MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES "${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES}")
	string(REPLACE ";" "#" MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.DEBUG "${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.DEBUG}")
	string(REPLACE ";" "#" MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.RELEASE "${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.RELEASE}")
	string(REPLACE ";" "#" MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.WINARM64 "${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.WINARM64}")

	MaxonUpdateProjects_SetSpecializedPaths2(
		placeholder maxon_linkLibraries.WINDOWS
		specializations ${CMAKE_CONFIGURATION_TYPES} ARM
		baseValues "${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES}"
		specializedValues \"${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.DEBUG}\" \"${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.RELEASE}\" "${MAXON_PROJECTOOL_ADDITIONALDEPENDENCIES.WINARM64}"
		content generatedContent)

	string(REPLACE "%(AdditionalLibraryDirectories)" "" MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES}")
	string(REPLACE "%(AdditionalLibraryDirectories)" "" MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.DEBUG "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.DEBUG}")
	string(REPLACE "%(AdditionalLibraryDirectories)" "" MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.RELEASE "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.RELEASE}")
	string(REPLACE "%(AdditionalLibraryDirectories)" "" MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.WINARM64 "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.WINARM64}")

	if(NOT CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE STREQUAL "ARM64")
		Combine2Variables(MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.WIN64)
		Combine2Variables(MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.DEBUG MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.DEBUG MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.WIN64.DEBUG)
		Combine2Variables(MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.RELEASE MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.RELEASE MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.WIN64.RELEASE)
	endif()

	MaxonUpdateProjects_SetPaths(maxon_additionalLinkDirectories.WINDOWS "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES}" generatedContent)
	MaxonUpdateProjects_SetSpecializedPaths(maxon_additionalLinkDirectories.WINDOWS .DEBUG "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES}" "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.DEBUG}" generatedContent)
	MaxonUpdateProjects_SetSpecializedPaths(maxon_additionalLinkDirectories.WINDOWS .RELEASE "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES}" "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.RELEASE}" generatedContent)
	MaxonUpdateProjects_SetSpecializedPaths(maxon_additionalLinkDirectories.WINDOWS .ARM "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES}" "${MAXON_PROJECTOOL_ADDITIONALLIBRARYDIRECTORIES.WINARM64}" generatedContent)

	# MaxonUpdateProjects_TransformAdditionalSourcePaths(MAXON_PROJECTOOL_INCLUDE.WIN)
	MaxonUpdateProjects_SetPaths(maxon_additionalSourceFiles.WINDOWS "${MAXON_PROJECTOOL_INCLUDE.WIN}" generatedContent)


	string(REPLACE "%(IgnoreSpecificDefaultLibraries)" "" MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES "${MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES}")
	string(REPLACE "%(IgnoreSpecificDefaultLibraries)" "" MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES.DEBUG "${MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES.DEBUG}")
	string(REPLACE "%(IgnoreSpecificDefaultLibraries)" "" MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES.RELEASE "${MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES.RELEASE}")

	if(g_maxonTargetOS STREQUAL "WINDOWS") 
		string(TOLOWER "${MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES}" clangLinkerFlagsLowerCase)
		string(TOLOWER "${MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES.DEBUG}" clangLinkerFlagsLowerCaseDebug)
		string(TOLOWER "${MAXON_PROJECTOOL_IGNORESPECIFICDEFAULTLIBRARIES.RELEASE}" clangLinkerFlagsLowerCaseRelease)
	endif()

	set(msvcLinkerFlagsLowerCase ${clangLinkerFlagsLowerCase})
	set(msvcLinkerFlagsLowerCaseDebug ${clangLinkerFlagsLowerCaseRelease})
	set(msvcLinkerFlagsLowerCaseRelease ${clangLinkerFlagsLowerCaseDebug})
	
	
	# IgnoreSpecificDefaultLibraries is only supported for WINDOWS not for macOS

	if(g_maxonTargetOS STREQUAL "WINDOWS") 
		set(clangNoDefaultLib "/NODEFAULTLIB:")
		list(TRANSFORM clangLinkerFlagsLowerCase PREPEND ${clangNoDefaultLib})
		list(TRANSFORM clangLinkerFlagsLowerCaseDebug PREPEND ${clangNoDefaultLib})
		list(TRANSFORM clangLinkerFlagsLowerCaseRelease PREPEND ${clangNoDefaultLib})
		list(TRANSFORM clangLinkerFlagsLowerCase APPEND ".lib")
		list(TRANSFORM clangLinkerFlagsLowerCaseDebug APPEND ".lib")
		list(TRANSFORM clangLinkerFlagsLowerCaseRelease APPEND ".lib")
	endif()

	set(msvcNoDefaultLib "-NODEFAULTLIB:")
	list(TRANSFORM msvcLinkerFlagsLowerCase PREPEND ${msvcNoDefaultLib})
	list(TRANSFORM msvcLinkerFlagsLowerCaseDebug PREPEND ${msvcNoDefaultLib})
	list(TRANSFORM msvcLinkerFlagsLowerCaseRelease PREPEND ${msvcNoDefaultLib})
	list(TRANSFORM msvcLinkerFlagsLowerCase APPEND ".lib")
	list(TRANSFORM msvcLinkerFlagsLowerCaseDebug APPEND ".lib")
	list(TRANSFORM msvcLinkerFlagsLowerCaseRelease APPEND ".lib")

	if(g_maxonTargetOS STREQUAL "WINDOWS") 
		if (clangLinkerFlagsLowerCaseDebug STREQUAL "")
			set(clangLinkerFlagsLowerCaseDebug ${clangLinkerFlagsLowerCase})
		endif()
		if (clangLinkerFlagsLowerCaseRelease STREQUAL "")
			set(clangLinkerFlagsLowerCaseRelease ${clangLinkerFlagsLowerCase})
		endif()
	endif()

	if (msvcLinkerFlagsLowerCaseDebug STREQUAL "")
		set(msvcLinkerFlagsLowerCaseDebug ${msvcLinkerFlagsLowerCase})
	endif()
	if (msvcLinkerFlagsLowerCaseRelease STREQUAL "")
		set(msvcLinkerFlagsLowerCaseRelease ${msvcLinkerFlagsLowerCase})
	endif()

	string(REPLACE "%(AdditionalOptions)" "" MAXON_PROJECTOOL_ADDITIONALLINKOPTIONS "${MAXON_PROJECTOOL_ADDITIONALLINKOPTIONS}")
	string(REPLACE "," "$<COMMA>" MAXON_PROJECTOOL_ADDITIONALLINKOPTIONS "${MAXON_PROJECTOOL_ADDITIONALLINKOPTIONS}")
	list(APPEND msvcLinkerFlagsLowerCaseDebug ${MAXON_PROJECTOOL_ADDITIONALLINKOPTIONS})
	list(APPEND msvcLinkerFlagsLowerCaseRelease ${MAXON_PROJECTOOL_ADDITIONALLINKOPTIONS})
	
	set(windowsSubsystem WINDOWS)
	if (${MAXON_PROJECTOOL_SUBSYSTEMCONSOLE} MATCHES "true")
		set(windowsSubsystem CONSOLE)
	endif()
	MaxonUpdateProjects_SetValues(maxon_subsystem.WINDOWS "${windowsSubsystem}" generatedContent)

	# --- MACOS specific ---
	MaxonUpdateProjects_SetPaths(maxon_excludeFromBuild.MACOS "${MAXON_PROJECTOOL_EXCLUDEFROMBUILD.OSX}" generatedContent)
	MaxonUpdateProjects_SetPaths(maxon_exclude.MACOS "${MAXON_PROJECTOOL_EXCLUDE.OSX}" generatedContent)

	MaxonUpdateProjects_SetValues(maxon_additionalDefinitions.MACOS "${preprocessorDefinitions.MACOS}" generatedContent)
	
	Combine2Variables(MAXON_PROJECTOOL_HEADER_SEARCH_PATHS MAXON_PROJECTOOL_HEADER_SEARCH_PATHS MAXON_PROJECTOOL_USER_HEADER_SEARCH_PATHS)
	Combine2Variables(MAXON_PROJECTOOL_HEADER_SEARCH_PATHS MAXON_PROJECTOOL_HEADER_SEARCH_PATHS resourceIncludePath)
	MaxonUpdateProjects_SetPaths(maxon_additionalIncludeDirectories.MACOS "${MAXON_PROJECTOOL_HEADER_SEARCH_PATHS}" generatedContent)

	CombineVariables(MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS MAXON_PROJECTOOL_OTHER_LDFLAGS MAXON_PROJECTOOL_OTHER_LDFLAGS.OSX MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS)
	CombineVariables(MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.DEBUG MAXON_PROJECTOOL_OTHER_LDFLAGS.DEBUG MAXON_PROJECTOOL_OTHER_LDFLAGS.OSX.DEBUG MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.DEBUG)
	CombineVariables(MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.RELEASE MAXON_PROJECTOOL_OTHER_LDFLAGS.RELEASE MAXON_PROJECTOOL_OTHER_LDFLAGS.OSX.RELEASE MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.RELEASE)

	string(REPLACE ";" "#" MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.DEBUG "${MAXON_PROJECTOOL_OTHER_LDFLAGS.DEBUG}")
	string(REPLACE ";" "#" MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.RELEASE "${MAXON_PROJECTOOL_OTHER_LDFLAGS.RELEASE}")
	
	# c4dplugin module  projectdefinition.txt has an additional library dependency that needs to be specifically handled. 
	# By combining the two individual elements "-weak_framework" and the library name "3DconnexionClient" into one tag with a space in between, 
	# we circumvent the automatic addition of an "l" before the library name, which would cause the library file to not be found.
	if (targetName STREQUAL "c4d_base")
		string(REGEX REPLACE "-weak_framework#(.+)" "-weak_framework \\1" MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.DEBUG "${MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.DEBUG}")
		string(REGEX REPLACE "-weak_framework#(.+)" "-weak_framework \\1" MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.RELEASE "${MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.RELEASE}")
	endif()

	MaxonUpdateProjects_SetSpecializedPaths2(
		placeholder maxon_linkLibraries.MACOS 
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS}"
		specializedValues "${MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.DEBUG}" "${MAXON_PROJECTOOL_OTHER_LDFLAGS.MACOS.RELEASE}" 
		content generatedContent)
 
	MaxonUpdateProjects_SetFrameworks(maxon_linkFrameworks.MACOS "${MAXON_PROJECTOOL_FRAMEWORKS.OSX}" generatedContent)
	
	# MaxonUpdateProjects_TransformAdditionalSourcePaths(MAXON_PROJECTOOL_INCLUDE.MACOS)
	MaxonUpdateProjects_SetPaths(maxon_additionalSourceFiles.MACOS "${MAXON_PROJECTOOL_INCLUDE.OSX}" generatedContent)

	# --- LINUX specific ---
	MaxonUpdateProjects_SetPaths(maxon_excludeFromBuild.LINUX "${MAXON_PROJECTOOL_EXCLUDE.LINUX}" generatedContent)
	MaxonUpdateProjects_SetPaths(maxon_exclude.LINUX "${MAXON_PROJECTOOL_EXCLUDE.LINUX}" generatedContent)

	Combine2Variables(MAXON_PROJECTOOL_LIBRARIES MAXON_PROJECTOOL_LIBRARIES MAXON_PROJECTOOL_LIBRARIES.LINUX)
	Combine2Variables(MAXON_PROJECTOOL_LIBRARIES MAXON_PROJECTOOL_LIBRARIES MAXON_PROJECTOOL_STATICLIBRARIES.LINUX)
	Combine2Variables(MAXON_PROJECTOOL_LIBRARIES.DEBUG MAXON_PROJECTOOL_LIBRARIES.DEBUG MAXON_PROJECTOOL_LIBRARIES.LINUX.DEBUG)
	Combine2Variables(MAXON_PROJECTOOL_LIBRARIES.RELEASE MAXON_PROJECTOOL_LIBRARIES.RELEASE MAXON_PROJECTOOL_LIBRARIES.LINUX.RELEASE)

	string(REPLACE ";" "#" MAXON_PROJECTOOL_LIBRARIES.DEBUG "${MAXON_PROJECTOOL_LIBRARIES.DEBUG}")
	string(REPLACE ";" "#" MAXON_PROJECTOOL_LIBRARIES.RELEASE "${MAXON_PROJECTOOL_LIBRARIES.RELEASE}")

	MaxonUpdateProjects_SetSpecializedPaths2(
		placeholder maxon_linkLibraries.LINUX
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${MAXON_PROJECTOOL_LIBRARIES}"
		specializedValues "${MAXON_PROJECTOOL_LIBRARIES.DEBUG}" "${MAXON_PROJECTOOL_LIBRARIES.RELEASE}"
		content generatedContent)

	Combine2Variables(MAXON_PROJECTOOL_LIBRARYSEARCHPATH MAXON_PROJECTOOL_LIBRARYSEARCHPATH MAXON_PROJECTOOL_LIBRARYSEARCHPATH.LINUX)
	Combine2Variables(MAXON_PROJECTOOL_LIBRARYSEARCHPATH.DEBUG MAXON_PROJECTOOL_LIBRARYSEARCHPATH.DEBUG MAXON_PROJECTOOL_LIBRARYSEARCHPATH.LINUX.DEBUG)
	Combine2Variables(MAXON_PROJECTOOL_LIBRARYSEARCHPATH.RELEASE MAXON_PROJECTOOL_LIBRARYSEARCHPATH.RELEASE MAXON_PROJECTOOL_LIBRARYSEARCHPATH.LINUX.RELEASE)

	string(REPLACE ";" "#" MAXON_PROJECTOOL_LIBRARYSEARCHPATH.DEBUG "${MAXON_PROJECTOOL_LIBRARYSEARCHPATH.DEBUG}")
	string(REPLACE ";" "#" MAXON_PROJECTOOL_LIBRARYSEARCHPATH.RELEASE "${MAXON_PROJECTOOL_LIBRARYSEARCHPATH.RELEASE}")

	MaxonUpdateProjects_SetSpecializedPaths2(
		placeholder maxon_additionalLinkDirectories.LINUX
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${MAXON_PROJECTOOL_LIBRARYSEARCHPATH}"
		specializedValues "${MAXON_PROJECTOOL_LIBRARYSEARCHPATH.DEBUG}" "${MAXON_PROJECTOOL_LIBRARYSEARCHPATH.RELEASE}"
		content generatedContent)

	# MaxonUpdateProjects_TransformAdditionalSourcePaths(MAXON_PROJECTOOL_INCLUDE.LINUX)
	MaxonUpdateProjects_SetPaths(maxon_additionalSourceFiles.LINUX "${MAXON_PROJECTOOL_INCLUDE.LINUX}" generatedContent)
	MaxonUpdateProjects_SetPaths(maxon_systemIncludePaths "${MAXON_PROJECTOOL_SYSTEMINCLUDEPATHS}" generatedContent)

	Combine2Variables(MAXON_PROJECTOOL_INCLUDEPATHS MAXON_PROJECTOOL_INCLUDEPATHS resourceIncludePath)
	MaxonUpdateProjects_SetPaths(maxon_additionalIncludeDirectories.LINUX "${MAXON_PROJECTOOL_INCLUDEPATHS}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalDefinitions.LINUX "${preprocessorDefinitions.LINUX}" generatedContent)

	#-----------------------------------------------------------------------------
	# --- Compiler specific ---
	#-----------------------------------------------------------------------------

	#-----------------------------------
	# --- Windows: MSVC ----------------
	#-----------------------------------

	# It is our understanding that BUILD.template::cinemake//config:win_x64_msvc overrules AdditionalCompileOptions.Win64
	# but either later gets combined with DisableSpecificWarnings.Win64.
	# According to bazel_generator.py::generate_build_file() bazel-defined values overrule and replace their projectdefinition.txt counterpart.
	string(REPLACE "%(AdditionalOptions)" "" MAXON_PROJECTOOL_ADDITIONALCOMPILEOPTIONS.WIN64 "${MAXON_PROJECTOOL_ADDITIONALCOMPILEOPTIONS.WIN64}")
	cmake_path(SET bazelTemplateFile NORMALIZE "${arg_ProjectFile}/../../BUILD.template")
	MaxonUpdateProjects_ParseBazelTemplateFileForWarnings(PATH ${bazelTemplateFile} CLANGCL BAZELOPTIONS.CLANGCL MSVC BAZELOPTIONS.MSVC)
	if (BAZELOPTIONS.MSVC)
		set(ADDITIONALCOMPILEOPTIONS.WIN64 "${BAZELOPTIONS.MSVC}")
	else()
		set(ADDITIONALCOMPILEOPTIONS.WIN64 "${MAXON_PROJECTOOL_ADDITIONALCOMPILEOPTIONS.WIN64}")
	endif()

	# MSVC: We combine DisableSpecificWarnings.Win64 + cinemake//config:win_x64_msvc or AdditionalCompileOptions.Win64
	string(REPLACE ";%(DisableSpecificWarnings)" "" MAXON_PROJECTOOL_DISABLESPECIFICWARNINGS.WIN64 "${MAXON_PROJECTOOL_DISABLESPECIFICWARNINGS.WIN64}")
	list(TRANSFORM MAXON_PROJECTOOL_DISABLESPECIFICWARNINGS.WIN64 PREPEND "/wd" OUTPUT_VARIABLE MAXON_PROJECTOOL_DISABLESPECIFICWARNINGS.WIN64)
	CombineVariables(ADDITIONALCOMPILEOPTIONS.WIN64 MAXON_PROJECTOOL_DISABLESPECIFICWARNINGS.WIN64 ADDITIONALCOMPILEOPTIONS.WIN64)
	MaxonUpdateProjects_SetValues(maxon_additionalCompileOptions.MSVC.CPP "${ADDITIONALCOMPILEOPTIONS.WIN64}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalCompileOptions.MSVC.C "${ADDITIONALCOMPILEOPTIONS.WIN64}" generatedContent)
	# Note that CMake automatically populates 'DisableSpecificWarnings' in VS for the appropriate options.

	#-----------------------------------
	# --- macOS: Clang -----------------
	#-----------------------------------

	# WARNING_CFLAGS in contrast to its name, is applied to both C and CPP files.
	# We ignore this because we consider the Bazel Clang settings to be more accurate and apply them everywhere.
	
	#-----------------------------------
	# --- any: Clang -------------------
	#-----------------------------------

	if(MAXON_PROJECTOOL_CLANG_WARN_DOCUMENTATION_COMMENTS STREQUAL "NO")
		set(BAZELOPTIONS.CLANGCL "-Wno-documentation;${BAZELOPTIONS.CLANGCL}")
	endif()
	MaxonUpdateProjects_SetValues(maxon_additionalCompileOptions.CLANG.CPP "${BAZELOPTIONS.CLANGCL}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalCompileOptions.CLANG.C "${BAZELOPTIONS.CLANGCL}" generatedContent)

	#-----------------------------------
	# --- Linux: GCC -------------------
	#-----------------------------------
	MaxonUpdateProjects_SetValues(maxon_additionalCompileOptions.GNU.CPP "${MAXON_PROJECTOOL_ADDITIONALCOMPILEOPTIONS.LINUX.C++}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalCompileOptions.GNU.C "${MAXON_PROJECTOOL_ADDITIONALCOMPILEOPTIONS.LINUX.C}" generatedContent)

	#-----------------------------------------------------------------------------
	# --- Linker specific ---
	#-----------------------------------------------------------------------------
	MaxonUpdateProjects_SetValues(maxon_additionalLinkerOptions.CLANG.DEBUG "${clangLinkerFlagsLowerCaseDebug}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalLinkerOptions.CLANG.RELEASE "${clangLinkerFlagsLowerCaseRelease}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalLinkerOptions.MSVC.DEBUG "${msvcLinkerFlagsLowerCaseDebug}" generatedContent)
	MaxonUpdateProjects_SetValues(maxon_additionalLinkerOptions.MSVC.RELEASE "${msvcLinkerFlagsLowerCaseRelease}" generatedContent)

	###############################
	# Validate the completeness of the fill.
	string(REGEX MATCH "<<(.*)>>" invalidSequence ${generatedContent})
	if (invalidSequence)
		message(FATAL_ERROR "${targetName}: Incomplete fill of the template detect. Make sure to remove all <<T>> sequences.\n${generatedContent}")
	endif()

	# Load current CMake file.
	if (EXISTS ${arg_CMakeFile})
		file(READ ${arg_CMakeFile} savedContent)
	endif()
	
	# Update if needed.
	string(COMPARE NOTEQUAL "${savedContent}" "${generatedContent}" contentsDiffer)
	if (contentsDiffer)
		message(STATUS "Updating CMake file for '${arg_TargetName}'")
		file(WRITE ${arg_CMakeFile} "${generatedContent}")
	else()
		#message(STATUS "Skipping update to CMake file for '${arg_TargetName}'")
	endif()
	
	set(${arg_Status} 1 PARENT_SCOPE)
endfunction()

function (MaxonUpdateProjects_Execute arg_UsedFrameworks arg_FrameworkPaths arg_ProjectDirectories)

	message(STATUS "Starting Update Projects.")

	MaxonUpdateProjects_CollectProjectDefinitionFiles(ProjectDirectories ${arg_ProjectDirectories} ProjectDefinitionFiles ProjectDefinitionFiles)
	set(frameWorkPaths "")
	foreach(entry IN LISTS ProjectDefinitionFiles)
		string(REPLACE "#" ";" tokens ${entry})

		list (GET tokens 0 entryParentDirectory)
		list (GET tokens 1 entryRelativeDirectory)
		
		get_filename_component(entryFile ${entryParentDirectory}/${entryRelativeDirectory} ABSOLUTE) # 'C:/sdk/frameworks/core.framework/project/projectdefinition.txt'
		get_filename_component(entryProjectDirectory ${entryFile}/.. ABSOLUTE) # 'C:/sdk/frameworks/core.framework/project'
		get_filename_component(entryDirectory ${entryFile}/../.. ABSOLUTE) # 'C:/sdk/frameworks/core.framework'
		file(RELATIVE_PATH entryName ${entryParentDirectory} ${entryDirectory}) # 'frameworks/core.framework'
		get_filename_component(targetName ${entryDirectory} NAME) # 'core.framework'
		get_filename_component(entryCMakeFile ${entryProjectDirectory}/CMakeLists.txt ABSOLUTE) # 'C:/sdk/frameworks/core.framework/project/CMakeLists.txt' (Optional)
		get_filename_component(entryCMakeDirectory ${CMAKE_BINARY_DIR}/${entryName}/project ABSOLUTE) # 'C:/sdk_build/frameworks/core.framework'

		set(project_source_dir "")
		set(project_binary_dir "")

		if (EXISTS ${entryCMakeFile})
			set(project_source_dir ${entryProjectDirectory})
			set(project_binary_dir ${entryCMakeDirectory})
			# As a user override we just load the defined CMakeLists.txt file.
			message(STATUS "Loading CMake file for '${entryName}'")
		else()
			set(project_source_dir ${entryCMakeDirectory})
			set(project_binary_dir ${entryCMakeDirectory})

			# We generate a CMakeLists.txt in the binary folder based on information in the projectdefinition.txt file.
			#message(STATUS "Parsing definition for '${entryName}'")
			get_filename_component(entryCMakeFile ${entryCMakeDirectory}/CMakeLists.txt ABSOLUTE) # 'C:/sdk_build/frameworks/core.framework/CMakeLists.txt'

			MaxonUpdateProjects_UpdateCMake(TargetName ${targetName} ProjectFile ${entryFile} CMakeFile ${entryCMakeFile} Status CMakeStatus)

			if (NOT CMakeStatus)
				# No CMake file was created. Possibly, because it defines an application or solution type.
				continue()
			endif()
		endif()  

		# We add the project.      
		set(maxon_targetFrameworkDependencies "")
		add_subdirectory(${project_source_dir} ${project_binary_dir}) # unfortunately not working: get_target_property(targetDependencies ${targetName} LINK_LIBRARIES)
		
		# We create a unique list of all frameworks that plugins directly depend upon.
		list(APPEND maxon_usedFrameworks ${maxon_targetFrameworkDependencies})

	endforeach()

	set(${arg_UsedFrameworks} "${maxon_usedFrameworks}" PARENT_SCOPE)
	set(${arg_FrameworkPaths} "${frameworkPaths}" PARENT_SCOPE)
	
endfunction()

function(MaxonUpdateProjects_GetUsedFrameworks arg_UsedFrameworks)
	set (frameworksToCreate "")

	while (arg_UsedFrameworks)
		list(REMOVE_DUPLICATES arg_UsedFrameworks)
		
		# We add the frameworks and collect their dependencies for the next iteration, to resolve transitive dependencies.
		set(new_maxon_usedFrameworks "")
		foreach(framework IN LISTS arg_UsedFrameworks)
			if (${framework} IN_LIST frameworksToCreate)
				# We have already encountered this framework.
				continue()
			endif()

			# We collect the framework for later ordered creation.
			list(APPEND frameworksToCreate ${framework})

			# We peek into the frameworks' CMake files and extract the framwork dependencies to handle transitivity.
			set(maxon_targetFrameworkDependencies "")

			MaxonUpdateProjects_GetProjectFrameworks(ProjectFile "${MAXON_FRAMEWORKS_DIR}/${framework}/project/projectdefinition.txt" Frameworks maxon_targetFrameworkDependencies)

			list(APPEND new_maxon_usedFrameworks ${maxon_targetFrameworkDependencies}) # maxon_targetFrameworkDependencies is populated by CMakeLists.txt
		
		endforeach()
		set(arg_UsedFrameworks ${new_maxon_usedFrameworks})
	endwhile()

	# In order to create an alphabetical list of frameworks in Xcode we must sort add_subdirectory() order.
	list(SORT frameworksToCreate)
	set(fullSortedFrameworksList "${frameworksToCreate}" PARENT_SCOPE)
endfunction()


function(MaxonUpdateProjects_LoadFrameworks arg_Frameworks)
	list(TRANSFORM arg_Frameworks PREPEND "${MAXON_FRAMEWORKS_DIR}/" OUTPUT_VARIABLE usedFrameworkSourceDirs)
	MaxonUpdateProjects_Initialize(usedFrameworks usedFrameworkPaths "${usedFrameworkSourceDirs}")
endfunction()


function (MaxonUpdateProjects_GetProjectFrameworks)
	set(options)
	set(oneValueArgs ProjectFile Frameworks)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	MaxonUpdateProjects_ParseProjectDefinitionFile(PATH ${arg_ProjectFile}) # Add VERBOSE for print outs.

	set(frameworks "${MAXON_PROJECTOOL_APIS}")

	# Return Values.
	set(${arg_Frameworks} "${frameworks}" PARENT_SCOPE)

endfunction()

# Normalizes the directory path and checks if it is a directory and exists when parsing a paths file.
# Explicitly meant to be used by #ReadCustomPaths below.
function(NormalizeDirectoryPath line root directoryPath)

    set(dirPath "${${directoryPath}}")
    if(NOT IS_ABSOLUTE "${dirPath}")
        set(dirPath "${root}/${dirPath}")
    endif()

    cmake_path(NORMAL_PATH dirPath)
    if(NOT IS_ABSOLUTE "${dirPath}")
        message(FATAL_ERROR "In '${line}': '${dirPath}' is not an absolute path.")
    endif()

    if(NOT IS_DIRECTORY "${dirPath}")
		set(temp "${dirPath}/")
		if(NOT IS_DIRECTORY "${temp}")
        	message(FATAL_ERROR "In '${line}': '${dirPath}' is not a directory.")
		else()
			set(dirPath "${temp}")
		endif()
    elseif(NOT EXISTS "${dirPath}")
        message(FATAL_ERROR "In '${line}': '${dirPath}' does not exist.")
    endif()

    set(${directoryPath} "${dirPath}" PARENT_SCOPE)
endfunction()

# Reads module paths and path variables from a custom paths file.
function(ReadCustomPaths paths_file out_modules out_symbols)
	if(NOT EXISTS ${paths_file})
		message(FATAL_ERROR "The paths file '${paths_file}' does not exist.")
	endif()

	message(STATUS "Reading path definitions: ${paths_file}")
	file(STRINGS ${paths_file} lines)

	set(modules "")
	set(aliases "")
	set(current_root "${MAXON_SDK_ROOT_DIR}")

	set(comment_pattern "^[ \t]*#.*")
	set(ws_pattern "^[ \t]*$")
	set(root_pattern "^[ \t]*ROOT[ \t]+(.*)")
	set(module_pattern "^[ \t]*MODULE[ \t]+(.*)")
	set(alias_pattern "^[ \t]*ALIAS[ \t]+([A-Za-z0-9_]+)[ \t]+(.*)")

	foreach(line ${lines})

		# Step over comments and empty lines.
		string(STRIP "${line}" line)
		if(line MATCHES "${comment_pattern}" OR line MATCHES "${ws_pattern}")
			continue()
		endif()

		# Parse root commands
		if(line MATCHES "${root_pattern}")
			string(REGEX REPLACE "${root_pattern}" "\\1" new_root "${line}")
			NormalizeDirectoryPath("${line}" "" new_root)
			
		# Parse module commands
		elseif(line MATCHES "${module_pattern}")
			string(REGEX REPLACE "${module_pattern}" "\\1" modulePath "${line}")
			NormalizeDirectoryPath("${line}" "${current_root}" modulePath)

			list(FIND modules "${modulePath}" index)
			if(index EQUAL -1)
				list(APPEND modules "${modulePath}")
			else()
				message("In '${line}': Stepping over duplicate include.")
			endif()
			
		# Parse alias commands
		elseif(line MATCHES "${alias_pattern}")
			string(REGEX REPLACE "${alias_pattern}" "\\1" alias "${line}")
			string(REGEX REPLACE "${alias_pattern}" "\\2" dirPath "${line}")
			NormalizeDirectoryPath("${line}" "${current_root}" dirPath)
			
			# Expose the variable with the USER_PATH_ prefix.
			set("USER_${alias}" "${dirPath}" CACHE PATH "User path for the symbol ${alias}.")
			list(APPEND aliases "${alias}")
		else()
			message(FATAL_ERROR "In '${line}': Critical error: Unrecognized command.")
		endif()
	endforeach()

	if(aliases)
		string(JOIN " " msg ${aliases})
		message(STATUS "Set path variables: ${msg}")
	endif()
	if (modules)
		string(JOIN " " msg ${modules})
		message(STATUS "Read module paths: ${msg}")
	endif()

	set(${out_symbols} ${aliases} PARENT_SCOPE)
	set(${out_modules} ${modules} PARENT_SCOPE)
endfunction()

set(g_maxonCMakeDirectory ${CMAKE_CURRENT_LIST_DIR})

set(MAXONUPDATEPROJECTS_INCLUDED ON)
