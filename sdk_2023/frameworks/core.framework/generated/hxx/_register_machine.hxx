#if 1
namespace maxon
{
	namespace enum32
	{
		enum class MACHINESTATE
		{
			NONE									= 0,									///< No bit set.
		
			CONNECTION_ERROR			= (1 << 0),						///< A connection error occurred with the machine.
			ADDED_MANUALLY				= (1 << 1),						///< Flag that signals that the machine is added manually.
			AVAILABLE_ZEROCONF		= (1 << 2),						///< Flag that signals that the machine is announced via zeroconf and is currently online (not necessary connected).
			CONNECTED							= (1 << 3),						///< Flag that signals that the machine is currently connected to the local machine.
		
			ALL										= (CONNECTION_ERROR | ADDED_MANUALLY | AVAILABLE_ZEROCONF | CONNECTED) ///< All Flags combined, useful for masking.
		} ;
		static const maxon::UInt64 MACHINESTATE_values[] = {maxon::UInt64(enum32::MACHINESTATE::NONE), maxon::UInt64(enum32::MACHINESTATE::CONNECTION_ERROR), maxon::UInt64(enum32::MACHINESTATE::ADDED_MANUALLY), maxon::UInt64(enum32::MACHINESTATE::AVAILABLE_ZEROCONF), maxon::UInt64(enum32::MACHINESTATE::CONNECTED), maxon::UInt64(enum32::MACHINESTATE::ALL)};
		static const maxon::EnumInfo MACHINESTATE_info{"MACHINESTATE", SIZEOF(MACHINESTATE), true, "NONE\0CONNECTION_ERROR\0ADDED_MANUALLY\0AVAILABLE_ZEROCONF\0CONNECTED\0ALL\0", MACHINESTATE_values, std::extent<decltype(MACHINESTATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MACHINESTATE32(){ return enum32::MACHINESTATE_info; }
	const maxon::Char* const MachineInterface::MTable::_ids = 
		"GetUniqueId@b8f12dfa16054f01\0" // String GetUniqueId() const
		"GetMachineInfo@b4a6b0e29e3a2d07\0" // Result<DataDictionary> GetMachineInfo() const
		"GetInterface@5db336786bae021b\0" // Result<ObjectRef> GetInterface(const Id& interfaceName)
		"GetState@3cd0500083b4d1fe\0" // MACHINESTATE GetState() const
		"SetState@e2bb00296ccef2e\0" // Bool SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags)
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"ObservablePrivateSplashMessageReceived@63704b81c7975d07\0" // maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate> ObservablePrivateSplashMessageReceived() const
		"ObservableActivationChanged@11c04ec923a0ccd\0" // maxon::ObservableRef<ObservableActivationChangedDelegate> ObservableActivationChanged() const
	"";
	const maxon::METHOD_FLAGS MachineInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MachineInterface, , "net.maxon.interface.machine", "maxon.MachineInterface", (ObserverObjectInterface::PrivateGetInterface()));
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
		"GetLocal@af1d98d1d6ee64f5\0" // MachineRef GetLocal()
		"GetRPCMachines@7504da3d38943ede\0" // Result<void> GetRPCMachines(WritableArrayInterface<MachineRef>& machines)
/// @cond INTERNAL

/// @endcond

		"FindRPCMachine@f36cc86d04b5b06e\0" // Result<MachineRef> FindRPCMachine(const String& machineUuid)
/// @cond INTERNAL

/// @endcond

		"FindOrAddRPCMachine@fd7326d6fd77372b\0" // Result<MachineRef> FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback)
/// @cond INTERNAL

/// @endcond

		"RemoveRPCMachine@75507bd7100139d9\0" // Result<void> RemoveRPCMachine(const MachineRef& machine)
		"ObservableMachineStateChanged@e75fd5e5d71ba290\0" // maxon::ObservableRef<ObservableMachineStateChangedDelegate> ObservableMachineStateChanged()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class MachinesInterface::Hxx2::Unresolved : public MachinesInterface
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
	MAXON_WARNING_POP
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
		if (maxon::details::NullReturnType<MachineRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->MachinesInterface_GetLocal = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_GetLocal), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_GetLocal);
		#else
		tbl->MachinesInterface_GetLocal = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_GetLocal), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_GetLocal);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->MachinesInterface_GetRPCMachines = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_GetRPCMachines), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_GetRPCMachines);
		#else
		tbl->MachinesInterface_GetRPCMachines = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_GetRPCMachines), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_GetRPCMachines);
		#endif
/// @cond INTERNAL

/// @endcond

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<MachineRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->MachinesInterface_FindRPCMachine = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_FindRPCMachine), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_FindRPCMachine);
		#else
		tbl->MachinesInterface_FindRPCMachine = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_FindRPCMachine), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_FindRPCMachine);
		#endif
/// @cond INTERNAL

/// @endcond

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<MachineRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->MachinesInterface_FindOrAddRPCMachine = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_FindOrAddRPCMachine), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_FindOrAddRPCMachine);
		#else
		tbl->MachinesInterface_FindOrAddRPCMachine = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_FindOrAddRPCMachine), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_FindOrAddRPCMachine);
		#endif
/// @cond INTERNAL

/// @endcond

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->MachinesInterface_RemoveRPCMachine = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_RemoveRPCMachine), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_RemoveRPCMachine);
		#else
		tbl->MachinesInterface_RemoveRPCMachine = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_RemoveRPCMachine), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_RemoveRPCMachine);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableMachineStateChangedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->MachinesInterface_ObservableMachineStateChanged = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_ObservableMachineStateChanged), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_ObservableMachineStateChanged);
		#else
		tbl->MachinesInterface_ObservableMachineStateChanged = PRIVATE_MAXON_MF_CAST(decltype(MachinesInterface_ObservableMachineStateChanged), &Hxx2::Wrapper<Hxx2::Unresolved>::MachinesInterface_ObservableMachineStateChanged);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
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
	namespace MACHINE_MESSAGE
	{
		MSG_ID_PrivateAttribute MSG_ID;
		namespace MSG_INITIALIZATION_FINISHED
		{
			ID_PrivateAttribute ID;
		}
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
