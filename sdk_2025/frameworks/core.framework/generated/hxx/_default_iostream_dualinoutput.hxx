// This file contains default implementations for the interfaces of iostream_dualinoutput.h. They are intended for copy&paste usage only.

class MyIoDualInOutputStreamImpl : public maxon::Component<MyIoDualInOutputStreamImpl, IoDualInOutputStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetInputStream(const InputStreamRef& inputStream)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> SetOutputStream(const OutputStreamRef& outputStream)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD InputStreamRef GetInputStream() const
	{
		return HXXRET3(NULLIMPL, InputStreamRef);
	}

	MAXON_METHOD OutputStreamRef GetOutputStream() const
	{
		return HXXRET3(NULLIMPL, OutputStreamRef);
	}

};
