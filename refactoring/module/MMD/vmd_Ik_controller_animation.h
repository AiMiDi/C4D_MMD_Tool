/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/14
File:			vmd_Ik_controller_animation.h
Description:	MMD style IK enable information animation

**************************************************************************/

#ifndef _VMD_IK_CONTROLLER_ANIMATION_
#define _VMD_IK_CONTROLLER_ANIMATION_

#include "pch.h"
#include "mmd_base.hpp"

struct VMDControllerData
{
	// IK name
	String	m_IK_name;
	// Is IK enable
	Bool	m_IK_enable;

	explicit VMDControllerData(String name = {}, const Bool enable = true) :
		m_IK_name{ name }, m_IK_enable{ enable } {}
};

class VMDIkControllerAnimation final : public MMDDataBase
{
	std::unique_ptr<VMDControllerData> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDIkControllerAnimation)
	/**
	 * \brief Constructor function
	 * \param name IK name
	 * \param enable Is IK enable
	 */
	explicit VMDIkControllerAnimation(const String name = {}, const Bool enable = true) :
		m_data{ std::make_unique<VMDControllerData>(name, enable) } {}

	explicit VMDIkControllerAnimation(const std::unique_ptr<VMDControllerData> data = nullptr) :
		m_data(data == nullptr ? nullptr : std::unique_ptr<VMDControllerData>(new VMDControllerData(data->m_IK_name, data->m_IK_enable))) {}
	/**
	 * \brief Move constructor
	 */
	VMDIkControllerAnimation(VMDIkControllerAnimation&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDIkControllerAnimation() override = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDIkControllerAnimation& operator =(VMDIkControllerAnimation&&) noexcept = default;
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

#endif //!_VMD_IK_CONTROLLER_ANIMATION_
