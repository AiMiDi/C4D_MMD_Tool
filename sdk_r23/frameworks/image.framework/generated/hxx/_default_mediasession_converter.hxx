// This file contains default implementations for the interfaces of mediasession_converter.h. They are intended for copy&paste usage only.

class MyMediaConverterImpl : public maxon::Component<MyMediaConverterImpl, MediaConverterInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool SupportImportStrategy() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool SupportExportStrategy() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<BaseArray<MediaConverterRef>> GetInputConverter() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> AddOutputStream(const MediaStreamRef& stream)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> RemoveOutputStream(const MediaStreamRef& stream)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Close(const Block<const MediaConverterRef>& inputs)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyMediaConverterErrorImpl : public maxon::Component<MyMediaConverterErrorImpl, MediaConverterErrorInterface>
{
	MAXON_COMPONENT();

public:
};
