#ifndef XSLAFILTER_H__
#define XSLAFILTER_H__

enum
{
	XSLAFilter                            = 1000,

	SLA_FILTER_TEXTURE                    = 1001, // texture group
	SLA_FILTER_HUE                        = 1002, // real
	SLA_FILTER_SATURATION                 = 1003, // real
	SLA_FILTER_LIGHTNESS                  = 1004, // real
	SLA_FILTER_COLORIZE                   = 1005, // bool
	SLA_FILTER_BRIGHNESS                  = 1006, // real
	SLA_FILTER_CONTRAST                   = 1007, // real
	SLA_FILTER_LOW_CLIP                   = 1008, // real
	SLA_FILTER_HIGH_CLIP                  = 1009, // real
	SLA_FILTER_CLIPPING                   = 1010, // bool
	SLA_FILTER_GAMMA                      = 1011, // real

	SLA_FILTER_GRADING										= 10000,	// Group
	SLA_FILTER_GRADING_INTENSITY					= 10001,	// Real
	SLA_FILTER_GRADING_CURVE_RGB					= 10002,	// Spline
	SLA_FILTER_GRADING_CURVE_R						= 10003,	// Spline
	SLA_FILTER_GRADING_CURVE_G						= 10004,	// Spline
	SLA_FILTER_GRADING_CURVE_B						= 10005,	// Spline
	SLA_FILTER_GRADING_ENABLED						= 10006,	// Bool

	SLA_FILTER_DUMMY_
};

#endif // XSLAFILTER_H__
