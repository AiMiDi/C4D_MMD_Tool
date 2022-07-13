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

struct VMDIkControllerAnimation
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
	explicit VMDIkControllerAnimation(String name = {}, const Bool enable = true) :
		m_IK_name(std::move(name)),m_IK_enable(enable) {}
	/**
	 * \brief Copy constructor
	 */
	VMDIkControllerAnimation(const VMDIkControllerAnimation&) = default;
	/**
	 * \brief Move constructor
	 */
	VMDIkControllerAnimation(VMDIkControllerAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDIkControllerAnimation() = default;
	/**
	 * \brief Copy operator=
	 * \return Result reference
	 */
	VMDIkControllerAnimation& operator =(const VMDIkControllerAnimation&) = default;
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
	Bool ReadFormVMDFile(BaseFile* file);
	/**
	 * \brief Write to vmd file
	 * \param file vmd file
	 * \return Successful TRUE, other FALSE
	 */
	Bool WriteToVMDFile(BaseFile* file) const;
};

#endif //!_VMD_IK_CONTROLLER_ANIMATION_
