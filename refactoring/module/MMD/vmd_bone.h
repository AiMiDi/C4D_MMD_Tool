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

#include "vmd_element.hpp"
#include "vmd_interpolator.h"

struct VMDBoneData
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

	/**
	 * \brief Constructor function
	 * \param bone_name The action corresponds to the bone name
	 * \param position The action corresponds to the bone position
	 * \param rotation The action corresponds to the rotation of the bone (quad)
	 * \param interpolator_position_x X-axis displacement action interpolation
	 * \param interpolator_position_y Y-axis displacement action interpolation
	 * \param interpolator_position_z Z-axis displacement action interpolation
	 * \param interpolator_rotation Rotation action interpolation
	 */
	explicit VMDBoneData(
		String				bone_name = {},
		const Vector32&		position = {},
		const Vector4d32&	rotation = {},
		VMDBoneInterpolator interpolator_position_x = {},
		VMDBoneInterpolator interpolator_position_y = {},
		VMDBoneInterpolator interpolator_position_z = {},
		VMDBoneInterpolator interpolator_rotation = {}) :
		m_bone_name(std::move(bone_name)),
		m_position(position),
		m_rotation(rotation),
		m_interpolator_position_x(std::move(interpolator_position_x)),
		m_interpolator_position_y(std::move(interpolator_position_y)),
		m_interpolator_position_z(std::move(interpolator_position_z)),
		m_interpolator_rotation(std::move(interpolator_rotation)) {}
};

class VMDBoneAnimation final : public VMDElement
{
	GENERATE_MMD_CLASS_BODY(VMDBoneAnimation, VMDBoneData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit VMDBoneAnimation() : VMDElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param data Internal data unique_ptr
	 */
	explicit VMDBoneAnimation(const UInt32& frame_num, std::unique_ptr<data_type> data = std::make_unique<data_type>()) : VMDElement(frame_num), m_data(std::move(data)) {}
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
