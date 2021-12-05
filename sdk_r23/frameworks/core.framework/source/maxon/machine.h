#ifndef MACHINE_H__
#define MACHINE_H__

#include "maxon/observerobject.h"
#include "maxon/datadictionary.h"
#include "maxon/array.h"


namespace maxon
{

class MachineRef;


//----------------------------------------------------------------------------------------
/// State of a MachineRef.
/// Various scenarios are possible with connected machines.
/// a) A machine is manually added but also announced via ZeroConf services.
/// b) A machine is added by ZeroConf and established a connection, but afterwards the ZeroConf disappeared and the connection is still online.
//----------------------------------------------------------------------------------------
enum class MACHINESTATE
{
	NONE									= 0,									///< No bit set.

	CONNECTION_ERROR			= (1 << 0),						///< A connection error occurred with the machine.
	ADDED_MANUALLY				= (1 << 1),						///< Flag that signals that the machine is added manually.
	AVAILABLE_ZEROCONF		= (1 << 2),						///< Flag that signals that the machine is announced via zeroconf and is currently online (not necessary connected).
	CONNECTED							= (1 << 3),						///< Flag that signals that the machine is currently connected to the local machine.

	ALL										= (CONNECTION_ERROR | ADDED_MANUALLY | AVAILABLE_ZEROCONF | CONNECTED) ///< All Flags combined, useful for masking.
} MAXON_ENUM_FLAGS(MACHINESTATE);



//----------------------------------------------------------------------------------------
/// This class is the entry point to access machine interfaces.
/// So there is no difference if the machine is running local or remote via rpc.
//----------------------------------------------------------------------------------------
class MachineInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(MachineInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.machine");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the service name of the local machine.
	/// This name is a unique name which allows to identify the machine.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetUniqueId() const;

	//----------------------------------------------------------------------------------------
	/// Returns information about the system and processor.
	/// See maxon::MACHINEINFO for DataDictionary properties.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDictionary> GetMachineInfo() const;

	//----------------------------------------------------------------------------------------
	/// Returns a interface of this machine. E.g. write OSClipboardRef clipboard = machine.GetInterface<OSClipboardRef>(); to get the clipboard interface handle.
	/// Don't use the Interface function but the overloaded NetworkRPCMachine::GetInterface<>() template instead.
	/// THREADSAFE.
	/// It automatically detects the interfaceName and casts the type.
	/// @param[in] interfaceName			INTERFACE::_interface.GetId().
	/// @return												If successful the handle to the interface is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ObjectRef> GetInterface(const Id& interfaceName);

	//----------------------------------------------------------------------------------------
	/// Returns a interface of a machine. e.g. write OSClipboardRef clipboard = machine.GetInterface<OSClipboardRef>(); to get the clipboard interface handle.
	/// At the moment supported are: OSGuiRef, OSClipboardRef, GameServerRef, CaptureDeviceListRef, UpdaterRef.
	/// @return												If the function is successful the handle to the interface is returned.
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE> MAXON_FUNCTION Result<INTERFACE> GetInterface()
	{
		iferr (auto res = MachineInterface::GetInterface(INTERFACE::ReferencedType::_interface.GetIdWithoutHash()))
			return err;
		INTERFACE typedRes = Cast<INTERFACE>(res);
		if (typedRes == nullptr)
			return IllegalStateError(MAXON_SOURCE_LOCATION);
		return typedRes;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the machine state of the given machine. See MACHINEINFO for details.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MACHINESTATE GetState() const;

	//----------------------------------------------------------------------------------------
	/// ** private ** Sets the machine state of the given machine. This function should not be called by users. It's private for internal functions.
	/// @param[in] stateMask					Mask of flags that should be changed.
	/// @param[in] stateFlags					Values of flags that be set.
	/// @return												True if the function succeeded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags);

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Use "{N}" for nive formatting of the name only. Otherwise the unique id is printed together with the name.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	MAXON_OBSERVABLE(void, ObservableMessageReceived, (const MachineRef& machine, const DataDictionary& data), ObservableCombinerRunAllComponent);

};



/// Callback used by FindOrAddRPCMachine.
/// This callback will be called when the machine is not already registered and must be created new.
using CreateNewMachineCallback = Delegate<Result<MachineRef>(const String& machineUuid)>;
/// Callback used by FindOrAddRPCMachine.
/// This callback will be called when the machine is already registered and will be reused.
using CheckExistingMachineCallback = Delegate<Result<void>(const MachineRef& machineRef)>;

//----------------------------------------------------------------------------------------
/// This class declares functions to access and manage machines.
/// There is no difference when accessing the machines using the available rpc interfaces where the machine runs (local, remote, webbrowser).
//----------------------------------------------------------------------------------------
class MachinesInterface
{
	MAXON_INTERFACE_NONVIRTUAL(MachinesInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.machines");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the local machine. It can be used like every other machine in the network.
	/// The difference is that the functions for this machine are called directly not using rpc.
	/// @return												Handle to the machine.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD MachineRef GetLocal();

	//----------------------------------------------------------------------------------------
	/// Returns a list of all available machines in the application. The local machine is always the first entry in this list.
	/// it's guaranteed that at least one machine (the local) is returned in the array.
	/// @param[out] machines					Returns the list of machines.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetRPCMachines(WritableArrayInterface<MachineRef>& machines);

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// This function finds a machine with the given machineName.
	/// @param[in] machineUuid				Unique id of the machine. This must be a unique name because it's inserted under this name to the list.
	/// @return												Valid MachineRef if the function succeeded.
	/// @endcond
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<MachineRef> FindRPCMachine(const String& machineUuid);

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// This function finds or adds a machine with the given machineName.
	/// @param[in] machineUuid				Unique id of the machine. This must be a unique name because it's inserted under this name to the list.
	/// @param[in] state							Can be one of the following flags: MACHINESTATE::ADDED_MANUALLY or MACHINESTATE::AVAILABLE_ZEROCONF.
	/// @param[in] newMachineCallback	This callback will be called if the machine was not found in the machine list. The callback needs to return the new MachineRef if it was not in the list. This callback is called within a locked scope of the machine database.
	/// @param[in] existingCallback		This callback will be called if the machine was found in the machine list. The callback needs to return true if everything is ok, false if an error appears. This callback is called within a locked scope of the machine database.
	/// @return												MachineRef if the function succeeded, in that case you must call FindOrAddRPCMachineUnlock(). If nullptr this indicates an error and there is no need to call FindOrAddRPCMachineUnlock().
	/// @endcond
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<MachineRef> FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback);

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// Removes a machine from the list of available machines.
	/// @param[in] machine						Reference to the machine to remove.
	/// @return												OK on success.
	/// @endcond
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RemoveRPCMachine(const MachineRef& machine);

	//----------------------------------------------------------------------------------------
	/// Signals that a machine state has been changed.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(void, ObservableMachineStateChanged, (const MachineRef& machine, MACHINESTATE oldState, MACHINESTATE newState), ObservableCombinerRunAllComponent);
};





#include "machine1.hxx"

MAXON_DECLARATION(Class<MachineRef>, LocalMachineClass, "net.maxon.class.localmachine");

//----------------------------------------------------------------------------------------
/// Registry to extend MachineInterface::GetInterface(Id)
#ifndef MAXON_COMPILER_CLANG	// circumvent clang bug that creates false positives
/// @return												ObjectRef to the interface.
#endif
//----------------------------------------------------------------------------------------
using CreateObjectRefFunc = ObjectRef(*)();
MAXON_DATATYPE(CreateObjectRefFunc, "net.maxon.datatype.createobjectreffunc");

MAXON_REGISTRY(CreateObjectRefFunc, MachineImplementationFactories, "net.maxon.registry.machineimplementationfactories");

#include "machine2.hxx"

}


#endif // MACHINE_H__
