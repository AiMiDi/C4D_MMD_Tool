#ifndef OSPLINE4SIDE_H__
#define OSPLINE4SIDE_H__

enum
{
	PRIM_4SIDE_TYPE						= 2120,	// LONG - Type [0:Diamond; 1:Kite; 2:Parallelogram; 3:Trapezium]
		PRIM_4SIDE_TYPE_DIAMOND				= 0,
		PRIM_4SIDE_TYPE_KITE					= 1,
		PRIM_4SIDE_TYPE_PARALLELOGRAM	= 2,
		PRIM_4SIDE_TYPE_TRAPEZIUM			= 3,
	PRIM_4SIDE_A							= 2121,	// REAL - a [>=0.0]
	PRIM_4SIDE_B							= 2122,	// REAL - b [>=0.0]
	PRIM_4SIDE_ANGLE					= 2123	// REAL - Angle [>-DegToRad(90.0); <DegToRad(90.0)]
};

#endif // OSPLINE4SIDE_H__
