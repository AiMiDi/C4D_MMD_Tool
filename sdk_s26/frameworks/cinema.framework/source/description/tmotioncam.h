#ifndef TMOTIONCAM_H__
#define TMOTIONCAM_H__

enum
{
	TMOTIONCAM_RIG_HEIGHT									= 100101,		// REAL
	TMOTIONCAM_RIG_PARALLAX								= 100102,		// VECTOR

	TMOTIONCAM_AUTOBANKING								= 100150,		// SEPARATOR
	TMOTIONCAM_AUTOBANKING_ENABLED				= 100151,		// BOOL
	TMOTIONCAM_AUTOBANKING_INTENSITY			= 100152,		// REAL
	TMOTIONCAM_AUTOBANKING_DAMPEN					= 100153,		// REAL

	TMOTIONCAM_TARGET											= 100200,		// GROUP
	TMOTIONCAM_TARGET_ENABLED							= 100201,		// BOOL
	TMOTIONCAM_TARGET_A1									= 100202,		// LINK
	TMOTIONCAM_TARGET_A2									= 100203,		// LINK
	TMOTIONCAM_TARGET_B1									= 100204,		// LINK
	TMOTIONCAM_TARGET_B2									= 100205,		// LINK
	TMOTIONCAM_TARGET_BLEND_A							= 100206,		// REAL
	TMOTIONCAM_TARGET_BLEND_B							= 100207,		// REAL
	TMOTIONCAM_TARGET_BLEND_AB						= 100208,		// REAL
	TMOTIONCAM_TARGET_INTENSITY						= 100209,		// REAL
	TMOTIONCAM_TARGET_UPVECTOR						= 100210,		// LINK
	TMOTIONCAM_TARGET_BLEND_A_SPLINE			= 100211,		// SPLINE
	TMOTIONCAM_TARGET_BLEND_B_SPLINE			= 100212,		// SPLINE
	TMOTIONCAM_TARGET_BLEND_AB_SPLINE			= 100213,		// SPLINE
	TMOTIONCAM_TARGET_INTENSITY_SPLINE		= 100214,		// SPLINE
	TMOTIONCAM_TARGET_SPLINE_A1_POS				= 101211,		// REAL
	TMOTIONCAM_TARGET_SPLINE_A2_POS				= 101221,		// REAL
	TMOTIONCAM_TARGET_SPLINE_B1_POS				= 101231,		// REAL
	TMOTIONCAM_TARGET_SPLINE_B2_POS				= 101241,		// REAL
	TMOTIONCAM_TARGET_SPLINE_UPVECTOR_POS	= 101251,		// REAL
	TMOTIONCAM_TARGET_COMPENSATE_PARALLAX	= 101252,		// BOOL

	TMOTIONCAM_SPLINE											= 100300,		// GROUP
	TMOTIONCAM_SPLINE_ENABLED							= 100301,		// BOOL
	TMOTIONCAM_SPLINE_A										= 100302,		// LINK
	TMOTIONCAM_SPLINE_B										= 100303,		// LINK
	TMOTIONCAM_SPLINE_A_RAIL							= 100304,		// LINK
	TMOTIONCAM_SPLINE_B_RAIL							= 100305,		// LINK
	TMOTIONCAM_SPLINE_POS_A								= 100306,		// REAL
	TMOTIONCAM_SPLINE_POS_B								= 100307,		// REAL
	TMOTIONCAM_SPLINE_POS_BLEND						= 100308,		// REAL
	TMOTIONCAM_SPLINE_TANGENTIAL					= 100309,		// BOOL
	TMOTIONCAM_SPLINE_POS_A_SPLINE				= 100310,		// SPLINE
	TMOTIONCAM_SPLINE_POS_B_SPLINE				= 100311,		// SPLINE
	TMOTIONCAM_SPLINE_POS_BLEND_SPLINE		= 100312,		// SPLINE
	TMOTIONCAM_SPLINE_INTENSITY						= 100322,		// REAL

	TMOTIONCAM_SPLINE_AUTO_A_ENABLED			= 100313,		// BOOL
	TMOTIONCAM_SPLINE_AUTO_A_START				= 100314,		// BASETIME
	TMOTIONCAM_SPLINE_AUTO_A_END					= 100315,		// BASETIME
	TMOTIONCAM_SPLINE_AUTO_B_ENABLED			= 100316,		// BOOL
	TMOTIONCAM_SPLINE_AUTO_B_START				= 100317,		// BASETIME
	TMOTIONCAM_SPLINE_AUTO_B_END					= 100318,		// BASETIME
	TMOTIONCAM_SPLINE_AUTO_BLEND_ENABLED	= 100319,		// BOOL
	TMOTIONCAM_SPLINE_AUTO_BLEND_START		= 100320,		// BASETIME
	TMOTIONCAM_SPLINE_AUTO_BLEND_END			= 100321,		// BASETIME

	TMOTIONCAM_ROT_MANUAL									= 100400,		// SEPARATOR
	TMOTIONCAM_ROT_MANUAL_HEAD						= 100401,		// VECTOR
	TMOTIONCAM_ROT_MANUAL_CAM							= 100402,		// VECTOR

	TMOTIONCAM_FOOT_DYN										= 100500,		// SEPARATOR
	TMOTIONCAM_FOOT_DYN_ENABLED						= 100501,		// BOOL
	TMOTIONCAM_FOOT_DYN_DAMP_POS					= 100502,		// REAL
	TMOTIONCAM_FOOT_DYN_DAMP_ROT					= 100503,		// REAL
	TMOTIONCAM_FOOT_DYN_INERTIA_POS				= 100504,		// REAL
	TMOTIONCAM_FOOT_DYN_INERTIA_ROT				= 100505,		// REAL
	TMOTIONCAM_FOOT_DYN_MODE							= 100506,		// LONG CYCLE
		TMOTIONCAM_DYN_MODE_DAMPEN						= 1,				// CYCLE VALUE
		TMOTIONCAM_DYN_MODE_SPRING						= 2,				// CYCLE VALUE

	TMOTIONCAM_HEAD_DYN										= 100510,		// SEPARATOR
	TMOTIONCAM_HEAD_DYN_ENABLED						= 100511,		// BOOL
	TMOTIONCAM_HEAD_DYN_DAMP_POS					= 100512,		// REAL
	TMOTIONCAM_HEAD_DYN_DAMP_ROT					= 100513,		// REAL
	TMOTIONCAM_HEAD_DYN_INERTIA_POS				= 100514,		// REAL
	TMOTIONCAM_HEAD_DYN_INERTIA_ROT				= 100515,		// REAL
	TMOTIONCAM_HEAD_DYN_MODE							= 100516,		// LONG CYCLE

	TMOTIONCAM_FOCUS_DYN									= 100520,		// SEPARATOR
	TMOTIONCAM_FOCUS_DYN_ENABLED					= 100521,		// BOOL
	TMOTIONCAM_FOCUS_DYN_MODE							= 100522,		// LONG CYCLE
	TMOTIONCAM_FOCUS_DYN_DAMP							= 100523,		// REAL
	TMOTIONCAM_FOCUS_DYN_INERTIA					= 100524,		// REAL

	TMOTIONCAM_CAM_DYN										= 100530,		// SEPARATOR
	TMOTIONCAM_CAM_DYN_ENABLED						= 100531,		// BOOL
	TMOTIONCAM_CAM_DYN_DAMP_POS						= 100532,		// REAL
	TMOTIONCAM_CAM_DYN_DAMP_ROT						= 100533,		// REAL
	TMOTIONCAM_CAM_DYN_INERTIA_POS				= 100534,		// REAL
	TMOTIONCAM_CAM_DYN_INERTIA_ROT				= 100535,		// REAL
	TMOTIONCAM_CAM_DYN_MODE								= 100536,		// LONG CYCLE

	TMOTIONCAM_VIS												= 100600,		// GROUP
	TMOTIONCAM_VIS_CAM										= 100601,		// SEPARATOR
	TMOTIONCAM_VIS_CAM_ENABLED						= 100602,		// BOOL
	TMOTIONCAM_VIS_CAM_COL								= 100603,		// COLOR
	TMOTIONCAM_VIS_RIG										= 100610,		// SEPARATOR
	TMOTIONCAM_VIS_RIG_ENABLED						= 100611,		// BOOL
	TMOTIONCAM_VIS_RIG_COL								= 100612,		// COLOR
	TMOTIONCAM_VIS_RIG_MODE								= 100613,		// LONG CYCLE
		TMOTIONCAM_VIS_RIG_MODE_SIMPLE				= 1,				// CYCLE VALUE
		TMOTIONCAM_VIS_RIG_MODE_FIGURE				= 2,				// CYCLE VALUE
	TMOTIONCAM_VIS_TARGET									= 100620,		// SEPARATOR
	TMOTIONCAM_VIS_TARGET_ENABLED					= 100621,		// BOOL
	TMOTIONCAM_VIS_TARGET_DRAWDISTTEXT		= 100622,		// BOOL
	TMOTIONCAM_VIS_TARGET_COLOR						= 100623,		// COLOR
	TMOTIONCAM_VIS_TARGET_RADIUS					= 100624,		// REAL
	TMOTIONCAM_VIS_TARGET_DRAWABERRATION	= 100625,		// BOOL
	TMOTIONCAM_VIS_TARGET_2D							= 100626,		// BOOL
	TMOTIONCAM_VIS_TARGET_DRAWSINGLETARGETS	= 100627,	// BOOL

	TMOTIONCAM_FOCUS											= 100700,		// GROUP
	TMOTIONCAM_FOCUS_ENABLED							= 100701,		// BOOL
	TMOTIONCAM_FOCUS_AUTO_ENABLED					= 100702,		// BOOL
	TMOTIONCAM_FOCUS_DISTANCE							= 100703,		// SEPARATOR
	TMOTIONCAM_FOCUS_DISTANCE_DIST				= 100704,		// REAL
	TMOTIONCAM_FOCUS_DISTANCE_OFFSET			= 100705,		// REAL
	TMOTIONCAM_FOCUS_FOCALLENGTH					= 100711,		// REAL
	TMOTIONCAM_FOCUS_APERTURE							= 100712,		// REAL

	TMOTIONCAM_FOCUS_DEPTH								= 100730,		// SEPARATOR
	TMOTIONCAM_FOCUS_DEPTH_ENABLED				= 100731,		// BOOL
	TMOTIONCAM_FOCUS_DEPTH_AREA						= 100732,		// REAL
	TMOTIONCAM_FOCUS_DEPTH_SOFT						= 100733,		// REAL
	TMOTIONCAM_FOCUS_DEPTH_MODE						= 100734,		// LONG CYCLE
		TMOTIONCAM_FOCUS_DEPTH_MODE_STANDARD	= 1,				// CYCLE VALUE
		TMOTIONCAM_FOCUS_DEPTH_MODE_FORPOST		= 2,				// CYCLE VALUE

	TMOTIONCAM_FOCUS_VERTIGO							= 100720,		// SEPARATOR
	TMOTIONCAM_FOCUS_VERTIGO_INTENSITY		= 100721,		// REAL

	TMOTIONCAM_NMOTION											= 100800,	// GROUP
	TMOTIONCAM_NMOTION_HEAD								= 100810,		// SEPARATOR
	TMOTIONCAM_NMOTION_HEAD_ROT_INTENSITY	= 100811,		// REAL
	TMOTIONCAM_NMOTION_HEAD_ROT_MAX				= 100812,		// VECTOR
	TMOTIONCAM_NMOTION_HEAD_ROT_FREQ				= 100813,	// VECTOR
	TMOTIONCAM_NMOTION_HEAD_ROT_OCT				= 100814,		// REAL
	TMOTIONCAM_NMOTION_HEAD_ROT_DESYNC			= 100815,	// REAL
	TMOTIONCAM_NMOTION_HEAD_ROT_OFFSET			= 100816,	// REAL

	TMOTIONCAM_NMOTION_CAM									= 100820,	// SEPARATOR
	TMOTIONCAM_NMOTION_CAM_ROT							= 100821,	// SEPARATOR
	TMOTIONCAM_NMOTION_CAM_ROT_INTENSITY		= 100822,	// REAL
	TMOTIONCAM_NMOTION_CAM_ROT_MAX					= 100823,	// VECTOR
	TMOTIONCAM_NMOTION_CAM_ROT_FREQ				= 100824,		// VECTOR
	TMOTIONCAM_NMOTION_CAM_ROT_OCT					= 100825,	// REAL
	TMOTIONCAM_NMOTION_CAM_ROT_DESYNC			= 100826,		// REAL
	TMOTIONCAM_NMOTION_CAM_ROT_OFFSET			= 100827,		// REAL

	TMOTIONCAM_NMOTION_CAM_POS							= 100831,	// SEPARATOR
	TMOTIONCAM_NMOTION_CAM_POS_INTENSITY		= 100832,	// REAL
	TMOTIONCAM_NMOTION_CAM_POS_MAX					= 100833,	// VECTOR
	TMOTIONCAM_NMOTION_CAM_POS_FREQ				= 100834,		// VECTOR
	TMOTIONCAM_NMOTION_CAM_POS_OCT					= 100835,	// REAL
	TMOTIONCAM_NMOTION_CAM_POS_DESYNC			= 100836,		// REAL
	TMOTIONCAM_NMOTION_CAM_POS_OFFSET			= 100837,		// REAL

	TMOTIONCAM_NMOTION_FOOT								= 100840,		// SEPARATOR
	TMOTIONCAM_NMOTION_FOOT_INTENSITY			= 100841,		// REAL
	TMOTIONCAM_NMOTION_FOOT_SCALE					= 100842,		// VECTOR
	TMOTIONCAM_NMOTION_FOOT_FREQ						= 100843,	// REAL

	TMOTIONCAM_NMOTION_PRESET							= 100880,		// LONG CYCLE
	TMOTIONCAM_NMOTION_PRESET_CUSTOM				= 100881,	// CYCLE VALUE
	TMOTIONCAM_NMOTION_PRESET_QUIET				= 100882,		// CYCLE VALUE
	TMOTIONCAM_NMOTION_PRESET_STEADYCAM_1	= 100883,		// CYCLE VALUE
	TMOTIONCAM_NMOTION_PRESET_STEADYCAM_2	= 100884,		// CYCLE VALUE
	TMOTIONCAM_NMOTION_PRESET_DOGMA				= 100885,		// CYCLE VALUE
	TMOTIONCAM_NMOTION_PRESET_EGO					= 100886,		// CYCLE VALUE

	TMOTIONCAM_BASE												= 100900,		// SEPARATOR
	TMOTIONCAM_FOLLOW_LINK								= 100901,		// LINK
	TMOTIONCAM_FOLLOW_MAXDISTANCE					= 100902,		// REAL
	TMOTIONCAM_BASE_LINK									= 100903,		// LINK
	TMOTIONCAM_FOLLOW											= 100904,		// SEPARATOR
	TMOTIONCAM_FOLLOW_MINDISTANCE					= 100905,		// REAL
	TMOTIONCAM_FOLLOW_ENABLED							= 100906,		// BOOL
	TMOTIONCAM_BASE_INHERITPARAMS					= 100907,		// BOOL
	TMOTIONCAM_BASE_OVERRIDE_RIGHEIGHT		= 100908,		// BOOL

	TMOTIONCAM_EXPORT											= 300000,		// GROUP
	TMOTIONCAM_EXPORT_TARGETPOS_LINK			= 300001,		// LINK
	TMOTIONCAM_EXPORT_TARGETPOS_VECTOR		= 300002,		// VECTOR
	TMOTIONCAM_EXPORT_FOOTPOS_LINK				= 300003,		// LINK
	TMOTIONCAM_EXPORT_FOOTPOS_VECTOR			= 300004,		// VECTOR
	TMOTIONCAM_EXPORT_HEADPOS_LINK				= 300005,		// LINK
	TMOTIONCAM_EXPORT_HEADPOS_VECTOR			= 300006,		// VECTOR
	TMOTIONCAM_EXPORT_SPEED								= 300007,		// REAL

	TMOTIONCAM_DYNAMICS										= 200000,		// GROUP
	TMOTIONCAM_RIG												= 200001,		// GROUP
	TMOTIONCAM_ANIMATION									= 200002		// GROUP
};

#endif // TMOTIONCAM_H__
