
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct LoggerTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Flush);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableLoggerNotify);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(LoggerTypeInterface_Write, Write, true, maxon::GenericComponent,, (Result<void>), const String& str, const SourceLocation& loc, WRITEMETA level);
	maxon::Int LoggerTypeInterface_Write_Offset;
	PRIVATE_MAXON_MF_POINTER(LoggerTypeInterface_Flush, Flush, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int LoggerTypeInterface_Flush_Offset;
	PRIVATE_MAXON_MF_POINTER(LoggerTypeInterface_ObservableLoggerNotify, ObservableLoggerNotify, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableLoggerNotifyDelegate>));
	maxon::Int LoggerTypeInterface_ObservableLoggerNotify_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Write))
	{
		maxon::Tie(LoggerTypeInterface_Write, LoggerTypeInterface_Write_Offset) = LoggerTypeInterface_Write_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Flush))
	{
		maxon::Tie(LoggerTypeInterface_Flush, LoggerTypeInterface_Flush_Offset) = LoggerTypeInterface_Flush_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, ObservableLoggerNotify))
	{
		maxon::Tie(LoggerTypeInterface_ObservableLoggerNotify, LoggerTypeInterface_ObservableLoggerNotify_Offset) = LoggerTypeInterface_ObservableLoggerNotify_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LoggerTypeInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<typename ObserverObjectInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<LoggerTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LoggerTypeInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<typename ObserverObjectInterface::Hxx2::template CWrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Flush);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableLoggerNotify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (LoggerTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, LoggerTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(LoggerTypeInterface_Write, maxon::GenericComponent,, (Result<void>), const String& str, const SourceLocation& loc, WRITEMETA level) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Write(str, loc, level); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerTypeInterface_Flush, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerTypeInterface_ObservableLoggerNotify, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableLoggerNotifyDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableLoggerNotify(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Write(const String& str, const SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.LoggerTypeInterface_Write_Offset), mt_.LoggerTypeInterface_Write, str, loc, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Flush() -> Result<void>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.LoggerTypeInterface_Flush_Offset), mt_.LoggerTypeInterface_Flush);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::ObservableLoggerNotify() const -> maxon::ObservableRef<ObservableLoggerNotifyDelegate>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.LoggerTypeInterface_ObservableLoggerNotify_Offset), mt_.LoggerTypeInterface_ObservableLoggerNotify);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::Fn<S>::Write(const String& str, const SourceLocation& loc, WRITEMETA level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Write_Offset), mt_.LoggerTypeInterface_Write, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::COWFn<S>::Write(const String& str, const SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Write_Offset), mt_.LoggerTypeInterface_Write, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::Fn<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Flush_Offset), mt_.LoggerTypeInterface_Flush));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::COWFn<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Flush_Offset), mt_.LoggerTypeInterface_Flush));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::ConstFn<S>::ObservableLoggerNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LoggerTypeInterface* o_ = (const LoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LoggerTypeInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableLoggerNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_ObservableLoggerNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_ObservableLoggerNotify_Offset), mt_.LoggerTypeInterface_ObservableLoggerNotify));
}
auto LoggerTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LoggerTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_logger)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LoggerTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LoggerTypeInterface() { new (s_ui_maxon_LoggerTypeInterface) maxon::EntityUse(LoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LoggerTypeInterface(LoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct FileLoggerTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(FileLoggerTypeInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const Url& url);
	maxon::Int FileLoggerTypeInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(FileLoggerTypeInterface_GetUrl, GetUrl, true, maxon::GenericComponent, const, (Url));
	maxon::Int FileLoggerTypeInterface_GetUrl_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, Init))
	{
		maxon::Tie(FileLoggerTypeInterface_Init, FileLoggerTypeInterface_Init_Offset) = FileLoggerTypeInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, GetUrl))
	{
		maxon::Tie(FileLoggerTypeInterface_GetUrl, FileLoggerTypeInterface_GetUrl_Offset) = FileLoggerTypeInterface_GetUrl_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileLoggerTypeInterface, typename LoggerTypeInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FileLoggerTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileLoggerTypeInterface::Hxx2
{
	template <typename S> class CWrapper : public LoggerTypeInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename LoggerTypeInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FileLoggerTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileLoggerTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FileLoggerTypeInterface_Init, maxon::GenericComponent,, (Result<void>), const Url& url) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(url); }
		PRIVATE_MAXON_MF_WRAPPER(FileLoggerTypeInterface_GetUrl, maxon::GenericComponent, const, (Url)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Init(const Url& url) -> Result<void>
{
	const FileLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.FileLoggerTypeInterface_Init_Offset), mt_.FileLoggerTypeInterface_Init, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::GetUrl() const -> Url
{
	const FileLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FileLoggerTypeInterface_GetUrl_Offset), mt_.FileLoggerTypeInterface_GetUrl);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::Fn<S>::Init(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FileLoggerTypeInterface* o_ = (FileLoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_Init_Offset), mt_.FileLoggerTypeInterface_Init, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::COWFn<S>::Init(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FileLoggerTypeInterface* o_ = (FileLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_Init_Offset), mt_.FileLoggerTypeInterface_Init, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FileLoggerTypeInterface* o_ = (const FileLoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FileLoggerTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_GetUrl_Offset), mt_.FileLoggerTypeInterface_GetUrl));
}
auto FileLoggerTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileLoggerTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_logger)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileLoggerTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileLoggerTypeInterface() { new (s_ui_maxon_FileLoggerTypeInterface) maxon::EntityUse(FileLoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileLoggerTypeInterface(FileLoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UserLoggerTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Iterate);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(UserLoggerTypeInterface_Iterate, Iterate, true, maxon::GenericComponent,, (Result<void>), const Delegate<Result<void>(LoggerLine&)>& callback);
	maxon::Int UserLoggerTypeInterface_Iterate_Offset;
	PRIVATE_MAXON_MF_POINTER(UserLoggerTypeInterface_GetCount, GetCount, true, maxon::GenericComponent,, (Int));
	maxon::Int UserLoggerTypeInterface_GetCount_Offset;
	PRIVATE_MAXON_MF_POINTER(UserLoggerTypeInterface_Reset, Reset, true, maxon::GenericComponent,, (void));
	maxon::Int UserLoggerTypeInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Iterate))
	{
		maxon::Tie(UserLoggerTypeInterface_Iterate, UserLoggerTypeInterface_Iterate_Offset) = UserLoggerTypeInterface_Iterate_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, GetCount))
	{
		maxon::Tie(UserLoggerTypeInterface_GetCount, UserLoggerTypeInterface_GetCount_Offset) = UserLoggerTypeInterface_GetCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Reset))
	{
		maxon::Tie(UserLoggerTypeInterface_Reset, UserLoggerTypeInterface_Reset_Offset) = UserLoggerTypeInterface_Reset_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UserLoggerTypeInterface, typename LoggerTypeInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UserLoggerTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UserLoggerTypeInterface::Hxx2
{
	template <typename S> class CWrapper : public LoggerTypeInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Iterate);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename LoggerTypeInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (UserLoggerTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UserLoggerTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(UserLoggerTypeInterface_Iterate, maxon::GenericComponent,, (Result<void>), const Delegate<Result<void>(LoggerLine&)>& callback) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Iterate(callback); }
		PRIVATE_MAXON_MF_WRAPPER(UserLoggerTypeInterface_GetCount, maxon::GenericComponent,, (Int)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetCount(); }
		PRIVATE_MAXON_MF_WRAPPER(UserLoggerTypeInterface_Reset, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) -> Result<void>
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.UserLoggerTypeInterface_Iterate_Offset), mt_.UserLoggerTypeInterface_Iterate, callback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::GetCount() -> Int
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.UserLoggerTypeInterface_GetCount_Offset), mt_.UserLoggerTypeInterface_GetCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Reset() -> void
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.UserLoggerTypeInterface_Reset_Offset), mt_.UserLoggerTypeInterface_Reset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::Fn<S>::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Iterate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Iterate_Offset), mt_.UserLoggerTypeInterface_Iterate, callback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWFn<S>::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Iterate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Iterate_Offset), mt_.UserLoggerTypeInterface_Iterate, callback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::Fn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_GetCount_Offset), mt_.UserLoggerTypeInterface_GetCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWFn<S>::GetCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_GetCount_Offset), mt_.UserLoggerTypeInterface_GetCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Reset_Offset), mt_.UserLoggerTypeInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Reset_Offset), mt_.UserLoggerTypeInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto UserLoggerTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UserLoggerTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_logger)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UserLoggerTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UserLoggerTypeInterface() { new (s_ui_maxon_UserLoggerTypeInterface) maxon::EntityUse(UserLoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UserLoggerTypeInterface(UserLoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* LoggerInterface::PrivateGetCppName() { return "maxon::LoggerRef"; }

struct LoggerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(LoggerInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const LoggerInterface* object);
	PRIVATE_MAXON_SF_POINTER(LoggerInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (LoggerInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_AddLoggerType, AddLoggerType, false, LoggerInterface,, (Result<void>), TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_RemoveLoggerType, RemoveLoggerType, false, LoggerInterface,, (Result<void>), LoggerTypeRef& loggerType);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_RemoveLoggerTypes, RemoveLoggerTypes, false, LoggerInterface,, (Result<void>), const Class<LoggerTypeRef>& loggerTypeCls);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_Write, Write, false, LoggerInterface,, (Result<void>), TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_GetName, GetName, false, LoggerInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_SetName, SetName, false, LoggerInterface,, (void), const String& name);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_Enable, Enable, false, LoggerInterface,, (void), Bool enable);
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_IsEnabled, IsEnabled, false, LoggerInterface,, (Bool));
	PRIVATE_MAXON_MF_POINTER(LoggerInterface_GetLoggerTypes, GetLoggerTypes, false, LoggerInterface, const, (BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>));
	PRIVATE_MAXON_SF_POINTER(LoggerInterface_ObservableLoggerNew, ObservableLoggerNew, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableLoggerNewDelegate>));
	PRIVATE_MAXON_SF_POINTER(LoggerInterface_AddNewLogger, AddNewLogger, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module);
	template <typename IMPL> void Init()
	{
		LoggerInterface_Free = LoggerInterface_Free_GetPtr<IMPL>(true);
		LoggerInterface_Alloc = LoggerInterface_Alloc_GetPtr<IMPL>(true);
		LoggerInterface_AddLoggerType = LoggerInterface_AddLoggerType_GetPtr<IMPL>(0, true).first;
		LoggerInterface_RemoveLoggerType = LoggerInterface_RemoveLoggerType_GetPtr<IMPL>(0, true).first;
		LoggerInterface_RemoveLoggerTypes = LoggerInterface_RemoveLoggerTypes_GetPtr<IMPL>(0, true).first;
		LoggerInterface_Write = LoggerInterface_Write_GetPtr<IMPL>(0, true).first;
		LoggerInterface_GetName = LoggerInterface_GetName_GetPtr<IMPL>(0, true).first;
		LoggerInterface_SetName = LoggerInterface_SetName_GetPtr<IMPL>(0, true).first;
		LoggerInterface_Enable = LoggerInterface_Enable_GetPtr<IMPL>(0, true).first;
		LoggerInterface_IsEnabled = LoggerInterface_IsEnabled_GetPtr<IMPL>(0, true).first;
		LoggerInterface_GetLoggerTypes = LoggerInterface_GetLoggerTypes_GetPtr<IMPL>(0, true).first;
		LoggerInterface_ObservableLoggerNew = LoggerInterface_ObservableLoggerNew_GetPtr<IMPL>(true);
		LoggerInterface_AddNewLogger = LoggerInterface_AddNewLogger_GetPtr<IMPL>(true);
	}
};

struct LoggerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void LoggerInterface_Free(const LoggerInterface* object) { return C::Free(object); }
		static LoggerInterface* LoggerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_AddLoggerType, LoggerInterface,, (Result<void>), TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->AddLoggerType(ta, loggerTypeCls, cb); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_RemoveLoggerType, LoggerInterface,, (Result<void>), LoggerTypeRef& loggerType) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->RemoveLoggerType(loggerType); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_RemoveLoggerTypes, LoggerInterface,, (Result<void>), const Class<LoggerTypeRef>& loggerTypeCls) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->RemoveLoggerTypes(loggerTypeCls); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_Write, LoggerInterface,, (Result<void>), TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->Write(ta, str, loc, level); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_GetName, LoggerInterface, const, (String)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LoggerInterface))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_SetName, LoggerInterface,, (void), const String& name) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->SetName(name); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_Enable, LoggerInterface,, (void), Bool enable) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->Enable(enable); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_IsEnabled, LoggerInterface,, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(LoggerInterface))->IsEnabled(); }
		PRIVATE_MAXON_MF_WRAPPER(LoggerInterface_GetLoggerTypes, LoggerInterface, const, (BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LoggerInterface))->GetLoggerTypes(); }
		static maxon::ObservableRef<ObservableLoggerNewDelegate> LoggerInterface_ObservableLoggerNew() { return C::ObservableLoggerNew(); }
		static Result<void> LoggerInterface_AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) { return C::AddNewLogger(id, logger, module); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Free(const LoggerInterface* object) -> void
{
	return MTable::_instance.LoggerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LoggerInterface*
{
	return MTable::_instance.LoggerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_AddLoggerType, ta, loggerTypeCls, cb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::RemoveLoggerType(LoggerTypeRef& loggerType) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_RemoveLoggerType, loggerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_RemoveLoggerTypes, loggerTypeCls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_Write, ta, str, loc, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::GetName() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::SetName(const String& name) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_SetName, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Enable(Bool enable) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_Enable, enable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::IsEnabled() -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_IsEnabled);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::GetLoggerTypes() const -> BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LoggerInterface_GetLoggerTypes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::ObservableLoggerNew() -> maxon::ObservableRef<ObservableLoggerNewDelegate>
{
	return MTable::_instance.LoggerInterface_ObservableLoggerNew();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) -> Result<void>
{
	return MTable::_instance.LoggerInterface_AddNewLogger(id, logger, module);
}

auto LoggerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LoggerRef>
{
	LoggerInterface* res_ = LoggerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LoggerRef(maxon::ForwardResultPtr<LoggerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_AddLoggerType, ta, loggerTypeCls, cb));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::RemoveLoggerType(LoggerTypeRef& loggerType) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_RemoveLoggerType, loggerType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_RemoveLoggerTypes, loggerTypeCls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_Write, ta, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LoggerInterface* o_ = (const LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LoggerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::SetName(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_SetName, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::Enable(Bool enable) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_Enable, enable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::IsEnabled() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_IsEnabled));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstFn<S>::GetLoggerTypes() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LoggerInterface* o_ = (const LoggerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LoggerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LoggerInterface_GetLoggerTypes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstFn<S>::ObservableLoggerNew() -> maxon::ObservableRef<ObservableLoggerNewDelegate>
{
	return (MTable::_instance.LoggerInterface_ObservableLoggerNew());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstFn<S>::AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) -> Result<void>
{
	return (MTable::_instance.LoggerInterface_AddNewLogger(id, logger, module));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_logger)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LoggerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LoggerInterface() { new (s_ui_maxon_LoggerInterface) maxon::EntityUse(LoggerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LoggerInterface(LoggerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

