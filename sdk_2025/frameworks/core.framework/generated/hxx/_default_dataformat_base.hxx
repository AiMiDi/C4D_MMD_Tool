// This file contains default implementations for the interfaces of dataformat_base.h. They are intended for copy&paste usage only.

class MyDataFormatBaseReaderImpl : public maxon::Component<MyDataFormatBaseReaderImpl, DataFormatBaseReaderInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> CloseInput()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyDataFormatBaseWriterImpl : public maxon::Component<MyDataFormatBaseWriterImpl, DataFormatBaseWriterInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> CloseOutput()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> WriteData(const void* data, Int dataSize, Int elementCount)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return HXXRET1(NULLIMPL);
	}

};
