#ifndef OOILTANK_H__
#define OOILTANK_H__

enum
{
	PRIM_OILTANK_RADIUS				     = 5100, // REAL
	PRIM_OILTANK_CAPHEIGHT		     = 5101, // REAL
	PRIM_OILTANK_HEIGHT				     = 5102, // ==PRIM_CONE_HEIGHT
	PRIM_OILTANK_HSUB					     = 5103, // ==PRIM_CONE_HSUB
	PRIM_OILTANK_FSUB					     = 5104, // ==PRIM_CONE_FSUB
	PRIM_OILTANK_SEG					     = 5105, // ==PRIM_CONE_SEG
	PRIM_OILTANK_USE_NEW_VERSION   = 5106, // BOOL   - Use migrated generator if true (R20). In the BaseContainer but not in the UI.
	PRIM_OILTANK_SWITCH_TO_UPDATED = 5107  // BUTTON - To switch from legacy to migrated generator.
};

#endif // OOILTANK_H__
