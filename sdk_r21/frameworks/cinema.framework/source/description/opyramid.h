#ifndef OPYRAMID_H__
#define OPYRAMID_H__

enum
{
	PRIM_PYRAMID_LEN					= 1220, // VECTOR   - Pyramid Size [>=0.0]
	PRIM_PYRAMID_SUB					= 1221, // LONG     - Segments [>0]
	PRIM_PYRAMID_USE_NEW_VERSION = 1222,	// BOOL	- Use new non-overlapping UV maps if true (R20). In the BaseContainer but not in the UI.
	PRIM_PYRAMID_SWITCH_TO_UPDATED = 1223 // BUTTON - To switch from legacy UV maps to the new non-overlapping ones.
};

#endif // OPYRAMID_H__
