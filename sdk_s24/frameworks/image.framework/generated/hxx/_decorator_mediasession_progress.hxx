// This file contains decorator implementations for the interfaces of mediasession_progress.h. They are intended for copy&paste usage only.

class MediaSessionProgressDecoratorImpl : public maxon::Component<MediaSessionProgressDecoratorImpl, MediaSessionProgressInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
	{
		return maxon::Cast<MediaSessionProgressRef>(self.GetDecoratedObject()).InitProgress(delayFirstProgress, minProgressUpdate);
	}

	MAXON_METHOD Result<Int> AddProgressJob(const Float jobWeight, const String& jobName)
	{
		return maxon::Cast<MediaSessionProgressRef>(self.GetDecoratedObject()).AddProgressJob(jobWeight, jobName);
	}

	MAXON_METHOD Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
	{
		return maxon::Cast<MediaSessionProgressRef>(self.GetDecoratedObject()).SetProgressAndCheckBreak(jobIndex, percent);
	}

	MAXON_METHOD Result<Float> GetProgress(Int jobIndex)
	{
		return maxon::Cast<MediaSessionProgressRef>(self.GetDecoratedObject()).GetProgress(jobIndex);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification() const
	{
		return maxon::Cast<MediaSessionProgressRef>(self.GetDecoratedObject()).ObservableProgressNotification();
	}

	MAXON_METHOD Float GetTotalWeight() const
	{
		return maxon::Cast<MediaSessionProgressRef>(self.GetDecoratedObject()).GetTotalWeight();
	}

};
