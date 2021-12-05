#include "lib_token.h"

static TokenLibrary* token_lib_cache = nullptr;

static TokenLibrary* CheckTokenLib(Int32 offset)
{
	return (TokenLibrary*)CheckLib(ID_TOKEN_LIB, offset, (C4DLibrary**)&token_lib_cache);
}

Bool GetAllTokenEntries(maxon::BaseArray<TokenEntry>& tokenList)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, GetAllTokenEntries));
	if (!lib || !lib->GetAllTokenEntries)
		return false;

	return lib->GetAllTokenEntries(tokenList);
}

String StringConvertTokens(const String& path, const RenderPathData* rpData)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, StringConvertTokens));
	if (!lib || !lib->StringConvertTokens)
		return String();

	return lib->StringConvertTokens(path, rpData);
}

Filename FilenameConvertTokens(const Filename& path, const RenderPathData* rpData)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, FilenameConvertTokens));
	if (!lib || !lib->FilenameConvertTokens)
		return Filename(String());

	return lib->FilenameConvertTokens(path, rpData);
}

String StringConvertTokensFilter(const String& path, const RenderPathData* rpData, const maxon::BaseArray<String>& exclude)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, FilenameConvertTokens));
	if (!lib || !lib->StringConvertTokensFilter)
		return String();

	return lib->StringConvertTokensFilter(path, rpData, exclude);
}

Filename FilenameConvertTokensFilter(const Filename& path, const RenderPathData* rpData, const maxon::BaseArray<String>& exclude)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, FilenameConvertTokens));
	if (!lib || !lib->FilenameConvertTokensFilter)
		return Filename(String());

	return lib->FilenameConvertTokensFilter(path, rpData, exclude);
}

String StringExtractRoot(const String& path)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, StringExtractRoot));
	if (!lib || !lib->StringExtractRoot)
		return String();

	return lib->StringExtractRoot(path);
}

Filename FilenameExtractRoot(const Filename& path)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, FilenameExtractRoot));
	if (!lib || !lib->FilenameExtractRoot)
		return Filename(String());

	return lib->FilenameExtractRoot(path);
}

Bool FilenameSlicePath(const Filename& path, Filename& root, Filename& fileName)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, FilenameSlicePath));
	if (!lib || !lib->FilenameSlicePath)
		return false;

	return lib->FilenameSlicePath(path, root, fileName);
}

Bool RegisterToken(const String& key, const String& help, const String& example, TOKENHOOK* hook)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, RegisterToken));
	if (!lib || !lib->RegisterToken)
		return false;

	return lib->RegisterToken(key, help, example, hook);
}

Bool RegisterHiddenToken(const String& key, const String& help, const String& example, TOKENHOOK* hook)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, RegisterHiddenToken));
	if (!lib || !lib->RegisterHiddenToken)
		return false;

	return lib->RegisterHiddenToken(key, help, example, hook);
}

Bool RegisterPythonToken(const String& key, const String& help, const String& example, void* callback)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, RegisterPythonToken));
	if (!lib || !lib->RegisterPythonToken)
		return false;

	return lib->RegisterPythonToken(key, help, example, callback);
}

Bool RegisterPythonHiddenToken(const String& key, const String& help, const String& example, void* callback)
{
	TokenLibrary* lib = CheckTokenLib(LIBOFFSET(TokenLibrary, RegisterPythonHiddenToken));
	if (!lib || !lib->RegisterPythonHiddenToken)
		return false;

	return lib->RegisterPythonHiddenToken(key, help, example, callback);
}
