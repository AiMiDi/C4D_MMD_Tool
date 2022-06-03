
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FileFormatHandlerInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CreateHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDependends);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFileFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHandlerType);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const FileFormat& (*FileFormatHandlerInterface_GetFileFormat) (const maxon::GenericComponent* this_);
	maxon::Int FileFormatHandlerInterface_GetFileFormat_Offset;
	Result<DataType> (*FileFormatHandlerInterface_GetHandlerType) (const maxon::GenericComponent* this_);
	maxon::Int FileFormatHandlerInterface_GetHandlerType_Offset;
	Result<ObjectRef> (*FileFormatHandlerInterface_CreateHandler) (const maxon::GenericComponent* this_, const Url& url);
	maxon::Int FileFormatHandlerInterface_CreateHandler_Offset;
	FILEFORMAT_PRIORITY (*FileFormatHandlerInterface_GetDependends) (const maxon::GenericComponent* this_);
	maxon::Int FileFormatHandlerInterface_GetDependends_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetFileFormat))
	{
		FileFormatHandlerInterface_GetFileFormat = &W::FileFormatHandlerInterface_GetFileFormat;
		FileFormatHandlerInterface_GetFileFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetHandlerType))
	{
		FileFormatHandlerInterface_GetHandlerType = &W::FileFormatHandlerInterface_GetHandlerType;
		FileFormatHandlerInterface_GetHandlerType_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, CreateHandler))
	{
		FileFormatHandlerInterface_CreateHandler = &W::FileFormatHandlerInterface_CreateHandler;
		FileFormatHandlerInterface_CreateHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetDependends))
	{
		FileFormatHandlerInterface_GetDependends = &W::FileFormatHandlerInterface_GetDependends;
		FileFormatHandlerInterface_GetDependends_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileFormatHandlerInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FileFormatHandlerInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileFormatHandlerInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreateHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDependends);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFileFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHandlerType);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (FileFormatHandlerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileFormatHandlerInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const FileFormat& FileFormatHandlerInterface_GetFileFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFileFormat(); }
		static Result<DataType> FileFormatHandlerInterface_GetHandlerType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHandlerType(); }
		static Result<ObjectRef> FileFormatHandlerInterface_CreateHandler(const maxon::GenericComponent* this_, const Url& url) { return ((const typename S::Implementation*) this_)->CreateHandler(url); }
		static FILEFORMAT_PRIORITY FileFormatHandlerInterface_GetDependends(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDependends(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetFileFormat() const -> const FileFormat&
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_.FileFormatHandlerInterface_GetFileFormat((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_GetFileFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetHandlerType() const -> Result<DataType>
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_.FileFormatHandlerInterface_GetHandlerType((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_GetHandlerType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::CreateHandler(const Url& url) const -> Result<ObjectRef>
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_.FileFormatHandlerInterface_CreateHandler((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_CreateHandler_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetDependends() const -> FILEFORMAT_PRIORITY
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_.FileFormatHandlerInterface_GetDependends((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_GetDependends_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::GetFileFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetFileFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_.FileFormatHandlerInterface_GetFileFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_GetFileFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::GetHandlerType() const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetHandlerType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_.FileFormatHandlerInterface_GetHandlerType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_GetHandlerType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::CreateHandler(const Url& url) const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_CreateHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_.FileFormatHandlerInterface_CreateHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_CreateHandler_Offset, url));
}
template <typename S> template <typename HANDLER> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::CreateHandler(const Url& url) const -> Result<HANDLER>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<HANDLER>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION FileFormatHandlerInterface::CreateHandler on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->CreateHandler<HANDLER>(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::GetDependends() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<FILEFORMAT_PRIORITY>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetDependends) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_.FileFormatHandlerInterface_GetDependends(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_GetDependends_Offset));
}
auto FileFormatHandlerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileFormatHandlerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_fileformat_handler)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatHandlerInterface() { new (s_ui_maxon_FileFormatHandlerInterface) maxon::EntityUse(FileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_handler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatHandlerInterface(FileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_handler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* FileFormatDetectionInterface::PrivateGetCppName() { return nullptr; }
#ifndef MAXON_COMPILER_CLANG
#endif

struct FileFormatDetectionInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
#ifndef MAXON_COMPILER_CLANG
#endif
	Result<BaseArray<FileFormatHandler>> (*FileFormatDetectionInterface_DetectAll) (const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback);
	template <typename IMPL> void Init()
	{
#ifndef MAXON_COMPILER_CLANG
#endif
		FileFormatDetectionInterface_DetectAll = &IMPL::FileFormatDetectionInterface_DetectAll;
	}
};

struct FileFormatDetectionInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
#ifndef MAXON_COMPILER_CLANG
#endif
		static Result<BaseArray<FileFormatHandler>> FileFormatDetectionInterface_DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback) { return C::DetectAll(url, limitDetection, detectedCallback); }
	};

};
#ifndef MAXON_COMPILER_CLANG
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionInterface::DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback) -> Result<BaseArray<FileFormatHandler>>
{
	return MTable::_instance.FileFormatDetectionInterface_DetectAll(url, limitDetection, detectedCallback);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_fileformat_handler)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatDetectionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatDetectionInterface() { new (s_ui_maxon_FileFormatDetectionInterface) maxon::EntityUse(FileFormatDetectionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_handler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatDetectionInterface(FileFormatDetectionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_handler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

