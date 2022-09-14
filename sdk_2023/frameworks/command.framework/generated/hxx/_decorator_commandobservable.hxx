// This file contains decorator implementations for the interfaces of commandobservable.h. They are intended for copy&paste usage only.

class CommandObserverDecoratorImpl : public maxon::Component<CommandObserverDecoratorImpl, CommandObserverInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD maxon::ObservableRef<ObservableCommandStatusDelegate> ObservableCommandStatus() const
	{
		return maxon::Cast<CommandObserverRef>(self.GetDecoratedObject()).ObservableCommandStatus();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableCommandInvokedDelegate> ObservableCommandInvoked() const
	{
		return maxon::Cast<CommandObserverRef>(self.GetDecoratedObject()).ObservableCommandInvoked();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableCommandPrepareInfoDelegate> ObservableCommandPrepareInfo() const
	{
		return maxon::Cast<CommandObserverRef>(self.GetDecoratedObject()).ObservableCommandPrepareInfo();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableCommandInvokedInfoDelegate> ObservableCommandInvokedInfo() const
	{
		return maxon::Cast<CommandObserverRef>(self.GetDecoratedObject()).ObservableCommandInvokedInfo();
	}

};
