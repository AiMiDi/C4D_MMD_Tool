// This file contains default implementations for the interfaces of machine.h. They are intended for copy&paste usage only.

class MyMachineImpl : public maxon::Component<MyMachineImpl, MachineInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String GetUniqueId() const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD Result<DataDictionary> GetMachineInfo() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<ObjectRef> GetInterface(const Id& interfaceName)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD MACHINESTATE GetState() const
	{
		return HXXRET3(NULLIMPL, MACHINESTATE);
	}

	MAXON_METHOD Bool SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate> ObservablePrivateSplashMessageReceived(Bool create) const
	{
		return maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>::DefaultValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableActivationChangedDelegate> ObservableActivationChanged(Bool create) const
	{
		return maxon::ObservableRef<ObservableActivationChangedDelegate>::DefaultValue();
	}

};
