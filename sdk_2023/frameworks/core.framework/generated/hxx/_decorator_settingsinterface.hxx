// This file contains decorator implementations for the interfaces of settingsinterface.h. They are intended for copy&paste usage only.

class SettingsDecoratorImpl : public maxon::Component<SettingsDecoratorImpl, SettingsInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD ACCESSLEVEL GetAccessLevel() const
	{
		return maxon::Cast<SettingsRef>(self.GetDecoratedObject()).GetAccessLevel();
	}

	MAXON_METHOD SettingsRef GetParentSettings() const
	{
		return maxon::Cast<SettingsRef>(self.GetDecoratedObject()).GetParentSettings();
	}

	MAXON_METHOD Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const
	{
		return maxon::Cast<SettingsRef>(self.GetDecoratedObject()).GetSettingsCopy(optionalList, accessLevel);
	}

};
