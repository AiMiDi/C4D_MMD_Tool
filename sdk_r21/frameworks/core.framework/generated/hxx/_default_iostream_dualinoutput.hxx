// This file contains default implementations for the interfaces of iostream_dualinoutput.h. They are intended for copy&paste usage only.

class MyIoDualInOutputStreamImpl : public maxon::Component<MyIoDualInOutputStreamImpl, IoDualInOutputStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetInputStream(const InputStreamRef& inputStream)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetOutputStream(const OutputStreamRef& outputStream)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD InputStreamRef GetInputStream() const
	{
		return maxon::PrivateIncompleteNullReturnValue<InputStreamRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD OutputStreamRef GetOutputStream() const
	{
		return maxon::PrivateIncompleteNullReturnValue<OutputStreamRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
