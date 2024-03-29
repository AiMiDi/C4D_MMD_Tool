#ifndef TOOLCAJOINT_H__
#define TOOLCAJOINT_H__

enum
{
	ID_CA_JOINT_TOOL_GROUP_DISPLAY = 5000,
	ID_CA_JOINT_TOOL_GROUP_MODIFIERS,
	ID_CA_JOINT_TOOL_GROUP_SYMMETRY,

	ID_CA_JOINT_TOOL_CREATE = 2000,
	ID_CA_JOINT_TOOL_ALIGN_AXIS,
	ID_CA_JOINT_TOOL_IK_CHAIN,
	ID_CA_JOINT_TOOL_SYMMETRY,
	ID_CA_JOINT_TOOL_MIRROR_ORIGIN,
	ID_CA_JOINT_TOOL_MIRROR_ORIGIN_LINK,
	ID_CA_JOINT_TOOL_MIRROR_PLANE,
	ID_CA_JOINT_TOOL_DUMMY_1,
	ID_CA_JOINT_TOOL_MODIFIER_DEFAULT,
	ID_CA_JOINT_TOOL_MODIFIER_CTRL,
	ID_CA_JOINT_TOOL_MODIFIER_SHIFT,
	ID_CA_JOINT_TOOL_CREATE_AT,
	ID_CA_JOINT_TOOL_HIGHLIGHT,
	ID_CA_JOINT_TOOL_BOUNDING_BOX,
	ID_CA_JOINT_TOOL_CREATE_ROOT,
	ID_CA_JOINT_TOOL_CREATE_POLE,
	ID_CA_JOINT_TOOL_SIZE,
	ID_CA_JOINT_TOOL_SIZE_USER,
	ID_CA_JOINT_TOOL_PROJECTION,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_JOINT_TOOL_CREATE_AXIS = 0,
	ID_CA_JOINT_TOOL_CREATE_FROMPARENT,
	ID_CA_JOINT_TOOL_CREATE_TOCHILD,

	ID_CA_JOINT_TOOL_MIRROR_WORLD_XY = 0,
	ID_CA_JOINT_TOOL_MIRROR_WORLD_XZ,
	ID_CA_JOINT_TOOL_MIRROR_WORLD_YZ,
	ID_CA_JOINT_TOOL_MIRROR_LOCAL_XY,
	ID_CA_JOINT_TOOL_MIRROR_LOCAL_XZ,
	ID_CA_JOINT_TOOL_MIRROR_LOCAL_YZ,

	ID_CA_JOINT_TOOL_MIRROR_ORIGIN_WORLD = 0,
	ID_CA_JOINT_TOOL_MIRROR_ORIGIN_ROOT,
	ID_CA_JOINT_TOOL_MIRROR_ORIGIN_HUB,
	ID_CA_JOINT_TOOL_MIRROR_ORIGIN_OBJECT,
	ID_CA_JOINT_TOOL_MIRROR_ORIGIN_PARENT,

	ID_CA_JOINT_TOOL_MODIFIER_DRAW = 0,
	ID_CA_JOINT_TOOL_MODIFIER_MOVE_JOINT,
	ID_CA_JOINT_TOOL_MODIFIER_MOVE_CHAIN,
	ID_CA_JOINT_TOOL_MODIFIER_SPLIT,
	ID_CA_JOINT_TOOL_MODIFIER_ALIGN,
	ID_CA_JOINT_TOOL_MODIFIER_SNAP,

	ID_CA_JOINT_TOOL_NAME_DEFAULT = 0,
	ID_CA_JOINT_TOOL_NAME_CUSTOM,
	ID_CA_JOINT_TOOL_NAME_COMPONENT,

	ID_CA_JOINT_TOOL_NAME_AS_NONE = 0,

	ID_CA_JOINT_TOOL_IK_CHAIN_NONE = 0,
	ID_CA_JOINT_TOOL_IK_CHAIN_2D,
	ID_CA_JOINT_TOOL_IK_CHAIN_3D,
	ID_CA_JOINT_TOOL_IK_CHAIN_SPLINE,

	ID_CA_JOINT_TOOL_SYMMETRY_NONE = 0,
	ID_CA_JOINT_TOOL_SYMMETRY_DRAW,
	ID_CA_JOINT_TOOL_SYMMETRY_LINKED,

	ID_CA_JOINT_TOOL_SIZE_LENGTH = 0,
	ID_CA_JOINT_TOOL_SIZE_CUSTOM,

	//////////////////////////////////////////////////////////////////////////

	ID_CA_JOINT_TOOL_DUMMY
};

#endif // TOOLCAJOINT_H__
