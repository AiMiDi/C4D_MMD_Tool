#ifndef OSPLINECIRCLE_H__
#define OSPLINECIRCLE_H__

enum
{
	PRIM_CIRCLE_ELLIPSE				= 2010,	// BOOL - Ellipse Shape
	PRIM_CIRCLE_RING					= 2011, // BOOL - Ring Shape
	PRIM_CIRCLE_RADIUS				= 2012, // REAL - Radius [>=0.0]
	PRIM_CIRCLE_RADIUSY				= 2013, // REAL - Y Radius [>=0.0]
	PRIM_CIRCLE_INNER					= 2014  // REAL - Inner Radius (Ring) [>=0.0]
};

#endif // OSPLINECIRCLE_H__
