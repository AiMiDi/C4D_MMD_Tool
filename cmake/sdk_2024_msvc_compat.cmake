# Graph-local compatibility option for SDK 2024's DataType comparisons.
# Verified with MSVC 19.38.33145 (v143): C++20 rewritten comparison candidates
# make the SDK's DataType/DataTypePtr operators ambiguous in core.framework.
# This option is tested on that toolchain; other compiler versions need checks.
#
# The SDK resets CMAKE_CXX_FLAGS in MaxonCompilerHelper_SetConfigurations.
# An inherited directory option survives that reset. Include this file only
# through the SDK 2024 graph's CMAKE_PROJECT_TOP_LEVEL_INCLUDES cache entry.
add_compile_options("$<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CXX_COMPILER_ID:MSVC>>:/Zc:rewrittenExpressions->")
