#ifndef GVHAIR_PROXIMITY_H__
#define GVHAIR_PROXIMITY_H__

#include "gvbase.h"

enum
{
	GV_HAIR_PROXIMITY_MODE									= 1900,
		GV_HAIR_PROXIMITY_MODE_GUIDE					= 2,
		GV_HAIR_PROXIMITY_MODE_DYNAMIC_GUIDE	= 3,
		GV_HAIR_PROXIMITY_MODE_HAIR						= 4,
	GV_HAIR_PROXIMITY_OBJECT								= 1901,

	GV_HAIR_PROXIMITY_INPUT_OBJECT	= 2000,
	GV_HAIR_PROXIMITY_INPUT_POINT	= 2001,

	GV_HAIR_PROXIMITY_POINT_INT		= 3000,
	GV_HAIR_PROXIMITY_POINT_VEC		= 3001,
	GV_HAIR_PROXIMITY_POINT_GUIDE	= 3002,
	GV_HAIR_PROXIMITY_POINT_SEGMENT	= 3003,
	GV_HAIR_PROXIMITY_POINT_T			= 3004,

	GV_HAIR_PROXIMITY
};

#endif // GVHAIR_PROXIMITY_H__
