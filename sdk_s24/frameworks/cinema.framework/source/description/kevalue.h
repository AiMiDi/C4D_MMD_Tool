#ifndef KEVALUE_H__
#define KEVALUE_H__

#include "kebase.h"

enum
{
	KE_VALUE							= 1000,
	KE_VALUE_LEFT					= 1001,
	KE_VALUE_RIGHT				= 1002,
	KE_TIME_LEFT					= 1003,
	KE_TIME_RIGHT					= 1004,
	KE_STR_LEFT						= 1005,
	KE_STR_RIGHT					= 1006,

	KE_INTER_LEFT					= 1007,
	KE_INTER_RIGHT				= 1008,
		INTER_CUSTOM = 0,
		INTER_SOFT   = 1,
		INTER_HARD   = 2,
		INTER_STEP   = 3,
		INTER_SLOW   = 4,
		INTER_FAST   = 5,
		INTER_NONE   = 6,

	KE_LINK_LEFTRIGHT			= 1009,
	KE_CLAMP_LEFT         = 1010,
	KE_CLAMP_RIGHT        = 1011,

	KE_DUMMY
};

#endif // KEVALUE_H__
