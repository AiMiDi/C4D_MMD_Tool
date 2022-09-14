/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef X4D_MACROS_H__
#define X4D_MACROS_H__

#define offsetofI(s, m) ((size_t) & (((s*)0)->m))	// from stddef

//----------------------------------------------------------------------------------------
// Structure alignment
//----------------------------------------------------------------------------------------
#define	VARIABLE_ARRAY_SIZE	1	// constant for arrays with variable size

//----------------------------------------------------------------------------------------
// Byte order for the destination platform
//----------------------------------------------------------------------------------------
#if _MSC_VER	// MSVC

	#define	GE_LITTLE_ENDIAN 1
	#ifndef LITTLE_ENDIAN
		#define	LITTLE_ENDIAN	"please replace with GE_LITTLE_ENDIAN"
	#endif

#elif	__GNUC__	// GNU
	#ifdef __BIG_ENDIAN__
		#define	GE_LITTLE_ENDIAN 0
	#elif	defined(__LITTLE_ENDIAN__)
		#define	GE_LITTLE_ENDIAN 1
	#else
		#if defined(__ppc__) || defined(__ppc64__)			// PPC-Code
			#define	GE_LITTLE_ENDIAN 0
		#elif defined(__m68k__)													// 68k-Code
			#define	GE_LITTLE_ENDIAN 0
		#elif defined(__i386__)	|| defined(__x86_64__)	// x86-Code
			#define	GE_LITTLE_ENDIAN 1
		#endif
	#endif
#else

	#error	"Unknown compiler, unknown endian format"

#endif

//----------------------------------------------------------------------------------------
// Macros for changing the byte order
//----------------------------------------------------------------------------------------
#define	REVERSEu16(a)	(UInt16) (((UInt16)(a) >> 8) | ((UInt16)(a) << 8))
#define	REVERSEu32(a)	(UInt32) (((UInt32)(a) << 24) | (((UInt32)(a) & 0xff00UL) << 8) | (((UInt32)(a) >> 8) & 0xff00UL) | ((UInt32)(a) >> 24))

//----------------------------------------------------------------------------------------
// Character constants
//----------------------------------------------------------------------------------------
#if GE_LITTLE_ENDIAN	// reverse byte order
	#define	CHAR_CONST32(a)	(UInt32) (((UInt32)(a) << 24) | (((UInt32)(a) & 0xff00UL) << 8) | (((UInt32)(a) >> 8) & 0xff00UL) | ((UInt32)(a) >> 24))
#else									// usual byte order
	#define	CHAR_CONST32(a)	(UInt32) (a)
#endif

#endif // X4D_MACROS_H__
