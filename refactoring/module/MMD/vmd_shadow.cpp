/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_shadow_animation.cpp
Description:	MMD style shadow animation

**************************************************************************/

#include "pch.h"
#include "vmd_shadow.h"

Bool VMDShadow::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_num))
		return FALSE;
	if (!file->ReadUChar(&m_data->shadow_type))
		return FALSE;
	if (!file->ReadFloat32(&m_data->distance))
		return FALSE;
	return TRUE;
}

Bool VMDShadow::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_num))
		return FALSE;
	if (!file->WriteUChar(m_data->shadow_type))
		return FALSE;
	if (!file->WriteFloat32(m_data->distance))
		return FALSE;
	return TRUE;
}
