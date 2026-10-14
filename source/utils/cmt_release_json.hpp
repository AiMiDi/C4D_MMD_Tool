#pragma once

#include "cmt_update_policy.hpp"
#include <cctype>
#include <stdexcept>
#include <unordered_set>

namespace cmt_update
{
struct Release
{
	std::string tag;
	std::string notes;
};
// Only release identity and channel flags are retained. Unknown fields are
// structurally parsed, including nested assets/author data, never regex-matched.
class ReleaseJsonReader
{
public:
	explicit ReleaseJsonReader(std::string_view input) : input_(input) {}

	std::optional<Release> Read()
	{
		try
		{
			Object(0);
			Whitespace();
			if (position_ != input_.size() || !tagSeen_ || !draftSeen_ || !prereleaseSeen_ ||
				draft_ || prerelease_ || !ParseVersion(tag_)) return std::nullopt;
			return Release{tag_, notes_};
		}
		catch (const std::runtime_error&) { return std::nullopt; }
	}

private:
	std::string_view input_;
	std::size_t position_ = 0;
	std::string tag_, notes_;
	bool tagSeen_ = false, draftSeen_ = false, prereleaseSeen_ = false;
	bool draft_ = false, prerelease_ = false;

	[[noreturn]] static void Invalid() { throw std::runtime_error("Invalid release JSON"); }
	void Whitespace()
	{
		while (position_ < input_.size() && (input_[position_] == ' ' || input_[position_] == '\t' ||
			input_[position_] == '\r' || input_[position_] == '\n')) ++position_;
	}
	bool Take(char token)
	{
		Whitespace();
		if (position_ == input_.size() || input_[position_] != token) return false;
		++position_;
		return true;
	}
	void Expect(char token) { if (!Take(token)) Invalid(); }
	bool Literal(std::string_view token)
	{
		Whitespace();
		if (input_.substr(position_, token.size()) != token) return false;
		position_ += token.size();
		return true;
	}
	bool Boolean()
	{
		if (Literal("true")) return true;
		if (Literal("false")) return false;
		Invalid();
	}
	unsigned HexCodepoint()
	{
		unsigned value = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (position_ == input_.size()) Invalid();
			const char hex = input_[position_++];
			unsigned digit;
			if (hex >= '0' && hex <= '9') digit = hex - '0';
			else if (hex >= 'a' && hex <= 'f') digit = hex - 'a' + 10;
			else if (hex >= 'A' && hex <= 'F') digit = hex - 'A' + 10;
			else Invalid();
			value = value * 16 + digit;
		}
		return value;
	}
	static void AppendUtf8(std::string& value, unsigned codepoint)
	{
		if (codepoint < 0x80) value += static_cast<char>(codepoint);
		else if (codepoint < 0x800)
		{
			value += static_cast<char>(0xc0 | (codepoint >> 6));
			value += static_cast<char>(0x80 | (codepoint & 0x3f));
		}
		else
		{
			if (codepoint >= 0x10000)
			{
				value += static_cast<char>(0xf0 | (codepoint >> 18));
				value += static_cast<char>(0x80 | ((codepoint >> 12) & 0x3f));
			}
			else value += static_cast<char>(0xe0 | (codepoint >> 12));
			value += static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f));
			value += static_cast<char>(0x80 | (codepoint & 0x3f));
		}
	}
	std::string String()
	{
		Expect('"');
		std::string value;
		while (position_ < input_.size())
		{
			char c = input_[position_++];
			if (c == '"') return value;
			if (static_cast<unsigned char>(c) < 32) Invalid();
			if (c == '\\')
			{
				if (position_ == input_.size()) Invalid();
				c = input_[position_++];
				switch (c)
				{
				case '"': case '\\': case '/': break;
				case 'b': c = '\b'; break;
				case 'f': c = '\f'; break;
				case 'n': c = '\n'; break;
				case 'r': c = '\r'; break;
				case 't': c = '\t'; break;
				case 'u':
				{
					unsigned codepoint = HexCodepoint();
					if (codepoint >= 0xd800 && codepoint <= 0xdbff)
					{
						if (input_.substr(position_, 2) != "\\u") Invalid();
						position_ += 2;
						const unsigned low = HexCodepoint();
						if (low < 0xdc00 || low > 0xdfff) Invalid();
						codepoint = 0x10000 + ((codepoint - 0xd800) << 10) + (low - 0xdc00);
					}
					else if (codepoint >= 0xdc00 && codepoint <= 0xdfff) Invalid();
					AppendUtf8(value, codepoint);
					continue;
				}
				default: Invalid();
				}
			}
			value += c;
		}
		Invalid();
	}
	void Number()
	{
		if (position_ < input_.size() && input_[position_] == '-') ++position_;
		const auto digits = [this]()
		{
			const auto begin = position_;
			while (position_ < input_.size() && input_[position_] >= '0' && input_[position_] <= '9') ++position_;
			if (position_ == begin) Invalid();
		};
		if (position_ < input_.size() && input_[position_] == '0') ++position_;
		else digits();
		if (position_ < input_.size() && input_[position_] == '.') { ++position_; digits(); }
		if (position_ < input_.size() && (input_[position_] == 'e' || input_[position_] == 'E'))
		{
			++position_;
			if (position_ < input_.size() && (input_[position_] == '+' || input_[position_] == '-')) ++position_;
			digits();
		}
	}
	void Value(unsigned depth)
	{
		Whitespace();
		if (depth > 32 || position_ == input_.size()) Invalid();
		switch (input_[position_])
		{
		case '{': Object(depth); break;
		case '[':
			++position_;
			if (!Take(']'))
			{
				do { Value(depth + 1); } while (Take(','));
				Expect(']');
			}
			break;
		case '"': String(); break;
		case 't': case 'f': Boolean(); break;
		case 'n': if (!Literal("null")) Invalid(); break;
		default: Number(); break;
		}
	}
	void Object(unsigned depth)
	{
		if (depth > 32) Invalid();
		Expect('{');
		if (Take('}')) return;
		std::unordered_set<std::string> keys;
		do
		{
			const auto key = String();
			if (!keys.insert(key).second) Invalid();
			Expect(':');
			if (depth == 0 && key == "tag_name") { tag_ = String(); tagSeen_ = true; }
			else if (depth == 0 && key == "body") { if (!Literal("null")) notes_ = String(); }
			else if (depth == 0 && key == "draft") { draft_ = Boolean(); draftSeen_ = true; }
			else if (depth == 0 && key == "prerelease") { prerelease_ = Boolean(); prereleaseSeen_ = true; }
			else Value(depth + 1);
		} while (Take(','));
		Expect('}');
	}
};

inline std::optional<Release> ParseStableRelease(std::string_view json)
{
	if (json.empty() || json.size() > 1024 * 1024) return std::nullopt;
	return ReleaseJsonReader(json).Read();
}
}
