/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/14
File:			vmd_model_controller_animation.h
Description:	MMD style model information animation

**************************************************************************/

#ifndef _VMD_MODEL_CONTROLLER_ANIMATION_H_
#define _VMD_MODEL_CONTROLLER_ANIMATION_H_

#include "pch.h"
#include "vmd_Ik_controller_animation.h"

typedef maxon::BaseArray<VMDIkControllerAnimation> VMDIkControllerArray;

struct VMDModelControllerAnimation
{
	// Frame of action
	UInt32				 m_frame_on;
	// Is model show
	Bool				 m_show;
	// IKs enable information
	VMDIkControllerArray m_IK_Info_array;

	/**
	 * \brief  Constructor function
	 * \param IK_Info_array IKs enable information
	 * \param frame_no Frame of action
	 * \param show Is model show
	 */
	explicit VMDModelControllerAnimation(VMDIkControllerArray&& IK_Info_array,const UInt32 frame_no = 0, const Bool show = true):
	m_frame_on(frame_no), m_show(show), m_IK_Info_array(std::move(IK_Info_array)) {}
	/**
	 * \brief Copy constructor
	 */
	VMDModelControllerAnimation(const VMDModelControllerAnimation&);
	/**
	 * \brief Move constructor
	 */
	VMDModelControllerAnimation(VMDModelControllerAnimation&&) noexcept;
	/**
	 * \brief Copy operator=
	 * \return Result reference
	 */
	VMDModelControllerAnimation& operator =(const VMDModelControllerAnimation&);
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDModelControllerAnimation& operator =(VMDModelControllerAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDModelControllerAnimation() = default;
	/**
	 * \brief Read from a vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFormFile(BaseFile* file);
	/**
	 * \brief Write to vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool WriteToFile(BaseFile* file) const;
};


#endif //!_VMD_MODEL_CONTROLLER_ANIMATION_H_
