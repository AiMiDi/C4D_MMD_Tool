if(MAXONSOURCEPROCESSOR_INCLUDED)
	return()
endif()

function(MaxonSourceProcessor_JsonArrayToList)
	set(options)
	set(oneValueArgs JSON KEY OS RESULT)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

  unset(_json)

  if (arg_OS)
  	string(JSON _json ERROR_VARIABLE _err GET "${arg_JSON}" "${arg_KEY}.${arg_OS}")
  endif()

  if (NOT _json OR _err)
  	string(JSON _json ERROR_VARIABLE _err GET "${arg_JSON}" "${arg_KEY}")
  endif()

	if(_err)
		set(${arg_RESULT} "" PARENT_SCOPE)
		return()
	endif()
	string(JSON _len LENGTH "${_json}")
	set(_list "")
	set(_idx 0)
	while(_idx LESS _len)
		string(JSON _item GET "${_json}" ${_idx})
		list(APPEND _list "${_item}")
		math(EXPR _idx "${_idx} + 1")
	endwhile()
	set(${arg_RESULT} "${_list}" PARENT_SCOPE)
endfunction()

function(MaxonSourceProcessor_JsonBool)
	set(options)
	set(oneValueArgs JSON KEY OS RESULT)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

  unset(_json)

  if (arg_OS)
  	string(JSON _json ERROR_VARIABLE _err GET "${arg_JSON}" "${arg_KEY}.${arg_OS}")
  endif()

  if (NOT _json OR _err)
  	string(JSON _json ERROR_VARIABLE _err GET "${arg_JSON}" "${arg_KEY}")
  endif()

	if(_err)
		set(${arg_RESULT} OFF PARENT_SCOPE) # todo return default value from input param?
		return()
	endif()
	set(${arg_RESULT} ${_json} PARENT_SCOPE)
endfunction()

function(MaxonSourceProcessor_JsonString)
	set(options)
	set(oneValueArgs JSON KEY OS RESULT)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

  unset(_json)

  if (arg_OS)
  	string(JSON _json ERROR_VARIABLE _err GET "${arg_JSON}" "${arg_KEY}.${arg_OS}")
  endif()

  if (NOT _json OR _err)
  	string(JSON _json ERROR_VARIABLE _err GET "${arg_JSON}" "${arg_KEY}")
  endif()

	if(_err)
		set(${arg_RESULT} "" PARENT_SCOPE) # todo return default value from input param?
		return()
	endif()
	set(${arg_RESULT} ${_json} PARENT_SCOPE)
endfunction()

# TODO must support a list of keys for efficiency and a prefix for result
function(MaxonSourceProcessor_ReadTargetSettingsFromCMake)
	set(options)
	set(oneValueArgs FILE KEY OS RESULT)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	file(READ "${arg_FILE}" _content)
	string(REGEX MATCH "set\\(target_settings \\[=\\[(.*)\\]=\\]" _match "${_content}")
	if(NOT _match)
		set(${arg_RESULT} "" PARENT_SCOPE)
		return()
	endif()
	set(_json "${CMAKE_MATCH_1}")
	MaxonSourceProcessor_JsonArrayToList(JSON "${_json}" KEY "${arg_KEY}" OS "${arg_OS}" RESULT _values)
	set(${arg_RESULT} "${_values}" PARENT_SCOPE)
endfunction()

function(MaxonSourceProcessor_ParseTargetSettings)
	set(options)
	set(oneValueArgs JSON OS)
	set(multiValueArgs)
	cmake_parse_arguments("arg" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	string(JSON target_type GET "${arg_JSON}" "type") # must be defined

  # Optional
	MaxonSourceProcessor_JsonArrayToList(JSON "${arg_JSON}" KEY "frameworkregistration" OS "${arg_OS}" RESULT target_frameworkregistration)
  MaxonSourceProcessor_JsonArrayToList(JSON "${arg_JSON}" KEY "apis" OS "${arg_OS}" RESULT target_apis)
	MaxonSourceProcessor_JsonBool(JSON "${arg_JSON}" KEY "c4d" OS "${arg_OS}" RESULT target_c4d)
	MaxonSourceProcessor_JsonBool(JSON "${arg_JSON}" KEY "omitapidefine" OS "${arg_OS}" RESULT target_omitapidefine)
	MaxonSourceProcessor_JsonString(JSON "${arg_JSON}" KEY "moduleid" OS "${arg_OS}" RESULT target_moduleid)

	# Return Values.
	set(target_type ${target_type} PARENT_SCOPE)
	set(target_frameworkregistration ${target_frameworkregistration} PARENT_SCOPE)
	set(target_apis ${target_apis} PARENT_SCOPE)
	set(target_c4d ${target_c4d} PARENT_SCOPE)
	set(target_omitapidefine ${target_omitapidefine} PARENT_SCOPE)
	set(target_moduleid ${target_moduleid} PARENT_SCOPE)

endfunction()

set(MAXONSOURCEPROCESSOR_INCLUDED ON)