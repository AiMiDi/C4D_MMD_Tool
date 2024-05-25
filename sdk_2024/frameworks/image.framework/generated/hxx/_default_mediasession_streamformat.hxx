// This file contains default implementations for the interfaces of mediasession_streamformat.h. They are intended for copy&paste usage only.

class MyMediaStreamFormatImpl : public maxon::Component<MyMediaStreamFormatImpl, MediaStreamFormatInterface>
{
	MAXON_COMPONENT();

public:
};

class MyMediaStreamPropertiesImpl : public maxon::Component<MyMediaStreamPropertiesImpl, MediaStreamPropertiesInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const MediaStreamFormat& withFormat)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const MediaStreamRef& withStream)
	{
		return HXXRET1(NULLIMPL);
	}

};
