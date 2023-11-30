#ifndef FILE_UTILITIES_H__
#define FILE_UTILITIES_H__


#include "maxon/url.h"
#include "maxon/array.h"
#include "maxon/streamconversion.h"


namespace maxon
{

class WriteArchiveRef;

class FileUtilities
{
	MAXON_INTERFACE_NONVIRTUAL(FileUtilities, MAXON_REFERENCE_STATIC, "net.maxon.interface.fileutilities");

public:
	//----------------------------------------------------------------------------------------
	/// Reads a file into memory.
	/// @param[in] name								Name or Stream of the file.
	/// @param[out] arr								Array holding the memory, will be initialized inside.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr);

	//----------------------------------------------------------------------------------------
	/// Reads a file into memory. If an UTF encoding is detected the proper decoding takes place.
	/// @param[in] url								Name or Stream of the file.
	/// @param[out] arr								Array holding the memory, will be initialized inside.
	/// @param[in] defaultDecoding		The character decoding that will be used if the file does not contain any Byte Order Mark (BOM).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding = UTFTEXT_OPTIONS::TEXTENCODING::UTF8);

	//----------------------------------------------------------------------------------------
	/// Writes a Utf32Char array from memory to disc in a UTF-encoded format.
	/// @param[in] url								The file to be written.
	/// @param[in] arr								Array holding the data.
	/// @param[in] encoding						The character encoding to be used.
	/// @param[in] dontWriteHeader		If true the utf8 header will not be written.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding = UTFTEXT_OPTIONS::TEXTENCODING::UTF8, Bool dontWriteHeader = false);

	//----------------------------------------------------------------------------------------
	/// Compares the content of 2 files for binary equality.
	/// @param[in] file1							Name or Stream of the file 1.
	/// @param[in] file2							Name or Stream of the file 2.
	/// @return												Success and result of the comparison. If the files don't match or cannot be read an error is returned.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2);

	//----------------------------------------------------------------------------------------
	/// Reads stream directly into an array
	/// @param[in] url								path to stream
	/// @param[out] dest							BaseArray where the data is stored
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<void> ReadToArray(UrlOrInputStream&& url, BaseArray<T>& dest);

	//----------------------------------------------------------------------------------------
	/// Copies all bytes from #from to #to. This function reads bytes as long as possible.
	/// It doesn't call the Close() method on #from or #to.
	/// @param[in] from								The stream from which the bytes shall be read.
	/// @param[in] to									The stream to which the bytes shall be written.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CopyStream(const InputStreamRef& from, const OutputStreamRef& to);

	//----------------------------------------------------------------------------------------
	/// Copies all bytes from #from to #to. This function reads bytes as long as possible.
	/// It doesn't call the Close() method on #from or #to.
	/// @param[in] from								The stream from which the bytes shall be read.
	/// @param[in] to									The stream to which the bytes shall be written.
	/// @param[in] progress						Progress delegate which is called to notify about the progress.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CopyStreamProgress(const InputStreamRef& from, const OutputStreamRef& to, const IoProgressDelegate& progress);

	//----------------------------------------------------------------------------------------
	/// Copies the file or directory #from to #to. If it doesn't already exist, a file or directory
	/// is created for the Url #to. For a file its content is copied, for a directory a recursive copy
	/// happens. Symbolic links are skipped.
	/// @param[in] from								The source Url.
	/// @param[in] to									The destination Url.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CopyFileOrDirectory(const Url& from, const Url& to);

	//----------------------------------------------------------------------------------------
	/// Copies the file or directory #from into an archive #archive/#to. If it doesn't already exist, a file or directory
	/// is created for the Url #to. For a file its content is copied, for a directory a recursive copy
	/// happens. Symbolic links are skipped.
	/// @param[in] from								The source Url.
	/// @param[in] to									The relative destination Url in the archive.
	/// @param[in] archive						Archive to write to.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CopyFileOrDirectory(const Url& from, const String& to, const WriteArchiveRef& archive);

	/// return true to add file to index, false to ignore in index
	using WriteDirectoryFilterDelegate = Delegate<Bool(const Url& url)>;
	using ReadDirectoryTreeReceiver = ValueReceiver<const Block<const String>&, Int64, const DataDictionary&>;

	static MAXON_METHOD Result<void> WriteDirectoryTree(const Url& root, UrlOrOutputStream&& out, const WriteDirectoryFilterDelegate& filterDelegate);

	static MAXON_METHOD Result<Bool> ReadDirectoryTree(UrlOrInputStream&& in, const ReadDirectoryTreeReceiver& receiver);

	//----------------------------------------------------------------------------------------
	/// Creates an output stream which writes to the given CString. Whenever bytes are written to the
	/// stream, these will be appended to str.
	/// @param[out] str								The string to write to. You have to keep the object alive as long as the stream is in use.
	/// 															Previously existing content of str is kept.
	/// @param[in] maxLength					The maximum length of the string. When this limit is exceeded, no further characters will be appended.
	/// @return												New output stream.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<OutputStreamRef> CreateCStringOutputStream(CString& str, Int maxLength = LIMIT<Int>::MAX);

	//----------------------------------------------------------------------------------------
	/// Creates an output stream which just discards any bytes written to it without reporting errors
	/// (similar to the null device of operating systems, e.g. @c{/dev/null}).
	/// @return												New output stream.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<OutputStreamRef> CreateNullOutputStream();

	static MAXON_METHOD Result<void> WriteArray(UrlOrOutputStream&& out, const Block<Char>& buffer);

	static MAXON_METHOD Result<void> WriteString(UrlOrOutputStream&& out, const String& string, const StringEncodingRef& encoding = GetUtf8DefaultEncoder());

	static MAXON_METHOD Result<String> ReadString(UrlOrInputStream&& in, const StringDecodingRef& decoding = GetUtf8DefaultDecoder());
};

#include "file_utilities1.hxx"

#include "file_utilities2.hxx"

template <typename T> Result<void> FileUtilities::ReadToArray(UrlOrInputStream&& url, BaseArray<T>& dest)
{
	iferr_scope;

	InputStreamRef stream = url.GetStream() iferr_return;
	Int64 size64 = stream.GetStreamLength() iferr_return;
	Int size = Int64ToInt(size64) iferr_return;
	Int elementsToRead = size / (Int)sizeof(T);

	if (elementsToRead * (Int)sizeof(T) != size)
		return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Array size @ not matching number of elements @ to read.", size, elementsToRead));

	dest.Resize(elementsToRead) iferr_return;
	stream.Read(dest) iferr_return;

	return OK;
}

//----------------------------------------------------------------------------------------
/// Controls a source control system, e.g. Perforce.
/// @return												true if if system is available
//----------------------------------------------------------------------------------------
inline Bool IsSourceControlAvailable()
{
	// p4 is x86 only lib and not available for iOS
	#if defined(MAXON_TARGET_CPU_X86) && !defined(MAXON_TARGET_IOS)
		return true;
	#else
		return false;
	#endif
}

}

#endif // FILE_UTILITIES_H__
