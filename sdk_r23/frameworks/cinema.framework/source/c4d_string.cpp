#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_string.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

maxon::String ToString(const String& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype)
{
	return MaxonConvert(val);
}

const maxon::String& MaxonConvert(const String& val)
{
	return *((const maxon::String*)&val);
}

String MaxonConvert(const maxon::String& val)
{
	CINEWARE_NAMESPACE::String str;
	*(maxon::String*)&str = val;
	return str;
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

#if MAXON_TARGET_DEBUG
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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
