/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/16
File:			vmd_bone_animation.h
Description:	MMD style bone animation

**************************************************************************/

#ifndef _VMD_BONE_ANIMATION_H_
#define _VMD_BONE_ANIMATION_H_

#include "pch.h"

#include "vmd_data_element.h"
#include "vmd_interpolator.h"

class VMDBoneAnimation final : public VMDAnimationElement
{
	// The action corresponds to the bone name
	String			m_bone_name;
	// The action corresponds to the bone position
	Vector32		m_position;
	// The action corresponds to the rotation of the bone (quad)
	Vector4d32		m_rotation;
	// X-axis displacement action interpolation
	VMDBoneInterpolator m_interpolator_position_x;
	// Y-axis displacement action interpolation
	VMDBoneInterpolator m_interpolator_position_y;
	// Z-axis displacement action interpolation
	VMDBoneInterpolator m_interpolator_position_z;
	// Rotation action interpolation
	VMDBoneInterpolator m_interpolator_rotation;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDBoneAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDBoneAnimation(
		String		bone_name = {},
		UInt32		frame_no = 0U,
		Vector32	position = {},
		Vector4d32	rotation = {},
		VMDBoneInterpolator interpolator_position_x = {},
		VMDBoneInterpolator interpolator_position_y = {},
		VMDBoneInterpolator interpolator_position_z = {},
		VMDBoneInterpolator interpolator_rotation = {});
	/**
	 * \brief Move constructor
	 */
	VMDBoneAnimation(VMDBoneAnimation&&) noexcept;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDBoneAnimation& operator =(VMDBoneAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDBoneAnimation() override = default;
	/**
	 * \brief Read from a vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
	/**
	 * \brief Write to vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool WriteToFile(BaseFile* file) const override;
};

#endif // !_VMD_BONE_ANIMATION_H_
