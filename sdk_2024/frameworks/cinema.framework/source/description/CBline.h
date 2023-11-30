#ifndef CBLINE_H__
#define CBLINE_H__

enum
{
	LINECURVE_TYPE							= 1101,
		LINECURVE_BOUNDED				= 0,
		LINECURVE_SEMIBOUNDED			= 1,
		LINECURVE_UNBOUNDED				= 2,

	LINECURVE_P1							= 1102,
	LINECURVE_P2							= 1103,

	LINECURVE_LIMIT                         = 1104
};

#endif // CBLINE_H__
