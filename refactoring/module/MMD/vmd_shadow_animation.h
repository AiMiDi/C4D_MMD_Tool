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
	explicit VMDShadowData(const UChar &shadow_type = 0U, const Float32 &distance = 0.f) :
	shadow_type(shadow_type), distance(distance) {}
};

class VMDShadowAnimation final : public VMDAnimationElement
{
	typedef VMDShadowData data_type;
	std::unique_ptr<data_type> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDShadowAnimation)
	/**
	 * \brief Default constructor function
	 */
	explicit VMDShadowAnimation() : VMDAnimationElement(), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param shadow_type 0:Off 1:mode1 2:mode2
	 * \param distance Shadow distance
	 */
	explicit VMDShadowAnimation(const UInt32 &frame_num, const UChar &shadow_type = 0U, const Float32 &distance = 0.f) :
	VMDAnimationElement(frame_num), m_data(std::make_unique<data_type>(shadow_type, distance)){}
	/**
	 * \brief Constructor function
	 * \param frame_num Frame of action
	 * \param data Internal data
	 */
	explicit VMDShadowAnimation(const UInt32 &frame_num, const data_type &data) :
		VMDAnimationElement(frame_num), m_data(std::make_unique<data_type>(data)) {}
	/**
	 * \brief Move constructor
	 */
	VMDShadowAnimation(VMDShadowAnimation&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDShadowAnimation& operator =(VMDShadowAnimation&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDShadowAnimation() override = default;
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
