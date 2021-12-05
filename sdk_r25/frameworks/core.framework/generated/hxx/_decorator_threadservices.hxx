// This file contains decorator implementations for the interfaces of threadservices.h. They are intended for copy&paste usage only.

class ThreadCancelledErrorDecoratorImpl : public maxon::Component<ThreadCancelledErrorDecoratorImpl, ThreadCancelledErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class JobErrorDecoratorImpl : public maxon::Component<JobErrorDecoratorImpl, JobErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};
