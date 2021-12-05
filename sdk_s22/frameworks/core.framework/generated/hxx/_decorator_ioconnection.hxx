// This file contains decorator implementations for the interfaces of ioconnection.h. They are intended for copy&paste usage only.

class IoConnectionDecoratorImpl : public maxon::Component<IoConnectionDecoratorImpl, IoConnectionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).GetUrl();
	}

	MAXON_METHOD Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).GetBrowseIterator(flags);
	}

	MAXON_METHOD Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).OpenInputStream(flags);
	}

	MAXON_METHOD Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).OpenOutputStream(flags);
	}

	MAXON_METHOD Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).OpenInOutputStream(flags);
	}

	MAXON_METHOD Result<Int64> GetContentLength()
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).GetContentLength();
	}

	MAXON_METHOD IODETECT IoDetect() const
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoDetect();
	}

	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoGetAttributes();
	}

	MAXON_METHOD Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoSetAttributes(flags, mask);
	}

	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoGetTime(mode);
	}

	MAXON_METHOD Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoSetTime(mode, dateTime);
	}

	MAXON_METHOD Result<void> IoDelete(Bool force)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoDelete(force);
	}

	MAXON_METHOD Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoCreateDirectory(createParents, createdDirs);
	}

	MAXON_METHOD Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoCopyFile(destName, overwrite, removeReadOnly);
	}

	MAXON_METHOD Result<void> IoMove(const Url& destName)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoMove(destName);
	}

	MAXON_METHOD Result<void> IoRename(const Url& newName)
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoRename(newName);
	}

	MAXON_METHOD Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoGetFreeVolumeSpace(availableBytes, totalBytes);
	}

	MAXON_METHOD Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const
	{
		return maxon::Cast<IoConnectionRef>(self.GetDecoratedObject()).IoShowInOS(flags);
	}

};
