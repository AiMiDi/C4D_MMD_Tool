/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/30
File:			cmt_tools_dialog.cpp
Description:	CMT tools main dialog.

**************************************************************************/

#include "pch.h"
#include "cmt_tools_dialog.h"
#include "cmt_tools_setting.h"
#include "cmt_tools_config_manager.h"
#include "cmt_tools_manager.h"

inline void CMTToolDialog::GetItem(const Int32 id, Float& value) const
{
	GetFloat(id, value);
	CMTToolConfigManager::GetInstance().SetConfig(id, value);
}

inline void CMTToolDialog::GetItem(const Int32 id, Int32& value) const
{
	GetInt32(id, value);
	CMTToolConfigManager::GetInstance().SetConfig(id, value);
}

inline void CMTToolDialog::GetItem(const Int32 id, Bool& value) const
{
	GetBool(id, value);
	CMTToolConfigManager::GetInstance().SetConfig(id, value);
}

Bool CMTToolDialog::CreateLayout()
{
	// call default CreateLayout()
	if (!GeDialog::CreateLayout())
		return false;

	// load dialog from resource file
	if (!LoadDialogResource(DLG_CMT_TOOL, nullptr, 0))
		return false;

	m_images = NewObj(ImagesUserArea, "mmd_tool_title.png"_s, 300, 95).GetValue();
	this->AttachUserArea((*m_images), DLG_CMT_TOOL_IMG);
	return true;
}

Bool CMTToolDialog::InitValues()
{
	CMTToolConfigManager::GetInstance().InitDialog(this);
	return true;
}

Bool CMTToolDialog::Command(const Int32 id, const BaseContainer& msg)
{
	iferr_scope_handler{
			return false;
	};
	switch (id)
	{
	case DLG_CMT_TOOL_CAMERA_IMPORT_BUTTON:
	{
		CMTToolsSetting::CameraImport setting(GetActiveDocument());
		GetItem(DLG_CMT_TOOL_CAMERA_IMPORT_SIZE, setting.position_multiple);
		GetItem(DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET, setting.time_offset);
		if(!filename_util::SelectSuffixImportFile(setting.fn, "vmd"_s))
		{
			return false;
		}
		if(!CMTToolsManager::ImportVMDCamera(setting))
		{
			return false;
		}
		break;
	}
	case DLG_CMT_TOOL_CAMERA_CONV_BUTTON:
	{
		CMTToolsSetting::CameraConversion setting(GetActiveDocument());
		GetItem(DLG_CMT_TOOL_CAMERA_CONV_DIS, setting.distance);
		GetItem(DLG_CMT_TOOL_CAMERA_CONV_ROTATION_TWEEN, setting.use_rotation);
		if (!CMTToolsManager::ConversionCamera(setting))
		{
			return false;
		}
		break;
	}
	case DLG_CMT_TOOL_CAMERA_EXPORT_USE_BAKE:
	{
		Bool use_bake = true;
		GetBool(DLG_CMT_TOOL_CAMERA_EXPORT_USE_BAKE, use_bake);
		if (use_bake == true) {
			Enable(DLG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN, false);
		}
		else {
			Enable(DLG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN, true);
		}
		break;
	}
	case DLG_CMT_TOOL_CAMERA_EXPORT_BUTTON:
	{
		CMTToolsSetting::CameraExport setting(GetActiveDocument());
		GetItem(DLG_CMT_TOOL_CAMERA_EXPORT_SIZE, setting.position_multiple);
		setting.position_multiple = 1.0 / setting.position_multiple;
		GetItem(DLG_CMT_TOOL_CAMERA_EXPORT_OFFSET, setting.time_offset);
		GetItem(DLG_CMT_TOOL_CAMERA_EXPORT_USE_BAKE, setting.use_bake);
		GetItem(DLG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN, setting.use_rotation);
		if (!filename_util::SelectSuffixExportFile(setting.fn, "vmd"_s))
		{
			return false;
		}
		if (!CMTToolsManager::ExportVMDCamera(setting))
		{
			return false;
		}
		break;
	}
	case DLG_CMT_TOOL_MOTION_IMPORT_BUTTON:
	{
		CMTToolsSetting::MotionImport setting(GetActiveDocument());
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_SIZE, setting.position_multiple);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_OFFSET, setting.time_offset);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_MOTION, setting.import_motion);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_MORPH, setting.import_morph);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_MODEL_INFO, setting.import_model_info);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_IGNORE_PHYSICAL, setting.ignore_physical);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_DELETE_PREVIOUS_ANIMATION, setting.delete_previous_animation);
		GetItem(DLG_CMT_TOOL_MOTION_IMPORT_DETAIL, setting.detail_report);
		break;
	}
	case DLG_CMT_TOOL_MOTION_EXPORT_USE_BAKE:
	{
		Bool use_bake = true;
		GetBool(DLG_CMT_TOOL_MOTION_EXPORT_USE_BAKE, use_bake);
		if (use_bake == true) {
			Enable(DLG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN, false);
		}
		else {
			Enable(DLG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN, true);
		}
		break;
	}
	case DLG_CMT_TOOL_MOTION_EXPORT_BUTTON:
	{
		CMTToolsSetting::MotionExport setting(GetActiveDocument());
		GetItem(DLG_CMT_TOOL_MOTION_EXPORT_SIZE, setting.position_multiple);
		GetItem(DLG_CMT_TOOL_MOTION_EXPORT_OFFSET, setting.time_offset);
		GetItem(DLG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN, setting.use_rotation);
		GetItem(DLG_CMT_TOOL_MOTION_EXPORT_MOTION, setting.export_motion);
		GetItem(DLG_CMT_TOOL_MOTION_EXPORT_MORPH, setting.export_morph);
		GetItem(DLG_CMT_TOOL_MOTION_EXPORT_MODEL_INFO, setting.export_model_info);
		break;
	}
	case DLG_CMT_TOOL_POSE_IMPORT_BUTTON:
	{
		break;
	}
	case DLG_CMT_TOOL_MODEL_IMPORT_BUTTON:
	{
		CMTToolsSetting::ModelImport setting(GetActiveDocument());
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_SIZE, setting.position_multiple);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_POLYGON, setting.import_polygon);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_NORMAL, setting.import_normal);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_UV, setting.import_uv);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL, setting.import_material);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_BONE, setting.import_bone);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, setting.import_weights);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_IK, setting.import_ik);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_INHERIT, setting.import_inherit);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_EXPRESSION, setting.import_expression);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_MULTIPART, setting.import_multipart);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH, setting.import_english);
		GetItem(DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH_CHECK, setting.import_english_check);
		break;
	}
	case DLG_CMT_TOOL_MODEL_IMPORT_BONE:
	{
		Bool import_bone = false;
		GetBool(DLG_CMT_TOOL_MODEL_IMPORT_BONE, import_bone);
		if (import_bone == false)
		{
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_IK, false);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_INHERIT, false);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_IK, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_INHERIT, false);
		}
		else {
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, true);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_IK, true);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_INHERIT, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_IK, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_INHERIT, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, true);
		}
		break;
	}
	case DLG_CMT_TOOL_MODEL_IMPORT_POLYGON:
	{
		Bool import_polygon = false;
		GetBool(DLG_CMT_TOOL_MODEL_IMPORT_POLYGON, import_polygon);
		if (import_polygon == false)
		{
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_NORMAL, false);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_UV, false);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, false);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_EXPRESSION, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_NORMAL, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_UV, false);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_EXPRESSION, false);
		}
		else {
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, true);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_NORMAL, true);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_UV, true);
			Enable(DLG_CMT_TOOL_MODEL_IMPORT_EXPRESSION, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_EXPRESSION, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_NORMAL, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_UV, true);
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS, true);
		}
		break;
	}
	case DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH:
	{
		Bool import_english = false;
		GetBool(DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH, import_english);
		if (import_english == false)
		{
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH_CHECK, false);
		}
		else {
			SetBool(DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH_CHECK, true);
		}
		break;
	}
	default:
		break;
	}
	CMTToolConfigManager::GetInstance().SaveConfig();
	return true;
}
