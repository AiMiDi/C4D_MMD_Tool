/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_light_animation.cpp
Description:	MMD style lighting animation

**************************************************************************/

#include "pch.h"
#include "vmd_light_animation.h"

Bool VMDLightAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_num))
		return FALSE;
	if (!file->ReadVector32(&m_data->light_color))
		return FALSE;
	if (!file->ReadVector32(&m_data->light_position))
		return FALSE;
	return TRUE;
}

Bool VMDLightAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_num))
		return FALSE;
	if (!file->WriteVector32(m_data->light_color))
		return FALSE;
	if (!file->WriteVector32(m_data->light_position))
		return FALSE;
	return TRUE;
}
