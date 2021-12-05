#ifndef OCONE_H__
#define OCONE_H__

enum
{
	ID_CONECAPS									= 820,

	PRIM_CONE_TRAD							= 1130, // REAL 	 - Top Radius [>=0.0]
	PRIM_CONE_BRAD							= 1131, // REAL  	 - Bottom Radius [>=0.0]
	PRIM_CONE_HEIGHT						= 1132, // REAL    - Height [>=0.0]
	PRIM_CONE_HSUB							= 1133, // LONG  	 - Height Segments [>0]
	PRIM_CONE_CSUB							= 1134, // LONG    - Cap Segments [>0]
	PRIM_CONE_SEG								= 1135, // LONG    - Rotational Segments [>2]
	PRIM_CONE_TOPFILLET_RADIUS	= 1137, // REAL	   - Top Fillet Radius [>=0.0, <=TopRad, TopFil+BotFil<=Height]
	PRIM_CONE_BOTFILLET_RADIUS	= 1138, // REAL	   - Bottom Fillet Radius [>=0.0, <=TopRad, TopFil+BotFil<=Height]
	PRIM_CONE_TOPFILLET_HEIGHT	= 1139, // REAL    - Top Fillet Y [>=0.0, overwrites Y component of TFILLET]
	PRIM_CONE_BOTFILLET_HEIGHT	= 1140, // REAL    - Bottom Fillet Y [>=0.0, overwrites Y component of BFILLET]
	PRIM_CONE_FSUB							= 1141, // LONG	   - Fillet Subdivision [>0]
	PRIM_CONE_TOPFILLET					= 1142,	// BOOL		 - Caps > Top
	PRIM_CONE_BOTFILLET					= 1143, // BOOL		 - Caps > Bottom
	PRIM_CONE_CAPS							= 1144,	// BOOL		 - Caps > Caps
	PRIM_CONE_USE_NEW_VERSION		= 1145,	// BOOL		 - Use migrated generator if true (R20). In the BaseContainer but not in the UI.
	PRIM_CONE_SWITCH_TO_UPDATED	= 1146  // BUTTON  - To switch from legacy to migrated generator.
};

#endif // OCONE_H__
