/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/11
File:			vmd_interpolator.cpp
Description:	MMD style animation interpolator

**************************************************************************/

#include "pch.h"
#include "vmd_interpolator.h"

VMDInterpolator::VMDInterpolator(const UChar ax, const UChar ay, const UChar bx, const UChar by):
	m_ax(ax), m_ay(ay), m_bx(bx), m_by(by){}

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
	return BaseTime{ static_cast<Float>(m_ax), 127.0 };
}

Float VMDInterpolator::GetValueRight() const
{
	return static_cast<Float>(m_ay) / 127.0;
}

BaseTime VMDInterpolator::GetTimeLeft() const
{
	return BaseTime{ static_cast<Float>(m_bx - 127), 127.0 };
}

Float VMDInterpolator::GetValueLeft() const
{
	return static_cast<Float>(m_by - 127) / 127.0;
}

Vector VMDInterpolator::GetTangentRight() const
{
	return Vector{ static_cast<Float>(m_ax),static_cast<Float>(m_ay),0. };
}

Vector VMDInterpolator::GetTangentLeft() const
{
	return Vector{ static_cast<Float>(m_bx - 127),static_cast<Float>(m_by - 127),0. };
}

void VMDInterpolator::Set(const SplineData* spline)
{
	const auto* knot_a = spline->GetKnot(0);
	const auto* knot_b = spline->GetKnot(spline->GetKnotCount() - 1);
	m_ax = maxon::SafeConvert<UChar>(knot_a->vTangentRight.x);
	m_ay = maxon::SafeConvert<UChar>(knot_a->vTangentRight.y);
	m_bx = 127U - maxon::SafeConvert<UChar>(-knot_b->vTangentLeft.x);
	m_by = 127U - maxon::SafeConvert<UChar>(-knot_b->vTangentLeft.y);
}

void VMDInterpolator::Set(const UChar& ax, const UChar& ay, const UChar& bx, const UChar& by)
{
	m_ax = ax;
	m_ay = ay;
	m_bx = bx;
	m_by = by;
}

void VMDInterpolator::Reset()
{
	Set();
}

maxon::HashInt VMDInterpolator::GetHashCode() const
{
	return MAXON_HASHCODE(this->m_ax, this->m_ay, this->m_bx, this->m_by);
}

void VMDInterpolator::Load(const libmmd::vmd_interpolator& interpolator)
{
	Set(interpolator.get_ax(),
		interpolator.get_ay(),
		interpolator.get_bx(),
		interpolator.get_by());
}

void VMDInterpolator::Save(libmmd::vmd_interpolator& interpolator) const
{
	interpolator.set_ax(m_ax);
	interpolator.set_ay(m_ay);
	interpolator.set_bx(m_bx);
	interpolator.set_by(m_by);
}
