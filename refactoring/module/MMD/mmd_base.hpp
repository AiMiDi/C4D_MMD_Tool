/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/13
File:			mmd_base.cpp
Description:	define MMD base class

**************************************************************************/
#ifndef _MMD_BASE_H_
#define _MMD_BASE_H_

class MMDDataBase
{
public:
	MMDDataBase() = default;
	virtual  ~MMDDataBase() = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(MMDDataBase)
	/**
	 * \brief Move constructor
	 */
	MMDDataBase(MMDDataBase&&) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	MMDDataBase& operator =(MMDDataBase&&) noexcept = default;
	/**
	* \brief Read from a mmd data file(pmx/vmd and more)
	* \param file mmd data file(pmx/vmd and more)
	* \return Successful TRUE, other FALSE.
	*/
	virtual Bool ReadFromFile(BaseFile* file)
	{
		DebugStop("Not overloaded MMDDataBase: : ReadFromFile ()"_s);
		return false;
	}
	/**
	 * \brief Write to mmd data file(pmx/vmd and more)
	 * \param file mmd data file(pmx/vmd and more)
	 * \return Successful TRUE, other FALSE.
	 */
	virtual Bool WriteToFile(BaseFile* file) const
	{
		DebugStop("Not overloaded MMDDataBase::WriteToFile ()"_s);
		return false;
	}
};

#endif
