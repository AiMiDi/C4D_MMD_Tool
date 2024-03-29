#ifndef OP_STORM_H__
#define OP_STORM_H__

#include "gvbase.h"

enum
{
	ST_VERSION = 1000,
	ST_BTYPE,
	ST_COUNT,
	ST_RATE,
	ST_SHOT,
	ST_LIFE,
	ST_LIFEVAR,
	ST_SPEED,
	ST_SPEEDVAR,
	ST_SIZE,
	ST_SIZEVAR,
	ST_XANGLE,
	ST_XSIZE,
	ST_YANGLE,
	ST_YSIZE,
	ST_SEED,
	ST_DIST,
	ST_DISTVAR,
	ST_SPIN,
	ST_SPINVAR,
	ST_SPINTYPE,
	ST_SPINAXIS,
	ST_TYPE,

	ST_TYPE_RECTANGLE = 0,
	ST_TYPE_CIRCLE,

	ST_BTYPE_COUNT = 0,
	ST_BTYPE_RATE,
	ST_BTYPE_SHOT,

	ST_SPINTYPE_RANDOM = 0,
	ST_SPINTYPE_USER,


//Inports
	IN_ST_ON = 2000,
	IN_ST_ATIME,
	IN_ST_POSITION,
	IN_ST_ALIGNMENT,
	IN_ST_VELOCITY,
	IN_ST_BIRTHRATE,
	OUT_ST_PARTICLE = 3000,
	OUT_ST_PARTICLECOUNT,
	OUT_ST_PARTICLENUM
};






#endif // OP_STORM_H__
