// This file contains default implementations for the interfaces of systemerror.h. They are intended for copy&paste usage only.

class MySystemErrorImpl : public maxon::Component<MySystemErrorImpl, SystemErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyNSSystemErrorImpl : public maxon::Component<MyNSSystemErrorImpl, NSSystemErrorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void SetNSError(NSError* osError)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD NSError* GetNSError() const
	{
		return nullptr;
	}

};
