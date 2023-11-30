// This file contains default implementations for the interfaces of ioarchivehandler.h. They are intended for copy&paste usage only.

class MyReadArchiveImpl : public maxon::Component<MyReadArchiveImpl, ReadArchiveInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Open(const Url& inputFile, const String& password)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyWriteArchiveImpl : public maxon::Component<MyWriteArchiveImpl, WriteArchiveInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Open(const Url& inputFile, Bool append, const String& password)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> SetCompressionLevel(Int compressionLevel)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Int GetCompressionLevel() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> WriteFile(const Block<const Byte>& data)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> CloseFile()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask)
	{
		return HXXRET1(NULLIMPL);
	}

};
