// This file contains decorator implementations for the interfaces of iostream_dualinoutput.h. They are intended for copy&paste usage only.

class IoDualInOutputStreamDecoratorImpl : public maxon::Component<IoDualInOutputStreamDecoratorImpl, IoDualInOutputStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetInputStream(const InputStreamRef& inputStream)
	{
		return maxon::Cast<IoDualInOutputStreamRef>(self.GetDecoratedObject()).SetInputStream(inputStream);
	}

	MAXON_METHOD Result<void> SetOutputStream(const OutputStreamRef& outputStream)
	{
		return maxon::Cast<IoDualInOutputStreamRef>(self.GetDecoratedObject()).SetOutputStream(outputStream);
	}

	MAXON_METHOD InputStreamRef GetInputStream() const
	{
		return maxon::Cast<IoDualInOutputStreamRef>(self.GetDecoratedObject()).GetInputStream();
	}

	MAXON_METHOD OutputStreamRef GetOutputStream() const
	{
		return maxon::Cast<IoDualInOutputStreamRef>(self.GetDecoratedObject()).GetOutputStream();
	}

};
