
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
	Result<void> (*LoggerTypeInterface_Write) (maxon::GenericComponent* this_, const String& str, const SourceLocation& loc, WRITEMETA level);
	maxon::Int LoggerTypeInterface_Write_Offset;
	Result<void> (*LoggerTypeInterface_Flush) (maxon::GenericComponent* this_);
	maxon::Int LoggerTypeInterface_Flush_Offset;
	maxon::ObservableRef<ObservableLoggerNotifyDelegate> (*LoggerTypeInterface_ObservableLoggerNotify) (const maxon::GenericComponent* this_);
	maxon::Int LoggerTypeInterface_ObservableLoggerNotify_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Write))
	{
		LoggerTypeInterface_Write = &W::LoggerTypeInterface_Write;
		LoggerTypeInterface_Write_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Flush))
	{
		LoggerTypeInterface_Flush = &W::LoggerTypeInterface_Flush;
		LoggerTypeInterface_Flush_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, ObservableLoggerNotify))
	{
		LoggerTypeInterface_ObservableLoggerNotify = &W::LoggerTypeInterface_ObservableLoggerNotify;
		LoggerTypeInterface_ObservableLoggerNotify_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (LoggerTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, LoggerTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> LoggerTypeInterface_Write(maxon::GenericComponent* this_, const String& str, const SourceLocation& loc, WRITEMETA level) { return ((typename S::Implementation*) this_)->Write(str, loc, level); }
		static Result<void> LoggerTypeInterface_Flush(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Flush(); }
		static maxon::ObservableRef<ObservableLoggerNotifyDelegate> LoggerTypeInterface_ObservableLoggerNotify(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableLoggerNotify(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Write(const String& str, const SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return mt_.LoggerTypeInterface_Write((maxon::GenericComponent*) this + mt_.LoggerTypeInterface_Write_Offset, str, loc, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Flush() -> Result<void>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return mt_.LoggerTypeInterface_Flush((maxon::GenericComponent*) this + mt_.LoggerTypeInterface_Flush_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::ObservableLoggerNotify() const -> maxon::ObservableRef<ObservableLoggerNotifyDelegate>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return mt_.LoggerTypeInterface_ObservableLoggerNotify((const maxon::GenericComponent*) this + mt_.LoggerTypeInterface_ObservableLoggerNotify_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::Fn<S>::Write(const String& str, const SourceLocation& loc, WRITEMETA level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_.LoggerTypeInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Write_Offset, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::COWFn<S>::Write(const String& str, const SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_.LoggerTypeInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Write_Offset, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::Fn<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_.LoggerTypeInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::COWFn<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_.LoggerTypeInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::ConstFn<S>::ObservableLoggerNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LoggerTypeInterface* o_ = (const LoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LoggerTypeInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableLoggerNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_ObservableLoggerNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_.LoggerTypeInterface_ObservableLoggerNotify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_ObservableLoggerNotify_Offset));
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
	Result<void> (*FileLoggerTypeInterface_Init) (maxon::GenericComponent* this_, const Url& url);
	maxon::Int FileLoggerTypeInterface_Init_Offset;
	Url (*FileLoggerTypeInterface_GetUrl) (const maxon::GenericComponent* this_);
	maxon::Int FileLoggerTypeInterface_GetUrl_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, Init))
	{
		FileLoggerTypeInterface_Init = &W::FileLoggerTypeInterface_Init;
		FileLoggerTypeInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, GetUrl))
	{
		FileLoggerTypeInterface_GetUrl = &W::FileLoggerTypeInterface_GetUrl;
		FileLoggerTypeInterface_GetUrl_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (FileLoggerTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileLoggerTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> FileLoggerTypeInterface_Init(maxon::GenericComponent* this_, const Url& url) { return ((typename S::Implementation*) this_)->Init(url); }
		static Url FileLoggerTypeInterface_GetUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Init(const Url& url) -> Result<void>
{
	const FileLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, this); return mt_.FileLoggerTypeInterface_Init((maxon::GenericComponent*) this + mt_.FileLoggerTypeInterface_Init_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::GetUrl() const -> Url
{
	const FileLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, this); return mt_.FileLoggerTypeInterface_GetUrl((const maxon::GenericComponent*) this + mt_.FileLoggerTypeInterface_GetUrl_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::Fn<S>::Init(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileLoggerTypeInterface* o_ = (FileLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (mt_.FileLoggerTypeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_Init_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::COWFn<S>::Init(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileLoggerTypeInterface* o_ = (FileLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (mt_.FileLoggerTypeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_Init_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileLoggerTypeInterface* o_ = (const FileLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileLoggerTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (mt_.FileLoggerTypeInterface_GetUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_GetUrl_Offset));
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
	Result<void> (*UserLoggerTypeInterface_Iterate) (maxon::GenericComponent* this_, const Delegate<Result<void>(LoggerLine&)>& callback);
	maxon::Int UserLoggerTypeInterface_Iterate_Offset;
	Int (*UserLoggerTypeInterface_GetCount) (maxon::GenericComponent* this_);
	maxon::Int UserLoggerTypeInterface_GetCount_Offset;
	void (*UserLoggerTypeInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int UserLoggerTypeInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Iterate))
	{
		UserLoggerTypeInterface_Iterate = &W::UserLoggerTypeInterface_Iterate;
		UserLoggerTypeInterface_Iterate_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, GetCount))
	{
		UserLoggerTypeInterface_GetCount = &W::UserLoggerTypeInterface_GetCount;
		UserLoggerTypeInterface_GetCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Reset))
	{
		UserLoggerTypeInterface_Reset = &W::UserLoggerTypeInterface_Reset;
		UserLoggerTypeInterface_Reset_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (UserLoggerTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UserLoggerTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> UserLoggerTypeInterface_Iterate(maxon::GenericComponent* this_, const Delegate<Result<void>(LoggerLine&)>& callback) { return ((typename S::Implementation*) this_)->Iterate(callback); }
		static Int UserLoggerTypeInterface_GetCount(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetCount(); }
		static void UserLoggerTypeInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) -> Result<void>
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return mt_.UserLoggerTypeInterface_Iterate((maxon::GenericComponent*) this + mt_.UserLoggerTypeInterface_Iterate_Offset, callback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::GetCount() -> Int
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return mt_.UserLoggerTypeInterface_GetCount((maxon::GenericComponent*) this + mt_.UserLoggerTypeInterface_GetCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Reset() -> void
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return mt_.UserLoggerTypeInterface_Reset((maxon::GenericComponent*) this + mt_.UserLoggerTypeInterface_Reset_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::Fn<S>::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Iterate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_.UserLoggerTypeInterface_Iterate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Iterate_Offset, callback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWFn<S>::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Iterate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_.UserLoggerTypeInterface_Iterate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Iterate_Offset, callback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::Fn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_.UserLoggerTypeInterface_GetCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_GetCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWFn<S>::GetCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_.UserLoggerTypeInterface_GetCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_GetCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	mt_.UserLoggerTypeInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	mt_.UserLoggerTypeInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Reset_Offset);
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
	void (*LoggerInterface_Free) (const LoggerInterface* object);
	LoggerInterface* (*LoggerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*LoggerInterface_AddLoggerType) (LoggerInterface* this_, TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb);
	Result<void> (*LoggerInterface_RemoveLoggerType) (LoggerInterface* this_, LoggerTypeRef& loggerType);
	Result<void> (*LoggerInterface_RemoveLoggerTypes) (LoggerInterface* this_, const Class<LoggerTypeRef>& loggerTypeCls);
	Result<void> (*LoggerInterface_Write) (LoggerInterface* this_, TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level);
	String (*LoggerInterface_GetName) (const LoggerInterface* this_);
	void (*LoggerInterface_SetName) (LoggerInterface* this_, const String& name);
	void (*LoggerInterface_Enable) (LoggerInterface* this_, Bool enable);
	Bool (*LoggerInterface_IsEnabled) (LoggerInterface* this_);
	BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> (*LoggerInterface_GetLoggerTypes) (const LoggerInterface* this_);
	maxon::ObservableRef<ObservableLoggerNewDelegate> (*LoggerInterface_ObservableLoggerNew) ();
	Result<void> (*LoggerInterface_AddNewLogger) (const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module);
	template <typename IMPL> void Init()
	{
		LoggerInterface_Free = &IMPL::LoggerInterface_Free;
		LoggerInterface_Alloc = &IMPL::LoggerInterface_Alloc;
		LoggerInterface_AddLoggerType = &IMPL::LoggerInterface_AddLoggerType;
		LoggerInterface_RemoveLoggerType = &IMPL::LoggerInterface_RemoveLoggerType;
		LoggerInterface_RemoveLoggerTypes = &IMPL::LoggerInterface_RemoveLoggerTypes;
		LoggerInterface_Write = &IMPL::LoggerInterface_Write;
		LoggerInterface_GetName = &IMPL::LoggerInterface_GetName;
		LoggerInterface_SetName = &IMPL::LoggerInterface_SetName;
		LoggerInterface_Enable = &IMPL::LoggerInterface_Enable;
		LoggerInterface_IsEnabled = &IMPL::LoggerInterface_IsEnabled;
		LoggerInterface_GetLoggerTypes = &IMPL::LoggerInterface_GetLoggerTypes;
		LoggerInterface_ObservableLoggerNew = &IMPL::LoggerInterface_ObservableLoggerNew;
		LoggerInterface_AddNewLogger = &IMPL::LoggerInterface_AddNewLogger;
	}
};

struct LoggerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void LoggerInterface_Free(const LoggerInterface* object) { return C::Free(object); }
		static LoggerInterface* LoggerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<void> LoggerInterface_AddLoggerType(LoggerInterface* this_, TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) { return C::Get(this_)->AddLoggerType(ta, loggerTypeCls, cb); }
		static Result<void> LoggerInterface_RemoveLoggerType(LoggerInterface* this_, LoggerTypeRef& loggerType) { return C::Get(this_)->RemoveLoggerType(loggerType); }
		static Result<void> LoggerInterface_RemoveLoggerTypes(LoggerInterface* this_, const Class<LoggerTypeRef>& loggerTypeCls) { return C::Get(this_)->RemoveLoggerTypes(loggerTypeCls); }
		static Result<void> LoggerInterface_Write(LoggerInterface* this_, TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) { return C::Get(this_)->Write(ta, str, loc, level); }
		static String LoggerInterface_GetName(const LoggerInterface* this_) { return C::Get(this_)->GetName(); }
		static void LoggerInterface_SetName(LoggerInterface* this_, const String& name) { return C::Get(this_)->SetName(name); }
		static void LoggerInterface_Enable(LoggerInterface* this_, Bool enable) { return C::Get(this_)->Enable(enable); }
		static Bool LoggerInterface_IsEnabled(LoggerInterface* this_) { return C::Get(this_)->IsEnabled(); }
		static BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> LoggerInterface_GetLoggerTypes(const LoggerInterface* this_) { return C::Get(this_)->GetLoggerTypes(); }
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
	return MTable::_instance.LoggerInterface_AddLoggerType(this, ta, loggerTypeCls, cb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::RemoveLoggerType(LoggerTypeRef& loggerType) -> Result<void>
{
	return MTable::_instance.LoggerInterface_RemoveLoggerType(this, loggerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) -> Result<void>
{
	return MTable::_instance.LoggerInterface_RemoveLoggerTypes(this, loggerTypeCls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	return MTable::_instance.LoggerInterface_Write(this, ta, str, loc, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::GetName() const -> String
{
	return MTable::_instance.LoggerInterface_GetName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::SetName(const String& name) -> void
{
	return MTable::_instance.LoggerInterface_SetName(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Enable(Bool enable) -> void
{
	return MTable::_instance.LoggerInterface_Enable(this, enable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::IsEnabled() -> Bool
{
	return MTable::_instance.LoggerInterface_IsEnabled(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::GetLoggerTypes() const -> BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>
{
	return MTable::_instance.LoggerInterface_GetLoggerTypes(this);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LoggerInterface_AddLoggerType(o_, ta, loggerTypeCls, cb));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::RemoveLoggerType(LoggerTypeRef& loggerType) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LoggerInterface_RemoveLoggerType(o_, loggerType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LoggerInterface_RemoveLoggerTypes(o_, loggerTypeCls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LoggerInterface_Write(o_, ta, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LoggerInterface* o_ = (const LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LoggerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LoggerInterface_GetName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::SetName(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.LoggerInterface_SetName(o_, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::Enable(Bool enable) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.LoggerInterface_Enable(o_, enable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::Fn<S>::IsEnabled() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.LoggerInterface_IsEnabled(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstFn<S>::GetLoggerTypes() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LoggerInterface* o_ = (const LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LoggerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LoggerInterface_GetLoggerTypes(o_));
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

