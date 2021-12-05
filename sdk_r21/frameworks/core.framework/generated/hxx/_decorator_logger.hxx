// This file contains decorator implementations for the interfaces of logger.h. They are intended for copy&paste usage only.

class LoggerTypeDecoratorImpl : public maxon::Component<LoggerTypeDecoratorImpl, LoggerTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level)
	{
		return maxon::Cast<LoggerTypeRef>(self.GetDecoratedObject()).Write(str, loc, level);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return maxon::Cast<LoggerTypeRef>(self.GetDecoratedObject()).Flush();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableLoggerNotifyDelegate> ObservableLoggerNotify() const
	{
		return maxon::Cast<LoggerTypeRef>(self.GetDecoratedObject()).ObservableLoggerNotify();
	}

};

class FileLoggerTypeDecoratorImpl : public maxon::Component<FileLoggerTypeDecoratorImpl, FileLoggerTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& url)
	{
		return maxon::Cast<FileLoggerTypeRef>(self.GetDecoratedObject()).Init(url);
	}

	MAXON_METHOD Url GetUrl() const
	{
		return maxon::Cast<FileLoggerTypeRef>(self.GetDecoratedObject()).GetUrl();
	}

};

class UserLoggerTypeDecoratorImpl : public maxon::Component<UserLoggerTypeDecoratorImpl, UserLoggerTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback)
	{
		return maxon::Cast<UserLoggerTypeRef>(self.GetDecoratedObject()).Iterate(callback);
	}

	MAXON_METHOD Int GetCount()
	{
		return maxon::Cast<UserLoggerTypeRef>(self.GetDecoratedObject()).GetCount();
	}

	MAXON_METHOD void Reset()
	{
		return maxon::Cast<UserLoggerTypeRef>(self.GetDecoratedObject()).Reset();
	}

};
