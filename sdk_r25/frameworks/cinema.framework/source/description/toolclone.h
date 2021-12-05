#ifndef TOOLCLONE_H__
#define TOOLCLONE_H__

enum
{
	MDATA_CLONE_CNT														= 2055, // LONG
	MDATA_CLONE_HOLES													= 2056, // REAL
	MDATA_CLONE_AXIS													= 2057, // LONG
		MDATA_CLONE_AXIS_X                      = 0,
		MDATA_CLONE_AXIS_Y                      = 1,
		MDATA_CLONE_AXIS_Z                      = 2,
	MDATA_CLONE_OFFSET												= 2058, // REAL
	MDATA_CLONE_SCALE													= 2059, // REAL
	MDATA_CLONE_ROTATION											= 2060, // REAL
	MDATA_CLONE_LOCALMOVE											= 2062, // VECTOR
	MDATA_CLONE_LOCALSCALE										= 2063, // VECTOR
	MDATA_CLONE_LOCALROTATE										= 2064, // VECTOR
	MDATA_CLONE_KEEPFORM											= 2065, // BOOL

	MDATA_CLONE_
};

#endif // TOOLCLONE_H__
