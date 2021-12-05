#ifndef CRASHREPORTPROPERTY_H__
#define CRASHREPORTPROPERTY_H__

#include "maxon/apibase.h"
#include "maxon/blockarray.h"

namespace maxon
{

struct CrashReportPropertyItem
{
	explicit CrashReportPropertyItem(const Char* name = nullptr, const Char* value = nullptr) : _name(name), _value(value) {}

	CrashReportPropertyItem(const CrashReportPropertyItem& src) : _name(src._name), _value(src._value) {}
	CrashReportPropertyItem(CrashReportPropertyItem&& src) : _name(src._name), _value(src._value) {}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(CrashReportPropertyItem);


	const Char* _name;
	const Char* _value;
};

using CrashReportPropertyArray = BlockArray<CrashReportPropertyItem, 8>;

} // namespace maxon


#ifndef CORETHREAD_H__

#include "maxon/crashreportservices.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// A property that can be stored by the crash report if something crashes while the property
/// is still part of the scope.
///
/// If you'd call the following method with makeCrash == true the crash report would contain
/// the two properties "Entered Sample method" and "Going to crash: true". The property "Will
/// not appear" won't be in the crash report because the scope of its code block has been left.
///
/// @code
/// void Sample(Int xyz, Bool makeCrash)
/// {
/// 	CRASHREPORTPROPERTY("Entered Sample method");
/// 	if (xyz)
/// 	{
/// 		CRASHREPORTPROPERTY("Will not appear", xyz);
/// 	}
/// 	if (makeCrash)
/// 	{
/// 		CRASHREPORTPROPERTY("Going to crash", makeCrash);
/// 		int* badAddress = (int*) 32;
/// 		*badAddress = 42;
/// 	}
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class CrashReportProperty
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(CrashReportProperty);

public:
	//----------------------------------------------------------------------------------------
	/// Constructs a property for the crash report if something crashes while this is still
	/// in scope.
	/// it when the object is no longer needed). If you try to start an already running thread
	/// this will fail and return an error.
	/// @param[in] name								Property name or key.
	/// @param[in] value							Pointer to a null terminated C string that must be valid until the scope is left.
	//----------------------------------------------------------------------------------------
	explicit CrashReportProperty(const Char* name, const Char* value = nullptr)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(value));
	}

	CrashReportProperty(const Char* name, Bool value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(value));
	}

	CrashReportProperty(const Char* name, Char value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(UChar(value), 2));
		SetAllocationState(false);
	}

	CrashReportProperty(const Char* name, Int16 value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(UInt16(value), 4));
	}

	CrashReportProperty(const Char* name, Int32 value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(UInt32(value), 8));
	}

	CrashReportProperty(const Char* name, Int64 value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(UInt64(value), 16));
	}

	CrashReportProperty(const Char* name, UChar value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(value, 2));
	}

	CrashReportProperty(const Char* name, UInt16 value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(value, 4));
	}

	CrashReportProperty(const Char* name, UInt32 value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(value, 8));
	}

	CrashReportProperty(const Char* name, UInt64 value)
	{
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(value, 16));
	}

	CrashReportProperty(const Char* name, const Float32& value)
	{
		UInt32 tmp = *(UInt32*) &value;
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(tmp, 8));
	}

	CrashReportProperty(const Char* name, const Float64& value)
	{
		UInt64 tmp = *(UInt64*) &value;
		_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, StoreValue(tmp, 16));
	}

	CrashReportProperty(const Char* name, const String& value)
	{
		ifnoerr (BaseArray<Char> temp = value.GetCString())
		{
			*(Char**)_buf = temp.Disconnect().GetFirst();
			SetAllocationState(true);
			_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, *(Char**)_buf);
		}
	}

	template <typename T> CrashReportProperty(const Char* name, const T& value)
	{
		ifnoerr (BaseArray<Char> temp = ToString(value, (const maxon::FormatStatement*)nullptr, false).GetCString())
		{
			*(Char**)_buf = temp.Disconnect().GetFirst();
			SetAllocationState(true);
			_propertyIdx = CrashReportServices::CreateCrashReportProperty(name, *(Char**)_buf);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Destructs a property for the crash report when the scope is left.
	/// From the C++ standard: "On exit from a scope (however accomplished), objects with
	/// automatic storage duration (3.7.3) that have been constructed in that scope are destroyed
	/// in the reverse order of their construction."
	//----------------------------------------------------------------------------------------
	~CrashReportProperty()
	{
		CrashReportServices::FreeCrashReportProperty(_propertyIdx);
		if (IsAllocated())
		{
			Char* str = *(Char**)_buf;
			DeleteMem(str);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to an array with crash properties (used by the crash report).
	/// @param[in] osThread						OS specific thread identifier.
	/// @return												Pointer to an array with crash properties.
	//----------------------------------------------------------------------------------------
	static CrashReportPropertyArray* GetCrashReportProperties(void* osThread)
	{
		return (CrashReportPropertyArray*) CrashReportServices::GetCrashReportProperties(osThread);
	}

private:
	void SetAllocationState(Bool state)
	{
		_buf[sizeof(_buf) - 1] = state;
	}

	Bool IsAllocated() const
	{
		return _buf[sizeof(_buf) - 1] != 0;
	}

	const Char* StoreValue(const Char* value)
	{
		SetAllocationState(false);
		return value;
	}

	const Char* StoreValue(Bool value)
	{
		SetAllocationState(false);
		return value ? "true" : "false";
	}

	const Char* StoreValue(UInt64 value, Int digits)
	{
		DebugAssert(digits <= 16);
		_buf[0] = '0';
		_buf[1] = 'x';
		_buf[2 + digits] = 0;
		for (Int idx = 2 + digits - 1; idx >= 2; idx--)
		{
			Char digit = Char(value & 0xf);
			digit += digit >= 10 ? 'a' : '0';
			_buf[idx] = digit;
			value >>= 4;
		}
		SetAllocationState(false);
		return _buf;
	}

private:
	Int32 _propertyIdx;
	char _buf[28];
};

#define CRASHREPORTPROPERTY(...) CrashReportProperty MAXON_CONCAT(crashProperty, __LINE__)(__VA_ARGS__)

} // namespace maxon

#endif

#endif // CRASHREPORTPROPERTY_H__
