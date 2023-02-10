/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_morph_animation.cpp
Description:	MMD style expression animation

**************************************************************************/

#include "pch.h"
#include "vmd_morph.h"

Bool VMDMorphAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	Char morph_name[15] = { '\0' };
	if (!file->ReadBytes(morph_name, 15))
		return FALSE;
	if (!file->ReadUInt32(&m_frame_num))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight))
		return FALSE;
	m_data->morph_name = code_conversion::SJIStoUTF8(morph_name);
	return TRUE;
}

Bool VMDMorphAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	std::string morph_name = code_conversion::UTF8toSJIS(m_data->morph_name);
	morph_name.resize(15, '\0');
	if (!file->WriteBytes(morph_name.c_str(), 15))
		return FALSE;
	if (!file->WriteUInt32(m_frame_num))
		return FALSE;
	if (!file->WriteFloat32(m_data->weight))
		return FALSE;
	return TRUE;
}
