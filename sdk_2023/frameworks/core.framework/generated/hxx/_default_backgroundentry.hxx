// This file contains default implementations for the interfaces of backgroundentry.h. They are intended for copy&paste usage only.

class MyBackgroundEntryImpl : public maxon::Component<MyBackgroundEntryImpl, BackgroundEntryInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String GetName() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD UniversalDateTime GetStartTime() const
	{
		return maxon::PrivateIncompleteNullReturnValue<UniversalDateTime>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD TimeValue GetDuration() const
	{
		return maxon::PrivateIncompleteNullReturnValue<TimeValue>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD STATE GetState()
	{
		return maxon::PrivateIncompleteNullReturnValue<STATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<Bool> GetStates(const ValueReceiver<STATE, const String&>& state) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetStateCount() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> AddState(STATE state, const String& message)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyBackgroundProgressImpl : public maxon::Component<MyBackgroundProgressImpl, BackgroundProgressInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Bool> GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetActiveCount() const
	{
		return 0;
	}

	MAXON_METHOD Result<Bool> GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetHistoryCount() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> ClearHistory()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableStateChangedDelegate> ObservableStateChanged() const
	{
		return maxon::ObservableRef<ObservableStateChangedDelegate>::NullValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> ObservableTotalProgressNotification() const
	{
		return maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>::NullValue();
	}

};
