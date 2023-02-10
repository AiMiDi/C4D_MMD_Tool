/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_data.cpp
Description:	vmd file data

**************************************************************************/

#include "pch.h"
#include "vmd.h"


VMD::VMD(String model_name, const bool is_camera) :
m_data(std::make_unique<data_type>(std::move(is_camera? m_camera_name : model_name))), m_is_camera(is_camera){}

Bool VMD::LoadFromFile(Filename& fn)
{
	iferr_scope_handler{
#ifdef _DEBUG
		MessageDialog(err.ToString(nullptr));
#endif // _DEBUG	
		return FALSE;
	};
	AutoAlloc<BaseFile>	file;
	filename_util::SelectSuffixImportFile(fn, file, "vmd"_s);
	Char VMD_version[30]{ '\0' };
	Char VMD_model_name[20]{ '\0' };
	if (!file->ReadBytes(VMD_version, 30))
		return FALSE;
	if (!strncmp(VMD_version, R"(Vocaloid Motion Data 0002)", 25))
	{
		if (!file->ReadBytes(VMD_model_name, 20))
			return FALSE;
		m_data->model_name = code_conversion::SJIStoUTF8(VMD_model_name);
		// カメラ照明
		if (m_data->model_name.LexComparePart(m_camera_name, 12, 0) == 0)
		{
			m_is_camera = true;
		}
		else {
			m_is_camera = false;
		}
	}
	else if (!strncmp(VMD_version, R"(Vocaloid Motion Data)", 20))
	{
		if (!file->ReadBytes(VMD_model_name, 10))
			return FALSE;
		m_data->model_name = code_conversion::SJIStoUTF8(VMD_model_name);
		if (m_data->model_name.LexComparePart(m_camera_name, 12, 0) == 0)
		{
			m_is_camera = true;
		}
		else {
			m_is_camera = false;
		}
	}
	else
	{
		MessageDialog("Import failed: File corruption or unknown version"_s);
		return FALSE;
	}
	if (!m_data->motion_frames.ReadFromFile(file))
		return FALSE;
	if (!m_data->morph_frames.ReadFromFile(file))
		return FALSE;
	if (!m_data->camera_frames.ReadFromFile(file))
		return FALSE;
	if (!m_data->light_frames.ReadFromFile(file))
		return FALSE;
	if (!m_data->shadow_frames.ReadFromFile(file))
		return FALSE;
	if (!m_data->model_frames.ReadFromFile(file))
		return FALSE;
	return TRUE;
}

Bool VMD::SaveToFile(Filename& fn) const
{
	iferr_scope_handler{
#ifdef _DEBUG
		MessageDialog(err.ToString(nullptr));
#endif // _DEBUG	
		return FALSE;
	};
	AutoAlloc<BaseFile>	file;
	filename_util::SelectSuffixExportFile(fn, file, "vmd"_s);
	if (constexpr Char vmd_version[30] = R"(Vocaloid Motion Data 0002)"; !file->WriteBytes(vmd_version, 30))
		return FALSE;
	if (const std::string vmd_mode_name = code_conversion::UTF8toSJIS(m_data->model_name);
		!file->WriteBytes(vmd_mode_name.data(), 20))
		return FALSE;
	if (!m_data->motion_frames.WriteToFile(file))
		return FALSE;
	if (!m_data->morph_frames.WriteToFile(file))
		return FALSE;
	if (!m_data->camera_frames.WriteToFile(file))
		return FALSE;
	if (!m_data->light_frames.WriteToFile(file))
		return FALSE;
	if (!m_data->shadow_frames.WriteToFile(file))
		return FALSE;
	if (!m_data->model_frames.WriteToFile(file))
		return FALSE;
	return TRUE;
}
