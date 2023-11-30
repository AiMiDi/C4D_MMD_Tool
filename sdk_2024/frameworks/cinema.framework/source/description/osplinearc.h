#ifndef OSPLINEARC_H__
#define OSPLINEARC_H__

enum
{
	PRIM_ARC_TYPE							= 2000,	// LONG - Arc Type [0:Arc; 1:Sector; 2:Segment; 3:Ring]
		PRIM_ARC_TYPE_ARC					= 0,
		PRIM_ARC_TYPE_SECTOR			= 1,
		PRIM_ARC_TYPE_SEGMENT			= 2,
		PRIM_ARC_TYPE_RING				= 3,
	PRIM_ARC_RADIUS						= 2001, // REAL - Radius [>=0.0]
	PRIM_ARC_INNER						= 2002, // REAL - Inner Radius (Ring) [>=0.0]
	PRIM_ARC_START						= 2005, // REAL - Start Angle
	PRIM_ARC_END							= 2006  // REAL - End Angle
};

#endif // OSPLINEARC_H__
