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
		return HXXRET3(NULLIMPL, const Url&);
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
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int64> GetPosition() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool SeekSupported() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<void> Seek(Int64 position)
	{
		return HXXRET1(NULLIMPL);
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
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int> ReadEOS(const Block<Byte>& data)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Skip(Int64 bytes)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyOutputStreamImpl : public maxon::Component<MyOutputStreamImpl, OutputStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Write(const Block<const Byte>& data)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyInOutputStreamImpl : public maxon::Component<MyInOutputStreamImpl, InOutputStreamInterface>
{
	MAXON_COMPONENT();

public:
};
