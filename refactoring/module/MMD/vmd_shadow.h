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
#include "vmd_element.hpp"

struct VMDShadowData
{
	// 0:Off 1:mode1 2:mode2
	UChar	shadow_type;
	// Distance
	Float32 distance;

	/**
	 * \brief Constructor function
	 * \param shadow_type 0:Off 1:mode1 2:mode2
	 * \param distance Shadow distance
	 */
	explicit VMDShadowData(const UChar& shadow_type = {}, const Float32& distance = {}) :
	shadow_type(shadow_type), distance(distance) {}
};

class VMDShadow final : public VMDElement
{
	GENERATE_MMD_CLASS_BODY(VMDShadow, VMDShadowData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit VMDShadow() : VMDElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param data Internal data unique_ptr
	 */
	explicit VMDShadow(const UInt32& frame_num, std::unique_ptr<data_type> data = std::make_unique<data_type>()) : VMDElement(frame_num), m_data(std::move(data)) {}
	/**
	 * \brief Destructor function
	 */
	~VMDShadow() override = default;
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

#endif // !_VMD_SHADOW_ANIMATION_H_
