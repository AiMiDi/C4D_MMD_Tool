#ifndef FDELAY_H__
#define FDELAY_H__

enum
{
	// Falloff controls
	DELAY_MODE				=	1000,	// Int Cycle
	DELAY_MODE_LINEAR	= 0,
	DELAY_MODE_SMOOTH	= 1,
	DELAY_MODE_SPRING	= 2,
	DELAY_SPEED				= 1001,	// Float
	DELAY_USEFIELDS		= 1002,	// Bool
	DELAY_SPEEDFIELDS	= 1003	// Fieldlist
};
#endif											// FDELAY_H__
