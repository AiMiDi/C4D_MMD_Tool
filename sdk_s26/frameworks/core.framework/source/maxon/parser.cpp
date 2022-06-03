#include "maxon/parser.h"
#include "maxon/iomemory.h"

namespace maxon
{

Result<void> ParserInterface::ReadString(const Block<const Char>& parserData, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects)
{
	iferr_scope;
	IoMemoryRef memRef = IoMemoryRef::Create() iferr_return;
	memRef.PrepareReadBuffer(parserData, {}) iferr_return;
	Url memFileUrl = memRef.GetUrl() iferr_return;
	return Read(memFileUrl, flags, stringDecoding, objects);
}

Result<void> ParserInterface::ReadString(const String& text, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects)
{
	iferr_scope;
	BaseArray<Char> strarray = text.GetCString() iferr_return;
	return ReadString(strarray, flags, stringDecoding, objects);
}

}