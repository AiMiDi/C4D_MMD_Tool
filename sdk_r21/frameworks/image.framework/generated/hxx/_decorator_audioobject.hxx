// This file contains decorator implementations for the interfaces of audioobject.h. They are intended for copy&paste usage only.

class AudioObjectDecoratorImpl : public maxon::Component<AudioObjectDecoratorImpl, AudioObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data)
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).Init(channelCount, bitsPerChannel, sampleRate, sampleCount, length, data);
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).GetChannelCount();
	}

	MAXON_METHOD Int GetBitsPerChannel() const
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).GetBitsPerChannel();
	}

	MAXON_METHOD Float GetSampleRate() const
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).GetSampleRate();
	}

	MAXON_METHOD Int GetSampleCount() const
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).GetSampleCount();
	}

	MAXON_METHOD TimeValue GetLength() const
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).GetLength();
	}

	MAXON_METHOD Block<const Char> GetDataPtr() const
	{
		return maxon::Cast<AudioObjectRef>(self.GetDecoratedObject()).GetDataPtr();
	}

};
