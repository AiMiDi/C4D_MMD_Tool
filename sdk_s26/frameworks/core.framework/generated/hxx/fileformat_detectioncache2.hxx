
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
	Result<Bool> (*FileFormatDetectionCacheInterface_DetectFile) (maxon::GenericComponent* this_, const Url& url, const Block<const DataType>& limitDetection);
	maxon::Int FileFormatDetectionCacheInterface_DetectFile_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatDetectionCacheInterface, DetectFile))
	{
		FileFormatDetectionCacheInterface_DetectFile = &W::FileFormatDetectionCacheInterface_DetectFile;
		FileFormatDetectionCacheInterface_DetectFile_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileFormatDetectionCacheInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (FileFormatDetectionCacheInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileFormatDetectionCacheInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<Bool> FileFormatDetectionCacheInterface_DetectFile(maxon::GenericComponent* this_, const Url& url, const Block<const DataType>& limitDetection) { return ((typename S::Implementation*) this_)->DetectFile(url, limitDetection); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::DetectFile(const Url& url, const Block<const DataType>& limitDetection) -> Result<Bool>
{
	const FileFormatDetectionCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatDetectionCacheInterface, this); return mt_.FileFormatDetectionCacheInterface_DetectFile((maxon::GenericComponent*) this + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset, url, limitDetection);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::Fn<S>::DetectFile(const Url& url, const Block<const DataType>& limitDetection) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileFormatDetectionCacheInterface* o_ = (FileFormatDetectionCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatDetectionCacheInterface, o_, FileFormatDetectionCacheInterface_DetectFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatDetectionCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatDetectionCacheInterface>() : PRIVATE_MAXON_VTABLE(FileFormatDetectionCacheInterface, o_); 
	return (mt_.FileFormatDetectionCacheInterface_DetectFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset, url, limitDetection));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::COWFn<S>::DetectFile(const Url& url, const Block<const DataType>& limitDetection) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileFormatDetectionCacheInterface* o_ = (FileFormatDetectionCacheInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatDetectionCacheInterface, o_, FileFormatDetectionCacheInterface_DetectFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatDetectionCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatDetectionCacheInterface>() : PRIVATE_MAXON_VTABLE(FileFormatDetectionCacheInterface, o_); 
	return (mt_.FileFormatDetectionCacheInterface_DetectFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset, url, limitDetection));
}
template <typename S> template <typename... LIMITTYPES> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::Fn<S>::DetectFile(const Url& url) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileFormatDetectionCacheInterface* o_ = (FileFormatDetectionCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->DetectFile<LIMITTYPES...>(url));
}
template <typename S> template <typename... LIMITTYPES> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionCacheInterface::Hxx1::COWFn<S>::DetectFile(const Url& url) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION FileFormatDetectionCacheInterface::DetectFile on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileFormatDetectionCacheInterface* o_ = (FileFormatDetectionCacheInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->DetectFile<LIMITTYPES...>(url));
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

