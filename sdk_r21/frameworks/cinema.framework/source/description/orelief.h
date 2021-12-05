#ifndef ORELIEF_H__
#define ORELIEF_H__

enum
{
	PRIM_RELIEF_LEN								= 1260, // VECTOR   - Relief Size [>=0.0]
	PRIM_RELIEF_SUBW							= 1261, // LONG     - Width Segments [>0]
	PRIM_RELIEF_SUBH							= 1262, // LONG     - Height Segments [>0]
	PRIM_RELIEF_TEXTURE						= 1263, // STRING		- Texture Name
	PRIM_RELIEF_SPHERICAL					= 1264, // BOOL			- Generate Spherical Shape
	PRIM_RELIEF_BLEVEL						= 1265, // REAL     - Pbottom Level (Sea) [>=0.0; <=1.0]
	PRIM_RELIEF_TLEVEL						= 1266, // REAL     - Ptop Level (Plateau) [>=0.0; <=1.0]
	PRIM_RELIEF_USE_NEW_VERSION		= 1267,	// BOOL			- Use new elevation behavior if true (R21). In the BaseContainer but not in the UI.
	PRIM_RELIEF_SWITCH_TO_UPDATED	= 1268	// BUTTON		- To switch from legacy to new behavior.
};

#endif // ORELIEF_H__
