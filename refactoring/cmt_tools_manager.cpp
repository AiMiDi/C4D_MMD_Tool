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

		auto vmd_camera_animation = std::make_unique<libmmd::VMDCameraAnimation>();
		if(!vmd_camera_animation)
		{
			LoadVmdCameraLog::LogOutMem();
			return false;
		}

		const auto vmd_path= string_util::GetStdString(setting.fn.GetString());
		libmmd::VMDFile vmd_file;
		if (!ReadVMDFile(&vmd_file, vmd_path.c_str()))
		{
			LoadVmdCameraLog::LogReadFileErr();
			return false;
		}

		if (!vmd_camera_animation->Create(vmd_file))
		{
			LoadVmdCameraLog::LogNotCameraError();
			return false;
		}

		log.camera_frame_number = vmd_camera_animation->GetKeyCount();
		if (!CMTSceneManager::LoadVMDCamera(setting, std::move(vmd_camera_animation)))
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
		libmmd::VMDFile vmd_file;
		if (!CMTSceneManager::SaveVMDCamera(setting, vmd_file))
		{
			log.LogOK();
			return false;
		}

		const auto vmd_path= string_util::GetStdString(setting.fn.GetString());
		if(!WriteVMDFile(&vmd_file, vmd_path.c_str()))
		{
			SaveVmdCameraLog::LogWriteFileErr();
			return false;
		}

		return true;
	}

	bool ImportVMDMotion(const CMTToolsSetting::MotionImport& setting)
	{
		LoadVmdMotionLog log;

		auto vmd_animation = std::make_unique<libmmd::VMDAnimation>();
		if (!vmd_animation)
		{
			LoadVmdMotionLog::LogOutMem();
			return false;
		}

		const auto vmd_path = string_util::GetStdString(setting.fn.GetString());
		libmmd::VMDFile vmd_file;
		if (!ReadVMDFile(&vmd_file, vmd_path.c_str()))
		{
			LoadVmdMotionLog::LogReadFileErr();
			return false;
		}

		if (!vmd_animation->Add(vmd_file))
		{
			LoadVmdMotionLog::LogNotMotionError();
			return false;
		}

		if (!CMTSceneManager::LoadVMDMotion(setting, std::move(vmd_animation), log))
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

		LoadModelLog log;

		PMXModelPtr pmx_model;
		if(setting.fn.CheckSuffix("pmx"_s))
		{
			pmx_model = std::make_shared<PMXModel>();

		}
		else
		{
			LoadModelLog::LogReadFileErr();
			return false;
		}

		if (!pmx_model)
		{
			LoadModelLog::LogOutMem();
			return false;
		}

		static auto mmd_data_filepath = GeGetPluginResourcePath() + Filename("mikumikudance_data");
		if (!GeFExist(mmd_data_filepath))
		{
			LoadModelLog::LogMMDDataPathErr();
			return false;
		}

		libmmd::PMXFile pmx_file;
		const std::string model_path = string_util::GetStdString(setting.fn.GetString());
		if (libmmd::ReadPMXFile(&pmx_file, model_path.c_str()))
		{
			LoadModelLog::LogReadFileErr();
			return false;
		}

		static std::string mmd_data_path =  string_util::GetStdString(mmd_data_filepath.GetString());
		if (const std::string model_dir = string_util::GetStdString(setting.fn.GetDirectory().GetString());
			!pmx_model->LoadPMX(pmx_file, model_dir, mmd_data_path))
		{
			LoadModelLog::LogReadFileErr();
			return false;
		}

		log.Set(pmx_model, setting);
		if (!CMTSceneManager::LoadPMXModel(pmx_file, pmx_model, setting))
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
