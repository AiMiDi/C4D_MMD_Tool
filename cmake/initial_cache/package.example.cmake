# Initial cache example: packaging / Inno (copy to e.g. package.cmake and edit; do not commit machine-specific paths)

# Usage:

#   cmake -S <repo root> -B _build_msvc -C cmake/initial_cache/package.example.cmake

# Then:

#   cmake --build _build_msvc --target cmt-workflow

#   cmake --build _build_msvc --target cmt-package

#

get_filename_component(_CMT_IC_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)

get_filename_component(_CMT_REPO "${_CMT_IC_DIR}/../.." ABSOLUTE)

set(CMT_SDK_BUILD_CONFIG "Release" CACHE STRING "" FORCE)

set(CMT_SDK_DIR "${_CMT_REPO}/sdk_2026" CACHE PATH "" FORCE)

set(CMT_INNO_SETUP_ISCC "C:/Program Files/Inno Setup 6/ISCC.exe" CACHE FILEPATH "" FORCE)

# set(CMT_ISS_EXTRA_ARGS "/DPluginVersion=0.4.5.2" CACHE STRING "" FORCE)

