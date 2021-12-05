#ifndef TAKEBASE_H__
#define TAKEBASE_H__

enum
{
	TAKEBASE_INDEX				= 1000,		// Int32
	TAKEBASE_CAMERA				= 10002,	// link
	TAKEBASE_RDATA				= 10003,	// link
	TAKEBASE_CAMERA_COMBO = 10004,	// Int32 cycle
	TAKEBASE_RDATA_COMBO	= 10005,	// Int32 cycle
	TAKEBASE_NOTES				= 10006,	// String
	TAKEBASE_OVERRIDES		= 20000,	// link list
	TAKEBASE_CHECK				=	20001,	// Bool take is checked

	TAKEBASE
};

#endif // TAKEBASE_H__
