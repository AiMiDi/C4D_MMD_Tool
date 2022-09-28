/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/16
File:			vmd_bone_animation.cpp
Description:	MMD style bone animation

**************************************************************************/

#include "pch.h"
#include "vmd_bone.h"



Bool VMDBoneAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	Char bone_name[15]{ 0 };
	if (!file->ReadBytes(bone_name, 15))
		return FALSE;
	m_data->m_bone_name = code_conversion::SJIStoUTF8(bone_name);
	if (!file->ReadUInt32(&m_frame_num))
		return FALSE;
	if (!file->ReadVector32(&m_data->m_position))
		return FALSE;
	static_assert(sizeof Vector4d32 == 16);
	if (!file->ReadBytes(&m_data->m_rotation, sizeof Vector4d32))
		return FALSE;
	if (!m_data->m_interpolator_position_x.ReadInterpolator(file))
		return FALSE;
	if (!m_data->m_interpolator_position_y.ReadInterpolator(file))
		return FALSE;
	if (!m_data->m_interpolator_position_z.ReadInterpolator(file))
		return FALSE;
	if (!m_data->m_interpolator_rotation.ReadInterpolator(file))
		return FALSE;
	return TRUE;
}

Bool VMDBoneAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	std::string bone_name = code_conversion::UTF8toSJIS(m_data->m_bone_name);
	bone_name.resize(15, '\0');
	if (!file->WriteBytes(bone_name.data(), 15))
		return FALSE;
	if (!file->WriteUInt32(m_frame_num))
		return FALSE;
	if (!file->WriteVector32(m_data->m_position))
		return FALSE;
	static_assert(sizeof Vector4d32 == 16);
	if (!file->WriteBytes(&m_data->m_rotation, sizeof Vector4d32))
		return FALSE;
	if (!m_data->m_interpolator_position_x.WriteInterpolator(file))
		return FALSE;
	if (!m_data->m_interpolator_position_y.WriteInterpolator(file))
		return FALSE;
	if (!m_data->m_interpolator_position_z.WriteInterpolator(file))
		return FALSE;
	if (!m_data->m_interpolator_rotation.WriteInterpolator(file))
		return FALSE;
	return TRUE;
}
