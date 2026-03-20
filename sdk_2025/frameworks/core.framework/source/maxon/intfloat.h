#ifndef INTFLOAT_H__
#define INTFLOAT_H__

#include "maxon/apibase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This structure is used to map an integer and a floating point value to the same memory location.
/// A stucture is used since gcc outputs a warning if you do something like *((Int32*)&myFloat32Value).
//----------------------------------------------------------------------------------------
struct IntFloat32
{
	IntFloat32() = default;
	explicit IntFloat32(Int32 a) { i = a; }
	explicit IntFloat32(UInt32 a) { i = (Int32)a; }
	explicit IntFloat32(Float32 a) { f = a; }
	const IntFloat32& operator = (const IntFloat32& other) { i = other.i; return *this; }

	// Compare the integer values here for a binary comparison. 
	// Comparing the float values would return true for 1.001e-42#DEN == 0.0.
	friend Bool operator == (const IntFloat32& a, const IntFloat32& b) { return a.i == b.i; } 
	friend Bool operator != (const IntFloat32& a, const IntFloat32& b) { return a.i != b.i; }

	UInt32 GetUInt() const { return (UInt32)i; }

	union
	{
		Int32 i;
		Float32 f;
	};
};

//----------------------------------------------------------------------------------------
/// This structure is used to map an integer and a floating point value to the same memory location.
/// A stucture is used since gcc outputs a warning if you do something like *((Int64*)&myFloat64Value).
//----------------------------------------------------------------------------------------
struct IntFloat64
{
	IntFloat64() = default;
	explicit IntFloat64(Int64 a) { i = a; }
	explicit IntFloat64(UInt64 a) { i = (Int64)a; }
	explicit IntFloat64(Float64 a) { f = a; }
	const IntFloat64& operator = (const IntFloat64& other) { i = other.i; return *this; }

	// Compare the integer values here for a binary comparison. 
	// Comparing the float values would return true for 1.001e-42#DEN == 0.0.
	friend Bool operator == (const IntFloat64& a, const IntFloat64& b) { return a.i == b.i; }
	friend Bool operator != (const IntFloat64& a, const IntFloat64& b) { return a.i != b.i; }

	UInt64 GetUInt() const { return (UInt64)i; }

	union
	{
		Int64 i;
		Float64 f;
	};
};

} // namespace maxon

#endif // INTFLOAT_H__
