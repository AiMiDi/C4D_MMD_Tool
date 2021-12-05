#ifndef CRYPTOGRAPHY_HASH_H__
#define CRYPTOGRAPHY_HASH_H__

#include "maxon/streamconversion.h"

namespace maxon
{

/// @addtogroup Cryptography
/// @{


#include "cryptography_hash1.hxx"

namespace StreamConversions
{
	/// MD5 hash algorithm.
	MAXON_DECLARATION(StreamConversionFactory, HashMD5, "net.maxon.streamconversion.hashmd5");

	/// SHA1 hash algorithm.
	MAXON_DECLARATION(StreamConversionFactory, HashSHA1, "net.maxon.streamconversion.hashsha1");

	/// SHA-256 hash algorithm.
	MAXON_DECLARATION(StreamConversionFactory, HashSHA256, "net.maxon.streamconversion.hashsha256");

	/// SHA-512 hash algorithm.
	MAXON_DECLARATION(StreamConversionFactory, HashSHA512, "net.maxon.streamconversion.hashsha512");

	/// Fast Crc algorithm using SSE, it's not compatible to the original Crc32 algorithm used by zip.
	MAXON_DECLARATION(StreamConversionFactory, HashCrc32c, "net.maxon.streamconversion.hashcrc32c");

	/// Crc algorithm used by zip and gzip.
	MAXON_DECLARATION(StreamConversionFactory, HashCrc32zip, "net.maxon.streamconversion.hashcrc32zip");

	/// Hash-based message authentication code
	/// allows any hash algorithm to be used with the hmac hashing
	/// http://en.wikipedia.org/wiki/HMAC
	/// use the settings container with the HASH_HMAC flags to setup the hash algorithm
	/** @code
		BaseArray<UChar> key;
		key.Insert(0, CharToBlock((const UChar*)"key")) iferr_return;

		DataDictionary settings;
		settings.Set(HASH_HMAC::BASEALGORITHM, StreamConversions::HashSHA1.GetId());
		settings.Set(HASH_HMAC::KEY, key);

		String hash = GetPasswordHash("The quick brown fox jumps over the lazy dog"_s, StreamConversions::HashHmac, settings) iferr_return;
	@endcode */
	MAXON_DECLARATION(StreamConversionFactory, HashHmac, "net.maxon.streamconversion.hashhmac");
}

//----------------------------------------------------------------------------------------
/// Options for StreamConversions::HashHmac
//----------------------------------------------------------------------------------------
namespace HASH_HMAC
{
	/// Base Algorithm that should be used for hmac (e.g. StreamConversions::HashMD5.GetId())
	MAXON_ATTRIBUTE(Id, BASEALGORITHM, "net.maxon.streamconversion.hmac.basealgorithm");

	/// encryption key
	MAXON_ATTRIBUTE(BaseArray<UChar>, KEY, "net.maxon.streamconversion.hmac.key");
}

#include "cryptography_hash2.hxx"

//----------------------------------------------------------------------------------------
/// Returns the hash value as a hexadecimal string. The length of the value depends on the algorithm.
/// @param[in] hashValue					The input (byte) values.
/// @return												The hexadecimal string.
//----------------------------------------------------------------------------------------
Result<String> GetHashString(const BaseArray<UChar>& hashValue);

//----------------------------------------------------------------------------------------
/// Returns the hash value string of a password.
/// @param[in] password						The input password.
/// @param[in] hashClass					The algorithm to use, e.g. StreamConversions::HashMD5()
/// @param[in] settings						Settings for the hash algorithm which will be passed to the Init() function.
/// @return												The hash value string.
//----------------------------------------------------------------------------------------
Result<String> GetPasswordHash(const String& password, const StreamConversionFactory& hashClass, const DataDictionary& settings = DataDictionary());

//----------------------------------------------------------------------------------------
/// HashPasswdWithSalt creates a unique salt string and hashes the password together with the string hash(salt + password).
/// To verify a password you need to store the salt and call "String hashedPasswd = GetPasswordHash(passwordSalt + passwd,
/// StreamConversions::HashSHA256())" to get the hashed passwd.
/// @param[in] password						Password to hash.
/// @param[in] hashClass					HashClass to use.
/// @return												Tuple<salt, passwordhash> if no error occurred.
//----------------------------------------------------------------------------------------
Result<Tuple<String, String>> HashPasswordWithSalt(const String& password, const StreamConversionFactory& hashClass = StreamConversions::HashSHA256());

/// @}

} // namespace maxon




#endif // CRYPTOGRAPHY_HASH_H__
