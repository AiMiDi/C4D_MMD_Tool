#ifndef OPLATONIC_H__
#define OPLATONIC_H__

enum
{
	PRIM_PLATONIC_RAD					= 1120, // REAL	   - Outer Radius	[>=0.0]
	PRIM_PLATONIC_SUB					= 1121, // LONG     - Subdivision [>=0]
	PRIM_PLATONIC_TYPE				= 1122,	// LONG     - Type [0:Tetra; 1:Hexa; 2:Octa; 3:Dodeca; 4:Icosa; 5:Bucky]
		PRIM_PLATONIC_TYPE_TETRA		= 0,
		PRIM_PLATONIC_TYPE_HEXA			= 1,
		PRIM_PLATONIC_TYPE_OCTA			= 2,
		PRIM_PLATONIC_TYPE_DODECA		= 3,
		PRIM_PLATONIC_TYPE_ICOSA		= 4,
		PRIM_PLATONIC_TYPE_BUCKY		= 5,
	PRIM_PLATONIC_USE_NEW_VERSION = 1123,	// BOOL	- Use new non-overlapping UV maps if true (R20). In the BaseContainer but not in the UI.
	PRIM_PLATONIC_SWITCH_TO_UPDATED = 1124 // BUTTON - To switch from legacy UV maps to the new non-overlapping ones.
};

#endif // OPLATONIC_H__
