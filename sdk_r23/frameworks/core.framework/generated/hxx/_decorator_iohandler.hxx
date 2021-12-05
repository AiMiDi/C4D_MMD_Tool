// This file contains decorator implementations for the interfaces of iohandler.h. They are intended for copy&paste usage only.

class IoHandlerDecoratorImpl : public maxon::Component<IoHandlerDecoratorImpl, IoHandlerInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Id& GetUrlScheme() const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).GetUrlScheme();
	}

	MAXON_METHOD Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).SetSystemPath(url, systemPath);
	}

	MAXON_METHOD Result<String> GetSystemPath(const UrlInterface& url) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).GetSystemPath(url);
	}

	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const String& name) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).AppendUrl(url, name);
	}

	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).AppendUrl(url, relativeUrl);
	}

	MAXON_METHOD Result<void> RemoveUrl(UrlInterface& url) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).RemoveUrl(url);
	}

	MAXON_METHOD Result<IoConnectionRef> OpenConnection(const Url& name) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).OpenConnection(name);
	}

	MAXON_METHOD Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).Normalize(url, flags);
	}

	MAXON_METHOD Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const
	{
		return maxon::Cast<IoHandler>(self.GetDecoratedObject()).IoNormalize(url, flags);
	}

};
