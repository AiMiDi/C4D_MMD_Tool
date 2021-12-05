#ifndef WIN_COM_H__
#define WIN_COM_H__

#include <wrl/client.h>
#include <propvarutil.h>

#pragma warning(push)
#pragma warning(disable:4986) // warning C4986: 'std::set_new_handler': exception specification does not match previous declaration
#include <comdef.h>
#pragma warning(pop)

#include "maxon/win_include.h"

#include "maxon/errorbase.h"
#include "maxon/datetime.h"
#include "maxon/win_type_conversions.h"

namespace maxon
{

// stylecheck.using=false
// stylecheck.naming=false

using namespace Microsoft::WRL;	// maps ComPtr<>

MAXON_ATTRIBUTE_FORCE_INLINE Error GetHResultError(HRESULT hr, MAXON_SOURCE_LOCATION_DECLARATION)
{
	_com_error error(hr);
	return IllegalStateError(MAXON_SOURCE_LOCATION_FORWARD, FormatString("Error 0x@{x}: @", (Int32)hr, String((const Utf16Char*)error.ErrorMessage(), -1)));
}

MAXON_ATTRIBUTE_FORCE_INLINE void operator %(HRESULT value, ThreadReferencedError& err)
{
	if (SUCCEEDED(value))
	{
		err = nullptr;
	}
	else
	{
		err = System::SetCurrentError(GetHResultError(value, MAXON_SOURCE_LOCATION));
	}
}

//----------------------------------------------------------------------------------------
/// This class allows to use windows GUID structures together with HashMaps/HashSets.
/// It implements GetHashCode and IsEqual for GUID.
//----------------------------------------------------------------------------------------
class GUIDHASH
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const GUID& guid)
	{
		UInt hashCode = 0;
		for (Int i = 0; i < (Int)sizeof(GUID); i++)
		{
			hashCode = 31 * hashCode + DefaultCompare::GetHashCode(((UChar*)&guid)[i]);
		}
		return hashCode;
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(const GUID& a, const GUID& b)
	{
		return maxon::CompareMem(&a, &b, sizeof(a)) == 0;
	}
};

//----------------------------------------------------------------------------------------
/// Converts a windows VARIANT into a Int64 value with proper error handling.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Result<Int64> PropVariantToInt64(const PROPVARIANT& vt)
{
	switch (vt.vt)
	{
		case VT_INT:	return vt.intVal;
		case VT_UINT:	return vt.uintVal;
		case VT_I8:		return vt.hVal.QuadPart;
		case VT_UI8:	return vt.uhVal.QuadPart;
	}
	return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION);
}

MAXON_ATTRIBUTE_FORCE_INLINE Result<Int64> VariantToInt64(const VARIANT& vt)
{
	static_assert(std::alignment_of<VARIANT>::value == std::alignment_of<PROPVARIANT>::value, "invalid alignment");
	return PropVariantToInt64(reinterpret_cast<const PROPVARIANT&>(vt));
}

//----------------------------------------------------------------------------------------
/// Converts a windows VARIANT into a DateTime value with proper error handling.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Result<UniversalDateTime> PropVariantToUniversalDateTime(const PROPVARIANT& vt)
{
	switch (vt.vt)
	{
		case VT_DATE:
		{
			Float64 date = vt.date;

			SYSTEMTIME systemtime;
			if (VariantTimeToSystemTime(date, &systemtime) == FALSE)
				return UnknownError(MAXON_SOURCE_LOCATION, "Cannot convert PROPVARIANT"_s);

			return ConvertSystemTimeToUniversalDateTime(systemtime);
		}

		case VT_FILETIME:
		{
			FILETIME ft = vt.filetime;
			return UniversalDateTime::FromUnixTimestamp(FiletimeToUnixTimestamp(ft));
		}
	}
	return IllegalArgumentError(MAXON_SOURCE_LOCATION);
}

MAXON_ATTRIBUTE_FORCE_INLINE Result<UniversalDateTime> VariantToUniversalDateTime(const VARIANT& vt)
{
	static_assert(std::alignment_of<VARIANT>::value == std::alignment_of<PROPVARIANT>::value, "invalid alignment");
	return PropVariantToUniversalDateTime(reinterpret_cast<const PROPVARIANT&>(vt));
}

} // namespace maxon

#endif // WIN_COM_H__
