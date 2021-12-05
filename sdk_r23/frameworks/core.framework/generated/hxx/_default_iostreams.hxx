// This file contains default implementations for the interfaces of iostreams.h. They are intended for copy&paste usage only.

class MyIoErrorImpl : public maxon::Component<MyIoErrorImpl, IoErrorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void SetUrl(const Url& url)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyFileFormatErrorImpl : public maxon::Component<MyFileFormatErrorImpl, FileFormatErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnknownFileSizeErrorImpl : public maxon::Component<MyUnknownFileSizeErrorImpl, UnknownFileSizeErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyBaseStreamImpl : public maxon::Component<MyBaseStreamImpl, BaseStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Int64> GetStreamLength() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Int64> GetPosition() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool SeekSupported() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<void> Seek(Int64 position)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void DisableBuffering()
	{
		return maxon::PrivateLogNullptrError();
	}

};

class MyInputStreamImpl : public maxon::Component<MyInputStreamImpl, InputStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Int64> BytesAvailable() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Int> ReadEOS(const Block<Byte>& data)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Skip(Int64 bytes)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyOutputStreamImpl : public maxon::Component<MyOutputStreamImpl, OutputStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Write(const Block<const Byte>& data)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyInOutputStreamImpl : public maxon::Component<MyInOutputStreamImpl, InOutputStreamInterface>
{
	MAXON_COMPONENT();

public:
};
