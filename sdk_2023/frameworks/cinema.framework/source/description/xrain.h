////////////////////////////////////////////////////////////////
// xrain
////////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved
////////////////////////////////////////////////////////////////

#ifndef XRAIN_H__
#define XRAIN_H__

enum
{
	XRAIN_SHADERLINK				=	10001,		// SHADERLINK
	XRAIN_INTENSITY					= 10002,		// REAL
	XRAIN_SAMPLES						= 10003,		// LONG
	XRAIN_DIRECTION					= 10004,		// LONG
		XRAIN_DIRECTION_U1			= 1,				// CYCLE OPTION
		XRAIN_DIRECTION_U2			= 2,				// CYCLE OPTION
		XRAIN_DIRECTION_V1			= 3,				// CYCLE OPTION
		XRAIN_DIRECTION_V2			= 4,				// CYCLE OPTION
	XRAIN_WEIGHTED					= 10005,		// LONG
		XRAIN_WEIGHTED_NONE			= 0,				// CYCLE OPTION
		XRAIN_WEIGHTED_1				= 1,				// CYCLE OPTION
		XRAIN_WEIGHTED_2				= 2,				// CYCLE OPTION
	XRAIN_CLAMP							= 10006,		// BOOL
	XRAIN_WEIGHTSHADER_INTENSITY	= 10007,		// REAL
	XRAIN_WEIGHTSHADER_LINK				= 10008			// SHADERLINK
};

#endif // XRAIN_H__
