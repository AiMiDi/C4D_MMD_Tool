/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_shadow_animation.cpp
Description:	MMD style shadow animation

**************************************************************************/

#include "pch.h"
#include "vmd_shadow_animation.h"

VMDShadowAnimation::VMDShadowAnimation(VMDShadowAnimation&& src) noexcept : VMDDataElement(src.m_frame_on)
{
	memmove_s(&m_shadow_type, sizeof UChar, &src.m_shadow_type, sizeof UChar);
	memmove_s(&m_distance, sizeof Float32, &src.m_distance, sizeof Float32);
}

VMDShadowAnimation& VMDShadowAnimation::operator=(VMDShadowAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	m_frame_on = src.m_frame_on;
	memmove_s(&m_shadow_type, sizeof UChar, &src.m_shadow_type, sizeof UChar);
	memmove_s(&m_distance, sizeof Float32, &src.m_distance, sizeof Float32);
	return *this;
}

Bool VMDShadowAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_on))
		return FALSE;
	if (!file->ReadUChar(&m_shadow_type))
		return FALSE;
	if (!file->ReadFloat32(&m_distance))
		return FALSE;
	return TRUE;
}

Bool VMDShadowAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_on))
		return FALSE;
	if (!file->WriteUChar(m_shadow_type))
		return FALSE;
	if (!file->WriteFloat32(m_distance))
		return FALSE;
	return TRUE;
}
