#ifndef SSE_VECTOR_4I32_H__
#define SSE_VECTOR_4I32_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

namespace maxon
{

class Vector4f32;

//----------------------------------------------------------------------------------------
/// The class and the default constructor are always defined. The functions of this class are only defined when C4D_HAS_SSE2_CAPABILITY is set. Instances of this class must be aligned to 16 bytes.
/// The layout in the memory is as follows:
/// address		+ 0		+ 1		+ 2		+ 3
/// 					R0		R1		R2		R3
//----------------------------------------------------------------------------------------
class Vector4i32
{
	friend Vector4f32 CastToVector4f32(const Vector4i32& a);
	friend Vector4f32 ConvertToVector4f32(const Vector4i32& a);
	friend Vector4i32 CastToVector4i32(const Vector4f32& a);
	friend Vector4i32 ConvertToVector4i32(const Vector4f32& a);
public:
	/// Constructs the object. It does not set a default value.
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32()
	{
	}

#ifdef C4D_HAS_SSE2_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object with an SSE vector.
	/// @param[in] i									The SSE vector used to initialize this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4i32(__m128i i)
	{
		_val = i;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to i.
	/// @param[in] i									The value that is assigned to all vector elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4i32(Int32 i)
	{
		_val = (!i) ? _mm_setzero_si128() : _mm_set1_epi32(i);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to i0...i3.
	/// @param[in] i0									The value that is assigned to vector element 0.
	/// @param[in] i1									The value that is assigned to vector element 1.
	/// @param[in] i2									The value that is assigned to vector element 2.
	/// @param[in] i3									The value that is assigned to vector element 3.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4i32(Int32 i0, Int32 i1, Int32 i2, Int32 i3)
	{
		_val = _mm_set_epi32(i3, i2, i1, i0);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Int32* p)
	{
		_val = _mm_loadu_si128((const __m128i*)p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Int32* p)
	{
		_val = _mm_load_si128((const __m128i*)p);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Int32* p) const
	{
		_mm_storeu_si128((__m128i*)p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored. It must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Int32* p) const
	{
		_mm_store_si128((__m128i*)p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the Int32ernal SSE vector.
	/// @return												The Int32ernal SSE vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE __m128i Get() const
	{
		return _val;
	}

	//----------------------------------------------------------------------------------------
	/// Adds two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator +(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_add_epi32(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds an Int32 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator +(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_add_epi32(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Adds an Int32 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator +(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_add_epi32(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator -(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_sub_epi32(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts an Int32 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator -(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_sub_epi32(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts each vector component from a vectorized Int32
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator -(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_sub_epi32(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiply two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The result of a * b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator *(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(Multiply(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiply an Int32 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The result of a * b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator *(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(Multiply(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Multiply each vector component with a vectorized Int32
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The result of a * b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator *(Int32 a, const Vector4i32& b)
	{
		return Vector4i32(Multiply(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector to this.
	/// @param[in] a									The vector to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32& operator +=(const Vector4i32& a)
	{
		_val = _mm_add_epi32(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Int32 to each vector component of this.
	/// @param[in] a									The Int32 to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32& operator +=(Int32 a)
	{
		_val = _mm_add_epi32(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector from this.
	/// @param[in] a									The vector to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32& operator -=(const Vector4i32& a)
	{
		_val = _mm_sub_epi32(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts the whole vector left. Note that the template argument must be a numeric constant.
	/// SSE2
	/// @param[in] a									Input vector.
	/// @tparam imm										Defines the number of bytes to shift left.
	/// @return												The shifted vector.
	//----------------------------------------------------------------------------------------
	template <Int32 imm> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 ShiftLeft(const Vector4i32 &a)
	{
		return Vector4i32(_mm_slli_si128(a._val, imm));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Int32 from each vector component of this.
	/// @param[in] a									The Int32 to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32& operator -=(Int32 a)
	{
		_val = _mm_sub_epi32(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a vector with this.
	/// @param[in] a									The vector to multiply.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32& operator *=(const Vector4i32& a)
	{
		_val = Multiply(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies an Int32 with each vector component of this.
	/// @param[in] a									The Int32 to multiply.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32& operator *=(Int32 a)
	{
		_val = Multiply(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator ==(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_cmpeq_epi32(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Int32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator ==(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_cmpeq_epi32(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Int32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator ==(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_cmpeq_epi32(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator !=(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_xor_si128(_mm_cmpeq_epi32(a._val, b._val), _mm_set1_epi32(true)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Int32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator !=(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_xor_si128(_mm_cmpeq_epi32(a._val, _mm_set1_epi32(b)), _mm_set1_epi32(true)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Int32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator !=(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_xor_si128(_mm_cmpeq_epi32(_mm_set1_epi32(a), b._val), _mm_set1_epi32(true)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator >(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_cmpgt_epi32(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with an Int32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator >(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_cmpgt_epi32(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares an Int32 with each component of an vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator >(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_cmpgt_epi32(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator <(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_cmplt_epi32(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with an Int32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator <(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_cmplt_epi32(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares an Int32 with each component of an vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator <(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_cmplt_epi32(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator >=(const Vector4i32 &a)
	{
		_val = _mm_cmpgt_epi32(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with an Int32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator >=(Int32 a)
	{
		_val = _mm_cmpgt_epi32(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator <=(const Vector4i32 &a)
	{
		_val = _mm_cmplt_epi32(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with an Int32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator <=(Int32 a)
	{
		_val = _mm_cmplt_epi32(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator &(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_and_si128(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of an Int32 with each component of a vector.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator &(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_and_si128(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of an Int32 with each component of a vector.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator &(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_and_si128(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator |(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_or_si128(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of an Int32 with each component of a vector.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator |(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_or_si128(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of an Int32 with each component of a vector.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator |(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_or_si128(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator ^(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_xor_si128(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of an Int32 with each component of a vector.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator ^(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_xor_si128(a._val, _mm_set1_epi32(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of an Int32 with each component of a vector.
	/// @param[in] a									Input Int32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator ^(Int32 a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_xor_si128(_mm_set1_epi32(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Shifts the 4 signed or unsigned 32-bit integers in a left by count bits while shifting in zeros.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a << b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator <<(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_slli_epi32(a._val, b));
	}

	//----------------------------------------------------------------------------------------
	/// Shifts the 4 signed 32-bit integers in a right by count bits while shifting in the sign bit.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Int32 B.
	/// @return												The component-by-component result of a >> b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 operator >>(const Vector4i32 &a, Int32 b)
	{
		return Vector4i32(_mm_srai_epi32(a._val, b));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator &=(const Vector4i32 &a)
	{
		_val = _mm_and_si128(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of an Int32 with each component of a vector.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator &=(Int32 a)
	{
		_val = _mm_and_si128(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator |=(const Vector4i32 &a)
	{
		_val = _mm_or_si128(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of an Int32 with each component of a vector.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator |=(Int32 a)
	{
		_val = _mm_or_si128(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator ^=(const Vector4i32& a)
	{
		_val = _mm_xor_si128(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of an Int32 with each component of a vector.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator ^=(Int32 a)
	{
		_val = _mm_xor_si128(_val, _mm_set1_epi32(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts the 4 signed or unsigned 32-bit integers in a left by count bits while shifting in zeros.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator <<=(Int32 a)
	{
		_val = _mm_slli_epi32(_val, a);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts the 4 signed 32-bit integers in a right by count bits while shifting in the sign bit.
	/// @param[in] a									Input Int32.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 operator >>=(Int32 a)
	{
		_val = _mm_srai_epi32(_val, a);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements of a vector.
	/// @param[in] a									The vector to build the horizontal sum from.
	/// @return												A vector that contains the sum of all elements of a in each element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4i32 HorizontalAdd(const Vector4i32 &a)
	{
		Vector4i32 ret;
		__m128i x, y;
		x = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(a._val), _mm_castsi128_ps(a._val), _MM_SHUFFLE(1, 0, 1, 0)));
		y = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(a._val), _mm_castsi128_ps(a._val), _MM_SHUFFLE(3, 2, 3, 2)));
		x = _mm_add_epi32(x, y);
		y = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x), _mm_castsi128_ps(x), _MM_SHUFFLE(3, 1, 3, 1)));
		x = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x), _mm_castsi128_ps(x), _MM_SHUFFLE(2, 0, 2, 0)));
		ret._val = _mm_add_epi32(x, y);
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vectors. Note that the template arguments must be numeric constants.
	/// @tparam ma1										Decides which element of vector A becomes the new R0.
	/// @tparam ma2										Decides which element of vector A becomes the new R1.
	/// @tparam mb1										Decides which element of vector B becomes the new R2.
	/// @tparam mb2										Decides which element of vector B becomes the new R3.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												A vector consisting of R0=A[ma1], R1=A[ma2], R2=B[mb1], R3=B[mb2]
	//----------------------------------------------------------------------------------------
	template <Int32 mb2, Int32 mb1, Int32 ma2, Int32 ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 Shuffle(const Vector4i32 &a, const Vector4i32 &b)
	{
		return Vector4i32(_mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(a._val), _mm_castsi128_ps(b._val), _MM_SHUFFLE(mb2, mb1, ma2, ma1))));
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vector. Note that the template arguments must be numeric constants.
	/// @param[in] a									Input vector.
	/// @tparam ma1										Decides which element of vector A becomes the new R0.
	/// @tparam ma2										Decides which element of vector A becomes the new R1.
	/// @tparam ma3										Decides which element of vector A becomes the new R2.
	/// @tparam ma4										Decides which element of vector A becomes the new R3.
	/// @return												A vector consisting of R0=A[ma1], R1=A[ma2], R2=A[ma2], R3=A[ma3]
	//----------------------------------------------------------------------------------------
	template <Int32 ma4, Int32 ma3, Int32 ma2, Int32 ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 Shuffle(const Vector4i32 &a)
	{
		return Vector4i32(_mm_shuffle_epi32(a._val, _MM_SHUFFLE(ma4, ma3, ma2, ma1)));
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int32& operator [](UInt i)
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int32 operator [](UInt i) const
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

protected:
	/// The internal SSE vector
	union { __m128i _val; Int32 v[4]; Int32 x, y, z, w; };

private:
	// Helper function for __m128i multiplication from: http://stackoverflow.com/questions/10500766/sse-multiplication-of-4-32-bit-integers
	static MAXON_ATTRIBUTE_FORCE_INLINE __m128i Multiply(const __m128i& a, const __m128i& b)
	{
	#ifdef C4D_HAS_SSE4_INTRINSICS  // Modern CPU - use SSE 4.1
		return _mm_mullo_epi32(a, b);
	#else                           // Old CPU - use SSE 2
		__m128i tmp1 = _mm_mul_epu32(a, b); // Mul 2, 0
		__m128i tmp2 = _mm_mul_epu32(_mm_srli_si128(a, 4), _mm_srli_si128(b, 4)); // Mul 3, 1
		return _mm_unpacklo_epi32(_mm_shuffle_epi32(tmp1, _MM_SHUFFLE (0, 0, 2, 0)), _mm_shuffle_epi32(tmp2, _MM_SHUFFLE(0, 0, 2, 0))); // Shuffle results to [63 .. 0] and pack
	#endif
	}

#else // C4D_HAS_SSE2_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to i.
	/// @param[in] i									The value that is assigned to all vector elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4i32(Int32 i)
	{
		v[0] = v[1] = v[2] = v[3] = i;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to i0...i3.
	/// @param[in] i0									The value that is assigned to vector element 0.
	/// @param[in] i1									The value that is assigned to vector element 1.
	/// @param[in] i2									The value that is assigned to vector element 2.
	/// @param[in] i3									The value that is assigned to vector element 3.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4i32(Int32 i0, Int32 i1, Int32 i2, Int32 i3)
	{
		v[0] = i0;
		v[1] = i1;
		v[2] = i2;
		v[3] = i3;
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Int32* p)
	{
		for (Int32 i = 0; i < 4; ++i)
			v[i] = p[i];
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Int32* p)
	{
		for (Int32 i = 0; i < 4; ++i)
			v[i] = p[i];
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Int32* p) const
	{
		for (Int32 i = 0; i < 4; ++i)
			p[i] = v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored. It must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Int32* p) const
	{
		for (Int32 i = 0; i < 4; ++i)
			p[i] = v[i];
	}

protected:
	/// The internal SSE vector
	union { Int32 v[4]; Int32 x, y, z, w; };

#endif // C4D_HAS_SSE2_CAPABILITY
};

} // namespace maxon

#endif // SSE_VECTOR_4I32_H__
