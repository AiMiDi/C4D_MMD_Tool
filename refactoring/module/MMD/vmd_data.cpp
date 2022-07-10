/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_data.cpp
Description:	vmd file data

**************************************************************************/

#include "pch.h"
#include "vmd_data.h"

VMDInterpolator::VMDInterpolator(const UChar ax, const UChar ay, const UChar bx, const UChar by): m_ax(ax), m_ay(ay), m_bx(bx), m_by(by)
{
	m_isLinear = m_ax == m_ay && m_bx == m_by;
}
Bool VMDInterpolator::IsLinear() const
{
	return m_isLinear;
}

void VMDInterpolator::SetValue(UChar ax, UChar ay, UChar bx, UChar by)
{
	this->m_ax = ax;
	this->m_ay = ay;
	this->m_bx = bx;
	this->m_by = by;
	m_isLinear = m_ax == m_ay && m_bx == m_by;
}

UChar VMDInterpolator::GetValue(const PartType& part) const
{
	switch (part)
	{
	case PartType::ax:
		{
			return this->m_ax;
		}
	case PartType::bx:
		{
			return this->m_bx;
		}
	case PartType::ay:
		{
			return this->m_ay;
		}
	case PartType::by:
		{
			return this->m_by;
		}
	default:
		return static_cast<UChar>(-1);
	}
}

Bool VMDInterpolator::ReadBoneInterpolator(BaseFile* const file)
{
	if (!file->ReadUChar(&this->m_ax))
		return false;
	file->Seek(3);
	if (!file->ReadUChar(&this->m_ay))
		return false;
	file->Seek(3);
	if (!file->ReadUChar(&this->m_bx))
		return false;
	file->Seek(3);
	if (!file->ReadUChar(&this->m_by))
		return false;
	file->Seek(3);
	m_isLinear = m_ax == m_ay && m_bx == m_by;
	return true;
}

Bool VMDInterpolator::ReadCameraInterpolator(BaseFile* const file)
{
	UInt32 tmp = 0;
	if (!file->ReadUInt32(&tmp))
		return false;
	this->m_ax = static_cast<UChar>(((tmp & 0xFF) ^ 0x80) - 0x80);
	this->m_bx = static_cast<UChar>(((tmp & 0xFF00) >> 8 ^ 0x80) - 0x80);
	this->m_ay = static_cast<UChar>(((tmp & 0xFF0000) >> 16 ^ 0x80) - 0x80);
	this->m_by = static_cast<UChar>(((tmp & 0xFF000000) >> 24 ^ 0x80) - 0x80);
	m_isLinear = m_ax == m_ay && m_bx == m_by;
	return true;
}

VMDModelControllerAnimation::VMDModelControllerAnimation(const VMDModelControllerAnimation& src)
{
	if (&src == this)
	{
		return;
	}
	this->m_frame_on = src.m_frame_on;
	this->m_show = src.m_show;
	this->m_IK_Info_array.CopyFrom(src.m_IK_Info_array) iferr_ignore();
}

VMDModelControllerAnimation::VMDModelControllerAnimation(VMDModelControllerAnimation&& src) noexcept
{
	if (&src == this)
	{
		return;
	}
	this->m_frame_on = src.m_frame_on;
	this->m_show = src.m_show;
	this->m_IK_Info_array = std::move(src.m_IK_Info_array);
}

VMDModelControllerAnimation& VMDModelControllerAnimation::operator=(const VMDModelControllerAnimation& src)
{
	if (&src == this)
	{
		return(*this);
	}
	this->m_frame_on = src.m_frame_on;
	this->m_show = src.m_show;
	this->m_IK_Info_array.CopyFrom(src.m_IK_Info_array) iferr_ignore();
	return(*this);
}

VMDModelControllerAnimation& VMDModelControllerAnimation::operator=(VMDModelControllerAnimation&& src) noexcept
{
	if (&src == this)
	{
		return(*this);
	}
	this->m_frame_on = src.m_frame_on;
	this->m_show = src.m_show;
	this->m_IK_Info_array = std::move(src.m_IK_Info_array);
	return(*this);
}
