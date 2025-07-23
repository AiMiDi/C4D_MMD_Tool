// This file contains decorator implementations for the interfaces of mediasession_streamformat.h. They are intended for copy&paste usage only.

class MediaStreamFormatDecoratorImpl : public maxon::Component<MediaStreamFormatDecoratorImpl, MediaStreamFormatInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class MediaStreamPropertiesDecoratorImpl : public maxon::Component<MediaStreamPropertiesDecoratorImpl, MediaStreamPropertiesInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const MediaStreamFormat& withFormat)
	{
		return maxon::Cast<MediaStreamProperties>(self.GetDecoratedObject()).Init(withFormat);
	}

	MAXON_METHOD Result<void> Init(const MediaStreamRef& withStream)
	{
		return maxon::Cast<MediaStreamProperties>(self.GetDecoratedObject()).Init(withStream);
	}

};
