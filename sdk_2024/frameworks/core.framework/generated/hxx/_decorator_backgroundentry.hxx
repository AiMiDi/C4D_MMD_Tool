// This file contains decorator implementations for the interfaces of backgroundentry.h. They are intended for copy&paste usage only.

class BackgroundEntryDecoratorImpl : public maxon::Component<BackgroundEntryDecoratorImpl, BackgroundEntryInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String GetName() const
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).GetName();
	}

	MAXON_METHOD UniversalDateTime GetStartTime() const
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).GetStartTime();
	}

	MAXON_METHOD TimeValue GetDuration() const
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).GetDuration();
	}

	MAXON_METHOD STATE GetState()
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).GetState();
	}

	MAXON_METHOD Result<Bool> GetStates(const ValueReceiver<STATE, const String&>& state) const
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).GetStates(state);
	}

	MAXON_METHOD Int GetStateCount() const
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).GetStateCount();
	}

	MAXON_METHOD Result<void> AddState(STATE state, const String& message)
	{
		return maxon::Cast<BackgroundEntryRef>(self.GetDecoratedObject()).AddState(state, message);
	}

};

class BackgroundProgressDecoratorImpl : public maxon::Component<BackgroundProgressDecoratorImpl, BackgroundProgressInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory)
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).AddActiveEntry(title, sendToHistory);
	}

	MAXON_METHOD Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry)
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).RemoveActiveEntry(entry);
	}

	MAXON_METHOD Result<Bool> GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).GetActiveEntries(entry);
	}

	MAXON_METHOD Int GetActiveCount() const
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).GetActiveCount();
	}

	MAXON_METHOD Result<Bool> GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).GetHistoryEntries(entry);
	}

	MAXON_METHOD Int GetHistoryCount() const
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).GetHistoryCount();
	}

	MAXON_METHOD Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry)
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).RemoveHistoryEntry(entry);
	}

	MAXON_METHOD Result<void> ClearHistory()
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).ClearHistory();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableStateChangedDelegate> ObservableStateChanged(Bool create) const
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).ObservableStateChanged(create);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> ObservableTotalProgressNotification(Bool create) const
	{
		return maxon::Cast<BackgroundProgressRef>(self.GetDecoratedObject()).ObservableTotalProgressNotification(create);
	}

};
