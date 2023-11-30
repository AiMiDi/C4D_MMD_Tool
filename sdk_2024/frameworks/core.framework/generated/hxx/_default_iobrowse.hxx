// This file contains default implementations for the interfaces of iobrowse.h. They are intended for copy&paste usage only.

class MyIoBrowseImpl : public maxon::Component<MyIoBrowseImpl, IoBrowseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const Url& GetBasePath() const
	{
		return HXXRET3(NULLIMPL, const Url&);
	}

	MAXON_METHOD Result<void> Reset()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> GetNext()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool HasEntry() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Url GetCurrentPath() const
	{
		return HXXRET3(NULLIMPL, Url);
	}

	MAXON_METHOD IOBROWSEFLAGS IoGetFlags() const
	{
		return HXXRET3(NULLIMPL, IOBROWSEFLAGS);
	}

	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Int64 GetSize() const
	{
		return 0;
	}

	MAXON_METHOD String GetExtraData() const
	{
		return HXXRET3(NULLIMPL, String);
	}

};
