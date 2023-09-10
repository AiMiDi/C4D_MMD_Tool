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
	std::shared_ptr<libmmd::vmd_animation> make_vmd_animation()
	{
		return std::shared_ptr<libmmd::vmd_animation>{ libmmd::vmd_animation::create(), libmmd::vmd_animation::free };
	}

	bool ImportVMDCamera(const CMTToolsSetting::CameraImport& setting)
	{
		maxon::AutoMem<Char> vmd_utf8_filename_mem(setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		const std::string_view vmd_utf8_filename{ vmd_utf8_filename_mem };
		const auto vmd_animation = make_vmd_animation();
		if(!vmd_animation)
		{
			return false;
		}
		if (!vmd_animation->read_from_file_u8(vmd_utf8_filename))
		{
			return false;
		}

		vmd_animation->mutable_vmd_camera_key_frame_array().sort();
		if (CMTSceneManager::LoadVMDCamera(setting, *vmd_animation))
		{
			return false;
		}

		return true;
	}

	bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
	{
		if (CMTSceneManager::ConversionCamera(setting))
		{
			return true;
		}
		return false;
	}

	bool ExportVMDCamera(const CMTToolsSetting::CameraExport& setting)
	{
		const maxon::AutoMem<Char> vmd_utf8_filename_mem(setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		const std::string_view vmd_utf8_filename{ vmd_utf8_filename_mem };
		const auto vmd_animation = make_vmd_animation();
		if (!vmd_animation)
		{
			return false;
		}

		if (CMTSceneManager::SaveVMDCamera(setting, vmd_animation.get()))
		{
			return false;
		}

		if(!vmd_animation->write_to_file_u8(vmd_utf8_filename))
		{
			return false;
		}
		
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
