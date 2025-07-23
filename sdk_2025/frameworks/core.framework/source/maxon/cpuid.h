#ifndef CPUID_H__
#define CPUID_H__

#include "maxon/module.h"

namespace maxon
{

// up to SSE4 we define the flags as constexpr, so that the compiler can optimize the code .
// the minimal compile flags include AVX.
constexpr Bool g_hasSSE2 = true;
constexpr Bool g_hasSSE3 = true;
constexpr Bool g_hasSSSE3 = true;
constexpr Bool g_hasSSE4_1 = true;
constexpr Bool g_hasSSE4_2 = true;

// these flags are evaluated at runtime
extern Bool g_hasAVX;
extern Bool g_hasFMA;
extern Bool g_hasAES;
extern Bool g_hasPCLMULQDQ;
extern Bool g_hasAVX2;

MAXON_DEPENDENCY(cpuidinit);

} // namespace maxon

#endif // CPUID_H__
