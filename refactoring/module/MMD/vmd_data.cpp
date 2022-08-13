/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_data.cpp
Description:	vmd file data

**************************************************************************/

#include "pch.h"
#include "vmd_data.h"

template <class T>
Bool VMDAnimationArray<T>::VMDAnimationSort::LessThan(const T& a, const T& b)
{
	return a < b;
}

template <class T>
Bool VMDAnimationArray<T>::VMDAnimationSort::IsEqual(const T& a, const T& b)
{
	return a == b;
}

template <class T>
Bool VMDAnimationArray<T>::ReadFormFile(BaseFile* file)
{
	UInt32 frame_number = 0;
	if (!file->ReadUInt32(&frame_number))
		return FALSE;
	iferr(this->Resize(frame_number))
		return FALSE;
	while (--frame_number)
	{
		if (T frame{}; frame.ReadFromFile(file))
		{
			iferr(this->Append(std::move(frame)))
				return FALSE;
		}
	}
	VMDAnimationSort sorter;
	sorter.Sort(*this);
	return TRUE;
}

template <class T>
Bool VMDAnimationArray<T>::WriteToFile(BaseFile* file) const
{
	auto frame_number = static_cast<UInt32>(this->GetCount());
	if (!file->WriteUInt32(frame_number))
		return FALSE;
	for (UInt32 frame_index = 0; frame_index < frame_number; ++frame_index)
	{
		(*this)[frame_number].WriteToFile(file);
	}
	return TRUE;
}

VMDAnimation::VMDAnimation(String model_name, const bool is_camera):m_model_name(std::move(model_name)), m_is_camera(is_camera)
{
	if(m_is_camera)
	{
		// カメラ・照明
		model_name = m_camera_name;
	}
}

VMDAnimation::VMDAnimation(VMDAnimation&& src) noexcept:
	m_motion_frames(std::move(src.m_motion_frames)),
	m_morph_frames(std::move(src.m_morph_frames)),
	m_camera_frames(std::move(src.m_camera_frames)),
	m_light_frames(std::move(src.m_light_frames)),
	m_shadow_frames(std::move(src.m_shadow_frames)),
	m_model_frames(std::move(src.m_model_frames))
{}

VMDAnimation& VMDAnimation::operator=(VMDAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	m_motion_frames = std::move(src.m_motion_frames);
	m_morph_frames = std::move(src.m_morph_frames);
	m_camera_frames = std::move(src.m_camera_frames);
	m_light_frames = std::move(src.m_light_frames);
	m_shadow_frames = std::move(src.m_shadow_frames);
	m_motion_frames = std::move(src.m_motion_frames);
	return *this;
}

Bool VMDAnimation::LoadFromFile(Filename& fn)
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
		m_model_name = code_conversion::SJIStoUTF8(VMD_model_name);
		// カメラ・照明
		if (m_model_name.LexComparePart(m_camera_name, 12, 0) == 0)
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
		m_model_name = code_conversion::SJIStoUTF8(VMD_model_name);
		if (m_model_name.LexComparePart(m_camera_name, 12, 0) == 0)
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
	if (!m_motion_frames.ReadFormFile(file))
		return FALSE;
	if (!m_morph_frames.ReadFormFile(file))
		return FALSE;
	if (!m_camera_frames.ReadFormFile(file))
		return FALSE;
	if (!m_light_frames.ReadFormFile(file))
		return FALSE;
	if (!m_shadow_frames.ReadFormFile(file))
		return FALSE;
	if (!m_model_frames.ReadFormFile(file))
		return FALSE;
	return TRUE;
}

Bool VMDAnimation::SaveToFile(Filename& fn) const
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
	if (const std::string vmd_mode_name = code_conversion::UTF8toSJIS(m_model_name); 
		!file->WriteBytes(vmd_mode_name.data(), 20))
		return FALSE;
	if (!m_motion_frames.WriteToFile(file))
		return FALSE;
	if (!m_morph_frames.WriteToFile(file))
		return FALSE;
	if (!m_camera_frames.WriteToFile(file))
		return FALSE;
	if (!m_light_frames.WriteToFile(file))
		return FALSE;
	if (!m_shadow_frames.WriteToFile(file))
		return FALSE;
	if (!m_model_frames.WriteToFile(file))
		return FALSE;
	return TRUE;
}
