// This file contains default implementations for the interfaces of fileformat_handler.h. They are intended for copy&paste usage only.

class MyFileFormatHandlerImpl : public maxon::Component<MyFileFormatHandlerImpl, FileFormatHandlerInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const FileFormat& GetFileFormat() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<DataType> GetHandlerType() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<ObjectRef> CreateHandler(const Url& url) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD FILEFORMAT_PRIORITY GetDependends() const
	{
		return maxon::PrivateIncompleteNullReturnValue<FILEFORMAT_PRIORITY>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
