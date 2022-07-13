/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/11
File:			vmd_interpolator.h
Description:	MMD style animation interpolator

**************************************************************************/
#ifndef VMD_INTERPOLATOR_H_
#define VMD_INTERPOLATOR_H_

#include "pch.h"

class VMDInterpolator
{
	UChar m_ax, m_ay, m_bx, m_by;
	Bool m_isLinear;
public:
	/* Partial types of interpolator data */
	enum class PartType { ax, ay, bx, by };
	/* Constructor function */
	explicit VMDInterpolator(const UChar ax = 20U, const UChar ay = 20U, const UChar bx = 107U, const UChar by = 107U) :
		m_ax(ax), m_ay(ay), m_bx(bx), m_by(by)
	{
		m_isLinear = m_ax == m_ay && m_bx == m_by;
	}
	~VMDInterpolator() = default;
	VMDInterpolator(const VMDInterpolator&) noexcept = default;
	VMDInterpolator(VMDInterpolator&&) noexcept = default;
	[[nodiscard]] Bool IsLinear() const
	{
		return m_isLinear;
	}
	/* Sets the value of the interpolator. If the parameter is empty, set the default value. */
	void SetValue(UChar ax = 20U, UChar ay = 20U, UChar bx = 107U, UChar by = 107U)
	{
		this->m_ax = ax;
		this->m_ay = ay;
		this->m_bx = bx;
		this->m_by = by;
		m_isLinear = m_ax == m_ay && m_bx == m_by;
	}
	/* Gets the interpolator value. */
	[[nodiscard]] UChar GetValue(const PartType& part) const;
	/* Hash function */
	[[nodiscard]] maxon::HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(this->m_ax, this->m_ay, this->m_bx, this->m_by);
	}
	/* Read bone interpolator information from a file */
	Bool ReadBoneInterpolator(BaseFile* file);
	/* Read the camera interpolator information from the file. */
	Bool ReadCameraInterpolator(BaseFile* file);
	/* Write the bone interpolator information to the file. */
	Bool WriteBoneInterpolator(BaseFile* file) const;
	/* Write the camera interpolator information to the file. */
	Bool WriteCameraInterpolator(BaseFile* file) const;
};



#endif //!VMD_INTERPOLATOR_H_
