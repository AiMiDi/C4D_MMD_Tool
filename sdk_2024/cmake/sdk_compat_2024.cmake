include_guard()

# Keep 2026 tooling language contract for generated code.
set(CMAKE_CXX_STANDARD "20" CACHE STRING "C++ Standard." FORCE)
set_property(CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS "17" "20")

# 2024 props do not force /Zc:__cplusplus; keep conservative MSVC flags.
# /permissive can relax parser strictness for legacy generated headers.
set(MAXON_COMPILE_OPTIONS_MSVC /MP /permissive)

# 2024 default settings use AVX as baseline ISA.
set(MAXON_COMPILE_OPTIONS_WINDOWS_MSVC_X64_ISA /arch:AVX)

# Reduce migration noise from ultra-aggressive warning presets.
set(MAXON_ENABLE_ALL_WARNINGS OFF CACHE BOOL "Disable /Wall during 2024 compatibility migration." FORCE)
