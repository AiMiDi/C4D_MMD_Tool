#ifndef OSPLINEHELIX_H__
#define OSPLINEHELIX_H__

enum
{
	PRIM_HELIX_START					= 2031,  // REAL - Start Angle
	PRIM_HELIX_END						= 2032,  // REAL - End Angle
	PRIM_HELIX_RADIUS1				= 2033,  // REAL - First Radius [>=0.0]
	PRIM_HELIX_RADIUS2				= 2034,  // REAL - Second Radius [>=0.0]
	PRIM_HELIX_HEIGHT					= 2035,  // REAL - Height
	PRIM_HELIX_RADIALBIAS			= 2036,  // REAL - Radial Bias [>=0.0; <=1.0]
	PRIM_HELIX_HEIGHTBIAS			= 2037,  // REAL - Height Bias [>=0.0; <=1.0]
	PRIM_HELIX_SUB						= 2038  // LONG - Subdivision [>=3]
};

#endif // OSPLINEHELIX_H__
