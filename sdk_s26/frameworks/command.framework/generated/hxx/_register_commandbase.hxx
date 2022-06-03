#if 1
namespace maxon
{
	namespace enum29
	{
		enum class COMMANDSTATE
		{
			DISABLED = 0,	///< The command can't be executed.
			ENABLED	 = 1  ///< The command can be executed.
		} ;
		static const maxon::UInt64 COMMANDSTATE_values[] = {maxon::UInt64(enum29::COMMANDSTATE::DISABLED), maxon::UInt64(enum29::COMMANDSTATE::ENABLED)};
		static const maxon::EnumInfo COMMANDSTATE_info{"COMMANDSTATE", SIZEOF(COMMANDSTATE), false, "DISABLED\0ENABLED\0", COMMANDSTATE_values, std::extent<decltype(COMMANDSTATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COMMANDSTATE29(){ return enum29::COMMANDSTATE_info; }
	namespace enum39
	{
		enum class COMMANDRESULT
		{
			OK		= 0,	///< The command was executed properly.
			SKIP 	= 1,	///< The command did not execute because no action was necessary (e.g. no selection).
			BREAK = 2		///< The command execution was interrupted.
		} ;
		static const maxon::UInt64 COMMANDRESULT_values[] = {maxon::UInt64(enum39::COMMANDRESULT::OK), maxon::UInt64(enum39::COMMANDRESULT::SKIP), maxon::UInt64(enum39::COMMANDRESULT::BREAK)};
		static const maxon::EnumInfo COMMANDRESULT_info{"COMMANDRESULT", SIZEOF(COMMANDRESULT), false, "OK\0SKIP\0BREAK\0", COMMANDRESULT_values, std::extent<decltype(COMMANDRESULT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COMMANDRESULT39(){ return enum39::COMMANDRESULT_info; }
	namespace enum51
	{
		enum class INTERACTIONTYPE
		{
			NONE 			= 0,	///< No interaction.
			START 		= 1,	///< Interaction start (e.g. first mouse click).
			ITERATE 	= 2,	///< Interaction iteration, performed several times after START (e.g. mouse drag).
			END 			= 3,	///< Interaction end (e.g. mouse released).
			REALTIME 	= 4		///< Real-time iterative interaction (e.g. cursor over viewport).
		} ;
		static const maxon::UInt64 INTERACTIONTYPE_values[] = {maxon::UInt64(enum51::INTERACTIONTYPE::NONE), maxon::UInt64(enum51::INTERACTIONTYPE::START), maxon::UInt64(enum51::INTERACTIONTYPE::ITERATE), maxon::UInt64(enum51::INTERACTIONTYPE::END), maxon::UInt64(enum51::INTERACTIONTYPE::REALTIME)};
		static const maxon::EnumInfo INTERACTIONTYPE_info{"INTERACTIONTYPE", SIZEOF(INTERACTIONTYPE), false, "NONE\0START\0ITERATE\0END\0REALTIME\0", INTERACTIONTYPE_values, std::extent<decltype(INTERACTIONTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INTERACTIONTYPE51(){ return enum51::INTERACTIONTYPE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_INTERACTIONTYPE, , "net.maxon.command.interationtype");
	const maxon::Char* const CommandDataInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS CommandDataInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandDataInterface, , "net.maxon.command.interface.commanddata", "maxon.CommandDataInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	const maxon::Char* const LegacyCommandDataInterface::MTable::_ids = 
		"GetLegacyData@961eec08ac81de3f\0" // Result<Generic*> GetLegacyData(Int index)
		"SetLegacyData@6b9dc50b944c09e8\0" // Result<void> SetLegacyData(const Generic* data, Int index)
		"GetLegacyDataCount@7d0e6f3d29c239e7\0" // Int GetLegacyDataCount() const
	"";
	const maxon::METHOD_FLAGS LegacyCommandDataInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(LegacyCommandDataInterface, , "net.maxon.command.interface.legacycommanddata", "maxon.LegacyCommandDataInterface", (CommandDataInterface::PrivateGetInterface()));
	const maxon::Char* const CommandClassInterface::MTable::_ids = 
		"GetState@136e3023f5c46817\0" // Result<COMMANDSTATE> GetState(CommandDataRef& data) const
		"Execute@547746b228fa35d1\0" // Result<COMMANDRESULT> Execute(CommandDataRef& data) const
	"";
	const maxon::METHOD_FLAGS CommandClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandClassInterface, , "net.maxon.command.interface.command", "maxon.CommandClassInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const CommandInteractionClassInterface::MTable::_ids = 
		"Interact@faadf7ba3965f275\0" // Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const
	"";
	const maxon::METHOD_FLAGS CommandInteractionClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandInteractionClassInterface, , "net.maxon.command.interface.commandinteraction", "maxon.CommandInteractionClassInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const CommandDescriptionClassInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS CommandDescriptionClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(CommandDescriptionClassInterface, CommandDescriptionClassInterface, , , "net.maxon.command.interface.commanddescriptioninterface", "maxon.CommandDescriptionClassInterface", (DataDictionaryReferenceObjectInterface::PrivateGetInterface()), (DataDescriptionObjectInterface::PrivateGetInterface()), nullptr);
	const maxon::Char* const LegacyCommandClassInterface::MTable::_ids = 
		"ConvertSettings@3460a1b1d60627b0\0" // Result<void> ConvertSettings(LegacyCommandDataRef& data) const
	"";
	const maxon::METHOD_FLAGS LegacyCommandClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(LegacyCommandClassInterface, , "net.maxon.command.interface.legacycommand", "maxon.LegacyCommandClassInterface", (CommandClassInterface::PrivateGetInterface()));
	const maxon::Char* const MigratedCommandClassInterface::MTable::_ids = 
		"GetMigratedCommandId@30a3c592bf87830a\0" // Int32 GetMigratedCommandId() const
	"";
	const maxon::METHOD_FLAGS MigratedCommandClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MigratedCommandClassInterface, , "net.maxon.command.interface.migratedcommand", "maxon.MigratedCommandClassInterface", (LegacyCommandClassInterface::PrivateGetInterface()));
	const maxon::Char* const CommandConversionClassInterface::MTable::_ids = 
		"ConvertInput@3460a1b1d60627b0\0" // Result<void> ConvertInput(LegacyCommandDataRef& data) const
		"ExecuteCustomActions@87bb87ebf69c3cac\0" // Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const
		"ConvertOutput@3460a1b1d60627b0\0" // Result<void> ConvertOutput(LegacyCommandDataRef& data) const
		"GetLegacyCommandId@30a3c592bf87830a\0" // Int32 GetLegacyCommandId() const
		"GetCommandId@33636d531bf4ad19\0" // Id GetCommandId() const
	"";
	const maxon::METHOD_FLAGS CommandConversionClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandConversionClassInterface, , "net.maxon.command.interface.commandconversion", "maxon.CommandConversionClassInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int CommandConversionClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_CommandCacheData,, "net.maxon.datatype.commandcachedata");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_CommandCacheMap,, "net.maxon.datatype.commandcachemap");
	const maxon::Char* const CommandCacheInterface::MTable::_ids = 
		"Init@caf50262980f7087\0" // Result<void> Init(CommandDataRef& data)
		"Reset@780cdac8f1a33934\0" // void Reset()
	"";
	const maxon::METHOD_FLAGS CommandCacheInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandCacheInterface, , "net.maxon.command.interface.cache", "maxon.CommandCacheInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const CommandExecutionInterface::MTable::_ids = 
		"Invoke@1955c4c6155f193c\0" // Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive)
		"Invoke@3d58e8b493505f5f\0" // Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters)
		"Interact@faadf7ba3065e44a\0" // Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class CommandExecutionInterface::Hxx2::Unresolved : public CommandExecutionInterface
	{
	public:
		static const Unresolved* Get(const CommandExecutionInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(CommandExecutionInterface* o) { return (Unresolved*) o; }
		static Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return CommandExecutionInterface::Invoke(command, data, interactive); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return CommandExecutionInterface::Invoke(command, data, interactive, setParameters); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return CommandExecutionInterface::Interact(data, interactionType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE CommandExecutionInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<COMMANDRESULT>>::value,
		maxon::details::NullReturnType<Result<COMMANDRESULT>>::value,
		maxon::details::NullReturnType<Result<COMMANDRESULT>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CommandExecutionInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<COMMANDRESULT>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->CommandExecutionInterface_Invoke = &Hxx2::Wrapper<Hxx2::Unresolved>::CommandExecutionInterface_Invoke;
		#else
		tbl->CommandExecutionInterface_Invoke = &Hxx2::Wrapper<Hxx2::Unresolved>::CommandExecutionInterface_Invoke;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<COMMANDRESULT>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->CommandExecutionInterface_Invoke_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::CommandExecutionInterface_Invoke_1;
		#else
		tbl->CommandExecutionInterface_Invoke_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::CommandExecutionInterface_Invoke_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<COMMANDRESULT>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->CommandExecutionInterface_Interact = &Hxx2::Wrapper<Hxx2::Unresolved>::CommandExecutionInterface_Interact;
		#else
		tbl->CommandExecutionInterface_Interact = &Hxx2::Wrapper<Hxx2::Unresolved>::CommandExecutionInterface_Interact;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CommandExecutionInterface, "net.maxon.command.interface.execution", nullptr);
	namespace COMMAND
	{
		INTERACTIVE_PrivateAttribute INTERACTIVE;
		INTERACTIONCLASS_PrivateAttribute INTERACTIONCLASS;
		USECACHE_PrivateAttribute USECACHE;
		CACHEDATA_PrivateAttribute CACHEDATA;
	}
	MAXON_REGISTRY_REGISTER(CommandDataClasses);
	MAXON_REGISTRY_REGISTER(LegacyCommandDataClasses);
	MAXON_REGISTRY_REGISTER(CommandClasses);
	MAXON_REGISTRY_REGISTER(LegacyCommand);
	MAXON_REGISTRY_REGISTER(MigratedCommand);
	MAXON_REGISTRY_REGISTER(CommandInteraction);
	MAXON_REGISTRY_REGISTER(CommandDescription);
	MAXON_REGISTRY_REGISTER(CommandConversionClasses);
	MAXON_REGISTRY_REGISTER(CommandCacheClasses);
	namespace CommandDataClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BASE, , "net.maxon.commanddata.base");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_commandbase(0
	| maxon::CommandConversionClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
