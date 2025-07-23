// This file contains decorator implementations for the interfaces of fileformat_handler.h. They are intended for copy&paste usage only.

class FileFormatHandlerDecoratorImpl : public maxon::Component<FileFormatHandlerDecoratorImpl, FileFormatHandlerInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const FileFormat& GetFileFormat() const
	{
		return maxon::Cast<FileFormatHandler>(self.GetDecoratedObject()).GetFileFormat();
	}

	MAXON_METHOD Result<DataType> GetHandlerType() const
	{
		return maxon::Cast<FileFormatHandler>(self.GetDecoratedObject()).GetHandlerType();
	}

	MAXON_METHOD Result<ObjectRef> CreateHandler(const Url& url) const
	{
		return maxon::Cast<FileFormatHandler>(self.GetDecoratedObject()).CreateHandler(url);
	}

	MAXON_METHOD FILEFORMAT_PRIORITY GetDependends() const
	{
		return maxon::Cast<FileFormatHandler>(self.GetDecoratedObject()).GetDependends();
	}

};
