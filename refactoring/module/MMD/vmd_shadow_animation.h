/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_shadow_animation.h
Description:	MMD style shadow animation

**************************************************************************/

#ifndef _VMD_SHADOW_ANIMATION_H_
#define _VMD_SHADOW_ANIMATION_H_

#include "pch.h"

#include "vmd_data_element.h"

class VMDShadowAnimation final : public VMDDataElement
{
	// Distance
	UChar	m_shadow_type{};
	// 0:Off 1:mode1 2:mode2 
	Float32 m_distance{};
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDShadowAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDShadowAnimation(const UInt32 frame_on = 0U, const UChar shadow_type = 0U, const Float32 distance = 0.f) :
		VMDDataElement(frame_on), m_shadow_type(shadow_type), m_distance(distance) {}
	/**
	 * \brief Move constructor
	 */
	VMDShadowAnimation(VMDShadowAnimation&&) noexcept;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDShadowAnimation& operator =(VMDShadowAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDShadowAnimation() override = default;
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

#endif // !_VMD_SHADOW_ANIMATION_H_