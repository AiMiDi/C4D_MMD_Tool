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

class VMDMorphAnimation final : public VMDDataElement
{
	// The action corresponds to the expression name
	String	m_morph_name;
	// Expression deformation strength
	Float32 m_weight;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDMorphAnimation)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDMorphAnimation(UInt32 frame_on = 0, String morph_name = {}, Float32 weight = 0.f);
	/**
	 * \brief Move constructor
	 */
	VMDMorphAnimation(VMDMorphAnimation&&) noexcept;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDMorphAnimation& operator =(VMDMorphAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDMorphAnimation() override = default;
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

#endif // !_VMD_MORPH_ANIMATION_H_