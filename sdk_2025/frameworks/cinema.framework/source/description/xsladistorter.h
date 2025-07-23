#ifndef XSLADISTORTER_H__
#define XSLADISTORTER_H__

enum
{
	XSLADistorter                         = 1000,

	SLA_DISTORTER_TYPE                    = 1001, // long
		SLA_DISTORTER_TYPE_DIRECTIONAL      = 2001,
		SLA_DISTORTER_TYPE_BIDIRECTIONAL    = 2002,
		SLA_DISTORTER_TYPE_FLOW_FIELD       = 2003,
	SLA_DISTORTER_WRAP                    = 1010, // long
		SLA_DISTORTER_WRAP_NONE             = 2010,
		SLA_DISTORTER_WRAP_CYCLE            = 2011,
		SLA_DISTORTER_WRAP_CLAMP            = 2012,
		SLA_DISTORTER_WRAP_SEAMLESS         = 2013,
	SLA_DISTORTER_AMOUNT                  = 1002, // real
	SLA_DISTORTER_X                       = 1003, // real
	SLA_DISTORTER_Y                       = 1004, // real
	SLA_DISTORTER_Z                       = 1005, // real
	SLA_DISTORTER_DELTA                   = 1006, // real
	SLA_DISTORTER_STEP                    = 1007, // real
	SLA_DISTORTER_TEXTURE                 = 1008, // texture group
	SLA_DISTORTER_DISTORTER               = 1009, // texture group

	SLA_DISTORTER_DUMMY_
};

#endif // XSLADISTORTER_H__
