// This file contains decorator implementations for the interfaces of streamconversion.h. They are intended for copy&paste usage only.

class StreamConversionDecoratorImpl : public maxon::Component<StreamConversionDecoratorImpl, StreamConversionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Int GetBatchSize() const
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).GetBatchSize();
	}

	MAXON_METHOD Int GetBlockSize() const
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).GetBlockSize();
	}

	MAXON_METHOD Id GetCounterpart() const
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).GetCounterpart();
	}

	MAXON_METHOD const DataType& GetSourceType() const
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).GetSourceType();
	}

	MAXON_METHOD const DataType& GetDestinationType() const
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).GetDestinationType();
	}

	MAXON_METHOD Bool SupportInplaceConversion() const
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).SupportInplaceConversion();
	}

	MAXON_METHOD Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertImpl(src, dst, dstLimitHint, inputFinished, outputFinished);
	}

	MAXON_METHOD Result<InputStreamRef> ConvertToStream(const InputStreamRef& in)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToStream(in);
	}

	MAXON_METHOD Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToStream(in);
	}

	MAXON_METHOD Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToReader(in);
	}

	MAXON_METHOD Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToReader(in);
	}

	MAXON_METHOD Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToStream(out);
	}

	MAXON_METHOD Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToStream(out);
	}

	MAXON_METHOD Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToWriter(out);
	}

	MAXON_METHOD Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out)
	{
		return maxon::Cast<StreamConversionRef>(self.GetDecoratedObject()).ConvertToWriter(out);
	}

};
