#ifndef __ENCODING_CONVERSION_H__
#define __ENCODING_CONVERSION_H__

#include "c4d.h"
#include <windows.h>

namespace EncodingConversion
{
	void* Memcpy(void* dst, const void* src, size_t size);
	String JIStoUTF8(char* Str_);
	char* UTF8toJIS(String& Str_);
};

#endif __ENCODING_CONVERSION_H__