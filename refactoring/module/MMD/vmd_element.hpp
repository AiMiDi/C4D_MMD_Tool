/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/17
File:			vmd_element.hpp
Description:	vmd element base class.

**************************************************************************/
#ifndef _VMD_ELEMENT_H_
#define _VMD_ELEMENT_H_

#include "pch.h"
#include "mmd_element.hpp"

class VMDElement : public MMDElement
{
protected:
	UInt32 m_frame_num;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(VMDElement)
	/**
	 * \brief Default constructor function
	 */
	explicit VMDElement() : m_frame_num(0U) {}
	/**
	 * \brief  Constructor function
	 */
	explicit VMDElement(const UInt32& frame_no) : m_frame_num(frame_no) {}
	/**
	 * \brief Move constructor
	 */
	VMDElement(VMDElement&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	VMDElement& operator =(VMDElement&&) noexcept = default;
	/**
	 * \brief Destructor function
	 */
	~VMDElement() override = default;
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
	bool operator ==(const VMDElement& other) const
	{
		return m_frame_num == other.m_frame_num;
	}
	/**
	 * \brief Less than operator, Sort by frame order
	 * \param other Another instance
	 * \return TRUE is returned if it is less than another instance, and the other is FALSE
	 */
	bool operator <(const VMDElement& other) const
	{
		return m_frame_num < other.m_frame_num;
	}
};

/**
 * \brief VMD animation data sort array template class
 * \tparam T VMD data element class
 */
template<class T>
class VMDElementArray final : public MMDElementArray<T>
{
	static_assert(std::is_base_of_v<VMDElement, T>);

	class VMDElementSorter : public maxon::ParallelSort<VMDElementSorter>
	{
	public:
		/**
		 * \brief Less than the comparison function, which is used to sort
		 * \return The first instance is less than the second instance and returns TRUE, and the other is FALSE
		 */
		static Bool LessThan(const T& a, const T& b)
		{
			return a < b;
		}
		/**
		 * \brief Equal to the comparison function, which is used to sort
		 * \return TRUE is returned when two instances are equal, and the other is FALSE
		 */
		static Bool IsEqual(const T& a, const T& b)
		{
			return a == b;
		}
	};
public:
	explicit VMDElementArray() : MMDElementArray() {}
	/**
	 * \brief Read from a vmd file
	 * \param file file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override
	{
		if(!MMDElementArray<T>::ReadFromFile(file))
		{
			return FALSE;
		}
		VMDElementSorter sorter{};
		sorter.Sort(*this);
		return TRUE;
	}
	/**
	 * \brief Write to vmd file
	 * \param file file vmd file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool WriteToFile(BaseFile* file) const override
	{
		return MMDElementArray<T>::WriteToFile(file);
	}
};


#endif //!_VMD_ELEMENT_H_

