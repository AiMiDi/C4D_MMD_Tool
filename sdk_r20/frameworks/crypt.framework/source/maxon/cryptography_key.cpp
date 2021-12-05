#include "maxon/cryptography_key.h"
#include "maxon/cryptography.h"

namespace maxon
{

Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Id& encoderId, const Id& decoderId,
																						Int blockSizeBits, const void* key1, Int key1BitSize,
																						const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback,
																						const Char* srcData, const Char* compareData)
{
	iferr_scope;

	DataDictionary settings;
	settings.Set(CryptographyOptions::CRYPTOKEY, CryptoKey(Id(), blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::move(callback))) iferr_return;

	ConversionTestSet set[] = { ConversionTestSet(encoderId, settings), ConversionTestSet(decoderId, settings) };

	return AddConversionTestSetting(MAXON_SOURCE_LOCATION_FORWARD, resultArray, set, CharToBlock(srcData), CharToBlock(compareData));
}

}
