#if 1
namespace maxon
{
	namespace enum24 { enum class BLOCK_CIPHER_MODE : UInt64
	{
		ECB									= 0, ///< Electronic codebook.
		CBC									= 1, ///< Cipher-block chaining.
		PCBC								= 2, ///< Propagating cipher-block chaining.
		CFB									= 3, ///< Cipher feedback.
		OFB									= 4, ///< Output feedback.
		CTR									= 5, ///< Counter.
		KEEP_STATE					= 0x80000000, ///< for CBC, PCBC, CFB, OFB: Store the current state in the instance. Otherwise the next Encrypt call will use the original initialization vector.
	} ; }
	maxon::String PrivateToString_BLOCK_CIPHER_MODE24(std::underlying_type<enum24::BLOCK_CIPHER_MODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum24::BLOCK_CIPHER_MODE::ECB, (maxon::UInt64) enum24::BLOCK_CIPHER_MODE::CBC, (maxon::UInt64) enum24::BLOCK_CIPHER_MODE::PCBC, (maxon::UInt64) enum24::BLOCK_CIPHER_MODE::CFB, (maxon::UInt64) enum24::BLOCK_CIPHER_MODE::OFB, (maxon::UInt64) enum24::BLOCK_CIPHER_MODE::CTR, (maxon::UInt64) enum24::BLOCK_CIPHER_MODE::KEEP_STATE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BLOCK_CIPHER_MODE", SIZEOF(x), true, values, "ECB\0CBC\0PCBC\0CFB\0OFB\0CTR\0KEEP_STATE\0", fmt);
	}
	const maxon::Char* const CryptographyStreamConversionInterface::MTable::_ids = 
		"IsChainingChiffre@12e73654e6d65520\0" // Bool IsChainingChiffre() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CryptographyStreamConversionInterface, , "net.maxon.interface.cryptographystreamconversion", "maxon.CryptographyStreamConversionInterface", (StreamConversionInterface::PrivateGetInterface()));
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AesEncoder, , "net.maxon.streamconversion.aes.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AesDecoder, , "net.maxon.streamconversion.aes.decoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BlowfishEncoder, , "net.maxon.streamconversion.blowfish.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BlowfishDecoder, , "net.maxon.streamconversion.blowfish.decoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BlowfishLegacyEncoder, , "net.maxon.streamconversion.blowfishlegacy.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BlowfishLegacyDecoder, , "net.maxon.streamconversion.blowfishlegacy.decoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BlowfishLegacyEnDecoder, , "net.maxon.streamconversion.blowfishlegacyen.decoder");
	}
	namespace BLOWFISHLEGACYENDECODER_OPTIONS
	{
		ENCRYPT_PrivateAttribute ENCRYPT;
	}
}
#endif
