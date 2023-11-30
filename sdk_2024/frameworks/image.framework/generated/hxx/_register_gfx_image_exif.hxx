#if 1
namespace maxon
{
	const maxon::Char* const ExifInterface::MTable::_ids = 
		"GetExifDictionary@b4a6b0e29e3a2d07\0" // Result<DataDictionary> GetExifDictionary() const
	"";
	const maxon::METHOD_FLAGS ExifInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ExifInterface, , "net.maxon.image.interface.exif", (DataDictionaryObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ExifStaticInterface::MTable::_ids = 
		"OpenFromMemory@38ecba69687e6de4\0" // Result<ExifRef> OpenFromMemory(const Block<const Char>& exifChunk)
		"OpenJpgFromUrl@f5b0013c23b75005\0" // Result<ExifRef> OpenJpgFromUrl(const Url& fileName)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ExifStaticInterface::Hxx2::Unresolved : public ExifStaticInterface
	{
	public:
		static const Unresolved* Get(const ExifStaticInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ExifStaticInterface* o) { return (Unresolved*) o; }
		static Result<ExifRef> OpenFromMemory(const Block<const Char>& exifChunk) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExifStaticInterface::OpenFromMemory(exifChunk); return HXXRET1(UNRESOLVED);}
		static Result<ExifRef> OpenJpgFromUrl(const Url& fileName) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExifStaticInterface::OpenJpgFromUrl(fileName); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ExifStaticInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<ExifRef>>::value,
		maxon::details::UnresolvedReturnType<Result<ExifRef>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ExifStaticInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ExifRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ExifStaticInterface_OpenFromMemory = PRIVATE_MAXON_MF_CAST(decltype(ExifStaticInterface_OpenFromMemory), &Hxx2::Wrapper<Hxx2::Unresolved>::ExifStaticInterface_OpenFromMemory);
		#else
		tbl->ExifStaticInterface_OpenFromMemory = PRIVATE_MAXON_MF_CAST(decltype(ExifStaticInterface_OpenFromMemory), &Hxx2::Wrapper<Hxx2::Unresolved>::ExifStaticInterface_OpenFromMemory);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ExifRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ExifStaticInterface_OpenJpgFromUrl = PRIVATE_MAXON_MF_CAST(decltype(ExifStaticInterface_OpenJpgFromUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::ExifStaticInterface_OpenJpgFromUrl);
		#else
		tbl->ExifStaticInterface_OpenJpgFromUrl = PRIVATE_MAXON_MF_CAST(decltype(ExifStaticInterface_OpenJpgFromUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::ExifStaticInterface_OpenJpgFromUrl);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ExifStaticInterface, "net.maxon.image.interface.exifstatic", MAXON_INTERFACE_REGISTER_NULLIMPL(ExifStaticInterface), maxon::EntityBase::FLAGS::NONE);
}
#endif
