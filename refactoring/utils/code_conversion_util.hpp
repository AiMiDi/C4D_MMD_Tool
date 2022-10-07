/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			code_conversion_util.hpp
Description:	Character coding conversion util

**************************************************************************/

#ifndef CODE_CONVERSION_UTIL_H_
#define CODE_CONVERSION_UTIL_H_

#include "pch.h"

class code_conversion
{
	libiconv_t m_JIStoU8_conv;
	libiconv_t m_U8toJIS_conv;
	std::vector<Char> m_buffer;
public:
		/**
		 * \brief Converts a UTF8 string to an SHIFT-JIS string.
		 * \param input_string Source UTF8 string
		 * \return Result SHIFT-JIS string
		 */
		static std::string UTF8toSJIS(const String& input_string)
		{
			std::string output_string;
			iferr_scope_handler{
				return output_string;
			};
			size_t input_length = input_string.GetCStringLen(STRINGENCODING::UTF8) + 1ull;
			size_t output_length = input_length * 2;
			output_string.resize(output_length, 0);
			Get().m_buffer.reserve(input_length);
			char* input_men = Get().m_buffer.data();
			input_string.GetCString(input_men, static_cast<Int>(input_length), STRINGENCODING::UTF8);
			char* output_buffer = output_string.data();
			const char* input_buffer = input_men;
			output_length = libiconv(Get().m_JIStoU8_conv, &input_buffer, &input_length, &output_buffer, &output_length);
			output_string.resize(output_length, 0);
			return output_string;
		}
		/**
		 * \brief Converts a UTF8 string to an SHIFT-JIS string.
		 * \param input_string Source UTF8 string
		 * \return Result SHIFT-JIS string
		 */
		static std::string UTF8toSJIS(const std::string& input_string)
		{
			std::string output_string{};
			iferr_scope_handler{
				return output_string;
			};
			size_t input_length = input_string.length() + 1ull;
			size_t output_length = input_length * 2;
			Get().m_buffer.reserve(input_length);
			output_string.resize(output_length);
			char* output_buffer = output_string.data();
			const char* input_buffer = input_string.data();
			output_length = libiconv(Get().m_JIStoU8_conv, &input_buffer, &input_length, &output_buffer, &output_length);
			output_string.resize(output_length, 0);
			return output_string;
		}
		/**
		 * \brief Converts a SHIFT-JIS string to an UTF8 string.
		 * \param input_string Source SHIFT-JIS string
		 * \param input_string_length Source SHIFT-JIS string length
		 * \return Result UTF8 string
		 */
		static String SJIStoUTF8(const char* input_string, const Int64 input_string_length = -1)
		{
			String output_string{};
			iferr_scope_handler{
				return output_string;
			};
			if (input_string == nullptr || input_string_length == 0)
			{
				return output_string;
			}
			size_t input_length;
			if (input_string_length == -1)
			{
				input_length = strlen(input_string) + 1;
				if (input_length == 1)
				{
					return output_string;
				}
			}
			else {
				input_length = input_string_length;
			}
			size_t output_length = input_length * 2;
			Get().m_buffer.reserve(output_length);
			char* output_men = Get().m_buffer.data();
			char* output_buffer = output_men;
			const char* input_buffer = input_string;
			if (output_length = libiconv(Get().m_U8toJIS_conv, &input_buffer, &input_length, &output_buffer, &output_length); output_length == static_cast<size_t>(-1))
			{
				return output_string;
			}
			output_string.SetCString(output_men, static_cast<Int>(output_length), STRINGENCODING::UTF8);
			return output_string;
		}
		/**
		 * \brief Converts a SHIFT-JIS string to an UTF8 string.
		 * \param input_string Source SHIFT-JIS string
		 * \return Result UTF8 string
		 */
		static std::string SJIStoUTF8(const std::string& input_string)
		{
			std::string output_string{};
			iferr_scope_handler{
				return output_string;
			};
			size_t input_length = input_string.length();
			size_t output_length = input_length * 2;
			Get().m_buffer.reserve(output_length);
			char* output_men = Get().m_buffer.data();
			char* output_buffer = output_men;
			const char* input_buffer = input_string.data();
			if (output_length = libiconv(Get().m_U8toJIS_conv, &input_buffer, &input_length, &output_buffer, &output_length); output_length == static_cast<size_t>(-1))
			{
				return output_string;
			}
			output_string.assign(output_men, output_length);
			return output_string;
		}

		code_conversion(const code_conversion&) = delete;
		void operator =(const code_conversion&) = delete;
		code_conversion(code_conversion&&) = delete;
		void operator=(code_conversion&&) = delete;
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

#endif // !CODE_CONVERSION_UTIL_H_
