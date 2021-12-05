#include "lib_zipfile.h"

ZipFileLib *lib_zipfile = nullptr;

static ZipFileLib *CheckZipLib(Int32 offset)
{
	return (ZipFileLib*)CheckLib(LIBRARY_ZIPFILE, offset, (C4DLibrary**)&lib_zipfile);
}

#define ZipLibCall(b) 		ZipFileLib *lib = CheckZipLib(LIBOFFSET(ZipFileLib, b)); \
															if (!lib || !lib->b) return; \
															(((iZipFile*)this)->*lib->b)

#define ZipLibCallR(a, b) ZipFileLib *lib = CheckZipLib(LIBOFFSET(ZipFileLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iZipFile*)this)->*lib->b)

static ZipFileLib *CheckLibZipFile(Int32 offset)
{
	return (ZipFileLib*)CheckLib(LIBRARY_ZIPFILE, offset, (C4DLibrary**)&lib_zipfile);
}

ZipFile* ZipFile::Alloc()
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, ZipFile_Alloc)); if (!lib) return nullptr;
	return lib->ZipFile_Alloc();
}

void ZipFile::Free(ZipFile *&p)
{
	if (!p) return;
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, ZipFile_Free)); if (!lib) return;
	lib->ZipFile_Free(p);
	p = nullptr;
}

Bool ZipFile::CreateLocalFileName(const Filename &fn, String& str)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, ZipFile_CreateLocalFileName)); if (!lib) return false;
	return lib->ZipFile_CreateLocalFileName(fn, str);
}

Bool ZipFile::CreateFilename(const String& str, Filename &fn)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, ZipFile_CreateFilename)); if (!lib) return false;
	return lib->ZipFile_CreateFilename(str, fn);
}

Bool ZipFile::GetFileCRC(const Filename &fn, UInt32 &ulCRC)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, ZipFile_GetFileCRC)); if (!lib) return false;
	return lib->ZipFile_GetFileCRC(fn, ulCRC);
}

UInt32 ZipFile::CalcCRC32(const void* pBuffer, Int32 lBufferLen, UInt32 ulOldCRC)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, ZipFile_CalcCRC32)); if (!lib) return 0;
	return lib->ZipFile_CalcCRC32(pBuffer, lBufferLen, ulOldCRC);
}

Bool ZipFile::Open(const Filename &fn, const Bool bRead, const Int32 lAppend)
{
	ZipLibCallR(false, Open)(fn, bRead, lAppend);
}

Bool ZipFile::OpenEncrypted(const Filename &fn, const Bool bRead, const char* pchKey, Int32 lKeyLength, Int32 lBlockLength, UInt32 lAESFlags, const Int32 lAppend)
{
	ZipLibCallR(false, OpenEncrypted)(fn, bRead, pchKey, lKeyLength, lBlockLength, lAESFlags, lAppend);
}

Bool ZipFile::SetSpanning(UInt32 ulSpan, Bool bOverwrite)
{
	ZipLibCallR(false, SetSpanning)(ulSpan, bOverwrite);
}

Bool ZipFile::ExtractToDirectory(const Filename& fnZip, const Filename& fnDir, Int32 lFlags, ExtractDirectoryCallback fn, void* pData, const char* pChPassword)
{
	ZipLibCallR(false, ExtractToDirectory)(fnZip, fnDir, lFlags, fn, pData, pChPassword);
}

Bool ZipFile::Close()
{
	ZipLibCallR(false, CloseNC)();
}

Bool ZipFile::Close(const char* pchGlobalComment)
{
	ZipLibCallR(false, CloseCC)(pchGlobalComment);
}

Bool ZipFile::Close(const String& strGlobalComment)
{
	ZipLibCallR(false, CloseSC)(strGlobalComment);
}

Bool ZipFile::GetGlobalInfo(ZipFileGlobalInfo &i)
{
	ZipLibCallR(false, GetGlobalInfo)(i);
}

Bool ZipFile::GetGlobalComment(String& str)
{
	ZipLibCallR(false, GetGlobalComment)(str);
}



Bool ZipFile::CreateFileInZip(const String& strName, ZipWriteInfo* pInfo, void* pExtraFieldLocal, UInt32 lExtraSizeLocal, void* pExtraFieldGlobal, UInt32 lExtraSizeGlobal,
											 String* pstrComment, ZipMethod method, INT lLevel, const char* pchPassword, UInt32 ulCryptingCRC)
{
	ZipLibCallR(false, CreateFileInZip)(strName, pInfo, pExtraFieldLocal, lExtraSizeLocal, pExtraFieldGlobal, lExtraSizeGlobal,
		pstrComment, method, lLevel, pchPassword, ulCryptingCRC);
}

Bool ZipFile::WriteInFileInZip(const void* pBuffer, const UInt32 lLen, const Int32 lExpectedSize)
{
	ZipLibCallR(false, WriteInFileInZip)(pBuffer, lLen, lExpectedSize);
}

Bool ZipFile::CopyInFileInZip(const Filename& fn, const String& str, const char* pchPassword)
{
	ZipLibCallR(false, CopyInFileInZipA)(fn, str, pchPassword);
}

Bool ZipFile::CopyInFileInZip(const Filename& fn, const String& str, UInt32 ulInternalAttributes, UInt32 ulExternalAttributes, const char* pchPassword)
{
	ZipLibCallR(false, CopyInFileInZipB)(fn, str, ulInternalAttributes, ulExternalAttributes, pchPassword);
}

Bool ZipFile::SetCompressionLevel(Int32 level)
{
	ZipLibCallR(false, SetCompressionLevel)(level);
}

Int32 ZipFile::GetCompressionLevel() const
{
	ZipLibCallR(0, GetCompressionLevel)();
}

Bool ZipFile::CloseFileInZip()
{
	ZipLibCallR(false, CloseFileInZip)();
}
Bool ZipFile::CreateDirectoryInZip(const String& strName, ZipFileTime* pTime)
{
	ZipLibCallR(false, CreateDirectoryInZip)(strName, pTime);
}


Bool ZipFile::GoToFirstFile()
{
	ZipLibCallR(false, GoToFirstFile)();
}

Bool ZipFile::GoToNextFile()
{
	ZipLibCallR(false, GoToNextFile)();
}

Bool ZipFile::LocateFile(const String& strName)
{
	ZipLibCallR(false, LocateFile)(strName);
}

Bool ZipFile::GetCurrentFileInfo(ZipFileInfo &i)
{
	ZipLibCallR(false, GetCurrentFileInfoA)(i);
}

Bool ZipFile::GetCurrentFileInfo(String* pstrName, String* pstrComment, void* pExtraField, UInt32 lExtraFieldSize)
{
	ZipLibCallR(false, GetCurrentFileInfoB)(pstrName, pstrComment, pExtraField, lExtraFieldSize);
}

Bool ZipFile::OpenCurrentFile(const char* pChPassword)
{
	ZipLibCallR(false, OpenCurrentFile)(pChPassword);
}

Bool ZipFile::CloseCurrentFile()
{
	ZipLibCallR(false, CloseCurrentFile)();
}

Int32 ZipFile::ReadCurrentFile(void* pBuffer, UInt32 lBufferSize)
{
	ZipLibCallR(-1, ReadCurrentFile)(pBuffer, lBufferSize);
}

Int32 ZipFile::GetCurrentFileReadPosition()
{
	ZipLibCallR(false, GetCurrentFileReadPosition)();
}

Bool ZipFile::EndOfCurrentFile()
{
	ZipLibCallR(false, EndOfCurrentFile)();
}

Bool ZipFile::ExtractCurrentFile(const Filename& fnDir, Int32 lFlags, const char* pchPassword, Filename* pfnDest)
{
	ZipLibCallR(false, ExtractCurrentFile)(fnDir, lFlags, pchPassword, pfnDest);
}

Bool ZipFile::ExtractCurrentFile(const Filename& fnDir, BaseThread* pThread, Int32 lFlags, const char* pchPassword, Filename* pfnDest)
{
	ZipLibCallR(false, ExtractCurrentFileT)(fnDir, pThread, lFlags, pchPassword, pfnDest);
}


Bool GetFileTime(const Filename &fn, UINT &nYear, UINT &nMonth, UINT &nDay, UINT &nHour, UINT &nMinute, UINT &nSec, Int32 lType, Bool bIsDir)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, GetFileTime)); if (!lib) return false;
	return lib->GetFileTime(fn, nYear, nMonth, nDay, nHour, nMinute, nSec, lType, bIsDir);
}

Bool SetFileTime(const Filename &fn, UINT nYear, UINT nMonth, UINT nDay, UINT nHour, UINT nMinute, UINT nSec, Int32 lType, Bool bIsDir)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, SetFileTime)); if (!lib) return false;
	return lib->SetFileTime(fn, nYear, nMonth, nDay, nHour, nMinute, nSec, lType, bIsDir);
}

Bool CompressDataRaw(const void* pSrcData, Int lSrcLen, void* pDestData, Int* plDestLen, Int32 lLevel)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, CompressDataRaw)); if (!lib) return false;
	return lib->CompressDataRaw(pSrcData, lSrcLen, pDestData, plDestLen, lLevel);
}

Bool UncompressDataRaw(const void* pSrcData, Int lSrcLen, void* pDestData, Int* plDestLen, Int* plRead)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, UncompressDataRaw)); if (!lib) return false;
	return lib->UncompressDataRaw(pSrcData, lSrcLen, pDestData, plDestLen, plRead);
}

Bool CompressData(const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int32 lLevel)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, CompressData2)); if (!lib) return false;
	return lib->CompressData2(pSrcData, lSrcLen, pDestData, lDestLen, lLevel);
}

ZHandle* CompressDataInit(Int32 lLevel)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, CompressDataInit)); if (!lib) return nullptr;
	return lib->CompressDataInit(lLevel);
}

Bool CompressDataDoIt(ZHandle *handle, const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int32 flags)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, CompressDataDoIt)); if (!lib) return false;
	return lib->CompressDataDoIt(handle, pSrcData, lSrcLen, pDestData, lDestLen, flags);
}

void CompressDataFree(ZHandle *&handle)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, CompressData2)); if (!lib) return;
	lib->CompressDataFree(handle);
}

Bool UncompressData(const void* pSrcData, Int lSrcLen, void *&pDestData, Int &lDestLen, Int* plRead)
{
	ZipFileLib *lib = CheckLibZipFile(LIBOFFSET(ZipFileLib, UncompressData2)); if (!lib) return false;
	return lib->UncompressData2(pSrcData, lSrcLen, pDestData, lDestLen, plRead);
}
