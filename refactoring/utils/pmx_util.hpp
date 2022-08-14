/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/8/10
File:			pmx_util.hpp
Description:	PMX util

**************************************************************************/

#ifndef _PMX_UTIL_H_
#define _PMX_UTIL_H_

#include "pch.h"

class PMXTextReader
{
	Char m_text_encoding;
public:
	explicit PMXTextReader(const Char& text_encoding):m_text_encoding(text_encoding){}
	bool operator()(BaseFile* const file, String& out_string) const
	{
		// text字符串最大长度
		Int32 text_length = 0;
		file->ReadInt32(&text_length);
		if (text_length > 0) {
			if (m_text_encoding == 0)
			{
				std::basic_string<char16_t> tmp_wstring(text_length, 0);
				file->ReadBytes(tmp_wstring.data(), text_length);
				out_string = String(tmp_wstring.data(), text_length);
				return true;
			}
			if (m_text_encoding == 1)
			{
				std::string tmp_string(text_length, 0);
				file->ReadBytes(tmp_string.data(), text_length);
				out_string.SetCString(tmp_string.data(), text_length, STRINGENCODING::UTF8);
				return true;
			}
		}
		else {
			out_string = String{};
			return true;
		}
		out_string = String{};
		return false;
	}
};

class PMXIndexReader
{
	Char m_index_size;
public:
	explicit PMXIndexReader(const Char& index_size) :m_index_size(index_size) {}
	bool operator()(BaseFile* const file, Int32& out_index) const
	{
		// 3种长度不同的Index
		switch (m_index_size)
		{
		case 1:
		{
			Char index;
			file->ReadChar(&index);
			out_index = index == -1 ? -1 : static_cast<UChar>(index);
			break;
		}
		case 2:
		{
			Int16 index;
			file->ReadInt16(&index);
			out_index = index;
			break;
		}
		case 4:
		{
			Int32 index;
			file->ReadInt32(&index);
			out_index = index;
			break;
		}
		default:
			out_index = -1;
			return false;
		}
		return true;
	}
};

class PMXUIndexReader
{
	Char m_index_size;
public:
	explicit PMXUIndexReader(const Char& index_size) :m_index_size(index_size) {}
	bool operator()(BaseFile* const file, UInt32& out_index) const
	{
		// 3种长度不同的Index
		switch (m_index_size) 
		{
		case 1:
		{
			UChar index;
			file->ReadUChar(&index);
			out_index = index;
			break;
		}
		case 2:
		{
			UInt16 index;
			file->ReadUInt16(&index);
			out_index = index;
			break;
		}
		case 4:
		{
			UInt32 index;
			file->ReadUInt32(&index);
			out_index = index;
			break;
		}
		default:
			out_index = 0;
			return false;
		}
		return true;
	}
};

#endif // !_PMX_UTIL_H_

