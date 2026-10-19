if (NOT CMAKE_SCRIPT_MODE_FILE)
	message(FATAL_ERROR "This file can only be used in script mode.")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/../sdk_targets.cmake)

if(NOT maxon_File OR NOT maxon_BaseDirectory OR NOT maxon_SearchDirectories)
		message(FATAL_ERROR "Invalid parameters for script mode.")
endif()
	
string(REPLACE "|" ";" maxon_SearchDirectories ${maxon_SearchDirectories}) # We must properly unescape this list.
foreach(d IN LISTS maxon_SearchDirectories)
	list(APPEND searchDirectories ${d})
endforeach()

set(cancelBuildWhenFileChangesDetected FALSE)
if(CMAKE_GENERATOR MATCHES "Xcode")
	set(cancelBuildWhenFileChangesDetected TRUE)
endif()
MaxonTargets_UpdateFileList(File ${maxon_File} BaseDirectory ${maxon_BaseDirectory} SearchDirectories ${searchDirectories} ErrorOnWrite ${cancelBuildWhenFileChangesDetected})
