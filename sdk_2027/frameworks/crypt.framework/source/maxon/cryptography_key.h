#ifndef CRYPTOGRAPHY_KEY_H__
#define CRYPTOGRAPHY_KEY_H__

#include "maxon/object.h"
#include "maxon/datadictionary.h"
#include "maxon/url.h"


namespace maxon
{

class CryptoKey;
using CryptoKeyDelegate = Delegate<Result<CryptoKey>(const Url&)>;

//----------------------------------------------------------------------------------------
/// Parameters for UrlInterface::SetData(), UrlInterface::GetData().
//----------------------------------------------------------------------------------------
namespace URLFLAGS
{
	MAXON_ATTRIBUTE(CryptoKey, CRYPTO_KEY, 'cryp');										///< Encryption key for URLSCHEME_CRYPTOFILE within Urls. @see CryptoKey.
	MAXON_ATTRIBUTE(CryptoKeyDelegate, CRYPTO_KEY_DELEGATE, 'cryd');	///< Encryption key delegate for URLSCHEME_CRYPTOFILE within Urls. @see CryptoKey.
	MAXON_ATTRIBUTE(UInt, CRYPTO_HEADER_SEED, 'crys');								///< Seed for the cryptography header written by URLSCHEME_CRYPTOFILE. With the default of 0, the header will be seeded with a random value.
}


/// @addtogroup Cryptography
/// @{

//----------------------------------------------------------------------------------------
/// param[in] block									The block number.
/// param[in] blockSize							The size in bytes.
/// param[in] userData							User data that was originally passed to the Encrypt and Decrypt function.
/// param[out] nonce								A buffer that is filled with the Nonce data. You may only write blockSize bytes.
//----------------------------------------------------------------------------------------
using BLOCK_CIPHER_CTR_CALLBACK = Delegate<void(Int block, Int blockSize, UChar* nonce)>;


//----------------------------------------------------------------------------------------
/// Stores encryption parameters for a StreamConversionRef class.
/// @code
/// const maxon::Id        encoderID = maxon::StreamConversions::AesEncoder.GetId();
/// const maxon::Int       blockSize = 128;
/// const maxon::Char*     key = "9USGxEPo0Tx6d8ZRRLbpEc4D88xdU2bb";
/// const maxon::Int       keySize = 128;
/// const maxon::CryptoKey cryptoKey(encoderID, blockSize, key, keySize);
/// @endcode
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CryptoKeyInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CryptoKeyInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.cryptokey");

public:
	//----------------------------------------------------------------------------------------
	/// Allocates a new CryptoKey.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @param[in] cryptoAlgorithm		Id of an encryption algorithm, e.g. StreamConversions::AesEncoder.GetId().
	/// @param[in] blockSizeBits			Blocksize of the algorithm in bits.
	/// @param[in] key1								Pointer to the data of key 1.
	/// @param[in] key1BitSize				Size of the key 1 in bits.
	/// @param[in] key2								Pointer to the data of key 2.
	/// @param[in] key2BitSize				Size of the key 2 in bits.
	/// @param[in] flags							Additional flags.
	/// @param[in] callback						Callback function for CTR mode. Please consult the documentation of the cryptography algorithm for an explanation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CryptoKeyInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback);

	//----------------------------------------------------------------------------------------
	/// Allocates a new CryptoKey.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @param[in] cryptoAlgorithm		Id of an encryption algorithm, e.g. StreamConversions::AesEncoder.GetId().
	/// @param[in] blockSizeBits			Blocksize of the algorithm in bits.
	/// @param[in] key1								The bytes of key 1.
	/// @param[in] key2								The bytes of key 2.
	/// @param[in] flags							Additional flags.
	/// @param[in] callback						Callback function for CTR mode. Please consult the documentation of the cryptography algorithm for an explanation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CryptoKeyInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const Id& cryptoAlgorithm, Int blockSizeBits, const Block<const Byte>& key1, const Block<const Byte>& key2, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback);

	//----------------------------------------------------------------------------------------
	/// Returns the cryptography algorithm.
	/// @return												Id of the used cryptography algorithm.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetCryptoAlgorithm() const;

	//----------------------------------------------------------------------------------------
	/// Returns the cryptography block size in bits.
	/// @return												Block size in bits.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBlockBitSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns the cryptography data of key 1.
	/// @return												Pointer to the memory of key 1.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const void* GetKey1() const;

	//----------------------------------------------------------------------------------------
	/// Returns the cryptography size of key 1.
	/// @return												Key 1 size in bits.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetKey1BitSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns the cryptography data of key 2.
	/// @return												Pointer to the memory of key 2.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const void* GetKey2() const;

	//----------------------------------------------------------------------------------------
	/// Returns the cryptography size of key 2.
	/// @return												Key 2 size in bits.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetKey2BitSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns the additional flags.
	/// @return												The flags.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt64 GetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Returns the callback delegate.
	/// @return												The delegate of the callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BLOCK_CIPHER_CTR_CALLBACK& GetCallbackFunction() const;

	MAXON_METHOD String ToString(const FormatStatement* formatStatement = nullptr) const;

	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);
};

// include autogenerated headerfile here
#include "cryptography_key1.hxx"

/// Reference counted class of CryptoKeyInterface.
class CryptoKey : public CryptoKeyInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CryptoKey, Reference);

	//----------------------------------------------------------------------------------------
	/// Allocates a new CryptoKey.
	/// @param[in] cryptoAlgorithm		Id of an encryption algorithm. e.g. StreamConversions::AesEncoder.GetId().
	/// @param[in] blockSizeBits			Blocksize of the algorithm in bits.
	/// @param[in] key1								Pointer to the data of key 1.
	/// @param[in] key1BitSize				Size of the key 1 in bits.
	/// @param[in] key2								Pointer to the data of key 2.
	/// @param[in] key2BitSize				Size of the key 2 in bits.
	/// @param[in] flags							Additional flags.
	/// @param[in] callback						Callback function for CTR mode.
	//----------------------------------------------------------------------------------------
	CryptoKey(const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2 = nullptr, Int key2BitSize = 0, UInt64 flags = 0, BLOCK_CIPHER_CTR_CALLBACK&& callback = BLOCK_CIPHER_CTR_CALLBACK()) :
		Reference(NewObj(CryptoKeyInterface, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::move(callback)).GetValue())
	{
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a new CryptoKey.
	/// @param[in] cryptoAlgorithm		Id of an encryption algorithm. e.g. StreamConversions::AesEncoder.GetId().
	/// @param[in] blockSizeBits			Blocksize of the algorithm in bits.
	/// @param[in] key1								The bytes of key 1.
	/// @param[in] key2								The bytes of key 2.
	/// @param[in] flags							Additional flags.
	/// @param[in] callback						Callback function for CTR mode.
	//----------------------------------------------------------------------------------------
	CryptoKey(const Id& cryptoAlgorithm, Int blockSizeBits, const Block<const Byte>& key1, const Block<const Byte>& key2 = GetZeroRef<Block<const Byte>>(), UInt64 flags = 0, BLOCK_CIPHER_CTR_CALLBACK&& callback = BLOCK_CIPHER_CTR_CALLBACK()) :
		Reference(NewObj(CryptoKeyInterface, cryptoAlgorithm, blockSizeBits, key1, key2, flags, std::move(callback)).GetValue())
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns a new Url where the given stream name is wrapped into a URLSCHEME_CRYPTOFILE with the given crypto key.
	/// This allows to do file en-/decryption on the fly when reading/writing streams.
	/// @param[in] unencryptedStream	The stream name of the unencrypted stream.
	/// @return												Returns a new Url which can be used as encrypted io stream.
	//----------------------------------------------------------------------------------------
	Result<Url> EmbedStreamName(const Url& unencryptedStream) const
	{
		if (!*this)
			return unencryptedStream;
		iferr_scope;
		Url encryptedStream = Url(URLSCHEME_CRYPTOFILE);
		encryptedStream.Set(URLFLAGS::CRYPTO_KEY, *this) iferr_return;
		encryptedStream.SetEmbeddedUrl(unencryptedStream) iferr_return;
		return encryptedStream;
	}
};

namespace CryptographyOptions
{
	MAXON_ATTRIBUTE(CryptoKey, CRYPTOKEY, "net.maxon.streamconversion.cryptokey");
}

// include autogenerated headerfile here
#include "cryptography_key2.hxx"

//----------------------------------------------------------------------------------------
/// Helper function to add crypto tests.
//----------------------------------------------------------------------------------------
Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Id& encoderId, const Id& decoderId,
																						Int blockSizeBits, const void* key1, Int key1BitSize,
																						const void* key2 = nullptr, Int key2BitSize = 0, UInt64 flags = 0, BLOCK_CIPHER_CTR_CALLBACK&& callback = BLOCK_CIPHER_CTR_CALLBACK(),
																						const Char* srcData = nullptr, const Char* compareData = nullptr);

/// @}


} // namespace maxon



#endif // CRYPTOGRAPHY_KEY_H__
