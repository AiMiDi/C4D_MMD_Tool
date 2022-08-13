/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_light_animation.cpp
Description:	MMD style lighting animation

**************************************************************************/

#include "pch.h"
#include "vmd_light_animation.h"

VMDLightAnimation::VMDLightAnimation(const UInt32 frame_no, const Vector32 rgb, const Vector32 position):
	VMDDataElement(frame_no), m_rgb(rgb), m_position(position)
{}

VMDLightAnimation::VMDLightAnimation(VMDLightAnimation&& src) noexcept:VMDDataElement(src.m_frame_on)
{
	memmove_s(&m_rgb, sizeof Vector32, &src.m_rgb, sizeof Vector32);
	memmove_s(&m_position, sizeof Vector32, &src.m_position, sizeof Vector32);
}

VMDLightAnimation& VMDLightAnimation::operator=(VMDLightAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	m_frame_on = src.m_frame_on;
	memmove_s(&m_rgb, sizeof Vector32, &src.m_rgb, sizeof Vector32);
	memmove_s(&m_position, sizeof Vector32, &src.m_position, sizeof Vector32);
	return *this;
}

Bool VMDLightAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_on))
		return FALSE;
	if (!file->ReadVector32(&m_rgb))
		return FALSE;
	if (!file->ReadVector32(&m_position))
		return FALSE;
	return TRUE;
}

Bool VMDLightAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_on))
		return FALSE;
	if (!file->WriteVector32(m_rgb))
		return FALSE;
	if (!file->WriteVector32(m_position))
		return FALSE;
	return TRUE;
}
