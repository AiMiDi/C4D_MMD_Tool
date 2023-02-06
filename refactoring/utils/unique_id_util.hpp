/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/7
File:			unique_id_util.h
Description:	Unique ID util

**************************************************************************/

#ifndef _UNIQUE_ID_UTIL_H_
#define _UNIQUE_ID_UTIL_H_

#include "pch.h"

class UniqueIDReader
{
	Int m_bytes = 0;
	const Char* m_cstr = nullptr;
public:
	explicit UniqueIDReader() = default;

	static auto GetUniqueIDString(const BaseList2D* bl, const Int32& appid)
	{
		UniqueIDReader id_reader;
		Bool successful = bl->FindUniqueID(appid, id_reader.m_cstr, id_reader.m_bytes);
		if (id_reader.m_bytes && id_reader.m_cstr[id_reader.m_bytes - 1] == '\0')
			--id_reader.m_bytes;
		return std::make_tuple(successful, maxon::String{ id_reader.m_cstr ,id_reader.m_bytes });
	}

	static Bool FindUniqueID(const BaseList2D* bl, const Int32& appid)
	{
		UniqueIDReader id_reader;
		return bl->FindUniqueID(appid, id_reader.m_cstr, id_reader.m_bytes);
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

#endif // !UNIQUE_ID_UTIL_H
