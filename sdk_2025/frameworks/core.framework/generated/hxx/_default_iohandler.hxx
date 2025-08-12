// This file contains default implementations for the interfaces of iohandler.h. They are intended for copy&paste usage only.

class MyIoHandlerImpl : public maxon::Component<MyIoHandlerImpl, IoHandlerInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Id& GetUrlScheme() const
	{
		return HXXRET3(NULLIMPL, const Id&);
	}

	MAXON_METHOD Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<String> GetSystemPath(const UrlInterface& url) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const String& name) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> RemoveUrl(UrlInterface& url) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<IoConnectionRef> OpenConnection(const Url& name) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<String> ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const
	{
		return HXXRET1(NULLIMPL);
	}

};
