/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/10/7
File:			unique_id_util.h
Description:	Unique ID util

**************************************************************************/

#pragma once

#include <c4d.h>
#include <tuple>
#include "module/core/cmt_marco.h"

class UniqueIDReader
{
public:
	explicit UniqueIDReader() = default;

	static auto GetUniqueIDString(const BaseList2D* bl, const Int32& appid)
	{
		Int bytes = 0;
		const Char* temp_mem;
		Bool successful = bl->FindUniqueID(appid, temp_mem, bytes);
		if (bytes && temp_mem[bytes - 1] == '\0')
			--bytes;
		return std::make_tuple(successful, maxon::String{ temp_mem, bytes });
	}

	static Bool FindUniqueID(const BaseList2D* bl, const Int32& appid)
	{
		Int bytes = 0;
		const Char* temp_mem;
		return bl->FindUniqueID(appid, temp_mem, bytes);
	}
};

class UniqueIDWriter
{
	Int m_bytes = 0;
	maxon::AutoMem<Char> m_cstr;
public:
	explicit UniqueIDWriter(const String& id) : m_bytes(id.GetCStringLen(STRINGENCODING::UTF8)), m_cstr(id.GetCStringCopy(STRINGENCODING::UTF8)) {}

	static Bool AddUniqueID(BaseList2D* bl, const String& id, const Int32& appid)
	{
		const UniqueIDWriter id_writer(id);
		return bl->AddUniqueID(appid, id_writer.m_cstr, id_writer.m_bytes);
	}
};
