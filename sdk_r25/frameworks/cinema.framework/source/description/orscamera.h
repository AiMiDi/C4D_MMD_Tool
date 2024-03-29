#ifndef ORSCAMERA_H__
#define ORSCAMERA_H__

enum
{
	ID_GROUP_PHYSICAL = 10000,
	ID_GROUP_POSTEFFECTS,
	ID_GROUP_DISPLAY,

	RSCAMERAOBJECT_PROJECTION,

	// Lens,
	RSCAMERAOBJECT_GROUP_LENS,
	RSCAMERAOBJECT_FOCAL_LENGTH,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET,
	RSCAMERAOBJECT_FOV_HORIZONTAL,
	RSCAMERAOBJECT_FOV_VERTICAL,
	RSCAMERAOBJECT_ZOOM,
	RSCAMERAOBJECT_LENS_DISTORTION,
	RSCAMERAOBJECT_LENS_DISTORTION_INTENSITY,
	RSCAMERAOBJECT_LENS_DISTORTION_FILE,

	RSCAMERAOBJECT_GROUP_SPHERICAL_CAMERA,
	RSCAMERAOBJECT_FOV_HELPER,
	RSCAMERAOBJECT_MAPPING,
	RSCAMERAOBJECT_FIT_FRAME,
	RSCAMERAOBJECT_USE_FULL_MAPPING,
	RSCAMERAOBJECT_LATITUDE_MIN,
	RSCAMERAOBJECT_LATITUDE_MAX,
	RSCAMERAOBJECT_LONGITUDE_MIN,
	RSCAMERAOBJECT_LONGITUDE_MAX,

	// Sensor Size,
	RSCAMERAOBJECT_GROUP_SENSOR_SIZE,
	RSCAMERAOBJECT_SENSOR_SIZE_PRESET,
	RSCAMERAOBJECT_SENSOR_SIZE_WIDTH,
	RSCAMERAOBJECT_SENSOR_SIZE_HEIGHT,
	RSCAMERAOBJECT_RESOLUTION_GATE_FIT,
	RSCAMERAOBJECT_RESOLUTION_GATE_FIT_PRESET,
	RSCAMERAOBJECT_SENSOR_SHIFT_HORIZONTAL,
	RSCAMERAOBJECT_SENSOR_SHIFT_VERTICAL,

	// Clipping,
	RSCAMERAOBJECT_CLIPPING_GROUP,
	RSCAMERAOBJECT_NEAR_CLIPPING,
	RSCAMERAOBJECT_NEAR_CLIPPING_ENABLE,
	RSCAMERAOBJECT_FAR_CLIPPING,
	RSCAMERAOBJECT_FAR_CLIPPING_ENABLE,

	// Physical
	RSCAMERAOBJECT_EXPOSURE,
	RSCAMERAOBJECT_PHOTOGRAPHIC_EXPOSURE,
	RSCAMERAOBJECT_ISO,
	RSCAMERAOBJECT_ISO_PRESET,
	RSCAMERAOBJECT_SHUTTER_SPEED,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET,
	RSCAMERAOBJECT_APERTURE,
	RSCAMERAOBJECT_APERTURE_PRESET,
	RSCAMERAOBJECT_WHITE_BALANCE,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET,
	RSCAMERAOBJECT_VIGNETTING,

	// Depth of Field
	RSCAMERAOBJECT_GROUP_DEPTH_OF_FIELD,
	RSCAMERAOBJECT_DEPTH_OF_FIELD,
	RSCAMERAOBJECT_FOCUS_DISTANCE,
	RSCAMERAOBJECT_TARGETOBJECT,
	RSCAMERAOBJECT_USETARGETOBJECT,

	RSCAMERAOBJECT_APERTURE_SHAPE,
	RSCAMERAOBJECT_APERTURE_BLADES,
	RSCAMERAOBJECT_APERTURE_ANGLE,
	RSCAMERAOBJECT_APERTURE_BIAS,
	RSCAMERAOBJECT_APERTURE_ANISOTROPY,
	RSCAMERAOBJECT_APERTURE_SHADER,

	// Motion Blur
	RSCAMERAOBJECT_GROUP_MOTION_BLUR,
	RSCAMERAOBJECT_MOTION_BLUR,
	RSCAMERAOBJECT_SHUTTER_EFFICIENCY,

	// Post Effects
	RSCAMERAOBJECT_POSTEFFECTS_OVERRIDE_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_LUT_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_CONTROLS_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_ENABLED,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_ENABLED,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_COLOR_MANAGEMENT,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_COMPENSATE_VIEW,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_DISPLAY_MODE,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_GAMMA,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_OCIO_CONFIG,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_OCIO_VIEW_TRANSFORM,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_LUT,
	RSCAMERAOBJECT_POSTEFFECTS_LUT_FILE,
	RSCAMERAOBJECT_POSTEFFECTS_LUT_INTENSITY,
	RSCAMERAOBJECT_POSTEFFECTS_LUT_LOG_SPACE,
	RSCAMERAOBJECT_POSTEFFECTS_LUT_COLOR_MANAGEMENT,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_COLOR_CONTROLS,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_CONTROLS_BRIGHTNESS,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_CONTROLS_CONTRAST,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_CONTROLS_SATURATION,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_CURVES,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_CONTROLS_GRADING_INTENSITY,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_TONE_MAPPING,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_INTENSITY,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_SHOULDER_ANGLE,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_SHOULDER_LENGTH,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_SHOULDER_STRENGTH,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_TOE_LENGTH,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_TOE_STRENGTH,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_TINT,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_TINT_SHADOWS,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_TINT_MIDTONES,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_TINT_HIGHLIGHTS,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_BLOOM,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_THRESHOLD,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_SOFTNESS,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_INTENSITY,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_TINT,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_TINT_1,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_TINT_2,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_TINT_3,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_TINT_4,
	RSCAMERAOBJECT_POSTEFFECTS_BLOOM_TINT_5,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_FLARE,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_THRESHOLD,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_SOFTNESS,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_CHROMATIC,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_SIZE,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_HALO,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_INTENSITY,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT_1,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT_2,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT_3,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT_4,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT_5,
	RSCAMERAOBJECT_POSTEFFECTS_FLARE_TINT_6,

	RSCAMERAOBJECT_POSTEFFECTS_GROUP_STREAK,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_THRESHOLD,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_TAIL,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_SOFTNESS,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_NUMBER,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_ANGLE,
	RSCAMERAOBJECT_POSTEFFECTS_STREAK_INTENSITY,

	// Layout helpers
	RSCAMERAOBJECT_LAYOUTHELP_ENABLE								= 5001,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GRID_ENABLE,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GRID_CELLS,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_ENABLE,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_I,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_TOP,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_BOTTOM,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_LEFT,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_RIGHT,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_DIAGONAL_ENABLE,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_DIAGONAL_MIRROR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_ENABLE,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_MODE,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_MODE_1,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_MODE_2,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_MIRROR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_FLIP,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ENABLE,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_MIRROR_H,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_MIRROR_V,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GRID,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_DIAGONAL,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_FLIP,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_V,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_H,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_CENTER,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_TOP,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_BOTTOM,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_LEFT,
		RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_ALIGN_RIGHT,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GRID_COLOR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSECTION_COLOR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_DIAGONAL_COLOR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_TRIANGLES_COLOR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_GOLDENSPIRAL_COLOR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_CROSSHAIR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_CROSSHAIR_ENABLE,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_CROSSHAIR_COLOR,
	RSCAMERAOBJECT_LAYOUTHELP_DRAW_CROSSHAIR_SCALE,
	RSCAMERAOBJECT_LAYOUTHELP_SHOW_FRUSTUM,


	// Enums
	RSCAMERAOBJECT_PROJECTION_PERSPECTIVE = 0,
	RSCAMERAOBJECT_PROJECTION_PARALLEL = 1,
	RSCAMERAOBJECT_PROJECTION_LEFT = 2,
	RSCAMERAOBJECT_PROJECTION_RIGHT = 3,
	RSCAMERAOBJECT_PROJECTION_FRONT = 4,
	RSCAMERAOBJECT_PROJECTION_BACK = 5,
	RSCAMERAOBJECT_PROJECTION_TOP = 6,
	RSCAMERAOBJECT_PROJECTION_BOTTOM = 7,
	RSCAMERAOBJECT_PROJECTION_ISOMETRIC = 12,
	RSCAMERAOBJECT_PROJECTION_DIMETRIC = 13,
	RSCAMERAOBJECT_PROJECTION_SPHERICAL = 14,
	RSCAMERAOBJECT_PROJECTION_FISHEYE =15,
	RSCAMERAOBJECT_PROJECTION_CYLINDRICAL = 16,
	RSCAMERAOBJECT_PROJECTION_STEREO_SPHERICAL = 17,

	RSCAMERAOBJECT_FOV_HELPER_DOME = 0,
	RSCAMERAOBJECT_FOV_HELPER_EQUIRECTANGULAR,

	RSCAMERAOBJECT_MAPPING_LATITUDE_LONGITUDE = 0,
	RSCAMERAOBJECT_MAPPING_CUBIC_CROSS,
	RSCAMERAOBJECT_MAPPING_CUBIC_3X2,
	RSCAMERAOBJECT_MAPPING_CUBIC_STRING,
	
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_14 = 0,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_24,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_35,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_50,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_85,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_135,
	RSCAMERAOBJECT_FOCAL_LENGTH_PRESET_300,

	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_CUSTOM = 0,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_2000,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_1000,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_500,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_250,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_125,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_60,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_30,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_15,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_8,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_4,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1_2,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_1,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_2,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_4,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_8,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_15,
	RSCAMERAOBJECT_SHUTTER_SPEED_PRESET_30,

	RSCAMERAOBJECT_APERTURE_PRESET_CUSTOM = 0,
	RSCAMERAOBJECT_APERTURE_PRESET_1,
	RSCAMERAOBJECT_APERTURE_PRESET_1_1,
	RSCAMERAOBJECT_APERTURE_PRESET_1_2,
	RSCAMERAOBJECT_APERTURE_PRESET_1_4,
	RSCAMERAOBJECT_APERTURE_PRESET_1_6,
	RSCAMERAOBJECT_APERTURE_PRESET_1_8,
	RSCAMERAOBJECT_APERTURE_PRESET_2,
	RSCAMERAOBJECT_APERTURE_PRESET_2_2,
	RSCAMERAOBJECT_APERTURE_PRESET_2_4,
	RSCAMERAOBJECT_APERTURE_PRESET_2_8,
	RSCAMERAOBJECT_APERTURE_PRESET_3_2,
	RSCAMERAOBJECT_APERTURE_PRESET_3_5,
	RSCAMERAOBJECT_APERTURE_PRESET_4,
	RSCAMERAOBJECT_APERTURE_PRESET_4_5,
	RSCAMERAOBJECT_APERTURE_PRESET_5,
	RSCAMERAOBJECT_APERTURE_PRESET_5_6,
	RSCAMERAOBJECT_APERTURE_PRESET_6_3,
	RSCAMERAOBJECT_APERTURE_PRESET_7_1,
	RSCAMERAOBJECT_APERTURE_PRESET_8,
	RSCAMERAOBJECT_APERTURE_PRESET_9,
	RSCAMERAOBJECT_APERTURE_PRESET_10,
	RSCAMERAOBJECT_APERTURE_PRESET_11,
	RSCAMERAOBJECT_APERTURE_PRESET_13,
	RSCAMERAOBJECT_APERTURE_PRESET_14,
	RSCAMERAOBJECT_APERTURE_PRESET_16,
	RSCAMERAOBJECT_APERTURE_PRESET_18,
	RSCAMERAOBJECT_APERTURE_PRESET_20,
	RSCAMERAOBJECT_APERTURE_PRESET_22,
	RSCAMERAOBJECT_APERTURE_PRESET_32,

	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_CUSTOM = 0,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_CANDLELIGHT,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_SUNSET,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_TUNGSTEN,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_QUARTZ,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_FLUORESCENT,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_SUN_NOON,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_WHITE,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_OVERCAST,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_SHADE,
	RSCAMERAOBJECT_WHITE_BALANCE_PRESET_PARTLY_CLOUDY,

	RSCAMERAOBJECT_RESOLUTION_GATE_FIT_PRESET_FILL = 0,
	RSCAMERAOBJECT_RESOLUTION_GATE_FIT_PRESET_HORIZONTAL,
	RSCAMERAOBJECT_RESOLUTION_GATE_FIT_PRESET_VERTICAL,
	RSCAMERAOBJECT_RESOLUTION_GATE_FIT_PRESET_OVERSCAN,

	RSCAMERAOBJECT_SENSOR_SIZE_PRESET_ARRI = 0,

	RSCAMERAOBJECT_LENS_DISTORTION_QUADRATIC = 0,
	RSCAMERAOBJECT_LENS_DISTORTION_CUBIC,
	RSCAMERAOBJECT_LENS_DISTORTION_IMAGE,

	RSCAMERAOBJECT_APERTURE_SHAPE_CIRCULAR = 0,
	RSCAMERAOBJECT_APERTURE_SHAPE_BLADED,
	RSCAMERAOBJECT_APERTURE_SHAPE_SHADER,

	RSCAMERAOBJECT_ISO_CUSTOM = 0,
	RSCAMERAOBJECT_ISO_50,
	RSCAMERAOBJECT_ISO_100,
	RSCAMERAOBJECT_ISO_200,
	RSCAMERAOBJECT_ISO_400,
	RSCAMERAOBJECT_ISO_800,
	RSCAMERAOBJECT_ISO_1600,
	RSCAMERAOBJECT_ISO_3200,
	RSCAMERAOBJECT_ISO_6400,
	RSCAMERAOBJECT_ISO_12800,
	RSCAMERAOBJECT_ISO_25600,
	RSCAMERAOBJECT_ISO_51200,
	RSCAMERAOBJECT_ISO_102400,

	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_DISPLAY_MODE_LINEAR = 0,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_DISPLAY_MODE_SRGB,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_DISPLAY_MODE_REC709,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_DISPLAY_MODE_CUSTOM_GAMMA,
	RSCAMERAOBJECT_POSTEFFECTS_COLOR_MANAGEMENT_DISPLAY_MODE_OCIO,

	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR_FILMIC = 0,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR_FILMIC_ADVANCED,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR_REINHARD,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR_UCHIMURA,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR_ACES,
	RSCAMERAOBJECT_POSTEFFECTS_TONE_MAPPING_OPERATOR_ACES_RRT,

	_REDSHIFT_CAMERA_END_
};

#endif // ORSCAMERA_H__
