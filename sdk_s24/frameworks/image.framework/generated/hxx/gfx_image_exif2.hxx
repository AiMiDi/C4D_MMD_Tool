
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ExifInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetExifDictionary);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<DataDictionary> (*_ExifInterface_GetExifDictionary) (const maxon::GenericComponent* this_);
	maxon::Int _ExifInterface_GetExifDictionary_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ExifInterface, GetExifDictionary))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ExifInterface, GetExifDictionary), W, MTable>::type::_ExifInterface_GetExifDictionary;
		_ExifInterface_GetExifDictionary = reinterpret_cast<const decltype(_ExifInterface_GetExifDictionary)&>(ptr);
		_ExifInterface_GetExifDictionary_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ExifInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ExifInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ExifInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExifDictionary);
		static Result<DataDictionary> _ExifInterface_GetExifDictionary(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetExifDictionary(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ExifInterface::GetExifDictionary() const -> Result<DataDictionary>
{
	const ExifInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ExifInterface, this); return mt_._ExifInterface_GetExifDictionary((const maxon::GenericComponent*) this + mt_._ExifInterface_GetExifDictionary_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ExifInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetExifDictionary() const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ExifInterface* o_ = (const ExifInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ExifInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ExifInterface, o_, ExifInterface_GetExifDictionary) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ExifInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ExifInterface>() : PRIVATE_MAXON_VTABLE(ExifInterface, o_); 
	return (mt_._ExifInterface_GetExifDictionary(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ExifInterface_GetExifDictionary_Offset));
}
auto ExifInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ExifInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ExifInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ExifInterface() { new (s_ui_maxon_ExifInterface) maxon::EntityUse(ExifInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_exif.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ExifInterface(ExifInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_exif.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* ExifStaticInterface::PrivateGetCppName() { return nullptr; }

struct ExifStaticInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<ExifRef> (*_ExifStaticInterface_OpenFromMemory) (const Block<const Char>& exifChunk);
	Result<ExifRef> (*_ExifStaticInterface_OpenJpgFromUrl) (const Url& fileName);
	template <typename IMPL> void Init()
	{
		_ExifStaticInterface_OpenFromMemory = &IMPL::_ExifStaticInterface_OpenFromMemory;
		_ExifStaticInterface_OpenJpgFromUrl = &IMPL::_ExifStaticInterface_OpenJpgFromUrl;
	}
};

struct ExifStaticInterface::Hxx2
{
	class Unresolved;
	class Null : public ExifStaticInterface
	{
	public:
	static const Null* Get(const ExifStaticInterface* o) { return (const Null*) o; }
	static Null* Get(ExifStaticInterface* o) { return (Null*) o; }
	static Result<ExifRef> OpenFromMemory(const Block<const Char>& exifChunk) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL); }
	static Result<ExifRef> OpenJpgFromUrl(const Url& fileName) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL); }
	};

	template <typename C> class Wrapper
	{
	public:
		static Result<ExifRef> _ExifStaticInterface_OpenFromMemory(const Block<const Char>& exifChunk) { return C::OpenFromMemory(exifChunk); }
		static Result<ExifRef> _ExifStaticInterface_OpenJpgFromUrl(const Url& fileName) { return C::OpenJpgFromUrl(fileName); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ExifStaticInterface::OpenFromMemory(const Block<const Char>& exifChunk) -> Result<ExifRef>
{
	return MTable::_instance._ExifStaticInterface_OpenFromMemory(exifChunk);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExifStaticInterface::OpenJpgFromUrl(const Url& fileName) -> Result<ExifRef>
{
	return MTable::_instance._ExifStaticInterface_OpenJpgFromUrl(fileName);
}

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

