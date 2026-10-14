#pragma once

#include <array>
#include <cstdint>
#include <limits>
#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

namespace cmt_update
{
inline constexpr std::int64_t CheckInterval = 24 * 60 * 60;
inline constexpr std::string_view ReleasePage = "https://github.com/AiMiDi/C4D_MMD_Tool/releases";

struct Version
{
	std::array<std::uint32_t, 4> parts{};
	bool operator==(const Version& other) const { return parts == other.parts; }
	bool operator<(const Version& other) const { return parts < other.parts; }
};

inline std::optional<Version> ParseVersion(std::string_view text)
{
	if (!text.empty() && text.front() == 'v') text.remove_prefix(1);
	Version version;
	std::size_t component = 0;
	while (!text.empty() && component < version.parts.size())
	{
		const auto end = text.find('.');
		const auto digits = text.substr(0, end);
		if (digits.empty()) return std::nullopt;
		std::uint32_t value = 0;
		for (const char digit : digits)
		{
			if (digit < '0' || digit > '9' ||
				value > (std::numeric_limits<std::uint32_t>::max() - (digit - '0')) / 10)
				return std::nullopt;
			value = value * 10 + (digit - '0');
		}
		version.parts[component++] = value;
		if (end == std::string_view::npos) return component >= 3 ? std::optional<Version>(version) : std::nullopt;
		text.remove_prefix(end + 1);
	}
	return std::nullopt;
}

inline bool SameVersion(std::string_view first, std::string_view second)
{
	const auto a = ParseVersion(first), b = ParseVersion(second);
	return a && b && *a == *b;
}

inline bool IsNewer(std::string_view installed, std::string_view latest)
{
	const auto a = ParseVersion(installed), b = ParseVersion(latest);
	return a && b && *a < *b;
}

inline bool CheckDue(bool enabled, std::int64_t lastAttempt, std::int64_t now)
{
	// A clock correction must not suppress automatic checks indefinitely.
	return enabled && (lastAttempt <= 0 || now < lastAttempt || now - lastAttempt >= CheckInterval);
}

inline bool ShouldRemind(std::string_view installed, std::string_view latest,
	std::string_view ignored, bool enabled, bool manual)
{
	return IsNewer(installed, latest) && (manual || (enabled && !SameVersion(latest, ignored)));
}

inline std::string PageForVersion(std::string_view tag)
{
	return ParseVersion(tag) ? std::string(ReleasePage) + "/tag/" + std::string(tag) : std::string(ReleasePage);
}

inline std::string LocalizedNotes(std::string_view body, bool chinese)
{
	std::string english, chineseNotes;
	enum class Section { Other, Chinese, English } section = Section::Other;
	bool hasLanguageSections = false;
	std::size_t offset = 0;
	while (offset < body.size())
	{
		const auto end = body.find('\n', offset);
		const auto line = body.substr(offset, end == std::string_view::npos ? body.size() - offset : end - offset);
		std::string normalized(line);
		while (!normalized.empty() && (normalized.back() == '\r' || normalized.back() == ' ' || normalized.back() == '\t'))
			normalized.pop_back();
		std::transform(normalized.begin(), normalized.end(), normalized.begin(), [](unsigned char c)
			{ return c >= 'A' && c <= 'Z' ? static_cast<char>(c + 'a' - 'A') : static_cast<char>(c); });
		if (line.substr(0, 3) == "## ")
		{
			if (normalized == "## english" || normalized == "## en-us")
			{ section = Section::English; hasLanguageSections = true; }
			else if (normalized == "## \xe4\xb8\xad\xe6\x96\x87" || normalized == "## zh-cn" ||
				normalized == "## simplified chinese")
			{ section = Section::Chinese; hasLanguageSections = true; }
			else section = Section::Other;
		}
		else if (section == Section::Chinese) { chineseNotes.append(line); chineseNotes += '\n'; }
		else if (section == Section::English) { english.append(line); english += '\n'; }
		if (end == std::string_view::npos) break;
		offset = end + 1;
	}
	if (!hasLanguageSections) return std::string(body);
	// A missing translation is handled by localized UI fallback text, not by
	// silently showing the opposite language or combined build metadata.
	return chinese ? chineseNotes : english;
}

// The host edit control wraps at spaces but leaves long CJK runs clipped.
// Insert conservative line breaks for its minimum width, preserving UTF-8
// characters and keeping inline Latin words together.
inline std::string WrapCjkNotes(std::string_view notes, std::size_t columns = 80)
{
	std::string result;
	std::size_t width = 0;
	for (std::size_t offset = 0; offset < notes.size();)
	{
		const auto first = static_cast<unsigned char>(notes[offset]);
		if (first == '\n') { result += '\n'; width = 0; ++offset; continue; }
		std::size_t length = 1, tokenWidth = 1;
		if (first >= 0x80)
		{
			length = first < 0xe0 ? 2 : first < 0xf0 ? 3 : 4;
			length = std::min(length, notes.size() - offset);
			tokenWidth = 2;
		}
		else if (first != ' ' && first != '\t' && first != '\r')
		{
			while (offset + length < notes.size())
			{
				const auto next = static_cast<unsigned char>(notes[offset + length]);
				if (next >= 0x80 || next == ' ' || next == '\t' || next == '\r' || next == '\n') break;
				++length;
			}
			tokenWidth = length;
		}
		if (width && width + tokenWidth > columns) { result += '\n'; width = 0; }
		result.append(notes.substr(offset, length));
		width += tokenWidth;
		offset += length;
	}
	return result;
}
}
