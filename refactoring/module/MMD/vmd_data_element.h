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

class VMDDataElement : public MMDDataBase
{
protected:
	UInt32 m_frame_on = 0U;
public:
	/**
	 * \brief Equality operator, Sort by frame order
	 * \param other Another instance
	 * \return TRUE is returned if it is equal to another instance, and the other is FALSE
	 */
	bool operator ==(const VMDDataElement& other) const
	{
		return m_frame_on == other.m_frame_on;
	}
	/**
	 * \brief Less than operator, Sort by frame order
	 * \param other Another instance
	 * \return TRUE is returned if it is less than another instance, and the other is FALSE
	 */
	bool operator <(const VMDDataElement& other) const
	{
		return m_frame_on < other.m_frame_on;
	}
	/**
	 * \brief  Constructor function
	 */
	explicit VMDDataElement(const UInt32 frame_no = 0U) :m_frame_on(frame_no) {}

	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDDataElement)
	/**
	 * \brief Move constructor
	 */
	VMDDataElement(VMDDataElement&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDDataElement& operator =(VMDDataElement&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDDataElement() override = default;
};


#endif //!_VMD_ELEMENT_H_

