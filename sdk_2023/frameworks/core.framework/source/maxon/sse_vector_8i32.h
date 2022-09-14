#ifndef SSE_VECTOR_8I32_H__
#define SSE_VECTOR_8I32_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

namespace maxon
{

class Vector4f32;
class Vector8i32;

//----------------------------------------------------------------------------------------
/// The class and the default constructor are always defined. The functions of this class are only defined when C4D_HAS_AVX_CAPABILITY is set. Instances of this class must be aligned to 32 bytes.
/// The layout in the memory is as follows:
/// address		+ 0		+ 1		+ 2		+ 3		+ 4		+ 5		+ 6		+ 7
/// 					R0		R1		R2		R3		R4		R5		R6		R7
//----------------------------------------------------------------------------------------
class Vector8i32
{
	/*friend Vector8f32 CastToVector8f32(const Vector8i32& a);
	friend Vector8f32 ConvertToVector8f32(const Vector8i32& a);*/
	friend Vector8f32 CastToVector8f32(const Vector8i32& a);
	/*friend Vector8i32 ConvertToVector8i32(const Vector8f32& a);
	friend void ConvertToVectors4f32(const Vector8f32& a, Vector4f32& result1, Vector4f32& result2);*/
public:
	using ValueType = Int32;

	/// Constructs the object. It does not set a default value.
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8i32()
	{
	}

#ifdef C4D_HAS_AVX_CAPABILITY
	//----------------------------------------------------------------------------------------
	/// Constructs the object with an SSE vector.
	/// @param[in] i									The SSE vector used to initialize this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector8i32(__m256i i)
	{
		_val = i;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f.
	/// @param[in] f									The value that is assigned to all vector elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector8i32(ValueType i)
	{
		_val = (i == 0) ? _mm256_setzero_si256() : _mm256_set1_epi32(i);
	}

	/*
	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3.
	/// @param[in] f0									The value that is assigned to vector element 0.
	/// @param[in] f1									The value that is assigned to vector element 1.
	/// @param[in] f2									The value that is assigned to vector element 2.
	/// @param[in] f3									The value that is assigned to vector element 3.
	/// @param[in] f4									The value that is assigned to vector element 4.
	/// @param[in] f5									The value that is assigned to vector element 5.
	/// @param[in] f6									The value that is assigned to vector element 6.
	/// @param[in] f7									The value that is assigned to vector element 7.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector8f32(Float32 f0, Float32 f1, Float32 f2, Float32 f3, Float32 f4, Float32 f5, Float32 f6, Float32 f7)
	{
		_val = _mm256_set_ps(f7, f6, f5, f4, f3, f2, f1, f0);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3. The Float64 values are automatically converted to Float32.
	/// @param[in] d0									The value that is assigned to vector element 0.
	/// @param[in] d1									The value that is assigned to vector element 1.
	/// @param[in] d2									The value that is assigned to vector element 2.
	/// @param[in] d3									The value that is assigned to vector element 3.
	/// @param[in] d4									The value that is assigned to vector element 4.
	/// @param[in] d5									The value that is assigned to vector element 5.
	/// @param[in] d6									The value that is assigned to vector element 6.
	/// @param[in] d7									The value that is assigned to vector element 7.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector8f32(Float64 d0, Float64 d1, Float64 d2, Float64 d3, Float64 d4, Float64 d5, Float64 d6, Float64 d7)
	{
		__m256d xx = _mm256_set_pd(d3, d2, d1, d0);
		__m256d yy = _mm256_set_pd(d7, d6, d5, d4);
		__m128 aa = _mm256_cvtpd_ps(xx);
		__m128 bb = _mm256_cvtpd_ps(yy);
		__m256 cc = _mm256_castps128_ps256(aa);
		__m256 dd = _mm256_castps128_ps256(bb);
		_val = _mm256_permute2f128_ps(cc, dd, 32);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float32* p)
	{
		_val = _mm256_loadu_ps(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from. It must be 32-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float32* p)
	{
		_val = _mm256_load_ps(p);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Float32* p) const
	{
		_mm256_storeu_ps(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored. It must be 32-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Float32* p) const
	{
		_mm256_store_ps(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the internal SSE vector.
	/// @return												The internal SSE vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE __m256 Get() const
	{
		return _val;
	}

	//----------------------------------------------------------------------------------------
	/// Adds two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator +(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_add_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float32 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator +(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_add_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float32 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator +(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_add_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator -(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_sub_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float32 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator -(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_sub_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float32 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator -(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_sub_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator *(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_mul_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator *(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_mul_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator *(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_mul_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator /(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_div_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides each component of a vector by a Float32
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator /(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_div_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Divides vectorized Float32 by each component of vector
	/// Divides each component of a vector by a Float32
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator /(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_div_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector to this.
	/// @param[in] other							The vector to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator +=(const Vector8f32& other)
	{
		_val = _mm256_add_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float32 to each vector component of this.
	/// @param[in] other							The Float32 to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator +=(const Float32 other)
	{
		_val = _mm256_add_ps(_val, _mm256_set1_ps(other));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector from this.
	/// @param[in] other							The vector to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator -=(const Vector8f32& other)
	{
		_val = _mm256_sub_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float32 from each vector component of this.
	/// @param[in] other							The Float32 to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator -=(const Float32 other)
	{
		_val = _mm256_sub_ps(_val, _mm256_set1_ps(other));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a vector with this.
	/// @param[in] other							The vector to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator *=(const Vector8f32& other)
	{
		_val = _mm256_mul_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 to each vector component of this.
	/// @param[in] other							The Float32 to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator *=(const Float32 other)
	{
		_val = _mm256_mul_ps(_val, _mm256_set1_ps(other));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides this by a vector.
	/// @param[in] other							The vector to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator /=(const Vector8f32& other)
	{
		_val = _mm256_div_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides each vector component of this by a Float32
	/// @param[in] other							The Float32 to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator /=(const Float32 other)
	{
		_val = _mm256_div_ps(_val, _mm256_set1_ps(other));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements of a vector.
	/// @param[in] a									The vector to build the horizontal sum from.
	/// @return												A vector that contains the sum of all elements of a in each element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 HorizontalAdd(const Vector8f32& a)
	{
		__m256 x, y;
		x = _mm256_permute2f128_ps(a._val, a._val, 1); // 4 5 6 7 0 1 2 3
		x = _mm256_add_ps(x, a._val); // (0 + 4) (5 + 1) (6 + 2) (7 + 3) (0 + 4) (1 + 5) (2 + 6) (3 + 7)
		y = _mm256_unpackhi_ps(x, x); // (6 + 2) (6 + 2) (7 + 3) (7 + 3) (2 + 6) (2 + 6) (3 + 7) (3 + 7)
		x = _mm256_unpacklo_ps(x, x); // (0 + 4) (0 + 4) (5 + 1) (5 + 1) (0 + 4) (0 + 4) (1 + 5) (1 + 5)
		x = _mm256_add_ps(x, y); // (6 + 2 + 0 + 4) (6 + 2 + 0 + 4) (7 + 3 + 5 + 1) (7 + 3 + 5 + 1) (2 + 6 + 0 + 4) (2 + 6 + 0 + 4) (3 + 7 + 1 + 5) (3 + 7 + 1 + 5)
		y = _mm256_unpackhi_ps(x, x); // 8 * (7 + 3 + 5 + 1)
		x = _mm256_unpacklo_ps(x, x); // 8 * (6 + 2 + 0 + 4)
		return Vector8f32(_mm256_add_ps(x, y));
	}

	//----------------------------------------------------------------------------------------
	/// Performs a multiply-add operation. Make sure to call this function only if fused multiply-add is supported on the target machine.
	/// The function is using the FMA instruction, therefore the result has a higher precision than the result of a * b + c.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @param[in] c									The third operand.
	/// @return												The result of a * b + c.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 MultiplyAdd(const Vector8f32& a, const Vector8f32& b, const Vector8f32& c)
	{
#ifdef C4D_HAS_FMADD_CAPABILITY
		return Vector8f32(_mm256_fmadd_ps(a._val, b._val, c._val));
#else
		return Vector8f32(_mm256_add_ps(_mm256_mul_ps(a._val, b._val), c._val));
#endif
	}
	*/
	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8i32 operator &(const Vector8i32& a, const Vector8i32& b)
	{
		//return Vector8i32(_mm256_and_si256(a._val, b._val));
		return Vector8i32(_mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(a._val), _mm256_castsi256_ps(b._val))));
	}
	/*
	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator &&(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_and_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator |(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_or_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator ||(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_or_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator ^(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_xor_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] other							Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator &=(const Vector8f32& other)
	{
		_val = _mm256_and_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] other							Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator |=(const Vector8f32& other)
	{
		_val = _mm256_or_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] other							Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32& operator ^=(const Vector8f32& other)
	{
		_val = _mm256_xor_ps(_val, other._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Blends this vector with another one using a mask.
	/// For each vector element, the element of this vector is chosen if the mask element is zero,
	/// and the element of the B vector is chosen if the mask element has all bits set.
	/// If only some of the mask bits are set, the result is undefined.
	/// @param[in] other							Input vector B.
	/// @param[in] mask								Mask vector.
	/// @return												Vector with elements from this or b, depending on mask.
	//----------------------------------------------------------------------------------------
	Vector8f32 Blend(const Vector8f32& other, const Vector8f32& mask) const
	{
		return Vector8f32(_mm256_blendv_ps(_val, other._val, mask._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator <=(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmple_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator <=(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_cmple_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator <=(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmple_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator ==(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpeq_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator ==(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_cmpeq_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator ==(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpeq_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator >=(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpge_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator >=(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_cmpge_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator >=(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpge_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator >(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpgt_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator >(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_cmpgt_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator >(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpgt_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator <(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmplt_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator <(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_cmplt_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator <(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmplt_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator != (const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpneq_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator != (const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_cmpneq_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 operator != (const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_cmpneq_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												True, if both vectors are identical, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector8f32& a, const Vector8f32& b)
	{
		return _mm256_movemask_ps(_mm256_cmpneq_ps(a._val, b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												True, if each vector component is equal to Float32, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector8f32& a, const Float32 b)
	{
		return _mm256_movemask_ps(_mm256_cmpneq_ps(a._val, _mm256_set1_ps(b))) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												True, if each vector component is equal to Float32, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Float32 a, const Vector8f32& b)
	{
		return _mm256_movemask_ps(_mm256_cmpneq_ps(_mm256_set1_ps(a), b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Min(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_min_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of each vector component compared to Float32.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Min(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_min_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum between a Float32 and each vector component.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Min(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_min_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Max(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_max_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of each vector component compared to a Float32.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Max(const Vector8f32& a, const Float32 b)
	{
		return Vector8f32(_mm256_max_ps(a._val, _mm256_set1_ps(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum between a Float32 and each vector component.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Max(const Float32 a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_max_ps(_mm256_set1_ps(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the mask of the most significant bits (i.e. the sign bits). Bit n is set if Rn is negative.
	/// @return												The mask of the most significant bits (i.e. the sign bits).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE int GetMSBMask() const
	{
		return _mm256_movemask_ps(_val);
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vectors. Note that the template arguments must be numeric constants from 0 to 3 each.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @tparam ma1										Decides which element of vector A becomes the new R0. R4 will get the value of A[ma1+4]
	/// @tparam ma2										Decides which element of vector A becomes the new R1. R5 will get the value of A[m21+4]
	/// @tparam mb1										Decides which element of vector B becomes the new R2. R6 will get the value of A[mb1+4]
	/// @tparam mb2										Decides which element of vector B becomes the new R3. R7 will get the value of A[mb2+4]
	/// @return												A vector consisting of R0=A[ma1], R1=A[ma2], R2=B[mb1], R3=B[mb2], R4=A[ma1+4], R5=A[ma2+4], R6=B[mb1+4], R7=B[mb2+4]
	//----------------------------------------------------------------------------------------
	template <int mb2, int mb1, int ma2, int ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32 Shuffle(const Vector8f32& a, const Vector8f32& b)
	{
		return Vector8f32(_mm256_shuffle_ps(a._val, b._val, _MM_SHUFFLE(mb2, mb1, ma2, ma1)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the square root.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component square root of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Sqrt(const Vector8f32& a)
	{
		return Vector8f32(_mm256_sqrt_ps(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the inverse square root.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component inverse square root of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Rsqrt(const Vector8f32& a)
	{
		return Vector8f32(_mm256_rsqrt_ps(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the approximate reciprocal. The result of this function is not precise.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component reciprocal of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Reciprocal(const Vector8f32& a)
	{
		return Vector8f32(_mm256_rcp_ps(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the absolute value of a vector.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component absolute value a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector8f32 Abs(const Vector8f32& a)
	{
		return Vector8f32(_mm256_and_ps(_mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff)), a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float32 operator [](UInt i)
	{
		DebugAssert(i >= 0 && i < 8);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float32 operator [](UInt i) const
	{
		DebugAssert(i >= 0 && i < 8);
		return v[i];
	}
	*/
protected:
	/// The internal SSE vector
	union { __m256i _val; Float32 v[8]; };
	/*
private:
	// stylecheck.naming=false

	static inline __m256 _mm256_cmpeq_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_EQ_OQ);
	}

	static inline __m256 _mm256_cmpneq_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_NEQ_UQ);
	}

	static inline __m256 _mm256_cmplt_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_LT_OS);
	}

	static inline __m256 _mm256_cmpge_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_NLT_US); // not less than = greater or equal
	}

	static inline __m256 _mm256_cmple_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_LE_OS);
	}

	static inline __m256 _mm256_cmpgt_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_NLE_US); // not less or equal = greater than
	}

	inline __m256 _mm256_cmpord_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_ORD_Q);
	}

	inline __m256 _mm256_cmpunord_ps(__m256 aa, __m256 bb)
	{
		return _mm256_cmp_ps(aa, bb, _CMP_UNORD_Q);
	}*/

#else

	alignas(32) ValueType _dummy[8]; // dummy to keep the structure size constant

#endif // #ifdef C4D_HAS_AVX_CAPABILITY
};

} // namespace maxon

#endif // SSE_VECTOR_8I32_H__
