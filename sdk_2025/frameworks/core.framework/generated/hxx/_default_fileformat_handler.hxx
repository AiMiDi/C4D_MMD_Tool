// This file contains default implementations for the interfaces of fileformat_handler.h. They are intended for copy&paste usage only.

class MyFileFormatHandlerImpl : public maxon::Component<MyFileFormatHandlerImpl, FileFormatHandlerInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const FileFormat& GetFileFormat() const
	{
		return HXXRET3(NULLIMPL, const FileFormat&);
	}

	MAXON_METHOD Result<DataType> GetHandlerType() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<ObjectRef> CreateHandler(const Url& url) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD FILEFORMAT_PRIORITY GetDependends() const
	{
		return HXXRET3(NULLIMPL, FILEFORMAT_PRIORITY);
	}

};
