#ifndef OCONE_H__
#define OCONE_H__

enum
{
	ID_CONECAPS									= 820,

	PRIM_CONE_TRAD							= 1130, // REAL 	 - Ptop Radius [>=0.0]
	PRIM_CONE_BRAD							= 1131, // REAL  	 - Pbottom Radius [>=0.0]
	PRIM_CONE_HEIGHT						= 1132, // REAL    - Height [>=0.0]
	PRIM_CONE_HSUB							= 1133, // LONG  	 - Height Segments [>0]
	PRIM_CONE_CSUB							= 1134, // LONG    - Cap Segments [>0]
	PRIM_CONE_SEG								= 1135, // LONG    - Rotational Segments [>2]
	PRIM_CONE_TOPFILLET_RADIUS	= 1137, // REAL	   - Ptop Fillet [>=0.0, <=TopRad, TopFil+BotFil<=Height]
	PRIM_CONE_BOTFILLET_RADIUS	= 1138, // REAL	   - Botom Fillet [>=0.0, <=TopRad, TopFil+BotFil<=Height]
	PRIM_CONE_TOPFILLET_HEIGHT	= 1139, // REAL    - Ptop Fillet Y [>=0.0, overwrites Y component of TFILLET]
	PRIM_CONE_BOTFILLET_HEIGHT	= 1140, // REAL    - Pbottom Fillet Y [>=0.0, overwrites Y component of BFILLET]
	PRIM_CONE_FSUB							= 1141, // LONG	   - Fillet Subdivision [>0]
	PRIM_CONE_TOPFILLET					= 1142,	// BOOL
	PRIM_CONE_BOTFILLET					= 1143, // BOOL
	PRIM_CONE_CAPS							= 1144
};

#endif // OCONE_H__
