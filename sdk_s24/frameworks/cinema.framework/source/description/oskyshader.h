#ifndef OSKYSHADER_H__
#define OSKYSHADER_H__

enum
{
	Oskyshader                            = 1000,

	ID_SKY_GROUP_DATE_TIME                = 4000,
	ID_SKY_GROUP_ASTRO                    = 4003,
	ID_SKY_GROUP_GENERAL                  = 4004,
	ID_SKY_GROUP_CLOUDS                   = 4110,
	ID_SKY_GROUP_FOG                      = 4111,
	ID_SKY_GROUP_VOL_CLOUDS               = 4112,
	ID_SKY_GROUP_RAINBOW                  = 4113,
	ID_SKY_GROUP_SKY_OBJECTS              = 4114,
	ID_SKY_GROUP_SUNBEAMS                 = 4115,
	ID_SKY_GROUP_ENABLE                   = 4116,

	ID_SKY_GROUP_ILLUMINATION             = 4118,
	ID_SKY_GROUP_PHYSICAL_SKY             = 4119,
	ID_SKY_GROUP_PHYSICAL_SUN             = 4120,
	ID_SKY_GROUP_PHYSICAL_ATM             = 4121,

	ID_SKY_MAT_SETTINGS                   = 4170, // dummy
	ID_SKY_GROUP_GENERAL_ADV              = 4180,
	ID_SKY_GROUP_BEAM_ADV                 = 4181,

	ID_SKY_GROUP_LAYER_1                  = 4201,
	ID_SKY_GROUP_LAYER_2                  = 4202,
	ID_SKY_GROUP_LAYER_3                  = 4203,
	ID_SKY_GROUP_LAYER_4                  = 4204,
	ID_SKY_GROUP_LAYER_5                  = 4205,
	ID_SKY_GROUP_LAYER_6                  = 4206,

	SKY_SHOW_CLOUD_BOX                    = 9002,
	SKY_CLOUD_EDITOR_COLOR                = 9003,
	SKY_UPDATE_EDITOR                     = 9004,
	SKY_PREVIEW_DATA                      = 9005,
	SKY_EXPRESSION_PRIORITY               = 9006, // priority
	SKY_CLOUD_EDITOR_QUALITY              = 9007, // real

	SKY_MATERIAL_PREVIEWSIZE							= 500, // long
		SKY_MATERIAL_PREVIEWSIZE_DEF					= 0,
		SKY_MATERIAL_PREVIEWSIZE_64						= 6,
		SKY_MATERIAL_PREVIEWSIZE_128					= 7,
		SKY_MATERIAL_PREVIEWSIZE_256					= 8,
		SKY_MATERIAL_PREVIEWSIZE_512					= 9,
		SKY_MATERIAL_PREVIEWSIZE_1024					= 10,
		SKY_MATERIAL_PREVIEWSIZE_2048					= 11,
		SKY_MATERIAL_PREVIEWSIZE_4096					= 12,

	SKY_ASTRO_PLANET                      = 9992,

	SKY_DATE_TIME                         = 10000, // date time
	SKY_TIME_NOW                          = 10001, // bool
	SKY_DATE_TODAY                        = 10002, // bool
	SKY_DATE_ANIMATE                      = 10003, // bool
	SKY_TIME_ANIMATE                      = 10004, // bool
	SKY_SHOW_HUD                          = 10005, // bool

	SKY_POS_LATITUDE                      = 10200, // real
	SKY_POS_LONGITUDE                     = 10201, // real
	SKY_POS_CITY_COMBO                    = 10202, // combo box
	SKY_POS_CITY_NEW_COMMAND							= 10203, // private
	SKY_POS_CITY_DEL_COMMAND              = 10204, // private
	SKY_POS_CITY                          = 10205, // hidden string
	SKY_POS_CONTINENT                     = 10206, // hidden string
	SKY_POS_COUNTRY                       = 10207, // hidden string
	SKY_POS_TIME_ZONE                     = 10208, // real
	SKY_POS_DST_TIME_ZONE                 = 10209, // real
	SKY_POS_TIMEZONE                      = 10210, // long
		SKY_POS_TZ_OS                       = 0,
		SKY_POS_TZ_CUSTOM                   = 1,
	SKY_POS_DST_SETTINGS                  = 10211, // long
		SKY_POS_DST_LAST_MARCH_LAST_OCT     = 0,
		SKY_POS_DST_FIRST_APR_LAST_OCT      = 1,
		SKY_POS_DST_FIRST_OCT_LAST_MARCH    = 2,
		SKY_POS_DST_LAST_OCT_LAST_MARCH     = 3,
		SKY_POS_DST_SECOND_MARCH_FIRST_NOV  = 4,
		SKY_POS_DST_OFF                     = 99,

	SKY_ASTRO_SUN_SHOW                    = 10311, // real
	SKY_ASTRO_MOON_SHOW                   = 10321, // real
	SKY_ASTRO_PLANETS_SHOW                = 10331, // bool
	SKY_ASTRO_SHOW_STARS                  = 10450, // bool

	SKY_GENERAL_SCALE_MOON                = 10500, // real
	SKY_GENERAL_USER_HORIZON              = 10501, // bool
	SKY_GENERAL_USER_COLOR                = 10502, // gradient
	SKY_GENERAL_EARTH_RADIUS              = 10503, // real
	SKY_GENERAL_EARTH_POS_ABOVE_NN        = 10504, // real
	SKY_GENERAL_MIN_MAG                   = 10505, // real
	SKY_GENERAL_RESIZE_STARS              = 10506, // bool
	SKY_GENERAL_LIGHTEN_UP_STARS          = 10507, // real
	SKY_GENERAL_STAR_RADIUS               = 10509, // real
	SKY_GENERAL_SHOW_CONSTELLATIONS       = 10510, // bool
	SKY_GENERAL_GRID_WIDTH                = 10511, // real
	SKY_GENERAL_MOON_DIST_SCALE           = 10512, // real
	SKY_GENERAL_SUN_DIST_SCALE            = 10513, // real
	SKY_GENERAL_CONSTELLATION_COLOR       = 10514, // color
	SKY_GENERAL_MOISTURE                  = 10515, // real
	SKY_GENERAL_CHANGE_SUN_COL            = 10524, // bool
	SKY_GENERAL_SUN_COLOR                 = 10525, // vector
	SKY_GENERAL_STRENGTH                  = 10526, // real
	SKY_GENERAL_GRID_COLOR                = 10527, // vector
	SKY_GENERAL_USER_HORIZON_MAX_ALT      = 10528, // real
	SKY_GENERAL_GI_INFLUENCE              = 10529, // real
	SKY_GENERAL_MAX_FLARE_GLOW            = 10530, // real
	SKY_GENERAL_MAX_FLARE_REFL            = 10531, // real
	SKY_GENERAL_HORIZON_START             = 10532, // real
	SKY_GENERAL_MOON_BRIGHT               = 10533, // real
	SKY_GENERAL_MOON_DARK                 = 10534, // real
	SKY_GENERAL_OZONE_LEGACY              = 10535, // real - legacy
	SKY_GENERAL_LENSFLARES                = 10536, // bool
	SKY_GENERAL_GI_SATURATION             = 10537, // real
	SKY_GENERAL_SKY_DOME                  = 10538, // bool
	SKY_GENERAL_MERGE_SUN                 = 10539, // bool

	SKY_CLOUD_1_NOISE                     = 11000, // long
	SKY_CLOUD_1_DENSITY                   = 11001, // real
	SKY_CLOUD_1_COVERAGE                  = 11002, // real
	SKY_CLOUD_1_THICKNESS                 = 11003, // real
	SKY_CLOUD_1_HEIGHT                    = 11004, // real
	SKY_CLOUD_1_ACTIVE                    = 11005, // bool
	SKY_CLOUD_1_SCALE_NS                  = 11006, // real
	SKY_CLOUD_1_SCALE_WE                  = 11007, // real
	SKY_CLOUD_1_MOVE_NS                   = 11008, // real
	SKY_CLOUD_1_MOVE_WE                   = 11009, // real
	SKY_CLOUD_1_COLOR                     = 11011, // vector
	SKY_CLOUD_1_TRANSPARENCY              = 11012, // real
	SKY_CLOUD_1_PREVIEW                   = 11013, // preview
	SKY_CLOUD_1_SPEED                     = 11010, // real
	SKY_CLOUD_1_OFFSET                    = 11014, // real

	SKY_CLOUD_2_NOISE                     = 12000, // long
	SKY_CLOUD_2_DENSITY                   = 12001, // real
	SKY_CLOUD_2_COVERAGE                  = 12002, // real
	SKY_CLOUD_2_THICKNESS                 = 12003, // real
	SKY_CLOUD_2_HEIGHT                    = 12004, // real
	SKY_CLOUD_2_ACTIVE                    = 12005, // bool
	SKY_CLOUD_2_SCALE_NS                  = 12006, // real
	SKY_CLOUD_2_SCALE_WE                  = 12007, // real
	SKY_CLOUD_2_MOVE_NS                   = 12008, // real
	SKY_CLOUD_2_MOVE_WE                   = 12009, // real
	SKY_CLOUD_2_MOVEMENT                  = 12010, // real
	SKY_CLOUD_2_COLOR                     = 12011, // vector
	SKY_CLOUD_2_TRANSPARENCY              = 12012, // real
	SKY_CLOUD_2_PREVIEW                   = 12013, // preview
	SKY_CLOUD_2_SPEED                     = 12010, // real
	SKY_CLOUD_2_OFFSET                    = 12014, // real

	SKY_CLOUD_3_NOISE                     = 13000, // long
	SKY_CLOUD_3_DENSITY                   = 13001, // real
	SKY_CLOUD_3_COVERAGE                  = 13002, // real
	SKY_CLOUD_3_THICKNESS                 = 13003, // real
	SKY_CLOUD_3_HEIGHT                    = 13004, // real
	SKY_CLOUD_3_ACTIVE                    = 13005, // bool
	SKY_CLOUD_3_SCALE_NS                  = 13006, // real
	SKY_CLOUD_3_SCALE_WE                  = 13007, // real
	SKY_CLOUD_3_MOVE_NS                   = 13008, // real
	SKY_CLOUD_3_MOVE_WE                   = 13009, // real
	SKY_CLOUD_3_COLOR                     = 13011, // vector
	SKY_CLOUD_3_TRANSPARENCY              = 13012, // real
	SKY_CLOUD_3_PREVIEW                   = 13013, // preview
	SKY_CLOUD_3_SPEED                     = 13010, // real
	SKY_CLOUD_3_OFFSET                    = 13014, // real

	SKY_CLOUD_4_NOISE                     = 14000, // long
	SKY_CLOUD_4_DENSITY                   = 14001, // real
	SKY_CLOUD_4_COVERAGE                  = 14002, // real
	SKY_CLOUD_4_THICKNESS                 = 14003, // real
	SKY_CLOUD_4_HEIGHT                    = 14004, // real
	SKY_CLOUD_4_ACTIVE                    = 14005, // bool
	SKY_CLOUD_4_SCALE_NS                  = 14006, // real
	SKY_CLOUD_4_SCALE_WE                  = 14007, // real
	SKY_CLOUD_4_MOVE_NS                   = 14008, // real
	SKY_CLOUD_4_MOVE_WE                   = 14009, // real
	SKY_CLOUD_4_COLOR                     = 14011, // vector
	SKY_CLOUD_4_TRANSPARENCY              = 14012, // real
	SKY_CLOUD_4_PREVIEW                   = 14013, // preview
	SKY_CLOUD_4_SPEED                     = 14010, // real
	SKY_CLOUD_4_OFFSET                    = 14014, // real

	SKY_CLOUD_5_NOISE                     = 15000, // long
	SKY_CLOUD_5_DENSITY                   = 15001, // real
	SKY_CLOUD_5_COVERAGE                  = 15002, // real
	SKY_CLOUD_5_THICKNESS                 = 15003, // real
	SKY_CLOUD_5_HEIGHT                    = 15004, // real
	SKY_CLOUD_5_ACTIVE                    = 15005, // bool
	SKY_CLOUD_5_SCALE_NS                  = 15006, // real
	SKY_CLOUD_5_SCALE_WE                  = 15007, // real
	SKY_CLOUD_5_MOVE_NS                   = 15008, // real
	SKY_CLOUD_5_MOVE_WE                   = 15009, // real
	SKY_CLOUD_5_COLOR                     = 15011, // vector
	SKY_CLOUD_5_TRANSPARENCY              = 15012, // real
	SKY_CLOUD_5_PREVIEW                   = 15013, // preview
	SKY_CLOUD_5_SPEED                     = 15010, // real
	SKY_CLOUD_5_OFFSET                    = 15014, // real

	SKY_CLOUD_6_NOISE                     = 16000, // long
	SKY_CLOUD_6_DENSITY                   = 16001, // real
	SKY_CLOUD_6_COVERAGE                  = 16002, // real
	SKY_CLOUD_6_THICKNESS                 = 16003, // real
	SKY_CLOUD_6_HEIGHT                    = 16004, // real
	SKY_CLOUD_6_ACTIVE                    = 16005, // bool
	SKY_CLOUD_6_SCALE_NS                  = 16006, // real
	SKY_CLOUD_6_SCALE_WE                  = 16007, // real
	SKY_CLOUD_6_MOVE_NS                   = 16008, // real
	SKY_CLOUD_6_MOVE_WE                   = 16009, // real
	SKY_CLOUD_6_COLOR                     = 16011, // vector
	SKY_CLOUD_6_TRANSPARENCY              = 16012, // real
	SKY_CLOUD_6_PREVIEW                   = 16013, // preview
	SKY_CLOUD_6_SPEED                     = 16010, // real
	SKY_CLOUD_6_OFFSET                    = 16014, // real
	SKY_CLOUD_ROLLOFF                     = 16100, // gradient
	SKY_CLOUD_ENABLE                      = 16101, // bool
	SKY_CLOUD_LAST												= 16999, // dummy

	SKY_CLOUD_1_SAVE_PRESET               = 10518, // button
	SKY_CLOUD_2_SAVE_PRESET               = 10519, // button
	SKY_CLOUD_3_SAVE_PRESET               = 10520, // button
	SKY_CLOUD_4_SAVE_PRESET               = 10521, // button
	SKY_CLOUD_5_SAVE_PRESET               = 10522, // button
	SKY_CLOUD_6_SAVE_PRESET               = 10523, // button

	SKY_FOG_ENABLE                        = 17000, // bool
	SKY_FOG_COLOR                         = 17012, // vector
	SKY_FOG_START                         = 17001, // real
	SKY_FOG_MAXDIST                       = 17011, // real
	SKY_FOG_END                           = 17002, // real
	SKY_FOG_DENSITY                       = 17003, // real
	SKY_FOG_DENSITY_DISTRIB               = 17004, // spline
	SKY_FOG_NOISE                         = 17005, // noise
	SKY_FOG_SAMPLE_SIZE                   = 17006, // real
	SKY_FOG_SCALE                         = 17007, // vector
	SKY_FOG_ANIMATION_SPEED               = 17008, // real
	SKY_FOG_NOISE_STRENGTH                = 17009, // real
	SKY_FOG_MOVEMENT                      = 17010, // vector
	SKY_FOG_SHADOW_INTENSITY              = 17013, // real
	SKY_FOG_ILLUM_INTENSITY               = 17014, // real

	SKY_VOL_CLOUDS_RENDER                 = 18000, // bool
	SKY_VOL_CLOUDS_RECEIVE_SHADOWS        = 18003, // bool
	SKY_VOL_CLOUDS_ADJUST_ALTITUDE        = 18009, // bool
	SKY_VOL_CLOUDS_EDGE_NOISE_CONTRAST    = 18004, // real
	SKY_VOL_CLOUDS_EDGE_NOISE_SCALE       = 18005, // real
	SKY_VOL_CLOUDS_EDGE_NOISE_NOISE       = 18007, // long
	SKY_VOL_CLOUDS_EDGE_NOISE_SPEED       = 18010, // real
	SKY_VOL_CLOUDS_SAMPLE_SIZE            = 18008, // real
	SKY_VOL_CLOUDS_LIGHT_LIST             = 18011, // light list

	SKY_RAINBOW_RENDER                    = 19000, // bool
	SKY_RAINBOW_MAX_STRENGTH              = 19001, // real
	SKY_RAINBOW_TURBIDITY_DEP             = 19002, // bool
	SKY_RAINBOW_TURBIDITY_THRESHOLD_MIN   = 19003, // real
	SKY_RAINBOW_TURBIDITY_THRESHOLD_MAX   = 19004, // real
	SKY_RAINBOW_1_INNER                   = 19005, // real
	SKY_RAINBOW_1_OUTER                   = 19006, // real
	SKY_RAINBOW_2_INNER                   = 19007, // real
	SKY_RAINBOW_2_OUTER                   = 19008, // real
	SKY_RAINBOW_START_CLIP                = 19009, // real
	SKY_RAINBOW_END_CLIP                  = 19010, // real

	SKY_SKY_OBJECTS                       = 20000, // custom gui
	SKY_SKY_OBECT_PLACE                   = 20001, // button

	SKY_BEAMS_ENABLE                      = 21000, // bool
	SKY_BEAMS_INTENS                      = 21001, // real
	SKY_BEAMS_MIN_BRIGHTNESS              = 21002, // real
	SKY_BEAMS_START                       = 21003, // real
	SKY_BEAMS_END                         = 21004, // real
	SKY_BEAMS_SAMPLE_DIST                 = 21005, // real
	SKY_BEAMS_TURBIDITY_DEPENDENT         = 21006, // bool

	SKY_MATERIAL_GLOBALILLUM_GENERATE					= 1101,
	SKY_MATERIAL_GLOBALILLUM_GENERATE_STRENGTH = 1112,

	SKY_OBJECT_SUN_OBJECT                 = 10104, // link
	SKY_OBJECT_MOON_OBJECT                = 10105, // link

	SKY_PHYSICAL_SKY_ENABLE 		= 24000, // bool
	SKY_REAL_SKY_SKY_WARM_COLORS_LEGACY	= 24001, // bool - legacy
	SKY_REAL_SKY_SKY_CHROMA_LEGACY		= 24002, // bool - legacy
	SKY_REAL_SKY_SKY_INTENSITY		= 24003, // real
	SKY_REAL_SKY_SKY_GAMMA			= 24004, // real
	SKY_REAL_SKY_SKY_SEEN_INTENSITY		= 24005, // real
	SKY_REAL_SKY_SKY_INTENSITY_NIGHT	= 24006, // real
	SKY_REAL_SKY_SKY_HUE			= 24007, // real
	SKY_REAL_SKY_SKY_SATURATION		= 24008, // real
	SKY_REAL_SKY_SKY_HORIZON		= 24009, // bool
	SKY_REAL_SKY_SKY_DITHER			= 24010, // real
	SKY_REAL_SKY_SKY_COLOR_WARMNESS		= 24011, // real

	SKY_REAL_SKY_TURBIDITY 			= 24020, // real
	SKY_REAL_SKY_OZONE    			= 24021, // real

	SKY_PHYSICAL_SUN_ENABLE			= 25000, // bool
	SKY_REAL_SKY_SUN_WARM_COLORS_LEGACY	= 25001, // bool - legacy
	SKY_REAL_SKY_SUN_INTENSITY		= 25002, // real
	SKY_REAL_SKY_SUN_GAMMA			= 25003, // real
	SKY_REAL_SKY_SUN_HUE			= 25004, // real
	SKY_REAL_SKY_SUN_SATURATION		= 25005, // real
	SKY_REAL_SKY_SUN_SIZE_RATIO		= 25006, // real
	SKY_REAL_SKY_SUN_SEEN_INTENSITY		= 25007, // real
	SKY_REAL_SKY_SUN_COLOR			= 25008, // color
	SKY_REAL_SKY_SUN_SHADOW_COLOR		= 25009, // color
	SKY_REAL_SKY_SUN_SAMPLING_QUALITY	= 25010, // real
	SKY_REAL_SKY_SUN_SAMPLING_SAMPLES_MIN	= 25011, // long
	SKY_REAL_SKY_SUN_SAMPLING_SAMPLES_MAX	= 25012, // long
	SKY_REAL_SKY_SUN_SHADOW_TYPE		= 25013, // long
		SKY_SUN_SHADOW_TYPE_NONE            = 1,
		SKY_SUN_SHADOW_TYPE_HARD            = 2,
		SKY_SUN_SHADOW_TYPE_AREA            = 3,
	SKY_REAL_SKY_SUN_SHADOW_DENSITY 	= 25014, // real
	SKY_REAL_SKY_SUN_SHADOW_TRANSPARENCY 	= 25015, // bool

	SKY_PHYSICAL_ATM_ENABLE 		= 26000, // bool
	SKY_REAL_SKY_ATM_INTENSITY		= 26001, // real
	SKY_REAL_SKY_ATM_GAMMA			= 26002, // real
	SKY_REAL_SKY_ATM_SCALE_RATIO		= 26003, // real
	SKY_REAL_SKY_ATM_HUE			= 26004, // real
	SKY_REAL_SKY_ATM_SATURATION		= 26005, // real
	SKY_REAL_SKY_ATM_HORIZON		= 26006, // real
	SKY_REAL_SKY_ATM_DITHER			= 26007, // real

	SKY_TIMEANDLOCATION = 27000,
	SKY_DETAILS = 27001,
	SKY_OBJECTS = 27002,
	SKY_LEFT_SEPARATOR = 27004,

	SKY_CLOUDS_SHADOW	= 27005,

	SKY_GROUP_PHYSICAL_SUN_SHADOW = 27006,
	SKY_PHYSICALSKYPAGE = 27007,

	SKY_PRESET = 27008,
	SKY_WEATHERPRESET = 27009,

	SKY_SHADER_DUMMY_
};

#endif // OSKYSHADER_H__
