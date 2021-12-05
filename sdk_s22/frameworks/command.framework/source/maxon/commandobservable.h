#ifndef COMMANDOBSERVABLE_H__
#define COMMANDOBSERVABLE_H__

#include "maxon/commandbase.h"
#include "maxon/observerobject.h"

namespace maxon
{

template<> class NullValueFunctionsHelper<const Result<COMMANDRESULT>&>
{
public:
	static const Result<COMMANDRESULT>& Get()
	{
		return GetZeroRef<Result<COMMANDRESULT>>();
	}
};

//----------------------------------------------------------------------------------------
/// Implements Observable for commands.
//----------------------------------------------------------------------------------------
class CommandObserverInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(CommandObserverInterface, MAXON_REFERENCE_NORMAL, "net.maxon.command.interface.observer");
	
public:
	
	MAXON_OBSERVABLE(Result<void>, ObservableCommandStatus, (const Id& commandId, const DataDictionary& statusMessage), ObservableCombinerRunAllComponent);
	MAXON_OBSERVABLE(Result<void>, ObservableCommandInvoked, (const Id& commandId, const Result<COMMANDRESULT>& result), ObservableCombinerRunAllComponent);
};

#include "commandobservable1.hxx"

MAXON_DECLARATION(Class<CommandObserverRef>, CommandObserverObjectClass, "net.maxon.command.class.observer");

#include "commandobservable2.hxx"

} // namespace maxon


#endif // COMMANDOBSERVABLE_H__
