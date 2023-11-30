
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
	PRIVATE_MAXON_MF_POINTER(ExifInterface_GetExifDictionary, GetExifDictionary, true, maxon::GenericComponent, const, (Result<DataDictionary>));
	maxon::Int ExifInterface_GetExifDictionary_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ExifInterface, GetExifDictionary))
	{
		maxon::Tie(ExifInterface_GetExifDictionary, ExifInterface_GetExifDictionary_Offset) = ExifInterface_GetExifDictionary_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ExifInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ExifInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ExifInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExifDictionary);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ExifInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ExifInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ExifInterface_GetExifDictionary, maxon::GenericComponent, const, (Result<DataDictionary>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetExifDictionary(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ExifInterface::GetExifDictionary() const -> Result<DataDictionary>
{
	const ExifInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ExifInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ExifInterface_GetExifDictionary_Offset), mt_.ExifInterface_GetExifDictionary);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ExifInterface::Hxx1::ConstFn<S>::GetExifDictionary() const -> Result<DataDictionary>
{
	HXXRETURN0(Result<DataDictionary>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ExifInterface_GetExifDictionary); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ExifInterface_GetExifDictionary_Offset), mt_.ExifInterface_GetExifDictionary));
}
auto ExifInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ExifInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_exif)
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(ExifStaticInterface_OpenFromMemory, OpenFromMemory, MAXON_EXPAND_VA_ARGS, (Result<ExifRef>), const Block<const Char>& exifChunk);
	PRIVATE_MAXON_SF_POINTER(ExifStaticInterface_OpenJpgFromUrl, OpenJpgFromUrl, MAXON_EXPAND_VA_ARGS, (Result<ExifRef>), const Url& fileName);
	template <typename IMPL> void Init()
	{
		ExifStaticInterface_OpenFromMemory = ExifStaticInterface_OpenFromMemory_GetPtr<IMPL>(true);
		ExifStaticInterface_OpenJpgFromUrl = ExifStaticInterface_OpenJpgFromUrl_GetPtr<IMPL>(true);
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
	static Result<ExifRef> OpenFromMemory(const Block<const Char>& exifChunk) { return HXXRET1(NULLIMPL); }
	static Result<ExifRef> OpenJpgFromUrl(const Url& fileName) { return HXXRET1(NULLIMPL); }
	};

	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<ExifRef> ExifStaticInterface_OpenFromMemory(const Block<const Char>& exifChunk) { return S::OpenFromMemory(exifChunk); }
		static Result<ExifRef> ExifStaticInterface_OpenJpgFromUrl(const Url& fileName) { return S::OpenJpgFromUrl(fileName); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ExifStaticInterface::OpenFromMemory(const Block<const Char>& exifChunk) -> Result<ExifRef>
{
	return MTable::_instance.ExifStaticInterface_OpenFromMemory(exifChunk);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExifStaticInterface::OpenJpgFromUrl(const Url& fileName) -> Result<ExifRef>
{
	return MTable::_instance.ExifStaticInterface_OpenJpgFromUrl(fileName);
}

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

