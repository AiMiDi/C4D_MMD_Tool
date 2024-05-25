// This file contains default implementations for the interfaces of progress.h. They are intended for copy&paste usage only.

class MyProgressImpl : public maxon::Component<MyProgressImpl, ProgressInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int> AddProgressJob(Float jobWeight, const String& jobName)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Float> GetProgress(Int jobIndex)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Float GetTotalWeight() const
	{
		return 0;
	}

	MAXON_METHOD maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification(Bool create) const
	{
		return maxon::ObservableRef<ObservableProgressNotificationDelegate>::DefaultValue();
	}

	MAXON_METHOD Result<Tuple<TimeValue, TimeValue>> GetTime() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD String GetDetailsText() const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD void SetDetailsText(const String& details)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool SupportsCancelJob() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> CancelJob()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool IsCancelled()
	{
		return maxon::PrivateLogNullptrError(false);
	}

};
