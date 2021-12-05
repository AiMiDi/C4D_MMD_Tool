#ifndef FLMOGRAPH_H__
#define FLMOGRAPH_H__

enum
{
		// Falloff controls
	
	FIELDLAYERMOGRAPH_LINK										= 1000,					// BASELINK
	FIELDLAYERMOGRAPH_MODE										=	1001,					// Int Cycle
		FIELDLAYERMOGRAPH_MODE_INDEX							= 0,					// By index
		FIELDLAYERMOGRAPH_MODE_NEAREST						= 1,					// Closest element
		FIELDLAYERMOGRAPH_MODE_PROXIMITYMAX 			= 2,					// Blended (max)
		FIELDLAYERMOGRAPH_MODE_PROXIMITYMIN 			= 3,					// Blended (min)
		FIELDLAYERMOGRAPH_MODE_PROXIMITY					= 4,					// Blended (average)
		FIELDLAYERMOGRAPH_MODE_PROXIMITYLUMMAX	 	= 5,					// Max based on luminance
		FIELDLAYERMOGRAPH_MODE_PROXIMITYLUMMIN 		= 6,					// Min based on luminance
		FIELDLAYERMOGRAPH_MODE_PROXIMITYDISTMIN		= 7,					// Blended (average with distance)
	FIELDLAYERMOGRAPH_RADIUS 									= 1002,					// Float
	FIELDLAYERMOGRAPH_SUBINDEX								= 1003,					// Int
	FIELDLAYERMOGRAPH_CONSTANTUPDATE					= 1004,					// Bool
	FIELDLAYERMOGRAPH_DISTANCEFALLOFF					= 1005					// Bool
};
#endif // FLMOGRAPH_H__
