// This file contains decorator implementations for the interfaces of noise.h. They are intended for copy&paste usage only.

class RenderNoiseDecoratorImpl : public maxon::Component<RenderNoiseDecoratorImpl, RenderNoiseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters)
	{
		return maxon::Cast<RenderNoiseRef>(self.GetDecoratedObject()).Init(seed, permutationTablePower, additionalParameters);
	}

	MAXON_METHOD Float32 Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const
	{
		return maxon::Cast<RenderNoiseRef>(self.GetDecoratedObject()).Noise(p, time, octaves, absolute, sampleRadius);
	}

	MAXON_METHOD Float32 Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const
	{
		return maxon::Cast<RenderNoiseRef>(self.GetDecoratedObject()).Noise(p, time, octaves, absolute, sampleRadius);
	}

};
