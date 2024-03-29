#ifndef GVRAY_H__
#define GVRAY_H__

#include "gvbase.h"

enum
{
	GV_RAY_TEST_ONLY = 1000,
	GV_RAY_GLOBAL,

	GV_RAY_INPUT_OBJECT					= 2000,
	GV_RAY_INPUT_POINT1,
	GV_RAY_INPUT_POINT2,

	GV_RAY_OUTPUT						= 3000,
	GV_RAY_OUTPUT_HITPOS,
	GV_RAY_OUTPUT_FACE_INDEX,
	GV_RAY_OUTPUT_FACE_NORMAL,
	GV_RAY_OUTPUT_PHONG_NORMAL,
	GV_RAY_OUTPUT_DISTANCE,
	GV_RAY_OUTPUT_BACKFACE,

	GV_RAY_
};

#endif // GVRAY_H__
