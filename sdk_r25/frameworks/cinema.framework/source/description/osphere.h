#ifndef OSPHERE_H__
#define OSPHERE_H__

enum
{
	PRIM_SPHERE_RAD								= 1110, // REAL     - Radius [>=0.0]
	PRIM_SPHERE_SUB								= 1111, // LONG     - Subdivision [>0]
	PRIM_SPHERE_TYPE							= 1112, // LONG     - Type [0:Standard; 1:Tetra; 2:Hexa; 3:Octa; 4:Icosa]
		PRIM_SPHERE_TYPE_STANDARD			= 0,
		PRIM_SPHERE_TYPE_TETRA				= 1,
		PRIM_SPHERE_TYPE_HEXA					= 2,
		PRIM_SPHERE_TYPE_OCTA					= 3,
		PRIM_SPHERE_TYPE_ICOSA				= 4,
		PRIM_SPHERE_TYPE_HEMISPHERE		= 5,
	PRIM_SPHERE_PERFECT						= 1113, // BOOL		 - Keep Perfect Shape During Rendering
	PRIM_SPHERE_USE_NEW_VERSION		= 1114,	// BOOL	- Use new non-overlapping UV maps if true (R20). In the BaseContainer but not in the UI.
	PRIM_SPHERE_SWITCH_TO_UPDATED = 1115	// BUTTON - To switch from legacy UV maps to the new non-overlapping ones.
};

#endif // OSPHERE_H__
