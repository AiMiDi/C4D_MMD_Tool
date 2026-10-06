if(NOT TARGET libMMD)
  return()
endif()

set(_cmt_fixture_dir "${CMAKE_CURRENT_BINARY_DIR}/fixtures")
set(_cmt_fixture_generator "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/c4d_regression_fixtures.py")
add_custom_command(
  OUTPUT "${_cmt_fixture_dir}/model.pmx" "${_cmt_fixture_dir}/motion_a.vmd"
         "${_cmt_fixture_dir}/motion_b.vmd" "${_cmt_fixture_dir}/camera.vmd"
         "${_cmt_fixture_dir}/mixed_morphs.pmx" "${_cmt_fixture_dir}/toon_material.pmx"
         "${_cmt_fixture_dir}/toon_white.bmp"
  COMMAND "${Python3_EXECUTABLE}" "${_cmt_fixture_generator}" "${_cmt_fixture_dir}"
  DEPENDS "${_cmt_fixture_generator}"
  VERBATIM
)
add_custom_target(cmt-runtime-fixtures DEPENDS
  "${_cmt_fixture_dir}/model.pmx" "${_cmt_fixture_dir}/motion_a.vmd"
  "${_cmt_fixture_dir}/motion_b.vmd" "${_cmt_fixture_dir}/camera.vmd"
  "${_cmt_fixture_dir}/mixed_morphs.pmx" "${_cmt_fixture_dir}/toon_material.pmx"
  "${_cmt_fixture_dir}/toon_white.bmp")
add_executable(cmt_runtime_fixture_test fixture_validation.cpp)
target_compile_features(cmt_runtime_fixture_test PRIVATE cxx_std_17)
target_include_directories(cmt_runtime_fixture_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../../dependency/libMMD/src"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../dependency/libMMD/external/eigen")
target_compile_definitions(cmt_runtime_fixture_test PRIVATE LIBMMD_STATIC=1)
target_link_libraries(cmt_runtime_fixture_test PRIVATE libMMD)
add_dependencies(cmt_runtime_fixture_test cmt-runtime-fixtures)
add_test(NAME cmt_runtime_fixture_test COMMAND cmt_runtime_fixture_test "${_cmt_fixture_dir}")
set_tests_properties(cmt_runtime_fixture_test PROPERTIES LABELS "plugin;fixture;regression")
set_property(GLOBAL APPEND PROPERTY CMT_PLUGIN_TEST_TARGETS cmt_runtime_fixture_test)
