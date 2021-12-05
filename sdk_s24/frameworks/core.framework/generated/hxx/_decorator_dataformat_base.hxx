// This file contains decorator implementations for the interfaces of dataformat_base.h. They are intended for copy&paste usage only.

class DataFormatBaseReaderDecoratorImpl : public maxon::Component<DataFormatBaseReaderDecoratorImpl, DataFormatBaseReaderInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> CloseInput()
	{
		return maxon::Cast<DataFormatBaseReaderRef>(self.GetDecoratedObject()).CloseInput();
	}

	MAXON_METHOD Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount)
	{
		return maxon::Cast<DataFormatBaseReaderRef>(self.GetDecoratedObject()).ReadDataEOS(data, dataSize, elementCount);
	}

};

class DataFormatBaseWriterDecoratorImpl : public maxon::Component<DataFormatBaseWriterDecoratorImpl, DataFormatBaseWriterInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> CloseOutput()
	{
		return maxon::Cast<DataFormatBaseWriterRef>(self.GetDecoratedObject()).CloseOutput();
	}

	MAXON_METHOD Result<void> WriteData(const void* data, Int dataSize, Int elementCount)
	{
		return maxon::Cast<DataFormatBaseWriterRef>(self.GetDecoratedObject()).WriteData(data, dataSize, elementCount);
	}

	MAXON_METHOD Result<void> Flush()
	{
		return maxon::Cast<DataFormatBaseWriterRef>(self.GetDecoratedObject()).Flush();
	}

};
