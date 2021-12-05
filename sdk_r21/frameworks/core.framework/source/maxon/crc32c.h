#ifndef CRC32C_H__
#define CRC32C_H__

#include "maxon/intfloat.h"
#include "maxon/sse_general.h"
#include "maxon/cpuid.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This class implements a CRC32C generator which is based on the generator polynom
/// x^32+x^28+x^27+x^26+x^25+x^23+x^22+x^20+x^19+x^18+x^14+x^13+x^11+x^10+x^9+x^8+x^6+1
/// 0x11EDC6F41 (the iSCSI CRC).
/// If available the SSE4.2 instructions are used, otherwise it will be calculated by software. The returned CRC value is equal for all machines.
/// All these examples should deliver the same result per line (0xcdee067a) on all systems:
/// UpdateUInt64(0x1234567890abcdef)
/// UpdateUInt32(0x90abcdef) UpdateUInt32(0x12345678)
/// UpdateUInt16(0xcdef) UpdateUInt32(0x567890ab) UpdateUInt16(0x1234)
/// UpdateUChar(0xef) UpdateUChar(0xcd) UpdateUInt32(0x567890ab) UpdateUChar(0x34) UpdateUChar(0x12)
/// UInt64 val = 0x1234567890abcdef Update(&val, 8)
/// see http://drdobbs.com/cpp/229401411 and http://download.intel.com/design/intarch/papers/323405.pdf for a parallelized CRC
//----------------------------------------------------------------------------------------
class Crc32C
{
protected:
	/// The CRC value that is accumulated
	UInt32 _crc;
	static const UInt32 RESET_VALUE = 0xffffffff;

	/// A helper table for the software CRC
	static const UInt32 crc32tab_o32[256];
	static const UInt32 crc32tab_o40[256];
	static const UInt32 crc32tab_o48[256];
	static const UInt32 crc32tab_o56[256];
	static const UInt32 crc32tab_o64[256];
	static const UInt32 crc32tab_o72[256];
	static const UInt32 crc32tab_o80[256];
	static const UInt32 crc32tab_o88[256];

public:
	/// Constructs the object and resets its state.
	Crc32C()
	{
		_crc = RESET_VALUE;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets its state to a certain value.
	/// @param[in] u									The initial value.
	//----------------------------------------------------------------------------------------
	explicit Crc32C(UInt32 u)
	{
		_crc = u ^ 0xffffffff;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the CRC value.
	/// @return												The CRC value.
	//----------------------------------------------------------------------------------------
	UInt32 GetCrc() const
	{
		return _crc ^ 0xffffffff;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the state of this instance.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_crc = RESET_VALUE;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the objects and resets its state.
	/// @param[in] u									The new state value.
	//----------------------------------------------------------------------------------------
	void Set(UInt32 u)
	{
		_crc = u ^ 0xffffffff;
	}

	//----------------------------------------------------------------------------------------
	/// Checks for equality.
	/// @param[in] a									First operand.
	/// @param[in] b									Second operand.
	/// @return												True, if both are equal.
	//----------------------------------------------------------------------------------------
	friend Bool operator == (const Crc32C& a, const Crc32C& b)
	{
		return a._crc == b._crc;
	}

	//----------------------------------------------------------------------------------------
	/// Checks for inequality.
	/// @param[in] a									First operand.
	/// @param[in] b									Second operand.
	/// @return												True, if both are equal.
	//----------------------------------------------------------------------------------------
	friend Bool operator != (const Crc32C& a, const Crc32C& b)
	{
		return !(a._crc == b._crc);
	}

	//----------------------------------------------------------------------------------------
	/// Assigns another value.
	/// @param[in] other							The new value.
	/// @return												A reference to itself.
	//----------------------------------------------------------------------------------------
	const Crc32C& operator = (const Crc32C& other)
	{
		_crc = other._crc;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the internal value of a reset class.
	/// @return												The reset value.
	//----------------------------------------------------------------------------------------
	static constexpr UInt32 GetResetValue()
	{
		return RESET_VALUE;
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] u									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateUInt64(UInt64 u)
	{
#ifdef C4D_HAS_SSE4_CAPABILITY
		if (MAXON_LIKELY(g_hasSSE4_2))
		{
			UInt64 c = _crc;
			c = _mm_crc32_u64(c, u);
			_crc = (UInt32)c;
		}
		else
#endif
		{
			UInt32 c = _crc;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8);
			_crc = c;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] u									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateUInt32(UInt32 u)
	{
#ifdef C4D_HAS_SSE4_CAPABILITY
		if (MAXON_LIKELY(g_hasSSE4_2))
		{
			_crc = _mm_crc32_u32(_crc, u);
		}
		else
#endif
		{
			UInt32 c = _crc;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8);
			_crc = c;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] u									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateUInt16(UInt16 u)
	{
#ifdef C4D_HAS_SSE4_CAPABILITY
		if (MAXON_LIKELY(g_hasSSE4_2))
		{
			_crc = _mm_crc32_u8(_crc, u & 0xff);
			_crc = _mm_crc32_u8(_crc, (u >> 8) & 0xff);
		}
		else
#endif
		{
			UInt32 c = _crc;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8); u >>= 8;
			c = crc32tab_o32[UChar(c ^ (u & 0xff))] ^ (c >> 8);
			_crc = c;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] u									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateUChar(UChar u)
	{
#ifdef C4D_HAS_SSE4_CAPABILITY
		if (MAXON_LIKELY(g_hasSSE4_2))
		{
			_crc = _mm_crc32_u8(_crc, u);
		}
		else
#endif
		{
			UInt32 c = _crc;
			c = crc32tab_o32[UChar(c ^ u)] ^ (c >> 8);
			_crc = c;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] mem								A raw memory buffer.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void Update(const Block<const Byte>& mem)
	{
		UInt32 c;
		Int x;
		const UChar* d = (const UChar*)mem.GetFirst();
		Int n = mem.GetCount();

#ifdef C4D_HAS_SSE4_CAPABILITY
		if (MAXON_LIKELY(g_hasSSE4_2))
		{
			UInt64 c64;

			// calculate to a 4-byte alignment
			c = _crc;
			x = UInt(d) & 3;
			if (x)
			{
				x = 4 - x;
				if (x > n)
					x = n;
				n -= x;
				while (x--)
					c = _mm_crc32_u8(c, *d++);
			}

			// calculate to a 8-byte alignment, the lower 2 bits of d are always 0. If the 3rd bit is set we are 4-byte aligned, otherwise 8.
			if ((UInt(d) & 7) && n >= 4)
			{
				c = _mm_crc32_u32(c, *((const UInt32*)d));
				n -= 4;
				d += 4;
			}

			// d is 8-byte aligned here
			x = n & ~7;
			if (x)
			{
				c64 = (UInt64)c;
				while (x)
				{
					c64 = _mm_crc32_u64(c64, *((const UInt64*)d));
					x -= 8;
					d += 8;
				}
				c = (UInt32)c64;
				n &= 7;
			}

			// calculate the remaining bytes
			if (n >= 4)
			{
				c = _mm_crc32_u32(c, *((const UInt32*)d));
				n -= 4;
				d += 4;
			}

			while (n--)
				c = _mm_crc32_u8(c, *d++);

			_crc = c;
		}
		else
#endif
		{
			UInt32 u32, term1, term2;

			// calculate to a 4-byte alignment
			c = _crc;
			x = UInt(d) & 3;
			if (x)
			{
				x = 4 - x;
				if (x > n)
					x = n;
				n -= x;
				while (x--)
					c = crc32tab_o32[UChar(c ^ *d++)] ^ (c >> 8);
			}

			// calculate to a 8-byte alignment, the lower 2 bits of d are always 0. If the 3rd bit is set we are 4-byte aligned, otherwise 8.
			if ((UInt(d) & 7) && n >= 4)
			{
				u32 = *((const UInt32*)d);
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8); u32 >>= 8;
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8); u32 >>= 8;
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8); u32 >>= 8;
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8);
				n -= 4;
				d += 4;
			}

			// d is 8-byte aligned here
			x = n & ~7;
			if (x)
			{
				while (x)
				{
					u32 = *((const UInt32*)d);
					c ^= u32;
					d += 4;
					term1 = crc32tab_o88[c & 0xff] ^ crc32tab_o80[(c >> 8) & 0xff];
					term2 = c >> 16;
					c = term1 ^ crc32tab_o72[term2 & 0xff] ^ crc32tab_o64[(term2 >> 8) & 0xff];
					term1 = crc32tab_o56[(*(UInt32*)d) & 0xff] ^ crc32tab_o48[((*(UInt32*)d) >> 8) & 0xff];

					term2 = (*(UInt32*)d) >> 16;
					c =	c ^ term1 ^ crc32tab_o40[term2  & 0xff] ^	crc32tab_o32[(term2 >> 8) & 0xff];
					d += 4;
					x -= 8;
				}
				n &= 7;
			}

			// calculate the remaining bytes
			if (n >= 4)
			{
				u32 = *((const UInt32*)d);
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8); u32 >>= 8;
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8); u32 >>= 8;
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8); u32 >>= 8;
				c = crc32tab_o32[UChar(c ^ (u32 & 0xff))] ^ (c >> 8);
				n -= 4;
				d += 4;
			}

			while (n--)
				c = crc32tab_o32[UChar(c ^ *d++)] ^ (c >> 8);

			_crc = c;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] u									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateUInt(UInt u)
	{
#ifdef MAXON_TARGET_64BIT
		UpdateUInt64(u);
#else
		UpdateUInt32(u);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] i									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateInt64(Int64 i)
	{
		UpdateUInt64((UInt64)i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] i									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateInt32(Int32 i)
	{
		UpdateUInt32((UInt32)i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] i									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateInt16(Int16 i)
	{
		UpdateUInt16((UInt16)i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] i									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateInt(Int i)
	{
		UpdateUInt((UInt)i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] i									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateChar(Char i)
	{
		UpdateUChar((UChar)i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] b									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateBool(Bool b)
	{
		UpdateUChar(b ? 1 : 0);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateFloat32(Float32 r)
	{
		IntFloat32 c;
		c.f = r;
		UpdateUInt32(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateFloat64(Float64 r)
	{
		IntFloat64 c;
		c.f = r;
		UpdateUInt64(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateFloat(Float r)
	{
#ifdef MAXON_TARGET_SINGLEPRECISION
		IntFloat32 c;
		c.f = r;
		UpdateUInt32(c.i);
#else
		IntFloat64 c;
		c.f = r;
		UpdateUInt64(c.i);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector2d32(const Vector2d32& r)
	{
		IntFloat32 c;
		c.f = r.x;
		UpdateUInt32(c.i);
		c.f = r.y;
		UpdateUInt32(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector32(const Vector32& r)
	{
		IntFloat32 c;
		// This function is not calling UpdateUInt32 for each vector component by intention. The compiler would store the 
		// _crc member in the memory while it can be kept in the register between the calls.
#ifdef C4D_HAS_SSE4_CAPABILITY
		if (MAXON_LIKELY(g_hasSSE4_2))
		{
			c.f = r.x;
			UInt32 crc = _mm_crc32_u32(_crc, (UInt32)c.i);
			c.f = r.y;
			crc = _mm_crc32_u32(crc, (UInt32)c.i);
			c.f = r.z;
			_crc = _mm_crc32_u32(crc, (UInt32)c.i);
		}
		else
#endif
		{
			UInt32 crc = _crc;

			c.f = r.x;
			UInt32 u = (UInt32)c.i;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8);

			c.f = r.y;
			u = (UInt32)c.i;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8);

			c.f = r.z;
			u = (UInt32)c.i;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8); u >>= 8;
			crc = crc32tab_o32[UChar(crc ^ (u & 0xff))] ^ (crc >> 8);

			_crc = crc;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector4d32(const Vector4d32& r)
	{
		IntFloat32 c;
		c.f = r.x;
		UpdateUInt32(c.i);
		c.f = r.y;
		UpdateUInt32(c.i);
		c.f = r.z;
		UpdateUInt32(c.i);
		c.f = r.w;
		UpdateUInt32(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector2d64(const Vector2d64& r)
	{
		IntFloat64 c;
		c.f = r.x;
		UpdateUInt64(c.i);
		c.f = r.y;
		UpdateUInt64(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector64(const Vector64& r)
	{
		IntFloat64 c;
		c.f = r.x;
		UpdateUInt64(c.i);
		c.f = r.y;
		UpdateUInt64(c.i);
		c.f = r.z;
		UpdateUInt64(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector4d64(const Vector4d64& r)
	{
		IntFloat64 c;
		c.f = r.x;
		UpdateUInt64(c.i);
		c.f = r.y;
		UpdateUInt64(c.i);
		c.f = r.z;
		UpdateUInt64(c.i);
		c.f = r.w;
		UpdateUInt64(c.i);
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector2d(const Vector2d& r)
	{
#ifdef MAXON_TARGET_SINGLEPRECISION
		UpdateVector2d32(r);
#else
		UpdateVector2d64(r);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector(const Vector& r)
	{
#ifdef MAXON_TARGET_SINGLEPRECISION
		UpdateVector32(r);
#else
		UpdateVector64(r);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] r									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdateVector4d(const Vector4d& r)
	{
#ifdef MAXON_TARGET_SINGLEPRECISION
		UpdateVector4d32(r);
#else
		UpdateVector4d64(r);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Accumulates the CRC value.
	/// @param[in] p									The value used to accumulate the CRC value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void UpdatePointer(const void* p)
	{
#ifdef MAXON_TARGET_64BIT
		UpdateUInt64((UInt64)p);
#else
		UpdateUInt32((UInt32)p);
#endif
	}

	// the slow software implementation, kept for reference
	/*MAXON_ATTRIBUTE_FORCE_INLINE void Update(const void* s, VLONG n)
	{
		register UInt32 c = _crc;
		register const unsigned char* d = (const unsigned char*)s;
		while (n--)
			c = crc32tab_o32[UChar(c ^ *d++)] ^ (c >> 8);
		_crc = c;
	}*/
};

static_assert(SIZEOF(Crc32C) == SIZEOF(UInt32), "size mismatch");

} // namespace maxon

#endif // CRC32C_H__
