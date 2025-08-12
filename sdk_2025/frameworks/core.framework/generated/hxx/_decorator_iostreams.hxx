// This file contains decorator implementations for the interfaces of iostreams.h. They are intended for copy&paste usage only.

class IoErrorDecoratorImpl : public maxon::Component<IoErrorDecoratorImpl, IoErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void SetUrl(const Url& url)
	{
		return maxon::Cast<IoError>(self.GetDecoratedObject()).SetUrl(url);
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::Cast<IoError>(self.GetDecoratedObject()).GetUrl();
	}

};

class FileFormatErrorDecoratorImpl : public maxon::Component<FileFormatErrorDecoratorImpl, FileFormatErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnknownFileSizeErrorDecoratorImpl : public maxon::Component<UnknownFileSizeErrorDecoratorImpl, UnknownFileSizeErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class BaseStreamDecoratorImpl : public maxon::Component<BaseStreamDecoratorImpl, BaseStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Int64> GetStreamLength() const
	{
		return maxon::Cast<BaseStreamRef>(self.GetDecoratedObject()).GetStreamLength();
	}

	MAXON_METHOD Result<Int64> GetPosition() const
	{
		return maxon::Cast<BaseStreamRef>(self.GetDecoratedObject()).GetPosition();
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::Cast<BaseStreamRef>(self.GetDecoratedObject()).Close();
	}

	MAXON_METHOD Bool SeekSupported() const
	{
		return maxon::Cast<BaseStreamRef>(self.GetDecoratedObject()).SeekSupported();
	}

	MAXON_METHOD Result<void> Seek(Int64 position)
	{
		return maxon::Cast<BaseStreamRef>(self.GetDecoratedObject()).Seek(position);
	}

	MAXON_METHOD void DisableBuffering()
	{
		return maxon::Cast<BaseStreamRef>(self.GetDecoratedObject()).DisableBuffering();
	}

};

class InputStreamDecoratorImpl : public maxon::Component<InputStreamDecoratorImpl, InputStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Int64> BytesAvailable() const
	{
		return maxon::Cast<InputStreamRef>(self.GetDecoratedObject()).BytesAvailable();
	}

	MAXON_METHOD Result<Int> ReadEOS(const Block<Byte>& data)
	{
		return maxon::Cast<InputStreamRef>(self.GetDecoratedObject()).ReadEOS(data);
	}

	MAXON_METHOD Result<void> Skip(Int64 bytes)
	{
		return maxon::Cast<InputStreamRef>(self.GetDecoratedObject()).Skip(bytes);
	}

};

class OutputStreamDecoratorImpl : public maxon::Component<OutputStreamDecoratorImpl, OutputStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Write(const Block<const Byte>& data)
	{
		return maxon::Cast<OutputStreamRef>(self.GetDecoratedObject()).Write(data);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return maxon::Cast<OutputStreamRef>(self.GetDecoratedObject()).Flush();
	}

};

class InOutputStreamDecoratorImpl : public maxon::Component<InOutputStreamDecoratorImpl, InOutputStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};
