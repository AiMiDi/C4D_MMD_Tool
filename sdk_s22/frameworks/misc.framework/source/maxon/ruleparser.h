#ifndef RULEPARSER_H__
#define RULEPARSER_H__

#include "maxon/string.h"
#include "maxon/apibase.h"
#include "maxon/basearray.h"
#include "maxon/iostreams.h"

namespace maxon
{

/// Class to evaluate in-/exclusion rules from an ASCII file. The rule parser allows e.g. for simple distillation scripts.
///
/// Scripts are always executed from top to bottom.
///
/// lines that start with + "PATTERN" mean that if the pattern matches the file(s)/directory(s) will be included
/// lines that start with - "PATTERN" mean that if the pattern matches the file(s)/directory(s) will be included
/// lines that contain "A" -> "B" mean that if the pattern matches the file(s)/directory(s) will be renamed
/// "->" can be combined with "+" at the same time
///
/// any path must be surrounded by quotation marks
///
/// patterns that only contain endings do not just check the pattern, but the ending itself (so .pbxproj.user will not match ".pbxproj")
///
/// conditions can be started with
/// if "PATTERN"
/// or
/// ifnot "PATTERN"
///
/// lines that are enclosed with {..} will only be executed if the condition matches
///
///
/// Here an example script:
/// @code
/// + "/_bin/kernel_app.exe" -> "/kernel_app_32bit.exe" // add any files matching "/_bin/kernel_app.exe" and rename the matching part to "/kernel_app_32bit.exe"
///
///	if "/modules/" // if "/modules/" matches
///	{
///		+ ".xdl32"   // add if ".xdl32" matches
/// }
/// @endcode
class RuleParserInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RuleParserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.ruleparser");

public:
	/// allocator for common use.
	static MAXON_METHOD RuleParserInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Initializes the rule set from a file.
	/// @param[in] ruleFile						Name of the file to read the rules from.
	/// @param[in] strDecoding				String Decoding that should be used for the char -> unichar conversion.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Url& ruleFile, const StringDecodingRef& strDecoding);

	//----------------------------------------------------------------------------------------
	/// Checks if a file matches the rule set.
	/// @param[in] relativeName				Relative name of the file, must start with "/", e.g. "/main_dev/test.cpp".
	/// @param[out] outputName				Can be set to nullptr. If present the content is identical to relativeName or, if the rule set contained a rename operation, the modified name.
	/// @return												True if the file matched the rule set and the rule set contained no errors.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool Check(const String& relativeName, String* outputName);
};

class ParseHelper
{
	MAXON_INTERFACE_NONVIRTUAL(ParseHelper, MAXON_REFERENCE_NONE, "net.maxon.interface.parsehelper");

public:
	//----------------------------------------------------------------------------------------
	/// Converts an ASCII file in memory into a array of strings with one string per line.
	/// @param[in] in									Array holding the memory.
	/// @param[out] out								Array holding the lines of the file, will be initialized inside.
	/// @param[in] allowBackSlashToJoinNextLine	True if a backslash at the end of the line joins the next line to the current line. Leading spaces of the next line will be discarded.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertTextToLines(const Block<const Char>& in, const StringDecodingRef& strDecoding, BaseArray<String>& out, Bool allowBackSlashToJoinNextLine);

	//----------------------------------------------------------------------------------------
	/// Converts an Utf32 array in memory into a array of strings with one string per line.
	/// @param[in] in									Array holding the data.
	/// @param[out] out								Array holding the lines of the file, will be initialized inside.
	/// @param[in] allowBackSlashToJoinNextLine	True if a backslash at the end of the line joins the next line to the current line. Leading spaces of the next line will be discarded.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertTextToLines(const BaseArray<Utf32Char>& in, BaseArray<String>& out, Bool allowBackSlashToJoinNextLine);
};

#include "ruleparser1.hxx"

#include "ruleparser2.hxx"

} // namespace maxon

#endif // RULEPARSER_H__
