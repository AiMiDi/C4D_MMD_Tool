#include "maxon/string.h"
#include "maxon/errorbase.h"

namespace maxon
{

String LiteralId::ToString(const FormatStatement* formatStatement) const
{
	return String(GetCString(), GetCStringLength());
}

CString LiteralId::ToCString() const
{
	return CString(GetCString(), GetCStringLength());
}

RefCountedCString* RefCountedCString::Alloc(Int len)
{
	RefCountedCString* s = (RefCountedCString*) System::Alloc(1 + len, MAXON_SOURCE_LOCATION_NAME(RefCountedCString));
	return s;
}

void RefCountedCString::AddReference() const
{
	System::GetReferenceCounter(this).Inc();
}

void RefCountedCString::RemoveReference() const
{
	if (MAXON_UNLIKELY(System::GetReferenceCounter(this).Dec() == true))
		System::Free(this);
}

ResultMem Id::Init(const Char* str, Bool copyString)
{
	Reset();
	if (!str)
		return OK;
	Int len = (Int) strlen(str);
	if (len == 0)
		return OK;
	if (copyString)
	{
		RefCountedCString* s = RefCountedCString::Alloc(len);
		if (!s)
			return FAILED;
		s->AddReference();
		Char* d = *s;
		for (Int i = 0; i < len; i++)
		{
			d[i] = str[i];
		}
		d[len] = 0;
		_value = d;
		_hash = GetHashCode(str) + RC_STRING_MASK;
	}
	else
	{
		_value = str;
		_hash = GetHashCode(str);
	}
	return OK;
}

ResultMem Id::Init(const Block<const Char>& str)
{
	Reset();
	if (str.IsEmpty())
		return OK;
	Int len = (Int) strnlen(str.GetFirst(), str.GetCount());
	if (len == 0)
		return OK;
	RefCountedCString* s = RefCountedCString::Alloc(len);
	if (!s)
		return FAILED;
	s->AddReference();
	Char* d = *s;
	for (Int i = 0; i < len; i++)
	{
		d[i] = str[i];
	}
	d[len] = 0;
	_value = d;
	_hash = GetHashCode(d) + RC_STRING_MASK;
	return OK;
}

ResultMem Id::Init(const String& str)
{
	iferr (BaseArray<Char> chars = str.GetCString())
		return FAILED;
	return Init(chars.GetFirst(), true);
}

void Id::Init(const InternedId& id)
{
	*this = id;
}

ResultMem Id::Init(const CString& str)
{
	Reset();
	Int len = str.GetLength();
	if (len == 0)
		return OK;

	RefCountedCString* s = RefCountedCString::Alloc(len);
	if (!s)
		return FAILED;
	s->AddReference();
	Char* d = *s;
	iferr (str.GetCStringBlock(maxon::ToBlock(d, len + 1)))
		return FAILED;
	_value = d;
	_hash = GetHashCode(d) + RC_STRING_MASK;
	return OK;
}

Result<void> InternedId::Init(const Id& i)
{
	iferr_scope;
	Reset();
	// reference counter has been incremented by PrivateGetInternedId
	_id = System::PrivateGetInternedId(i) iferr_return;
	return OK;
}

Result<void> InternedId::Init(const CString& str)
{
	iferr_scope;

	Id tmp;
	tmp.Init(str) iferr_return;

	Init(tmp) iferr_return;

	return OK;
}

Result<void> InternedId::Init(const String& str)
{
	iferr_scope;

	Id tmp;
	tmp.Init(str) iferr_return;

	Init(tmp) iferr_return;

	return OK;
}

Result<void> InternedId::Init(const Char* str)
{
	iferr_scope;

	Id tmp;
	tmp.Init(str, true) iferr_return;

	Init(tmp) iferr_return;

	return OK;
}

Result<void> InternedId::Init(const Block<const Char>& str)
{
	iferr_scope;

	Id tmp;
	tmp.Init(str) iferr_return;

	Init(tmp) iferr_return;

	return OK;
}

String InternedId::ToString(const FormatStatement* fmt) const
{
	return Get().ToString(fmt);
}

void InternedId::Free(const Id* ptr)
{
	System::PrivateFreeInternedId(ptr);
}

const InternedId InternedId::NULL_VALUE;

} // namespace maxon

