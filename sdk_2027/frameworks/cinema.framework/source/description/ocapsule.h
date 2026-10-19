#ifndef OCAPSULE_H__
#define OCAPSULE_H__

enum
{
	PRIM_CAPSULE_RADIUS				     = 5200, // REAL
	PRIM_CAPSULE_HEIGHT				     = 5201, // ==PRIM_CONE_HEIGHT
	PRIM_CAPSULE_HSUB					     = 5202, // ==PRIM_CONE_HSUB
	PRIM_CAPSULE_FSUB					     = 5203, // ==PRIM_CONE_FSUB
	PRIM_CAPSULE_SEG					     = 5204, // ==PRIM_CONE_SEG
	PRIM_CAPSULE_USE_NEW_VERSION   = 5205, // BOOL   - Use migrated generator if true (R20). In the BaseContainer but not in the UI.
	PRIM_CAPSULE_SWITCH_TO_UPDATED = 5206  // BUTTON - To switch from legacy to migrated generator.
};

#endif // OCAPSULE_H__
