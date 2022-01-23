#ifndef TMORPHCAM_H__
#define TMORPHCAM_H__

enum
{
	TMORPHCAM_LIST									= 100001,		// INEXCLUDE
	TMORPHCAM_LIST_LINKS						= 100002,		// GROUP
	TMORPHCAM_BLEND									= 100003,		// REAL
	TMORPHCAM_STEADY								= 100004,		// BOOL
	TMORPHCAM_INFOTEXT							= 100005,		// STATICTEXT
	TMORPHCAM_INTERPOLATION					= 100006,		// LONG CYCLE
		TMORPHCAM_INTERPOLATION_LINEAR		= 0,			// CYCLE OPTION
		TMORPHCAM_INTERPOLATION_CUBIC			= 1,			// CYCLE OPTION
		TMORPHCAM_INTERPOLATION_AKIMA			= 2,			// CYCLE OPTION
	TMORPHCAM_BLEND_CURVE						= 100007,		// SPLINE
	TMORPHCAM_LIST_MODE							= 100008,		// LONG CYCLE
		TMORPHCAM_LIST_MODE_SIMPLE				= 1,			// CYCLE OPTION
		TMORPHCAM_LIST_MODE_MULTI					= 2,			// CYCLE OPTION
	TMORPHCAM_LIST_LINK_A						= 100009,		// LINK
	TMORPHCAM_LIST_LINK_B						= 100010,		// LINK
	TMORPHCAM_STEADY_LINK						= 100011,		// LINK

	TMORPHCAM_VISUALIZATION					= 100100,		// GROUP
	TMORPHCAM_VISUALIZATION_POS			= 100101,		// BOOL
	TMORPHCAM_VISUALIZATION_ALIGN		= 100102,		// BOOL
	TMORPHCAM_VISUALIZATION_NAMES		= 100103,		// BOOL
	TMORPHCAM_VISUALIZATION_CAM_ENABLED	= 100104,	// BOOL
	TMORPHCAM_VISUALIZATION_CAM_COLOR		= 100105,	// VECTOR

	TMORPHCAM_TRACK									= 100200,		// GROUP
	TMORPHCAM_TRACK_FOCALLENGTH			= 100201,		// BOOL
	TMORPHCAM_TRACK_APERTURE				= 100202,		// BOOL
	TMORPHCAM_TRACK_TARGETDIST			= 100203,		// BOOL
	TMORPHCAM_TRACK_DOF							= 100204,		// BOOL
	TMORPHCAM_TRACK_WB							= 100205,		// BOOL
	TMORPHCAM_TRACK_PHY_FNUMBER			= 100206,		// BOOL
	TMORPHCAM_TRACK_PHY_ISOGAIN			= 100207,		// BOOL
	TMORPHCAM_TRACK_PHY_SHUTTER			= 100208,		// BOOL
	TMORPHCAM_TRACK_PHY_LENSDIST		= 100209,		// BOOL
	TMORPHCAM_TRACK_PHY_VIGNETTE		= 100210,		// BOOL
	TMORPHCAM_TRACK_PHY_ABERRATION	= 100211,		// BOOL
	TMORPHCAM_TRACK_PHY							= 100212,		// SEPARATOR
	TMORPHCAM_TRACK_STEREO					= 100213		// BOOL
};

#endif // TMORPHCAM_H__