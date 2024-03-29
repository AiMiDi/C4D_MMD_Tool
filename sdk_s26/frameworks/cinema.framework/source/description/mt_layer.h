#ifndef MT_LAYER_H__
#define MT_LAYER_H__

enum
{
	ID_MT_LAYER_GROUP				= 2002,
	ID_MT_LAYER_MUTE				= 2007,
	ID_MT_LAYER_PASSTHROUGH	= 2009,
	ID_MT_LAYER_VALUE				= 2010,
	ID_MT_LAYER_SOLO				= 2011,
	ID_MT_LAYER_REGION_FC1				= 2012,
	ID_MT_LAYER_REGION_FC2				= 2013,
	ID_MT_LAYER_REGION_TIME1			= 2014,
	ID_MT_LAYER_REGION_TIME2			= 2015,
	ID_MT_LAYER_MODE   						= 2017,
	ID_MT_LAYER_MODE_MIX = 0,
	ID_MT_LAYER_MODE_ADD = 1,
	ID_MT_LAYER_MODE_REP = 2,
	ID_MT_LAYER_ACTIVE	= 2018, // also defined in ckeyframer.cpp !!!
	ID_MT_LAYER_GHOST		= 2020,
	ID_MT_LAYER_QUATERNION	= 2021,

	ID_MT_LAYER_
};

#endif // MT_LAYER_H__
