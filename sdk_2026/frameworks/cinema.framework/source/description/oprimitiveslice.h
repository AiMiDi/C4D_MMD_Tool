#ifndef OPRIMITIVESLICE_H__
#define OPRIMITIVESLICE_H__

enum
{
	ID_SLICE = 899, // from Obase.h

	PRIM_SLICE								= 1200, // BOOL     - Slicing
	PRIM_SLICEFROM						= 1201, // REAL     - Start Angle
	PRIM_SLICETO							= 1202, // REAL     - End Angle [>=Start Angle]
	PRIM_REGULAR							= 1203, // BOOL		 - Regular Grid
	PRIM_REGULARWIDTH					= 1204 // REAL		 - Regular Grid Width
};

#endif // OPRIMITIVESLICE_H__
