cmake_minimum_required(VERSION 3.20)
project(MotionSizingAudit LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
get_filename_component(DEFAULT_REPO "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)
set(CMT_REPO "${DEFAULT_REPO}" CACHE PATH "C4D MMD Tool checkout")
set(CORE_ROOT "${CMT_REPO}/dependency/libMMD" CACHE PATH "libMMD checkout or clean revision archive")
set(LIBMMD_IO_LIBRARY "${CMT_REPO}/_build_msvc/libmmd-sizing-standalone/src/Release/libMMD.lib" CACHE FILEPATH "Built libMMD library providing PMX/VMD IO")
file(GLOB_RECURSE SIZING_SOURCES CONFIGURE_DEPENDS "${CORE_ROOT}/src/MotionSizing/*.cpp")
add_executable(sizing_audit audit.cpp ${SIZING_SOURCES})
target_include_directories(sizing_audit PRIVATE
    "${CORE_ROOT}/src"
    "${CORE_ROOT}/src/MotionSizing/Pose"
    "${CORE_ROOT}/src/MotionSizing/Solvers"
    "${CMT_REPO}/dependency/libMMD/external/eigen")
if(MSVC)
    target_compile_options(sizing_audit PRIVATE /utf-8 /arch:SSE2 /EHsc /bigobj /MP)
endif()
target_link_libraries(sizing_audit PRIVATE "${LIBMMD_IO_LIBRARY}")
