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
#include "utils/filename_util.hpp"

#include <set>

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

		std::vector<uint8_t> file_data;
		if (!filename_util::ReadFileData(setting.fn, file_data))
		{
			LoadVmdCameraLog::LogReadFileErr();
			return false;
		}

		libmmd::VMDFile vmd_file;
		if (!ReadVMDFile(&vmd_file, file_data.data(), file_data.size()))
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

		std::vector<uint8_t> file_data;
		if (!filename_util::ReadFileData(setting.fn, file_data))
		{
			LoadVmdMotionLog::LogReadFileErr();
			return false;
		}

		libmmd::VMDFile vmd_file;
		if (!ReadVMDFile(&vmd_file, file_data.data(), file_data.size()))
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
		SaveVmdMotionLog logger;

		libmmd::VMDFile vmd_file;
		if (!CMTSceneManager::SaveVMDMotion(setting, vmd_file, logger))
		{
			return false;
		}

		const auto vmd_path = string_util::GetStdString(setting.fn.GetString());
		if (!WriteVMDFile(&vmd_file, vmd_path.c_str()))
		{
			SaveVmdMotionLog::LogWriteFileErr();
			return false;
		}

		std::set<std::string> bone_names;
		for (const auto& m : vmd_file.m_motions)
			bone_names.insert(m.m_boneName.ToString());
		std::set<std::string> morph_names;
		for (const auto& m : vmd_file.m_morphs)
			morph_names.insert(m.m_blendShapeName.ToString());
		logger.exported_bone_count = bone_names.size();
		logger.exported_morph_count = morph_names.size();
		logger.exported_frame_count = vmd_file.m_motions.size() + vmd_file.m_morphs.size();

		logger.LogOK();
		return true;
	}

	bool ImportPMXModel(const CMTToolsSetting::ModelImport& setting)
	{
		LoadModelLog logger;

		if (!setting.fn.CheckSuffix("pmx"_s))
		{
			LoadModelLog::LogReadFileErr();
			return false;
		}

		std::vector<uint8_t> file_data;
		if (!filename_util::ReadFileData(setting.fn, file_data))
		{
			GePrint(FormatString("Failed to read PMX file: @", setting.fn.GetString()));
			LoadModelLog::LogReadFileErr();
			return false;
		}

		libmmd::PMXFile pmx_file;
		std::string parse_error;
		if (!libmmd::ReadPMXFile(&pmx_file, file_data.data(), file_data.size(), &parse_error))
		{
			GePrint(FormatString("PMX parse failed: @", String(parse_error.c_str())));
			LoadModelLog::LogReadFileErr();
			return false;
		}

		logger.Set(pmx_file, setting);
		if (!CMTSceneManager::LoadPMXModel(pmx_file, setting))
		{
			return false;
		}
		logger.LogOK();

		return true;
	}

	bool ExportPMXModel(const CMTToolsSetting::ModelExport& setting)
	{
		SavePmxModelLog logger;

		libmmd::PMXFile pmx_file;
		if (CMTSceneManager::SavePMXModel(setting, pmx_file) == nullptr)
			return false;

		logger.Set(pmx_file, setting);
		const auto pmx_path = string_util::GetStdString(setting.fn.GetString());
		if (!WritePMXFile(&pmx_file, pmx_path.c_str()))
		{
			IOLog::LogWriteFileErr();
			return false;
		}

		logger.LogOK();
		return true;
	}
}
