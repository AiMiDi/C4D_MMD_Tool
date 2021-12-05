#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_string.h"

String MaxonConvert(const maxon::String& val)
{
	::String str;
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

#if (defined MAXON_TARGET_DEBUG) && (defined MAXON_TARGET_WINDOWS)
static const Int CSTR_BUFFER_LEN = 1000;
static Char cstr_array[CSTR_BUFFER_LEN];

Char* cstr(String& str)
{
	str.GetCString(cstr_array, CSTR_BUFFER_LEN);
	return cstr_array;
}

Char* cstr(const String& str)
{
	str.GetCString(cstr_array, CSTR_BUFFER_LEN);
	return cstr_array;
}

#include "c4d_baselist.h"

Char* cstr(GeListNode* node)
{
	if (node->IsInstanceOf(Tbaselist2d))
		((BaseList2D*)node)->GetName().GetCString(cstr_array, CSTR_BUFFER_LEN);
	else
		strcpy(cstr_array, "no baselist");
	return cstr_array;
}

#include "c4d_file.h"

Char* cstr(Filename& fn)
{
	fn.GetString().GetCString(cstr_array, CSTR_BUFFER_LEN);
	return cstr_array;
}

Char* cstr(const Filename& fn)
{
	fn.GetString().GetCString(cstr_array, CSTR_BUFFER_LEN);
	return cstr_array;
}

#endif
