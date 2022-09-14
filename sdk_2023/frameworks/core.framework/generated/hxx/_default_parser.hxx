// This file contains default implementations for the interfaces of parser.h. They are intended for copy&paste usage only.

class MyParserImpl : public maxon::Component<MyParserImpl, ParserInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD String GetFileExtension() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
