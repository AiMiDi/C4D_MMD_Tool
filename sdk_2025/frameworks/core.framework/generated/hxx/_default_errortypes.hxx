// This file contains default implementations for the interfaces of errortypes.h. They are intended for copy&paste usage only.

class MyUnsupportedArgumentErrorImpl : public maxon::Component<MyUnsupportedArgumentErrorImpl, UnsupportedArgumentErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnresolvedErrorImpl : public maxon::Component<MyUnresolvedErrorImpl, UnresolvedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnknownErrorImpl : public maxon::Component<MyUnknownErrorImpl, UnknownErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnsupportedOperationErrorImpl : public maxon::Component<MyUnsupportedOperationErrorImpl, UnsupportedOperationErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyShutdownErrorImpl : public maxon::Component<MyShutdownErrorImpl, ShutdownErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyDisabledErrorImpl : public maxon::Component<MyDisabledErrorImpl, DisabledErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyErrnoErrorImpl : public maxon::Component<MyErrnoErrorImpl, ErrnoErrorInterface>
{
	MAXON_COMPONENT();

public:
};
