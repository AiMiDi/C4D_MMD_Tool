////////////////////////////////////////////////////////////////
// xnormalizer
////////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved
////////////////////////////////////////////////////////////////

#ifndef XNORMALIZER_H__
#define XNORMALIZER_H__

enum
{
	XNORM_SHADERLINK			=	10001,		// SHADERLINK
	XNORM_STRENGTH				= 10002,		// REAL
	XNORM_FILTER					= 10003,		// BOOL
		XNORM_FILTER_CONDENSED		= 0,		// CYCLE VAL
		XNORM_FILTER_SOBEL_2X			= 1,		// CYCLE VAL
		XNORM_FILTER_SOBEL_4X			= 2,		// CYCLE VAL
	XNORM_INVERT					= 10004,			// BOOL
	XNORM_DELTA						= 10005,			// REAL
	XNORM_CLAMP_UV				= 10006				// BOOL
};

#endif // XNORMALIZER_H__
