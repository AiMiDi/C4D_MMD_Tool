#include "c4d.h"
#include <windows.h>

class EncodingConversion
{
private:	
	static wchar_t* SjisToUnicode(char *Str_);
	static char* UnicodeToUTF8(wchar_t *wStr_);
	static wchar_t* UTF8ToUnicode(char *Str_);
	static char* UnicodeToSjis(wchar_t *wStr_);
public:
	static String JIStoUTF8(char* Str_);
	static char* UTF8toJIS(String& Str_);
	EncodingConversion() {};
	~EncodingConversion() {};
};