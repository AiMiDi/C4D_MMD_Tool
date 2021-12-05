// This file contains default implementations for the interfaces of ioconnection.h. They are intended for copy&paste usage only.

class MyIoConnectionImpl : public maxon::Component<MyIoConnectionImpl, IoConnectionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Int64> GetContentLength()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD IODETECT IoDetect() const
	{
		return maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoDelete(Bool force)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoMove(const Url& destName)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoRename(const Url& newName)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
