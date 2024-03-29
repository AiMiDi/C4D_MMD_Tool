#ifndef GVPOINT_H__
#define GVPOINT_H__

#include "gvbase.h"

enum
{
	GV_POINT_MODE									= 1000,
		GV_POINT_OPERATOR_MODE_GLOBAL = 100,
		GV_POINT_OPERATOR_MODE_LOCAL,
	GV_POINT_USE_DEFORMED,

	GV_POINT_INPUT_OBJECT					= 2000,
	GV_POINT_INPUT_POINT,
	GV_POINT_INPUT_POSITION,

	GV_POINT_OUTPUT_POINT					= 3000,
	GV_POINT_OUTPUT_POSITION,
	GV_POINT_OUTPUT_NORMAL,

	GV_POINT_
};

#endif // GVPOINT_H__
