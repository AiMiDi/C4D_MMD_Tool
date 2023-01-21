/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/14
File:			vmd_model_controller_animation.h
Description:	MMD style model information animation

**************************************************************************/

#ifndef _VMD_MODEL_CONTROLLER_H_
#define _VMD_MODEL_CONTROLLER_H_

#include "pch.h"

#include "vmd_element.hpp"
#include "vmd_Ik_controller.h"

struct VMDModelControllerData
{
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(VMDModelControllerData)
	CMT_DEFAULT_MOVE_BODY(VMDModelControllerData)
public:
	typedef maxon::BaseArray<VMDIkController> VMDIkControllerArray;

	// Is model show
	Bool				 show;
	// IKs enable information
	VMDIkControllerArray IK_Info_array{};
	/**
	 * \brief  Constructor function
	 * \param show Is model show
	 */
	explicit VMDModelControllerData(const Bool &show = true):
		show(show){}
};

class VMDModelController final : public VMDElement
{
	GENERATE_MMD_CLASS_BODY(VMDModelController, VMDModelControllerData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit VMDModelController() : VMDElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param data Internal data unique_ptr
	 */
	explicit VMDModelController(const UInt32& frame_num, std::unique_ptr<data_type> data = std::make_unique<data_type>()) : VMDElement(frame_num), m_data(std::move(data)) {}
	/**
	 * \brief Destructor function
	 */
	~VMDModelController() override = default;
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

#endif //!_VMD_MODEL_CONTROLLER_H_
