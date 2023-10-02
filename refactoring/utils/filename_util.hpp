/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			Filename_util.hpp
Description:	Filename utils 

**************************************************************************/

#ifndef _FILENAME_UTIL_H_
#define _FILENAME_UTIL_H_

#include "pch.h"

namespace filename_util
{
	/**
	 * \brief Check that the file name suffix is consistent with the given suffix.
	 * \param fn File name to check
	 * \param suffix Suffix to match
	 * \return The suffix match of the file name returns TRUE, otherwise it is FALSE.
	 */
	inline Bool CheckSuffix(const Filename& fn, const String& suffix)
	{
		if (fn.GetSuffix().ToLower().Compare(suffix) == maxon::COMPARERESULT::EQUAL)
		{
			return true;
		}
		return false;
	}
	/**
	 * \brief Open the file with the specified suffix.
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise to check the passed file name.
	 * \param suffix Suffix to match
	 * \return The suffix of the file name matches and the file is successfully opened and returns TRUE, otherwise it returns FALSE.
	 */
	inline Bool SelectSuffixImportFile(Filename& fn, const String& suffix) {
		if (!fn.IsPopulated() && !fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE)))
		{
			return false;
		}
		if (!CheckSuffix(fn, suffix))
		{
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR, suffix));
			return false;
		}
		return true;
	}
	/**
	 * \brief Save the file with the specified suffix.
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise to check the passed file name.
	 * \param suffix Suffix to match
	 * \return The suffix of the file name matches and the file is successfully opened and returns TRUE, otherwise it returns FALSE.
	 */
	inline Bool SelectSuffixExportFile(Filename& fn, const String& suffix) {
		if (!fn.IsPopulated() && !fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::SAVE, GeLoadString(IDS_MES_SAVEFILE), suffix))
		{
			return false;
		}
		return true;
	}
}

#endif // !_FILENAME_UTIL_H_
