#ifndef OSPLINECYCLOID_H__
#define OSPLINECYCLOID_H__

enum
{
	PRIM_CYCLOID_TYPE					= 2040,  // LONG - Type [0:Cycloid; 1:Epicycloid; 2:Hypocycloid]
		PRIM_CYCLOID_TYPE_CYCLOID     = 0,
		PRIM_CYCLOID_TYPE_EPICYCLOID  = 1,
		PRIM_CYCLOID_TYPE_HYPOCYCLOID = 2,
	PRIM_CYCLOID_RADIUS				= 2041,  // REAL - Radius [>=0.0]
	PRIM_CYCLOID_R						= 2042,  // REAL - R [>=0.0]
	PRIM_CYCLOID_A						= 2043,  // REAL - A [>=0.0]
	PRIM_CYCLOID_START				= 2044,  // REAL - Start Angle
	PRIM_CYCLOID_END					= 2045  // REAL - End Angle
};

#endif // OSPLINECYCLOID_H__
