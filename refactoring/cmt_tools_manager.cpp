/**************************************************************************

Copyright:Copyright(c) 2023-present, Aimidi & CMT contributors.
Author:			Aimidi
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
		LoadVmdCameraLog log;
		const auto vmd_camera_animation = std::make_unique<saba::VMDCameraAnimation>();
		if(!vmd_camera_animation)
		{
			LoadVmdCameraLog::LogOutMem();
			return false;
		}

		maxon::AutoMem<Char> vmd_path(setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		saba::VMDFile vmd_file;
		if (!ReadVMDFile(&vmd_file, vmd_path))
		{
			LoadVmdCameraLog::LogReadFileErr();
			return false;
		}

		if (!vmd_camera_animation->Create(vmd_file))
		{
			LoadVmdCameraLog::LogNotCameraError();
			return false;
		}

		log.camera_frame_number = vmd_file.m_cameras.size();
		if (!CMTSceneManager::LoadVMDCamera(setting, *vmd_camera_animation))
		{
			return false;
		}
		log.LogOK();

		return true;
	}

	bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
	{
		if (ConversionVmdCameraLog log; CMTSceneManager::ConversionCamera(setting))
		{
			log.LogOK();
			return true;
		}
		return false;
	}

	bool ExportVMDCamera(const CMTToolsSetting::CameraExport& setting)
	{
		SaveVmdCameraLog log;
		const auto vmd_animation = make_vmd_animation();
		if (!vmd_animation)
		{
			SaveVmdCameraLog::LogOutMem();
			return false;
		}

		if (!CMTSceneManager::SaveVMDCamera(setting, vmd_animation.get()))
		{
			log.LogOK();
			return false;
		}

		const maxon::AutoMem<Char> vmd_utf8_filename_mem(setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		const std::string_view vmd_utf8_filename{ vmd_utf8_filename_mem };
		if(!vmd_animation->write_to_file_u8(vmd_utf8_filename))
		{
			SaveVmdCameraLog::LogWriteFileErr();
			return false;
		}

		return true;
	}

	bool ImportVMDMotion(const CMTToolsSetting::MotionImport& setting)
	{
		LoadVmdMotionLog log;

		const auto vmd_animation = make_vmd_animation();
		if (!vmd_animation)
		{
			LoadVmdMotionLog::LogOutMem();
			return false;
		}

		maxon::AutoMem<Char> vmd_utf8_filename_mem(setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		const std::string_view vmd_utf8_filename{ vmd_utf8_filename_mem };
		if (!vmd_animation->read_from_file_u8(vmd_utf8_filename))
		{
			LoadVmdMotionLog::LogReadFileErr();
			return false;
		}

		if (vmd_animation->is_camera())
		{
			LoadVmdMotionLog::LogNotMotionError();
			return false;
		}

		if (setting.import_motion)
			vmd_animation->mutable_vmd_bone_key_frame_array().sort();

		if (setting.import_morph)
			vmd_animation->mutable_vmd_morph_key_frame_array().sort();

		if (setting.import_model_info)
			vmd_animation->mutable_vmd_model_controller_key_frame_array().sort();

		if (!CMTSceneManager::LoadVMDMotion(setting, *vmd_animation, log))
		{
			return false;
		}

		log.LogOK(setting.detail_report);

		return true;
	}

	bool ExportVMDMotion(const CMTToolsSetting::MotionExport& setting)
	{
		return true;
	}

	bool ImportPMXModel(const CMTToolsSetting::ModelImport& setting)
	{
		if (setting.import_english_check)


		LoadPmxModelLog log;

		const auto pmx_model = make_pmx_model();
		if (!pmx_model)
		{
			LoadPmxModelLog::LogOutMem();
			return false;
		}

		maxon::AutoMem<Char> pmx_utf8_filename_mem(setting.fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		const std::string_view pmx_utf8_filename{ pmx_utf8_filename_mem };
		if (!pmx_model->read_from_file_u8(pmx_utf8_filename))
		{
			LoadPmxModelLog::LogReadFileErr();
			return false;
		}

		log.Set(*pmx_model, setting);
		if (!CMTSceneManager::LoadPMXModel(setting, *pmx_model))
		{
			return false;
		}
		log.LogOK();

		return true;
	}

	bool ExportPMXModel(const CMTToolsSetting::ModelExport& setting)
	{
		return true;
	}
}
