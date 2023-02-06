/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/14
File:			vmd_Ik_controller_animation.h
Description:	MMD style IK enable information animation

**************************************************************************/

#ifndef _VMD_IK_CONTROLLER_H_
#define _VMD_IK_CONTROLLER_H_

#include "pch.h"
#include "mmd_element.hpp"

struct VMDControllerData
{
	// IK name
	String	m_IK_name;
	// Is IK enable
	Bool	m_IK_enable;
	/**
	 * \brief Constructor function
	 * \param name IK name
	 * \param enable Is IK enable
	 */
	explicit VMDControllerData(String name = {}, const Bool& enable = true) :
		m_IK_name(std::move(name)), m_IK_enable(enable) {}
};

class VMDIkController final : public MMDElement
{
	GENERATE_MMD_CLASS_BODY(VMDIkController, VMDControllerData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit VMDIkController() : MMDElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param data Internal data unique_ptr
	 */
	explicit VMDIkController(std::unique_ptr<data_type> data) : MMDElement(), m_data(std::move(data)) {}
	/**
	 * \brief Destructor function
	 */
	~VMDIkController() override = default;
	/**
	 * \brief Read from a vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE
	 */
	Bool ReadFromFile(BaseFile* file) override;
	/**
	 * \brief Write to vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE
	 */
	Bool WriteToFile(BaseFile* file) const override;
};

#endif //!_VMD_IK_CONTROLLER_H_
