/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
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
			return TRUE;
		}
		return FALSE;
	}
	/**
	 * \brief Opens the file with the specified suffix.
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise to check the passed file name.
	 * \param file Output, the open suffix matches the file object.
	 * \param suffix Suffix to match
	 * \return The suffix of the file name matches and the file is successfully opened and returns TRUE, otherwise it returns FALSE.
	 */
	inline Bool SelectSuffixImportFile(Filename& fn, BaseFile* file, const String& suffix) {
		if (!fn.IsPopulated() && !fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE)))
		{
			return FALSE;
		}
		if (file == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return FALSE;
		}
		if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA))
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
			return FALSE;
		}
		if (CheckSuffix(fn, suffix))
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR, suffix));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR, suffix));
			return FALSE;
		}
		return TRUE;
	}
}

#endif // !_FILENAME_UTIL_H_