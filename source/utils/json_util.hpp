/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2026/2/28
File:			json_util.hpp
Description:	Lightweight JSON reader/writer (header-only).
				Supports flat JSON objects with bool/int/double/string values.
				Uses C4D Filename/BaseFile for file I/O.

**************************************************************************/

#pragma once

#include <string>
#include <unordered_map>
#include <variant>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <c4d.h>
#include <cstdlib>
#include <cerrno>
#include <climits>

namespace cmt_json
{

using JsonValue = std::variant<bool, int, double, std::string>;
using JsonObject = std::unordered_map<std::string, JsonValue>;

namespace detail
{
	inline void SkipWhitespace(const std::string& s, size_t& pos)
	{
		while (pos < s.size() && (s[pos] == ' ' || s[pos] == '\t' || s[pos] == '\n' || s[pos] == '\r'))
			++pos;
	}

	inline char Peek(const std::string& s, size_t pos)
	{
		if (pos >= s.size())
			throw std::runtime_error("JSON: unexpected end of input");
		return s[pos];
	}

	inline void Expect(const std::string& s, size_t& pos, char c)
	{
		SkipWhitespace(s, pos);
		if (pos >= s.size() || s[pos] != c)
			throw std::runtime_error(std::string("JSON: expected '") + c + "'");
		++pos;
	}

	inline std::string ParseString(const std::string& s, size_t& pos)
	{
		SkipWhitespace(s, pos);
		Expect(s, pos, '"');
		std::string result;
		while (pos < s.size() && s[pos] != '"')
		{
			if (s[pos] == '\\')
			{
				++pos;
				if (pos >= s.size())
					throw std::runtime_error("JSON: unexpected end in string escape");
				switch (s[pos])
				{
				case '"':  result += '"'; break;
				case '\\': result += '\\'; break;
				case '/':  result += '/'; break;
				case 'b':  result += '\b'; break;
				case 'f':  result += '\f'; break;
				case 'n':  result += '\n'; break;
				case 'r':  result += '\r'; break;
				case 't':  result += '\t'; break;
				case 'u':
				{
					if (pos + 4 >= s.size())
						throw std::runtime_error("JSON: incomplete \\u escape");
					unsigned cp = 0;
					for (int i = 0; i < 4; ++i)
					{
						++pos;
						char ch = s[pos];
						cp <<= 4;
						if (ch >= '0' && ch <= '9') cp |= (ch - '0');
						else if (ch >= 'a' && ch <= 'f') cp |= (ch - 'a' + 10);
						else if (ch >= 'A' && ch <= 'F') cp |= (ch - 'A' + 10);
						else throw std::runtime_error("JSON: invalid \\u hex digit");
					}
					if (cp <= 0x7F)
					{
						result += static_cast<char>(cp);
					}
					else if (cp <= 0x7FF)
					{
						result += static_cast<char>(0xC0 | (cp >> 6));
						result += static_cast<char>(0x80 | (cp & 0x3F));
					}
					else
					{
						result += static_cast<char>(0xE0 | (cp >> 12));
						result += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
						result += static_cast<char>(0x80 | (cp & 0x3F));
					}
					break;
				}
				default:
					result += s[pos];
					break;
				}
			}
			else
			{
				result += s[pos];
			}
			++pos;
		}
		if (pos >= s.size())
			throw std::runtime_error("JSON: unterminated string");
		++pos; // skip closing '"'
		return result;
	}

	inline JsonValue ParseValue(const std::string& s, size_t& pos)
	{
		SkipWhitespace(s, pos);
		char c = Peek(s, pos);

		if (c == '"')
			return ParseString(s, pos);

		if (c == 't')
		{
			if (s.compare(pos, 4, "true") == 0)
			{
				pos += 4;
				return true;
			}
			throw std::runtime_error("JSON: invalid token");
		}

		if (c == 'f')
		{
			if (s.compare(pos, 5, "false") == 0)
			{
				pos += 5;
				return false;
			}
			throw std::runtime_error("JSON: invalid token");
		}

		if (c == 'n')
		{
			if (s.compare(pos, 4, "null") == 0)
			{
				pos += 4;
				return std::string{};
			}
			throw std::runtime_error("JSON: invalid token");
		}

		// Number
		size_t start = pos;
		bool is_float = false;
		if (s[pos] == '-')
			++pos;
		while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
			++pos;
		if (pos < s.size() && s[pos] == '.')
		{
			is_float = true;
			++pos;
			while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
				++pos;
		}
		if (pos < s.size() && (s[pos] == 'e' || s[pos] == 'E'))
		{
			is_float = true;
			++pos;
			if (pos < s.size() && (s[pos] == '+' || s[pos] == '-'))
				++pos;
			while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
				++pos;
		}

		if (pos == start)
			throw std::runtime_error("JSON: invalid value");

		std::string num_str = s.substr(start, pos - start);
		if (is_float)
			return std::stod(num_str);

		long long val = std::stoll(num_str);
		if (val >= INT_MIN && val <= INT_MAX)
			return static_cast<int>(val);
		return static_cast<double>(val);
	}

	inline JsonObject ParseObject(const std::string& s, size_t& pos)
	{
		JsonObject obj;
		SkipWhitespace(s, pos);
		Expect(s, pos, '{');
		SkipWhitespace(s, pos);

		if (pos < s.size() && s[pos] == '}')
		{
			++pos;
			return obj;
		}

		for (;;)
		{
			std::string key = ParseString(s, pos);
			SkipWhitespace(s, pos);
			Expect(s, pos, ':');
			JsonValue val = ParseValue(s, pos);
			obj[std::move(key)] = std::move(val);

			SkipWhitespace(s, pos);
			if (pos >= s.size())
				throw std::runtime_error("JSON: unexpected end of object");
			if (s[pos] == '}')
			{
				++pos;
				return obj;
			}
			Expect(s, pos, ',');
		}
	}

	inline std::string EscapeString(const std::string& s)
	{
		std::string out;
		out.reserve(s.size() + 2);
		out += '"';
		for (unsigned char c : s)
		{
			switch (c)
			{
			case '"':  out += "\\\""; break;
			case '\\': out += "\\\\"; break;
			case '\b': out += "\\b"; break;
			case '\f': out += "\\f"; break;
			case '\n': out += "\\n"; break;
			case '\r': out += "\\r"; break;
			case '\t': out += "\\t"; break;
			default:
				if (c < 0x20)
				{
					char buf[8];
					snprintf(buf, sizeof(buf), "\\u%04x", c);
					out += buf;
				}
				else
				{
					out += static_cast<char>(c);
				}
				break;
			}
		}
		out += '"';
		return out;
	}

	inline std::string SerializeValue(const JsonValue& val)
	{
		struct Visitor
		{
			std::string operator()(bool v) const { return v ? "true" : "false"; }
			std::string operator()(int v) const { return std::to_string(v); }
			std::string operator()(double v) const
			{
				std::ostringstream oss;
				oss << std::setprecision(17) << v;
				std::string s = oss.str();
				if (s.find('.') == std::string::npos && s.find('e') == std::string::npos && s.find('E') == std::string::npos)
					s += ".0";
				return s;
			}
			std::string operator()(const std::string& v) const { return EscapeString(v); }
		};
		return std::visit(Visitor{}, val);
	}

} // namespace detail

/// Parse a JSON object from a string.
inline JsonObject Parse(const std::string& json_text)
{
	size_t pos = 0;
	return detail::ParseObject(json_text, pos);
}

/// Serialize a JsonObject to a formatted JSON string.
inline std::string Serialize(const JsonObject& obj, bool pretty = true)
{
	std::string out;
	out += '{';
	if (pretty)
		out += '\n';

	size_t i = 0;
	const size_t count = obj.size();
	for (const auto& [key, value] : obj)
	{
		if (pretty)
			out += '\t';
		out += detail::EscapeString(key);
		out += ':';
		if (pretty)
			out += ' ';
		out += detail::SerializeValue(value);
		if (i + 1 < count)
			out += ',';
		if (pretty)
			out += '\n';
		++i;
	}

	out += '}';
	if (pretty)
		out += '\n';
	return out;
}

/// Read a JSON object from a file. Returns empty object on failure.
inline JsonObject ReadJsonFile(const Filename& path)
{
	AutoAlloc<BaseFile> file;
	if (!file || !file->Open(path, FILEOPEN::READ))
		return {};

	const Int64 len = file->GetLength();
	if (len <= 0)
	{
		file->Close();
		return {};
	}

	std::string content(static_cast<size_t>(len), '\0');
	if (!file->ReadBytes(&content[0], len))
	{
		file->Close();
		return {};
	}
	file->Close();

	try
	{
		return Parse(content);
	}
	catch (const std::runtime_error&)
	{
		return {};
	}
}

/// Write a JSON object to a file. Returns true on success.
inline bool WriteJsonFile(const Filename& path, const JsonObject& obj, bool pretty = true)
{
	AutoAlloc<BaseFile> file;
	if (!file || !file->Open(path, FILEOPEN::WRITE))
		return false;

	std::string data = Serialize(obj, pretty);
	bool ok = file->WriteBytes(data.data(), static_cast<Int>(data.size()));
	file->Close();
	return ok;
}

} // namespace cmt_json
