/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_data.h
Description:	vmd file data

**************************************************************************/

#ifndef _VMD_DATA_H_
#define _VMD_DATA_H_

#include "pch.h"

#include "vmd_bone_animation.h"
#include "vmd_camera_animation.h"
#include "vmd_light_animation.h"
#include "vmd_model_controller_animation.h"
#include "vmd_morph_animation.h"
#include "vmd_shadow_animation.h"
#include "maxon/sortedarray.h"


/**
 * \brief VMD animation data sort array template class
 * \tparam T VMD data element class
 */
template<class T>
class VMDAnimationSortedArray : public maxon::SortedArray<VMDAnimationSortedArray<T>, maxon::BaseArray<T>, maxon::BASESORTFLAGS::NONE, true>
{
public:
	/**
	 * \brief Less than the comparison function, which is used to sort
	 * \return The first instance is less than the second instance and returns TRUE, and the other is FALSE
	 */
	static Bool LessThan(const T&, const T&);
	/**
	 * \brief Equal to the comparison function, which is used to sort
	 * \return TRUE is returned when two instances are equal, and the other is FALSE
	 */
	static Bool IsEqual(const T&, const T&);
	/**
	 * \brief Read from a vmd file
	 * \param file file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFormFile(BaseFile* file);
	/**
	 * \brief Write to vmd file
	 * \param file file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool WriteToFile(BaseFile* file) const;
};

class VMDAnimation
{
	inline static String m_camera_name;
	String m_model_name;
	bool m_is_camera = false;
	VMDAnimationSortedArray<VMDBoneAnimation> m_motion_frames;
	VMDAnimationSortedArray<VMDMorphAnimation> m_morph_frames;
	VMDAnimationSortedArray<VMDCameraAnimation> m_camera_frames;
	VMDAnimationSortedArray<VMDLightAnimation> m_light_frames;
	VMDAnimationSortedArray<VMDShadowAnimation> m_shadow_frames;
	VMDAnimationSortedArray<VMDModelControllerAnimation> m_model_frames;
public:
	/**
	 * \brief  Constructor function
	 */
	explicit VMDAnimation(String model_name = {}, bool is_camera = false);
	/**
	 * \brief Copy constructor
	 */
	VMDAnimation(const VMDAnimation&) = delete;
	/**
	 * \brief Move constructor
	 */
	VMDAnimation(VMDAnimation&&) noexcept;
	/**
	 * \brief Copy operator=
	 * \return Result reference
	 */
	VMDAnimation& operator =(const VMDAnimation&) = delete;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDAnimation& operator =(VMDAnimation&&) noexcept;
	/**
	 * \brief Destructor function
	 */
	~VMDAnimation() = default;
	/**
	 * \brief Read from a vmd file
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise use the passed file name.
	 * \return Successful TRUE, other FALSE.
	 */
	Bool LoadFromFile(Filename& fn);
	/**
	 * \brief Write to vmd file
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise use the passed file name.
	 * \return Successful TRUE, other FALSE.
	 */
	Bool SaveToFile(Filename& fn) const;
	static void Init()
	{
		m_camera_name = L"カメラ・照明"_s;
	}
};

#endif // !_VMD_DATA_H_