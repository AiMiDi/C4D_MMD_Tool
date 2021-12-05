#ifndef CONFIGURATION_H__
#define CONFIGURATION_H__

#include "maxon/module.h"
#include "maxon/datatype.h"

/// @file

namespace maxon
{

class String;

/// Help Category for configuration values
enum class CONFIGURATION_CATEGORY
{
	REGULAR					= 0,	///< Help will be shown when application is started with command line parameter help. Use this value for configuration variables that are relevant to an end-user.
	DEVELOPMENT			= 1,	///< Help will be shown when application is started with command line parameter help=dev. Use this value for configuration variables that are relevant to a developer.
	MODULE					= 2,	///< Help will be shown when application is started with command line parameter help=module. Don't use this for your own variables.
	EXTENSION				= 3,	///< Help will be shown when application is started with command line parameter help=extension. Don't use this for your own variables.
	IMPLEMENTATION	= 4,	///< Help will be shown when application is started with command line parameter help=impl. Don't use this for your own variables.
	NONE						= 5		///< No help will be shown.
} MAXON_ENUM_LIST(CONFIGURATION_CATEGORY);

/// Source where a configuration value was defined
enum class CONFIGURATIONENTRY_ORIGIN
{
	APPLICATION		= 0,	///< Configuration value was defined by the application itself
	CONFIGURATION = 1,	///< Configuration value originated from a configuration file
	ENVIRONMENT		= 2,	///< Configuration value originated from an environment variable
	COMMANDLINE		= 3		///< Configuration value originated from a command line parameter
} MAXON_ENUM_LIST(CONFIGURATIONENTRY_ORIGIN);

/// State of a configuration value
enum class CONFIGURATIONENTRY_STATE
{
	UNUSED					 = 0,	///< Configuration value was not used by or known to the application. This is e.g. true for environment variables that the application cannot process.
	INVALIDARGUMENT = 1,	///< Configuration value was recognized by the application, but argument was invalid.
	USED						 = 2,	///< Configuration value was recognized and successfully used by the application.
	OUTOFRANGE			 = 3	///< Configuration value was recognized by the application, but argument was out of range. The value has been clamped and is now valid.
} MAXON_ENUM_LIST(CONFIGURATIONENTRY_STATE);

/// @cond INTERNAL
struct ConfigInit
{
	const Char* key;
	const Char* helpText;

	CONFIGURATION_CATEGORY category;

	union
	{
		Bool*		bValue;
		Int*		iValue;
		Float*	fValue;
		String*	sValue;
	};

	enum
	{
		CONFIGURATION_DATATYPE_BOOL			= 0,
		CONFIGURATION_DATATYPE_INT			= 1,
		CONFIGURATION_DATATYPE_FLOAT		= 2,
		CONFIGURATION_DATATYPE_STRING_C	= 3,
		CONFIGURATION_DATATYPE_STRING		= 4
	} type;

	union
	{
		Float fMinValue;
		Int		minValue;
	};
	union
	{
		Float					 fMaxValue;
		Int						 maxValue;

		const wchar_t* defaultValue;
		const Char*		 defaultValueC;
	};
};

Bool ConfigurationRegisterBool(const Char* key, Bool& value, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* helpText);
Int ConfigurationRegisterInt(const Char* key, Int& value, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* helpText);
Float ConfigurationRegisterFloat(const Char* key, Float& value, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* helpText);
Bool ConfigurationRegisterString(const Char* key, String& value, const Char* defaultValue, CONFIGURATION_CATEGORY category, const Char* helpText);
Bool ConfigurationRegisterString(const Char* key, String& value, const wchar_t* defaultValue, CONFIGURATION_CATEGORY category, const Char* helpText);
/// @endcond

//----------------------------------------------------------------------------------------
/// @anchor ConfigValues
///
/// Use these macros to define a so called 'Configuration Variable'.
/// A global variable will be created under this name (CONFIGVALUE) that initially gets assigned the default (DEFVALUE).
/// However a user or programmer can override this default in a config file (e.g. config.txt), the environment or a command line.
/// A configuration file overrides the initial default, an environment variable the value of the configuration file and the command line the value of an environment variable.
/// The name in the configuration file, environment and command line is identical to the one defined here (CONFIGVALUE), but can be used in a case-insensitive way.
///
/// Please note that these macros must only be used in global space, otherwise they will crash.
///
/// The HELPTEXT will show up when the application is started with the command line argument 'help'.
/// DEVCATEGORY specifies in which category the variable falls.
//----------------------------------------------------------------------------------------
#define MAXON_CONFIGURATION_BOOL(CONFIGVALUE, DEFVALUE, DEVCATEGORY, HELPTEXT) maxon::Bool CONFIGVALUE = ConfigurationRegisterBool(# CONFIGVALUE, CONFIGVALUE, DEFVALUE, DEVCATEGORY, HELPTEXT)

/// @copydoc MAXON_CONFIGURATION_BOOL
#define MAXON_CONFIGURATION_INT(CONFIGVALUE, DEFVALUE, MINVALUE, MAXVALUE, DEVCATEGORY, HELPTEXT) maxon::Int CONFIGVALUE = ConfigurationRegisterInt(# CONFIGVALUE, CONFIGVALUE, DEFVALUE, MINVALUE, MAXVALUE, DEVCATEGORY, HELPTEXT)

/// @copydoc MAXON_CONFIGURATION_BOOL
#define MAXON_CONFIGURATION_FLOAT(CONFIGVALUE, DEFVALUE, MINVALUE, MAXVALUE, DEVCATEGORY, HELPTEXT) maxon::Float CONFIGVALUE = ConfigurationRegisterFloat(# CONFIGVALUE, CONFIGVALUE, DEFVALUE, MINVALUE, MAXVALUE, DEVCATEGORY, HELPTEXT)

/// @copydoc MAXON_CONFIGURATION_BOOL
#define MAXON_CONFIGURATION_STRING(CONFIGVALUE, DEFVALUE, DEVCATEGORY, HELPTEXT) maxon::String CONFIGVALUE = (ConfigurationRegisterString(# CONFIGVALUE, CONFIGVALUE, DEFVALUE, DEVCATEGORY, HELPTEXT) ? maxon::String() : maxon::String())

MAXON_DATATYPE(ConfigInit, "net.maxon.datatype.configinit");
MAXON_DEPENDENCY(configuration);

} // namespace maxon

#endif // CONFIGURATION_H__
