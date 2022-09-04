/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/17
File:			vmd_element.h
Description:	

**************************************************************************/
#ifndef _VMD_ELEMENT_H_
#define _VMD_ELEMENT_H_

#include "pch.h"
#include "mmd_base.hpp"

class VMDAnimationElement : public MMDDataBase
{
protected:
	UInt32 m_frame_num = 0U;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDAnimationElement)
	/**
	 * \brief  Constructor function
	 */
	explicit VMDAnimationElement(const UInt32& frame_no = 0U) :m_frame_num(frame_no) {}
	/**
	 * \brief Move constructor
	 */
	VMDAnimationElement(VMDAnimationElement&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDAnimationElement& operator =(VMDAnimationElement&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDAnimationElement() override = default;
public:
	[[nodiscard]] UInt32 GetFrameNum() const
	{
		return m_frame_num;
	}
	/**
	 * \brief Equality operator, Sort by frame order
	 * \param other Another instance
	 * \return TRUE is returned if it is equal to another instance, and the other is FALSE
	 */
	bool operator ==(const VMDAnimationElement& other) const
	{
		return m_frame_num == other.m_frame_num;
	}
	/**
	 * \brief Less than operator, Sort by frame order
	 * \param other Another instance
	 * \return TRUE is returned if it is less than another instance, and the other is FALSE
	 */
	bool operator <(const VMDAnimationElement& other) const
	{
		return m_frame_num < other.m_frame_num;
	}
};


#endif //!_VMD_ELEMENT_H_

