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
		String bone_name = {},
		const Vector32				&position = {},
		const Vector4d32			&rotation = {},
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

class VMDBoneAnimation final : public VMDAnimationElement
{
	typedef VMDBoneData data_type;
	std::unique_ptr<data_type> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDBoneAnimation)
	/**
	 * \brief Default constructor function
	 */
	explicit VMDBoneAnimation() :VMDAnimationElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param bone_name The action corresponds to the bone name
	 * \param position The action corresponds to the bone position
	 * \param rotation The action corresponds to the rotation of the bone (quad)
	 * \param interpolator_position_x X-axis displacement action interpolation
	 * \param interpolator_position_y Y-axis displacement action interpolation
	 * \param interpolator_position_z Z-axis displacement action interpolation
	 * \param interpolator_rotation Rotation action interpolation
	 */
	explicit VMDBoneAnimation(
		const UInt32				&frame_num, 
		const String				&bone_name = {},
		const Vector32				&position = {},
		const Vector4d32			&rotation = {},
		const VMDBoneInterpolator	&interpolator_position_x = {},
		const VMDBoneInterpolator	&interpolator_position_y = {},
		const VMDBoneInterpolator	&interpolator_position_z = {},
		const VMDBoneInterpolator	&interpolator_rotation = {}) :
		VMDAnimationElement(frame_num), m_data(std::make_unique<data_type>(bone_name, position, rotation, interpolator_position_x, interpolator_position_y, interpolator_position_z, interpolator_rotation)) {}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param data Internal data
	 */
	explicit VMDBoneAnimation(const UInt32& frame_num, const data_type& data) : VMDAnimationElement(frame_num), m_data(std::make_unique<data_type>(data)) {}
	/**
	 * \brief Move constructor
	 */
	VMDBoneAnimation(VMDBoneAnimation&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDBoneAnimation& operator =(VMDBoneAnimation&&) noexcept = default;
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
