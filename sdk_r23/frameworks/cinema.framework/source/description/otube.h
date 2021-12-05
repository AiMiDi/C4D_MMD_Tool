#ifndef OTUBE_H__
#define OTUBE_H__

enum
{
	PRIM_TUBE_ORAD						  = 1170, // REAL	  - Outer Radius [>=0.0]
	PRIM_TUBE_IRAD						  = 1171, // REAL   - Inner Radius [>=0.0,<=Outer Radius]
	PRIM_TUBE_HEIGHT					  = 1172, // REAL   - Height [>=0.0]
	PRIM_TUBE_HSUB						  = 1174, // LONG   - Height Subdivision [>0]
	PRIM_TUBE_CSUB						  = 1175, // LONG   - Cap Subdivision [>0]
	PRIM_TUBE_SEG							  = 1176, // LONG   - Rotational Segments [>2]
	PRIM_TUBE_FILLET					  = 1177, // BOOL   - Fillet
	PRIM_TUBE_FSUB						  = 1178, // LONG   - Fillet > Segments
	PRIM_TUBE_FILLET_RADIUS		  = 1179, // REAL   - Fillet > Radius
	PRIM_TUBE_USE_NEW_VERSION   = 1180, // BOOL   - Use migrated generator if true (R20). In the BaseContainer but not in the UI.
	PRIM_TUBE_SWITCH_TO_UPDATED = 1181  // BUTTON - To switch from legacy to migrated generator.
};

#endif // OTUBE_H__
