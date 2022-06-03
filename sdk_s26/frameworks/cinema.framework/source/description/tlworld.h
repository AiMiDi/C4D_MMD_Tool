#ifndef TLWORLD_H__
#define TLWORLD_H__

enum
{
	TLWORLD_OVERDUB		= 1000,
	TLWORLD_LOCKV			= 1001,
	TLWORLD_LOCKT			= 1002,
	TLWORLD_LOCKTA		= 1003,
	TLWORLD_LOCKTL		= 1004,
	TLWORLD_AUTO			= 1005,
	TLWORLD_CLAMP = 1006,
	TLWORLD_BREAK			= 1007,
	TLWORLD_KEEPVISUALANGLE			= 1008,
	TLWORLD_INTER			= 1009,
	TLWORLD_INTER_SP = 1,
	TLWORLD_INTER_LI = 2,
	TLWORLD_INTER_ST = 3,
	TLWORLD_AUTOTYPE = 1010,
	TLWORLD_AUTOTYPE_CLASSIC = 1,
	TLWORLD_AUTOTYPE_FIXEDSLOPE = 2,
	TLWORLD_WEIGHTEDTANGENT = 1011,
	TLWORLD_REMOVEOVERSHOOT = 1012,
	TLWORLD_AUTOWEIGHT = 1013,
	TLWORLD_QUATINTER = 1014,
		TLWORLD_QUATINTER_SPLINE = 1,
		TLWORLD_QUATINTER_LINEAR = 2,
		TLWORLD_QUATINTER_SMOOTH = 3,
	TLWORLD_BREAKDOWNCOLOR = 1015,
	TLWORLD_BREAKDOWN = 1016,
	TLWORLD_PRESET = 1017,
		TLWORLD_PRESET_AUTO_CLAMP = 1,
		TLWORLD_PRESET_AUTO_OVERSHOOT = 2,
		TLWORLD_PRESET_FIXED_OVERSHOOTWEIGHTED = 3,
		TLWORLD_PRESET_CUSTOM = 4,
		TLWORLD_PRESET_AUTO_OVERSHOOTWEIGHTED = 5,
		TLWORLD_TRACKEVALMODE = 1018,
	TLWORLD_GROUP = 2000,
};

#endif // TLWORLD_H__
