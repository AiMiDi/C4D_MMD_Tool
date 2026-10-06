if(NOT DEFINED SOURCE OR NOT DEFINED DESTINATION)
  message(FATAL_ERROR "SOURCE and DESTINATION are required")
endif()

# Install only maintained runtime files, never credentials, fixtures or caches.
set(_files
  run_mmdtool_mcp.py
  mmdtool_mcp/__init__.py
  mmdtool_mcp/schema.py
  mmdtool_mcp/host.py
  mmdtool_mcp/server.py
)
foreach(_file IN LISTS _files)
  if(NOT EXISTS "${SOURCE}/${_file}")
    message(FATAL_ERROR "Missing MCP runtime file: ${SOURCE}/${_file}")
  endif()
endforeach()
foreach(_file IN LISTS _files)
  get_filename_component(_parent "${DESTINATION}/${_file}" DIRECTORY)
  file(MAKE_DIRECTORY "${_parent}")
  file(COPY_FILE "${SOURCE}/${_file}" "${DESTINATION}/${_file}" ONLY_IF_DIFFERENT)
endforeach()
