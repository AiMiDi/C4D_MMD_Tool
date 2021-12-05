#ifndef OTUBE_H__
#define OTUBE_H__

enum
{
	PRIM_TUBE_ORAD						= 1170, // REAL	   - Outer Radius [>=0.0]
	PRIM_TUBE_IRAD						= 1171, // REAL     - Inner Radius [>=0.0,<=Outer Radius]
	PRIM_TUBE_HEIGHT					= 1172, // REAL     - Height [>=0.0]
	PRIM_TUBE_HSUB						= 1174, // LONG     - Height Subdivision [>0]
	PRIM_TUBE_CSUB						= 1175, // LONG     - Cap Subdivision [>0]
	PRIM_TUBE_SEG							= 1176, // LONG     - Rotational Segments [>2]
	PRIM_TUBE_FILLET					= 1177, // BOOL
	PRIM_TUBE_FSUB						= 1178, // LONG
	PRIM_TUBE_FILLET_RADIUS		= 1179
};

#endif // OTUBE_H__
