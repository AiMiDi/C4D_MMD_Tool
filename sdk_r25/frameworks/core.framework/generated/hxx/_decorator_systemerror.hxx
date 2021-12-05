// This file contains decorator implementations for the interfaces of systemerror.h. They are intended for copy&paste usage only.

class SystemErrorDecoratorImpl : public maxon::Component<SystemErrorDecoratorImpl, SystemErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class NSSystemErrorDecoratorImpl : public maxon::Component<NSSystemErrorDecoratorImpl, NSSystemErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void SetNSError(NSError* osError)
	{
		return maxon::Cast<NSSystemError>(self.GetDecoratedObject()).SetNSError(osError);
	}

	MAXON_METHOD NSError* GetNSError() const
	{
		return maxon::Cast<NSSystemError>(self.GetDecoratedObject()).GetNSError();
	}

};
