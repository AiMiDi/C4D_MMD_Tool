#if 1
namespace maxon
{
	namespace enum23 { enum class CONFIGURATION_CATEGORY
	{
		REGULAR					= 0,	///< Help will be shown when application is started with command line parameter help. Use this value for configuration variables that are relevant to an end-user.
		DEVELOPMENT			= 1,	///< Help will be shown when application is started with command line parameter help=dev. Use this value for configuration variables that are relevant to a developer.
		MODULE					= 2,	///< Help will be shown when application is started with command line parameter help=module. Don't use this for your own variables.
		EXTENSION				= 3,	///< Help will be shown when application is started with command line parameter help=extension. Don't use this for your own variables.
		IMPLEMENTATION	= 4,	///< Help will be shown when application is started with command line parameter help=impl. Don't use this for your own variables.
		NONE						= 5		///< No help will be shown.
	} ; }
	maxon::String PrivateToString_CONFIGURATION_CATEGORY23(std::underlying_type<enum23::CONFIGURATION_CATEGORY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum23::CONFIGURATION_CATEGORY::REGULAR, (maxon::UInt64) enum23::CONFIGURATION_CATEGORY::DEVELOPMENT, (maxon::UInt64) enum23::CONFIGURATION_CATEGORY::MODULE, (maxon::UInt64) enum23::CONFIGURATION_CATEGORY::EXTENSION, (maxon::UInt64) enum23::CONFIGURATION_CATEGORY::IMPLEMENTATION, (maxon::UInt64) enum23::CONFIGURATION_CATEGORY::NONE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONFIGURATION_CATEGORY", SIZEOF(x), false, values, "REGULAR\0DEVELOPMENT\0MODULE\0EXTENSION\0IMPLEMENTATION\0NONE\0", fmt);
	}
	namespace enum32 { enum class CONFIGURATIONENTRY_ORIGIN
	{
		APPLICATION		= 0,	///< Configuration value was defined by the application itself
		CONFIGURATION = 1,	///< Configuration value originated from a configuration file
		ENVIRONMENT		= 2,	///< Configuration value originated from an environment variable
		COMMANDLINE		= 3		///< Configuration value originated from a command line parameter
	} ; }
	maxon::String PrivateToString_CONFIGURATIONENTRY_ORIGIN32(std::underlying_type<enum32::CONFIGURATIONENTRY_ORIGIN>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum32::CONFIGURATIONENTRY_ORIGIN::APPLICATION, (maxon::UInt64) enum32::CONFIGURATIONENTRY_ORIGIN::CONFIGURATION, (maxon::UInt64) enum32::CONFIGURATIONENTRY_ORIGIN::ENVIRONMENT, (maxon::UInt64) enum32::CONFIGURATIONENTRY_ORIGIN::COMMANDLINE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONFIGURATIONENTRY_ORIGIN", SIZEOF(x), false, values, "APPLICATION\0CONFIGURATION\0ENVIRONMENT\0COMMANDLINE\0", fmt);
	}
	namespace enum41 { enum class CONFIGURATIONENTRY_STATE
	{
		UNUSED					 = 0,	///< Configuration value was not used by or known to the application. This is e.g. true for environment variables that the application cannot process.
		INVALIDARGUMENT = 1,	///< Configuration value was recognized by the application, but argument was invalid.
		USED						 = 2,	///< Configuration value was recognized and successfully used by the application.
		OUTOFRANGE			 = 3	///< Configuration value was recognized by the application, but argument was out of range. The value has been clamped and is now valid.
	} ; }
	maxon::String PrivateToString_CONFIGURATIONENTRY_STATE41(std::underlying_type<enum41::CONFIGURATIONENTRY_STATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum41::CONFIGURATIONENTRY_STATE::UNUSED, (maxon::UInt64) enum41::CONFIGURATIONENTRY_STATE::INVALIDARGUMENT, (maxon::UInt64) enum41::CONFIGURATIONENTRY_STATE::USED, (maxon::UInt64) enum41::CONFIGURATIONENTRY_STATE::OUTOFRANGE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONFIGURATIONENTRY_STATE", SIZEOF(x), false, values, "UNUSED\0INVALIDARGUMENT\0USED\0OUTOFRANGE\0", fmt);
	}
/// @cond INTERNAL

/// @endcond

	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ConfigInit,, "net.maxon.datatype.configinit");
}
#endif
