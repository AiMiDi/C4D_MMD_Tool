#ifndef TCAPOSEMORPH_H__
#define TCAPOSEMORPH_H__

enum
{
	ID_CA_POSE_SLIDERS_GROUP = 5000,
	ID_CA_POSE_ADVANCED_GROUP,
	ID_CA_POSE_ANIMATE_GROUP,
	ID_CA_POSE_ROTATION_GROUP,
	ID_CA_POSE_OPTIONS_GROUP,
	ID_CA_POSE_INCLUDE_GROUP,
	ID_CA_POSE_PSD_GROUP,
	ID_CA_POSE_EDIT_PSD_GROUP,
	ID_CA_POSE_OPTIONS_PSD_GROUP,
	ID_CA_POSE_PSD_TAB_GROUP,

	ID_CA_POSE_MORPHS = 1000,
	ID_CA_POSE_MODE,
	ID_CA_POSE_ADDMORPH,
	ID_CA_POSE_P,
	ID_CA_POSE_S,
	ID_CA_POSE_R,
	ID_CA_POSE_STRENGTH,
	ID_CA_POSE_TARGET,
	ID_CA_POSE_EXTERNAL,
	ID_CA_POSE_MIXING,
	ID_CA_POSE_EXTERNAL_SAVE,
	ID_CA_POSE_RECORD_SLIDER,
	ID_CA_POSE_RESET_SLIDER,
	ID_CA_POSE_PARAM,
	ID_CA_POSE_USERDATA,
	ID_CA_POSE_TARGET_INCLUDE,
	ID_CA_POSE_DEST,
	ID_CA_POSE_POINTS,
	ID_CA_POSE_MAPS,
	ID_CA_POSE_ROTATION_POS,
	ID_CA_POSE_ROTATION_AXIS,
	ID_CA_POSE_ROTATION_FROMEDGE,
	ID_CA_POSE_ROTATION_FROMPOINTS,
	ID_CA_POSE_UV,
	ID_CA_POSE_TAGS,
	ID_CA_POSE_MIXING_DEFORMED,
	ID_CA_POSE_EDIT_MODE,
	ID_CA_POSE_HIERARCHY,
	ID_CA_POSE_TARGET_INCLUDE_MODE,
	ID_CA_POSE_MEMORY_USED,
	ID_CA_POSE_USE_STRENGTH,
	ID_CA_POSE_TOTAL_STRENGTH,
	ID_CA_POSE_ANIMATE_FOLDER_GROUPS,
	ID_CA_POSE_BASE_PRI,
	ID_CA_POSE_PSD_ORIENT_INTERP_UI_ONLY,
	ID_CA_POSE_PSD_POS_INTERP_UI_ONLY,
	ID_CA_POSE_PSD_TWIST_INTERP_UI_ONLY,
	ID_CA_POSE_WEIGHTTAG_UI_ONLY,										// ID_CA_POSE_PSD_WEIGHT_TAG should be used for data management, this is only there for the string
	ID_CA_POSE_PSD_ORIENT_INTERP_AVERAGEWEIGHT_UI_ONLY, // ID_CA_POSE_PSD_ORIENT_INTERP_AVERAGEWEIGHT should be used for data management, this is only there for the string
	ID_CA_POSE_PSD_POS_INTERP_AVERAGEWEIGHT_UI_ONLY, // ID_CA_POSE_PSD_POS_INTERP_AVERAGEWEIGHT should be used for data management, this is only there for the string
	ID_CA_POSE_PSD_TWIST_INTERP_AVERAGEWEIGHT_UI_ONLY, // ID_CA_POSE_PSD_TWIST_INTERP_AVERAGEWEIGHT should be used for data management, this is only there for the string
	ID_CA_POSE_PSD_INTERP_AVERAGEWEIGHT_UI_ONLY, // ID_CA_POSE_PSD_INTERP_AVERAGEWEIGHT should be used for data management, this is only there for the string
	ID_CA_POSE_FORCE_AUTOWEIGHTDRIVER,			// PSD Action
	ID_CA_POSE_SHOW_AUTOWEIGHTDRIVER,				// PSD Action
	ID_CA_POSE_UPDATE_PSD_POSE,							// PSD Action
	ID_CA_POSE_RESTORE_PSD_POSE,						// PSD Action
	ID_CA_POSE_PSD_INTERP_MODE_UI_ONLY,			// ID_CA_POSE_PSD_INTERP_MODE should be used for data management, this is only there for the string and UI
	ID_CA_POSE_OPTIONS_PSD_DRAWDRIVER,
	ID_CA_POSE_OPTIONS_PSD_DRIVERCOLOR,
	ID_CA_POSE_OPTIONS_PSD_POS_THRESHOLD,
	ID_CA_POSE_OPTIONS_PSD_ORIENT_THRESHOLD,
	ID_CA_POSE_OPTIONS_PSD_TWIST_THRESHOLD,
	ID_CA_POSE_PSD_AUTOWEIGHT_INTERP_UI_ONLY, // ID_CA_POSE_PSD_AUTOWEIGHT_INTERP should be used for data management
	ID_CA_POSE_NORMAL,

	// Data Offset
	ID_CA_POSE_ANIMATE_DATA = 4000,
	ID_CA_POSE_ANIMATE_CNT = 100,
	ID_CA_POSE_ANIMATE_OFFSET = 1000,

	// Emulation offset
	ID_CA_POSE_EMULUATION_BEGIN = 3000,
	ID_CA_POSE_EMULUATION_END = 3999,

	// IDs for different Modes
	ID_CA_POSE_ANIMATE_ENABLE = 0,
	ID_CA_POSE_ANIMATE_STRENGTH = 1,
	ID_CA_POSE_ANIMATE_PSD_DATA = 2,
	
	ID_CA_POSE_MODE_EDIT = 0,
	ID_CA_POSE_MODE_ANIMATE,

	ID_CA_POSE_MIXING_ABS = 0,
	ID_CA_POSE_MIXING_REL,
	ID_CA_POSE_MIXING_ROT,
	ID_CA_POSE_MIXING_CORRECTIONAL,
	ID_CA_POSE_MIXING_CORRECTIONAL_AREA,
	ID_CA_POSE_MIXING_CORRECTIONAL_PSD,

	ID_CA_POSE_MIX_TYPE_AUTO = 0,
	ID_CA_POSE_MIX_TYPE_HIERARCHY,
	ID_CA_POSE_MIX_TYPE_NAME,

	ID_CA_POSE_EDIT_MODE_OFF = 0,
	ID_CA_POSE_EDIT_MODE_TARGET,
	ID_CA_POSE_EDIT_MODE_INPLACE,

	ID_CA_POSE_TARGET_INCLUDE_MODE_INCLUDE = 0,
	ID_CA_POSE_TARGET_INCLUDE_MODE_EXCLUDE,

	ID_CA_POSE_PSD_INTERP_MODE_AXIS = 0,
	ID_CA_POSE_PSD_INTERP_MODE_JOINT,
	ID_CA_POSE_PSD_INTERP_MODE_GLOBALAVERAGE,
	
	// PSD Offsets
	ID_CA_POSE_PSD_DATA_OFFSET = 100, // PSD Data Start Point (per pose, no joint data)
	ID_CA_POSE_PSD_DUMMYDATA_OFFSET = 900, // Dummy Id, like empty static text
	ID_CA_POSE_PSD_JOINT_OFFSET = 1000, // where joint information begin
	ID_CA_POSE_PSD_JOINT_CNT = 100, // Max Data per Joint

	// PSD Data
	ID_CA_POSE_PSD_ORIENT_INTERP_DEPRECATED = 0,	// Still used for old scene conversion
	ID_CA_POSE_PSD_POS_INTERP_DEPRECATED,					// Still used for old scene conversion
	ID_CA_POSE_PSD_TWIST_INTERP_DEPRECATED,				// Still used for old scene conversion
	ID_CA_POSE_PSD_ORIENT_INTERP_WEIGHT,
	ID_CA_POSE_PSD_POS_INTERP_WEIGHT,
	ID_CA_POSE_PSD_TWIST_INTERP_WEIGHT,
	ID_CA_POSE_PSD_WEIGHT_TAG,
	ID_CA_POSE_PSD_ORIENT_INTERP_AVERAGEWEIGHT,
	ID_CA_POSE_PSD_POS_INTERP_AVERAGEWEIGHT,
	ID_CA_POSE_PSD_TWIST_INTERP_AVERAGEWEIGHT,
	ID_CA_POSE_PSD_INTERP_AVERAGEWEIGHT,
	ID_CA_POSE_PSD_INTERP_MODE,
	ID_CA_POSE_PSD_AUTOWEIGHT_INTERP,	// If Autoweighting is Active

	// Per Joint PSD Data
	ID_CA_POSE_PSD_JOINT_REFERENCE = 0,
	ID_CA_POSE_PSD_JOINT_X_WEIGHT,
	ID_CA_POSE_PSD_JOINT_Y_WEIGHT,
	ID_CA_POSE_PSD_JOINT_Z_WEIGHT,
	ID_CA_POSE_PSD_JOINT_FORCE_IN_AUTOWEIGHT,
	ID_CA_POSE_PSD_JOINT_UNUSED_VALUE, // keep this one at the end


	ID_CA_POSE_TARGET_DUMMY
};

#endif // TCAPOSEMORPH_H__