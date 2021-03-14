#include "EncodingConversion.h"

String EncodingConversion::JIStoUTF8(char* Str_) {

	UInt32 wStrLen = MultiByteToWideChar(932, 0, Str_, -1, NULL, 0);
	wchar_t* tmp = new wchar_t[wStrLen] {0};
	if (!tmp)
	{
		delete[] tmp;
	}
	MultiByteToWideChar(932, 0, Str_, -1, tmp, wStrLen);

	UInt32 StrLen = WideCharToMultiByte(65001, 0, tmp, -1, NULL, 0, NULL, 0);
	char* outChar;
	outChar = new char[StrLen] {0};
	if (!outChar)
	{
		delete[] outChar;
	}
	WideCharToMultiByte(65001, 0, tmp, -1, outChar, StrLen, NULL, 0);

	String res;
	res.SetCString(outChar, -1, STRINGENCODING::UTF8);
	delete[] tmp;
	delete[] outChar;
	return res;
}

char* EncodingConversion::UTF8toJIS(String& Str_) {
	char* inStr = new char[Str_.GetCStringLen(STRINGENCODING::UTF8)] {0};
	if (!inStr)
	{
		delete[] inStr;
	}
	Str_.GetCString(inStr, -1, STRINGENCODING::UTF8);

	UInt32 wStrLen = MultiByteToWideChar(65001, 0, inStr, -1, NULL, 0);
	wchar_t* tmp = new wchar_t[wStrLen] {0};
	if (!tmp)
	{
		delete[] tmp;
	}
	MultiByteToWideChar(65001, 0, inStr, -1, tmp, wStrLen);

	UInt32 StrLen = WideCharToMultiByte(932, 0, tmp, -1, NULL, 0, NULL, 0);
	char* res = new char[StrLen] {0};
	if (!res)
	{
		delete[] res;
	}
	WideCharToMultiByte(932, 0, tmp, -1, res, StrLen, NULL, 0);
	delete[] inStr;
	delete[] tmp;
	return res;
}
