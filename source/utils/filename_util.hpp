/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			Filename_util.hpp
Description:	Filename utils

**************************************************************************/

#pragma once

#include <vector>
#include <c4d.h>
#include <c4d_symbols.h>

namespace filename_util
{
#if API_VERSION >= 2024900
	using namespace cinema;
#endif

	/**
	 * \brief Read an entire file into a byte buffer using C4D's BaseFile API.
	 *        This handles Unicode file paths natively through Cinema 4D's Filename type.
	 * \param fn File to read
	 * \param data Output buffer
	 * \return TRUE on success, FALSE on failure
	 */
	inline Bool ReadFileData(const Filename& fn, std::vector<uint8_t>& data)
	{
		AutoAlloc<BaseFile> file;
		if (!file || !file->Open(fn, FILEOPEN::READ, FILEDIALOG::NONE, BYTEORDER::V_INTEL))
		{
			return false;
		}
		const Int64 size = file->GetLength();
		data.resize(static_cast<size_t>(size));
		if (file->ReadBytes(data.data(), size) != size)
		{
			return false;
		}
		file->Close();
		return true;
	}
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
