// This file contains default implementations for the interfaces of iobrowse.h. They are intended for copy&paste usage only.

class MyIoBrowseImpl : public maxon::Component<MyIoBrowseImpl, IoBrowseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD const Url& GetBasePath() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> Reset()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> GetNext()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool HasEntry() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Url GetCurrentPath() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD IOBROWSEFLAGS IoGetFlags() const
	{
		return maxon::PrivateIncompleteNullReturnValue<IOBROWSEFLAGS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int64 GetSize() const
	{
		return 0;
	}

	MAXON_METHOD String GetExtraData() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
