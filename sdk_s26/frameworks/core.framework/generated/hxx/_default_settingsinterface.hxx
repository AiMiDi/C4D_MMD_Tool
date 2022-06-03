// This file contains default implementations for the interfaces of settingsinterface.h. They are intended for copy&paste usage only.

class MySettingsImpl : public maxon::Component<MySettingsImpl, SettingsInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD ACCESSLEVEL GetAccessLevel() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ACCESSLEVEL>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD SettingsRef GetParentSettings() const
	{
		return maxon::PrivateIncompleteNullReturnValue<SettingsRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
