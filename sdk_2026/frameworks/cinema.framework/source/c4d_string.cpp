#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_string.h"

namespace cinema
{

maxon::String ToString(const String& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype)
{
	return MaxonConvert(val);
}

Char* String::GetCStringCopy(STRINGENCODING type) const
{
	Char* txt = nullptr;
	Int32 len = StCall(GetCStringLen) (type);
	if (len > 0)
	{
		iferr (txt = NewMemClear(Char, len + 2))
		{
			DebugStop();
		}
		else
		{
			StCall(GetCString) (txt, len + 2, type);
			txt[len] = 0;

#ifdef MAXON_TARGET_DEBUG
			if (type == STRINGENCODING::XBIT)
			{
				for (Int32 i = 0; i < len; i++)
				{
					if (UChar(txt[i]) > 127)
					{
						DebugStop("Undefined encoding. Use maxon::StringDecodings::Utf8()");
						break;
					}
				}
			}
#endif
		}
	}

	return txt;
}

} // namespace cinema
