cmake_minimum_required(VERSION 3.23)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(cmt_plugin_logic_tests LANGUAGES CXX)
endif()

enable_testing()

function(cmt_add_logic_test name source)
  add_executable(${name} ${source})
  target_compile_features(${name} PRIVATE cxx_std_17)
  target_include_directories(${name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../source")
  add_test(NAME ${name} COMMAND $<TARGET_FILE:${name}>)
  set_tests_properties(${name} PROPERTIES LABELS "plugin;unit;regression")
  set_property(GLOBAL APPEND PROPERTY CMT_PLUGIN_TEST_TARGETS ${name})
endfunction()

cmt_add_logic_test(bone_execution_plan_test bone_execution_plan_test.cpp)
cmt_add_logic_test(control_role_test control_role_test.cpp)
target_compile_options(control_role_test PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
cmt_add_logic_test(material_morph_runtime_test material_morph_runtime_test.cpp)
cmt_add_logic_test(morph_evaluation_test morph_evaluation_test.cpp)
cmt_add_logic_test(runtime_profile_test runtime_profile_test.cpp)
cmt_add_logic_test(mmd_model_info_test mmd_model_info_test.cpp)
cmt_add_logic_test(mmd_motion_validation_test mmd_motion_validation_test.cpp)
cmt_add_logic_test(camera_fov_test camera_fov_test.cpp)
cmt_add_logic_test(specular_conversion_test specular_conversion_test.cpp)
cmt_add_logic_test(toon_fallback_test toon_fallback_test.cpp)
cmt_add_logic_test(pmx_export_scale_test pmx_export_scale_test.cpp)
target_include_directories(pmx_export_scale_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../dependency/libMMD/src"
  "${CMAKE_CURRENT_SOURCE_DIR}/../dependency/libMMD/external/eigen")
target_compile_options(pmx_export_scale_test PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

find_package(Python3 REQUIRED COMPONENTS Interpreter)
function(cmt_add_python_fixture_test name script)
  add_test(NAME ${name}
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/${script}")
  set_tests_properties(${name} PROPERTIES LABELS "plugin;fixture;regression")
endfunction()

cmt_add_python_fixture_test(cmt_runtime_receipt_contract runtime/test_regression_contract.py)
foreach(_cmt_fixture IN ITEMS document_lifecycle production_document_lifecycle dependency_provenance pmx_scale_snapshot)
  cmt_add_python_fixture_test(cmt_${_cmt_fixture} runtime/test_${_cmt_fixture}.py)
endforeach()
cmt_add_python_fixture_test(cmt_material_fixture_matrix material/test_fixture_matrix.py)
cmt_add_python_fixture_test(cmt_highlight_lifecycle material/test_highlight_lifecycle.py)
cmt_add_python_fixture_test(cmt_highlight_analysis material/test_highlight_analysis.py)
cmt_add_python_fixture_test(cmt_production_mcp_adapter ../mcp/tests/test_adapter.py)

if(TARGET libMMD)
  add_subdirectory(runtime)
endif()

get_property(_cmt_logic_targets GLOBAL PROPERTY CMT_PLUGIN_TEST_TARGETS)
add_custom_target(cmt-plugin-tests
  COMMAND ${CMAKE_CTEST_COMMAND} --test-dir "${CMAKE_CURRENT_BINARY_DIR}" -C $<CONFIG> --output-on-failure
  DEPENDS ${_cmt_logic_targets}
  USES_TERMINAL
  COMMENT "Run SDK-independent plugin logic regression tests"
)
