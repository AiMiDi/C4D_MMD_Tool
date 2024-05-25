// This file contains default implementations for the interfaces of noise.h. They are intended for copy&paste usage only.

class MyRenderNoiseImpl : public maxon::Component<MyRenderNoiseImpl, RenderNoiseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Float32 Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const
	{
		return 0;
	}

	MAXON_METHOD Float32 Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const
	{
		return 0;
	}

};
