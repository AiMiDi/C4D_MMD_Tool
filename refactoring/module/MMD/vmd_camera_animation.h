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

/* MMD风格的摄像机动画 */
class VMDCameraAnimation final : public VMDDataElement
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
	VMDCameraInterpolator m_interpolator_rotation	 {};
	// Distance action interpolation
	VMDCameraInterpolator m_interpolator_position_d{};
	// View Angle motion interpolation
	VMDCameraInterpolator m_interpolator_position_v{};
	// View Angle
	UInt32		m_viewing_angle = 0U;
	// 0:on, 1:off
	UChar		m_perspective = 0U;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDCameraAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDCameraAnimation(
		UInt32		frame_no = 0U,
		Float32		distance = 0.f,
		Vector32	position = {},
		Vector4d32	rotation = {},
		VMDCameraInterpolator interpolator_position_x = {},
		VMDCameraInterpolator interpolator_position_y = {},
		VMDCameraInterpolator interpolator_position_z = {},
		VMDCameraInterpolator interpolator_rotation = {},
		VMDCameraInterpolator interpolator_position_d = {},
		VMDCameraInterpolator interpolator_position_v = {});

	/**
	 * \brief Move constructor
	 */
	VMDCameraAnimation(VMDCameraAnimation&&) noexcept;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDCameraAnimation& operator =(VMDCameraAnimation&&) noexcept;
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
