cmake_minimum_required(VERSION 3.23)
project(libmmd_installed_consumer LANGUAGES CXX)
add_library(libmmd_installed STATIC IMPORTED)
set_target_properties(libmmd_installed PROPERTIES
    IMPORTED_LOCATION "S:/tmp/cmt-libmmd-sizing-install/lib/libMMD.lib"
    INTERFACE_INCLUDE_DIRECTORIES "S:/tmp/cmt-libmmd-sizing-install/include")
add_executable(consumer main.cpp)
target_compile_features(consumer PRIVATE cxx_std_17)
target_link_libraries(consumer PRIVATE libmmd_installed)
