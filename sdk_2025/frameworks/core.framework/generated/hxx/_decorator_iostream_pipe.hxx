// This file contains decorator implementations for the interfaces of iostream_pipe.h. They are intended for copy&paste usage only.

class IoPipeInOutputStreamDecoratorImpl : public maxon::Component<IoPipeInOutputStreamDecoratorImpl, IoPipeInOutputStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD PIPEHANDLE GetReadHandle() const
	{
		return maxon::Cast<IoPipeInOutputStreamRef>(self.GetDecoratedObject()).GetReadHandle();
	}

	MAXON_METHOD PIPEHANDLE GetWriteHandle() const
	{
		return maxon::Cast<IoPipeInOutputStreamRef>(self.GetDecoratedObject()).GetWriteHandle();
	}

};
