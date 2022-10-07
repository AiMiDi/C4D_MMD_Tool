/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/1
File:			pmx_element.hpp
Description:	pmx element base class.

**************************************************************************/
#ifndef _PMX_ELEMENT_H_
#define _PMX_ELEMENT_H_

#include "pch.h"
#include "mmd_element.hpp"
#include "pmx_model_info.h"

class PMXElement : public MMDElement
{
protected:
	const PMXModelInfo* m_model_info = nullptr;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXElement)
	/**
	* \brief  Constructor function
	*/
	explicit PMXElement(const PMXModelInfo* model_info) : m_model_info(model_info) {}
	/**
	 * \brief Move constructor
	 */
	PMXElement(PMXElement&& src) noexcept : m_model_info(src.m_model_info){}
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXElement& operator =(PMXElement&& src) noexcept
	{
		if (this != &src)
			m_model_info = src.m_model_info;
		return *this;
	}
	/**
	 * \brief Destructor function
	 */
	~PMXElement() override = default;
};

/**
 * \brief PMX data array template class
 * \tparam T PMX data element class
 */
template<class T>
class PMXElementArray final : public MMDElementArray<T, const PMXModelInfo*>
{
	static_assert(std::is_base_of_v<PMXElement, T>);
public:
	explicit PMXElementArray(const PMXModelInfo* model_info_ptr) :
	MMDElementArray<T, const PMXModelInfo*>(model_info_ptr) {}
	/**
	 * \brief Read from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override
	{
		if (!MMDElementArray<T, const PMXModelInfo*>::ReadFromFile(file))
		{
			return FALSE;
		}
		return TRUE;
	}
	/**
	 * \brief Write to pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool WriteToFile(BaseFile* file) const override
	{
		return MMDElementArray<T, const PMXModelInfo*>::WriteToFile(file);
	}
};


#endif
