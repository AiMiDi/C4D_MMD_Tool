#include "maxon/defaultallocator.h"
#include "maxon/mac_strings.h"
#include "maxon/string.h"
#include "maxon/basearray.h"
#include "maxon/errorbase.h"


namespace maxon
{

CFStringRef CreateCFString(const String& in)
{
	iferr (SysCharArray utf8 = in.GetSystemEncoding())
	{
		CriticalStop("String conversion failed: Not enough memory.");
		return nullptr;
	}

	CFStringRef cf = CFStringCreateWithCString(kCFAllocatorDefault, utf8.GetFirst(), kCFStringEncodingUTF8);

	if (MAXON_UNLIKELY(cf == nullptr))
		CriticalStop("String conversion failed: Check for invalid encoding.");

	return cf;
}

static CFStringRef CreateCFString(const CString& in)
{
	CFStringRef cf = CFStringCreateWithCString(kCFAllocatorDefault, (const char*)in, kCFStringEncodingUTF8);
	
	if (MAXON_UNLIKELY(cf == nullptr))
		CriticalStop("String conversion failed: Check for invalid encoding.");
	
	return cf;
}

CFAutoReference<CFStringRef> ToCFString(const String& in)
{
	return CreateCFString(in);
}

CFAutoReference<CFStringRef> ToCFString(const CString& in)
{
	return CreateCFString(in);
}

NSAutoReference<NSString> ToNSString(const String& in)
{
	return (NSString*) CreateCFString(in);
}

NSAutoReference<NSString> ToNSString(const CString& in)
{
	return (NSString*) CreateCFString(in);
}
	
String NSToString(const NSString* in)
{
	return CFToString((CFStringRef) in);
}
	
String CFToString(const CFStringRef in)
{
	if (in)
	{
		// Obtain the char* if the string is utf8 encoded.
		const Char* utf8 = CFStringGetCStringPtr(in, kCFStringEncodingUTF8);
		if (utf8)
			return String(utf8);

		// Get the UniChar* if the string is utf16 encoded.
		Utf16CharBuffer tmp;
		CFIndex length = CFStringGetLength(in);
		const Utf16Char* utf16 = (const Utf16Char*)CFStringGetCharactersPtr(in);
		if (utf16 == nullptr)
		{
			// String backing store is not accessible. Convert to UniChar.
			if (tmp.Resize(length) == OK)
			{
				CFRange range = { 0 , length };
				CFStringGetCharacters(in, range, (UTF16Char*)tmp.GetFirst());
			}
			else
			{
				length = 0;
				CriticalStop("String conversion failed.");
			}
			utf16 = tmp.GetFirst();
		}

		return String(utf16, length);
	}
	return String();
}

}
