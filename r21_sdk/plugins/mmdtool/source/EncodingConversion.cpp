#include "EncodingConversion.h"


inline void* EncodingConversion::Memcpy(void* dst, const void* src, size_t size)
{
	char* psrc;
	char* pdst;
	if (nullptr == dst || nullptr == src)
	{
		return nullptr;
	}
	if ((src < dst) && (char*)src + size > (char*)dst) //自后向前拷贝
	{
		psrc = (char*)src + size - 1;
		pdst = (char*)dst + size - 1;
		while (size--)
		{
			*pdst-- = *psrc--;
		}
	}
	else
	{
		psrc = (char*)src;
		pdst = (char*)dst;
		while (size--)
		{
			*pdst++ = *psrc++;
		}
	}
	return dst;
}

String EncodingConversion::JIStoUTF8(char* Str_) {
	UInt32 wStrLen = MultiByteToWideChar(932, 0, Str_, -1, NULL, 0);
	wchar_t* tmp = new wchar_t[wStrLen] {0};
	if (!tmp)
	{
		delete[] tmp;
	}
	MultiByteToWideChar(932, 0, Str_, -1, tmp, wStrLen);
	Utf16Char* outChar = new Utf16Char[wStrLen + 1]{ 0 };
	EncodingConversion::Memcpy(outChar, tmp, wStrLen * sizeof(wchar_t));
	delete[] tmp;
	String res(outChar);
	delete[] outChar;
	return res;
}

char* EncodingConversion::UTF8toJIS(String& Str_) {
	maxon::Utf16CharBuffer wchar_buffer;
	iferr(Str_.GetUtf16(wchar_buffer))return nullptr;
	UInt32 wStrLen = wchar_buffer.GetCount();
	wchar_t* tmp = new wchar_t[wStrLen + 1]{ 0 };
	for (Int32 i = 0; i < wStrLen; i++) {
		tmp[i] = wchar_buffer[i];
	}
	UInt32 StrLen = WideCharToMultiByte(932, 0, tmp, -1, NULL, 0, NULL, 0);
	char* res = new char[StrLen] {0};
	if (!res)
	{
		delete[] res;
	}
	WideCharToMultiByte(932, 0, tmp, -1, res, StrLen, NULL, 0);
	delete[] tmp;
	return res;
}
