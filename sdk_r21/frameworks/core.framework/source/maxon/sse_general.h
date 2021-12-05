#ifndef SSE_GENERAL_H__
#define SSE_GENERAL_H__

#include "maxon/apibase.h"

//----------------------------------------------------------------------------------------
/// This is the general include file for all SSE2, SSE3, SSE4.1 and SSE4.2 stuff. Usually,
/// you do not have to include this file directly.
//----------------------------------------------------------------------------------------

#ifdef MAXON_TARGET_CPU_INTEL
	#define C4D_HAS_SSE2_CAPABILITY
	#define C4D_HAS_SSE2_INTRINSICS
#endif

#ifdef C4D_HAS_SSE2_CAPABILITY
	#ifdef MAXON_TARGET_LINUX
		#ifndef __SSE__
			// set -msse2 under Linux: AM_CXXFLAGS = -D "__API_INTERN__" -msse2
			# error "SSE instruction set not enabled"
		#endif // !__SSE__
	#endif // MAXON_TARGET_LINUX

	#include <xmmintrin.h> // SSE
	#include <emmintrin.h> // SSE2

	#ifdef MAXON_TARGET_WINDOWS
		#if defined MAXON_COMPILER_CLANG
			#define C4D_HAS_SSE3_CAPABILITY
			#define C4D_HAS_SSE3_INTRINSICS
			#include <pmmintrin.h> // SSE3
			#include <tmmintrin.h> // SSSE3

			#define C4D_HAS_SSE4_CAPABILITY
			#define C4D_HAS_SSE4_INTRINSICS
			#include <smmintrin.h> // SSE4.1
			#include <nmmintrin.h> // SSE4.2
			#include <ammintrin.h> // SSE4A

			#define C4D_HAS_AVX_CAPABILITY
			#define C4D_HAS_AVX_INTRINSICS
			#include <immintrin.h>

			#define C4D_HAS_AES_CAPABILITY
			// llvm throws an error when using AES intrinsics:
			// 1>CL : fatal error : error in backend: Cannot select: intrinsic %llvm.x86.aesni.aesimc
			// 1>clang-cl.exe : error : clang frontend command failed with exit code 70 (use -v to see invocation)
// 			#define C4D_HAS_AES_INTRINSICS
// 			#include <wmmintrin.h> // AES

			#define C4D_HAS_PCLMULQDQ_CAPABILITY
			#define C4D_HAS_AVX2_CAPABILITY
		#elif defined(MAXON_COMPILER_MSVC) || defined(MAXON_COMPILER_INTEL)
			#define C4D_HAS_SSE3_CAPABILITY
			#define C4D_HAS_SSE3_INTRINSICS
			#define C4D_HAS_SSE4_CAPABILITY
			#define C4D_HAS_SSE4_INTRINSICS
			#define C4D_HAS_AVX_CAPABILITY
			#define C4D_HAS_AVX_INTRINSICS
			#include <intrin.h>
			#include <immintrin.h>
			#define C4D_HAS_FMADD_CAPABILITY
			#define C4D_HAS_FMADD_INTRINSICS
			#define C4D_HAS_AES_CAPABILITY
			#define C4D_HAS_AES_INTRINSICS
			#define C4D_HAS_PCLMULQDQ_CAPABILITY
			#define C4D_HAS_PCLMULQDQ_INTRINSICS
			#define C4D_HAS_AVX2_CAPABILITY
			#define C4D_HAS_AVX2_INTRINSICS
		#endif
	#elif defined MAXON_TARGET_LINUX
		#define C4D_HAS_SSE4_CAPABILITY
		#define C4D_HAS_AES_CAPABILITY
		#ifdef MAXON_COMPILER_INTEL
			#define C4D_HAS_SSE4_INTRINSICS
			#define C4D_HAS_AES_INTRINSICS
		#endif
	#elif defined MAXON_TARGET_MACOS && defined(MAXON_TARGET_CPU_INTEL)
		#define C4D_HAS_SSE4_CAPABILITY
		// #define C4D_HAS_SSE4_INTRINSICS
		// #define C4D_HAS_AVX_CAPABILITY
		#define C4D_HAS_AES_CAPABILITY
		#include <immintrin.h>
	#endif

	#ifdef MAXON_COMPILER_INTEL
		extern "C" { __m128 vmlsPow4(__m128 a, __m128 b); }
	#endif

	#ifdef __SSE3__
		// only include these files when compiling with -msse3
		#ifdef MAXON_TARGET_LINUX
			#include "pmmintrin.h"
		#endif
		#if defined MAXON_TARGET_MACOS && !defined(MAXON_TARGET_CPU_PPC)
			#include <pmmintrin.h>
		#endif
		#define C4D_HAS_SSE3_INTRINSICS
	#endif
	#ifdef __SSSE3__
		// only include these files when compiling with -mssse3
		#ifdef MAXON_TARGET_LINUX
			#include "tmmintrin.h"
		#endif
		#if defined MAXON_TARGET_MACOS && !defined(MAXON_TARGET_CPU_PPC)
			#include <tmmintrin.h>
		#endif
		#define C4D_HAS_SSSE3_INTRINSICS
	#endif

	#include "maxon/sse_intrinsics_42.h"

#endif // C4D_USE_SSE2_INTRINSICS

#endif // SSE_GENERAL_H__
