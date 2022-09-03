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

struct VMDModelControllerData
{
	// Is model show
	Bool				 show;
	// IKs enable information
	VMDIkControllerArray IK_Info_array;


	explicit VMDModelControllerData(const Bool& show = true):
		show(show){}
};

class VMDModelControllerAnimation final : public VMDAnimationElement
{
	std::unique_ptr<VMDModelControllerData> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDModelControllerAnimation)
	/**
	 * \brief  Constructor function
	 * \param frame_no Frame of action
	 * \param show Is model show
	 */
	explicit VMDModelControllerAnimation(const UInt32& frame_no = 0U, const Bool& show = true) :
	VMDAnimationElement(frame_no), m_data(std::make_unique<VMDModelControllerData>(show)){}

	explicit VMDModelControllerAnimation(const UInt32& frame_no = 0U, const std::unique_ptr<VMDModelControllerData> data = nullptr) :
		VMDAnimationElement(frame_no), m_data(std::unique_ptr<VMDModelControllerData>(data == nullptr ? nullptr : new VMDModelControllerData(data->show))) {}
	/**
	 * \brief Move constructor
	 */
	VMDModelControllerAnimation(VMDModelControllerAnimation&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDModelControllerAnimation& operator =(VMDModelControllerAnimation&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDModelControllerAnimation() override = default;
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


#endif //!_VMD_MODEL_CONTROLLER_ANIMATION_H_
