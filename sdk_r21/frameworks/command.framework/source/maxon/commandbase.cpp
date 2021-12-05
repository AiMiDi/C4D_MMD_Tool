#include "maxon/commandbase.h"
#include "maxon/datadescription_data.h"
#include "maxon/datadescriptiondatabase.h"

namespace maxon
{
	
MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Invoke(const Id& command, Bool interactive)
{
	CommandDataRef dataRef = this;
	return CommandExecutionInterface::Invoke(CommandClasses::Get(command), dataRef, interactive);
}

MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Invoke(const CommandClass& command, Bool interactive)
{
	CommandDataRef dataRef = this;
	return CommandExecutionInterface::Invoke(command, dataRef, interactive);
}

MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Invoke(const Id& command, Bool interactive, const SetParameters& setParameters)
{
	CommandDataRef dataRef = this;
	return CommandExecutionInterface::Invoke(CommandClasses::Get(command), dataRef, interactive, setParameters);
}

MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters)
{
	CommandDataRef dataRef = this;
	return CommandExecutionInterface::Invoke(command, dataRef, interactive, setParameters);
}

MAXON_FUNCTION Result<COMMANDRESULT> CommandDataInterface::Interact(INTERACTIONTYPE interactionType)
{
	CommandDataRef 	dataRef = this;
	return CommandExecutionInterface::Interact(dataRef, interactionType);
}

MAXON_FUNCTION Result<void> CommandDescriptionClassInterface::SetContext(CommandDataRef& data) const
{
	DataDictionary* dataDictionaryPtr = (DataDictionary*)data.GetPointer();
	return ((DataDictionaryReferenceObjectInterface*)this)->Init(dataDictionaryPtr);
}

} // namespace maxon
