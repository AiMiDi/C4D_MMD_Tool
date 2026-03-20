include_guard()

# 2023 keeps conservative defaults close to legacy VS project behavior.
set(CMAKE_CXX_STANDARD "20" CACHE STRING "C++ Standard." FORCE)
set_property(CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS "17" "20")
set(MAXON_COMPILE_OPTIONS_MSVC /MP /permissive)
set(MAXON_COMPILE_OPTIONS_WINDOWS_MSVC_X64_ISA /arch:AVX)
set(MAXON_ENABLE_ALL_WARNINGS OFF CACHE BOOL "Disable /Wall during 2023 compatibility migration." FORCE)
