#ifndef OSPLINEPROFILE_H__
#define OSPLINEPROFILE_H__

enum
{
	PRIM_PROFILE_TYPE				= 2050,  // LONG - Type [0:H; 1:L; 2:T; 3:U; 4:Z]
		PRIM_PROFILE_TYPE_H		= 0,
		PRIM_PROFILE_TYPE_L		= 1,
		PRIM_PROFILE_TYPE_T		= 2,
		PRIM_PROFILE_TYPE_U		= 3,
		PRIM_PROFILE_TYPE_Z		= 4,
	PRIM_PROFILE_A							= 2051,  // REAL - A [>=0.0]
	PRIM_PROFILE_B							= 2052,  // REAL - B [>=0.0]
	PRIM_PROFILE_S						  = 2053,  // REAL - S [>=0.0]
	PRIM_PROFILE_T    					= 2054  // REAL - T [>=0.0]
};

#endif // OSPLINEPROFILE_H__
