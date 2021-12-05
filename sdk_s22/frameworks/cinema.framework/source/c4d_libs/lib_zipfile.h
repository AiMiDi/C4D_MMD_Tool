#ifndef LIB_ZIPFILE_H__
#define LIB_ZIPFILE_H__

#include "c4d_library.h"

/// @addtogroup group_zipfilelibrary Zip File
/// @ingroup group_library
/// @{
/// Based upon zlib, see http://www.zlib.net/ for more information.

// External attributes

/// @addtogroup ZIP_FLAG
/// @ingroup group_enumeration
/// @{
#define ZIP_FLAG_READONLY							0x00000001			///< Read-only flag.
#define ZIP_FLAG_DIRECTORY						0x00000010			///< Directory flag.
/// @}

/// @addtogroup ZIP_FILE_FLAG
/// @ingroup group_enumeration
/// @{
#define ZIP_FILE_FLAG_OWNER_R					0x01000000			///< Owner read file permission.
#define ZIP_FILE_FLAG_OWNER_W					0x00800000			///< Owner write file permission.
#define ZIP_FILE_FLAG_OWNER_X					0x00400000			///< Owner execute file permission.
#define ZIP_FILE_FLAG_GROUP_R					0x00200000			///< Group read file permission.
#define ZIP_FILE_FLAG_GROUP_W					0x00100000			///< Group write file permission.
#define ZIP_FILE_FLAG_GROUP_X					0x00080000			///< Group execute filer permission.
#define ZIP_FILE_FLAG_PUBLIC_R				0x00040000			///< Public read file permission.
#define ZIP_FILE_FLAG_PUBLIC_W				0x00020000			///< Public write file permission.
#define ZIP_FILE_FLAG_PUBLIC_X				0x00010000			///< Public execute file permission.
#define ZIP_FILE_FLAG_UNIX_MASK				0x01ff0000			///< Unix mask.
#define ZIP_FILE_FLAG_USE_UNIX_FLAGS	0x80000000			///< Use Unix file permission flags.
/// @}

// Internal attributes

/// @addtogroup ZIP_FILE_FLAG_UNIX
/// @ingroup group_enumeration
/// @{
#define ZIP_FILE_FLAG_UNIX_ATTR				0x00000001			///< Unix file attributes.
/// @}

/// @addtogroup ZIP_EXTRACT
/// @ingroup group_enumeration
/// @{
#define ZIP_EXTRACT_CREATE_SUBDIR			0x00000001			///< Creates sub-directories.
#define ZIP_EXTRACT_IGNORE_READONLY		0x00000002			///< Ignore read-only flags.
#define ZIP_EXTRACT_IGNORE_PATH_CASE	0x00000004			///< Ignore upper/lower case paths on Linux (if the path or parts of it already exist).
/// @}

struct ZipFileTime
{
	UINT nSec;				///< Seconds (@em 0 to @em 59).
	UINT nMin;				///< Minutes (@em 0 to @em 59).
	UINT nHour;				///< Hour (@em 0 to @em 23).
	UINT nMDay;				///< Day of month (@em 1 to @em 31).
	UINT nMonth;			///< Month (@em 0 to @em 11).
	UINT nYear;				///< Year (@em 1980 to @em 2044).
};

struct ZipFileGlobalInfo
{
	UInt32 lEntries;					///< The number of entries in the ZIP file.
	UInt32 lCommentSize;			///< The size of the global comment.
};

struct ZipFileInfo
{
	UInt32 lVersion;								///< Version.
	UInt32 lVersionNeeded;					///< Version needed.
	UInt32 lFlags;									///< Flags: @enumerateEnum{ZIP_FLAG}
	UInt32 lCompressionMethod;			///< Compression method.
	UInt32 lDOSDate;								///< DOS date.
	UInt32 lCRC32;									///< CRC32.
	UInt32 lCompressedSize;					///< Compressed size.
	UInt32 lUncompressedSize;				///< Uncompressed size.
	UInt32 lSizeFilename;						///< File name size.
	UInt32 lSizeExtraField;					///< Extra field size.
	UInt32 lSizeFileComment;				///< File comment size.
	UInt32 lDiskNumberStart;				///< Disk number start.
	UInt32 lInternalAttr;						///< Currently private.
	UInt32 lExternalAttr;						///< Currently private.
	ZipFileTime t;									///< Time.
};

struct ZipWriteInfo
{
	ZipFileTime	ti;									///< The time of the file in the ZIP file.
	UInt32			lInternalAttr,			///< Currently private.
							lExternalAttr;			///< Currently private.
};

/// @addtogroup ZipMethod
/// @ingroup group_enumeration
/// @{
enum ZipMethod
{
	ZipMethodDeflate,			///< Deflate.
	ZipMethodStore				///< Store.
};
/// @}

//----------------------------------------------------------------------------------------
/// Called during file extraction.
/// @param[in] fnSrc							The source filename within the ZIP file.
/// @param[in] fnDest							The filename of the destination file (the extracted file).
/// @param[in] pData							The private data passed to ZipFile::ExtractToDirectory().
/// @param[in] lInfo							The extraction info: @enumerateEnum{EXTRACT_INFO}
/// @return												The result: @enumerateEnum{EXTRACT_INFO}
//----------------------------------------------------------------------------------------
typedef Int32 (*ExtractDirectoryCallback)(const Filename &fnSrc, const Filename &fnDest, void* pData, Int32 lInfo);

/// @addtogroup EXTRACT_INFO
/// @ingroup group_enumeration
/// @{
#define EXTRACT_INFO_SUCCESS													0			///< Extraction was successful.
#define EXTRACT_INFO_FAILED														1			///< Extraction failed.
#define EXTRACT_INFO_CANT_WRITE												2			///< Cannot write extracted files.
	#define EXTRACT_INFO_CANT_WRITE_R_FORCE_OVERWRITE		2			///< Overwrites read-only files.
	#define EXTRACT_INFO_CANT_WRITE_R_IGNORE						3			///< Ignores read-only files.
#define EXTRACT_INFO_R_CANCEL													1			///< Cancels file extraction.
/// @}

/// @addtogroup ZIP_APPEND
/// @ingroup group_enumeration
/// @{
#define ZIP_APPEND_CREATE					0			///< Creates a new ZIP file.
#define ZIP_APPEND_CREATEAFTER		1			///< Appends the ZIP information at the end of an existing file (used e.g. for self-extracting installers).
#define ZIP_APPEND_ADDINZIP				2			///< Inserts new files into the ZIP file.
/// @}

//----------------------------------------------------------------------------------------
/// Allows to read/write ZIP files.
//----------------------------------------------------------------------------------------
class ZipFile
{
private:
	ZipFile();
	~ZipFile();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{ZIP file}
	/// @return												@allocReturn{ZIP file}
	//----------------------------------------------------------------------------------------
	static ZipFile* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{ZIP file}
	/// @param[in,out] p							@theToDestruct{ZIP file}
	//----------------------------------------------------------------------------------------
	static void Free(ZipFile *&p);

	/// @}

	/// @name Static
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a local file name.
	/// @param[in] fn									The filename to create from.
	/// @param[out] str								Assigned the local file name to create.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool CreateLocalFileName(const Filename &fn, String& str);

	//----------------------------------------------------------------------------------------
	/// Creates a file name.
	/// @param[in] str								The file string to create from.
	/// @param[in] fn									Assigned the filename to create.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool CreateFilename(const String& str, Filename &fn);

	//----------------------------------------------------------------------------------------
	/// Gets a ZIP file CRC.
	/// @param[in] fn									The filename to get the CRC for.
	/// @param[out] ulCRC							The calculated CRC.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool GetFileCRC(const Filename &fn, UInt32 &ulCRC);

	//----------------------------------------------------------------------------------------
	/// Calculates the CRC from a buffer.
	/// @param[in] pBuffer						The buffer to calculate the CRC from.
	/// @param[in] lBufferLen					The buffer length.
	/// @param[in] ulOldCRC						The optional initial CRC value.
	/// @return												The calculated CRC.
	//----------------------------------------------------------------------------------------
	static UInt32 CalcCRC32(const void* pBuffer, Int32 lBufferLen, UInt32 ulOldCRC = 0);

	/// @}

	/// @name Open/Extract/Close
	/// @{

	//----------------------------------------------------------------------------------------
	/// Opens a ZIP file.
	/// @param[in] fn									The file to open.
	/// @param[in] bRead							@trueOtherwiseFalse{to open for reading}
	/// @param[in] lAppend						The append flags to append the ZIP file to an existing file: @enumerateEnum{ZIP_APPEND}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Open(const Filename &fn, const Bool bRead, const Int32 lAppend = ZIP_APPEND_CREATE);

	//----------------------------------------------------------------------------------------
	/// Opens an AES encrypted ZIP file, see AESFile.
	/// @param[in] fn									The encrypted file to open.
	/// @param[in] bRead							@trueOtherwiseFalse{to open for reading}
	/// @param[in] pchKey							The decryption key.
	/// @param[in] lKeyLength					The key length. Must be @em 128, @em 192 or @em 256 (bits).
	/// @param[in] lBlockLength				The block size. Must be @em 128, @em 192 or @em 256 (bits).
	/// @param[in] lAESFlags					Reserved for later use. Must be set to @em 0.
	/// @param[in] lAppend						The append flags to append the ZIP file to an existing file: @enumerateEnum{ZIP_APPEND}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool OpenEncrypted(const Filename &fn, const Bool bRead, const char* pchKey, Int32 lKeyLength, Int32 lBlockLength, UInt32 lAESFlags, const Int32 lAppend = ZIP_APPEND_CREATE);

	//----------------------------------------------------------------------------------------
	/// Sets the maximum size of the ZIP file. A new file is created with the same name and a consecutive number if it exceeds this size.
	/// @note Call immediately after opening a ZIP file for writing.
	/// @param[in] ulSpan							The maximum size of the file.
	/// @param[in] bOverwrite					If @formatConstant{true} the next file is overwritten.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetSpanning(UInt32 ulSpan, Bool bOverwrite);

	//----------------------------------------------------------------------------------------
	/// Extracts the ZIP file to the specified directory.
	/// @param[in] fnZip							The ZIP filename.
	/// @param[in] fnDir							The directory to extract to.
	/// @param[in] lFlags							The extract flags: @enumerateEnum{ZIP_EXTRACT}
	/// @param[in] fn									The extract callback.
	/// @param[in] pData							The private data for the extract callback.
	/// @param[in] pChPassword				An optional password.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ExtractToDirectory(const Filename& fnZip, const Filename& fnDir, Int32 lFlags = ZIP_EXTRACT_CREATE_SUBDIR, ExtractDirectoryCallback fn = nullptr,
		void* pData = nullptr, const char* pChPassword = nullptr);

	//----------------------------------------------------------------------------------------
	/// Closes the ZIP file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Close();

	//----------------------------------------------------------------------------------------
	/// Closes the ZIP file and writes a comment.
	/// @note Comments are only written if the file is saved.
	/// @param[in] pchGlobalComment		The global comment string.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Close(const char* pchGlobalComment);

	//----------------------------------------------------------------------------------------
	/// Closes the ZIP file and writes a comment.
	/// @note Comments are only written if the file is saved.
	/// @param[in] strGlobalComment		The global comment string.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Close(const String& strGlobalComment);

	/// @}

	/// @name Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a file in the ZIP file.
	/// @note Directories must be separated by a slash.
	/// @param[in] strName						The file name.
	/// @param[in] pInfo							The write information.
	/// @param[in] pExtraFieldLocal		The extra local field.
	/// @param[in] lExtraSizeLocal		The extra local size.
	/// @param[in] pExtraFieldGlobal	The extra global field.
	/// @param[in] lExtraSizeGlobal		The extra global size.
	/// @param[in] pstrComment				The comment string.
	/// @param[in] method							The ZIP method: @enumerateEnum{ZipMethod}
	/// @param[in] lLevel							The ZIP compression level, between @em 0 and @em 9.
	/// @param[in] pchPassword				An optional password.
	/// @param[in] ulCryptingCRC			An optional encryption CRC.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CreateFileInZip(const String& strName, ZipWriteInfo* pInfo, void* pExtraFieldLocal, UInt32 lExtraSizeLocal, void* pExtraFieldGlobal, UInt32 lExtraSizeGlobal,
											 String* pstrComment, ZipMethod method, INT lLevel, const char* pchPassword = nullptr, UInt32 ulCryptingCRC = 0);

	//----------------------------------------------------------------------------------------
	/// Writes a buffer in the ZIP file.
	/// @param[in] pBuffer						The buffer to write.
	/// @param[in] lLen								The buffer length.
	/// @param[in] lExpectedSize			An optional expected size.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WriteInFileInZip(const void* pBuffer, const UInt32 lLen, const Int32 lExpectedSize = -1);

	//----------------------------------------------------------------------------------------
	/// Copies a file in the ZIP file.
	/// @param[in] fn									The file to copy.
	/// @param[in] str								The destination file name.
	/// @param[in] pchPassword				An optional password.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyInFileInZip(const Filename& fn, const String& str, const char* pchPassword = nullptr);

	//----------------------------------------------------------------------------------------
	/// Copies a file in the ZIP file.
	/// @param[in] fn									The file to copy.
	/// @param[in] str								The destination file name.
	/// @param[in] ulInternalAttributes	The internal file attributes.
	/// @param[in] ulExternalAttributes	The external file attributes.
	/// @param[in] pchPassword				An optional password.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyInFileInZip(const Filename& fn, const String& str, UInt32 ulInternalAttributes, UInt32 ulExternalAttributes, const char* pchPassword = nullptr);

	//----------------------------------------------------------------------------------------
	/// Closes a file in the ZIP file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CloseFileInZip();

	//----------------------------------------------------------------------------------------
	/// Creates a directory in the ZIP file. A slash is added if necessary.
	/// @param[in] strName						The directory name.
	/// @param[in] pTime							The directory time.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CreateDirectoryInZip(const String& strName, ZipFileTime* pTime);

	/// @}

	/// @name Read
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the global information.
	/// @param[out] i									Filled with the global information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetGlobalInfo(ZipFileGlobalInfo &i);

	//----------------------------------------------------------------------------------------
	/// Retrieves the global comment.
	/// @param[out] str								Filled with the global comment.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetGlobalComment(String& str);

	//----------------------------------------------------------------------------------------
	/// Goes to the first file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GoToFirstFile();

	//----------------------------------------------------------------------------------------
	/// Goes to the next file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GoToNextFile();

	//----------------------------------------------------------------------------------------
	/// Locates a file.
	/// @param[in] strName						The file name to locate.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool LocateFile(const String& strName);

	//----------------------------------------------------------------------------------------
	/// Retrieves the information for the current file.
	/// @param[out] i									Filled with the current file information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetCurrentFileInfo(ZipFileInfo &i);

	//----------------------------------------------------------------------------------------
	/// Retrieves the information for the current file.
	/// @param[out] pstrName					Filled with the current file name.
	/// @param[out] pstrComment				Filled with the current file comment.
	/// @param[out] pExtraField				Filled with the current file extra field.
	/// @param[out] lExtraFieldSize		Filled with the current file extra field size.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetCurrentFileInfo(String* pstrName, String* pstrComment = nullptr, void* pExtraField = nullptr, UInt32 lExtraFieldSize = 0);

	//----------------------------------------------------------------------------------------
	/// Extracts the contents of the current archive to the directory @formatParam{fnDir}.
	/// @param[in] fnDir							The directory to extract the files to.
	/// @param[in] pThread						The thread for extracting in an own thread.
	/// @param[in] lFlags							The extract flags: @enumerateEnum{ZIP_EXTRACT}
	/// @param[in] pchPassword				An optional password.
	/// @param[out] pfnDest						An optional filename pointer filled with the destination.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ExtractCurrentFile(const Filename& fnDir, BaseThread* pThread, Int32 lFlags = ZIP_EXTRACT_CREATE_SUBDIR, const char* pchPassword = nullptr, Filename* pfnDest = nullptr);

	//----------------------------------------------------------------------------------------
	/// Extracts the contents of the current archive to the directory @formatParam{fnDir}.
	/// @param[in] fnDir							The directory to extract the files to.
	/// @param[in] lFlags							The extract flags: @enumerateEnum{ZIP_EXTRACT}
	/// @param[in] pchPassword				An optional password.
	/// @param[out] pfnDest						An optional filename pointer filled with the destination.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ExtractCurrentFile(const Filename& fnDir, Int32 lFlags = ZIP_EXTRACT_CREATE_SUBDIR, const char* pchPassword = nullptr, Filename* pfnDest = nullptr);

	//----------------------------------------------------------------------------------------
	/// Opens the current file with password protection.
	/// @param[in] pChPassword				An optional password.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool OpenCurrentFile(const char* pChPassword = nullptr);

	//----------------------------------------------------------------------------------------
	/// Closes the current file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CloseCurrentFile();

	//----------------------------------------------------------------------------------------
	/// Reads a buffer from the current file.
	/// @param[in,out] pBuffer				The buffer to read to.
	/// @param[in,out] lBufferSize		The buffer size.
	/// @return												The number of bytes read, or < @em 0 if there was an error.
	//----------------------------------------------------------------------------------------
	Int32 ReadCurrentFile(void* pBuffer, UInt32 lBufferSize);

	//----------------------------------------------------------------------------------------
	/// Gets the read position in the current file.
	/// @return												The current read position.
	//----------------------------------------------------------------------------------------
	Int32 GetCurrentFileReadPosition();

	//----------------------------------------------------------------------------------------
	/// Checks for the end of the current file.
	/// @return												@trueIfOtherwiseFalse{end of current file}
	//----------------------------------------------------------------------------------------
	Bool EndOfCurrentFile();

	/// @}

	/// @name Compression Level
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the compression level of the ZIP file.
	/// @note Must be called before opening and initializing the file.
	/// @param[in] lLevel							The compression level, ranges from @em 0 (min) to @em 9 (max).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetCompressionLevel(Int32 lLevel);

	//----------------------------------------------------------------------------------------
	/// Gets the compression level of the ZIP file.
	/// @return												The compression level, ranges from @em 0 (min) to @em 9 (max).
	//----------------------------------------------------------------------------------------
	Int32 GetCompressionLevel() const;

	/// @}
};

/// @addtogroup FILETIME
/// @ingroup group_enumeration
/// @{
#define FILETIME_CREATED			0			///< Creation date.
#define FILETIME_MODIFIED			1			///< Modification date.
#define FILETIME_ACCESS				2			///< Access date.
/// @}

//----------------------------------------------------------------------------------------
/// Retrieves the time of a file.
/// @param[in] fn									The file to get the time for.
/// @param[out] nYear							Assigned the year.
/// @param[out] nMonth						Assigned the month.
/// @param[out] nDay							Assigned the day.
/// @param[out] nHour							Assigned the hour.
/// @param[out] nMinute						Assigned the minute.
/// @param[out] nSec							Assigned the second.
/// @param[in] lType							The type of file time to get: @enumerateEnum{FILETIME}
/// @param[in] bIsDir							@formatConstant{true} for a directory.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GetFileTime(const Filename &fn, UINT &nYear, UINT &nMonth, UINT &nDay, UINT &nHour, UINT &nMinute, UINT &nSec, Int32 lType, Bool bIsDir);

//----------------------------------------------------------------------------------------
/// Sets the time of a file.
/// @param[in] fn									The file to set the time for.
/// @param[in] nYear							The year.
/// @param[in] nMonth							The month.
/// @param[in] nDay								The day.
/// @param[in] nHour							The hour.
/// @param[in] nMinute						The minute.
/// @param[in] nSec								The second.
/// @param[in] lType							The type of file time to set: @enumerateEnum{FILETIME}
/// @param[in] bIsDir							@formatConstant{true} for a directory.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool SetFileTime(const Filename &fn, UINT nYear, UINT nMonth, UINT nDay, UINT nHour, UINT nMinute, UINT nSec, Int32 lType, Bool bIsDir);

//----------------------------------------------------------------------------------------
/// Compresses data into a caller supplied buffer.
/// @param[in] pSrcData						The source data.
/// @param[in] lSrcLen						The source data length.
/// @param[in,out] pDestData			Filled with the compressed data.
/// @param[in,out] plDestLen			The compressed data length. The destination buffer needs to be at least @em 0.1% bigger than the data to compress plus @em 12 bytes for the header.\n
/// 															Updated with the actual length used.
/// @param[in] lLevel							The compression level, ranges from @em 0 (min) to @em 9 (max).
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool CompressDataRaw(const void* pSrcData, Int lSrcLen, void* pDestData, Int* plDestLen, Int32 lLevel);

//----------------------------------------------------------------------------------------
/// Uncompresses data into a caller supplied buffer.
/// @param[in] pSrcData						The source data.
/// @param[in] lSrcLen						The source data length. May not be greater than @em 2 GB.
/// @param[in,out] pDestData			Filled with the uncompressed data. The buffer needs to be big enough to fit the uncompressed data.
/// @param[in,out] plDestLen			The uncompressed data length. Updated with the actual length used.
/// @param[out] plRead						Assigned the amount of data read.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool UncompressDataRaw(const void* pSrcData, Int lSrcLen, void* pDestData, Int* plDestLen, Int* plRead = nullptr);

/// For CompressData(), @c COMPRESS_DATA_32_BYTE_PADDING | lLevel to make @c lDestLen a multiple of @em 32.
#define COMPRESS_DATA_32_BYTE_PADDING			0x00000100

//----------------------------------------------------------------------------------------
/// Compresses data and give the caller a pointer in @formatParam{pDestData} to memory that must be freed with DeleteMem().
/// @param[in] pSrcData						The source data.
/// @param[in] lSrcLen						The source data length. May not be greater than @em 2 GB.
/// @param[out] pDestData					Assigned a pointer to the destination compressed data. Needs to be freed with DeleteMem().
/// @param[out] lDestLen					Assigned the destination length.
/// 															Pass @c COMPRESS_DATA_32_BYTE_PADDING | lLevel to make @c lDestLen a multiple of @em 32.
/// @param[in] lLevel							The compression level, ranges from @em 0 (min) to @em 9 (max).
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool CompressData(const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int32 lLevel);

//----------------------------------------------------------------------------------------
/// Uncompresses data and give the caller a pointer in @formatParam{pDestData} to memory that must be freed with DeleteMem().
/// @param[in] pSrcData						The source data.
/// @param[in] lSrcLen						The source data length. May not be greater than @em 2 GB.
/// @param[out] pDestData					Assigned the destination data pointer. Needs to be freed with DeleteMem().
/// @param[out] lDestLen					Assigned the destination length.
/// @param[out] plRead						Assigned the amount of data read.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool UncompressData(const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int* plRead = nullptr);

struct ZHandle;

//----------------------------------------------------------------------------------------
/// Initializes data compression.
/// @see CompressDataDoIt()
/// @param[in] lLevel							The compression level, ranges from @em 0 (min) to @em 9 (max).
/// @return												The handle for data compression.
//----------------------------------------------------------------------------------------
ZHandle* CompressDataInit(Int32 lLevel);

//----------------------------------------------------------------------------------------
/// Compresses data.\n
/// @b Example:
/// @code
/// static ZHandle *zhandle = nullptr;
/// zhandle = CompressDataInit(5);
/// res = zhandle && CompressDataDoIt(zhandle, c, l, l_zippedmem, l_ziplen, 0);
/// DeleteMem(l_zippedmem);
/// CompressDataFree(zhandle);
/// @endcode
/// @param[in] handle							The handle for data compression.
/// @param[in] pSrcData						The address to the source data.
/// @param[in] lSrcLen						The size of the source data block.
/// @param[out] pDestData					Assigned the address of the compressed data. Must be freed with DeleteMem().
/// @param[out] lDestLen					Assigned the size of the compressed data block.
/// @param[in] lFlags							Usually @em 0 but can be set to @ref COMPRESS_DATA_32_BYTE_PADDING.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool CompressDataDoIt(ZHandle *handle, const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int32 lFlags);

//----------------------------------------------------------------------------------------
/// Frees the handle of the compressed data. See also CompressDataDoIt().
/// @param[in,out] handle					The handle for data compression to be freed.
//----------------------------------------------------------------------------------------
void CompressDataFree(ZHandle *&handle);

/// ZIP file library ID.
#define LIBRARY_ZIPFILE 1011188

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iZipFile;

struct ZipFileLib : public C4DLibrary
{
	ZipFile*	(*ZipFile_Alloc)();
	void			(*ZipFile_Free)(ZipFile *&p);
	Bool			(*ZipFile_CreateLocalFileName)(const Filename &fn, String& str);
	Bool			(*ZipFile_CreateFilename)(const String& str, Filename &fn);
	Bool			(*ZipFile_GetFileCRC)(const Filename &fn, UInt32 &ulCRC);
	UInt32		(*ZipFile_CalcCRC32)(const void* pBuffer, Int32 lBufferLen, UInt32 ulOldCRC);

	Bool			(iZipFile::*Open)(const Filename& fn, const Bool bRead, const Int32 lAppend);
	Bool			(iZipFile::*CloseNC)();
	Bool			(iZipFile::*CloseCC)(const char* pComment);
	Bool			(iZipFile::*CloseSC)(const String& strComment);

	// Write
	Bool			(iZipFile::*CreateFileInZip)(const String& strName, ZipWriteInfo* pInfo, void* pExtraFieldLocal, UInt32 lExtraSizeLocal, void* pExtraFieldGlobal, UInt32 lExtraSizeGlobal,
											String* pstrComment, ZipMethod method, INT lLevel, const char* pchPassword, UInt32 ulCryptingCRC);
	Bool			(iZipFile::*CopyInFileInZipA)(const Filename& fn, const String& str, const char* pchPassword);
	Bool			(iZipFile::*CloseFileInZip)();
	Bool			(iZipFile::*CreateDirectoryInZip)(const String& strName, ZipFileTime* pTime);

	// Read
	Bool			(iZipFile::*GetGlobalInfo)(ZipFileGlobalInfo &i);
	Bool			(iZipFile::*GetGlobalComment)(String& str);
	Bool			(iZipFile::*GoToFirstFile)();
	Bool			(iZipFile::*GoToNextFile)();
	Bool			(iZipFile::*LocateFile)(const String& strName);
	Bool			(iZipFile::*GetCurrentFileInfoA)(ZipFileInfo &i);
	Bool			(iZipFile::*GetCurrentFileInfoB)(String* pstrName, String* pstrComment, void* pExtraField, UInt32 lExtraFieldSize);
	Bool			(iZipFile::*OpenCurrentFile)(const char* pChPassword);
	Bool			(iZipFile::*CloseCurrentFile)();
	Int32			(iZipFile::*ReadCurrentFile)(void* pBuffer, UInt32 lBufferSize);
	Int32			(iZipFile::*GetCurrentFileReadPosition)();
	Bool			(iZipFile::*EndOfCurrentFile)();

	// Other stuff
	Bool			(*GetFileTime)(const Filename &fn, UINT &nYear, UINT &nMonth, UINT &nDay, UINT &nHour, UINT &nMinute, UINT &nSec, Int32 lType, Bool bIsDir);
	Bool			(*SetFileTime)(const Filename &fn, UINT nYear, UINT nMonth, UINT nDay, UINT nHour, UINT nMinute, UINT nSec, Int32 lType, Bool bIsDir);
	Bool			(*CompressDataRaw)(const void* pSrcData, Int lSrcLen, void* pDestData, Int* plDestLen, Int32 lLevel);
	Bool			(*UncompressDataRaw)(const void* pSrcData, Int lSrcLen, void* pDestData, Int* plDestLen, Int* plRead);
	Bool			(*CompressData2)(const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int32 lLevel);
	Bool			(*UncompressData2)(const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int* plRead);

	Bool			(iZipFile::*ExtractCurrentFile)(const Filename& fnDir, Int32 lFlags, const char* pchPassword, Filename* pfnDest);
	Bool			(iZipFile::*ExtractToDirectory)(const Filename& fnZip, const Filename& fnDir, Int32 lFlags, ExtractDirectoryCallback fn, void* pData, const char* pChPassword);

	Bool			(iZipFile::*SetSpanning)(UInt32 ulSpan, Bool bOverwrite);
	Bool			(iZipFile::*OpenEncrypted)(const Filename &fn, const Bool bRead, const char* pKey, Int32 lKeyLength, Int32 lBlockLength, UInt32 lAESFlags, const Int32 lAppend);

	Bool			(iZipFile::*ExtractCurrentFileT)(const Filename& fnDir, BaseThread* pThread, Int32 lFlags, const char* pchPassword, Filename* pfnDest);

	ZHandle*	(*CompressDataInit)(Int32 lLevel);
	Bool			(*CompressDataDoIt)(ZHandle *handle, const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int32 flags);
	void			(*CompressDataFree)(ZHandle *&handle);

	Bool			(iZipFile::*CopyInFileInZipB)(const Filename& fn, const String& str, UInt32 ulInternalAttributes, UInt32 ulExternalAttributes, const char* pchPassword);

	Bool			(iZipFile::*SetCompressionLevel)(Int32 lLevel);
	Int32			(iZipFile::*GetCompressionLevel)() const;

	Bool			(iZipFile::*WriteInFileInZip)(const void* pBuffer, UInt lLen, Int64 lExpectedSize);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_ZIPFILE_H__
