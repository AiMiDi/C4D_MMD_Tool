// This file contains default implementations for the interfaces of machine.h. They are intended for copy&paste usage only.

class MyMachineImpl : public maxon::Component<MyMachineImpl, MachineInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String GetUniqueId() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<DataDictionary> GetMachineInfo() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<ObjectRef> GetInterface(const Id& interfaceName)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD MACHINESTATE GetState() const
	{
		return maxon::PrivateIncompleteNullReturnValue<MACHINESTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableMessageReceivedDelegate> ObservableMessageReceived() const
	{
		return maxon::ObservableRef<ObservableMessageReceivedDelegate>::NullValue();
	}

};
