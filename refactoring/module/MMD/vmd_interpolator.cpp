/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/11
File:			vmd_interpolator.cpp
Description:	MMD style animation interpolator

**************************************************************************/

#include "pch.h"
#include "vmd_interpolator.h"

VMDInterpolator::VMDInterpolator(const UChar ax, const UChar ay, const UChar bx, const UChar by):
	m_ax(ax), m_ay(ay), m_bx(bx), m_by(by)
{
	m_isLinear = m_ax == m_ay && m_bx == m_by;
}

VMDInterpolator::VMDInterpolator(VMDInterpolator&& src) noexcept
{
	memmove_s(this, sizeof VMDInterpolator, &src, sizeof VMDInterpolator);
}

VMDInterpolator& VMDInterpolator::operator=(VMDInterpolator&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	memmove_s(this, sizeof VMDInterpolator, &src, sizeof VMDInterpolator);
	return *this;
}

BaseTime VMDInterpolator::GetTimeRight() const
{
	return BaseTime{ static_cast<Float>(m_ax) / 127.0,127.0 };
}

Float VMDInterpolator::GetValueRight() const
{
	return static_cast<Float>(m_ay) / 127.0;
}

BaseTime VMDInterpolator::GetTimeLeft() const
{
	return BaseTime{ static_cast<Float>(m_bx - 127) / 127.0,127.0 };
}

Float VMDInterpolator::GetValueLeft() const
{
	return static_cast<Float>(m_by - 127)/127.0;
}

void VMDInterpolator::SetInterpolator(const SplineData* spline)
{
	m_ax = maxon::SafeConvert<UChar>(spline->GetKnot(0)->vTangentRight.x);
	m_ay = maxon::SafeConvert<UChar>(spline->GetKnot(0)->vTangentRight.y);
	m_bx = 127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x);
	m_by = 127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y);
}

Bool VMDInterpolator::IsLinear() const
{
	return m_isLinear;
}

maxon::HashInt VMDInterpolator::GetHashCode() const
{
	return MAXON_HASHCODE(this->m_ax, this->m_ay, this->m_bx, this->m_by);
}

Bool VMDBoneInterpolator::ReadInterpolator(BaseFile* const file)
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

Bool VMDBoneInterpolator::WriteInterpolator(BaseFile* const file) const
{
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	return true;
}

Bool VMDCameraInterpolator::ReadInterpolator(BaseFile* const file)
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

Bool VMDCameraInterpolator::WriteInterpolator(BaseFile* const file) const
{
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	return true;
}