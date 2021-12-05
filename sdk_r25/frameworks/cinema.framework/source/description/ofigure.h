#ifndef OFIGURE_H__
#define OFIGURE_H__

enum
{
	PRIM_FIGURE_HEIGHT									= 1210, // REAL     - Height [>=0.0]
	PRIM_FIGURE_SUB											= 1211, // LONG     - Subdivision [>2]
	PRIM_FIGURE_LEGACY_AXIS_MODE				= 1212,	// BOOL			- R18 Legacy Axis. true: legacy axis (at figure center), false: R18 axis (at figure feet)
	PRIM_FIGURE_PHONG										= 1213,
	PRIM_FIGURE_PHONG_ANGLELIMIT				= 1214,
	PRIM_FIGURE_PHONG_ANGLE							= 1215,
	PRIM_FIGURE_PHONG_USEEDGES					= 1216,
	PRIM_FIGURE_USE_NEW_VERSION					= 1217, // BOOL   - Use migrated generator if true (R20). In the BaseContainer but not in the UI.
	PRIM_FIGURE_SWITCH_TO_UPDATED				= 1218  // BUTTON - To switch from legacy to migrated generator.
};

#endif // OFIGURE_H__
