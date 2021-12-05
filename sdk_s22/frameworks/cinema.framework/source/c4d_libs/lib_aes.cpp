#include "c4d_library.h"
#include "lib_aes.h"

AESLib* lib_aes = nullptr;

static AESLib *CheckLibAES(Int32 offset)
{
	return (AESLib*)CheckLib(AES_LIB, offset, (C4DLibrary**)&lib_aes);
}

#define AESLibCall(b) 		AESLib *lib = CheckLibAES(LIBOFFSET(AESLib, b)); \
	if (!lib || !lib->b) return; \
	(((RijndaelCipher*)this)->*lib->b)

#define AESLibCallR(a, b)  AESLib *lib = CheckLibAES(LIBOFFSET(AESLib, b)); \
	if (!lib || !lib->b) return a; \
	return (((RijndaelCipher*)this)->*lib->b)

AES* AES::Alloc()
{
	AESLib *lib = CheckLibAES(LIBOFFSET(AESLib, RijndaelCipher_Alloc)); if (!lib) return nullptr;
	return (AES*)lib->RijndaelCipher_Alloc();
}

void AES::Free(AES *&p)
{
	if (!p) return;
	AESLib *lib = CheckLibAES(LIBOFFSET(AESLib, RijndaelCipher_Free)); if (!lib) return;
	RijndaelCipher* i = (RijndaelCipher*)p;
	lib->RijndaelCipher_Free(i);
	p = nullptr;
}

Int AES::CalcEncryptedDataSize(Int32 lBlockLength, Int lDataLength)
{
	AESLib *lib = CheckLibAES(LIBOFFSET(AESLib, RijndaelCipher_CalcEncryptedDataSize));
	if (!lib) return 0;
	return lib->RijndaelCipher_CalcEncryptedDataSize(lBlockLength, lDataLength);
}

Bool AES::Init(Int32 lBlockLength, Int32 lKeyLength)
{
	AESLibCallR(false, Init)(lBlockLength, lKeyLength);
}

Bool AES::Encrypt(void* pData, Int lDataLength, const void* pKey)
{
	AESLibCallR(false, Encrypt)(pData, lDataLength, pKey);
}

Bool AES::Decrypt(void* pData, Int lDataLength, const void* pKey)
{
	AESLibCallR(false, Decrypt)(pData, lDataLength, pKey);
}

void AES::SetProgressCallback(PFNRIJINDAEL_CIPHER_PROGRESS fn, void* pData)
{
	AESLibCall(SetProgressCallback)(fn, pData);
}
