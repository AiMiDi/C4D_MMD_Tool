#ifndef CLOTHTAG_H__
#define CLOTHTAG_H__

enum
{

	CLOTH_BELT       = 10001, // link [just for compatibilty <V9.200]
	CLOTH_MASS       = 10002, // real
	CLOTH_DRAG       = 10005, // real
	CLOTH_GRAVITY    = 10006, // real
	CLOTH_STRUCT_F   = 10009, // real
	CLOTH_FLEXION_F  = 10010, // real
	CLOTH_TEAR_F     = 10011, // real

	CLOTH_SETMASS   = 11000, // button
	CLOTH_SETSEAMS  = 11001, // button
	CLOTH_SETINIT   = 11002, // button
	CLOTH_SETDINIT  = 11003, // button

	CLOTH_SHOWMASS  = 11004, // button
	CLOTH_SHOWSEAMS = 11005, // button
	CLOTH_SHOWINIT  = 11006, // button
	CLOTH_SHOWDINIT = 11007, // button

	CLOTH_BOUNCE    = 11010, // real
	CLOTH_STICKI    = 11011, // real
	CLOTH_SELF      = 11012, // bool

	CLOTH_SREP      = 11014, // bool
	CLOTH_SREP_D    = 11015, // real
	CLOTH_SREP_F    = 11016, // real
	CLOTH_SREP_B    = 11017, // real

	CLOTH_WIND_DIR    = 11020, // vector
	CLOTH_WIND_F      = 11021, // real
	CLOTH_WIND_TURB_F = 11022, // real
	CLOTH_WIND_TURB_S = 11023, // real
	CLOTH_WIND_DRAG   = 11024, // real
	CLOTH_WIND_IMPACT = 11025, // real
	CLOTH_WIND_LIFT   = 11026, // real
	CLOTH_WIND_SPEED  = 11027, // real

	CLOTH_SEAMS_DIST  = 11028, // real


	CLOTH_DRESSMODE      = 11031, // bool

	CLOTH_DO_DRESSING    = 11040, // button
	CLOTH_DRESS_STEPS    = 11041, // long
	CLOTH_SHRINK_F       = 11042, // real

	CLOTH_MASS_MAP       = 11043, // link
	CLOTH_STRUCT_F_MAP   = 11044, // link
	CLOTH_FLEXION_F_MAP  = 11045, // link
	CLOTH_SHRINK_F_MAP   = 11047, // link
	CLOTH_BOUNCE_MAP     = 11048, // link
	CLOTH_STICKI_MAP     = 11049, // link

	CLOTH_DO_RELAXING    = 11050, // button
	CLOTH_RELAX_STEPS    = 11051, // long

	CLOTH_SUBDIV     = 11052, // long
	CLOTH_START      = 11053, // basetime
	CLOTH_STOP       = 11054, // basetime
	CLOTH_AUTOTIME   = 11055, // bool

	CLOTH_P_EPS      = 11056, // real
	CLOTH_K_EPS      = 11057, // real
	CLOTH_V_EPS      = 11058, // real
	CLOTH_POINTS     = 11059, // bool
	CLOTH_EDGES      = 11060, // bool
	CLOTH_POLYS      = 11061, // bool
	CLOTH_GIA        = 11062, // bool


	CLOTH_BAKE       = 11065, // bool

	CLOTH_USE        = 11070, // bool
	CLOTH_INCLUDE    = 11071, // include list

	CLOTH_BELT_F_MAP = 11072, // link [just for compatibilty <V9.200]
	CLOTH_BELT_S_MAP = 11073, // link [just for compatibilty <V9.200]

	CLOTH_TEAR       = 11074, // bool
	CLOTH_DRAWMASS   = 11075, // bool
	CLOTH_RUBBER_F   = 11077, // real
	CLOTH_RUBBER_F_MAP = 11078, // link

	CLOTH_TEAR_F_MAP  = 11080, // link
	CLOTH_CACHE_OFF   = 11081, // basetime [deprecated]
	CLOTH_ITERATIONS  = 11082, // long
	CLOTH_CACHE_START = 11083, // basetime [replacing CLOTH_CACHE_OFF]

	// GUI
	CLOTH_GROUP_MAIN      = 12000,
	CLOTH_GROUP_FORCES    = 12001,
	CLOTH_GROUP_EFFECTS   = 12002,
	CLOTH_GROUP_DRESSING  = 12003,
	CLOTH_GROUP_EXPERT    = 12004,

	CLOTH_DO_CALCULATE    = 12005, // button
	CLOTH_DELCACHE        = 12006, // button
	CLOTH_CACHE_INFO1     = 12007, // button
	CLOTH_CACHE_INFO2     = 12008, // button
	CLOTH_CACHE_FRAME     = 12009, // button

	CLOTH_TEXT_INIT  = 12012,
	CLOTH_TEXT_DRESS = 12013,
	CLOTH_TEXT_FIX   = 12014,
	CLOTH_TEXT_SEAM  = 12015,

	CLOTH_CLEARDRESS = 12016,
	CLOTH_CLEARMASS  = 12017,
	CLOTH_CLEARSEAM  = 12018,
	CLOTH_CLEARINIT  = 12019,

	CLOTH_TEXT_LIMIT = 12020,

	CLOTH_CACHE_LOAD = 12021,
	CLOTH_CACHE_SAVE = 12022,

	CLOTH_SIMULATION_PRIORITY = 13002,

	// START OF PBD CLOTH INTEGRATION
	CLOTH_LEGACY_SETTINGS_GROUP = 19998,
	CLOTH_PBD_SETTINGS_GROUP = 19999,

	CLOTH_PBD_BENDINESS = 20001,
	CLOTH_PBD_STRETCHINESS = 20002,
	CLOTH_PBD_FRICTION = 20003,
	CLOTH_PBD_THICKNESS = 20004,
	CLOTH_PBD_MASS = 20005,
	CLOTH_PBD_TEARING = 20006,
	CLOTH_PBD_TEARPAST = 20007,
	CLOTH_PBD_BALLOON = 20008,
	CLOTH_PBD_OVERPRESSURE = 20009,
	CLOTH_PBD_EXPANSIONTIME = 20026,
	CLOTH_PBD_CONSTRAINTS_QUADDIAGONALS = 20010,
		CLOTH_PBD_CONSTRAINTS_QUADDIAGONALS_NONE = 0,
		CLOTH_PBD_CONSTRAINTS_QUADDIAGONALS_SINGLE = 1,
		CLOTH_PBD_CONSTRAINTS_QUADDIAGONALS_DOUBLE = 2,
	CLOTH_PBD_TEAR_GUIDE_CONE_ANGLE = 20011,
	CLOTH_PBD_BOUNCINESS = 20027,

	CLOTH_PBD_FORCES_GROUP = 20012,
	CLOTH_PBD_FORCES_INCLUDE = 20013,
	CLOTH_PBD_BENDINESS_WEIGHTS = 20020,
	CLOTH_PBD_STRETCHINESS_WEIGHTS = 20021,
	CLOTH_PBD_FRICTION_WEIGHTS = 20022,
	CLOTH_PBD_THICKNESS_WEIGHTS = 20023,
	CLOTH_PBD_MASS_WEIGHTS = 20024,
	CLOTH_PBD_TEARPAST_WEIGHTS = 20025,
	CLOTH_PBD_BOUNCINESS_WEIGHTS = 20028,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM = 20029,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM_PAST = 20030,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM_PAST_WEIGHTS = 20031,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM_RATE = 20032,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM_RATE_WEIGHTS = 20033,
	CLOTH_PBD_BEND_PLASTIC_DEFORM = 20034,
	CLOTH_PBD_BEND_PLASTIC_DEFORM_PAST = 20035,
	CLOTH_PBD_BEND_PLASTIC_DEFORM_PAST_WEIGHTS = 20036,
	CLOTH_PBD_BEND_PLASTIC_DEFORM_RATE = 20037,
	CLOTH_PBD_BEND_PLASTIC_DEFORM_RATE_WEIGHTS = 20038,
	CLOTH_PBD_PLASTIC_DEFORM_GROUP = 20039,
	CLOTH_PBD_TEARING_GROUP = 20040,
	CLOTH_PBD_BALLOON_GROUP = 20041,
	CLOTH_DO_CALCULATE_ALL  = 20042, // button
	CLOTH_DELCACHE_ALL  = 20043, // button
	CLOTH_PBD_BEND_PLASTIC_DEFORM_HARDENING = 20044,
	CLOTH_PBD_BEND_PLASTIC_DEFORM_HARDENING_WEIGHTS = 20045,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM_HARDENING = 20046,
	CLOTH_PBD_ELASTIC_PLASTIC_DEFORM_HARDENING_WEIGHTS = 20047,
	CLOTH_LEGACYON = 20048,
	CLOTH_PBD_MAPMINTEARPAST = 20049,
	CLOTH_DUMMY
};

#endif // CLOTHTAG_H__