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

struct VMDLightData
{
	// Light color
	Vector32	m_rgb;
	// location
	Vector32	m_position;


	explicit VMDLightData(const Vector32& rgb = {}, const Vector32& pos = {}) :
		m_rgb(rgb), m_position(pos) {}
};

class VMDLightAnimation final : public VMDAnimationElement
{
	std::unique_ptr<VMDLightData> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDLightAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDLightAnimation(const UInt32 frame_no = 0, const Vector32 rgb = {}, const Vector32 position = {}):
		VMDAnimationElement(frame_no), m_data(std::make_unique<VMDLightData>(rgb, position)) {}

	explicit VMDLightAnimation(const UInt32 frame_no = 0, const std::unique_ptr<VMDLightData> data = nullptr) :
		VMDAnimationElement(frame_no), m_data(data == nullptr ? nullptr : std::unique_ptr<VMDLightData>(new VMDLightData(data->m_rgb, data->m_position))) {}

	/**
	 * \brief Move constructor
	 */
	VMDLightAnimation(VMDLightAnimation&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDLightAnimation& operator =(VMDLightAnimation&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDLightAnimation() override = default;
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

#endif // !_VMD_LIGHT_ANIMATION_H_
