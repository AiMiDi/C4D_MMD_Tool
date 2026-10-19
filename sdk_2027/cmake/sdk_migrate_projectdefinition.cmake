if(SDK_MIGRATE_PROJECTDEFINITION_INCLUDED)
		return()
endif()

function(MigrateProjectDefinition_Combine2Variables varResult var1 var2)
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

function(MigrateProjectDefinition_CombineVariables resultVar)
	set(resultValue "")
	foreach(arg IN LISTS ARGN)
		if(NOT "${${arg}}" STREQUAL "")
			list(APPEND resultValue "${${arg}}")
		endif()
	endforeach()
	set(${resultVar} "${resultValue}" PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_StripStrings list result)
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

function(MigrateProjectDefinition_ParseProjectDefinitionFile)
	set(options VERBOSE DONTFAILONMISSINGDEF)
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
	string(REGEX REPLACE "(^|\n)[ \t]*\/\/[^\n]*" "\\1" lines "${lines}") # Strip full-line comments like '// strip me'
	string(REGEX REPLACE "[ \t]\/\/[^\n]*" "" lines "${lines}") # Strip inline comments like 'value // comment' (space/tab before // distinguishes from // in paths)
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
			MigrateProjectDefinition_StripStrings("${TOKEN_VALUES}" TOKEN_VALUES) # We now strip the leading and trailing whitespace for each value in the list.
			set(PROJ_DEF_${TOKEN_ID} "${TOKEN_VALUES}" PARENT_SCOPE)
		
		# Filter out the source processor call from the prebuild events since we are already always doing the source processor anyways.
		else()
			string(STRIP "${TOKEN_VALUES}" TOKEN_VALUES)
			string(REPLACE "&&" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			string(REPLACE "&" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			string(REPLACE ";amp#;amp#" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			string(REPLACE ";amp#" ";" TOKEN_VALUES "${TOKEN_VALUES}") # Make the prebuild events params into an iterable list
			set(prebuildEventsNoSourceProcessor "")
			foreach(token IN LISTS TOKEN_VALUES)
				if(token MATCHES "sourceprocessor\\.py") # Skip the source processor entry
					continue()
				endif()
				list(APPEND prebuildEventsNoSourceProcessor "${token}")
			endforeach()
			set(TOKEN_VALUES "${prebuildEventsNoSourceProcessor}")
			set(PROJ_DEF_${TOKEN_ID} "${TOKEN_VALUES}" PARENT_SCOPE)
		endif()
		
		if(arg_VERBOSE)
			message(STATUS "Line: '${TOKEN_ID}=${TOKEN_VALUES}'")
		endif()

	endforeach()

	if(arg_VERBOSE)
			message(STATUS "")
	endif()

endfunction()

function(MigrateProjectDefinition_SetBool placeholder value content)
	if (${value})
		set(value ON)
	else()
		set(value OFF)
	endif()
	string(REPLACE "<<${placeholder}>>" "${value}" newContent "${${content}}")
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_SetValues placeholder values content)
	list(REMOVE_DUPLICATES values)
	list(LENGTH values numValues)
	if (numValues GREATER 1) # split if there's multiple items
		list(JOIN values "" joinedValues)
		string(LENGTH "${joinedValues}" joinedLength)
		if (joinedLength GREATER 100)
			list(TRANSFORM values PREPEND "\n  ")
			list(APPEND values "\n")
		else()
			# A space for shorter lines
			list(TRANSFORM values PREPEND " ")
		endif()
	endif()
	list(JOIN values "" values)
	string(STRIP "${values}" values)
	if ("${values}" STREQUAL "")
		string(REGEX REPLACE "[^\n]*<<${placeholder}>>[^\n]*\n?" "" newContent "${${content}}")
	else()
		string(REPLACE "<<${placeholder}>>" "${values}" newContent "${${content}}")
	endif()
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_ListToJsonArray list result)
	set(json_array "[]")
	set(idx 0)
	foreach(item IN LISTS list)
		string(REGEX REPLACE "^\"(.*)\"$" "\\1" item "${item}")
		string(JSON json_array SET "${json_array}" ${idx} "\"${item}\"")
		math(EXPR idx "${idx} + 1")
	endforeach()
	set(${result} "${json_array}" PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_ReplacePathPlaceholders values output)
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

function(MigrateProjectDefinition_NormalizeDirectoryPath line root directoryPath)
	set(path "${${directoryPath}}")
	if(NOT IS_ABSOLUTE "${path}")
		set(path "${root}/${path}")
	endif()
	cmake_path(NORMAL_PATH path)
	if(NOT IS_ABSOLUTE "${path}" OR NOT IS_DIRECTORY "${path}")
		message(FATAL_ERROR "In '${line}': '${path}' is not an existing directory.")
	endif()
	set(${directoryPath} "${path}" PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_ParseCustomPathsFile)
	set(options VERBOSE)
	set(oneValueArgs PATH ROOT_DIR MODULES_RESULT ALIASES_RESULT)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "" ${ARGN})

	if(NOT arg_PATH OR NOT EXISTS "${arg_PATH}")
		message(FATAL_ERROR "Custom paths file does not exist: '${arg_PATH}'")
	endif()

	set(current_root "${arg_ROOT_DIR}")
	if(NOT current_root)
		set(current_root "${MAXON_SDK_ROOT_DIR}")
	endif()
	MigrateProjectDefinition_NormalizeDirectoryPath("ROOT ${current_root}" "" current_root)

	set(modules)
	set(aliases)
	set(comment_pattern "^[ \t]*#.*")
	set(ws_pattern "^[ \t]*$")
	set(root_pattern "^[ \t]*ROOT[ \t]+(.*)")
	set(module_pattern "^[ \t]*MODULE[ \t]+(.*)")
	set(alias_pattern "^[ \t]*ALIAS[ \t]+([A-Za-z0-9_]+)[ \t]+(.*)")
	file(STRINGS "${arg_PATH}" lines)
	foreach(line IN LISTS lines)
		string(STRIP "${line}" line)
		if(line MATCHES "${comment_pattern}" OR line MATCHES "${ws_pattern}")
			continue()
		elseif(line MATCHES "${root_pattern}")
			string(REGEX REPLACE "${root_pattern}" "\\1" new_root "${line}")
			MigrateProjectDefinition_NormalizeDirectoryPath("${line}" "${current_root}" new_root)
			set(current_root "${new_root}")
		elseif(line MATCHES "${module_pattern}")
			string(REGEX REPLACE "${module_pattern}" "\\1" module_path "${line}")
			MigrateProjectDefinition_NormalizeDirectoryPath("${line}" "${current_root}" module_path)
			list(FIND modules "${module_path}" module_index)
			if(module_index EQUAL -1)
				list(APPEND modules "${module_path}")
			elseif(arg_VERBOSE)
				message(STATUS "Skipping duplicate module path '${module_path}'.")
			endif()
		elseif(line MATCHES "${alias_pattern}")
			string(REGEX REPLACE "${alias_pattern}" "\\1" alias "${line}")
			string(REGEX REPLACE "${alias_pattern}" "\\2" alias_path "${line}")
			MigrateProjectDefinition_NormalizeDirectoryPath("${line}" "${current_root}" alias_path)
			set("USER_${alias}" "${alias_path}" CACHE PATH "User path for the symbol ${alias}.")
			list(APPEND aliases "${alias}")
		else()
			message(FATAL_ERROR "In '${line}': unrecognized custom path command.")
		endif()
	endforeach()

	set(MAXON_SDK_PATH_ALIASES "${aliases}" PARENT_SCOPE)
	set(${arg_MODULES_RESULT} "${modules}" PARENT_SCOPE)
	set(${arg_ALIASES_RESULT} "${aliases}" PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_DiscoverModules)
	set(options VERBOSE)
				string(REGEX REPLACE "${alias_pattern}" "\\1" alias "${line}")
				string(REGEX REPLACE "${alias_pattern}" "\\2" alias_path "${line}")

	if(NOT arg_MODULES_DIR)
		set(arg_MODULES_DIR "${MAXON_SDK_ROOT_DIR}/plugins")
	endif()
	set(module_paths)
	if(arg_CUSTOM_PATHS_FILE AND EXISTS "${arg_CUSTOM_PATHS_FILE}")
		MigrateProjectDefinition_ParseCustomPathsFile(
			PATH "${arg_CUSTOM_PATHS_FILE}"
			ROOT_DIR "${MAXON_SDK_ROOT_DIR}"
			MODULES_RESULT module_paths
			ALIASES_RESULT path_aliases
			VERBOSE ${arg_VERBOSE}
		)
		set(MAXON_SDK_PATH_ALIASES "${path_aliases}")
	endif()

	if(NOT module_paths)
		file(GLOB module_candidates LIST_DIRECTORIES true "${arg_MODULES_DIR}/*")
		foreach(module_path IN LISTS module_candidates)
			if(IS_DIRECTORY "${module_path}")
				list(APPEND module_paths "${module_path}")
			endif()
		endforeach()
	endif()

	list(REMOVE_DUPLICATES module_paths)
	set(MAXON_SDK_PATH_ALIASES "${MAXON_SDK_PATH_ALIASES}" PARENT_SCOPE)
	foreach(module_path IN LISTS module_paths)
		set(project_path "${module_path}/project")
		set(cmake_file "${project_path}/CMakeLists.txt")
		set(project_definition "${project_path}/projectdefinition.txt")
		if(NOT EXISTS "${cmake_file}")
			if(NOT EXISTS "${project_definition}")
				message(FATAL_ERROR "Module '${module_path}' has neither '${cmake_file}' nor '${project_definition}'.")
			endif()
			get_filename_component(target_name "${module_path}" NAME)
			MigrateProjectDefinition_UpdateProject(
				TargetName "${target_name}"
				ProjectFile "${project_definition}"
				CMakeFile "${cmake_file}"
				Status migration_status
			)
			if(NOT migration_status OR NOT EXISTS "${cmake_file}")
				message(FATAL_ERROR "Could not migrate module '${module_path}'.")
			endif()
		endif()

		get_filename_component(module_name "${module_path}" NAME)
		string(SHA256 module_hash "${module_path}")
		string(SUBSTRING "${module_hash}" 0 12 module_hash)
		string(REGEX REPLACE "[^A-Za-z0-9_]" "_" binary_name "${module_name}")
		add_subdirectory("${project_path}" "${CMAKE_BINARY_DIR}/modules/${binary_name}_${module_hash}")
	endforeach()
endfunction()

function(MigrateProjectDefinition_FixRPaths values output)
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

function(MigrateProjectDefinition_SetPaths placeholder values content)
	list(REMOVE_DUPLICATES values)
	MigrateProjectDefinition_FixRPaths("${values}" values)
	set(escapesValues)
	foreach(p IN LISTS values)
		if(NOT p STREQUAL "" AND NOT "${p}" MATCHES "^(@|-rpath)")
			cmake_path(SET p NORMALIZE "${p}")
		endif()
		string(FIND "${p}" " " containsSpaces)
		if (NOT containsSpaces EQUAL -1)
			set(p "\"${p}\"")
		endif()
		if ("${p}" MATCHES "^\\.\\./\\.\\./" AND NOT MAXON_PROJECTDEFINITION_AUTOGEN_PERSIST) # c4dplugin makes includes to other frameworks and modules. We must root these relative paths.
			set(p "\$\{CMAKE_CURRENT_SOURCE_DIR}/${p}")
		endif()
		list(APPEND escapesValues "${p}")
	endforeach()
	set(values ${escapesValues})
	list(LENGTH values numValues)
	if (numValues GREATER 1) # split if there's multiple items
		list(JOIN values "" joinedValues)
		string(LENGTH "${joinedValues}" joinedLength)
		if (joinedLength GREATER 100)
			list(TRANSFORM values PREPEND "\n  ")
			list(APPEND values "\n")
		else()
			# A space for shorter lines
			list(TRANSFORM values PREPEND " ")
		endif()
	endif()
	list(JOIN values "" values)

	MigrateProjectDefinition_ReplacePathPlaceholders("${values}" values)

	string(STRIP "${values}" values)
	if (NOT values)
		string(REGEX REPLACE "[^\n]*<<${placeholder}>>[^\n]*\n?" "" newContent "${${content}}")
	else()
		string(REPLACE "<<${placeholder}>>" "${values}" newContent "${${content}}")
	endif()
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_SetSpecializedPaths placeholder specialized baseValues specializedValues content)
	if(specializedValues AND NOT "${baseValues}" STREQUAL "${specializedValues}")
		MigrateProjectDefinition_SetPaths(${placeholder}${specialized} "${specializedValues}" generatedContent)
	elseif(baseValues)
		MigrateProjectDefinition_SetValues(${placeholder}${specialized} "\$\{${placeholder}}" generatedContent)
	else()
		MigrateProjectDefinition_SetValues(${placeholder}${specialized} "" generatedContent)
	endif()
	set(${content} ${generatedContent} PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_ReplaceConfigurationSpecificTokens configuration pathStrings output)
	#message("replacement function input: ${pathStrings}")
	string(REGEX REPLACE "\\$\\(\\MAXON_BIN_PATH\\)" "\${CMAKE_BINARY_DIR}/bin/${configuration}" pathStrings "${pathStrings}")
	string(REPLACE "\$CONFIGURATION" ${configuration} pathStrings "${pathStrings}")
	set(${output} "${pathStrings}" PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_SetSpecializedPaths2)
	set(options)
	set(oneValueArgs placeholder content)
	set(multiValueArgs baseValues specializations specializedValues)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	#message("")
	#message(" arg_specializations  : ${arg_specializations}")
	#message(" arg_baseValues       : ${arg_baseValues}")
	#message(" arg_specializedValues: _${arg_specializedValues}_")

	if (DEFINED arg_UNPARSED_ARGUMENTS)
		message(FATAL_ERROR "Unparsed Arguments in MigrateProjectDefinition_SetSpecializedPaths2: ${arg_UNPARSED_ARGUMENTS}\n")
	endif()

	# We determine the specialized values
	set(specialization_names)
	set(specialization_values)
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

		MigrateProjectDefinition_ReplaceConfigurationSpecificTokens(${specialization} "${specializedValue}" specializedValue)

		string(TOUPPER ${specialization} specialization_upper)

		list(APPEND specialization_names ${specialization_upper})
		
		string(REPLACE ";" "#" specializedValue "${specializedValue}")
		list(APPEND specialization_values "${specializedValue}")
	endforeach()

	set(processed_names)
	set(processed_values)
	foreach(specialization_name specialization_value IN ZIP_LISTS specialization_names specialization_values)

		# We search for a previous value that matches the current one. If we find one, we use it instead.
		set(matched_previous "")
		foreach(prev_name prev_value IN ZIP_LISTS processed_names processed_values)
			if("${specialization_value}" STREQUAL "${prev_value}")
				set(matched_previous "${prev_name}")
				break()
			endif()
		endforeach()

		if(NOT "${matched_previous}" STREQUAL "" AND NOT "${specialization_value}" STREQUAL "")
			MigrateProjectDefinition_SetValues(${arg_placeholder}.${specialization_name} "\$\{${arg_placeholder}.${matched_previous}}" generatedContent)
		else()
			# We unfold the list and assign the value
			string(REPLACE "#" ";" unfolded_specialization_value "${specialization_value}")
			MigrateProjectDefinition_SetPaths(${arg_placeholder}.${specialization_name} "${unfolded_specialization_value}" generatedContent)
		endif()

		list(APPEND processed_names "${specialization_name}")
		list(APPEND processed_values "${specialization_value}")
	endforeach()

	set(${arg_content} ${generatedContent} PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_SetFrameworks placeholder values content)
	list(REMOVE_DUPLICATES values)
	set(escapesValues)

	foreach(p IN LISTS values)
		string(FIND "${p}" " " containsSpaces)
		if (NOT containsSpaces EQUAL -1)
			set(p "\"${p}\"")
		endif()

		MigrateProjectDefinition_ReplacePathPlaceholders("${p}" p)  
		cmake_path(GET p STEM LAST_ONLY p)
		list(APPEND escapesValues \"-framework\ ${p}\")
	endforeach()
	set(values ${escapesValues})
	list(LENGTH values numValues)
	if (numValues GREATER 1) # split if there's multiple items
		list(JOIN values "" joinedValues)
		string(LENGTH "${joinedValues}" joinedLength)
		if (joinedLength GREATER 100)
			list(TRANSFORM values PREPEND "\n  ")
			list(APPEND values "\n")
		else()
			# A space for shorter lines
			list(TRANSFORM values PREPEND " ")
		endif()
	endif()
	list(JOIN values "" values)

	string(STRIP "${values}" values)
	if (NOT values)
		string(REGEX REPLACE "[^\n]*<<${placeholder}>>[^\n]*\n?" "" newContent "${${content}}")
	else()
		string(REPLACE "<<${placeholder}>>" "${values}" newContent "${${content}}")
	endif()
	set(${content} ${newContent} PARENT_SCOPE)
endfunction()

function(MigrateProjectDefinition_TransformAdditionalSourcePaths additionalSourcePaths)
	set(sourceDirectory "source/")
	foreach(sourcePath IN LISTS ${additionalSourcePaths})
		if (${sourcePath} MATCHES "\(EXTERNAL_LIBS\)")
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

function(MigrateProjectDefinition_ParseBazelTemplateFileForWarnings)
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

function(MigrateProjectDefinition_UpdateProject)
	set(options)
	set(oneValueArgs TargetName ProjectFile CMakeFile Status)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	# Validate Input.
	if (NOT arg_TargetName)
		message(FATAL_ERROR "No target name provided for project file '${ProjectFile}'")
	endif()
	MigrateProjectDefinition_ParseProjectDefinitionFile(PATH ${arg_ProjectFile}) # Add VERBOSE for print outs.

	MigrateProjectDefinition_UpdateCMake(TargetName ${arg_TargetName} ProjectFile ${arg_ProjectFile} CMakeFile ${arg_CMakeFile} Status CMakeStatus)
	if (NOT CMakeStatus)
		set(${arg_Status} "" PARENT_SCOPE)
	else()
		set(${arg_Status} "1" PARENT_SCOPE)
	endif()

endfunction()

function(MigrateProjectDefinition_UpdateCMake)
	set(options)
	set(oneValueArgs TargetName ProjectFile CMakeFile Status)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )


	file(READ ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/sdk_library_template.cmake g_libraryTemplate)

	# Load the appropriate template.
	if ("${PROJ_DEF_TYPE}" STREQUAL "Lib" OR 
		"${PROJ_DEF_TYPE}" STREQUAL "DLL")
		set (generatedContent ${g_libraryTemplate})
	endif()
	
	if(NOT generatedContent)
		# We skip solutions and applications for now.
		message("Skipping target '${arg_TargetName}' because it is of unsupported type '${PROJ_DEF_TYPE}'")
		set(${arg_Status} "" PARENT_SCOPE)
		return()
	endif()
	
	# Fill the appropriate template.
	###############################

	get_filename_component(targetSourceDir ${arg_ProjectFile}/.. ABSOLUTE) # 'C:/sdk/frameworks/core.framework/project'

	MigrateProjectDefinition_SetPaths(CMAKE_CURRENT_SOURCE_DIR "" generatedContent)

	# --- source processor settings ---




	set(target_settings "{}")
	if (PROJ_DEF_TYPE)
		string(JSON target_settings SET "${target_settings}" "type" "\"${PROJ_DEF_TYPE}\"")
	endif()
	if (PROJ_DEF_APIS)
		MigrateProjectDefinition_ListToJsonArray("${PROJ_DEF_APIS}" json_array)
		string(JSON target_settings SET "${target_settings}" "apis" "${json_array}")
	endif()
	if (PROJ_DEF_MODULEID)
		string(JSON target_settings SET "${target_settings}" "moduleid" "\"${PROJ_DEF_MODULEID}\"")
	endif()
	if (PROJ_DEF_MAXON)
		string(JSON target_settings SET "${target_settings}" "maxon" "true")
	endif()
	if (PROJ_DEF_C4D)
		string(JSON target_settings SET "${target_settings}" "c4d" "true")
	endif()
	if (PROJ_DEF_OMITAPIDEFINE)
		string(JSON target_settings SET "${target_settings}" "omitapidefine" "true")
	endif()

	if (PROJ_DEF_PUBLICATIONLEVEL)
		string(JSON target_settings SET "${target_settings}" "publicationlevel" "\"${PROJ_DEF_PUBLICATIONLEVEL}\"")
	endif()
	if (PROJ_DEF_MODULES)
		MigrateProjectDefinition_ListToJsonArray("${PROJ_DEF_MODULES}" json_array)
		string(JSON target_settings SET "${target_settings}" "modules" "${json_array}")
	endif()
	if ("${PROJ_DEF_MODULEREGISTRATION}" STREQUAL "false")
		string(JSON target_settings SET "${target_settings}" "moduleregistration" "false")
	endif()

	if (PROJ_DEF_EXCLUDESPLITREGISTERCPPS)
		string(JSON target_settings SET "${target_settings}" "excludesplitregistercpps" "true")
	endif()
	if (PROJ_DEF_FRAMEWORKREGISTRATION)
		MigrateProjectDefinition_ListToJsonArray("${PROJ_DEF_FRAMEWORKREGISTRATION}" json_array)
		string(JSON target_settings SET "${target_settings}" "frameworkregistration" "${json_array}")
	endif()
	if (PROJ_DEF_FRAMEWORKREGISTRATIONINCLUDEREFLECTION)
		string(JSON target_settings SET "${target_settings}" "frameworkregistrationincludereflection" "true")
	endif()
	if (PROJ_DEF_OBFUSCATE)
		string(JSON target_settings SET "${target_settings}" "obfuscate" "true")
	endif()
	if (PROJ_DEF_DONTUNCRUSTIFY)
		MigrateProjectDefinition_ListToJsonArray("${PROJ_DEF_DONTUNCRUSTIFY}" json_array)
		string(JSON target_settings SET "${target_settings}" "dontuncrustify" "${json_array}")
	endif()

	if (NOT "${PROJ_DEF_STYLECHECK}" STREQUAL "")
		if (PROJ_DEF_STYLECHECK)
			string(JSON target_settings SET "${target_settings}" "stylecheck" "true")
		else()
			string(JSON target_settings SET "${target_settings}" "stylecheck" "false")
		endif()
	endif()
	if (PROJ_DEF_STYLECHECK.DOMAINS)
		MigrateProjectDefinition_ListToJsonArray("${PROJ_DEF_STYLECHECK.DOMAINS}" json_array)
		string(JSON target_settings SET "${target_settings}" "stylecheck.domains" "${json_array}")
	endif()

	if ("${PROJ_DEF_STYLECHECK.ENUM-CLASS}" STREQUAL "false")
		string(JSON target_settings SET "${target_settings}" "stylecheck.enum-class" "false")
	endif()
	if ("${PROJ_DEF_STYLECHECK.ENUM-REGISTRATION}" STREQUAL "false")
		string(JSON target_settings SET "${target_settings}" "stylecheck.enum-registration" "false")
	endif()
	if (NOT "${PROJ_DEF_STYLECHECK.LEVEL}" STREQUAL "")
		string(JSON target_settings SET "${target_settings}" "stylecheck.level" "${PROJ_DEF_STYLECHECK.LEVEL}")
	endif()

	# We escape and write the json construct if it's not empty.
	string(JSON target_settings_num LENGTH "${target_settings}")
	if (target_settings_num GREATER 0)
		# We escape the json string.
		MigrateProjectDefinition_SetValues(target_settings "[=[\n${target_settings}\n]=]" generatedContent)
	else()
		# We remove the empty variable entirely.
		MigrateProjectDefinition_SetValues(target_settings "" generatedContent)
	endif()

	# --- general ---
	MigrateProjectDefinition_SetValues(target_base_name "${arg_TargetName}" generatedContent)
	MigrateProjectDefinition_SetValues(target_platforms "${PROJ_DEF_PLATFORM}" generatedContent)

	list(APPEND targetSourceDirectories source)
	if(${PROJ_DEF_TYPE} MATCHES "DLL" AND IS_DIRECTORY "${targetSourceDir}/../res")
		list(APPEND targetSourceDirectories res)
	endif()
	MigrateProjectDefinition_SetPaths(source_directories "${targetSourceDirectories}" generatedContent)

	# according to documentation if preprocessor values are specified for a platform they overwrite the base values
	set(preprocessorDefinitions       "${PROJ_DEF_ADDITIONALPREPROCESSORDEFINITIONS}")
	set(preprocessorDefinitions.WINDOWS   "${PROJ_DEF_ADDITIONALPREPROCESSORDEFINITIONS.WIN}")
	set(preprocessorDefinitions.MACOS "${PROJ_DEF_ADDITIONALPREPROCESSORDEFINITIONS.OSX}")
	set(preprocessorDefinitions.LINUX   "${PROJ_DEF_ADDITIONALPREPROCESSORDEFINITIONS.LINUX}")

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
	MigrateProjectDefinition_SetPaths(type_viewer_files "${typeviewerFiles}" generatedContent)
	MigrateProjectDefinition_SetValues(additional_definitions "${preprocessorDefinitions}" generatedContent)
	MigrateProjectDefinition_SetPaths(output_directory "${PROJ_DEF_RELATIVEDIR}" generatedContent)
	MigrateProjectDefinition_SetBool(enable_exception_handling "${PROJ_DEF_EXCEPTIONHANDLING}" generatedContent)
	MigrateProjectDefinition_SetBool(enable_rtti "${PROJ_DEF_RUNTIMETYPEINFO}" generatedContent)

	set(PROJ_DEF_PREBUILDEVENT.MACOS "${PROJ_DEF_SHELLSCRIPT.OSX}")
	set(PROJ_DEF_PREBUILDEVENT.WINDOWS "${PROJ_DEF_PREBUILDEVENT}")
	set(PROJ_DEF_PREBUILDEVENT.WINDOWS.DEBUG "${PROJ_DEF_PREBUILDEVENT.DEBUG}")
	set(PROJ_DEF_PREBUILDEVENT.WINDOWS.RELEASE "${PROJ_DEF_PREBUILDEVENT.RELEASE}")
	set(PROJ_DEF_PREBUILDEVENT.LINUX "${PROJ_DEF_SHELLSCRIPT.LINUX}")

	set(supportedPlatformSuffixes WINDOWS MACOS LINUX)
	foreach(platform ${supportedPlatformSuffixes})
		foreach(config ${CMAKE_CONFIGURATION_TYPES})
			string(TOUPPER ${config} config_upper)
			set(currentPrebuildEvent ${PROJ_DEF_PREBUILDEVENT.${platform}.${config_upper}})
			if("${currentPrebuildEvent}" STREQUAL "")
				if(NOT "${PROJ_DEF_PREBUILDEVENT.${platform}}" STREQUAL "")
					set(currentPrebuildEvent "${PROJ_DEF_PREBUILDEVENT.${platform}}")
					string(STRIP "${currentPrebuildEvent}" currentPrebuildEvent)
				endif()
			endif()
			if (currentPrebuildEvent)
				string(REPLACE "\$CONFIGURATION" ${config_upper} currentPrebuildEvent "${currentPrebuildEvent}")
				MigrateProjectDefinition_ReplacePathPlaceholders("${currentPrebuildEvent}" currentPrebuildEvent)
				MigrateProjectDefinition_ReplaceConfigurationSpecificTokens(${config} "${currentPrebuildEvent}" currentPrebuildEvent)
				# Escape backslashes and quotes for the regular CMake string context in the generated file.
				string(REPLACE "\\" "\\\\" currentPrebuildEvent "${currentPrebuildEvent}")
				string(REPLACE "\"" "\\\"" currentPrebuildEvent "${currentPrebuildEvent}")
				string(REPLACE "<<prebuild_event.${platform}.${config_upper}>>" "\"${currentPrebuildEvent}\"" generatedContent "${generatedContent}") # Add the prebuild events to the cmakelists file.
			else()
				string(REGEX REPLACE "[^\n]*<<prebuild_event.${platform}.${config_upper}>>[^\n]*\n?" "" generatedContent "${generatedContent}")
			endif()
		endforeach()
	endforeach()

	# --- WINDOWS specific ---
	MigrateProjectDefinition_SetPaths(exclude_from_build.WINDOWS "${PROJ_DEF_EXCLUDEFROMBUILD.WIN}" generatedContent)
	MigrateProjectDefinition_SetPaths(exclude.WINDOWS "${PROJ_DEF_EXCLUDE.WIN}" generatedContent)
	
	MigrateProjectDefinition_SetValues(additional_definitions.WINDOWS "${preprocessorDefinitions.WINDOWS}" generatedContent)

	MigrateProjectDefinition_SetPaths(additional_include_directories.WINDOWS "${PROJ_DEF_ADDITIONALINCLUDEDIRECTORIES}" generatedContent)

	if(NOT DEFINED PROJ_DEF_ADDITIONALINCLUDEDIRECTORIES.WINARM64)
		set(PROJ_DEF_ADDITIONALINCLUDEDIRECTORIES.WINARM64 ${PROJ_DEF_ADDITIONALINCLUDEDIRECTORIES})
	endif()
	MigrateProjectDefinition_SetPaths(additional_include_directories.WINDOWS.ARM "${PROJ_DEF_ADDITIONALINCLUDEDIRECTORIES.WINARM64}" generatedContent)

	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_ADDITIONALDEPENDENCIES PROJ_DEF_ADDITIONALDEPENDENCIES PROJ_DEF_ADDITIONALDEPENDENCIES.WIN64)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_ADDITIONALDEPENDENCIES.DEBUG PROJ_DEF_ADDITIONALDEPENDENCIES.DEBUG PROJ_DEF_ADDITIONALDEPENDENCIES.WIN64.DEBUG)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_ADDITIONALDEPENDENCIES.RELEASE PROJ_DEF_ADDITIONALDEPENDENCIES.RELEASE PROJ_DEF_ADDITIONALDEPENDENCIES.WIN64.RELEASE)

	string(REPLACE ";" "#" PROJ_DEF_ADDITIONALDEPENDENCIES "${PROJ_DEF_ADDITIONALDEPENDENCIES}")
	string(REPLACE ";" "#" PROJ_DEF_ADDITIONALDEPENDENCIES.DEBUG "${PROJ_DEF_ADDITIONALDEPENDENCIES.DEBUG}")
	string(REPLACE ";" "#" PROJ_DEF_ADDITIONALDEPENDENCIES.RELEASE "${PROJ_DEF_ADDITIONALDEPENDENCIES.RELEASE}")

	MigrateProjectDefinition_SetSpecializedPaths2(
		placeholder link_libraries.WINDOWS
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${PROJ_DEF_ADDITIONALDEPENDENCIES}"
		specializedValues \"${PROJ_DEF_ADDITIONALDEPENDENCIES.DEBUG}\" \"${PROJ_DEF_ADDITIONALDEPENDENCIES.RELEASE}\"
		content generatedContent)

	if(DEFINED PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64 OR DEFINED PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.DEBUG OR DEFINED PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.RELEASE)
		string(REPLACE ";" "#" PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64 "${PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64}")
		string(REPLACE ";" "#" PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.DEBUG "${PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.DEBUG}")
		string(REPLACE ";" "#" PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.RELEASE "${PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.RELEASE}")
	else()
		# For windows-arm64 we may take over the windows-x64 library names along with the debug/release switch
		set(PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64 "${PROJ_DEF_ADDITIONALDEPENDENCIES}")
		set(PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.DEBUG "${PROJ_DEF_ADDITIONALDEPENDENCIES.DEBUG}")
		set(PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.RELEASE "${PROJ_DEF_ADDITIONALDEPENDENCIES.RELEASE}")
	endif()

	MigrateProjectDefinition_SetSpecializedPaths2(
		placeholder link_libraries.WINDOWS.ARM
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64}"
		specializedValues \"${PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.DEBUG}\" \"${PROJ_DEF_ADDITIONALDEPENDENCIES.WINARM64.RELEASE}\"
		content generatedContent)

	string(REPLACE "%(AdditionalLibraryDirectories)" "" PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES}")
	string(REPLACE "%(AdditionalLibraryDirectories)" "" PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.DEBUG "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.DEBUG}")
	string(REPLACE "%(AdditionalLibraryDirectories)" "" PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.RELEASE "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.RELEASE}")
	string(REPLACE "%(AdditionalLibraryDirectories)" "" PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.WINARM64 "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.WINARM64}")

	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.WIN64)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.DEBUG PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.DEBUG PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.WIN64.DEBUG)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.RELEASE PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.RELEASE PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.WIN64.RELEASE)

	MigrateProjectDefinition_SetPaths(additional_link_directories.WINDOWS "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES}" generatedContent)
	MigrateProjectDefinition_SetSpecializedPaths(additional_link_directories.WINDOWS .DEBUG "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES}" "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.DEBUG}" generatedContent)
	MigrateProjectDefinition_SetSpecializedPaths(additional_link_directories.WINDOWS .RELEASE "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES}" "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.RELEASE}" generatedContent)
	MigrateProjectDefinition_SetSpecializedPaths(additional_link_directories.WINDOWS .ARM "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES}" "${PROJ_DEF_ADDITIONALLIBRARYDIRECTORIES.WINARM64}" generatedContent)

	MigrateProjectDefinition_TransformAdditionalSourcePaths(PROJ_DEF_INCLUDE.WIN)
	MigrateProjectDefinition_SetPaths(additional_source_files.WINDOWS "${PROJ_DEF_INCLUDE.WIN}" generatedContent)


	string(REPLACE "%(IgnoreSpecificDefaultLibraries)" "" PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES "${PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES}")
	string(REPLACE "%(IgnoreSpecificDefaultLibraries)" "" PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES.DEBUG "${PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES.DEBUG}")
	string(REPLACE "%(IgnoreSpecificDefaultLibraries)" "" PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES.RELEASE "${PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES.RELEASE}")

	if(g_maxonTargetOS STREQUAL "WINDOWS") 
		string(TOLOWER "${PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES}" clangLinkerFlagsLowerCase)
		string(TOLOWER "${PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES.DEBUG}" clangLinkerFlagsLowerCaseDebug)
		string(TOLOWER "${PROJ_DEF_IGNORESPECIFICDEFAULTLIBRARIES.RELEASE}" clangLinkerFlagsLowerCaseRelease)
	endif()

	set(msvcLinkerFlagsLowerCase ${clangLinkerFlagsLowerCase})
	set(msvcLinkerFlagsLowerCaseDebug ${clangLinkerFlagsLowerCaseDebug})
	set(msvcLinkerFlagsLowerCaseRelease ${clangLinkerFlagsLowerCaseRelease})
	
	
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

	string(REPLACE "%(AdditionalOptions)" "" PROJ_DEF_ADDITIONALLINKOPTIONS "${PROJ_DEF_ADDITIONALLINKOPTIONS}")
	string(REPLACE "," "$<COMMA>" PROJ_DEF_ADDITIONALLINKOPTIONS "${PROJ_DEF_ADDITIONALLINKOPTIONS}")
	list(APPEND msvcLinkerFlagsLowerCaseDebug ${PROJ_DEF_ADDITIONALLINKOPTIONS})
	list(APPEND msvcLinkerFlagsLowerCaseRelease ${PROJ_DEF_ADDITIONALLINKOPTIONS})
	
	if (${PROJ_DEF_SUBSYSTEMCONSOLE} MATCHES "true")
		set(windowsSubsystem CONSOLE)
	endif()
	MigrateProjectDefinition_SetValues(subsystem.WINDOWS "${windowsSubsystem}" generatedContent)
	MigrateProjectDefinition_SetPaths(additional_solution_files.WINDOWS "${PROJ_DEF_ADDITIONALSOLUTIONFILES}" generatedContent)

	# --- MACOS specific ---
	MigrateProjectDefinition_SetPaths(exclude_from_build.MACOS "${PROJ_DEF_EXCLUDEFROMBUILD.OSX}" generatedContent)
	MigrateProjectDefinition_SetPaths(exclude.MACOS "${PROJ_DEF_EXCLUDE.OSX}" generatedContent)

	MigrateProjectDefinition_SetValues(additional_definitions.MACOS "${preprocessorDefinitions.MACOS}" generatedContent)
	
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_HEADER_SEARCH_PATHS PROJ_DEF_HEADER_SEARCH_PATHS PROJ_DEF_USER_HEADER_SEARCH_PATHS)
	MigrateProjectDefinition_SetPaths(additional_include_directories.MACOS "${PROJ_DEF_HEADER_SEARCH_PATHS}" generatedContent)

	MigrateProjectDefinition_CombineVariables(PROJ_DEF_OTHER_LDFLAGS.MACOS PROJ_DEF_OTHER_LDFLAGS PROJ_DEF_OTHER_LDFLAGS.OSX PROJ_DEF_OTHER_LDFLAGS.MACOS)
	MigrateProjectDefinition_CombineVariables(PROJ_DEF_OTHER_LDFLAGS.MACOS.DEBUG PROJ_DEF_OTHER_LDFLAGS.DEBUG PROJ_DEF_OTHER_LDFLAGS.OSX.DEBUG PROJ_DEF_OTHER_LDFLAGS.MACOS.DEBUG)
	MigrateProjectDefinition_CombineVariables(PROJ_DEF_OTHER_LDFLAGS.MACOS.RELEASE PROJ_DEF_OTHER_LDFLAGS.RELEASE PROJ_DEF_OTHER_LDFLAGS.OSX.RELEASE PROJ_DEF_OTHER_LDFLAGS.MACOS.RELEASE)

	string(REPLACE ";" "#" PROJ_DEF_OTHER_LDFLAGS.MACOS.DEBUG "${PROJ_DEF_OTHER_LDFLAGS.DEBUG}")
	string(REPLACE ";" "#" PROJ_DEF_OTHER_LDFLAGS.MACOS.RELEASE "${PROJ_DEF_OTHER_LDFLAGS.RELEASE}")
	
	# c4dplugin module has an additional library dependency that needs to be specifically handled. 
	# By combining the two individual elements "-weak_framework" and the library name "3DconnexionClient" into one tag with a space in between, 
	# we circumvent the automatic addition of an "l" before the library name, which would cause the library file to not be found.
	if (targetName STREQUAL "c4d_base")
		string(REGEX REPLACE "-weak_framework#(.+)" "-weak_framework \\1" PROJ_DEF_OTHER_LDFLAGS.MACOS.DEBUG "${PROJ_DEF_OTHER_LDFLAGS.MACOS.DEBUG}")
		string(REGEX REPLACE "-weak_framework#(.+)" "-weak_framework \\1" PROJ_DEF_OTHER_LDFLAGS.MACOS.RELEASE "${PROJ_DEF_OTHER_LDFLAGS.MACOS.RELEASE}")
	endif()

	MigrateProjectDefinition_SetSpecializedPaths2(
		placeholder link_libraries.MACOS 
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${PROJ_DEF_OTHER_LDFLAGS.MACOS}"
		specializedValues "${PROJ_DEF_OTHER_LDFLAGS.MACOS.DEBUG}" "${PROJ_DEF_OTHER_LDFLAGS.MACOS.RELEASE}" 
		content generatedContent)
 
	MigrateProjectDefinition_SetPaths(swift_bridging_header.MACOS "${PROJ_DEF_SWIFTBRIDGINGHEADER.OSX}" generatedContent)
	MigrateProjectDefinition_SetPaths(xib_file.MACOS "${PROJ_DEF_XIB.OSX}" generatedContent)
	MigrateProjectDefinition_SetPaths(plist_file.MACOS "${PROJ_DEF_PLIST.OSX}" generatedContent)
	MigrateProjectDefinition_SetPaths(icon_files.MACOS "${PROJ_DEF_ICONS.OSX}" generatedContent)
	MigrateProjectDefinition_SetFrameworks(link_frameworks.MACOS "${PROJ_DEF_FRAMEWORKS.OSX}" generatedContent)
	
	MigrateProjectDefinition_TransformAdditionalSourcePaths(PROJ_DEF_INCLUDE.MACOS)
	MigrateProjectDefinition_SetPaths(additional_source_files.MACOS "${PROJ_DEF_INCLUDE.OSX}" generatedContent)

	# --- LINUX specific ---
	MigrateProjectDefinition_SetPaths(exclude_from_build.LINUX "${PROJ_DEF_EXCLUDEFROMBUILD.LINUX}" generatedContent)
	MigrateProjectDefinition_SetPaths(exclude.LINUX "${PROJ_DEF_EXCLUDE.LINUX}" generatedContent)

	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARIES PROJ_DEF_LIBRARIES PROJ_DEF_LIBRARIES.LINUX)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARIES PROJ_DEF_LIBRARIES PROJ_DEF_STATICLIBRARIES.LINUX)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARIES.DEBUG PROJ_DEF_LIBRARIES.DEBUG PROJ_DEF_LIBRARIES.LINUX.DEBUG)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARIES.RELEASE PROJ_DEF_LIBRARIES.RELEASE PROJ_DEF_LIBRARIES.LINUX.RELEASE)

	string(REPLACE ";" "#" PROJ_DEF_LIBRARIES.DEBUG "${PROJ_DEF_LIBRARIES.DEBUG}")
	string(REPLACE ";" "#" PROJ_DEF_LIBRARIES.RELEASE "${PROJ_DEF_LIBRARIES.RELEASE}")

	MigrateProjectDefinition_SetSpecializedPaths2(
		placeholder link_libraries.LINUX
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${PROJ_DEF_LIBRARIES}"
		specializedValues "${PROJ_DEF_LIBRARIES.DEBUG}" "${PROJ_DEF_LIBRARIES.RELEASE}"
		content generatedContent)

	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARYSEARCHPATH PROJ_DEF_LIBRARYSEARCHPATH PROJ_DEF_LIBRARYSEARCHPATH.LINUX)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARYSEARCHPATH.DEBUG PROJ_DEF_LIBRARYSEARCHPATH.DEBUG PROJ_DEF_LIBRARYSEARCHPATH.LINUX.DEBUG)
	MigrateProjectDefinition_Combine2Variables(PROJ_DEF_LIBRARYSEARCHPATH.RELEASE PROJ_DEF_LIBRARYSEARCHPATH.RELEASE PROJ_DEF_LIBRARYSEARCHPATH.LINUX.RELEASE)

	string(REPLACE ";" "#" PROJ_DEF_LIBRARYSEARCHPATH.DEBUG "${PROJ_DEF_LIBRARYSEARCHPATH.DEBUG}")
	string(REPLACE ";" "#" PROJ_DEF_LIBRARYSEARCHPATH.RELEASE "${PROJ_DEF_LIBRARYSEARCHPATH.RELEASE}")

	MigrateProjectDefinition_SetSpecializedPaths2(
		placeholder additional_link_directories.LINUX
		specializations ${CMAKE_CONFIGURATION_TYPES}
		baseValues "${PROJ_DEF_LIBRARYSEARCHPATH}"
		specializedValues "${PROJ_DEF_LIBRARYSEARCHPATH.DEBUG}" "${PROJ_DEF_LIBRARYSEARCHPATH.RELEASE}"
		content generatedContent)

	MigrateProjectDefinition_TransformAdditionalSourcePaths(PROJ_DEF_INCLUDE.LINUX)
	MigrateProjectDefinition_SetPaths(additional_source_files.LINUX "${PROJ_DEF_INCLUDE.LINUX}" generatedContent)
	MigrateProjectDefinition_SetPaths(system_include_paths "${PROJ_DEF_SYSTEMINCLUDEPATHS}" generatedContent)

	MigrateProjectDefinition_SetPaths(additional_include_directories.LINUX "${PROJ_DEF_INCLUDEPATHS}" generatedContent)
	MigrateProjectDefinition_SetValues(additional_definitions.LINUX "${preprocessorDefinitions.LINUX}" generatedContent)

	#-----------------------------------------------------------------------------
	# --- Compiler specific ---
	#-----------------------------------------------------------------------------

	#-----------------------------------
	# --- Windows: MSVC ----------------
	#-----------------------------------

	# It is our understanding that BUILD.template::cinemake//config:win_x64_msvc overrules AdditionalCompileOptions.Win64
	# but either later gets combined with DisableSpecificWarnings.Win64.
	# According to bazel_generator.py::generate_build_file() bazel-defined values overrule and replace their projectdefinition.txt counterpart.
	string(REPLACE "%(AdditionalOptions)" "" PROJ_DEF_ADDITIONALCOMPILEOPTIONS.WIN64 "${PROJ_DEF_ADDITIONALCOMPILEOPTIONS.WIN64}")
	cmake_path(SET bazelTemplateFile NORMALIZE "${arg_ProjectFile}/../../BUILD.template")
	MigrateProjectDefinition_ParseBazelTemplateFileForWarnings(PATH ${bazelTemplateFile} CLANGCL BAZELOPTIONS.CLANGCL MSVC BAZELOPTIONS.MSVC)
	if (BAZELOPTIONS.MSVC)
		set(ADDITIONALCOMPILEOPTIONS.WIN64 "${BAZELOPTIONS.MSVC}")
	else()
		set(ADDITIONALCOMPILEOPTIONS.WIN64 "${PROJ_DEF_ADDITIONALCOMPILEOPTIONS.WIN64}")
	endif()

	# MSVC: We combine DisableSpecificWarnings.Win64 + cinemake//config:win_x64_msvc or AdditionalCompileOptions.Win64
	string(REPLACE ";%(DisableSpecificWarnings)" "" PROJ_DEF_DISABLESPECIFICWARNINGS.WIN64 "${PROJ_DEF_DISABLESPECIFICWARNINGS.WIN64}")
	list(TRANSFORM PROJ_DEF_DISABLESPECIFICWARNINGS.WIN64 PREPEND "/wd" OUTPUT_VARIABLE PROJ_DEF_DISABLESPECIFICWARNINGS.WIN64)
	MigrateProjectDefinition_CombineVariables(ADDITIONALCOMPILEOPTIONS.WIN64 PROJ_DEF_DISABLESPECIFICWARNINGS.WIN64 ADDITIONALCOMPILEOPTIONS.WIN64)
	MigrateProjectDefinition_SetValues(additional_compile_options.MSVC.CPP "${ADDITIONALCOMPILEOPTIONS.WIN64}" generatedContent)
	if (NOT "${ADDITIONALCOMPILEOPTIONS.WIN64}" STREQUAL "")
		MigrateProjectDefinition_SetValues(additional_compile_options.MSVC.C "$\{additional_compile_options.MSVC.CPP}" generatedContent)
	else()
		MigrateProjectDefinition_SetValues(additional_compile_options.MSVC.C "" generatedContent)
	endif()
	# Note that CMake automatically populates 'DisableSpecificWarnings' in VS for the appropriate options.

	#-----------------------------------
	# --- macOS: Clang -----------------
	#-----------------------------------

	# WARNING_CFLAGS in contrast to its name, is applied to both C and CPP files.
	# We ignore this because we consider the Bazel Clang settings to be more accurate and apply them everywhere.
	
	#-----------------------------------
	# --- any: Clang -------------------
	#-----------------------------------

	if(PROJ_DEF_CLANG_WARN_DOCUMENTATION_COMMENTS STREQUAL "NO")
		set(BAZELOPTIONS.CLANGCL "-Wno-documentation;${BAZELOPTIONS.CLANGCL}")
	endif()
	MigrateProjectDefinition_SetValues(additional_compile_options.CLANG.CPP "${BAZELOPTIONS.CLANGCL}" generatedContent)
	if (NOT "${BAZELOPTIONS.CLANGCL}" STREQUAL "")
		MigrateProjectDefinition_SetValues(additional_compile_options.CLANG.C "$\{additional_compile_options.CLANG.CPP}" generatedContent)
	else()
		MigrateProjectDefinition_SetValues(additional_compile_options.CLANG.C "" generatedContent)
	endif()

	#-----------------------------------
	# --- Linux: GCC -------------------
	#-----------------------------------
	MigrateProjectDefinition_SetValues(additional_compile_options.GNU.CPP "${PROJ_DEF_ADDITIONALCOMPILEOPTIONS.LINUX.C++}" generatedContent)
	MigrateProjectDefinition_SetValues(additional_compile_options.GNU.C "${PROJ_DEF_ADDITIONALCOMPILEOPTIONS.LINUX.C}" generatedContent)

	#-----------------------------------------------------------------------------
	# --- Linker specific ---
	#-----------------------------------------------------------------------------
	MigrateProjectDefinition_SetValues(additional_linker_options.CLANG.DEBUG "${clangLinkerFlagsLowerCaseDebug}" generatedContent)
	MigrateProjectDefinition_SetValues(additional_linker_options.CLANG.RELEASE "${clangLinkerFlagsLowerCaseRelease}" generatedContent)
	MigrateProjectDefinition_SetValues(additional_linker_options.MSVC.DEBUG "${msvcLinkerFlagsLowerCaseDebug}" generatedContent)
	MigrateProjectDefinition_SetValues(additional_linker_options.MSVC.RELEASE "${msvcLinkerFlagsLowerCaseRelease}" generatedContent)

	###############################
	# Remove empty section/subsection headers left after placeholder removal.
	set(_cleanupDone OFF)
	while(NOT _cleanupDone)
		set(_prev "${generatedContent}")
		string(REGEX REPLACE "\n# (Section|Subsection):[^\n]*\n\n" "\n" generatedContent "${generatedContent}")
		if("${_prev}" STREQUAL "${generatedContent}")
			set(_cleanupDone ON)
		endif()
	endwhile()
	# Collapse multiple consecutive blank lines into one.
	set(_cleanupDone OFF)
	while(NOT _cleanupDone)
		set(_prev "${generatedContent}")
		string(REGEX REPLACE "\n\n\n" "\n\n" generatedContent "${generatedContent}")
		if("${_prev}" STREQUAL "${generatedContent}")
			set(_cleanupDone ON)
		endif()
	endwhile()

	###############################
	# Validate the completeness of the fill.
	string(REGEX MATCH "<<(.*)>>" invalidSequence ${generatedContent})
	if (invalidSequence)
		message(FATAL_ERROR "${targetName}: Incomplete fill of the cmake template detected. Make sure to remove all <<T>> sequences.\n${generatedContent}")
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

set(SDK_MIGRATE_PROJECTDEFINITION_INCLUDED ON)
