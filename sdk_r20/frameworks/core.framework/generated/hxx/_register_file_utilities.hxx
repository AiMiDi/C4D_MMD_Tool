#if 1
namespace maxon
{
	const maxon::Char* const FileUtilities::MTable::_ids = 
		"ReadFileToMemory@a040586dc3e2f025\0" // ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr)
		"ReadUtfFile@7220b0ba4a759c18\0" // ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding)
		"WriteUtfFile@896ad10401125459\0" // WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader)
		"CompareFiles@d64eea1b1635b60f\0" // CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2)
		"CopyStream@47c51da783bf346e\0" // CopyStream(const InputStreamRef& from, const OutputStreamRef& to)
		"CopyFileOrDirectory@100dc7db9f8f1b8f\0" // CopyFileOrDirectory(const Url& from, const Url& to)
		"CopyFileOrDirectory@f288fd0b292bf7bc\0" // CopyFileOrDirectory(const Url& from, const String& to, const WriteArchiveRef& archive)
	"";
	class FileUtilities::Unresolved : public FileUtilities
	{
	public:
		static const Unresolved* Get(const FileUtilities* o) { return (const Unresolved*) o; }
		static Unresolved* Get(FileUtilities* o) { return (Unresolved*) o; }
		static Result<void> ReadFileToMemory(UrlOrInputStream&& name, WritableArrayInterface<Char>& arr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::ReadFileToMemory(std::forward<UrlOrInputStream>(name), arr); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> ReadUtfFile(UrlOrInputStream&& url, WritableArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING defaultDecoding) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::ReadUtfFile(std::forward<UrlOrInputStream>(url), arr, defaultDecoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> WriteUtfFile(const Url& url, const ArrayInterface<Utf32Char>& arr, UTFTEXT_OPTIONS::TEXTENCODING encoding, Bool dontWriteHeader) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::WriteUtfFile(url, arr, encoding, dontWriteHeader); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> CompareFiles(UrlOrInputStream&& file1, UrlOrInputStream&& file2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::CompareFiles(std::forward<UrlOrInputStream>(file1), std::forward<UrlOrInputStream>(file2)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> CopyStream(const InputStreamRef& from, const OutputStreamRef& to) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::CopyStream(from, to); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> CopyFileOrDirectory(const Url& from, const Url& to) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::CopyFileOrDirectory(from, to); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> CopyFileOrDirectory(const Url& from, const String& to, const WriteArchiveRef& archive) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileUtilities::CopyFileOrDirectory(from, to, archive); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE FileUtilities::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool FileUtilities::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_ReadFileToMemory = &Wrapper<Unresolved>::_FileUtilities_ReadFileToMemory;
	#else
		tbl->_FileUtilities_ReadFileToMemory = &Wrapper<Unresolved>::_FileUtilities_ReadFileToMemory;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_ReadUtfFile = &Wrapper<Unresolved>::_FileUtilities_ReadUtfFile;
	#else
		tbl->_FileUtilities_ReadUtfFile = &Wrapper<Unresolved>::_FileUtilities_ReadUtfFile;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_WriteUtfFile = &Wrapper<Unresolved>::_FileUtilities_WriteUtfFile;
	#else
		tbl->_FileUtilities_WriteUtfFile = &Wrapper<Unresolved>::_FileUtilities_WriteUtfFile;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_CompareFiles = &Wrapper<Unresolved>::_FileUtilities_CompareFiles;
	#else
		tbl->_FileUtilities_CompareFiles = &Wrapper<Unresolved>::_FileUtilities_CompareFiles;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_CopyStream = &Wrapper<Unresolved>::_FileUtilities_CopyStream;
	#else
		tbl->_FileUtilities_CopyStream = &Wrapper<Unresolved>::_FileUtilities_CopyStream;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_CopyFileOrDirectory = &Wrapper<Unresolved>::_FileUtilities_CopyFileOrDirectory;
	#else
		tbl->_FileUtilities_CopyFileOrDirectory = &Wrapper<Unresolved>::_FileUtilities_CopyFileOrDirectory;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileUtilities_CopyFileOrDirectory_1 = &Wrapper<Unresolved>::_FileUtilities_CopyFileOrDirectory_1;
	#else
		tbl->_FileUtilities_CopyFileOrDirectory_1 = &Wrapper<Unresolved>::_FileUtilities_CopyFileOrDirectory_1;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(FileUtilities, "net.maxon.interface.fileutilities", nullptr);
	template <typename DUMMY> maxon::Int FileUtilities::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_file_utilities(0
	| maxon::FileUtilities::PrivateInstantiateNullValueHelper<maxon::Int>()
);
