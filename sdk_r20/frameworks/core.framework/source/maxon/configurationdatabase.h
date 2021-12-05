#ifndef CONFIGURATIONDATABASE_H__
#define CONFIGURATIONDATABASE_H__

#include "maxon/configuration.h"
#include "maxon/interfacebase.h"
#include "maxon/objectbase.h"

/// @file

namespace maxon
{

class String;

//----------------------------------------------------------------------------------------
/// Configuration database functions.
//----------------------------------------------------------------------------------------
class Configuration
{
	MAXON_INTERFACE_NONVIRTUAL(Configuration, MAXON_REFERENCE_NONE, "net.maxon.interface.configuration");

public:
	//----------------------------------------------------------------------------------------
	/// Gets a boolean value from the configuration database.
	/// If an entry is present but its state is invalid the function will return false and set 'state' to CONFIGURATIONENTRY_STATE::INVALID.
	/// In that case you can use GetConfigurationDatabaseString to retrieve the text content of the entry.
	/// @param[in] key								Key that is searched in the database.
	/// @param[out] result						Value of the database entry if valid or false.
	/// @param[out] origin						Documents where the database entry was defined.
	/// @param[out] state							State of the database entry.
	/// @return												False if there is no entry in the database or its value is invalid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);

	//----------------------------------------------------------------------------------------
	/// Gets an integer value from the configuration database.
	/// If an entry is present but its state is invalid the function will return false and set 'state' to CONFIGURATIONENTRY_STATE::INVALID.
	/// In that case you can use GetConfigurationDatabaseString to retrieve the text content of the entry.
	/// @param[in] key								Key that is searched in the database.
	/// @param[out] result						Value of the database entry if valid or 0.
	/// @param[out] origin						Documents where the database entry was defined.
	/// @param[out] state							State of the database entry.
	/// @return												False if there is no entry in the database or its value is invalid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);

	//----------------------------------------------------------------------------------------
	/// Gets a floating point value from the configuration database.
	/// If an entry is present but its state is invalid the function will return false and set 'state' to CONFIGURATIONENTRY_STATE::INVALID.
	/// In that case you can use GetConfigurationDatabaseString to retrieve the text content of the entry.
	/// @param[in] key								Key that is searched in the database.
	/// @param[out] result						Value of the database entry if valid or 0.0.
	/// @param[out] origin						Documents where the database entry was defined.
	/// @param[out] state							State of the database entry.
	/// @return												False if there is no entry in the database or its value is invalid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);

	//----------------------------------------------------------------------------------------
	/// Gets a string value from the configuration database.
	/// This function can also be called on any boolean, integer or floating point types as all values are stored as strings in the database.
	/// @param[in] key								Key that is searched in the database.
	/// @param[out] result						Value of the database entry or an empty string if not present.
	/// @param[out] origin						Documents where the database entry was defined.
	/// @param[out] state							State of the database entry.
	/// @return												False if there is no entry in the database.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);

	//----------------------------------------------------------------------------------------
	/// Adds information to the help system (command line option 'help') and marks an entry in the configuration database as used (or invalid).
	/// This is necessary so that the application won't warn that a key is unknown.
	/// This routine must only be used for values created dynamically at runtime and not if a value was created by one of the MAXON_CONFIGURATION_XXX macros.
	/// @param[in] key								Key that is processed.
	/// @param[in] defaultValue				Default value that will show up in the help information.
	/// @param[in] category						The help category (should usually be set to either CONFIGURATION_CATEGORY::REGULAR or CONFIGURATION_CATEGORY::DEVELOPMENT).
	/// @param[in] help								Help text as a C string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help);

	//----------------------------------------------------------------------------------------
	/// Adds information to the help system (command line option 'help') and marks an entry in the configuration database as used (or invalid / out of range).
	/// This is necessary so that the application won't warn that a key is unknown.
	/// This routine must only be used for values created dynamically at runtime and not if a value was created by one of the MAXON_CONFIGURATION_XXX macros.
	/// @param[in] key								Key that is processed.
	/// @param[in] defaultValue				Default value that will show up in the help information.
	/// @param[in] minValue						The smallest allowed value.
	/// @param[in] maxValue						The largest allowed value.
	/// @param[in] category						The help category (should usually be set to either CONFIGURATION_CATEGORY::REGULAR or CONFIGURATION_CATEGORY::DEVELOPMENT).
	/// @param[in] help								Help text as a C string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help);

	//----------------------------------------------------------------------------------------
	/// Adds information to the help system (command line option 'help') and marks an entry in the configuration database as used (or invalid / out of range).
	/// This is necessary so that the application won't warn that a key is unknown.
	/// This routine must only be used for values created dynamically at runtime and not if a value was created by one of the MAXON_CONFIGURATION_XXX macros.
	/// @param[in] key								Key that is processed.
	/// @param[in] defaultValue				Default value that will show up in the help information.
	/// @param[in] minValue						The smallest allowed value.
	/// @param[in] maxValue						The largest allowed value.
	/// @param[in] category						The help category (should usually be set to either CONFIGURATION_CATEGORY::REGULAR or CONFIGURATION_CATEGORY::DEVELOPMENT).
	/// @param[in] help								Help text as a C string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help);

	//----------------------------------------------------------------------------------------
	/// Adds information to the help system (command line option 'help') and marks an entry in the configuration database as used (or invalid / out of range).
	/// This is necessary so that the application won't warn that a key is unknown.
	/// This routine must only be used for values created dynamically at runtime and not if a value was created by one of the MAXON_CONFIGURATION_XXX macros.
	/// @param[in] key								Key that is processed.
	/// @param[in] defaultValue				Default value that will show up in the help information.
	/// @param[in] category						The help category (should usually be set to either CONFIGURATION_CATEGORY::REGULAR or CONFIGURATION_CATEGORY::DEVELOPMENT).
	/// @param[in] help								Help text as a C string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help);

	//----------------------------------------------------------------------------------------
	/// Adds information to the help system (command line option 'help') and marks an entry in the configuration database as used if the passed option was set.
	/// This is necessary so that the application won't warn that a key is unknown.
	/// This routine must only be used for values created dynamically at runtime and not if a value was created by one of the MAXON_CONFIGURATION_XXX macros.
	/// Call this routine multiple times to add all available options. category and help should be the same for each call.
	/// Example: three calls with option set to "a", "b" and then "c" will create the help text description key=[a|b|c]
	/// @param[in] key								Key that is processed.
	/// @param[in] option							Option that the key is checked for.
	/// @param[in] isDefaultValue			Determines if the passed option is the default value.
	/// @param[in] caseSensitive			If true the corresponding entry in the database will only be flagged if the case-sensitive comparison is successful.
	/// @param[in] category						The help category (should usually be set to either CONFIGURATION_CATEGORY::REGULAR or CONFIGURATION_CATEGORY::DEVELOPMENT).
	/// @param[in] help								Help text as a C string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help);

	//----------------------------------------------------------------------------------------
	/// Copies a value into all modules that defined it. E.g. in case of a crash situation g_inCrashhandler can be set to true with this routine.
	/// @param[in] key								Case-Sensitive key that is processed.
	/// @param[in] value							Value to be set.
	/// @return												OK on success. A possible result value is IllegalArgumentError if the key did not exist.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> BroadcastBool(const String& key, Bool value);

	//----------------------------------------------------------------------------------------
	/// Copies a value into all modules that defined it. E.g. in case of a crash situation g_inCrashhandler can be set to true with this routine.
	/// @param[in] key								Case-Sensitive key that is processed.
	/// @param[in] value							Value to be set.
	/// @return												OK on success. A possible result value is IllegalArgumentError if the key did not exist.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> BroadcastInt(const String& key, Int value);

	//----------------------------------------------------------------------------------------
	/// Copies a value into all modules that defined it. E.g. in case of a crash situation g_inCrashhandler can be set to true with this routine.
	/// @param[in] key								Case-Sensitive key that is processed.
	/// @param[in] value							Value to be set.
	/// @return												OK on success. A possible result value is IllegalArgumentError if the key did not exist.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> BroadcastFloat(const String& key, Float value);

	//----------------------------------------------------------------------------------------
	/// Copies a value into all modules that defined it. E.g. in case of a crash situation g_inCrashhandler can be set to true with this routine.
	/// @param[in] key								Case-Sensitive key that is processed.
	/// @param[in] value							Value to be set.
	/// @return												OK on success. A possible result value is IllegalArgumentError if the key did not exist.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> BroadcastString(const String& key, const String& value);
};

// include autogenerated headerfile here
#include "configurationdatabase1.hxx"
// include autogenerated headerfile here
#include "configurationdatabase2.hxx"

} // namespace maxon

#endif // CONFIGURATIONDATABASE_H__
