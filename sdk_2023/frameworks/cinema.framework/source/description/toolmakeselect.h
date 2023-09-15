#ifndef TOOLMAKESELECT_H__
#define TOOLMAKESELECT_H__

enum
{
	MDATA_MAKESELECT_SELECT			= 900,

	MDATA_MAKESELECT_NGONS			= 1100,		// Bool
	MDATA_MAKESELECT_QUADS			= 1101,		// Bool
	MDATA_MAKESELECT_TRIS			= 1102,		// Bool
	MDATA_MAKESELECT_STATE			= 1103,		// LONG

	//////////////////////////////////////////////////////////////////////////

	MDATA_MAKESELECT_STATE_ANY				= 0,
	MDATA_MAKESELECT_STATE_PLANAR			= 1,
	MDATA_MAKESELECT_STATE_NONDEGENERATE	= 2,
	MDATA_MAKESELECT_STATE_NONPLANAR		= 3,
	MDATA_MAKESELECT_STATE_DEGENERATE		= 4,

	//////////////////////////////////////////////////////////////////////////

	MDATA_MAKESELECT_
};

#endif // TOOLMAKESELECT_H__
