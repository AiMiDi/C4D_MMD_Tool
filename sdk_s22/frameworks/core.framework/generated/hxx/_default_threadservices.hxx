// This file contains default implementations for the interfaces of threadservices.h. They are intended for copy&paste usage only.

class MyThreadCancelledErrorImpl : public maxon::Component<MyThreadCancelledErrorImpl, ThreadCancelledErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyJobErrorImpl : public maxon::Component<MyJobErrorImpl, JobErrorInterface>
{
	MAXON_COMPONENT();

public:
};
