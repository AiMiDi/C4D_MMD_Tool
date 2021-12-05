#ifndef SSE_VECTOR_4F64_H__
#define SSE_VECTOR_4F64_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

namespace maxon
{

class Vector4i64;

//----------------------------------------------------------------------------------------
/// The class and the default constructor are always defined. The functions of this class are only defined when C4D_HAS_AVX_CAPABILITY is set. Instances of this class must be aligned to 32 bytes.
/// The layout in the memory is as follows:
/// address		+ 0		+ 1		+ 2		+ 3
/// 					R0		R1		R2		R3
//----------------------------------------------------------------------------------------
class Vector4f64
{
	friend Vector4f64 CastToVector4f64(const Vector4i64& a);
	friend Vector4f64 ConvertToVector4f64(const Vector4i64& a);
	friend Vector4i64 CastToVector4i64(const Vector4f64& a);
	friend Vector4i64 ConvertToVector4i64(const Vector4f64& a);

public:
	using ValueType = Float64;

	/// Constructs the object. It does not set a default value.
	Vector4f64() = default;

#ifdef C4D_HAS_AVX_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object with an SSE vector.
	/// @param[in] d									The SSE vector used to initialize this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f64(__m256d d)
	{
		_val = d;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f.
	/// @param[in] d									The value that is assigned to all vector elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f64(Float64 d)
	{
		_val = (d == 0.0) ? _mm256_setzero_pd() : _mm256_set1_pd(d);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3.
	/// @param[in] d0									The value that is assigned to vector element 0.
	/// @param[in] d1									The value that is assigned to vector element 1.
	/// @param[in] d2									The value that is assigned to vector element 2.
	/// @param[in] d3									The value that is assigned to vector element 3.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f64(Float64 d0, Float64 d1, Float64 d2, Float64 d3)
	{
		_val = _mm256_set_pd(d3, d2, d1, d0);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float64* p)
	{
		_val = _mm256_loadu_pd(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 32-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float64* p)
	{
		_val = _mm256_load_pd(p);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Float64* p) const
	{
		_mm256_storeu_pd(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored, must be 32-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Float64* p) const
	{
		_mm256_store_pd(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the internal SSE vector.
	/// @return												The internal SSE vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE __m256d Get() const
	{
		return _val;
	}

	//----------------------------------------------------------------------------------------
	/// Adds two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator +(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_add_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float64 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator +(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_add_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float64 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator +(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_add_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator -(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_sub_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float64 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator -(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_sub_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float64 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator -(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_sub_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator *(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_mul_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float64 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator *(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_mul_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float64 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator *(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_mul_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator /(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_div_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides each component of a vector by a Float64
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator /(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_div_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Divides vectorized Float64 by each component of vector
	/// Divides each component of a vector by a Float64
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator /(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_div_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector to this.
	/// @param[in] a									The vector to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator +=(const Vector4f64& a)
	{
		_val = _mm256_add_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float64 to each vector component of this.
	/// @param[in] a									The Float64 to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator +=(const Float64 a)
	{
		_val = _mm256_add_pd(_val, _mm256_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector from this.
	/// @param[in] a									The vector to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator -=(const Vector4f64& a)
	{
		_val = _mm256_sub_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float64 from each vector component of this.
	/// @param[in] a									The Float64 to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator -=(const Float64 a)
	{
		_val = _mm256_sub_pd(_val, _mm256_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a vector with this.
	/// @param[in] a									The vector to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator *=(const Vector4f64& a)
	{
		_val = _mm256_mul_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float64 to each vector component of this.
	/// @param[in] a									The Float64 to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator *=(const Float64 a)
	{
		_val = _mm256_mul_pd(_val, _mm256_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides this by a vector.
	/// @param[in] a									The vector to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator /=(const Vector4f64& a)
	{
		_val = _mm256_div_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides each vector component of this by a Float64
	/// @param[in] a									The Float64 to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator /=(const Float64 a)
	{
		_val = _mm256_div_pd(_val, _mm256_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements of a vector.
	/// @param[in] a									The vector to build the horizontal sum from.
	/// @return												A vector that contains the sum of all elements of a in each element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 HorizontalAdd(const Vector4f64 &a)
	{
		Vector4f64 ret;
		__m256d x, y;
		x = _mm256_permute2f128_pd(a._val, a._val, 1); // 2 3 0 1
		x = _mm256_add_pd(x, a._val); // (2 + 0) (3 + 1) (0 + 2) (1 + 3)
		y = _mm256_unpacklo_pd(x, x); // (2 + 0) (2 + 0) (0 + 2) (0 + 2)
		x = _mm256_unpackhi_pd(x, x); // (3 + 1) (3 + 1) (1 + 3) (1 + 3)
		ret._val = _mm256_add_pd(x, y); // (2 + 0 + 3 + 1) (2 + 0 + 3 + 1) (0 + 2 + 1 + 3) (0 + 2 + 1 + 3)*/
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Performs a multiply-add operation. Make sure to call this function only if fused multiply-add is supported on the target machine.
	/// The function is using the FMA instruction, therefore the result has a higher precision than the result of a * b + c.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @param[in] c									The third operand.
	/// @return												The result of a * b + c.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 MultiplyAdd(const Vector4f64 &a, const Vector4f64 &b, const Vector4f64 &c)
	{
#ifdef C4D_HAS_FMADD_CAPABILITY
		return Vector4f64(_mm256_fmadd_pd(a._val, b._val, c._val));
#else
		return Vector4f64(_mm256_add_pd(_mm256_mul_ps(a._val, b._val), c._val));
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator &(const Vector4f64 &a, const Vector4f64 &b)
	{
		Vector4f64 ret;
		ret._val = _mm256_and_pd(a._val, b._val);
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator &&(const Vector4f64 &a, const Vector4f64 &b)
	{
		Vector4f64 ret;
		ret._val = _mm256_and_pd(a._val, b._val);
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator |(const Vector4f64 &a, const Vector4f64 &b)
	{
		Vector4f64 ret;
		ret._val = _mm256_or_pd(a._val, b._val);
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator ||(const Vector4f64 &a, const Vector4f64 &b)
	{
		Vector4f64 ret;
		ret._val = _mm256_or_pd(a._val, b._val);
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator ^(const Vector4f64 &a, const Vector4f64 &b)
	{
		Vector4f64 ret;
		ret._val = _mm256_xor_pd(a._val, b._val);
		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator &=(const Vector4f64 &a)
	{
		_val = _mm256_and_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator |=(const Vector4f64 &a)
	{
		_val = _mm256_or_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64& operator ^=(const Vector4f64 &a)
	{
		_val = _mm256_xor_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Blends this vector with another one using a mask.
	/// For each vector element, the element of this vector is chosen if the mask element is zero,
	/// and the element of the B vector is chosen if the mask element has all bits set.
	/// If only some of the mask bits are set, the result is undefined.
	/// @param[in] b									Input vector B.
	/// @param[in] mask								Mask vector.
	/// @return												Vector with elements from this or b, depending on mask.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64 Blend(const Vector4f64& b, const Vector4f64& mask) const
	{
		return Vector4f64(_mm256_blendv_pd(_val, b._val, mask._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator <=(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmple_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator <=(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_cmple_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator <=(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmple_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator ==(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpeq_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator ==(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_cmpeq_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator ==(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpeq_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator >=(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpge_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator >=(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_cmpge_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator >=(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpge_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator >(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpgt_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator >(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_cmpgt_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator >(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpgt_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator <(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmplt_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator <(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_cmplt_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator <(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmplt_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator != (const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpneq_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator != (const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_cmpneq_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator != (const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_cmpneq_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												True, if both vectors are identical, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector4f64& a, const Vector4f64& b)
	{
		return _mm256_movemask_pd(_mm256_cmpneq_pd(a._val, b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												True, if each vector component is equal to Float64, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector4f64& a, const Float64 b)
	{
		return _mm256_movemask_pd(_mm256_cmpneq_pd(a._val, _mm256_set1_pd(b))) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												True, if each vector component is equal to Float64, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Float64 a, const Vector4f64& b)
	{
		return _mm256_movemask_pd(_mm256_cmpneq_pd(_mm256_set1_pd(a), b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Min(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_min_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of each vector component compared to Float64.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Min(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_min_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum between a Float64 and each vector component.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Min(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_min_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Max(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_max_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of each vector component compared to a Float64.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Max(const Vector4f64 &a, const Float64 b)
	{
		return Vector4f64(_mm256_max_pd(a._val, _mm256_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum between a Float64 and each vector component.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Max(const Float64 a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_max_pd(_mm256_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the mask of the most significant bits (i.e. the sign bits). Bit n is set if Rn is negative.
	/// @return												The mask of the most significant bits (i.e. the sign bits).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE int GetMSBMask() const
	{
		return _mm256_movemask_pd(_val);
	}

	template<int B, int A> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64 Shuffle(const Vector4f64& v)
	{
		return Vector4f64(_mm256_permute_pd(v._val, ((int)(((B) << 3) | ((A) << 2) | ((B) << 1) | (A)))));
	}

	template<int A> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64 Shuffle(const Vector4f64& x)
	{
		return Shuffle<A, A>(x);
	}

	template<int B, int A> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64 Shuffle2(const Vector4f64& v)
	{
		return Vector4f64(_mm256_permute2f128_pd(v._val, v._val, ((int)(((B) << 4) | (A)))));
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vectors. Note that the template arguments must be either 0 or 1 and be numeric constants.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @tparam ma01									Decides which element of vector A becomes the new R0. If ma01 is 0, element 0 is copied, otherwise element 1.
	/// @tparam mb01									Decides which element of vector B becomes the new R1. If mb01 is 0, element 0 is copied, otherwise element 1.
	/// @tparam ma23									Decides which element of vector A becomes the new R2. If ma23 is 0, element 2 is copied, otherwise element 3.
	/// @tparam mb23									Decides which element of vector B becomes the new R3. If mb23 is 0, element 2 is copied, otherwise element 3.
	/// @return												A vector consisting of R0=A[ma01 ? 1 : 0], R1=B[mb01 ? 1 : 0], R2=A[ma23 ? 3 : 2], R3=B[mb23 ? 3 : 2].
	//----------------------------------------------------------------------------------------
	template <int mb23, int ma23, int mb01, int ma01> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f64 Shuffle(const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_shuffle_pd(a._val, b._val, (mb23 << 3) | (ma23 << 2) | (mb01 << 1) | (ma01)));
	}

	//----------------------------------------------------------------------------------------
	/// All 0's in the mask become b and 1's become a.
	/// @param[in] mask								Input mask used to mask out components.
	/// @param[in] a									Input vector a.
	/// @param[in] b									Input vector b.
	/// @return												Returns a vector with the mask applied to it.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Select(const Vector4f64& mask, const Vector4f64 &a, const Vector4f64 &b)
	{
		return Vector4f64(_mm256_blendv_pd(b._val, a._val, mask._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the square root.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component square root of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Sqrt(const Vector4f64& a)
	{
		return Vector4f64(_mm256_sqrt_pd(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates reciprocal of each component in the vector.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component reciprocal of vector a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Reciprocal(const Vector4f64& a)
	{
		// TODO: (Mauro) Find a faster way to do this!
		return Vector4f64(1.0) / a;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the absolute value of a vector.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component absolute value a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Abs(const Vector4f64& a)
	{
		__m256i mask = _mm256_set_epi32(0x7fffffff, 0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff, 0xffffffff);
		return Vector4f64(_mm256_and_pd(_mm256_castsi256_pd(mask), a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Return a vector with the sign for each value.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component sign of vector a i.e. 1.0 or -1.0
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 Sign(const Vector4f64& a)
	{
		return Vector4f64(_mm256_blendv_pd(_mm256_set1_pd(1.0), _mm256_set1_pd(-1.0), _mm256_cmp_pd(a._val, _mm256_setzero_pd(), _CMP_NGE_UQ)));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a masked out vector and leaves only the sign.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component masked sign of vector a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 SignMask(const Vector4f64& a)
	{
		__m256i mask = _mm256_set_epi32(0x80000000, 0x00000000, 0x80000000, 0x00000000, 0x80000000, 0x00000000, 0x80000000, 0x00000000);
		return Vector4f64(_mm256_and_pd(a._val, _mm256_castsi256_pd(mask)));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if any component != 0.0.
	/// @param[in] a									The input vector.
	/// @return												Returns true if any of the components is not 0.0.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool Any(const Vector4f64& a)
	{
		return _mm256_movemask_pd(a._val) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if all components are 0.0.
	/// @param[in] a									The input vector.
	/// @return												Returns true all components are 0.0.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool None(const Vector4f64& a)
	{
		return _mm256_movemask_pd(a._val) == 0;
	}

	//----------------------------------------------------------------------------------------
	// Reduction to find the minimum or maximum value in the vector.
	//----------------------------------------------------------------------------------------

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 ReduceMin(const Vector4f64& a)
	{
		const Vector4f64 first = Min(a, Shuffle<0, 1>(a));
		return Min(first, Shuffle2<0, 1>(first));
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 ReduceMax(const Vector4f64& a)
	{
		const Vector4f64 first = Max(a, Shuffle<0, 1>(a));
		return Max(first, Shuffle2<0, 1>(first));
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Int SelectMin(const Vector4f64& mask, const Vector4f64& a)
	{
		const Vector4f64 selected = Select(mask, a, Vector4f64(MAXVALUE_FLOAT64));
		const Vector4f64 validMin	= mask & (selected == ReduceMin(selected));
		const Int32 value					= _mm256_movemask_pd(Any(validMin) ? validMin._val : mask._val);
		Int retValue							= Ctz(value);
		DebugAssert(retValue < 4);
		return retValue;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Int SelectMax(const Vector4f64& mask, const Vector4f64& a)
	{
		const Vector4f64 selected = Select(mask, a, Vector4f64(MINVALUE_FLOAT64));
		const Vector4f64 validMin	= mask & (selected == ReduceMax(selected));
		const Int32 value					= _mm256_movemask_pd(Any(validMin) ? validMin._val : mask._val);
		Int retValue							= Ctz(value);
		DebugAssert(retValue < 4);
		return retValue;
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float64& operator [](UInt i)
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float64 operator [](UInt i) const
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

protected:
	/// The internal SSE vector
	union { __m256d _val; Float64 v[4]; Float64 x, y, z, w; };

private:
	// stylecheck.naming=false

	static inline __m256d _mm256_cmpeq_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_EQ_OQ);
	}

	static inline __m256d _mm256_cmpneq_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_NEQ_UQ);
	}

	static inline __m256d _mm256_cmplt_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_LT_OS);
	}

	static inline __m256d _mm256_cmpge_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_NLT_US); // not less than = greater or equal
	}

	static inline __m256d _mm256_cmple_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_LE_OS);
	}

	static inline __m256d _mm256_cmpgt_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_NLE_US); // not less or equal = greater than
	}

	inline __m256d _mm256_cmpord_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_ORD_Q);
	}

	inline __m256d _mm256_cmpunord_pd(__m256d a, __m256d b)
	{
		return _mm256_cmp_pd(a, b, _CMP_UNORD_Q);
	}

#else
	/// just a dummy that the class has the same size like in the C4D_HAS_AVX_CAPABILITY case

	alignas(32) Float64 _dummy[4]; // dummy to keep the structure size constant

#endif // C4D_HAS_AVX_CAPABILITY
};

} // namespace maxon

#endif // SSE_VECTOR_4F64_H__
