# Inspect the module itself: cache settings alone cannot identify stale or
# downloaded binaries. The profiling build exports a retained ASCII marker.
if(NOT IS_DIRECTORY "${PLUGIN_DIR}")
  message(FATAL_ERROR "Plugin directory missing: ${PLUGIN_DIR}")
endif()
file(GLOB_RECURSE _modules LIST_DIRECTORIES FALSE
  "${PLUGIN_DIR}/*.xdl64" "${PLUGIN_DIR}/*.dylib" "${PLUGIN_DIR}/*.xlib")
if(NOT _modules)
  message(FATAL_ERROR "No plugin modules found in ${PLUGIN_DIR}")
endif()
foreach(_module IN LISTS _modules)
  file(STRINGS "${_module}" _profiling_markers REGEX "CMT_RUNTIME_PROFILING=1" LIMIT_COUNT 1)
  if(_profiling_markers)
    message(FATAL_ERROR "Packaging rejected instrumented module: ${_module}. Rebuild with CMT_ENABLE_RUNTIME_PROFILING=OFF.")
  endif()
endforeach()
message(STATUS "Package profiling guard passed: ${PLUGIN_DIR}")
