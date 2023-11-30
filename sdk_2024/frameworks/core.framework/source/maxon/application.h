#ifndef APPLICATION_H__
#define APPLICATION_H__

#include "maxon/url.h"
#include "maxon/module.h"
#include "maxon/datadictionary.h"
#include "maxon/observable.h"


namespace maxon
{

/// @addtogroup SYSTEM System
/// @{

//----------------------------------------------------------------------------------------
/// Available subsystems (Windows only)
//----------------------------------------------------------------------------------------
enum class SUBSYSTEM
{
	UNDEFINED = 0,///< Undefined SUBSYSTEM
	CONSOLE = 1,	///< (\/%SUBSYSTEM:%CONSOLE)
	WINDOWS = 2		///< (\/%SUBSYSTEM:%WINDOWS)
} MAXON_ENUM_LIST(SUBSYSTEM, "net.maxon.datatype.enum.subsystem");

//----------------------------------------------------------------------------------------
/// Possible values for GetUrl() function.
//----------------------------------------------------------------------------------------
enum class APPLICATION_URLTYPE
{
	//----------------------------------------------------------------------------------------
	/// The directory where the executable/bundle is placed in.
	/// The executable name is not part of the Url.
	//----------------------------------------------------------------------------------------
	STARTUP_DIR,

	//----------------------------------------------------------------------------------------
	/// The Url of the executable (Windows / Linux) or bundle (OS X / iOS).
	//----------------------------------------------------------------------------------------
	APPLICATION,

	//----------------------------------------------------------------------------------------
	/// The Url of the inner executable.
	/// Under Windows / Linux this is identical to APPLICATION.
	/// Under OS X / iOS this is the Url inside the bundle.
	//----------------------------------------------------------------------------------------
	APP_EXECUTABLE,

	//----------------------------------------------------------------------------------------
	/// The directory where the core modules are placed in.
	//----------------------------------------------------------------------------------------
	CORELIBS_DIR,

	//----------------------------------------------------------------------------------------
	/// The directory where the resource is placed in.
	//----------------------------------------------------------------------------------------
	RESOURCE_DIR,

	//----------------------------------------------------------------------------------------
	/// Temporary directory where data can be read or written.
	/// The temporary directory is placed in various locations depending on the operating system.
	//----------------------------------------------------------------------------------------
	TEMP_DIR,

	//----------------------------------------------------------------------------------------
	/// Preferences directory.
	/// The preferences directory is based on the startup Url of the application. If the parent
	/// directory location is changed, the preferences Url will change as well.
	/// The preferences directory is placed in various locations depending on the operating system.
	//----------------------------------------------------------------------------------------
	PREFS_DIR,

	//----------------------------------------------------------------------------------------
	/// Global preferences directory.
	/// The global preferences Url is always in the same place for all applications on the
	/// same operating system.
	//----------------------------------------------------------------------------------------
	GLOBALPREFS_DIR,

	//----------------------------------------------------------------------------------------
	/// Users desktop directory.
	//----------------------------------------------------------------------------------------
	DESKTOP_DIR,

	//----------------------------------------------------------------------------------------
	/// Users Home directory.
	//----------------------------------------------------------------------------------------
	USER_HOME_DIR,

	//----------------------------------------------------------------------------------------
	/// Users documents directory.
	//----------------------------------------------------------------------------------------
	USER_DOCUMENTS_DIR,

	//----------------------------------------------------------------------------------------
	/// System application directory. This is where apps are installed by default (e.g. "C:\Program Files")
	//----------------------------------------------------------------------------------------
	SYSTEM_PROGRAMS_DIR,

	//----------------------------------------------------------------------------------------
	/// Current working directory.
	//----------------------------------------------------------------------------------------
	CURRENT_WORKING_DIR,

	//----------------------------------------------------------------------------------------
	/// Directory of the module that invoked this call.
	//----------------------------------------------------------------------------------------
	CURRENT_MODULE_DIR,

	//----------------------------------------------------------------------------------------
	/// Resource directory of the module that invoked this call.
	//----------------------------------------------------------------------------------------
	CURRENT_MODULE_RESOURCE_DIR,

	//----------------------------------------------------------------------------------------
	/// Library directory.
	//----------------------------------------------------------------------------------------
	LIBRARY_DIR,

	//----------------------------------------------------------------------------------------
	/// Same as PREFS_DIR but without being able to set the path in the config.
	/// Cineware AE plug-in generates a lite.cert file at this location.
	/// Used for placing and reading the Lite certification file.
	//----------------------------------------------------------------------------------------
	PREFS_DIR_STATIC
} MAXON_ENUM_LIST(APPLICATION_URLTYPE, "net.maxon.datatype.enum.application_urltype");

/// @see Application::SetApplicationMode().
//----------------------------------------------------------------------------------------
enum class APPLICATIONMODE
{
	DONTWAIT,			///< Stops the execution as soon as all initializations are done, used for command line mode.
	KEEPRUNNING,	///< Keeps the program running after all initializations.
	SHUTDOWN,			///< Quits the application and leave the main loop. Only working when APPLICATIONMODE::KEEPRUNNING was set before.
} MAXON_ENUM_LIST(APPLICATIONMODE, "net.maxon.datatype.enum.applicationmode");

enum class APPLICATIONFEATURE
{
	NONE = 0,								///< Default case
	COMMANDLINE = (1 << 0), ///< Application runs as headless command line version.
	LIBRARY = 		(1 << 1), ///< Frameworks are used by plugins or another host (Cineware, Redshift, ...)
	UI = 					(1 << 2), ///<  UI is enabled (if this is LIBRARY or COMMANDLINE)
} MAXON_ENUM_FLAGS(APPLICATIONFEATURE);

namespace APPMESSAGE
{
	namespace OPENFILES
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.appmessage.openfiles");
		MAXON_ATTRIBUTE(BaseArray<String>, ARGUMENTS, "net.maxon.appmessage.openfiles.arguments");
	}
	namespace OPENURLS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.appmessage.openurls");
		MAXON_ATTRIBUTE(BaseArray<Url>, ARGUMENTS, "net.maxon.appmessage.openurls.arguments");
	}
}

//----------------------------------------------------------------------------------------
/// Application wide functions.
/// Implement this interface to be able to link against the kernel library.
//----------------------------------------------------------------------------------------
class Application
{
	MAXON_INTERFACE_NONVIRTUAL(Application, MAXON_REFERENCE_STATIC, "net.maxon.interface.application");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the requested url.
	/// @param[in] urlType						Type of the url, see ::APPLICATION_URLTYPE.
	/// @return												Url containing the requested.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<Url> GetUrl(APPLICATION_URLTYPE urlType, const Char* maxonModuleID = MAXON_MODULE_ID)
	{
		return PrivateGetUrl(urlType, maxonModuleID, g_maxon);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a new unique url for a temporary file.
	/// A typical use for this is Url tempfile = Application::GetTempUrl(tempDirectory);
	/// @param[in] directory					Directory url where the temporary file should be created in.
	/// @return												Url pointing to the temporary file.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> GetTempUrl(const Url& directory);

	//----------------------------------------------------------------------------------------
	/// Returns all module paths configured through g_modulePath, g_additionalModulePath and user preferences.
	/// @return												Array containing all paths that are searched for modules.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Url>> GetModulePaths();

	//----------------------------------------------------------------------------------------
	/// Returns the number of command line arguments delivered to the app on startup.
	/// @return												Number of arguments to request via GetCommandLineArg().
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetCommandLineArgCount();

	//----------------------------------------------------------------------------------------
	/// Returns a command line argument.
	/// @param[in] idx								The index of the argument. (0 >= idx < GetCommandLineArgCount()).
	/// @return												The requested argument.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetCommandLineArg(Int idx);

	//----------------------------------------------------------------------------------------
	/// Returns information about the system and processor.
	/// See maxon::MACHINEINFO for DataDictionary properties.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD DataDictionary GetMachineInfo();

	//----------------------------------------------------------------------------------------
	/// Retrieves the current application mode.
	/// This mode defines the behavior after the startup is done.
	/// @return												The current application mode.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD APPLICATIONMODE GetApplicationMode();

	//----------------------------------------------------------------------------------------
	/// Sets a new application mode.
	/// This mode defines the behavior after the startup is done. Please note that it's only possible to raise the mode
	/// from APPLICATIONMODE::DONTWAIT to APPLICATIONMODE::KEEPRUNNING.
	/// @param[in] mode								The new mode to be set.
	/// @return												True if the function changed the mode successfully.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SetApplicationMode(APPLICATIONMODE mode);

	static MAXON_METHOD Bool GetFeature(APPLICATIONFEATURE feature);

	/// @param[in] feature						The feature to set or clear.
	/// @param[in] value							The value of the feature
	static MAXON_METHOD void SetFeature(APPLICATIONFEATURE feature, Bool value);

	//----------------------------------------------------------------------------------------
	/// Gets the version number and build ID.
	/// @param[out] version						The version number will be assigned to this value.
	/// @param[out] buildID						Variable that will hold the buildID.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetVersion(Int& version, String& buildID);

	//----------------------------------------------------------------------------------------
	/// Formats the Int version returned by GetVersion() into a string with the 2023 (and later) format
	/// @param[in] rawVersionNumber		The version to be formatted.
	/// @return												The formatted string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String FormatVersionString(Int rawVersionNumber);
	
#ifdef MAXON_TARGET_WINDOWS
	//----------------------------------------------------------------------------------------
	/// Get the subsystem of the application (Windows only)
	/// @return												The current subsystem of the current process
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD SUBSYSTEM GetWindowsSubsystem();
#endif

	//----------------------------------------------------------------------------------------
	/// ObservableDatabaseRegistrationChange after a database was added or removed to the system.
	/// This can be used to update editors.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<Bool>, ObservableApplicationMessage, (const Id& messageId, const DataDictionary& messageData), ObservableCombinerRunAllBoolUntilFalse);

	//----------------------------------------------------------------------------------------
	/// RegisterSystemUrlSchemeHandler description. Depending on the operating system you can specify if the current application is the receiving application (e.g. windows).
	/// OSX for instance handles this on it's own and the application is always the receiving application.
	/// @param[in] urlScheme					Url scheme to register e.g. "c4d" to open all urls starting with "c4d://"
	/// @param[in] reassignApplication True if the application should be reassigned to the url scheme handler. False just register the handler in case the application is the receiving instance.
	/// @param[in] callback						Callback which is triggered if the url protocol handler receives the url
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterSystemUrlSchemeHandler(const Id& urlScheme, Bool reassignApplication, Delegate<void(const Url&)>&& callback);

	//----------------------------------------------------------------------------------------
	/// Check if the current application is assigned to the system url scheme handler for the given url scheme.
	/// @param[in] urlScheme					Url scheme to check e.g "c4d". 
	/// @return												True if the current application is the system url scheme handler for the given url scheme
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CheckSystemUrlSchemeHandlerIsCurrent(const Id& urlScheme);

protected:
	static MAXON_METHOD Result<Url> PrivateGetUrl(APPLICATION_URLTYPE urlType, const Char* maxonModuleID, const Binary& currentModule);
};

// include autogenerated headerfile here
#include "application1.hxx"
// include autogenerated headerfile here
#include "application2.hxx"

/// @}

} // namespace maxon

#endif // APPLICATION_H__
