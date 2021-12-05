/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_AES_H__
#define LIB_AES_H__

#include "c4d_library.h"

#ifdef __API_INTERN__
#include "c4d_library.h"
#include "intbaselist.h"
#endif

/// @addtogroup group_aeslibrary AES
/// @ingroup group_library
/// @{

/// AES library ID.
#define AES_LIB 450000218

//----------------------------------------------------------------------------------------
/// Progress hook set with AES::SetProgressCallback(). Gets the percentage of the progress by @formatParam{lProgress}/@formatParam{lLength}.
/// @param[in] lProgress					The progress (current block).
/// @param[in] lLength						The length of the encrypted data.
/// @param[in] pData							The pointer to the data.
/// @return												@formatConstant{true} to continue encryption/decryption, @formatConstant{false} to cancel.
//----------------------------------------------------------------------------------------
typedef Bool (*PFNRIJINDAEL_CIPHER_PROGRESS)(Int lProgress, Int lLength, void* pData);

//----------------------------------------------------------------------------------------
/// An Advanced Encryption Standard (also known as Rijndael) class to encrypt/decrypt data.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class AES
{
private:
	AES();
	~AES();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesAN{AES cipher}
	/// @return												@allocReturn{AES cipher}
	//----------------------------------------------------------------------------------------
	static AES* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{AES ciphers}
	/// @param[in,out] pAES						@theToDestruct{AES cipher}
	//----------------------------------------------------------------------------------------
	static void Free(AES *&pAES);

	/// @}

	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the AES cipher to the given block length and key length.
	/// @param[in] lBlockLength				The block length. Must be @em 128, @em 192 or @em 256 (bit).
	/// @param[in] lKeyLength					The key length. Must be @em 128, @em 192 or @em 256 (bit).
	/// @return												@trueIfOtherwiseFalse{initialization was successful}
	//----------------------------------------------------------------------------------------
	Bool Init(Int32 lBlockLength, Int32 lKeyLength);

	/// @}

	/// @name Calculate Data Size
	/// @{

	//----------------------------------------------------------------------------------------
	/// Calculates the size of the data block (data size + encryption overhead).
	/// @param[in] lBlockLength				The block length in bits.
	/// @param[in] lDataLength				The size of the data in bytes.
	/// @return												The size of the data block in bytes.
	//----------------------------------------------------------------------------------------
	static Int CalcEncryptedDataSize(Int32 lBlockLength, Int lDataLength);

	/// @}

	/// @name Encrypt/Decrypt
	/// @{

	//----------------------------------------------------------------------------------------
	/// Encrypts a data block.
	/// @param[in,out] pData					The data block to encrypt.
	/// @param[in] lDataLength				The size of the data block. Usually retrieved with CalcEncryptedDataSize().
	/// @param[in] pKey								The encryption key.
	/// @return												@trueIfOtherwiseFalse{encryption was successful}
	//----------------------------------------------------------------------------------------
	Bool Encrypt(void* pData, Int lDataLength, const void* pKey);

	//----------------------------------------------------------------------------------------
	/// Decrypts a data block.
	/// @param[in,out] pData					The encrypted data block.
	/// @param[in] lDataLength				The size of the data block.
	/// @param[in] pKey								The decryption key.
	/// @return												@trueIfOtherwiseFalse{decryption was successful}
	//----------------------------------------------------------------------------------------
	Bool Decrypt(void* pData, Int lDataLength, const void* pKey);

	/// @}

	/// @name Progress Callback
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the encryption/decryption progress hook.
	/// @note For future use, does nothing, currently.
	/// @param[in] fn									The progress hook.
	/// @param[in] pData							The data pointer passed to the hook.
	//----------------------------------------------------------------------------------------
	void SetProgressCallback(PFNRIJINDAEL_CIPHER_PROGRESS fn, void* pData);

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class RijndaelCipher;

struct AESLib : public C4DLibrary
{
	RijndaelCipher*		(*RijndaelCipher_Alloc)();
	void		(*RijndaelCipher_Free)(RijndaelCipher *&pAES);
	Int		(*RijndaelCipher_CalcEncryptedDataSize)(Int32 lBlockLength, Int lDataLength); // lBlockLength in bits, lDataLength in bytes

	Bool		(RijndaelCipher::*Init)(Int32 lBlockLength, Int32 lKeyLength);
	Bool		(RijndaelCipher::*Encrypt)(void* pData, Int lDataLength, const void* pKey);
	Bool		(RijndaelCipher::*Decrypt)(void* pData, Int lDataLength, const void* pKey);
	void		(RijndaelCipher::*SetProgressCallback)(PFNRIJINDAEL_CIPHER_PROGRESS fn, void* pData);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_AES_H__
