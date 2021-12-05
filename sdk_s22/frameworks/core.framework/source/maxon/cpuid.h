#ifndef CPUID_H__
#define CPUID_H__

#undef __USE_CPU_FEATURE_INTRINSICS
// nice idea from intel to you _may_i_use_cpu_feature() but gives an internal compiler error when using
// https://premier.intel.com/premier/IssueDetail.aspx?IssueID=690872

#include "maxon/apibase.h"
#include "maxon/module.h"

namespace maxon
{

#ifdef __USE_CPU_FEATURE_INTRINSICS
	#define g_hasSSE2				_may_i_use_cpu_feature(_FEATURE_SSE2)
	#define g_hasSSE3				_may_i_use_cpu_feature(_FEATURE_SSE3)
	#define g_hasSSSE3			_may_i_use_cpu_feature(_FEATURE_SSSE3)
	#define g_hasSSE4_1			_may_i_use_cpu_feature(_FEATURE_SSE4_1)
	#define g_hasSSE4_2			_may_i_use_cpu_feature(_FEATURE_SSE4_2)
	#define g_hasAVX				_may_i_use_cpu_feature(_FEATURE_AVX)
	#define g_hasFMA				_may_i_use_cpu_feature(_FEATURE_FMA)
	#define g_hasAES				_may_i_use_cpu_feature(_FEATURE_AES)
	#define g_hasPCLMULQDQ	_may_i_use_cpu_feature(_FEATURE_PCLMULQDQ)
	#define g_hasAVX2				_may_i_use_cpu_feature(_FEATURE_AVX2)
#else
	extern Bool g_hasSSE2;
	extern Bool g_hasSSE3;
	extern Bool g_hasSSSE3;
	extern Bool g_hasSSE4_1;
	extern Bool g_hasSSE4_2;
	extern Bool g_hasAVX;
	extern Bool g_hasFMA;
	extern Bool g_hasAES;
	extern Bool g_hasPCLMULQDQ;
	extern Bool g_hasAVX2;
#endif

MAXON_DEPENDENCY(cpuidinit);

} // namespace maxon

#endif // CPUID_H__
