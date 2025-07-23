// This file contains default implementations for the interfaces of streamconversion.h. They are intended for copy&paste usage only.

class MyStreamConversionImpl : public maxon::Component<MyStreamConversionImpl, StreamConversionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Int GetBatchSize() const
	{
		return 0;
	}

	MAXON_METHOD Int GetBlockSize() const
	{
		return 0;
	}

	MAXON_METHOD Id GetCounterpart() const
	{
		return HXXRET3(NULLIMPL, Id);
	}

	MAXON_METHOD const DataType& GetSourceType() const
	{
		return HXXRET3(NULLIMPL, const DataType&);
	}

	MAXON_METHOD const DataType& GetDestinationType() const
	{
		return HXXRET3(NULLIMPL, const DataType&);
	}

	MAXON_METHOD Bool SupportInplaceConversion() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<InputStreamRef> ConvertToStream(const InputStreamRef& in)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out)
	{
		return HXXRET1(NULLIMPL);
	}

};
