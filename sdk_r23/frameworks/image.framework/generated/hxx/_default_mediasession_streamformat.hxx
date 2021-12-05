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
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const MediaStreamRef& withStream)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
