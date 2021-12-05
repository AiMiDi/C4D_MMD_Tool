#if 1
namespace maxon
{
	namespace LOGGERTYPEFLAGS
	{
		DEBUG_PrivateAttribute DEBUG;
		REUSESTREAM_PrivateAttribute REUSESTREAM;
		ENQUEUEWRITE_PrivateAttribute ENQUEUEWRITE;
		ALWAYSFLUSH_PrivateAttribute ALWAYSFLUSH;
		MAXLINEBUFFER_PrivateAttribute MAXLINEBUFFER;
		MAXFILEBUFFER_PrivateAttribute MAXFILEBUFFER;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL(LoggerTypeInterface, "net.maxon.interface.loggertype", "maxon.LoggerTypeInterface", , &ObserverObjectInterface::_interface, &DataDictionaryObjectInterface::_interface, nullptr);
	const maxon::Char* const LoggerTypeInterface::MTable::_ids = 
		"Write@dcf6278dbe7695c5\0" // Write(const String& str, const SourceLocation& loc, WRITEMETA level)
		"Flush@a54f4799cbe1a498\0" // Flush()
		"ObservableLoggerNotify@299eac2e68029e45\0" // ObservableLoggerNotify() const
	"";
	template <typename DUMMY> maxon::Int LoggerTypeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileLoggerTypeInterface, "net.maxon.interface.fileloggertype", "maxon.FileLoggerTypeInterface", , &LoggerTypeInterface::_interface);
	const maxon::Char* const FileLoggerTypeInterface::MTable::_ids = 
		"Init@e1e93c17010d01ec\0" // Init(const Url& url)
		"GetUrl@4e33a06\0" // GetUrl() const
	"";
	template <typename DUMMY> maxon::Int FileLoggerTypeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UserLoggerTypeInterface, "net.maxon.interface.userloggertype", "maxon.UserLoggerTypeInterface", , &LoggerTypeInterface::_interface);
	const maxon::Char* const UserLoggerTypeInterface::MTable::_ids = 
		"Iterate@57c2f805f6e434ea\0" // Iterate(const Delegate<Result<void>(LoggerLine&)>& callback)
		"GetCount@22da34\0" // GetCount()
		"Reset@6b2e10f\0" // Reset()
	"";
	template <typename DUMMY> maxon::Int UserLoggerTypeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	const maxon::Char* const LoggerInterface::MTable::_ids = 
		"Free@f3ca273a1c75c6f6\0" // Free(const LoggerInterface* object)
		"Alloc@668161349c9321b1\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"AddLoggerType@7916a30626de8bef\0" // AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb)
		"RemoveLoggerType@9fc2c011949b80b5\0" // RemoveLoggerType(LoggerTypeRef& loggerType)
		"RemoveLoggerTypes@271bede43e89d598\0" // RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls)
		"Write@a41c9c0e90c0bbdb\0" // Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level)
		"GetName@22c6ed80868\0" // GetName() const
		"SetName@0a91ca997ced89a9\0" // SetName(const String& name)
		"Enable@5e65c14d7099\0" // Enable(Bool enable)
		"IsEnabled@3d63259\0" // IsEnabled()
		"GetLoggerTypes@6917f95f3938e17b\0" // GetLoggerTypes() const
		"ObservableLoggerNew@b8b54708db7808bb\0" // ObservableLoggerNew()
		"AddNewLogger@fed7cff1cc425b03\0" // AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module)
	"";
	class LoggerInterface::Unresolved : public LoggerInterface
	{
	public:
		static const Unresolved* Get(const LoggerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LoggerInterface* o) { return (Unresolved*) o; }
		static void Free(const LoggerInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LoggerInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static LoggerInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LoggerInterface::Alloc(allocLocation); return nullptr;}
		Result<void> AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->AddLoggerType(ta, loggerTypeCls, cb); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> RemoveLoggerType(LoggerTypeRef& loggerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->RemoveLoggerType(loggerType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->RemoveLoggerTypes(loggerTypeCls); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->Write(ta, str, loc, level); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String GetName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LoggerInterface*) this)->GetName(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void SetName(const String& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LoggerInterface*) this)->SetName(name); return maxon::PrivateLogNullptrError();}
		void Enable(Bool enable) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LoggerInterface*) this)->Enable(enable); return maxon::PrivateLogNullptrError();}
		Bool IsEnabled() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LoggerInterface*) this)->IsEnabled(); return maxon::PrivateLogNullptrError(false);}
		BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> GetLoggerTypes() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LoggerInterface*) this)->GetLoggerTypes(); return maxon::PrivateIncompleteNullReturnValue<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static maxon::ObservableRef<ObservableLoggerNewDelegate> ObservableLoggerNew() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LoggerInterface::ObservableLoggerNew(); return maxon::ObservableRef<ObservableLoggerNewDelegate>::NullValue();}
		static Result<void> AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return LoggerInterface::AddNewLogger(id, logger, module); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LoggerInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<LoggerInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableLoggerNewDelegate>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LoggerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LoggerInterface_Free = &Wrapper<Unresolved>::_LoggerInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LoggerInterface_Alloc = &Wrapper<Unresolved>::_LoggerInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_AddLoggerType = &Wrapper<Unresolved>::_LoggerInterface_AddLoggerType;
	#else
		tbl->_LoggerInterface_AddLoggerType = &Wrapper<Unresolved>::_LoggerInterface_AddLoggerType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_RemoveLoggerType = &Wrapper<Unresolved>::_LoggerInterface_RemoveLoggerType;
	#else
		tbl->_LoggerInterface_RemoveLoggerType = &Wrapper<Unresolved>::_LoggerInterface_RemoveLoggerType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_RemoveLoggerTypes = &Wrapper<Unresolved>::_LoggerInterface_RemoveLoggerTypes;
	#else
		tbl->_LoggerInterface_RemoveLoggerTypes = &Wrapper<Unresolved>::_LoggerInterface_RemoveLoggerTypes;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_Write = &Wrapper<Unresolved>::_LoggerInterface_Write;
	#else
		tbl->_LoggerInterface_Write = &Wrapper<Unresolved>::_LoggerInterface_Write;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_GetName = &Wrapper<Unresolved>::_LoggerInterface_GetName;
	#else
		tbl->_LoggerInterface_GetName = &Wrapper<Unresolved>::_LoggerInterface_GetName;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LoggerInterface_SetName = &Wrapper<Unresolved>::_LoggerInterface_SetName;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LoggerInterface_Enable = &Wrapper<Unresolved>::_LoggerInterface_Enable;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LoggerInterface_IsEnabled = &Wrapper<Unresolved>::_LoggerInterface_IsEnabled;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_GetLoggerTypes = &Wrapper<Unresolved>::_LoggerInterface_GetLoggerTypes;
	#else
		tbl->_LoggerInterface_GetLoggerTypes = &Wrapper<Unresolved>::_LoggerInterface_GetLoggerTypes;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableLoggerNewDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_ObservableLoggerNew = &Wrapper<Unresolved>::_LoggerInterface_ObservableLoggerNew;
	#else
		tbl->_LoggerInterface_ObservableLoggerNew = &Wrapper<Unresolved>::_LoggerInterface_ObservableLoggerNew;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LoggerInterface_AddNewLogger = &Wrapper<Unresolved>::_LoggerInterface_AddNewLogger;
	#else
		tbl->_LoggerInterface_AddNewLogger = &Wrapper<Unresolved>::_LoggerInterface_AddNewLogger;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LoggerInterface, "net.maxon.interface.logger", nullptr);
	template <typename DUMMY> maxon::Int LoggerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LoggerTypeBaseClass, , "net.maxon.class.loggertypebase");
	MAXON_REGISTRY_REGISTER(LoggerTypes);
	namespace LoggerTypes
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MultiFile, , "net.maxon.core.loggertype.multifile");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(File, , "net.maxon.core.loggertype.file");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Application, , "net.maxon.core.loggertype.applicationconsole");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Process, , "net.maxon.core.loggertype.process");
	}
	MAXON_REGISTRY_REGISTER(Loggers);
	namespace Loggers
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Default, , "net.maxon.core.logger.default");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Process, , "net.maxon.core.logger.process");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_logger(0
	| maxon::LoggerTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::FileLoggerTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UserLoggerTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::LoggerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
