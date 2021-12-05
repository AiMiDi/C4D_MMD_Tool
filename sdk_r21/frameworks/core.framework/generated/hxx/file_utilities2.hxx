
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FileUtilities::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_FileUtilities_ReadFileToMemory) (UrlOrInputStream&& name, WritableArrayInterface<Char>& arr);
	Result<void> (*_FileUtilities_ReadUtfFile) (UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding);
	Result<void> (*_FileUtilities_WriteUtfFile) (const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader);
	Result<void> (*_FileUtilities_CompareFiles) (UrlOrInputStream&& file1, UrlOrInputStream&& file2);
	Result<void> (*_FileUtilities_CopyStream) (const InputStreamRef& from, const OutputStreamRef& to);
	Result<void> (*_FileUtilities_CopyFileOrDirectory) (const Url& from, const Url& to);
	Result<void> (*_FileUtilities_CopyFileOrDirectory_1) (const Url& from, const String& to, const WriteArchiveRef& archive);
	template <typename IMPL> void Init()
	{
		_FileUtilities_ReadFileToMemory = &IMPL::_FileUtilities_ReadFileToMemory;
		_FileUtilities_ReadUtfFile = &IMPL::_FileUtilities_ReadUtfFile;
		_FileUtilities_WriteUtfFile = &IMPL::_FileUtilities_WriteUtfFile;
		_FileUtilities_CompareFiles = &IMPL::_FileUtilities_CompareFiles;
		_FileUtilities_CopyStream = &IMPL::_FileUtilities_CopyStream;
		_FileUtilities_CopyFileOrDirectory = &IMPL::_FileUtilities_CopyFileOrDirectory;
		_FileUtilities_CopyFileOrDirectory_1 = &IMPL::_FileUtilities_CopyFileOrDirectory_1;
	}
};

struct FileUtilities::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<void> _FileUtilities_ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr) { return C::ReadFileToMemory(std::forward<UrlOrInputStream>(name), arr); }
	static Result<void> _FileUtilities_ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding) { return C::ReadUtfFile(std::forward<UrlOrInputStream>(url), arr, defaultDecoding); }
	static Result<void> _FileUtilities_WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader) { return C::WriteUtfFile(url, arr, encoding, dontWriteHeader); }
	static Result<void> _FileUtilities_CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2) { return C::CompareFiles(std::forward<UrlOrInputStream>(file1), std::forward<UrlOrInputStream>(file2)); }
	static Result<void> _FileUtilities_CopyStream(const InputStreamRef& from, const OutputStreamRef& to) { return C::CopyStream(from, to); }
	static Result<void> _FileUtilities_CopyFileOrDirectory(const Url& from, const Url& to) { return C::CopyFileOrDirectory(from, to); }
	static Result<void> _FileUtilities_CopyFileOrDirectory_1(const Url& from, const String& to, const WriteArchiveRef& archive) { return C::CopyFileOrDirectory(from, to, archive); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr) -> Result<void>
{
	return MTable::_instance._FileUtilities_ReadFileToMemory(std::forward<UrlOrInputStream>(name), arr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding) -> Result<void>
{
	return MTable::_instance._FileUtilities_ReadUtfFile(std::forward<UrlOrInputStream>(url), arr, defaultDecoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader) -> Result<void>
{
	return MTable::_instance._FileUtilities_WriteUtfFile(url, arr, encoding, dontWriteHeader);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2) -> Result<void>
{
	return MTable::_instance._FileUtilities_CompareFiles(std::forward<UrlOrInputStream>(file1), std::forward<UrlOrInputStream>(file2));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyStream(const InputStreamRef& from, const OutputStreamRef& to) -> Result<void>
{
	return MTable::_instance._FileUtilities_CopyStream(from, to);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyFileOrDirectory(const Url& from, const Url& to) -> Result<void>
{
	return MTable::_instance._FileUtilities_CopyFileOrDirectory(from, to);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileUtilities::CopyFileOrDirectory(const Url& from, const String& to, const WriteArchiveRef& archive) -> Result<void>
{
	return MTable::_instance._FileUtilities_CopyFileOrDirectory_1(from, to, archive);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

