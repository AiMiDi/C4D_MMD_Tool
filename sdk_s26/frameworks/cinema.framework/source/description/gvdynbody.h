#ifndef GVDYNBODY_H__
#define GVDYNBODY_H__

#include "gvbase.h"

enum
{
	DYNAMICS_BODY_NODE_OBJECT = 10001,

	DYNAMICS_BODY_NODE_INPUT_ON = 10100,
	DYNAMICS_BODY_NODE_INPUT_INDEX = 10101,
	DYNAMICS_BODY_NODE_INPUT_OBJECT = 10111,
	DYNAMICS_BODY_NODE_INPUT_MASS = 10112,
	DYNAMICS_BODY_NODE_INPUT_POINT_INDEX = 10113,
	DYNAMICS_BODY_NODE_INPUT_TRIGGER = 10114,
	DYNAMICS_BODY_NODE_INPUT_POSITION = 10121,
	DYNAMICS_BODY_NODE_INPUT_ROTATION = 10122,
	DYNAMICS_BODY_NODE_INPUT_LOCAL_POSITION = 10123,
	DYNAMICS_BODY_NODE_INPUT_MATRIX = 10124,
	DYNAMICS_BODY_NODE_INPUT_LINEAR_VELOCITY = 10131,
	DYNAMICS_BODY_NODE_INPUT_ANGULAR_VELOCITY = 10132,
	DYNAMICS_BODY_NODE_INPUT_ADD_FORCE = 10135,
	DYNAMICS_BODY_NODE_INPUT_ADD_TORQUE = 10136,
	DYNAMICS_BODY_NODE_INPUT_ADD_LINEAR_ACCELERATION = 10137,
	DYNAMICS_BODY_NODE_INPUT_ADD_ANGULAR_ACCELERATION = 10138,
	DYNAMICS_BODY_NODE_INPUT_POINT_OF_APPLICATION = 10139,
	DYNAMICS_BODY_NODE_INPUT_LOCAL_POINT_OF_APPLICATION = 10140,

	DYNAMICS_BODY_NODE_OUTPUT_COUNT = 10201,
	DYNAMICS_BODY_NODE_OUTPUT_OBJECT = 10211,
	DYNAMICS_BODY_NODE_OUTPUT_MASS = 10212,
	DYNAMICS_BODY_NODE_OUTPUT_TAG = 10213,
	DYNAMICS_BODY_NODE_OUTPUT_INDEX = 10214,
	DYNAMICS_BODY_NODE_OUTPUT_DYNAMIC = 10215,
	DYNAMICS_BODY_NODE_OUTPUT_POSITION = 10221,
	DYNAMICS_BODY_NODE_OUTPUT_ROTATION = 10222,
	DYNAMICS_BODY_NODE_OUTPUT_LOCAL_POSITION = 10223,
	DYNAMICS_BODY_NODE_OUTPUT_MATRIX = 10224,
	DYNAMICS_BODY_NODE_OUTPUT_LINEAR_VELOCITY = 10231,
	DYNAMICS_BODY_NODE_OUTPUT_ANGULAR_VELOCITY = 10232,
	DYNAMICS_BODY_NODE_OUTPUT_FORCE = 10235,
	DYNAMICS_BODY_NODE_OUTPUT_TORQUE = 10236,
	DYNAMICS_BODY_NODE_OUTPUT_LINEAR_ACCELERATION = 10237,
	DYNAMICS_BODY_NODE_OUTPUT_ANGULAR_ACCELERATION = 10238,
};

#endif // GVDYNBODY_H__
