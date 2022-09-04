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
	/**
	 * \brief  Constructor function
	 * \param show Is model show
	 */
	explicit VMDModelControllerData(const Bool &show = true):
		show(show){}

	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDModelControllerData)
	/**
	 * \brief Move constructor
	 */
	VMDModelControllerData(VMDModelControllerData&& src) noexcept : MAXON_MOVE_MEMBERS(show, IK_Info_array){}
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDModelControllerData& operator =(VMDModelControllerData&&) noexcept = default;
};

class VMDModelControllerAnimation final : public VMDAnimationElement
{
	typedef VMDModelControllerData data_type;
	std::unique_ptr<data_type> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDModelControllerAnimation)
	/**
	 * \brief Default constructor function
	 */
	explicit VMDModelControllerAnimation() : VMDAnimationElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief  Constructor function
	 * \param frame_num Frame of action
	 * \param show Is model show
	 */
	explicit VMDModelControllerAnimation(const UInt32& frame_num, const Bool &show = true) :
	VMDAnimationElement(frame_num), m_data(std::make_unique<data_type>(show)){}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param data Internal data
	 */
	explicit VMDModelControllerAnimation(const UInt32& frame_num, data_type&& data) :
		VMDAnimationElement(frame_num), m_data(std::make_unique<data_type>(std::move(data))) {}
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
