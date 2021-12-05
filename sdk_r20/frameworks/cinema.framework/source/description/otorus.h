#ifndef OTORUS_H__
#define OTORUS_H__

enum
{
	PRIM_TORUS_OUTERRAD				= 1150, // REAL	   - Outer Radius [>=0.0]
	PRIM_TORUS_INNERRAD				= 1151, // REAL     - Inner Radius [>=0.0,<=Outer Radius]
	PRIM_TORUS_CSUB						= 1152, // LONG	   - Cross Section Segments [>2]
	PRIM_TORUS_SEG						= 1153 // LONG     - Rotational Segments [>2]
};

#endif // OTORUS_H__
