#if 1
namespace maxon
{
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashMD5, , "net.maxon.streamconversion.hashmd5");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashSHA1, , "net.maxon.streamconversion.hashsha1");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashSHA256, , "net.maxon.streamconversion.hashsha256");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashSHA512, , "net.maxon.streamconversion.hashsha512");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashCrc32c, , "net.maxon.streamconversion.hashcrc32c");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashCrc32zip, , "net.maxon.streamconversion.hashcrc32zip");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HashHmac, , "net.maxon.streamconversion.hashhmac");
	}
	namespace HASH_HMAC
	{
		BASEALGORITHM_PrivateAttribute BASEALGORITHM;
		KEY_PrivateAttribute KEY;
	}
}
#endif
