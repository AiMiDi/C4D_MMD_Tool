
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FileFormatInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Detect);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(FileFormatInterface_Detect, Detect, true, maxon::GenericComponent, const, (Result<Bool>), const Url& url, const InputStreamRef& probeStream, FILEFORMATDETECTIONFLAGS flags);
	maxon::Int FileFormatInterface_Detect_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatInterface, Detect))
	{
		maxon::Tie(FileFormatInterface_Detect, FileFormatInterface_Detect_Offset) = FileFormatInterface_Detect_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<FileFormatInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FileFormatInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileFormatInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Detect);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FileFormatInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileFormatInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FileFormatInterface_Detect, maxon::GenericComponent, const, (Result<Bool>), const Url& url, const InputStreamRef& probeStream, FILEFORMATDETECTIONFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Detect(url, probeStream, flags); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatInterface::Detect(const Url& url, const InputStreamRef& probeStream, FILEFORMATDETECTIONFLAGS flags) const -> Result<Bool>
{
	const FileFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FileFormatInterface_Detect_Offset), mt_.FileFormatInterface_Detect, url, probeStream, flags);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatInterface::Hxx1::ConstFn<S>::Detect(const Url& url, const InputStreamRef& probeStream, FILEFORMATDETECTIONFLAGS flags) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(FileFormatInterface_Detect); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatInterface_Detect_Offset), mt_.FileFormatInterface_Detect, url, probeStream, flags));
}
auto FileFormatInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileFormatInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_fileformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatInterface() { new (s_ui_maxon_FileFormatInterface) maxon::EntityUse(FileFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatInterface(FileFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

