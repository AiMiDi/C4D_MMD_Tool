// This file contains default implementations for the interfaces of settingsinterface.h. They are intended for copy&paste usage only.

class MySettingsImpl : public maxon::Component<MySettingsImpl, SettingsInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD ACCESSLEVEL GetAccessLevel() const
	{
		return HXXRET3(NULLIMPL, ACCESSLEVEL);
	}

	MAXON_METHOD SettingsRef GetParentSettings() const
	{
		return HXXRET3(NULLIMPL, SettingsRef);
	}

	MAXON_METHOD Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const
	{
		return HXXRET1(NULLIMPL);
	}

};
