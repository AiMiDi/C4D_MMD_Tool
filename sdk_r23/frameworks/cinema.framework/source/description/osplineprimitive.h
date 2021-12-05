#ifndef OSPLINEPRIMITIVE_H__
#define OSPLINEPRIMITIVE_H__

enum
{
	PRIM_PLANE																= 2300,	// LONG	- Direction [0:XY; 1:ZY; 2:XZ]
		PRIM_PLANE_XY														= 0,
		PRIM_PLANE_ZY														= 1,
		PRIM_PLANE_XZ														= 2,
	PRIM_REVERSE															= 2301  // BOOL - Reverse Spline Order
};

#endif // OSPLINEPRIMITIVE_H__
