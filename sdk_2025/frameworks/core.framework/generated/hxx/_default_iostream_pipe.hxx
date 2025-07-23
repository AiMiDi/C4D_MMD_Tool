// This file contains default implementations for the interfaces of iostream_pipe.h. They are intended for copy&paste usage only.

class MyIoPipeInOutputStreamImpl : public maxon::Component<MyIoPipeInOutputStreamImpl, IoPipeInOutputStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD PIPEHANDLE GetReadHandle() const
	{
		return HXXRET3(NULLIMPL, PIPEHANDLE);
	}

	MAXON_METHOD PIPEHANDLE GetWriteHandle() const
	{
		return HXXRET3(NULLIMPL, PIPEHANDLE);
	}

};
