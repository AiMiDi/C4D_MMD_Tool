/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/15
File:			vmd_morph_animation.h
Description:	MMD style expression animation

**************************************************************************/

#ifndef _VMD_MORPH_ANIMATION_H_
#define _VMD_MORPH_ANIMATION_H_

#include "pch.h"

#include "vmd_data_element.h"

struct VMDMorphData
{
	// The action corresponds to the expression name
	String	morph_name;
	// Expression deformation strength
	Float32 weight;


	explicit VMDMorphData(String morph_name = {}, const Float32& weight = 0.f) :
		morph_name(std::move(morph_name)), weight(weight){}
};

class VMDMorphAnimation final : public VMDAnimationElement
{
	std::unique_ptr<VMDMorphData> m_data;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDMorphAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDMorphAnimation(const UInt32& frame_on = 0,const String& morph_name = {},const Float32& weight = 0.f) :
	VMDAnimationElement(frame_on), m_data(std::make_unique<VMDMorphData>(morph_name, weight)) {}

	explicit VMDMorphAnimation(const UInt32& frame_on = 0, const std::unique_ptr<VMDMorphData> data = nullptr) :
		VMDAnimationElement(frame_on), m_data(std::unique_ptr<VMDMorphData>(data == nullptr ? nullptr : new VMDMorphData(data->morph_name, data->weight))) {}
	/**
	 * \brief Move constructor
	 */
	VMDMorphAnimation(VMDMorphAnimation&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDMorphAnimation& operator =(VMDMorphAnimation&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDMorphAnimation() override = default;
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

#endif // !_VMD_MORPH_ANIMATION_H_
