// This file contains decorator implementations for the interfaces of mediasession_converter.h. They are intended for copy&paste usage only.

class MediaConverterDecoratorImpl : public maxon::Component<MediaConverterDecoratorImpl, MediaConverterInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool SupportImportStrategy() const
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).SupportImportStrategy();
	}

	MAXON_METHOD Bool SupportExportStrategy() const
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).SupportExportStrategy();
	}

	MAXON_METHOD Result<BaseArray<MediaConverterRef>> GetInputConverter() const
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).GetInputConverter();
	}

	MAXON_METHOD Result<void> AddOutputStream(const MediaStreamRef& stream)
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).AddOutputStream(stream);
	}

	MAXON_METHOD Result<void> RemoveOutputStream(const MediaStreamRef& stream)
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).RemoveOutputStream(stream);
	}

	MAXON_METHOD Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).GetOutputStreams(flattenChildren);
	}

	MAXON_METHOD Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).Analyze(inputs, targetTime, flags);
	}

	MAXON_METHOD Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).PrepareExecute(inputs, targetTime, flags);
	}

	MAXON_METHOD Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).Execute(inputs, targetTime, flags);
	}

	MAXON_METHOD Result<void> Close(const Block<const MediaConverterRef>& inputs)
	{
		return maxon::Cast<MediaConverterRef>(self.GetDecoratedObject()).Close(inputs);
	}

};

class MediaConverterErrorDecoratorImpl : public maxon::Component<MediaConverterErrorDecoratorImpl, MediaConverterErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};
