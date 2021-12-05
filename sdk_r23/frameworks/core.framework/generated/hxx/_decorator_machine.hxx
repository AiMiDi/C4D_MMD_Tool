// This file contains decorator implementations for the interfaces of machine.h. They are intended for copy&paste usage only.

class MachineDecoratorImpl : public maxon::Component<MachineDecoratorImpl, MachineInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String GetUniqueId() const
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).GetUniqueId();
	}

	MAXON_METHOD Result<DataDictionary> GetMachineInfo() const
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).GetMachineInfo();
	}

	MAXON_METHOD Result<ObjectRef> GetInterface(const Id& interfaceName)
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).GetInterface(interfaceName);
	}

	MAXON_METHOD MACHINESTATE GetState() const
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).GetState();
	}

	MAXON_METHOD Bool SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags)
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).SetState(stateMask, stateFlags);
	}

	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).ToString(formatStatement);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableMessageReceivedDelegate> ObservableMessageReceived() const
	{
		return maxon::Cast<MachineRef>(self.GetDecoratedObject()).ObservableMessageReceived();
	}

};
