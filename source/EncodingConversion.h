#ifndef __ENCODING_CONVERSION_H__
#define __ENCODING_CONVERSION_H__

#include "c4d.h"

namespace EncodingConversion
{
	extern Bool SJIStoUTF8(char* strin, String& strout);
	extern Bool UTF8toSJIS(String& strin, char* strout);
};

#endif /* __ENCODING_CONVERSION_H__ */