#include "utils/cmt_release_json.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>

namespace
{
void Require(bool value, const char* message)
{
	if (!value) { std::cerr << message << '\n'; std::exit(EXIT_FAILURE); }
}
}

int main(int argc, char** argv)
{
	using namespace cmt_update;
	Require(IsNewer("0.9.3.2", "v0.9.3.10"), "fourth component must compare numerically");
	Require(IsNewer("0.9.9.99", "0.10.0"), "minor rollover");
	Require(IsNewer("0.99.99", "1.0.0"), "major rollover");
	Require(SameVersion("v1.2.3", "1.2.3.0"), "optional prefix and fourth zero");
	Require(!IsNewer("1.2.3", "1.2.2.99"), "older version");
	for (const auto* invalid : {"", "v", "1.2", "1.2.3.", "1.2.3.4.5", "1..3", "1.2.3-beta",
		"1.2.3+build", "1.2.-3", "1.2.4294967296", " 1.2.3", "1.2.3/path"})
		Require(!ParseVersion(invalid), "invalid version must be rejected");
	Require(!IsNewer("", "9.9.9"), "unknown installed version must not notify");
	Require(CheckDue(true, 0, 100), "first automatic check");
	Require(!CheckDue(false, 0, 100), "disabled checks");
	Require(!CheckDue(true, 100, 100 + CheckInterval - 1), "daily throttle");
	Require(CheckDue(true, 100, 100 + CheckInterval), "daily boundary");
	Require(CheckDue(true, 200, 100), "clock correction");
	Require(!ShouldRemind("1.0.0", "v1.1.0", "1.1.0.0", true, false), "ignore normalized identity");
	Require(ShouldRemind("1.0.0", "1.1.1", "1.1.0", true, false), "later release after ignore");
	Require(!ShouldRemind("1.0.0", "1.1.0", "", false, false), "disabled automatic reminder");
	Require(ShouldRemind("1.0.0", "v1.1.0", "1.1.0", false, true), "manual bypasses ignore and disable");
	Require(PageForVersion("1.2.3/path") == ReleasePage, "unsafe tag must not become a URL");
	Require(PageForVersion("v1.2.3") == std::string(ReleasePage) + "/tag/v1.2.3", "fixed project page");
	const auto release = ParseStableRelease(R"({"author":{"tag_name":"99.0.0","draft":true},"assets":[{"name":"a\\b\"c","size":12.3e+2}],"tag_name":"v0.9.3.10","draft":false,"prerelease":false,"body":"\u4e2d\u6587"})");
	Require(release && release->tag == "v0.9.3.10", "nested real release shape");
	Require(release->notes == u8"\u4e2d\u6587", "Unicode release notes decoded");
	Require(ParseStableRelease(R"({"tag_name":"\u00761.2.3","draft":false,"prerelease":false})")->tag == "v1.2.3", "escaped numeric tag");
	const std::string bilingual = u8"# Shared title\n## \u4e2d\u6587\n\u4e2d\u6587\u66f4\u65b0\n### Detail\n- C\n## English\nEnglish update\n## Build and downloads\nInternal metadata";
	Require(LocalizedNotes(bilingual, true) == u8"\u4e2d\u6587\u66f4\u65b0\n### Detail\n- C\n", "Chinese section only");
	Require(LocalizedNotes(bilingual, false) == "English update\n", "English section only");
	Require(LocalizedNotes("## English\nEnglish only", true).empty(), "missing Chinese translation uses UI fallback");
	Require(LocalizedNotes("Single-language notes", false) == "Single-language notes", "unstructured release notes");
	Require(WrapCjkNotes(u8"\u4e2d\u6587\u66f4\u65b0", 4) == u8"\u4e2d\u6587\n\u66f4\u65b0", "CJK display wraps without splitting UTF-8");
	Require(WrapCjkNotes(u8"\u4e2d\u6587 worker_count \u4e2d\u6587", 16) == u8"\u4e2d\u6587 \nworker_count \u4e2d\n\u6587", "CJK wrapping preserves inline Latin words");
	Require(WrapCjkNotes(u8"\u4e2d\u6587\n\u66f4\u65b0", 4) == u8"\u4e2d\u6587\n\u66f4\u65b0", "existing release-note line breaks preserved");
	Require(LocalizedNotes("## en-US \r\nEnglish\r\n## zh-CN\r\nChinese\r\n", true) == "Chinese\r\n", "CRLF language headings");
	const auto emoji = ParseStableRelease(R"({"tag_name":"1.2.3","draft":false,"prerelease":false,"body":"\ud83d\ude00"})");
	Require(emoji && emoji->notes == "\xf0\x9f\x98\x80", "Unicode surrogate pair");
	for (const auto* invalid : {
		R"({"message":"API rate limit exceeded"})",
		R"({"tag_name":"1.2.3","draft":true,"prerelease":false})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":true})",
		R"({"tag_name":"1.2.3-beta","draft":false,"prerelease":false})",
		R"({"tag_name":"1.2.3","draft":"false","prerelease":false})",
		R"({"tag_name":"1.2.3","draft":false})",
		R"({"nested":{"tag_name":"1.2.3","draft":false,"prerelease":false}})",
		R"({"tag_name":"1.2.3","tag_name":"9.9.9","draft":false,"prerelease":false})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false,"x":01})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false,"x":- 1})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false,"x":[1,]})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false,"body":"\ud800"})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false,"body":"\udc00"})",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false} trailing)",
		R"({"tag_name":"1.2.3","draft":false,"prerelease":false)", "<html>error</html>"})
		Require(!ParseStableRelease(invalid), "malformed/nonstable response rejected");
	Require(!ParseStableRelease(std::string(1024 * 1024 + 1, ' ')), "response size limit");
	Require(!ParseStableRelease("{\"x\":" + std::string(33, '[') + "0" + std::string(33, ']') + "}"), "JSON nesting limit");
	if (argc > 1)
	{
		std::ifstream file(argv[1], std::ios::binary);
		Require(file.is_open(), "live API fixture must exist");
		const std::string json{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
		const auto live = ParseStableRelease(json);
		Require(live && !live->notes.empty(), "live release identity and body parsed");
		Require(!LocalizedNotes(live->notes, true).empty() && !LocalizedNotes(live->notes, false).empty(), "live bilingual release sections");
		std::cout << "Live release fixture passed: " << live->tag << '\n';
	}
	std::cout << "Update version, throttle, reminder and release JSON cases passed\n";
}
