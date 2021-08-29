#include "EncodingConversion.h"
#include "iconv.h"

inline Bool EncodingConversion::UTF8toSJIS(String& strin, char* strout)
{
	libiconv_t cd = libiconv_open("SHIFT_JIS", "UTF-8");
	iferr_scope_handler{
		libiconv_close(cd);
		return false;
	};
	size_t length_i = strin.GetCStringLen(STRINGENCODING::UTF8) + size_t(1);
	maxon::AutoMem<maxon::Char> inmen = NewMemClear(maxon::Char, length_i) iferr_return;
	strin.GetCString(inmen, length_i, STRINGENCODING::UTF8);
	size_t length_o = length_i * 2;
	char* outbuf = strout;
	char* inbuf = inmen;
	if (libiconv(cd, &inbuf, &length_i, &outbuf, &length_o) == size_t(-1))
	{
		strout = "Null";
		libiconv_close(cd);
		return false;
	}
	libiconv_close(cd);
	return true;
}

inline Bool EncodingConversion::SJIStoUTF8(char* strin, String& strout)
{
	libiconv_t cd = libiconv_open("UTF-8", "SHIFT_JIS");
	iferr_scope_handler{
		strout = String();
		libiconv_close(cd);
		return false;
	};
	if (strin == nullptr)
	{
		strout = String();
		return false;
	}
	size_t length_i = strlen(strin) + 1;
	size_t length_o = length_i * 2;
	maxon::AutoMem<maxon::Char> outmen = NewMemClear(maxon::Char, length_o) iferr_return;
	char* outbuf = outmen;
	if (libiconv(cd, &strin, &length_i, &outbuf, &length_o) == size_t(-1))
	{
		strout = String();
		libiconv_close(cd);
		return false;
	}	
	libiconv_close(cd);
	strout.SetCString(outmen, -1, STRINGENCODING::UTF8);
	return (true);
}
