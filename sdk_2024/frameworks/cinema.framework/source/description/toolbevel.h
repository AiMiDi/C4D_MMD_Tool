#ifndef TOOLBEVEL_H__
#define TOOLBEVEL_H__

enum
{
	MDATA_BEVEL_PRESERVEGROUPS								= 2040, // BOOL
	MDATA_BEVEL_OFFSET1												= 2041, // REAL
	MDATA_BEVEL_OFFSET2												= 2042, // REAL
	MDATA_BEVEL_ANGLE													= 2043, // REAL
	MDATA_BEVEL_VARIANCE1											= 2044, // REAL
	MDATA_BEVEL_VARIANCE2											= 2045, // REAL
	MDATA_BEVEL_SUBDIVISION										= 2172, // LONG
	MDATA_BEVEL_CREATENGONS										= 2173, // BOOL
	MDATA_BEVEL_PATH													= 2174,	// Spline
	MDATA_BEVEL_MODE                          = 2175, // LONG
		MDATA_BEVEL_MODE_LINEAR                 = 0,
		MDATA_BEVEL_MODE_OUTER_CIRCLE           = 1,
		MDATA_BEVEL_MODE_INNER_CIRCLE           = 2,
		MDATA_BEVEL_MODE_BEZIER                 = 3,
		MDATA_BEVEL_MODE_USER                   = 10,

	MDATA_BEVEL_
};

#endif // TOOLBEVEL_H__
