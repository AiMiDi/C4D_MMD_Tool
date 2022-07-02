/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			code_conversion_util.hpp
Description:	Character coding conversion util

**************************************************************************/

#ifndef _CODE_CONVERSION_UTIL_H_
#define _CODE_CONVERSION_UTIL_H_

#include "pch.h"

class code_conversion
{
	libiconv_t m_JIStoU8_conv;
	libiconv_t m_U8toJIS_conv;
	std::vector<Char> m_buffer;
public:
	/**
		 * \brief Converts a UTF8 string to an SHIFT-JIS string.
		 * \param strin Source UTF8 string
		 * \param strout Result SHIFT-JIS string
		 * \return Result SHIFT-JIS string length
		 */
		static size_t UTF8toSJIS(const String& strin, char* strout)
		{
			iferr_scope_handler{
				return false;
			};
			size_t length_i = strin.GetCStringLen(STRINGENCODING::UTF8) + 1ull;
			size_t length_o = length_i * 2;
			Get().m_buffer.reserve(length_i);
			char* inmen = Get().m_buffer.data();
			strin.GetCString(inmen, static_cast<Int>(length_i), STRINGENCODING::UTF8);
			char* outbuf = strout;
			char* inbuf = inmen;
			length_o = libiconv(Get().m_JIStoU8_conv, &inbuf, &length_i, &outbuf, &length_o);
			return length_o;
		}

	/**
		 * \brief Converts a SHIFT-JIS string to an UTF8 string.
		 * \param strin Source SHIFT-JIS string
		 * \param strin_length Source SHIFT-JIS string length
		 * \return Result UTF8 string
		 */
		static String SJIStoUTF8(char* strin, const Int64 strin_length = -1)
		{
			iferr_scope_handler{
				return String{};
			};
			if (strin == nullptr || strin_length == 0)
			{
				return String{};
			}
			size_t length_i;
			if (strin_length == -1)
			{
				length_i = strlen(strin) + 1;
				if (strin_length == 1)
				{
					return String{};
				}
			}
			else {
				length_i = strin_length;
			}
			size_t length_o = length_i * 2;
			Get().m_buffer.reserve(length_o);
			char* outmen =Get().m_buffer.data();
			char* outbuf = outmen;
			if (length_o = libiconv(Get().m_U8toJIS_conv, &strin, &length_i, &outbuf, &length_o); length_o == static_cast<size_t>(-1))
			{
				return String{};
			}
			String res;
			res.SetCString(outmen, static_cast<Int>(length_o), STRINGENCODING::UTF8);
			return res;
		}
private:
	code_conversion() :
		m_JIStoU8_conv(libiconv_open("SHIFT_JIS", "UTF-8")),
		m_U8toJIS_conv(libiconv_open("UTF-8", "SHIFT_JIS")),
		m_buffer(1024) {}

	~code_conversion()
	{
		libiconv_close(m_JIStoU8_conv);
		libiconv_close(m_U8toJIS_conv);
	}
	static code_conversion& Get()
	{
		static code_conversion instance;
		return instance;
	}
};

#endif // !_CODE_CONVERSION_UTIL_H_