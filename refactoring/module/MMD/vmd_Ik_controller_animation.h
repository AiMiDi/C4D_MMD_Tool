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

class VMDIkControllerAnimation final : public MMDDataBase
{
	// IK name
	String	m_IK_name;
	// Is IK enable
	Bool	m_IK_enable;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDIkControllerAnimation)
	/**
	 * \brief Constructor function
	 * \param name IK name
	 * \param enable Is IK enable
	 */
	explicit VMDIkControllerAnimation(String name = {}, const Bool enable = true) :
		m_IK_name(std::move(name)),m_IK_enable(enable) {}
	/**
	 * \brief Move constructor
	 */
	VMDIkControllerAnimation(VMDIkControllerAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDIkControllerAnimation() override = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDIkControllerAnimation& operator =(VMDIkControllerAnimation&&) noexcept;
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
