/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/16
File:			vmd_bone_animation.cpp
Description:	MMD style bone animation

**************************************************************************/

#include "pch.h"
#include "vmd_bone_animation.h"

VMDBoneAnimation::VMDBoneAnimation(
	String bone_name, 
	const UInt32 frame_no,
	const Vector32 position,
	const Vector4d32 rotation,
	VMDBoneInterpolator interpolator_position_x,
	VMDBoneInterpolator interpolator_position_y,
	VMDBoneInterpolator interpolator_position_z,
	VMDBoneInterpolator interpolator_rotation):
	VMDDataElement(frame_no),
	m_bone_name(std::move(bone_name)),
	m_position(position),
	m_rotation(rotation),
	m_interpolator_position_x(std::move(interpolator_position_x)),
	m_interpolator_position_y(std::move(interpolator_position_y)),
	m_interpolator_position_z(std::move(interpolator_position_z)),
	m_interpolator_rotation(std::move(interpolator_rotation))
{}

VMDBoneAnimation::VMDBoneAnimation(VMDBoneAnimation&& src) noexcept :
	VMDDataElement(src.m_frame_on),
	m_bone_name(std::move(src.m_bone_name)),
	m_interpolator_position_x(std::move(src.m_interpolator_position_x)),
	m_interpolator_position_y(std::move(src.m_interpolator_position_y)),
	m_interpolator_position_z(std::move(src.m_interpolator_position_z)),
	m_interpolator_rotation(std::move(src.m_interpolator_rotation))
{
	memmove_s(&m_position, sizeof Vector32, &src.m_position, sizeof Vector32);
	memmove_s(&m_rotation, sizeof Vector32, &src.m_rotation, sizeof Vector32);
}

VMDBoneAnimation& VMDBoneAnimation::operator=(VMDBoneAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	m_bone_name = std::move(src.m_bone_name);
	m_frame_on = src.m_frame_on;
	memmove_s(&m_position, sizeof Vector32, &src.m_position, sizeof Vector32);
	memmove_s(&m_rotation, sizeof Vector32, &src.m_rotation, sizeof Vector32);
	m_interpolator_position_x = std::move(src.m_interpolator_position_x);
	m_interpolator_position_y = std::move(src.m_interpolator_position_y);
	m_interpolator_position_z = std::move(src.m_interpolator_position_z);
	m_interpolator_rotation = std::move(src.m_interpolator_rotation);
	return *this;
}

Bool VMDBoneAnimation::ReadFromFile(BaseFile* file)
{
	assert(file != nullptr);
	Char bone_name[15]{ 0 };
	if (!file->ReadBytes(bone_name, 15))
		return FALSE;
	m_bone_name = code_conversion::SJIStoUTF8(bone_name);
	if (!file->ReadUInt32(&m_frame_on))
		return FALSE;
	if (!file->ReadVector32(&m_position))
		return FALSE;
	static_assert(sizeof Vector4d32 == 16);
	if (!file->ReadBytes(&m_rotation, sizeof Vector4d32))
		return FALSE;
	if (!m_interpolator_position_x.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_y.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_z.ReadInterpolator(file))
		return FALSE;
	if (!m_interpolator_rotation.ReadInterpolator(file))
		return FALSE;
	return TRUE;
}

Bool VMDBoneAnimation::WriteToFile(BaseFile* file) const
{
	assert(file != nullptr);
	std::string bone_name = code_conversion::UTF8toSJIS(m_bone_name);
	bone_name.resize(15, '\0');
	if (!file->WriteBytes(bone_name.data(), 15))
		return FALSE;
	if (!file->WriteUInt32(m_frame_on))
		return FALSE;
	if (!file->WriteVector32(m_position))
		return FALSE;
	static_assert(sizeof Vector4d32 == 16);
	if (!file->WriteBytes(&m_rotation, sizeof Vector4d32))
		return FALSE;
	if (!m_interpolator_position_x.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_y.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_position_z.WriteInterpolator(file))
		return FALSE;
	if (!m_interpolator_rotation.WriteInterpolator(file))
		return FALSE;
	return TRUE;
}
