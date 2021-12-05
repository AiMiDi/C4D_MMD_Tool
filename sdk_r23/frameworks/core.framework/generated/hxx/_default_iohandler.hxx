// This file contains default implementations for the interfaces of iohandler.h. They are intended for copy&paste usage only.

class MyIoHandlerImpl : public maxon::Component<MyIoHandlerImpl, IoHandlerInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Id& GetUrlScheme() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<String> GetSystemPath(const UrlInterface& url) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const String& name) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> RemoveUrl(UrlInterface& url) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<IoConnectionRef> OpenConnection(const Url& name) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
