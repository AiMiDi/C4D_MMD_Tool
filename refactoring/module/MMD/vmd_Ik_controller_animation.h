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
	/**
	 * \brief Constructor function
	 * \param name IK name
	 * \param enable Is IK enable
	 */
	explicit VMDControllerData(String name = {}, const Bool &enable = true) :
		m_IK_name{std::move(name)}, m_IK_enable{ enable } {}
};

class VMDIkControllerAnimation final : public MMDDataBase
{
	typedef VMDControllerData data_type;
	std::unique_ptr<data_type> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDIkControllerAnimation)
	/**
	 * \brief Default constructor function
	 */
	explicit VMDIkControllerAnimation() : m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param name IK name
	 * \param enable Is IK enable
	 */
	explicit VMDIkControllerAnimation(const String &name, const Bool &enable) :
		m_data(std::make_unique<data_type>(name, enable)) {}
	/**
	 * \brief Constructor function
	 * \param data Internal data
	 */
	explicit VMDIkControllerAnimation(const data_type &data) :
		m_data(std::make_unique<data_type>(data)) {}
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
