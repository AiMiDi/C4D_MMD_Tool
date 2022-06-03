// This file contains default implementations for the interfaces of logger.h. They are intended for copy&paste usage only.

class MyLoggerTypeImpl : public maxon::Component<MyLoggerTypeImpl, LoggerTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableLoggerNotifyDelegate> ObservableLoggerNotify() const
	{
		return maxon::ObservableRef<ObservableLoggerNotifyDelegate>::NullValue();
	}

};

class MyFileLoggerTypeImpl : public maxon::Component<MyFileLoggerTypeImpl, FileLoggerTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& url)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Url GetUrl() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyUserLoggerTypeImpl : public maxon::Component<MyUserLoggerTypeImpl, UserLoggerTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetCount()
	{
		return 0;
	}

	MAXON_METHOD void Reset()
	{
		return maxon::PrivateLogNullptrError();
	}

};
