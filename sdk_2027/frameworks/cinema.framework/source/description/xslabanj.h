#ifndef XSLABANJ_H__
#define XSLABANJ_H__

enum
{
	XSLABanj                              = 1000,

	SLA_BANJ_COLOR                        = 1001, // vector

	SLA_BANJ_ALGORITHM                    = 1002, // long
		SLA_BANJ_ALGORITHM_INTERNAL         = 2001,
		SLA_BANJ_ALGORITHM_OREN_NAYAR       = 2002,
		SLA_BANJ_ALGORITHM_SIMPLE						= 2003,
	SLA_BANJ_ILLIMINATION                 = 1003, // real
	SLA_BANJ_ROUGHNESS                    = 1004, // real
	SLA_BANJ_SHADOW_INTENSITY             = 1005, // real
	SLA_BANJ_CONTRAST                     = 1006, // real
	SLA_BANJ_CLIP                         = 1007  // bool
};

#endif // XSLABANJ_H__
