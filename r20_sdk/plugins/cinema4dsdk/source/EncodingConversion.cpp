#include "EncodingConversion.h"

wchar_t* EncodingConversion::SjisToUnicode(char *Str_)
{
	UInt32 StrLen = MultiByteToWideChar(932, 0, Str_, -1, NULL, 0);
	wchar_t *res = new wchar_t[StrLen] {0};
	if (!res)
	{
		delete[] res;
	}
	MultiByteToWideChar(932, 0, Str_, -1, res, StrLen);
	return res;
}
char* EncodingConversion::UnicodeToUTF8(wchar_t *wStr_)
{
	UInt32 wStrLen = WideCharToMultiByte(65001, 0, wStr_, -1, NULL, 0, NULL, 0);
	char *res;
	res = new char[wStrLen] {0};
	if (!res)
	{
		delete[] res;
	}
	WideCharToMultiByte(65001, 0, wStr_, -1, res, wStrLen, NULL, 0);
	return res;
}

wchar_t* EncodingConversion::UTF8ToUnicode(char *Str_)
{
	UInt32 StrLen = MultiByteToWideChar(65001, 0, Str_, -1, NULL, 0);
	wchar_t* res = new wchar_t[StrLen] {0};
	if (!res)
	{
		delete[] res;
	}
	MultiByteToWideChar(65001, 0, Str_, -1, res, StrLen);
	return res;
}
char* EncodingConversion::UnicodeToSjis(wchar_t *wStr_)
{
	UInt32 wStrLen = WideCharToMultiByte(932, 0, wStr_, -1, NULL, 0, NULL, 0);
	char* res = new char[wStrLen] {0};
	if (!res)
	{
		delete[] res;
	}
	WideCharToMultiByte(932, 0, wStr_, -1, res, wStrLen, NULL, 0);
	return res;
}

String EncodingConversion::JIStoUTF8(char* Str_) {
	wchar_t *tmp = SjisToUnicode(Str_);
	char *outChar = UnicodeToUTF8(tmp);
	String res;
	res.SetCString(outChar, -1, STRINGENCODING::UTF8);
	return res;
}

char* EncodingConversion::UTF8toJIS(String& Str_) {
	Int32 StrLen = Str_.GetCStringLen(STRINGENCODING::UTF8);
	char* inStr = new char[StrLen] {0};
	if (!inStr)
	{
		delete[] inStr;
	}
	Str_.GetCString(inStr, -1, STRINGENCODING::UTF8);
	wchar_t *tmp = UTF8ToUnicode(inStr);
	char* res = UnicodeToSjis(tmp);
	return res;
}
