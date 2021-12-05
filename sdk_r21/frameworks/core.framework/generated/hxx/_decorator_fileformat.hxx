// This file contains decorator implementations for the interfaces of fileformat.h. They are intended for copy&paste usage only.

class FileFormatDecoratorImpl : public maxon::Component<FileFormatDecoratorImpl, FileFormatInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Bool> Detect(const Url& url, const InputStreamRef& probeStream) const
	{
		return maxon::Cast<FileFormat>(self.GetDecoratedObject()).Detect(url, probeStream);
	}

};
