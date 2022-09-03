/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/16
File:			vmd_camera_animation.h
Description:	

**************************************************************************/

#ifndef _VMD_CAMERA_ANIMATION_H_
#define _VMD_CAMERA_ANIMATION_H_

#include "pch.h"

#include "vmd_data_element.h"
#include "vmd_interpolator.h"

struct VMDcameraData
{
	// Camera view distance
	Float32		m_distance = 0.f;
	// View position of the camera
	Vector32	m_position{};
	// Camera view rotation (Euler Angle of x and Y reversal)
	Vector32	m_rotation{};
	//  X-axis displacement action interpolation
	VMDCameraInterpolator m_interpolator_position_x{};
	// Y-axis displacement action interpolation
	VMDCameraInterpolator m_interpolator_position_y{};
	// Z-axis displacement action interpolation
	VMDCameraInterpolator m_interpolator_position_z{};
	// Rotation action interpolation
	VMDCameraInterpolator m_interpolator_rotation{};
	// Distance action interpolation
	VMDCameraInterpolator m_interpolator_position_d{};
	// View Angle motion interpolation
	VMDCameraInterpolator m_interpolator_position_v{};
	// View Angle
	UInt32		m_viewing_angle = 0U;
	// 0:on, 1:off
	UChar		m_perspective = 0U;


	explicit VMDcameraData(
		const Float32& distance = 0.f,
		const Vector32& position = {},
		const Vector4d32& rotation = {},
		const VMDCameraInterpolator& interpolator_position_x = {},
		const VMDCameraInterpolator& interpolator_position_y = {},
		const VMDCameraInterpolator& interpolator_position_z = {},
		const VMDCameraInterpolator& interpolator_rotation = {},
		const VMDCameraInterpolator& interpolator_position_d = {},
		const VMDCameraInterpolator& interpolator_position_v = {}) :
		m_distance(distance),
		m_position(position),
		m_rotation(rotation),
		m_interpolator_position_x(interpolator_position_x),
		m_interpolator_position_y(interpolator_position_y),
		m_interpolator_position_z(interpolator_position_z),
		m_interpolator_rotation(interpolator_rotation),
		m_interpolator_position_d(interpolator_position_d),
		m_interpolator_position_v(interpolator_position_v) {}
};

/* MMD风格的摄像机动画 */
class VMDCameraAnimation final : public VMDAnimationElement
{
	typedef VMDcameraData data_type;
	std::unique_ptr<data_type> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDCameraAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDCameraAnimation() : VMDAnimationElement(), m_data(std::make_unique<data_type>()) {}

	explicit VMDCameraAnimation(
		const UInt32& frame_no,
		const Float32& distance = 0.f,
		const Vector32& position = {},
		const Vector4d32& rotation = {},
		const VMDCameraInterpolator& interpolator_position_x = {},
		const VMDCameraInterpolator& interpolator_position_y = {},
		const VMDCameraInterpolator& interpolator_position_z = {},
		const VMDCameraInterpolator& interpolator_rotation = {},
		const VMDCameraInterpolator& interpolator_position_d = {},
		const VMDCameraInterpolator& interpolator_position_v = {}) :
		VMDAnimationElement(frame_no),
		m_data(std::make_unique<data_type>(distance, position, rotation, interpolator_position_x, interpolator_position_y, interpolator_position_z, interpolator_rotation, interpolator_position_d, interpolator_position_v)) {}

	explicit VMDCameraAnimation(const UInt32& frame_no, const data_type& data) : VMDAnimationElement(frame_no), m_data(std::make_unique<data_type>(data)) {}

	/**
	 * \brief Move constructor
	 */
	VMDCameraAnimation(VMDCameraAnimation&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDCameraAnimation& operator =(VMDCameraAnimation&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDCameraAnimation() override = default;
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

#endif // !_VMD_CAMERA_ANIMATION_H_
