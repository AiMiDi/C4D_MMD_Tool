#ifndef SSE_INTRINSICS_42_H__
#define SSE_INTRINSICS_42_H__

namespace maxon
{

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// This file defines the intrinsics that are not available from the compiler.
//----------------------------------------------------------------------------------------

#ifndef SSE_GENERAL_H__
#error Do not include this file directly. Include sse_general.h or a file which includes this instead.
#endif

#if defined __GNUC__ || defined(__llvm__)
	#define C4D_SSE_ASM_CALL		asm volatile
#endif

#ifndef C4D_HAS_SSE4_INTRINSICS
	// no intrinsics available, emulate them via inline assembly call
	#ifdef MAXON_TARGET_64BIT

		inline UInt64 _mm_crc32_u64(UInt64 c, UInt64 d)
		{
			C4D_SSE_ASM_CALL("crc32q %1, %0" : "=r"(c) : "r"(d), "0"(c) : );
			return c;
		}
	#endif
	inline unsigned int _mm_crc32_u32(UInt32 c, UInt32 d)
	{
		C4D_SSE_ASM_CALL("crc32l %1, %0" : "=r"(c) : "r"(d), "0"(c) : );
		return c;
	}
	inline unsigned int _mm_crc32_u8(UInt32 c, UChar d)
	{
		C4D_SSE_ASM_CALL("crc32b %1, %0" : "=r"(c) : "r"(d), "0"(c) : );
		return c;
	}
#endif // !C4D_HAS_SSE4_INTRINSICS

#if defined C4D_HAS_AES_CAPABILITY && !defined C4D_HAS_AES_INTRINSICS
	inline __m128i _mm_aesdec_si128(__m128i a, __m128i b)
	{
		C4D_SSE_ASM_CALL("aesdec %1, %0" : "+x"(a) : "xm"(b));
		return a;
	}
	inline __m128i _mm_aesdeclast_si128(__m128i a, __m128i b)
	{
		C4D_SSE_ASM_CALL("aesdeclast %1, %0" : "+x"(a) : "xm"(b));
		return a;
	}
	inline __m128i _mm_aesenc_si128(__m128i a, __m128i b)
	{
		C4D_SSE_ASM_CALL("aesenc %1, %0" : "+x"(a) : "xm"(b));
		return a;
	}
	inline __m128i _mm_aesenclast_si128(__m128i a, __m128i b)
	{
		C4D_SSE_ASM_CALL("aesenclast %1, %0" : "+x"(a) : "xm"(b));
		return a;
	}
	template<Int B> inline __m128i _mm_aeskeygenassist_si128_template(__m128i a)
	{
		__m128i r;
		C4D_SSE_ASM_CALL("aeskeygenassist %2, %1, %0" : "=x"(r) : "xm"(a), "i"(B));
		return r;
	}
	#undef _mm_aeskeygenassist_si128
	#define _mm_aeskeygenassist_si128(a, b) _mm_aeskeygenassist_si128_template<b>(a)
	inline __m128i _mm_aesimc_si128(__m128i a)
	{
		__m128i r;
		C4D_SSE_ASM_CALL("aesimc %1, %0" : "=x"(r) : "xm"(a));
		return r;
	}
	inline __m128i _mm_blendv_epi8(__m128i value, __m128i input, __m128i mask)
	{
		// mask needs to be in xmm0
#ifdef MAXON_TARGET_LINUX
	#if defined (MAXON_COMPILER_GCC)
		C4D_SSE_ASM_CALL("pblendvb %1, %0" : "=x"(value) : "x"(input), "0"(value), "Yz"(mask));
	#elif defined (MAXON_COMPILER_CLANG)
		register __m128i m asm ("xmm0") = mask;
		C4D_SSE_ASM_CALL("pblendvb %1, %0" : "+x"(value) : "x"(input), "x"(m));
	#endif
#elif defined MAXON_TARGET_MACOS
		register __m128i m asm ("xmm0") = mask;
		C4D_SSE_ASM_CALL("pblendvb %1, %0" : "+x"(value) : "x"(input), "x"(m));
#endif
		return value;
	}
#endif

#ifndef MAXON_TARGET_64BIT
inline UInt64 _mm_crc32_u64(UInt64 c, UInt64 d)
{
	UInt32 crc = (UInt32)(c & 0xffffffff);
	crc = _mm_crc32_u32(crc, (d & 0xffffffff));
	crc = _mm_crc32_u32(crc, ((d >> 32) & 0xffffffff));
	return crc;
}
#endif

#undef C4D_SSE_ASM_CALL

} // namespace maxon

#endif // SSE_INTRINSICS_42_H__
