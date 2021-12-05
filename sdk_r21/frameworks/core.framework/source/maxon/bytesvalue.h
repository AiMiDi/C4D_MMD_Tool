#ifndef BYTESVALUE_H__
#define BYTESVALUE_H__

#include "maxon/apibase.h"
#include "maxon/datatype.h"

namespace maxon
{

/// @addtogroup BYTE Size
/// @{

//----------------------------------------------------------------------------------------
/// The BytesValue class encapsulates the byte size.
//----------------------------------------------------------------------------------------
class BytesValue
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor
	//----------------------------------------------------------------------------------------
	BytesValue() : _value(Int64(0))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default constructor
	//----------------------------------------------------------------------------------------
	BytesValue(const BytesValue& src) : _value(src._value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Assignment operator
	//----------------------------------------------------------------------------------------
	BytesValue& operator =(const BytesValue& src)
	{
		_value = src._value;																		// self assignment is no problem here, therefore no check if (this != &src)
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two BytesValue
	//----------------------------------------------------------------------------------------
	Bool operator ==(const BytesValue b) const
	{
		return _value == b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two BytesValue
	//----------------------------------------------------------------------------------------
	Bool operator <(const BytesValue b) const
	{
		return _value < b._value;
	}

	MAXON_OPERATOR_COMPARISON(BytesValue)

	//----------------------------------------------------------------------------------------
	/// Adds two BytesValue
	//----------------------------------------------------------------------------------------
	BytesValue operator +(const BytesValue b) const
	{
		return BytesValue(_value + b._value);
	}

	//----------------------------------------------------------------------------------------
	/// Adds two BytesValue
	//----------------------------------------------------------------------------------------
	BytesValue& operator +=(const BytesValue b)
	{
		_value += b._value;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two BytesValue
	//----------------------------------------------------------------------------------------
	BytesValue operator -(const BytesValue b) const
	{
		return BytesValue(_value - b._value);
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two BytesValue
	//----------------------------------------------------------------------------------------
	const BytesValue& operator -=(const BytesValue b)
	{
		_value -= b._value;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two BytesValue
	//----------------------------------------------------------------------------------------
	Bool operator >=(const BytesValue b)
	{
		return _value >= b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two BytesValue
	//----------------------------------------------------------------------------------------
	Bool operator <=(const BytesValue b)
	{
		return _value <= b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two BytesValue
	//----------------------------------------------------------------------------------------
	Bool operator >(const BytesValue b)
	{
		return _value > b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two BytesValue
	//----------------------------------------------------------------------------------------
	Bool operator <(const BytesValue b)
	{
		return _value < b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Compares the BytesValue with an Int64
	//----------------------------------------------------------------------------------------
	Bool operator >=(const Int64 b)
	{
		return _value >= b;
	}

	//----------------------------------------------------------------------------------------
	/// Compares the BytesValue with an Int64
	//----------------------------------------------------------------------------------------
	Bool operator <=(const Int64 b)
	{
		return _value <= b;
	}

	//----------------------------------------------------------------------------------------
	/// Compares the BytesValue with an Int64
	//----------------------------------------------------------------------------------------
	Bool operator >(const Int64 b)
	{
		return _value > b;
	}

	//----------------------------------------------------------------------------------------
	/// Compares the BytesValue with an Int64
	//----------------------------------------------------------------------------------------
	Bool operator <(const Int64 b)
	{
		return _value < b;
	}

	operator Int64() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a BytesValue with a factor.
	/// @param[in] b									The second factor.
	/// @return												The result of this * b.
	//----------------------------------------------------------------------------------------
	BytesValue& operator *=(const Int64 b)
	{
		_value *= b;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a BytesValue with a factor.
	/// @param[in] a									The first factor.
	/// @param[in] b									The second factor.
	/// @return												The result of a * b.
	//----------------------------------------------------------------------------------------
	inline friend BytesValue operator *(const BytesValue a, const Int64 b)
	{
		return BytesValue(a._value * b);
	}

	//----------------------------------------------------------------------------------------
	/// Divides two BytesValue and returns the quotient.
	/// @param[in] a									The dividend.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be undefined (floating point exception).
	/// @return												The result of a / b, the quotient has unit therefore it is returned as Int64.
	//----------------------------------------------------------------------------------------
	inline friend Int64 operator /(const BytesValue a, const BytesValue b)
	{
		DebugAssert(b._value > 0, "Division by zero");
		return b._value == 0 ? 0 : a._value / b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Divides a BytesValue by a scalar and returns the quotient.
	/// @param[in] a									The dividend.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be undefined (floating point exception).
	/// @return												The result of a / b.
	//----------------------------------------------------------------------------------------
	inline friend BytesValue operator /(const BytesValue a, const Int64 b)
	{
		DebugAssert(b > 0, "Division by zero");
		return BytesValue(b == 0 ? 0 : a._value / b);
	}


	//----------------------------------------------------------------------------------------
	/// Return the number of bits.
	/// @return												value in bits
	//----------------------------------------------------------------------------------------
	Int64 GetBits() const
	{
		return _value << 3;
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in bytes
	//----------------------------------------------------------------------------------------
	Int64 GetBytes() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Set the BytesValue
	/// @param[in] bytes							byte value
	//----------------------------------------------------------------------------------------
	void SetBytes(Int64 bytes)
	{
		_value = bytes;
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in kilobytes (KB)
	//----------------------------------------------------------------------------------------
	Float32 GetKilobytes() const
	{
		return _value * Float32(0.001);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in kibibytes (KiB)
	//----------------------------------------------------------------------------------------
	Float32 GetKibibytes() const
	{
		return _value / Float32(1024);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in megabytes (MB)
	//----------------------------------------------------------------------------------------
	Float32 GetMegabytes() const
	{
		return _value * Float32(0.001) * Float32(0.001);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in mebibytes (MiB)
	//----------------------------------------------------------------------------------------
	Float32 GetMebibytes() const
	{
		return _value / Float32(1024) / Float32(1024);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in gigabytes (GB)
	//----------------------------------------------------------------------------------------
	Float32 GetGigabytes() const
	{
		return _value * Float32(0.001) * Float32(0.001) * Float32(0.001);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in gibibytes (GiB)
	//----------------------------------------------------------------------------------------
	Float32 GetGibibytes() const
	{
		return _value / Float32(1024) / Float32(1024) / Float32(1024);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in terrabytes (TB)
	//----------------------------------------------------------------------------------------
	Float32 GetTerabytes() const
	{
		return _value * Float32(0.001) * Float32(0.001) * Float32(0.001) * Float32(0.001);
	}

	//----------------------------------------------------------------------------------------
	/// Get the BytesValue
	/// @return												value in tebibytes (TiB)
	//----------------------------------------------------------------------------------------
	Float32 GetTebibytes() const
	{
		return _value / Float32(1024) / Float32(1024) / Float32(1024) / Float32(1024);
	}

	//----------------------------------------------------------------------------------------
	/// Converts the value into a string.
	/// @param[in] formatStatement		Nullptr or an additional formatting instruction. See also @ref format_timer.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	UInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(_value);
	}

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

protected:
	explicit BytesValue(Int64 bytes) : _value(bytes)
	{
	}

private:
	Int64 _value;
};

//----------------------------------------------------------------------------------------
/// Byte value in bytes.
//----------------------------------------------------------------------------------------
class Bytes : public BytesValue
{
public:
	explicit Bytes(Int64 bytes) : BytesValue(bytes)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in kilobytes.
//----------------------------------------------------------------------------------------
class Kilobytes : public BytesValue
{
public:
	explicit Kilobytes(Int32 kilobytes) : BytesValue(Int64(kilobytes) * 1000)
	{
	}
	explicit Kilobytes(Int64 kilobytes) : BytesValue(kilobytes * 1000)
	{
	}
	explicit Kilobytes(Float kilobytes) : BytesValue((Int64)(kilobytes * 1000.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in kibibytes.
//----------------------------------------------------------------------------------------
class Kibibytes : public BytesValue
{
public:
	explicit Kibibytes(Int32 kibibytes) : BytesValue(Int64(kibibytes) * 1024)
	{
	}
	explicit Kibibytes(Int64 kibibytes) : BytesValue(kibibytes * 1024)
	{
	}
	explicit Kibibytes(Float kibibytes) : BytesValue((Int64)(kibibytes * 1024.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in mebibytes.
//----------------------------------------------------------------------------------------
class Mebibytes : public BytesValue
{
public:
	explicit Mebibytes(Int32 mebibytes) : BytesValue(Int64(mebibytes) * 1024 * 1024)
	{
	}
	explicit Mebibytes(Int64 mebibytes) : BytesValue(mebibytes * 1024 * 1024)
	{
	}
	explicit Mebibytes(Float mebibytes) : BytesValue((Int64)(mebibytes * 1024.0_f * 1024.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in megabytes.
//----------------------------------------------------------------------------------------
class Megabytes : public BytesValue
{
public:
	explicit Megabytes(Int32 megabytes) : BytesValue(Int64(megabytes) * 1000 * 1000)
	{
	}
	explicit Megabytes(Int64 megabytes) : BytesValue(megabytes * 1000 * 1000)
	{
	}
	explicit Megabytes(Float megabytes) : BytesValue((Int64)(megabytes * 1000.0_f * 1000.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in kilobytes.
//----------------------------------------------------------------------------------------
class Gibibytes : public BytesValue
{
public:
	explicit Gibibytes(Int32 gibibytes) : BytesValue(Int64(gibibytes) * 1024 * 1024 * 1024)
	{
	}
	explicit Gibibytes(Int64 gibibytes) : BytesValue(gibibytes * 1024 * 1024 * 1024)
	{
	}
	explicit Gibibytes(Float gibibytes) : BytesValue((Int64)(gibibytes * 1024.0_f * 1024.0_f * 1024.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in gigabytes.
//----------------------------------------------------------------------------------------
class Gigabytes : public BytesValue
{
public:
	explicit Gigabytes(Int32 gigabytes) : BytesValue(Int64(gigabytes) * 1000 * 1000 * 1000)
	{
	}
	explicit Gigabytes(Int64 gigabytes) : BytesValue(gigabytes * 1000 * 1000 * 1000)
	{
	}
	explicit Gigabytes(Float gigabytes) : BytesValue((Int64)(gigabytes * 1000.0_f * 1000.0_f * 1000.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in terabytes.
//----------------------------------------------------------------------------------------
class Terabytes : public BytesValue
{
public:
	explicit Terabytes(Int32 terabytes) : BytesValue(Int64(terabytes) * 1000 * 1000 * 1000 * 1000)
	{
	}
	explicit Terabytes(Int64 terabytes) : BytesValue(terabytes * 1000 * 1000 * 1000 * 1000)
	{
	}
	explicit Terabytes(Float terabytes) : BytesValue((Int64)(terabytes * 1000.0_f * 1000.0_f * 1000.0_f * 1000.0_f + 0.5_f))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Byte value in Gib.
//----------------------------------------------------------------------------------------
class Tebibytes : public BytesValue
{
public:
	explicit Tebibytes(Int32 tebibytes) : BytesValue(Int64(tebibytes) * 1024 * 1024 * 1024 * 1024)
	{
	}
	explicit Tebibytes(Int64 tebibytes) : BytesValue(tebibytes * 1024 * 1024 * 1024 * 1024)
	{
	}
	explicit Tebibytes(Float tebibytes) : BytesValue((Int64)(tebibytes * 1024.0_f * 1024.0_f * 1024.0_f * 1024.0_f + 0.5_f))
	{
	}
};

/// @}

MAXON_DATATYPE(BytesValue, "net.maxon.datatype.bytesvalue");

} // namespace maxon

#endif // BYTESVALUE_H__
