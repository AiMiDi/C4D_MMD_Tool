// This file contains default implementations for the interfaces of mediasession_progress.h. They are intended for copy&paste usage only.

class MyMediaSessionProgressImpl : public maxon::Component<MyMediaSessionProgressImpl, MediaSessionProgressInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Int> AddProgressJob(const Float jobWeight, const String& jobName)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Float> GetProgress(Int jobIndex)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification() const
	{
		return maxon::ObservableRef<ObservableProgressNotificationDelegate>::NullValue();
	}

	MAXON_METHOD Float GetTotalWeight() const
	{
		return 0;
	}

};
