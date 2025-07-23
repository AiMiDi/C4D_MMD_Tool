// This file contains default implementations for the interfaces of mediasession_errors.h. They are intended for copy&paste usage only.

class MyMediaSessionWrongTypeErrorImpl : public maxon::Component<MyMediaSessionWrongTypeErrorImpl, MediaSessionWrongTypeErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyMediaStreamEOFErrorImpl : public maxon::Component<MyMediaStreamEOFErrorImpl, MediaStreamEOFErrorInterface>
{
	MAXON_COMPONENT();

public:
};
