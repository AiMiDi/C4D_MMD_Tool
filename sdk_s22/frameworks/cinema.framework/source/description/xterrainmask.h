////////////////////////////////////////////////////////////////
// xTerrainmask
////////////////////////////////////////////////////////////////
// (c) 2010 MAXON Computer GmbH, all rights reserved
////////////////////////////////////////////////////////////////

#ifndef XTERRAINMASK_H__
#define XTERRAINMASK_H__

enum
{
	XTMASK_GRADIENT								= 10000,					// GRADIENT

	XTMASK_ALTITUDE_ENABLE				= 10020,					// BOOL
	XTMASK_ALTITUDE_MIN						=	10001,					// REAL
	XTMASK_ALTITUDE_MAX						= 10002,					// REAL
	XTMASK_ALTITUDE_SOFTEN_MIN		= 10003,					// REAL
	XTMASK_ALTITUDE_SOFTEN_MAX		= 10004,					// REAL
	XTMASK_ALTITUDE_NOISE_HEIGHT	= 10005,					// REAL
	XTMASK_ALTITUDE_NOISE_SCALE		= 10006,					// REAL

	XTMASK_SLOPE_ENABLE						= 10010,					// BOOL
	XTMASK_SLOPE_MIN							= 10011,					// REAL
	XTMASK_SLOPE_MAX							= 10012,					// REAL
	XTMASK_SLOPE_SOFTEN_MIN				= 10013,					// REAL
	XTMASK_SLOPE_SOFTEN_MAX				= 10014,					// REAL
	XTMASK_SLOPE_DIRECTION				= 10015,					// LONG
		XTMASK_DIRECTION_Y						= 1,							// CYCLE VALUE
		XTMASK_DIRECTION_CUSTOM				= 2,							// CYCLE VALUE
		XTMASK_DIRECTION_X						= 3,							// CYCLE VALUE
		XTMASK_DIRECTION_Z						= 4,							// CYCLE VALUE
		XTMASK_DIRECTION_X2						= 5,							// CYCLE VALUE
		XTMASK_DIRECTION_Y2						= 6,							// CYCLE VALUE
		XTMASK_DIRECTION_Z2						= 7,							// CYCLE VALUE
	XTMASK_SLOPE_DIRECTION_CUSTOM	= 10016,					// VECTOR
	XTMASK_SLOPE_USEBUMP					= 10017,					// BOOL
	XTMASK_SLOPE_ALTERNATIVEBLENDING		= 10023,						// BOOL
	XTMASK_SLOPE_ALTERNATIVEBLENDING_HARDNESS = 10024,				// REAL

	XTMASK_GLOBAL									= 10021,					// BOOL
	XTMASK_INVERT									= 10022						// BOOL
};
#endif // XTERRAINMASK_H__
