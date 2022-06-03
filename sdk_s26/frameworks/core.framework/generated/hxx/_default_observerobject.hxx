// This file contains default implementations for the interfaces of observerobject.h. They are intended for copy&paste usage only.

class MyObserverObjectImpl : public maxon::Component<MyObserverObjectImpl, ObserverObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> AddSenderSignal(ObservableBaseInterface* observable)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void RemoveSenderSignal(ObservableBaseInterface* observable)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD String GetName() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void SetName(const String& name)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD maxon::ObservableRef<ObserverDestroyedDelegate> ObserverDestroyed() const
	{
		return maxon::ObservableRef<ObserverDestroyedDelegate>::NullValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverDisconnectNotify() const
	{
		return maxon::ObservableRef<ObserverDisconnectNotifyDelegate>::NullValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverConnectNotify() const
	{
		return maxon::ObservableRef<ObserverConnectNotifyDelegate>::NullValue();
	}

};
