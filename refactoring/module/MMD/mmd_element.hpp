/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/13
File:			mmd_element.hpp
Description:	MMD element base class.

**************************************************************************/
#ifndef _MMD_ELEMENT_H_
#define _MMD_ELEMENT_H_

#include "pch.h"

class MMDElement
{
public:
	MMDElement() = default;
	virtual  ~MMDElement() = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(MMDElement)
	/**
	 * \brief Move constructor
	 */
	MMDElement(MMDElement&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	MMDElement& operator =(MMDElement&&) noexcept = default;
	/**
	* \brief Read from a mmd data file(pmx/vmd and more)
	* \param file mmd data file(pmx/vmd and more)
	* \return Successful TRUE, other FALSE.
	*/
	virtual Bool ReadFromFile(BaseFile* file)
	{
		DebugStop("Not overloaded MMDElement::ReadFromFile()"_s);
		return false;
	}
	/**
	 * \brief Write to mmd data file(pmx/vmd and more)
	 * \param file mmd data file(pmx/vmd and more)
	 * \return Successful TRUE, other FALSE.
	 */
	virtual Bool WriteToFile(BaseFile* file) const
	{
		DebugStop("Not overloaded MMDElement::WriteToFile()"_s);
		return false;
	}
};

/**
 * \brief MMD data sort array template class
 * \tparam T MMD data element class
 */
template<class T, typename... Args>
class MMDElementArray : public maxon::BaseArray<T>
{
	static_assert(std::is_base_of_v<MMDElement, T>);
	std::tuple<Args...> args;
public:
	explicit MMDElementArray(Args... args) : args(std::forward<Args>(args)...){}

	/**
	 * \brief Read from a mmd file
	 * \param file file mmd file
	 * \return Successful TRUE, other FALSE.
	 */
	virtual Bool ReadFromFile(BaseFile* file)
	{
		UInt32 data_number = 0;
		if (!file->ReadUInt32(&data_number))
			return FALSE;
		this->Flush();
		iferr(this->EnsureCapacity(data_number))
			return FALSE;
		for (int data_index = 0; data_index < data_number; ++data_index)
		{
			T data = std::make_from_tuple<T>(args);
			if (!data.ReadFromFile(file))
			{
				return FALSE;
			}
			iferr(this->Append(std::move(data)))
				return FALSE;
		}
		return TRUE;
	}
	/**
	 * \brief Write to mmd file
	 * \param file file mmd file
	 * \return Successful TRUE, other FALSE.
	 */
	virtual Bool WriteToFile(BaseFile* file) const
	{
		if (const auto data_number = static_cast<UInt32>(this->GetCount()); !file->WriteUInt32(data_number))
			return FALSE;
		for(auto& data : *this)
		{
			if (!data.WriteToFile(file))
			{
				return FALSE;
			}
		}
		return TRUE;
	}
};

#endif // !_MMD_ELEMENT_H_
