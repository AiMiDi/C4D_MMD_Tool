#ifndef TOOLCAWEIGHT_H__
#define TOOLCAWEIGHT_H__

// NOTE: Lots of the deprecated item below were moved to the new weight manager description files.
// Weight manager and weight tool data were separated for R19.

enum
{
	ID_CA_WEIGHT_TOOL_JOINTS_GROUP_DEPRECATED = 5000,
	ID_CA_WEIGHT_TOOL_DISPLAY_GROUP,
	ID_CA_WEIGHT_TOOL_PAINT_GROUP,
	ID_CA_WEIGHT_TOOL_AUTOWEIGHT_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SMOOTH_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SYMMETRY_GROUP,
	ID_CA_WEIGHT_TOOL_SHEET_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_CLAMP_GROUP,
	ID_CA_WEIGHT_TOOL_BRUSH_GROUP,
	ID_CA_WEIGHT_TOOL_SHEET_EDIT_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SHEET_OPTIONS_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SHEET_FILTER_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_JOINT_FN_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_PAINT_FN_GROUP_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_SUB_GROUP,
	ID_CA_WEIGHT_TOOL_DISPLAY_COLORS_GROUP,

	ID_CA_WEIGHT_TOOL_RADIUS = 2000,
	ID_CA_WEIGHT_TOOL_AUTOWEIGHT_DISTANCE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_PEN,
	ID_CA_WEIGHT_TOOL_VISIBLE_ONLY,
	ID_CA_WEIGHT_TOOL_PREVIEW_DEPRECATED,
	ID_CA_WEIGHT_TOOL_STRENGTH,
	ID_CA_WEIGHT_TOOL_MODE,
	ID_CA_WEIGHT_TOOL_PROJECTION,
	ID_CA_WEIGHT_TOOL_JOINTS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_JOINTS_LOCK_DEPRECATED,
	ID_CA_WEIGHT_TOOL_JOINTS_UNLOCKALL_DEPRECATED,
	ID_CA_WEIGHT_TOOL_JOINTS_UNLOCK_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SHOWALL_DEPRECATED,

	ID_CA_WEIGHT_TOOL_SELECTED,
	ID_CA_WEIGHT_TOOL_CLAMP_LOWER_ENABLE,
	ID_CA_WEIGHT_TOOL_CLAMP_LOWER,
	ID_CA_WEIGHT_TOOL_CLAMP_UPPER_ENABLE,
	ID_CA_WEIGHT_TOOL_CLAMP_UPPER,
	ID_CA_WEIGHT_TOOL_APPLY_ALL_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FALLOFF,
	ID_CA_WEIGHT_TOOL_WIDTH,
	ID_CA_WEIGHT_TOOL_FALLOFF_CURVE,
	ID_CA_WEIGHT_TOOL_HARDNESS,

	ID_CA_WEIGHT_TOOL_DISPLAY_FALLOFF,
	ID_CA_WEIGHT_TOOL_DISPLAY_CURSOR,
	ID_CA_WEIGHT_TOOL_DISPLAY_MOUSEIN,
	ID_CA_WEIGHT_TOOL_DISPLAY_FALLOFF_COLOR,
	ID_CA_WEIGHT_TOOL_DISPLAY_ERASE_COLOR,
	ID_CA_WEIGHT_TOOL_DISPLAY_CURSOR_COLOR,

	ID_CA_WEIGHT_TOOL_APPLY_SELECTED_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_ZERO_COLOR_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_LOWER,
	ID_CA_WEIGHT_TOOL_DISPLAY_UPPER,
	ID_CA_WEIGHT_TOOL_DISPLAY_POINTS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DELETED_7_DEPRECATED,

	ID_CA_WEIGHT_TOOL_EDITOR_WEIGHTS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_EDITOR_SLIDER_DEPRECATED,

	ID_CA_WEIGHT_TOOL_NORMALIZE,
	ID_CA_WEIGHT_TOOL_REASSIGN_DEPRECATED,
	ID_CA_WEIGHT_TOOL_EDITOR_SLIDER_ZERO_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SHOWALL_JOINTS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DELETED_1_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_COLOR_MODE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_COLOR_DEPRECATED,

	ID_CA_WEIGHT_TOOL_DISPLAY_EFFECTORS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_LOCK_LIST_DEPRECATED,
	ID_CA_WEIGHT_TOOL_BAKE_DEPRECATED,

	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_CLEARWEIGHT_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_JOINTS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_FALLOFF_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_MODE_DEPRECATED,

	ID_CA_WEIGHT_TOOL_DELETED_2_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_SELECTED_VERTICES_DEPRECATED,

	ID_CA_WEIGHT_TOOL_DELETED_3_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_SMOOTH_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FN_AUTOWEIGHT_VIS_DEPRECATED,

	ID_CA_WEIGHT_TOOL_SMOOTH_STRENGTH_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SMOOTH_DISTANCE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SMOOTH_CURVE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SMOOTH_INTERACTIVE_DEPRECATED,

	ID_CA_WEIGHT_TOOL_DISPLAY_MOUSEOVER_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_FADE_DEPRECATED,

	ID_CA_WEIGHT_TOOL_DELETED_6_DEPRECATED,
	ID_CA_WEIGHT_TOOL_NORMALIZE_ALL_DEPRECATED,

	ID_CA_WEIGHT_TOOL_SPLINE,

	ID_CA_WEIGHT_TOOL_SYMMETRY,
	ID_CA_WEIGHT_TOOL_SYMMETRY_RAD,
	ID_CA_WEIGHT_TOOL_SYMMETRY_COORD,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MIRROR,
	ID_CA_WEIGHT_TOOL_SYMMETRY_COORD_CUSTOM_OBJECT,

	ID_CA_WEIGHT_TOOL_DELETED_4_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DELETED_5_DEPRECATED,

	ID_CA_WEIGHT_TOOL_SYMMETRY_MODE,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MODE_NAME_LEFT,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MODE_NAME_RIGHT,

	ID_CA_WEIGHT_TOOL_DISPLAY_HSIZE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_LINK_SELECTION_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FOCUS_DEPRECATED,
	ID_CA_WEIGHT_TOOL_WEIGHTS_FILTER_DEPRECATED,
	ID_CA_WEIGHT_TOOL_WEIGHTS_FILTER_MIN_DEPRECATED,
	ID_CA_WEIGHT_TOOL_WEIGHTS_FILTER_MAX_DEPRECATED,
	ID_CA_WEIGHT_TOOL_TOTAL_DEPRECATED,

	ID_CA_WEIGHT_TOOL_WEIGHTS_SLIDER_MODE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SLIDER_NORMALIZE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FULLWEIGHTED_DEPRECATED,

	ID_CA_WEIGHT_TOOL_SMOOTH_DEPRECATED,
	ID_CA_WEIGHT_TOOL_MIRROR_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FLIP_PLANE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_WEIGHTS_SELECTION_DEPRECATED,

	ID_CA_WEIGHT_TOOL_COPY_DEPRECATED,
	ID_CA_WEIGHT_TOOL_REPLACE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_MERGE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_DEPRECATED,
	ID_CA_WEIGHT_TOOL_WEIGHTS_HIDE_ZERO_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SORT_LIST_DEPRECATED,
	ID_CA_WEIGHT_TOOL_SELECTED_COLOR_MODE_DEPRECATED,
	ID_CA_WEIGHT_TOOL_DISPLAY_SELECTED_COLOR_DEPRECATED,
	ID_CA_WEIGHT_TOOL_EDITOR_ROUND_TO_DEPRECATED,
	ID_CA_WEIGHT_TOOL_EDITOR_SLIDER_SETV_DEPRECATED,
	ID_CA_WEIGHT_TOOL_FILTER_LIST_DEPRECATED,
	
	ID_CA_WEIGHT_TOOL_ENABLE_DISPLAY = 2500,

	ID_CA_WEIGHT_TOOL_SYMMETRY_MODE_NONE = 0,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MODE_NAME,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MODE_HIEARCHY,

	ID_CA_WEIGHT_TOOL_PEN_NONE = 0,
	ID_CA_WEIGHT_TOOL_PEN_RADIUS,
	ID_CA_WEIGHT_TOOL_PEN_STRENGTH,
	ID_CA_WEIGHT_TOOL_PEN_HARDNESS,

	ID_CA_WEIGHT_TOOL_FALLOFF_NONE = 0,
	ID_CA_WEIGHT_TOOL_FALLOFF_LINEAR,
	ID_CA_WEIGHT_TOOL_FALLOFF_DOME,
	ID_CA_WEIGHT_TOOL_FALLOFF_BELL,
	ID_CA_WEIGHT_TOOL_FALLOFF_CIRCLE,
	ID_CA_WEIGHT_TOOL_FALLOFF_NEEDLE,
	ID_CA_WEIGHT_TOOL_FALLOFF_SPLINE,
	ID_CA_WEIGHT_TOOL_FALLOFF_SIMPLE,

	ID_CA_WEIGHT_TOOL_SYMMETRY_COORD_LOCAL = 0,
	ID_CA_WEIGHT_TOOL_SYMMETRY_COORD_WORLD,
	ID_CA_WEIGHT_TOOL_SYMMETRY_COORD_CUSTOM,

	ID_CA_WEIGHT_TOOL_SYMMETRY_MIRROR_XY = 0,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MIRROR_YZ,
	ID_CA_WEIGHT_TOOL_SYMMETRY_MIRROR_XZ,

	ID_CA_WEIGHT_TOOL_DUMMY
};

#endif // TOOLCAWEIGHT_H__
