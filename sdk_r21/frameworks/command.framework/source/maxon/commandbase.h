#ifndef COMMANDBASE_H__
#define COMMANDBASE_H__

#include "maxon/apibase.h"
#include "maxon/objectbase.h"
#include "maxon/interfacebase.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/datadescriptionobject.h"
#include "maxon/delegate.h"
#include "maxon/fid.h"

namespace maxon
{

// forward declarations
class CommandClass;
class CommandInteractionClass;
class CommandDataRef;
class LegacyCommandDataRef;

//----------------------------------------------------------------------------------------
/// Defines if a command can be executed or not.
//----------------------------------------------------------------------------------------
enum class COMMANDSTATE
{
	DISABLED = 0,	///< The command can't be executed.
	ENABLED	 = 1  ///< The command can be executed.
} MAXON_ENUM_LIST(COMMANDSTATE);

//----------------------------------------------------------------------------------------
/// Defines the result of the command after execution.
//----------------------------------------------------------------------------------------
enum class COMMANDRESULT
{
	OK		= 0,	///< The command was executed properly.
	SKIP 	= 1,	///< The command did not execute because no action was necessary (e.g. no selection).
	BREAK = 2		///< The command execution was interrupted.
} MAXON_ENUM_LIST(COMMANDRESULT);

//----------------------------------------------------------------------------------------
/// Defines the interactivity mode.
//----------------------------------------------------------------------------------------
enum class INTERACTIONTYPE
{
	NONE 			= 0,	///< No interaction.
	START 		= 1,	///< Interaction start (e.g. first mouse click).
	ITERATE 	= 2,	///< Interaction iteration, performed several times after START (e.g. mouse drag).
	END 			= 3,	///< Interaction end (e.g. mouse released).
	REALTIME 	= 4		///< Real-time iterative interaction (e.g. cursor over viewport).
} MAXON_ENUM_LIST(INTERACTIONTYPE);

//----------------------------------------------------------------------------------------
/// A parameter id with its own value. Used internally by the PARAM() macro (see below).
//----------------------------------------------------------------------------------------
class CommandTuple
{
	public:
	CommandTuple(const InternedId& idx, Data&& data) : _data(Tuple<InternedId, Data>(idx, std::move(data))) {	}

	template<typename T> static CommandTuple Create(const InternedId& idx, T&& data)
	{
		Data d;
		MAXON_WARN_MUTE_UNUSED d.Set(data);
		return CommandTuple(idx, std::move(d));
	}

	Tuple<InternedId, Data> _data; ///< The parameter id and the corresponding value to be set.
};

//----------------------------------------------------------------------------------------
/// PARAM allows to invoke a command and to set the command data at the same time.
/// Example usage:
///	maxon::CommandDataRef commandData = maxon::CommandDataClasses::BASE().Create() iferr_return;
///	maxon::COMMANDRESULT result = commandData.Invoke(maxon::CommandClasses::PAINT(), true,
///			PARAM(maxon::COMMAND::POLYLINE::DRAW, maxon::POLYLINE_DRAW::BOX),
///			PARAM(maxon::COMMAND::POLYLINE::START, Vector(mouseX, mouseY, 0.0)),
///			PARAM(maxon::COMMAND::POLYLINE::END, Vector(mouseX, mouseY, 0.0))) iferr_return;
//----------------------------------------------------------------------------------------
#define PARAM(Name, Value)\
	maxon::CommandTuple::Create(Name, Value)

//----------------------------------------------------------------------------------------
/// Base command data interface as a simple data dictionary.
/// It contains all the data and necessary functions to executed and interact with commands.
//----------------------------------------------------------------------------------------
class CommandDataInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(CommandDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.command.interface.commanddata");
public:

	using SetParameters = Delegate<Result<void>(CommandDataRef& data)>;

	//----------------------------------------------------------------------------------------
	/// Invokes a command on this data.
	/// @param[in] command						The command ID.
	/// @param[in] interactive 				If true the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
	/// @return 											The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive);
	
	//----------------------------------------------------------------------------------------
	/// Invokes a command on this data.
	/// @param[in] command						The command class.
	/// @param[in] interactive				If true the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
	/// @return												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive);

	//----------------------------------------------------------------------------------------
	/// Invokes a command on this data.
	/// @param[in] command						The command ID.
	/// @param[in] interactive 				If true, the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
	/// @param[in] setParameters 			A delegate to fill the CommandData with command parameters.
	/// @return 											The command result, or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive, const SetParameters& setParameters);

	//----------------------------------------------------------------------------------------
	/// Invokes a command on this data.
	/// @param[in] command						The command class.
	/// @param[in] interactive				If true, the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
	/// @param[in] setParameters 			A delegate to fill the CommandData with command parameters.
	/// @return												The command result, or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters);

	//----------------------------------------------------------------------------------------
	/// Interact with the command result on this data. An interactive command must be called before this method is used.
	/// @param[in] interactionType		Define the kind of interaction, see INTERACTIONTYPE.
	/// @return												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Interact(INTERACTIONTYPE interactionType);

	class SetFunctor
	{
	public:
		explicit SetFunctor(DataDictionaryObjectInterface* dd) : _dd(dd) { }
		DataDictionaryObjectInterface* _dd = nullptr;

		template <typename T> void operator ()(T&& arg)
		{
			if (_dd)
			{
				MAXON_WARN_MUTE_UNUSED _dd->SetData(ForwardingDataPtr(MoveDataPtr(std::move(arg._data.first))), std::move(arg._data.second));
			}
		}
	};

	template <typename ...ARGS> MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive, ARGS&& ...args)
	{
		iferr_scope;

		DataDictionaryObjectInterface* dd = ((DataDictionaryObjectInterface*)this);
		Tuple<ARGS ...> r(std::forward<ARGS>(args) ...);
		SetFunctor f(dd);
		TupleForEach(r, f);
		return Invoke(command, interactive);
	}
};

//----------------------------------------------------------------------------------------
/// Legacy command data interface: a data dictionary which holds one or more pointers to generic data used to store legacy data types.
//----------------------------------------------------------------------------------------
class LegacyCommandDataInterface : MAXON_INTERFACE_BASES(CommandDataInterface)
{
	MAXON_INTERFACE(LegacyCommandDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.command.interface.legacycommanddata");

public:

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the legacy data at index.
	/// @param[in] index							The data index.
	/// @return												A pointer to the legacy data at the specified index. The memory ownership depends on the implementation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Generic*> GetLegacyData(Int index);

	//----------------------------------------------------------------------------------------
	/// Sets legacy data from a data pointer at index.
	/// @param[in] data								The legacy data pointer. The memory ownership depends on the implementation.
	/// @param[in] index							The data index.
	/// @return												OK on success at index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetLegacyData(const Generic* data, Int index);

	//----------------------------------------------------------------------------------------
	/// Count of legacy data entries.
	/// @return												Reference to the legacy data at index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLegacyDataCount() const;

	//----------------------------------------------------------------------------------------
	/// Sets legacy data from a data reference at index.
	/// @tparam LEGACYDATA						The type of legacy data.
	/// @param[in] data								The data.
	/// @param[in] index							The data index.
	/// #return 											OK on success.
	//----------------------------------------------------------------------------------------
	template<typename LEGACYDATA> MAXON_FUNCTION Result<void> SetLegacyData(const LEGACYDATA& data, Int index)
	{
		if (index >= GetLegacyDataCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Invalid legacy data index"_s);

		const Generic* res = reinterpret_cast<const Generic*>(&data);
		return SetLegacyData(res, index);
	}

	//----------------------------------------------------------------------------------------
	/// Gets a legacy data reference at index.
	/// @tparam LEGACYDATA						The data type that will be returned.
	/// @param[in] index							The data index.
	/// @return												Reference to the legacy data at index.
	//----------------------------------------------------------------------------------------
	template<typename LEGACYDATA> MAXON_FUNCTION Result<LEGACYDATA&> GetLegacyData(Int index)
	{
		iferr_scope;

		if (index >= GetLegacyDataCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Invalid legacy data index"_s);

		Generic* res = GetLegacyData(index) iferr_return;
		if (!res)
			return IllegalStateError(MAXON_SOURCE_LOCATION, "legacy data ss nullptr"_s); // does not mean this is always an error it depend on each data implementation.
		return *reinterpret_cast<LEGACYDATA*>(res);
	}
};

//----------------------------------------------------------------------------------------
/// Generic command interface.
//----------------------------------------------------------------------------------------
class CommandClassInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CommandClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.command");

public:

	//----------------------------------------------------------------------------------------
	/// Gets the command state, i.e. if it can be executed or not depending on a given data.
	/// @param[in,out] data						The command data.
	/// @return												The command state or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<COMMANDSTATE> GetState(CommandDataRef& data) const;

	//----------------------------------------------------------------------------------------
	/// Executes the command.
	/// @param[in,out] data						The command data.
	/// @return												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<COMMANDRESULT> Execute(CommandDataRef& data) const;
};

//----------------------------------------------------------------------------------------
/// Implements the command interactivity. Optional.
//----------------------------------------------------------------------------------------
class CommandInteractionClassInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CommandInteractionClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.commandinteraction");

public:

	//----------------------------------------------------------------------------------------
	/// Executes the command interaction.
	/// @param[in,out] data						The command data.
	/// @param[in] interactionType		The interaction type.
	/// @return												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const;
};

class CommandDescriptionClassInterface : MAXON_INTERFACE_BASES(DataDictionaryReferenceObjectInterface, DataDescriptionObjectInterface)
{
	MAXON_INTERFACE(CommandDescriptionClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.commanddescriptioninterface");

public:
	
	MAXON_FUNCTION Result<void> SetContext(CommandDataRef& data) const;
};
	
//----------------------------------------------------------------------------------------
/// A legacy command interface that implements the ability to convert legacy data settings to regular settings.
//----------------------------------------------------------------------------------------
class LegacyCommandClassInterface : MAXON_INTERFACE_BASES(CommandClassInterface)
{
	MAXON_INTERFACE(LegacyCommandClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.legacycommand");

public:

	//----------------------------------------------------------------------------------------
	/// Converts legacy settings (e.g. from a BaseContainer) to regular data parameters.
	/// @param[in,out] data						The command data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConvertSettings(LegacyCommandDataRef& data) const;
};

//----------------------------------------------------------------------------------------
/// A specialized legacy command interface for migrated commands.
/// Private.
//----------------------------------------------------------------------------------------
class MigratedCommandClassInterface : MAXON_INTERFACE_BASES(LegacyCommandClassInterface)
{
	MAXON_INTERFACE(MigratedCommandClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.migratedcommand");

public:

	//----------------------------------------------------------------------------------------
	/// Returns the legacy migrated command id. Used for the global command table registration.
	/// @return												The command plugin id.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetMigratedCommandId() const;
};

//----------------------------------------------------------------------------------------
/// Implements for command the conversions action.
//----------------------------------------------------------------------------------------
class CommandConversionClassInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CommandConversionClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.commandconversion");

public:

	MAXON_METHOD Result<void> ConvertInput(LegacyCommandDataRef& data) const;

	MAXON_METHOD Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const;

	MAXON_METHOD Result<void> ConvertOutput(LegacyCommandDataRef& data) const;

	MAXON_METHOD Int32 GetLegacyCommandId() const;

	MAXON_METHOD Id GetCommandId() const;
};

//----------------------------------------------------------------------------------------
/// Implements the commands execution.
/// Private.
//----------------------------------------------------------------------------------------
class CommandExecutionInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CommandExecutionInterface, MAXON_REFERENCE_NONE, "net.maxon.command.interface.execution");

public:

	static MAXON_METHOD Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive);

	static MAXON_METHOD Result<COMMANDRESULT> Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters);

	static MAXON_METHOD Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType);
};

//----------------------------------------------------------------------------------------
///	Generic command data parameters.
//----------------------------------------------------------------------------------------
namespace COMMAND
{
	MAXON_ATTRIBUTE(Bool, INTERACTIVE, "net.maxon.command.interactive", RESOURCE_DEFAULT(false)); 					///< True if the command is interactive. Owns the INTERACTIVE CALLBACK.
	MAXON_ATTRIBUTE(CommandClass, INTERACTIONCLASS, "net.maxon.command.interactionclass");									///< Optional command that can be used for interaction.
}

#include "commandbase1.hxx"

MAXON_REGISTRY(Class<CommandDataRef>, CommandDataClasses, "net.maxon.command.registry.commanddataclasses");
MAXON_REGISTRY(Class<LegacyCommandDataRef>, LegacyCommandDataClasses, "net.maxon.command.registry.legacycommanddataclasses");
MAXON_REGISTRY(CommandClass, CommandClasses, "net.maxon.command.registry.commandclasses");
MAXON_REGISTRY(LegacyCommandClass, LegacyCommand, "net.maxon.command.registry.legacycommandclass");
MAXON_REGISTRY(MigratedCommandClass, MigratedCommand, "net.maxon.command.registry.migratedcommandclass");
MAXON_REGISTRY(CommandInteractionClass, CommandInteraction, "net.maxon.command.registry.commandinteractionclass");
MAXON_REGISTRY(CommandDescriptionClass, CommandDescription, "net.maxon.command.registry.commanddescriptionclass");
MAXON_REGISTRY(CommandConversionClass, CommandConversionClasses, "net.maxon.command.registry.commandconversionclasses");

namespace CommandDataClasses
{
	MAXON_DECLARATION(CommandDataClasses::EntryType, BASE, "net.maxon.commanddata.base");
}

#include "commandbase2.hxx"

} // namespace maxon

#endif // COMMANDBASE_H__
