// This file contains decorator implementations for the interfaces of iobrowse.h. They are intended for copy&paste usage only.

class IoBrowseDecoratorImpl : public maxon::Component<IoBrowseDecoratorImpl, IoBrowseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags)
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).Init(connection, flags);
	}

	MAXON_METHOD const Url& GetBasePath() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).GetBasePath();
	}

	MAXON_METHOD Result<void> Reset()
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).Reset();
	}

	MAXON_METHOD Result<void> GetNext()
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).GetNext();
	}

	MAXON_METHOD Bool HasEntry() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).HasEntry();
	}

	MAXON_METHOD Url GetCurrentPath() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).GetCurrentPath();
	}

	MAXON_METHOD IOBROWSEFLAGS IoGetFlags() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).IoGetFlags();
	}

	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).IoGetAttributes();
	}

	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).IoGetTime(mode);
	}

	MAXON_METHOD Int64 GetSize() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).GetSize();
	}

	MAXON_METHOD String GetExtraData() const
	{
		return maxon::Cast<IoBrowseRef>(self.GetDecoratedObject()).GetExtraData();
	}

};
