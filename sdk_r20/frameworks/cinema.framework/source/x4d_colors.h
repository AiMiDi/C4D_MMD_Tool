/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef X4D_COLORS_H__
#define X4D_COLORS_H__

#include "ge_math.h"
#include "x4d_macros.h"	// defines for platform independency

//----------------------------------------------------------------------------------------
// Colors and color spaces
//----------------------------------------------------------------------------------------

enum													// Color spaces (color_space)
{
	CSPACE_MASK				=	0x00ff,	// the lower bits contain the color space id

	CSPACE_ALPHA_FLAG	= 0x0100,	// alpha flag

	CSPACE_UNKNOWN		=	0x0000,

	CSPACE_RGB				=	0x0001,	// RGB color space
	CSPACE_ARGB				=	0x0101,	// RGB color space with alpha channel

	CSPACE_GRAY				=	0x0007,	// gray space
	CSPACE_AGRAY			=	0x0107	// gray with alpha
};

//----------------------------------------------------------------------------------------
// Pixel formats
//----------------------------------------------------------------------------------------

// number of bits per component
#define	PX_DEPTH_8	0x30000000UL	// channel depth: 8 bits per component
#define	PX_DEPTH_16	0x40000000UL	// channel depth: 16 bits per component
#define	PX_DEPTH_32	0x50000000UL	// channel depth: 24 bits per component

// number of used pixel components
#define	PX_1COMP 0x01000000UL	// pixel consists of one used component: color index
#define	PX_2COMP 0x02000000UL	// pixel consists of two used components, e.g. AG
#define	PX_3COMP 0x03000000UL	// pixel consists of three used components, e.g. RGB, YCbCr, XYZ, Yxy, Lab, Luv
#define	PX_4COMP 0x04000000UL	// pixel consists of four used components, e.g. CMYK, ARGB

// little endian flags
#define	PX_CMPTREVERSED	0x00080000UL	// component order remains unchanged but multi-byte components are stored in reversed byte order

// bit packing
#define	PX_FLOAT	0x00030000UL	// components are IEEE floats ...
#define	PX_PACKED	0x00020000UL	// components are packed (default case), one byte for red is followed by one for green and blue - the same goes for the next pixel

// number of used bits
#define	PX_USES8	 0x00000800UL	// 8 bits of the pixel are used
#define	PX_USES16	 0x00001000UL	// 16 bits of the pixel are used
#define	PX_USES24	 0x00001800UL	// 24 bits of the pixel are used
#define	PX_USES32	 0x00002000UL	// 32 bits of the pixel are used
#define	PX_USES48	 0x00003000UL	// 48 bits of the pixel are used
#define	PX_USES64	 0x00004000UL	// 64 bits of the pixel are used
#define	PX_USES96	 0x00006000UL	// 96 bits of the pixel are used
#define	PX_USES128 0x00008000UL	// 128 bits of the pixel are used

// number of bits per pixel
#define	PX_8BIT		0x00000008UL	// pixel consists of 8 bits
#define	PX_16BIT	0x00000010UL	// pixel consists of 16 bits
#define	PX_24BIT	0x00000018UL	// pixel consists of 24 bits
#define	PX_32BIT	0x00000020UL	// pixel consists of 32 bits
#define	PX_48BIT	0x00000030UL	// pixel consists of 48 bits
#define	PX_64BIT	0x00000040UL	// pixel consists of 64 bits
#define	PX_96BIT	0x00000060UL	// pixel consists of 96 bits
#define	PX_128BIT	0x00000080UL	// pixel consists of 128 bits

// masks
#define	PX_DEPTH	 0x70000000UL	// bits per component (a shift value)
#define	PX_CMPNTS	 0x0f000000UL	// number of pixel components
#define	PX_PACKING 0x00030000UL	// bit packing
#define	PX_USED		 0x0000ff00UL	// number of used bits
#define	PX_BITS		 0x000000ffUL	// total number of bits

//----------------------------------------------------------------------------------------
// easy access macros
//----------------------------------------------------------------------------------------
#define	get_PX_CMPNTS(px_format) (((px_format) & PX_CMPNTS) >> 24)	// number of components
#define	get_PX_USED(px_format)	 (((px_format) & PX_USED) >> 8)			// number of used bits per pixel
#define	get_PX_BITS(px_format)	 (((px_format) & PX_BITS))					// total number of bits per pixel
#define	get_PX_DEPTH(px_format)	 (((px_format) & PX_DEPTH))					//

//----------------------------------------------------------------------------------------
// some RGB pixel formats
//----------------------------------------------------------------------------------------
#define	PX_RGB24 (PX_DEPTH_8 + PX_3COMP + PX_PACKED + PX_USES24 + PX_24BIT)

#if GE_LITTLE_ENDIAN	// multi-byte components with little endian byte order
	#define	PX_RGB48 (PX_DEPTH_16 + PX_3COMP + PX_PACKED + PX_USES48 + PX_48BIT + PX_CMPTREVERSED)
	#define	PX_RGB96 (PX_DEPTH_32 + PX_3COMP + PX_FLOAT + PX_USES96 + PX_96BIT + PX_CMPTREVERSED)
#else	// multi-byte components with big endian byte order
	#define	PX_RGB48 (PX_DEPTH_16 + PX_3COMP + PX_PACKED + PX_USES48 + PX_48BIT)
	#define	PX_RGB96 (PX_DEPTH_32 + PX_3COMP + PX_FLOAT + PX_USES96 + PX_96BIT)
#endif

//----------------------------------------------------------------------------------------
// pixel formats for RGB with alpha
//----------------------------------------------------------------------------------------
#define	PX_ARGB32	(PX_DEPTH_8 + PX_4COMP + PX_PACKED + PX_USES32 + PX_32BIT)

#if GE_LITTLE_ENDIAN	// multi-byte components with little endian byte order
	#define	PX_ARGB64	 (PX_DEPTH_16 + PX_4COMP + PX_PACKED + PX_USES64 + PX_64BIT + PX_CMPTREVERSED)
	#define	PX_ARGB128 (PX_DEPTH_32 + PX_4COMP + PX_FLOAT + PX_USES128 + PX_128BIT + PX_CMPTREVERSED)
#else	// multi-byte components with big endian byte order
	#define	PX_ARGB64	 (PX_DEPTH_16 + PX_4COMP + PX_PACKED + PX_USES64 + PX_64BIT)
	#define	PX_ARGB128 (PX_DEPTH_32 + PX_4COMP + PX_FLOAT + PX_USES128 + PX_128BIT)
#endif

//----------------------------------------------------------------------------------------
// pixel formats for gray
//----------------------------------------------------------------------------------------
#define	PX_GRAY8 (PX_DEPTH_8 + PX_1COMP + PX_PACKED + PX_USES8 + PX_8BIT)

#if GE_LITTLE_ENDIAN	// multi-byte components with little endian byte order
	#define	PX_GRAY16	(PX_DEPTH_16 + PX_1COMP + PX_PACKED + PX_USES16 + PX_16BIT)
	#define	PX_GRAY32	(PX_DEPTH_32 + PX_1COMP + PX_FLOAT + PX_USES32 + PX_32BIT)
#else	// multi-byte components with big endian byte order
	#define	PX_GRAY16	(PX_DEPTH_16 + PX_1COMP + PX_PACKED + PX_USES16 + PX_16BIT)
	#define	PX_GRAY32	(PX_DEPTH_32 + PX_1COMP + PX_FLOAT + PX_USES32 + PX_32BIT)
#endif

//----------------------------------------------------------------------------------------
// pixel formats for gray with alpha
//----------------------------------------------------------------------------------------
#define	PX_AGRAY16 (PX_DEPTH_8 + PX_2COMP + PX_PACKED + PX_USES16 + PX_16BIT)

#if GE_LITTLE_ENDIAN	// multi-byte components with little endian byte order
	#define	PX_AGRAY32 (PX_DEPTH_16 + PX_2COMP + PX_PACKED + PX_USES32 + PX_32BIT + PX_CMPTREVERSED)
	#define	PX_AGRAY64 (PX_DEPTH_32 + PX_2COMP + PX_FLOAT + PX_USES64 + PX_64BIT + PX_CMPTREVERSED)
#else	// multi-byte components with big endian byte order
	#define	PX_AGRAY32 (PX_DEPTH_16 + PX_2COMP + PX_PACKED + PX_USES32 + PX_32BIT)
	#define	PX_AGRAY64 (PX_DEPTH_32 + PX_2COMP + PX_FLOAT + PX_USES64 + PX_64BIT)
#endif

#endif // X4D_COLORS_H__
