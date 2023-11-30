// This file contains default implementations for the interfaces of observerobject.h. They are intended for copy&paste usage only.

class MyObserverObjectImpl : public maxon::Component<MyObserverObjectImpl, ObserverObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> AddSenderSignal(ObservableBaseInterface* observable)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD void RemoveSenderSignal(ObservableBaseInterface* observable)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD String GetName() const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD void SetName(const String& name)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD maxon::ObservableRef<ObserverDestroyedDelegate> ObserverDestroyed(Bool create) const
	{
		return maxon::ObservableRef<ObserverDestroyedDelegate>::DefaultValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverDisconnectNotify(Bool create) const
	{
		return maxon::ObservableRef<ObserverDisconnectNotifyDelegate>::DefaultValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverConnectNotify(Bool create) const
	{
		return maxon::ObservableRef<ObserverConnectNotifyDelegate>::DefaultValue();
	}

};
