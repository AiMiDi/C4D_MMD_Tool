// This file contains default implementations for the interfaces of ioarchivehandler.h. They are intended for copy&paste usage only.

class MyReadArchiveImpl : public maxon::Component<MyReadArchiveImpl, ReadArchiveInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Open(const Url& inputFile, const String& password)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyWriteArchiveImpl : public maxon::Component<MyWriteArchiveImpl, WriteArchiveInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Open(const Url& inputFile, Bool append, const String& password)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetCompressionLevel(Int compressionLevel)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetCompressionLevel() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> WriteFile(const Block<const Byte>& data)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> CloseFile()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
