/**************************************************************************

Copyright:Copyright(c) 2023-present, Aimidi libMMD contributors.
Author:			walter white/Aimidi
Date:			2023/7/28
File:			cmt_tools_manager.cpp
Description:	tools manager

**************************************************************************/

#include "pch.h"
#include "cmt_tools_manager.h"
#include "CMTSceneManager.h"

namespace CMTToolsManager
{
	bool ImportVMDCamera(const CMTToolsSetting::CameraImport& setting)
	{
		const std::string vmd_utf8_filename{ setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8) };
		libmmd::vmd_animation* vmd_animation = libmmd::create_vmd_animation();
		if (!vmd_animation->read_from_file(vmd_utf8_filename))
			return false;

		CMTSceneManager::GetSceneManager(GetActiveDocument()).LoadVMDCamera(setting, vmd_animation);

		libmmd::delete_vmd_animation(&vmd_animation);
		return true;
	}

	bool ExportVMDCamera(const CMTToolsSetting::CameraExport& setting)
	{
		const std::string vmd_utf8_filename{ setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8) };
		libmmd::vmd_animation* vmd_animation = libmmd::create_vmd_animation();
		if(!vmd_animation->write_to_file(vmd_utf8_filename))
			return false;
		// TODO

		libmmd::delete_vmd_animation(&vmd_animation);
		return true;
	}

	bool ImportVMDMotion(CMTToolsSetting::MotionImport& setting)
	{
		return true;
	}

	bool ExportVMDMotion(CMTToolsSetting::MotionExport& setting)
	{
		return true;
	}

	bool ImportPMXModel(CMTToolsSetting::ModelImport& setting)
	{
		return true;
	}

	bool ExportPMXModel(CMTToolsSetting::ModelExport& setting)
	{
		return true;
	}
}
