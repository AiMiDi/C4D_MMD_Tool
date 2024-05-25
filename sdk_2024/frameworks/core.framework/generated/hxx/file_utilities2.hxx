
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(FileUtilities_ReadFileToMemory, ReadFileToMemory, MAXON_EXPAND_VA_ARGS, (Result<void>), UrlOrInputStream&& name, WritableArrayInterface<Char>& arr);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_ReadUtfFile, ReadUtfFile, MAXON_EXPAND_VA_ARGS, (Result<void>), UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_WriteUtfFile, WriteUtfFile, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CompareFiles, CompareFiles, MAXON_EXPAND_VA_ARGS, (Result<void>), UrlOrInputStream&& file1, UrlOrInputStream&& file2);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CopyStream, CopyStream, MAXON_EXPAND_VA_ARGS, (Result<void>), const InputStreamRef& from, const OutputStreamRef& to);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CopyStreamProgress, CopyStreamProgress, MAXON_EXPAND_VA_ARGS, (Result<void>), const InputStreamRef& from, const OutputStreamRef& to, const IoProgressDelegate& progress);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CopyFileOrDirectory, CopyFileOrDirectory, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& from, const Url& to);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CopyFileOrDirectory_1, CopyFileOrDirectory, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& from, const String& to, const WriteArchiveRef& archive);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_WriteDirectoryTree, WriteDirectoryTree, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& root, UrlOrOutputStream&& out, const WriteDirectoryFilterDelegate& filterDelegate);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_ReadDirectoryTree, ReadDirectoryTree, MAXON_EXPAND_VA_ARGS, (Result<Bool>), UrlOrInputStream&& in, const ReadDirectoryTreeReceiver& receiver);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CreateCStringOutputStream, CreateCStringOutputStream, MAXON_EXPAND_VA_ARGS, (Result<OutputStreamRef>), CString& str, Int maxLength);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_CreateNullOutputStream, CreateNullOutputStream, MAXON_EXPAND_VA_ARGS, (Result<OutputStreamRef>));
	PRIVATE_MAXON_SF_POINTER(FileUtilities_WriteArray, WriteArray, MAXON_EXPAND_VA_ARGS, (Result<void>), UrlOrOutputStream&& out, const Block<Char>& buffer);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_WriteString, WriteString, MAXON_EXPAND_VA_ARGS, (Result<void>), UrlOrOutputStream&& out, const String& string, const StringEncodingRef& encoding);
	PRIVATE_MAXON_SF_POINTER(FileUtilities_ReadString, ReadString, MAXON_EXPAND_VA_ARGS, (Result<String>), UrlOrInputStream&& in, const StringDecodingRef& decoding);
	template <typename IMPL> void Init()
	{
		FileUtilities_ReadFileToMemory = FileUtilities_ReadFileToMemory_GetPtr<IMPL>(true);
		FileUtilities_ReadUtfFile = FileUtilities_ReadUtfFile_GetPtr<IMPL>(true);
		FileUtilities_WriteUtfFile = FileUtilities_WriteUtfFile_GetPtr<IMPL>(true);
		FileUtilities_CompareFiles = FileUtilities_CompareFiles_GetPtr<IMPL>(true);
		FileUtilities_CopyStream = FileUtilities_CopyStream_GetPtr<IMPL>(true);
		FileUtilities_CopyStreamProgress = FileUtilities_CopyStreamProgress_GetPtr<IMPL>(true);
		FileUtilities_CopyFileOrDirectory = FileUtilities_CopyFileOrDirectory_GetPtr<IMPL>(true);
		FileUtilities_CopyFileOrDirectory_1 = FileUtilities_CopyFileOrDirectory_1_GetPtr<IMPL>(true);
		FileUtilities_WriteDirectoryTree = FileUtilities_WriteDirectoryTree_GetPtr<IMPL>(true);
		FileUtilities_ReadDirectoryTree = FileUtilities_ReadDirectoryTree_GetPtr<IMPL>(true);
		FileUtilities_CreateCStringOutputStream = FileUtilities_CreateCStringOutputStream_GetPtr<IMPL>(true);
		FileUtilities_CreateNullOutputStream = FileUtilities_CreateNullOutputStream_GetPtr<IMPL>(true);
		FileUtilities_WriteArray = FileUtilities_WriteArray_GetPtr<IMPL>(true);
		FileUtilities_WriteString = FileUtilities_WriteString_GetPtr<IMPL>(true);
		FileUtilities_ReadString = FileUtilities_ReadString_GetPtr<IMPL>(true);
	}
};

struct FileUtilities::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<void> FileUtilities_ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr) { return S::ReadFileToMemory(std::forward<UrlOrInputStream>(name), arr); }
		static Result<void> FileUtilities_ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding) { return S::ReadUtfFile(std::forward<UrlOrInputStream>(url), arr, defaultDecoding); }
		static Result<void> FileUtilities_WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader) { return S::WriteUtfFile(url, arr, encoding, dontWriteHeader); }
		static Result<void> FileUtilities_CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2) { return S::CompareFiles(std::forward<UrlOrInputStream>(file1), std::forward<UrlOrInputStream>(file2)); }
		static Result<void> FileUtilities_CopyStream(const InputStreamRef& from, const OutputStreamRef& to) { return S::CopyStream(from, to); }
		static Result<void> FileUtilities_CopyStreamProgress(const InputStreamRef& from, const OutputStreamRef& to, const IoProgressDelegate& progress) { return S::CopyStreamProgress(from, to, progress); }
		static Result<void> FileUtilities_CopyFileOrDirectory(const Url& from, const Url& to) { return S::CopyFileOrDirectory(from, to); }
		static Result<void> FileUtilities_CopyFileOrDirectory_1(const Url& from, const String& to, const WriteArchiveRef& archive) { return S::CopyFileOrDirectory(from, to, archive); }
		static Result<void> FileUtilities_WriteDirectoryTree(const Url& root, UrlOrOutputStream&& out, const WriteDirectoryFilterDelegate& filterDelegate) { return S::WriteDirectoryTree(root, std::forward<UrlOrOutputStream>(out), filterDelegate); }
		static Result<Bool> FileUtilities_ReadDirectoryTree(UrlOrInputStream&& in, const ReadDirectoryTreeReceiver& receiver) { return S::ReadDirectoryTree(std::forward<UrlOrInputStream>(in), receiver); }
		static Result<OutputStreamRef> FileUtilities_CreateCStringOutputStream(CString& str, Int maxLength) { return S::CreateCStringOutputStream(str, maxLength); }
		static Result<OutputStreamRef> FileUtilities_CreateNullOutputStream() { return S::CreateNullOutputStream(); }
		static Result<void> FileUtilities_WriteArray(UrlOrOutputStream&& out, const Block<Char>& buffer) { return S::WriteArray(std::forward<UrlOrOutputStream>(out), buffer); }
		static Result<void> FileUtilities_WriteString(UrlOrOutputStream&& out, const String& string, const StringEncodingRef& encoding) { return S::WriteString(std::forward<UrlOrOutputStream>(out), string, encoding); }
		static Result<String> FileUtilities_ReadString(UrlOrInputStream&& in, const StringDecodingRef& decoding) { return S::ReadString(std::forward<UrlOrInputStream>(in), decoding); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CreateCStringOutputStream(CString& str, Int maxLength) -> Result<OutputStreamRef>
{
	return MTable::_instance.FileUtilities_CreateCStringOutputStream(str, maxLength);
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

