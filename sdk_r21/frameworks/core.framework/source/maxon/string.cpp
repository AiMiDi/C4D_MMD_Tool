#include "maxon/string.h"
#include "maxon/stringconversion.h"
#include "maxon/stringresource.h"
#include "maxon/streamconversion.h"


static maxon::Char g_tempErrorDebugBuffer[1024];

const maxon::Char* cstr(const maxon::Error& err)
{
	maxon::CString cerr = FormatCString("@", err);
	cerr.GetCStringBlock(maxon::Block<maxon::Char>(g_tempErrorDebugBuffer)) iferr_ignore("Ignore ToString errors");
	return g_tempErrorDebugBuffer;
}

const maxon::Char* cstr(const maxon::ErrorPtr& err)
{
	maxon::CString cerr = FormatCString("@", err);
	cerr.GetCStringBlock(maxon::Block<maxon::Char>(g_tempErrorDebugBuffer)) iferr_ignore("Ignore ToString errors");
	return g_tempErrorDebugBuffer;
}

const maxon::Char* cstr(const maxon::ThreadReferencedError& err)
{
	if (err.GetReferencedError())
	{
		maxon::CString cerr = FormatCString("@", *err.GetReferencedError());
		cerr.GetCStringBlock(maxon::Block<maxon::Char>(g_tempErrorDebugBuffer)) iferr_ignore("Ignore ToString errors");
	}
	else
	{
		g_tempErrorDebugBuffer[0] = 0;
	}
	return g_tempErrorDebugBuffer;
}


namespace maxon
{

template <typename I, typename R, typename C> Bool StringTemplate<I, R, C>::Find(const R& str, Int* pos, StringPosition start) const
{
	Int index = FindIndex(str, start);
	if (pos)
		*pos = index;
	return index != -1;
}

template <typename I, typename R, typename C> Bool StringTemplate<I, R, C>::FindLast(const R& str, Int* pos, StringPosition start) const
{
	Int index = FindLastIndex(str, start);
	if (pos)
		*pos = index;
	return index != -1;
}

template <typename I, typename R, typename C> Bool StringTemplate<I, R, C>::Find(C ch, Int* pos, StringPosition start) const
{
	Int index = FindIndex(ch, start);
	if (pos)
		*pos = index;
	return index != -1;
}

template <typename I, typename R, typename C> Bool StringTemplate<I, R, C>::FindLast(C ch, Int* pos, StringPosition start) const
{
	Int index = FindLastIndex(ch, start);
	if (pos)
		*pos = index;
	return index != -1;
}

template <typename I, typename R, typename C> Bool StringTemplate<I, R, C>::FindUpper(const R& str, Int* pos, StringPosition start) const
{
	Int index = FindUpperIndex(str, start);
	if (pos)
		*pos = index;
	return index != -1;
}

template <typename I, typename R, typename C> Bool StringTemplate<I, R, C>::FindLastUpper(const R& str, Int* pos, StringPosition start) const
{
	Int index = FindLastUpperIndex(str, start);
	if (pos)
		*pos = index;
	return index != -1;
}

template <typename I, typename R, typename C> Result<void> StringTemplate<I, R, C>::Trim()
{
	iferr_scope;

	TrimLeft() iferr_return;
	TrimRight() iferr_return;

	return OK;
}

String ExtractString(StringProxy* proxy)
{
	String tmp;
	if (proxy)
		tmp = proxy->str;
	DeleteObj(proxy);
	return tmp;
}

String::String(const Id& type, const void* ptr)
{
	if (SetCString(type.GetCString(), type.GetCStringLength()) == FAILED)
		DebugStop();
	if (Append("@"_s) == FAILED)
		DebugStop();
	if (Append(StringConversion::HexToString((UInt) ptr, true, true, nullptr)) == FAILED)
		DebugStop();
}

String::String(const String& prefix, const void* ptr, Bool prefix0x)
{
	*this = prefix;
	if (Append("@"_s) == FAILED)
		DebugStop();
	if (Append(StringConversion::HexToString((UInt) ptr, prefix0x, false, nullptr)) == FAILED)
		DebugStop();
}

String::String(const CString& str, const StringDecodingRef& stringDecoding)
{
	if (SetCString(str.GetInternalData().GetFirst(), -1, stringDecoding) == FAILED)
		DebugStop();
}

String ToString(Char val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	if (formatStatement)
	{
		String str;
		StringConversion::AppendInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
		return str;
	}
	return String(&val, 1);
}

String ToString(UChar val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	if (formatStatement)
	{
		String str;
		StringConversion::AppendUInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
		return str;
	}
	return String((Char*)&val, 1);
}

String ToString(Int16 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(Int32 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(Utf16Char val, const FormatStatement* formatStatement, Bool checkDataType)
{
	String str;
	StringConversion::AppendInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(Utf32Char val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(Int64 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(UInt16 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendUInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(UInt32 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendUInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(UInt64 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	String str;
	StringConversion::AppendUInt(str.MakeWritable().GetPointer(), val, SIZEOF(val), formatStatement);
	return str;
}

String ToString(Float64 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	return StringConversion::FloatToString(val, STRING_DYNAMIC_DIGITS, -3, false, '0', formatStatement);
}

String ToString(Float32 val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	return StringConversion::FloatToString(val, STRING_DYNAMIC_DIGITS, -3, false, '0', formatStatement);
}

const String& String::GetLineEnd()
{
	return StringConversion::GetLineEnd();
}

const CString& CString::GetLineEnd()
{
	return StringConversion::GetLineEndC();
}

template <typename I, typename R, typename C> R StringTemplate<I, R, C>::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, C fillChar)
{
	return (R) StringConversion::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, (Utf32Char)fillChar, nullptr);
}

template <typename I, typename R, typename C> R StringTemplate<I, R, C>::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, C fillChar)
{
	return (R) StringConversion::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, (Utf32Char)fillChar, nullptr);
}

template <typename I, typename R, typename C> R StringTemplate<I, R, C>::PointerToString(const void* v)
{
	return (R) StringConversion::HexToString((UInt) v, true, true, nullptr);
}

template <typename I, typename R, typename C> I* StringTemplate<I, R, C>::AppendInt(Int64 l)
{
	StringConversion::AppendInt(static_cast<I*>(this), l, SIZEOF(l), nullptr);
	return static_cast<I*>(this);
}

template <typename I, typename R, typename C> I* StringTemplate<I, R, C>::AppendUInt(UInt64 l)
{
	StringConversion::AppendUInt(static_cast<I*>(this), l, SIZEOF(l), nullptr);
	return static_cast<I*>(this);
}

template <typename I, typename R, typename C> R StringTemplate<I, R, C>::MemorySizeToString(Int64 mem, bool mebibytes)
{
	return (R) StringConversion::MemorySizeToString(mem, mebibytes);
}

template <typename I, typename R, typename C> R StringTemplate<I, R, C>::HexToString(UInt32 l, Bool prefix0x)
{
	return (R) StringConversion::HexToString(l, prefix0x, true, nullptr);
}

template <typename I, typename R, typename C> R StringTemplate<I, R, C>::HexToString(UInt64 l, Bool prefix0x)
{
	return (R) StringConversion::HexToString(l, prefix0x, true, nullptr);
}

inline const String& AsString(const String& s)
{
	return s;
}

inline String AsString(const CString& s)
{
	return String(s);
}

template <typename I, typename R, typename C> Result<Float32> StringTemplate<I, R, C>::ToFloat32(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
	return StringConversion::ToFloat32(buffer, flags);
}

template <typename I, typename R, typename C> Result<Float64> StringTemplate<I, R, C>::ToFloat64(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
	return StringConversion::ToFloat64(buffer, flags);
}

template <typename I, typename R, typename C> Result<Float> StringTemplate<I, R, C>::ToFloat(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
#ifdef MAXON_TARGET_SINGLEPRECISION
	return StringConversion::ToFloat32(buffer, flags);
#else
	return StringConversion::ToFloat64(buffer, flags);
#endif
}

template <typename I, typename R, typename C> Result<Int64> StringTemplate<I, R, C>::ToInt64(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
	return StringConversion::ToInt64(buffer, flags);
}

template <typename I, typename R, typename C> Result<Int32> StringTemplate<I, R, C>::ToInt32(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
	return StringConversion::ToInt32(buffer, flags);
}

template <typename I, typename R, typename C> Result<Int> StringTemplate<I, R, C>::ToInt(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
#ifdef MAXON_TARGET_64BIT
	return StringConversion::ToInt64(buffer, flags);
#else
	return StringConversion::ToInt32(buffer, flags);
#endif
}

template <typename I, typename R, typename C> Result<UInt64> StringTemplate<I, R, C>::ToUInt64(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
	return StringConversion::ToUInt64(buffer, flags);
}

template <typename I, typename R, typename C> Result<UInt32> StringTemplate<I, R, C>::ToUInt32(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
	return StringConversion::ToUInt32(buffer, flags);
}

template <typename I, typename R, typename C> Result<UInt> StringTemplate<I, R, C>::ToUInt(STRINGCONVERSION flags) const
{
	Utf32CharBuffer buffer;
	iferr (GetUtf32(buffer))
		return err;
#ifdef MAXON_TARGET_64BIT
	return StringConversion::ToUInt64(buffer, flags);
#else
	return StringConversion::ToUInt32(buffer, flags);
#endif
}


template class StringTemplate<StringInterface, String, Utf32Char>;
template class StringTemplate<CStringInterface, CString, Char>;


using FormatStatementData = HashMap<CString, CString, CStringCompare>;

FormatStatement::FormatStatement()
{
	iferr (_priv = NewObj(FormatStatementData))
		err.CritStop();
}

FormatStatement::FormatStatement(const FormatStatement& str)
{
	FormatStatementData* tmp = nullptr;
	if (str._priv)
	{
		iferr (tmp = NewObj(FormatStatementData))
			err.CritStop();

		if (tmp)
		{
			iferr (tmp->CopyFrom(*(const FormatStatementData*)str._priv))
				err.CritStop();
		}
	}
	_priv = tmp;
}

FormatStatement::~FormatStatement()
{
	FormatStatementData* tmp = (FormatStatementData*)_priv;
	DeleteObj(tmp);
	_priv = nullptr;
}

const FormatStatement& FormatStatement::operator =(const FormatStatement& str)
{
	FormatStatementData* tmp = (FormatStatementData*)_priv;
	DeleteObj(tmp);
	if (str._priv)
	{
		iferr (tmp = NewObj(FormatStatementData))
			err.CritStop();

		if (tmp)
		{
			iferr (tmp->CopyFrom(*(const FormatStatementData*)str._priv))
				err.CritStop();
		}
	}
	_priv = tmp;
	return *this;
}

const CString FormatStatement::Get(const Char* id) const
{
	const FormatStatementData* tmp = (const FormatStatementData*)_priv;
	if (tmp)
	{
		const CString* str = tmp->FindValue(CString(id));
		if (!str)
			str = tmp->FindValue(CString());

		if (str)
			return *str;
	}

	return CString();
}

Result<void> FormatStatement::Set(const Char* identifier, const CString& str)
{
	FormatStatementData* tmp = (FormatStatementData*)_priv;
	if (!tmp)
		return OK;

	Bool created = false;
	iferr (tmp->Insert(CString(identifier), str, created))
		return err;
	return OK;
}

Bool ScanStringTemplate(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs)
{
	return StringConversion::ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs);
}

void ScanParameter(Float64& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	result = 0.0;
	error = false;
	iferr (result = StringConversion::StringToFloat(str, processed))
		error = true;
}

void ScanParameter(Float32& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	result = 0.0;
	error = false;

	iferr (Float64 tmp = StringConversion::StringToFloat(str, processed))
	{
		error = true;
	}
	else
	{
		// check if range is legal
		if (tmp > (Float64)LIMIT<Float32>::Max() || tmp < (Float64)LIMIT<Float32>::Min())
			error = true;
		else
			result = (Float32)tmp;
	}
}

void ScanParameter(Int64& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	result = StringConversion::ScanParameterBasic(str, true, processed, formatStatement, error);
}

void ScanParameter(Int32& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	Int64 tmp = StringConversion::ScanParameterBasic(str, true, processed, formatStatement, error);
	result = (Int32) tmp;

	// check if range is legal
	if ((Int64)result != tmp)
		error = true;
}

void ScanParameter(Int16& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	Int64 tmp = StringConversion::ScanParameterBasic(str, true, processed, formatStatement, error);
	result = (Int16) tmp;

	// check if range is legal
	if ((Int64)result != tmp)
		error = true;
}

void ScanParameter(Char& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	Int64 tmp = StringConversion::ScanParameterBasic(str, true, processed, formatStatement, error);
	result = (Char) tmp;

	// check if range is legal
	if ((Int64)result != tmp)
		error = true;
}

void ScanParameter(UInt64& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	result = (UInt64)StringConversion::ScanParameterBasic(str, false, processed, formatStatement, error);
}

void ScanParameter(UInt32& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	UInt64 tmp = (UInt64)StringConversion::ScanParameterBasic(str, false, processed, formatStatement, error);
	result = (UInt32) tmp;

	// check if range is legal
	if ((UInt64)result != tmp)
		error = true;
}

void ScanParameter(UInt16& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	UInt64 tmp = (UInt64)StringConversion::ScanParameterBasic(str, false, processed, formatStatement, error);
	result = (UInt16) tmp;

	// check if range is legal
	if ((UInt64)result != tmp)
		error = true;
}

void ScanParameter(UChar& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	UInt64 tmp = (UInt64)StringConversion::ScanParameterBasic(str, false, processed, formatStatement, error);
	result = (UChar) tmp;

	// check if range is legal
	if ((UInt64)result != tmp)
		error = true;
}

String _LoadResourceString(const Id& scope, const InternedId& keyValue)
{
	return Resource::LoadResourceString(scope, keyValue);
}

String ToString(const DataType& type, const FormatStatement* formatStatement, Bool checkDatatype)
{
	if (!type)
		return "nullptr"_s;
	return type->GetId().ToString(formatStatement);
}


CString::CString(const String& str, const StringEncodingRef& stringEncoding)
{
	// convert String to CString
	iferr (BaseArray<Char> temp = str.GetCString(stringEncoding))
	{
		DebugStop();
		temp.Reset();
	}

	if (Init(temp.GetCount()) == OK)
	{
		Char* dst = const_cast<Char*>(GetInternalData().GetFirst());

		// It is allright to copy the string without terminator, CString::Init() took care of that.
		MemCopy(dst, temp.GetFirst(), temp.GetCount());
	}
}

CString ExtractCString(StringProxy* proxy)
{
	CString tmp;
	if (proxy)
		tmp = CString(proxy->str);

	DeleteObj(proxy);
	return tmp;
}

String CStringInterface::ToString(const FormatStatement* formatStatement) const
{
	Block<const Char> b = GetInternalData();
	return String(b);
}

String& operator +=(String& s, const CString& b)
{
	s += String(b);
	return s;
}

String operator +(const String& a, const Char* b)
{
	String s(a);
	s += String(b);
	return s;
}

String&& operator +(String&& a, const Char* b)
{
	return std::move(a += String(b));
}

String ToString(Char* val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	return String(val);
}

String ToString(const Char* val, const FormatStatement* formatStatement, Bool checkDatatype)
{
	return String(val);
}

Result<String> StringInterface::ConvertString(const StreamConversionRef& converter) const
{
	iferr_scope;

	Utf32CharBuffer block;
	GetUtf32(block) iferr_return;

	BaseArray<Utf32Char> tmp;
	converter.ConvertAll(block, tmp) iferr_return;

	return String(tmp);
}

const String& StringInterface_GetAndCacheConstString(const wchar_t* str, Int len)
{
	return StringInterface::GetAndCacheConstString(str, len);
}

const String& StringInterface_GetAndCacheConstString(const Char* str, Int len, Int isUtf8)
{
	return StringInterface::GetAndCacheConstString(str, len, isUtf8);
}

} // namespace maxon
