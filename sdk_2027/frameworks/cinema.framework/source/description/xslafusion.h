#ifndef XSLAFUSION_H__
#define XSLAFUSION_H__

enum
{
	XSLAFusion                            = 1000,

	SLA_FUSION_MODE                       = 1001, // long
		SLA_FUSION_MODE_NORMAL              = 2001,
		SLA_FUSION_MODE_SEP_1               = 3001,
		SLA_FUSION_MODE_MULTIPLY            = 2019,
		SLA_FUSION_MODE_SCREEN              = 2002,
		SLA_FUSION_MODE_OVERLAY             = 2003,
		SLA_FUSION_MODE_HARD_LIGHT          = 2004,
		SLA_FUSION_MODE_SOFT_LIGHT          = 2005,
		SLA_FUSION_MODE_SEP_2               = 3002,
		SLA_FUSION_MODE_DODGE               = 2006,
		SLA_FUSION_MODE_BURN                = 2007,
		SLA_FUSION_MODE_SEP_3               = 3003,
		SLA_FUSION_MODE_DARKEN              = 2008,
		SLA_FUSION_MODE_LIGHTEN             = 2009,
		SLA_FUSION_MODE_ADD                 = 2010,
		SLA_FUSION_MODE_SUBTRACT            = 2011,
		SLA_FUSION_MODE_DIFFERENCE          = 2012,
		SLA_FUSION_MODE_EXCLUSION           = 2013,
		SLA_FUSION_MODE_SEP_4               = 3004,
		SLA_FUSION_MODE_HUE                 = 2014,
		SLA_FUSION_MODE_SAT                 = 2015,
		SLA_FUSION_MODE_COLOR               = 2016,
		SLA_FUSION_MODE_LUMINANCE           = 2017,
		SLA_FUSION_MODE_SEP_5               = 3005,
		SLA_FUSION_MODE_LEVR                = 2018,

	SLA_FUSION_BLEND                      = 1002, // real
	SLA_FUSION_USE_MASK                   = 1003, // bool
	SLA_FUSION_INVERT_MASK                = 1004, // bool
	SLA_FUSION_INVERT_OUTPUT              = 1005, // bool
	SLA_FUSION_BLEND_CHANNEL              = 1006, // texure group
	SLA_FUSION_MASK_CHANNEL               = 1007, // texure group
	SLA_FUSION_BASE_CHANNEL               = 1008, // texure group

	SLA_FUSION_DUMMY_
};

#endif // XSLAFUSION_H__
