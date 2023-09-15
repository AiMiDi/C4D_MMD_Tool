#ifndef OSPLINEFORMULA_H__
#define OSPLINEFORMULA_H__

enum
{
	PRIM_FORMULA_X						= 2100,	// STRING - X component
	PRIM_FORMULA_Y						= 2101,	// STRING - Y component
	PRIM_FORMULA_Z						= 2102,	// STRING - Z component
	PRIM_FORMULA_TMIN					= 2103,	// REAL - Start Value
	PRIM_FORMULA_TMAX					= 2104,	// REAL - End Value
	PRIM_FORMULA_SAMPLES			= 2105,	// LONG - Samples [>=2]
	PRIM_FORMULA_CUBIC				= 2106	// BOOL - Cubic Extrapolation
};

#endif // OSPLINEFORMULA_H__
