/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			walter white
Date:			2022/6/21
File:			plugin_resource.h
Description:	plugin load resource

**************************************************************************/

#ifndef PLUGIN_RESOURCE_H__
#define PLUGIN_RESOURCE_H__

/*------------Plugin ID------------*/
//	GUI
constexpr auto ID_COMMAND_CMT_TOOL = 1056563;

//	Entity
constexpr auto ID_O_MMD_MODEL		= 1056724;
constexpr auto ID_T_MMD_MATERIAL	= 1056725;
constexpr auto ID_T_MMD_DISPLAY		= 1056721;
constexpr auto ID_T_MMD_BONE		= 1056720;
constexpr auto ID_O_MMD_RIGID		= 1056722;
constexpr auto ID_O_MMD_JOINT		= 1056723;
constexpr auto ID_O_MMD_CAMERA		= 1056978;
constexpr auto ID_O_MMD_MESH_ROOT	= 1057943;
constexpr auto ID_O_MMD_BONE_ROOT	= 1057944;
constexpr auto ID_O_MMD_RIGID_ROOT	= 1057945;
constexpr auto ID_O_MMD_JOINT_ROOT	= 1057946;

//	Util
constexpr auto ID_SCENE_HOOK_CMT_SCENE_MANAGER = 1057017;
constexpr auto ID_L_MMD_VMD_IMPORT             = 1057489;
constexpr auto ID_E_MMD_VMD_EXPORT             = 1057490;

#endif // !PLUGIN_RESOURCE_H__
