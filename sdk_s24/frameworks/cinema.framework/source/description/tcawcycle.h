#ifndef TCAWCYCLE_H__
#define TCAWCYCLE_H__

enum
{
	ID_CA_WCYCLE_TAG_GROUP_SETUP = 5000,
	ID_CA_WCYCLE_TAG_GROUP_TARGET,
	ID_CA_WCYCLE_TAG_GROUP_MOTION,
	ID_CA_WCYCLE_TAG_HUB_MOTION_GROUP,
	ID_CA_WCYCLE_TAG_GROUP_POSE,
	ID_CA_WCYCLE_TAG_GROUP_FOOTSTEPS,
	ID_CA_WCYCLE_TAG_GROUP_HUB_BASE,
	ID_CA_WCYCLE_TAG_GROUP_SURFACE,
	ID_CA_WCYCLE_TAG_GROUP_ANIMATE,
	ID_CA_WCYCLE_TAG_GROUP_PATH,
	ID_CA_WCYCLE_TAG_GROUP_AXES,
	ID_CA_WCYCLE_TAG_GROUP_RESTPOSE,
	ID_CA_WCYCLE_TAG_GROUP_ROUTE,
	ID_CA_WCYCLE_TAG_GROUP_ROOT,
	ID_CA_WCYCLE_TAG_PARAMS_GROUP,
	ID_CA_WCYCLE_TAG_GROUP_OBJECTS,
	ID_CA_WCYCLE_TAG_GROUP_ANALYSIS,

	ID_CA_WCYCLE_TAG_START_INDEX = 999,
	ID_CA_WCYCLE_TAG_AUTOTIME = 1000,
	ID_CA_WCYCLE_TAG_START,
	ID_CA_WCYCLE_TAG_STOP,
	ID_CA_WCYCLE_TAG_STRIDE,
	ID_CA_WCYCLE_TAG_STRIDE_TIME,
	ID_CA_WCYCLE_TAG_DIRECTION,
	ID_CA_WCYCLE_TAG_GRADIENT,
	ID_CA_WCYCLE_TAG_PATH,
	ID_CA_WCYCLE_TAG_SURFACE,
	ID_CA_WCYCLE_TAG_HUB,
	ID_CA_WCYCLE_TAG_HUB_PHASE,
	ID_CA_WCYCLE_TAG_TARGET,
	ID_CA_WCYCLE_TAG_TARGET_PHASE,
	ID_CA_WCYCLE_TAG_WALK_TYPE,
	ID_CA_WCYCLE_TAG_HUB_OFFSET,
	ID_CA_WCYCLE_TAG_TARGET_OFFSET,
	ID_CA_WCYCLE_USE_RESTPOSE,
	ID_CA_WCYCLE_STORE_RESTPOSE,
	ID_CA_WCYCLE_TAG_HUB_AUTOOFFSET,
	ID_CA_WCYCLE_TAG_HUB_LIFT_MOTION,
	ID_CA_WCYCLE_TAG_TARGET_LIFT_MOTION,
	ID_CA_WCYCLE_TAG_TARGET_LIFT,
	ID_CA_WCYCLE_STORE_CREATESTEPS,
	ID_CA_WCYCLE_TAG_STEPS,
	ID_CA_WCYCLE_TAG_FOLLOW,
	ID_CA_WCYCLE_TAG_HUB_RETARGET,
	ID_CA_WCYCLE_TAG_SURFACE_OFFSET,
	ID_CA_WCYCLE_TAG_SURFACE_ALIGN_HUB,
	ID_CA_WCYCLE_TAG_SURFACE_ALIGN_TARGET,
	ID_CA_WCYCLE_TAG_TARGET_PLACEMENT,
	ID_CA_WCYCLE_TAG_TARGET_PLACEMENT_SPACE,
	ID_CA_WCYCLE_TAG_WALK_AXIS,
	ID_CA_WCYCLE_TAG_VERT_AXIS,
	ID_CA_WCYCLE_TAG_ALIGN_AXIS,
	ID_CA_WCYCLE_TAG_AXIS_DELETED_1,
	ID_CA_WCYCLE_TAG_AXIS_DELETED_2,
	ID_CA_WCYCLE_TAG_HUB_VOFFSET,
	ID_CA_WCYCLE_TAG_TARGET_VOFFSET,
	ID_CA_WCYCLE_RESTORE_RESTPOSE,
	ID_CA_WCYCLE_TAG_HUB_ROOT,
	ID_CA_WCYCLE_TAG_HUB_TARGETTING,
	ID_CA_WCYCLE_TAG_HUB_HOFFSET,
	ID_CA_WCYCLE_TAG_TARGET_HOFFSET,
	ID_CA_WCYCLE_TAG_ACTION_WEIGHT,
	ID_CA_WCYCLE_TAG_BANK,
	ID_CA_WCYCLE_TAG_HUB_MOTIONS,
	ID_CA_WCYCLE_TAG_HUB_ROOT_TYPE,
	ID_CA_WCYCLE_TAG_AXIS_ALIGN_HUB,
	ID_CA_WCYCLE_TAG_PATH_PROJECTION,
	ID_CA_WCYCLE_TAG_SURFACE_PROJECTION,
	ID_CA_WCYCLE_TAG_PATH_START,
	ID_CA_WCYCLE_TAG_WALK_RELATIVE,
	ID_CA_WCYCLE_TAG_WALK_MODE,
	ID_CA_WCYCLE_TAG_TARGET_WALK,
	ID_CA_WCYCLE_STORE_AUTO_CREATESTEPS,
	ID_CA_WCYCLE_STORE_CREATESTEPS_NUMBER,
	ID_CA_WCYCLE_TAG_LIMIT,
	ID_CA_WCYCLE_TAG_LIMIT_DISTANCE,
	ID_CA_WCYCLE_TAG_STEPS_WEIGHT,
	ID_CA_WCYCLE_TAG_SURFACE_BASE,
	ID_CA_WCYCLE_TAG_SURFACE_BASE_WIDTH,
	ID_CA_WCYCLE_TAG_SURFACE_BASE_LENGTH,
	ID_CA_WCYCLE_TAG_STEPS_TYPE,
	ID_CA_WCYCLE_TAG_HUB_ROOT_OFFSET,
	ID_CA_WCYCLE_TAG_PATH_END,
	ID_CA_WCYCLE_TAG_HUB_MOTION_ACTION_LIST,
	ID_CA_WCYCLE_TAG_ACTION_MIX,
	ID_CA_WCYCLE_TAG_ACTION_MIX_WEIGHT,
	ID_CA_WCYCLE_TAG_DELETED_1,
	ID_CA_WCYCLE_TAG_OBJECTS,
	ID_CA_WCYCLE_TAG_ACTION_ADD,
	ID_CA_WCYCLE_TAG_ACTIONS,
	ID_CA_WCYCLE_TAG_PREVIEW,
	ID_CA_WCYCLE_TAG_HUB_ROOT_AUTO,
	ID_CA_WCYCLE_TAG_LOAD_PRESET,
	ID_CA_WCYCLE_TAG_SAVE_PRESET,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_WCYCLE_TAG_ANALYSE = 4000,
	ID_CA_WCYCLE_TAG_ANALYSIS_AUTO = 4003,
	ID_CA_WCYCLE_TAG_ANALYSIS_START,
	ID_CA_WCYCLE_TAG_ANALYSIS_END,
	ID_CA_WCYCLE_TAG_ANALYSIS_CALC,
	ID_CA_WCYCLE_TAG_ANALYSIS_INPUT,
	ID_CA_WCYCLE_TAG_ANALYSIS_OUPUT,
	ID_CA_WCYCLE_TAG_ANALYSIS_OUPUT_STATIC,
	ID_CA_WCYCLE_TAG_ANALYSIS_FLOOR,
	ID_CA_WCYCLE_TAG_ANALYSIS_STRIDE,
	ID_CA_WCYCLE_TAG_ANALYSIS_TIME,
	ID_CA_WCYCLE_TAG_ANALYSIS_PATHTOSPLINE,
	ID_CA_WCYCLE_TAG_ANALYSIS_MOTION,
	ID_CA_WCYCLE_TAG_ANALYSIS_CREATEMO,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_WCYCLE_TAG_EXPRESSION_PRIORITY = 1000998,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_WCYCLE_TAG_WALK_DUMMY_IDS = 20000,
	ID_CA_WCYCLE_TAG_WALK_PARAMETER_CONTAINER,

	//////////////////////////////////////////////////////////////////////////

	// motions data

	ID_CA_WCYCLE_TAG_WALK_ACTION_ID_BEGIN = 1000,

	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_ID = 0,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_CURVE,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_RANGE,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_LINK,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_WEIGHT,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_VAR,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_BLEND,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_PYTHON,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_PARAM,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_PARAM_CHAN,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_PARAM_NAME,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_ACTION_REF,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MOTION_PARAM_R18,
	// hub data

	ID_CA_WCYCLE_TAG_WALK_ITEM_TYPE = 500,
	ID_CA_WCYCLE_TAG_WALK_ITEM_PARAM_DATA = 502,
	ID_CA_WCYCLE_TAG_WALK_ITEM_MATRIX,
	ID_CA_WCYCLE_TAG_WALK_ITEM_LMATRIX,
	ID_CA_WCYCLE_TAG_WALK_ITEM_PARAMS,
	ID_CA_WCYCLE_TAG_WALK_ITEM_REL_P,
	ID_CA_WCYCLE_TAG_WALK_ITEM_REL_S,
	ID_CA_WCYCLE_TAG_WALK_ITEM_REL_R,

	// common (hub, target)

	ID_CA_WCYCLE_TAG_WALK_ITEM_PHASE_OFFSET = 600,
	ID_CA_WCYCLE_TAG_WALK_ITEM_POS_OFFSET,
	ID_CA_WCYCLE_TAG_WALK_ITEM_VERT_OFFSET,
	ID_CA_WCYCLE_TAG_WALK_ITEM_HORIZ_OFFSET,
	ID_CA_WCYCLE_TAG_WALK_ITEM_TARGET_WALK,
	ID_CA_WCYCLE_TAG_WALK_ITEM_LINK,

	// target

	ID_CA_WCYCLE_TAG_WALK_ITEM_PLACEMENT = 700,
	ID_CA_WCYCLE_TAG_WALK_ITEM_PLACEMENT_SPACE,

	// preset actions

	ID_CA_WCYCLE_TAG_LIFT = 1,	// ids for preset curves
	ID_CA_WCYCLE_TAG_WEIGHTSHIFT,
	ID_CA_WCYCLE_TAG_PUSH,
	ID_CA_WCYCLE_TAG_TWIST,
	ID_CA_WCYCLE_TAG_ROLL,
	ID_CA_WCYCLE_TAG_PITCH,
	ID_CA_WCYCLE_TAG_PITCH_PIVOT,
	ID_CA_WCYCLE_TAG_ROLL_PIVOT,
	ID_CA_WCYCLE_TAG_POSITION,
	ID_CA_WCYCLE_TAG_RETARGET_WEIGHT,
	ID_CA_WCYCLE_TAG_MOTION,
	ID_CA_WCYCLE_TAG_SPLINE,
	ID_CA_WCYCLE_TAG_PYTHON,
	ID_CA_WCYCLE_TAG_PARAM,
	ID_CA_WCYCLE_TAG_ACTION,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_WCYCLE_TAG_WALK_ITEM_TYPE_HUB = 0,
	ID_CA_WCYCLE_TAG_WALK_ITEM_TYPE_TARGET,
	ID_CA_WCYCLE_TAG_WALK_ITEM_TYPE_MOTION,
	ID_CA_WCYCLE_TAG_WALK_ITEM_TYPE_HUB_DEFAULTS,
	ID_CA_WCYCLE_TAG_WALK_ITEM_TYPE_TARGET_DEFAULTS,

	ID_CA_WCYCLE_TAG_WALK_TYPE_STATIC = 0,
	ID_CA_WCYCLE_TAG_WALK_TYPE_LINE,
	ID_CA_WCYCLE_TAG_WALK_TYPE_PATH,

	ID_CA_WCYCLE_TAG_HUB_RETARGET_NONE = 0,
	ID_CA_WCYCLE_TAG_HUB_RETARGET_VERT,
	ID_CA_WCYCLE_TAG_HUB_RETARGET_CENTER,
	ID_CA_WCYCLE_TAG_HUB_RETARGET_WEIGHTED,

	ID_CA_WCYCLE_TAG_TARGET_PLACEMENT_DEFAULT = 0,
	ID_CA_WCYCLE_TAG_TARGET_PLACEMENT_LINE,
	ID_CA_WCYCLE_TAG_TARGET_PLACEMENT_SPACED,

	ID_CA_WCYCLE_TAG_AXIS_X = 0,
	ID_CA_WCYCLE_TAG_AXIS_Y,
	ID_CA_WCYCLE_TAG_AXIS_Z,
	ID_CA_WCYCLE_TAG_AXIS_NX,
	ID_CA_WCYCLE_TAG_AXIS_NY,
	ID_CA_WCYCLE_TAG_AXIS_NZ,

	ID_CA_WCYCLE_TAG_HUB_ROOT_TYPE_MAIN = 0,
	ID_CA_WCYCLE_TAG_HUB_ROOT_TYPE_WORLD,
	ID_CA_WCYCLE_TAG_HUB_ROOT_TYPE_OBJECT,

	ID_CA_WCYCLE_TAG_SURFACE_PROJECTION_CLOSEST = 0,
	ID_CA_WCYCLE_TAG_SURFACE_PROJECTION_DOWN,
	ID_CA_WCYCLE_TAG_SURFACE_PROJECTION_TOPATH,

	ID_CA_WCYCLE_TAG_WALK_MODE_INTERPOLATED = 0,
	ID_CA_WCYCLE_TAG_WALK_MODE_ADAPTIVE,

	ID_CA_WCYCLE_TAG_TARGET_WALK_DISABLE = -1,
	ID_CA_WCYCLE_TAG_TARGET_WALK_NONE = 0,
	ID_CA_WCYCLE_TAG_TARGET_WALK_HUB,
	ID_CA_WCYCLE_TAG_TARGET_WALK_PATH,
	ID_CA_WCYCLE_TAG_TARGET_WALK_STEPS,

	ID_CA_WCYCLE_TAG_SURFACE_BASE_POINT = 0,
	ID_CA_WCYCLE_TAG_SURFACE_BASE_RECT,
	ID_CA_WCYCLE_TAG_SURFACE_BASE_OBJECT,

	ID_CA_WCYCLE_TAG_STEPS_TYPE_STEPS = 0,
	ID_CA_WCYCLE_TAG_STEPS_TYPE_HUBS,
	ID_CA_WCYCLE_TAG_STEPS_TYPE_FULL,

	ID_CA_WCYCLE_STORE_AUTO_CREATESTEPS_CUSTOM = 0,
	ID_CA_WCYCLE_STORE_AUTO_CREATESTEPS_ALL,
	ID_CA_WCYCLE_STORE_AUTO_CREATESTEPS_CURRENT,

	ID_CA_WCYCLE_TAG_TARGET_ACTION_LIST_HINDEX = 1000,
	ID_CA_WCYCLE_TAG_TARGET_ACTION_LIST_TINDEX,

	ID_CA_WCYCLE_TAG_ACTION_MIX_NONE = 0,
	ID_CA_WCYCLE_TAG_ACTION_MIX_ABS,
	ID_CA_WCYCLE_TAG_ACTION_MIX_ADD,
	ID_CA_WCYCLE_TAG_ACTION_MIX_SUB,
	ID_CA_WCYCLE_TAG_ACTION_MIX_MULT,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_WCYCLE_TAG_DUMMY
};

#endif // TCAWCYCLE_H__