# Version identity is packaging metadata so reused binaries receive the final
# package version too. Validate before touching any file.
if(NOT DEFINED VERSION OR NOT VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+(\\.[0-9]+)?$")
  message(FATAL_ERROR "Expected a numeric three-part or four-part VERSION")
endif()
if(NOT DEFINED RESOURCE_DIR OR NOT EXISTS "${RESOURCE_DIR}/cmt_config.json")
  message(FATAL_ERROR "RESOURCE_DIR must identify a built plugin resource directory")
endif()
file(WRITE "${RESOURCE_DIR}/cmt_version.txt" "${VERSION}\n")
