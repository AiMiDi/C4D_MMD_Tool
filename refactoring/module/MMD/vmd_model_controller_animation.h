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

#include "vmd_data_element.h"
#include "vmd_Ik_controller_animation.h"

typedef maxon::BaseArray<VMDIkControllerAnimation> VMDIkControllerArray;

class VMDModelControllerAnimation final : public VMDDataElement
{
	// Is model show
	Bool				 m_show;
	// IKs enable information
	VMDIkControllerArray m_IK_Info_array;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDModelControllerAnimation)
	/**
	 * \brief  Constructor function
	 * \param frame_no Frame of action
	 * \param show Is model show
	 */
	explicit VMDModelControllerAnimation(const UInt32 frame_no = 0U, const Bool show = true):
	VMDDataElement(frame_no), m_show(show){}
	/**
	 * \brief Move constructor
	 */
	VMDModelControllerAnimation(VMDModelControllerAnimation&&) noexcept;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDModelControllerAnimation& operator =(VMDModelControllerAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDModelControllerAnimation() override = default;
	/**
	 * \brief Read from a vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFormFile(BaseFile* file) override;
	/**
	 * \brief Write to vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool WriteToFile(BaseFile* file) const override;
};


#endif //!_VMD_MODEL_CONTROLLER_ANIMATION_H_
