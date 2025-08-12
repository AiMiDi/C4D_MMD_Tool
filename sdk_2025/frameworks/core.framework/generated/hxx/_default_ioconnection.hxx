// This file contains default implementations for the interfaces of ioconnection.h. They are intended for copy&paste usage only.

class MyIoConnectionImpl : public maxon::Component<MyIoConnectionImpl, IoConnectionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Url& GetUrl() const
	{
		return HXXRET3(NULLIMPL, const Url&);
	}

	MAXON_METHOD Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int64> GetContentLength()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD IODETECT IoDetect() const
	{
		return HXXRET3(NULLIMPL, IODETECT);
	}

	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoDelete(Bool force)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoMove(const Url& destName)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoRename(const Url& newName)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const
	{
		return HXXRET1(NULLIMPL);
	}

};
