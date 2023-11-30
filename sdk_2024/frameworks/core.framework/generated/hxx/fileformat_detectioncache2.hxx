
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FileFormatDetectionCacheInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DetectFile);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(FileFormatDetectionCacheInterface_DetectFile, DetectFile, true, maxon::GenericComponent,, (Result<Bool>), const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection);
	maxon::Int FileFormatDetectionCacheInterface_DetectFile_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatDetectionCacheInterface, DetectFile))
	{
		maxon::Tie(FileFormatDetectionCacheInterface_DetectFile, FileFormatDetectionCacheInterface_DetectFile_Offset) = FileFormatDetectionCacheInterface_DetectFile_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<FileFormatDetectionCacheInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FileFormatDetectionCacheInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileFormatDetectionCacheInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DetectFile);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FileFormatDetectionCacheInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileFormatDetectionCacheInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FileFormatDetectionCacheInterface_DetectFile, maxon::GenericComponent,, (Result<Bool>), const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->DetectFile(url, flags, limitDetection); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection) -> Result<Bool>
{
	const FileFormatDetectionCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatDetectionCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset), mt_.FileFormatDetectionCacheInterface_DetectFile, url, flags, limitDetection);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::Fn<S>::DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(FileFormatDetectionCacheInterface_DetectFile); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset), mt_.FileFormatDetectionCacheInterface_DetectFile, url, flags, limitDetection));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::COWFn<S>::DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(FileFormatDetectionCacheInterface_DetectFile); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset), mt_.FileFormatDetectionCacheInterface_DetectFile, url, flags, limitDetection));
}
template <typename S> template <typename... LIMITTYPES> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::Fn<S>::DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->DetectFile<LIMITTYPES...>(url, flags));
}
template <typename S> template <typename... LIMITTYPES> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::COWFn<S>::DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXSUPER("FileFormatDetectionCacheInterface::DetectFile"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->DetectFile<LIMITTYPES...>(url, flags));
}
auto FileFormatDetectionCacheInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileFormatDetectionCacheInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_fileformat_detectioncache)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatDetectionCacheInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatDetectionCacheInterface() { new (s_ui_maxon_FileFormatDetectionCacheInterface) maxon::EntityUse(FileFormatDetectionCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_detectioncache.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatDetectionCacheInterface(FileFormatDetectionCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_detectioncache.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

