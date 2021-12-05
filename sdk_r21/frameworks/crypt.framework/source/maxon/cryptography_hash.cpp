#include "maxon/cryptography_hash.h"
#include "maxon/secure_random.h"
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

Result<Tuple<String, String>> HashPasswordWithSalt(const String& password, const StreamConversionFactory& hashClass)
{
	iferr_scope;

	// create a random salt
	// the salt should have the same length as the hash
	SecureRandomProvider provider = SecureRandom::GetDefaultProvider();
	BaseArray<UChar> rndBuffer;
	rndBuffer.Resize(64) iferr_return;
	Bool res = SecureRandom::GetRandomNumber(provider, rndBuffer);
	CheckArgument(res == true);

	StreamConversionRef encoderRef = StreamConversions::Base64Encoder().Create() iferr_return;
	BaseArray<Char> base64;
	encoderRef.ConvertAll(rndBuffer, base64) iferr_return;
	String salt = String(base64);

	String hashStr = GetPasswordHash(salt + password, hashClass) iferr_return;

	return Tuple<String, String>{ std::move(salt), std::move(hashStr)  };
}

}
