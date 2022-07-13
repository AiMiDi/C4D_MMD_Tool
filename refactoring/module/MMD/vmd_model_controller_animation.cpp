/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/14
File:			vmd_model_controller_animation.cpp
Description:	MMD style model information animation

**************************************************************************/

#include "pch.h"
#include "vmd_model_controller_animation.h"


inline VMDModelControllerAnimation::VMDModelControllerAnimation(const VMDModelControllerAnimation& src) :
m_frame_on(src.m_frame_on), m_show(src.m_show)
{
	m_IK_Info_array.CopyFrom(src.m_IK_Info_array) iferr_ignore();
}

inline VMDModelControllerAnimation::VMDModelControllerAnimation(VMDModelControllerAnimation&& src) noexcept:
m_frame_on(src.m_frame_on),m_show(src.m_show), m_IK_Info_array(std::move(src.m_IK_Info_array)){}

inline VMDModelControllerAnimation& VMDModelControllerAnimation::operator=(const VMDModelControllerAnimation& src)
{
	if (&src == this)
	{
		return *this;
	}
	this->m_frame_on = src.m_frame_on;
	this->m_show = src.m_show;
	this->m_IK_Info_array.CopyFrom(src.m_IK_Info_array) iferr_ignore();
	return(*this);
}

inline VMDModelControllerAnimation& VMDModelControllerAnimation::operator=(VMDModelControllerAnimation&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	this->m_frame_on = src.m_frame_on;
	this->m_show = src.m_show;
	this->m_IK_Info_array = std::move(src.m_IK_Info_array);
	return(*this);
}

Bool VMDModelControllerAnimation::ReadFormFile(BaseFile* file)
{
	iferr_scope_handler
	{
		return FALSE;
	};
	if (!file)
	{
		return FALSE;
	}
	if (!file->ReadUInt32(&m_frame_on))
		return FALSE;
	if (!file->ReadBool(&m_show))
		return FALSE;
	UInt32 ik_info_number = 0;
	if (!file->ReadUInt32(&ik_info_number))
		return FALSE;
	m_IK_Info_array.Resize(ik_info_number)iferr_return;
	for (UInt32 ik_info_index = 0; ik_info_index < ik_info_number; ++ik_info_index)
	{
		if (!m_IK_Info_array[ik_info_index].ReadFormVMDFile(file))
			return FALSE;
	}
	return TRUE;
}

Bool VMDModelControllerAnimation::WriteToFile(BaseFile* file) const
{
	iferr_scope_handler
	{
		return FALSE;
	};
	if (!file)
	{
		return false;
	}
	if (!file->WriteUInt32(m_frame_on))
		return FALSE;
	if (!file->WriteBool(m_show))
		return FALSE;
	auto ikInfoCount = static_cast<UInt32>(m_IK_Info_array.GetCount());
	if (!file->WriteUInt32(ikInfoCount))
		return FALSE;
	while (ikInfoCount--)
	{
		if (!m_IK_Info_array[ikInfoCount].WriteToVMDFile(file))
			return FALSE;
	}
	return TRUE;
}