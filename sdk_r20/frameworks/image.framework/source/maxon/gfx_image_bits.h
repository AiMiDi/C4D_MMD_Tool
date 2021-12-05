#ifndef GFX_IMAGE_BITS_H__
#define GFX_IMAGE_BITS_H__

#include "maxon/dataserialize.h"

namespace maxon
{

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// This class represents the number of bits in a pixel format.
//----------------------------------------------------------------------------------------
class BITS
{
public:
	MAXON_ATTRIBUTE_FORCE_INLINE BITS() = default;

	//----------------------------------------------------------------------------------------
	/// Sets the bits of the object. BITS(8) means 8 bit.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BITS(Int bits) : _bits(bits)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of bits.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int Get() const
	{
		return _bits;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of bytes needed for the bits of this object.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetBytes(Int pixelCnt = 1) const
	{
		// trick1: /8 would do complicated signed integer division. >> 3 will do the unsigned integer division.
		// trick2: ((_bits >> 31) & -7) + 7 is the same as (_bits >= 0 ? 7 : 0) but prevents the conditional move completely
		// the original forumla was: (pixelCnt * _bits + (_bits >= 0 ? 7 : 0)) >> 3;
		// -1 >> 3 = -1 ...  -8 >> 3 = -1
		// -9 >> 3 = -2 ..  -16 >> 3 = -2
		return (pixelCnt * _bits + ((_bits >> 31) & -7) + 7) >> 3;
	}

	//----------------------------------------------------------------------------------------
	/// Compares against another BITS value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator == (const BITS& other) const
	{
		return _bits == other._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Compares against another BITS value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator != (const BITS& other) const
	{
		return _bits != other._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Compares against another BITS value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator < (const BITS& other) const
	{
		return _bits < other._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Compares against another BITS value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator <= (const BITS& other) const
	{
		return _bits <= other._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Compares against another BITS value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator > (const BITS& other) const
	{
		return _bits > other._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Compares against another BITS value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator >= (const BITS& other) const
	{
		return _bits >= other._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Add BITS.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BITS operator + (const BITS& other) const
	{
		return BITS(_bits + other._bits);
	}

	//----------------------------------------------------------------------------------------
	/// Sub BITS.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BITS operator - (const BITS& other) const
	{
		return BITS(_bits - other._bits);
	}

	//----------------------------------------------------------------------------------------
	/// Mul BITS.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BITS operator * (const BITS& other) const
	{
		return BITS(_bits * other._bits);
	}

	//----------------------------------------------------------------------------------------
	/// Mul BITS.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BITS operator * (Int other) const
	{
		return BITS(_bits * other);
	}

	//----------------------------------------------------------------------------------------
	/// Div BITS.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BITS operator / (const BITS& other) const
	{
		return BITS(_bits / other._bits);
	}

	//----------------------------------------------------------------------------------------
	/// Convert BITS into String.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

	UInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(_bits);
	}

private:
	Int _bits = 0;
};

MAXON_DATATYPE(BITS, "net.maxon.image.bits");

}

#endif // GFX_IMAGE_BITS_H__
