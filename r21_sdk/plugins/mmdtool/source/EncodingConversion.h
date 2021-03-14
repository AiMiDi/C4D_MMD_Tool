#ifndef __ENCODING_CONVERSION_H__
#define __ENCODING_CONVERSION_H__

#include "c4d.h"
#include <windows.h>

namespace EncodingConversion
{
	String JIStoUTF8(char* Str_);
	char* UTF8toJIS(String& Str_);
};

#endif __ENCODING_CONVERSION_H__