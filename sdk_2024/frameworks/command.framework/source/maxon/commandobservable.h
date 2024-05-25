#ifndef COMMANDOBSERVABLE_H__
#define COMMANDOBSERVABLE_H__

#include "maxon/commandbase.h"
#include "maxon/observerobject.h"

namespace maxon
{

template<> class DefaultValueFunctionsHelper<const Result<COMMANDRESULT>&>
{
public:
	static const Result<COMMANDRESULT>& Get()
	{
		return GetZeroRef<Result<COMMANDRESULT>>();
	}
};

struct InvocationState
{
	Bool _interactive = false;
	INTERACTIONTYPE _interaction = INTERACTIONTYPE::NONE;
};

//----------------------------------------------------------------------------------------
/// Implements Observables for the command system.
//----------------------------------------------------------------------------------------
class CommandObserverInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(CommandObserverInterface, MAXON_REFERENCE_NORMAL, "net.maxon.command.interface.observer");
	
public:

	//----------------------------------------------------------------------------------------
	/// ObservableCommandStatus can be sent from each command to update the progress of the command execution.
	/// Can be subscribed for example to update status bars.
	/// @param[in] commandId					The command id.
	/// @param[in] statusMessage			A dictionary containing the status messages.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableCommandStatus, (const Id& commandId, const DataDictionary& statusMessage), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableCommandInvoked is sent by the command system whenever a command is invoked.
	/// @param[in] commandId					The command id.
	/// @param[in] result							The result of the command invocation.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableCommandInvoked, (const Id& commandId, const Result<COMMANDRESULT>& result), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableCommandPrepareInfo is sent by the command system between the GetState and the Execute calls.
	/// @param[in] commandId					The command id.
	/// @param[in] data								The command data.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableCommandPrepareInfo, (const Id& commandId, const CommandDataRef& data), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableCommandInvokedInfo is sent by the command system at each stage of the command invokation.
	/// @param[in] commandId					The command id.
	/// @param[in] result							The result of the command invocation.
	/// @param[in] data								The command data.
	/// @param[in] interactionState		The stage of interaction.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableCommandInvokedInfo, (const Id& commandId, const Result<COMMANDRESULT>& result, const CommandDataRef& data, const InvocationState& interactionState), ObservableCombinerRunAllComponent);
};

#include "commandobservable1.hxx"

MAXON_DECLARATION(Class<CommandObserverRef>, CommandObserverObjectClass, "net.maxon.command.class.observer");
MAXON_DATATYPE(InvocationState, "net.maxon.datatype.command.invokationstate");

#include "commandobservable2.hxx"

} // namespace maxon


#endif // COMMANDOBSERVABLE_H__
