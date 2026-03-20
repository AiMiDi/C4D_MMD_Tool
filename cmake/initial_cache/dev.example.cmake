# Initial cache example: daily dev (Debug, sdk_2026)

# Usage:

#   cmake -S <repo root> -B _build_msvc -C cmake/initial_cache/dev.example.cmake

#

get_filename_component(_CMT_IC_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)

get_filename_component(_CMT_REPO "${_CMT_IC_DIR}/../.." ABSOLUTE)

set(CMT_SDK_BUILD_CONFIG "Debug" CACHE STRING "" FORCE)

set(CMT_SDK_DIR "${_CMT_REPO}/sdk_2026" CACHE PATH "" FORCE)

# Omit CMT_INNO_SETUP_ISCC so the root project does not register cmt-package.

# Optional: enable libMMD CTest in dependency/

# set(CMT_DEPS_ENABLE_LIBMMD_TESTS ON CACHE BOOL "" FORCE)

