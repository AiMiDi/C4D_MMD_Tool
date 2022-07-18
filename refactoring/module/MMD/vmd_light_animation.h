/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_light_animation.h
Description:	MMD style lighting animation

**************************************************************************/

#ifndef _VMD_LIGHT_ANIMATION_H_
#define _VMD_LIGHT_ANIMATION_H_

#include "pch.h"

#include "vmd_data_element.h"

class VMDLightAnimation final : public VMDDataElement
{
	// Light color
	Vector32	m_rgb;
	// location
	Vector32	m_position;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDLightAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDLightAnimation(UInt32 frame_no = 0, Vector32 rgb = {}, Vector32 position = {});
	/**
	 * \brief Move constructor
	 */
	VMDLightAnimation(VMDLightAnimation&&) noexcept;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDLightAnimation& operator =(VMDLightAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDLightAnimation() override = default;
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

#endif // !_VMD_LIGHT_ANIMATION_H_