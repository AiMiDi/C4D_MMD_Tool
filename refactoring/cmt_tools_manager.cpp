/**************************************************************************

Copyright:Copyright(c) 2023-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/7/28
File:			cmt_tools_manager.cpp
Description:	tools manager

**************************************************************************/


#include "cmt_tools_manager.h"
#include "CMTSceneManager.h"
#include "module/ui/cmt_name_conversion_dialog.h"
#include "utils/string_util.hpp"

namespace CMTToolsManager
{
	bool ImportVMDCamera(const CMTToolsSetting::CameraImport& setting)
	{
		LoadVmdCameraLog logger;

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

		logger.camera_frame_number = vmd_camera_animation->GetKeyCount();
		if (!CMTSceneManager::LoadVMDCamera(setting, std::move(vmd_camera_animation)))
		{
			return false;
		}
		logger.LogOK();

		return true;
	}

	bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
	{
		if (ConversionVmdCameraLog logger; CMTSceneManager::ConversionCamera(setting))
		{
			logger.LogOK();
			return true;
		}
		return false;
	}

	bool ExportVMDCamera(const CMTToolsSetting::CameraExport& setting)
	{
		libmmd::VMDFile vmd_file;
		if (SaveVmdCameraLog logger; !CMTSceneManager::SaveVMDCamera(setting, vmd_file))
		{
			logger.LogOK();
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

	bool ImportVMDMotion(const CMTToolsSetting::MotionImport& setting, BaseObject* select_object)
	{
		LoadVmdMotionLog logger;

		const auto vmd_path = string_util::GetStdString(setting.fn.GetString());
		libmmd::VMDFile vmd_file;
		if (!ReadVMDFile(&vmd_file, vmd_path.c_str()))
		{
			LoadVmdMotionLog::LogReadFileErr();
			return false;
		}

		if (!CMTSceneManager::LoadVMDMotion(setting, vmd_file, logger, select_object))
		{
			return false;
		}

		logger.LogOK(setting.detail_report);

		return true;
	}

	bool ExportVMDMotion(const CMTToolsSetting::MotionExport& setting)
	{
		return true;
	}

	bool ImportPMXModel(const CMTToolsSetting::ModelImport& setting)
	{
		LoadModelLog logger;

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

		static auto mmd_data_filepath = GeGetPluginResourcePath() + Filename("\\mikumikudance_data");
		if (!GeFExist(mmd_data_filepath, true))
		{
			LoadModelLog::LogMMDDataPathErr();
			return false;
		}

		libmmd::PMXFile pmx_file;
		const std::string model_path = string_util::GetStdString(setting.fn.GetString());
		if (!libmmd::ReadPMXFile(&pmx_file, model_path.c_str()))
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

		logger.Set(pmx_model, pmx_file, setting);
		if (!CMTSceneManager::LoadPMXModel(pmx_file, pmx_model, setting))
		{
			return false;
		}
		logger.LogOK();

		return true;
	}

	bool ExportPMXModel(const CMTToolsSetting::ModelExport& setting)
	{
		return true;
	}
}
