// This file contains decorator implementations for the interfaces of ioarchivehandler.h. They are intended for copy&paste usage only.

class ReadArchiveDecoratorImpl : public maxon::Component<ReadArchiveDecoratorImpl, ReadArchiveInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Open(const Url& inputFile, const String& password)
	{
		return maxon::Cast<ReadArchiveRef>(self.GetDecoratedObject()).Open(inputFile, password);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::Cast<ReadArchiveRef>(self.GetDecoratedObject()).Close();
	}

	MAXON_METHOD Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	{
		return maxon::Cast<ReadArchiveRef>(self.GetDecoratedObject()).ExtractSingleFile(archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
	}

	MAXON_METHOD Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	{
		return maxon::Cast<ReadArchiveRef>(self.GetDecoratedObject()).Extract(outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
	}

};

class WriteArchiveDecoratorImpl : public maxon::Component<WriteArchiveDecoratorImpl, WriteArchiveInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Open(const Url& inputFile, Bool append, const String& password)
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).Open(inputFile, append, password);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).Close();
	}

	MAXON_METHOD Result<void> SetCompressionLevel(Int compressionLevel)
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).SetCompressionLevel(compressionLevel);
	}

	MAXON_METHOD Int GetCompressionLevel() const
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).GetCompressionLevel();
	}

	MAXON_METHOD Result<void> CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes)
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).CreateDirectory(name, dateTime, fileAttributes);
	}

	MAXON_METHOD Result<void> CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc)
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).CreateFile(name, dateTime, method, fileAttributes, cryptCrc);
	}

	MAXON_METHOD Result<void> WriteFile(const Block<const Byte>& data)
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).WriteFile(data);
	}

	MAXON_METHOD Result<void> CloseFile()
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).CloseFile();
	}

	MAXON_METHOD Result<void> CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask)
	{
		return maxon::Cast<WriteArchiveRef>(self.GetDecoratedObject()).CopyFile(fn, str, fileAttributes, fileAttributesMask);
	}

};
