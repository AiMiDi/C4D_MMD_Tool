#if 1
namespace maxon
{
	const maxon::Char* const LoggerTypeInterface::MTable::_ids = 
		"Write@6de90b33424e492c\0" // Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level)
		"Flush@3008090429c5a175\0" // Result<void> Flush()
		"ObservableLoggerNotify@2d80bc1408e93bb8\0" // maxon::ObservableRef<ObservableLoggerNotifyDelegate> ObservableLoggerNotify(Bool create) const
	"";
	const maxon::METHOD_FLAGS LoggerTypeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(LoggerTypeInterface, LoggerTypeInterface, , , "net.maxon.interface.loggertype", (ObserverObjectInterface::PrivateGetInterface()), (DataDictionaryObjectInterface::PrivateGetInterface()), nullptr);
	const maxon::Char* const FileLoggerTypeInterface::MTable::_ids = 
		"Init@1db4eca46d9225b9\0" // Result<void> Init(const Url& url)
		"GetUrl@f0cc56ca89511da7\0" // Url GetUrl() const
	"";
	const maxon::METHOD_FLAGS FileLoggerTypeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileLoggerTypeInterface, , "net.maxon.interface.fileloggertype", (LoggerTypeInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int FileLoggerTypeInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<Url>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const UserLoggerTypeInterface::MTable::_ids = 
		"Iterate@fbcd7d88a6d04d17\0" // Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback)
		"GetCount@6286b762fbbe6ae7\0" // Int GetCount()
		"Reset@780cdac8f1a33934\0" // void Reset()
	"";
	const maxon::METHOD_FLAGS UserLoggerTypeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UserLoggerTypeInterface, , "net.maxon.interface.userloggertype", (LoggerTypeInterface::PrivateGetInterface()));
	const maxon::Char* const LoggerInterface::MTable::_ids = 
		"Free@150a07a7276bea67\0" // void Free(const LoggerInterface* object)
		"Alloc@24dfb56f7eac4ddc\0" // LoggerInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"AddLoggerType@cf0541d7f47432ea\0" // Result<void> AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb)
		"RemoveLoggerType@c1a974a9dfdf5a54\0" // Result<void> RemoveLoggerType(LoggerTypeRef& loggerType)
		"RemoveLoggerTypes@5862a2dd783fac99\0" // Result<void> RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls)
		"Write@c8a101188b3e8002\0" // Result<void> Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level)
		"GetName@b8f12dfa16054f01\0" // String GetName() const
		"SetName@cc63eccfe460c07a\0" // void SetName(const String& name)
		"Enable@add9409250097f0c\0" // void Enable(Bool enable)
		"IsEnabled@d7a8c99431e20a5a\0" // Bool IsEnabled()
		"GetLoggerTypes@71cf2b33e09cc798\0" // BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> GetLoggerTypes() const
		"ObservableLoggerNew@3f5484565e00596c\0" // maxon::ObservableRef<ObservableLoggerNewDelegate> ObservableLoggerNew(Bool create)
		"AddNewLogger@d0d3604369597860\0" // Result<void> AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class LoggerInterface::Hxx2::Unresolved : public LoggerInterface
	{
	public:
		static const Unresolved* Get(const LoggerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LoggerInterface* o) { return (Unresolved*) o; }
		static void Free(const LoggerInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LoggerInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static LoggerInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LoggerInterface::Alloc(allocLocation); return nullptr;}
		Result<void> AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->AddLoggerType(ta, loggerTypeCls, cb); return HXXRET1(UNRESOLVED);}
		Result<void> RemoveLoggerType(LoggerTypeRef& loggerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->RemoveLoggerType(loggerType); return HXXRET1(UNRESOLVED);}
		Result<void> RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->RemoveLoggerTypes(loggerTypeCls); return HXXRET1(UNRESOLVED);}
		Result<void> Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LoggerInterface*) this)->Write(ta, str, loc, level); return HXXRET1(UNRESOLVED);}
		String GetName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LoggerInterface*) this)->GetName(); return HXXRET3(UNRESOLVED, String);}
		void SetName(const String& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LoggerInterface*) this)->SetName(name); return maxon::PrivateLogNullptrError();}
		void Enable(Bool enable) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LoggerInterface*) this)->Enable(enable); return maxon::PrivateLogNullptrError();}
		Bool IsEnabled() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LoggerInterface*) this)->IsEnabled(); return maxon::PrivateLogNullptrError(false);}
		BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> GetLoggerTypes() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LoggerInterface*) this)->GetLoggerTypes(); return HXXRET3(UNRESOLVED, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>);}
		static maxon::ObservableRef<ObservableLoggerNewDelegate> ObservableLoggerNew(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LoggerInterface::ObservableLoggerNew(create); return maxon::ObservableRef<ObservableLoggerNewDelegate>::DefaultValue();}
		static Result<void> AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return LoggerInterface::AddNewLogger(id, logger, module); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE LoggerInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<LoggerInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableLoggerNewDelegate>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LoggerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LoggerInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LoggerInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_AddLoggerType = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_AddLoggerType), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_AddLoggerType);
		#else
		tbl->LoggerInterface_AddLoggerType = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_AddLoggerType), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_AddLoggerType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_RemoveLoggerType = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_RemoveLoggerType), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_RemoveLoggerType);
		#else
		tbl->LoggerInterface_RemoveLoggerType = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_RemoveLoggerType), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_RemoveLoggerType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_RemoveLoggerTypes = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_RemoveLoggerTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_RemoveLoggerTypes);
		#else
		tbl->LoggerInterface_RemoveLoggerTypes = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_RemoveLoggerTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_RemoveLoggerTypes);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_Write = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_Write), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_Write);
		#else
		tbl->LoggerInterface_Write = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_Write), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_Write);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_GetName = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_GetName), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_GetName);
		#else
		tbl->LoggerInterface_GetName = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_GetName), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_GetName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LoggerInterface_SetName = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_SetName), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_SetName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LoggerInterface_Enable = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_Enable), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_Enable);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LoggerInterface_IsEnabled = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_IsEnabled), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_IsEnabled);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_GetLoggerTypes = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_GetLoggerTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_GetLoggerTypes);
		#else
		tbl->LoggerInterface_GetLoggerTypes = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_GetLoggerTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_GetLoggerTypes);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableLoggerNewDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_ObservableLoggerNew = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_ObservableLoggerNew), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_ObservableLoggerNew);
		#else
		tbl->LoggerInterface_ObservableLoggerNew = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_ObservableLoggerNew), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_ObservableLoggerNew);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LoggerInterface_AddNewLogger = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_AddNewLogger), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_AddNewLogger);
		#else
		tbl->LoggerInterface_AddNewLogger = PRIVATE_MAXON_MF_CAST(decltype(LoggerInterface_AddNewLogger), &Hxx2::Wrapper<Hxx2::Unresolved>::LoggerInterface_AddNewLogger);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LoggerInterface, "net.maxon.interface.logger", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int LoggerInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
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
	| maxon::FileLoggerTypeInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::LoggerInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
