#if 1
namespace maxon
{
	namespace enum31 { enum class MACHINESTATE
	{
		NONE									= 0,									///< No bit set.
	
		CONNECTION_ERROR			= (1 << 0),						///< A connection error occurred with the machine.
		ADDED_MANUALLY				= (1 << 1),						///< Flag that signals that the machine is added manually.
		AVAILABLE_ZEROCONF		= (1 << 2),						///< Flag that signals that the machine is announced via zeroconf and is currently online (not necessary connected).
		CONNECTED							= (1 << 3),						///< Flag that signals that the machine is currently connected to the local machine.
	
		ALL										= (CONNECTION_ERROR | ADDED_MANUALLY | AVAILABLE_ZEROCONF | CONNECTED) ///< All Flags combined, useful for masking.
	} ; }
	maxon::String PrivateToString_MACHINESTATE31(std::underlying_type<enum31::MACHINESTATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum31::MACHINESTATE::NONE, (maxon::UInt64) enum31::MACHINESTATE::CONNECTION_ERROR, (maxon::UInt64) enum31::MACHINESTATE::ADDED_MANUALLY, (maxon::UInt64) enum31::MACHINESTATE::AVAILABLE_ZEROCONF, (maxon::UInt64) enum31::MACHINESTATE::CONNECTED, (maxon::UInt64) enum31::MACHINESTATE::ALL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MACHINESTATE", SIZEOF(x), true, values, "NONE\0CONNECTION_ERROR\0ADDED_MANUALLY\0AVAILABLE_ZEROCONF\0CONNECTED\0ALL\0", fmt);
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MachineInterface, "net.maxon.interface.machine", "maxon.MachineInterface", , &ObserverObjectInterface::_interface);
	const maxon::Char* const MachineInterface::MTable::_ids = 
		"GetUniqueId@22c6ed80868\0" // GetUniqueId() const
		"GetMachineInfo@073ad55d659a6f76\0" // GetMachineInfo() const
		"GetInterface@d343e8521a90cef4\0" // GetInterface(const Id& interfaceName)
		"GetState@cb534ffdf1fe7ea1\0" // GetState() const
		"SetState@d3b877e4563a7633\0" // SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags)
		"ToString@7de9f6f51c89c899\0" // ToString(const FormatStatement* formatStatement) const
		"ObservableMessageReceived@0dbc1c699a555f3a\0" // ObservableMessageReceived() const
	"";
	template <typename DUMMY> maxon::Int MachineInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<MACHINESTATE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

	const maxon::Char* const MachinesInterface::MTable::_ids = 
		"GetLocal@1c4acbd0769f984c\0" // GetLocal()
		"GetRPCMachines@82bb30d1287823ab\0" // GetRPCMachines(WritableArrayInterface<MachineRef>& machines)
/// @cond INTERNAL

/// @endcond

		"FindRPCMachine@bc6fd548095a557b\0" // FindRPCMachine(const String& machineUuid)
/// @cond INTERNAL

/// @endcond

		"FindOrAddRPCMachine@a2a810741d601e7c\0" // FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback)
/// @cond INTERNAL

/// @endcond

		"RemoveRPCMachine@12ba3487213a38de\0" // RemoveRPCMachine(const MachineRef& machine)
		"ObservableMachineStateChanged@aaea1fc06a2de921\0" // ObservableMachineStateChanged()
	"";
	class MachinesInterface::Unresolved : public MachinesInterface
	{
	public:
		static const Unresolved* Get(const MachinesInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(MachinesInterface* o) { return (Unresolved*) o; }
		static MachineRef GetLocal() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return MachinesInterface::GetLocal(); return maxon::PrivateIncompleteNullReturnValue<MachineRef>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> GetRPCMachines(WritableArrayInterface<MachineRef>& machines) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return MachinesInterface::GetRPCMachines(machines); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
/// @cond INTERNAL

/// @endcond

		static Result<MachineRef> FindRPCMachine(const String& machineUuid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return MachinesInterface::FindRPCMachine(machineUuid); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
/// @cond INTERNAL

/// @endcond

		static Result<MachineRef> FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return MachinesInterface::FindOrAddRPCMachine(machineUuid, state, newMachineCallback, existingCallback); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
/// @cond INTERNAL

/// @endcond

		static Result<void> RemoveRPCMachine(const MachineRef& machine) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return MachinesInterface::RemoveRPCMachine(machine); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static maxon::ObservableRef<ObservableMachineStateChangedDelegate> ObservableMachineStateChanged() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return MachinesInterface::ObservableMachineStateChanged(); return maxon::ObservableRef<ObservableMachineStateChangedDelegate>::NullValue();}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE MachinesInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<MachineRef>::value,
		maxon::details::NullReturnType<Result<void>>::value,
/// @cond INTERNAL

/// @endcond

		maxon::details::NullReturnType<Result<MachineRef>>::value,
/// @cond INTERNAL

/// @endcond

		maxon::details::NullReturnType<Result<MachineRef>>::value,
/// @cond INTERNAL

/// @endcond

		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableMachineStateChangedDelegate>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool MachinesInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<MachineRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_MachinesInterface_GetLocal = &Wrapper<Unresolved>::_MachinesInterface_GetLocal;
	#else
		tbl->_MachinesInterface_GetLocal = &Wrapper<Unresolved>::_MachinesInterface_GetLocal;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_MachinesInterface_GetRPCMachines = &Wrapper<Unresolved>::_MachinesInterface_GetRPCMachines;
	#else
		tbl->_MachinesInterface_GetRPCMachines = &Wrapper<Unresolved>::_MachinesInterface_GetRPCMachines;
	#endif
/// @cond INTERNAL

/// @endcond

	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<MachineRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_MachinesInterface_FindRPCMachine = &Wrapper<Unresolved>::_MachinesInterface_FindRPCMachine;
	#else
		tbl->_MachinesInterface_FindRPCMachine = &Wrapper<Unresolved>::_MachinesInterface_FindRPCMachine;
	#endif
/// @cond INTERNAL

/// @endcond

	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<MachineRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_MachinesInterface_FindOrAddRPCMachine = &Wrapper<Unresolved>::_MachinesInterface_FindOrAddRPCMachine;
	#else
		tbl->_MachinesInterface_FindOrAddRPCMachine = &Wrapper<Unresolved>::_MachinesInterface_FindOrAddRPCMachine;
	#endif
/// @cond INTERNAL

/// @endcond

	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_MachinesInterface_RemoveRPCMachine = &Wrapper<Unresolved>::_MachinesInterface_RemoveRPCMachine;
	#else
		tbl->_MachinesInterface_RemoveRPCMachine = &Wrapper<Unresolved>::_MachinesInterface_RemoveRPCMachine;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableMachineStateChangedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_MachinesInterface_ObservableMachineStateChanged = &Wrapper<Unresolved>::_MachinesInterface_ObservableMachineStateChanged;
	#else
		tbl->_MachinesInterface_ObservableMachineStateChanged = &Wrapper<Unresolved>::_MachinesInterface_ObservableMachineStateChanged;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(MachinesInterface, "net.maxon.interface.machines", nullptr);
	template <typename DUMMY> maxon::Int MachinesInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<MachineRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LocalMachineClass, , "net.maxon.class.localmachine");
#ifndef MAXON_COMPILER_CLANG
#endif
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_CreateObjectRefFunc,, "net.maxon.datatype.createobjectreffunc");
	MAXON_REGISTRY_REGISTER(MachineImplementationFactories);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_machine(0
	| maxon::MachineInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::MachinesInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
