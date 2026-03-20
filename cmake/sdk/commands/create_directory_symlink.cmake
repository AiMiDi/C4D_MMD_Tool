if (NOT CMAKE_SCRIPT_MODE_FILE)
	message(FATAL_ERROR "This file can only be used in script mode.")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/../sdk_targets.cmake)

if(NOT maxon_Path OR NOT maxon_Target)
		message(FATAL_ERROR "Invalid parameters for script mode.")
endif()

MaxonTargets_CreateDirectoryLink(PATH ${maxon_Path} TARGET ${maxon_Target})