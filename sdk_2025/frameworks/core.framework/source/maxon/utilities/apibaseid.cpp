#include "maxon/string.h"
#include "maxon/errorbase.h"
#include "maxon/typename.h"

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

UniqueHash LiteralId::GetUniqueHashCode() const
{
	return UniqueHash::GetUniqueHashCode(ToBlock());
}

void Id::AddStrReference()
{
	System::GetReferenceCounter(_value).Inc();
}

void Id::RemoveStrReference()
{
	if (MAXON_UNLIKELY(System::GetReferenceCounter(_value).Dec() == true))
		System::Free(_value);
}

void Id::InitReference(const Char* str)
{
	DebugAssert(str && !_value);
	_value = str;
	_hash = GetHashCode(str) | RC_STRING_MASK;
	AddStrReference();
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
		Char* d = (Char*) System::Alloc(1 + len, MAXON_SOURCE_LOCATION);
		if (!d)
			return FAILED;
		for (Int i = 0; i < len; i++)
		{
			d[i] = str[i];
		}
		d[len] = 0;
		InitReference(d);
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
	Char* d = (Char*) System::Alloc(1 + len, MAXON_SOURCE_LOCATION);
	if (!d)
		return FAILED;
	for (Int i = 0; i < len; i++)
	{
		d[i] = str[i];
	}
	d[len] = 0;
	InitReference(d);
	return OK;
}

ResultMem Id::Init(const String& str)
{
	iferr (BaseArray<Char> chars = str.GetCString())
		return FAILED;
	return Init(chars);
}

void Id::Init(const InternedId& id)
{
	*this = id;
}

ResultMem Id::Init(CString&& str)
{
	Reset();

	iferr (Block<Char> mem = str.Disconnect())
		return FAILED;

	Int len = mem.GetCount();
	if (len == 0)
		return OK;

	Char* d = mem.GetFirst();
	if (!d)
		return FAILED;
	InitReference(d);
	return OK;
}

ResultMem Id::Init(const CString& str)
{
	Reset();
	Int len = str.GetLength();
	if (len == 0)
		return OK;

	Char* d = (Char*) System::Alloc(1 + len, MAXON_SOURCE_LOCATION);
	if (!d)
		return FAILED;
	iferr (str.GetCStringBlock(maxon::ToBlock(d, len + 1)))
	{
		System::Free(d);
		return FAILED;
	}
	InitReference(d);
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

Result<void> InternedId::Init(CString&& str)
{
	iferr_scope;

	Id tmp;
	tmp.Init(std::move(str)) iferr_return;

	Init(tmp) iferr_return;

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

Result<void> InternedId::Init(const Char* str, Bool copyString)
{
	iferr_scope;

	Id tmp;
	tmp.Init(str, copyString) iferr_return;

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

CString InternedId::ToCString() const
{
	return Get().ToCString();
}

void InternedId::Free(const Id* ptr)
{
	System::PrivateFreeInternedId(ptr);
}

const InternedId InternedId::DEFAULT_VALUE;

namespace details
{

const Char* SkipTypeNamePrefix(const Char* name)
{
	const Char* const start = strstr(name, "int");
	if (start)
	{
		name = start + 4;
		while (*name == ' ' || *name == ',')
			++name;
	}
	return name;
}

static Int GetTypeNameLength(const Char* name)
{
	const Char* end = strstr(name, "int");
	if (end)
	{
		while (end > name && (end[-1] == ' ' || end[-1] == ','))
			--end;
		return end - name;
	}
	return -1;
}

Id SkipTypeNameSuffix(const Char* name)
{
	const Int len = GetTypeNameLength(name);
	if (len > 0)
	{
		Id id;
		ifnoerr (id.Init(ToBlock(name, len)))
		{
			return id;
		}
	}
	return Id(name);
}

}

void ClassInfoBase::PrivateInitName(const Char* name)
{
	// Careful, the name here is still compiler dependent.
	// class on msvc: "class maxon::TheClassName"
	// class on clang: "maxon::TheClassName"
	// ...
	_name = maxon::details::SkipTypeNamePrefix(name);
	_nameLength = maxon::details::GetTypeNameLength(_name);
}

} // namespace maxon
