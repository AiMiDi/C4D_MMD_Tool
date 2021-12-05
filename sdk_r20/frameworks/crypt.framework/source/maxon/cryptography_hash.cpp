#include "maxon/cryptography_hash.h"
#include "maxon/stringencoding.h"


namespace maxon
{

Result<String> GetHashString(const BaseArray<UChar>& hashValue)
{
	String hash;
	for (auto c : hashValue)
		hash += FormatString("@{2x'0'}", c);

	return hash;
}

Result<String> GetPasswordHash(const String& password, const StreamConversionFactory& hashClass, const DataDictionary& settings)
{
	iferr_scope;

	BaseArray<Char> passwdchr = password.GetCString(StringEncodings::Utf8()) iferr_return;

	StreamConversionRef hash = hashClass.Create(settings) iferr_return;

	BaseArray<UChar> hashValue;
	hash.ConvertAll(passwdchr, hashValue) iferr_return;

	String hashStr = GetHashString(hashValue) iferr_return;

	return hashStr;
}

}
