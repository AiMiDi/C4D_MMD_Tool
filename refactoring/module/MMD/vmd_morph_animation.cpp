/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_morph_animation.cpp
Description:	MMD style expression animation

**************************************************************************/

#include "pch.h"
#include "vmd_morph_animation.h"

VMDMorphAnimation::VMDMorphAnimation(const UInt32 frame_on, String morph_name, const Float32 weight):
	VMDDataElement(frame_on), m_morph_name(std::move(morph_name)), m_weight(weight)
{}

VMDMorphAnimation::VMDMorphAnimation(VMDMorphAnimation&& src) noexcept : VMDDataElement(src.m_frame_on), m_morph_name(std::move(src.m_morph_name)), m_weight(src.m_weight) {}

VMDMorphAnimation& VMDMorphAnimation::operator=(VMDMorphAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	m_frame_on =src.m_frame_on;
	m_morph_name = std::move(src.m_morph_name);
	m_weight = src.m_weight;
	return *this;
}

Bool VMDMorphAnimation::ReadFormFile(BaseFile* file)
{
	assert(file != nullptr);
	Char morph_name[15] = { '\0' };
	if (!file->ReadBytes(morph_name, 15))
		return FALSE;
	if (!file->ReadUInt32(&m_frame_on))
		return FALSE;
	if (!file->ReadFloat32(&m_weight))
		return FALSE;
	m_morph_name = code_conversion::SJIStoUTF8(morph_name);
	return TRUE;
}

Bool VMDMorphAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	std::string morph_name = code_conversion::UTF8toSJIS(m_morph_name);
	morph_name.resize(15, '\0');
	if (!file->WriteBytes(morph_name.c_str(), 15))
		return FALSE;
	if (!file->WriteUInt32(m_frame_on))
		return FALSE;
	if (!file->WriteFloat32(m_weight))
		return FALSE;
	return TRUE;
}
