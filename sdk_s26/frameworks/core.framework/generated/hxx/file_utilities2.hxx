
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* FileUtilities::PrivateGetCppName() { return nullptr; }

struct FileUtilities::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*FileUtilities_ReadFileToMemory) (UrlOrInputStream&& name, WritableArrayInterface<Char>& arr);
	Result<void> (*FileUtilities_ReadUtfFile) (UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding);
	Result<void> (*FileUtilities_WriteUtfFile) (const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader);
	Result<void> (*FileUtilities_CompareFiles) (UrlOrInputStream&& file1, UrlOrInputStream&& file2);
	Result<void> (*FileUtilities_CopyStream) (const InputStreamRef& from, const OutputStreamRef& to);
	Result<void> (*FileUtilities_CopyStreamProgress) (const InputStreamRef& from, const OutputStreamRef& to, const IoProgressDelegate& progress);
	Result<void> (*FileUtilities_CopyFileOrDirectory) (const Url& from, const Url& to);
	Result<void> (*FileUtilities_CopyFileOrDirectory_1) (const Url& from, const String& to, const WriteArchiveRef& archive);
	Result<void> (*FileUtilities_WriteDirectoryTree) (const Url& root, UrlOrOutputStream&& out, const WriteDirectoryFilterDelegate& filterDelegate);
	Result<Bool> (*FileUtilities_ReadDirectoryTree) (UrlOrInputStream&& in, const ReadDirectoryTreeReceiver& receiver);
	Result<OutputStreamRef> (*FileUtilities_CreateCStringOutputStream) (CString& str);
	Result<OutputStreamRef> (*FileUtilities_CreateCStringOutputStream_1) (CString& str, Int maxLength);
	Result<OutputStreamRef> (*FileUtilities_CreateNullOutputStream) ();
	Result<void> (*FileUtilities_WriteArray) (UrlOrOutputStream&& out, const Block<Char>& buffer);
	Result<void> (*FileUtilities_WriteString) (UrlOrOutputStream&& out, const String& string, const StringEncodingRef& encoding);
	Result<String> (*FileUtilities_ReadString) (UrlOrInputStream&& in, const StringDecodingRef& decoding);
	template <typename IMPL> void Init()
	{
		FileUtilities_ReadFileToMemory = &IMPL::FileUtilities_ReadFileToMemory;
		FileUtilities_ReadUtfFile = &IMPL::FileUtilities_ReadUtfFile;
		FileUtilities_WriteUtfFile = &IMPL::FileUtilities_WriteUtfFile;
		FileUtilities_CompareFiles = &IMPL::FileUtilities_CompareFiles;
		FileUtilities_CopyStream = &IMPL::FileUtilities_CopyStream;
		FileUtilities_CopyStreamProgress = &IMPL::FileUtilities_CopyStreamProgress;
		FileUtilities_CopyFileOrDirectory = &IMPL::FileUtilities_CopyFileOrDirectory;
		FileUtilities_CopyFileOrDirectory_1 = &IMPL::FileUtilities_CopyFileOrDirectory_1;
		FileUtilities_WriteDirectoryTree = &IMPL::FileUtilities_WriteDirectoryTree;
		FileUtilities_ReadDirectoryTree = &IMPL::FileUtilities_ReadDirectoryTree;
		FileUtilities_CreateCStringOutputStream = &IMPL::FileUtilities_CreateCStringOutputStream;
		FileUtilities_CreateCStringOutputStream_1 = &IMPL::FileUtilities_CreateCStringOutputStream_1;
		FileUtilities_CreateNullOutputStream = &IMPL::FileUtilities_CreateNullOutputStream;
		FileUtilities_WriteArray = &IMPL::FileUtilities_WriteArray;
		FileUtilities_WriteString = &IMPL::FileUtilities_WriteString;
		FileUtilities_ReadString = &IMPL::FileUtilities_ReadString;
	}
};

struct FileUtilities::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<void> FileUtilities_ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr) { return C::ReadFileToMemory(std::forward<UrlOrInputStream>(name), arr); }
		static Result<void> FileUtilities_ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding) { return C::ReadUtfFile(std::forward<UrlOrInputStream>(url), arr, defaultDecoding); }
		static Result<void> FileUtilities_WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader) { return C::WriteUtfFile(url, arr, encoding, dontWriteHeader); }
		static Result<void> FileUtilities_CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2) { return C::CompareFiles(std::forward<UrlOrInputStream>(file1), std::forward<UrlOrInputStream>(file2)); }
		static Result<void> FileUtilities_CopyStream(const InputStreamRef& from, const OutputStreamRef& to) { return C::CopyStream(from, to); }
		static Result<void> FileUtilities_CopyStreamProgress(const InputStreamRef& from, const OutputStreamRef& to, const IoProgressDelegate& progress) { return C::CopyStreamProgress(from, to, progress); }
		static Result<void> FileUtilities_CopyFileOrDirectory(const Url& from, const Url& to) { return C::CopyFileOrDirectory(from, to); }
		static Result<void> FileUtilities_CopyFileOrDirectory_1(const Url& from, const String& to, const WriteArchiveRef& archive) { return C::CopyFileOrDirectory(from, to, archive); }
		static Result<void> FileUtilities_WriteDirectoryTree(const Url& root, UrlOrOutputStream&& out, const WriteDirectoryFilterDelegate& filterDelegate) { return C::WriteDirectoryTree(root, std::forward<UrlOrOutputStream>(out), filterDelegate); }
		static Result<Bool> FileUtilities_ReadDirectoryTree(UrlOrInputStream&& in, const ReadDirectoryTreeReceiver& receiver) { return C::ReadDirectoryTree(std::forward<UrlOrInputStream>(in), receiver); }
		static Result<OutputStreamRef> FileUtilities_CreateCStringOutputStream(CString& str) { return C::CreateCStringOutputStream(str); }
		static Result<OutputStreamRef> FileUtilities_CreateCStringOutputStream_1(CString& str, Int maxLength) { return C::CreateCStringOutputStream(str, maxLength); }
		static Result<OutputStreamRef> FileUtilities_CreateNullOutputStream() { return C::CreateNullOutputStream(); }
		static Result<void> FileUtilities_WriteArray(UrlOrOutputStream&& out, const Block<Char>& buffer) { return C::WriteArray(std::forward<UrlOrOutputStream>(out), buffer); }
		static Result<void> FileUtilities_WriteString(UrlOrOutputStream&& out, const String& string, const StringEncodingRef& encoding) { return C::WriteString(std::forward<UrlOrOutputStream>(out), string, encoding); }
		static Result<String> FileUtilities_ReadString(UrlOrInputStream&& in, const StringDecodingRef& decoding) { return C::ReadString(std::forward<UrlOrInputStream>(in), decoding); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr) -> Result<void>
{
	return MTable::_instance.FileUtilities_ReadFileToMemory(std::forward<UrlOrInputStream>(name), arr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding) -> Result<void>
{
	return MTable::_instance.FileUtilities_ReadUtfFile(std::forward<UrlOrInputStream>(url), arr, defaultDecoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader) -> Result<void>
{
	return MTable::_instance.FileUtilities_WriteUtfFile(url, arr, encoding, dontWriteHeader);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2) -> Result<void>
{
	return MTable::_instance.FileUtilities_CompareFiles(std::forward<UrlOrInputStream>(file1), std::forward<UrlOrInputStream>(file2));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyStream(const InputStreamRef& from, const OutputStreamRef& to) -> Result<void>
{
	return MTable::_instance.FileUtilities_CopyStream(from, to);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyStreamProgress(const InputStreamRef& from, const OutputStreamRef& to, const IoProgressDelegate& progress) -> Result<void>
{
	return MTable::_instance.FileUtilities_CopyStreamProgress(from, to, progress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyFileOrDirectory(const Url& from, const Url& to) -> Result<void>
{
	return MTable::_instance.FileUtilities_CopyFileOrDirectory(from, to);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyFileOrDirectory(const Url& from, const String& to, const WriteArchiveRef& archive) -> Result<void>
{
	return MTable::_instance.FileUtilities_CopyFileOrDirectory_1(from, to, archive);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::WriteDirectoryTree(const Url& root, UrlOrOutputStream&& out, const WriteDirectoryFilterDelegate& filterDelegate) -> Result<void>
{
	return MTable::_instance.FileUtilities_WriteDirectoryTree(root, std::forward<UrlOrOutputStream>(out), filterDelegate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::ReadDirectoryTree(UrlOrInputStream&& in, const ReadDirectoryTreeReceiver& receiver) -> Result<Bool>
{
	return MTable::_instance.FileUtilities_ReadDirectoryTree(std::forward<UrlOrInputStream>(in), receiver);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CreateCStringOutputStream(CString& str) -> Result<OutputStreamRef>
{
	return MTable::_instance.FileUtilities_CreateCStringOutputStream(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CreateCStringOutputStream(CString& str, Int maxLength) -> Result<OutputStreamRef>
{
	return MTable::_instance.FileUtilities_CreateCStringOutputStream_1(str, maxLength);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CreateNullOutputStream() -> Result<OutputStreamRef>
{
	return MTable::_instance.FileUtilities_CreateNullOutputStream();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::WriteArray(UrlOrOutputStream&& out, const Block<Char>& buffer) -> Result<void>
{
	return MTable::_instance.FileUtilities_WriteArray(std::forward<UrlOrOutputStream>(out), buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::WriteString(UrlOrOutputStream&& out, const String& string, const StringEncodingRef& encoding) -> Result<void>
{
	return MTable::_instance.FileUtilities_WriteString(std::forward<UrlOrOutputStream>(out), string, encoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::ReadString(UrlOrInputStream&& in, const StringDecodingRef& decoding) -> Result<String>
{
	return MTable::_instance.FileUtilities_ReadString(std::forward<UrlOrInputStream>(in), decoding);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_file_utilities)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileUtilities); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileUtilities() { new (s_ui_maxon_FileUtilities) maxon::EntityUse(FileUtilities::_interface.GetReference(), &maxon::g_translationUnit, "maxon/file_utilities.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileUtilities(FileUtilities::_interface.GetReference(), &maxon::g_translationUnit, "maxon/file_utilities.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

