/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/16
File:			vmd_camera_animation.cpp
Description:	

**************************************************************************/

#include "pch.h"
#include "vmd_camera_animation.h"

VMDCameraAnimation::VMDCameraAnimation(const UInt32 frame_no, const Float32 distance, 
									   const Vector32 position, const Vector4d32 rotation,
                                       VMDCameraInterpolator interpolator_position_x,
                                       VMDCameraInterpolator interpolator_position_y,
                                       VMDCameraInterpolator interpolator_position_z,
                                       VMDCameraInterpolator interpolator_rotation,
                                       VMDCameraInterpolator interpolator_position_d,
                                       VMDCameraInterpolator interpolator_position_v) :
	VMDDataElement(frame_no),
	m_distance(distance),
	m_position(position),
	m_rotation(rotation),
	m_interpolator_position_x(std::move(interpolator_position_x)),
	m_interpolator_position_y(std::move(interpolator_position_y)),
	m_interpolator_position_z(std::move(interpolator_position_z)),
	m_interpolator_rotation  (std::move(interpolator_rotation)),
	m_interpolator_position_d(std::move(interpolator_position_d)),
	m_interpolator_position_v(std::move(interpolator_position_v)){}

VMDCameraAnimation::VMDCameraAnimation(VMDCameraAnimation&& src) noexcept :
	VMDDataElement(src.m_frame_on),
	m_distance(src.m_distance),
	m_interpolator_position_x(std::move(src.m_interpolator_position_x)),
	m_interpolator_position_y(std::move(src.m_interpolator_position_y)),
	m_interpolator_position_z(std::move(src.m_interpolator_position_z)),
	m_interpolator_rotation  (std::move(src.m_interpolator_rotation)),
	m_interpolator_position_d(std::move(src.m_interpolator_position_d)),
	m_interpolator_position_v(std::move(src.m_interpolator_position_v))
{
	memmove_s(&m_position, sizeof Vector32, &src.m_position, sizeof Vector32);
	memmove_s(&m_rotation, sizeof Vector32, &src.m_rotation, sizeof Vector32);
}

VMDCameraAnimation& VMDCameraAnimation::operator=(VMDCameraAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	m_frame_on = src.m_frame_on;
	m_distance = src.m_distance;
	memmove_s(&m_position, sizeof Vector32, &src.m_position, sizeof Vector32);
	memmove_s(&m_rotation, sizeof Vector32, &src.m_rotation, sizeof Vector32);
	m_interpolator_position_x = std::move(src.m_interpolator_position_x);
	m_interpolator_position_y = std::move(src.m_interpolator_position_y);
	m_interpolator_position_z = std::move(src.m_interpolator_position_z);
	m_interpolator_rotation   = std::move(src.m_interpolator_rotation);
	m_interpolator_position_d = std::move(src.m_interpolator_position_d);
	m_interpolator_position_v = std::move(src.m_interpolator_position_v);
	return *this;
}

Bool VMDCameraAnimation::ReadFormFile(BaseFile* file)
{
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_on))
		return FALSE;
	if (!file->ReadFloat32(&m_distance))
		return FALSE;
	if (!file->ReadVector32(&m_position))
		return FALSE;
	if (!file->ReadVector32(&m_rotation))
		return FALSE;
	if (!m_interpolator_position_x.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_y.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_z.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_rotation.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_d.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_v.ReadInterpolator(file))
		return FALSE;
	if (!file->ReadUInt32(&m_viewing_angle))
		return FALSE;
	if (!file->ReadUChar(&m_perspective))
		return FALSE;
	return TRUE;
}

Bool VMDCameraAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_on))
		return FALSE;
	if (!file->WriteFloat32(m_distance))
		return FALSE;
	if (!file->WriteVector32(m_position))
		return FALSE;
	if (!file->WriteVector32(m_rotation))
		return FALSE;
	if (!m_interpolator_position_x.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_y.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_z.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_rotation.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_d.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_v.WriteInterpolator(file))
		return FALSE;
	if (!file->WriteUInt32(m_viewing_angle))
		return FALSE;
	if (!file->WriteUChar(m_perspective))
		return FALSE;
	return TRUE;
}
