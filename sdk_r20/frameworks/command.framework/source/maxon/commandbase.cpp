#include "maxon/commandbase.h"

namespace maxon
{
	
MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Invoke(const Id& command, Bool interactive)
{
	return Invoke(CommandClasses::Get(command), interactive);
}

MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Invoke(const CommandClass& command, Bool interactive)
{
	iferr_scope;
	
	CommandDataRef dataRef = this;
	
	if (command.IsInstanceOf<LegacyCommandClassInterface>() && dataRef.IsInstanceOf<LegacyCommandDataRef>())
	{
		LegacyCommandDataRef 	legacyDataRef = Cast<LegacyCommandDataRef>(dataRef);
		const LegacyCommandClass& legacyClass = Cast<LegacyCommandClass>(command);
		legacyClass.ConvertSettings(legacyDataRef) iferr_return;
	}
	
	COMMANDSTATE state = command.GetState(dataRef) iferr_return;
	
	if (state != COMMANDSTATE::ENABLED)
		return COMMANDRESULT::SKIP;
	
	dataRef.Set<Bool>(COMMAND::INTERACTIVE, interactive ? true : false) iferr_return;
	
	if (interactive && command.IsInstanceOf<CommandInteractionClassInterface>())
	{
		CommandClass cls = command.Clone() iferr_return;
		dataRef.Set<CommandClass>(COMMAND::INTERACTIONCLASS, std::move(cls)) iferr_return;
	}
	else
	{
		dataRef.Erase(COMMAND::INTERACTIONCLASS) iferr_return;
	}
	
	return command.Execute(dataRef);
}

MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Interact(INTERACTIONTYPE interactionType)
{
	iferr_scope;
	
	CommandDataRef 	dataRef = this;
	const CommandClass& command = dataRef.Get(COMMAND::INTERACTIONCLASS) iferr_return;

	if (command.IsInstanceOf<LegacyCommandClassInterface>() && dataRef.IsInstanceOf<LegacyCommandDataRef>())
	{
		LegacyCommandDataRef 	legacyDataRef = Cast<LegacyCommandDataRef>(dataRef);
		const LegacyCommandClass& legacyClass = Cast<LegacyCommandClass>(command);
		legacyClass.ConvertSettings(legacyDataRef) iferr_return;
	}

	COMMANDSTATE state = command.GetState(dataRef) iferr_return;

	if (state != COMMANDSTATE::ENABLED)
		return COMMANDRESULT::SKIP;

	if (command.IsInstanceOf<CommandInteractionClassInterface>())
	{
		const CommandInteractionClass& interactionClass = Cast<CommandInteractionClass>(command);
		return interactionClass.Interact(dataRef, interactionType);
	}
	
	return IllegalStateError(MAXON_SOURCE_LOCATION);
}

	
} // namespace maxon
