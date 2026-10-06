include_guard(GLOBAL)

set(CMT_RUNTIME_RESOURCE_CONFIG_POLICY reset CACHE STRING
  "Runtime resource configuration: reset to repository default, or preserve output cmt_config.json")
set_property(CACHE CMT_RUNTIME_RESOURCE_CONFIG_POLICY PROPERTY STRINGS reset preserve)

# The SDK owns target creation and emits its resource command internally. Give
# it a local command directory while creating mmdtool, forwarding SDK helpers
# unchanged except for the old runtime symlink command. This avoids modifying
# Maxon vendor files or redefining their global functions for other plugins.
macro(cmt_prepare_runtime_resource_commands)
  if(NOT CMT_RUNTIME_RESOURCE_CONFIG_POLICY MATCHES "^(reset|preserve)$")
    message(FATAL_ERROR "CMT_RUNTIME_RESOURCE_CONFIG_POLICY must be reset or preserve")
  endif()
  set(_cmt_original_tooling_dir "${MAXON_TOOLING_DIR}")
  set(_cmt_command_dir "${CMAKE_CURRENT_BINARY_DIR}/cmt_runtime_commands")
  file(MAKE_DIRECTORY "${_cmt_command_dir}/commands")
  file(GLOB _cmt_sdk_commands "${MAXON_TOOLING_DIR}/commands/*.cmake")
  foreach(_cmt_command IN LISTS _cmt_sdk_commands)
    cmake_path(GET _cmt_command FILENAME _cmt_command_name)
    file(WRITE "${_cmt_command_dir}/commands/${_cmt_command_name}"
      "include([==[${_cmt_command}]==])\n")
  endforeach()
  file(WRITE "${_cmt_command_dir}/commands/create_directory_symlink.cmake"
    "set(SOURCE [==[${CMT_RESOURCE_ROOT}]==])\n"
    "set(DESTINATION \"\${maxon_Path}\")\n"
    "set(BUILD_ROOT [==[${CMAKE_BINARY_DIR}]==])\n"
    "set(DEFAULT_CONFIG [==[${CMT_PROJECT_ROOT_DIR}/res/S24_up/cmt_config.json]==])\n"
    "set(CONFIG_POLICY [==[${CMT_RUNTIME_RESOURCE_CONFIG_POLICY}]==])\n"
    "include([==[${CMT_PROJECT_ROOT_DIR}/cmake/sync_runtime_resources.cmake]==])\n")
  set(MAXON_TOOLING_DIR "${_cmt_command_dir}")
endmacro()

macro(cmt_restore_runtime_resource_commands)
  set(MAXON_TOOLING_DIR "${_cmt_original_tooling_dir}")
endmacro()
