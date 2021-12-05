
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace LOGGERTYPEFLAGS
{
	struct DEBUG_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x905574a29ca764cfLL), maxon::UInt(36))> { };
	struct REUSESTREAM_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x29a7a937af92d070LL), maxon::UInt(42))> { };
	struct ENQUEUEWRITE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x06d1d4c2c2af7cdbLL), maxon::UInt(43))> { };
	struct ALWAYSFLUSH_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x2976d20d764d9bd1LL), maxon::UInt(42))> { };
	struct MAXLINEBUFFER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x265989e0753b4814LL), maxon::UInt(44))> { };
	struct MAXFILEBUFFER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x2658f98bebc0479cLL), maxon::UInt(44))> { };
}

struct LoggerTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Flush);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableLoggerNotify);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_LoggerTypeInterface_Write) (maxon::GenericComponent* this_, const String& str, const SourceLocation& loc, WRITEMETA level);
	maxon::Int _LoggerTypeInterface_Write_Offset;
	Result<void> (*_LoggerTypeInterface_Flush) (maxon::GenericComponent* this_);
	maxon::Int _LoggerTypeInterface_Flush_Offset;
	maxon::ObservableRef<ObservableLoggerNotifyDelegate> (*_LoggerTypeInterface_ObservableLoggerNotify) (const maxon::GenericComponent* this_);
	maxon::Int _LoggerTypeInterface_ObservableLoggerNotify_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Write))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Write), W, MTable>::type::_LoggerTypeInterface_Write;
			_LoggerTypeInterface_Write = reinterpret_cast<const decltype(_LoggerTypeInterface_Write)&>(ptr);
			_LoggerTypeInterface_Write_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Flush))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, Flush), W, MTable>::type::_LoggerTypeInterface_Flush;
			_LoggerTypeInterface_Flush = reinterpret_cast<const decltype(_LoggerTypeInterface_Flush)&>(ptr);
			_LoggerTypeInterface_Flush_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, ObservableLoggerNotify))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LoggerTypeInterface, ObservableLoggerNotify), W, MTable>::type::_LoggerTypeInterface_ObservableLoggerNotify;
			_LoggerTypeInterface_ObservableLoggerNotify = reinterpret_cast<const decltype(_LoggerTypeInterface_ObservableLoggerNotify)&>(ptr);
			_LoggerTypeInterface_ObservableLoggerNotify_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset) || !DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LoggerTypeInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<typename ObserverObjectInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(LoggerTypeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LoggerTypeInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<typename ObserverObjectInterface::Hxx2::template Wrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Flush);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableLoggerNotify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
	static Result<void> _LoggerTypeInterface_Write(maxon::GenericComponent* this_, const String& str, const SourceLocation& loc, WRITEMETA level) { return ((typename S::Implementation*) this_)->Write(str, loc, level); }
	static Result<void> _LoggerTypeInterface_Flush(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Flush(); }
	static maxon::ObservableRef<ObservableLoggerNotifyDelegate> _LoggerTypeInterface_ObservableLoggerNotify(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableLoggerNotify(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Write(const String& str, const SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return mt_._LoggerTypeInterface_Write((maxon::GenericComponent*) this + mt_._LoggerTypeInterface_Write_Offset, str, loc, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Flush() -> Result<void>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return mt_._LoggerTypeInterface_Flush((maxon::GenericComponent*) this + mt_._LoggerTypeInterface_Flush_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::ObservableLoggerNotify() const -> maxon::ObservableRef<ObservableLoggerNotifyDelegate>
{
	const LoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LoggerTypeInterface, this); return mt_._LoggerTypeInterface_ObservableLoggerNotify((const maxon::GenericComponent*) this + mt_._LoggerTypeInterface_ObservableLoggerNotify_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(const String& str, const SourceLocation& loc, WRITEMETA level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_._LoggerTypeInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_Write_Offset, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Write(const String& str, const SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_._LoggerTypeInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_Write_Offset, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_._LoggerTypeInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerTypeInterface* o_ = (LoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_._LoggerTypeInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableLoggerNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LoggerTypeInterface* o_ = (const LoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LoggerTypeInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableLoggerNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LoggerTypeInterface, o_, LoggerTypeInterface_ObservableLoggerNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(LoggerTypeInterface, o_); 
	return (mt_._LoggerTypeInterface_ObservableLoggerNotify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_ObservableLoggerNotify_Offset));
}
auto LoggerTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LoggerTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_FileLoggerTypeInterface_Init) (maxon::GenericComponent* this_, const Url& url);
	maxon::Int _FileLoggerTypeInterface_Init_Offset;
	Url (*_FileLoggerTypeInterface_GetUrl) (const maxon::GenericComponent* this_);
	maxon::Int _FileLoggerTypeInterface_GetUrl_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, Init), W, MTable>::type::_FileLoggerTypeInterface_Init;
			_FileLoggerTypeInterface_Init = reinterpret_cast<const decltype(_FileLoggerTypeInterface_Init)&>(ptr);
			_FileLoggerTypeInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, GetUrl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FileLoggerTypeInterface, GetUrl), W, MTable>::type::_FileLoggerTypeInterface_GetUrl;
			_FileLoggerTypeInterface_GetUrl = reinterpret_cast<const decltype(_FileLoggerTypeInterface_GetUrl)&>(ptr);
			_FileLoggerTypeInterface_GetUrl_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!LoggerTypeInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileLoggerTypeInterface, typename LoggerTypeInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FileLoggerTypeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileLoggerTypeInterface::Hxx2
{
	template <typename S> class Wrapper : public LoggerTypeInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
	static Result<void> _FileLoggerTypeInterface_Init(maxon::GenericComponent* this_, const Url& url) { return ((typename S::Implementation*) this_)->Init(url); }
	static Url _FileLoggerTypeInterface_GetUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Init(const Url& url) -> Result<void>
{
	const FileLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, this); return mt_._FileLoggerTypeInterface_Init((maxon::GenericComponent*) this + mt_._FileLoggerTypeInterface_Init_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::GetUrl() const -> Url
{
	const FileLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, this); return mt_._FileLoggerTypeInterface_GetUrl((const maxon::GenericComponent*) this + mt_._FileLoggerTypeInterface_GetUrl_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileLoggerTypeInterface* o_ = (FileLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (mt_._FileLoggerTypeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileLoggerTypeInterface_Init_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FileLoggerTypeInterface* o_ = (FileLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (mt_._FileLoggerTypeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileLoggerTypeInterface_Init_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FileLoggerTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FileLoggerTypeInterface* o_ = (const FileLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FileLoggerTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FileLoggerTypeInterface, o_, FileLoggerTypeInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FileLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FileLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(FileLoggerTypeInterface, o_); 
	return (mt_._FileLoggerTypeInterface_GetUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FileLoggerTypeInterface_GetUrl_Offset));
}
auto FileLoggerTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileLoggerTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_UserLoggerTypeInterface_Iterate) (maxon::GenericComponent* this_, const Delegate<Result<void>(LoggerLine&)>& callback);
	maxon::Int _UserLoggerTypeInterface_Iterate_Offset;
	Int (*_UserLoggerTypeInterface_GetCount) (maxon::GenericComponent* this_);
	maxon::Int _UserLoggerTypeInterface_GetCount_Offset;
	void (*_UserLoggerTypeInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _UserLoggerTypeInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Iterate))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Iterate), W, MTable>::type::_UserLoggerTypeInterface_Iterate;
			_UserLoggerTypeInterface_Iterate = reinterpret_cast<const decltype(_UserLoggerTypeInterface_Iterate)&>(ptr);
			_UserLoggerTypeInterface_Iterate_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, GetCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, GetCount), W, MTable>::type::_UserLoggerTypeInterface_GetCount;
			_UserLoggerTypeInterface_GetCount = reinterpret_cast<const decltype(_UserLoggerTypeInterface_GetCount)&>(ptr);
			_UserLoggerTypeInterface_GetCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, UserLoggerTypeInterface, Reset), W, MTable>::type::_UserLoggerTypeInterface_Reset;
			_UserLoggerTypeInterface_Reset = reinterpret_cast<const decltype(_UserLoggerTypeInterface_Reset)&>(ptr);
			_UserLoggerTypeInterface_Reset_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!LoggerTypeInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UserLoggerTypeInterface, typename LoggerTypeInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UserLoggerTypeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UserLoggerTypeInterface::Hxx2
{
	template <typename S> class Wrapper : public LoggerTypeInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Iterate);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
	static Result<void> _UserLoggerTypeInterface_Iterate(maxon::GenericComponent* this_, const Delegate<Result<void>(LoggerLine&)>& callback) { return ((typename S::Implementation*) this_)->Iterate(callback); }
	static Int _UserLoggerTypeInterface_GetCount(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetCount(); }
	static void _UserLoggerTypeInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) -> Result<void>
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return mt_._UserLoggerTypeInterface_Iterate((maxon::GenericComponent*) this + mt_._UserLoggerTypeInterface_Iterate_Offset, callback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::GetCount() -> Int
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return mt_._UserLoggerTypeInterface_GetCount((maxon::GenericComponent*) this + mt_._UserLoggerTypeInterface_GetCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Reset() -> void
{
	const UserLoggerTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, this); return mt_._UserLoggerTypeInterface_Reset((maxon::GenericComponent*) this + mt_._UserLoggerTypeInterface_Reset_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::ReferenceFunctionsImpl<S>::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Iterate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_._UserLoggerTypeInterface_Iterate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_Iterate_Offset, callback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Iterate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_._UserLoggerTypeInterface_Iterate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_Iterate_Offset, callback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::ReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return 0; const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_._UserLoggerTypeInterface_GetCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_GetCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	return (mt_._UserLoggerTypeInterface_GetCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_GetCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	mt_._UserLoggerTypeInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UserLoggerTypeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UserLoggerTypeInterface* o_ = (UserLoggerTypeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(UserLoggerTypeInterface, o_, UserLoggerTypeInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<UserLoggerTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<UserLoggerTypeInterface>() : PRIVATE_MAXON_VTABLE(UserLoggerTypeInterface, o_); 
	mt_._UserLoggerTypeInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto UserLoggerTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UserLoggerTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UserLoggerTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UserLoggerTypeInterface() { new (s_ui_maxon_UserLoggerTypeInterface) maxon::EntityUse(UserLoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UserLoggerTypeInterface(UserLoggerTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/logger.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct LoggerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_LoggerInterface_Free) (const LoggerInterface* object);
	LoggerInterface* (*_LoggerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_LoggerInterface_AddLoggerType) (LoggerInterface* this_, TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb);
	Result<void> (*_LoggerInterface_RemoveLoggerType) (LoggerInterface* this_, LoggerTypeRef& loggerType);
	Result<void> (*_LoggerInterface_RemoveLoggerTypes) (LoggerInterface* this_, const Class<LoggerTypeRef>& loggerTypeCls);
	Result<void> (*_LoggerInterface_Write) (LoggerInterface* this_, TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level);
	String (*_LoggerInterface_GetName) (const LoggerInterface* this_);
	void (*_LoggerInterface_SetName) (LoggerInterface* this_, const String& name);
	void (*_LoggerInterface_Enable) (LoggerInterface* this_, Bool enable);
	Bool (*_LoggerInterface_IsEnabled) (LoggerInterface* this_);
	BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> (*_LoggerInterface_GetLoggerTypes) (const LoggerInterface* this_);
	maxon::ObservableRef<ObservableLoggerNewDelegate> (*_LoggerInterface_ObservableLoggerNew) ();
	Result<void> (*_LoggerInterface_AddNewLogger) (const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module);
	template <typename IMPL> void Init()
	{
		_LoggerInterface_Free = &IMPL::_LoggerInterface_Free;
		_LoggerInterface_Alloc = &IMPL::_LoggerInterface_Alloc;
		_LoggerInterface_AddLoggerType = &IMPL::_LoggerInterface_AddLoggerType;
		_LoggerInterface_RemoveLoggerType = &IMPL::_LoggerInterface_RemoveLoggerType;
		_LoggerInterface_RemoveLoggerTypes = &IMPL::_LoggerInterface_RemoveLoggerTypes;
		_LoggerInterface_Write = &IMPL::_LoggerInterface_Write;
		_LoggerInterface_GetName = &IMPL::_LoggerInterface_GetName;
		_LoggerInterface_SetName = &IMPL::_LoggerInterface_SetName;
		_LoggerInterface_Enable = &IMPL::_LoggerInterface_Enable;
		_LoggerInterface_IsEnabled = &IMPL::_LoggerInterface_IsEnabled;
		_LoggerInterface_GetLoggerTypes = &IMPL::_LoggerInterface_GetLoggerTypes;
		_LoggerInterface_ObservableLoggerNew = &IMPL::_LoggerInterface_ObservableLoggerNew;
		_LoggerInterface_AddNewLogger = &IMPL::_LoggerInterface_AddNewLogger;
	}
};

struct LoggerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _LoggerInterface_Free(const LoggerInterface* object) { return C::Free(object); }
	static LoggerInterface* _LoggerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _LoggerInterface_AddLoggerType(LoggerInterface* this_, TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) { return ((C*) this_)->AddLoggerType(ta, loggerTypeCls, cb); }
	static Result<void> _LoggerInterface_RemoveLoggerType(LoggerInterface* this_, LoggerTypeRef& loggerType) { return ((C*) this_)->RemoveLoggerType(loggerType); }
	static Result<void> _LoggerInterface_RemoveLoggerTypes(LoggerInterface* this_, const Class<LoggerTypeRef>& loggerTypeCls) { return ((C*) this_)->RemoveLoggerTypes(loggerTypeCls); }
	static Result<void> _LoggerInterface_Write(LoggerInterface* this_, TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) { return ((C*) this_)->Write(ta, str, loc, level); }
	static String _LoggerInterface_GetName(const LoggerInterface* this_) { return ((const C*) this_)->GetName(); }
	static void _LoggerInterface_SetName(LoggerInterface* this_, const String& name) { return ((C*) this_)->SetName(name); }
	static void _LoggerInterface_Enable(LoggerInterface* this_, Bool enable) { return ((C*) this_)->Enable(enable); }
	static Bool _LoggerInterface_IsEnabled(LoggerInterface* this_) { return ((C*) this_)->IsEnabled(); }
	static BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> _LoggerInterface_GetLoggerTypes(const LoggerInterface* this_) { return ((const C*) this_)->GetLoggerTypes(); }
	static maxon::ObservableRef<ObservableLoggerNewDelegate> _LoggerInterface_ObservableLoggerNew() { return C::ObservableLoggerNew(); }
	static Result<void> _LoggerInterface_AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) { return C::AddNewLogger(id, logger, module); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Free(const LoggerInterface* object) -> void
{
	return MTable::_instance._LoggerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LoggerInterface*
{
	return MTable::_instance._LoggerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) -> Result<void>
{
	return MTable::_instance._LoggerInterface_AddLoggerType(this, ta, loggerTypeCls, cb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::RemoveLoggerType(LoggerTypeRef& loggerType) -> Result<void>
{
	return MTable::_instance._LoggerInterface_RemoveLoggerType(this, loggerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) -> Result<void>
{
	return MTable::_instance._LoggerInterface_RemoveLoggerTypes(this, loggerTypeCls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) -> Result<void>
{
	return MTable::_instance._LoggerInterface_Write(this, ta, str, loc, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::GetName() const -> String
{
	return MTable::_instance._LoggerInterface_GetName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::SetName(const String& name) -> void
{
	return MTable::_instance._LoggerInterface_SetName(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Enable(Bool enable) -> void
{
	return MTable::_instance._LoggerInterface_Enable(this, enable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::IsEnabled() -> Bool
{
	return MTable::_instance._LoggerInterface_IsEnabled(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::GetLoggerTypes() const -> BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>
{
	return MTable::_instance._LoggerInterface_GetLoggerTypes(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::ObservableLoggerNew() -> maxon::ObservableRef<ObservableLoggerNewDelegate>
{
	return MTable::_instance._LoggerInterface_ObservableLoggerNew();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) -> Result<void>
{
	return MTable::_instance._LoggerInterface_AddNewLogger(id, logger, module);
}

auto LoggerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LoggerRef>
{
	LoggerInterface* res_ = LoggerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LoggerRef(maxon::ForwardResultPtr<LoggerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LoggerInterface_AddLoggerType(o_, ta, loggerTypeCls, cb));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveLoggerType(LoggerTypeRef& loggerType) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LoggerInterface_RemoveLoggerType(o_, loggerType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LoggerInterface_RemoveLoggerTypes(o_, loggerTypeCls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LoggerInterface_Write(o_, ta, str, loc, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LoggerInterface* o_ = (const LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LoggerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LoggerInterface_GetName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::SetName(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._LoggerInterface_SetName(o_, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::Enable(Bool enable) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._LoggerInterface_Enable(o_, enable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ReferenceFunctionsImpl<S>::IsEnabled() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LoggerInterface* o_ = (LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); 
	return (MTable::_instance._LoggerInterface_IsEnabled(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLoggerTypes() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LoggerInterface* o_ = (const LoggerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LoggerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LoggerInterface_GetLoggerTypes(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableLoggerNew() -> maxon::ObservableRef<ObservableLoggerNewDelegate> { return (MTable::_instance._LoggerInterface_ObservableLoggerNew()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LoggerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) -> Result<void> { return (MTable::_instance._LoggerInterface_AddNewLogger(id, logger, module)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

