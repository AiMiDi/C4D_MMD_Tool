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

CommandCacheData::~CommandCacheData()
{
	for (CommandCacheRef& cache : _map.GetValues())
	{
		if (cache)
		{
			cache.Reset();
		}
	}
}

Result<void> CommandCacheData::CopyFrom(const CommandCacheData& src)
{
	iferr_scope;
	_map.CopyFrom(src._map) iferr_return;
	_validateFn.CopyFrom(src._validateFn) iferr_return;
	return OK;
}

Result<CommandCacheRef> CommandCacheData::Validate(CommandDataRef& data, const Id& commandId, const Id& cacheId, Bool& valid)
{
	iferr_scope;

	CommandCacheRef& cache = _map.InsertKey(commandId) iferr_return;
	if (!cache)
	{
		cache = CommandCacheClasses::Get(cacheId).Create() iferr_return;
	}

	valid = _validateFn(commandId) iferr_return;

	return cache;
}

Result<void> CommandCacheData::AddValidation(Delegate<Result<Bool>(const Id& commandId)>&& validation)
{
	iferr_scope;
	_validateFn = std::move(validation);
	return OK;
}

Result<void> CommandCacheData::CreateInitCache(CommandDataRef& data, CommandCacheRef& cache, const Id& cacheId)
{
	iferr_scope;

	if (cache)
	{
		cache.Reset();
	}
	else
	{
		cache = CommandCacheClasses::Get(cacheId).Create() iferr_return;
	}

	cache.Init(data) iferr_return;

	return OK;
}

} // namespace maxon
