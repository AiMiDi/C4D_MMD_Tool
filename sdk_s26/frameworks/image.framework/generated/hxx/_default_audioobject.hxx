// This file contains default implementations for the interfaces of audioobject.h. They are intended for copy&paste usage only.

class MyAudioObjectImpl : public maxon::Component<MyAudioObjectImpl, AudioObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return 0;
	}

	MAXON_METHOD Int GetBitsPerChannel() const
	{
		return 0;
	}

	MAXON_METHOD Float GetSampleRate() const
	{
		return 0;
	}

	MAXON_METHOD Int GetSampleCount() const
	{
		return 0;
	}

	MAXON_METHOD TimeValue GetLength() const
	{
		return maxon::PrivateIncompleteNullReturnValue<TimeValue>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Block<const Char> GetDataPtr() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Block<const Char>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
