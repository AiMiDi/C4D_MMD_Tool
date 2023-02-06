/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/16
File:			vmd_camera_animation.cpp
Description:	

**************************************************************************/

#include "pch.h"
#include "vmd_camera.h"

Bool VMDCameraAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_num))
		return FALSE;
	if (!file->ReadFloat32(&m_data->m_distance))
		return FALSE;
	if (!file->ReadVector32(&m_data->m_position))
		return FALSE;
	if (!file->ReadVector32(&m_data->m_rotation))
		return FALSE;
	if (!m_data->m_interpolator_position_x.Read(file))
		return FALSE;
	if (!m_data->m_interpolator_position_y.Read(file))
		return FALSE;
	if (!m_data->m_interpolator_position_z.Read(file))
		return FALSE;
	if (!m_data->m_interpolator_rotation.Read(file))
		return FALSE;
	if (!m_data->m_interpolator_position_d.Read(file))
		return FALSE;
	if (!m_data->m_interpolator_position_v.Read(file))
		return FALSE;
	if (!file->ReadUInt32(&m_data->m_viewing_angle))
		return FALSE;
	if (!file->ReadUChar(&m_data->m_perspective))
		return FALSE;
	return TRUE;
}

Bool VMDCameraAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_num))
		return FALSE;
	if (!file->WriteFloat32(m_data->m_distance))
		return FALSE;
	if (!file->WriteVector32(m_data->m_position))
		return FALSE;
	if (!file->WriteVector32(m_data->m_rotation))
		return FALSE;
	if (!m_data->m_interpolator_position_x.Write(file))
		return FALSE;
	if (!m_data->m_interpolator_position_y.Write(file))
		return FALSE;
	if (!m_data->m_interpolator_position_z.Write(file))
		return FALSE;
	if (!m_data->m_interpolator_rotation.Write(file))
		return FALSE;
	if (!m_data->m_interpolator_position_d.Write(file))
		return FALSE;
	if (!m_data->m_interpolator_position_v.Write(file))
		return FALSE;
	if (!file->WriteUInt32(m_data->m_viewing_angle))
		return FALSE;
	if (!file->WriteUChar(m_data->m_perspective))
		return FALSE;
	return TRUE;
}
