#if 1
namespace maxon
{
	namespace enum24
	{
		enum class CONFIGURATION_CATEGORY
		{
			REGULAR					= 0,	///< Help will be shown when application is started with command line parameter help. Use this value for configuration variables that are relevant to an end-user.
			DEVELOPMENT			= 1,	///< Help will be shown when application is started with command line parameter help=dev. Use this value for configuration variables that are relevant to a developer.
			MODULE					= 2,	///< Help will be shown when application is started with command line parameter help=module. Don't use this for your own variables.
			EXTENSION				= 3,	///< Help will be shown when application is started with command line parameter help=extension. Don't use this for your own variables.
			IMPLEMENTATION	= 4,	///< Help will be shown when application is started with command line parameter help=impl. Don't use this for your own variables.
			NONE						= 5,	///< No help will be shown.
			SUBSCRIBER			= 6,	///< This entry jjust copies whatever setting has been assigned to the owner.
		} ;
		static const maxon::UInt64 CONFIGURATION_CATEGORY_values[] = {maxon::UInt64(enum24::CONFIGURATION_CATEGORY::REGULAR), maxon::UInt64(enum24::CONFIGURATION_CATEGORY::DEVELOPMENT), maxon::UInt64(enum24::CONFIGURATION_CATEGORY::MODULE), maxon::UInt64(enum24::CONFIGURATION_CATEGORY::EXTENSION), maxon::UInt64(enum24::CONFIGURATION_CATEGORY::IMPLEMENTATION), maxon::UInt64(enum24::CONFIGURATION_CATEGORY::NONE), maxon::UInt64(enum24::CONFIGURATION_CATEGORY::SUBSCRIBER)};
		static const maxon::EnumInfo CONFIGURATION_CATEGORY_info{"CONFIGURATION_CATEGORY", SIZEOF(CONFIGURATION_CATEGORY), false, "REGULAR\0DEVELOPMENT\0MODULE\0EXTENSION\0IMPLEMENTATION\0NONE\0SUBSCRIBER\0", CONFIGURATION_CATEGORY_values, std::extent<decltype(CONFIGURATION_CATEGORY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONFIGURATION_CATEGORY24(){ return enum24::CONFIGURATION_CATEGORY_info; }
	namespace enum33
	{
		enum class CONFIGURATIONENTRY_ORIGIN
		{
			APPLICATION		= 0,	///< Configuration value was defined by the application itself
			CONFIGURATION = 1,	///< Configuration value originated from a configuration file
			ENVIRONMENT		= 2,	///< Configuration value originated from an environment variable
			COMMANDLINE		= 3		///< Configuration value originated from a command line parameter
		} ;
		static const maxon::UInt64 CONFIGURATIONENTRY_ORIGIN_values[] = {maxon::UInt64(enum33::CONFIGURATIONENTRY_ORIGIN::APPLICATION), maxon::UInt64(enum33::CONFIGURATIONENTRY_ORIGIN::CONFIGURATION), maxon::UInt64(enum33::CONFIGURATIONENTRY_ORIGIN::ENVIRONMENT), maxon::UInt64(enum33::CONFIGURATIONENTRY_ORIGIN::COMMANDLINE)};
		static const maxon::EnumInfo CONFIGURATIONENTRY_ORIGIN_info{"CONFIGURATIONENTRY_ORIGIN", SIZEOF(CONFIGURATIONENTRY_ORIGIN), false, "APPLICATION\0CONFIGURATION\0ENVIRONMENT\0COMMANDLINE\0", CONFIGURATIONENTRY_ORIGIN_values, std::extent<decltype(CONFIGURATIONENTRY_ORIGIN_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONFIGURATIONENTRY_ORIGIN33(){ return enum33::CONFIGURATIONENTRY_ORIGIN_info; }
	namespace enum42
	{
		enum class CONFIGURATIONENTRY_STATE
		{
			UNUSED					 = 0,	///< Configuration value was not used by or known to the application. This is e.g. true for environment variables that the application cannot process.
			INVALIDARGUMENT = 1,	///< Configuration value was recognized by the application, but argument was invalid.
			USED						 = 2,	///< Configuration value was recognized and successfully used by the application.
			OUTOFRANGE			 = 3	///< Configuration value was recognized by the application, but argument was out of range. The value has been clamped and is now valid.
		} ;
		static const maxon::UInt64 CONFIGURATIONENTRY_STATE_values[] = {maxon::UInt64(enum42::CONFIGURATIONENTRY_STATE::UNUSED), maxon::UInt64(enum42::CONFIGURATIONENTRY_STATE::INVALIDARGUMENT), maxon::UInt64(enum42::CONFIGURATIONENTRY_STATE::USED), maxon::UInt64(enum42::CONFIGURATIONENTRY_STATE::OUTOFRANGE)};
		static const maxon::EnumInfo CONFIGURATIONENTRY_STATE_info{"CONFIGURATIONENTRY_STATE", SIZEOF(CONFIGURATIONENTRY_STATE), false, "UNUSED\0INVALIDARGUMENT\0USED\0OUTOFRANGE\0", CONFIGURATIONENTRY_STATE_values, std::extent<decltype(CONFIGURATIONENTRY_STATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONFIGURATIONENTRY_STATE42(){ return enum42::CONFIGURATIONENTRY_STATE_info; }
/// @cond INTERNAL

/// @endcond

#ifdef __STANDALONEAPP
#else
#endif
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ConfigInit,, "net.maxon.datatype.configinit");
}
#endif
