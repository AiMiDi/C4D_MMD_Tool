#if 1
namespace maxon
{
	namespace enum28 { enum class COMMANDSTATE
	{
		DISABLED = 0,	///< The command can't be executed.
		ENABLED	 = 1  ///< The command can be executed.
	} ; }
	maxon::String PrivateToString_COMMANDSTATE28(std::underlying_type<enum28::COMMANDSTATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum28::COMMANDSTATE::DISABLED, (maxon::UInt64) enum28::COMMANDSTATE::ENABLED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COMMANDSTATE", SIZEOF(x), false, values, "DISABLED\0ENABLED\0", fmt);
	}
	namespace enum38 { enum class COMMANDRESULT
	{
		OK		= 0,	///< The command was executed properly.
		SKIP 	= 1,	///< The command did not execute because no action was necessary (e.g. no selection).
		BREAK = 2		///< The command execution was interrupted.
	} ; }
	maxon::String PrivateToString_COMMANDRESULT38(std::underlying_type<enum38::COMMANDRESULT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum38::COMMANDRESULT::OK, (maxon::UInt64) enum38::COMMANDRESULT::SKIP, (maxon::UInt64) enum38::COMMANDRESULT::BREAK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COMMANDRESULT", SIZEOF(x), false, values, "OK\0SKIP\0BREAK\0", fmt);
	}
	namespace enum50 { enum class INTERACTIONTYPE
	{
		NONE 			= 0,	///< No interaction.
		START 		= 1,	///< Interaction start (e.g. first mouse click).
		ITERATE 	= 2,	///< Interaction iteration, performed several times after START (e.g. mouse drag).
		END 			= 3,	///< Interaction end (e.g. mouse released).
		REALTIME 	= 4		///< Real-time iterative interaction (e.g. cursor over viewport).
	} ; }
	maxon::String PrivateToString_INTERACTIONTYPE50(std::underlying_type<enum50::INTERACTIONTYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum50::INTERACTIONTYPE::NONE, (maxon::UInt64) enum50::INTERACTIONTYPE::START, (maxon::UInt64) enum50::INTERACTIONTYPE::ITERATE, (maxon::UInt64) enum50::INTERACTIONTYPE::END, (maxon::UInt64) enum50::INTERACTIONTYPE::REALTIME};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "INTERACTIONTYPE", SIZEOF(x), false, values, "NONE\0START\0ITERATE\0END\0REALTIME\0", fmt);
	}
	const maxon::Char* const CommandDataInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandDataInterface, , "net.maxon.command.interface.commanddata", "maxon.CommandDataInterface", (&DataDictionaryObjectInterface::_interface));
	const maxon::Char* const LegacyCommandDataInterface::MTable::_ids = 
		"GetLegacyData@31a1c5c63edac758\0" // Result<Generic*> GetLegacyData(Int index)
		"SetLegacyData@10a94379a1b1742b\0" // Result<void> SetLegacyData(const Generic* data, Int index)
		"GetLegacyDataCount@4386c86\0" // Int GetLegacyDataCount() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(LegacyCommandDataInterface, , "net.maxon.command.interface.legacycommanddata", "maxon.LegacyCommandDataInterface", (&CommandDataInterface::_interface));
	const maxon::Char* const CommandClassInterface::MTable::_ids = 
		"GetState@543ad5b829a7ffdc\0" // Result<COMMANDSTATE> GetState(CommandDataRef& data) const
		"Execute@1cd0ab9d77b48760\0" // Result<COMMANDRESULT> Execute(CommandDataRef& data) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandClassInterface, , "net.maxon.command.interface.command", "maxon.CommandClassInterface", (&ObjectInterface::_interface));
	const maxon::Char* const CommandInteractionClassInterface::MTable::_ids = 
		"Interact@de2c47566a8408e0\0" // Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandInteractionClassInterface, , "net.maxon.command.interface.commandinteraction", "maxon.CommandInteractionClassInterface", (&ObjectInterface::_interface));
	const maxon::Char* const CommandDescriptionClassInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(CommandDescriptionClassInterface, CommandDescriptionClassInterface, , , "net.maxon.command.interface.commanddescriptioninterface", "maxon.CommandDescriptionClassInterface", (&DataDictionaryReferenceObjectInterface::_interface), (&DataDescriptionObjectInterface::_interface), nullptr);
	const maxon::Char* const LegacyCommandClassInterface::MTable::_ids = 
		"ConvertSettings@1883596fa80758b3\0" // Result<void> ConvertSettings(LegacyCommandDataRef& data) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(LegacyCommandClassInterface, , "net.maxon.command.interface.legacycommand", "maxon.LegacyCommandClassInterface", (&CommandClassInterface::_interface));
	const maxon::Char* const MigratedCommandClassInterface::MTable::_ids = 
		"GetMigratedCommandId@fd7d68f65\0" // Int32 GetMigratedCommandId() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MigratedCommandClassInterface, , "net.maxon.command.interface.migratedcommand", "maxon.MigratedCommandClassInterface", (&LegacyCommandClassInterface::_interface));
	const maxon::Char* const CommandConversionClassInterface::MTable::_ids = 
		"ConvertInput@1883596fa80758b3\0" // Result<void> ConvertInput(LegacyCommandDataRef& data) const
		"ExecuteCustomActions@50c63606e9ef31ad\0" // Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const
		"ConvertOutput@1883596fa80758b3\0" // Result<void> ConvertOutput(LegacyCommandDataRef& data) const
		"GetLegacyCommandId@fd7d68f65\0" // Int32 GetLegacyCommandId() const
		"GetCommandId@22aaf2\0" // Id GetCommandId() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandConversionClassInterface, , "net.maxon.command.interface.commandconversion", "maxon.CommandConversionClassInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int CommandConversionClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const CommandExecutionInterface::MTable::_ids = 
		"Invoke@2b0c8f78d624ee57\0" // Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive)
		"Invoke@12165afd235ba628\0" // Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters)
		"Interact@de2c47566a8408c9\0" // Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType)
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
		if (maxon::details::NullReturnType<Result<COMMANDRESULT>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CommandExecutionInterface_Invoke = &Hxx2::Wrapper<Hxx2::Unresolved>::_CommandExecutionInterface_Invoke;
		#else
		tbl->_CommandExecutionInterface_Invoke = &Hxx2::Wrapper<Hxx2::Unresolved>::_CommandExecutionInterface_Invoke;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<COMMANDRESULT>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CommandExecutionInterface_Invoke_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CommandExecutionInterface_Invoke_1;
		#else
		tbl->_CommandExecutionInterface_Invoke_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CommandExecutionInterface_Invoke_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<COMMANDRESULT>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CommandExecutionInterface_Interact = &Hxx2::Wrapper<Hxx2::Unresolved>::_CommandExecutionInterface_Interact;
		#else
		tbl->_CommandExecutionInterface_Interact = &Hxx2::Wrapper<Hxx2::Unresolved>::_CommandExecutionInterface_Interact;
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
	}
	MAXON_REGISTRY_REGISTER(CommandDataClasses);
	MAXON_REGISTRY_REGISTER(LegacyCommandDataClasses);
	MAXON_REGISTRY_REGISTER(CommandClasses);
	MAXON_REGISTRY_REGISTER(LegacyCommand);
	MAXON_REGISTRY_REGISTER(MigratedCommand);
	MAXON_REGISTRY_REGISTER(CommandInteraction);
	MAXON_REGISTRY_REGISTER(CommandDescription);
	MAXON_REGISTRY_REGISTER(CommandConversionClasses);
	namespace CommandDataClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BASE, , "net.maxon.commanddata.base");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_commandbase(0
	| maxon::CommandConversionClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
