/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2025/3/22
File:			string_util.hpp
Description:	std string util

**************************************************************************/

#pragma once

namespace string_util
{
	static std::string GetStdString(const maxon::String& str)
	{
		if (str.IsEmpty())
		{
			return {};
		}
		iferr_scope_handler{
			return {};
		};
		maxon::BaseArray<Char> buffer;
		iferr(str.GetCStringAppendArray(buffer))
		{
			return {};
		}
		return { buffer.GetFirst(), static_cast<size_t>(buffer.GetCount()) };
	}
}
