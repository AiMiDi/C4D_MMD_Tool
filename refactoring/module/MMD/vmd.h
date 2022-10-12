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

#include "vmd_bone.h"
#include "vmd_camera.h"
#include "vmd_light.h"
#include "vmd_model_controller.h"
#include "vmd_morph.h"
#include "vmd_shadow.h"

struct VMDData
{
	String model_name;
	VMDElementArray<VMDBoneAnimation> motion_frames{};
	VMDElementArray<VMDMorphAnimation> morph_frames{};
	VMDElementArray<VMDCameraAnimation> camera_frames{};
	VMDElementArray<VMDLightAnimation> light_frames{};
	VMDElementArray<VMDShadow> shadow_frames{};
	VMDElementArray<VMDModelController> model_frames;

	explicit VMDData(String model_name) : model_name(std::move(model_name)){}
};

class VMD
{
public:
	/**
	 * \brief  Constructor function
	 */
	explicit VMD(String model_name = {}, bool is_camera = false);
	/**
	 * \brief Copy constructor
	 */
	VMD(const VMD&) = delete;
	/**
	 * \brief Move constructor
	 */
	VMD(VMD&&) noexcept = default;
	/**
	 * \brief Copy operator=
	 * \return Result reference
	 */
	VMD& operator =(const VMD&) = delete;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMD& operator =(VMD&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMD() = default;
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
	/**
	 * \brief Check it is VMD Camera
	 * \return Is a VMD Camera TRUE, other FALSE.
	 */
	[[nodiscard]] bool IsCamera() const
	{
		return m_is_camera;
	}
private:
	using data_type = VMDData;

	std::unique_ptr<data_type> m_data;
	bool m_is_camera = false;

	inline static String m_camera_name = L"カメラ・照明"_s;
	
};

#endif // !_VMD_DATA_H_
