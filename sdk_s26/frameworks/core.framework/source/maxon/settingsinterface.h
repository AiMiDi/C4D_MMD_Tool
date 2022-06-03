#ifndef SETTINGSINTERFACE_H__
#define SETTINGSINTERFACE_H__

#include "maxon/datadictionaryobject.h"
#include "maxon/observable.h"


namespace maxon
{

class SettingsRef;

enum class ACCESSLEVEL
{
	UNDEFINED = 0,		///< not defined, invalid setting.
	USERINSTALLATION, ///< settings for this users local installation.
	ACCOUNT,					///< settings for the currently logged-in user.
	USER,							///< settings for the current local user.
	MACHINE,					///< settings for all users of the current machine.
	DEFAULTS,					///< settings of the default value (needs to be initialized on startup)
	ALL,							///< start level of the search through all instances USERINSTALLATION -> ACCOUNT -> USER -> MACHINE -> DEFAULT
} MAXON_ENUM_LIST(ACCESSLEVEL);

//----------------------------------------------------------------------------------------
/// This namespace contains all attributes to be used with SettingsInterface to set and get preferences
//----------------------------------------------------------------------------------------
namespace APPSETTINGS
{
	class RESTRICT;
}

//----------------------------------------------------------------------------------------
/// Settings interface to store and load settings like preferences.
//----------------------------------------------------------------------------------------
class SettingsInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(SettingsInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.settingsinterface");

public:
	using RESTRICT_DICTIONARY_PROPS = APPSETTINGS::RESTRICT;

	//----------------------------------------------------------------------------------------
	/// GetAccessLevel returns the current level of this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ACCESSLEVEL GetAccessLevel() const;

	//----------------------------------------------------------------------------------------
	/// GetParentSettings returns the SettingsRef from which settings are inherited.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SettingsRef GetParentSettings() const;

	//----------------------------------------------------------------------------------------
	/// GetSettingsCopy returns a copy of all settings starting at the given level.
	/// @param[in] optionalList				Optional list of ids of interest. If empty, everything is returned.
	/// @param[in] accessLevel				Unused (for future extensions).
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel = ACCESSLEVEL::ALL) const;

	//----------------------------------------------------------------------------------------
	/// GetSettings returns all settings on the current access level (see order above ACCESSLEVEL).
	/// The settings contain all inherited settings from lower levels.
	/// @param[in] accessLevel				ACCESSLEVEL to ask for.
	/// @return                       SettingsRef on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD SettingsRef GetSettings(ACCESSLEVEL accessLevel = ACCESSLEVEL::ALL);

	MAXON_OBSERVABLE_STATIC(void, ObservableSettingsChanged, (const ACCESSLEVEL& accessLevel, const HashSet<Id>& changedProperties), ObservableCombinerRunAllComponent);
};

// include auto generated header file here
#include "settingsinterface1.hxx"
#include "settingsinterface2.hxx"

} // namespace maxon




#endif // SETTINGSINTERFACE_H__
