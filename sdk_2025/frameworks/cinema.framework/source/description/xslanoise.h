#ifndef XSLANOISE_H__
#define XSLANOISE_H__

enum
{
	XSLANoise                             = 1000,

	SLA_NOISE_USE_AS_ENV                  = 1017, // bool
	SLA_NOISE_PROJECT_ENV                 = 1018, // bool
	SLA_NOISE_SEED												= 1024, // long
	SLA_NOISE_NOISE                       = 1001, // long
		//SLA_NOISE_NOISE_BOX_NOISE           = 2001,
		//SLA_NOISE_NOISE_BLIST_TURB          = 2002,
		//SLA_NOISE_NOISE_BUYA                = 2003,
		//SLA_NOISE_NOISE_CELL_NOISE          = 2004,
		//SLA_NOISE_NOISE_CRANAL              = 2005,
		//SLA_NOISE_NOISE_DENTS               = 2006,
		//SLA_NOISE_NOISE_DISPL_TURB          = 2007,
		//SLA_NOISE_NOISE_FBM                 = 2008,
		//SLA_NOISE_NOISE_HAMA                = 2009,
		//SLA_NOISE_NOISE_LUKA                = 2010,
		//SLA_NOISE_NOISE_MOD_NOISE           = 2011,
		//SLA_NOISE_NOISE_NAKI                = 2012,
		//SLA_NOISE_NOISE_NOISE               = 2013,
		//SLA_NOISE_NOISE_NUTOUS              = 2014,
		//SLA_NOISE_NOISE_OBER                = 2015,
		//SLA_NOISE_NOISE_PEZO                = 2016,
		//SLA_NOISE_NOISE_POXO                = 2017,
		//SLA_NOISE_NOISE_RANDOM              = 2018,
		//SLA_NOISE_NOISE_SEMA                = 2019,
		//SLA_NOISE_NOISE_STUPL               = 2020,
		//SLA_NOISE_NOISE_TURBULENCE          = 2021,
		//SLA_NOISE_NOISE_VL_NOISE            = 2022,
		//SLA_NOISE_NOISE_WAVY_TURB           = 2023,
		//SLA_NOISE_NOISE_SEPARATOR           = 3000,
		//SLA_NOISE_NOISE_CELL_VORONOI        = 2024,
		//SLA_NOISE_NOISE_DISPL_VORONOI       = 2025,
		//SLA_NOISE_NOISE_SPARSE_CONV         = 2026,
		//SLA_NOISE_NOISE_VORONOI_1           = 2027,
		//SLA_NOISE_NOISE_VORONOI_2           = 2028,
		//SLA_NOISE_NOISE_VORONOI_3           = 2029,
		//SLA_NOISE_NOISE_ZADA                = 2030,

	SLA_NOISE_SPACE                       = 1022,
		SLA_NOISE_SPACE_UV                  = 2099,
		SLA_NOISE_SPACE_TEXTURE             = 2100,
		SLA_NOISE_SPACE_OBJECT              = 2101,
		SLA_NOISE_SPACE_WORLD               = 2102,
		SLA_NOISE_SPACE_CAMERA              = 2103,
		SLA_NOISE_SPACE_SCREEN              = 2104,
		SLA_NOISE_SPACE_RASTER              = 2105,

	SLA_NOISE_GLOBAL_SCALE                = 1002, // real
	SLA_NOISE_SCALE                       = 1003, // vector
	SLA_NOISE_ANI_SPEED                   = 1005, // real
	SLA_NOISE_DETAIL_ATT                  = 1006, // real
	SLA_NOISE_OCTAVES                     = 1007, // real
	SLA_NOISE_DELTA                       = 1008, // real
	//SLA_NOISE_HARD_BUMP                   = 1021, // bool
	SLA_NOISE_MOVEMENT                    = 1019, // vector
	SLA_NOISE_SPEED                       = 1020, // real
	SLA_NOISE_COLOR1                      = 1009, // vector
	SLA_NOISE_COLOR2                      = 1010, // vector
	SLA_NOISE_ABSOLUTE                    = 1011, // bool
	SLA_NOISE_CYCLES                      = 1012, // real
	SLA_NOISE_LOW_CLIP                    = 1013, // real
	SLA_NOISE_HIGH_CLIP                   = 1014, // real
	SLA_NOISE_BRIGHTNESS                  = 1015, // real
	SLA_NOISE_CONTRAST                    = 1016, // real
	SLA_NOISE_TIMEPERIOD									= 1023, // real

	SLA_NOISE_COMPATIBILITY								= 3000,

	SLA_NOISE_DUMMY_
};

#endif // XSLANOISE_H__
