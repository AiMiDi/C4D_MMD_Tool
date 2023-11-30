// This file contains decorator implementations for the interfaces of parser.h. They are intended for copy&paste usage only.

class ParserDecoratorImpl : public maxon::Component<ParserDecoratorImpl, ParserInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken)
	{
		return maxon::Cast<ParserRef>(self.GetDecoratedObject()).Read(std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, objects, originalToken);
	}

	MAXON_METHOD Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting)
	{
		return maxon::Cast<ParserRef>(self.GetDecoratedObject()).Write(object, string, niceFormatting);
	}

	MAXON_METHOD Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting)
	{
		return maxon::Cast<ParserRef>(self.GetDecoratedObject()).WriteFile(std::forward<UrlOrOutputStream>(out), stringEncoding, dict, niceFormatting);
	}

	MAXON_METHOD String GetFileExtension() const
	{
		return maxon::Cast<ParserRef>(self.GetDecoratedObject()).GetFileExtension();
	}

};
