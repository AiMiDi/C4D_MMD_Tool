#include "maxon/stringencoding.h"


namespace maxon
{

const StringDecodingRef& GetUtf8DefaultDecoder()
{
	return StringDecodings::Utf8.IsInitialized() ? StringDecodings::Utf8() : StringDecodingRef::DefaultValue();
}

const StringEncodingRef& GetUtf8DefaultEncoder()
{
	return StringEncodings::Utf8.IsInitialized() ? StringEncodings::Utf8() : StringEncodingRef::DefaultValue();
}

}

