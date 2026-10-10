cmake_minimum_required(VERSION 3.20)
project(HandContactAudit LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
get_filename_component(REPO "${CMAKE_CURRENT_SOURCE_DIR}/../../../.." ABSOLUTE)
set(CORE_ROOT "${REPO}/dependency/libMMD" CACHE PATH "libMMD revision to audit")
set(LIBMMD_IO_LIBRARY "${REPO}/_build_msvc/libmmd-sizing-standalone/src/Release/libMMD.lib"
    CACHE FILEPATH "Built libMMD IO library")
file(GLOB_RECURSE SIZING_SOURCES CONFIGURE_DEPENDS "${CORE_ROOT}/src/MotionSizing/*.cpp")
add_executable(sizing_audit handfix-audit.cpp ${SIZING_SOURCES})
target_include_directories(sizing_audit PRIVATE
    "${CORE_ROOT}/src" "${CORE_ROOT}/src/MotionSizing/Pose"
    "${CORE_ROOT}/src/MotionSizing/Solvers" "${REPO}/dependency/libMMD/external/eigen")
if(MSVC)
    target_compile_options(sizing_audit PRIVATE /utf-8 /arch:SSE2 /EHsc /bigobj /MP)
endif()
target_link_libraries(sizing_audit PRIVATE "${LIBMMD_IO_LIBRARY}")
