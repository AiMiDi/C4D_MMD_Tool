// This file contains decorator implementations for the interfaces of progress.h. They are intended for copy&paste usage only.

class ProgressDecoratorImpl : public maxon::Component<ProgressDecoratorImpl, ProgressInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).InitProgress(delayFirstProgress, minProgressUpdate);
	}

	MAXON_METHOD Result<Int> AddProgressJob(Float jobWeight, const String& jobName)
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).AddProgressJob(jobWeight, jobName);
	}

	MAXON_METHOD Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).SetProgressAndCheckBreak(jobIndex, percent);
	}

	MAXON_METHOD Result<Float> GetProgress(Int jobIndex)
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).GetProgress(jobIndex);
	}

	MAXON_METHOD Float GetTotalWeight() const
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).GetTotalWeight();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification() const
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).ObservableProgressNotification();
	}

	MAXON_METHOD Result<Tuple<TimeValue, TimeValue>> GetTime() const
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).GetTime();
	}

	MAXON_METHOD String GetDetailsText() const
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).GetDetailsText();
	}

	MAXON_METHOD void SetDetailsText(const String& details)
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).SetDetailsText(details);
	}

	MAXON_METHOD Bool SupportsCancelJob() const
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).SupportsCancelJob();
	}

	MAXON_METHOD Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate)
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).SetCancelJobDelegate(std::forward<JobCancelDelegate>(cancelJobDelegate));
	}

	MAXON_METHOD Result<void> CancelJob()
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).CancelJob();
	}

	MAXON_METHOD Bool IsCancelled()
	{
		return maxon::Cast<ProgressRef>(self.GetDecoratedObject()).IsCancelled();
	}

};
