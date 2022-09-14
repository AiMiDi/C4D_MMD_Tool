
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
	PRIVATE_MAXON_MF_POINTER(FileFormatHandlerInterface_GetFileFormat, GetFileFormat, true, maxon::GenericComponent, const, (const FileFormat&));
	maxon::Int FileFormatHandlerInterface_GetFileFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(FileFormatHandlerInterface_GetHandlerType, GetHandlerType, true, maxon::GenericComponent, const, (Result<DataType>));
	maxon::Int FileFormatHandlerInterface_GetHandlerType_Offset;
	PRIVATE_MAXON_MF_POINTER(FileFormatHandlerInterface_CreateHandler, CreateHandler, true, maxon::GenericComponent, const, (Result<ObjectRef>), const Url& url);
	maxon::Int FileFormatHandlerInterface_CreateHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(FileFormatHandlerInterface_GetDependends, GetDependends, true, maxon::GenericComponent, const, (FILEFORMAT_PRIORITY));
	maxon::Int FileFormatHandlerInterface_GetDependends_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetFileFormat))
	{
		maxon::Tie(FileFormatHandlerInterface_GetFileFormat, FileFormatHandlerInterface_GetFileFormat_Offset) = FileFormatHandlerInterface_GetFileFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetHandlerType))
	{
		maxon::Tie(FileFormatHandlerInterface_GetHandlerType, FileFormatHandlerInterface_GetHandlerType_Offset) = FileFormatHandlerInterface_GetHandlerType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, CreateHandler))
	{
		maxon::Tie(FileFormatHandlerInterface_CreateHandler, FileFormatHandlerInterface_CreateHandler_Offset) = FileFormatHandlerInterface_CreateHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetDependends))
	{
		maxon::Tie(FileFormatHandlerInterface_GetDependends, FileFormatHandlerInterface_GetDependends_Offset) = FileFormatHandlerInterface_GetDependends_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FileFormatHandlerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileFormatHandlerInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FileFormatHandlerInterface_GetFileFormat, maxon::GenericComponent, const, (const FileFormat&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFileFormat(); }
		PRIVATE_MAXON_MF_WRAPPER(FileFormatHandlerInterface_GetHandlerType, maxon::GenericComponent, const, (Result<DataType>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetHandlerType(); }
		PRIVATE_MAXON_MF_WRAPPER(FileFormatHandlerInterface_CreateHandler, maxon::GenericComponent, const, (Result<ObjectRef>), const Url& url) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->CreateHandler(url); }
		PRIVATE_MAXON_MF_WRAPPER(FileFormatHandlerInterface_GetDependends, maxon::GenericComponent, const, (FILEFORMAT_PRIORITY)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDependends(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetFileFormat() const -> const FileFormat&
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_GetFileFormat_Offset), mt_.FileFormatHandlerInterface_GetFileFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetHandlerType() const -> Result<DataType>
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_GetHandlerType_Offset), mt_.FileFormatHandlerInterface_GetHandlerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::CreateHandler(const Url& url) const -> Result<ObjectRef>
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_CreateHandler_Offset), mt_.FileFormatHandlerInterface_CreateHandler, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetDependends() const -> FILEFORMAT_PRIORITY
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FileFormatHandlerInterface_GetDependends_Offset), mt_.FileFormatHandlerInterface_GetDependends);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::GetFileFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetFileFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_GetFileFormat_Offset), mt_.FileFormatHandlerInterface_GetFileFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::GetHandlerType() const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetHandlerType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_GetHandlerType_Offset), mt_.FileFormatHandlerInterface_GetHandlerType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::CreateHandler(const Url& url) const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_CreateHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_CreateHandler_Offset), mt_.FileFormatHandlerInterface_CreateHandler, url));
}
template <typename S> template <typename HANDLER> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::CreateHandler(const Url& url) const -> Result<HANDLER>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<HANDLER>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION FileFormatHandlerInterface::CreateHandler on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->CreateHandler<HANDLER>(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstFn<S>::GetDependends() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<FILEFORMAT_PRIORITY>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetDependends) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileFormatHandlerInterface_GetDependends_Offset), mt_.FileFormatHandlerInterface_GetDependends));
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
	PRIVATE_MAXON_SF_POINTER(FileFormatDetectionInterface_DetectAll, DetectAll, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<FileFormatHandler>>), const Url& url, const Block<const DataType>& limitDetection, FILEFORMATDETECTIONFLAGS flags, const DetectedCallback& detectedCallback);
	template <typename IMPL> void Init()
	{
#ifndef MAXON_COMPILER_CLANG
#endif
		FileFormatDetectionInterface_DetectAll = FileFormatDetectionInterface_DetectAll_GetPtr<IMPL>(true);
	}
};

struct FileFormatDetectionInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
#ifndef MAXON_COMPILER_CLANG
#endif
		static Result<BaseArray<FileFormatHandler>> FileFormatDetectionInterface_DetectAll(const Url& url, const Block<const DataType>& limitDetection, FILEFORMATDETECTIONFLAGS flags, const DetectedCallback& detectedCallback) { return C::DetectAll(url, limitDetection, flags, detectedCallback); }
	};

};
#ifndef MAXON_COMPILER_CLANG
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionInterface::DetectAll(const Url& url, const Block<const DataType>& limitDetection, FILEFORMATDETECTIONFLAGS flags, const DetectedCallback& detectedCallback) -> Result<BaseArray<FileFormatHandler>>
{
	return MTable::_instance.FileFormatDetectionInterface_DetectAll(url, limitDetection, flags, detectedCallback);
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

