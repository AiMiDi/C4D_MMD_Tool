
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
	static const maxon::Bool HAS_NONSTATIC = false;
	const FileFormat& (*_FileFormatHandlerInterface_GetFileFormat) (const maxon::GenericComponent* this_);
	maxon::Int _FileFormatHandlerInterface_GetFileFormat_Offset;
	Result<DataType> (*_FileFormatHandlerInterface_GetHandlerType) (const maxon::GenericComponent* this_);
	maxon::Int _FileFormatHandlerInterface_GetHandlerType_Offset;
	Result<ObjectRef> (*_FileFormatHandlerInterface_CreateHandler) (const maxon::GenericComponent* this_, const Url& url);
	maxon::Int _FileFormatHandlerInterface_CreateHandler_Offset;
	FILEFORMAT_PRIORITY (*_FileFormatHandlerInterface_GetDependends) (const maxon::GenericComponent* this_);
	maxon::Int _FileFormatHandlerInterface_GetDependends_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetFileFormat))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetFileFormat), W, MTable>::type::_FileFormatHandlerInterface_GetFileFormat;
			_FileFormatHandlerInterface_GetFileFormat = reinterpret_cast<const decltype(_FileFormatHandlerInterface_GetFileFormat)&>(ptr);
			_FileFormatHandlerInterface_GetFileFormat_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetHandlerType))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetHandlerType), W, MTable>::type::_FileFormatHandlerInterface_GetHandlerType;
			_FileFormatHandlerInterface_GetHandlerType = reinterpret_cast<const decltype(_FileFormatHandlerInterface_GetHandlerType)&>(ptr);
			_FileFormatHandlerInterface_GetHandlerType_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, CreateHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, CreateHandler), W, MTable>::type::_FileFormatHandlerInterface_CreateHandler;
			_FileFormatHandlerInterface_CreateHandler = reinterpret_cast<const decltype(_FileFormatHandlerInterface_CreateHandler)&>(ptr);
			_FileFormatHandlerInterface_CreateHandler_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetDependends))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileFormatHandlerInterface, GetDependends), W, MTable>::type::_FileFormatHandlerInterface_GetDependends;
			_FileFormatHandlerInterface_GetDependends = reinterpret_cast<const decltype(_FileFormatHandlerInterface_GetDependends)&>(ptr);
			_FileFormatHandlerInterface_GetDependends_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileFormatHandlerInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FileFormatHandlerInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileFormatHandlerInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreateHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDependends);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFileFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHandlerType);
	static const FileFormat& _FileFormatHandlerInterface_GetFileFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFileFormat(); }
	static Result<DataType> _FileFormatHandlerInterface_GetHandlerType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHandlerType(); }
	static Result<ObjectRef> _FileFormatHandlerInterface_CreateHandler(const maxon::GenericComponent* this_, const Url& url) { return ((const typename S::Implementation*) this_)->CreateHandler(url); }
	static FILEFORMAT_PRIORITY _FileFormatHandlerInterface_GetDependends(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDependends(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetFileFormat() const -> const FileFormat&
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_._FileFormatHandlerInterface_GetFileFormat((const maxon::GenericComponent*) this + mt_._FileFormatHandlerInterface_GetFileFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetHandlerType() const -> Result<DataType>
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_._FileFormatHandlerInterface_GetHandlerType((const maxon::GenericComponent*) this + mt_._FileFormatHandlerInterface_GetHandlerType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::CreateHandler(const Url& url) const -> Result<ObjectRef>
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_._FileFormatHandlerInterface_CreateHandler((const maxon::GenericComponent*) this + mt_._FileFormatHandlerInterface_CreateHandler_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::GetDependends() const -> FILEFORMAT_PRIORITY
{
	const FileFormatHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, this); return mt_._FileFormatHandlerInterface_GetDependends((const maxon::GenericComponent*) this + mt_._FileFormatHandlerInterface_GetDependends_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFileFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetFileFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_._FileFormatHandlerInterface_GetFileFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_GetFileFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetHandlerType() const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetHandlerType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_._FileFormatHandlerInterface_GetHandlerType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_GetHandlerType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateHandler(const Url& url) const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_CreateHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_._FileFormatHandlerInterface_CreateHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_CreateHandler_Offset, url));
}
template <typename S> template <typename HANDLER> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateHandler(const Url& url) const -> Result<HANDLER>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<HANDLER>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION FileFormatHandlerInterface::CreateHandler on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->CreateHandler<HANDLER>(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDependends() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileFormatHandlerInterface* o_ = (const FileFormatHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileFormatHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<FILEFORMAT_PRIORITY>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileFormatHandlerInterface, o_, FileFormatHandlerInterface_GetDependends) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileFormatHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileFormatHandlerInterface>() : PRIVATE_MAXON_VTABLE(FileFormatHandlerInterface, o_); 
	return (mt_._FileFormatHandlerInterface_GetDependends(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_GetDependends_Offset));
}
auto FileFormatHandlerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileFormatHandlerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatHandlerInterface() { new (s_ui_maxon_FileFormatHandlerInterface) maxon::EntityUse(FileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_handler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatHandlerInterface(FileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fileformat_handler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
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
	Result<BaseArray<FileFormatHandler>> (*_FileFormatDetectionInterface_DetectAll) (const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback);
	template <typename IMPL> void Init()
	{
#ifndef MAXON_COMPILER_CLANG
#endif
		_FileFormatDetectionInterface_DetectAll = &IMPL::_FileFormatDetectionInterface_DetectAll;
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
	static Result<BaseArray<FileFormatHandler>> _FileFormatDetectionInterface_DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback) { return C::DetectAll(url, limitDetection, detectedCallback); }
	};

};
#ifndef MAXON_COMPILER_CLANG
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto FileFormatDetectionInterface::DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback) -> Result<BaseArray<FileFormatHandler>>
{
	return MTable::_instance._FileFormatDetectionInterface_DetectAll(url, limitDetection, detectedCallback);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

