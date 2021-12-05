#ifndef COMMANDBASE_H__
#define COMMANDBASE_H__

#include "maxon/apibase.h"
#include "maxon/objectbase.h"
#include "maxon/interfacebase.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/delegate.h"

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
	ITERATE 	= 2,	///< Interaction iteration; performed several times after START (e.g. mouse drag).
	END 			= 3,	///< Interaction end (e.g. mouse released).
	REALTIME 	= 4		///< Real-time iterative interaction (e.g. cursor over viewport).
} MAXON_ENUM_LIST(INTERACTIONTYPE);

//----------------------------------------------------------------------------------------
/// Base command data interface as a simple data dictionary.
/// It contains all the data and necessary functions to executed and interact with commands.
//----------------------------------------------------------------------------------------
class CommandDataInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(CommandDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.command.interface.commanddata");
public:
	
	//----------------------------------------------------------------------------------------
	/// Invokes a command on this data.
	/// @param[in] command							The command ID.
	/// @param[in] interactive 					If true the command execution will be prepared with future interactivities. The ececuted command must implement CommandInteractionClassInterface.
	/// @return 												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive);
	
	//----------------------------------------------------------------------------------------
	/// Invokes a command on this data.
	/// @param[in] command							The command class.
	/// @param[in] interactive 					If true the command execution will be prepared with future interactivities. The executed command must implement CommandInteractionClassInterface.
	/// @return 												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive);
	
	//----------------------------------------------------------------------------------------
	/// Interact with the command result on this data. An interactive command must be called before this method is used.
	/// @param[in] interactionType 			Define the kind of interaction, see INTERACTIONTYPE.
	/// @return 												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<COMMANDRESULT> Interact(INTERACTIONTYPE interactionType);
};

//----------------------------------------------------------------------------------------
/// Legacy command data interface: a data dictionary which holds a pointer to generic data used to store legacy data types.
//----------------------------------------------------------------------------------------
class LegacyCommandDataInterface : MAXON_INTERFACE_BASES(CommandDataInterface)
{
	MAXON_INTERFACE(LegacyCommandDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.command.interface.legacycommanddata");

public:

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the legacy data.
	/// @return												A pointer to the legacy data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Generic*> GetLegacyData();

	//----------------------------------------------------------------------------------------
	/// Sets legacy data from a data pointer.
	/// @param[in] data								The legacy data pointer.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetLegacyData(const Generic* data);

	//----------------------------------------------------------------------------------------
	/// Gets a legacy data reference.
	/// @tparam LEGACYDATA						The data type that will be returned.
	/// @return												Reference to the legacy data.
	//----------------------------------------------------------------------------------------
	template<typename LEGACYDATA> MAXON_FUNCTION Result<LEGACYDATA&> GetLegacyData()
	{
		iferr_scope;
		Generic* res = GetLegacyData() iferr_return;
		return *reinterpret_cast<LEGACYDATA*>(res);
	}

	//----------------------------------------------------------------------------------------
	/// Sets legacy data from a data reference.
	/// @tparam LEGACYDATA						The type of legacy data.
	/// @param[in] data								The data.
	/// #return 											OK on success.
	//----------------------------------------------------------------------------------------
	template<typename LEGACYDATA> MAXON_FUNCTION Result<void> SetLegacyData(const LEGACYDATA& data)
	{
		const Generic* res = reinterpret_cast<const Generic*>(&data);
		return SetLegacyData(res);
	}
};

//----------------------------------------------------------------------------------------
/// Generic command interface.
//----------------------------------------------------------------------------------------
class CommandClassInterface : MAXON_INTERFACE_BASES(Object)
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
	/// @param[in,out] data				The command data.
	/// @return												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<COMMANDRESULT> Execute(CommandDataRef& data) const;
};

//----------------------------------------------------------------------------------------
/// Implements the command interactivity. Optional.
//----------------------------------------------------------------------------------------
class CommandInteractionClassInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(CommandInteractionClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.commandInteraction");

public:

	//----------------------------------------------------------------------------------------
	/// Executes the command interaction.
	/// @param[in,out] data						The command data.
	/// @param[in] interactionType		The interaction type.
	/// @return												The command result or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const;
};

//----------------------------------------------------------------------------------------
/// A legacy command interface that implements the ability to convert legacy data settings to regular settings.
//----------------------------------------------------------------------------------------
class LegacyCommandClassInterface : MAXON_INTERFACE_BASES(CommandClassInterface)
{
	MAXON_INTERFACE(LegacyCommandClassInterface, MAXON_REFERENCE_CONST, "net.maxon.command.interface.legacycommand");

public:

	//----------------------------------------------------------------------------------------
	/// Converts legacy settings (eg BaseContainer) to regular data parameters.
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
///	Generic command data parameters.
//----------------------------------------------------------------------------------------
namespace COMMAND
{
	MAXON_ATTRIBUTE(Bool, INTERACTIVE, "net.maxon.command.interactive", RESOURCE_DEFAULT(false)); 					///< True if the command is interactive. Owns the INTERACTIVE CALLBACK.
	MAXON_ATTRIBUTE(CommandClass, INTERACTIONCLASS, "net.maxon.command.interactionclass");									///< Optional command that can be used for interaction.
	// MAXON_ATTRIBUTE(Bool, NOSYNC, "net.maxon.command.nosync", RESOURCE_DEFAULT(false));											///< The command will not update the scene at the end of operation.
}

#include "commandbase1.hxx"

MAXON_REGISTRY(Class<CommandDataRef>, CommandDataClasses, "net.maxon.command.registry.commanddataclasses");
MAXON_REGISTRY(Class<LegacyCommandDataRef>, LegacyCommandDataClasses, "net.maxon.command.registry.legacycommanddataclasses");
MAXON_REGISTRY(CommandClass, CommandClasses, "net.maxon.command.registry.commandclasses");
MAXON_REGISTRY(LegacyCommandClass, LegacyCommand, "net.maxon.command.registry.legacycommandclass");
MAXON_REGISTRY(MigratedCommandClass, MigratedCommand, "net.maxon.command.registry.migratedcommandclass");
MAXON_REGISTRY(CommandInteractionClass, CommandInteraction, "net.maxon.command.registry.commandinteractionclass");

namespace CommandDataClasses
{
	MAXON_DECLARATION(CommandDataClasses::EntryType, BASE, "net.maxon.commanddata.base");
}

#include "commandbase2.hxx"

} // namespace maxon

#endif // COMMANDBASE_H__
