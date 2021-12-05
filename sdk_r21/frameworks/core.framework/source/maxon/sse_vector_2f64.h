#ifndef SSE_VECTOR_2F64_H__
#define SSE_VECTOR_2F64_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

namespace maxon
{

class Vector4f32;

//----------------------------------------------------------------------------------------
/// The class and the default constructor are always defined. The functions of this class are only defined when C4D_HAS_SSE2_CAPABILITY is set. Instances of this class must be aligned to 16 bytes.
/// The layout in the memory is as follows:
/// address		+ 0		+ 1
/// 					R0		R1
//----------------------------------------------------------------------------------------
class Vector2f64
{
	friend Vector4f32 ConvertToVector4f32(const Vector2f64& a, const Vector2f64& b);
	friend Vector4f32 ConvertToVector4f32(const Vector2f64& a);
	friend void ConvertToVectors2f64(const Vector4f32& a, Vector2f64& result1, Vector2f64& result2);
public:
	using ValueType = Float64;

	/// Constructs the object. It does not set a default value.
	Vector2f64() = default;

#ifdef C4D_HAS_SSE2_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object with an SSE vector.
	/// @param[in] d									The SSE vector used to initialize this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector2f64(__m128d d)
	{
		_val = d;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to d.
	/// @param[in] d									The value that is assigned to all vector elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector2f64(Float64 d)
	{
		_val = (d == 0.0f) ? _mm_setzero_pd() : _mm_set1_pd(d);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3.
	/// @param[in] d0									The value that is assigned to vector element 0.
	/// @param[in] d1									The value that is assigned to vector element 1.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector2f64(Float64 d0, Float64 d1)
	{
		_val = _mm_set_pd(d1, d0);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	/// @param[in] aligned						Should be set to true, if #p is known to be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector2f64(const Float64* p, Bool aligned)
	{
		_val = aligned ? _mm_load_pd(p) : _mm_loadu_pd(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float64* p)
	{
		_val = _mm_loadu_pd(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from. It must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float64* p)
	{
		_val = _mm_load_pd(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a single value from an address in the memory to the lower value of the vector. The upper part is set to zero.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadSingle(const double* p)
	{
		_val = _mm_load_sd(p);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Float64* p) const
	{
		_mm_storeu_pd(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored. It must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Float64* p) const
	{
		_mm_store_pd(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the internal SSE vector.
	/// @return												The internal SSE vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE __m128d Get() const
	{
		return _val;
	}

	//----------------------------------------------------------------------------------------
	/// Adds two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator +(const Vector2f64& a, const Vector2f64& b)
	{
		return Vector2f64(_mm_add_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float64 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator +(const Vector2f64& a, const Float64 b)
	{
		return Vector2f64(_mm_add_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float64 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator +(const Float64 a, const Vector2f64& b)
	{
		return Vector2f64(_mm_add_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator -(const Vector2f64& a, const Vector2f64& b)
	{
		return Vector2f64(_mm_sub_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float64 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator -(const Vector2f64& a, const Float64 b)
	{
		return Vector2f64(_mm_sub_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float64 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator -(const Float64 a, const Vector2f64& b)
	{
		return Vector2f64(_mm_sub_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator *(const Vector2f64& a, const Vector2f64& b)
	{
		return Vector2f64(_mm_mul_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float64 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator *(const Vector2f64& a, const Float64 b)
	{
		return Vector2f64(_mm_mul_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float64 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator *(const Float64 a, const Vector2f64& b)
	{
		return Vector2f64(_mm_mul_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator /(const Vector2f64& a, const Vector2f64& b)
	{
		return Vector2f64(_mm_div_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides each component of a vector by a Float64
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator /(const Vector2f64& a, const Float64 b)
	{
		return Vector2f64(_mm_div_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Divides vectorized Float64 by each component of vector
	/// Divides each component of a vector by a Float64
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator /(const Float64 a, const Vector2f64& b)
	{
		return Vector2f64(_mm_div_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector to this.
	/// @param[in] a									The vector to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator +=(const Vector2f64& a)
	{
		_val = _mm_add_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float64 to each vector component of this.
	/// @param[in] a									The Float64 to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator +=(const Float64 a)
	{
		_val = _mm_add_pd(_val, _mm_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector from this.
	/// @param[in] a									The vector to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator -=(const Vector2f64& a)
	{
		_val = _mm_sub_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float64 from each vector component of this.
	/// @param[in] a									The Float64 to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator -=(const Float64 a)
	{
		_val = _mm_sub_pd(_val, _mm_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a vector with this.
	/// @param[in] a									The vector to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator *=(const Vector2f64& a)
	{
		_val = _mm_mul_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float64 to each vector component of this.
	/// @param[in] a									The Float64 to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator *=(const Float64 a)
	{
		_val = _mm_mul_pd(_val, _mm_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides this by a vector.
	/// @param[in] a									The vector to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator /=(const Vector2f64& a)
	{
		_val = _mm_div_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides each vector component of this by a Float64
	/// @param[in] a									The Float64 to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator /=(const Float64 a)
	{
		_val = _mm_div_pd(_val, _mm_set1_pd(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements of a vector.
	/// @param[in] a									The vector to build the horizontal sum from.
	/// @return												A vector that contains the sum of all elements of a in each element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 HorizontalAdd(const Vector2f64& a)
	{
		__m128d x, y;
		x = _mm_shuffle_pd(a._val, a._val, _MM_SHUFFLE2(1, 0));
		y = _mm_shuffle_pd(a._val, a._val, _MM_SHUFFLE2(0, 1));
		return Vector2f64(_mm_add_pd(x, y));
	}

	//----------------------------------------------------------------------------------------
	/// Performs a multiply-add operation. Make sure to call this function only if fused multiply-add is supported on the target machine.
	/// The function is using the FMA instruction, therefore the result has a higher precision than the result of a * b + c.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @param[in] c									The third operand.
	/// @return												The result of a * b + c.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 MultiplyAdd(const Vector2f64 &a, const Vector2f64 &b, const Vector2f64 &c)
	{
#ifdef C4D_HAS_FMADD_CAPABILITY
		return Vector2f64(_mm_fmadd_pd(a._val, b._val, c._val));
#else
		return Vector2f64(_mm_add_pd(_mm_mul_pd(a._val, b._val), c._val));
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator &(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_and_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator &&(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_and_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator |(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_or_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator ||(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_or_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator ^(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_xor_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator &=(const Vector2f64 &a)
	{
		_val = _mm_and_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator |=(const Vector2f64 &a)
	{
		_val = _mm_or_pd(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64& operator ^=(const Vector2f64 &a)
	{
		_val = _mm_xor_pd(_val, a._val);
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
	MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64 Blend(const Vector2f64& b, const Vector2f64& mask) const
	{
		return Vector2f64(_mm_or_pd(_mm_andnot_pd(mask._val, _val), _mm_and_pd(mask._val, b._val)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator <=(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmple_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator <=(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_cmple_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator <=(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmple_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator ==(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpeq_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator ==(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_cmpeq_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator ==(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpeq_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator >=(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpge_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator >=(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_cmpge_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator >=(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpge_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator >(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpgt_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator >(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_cmpgt_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator >(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpgt_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator <(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmplt_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator <(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_cmplt_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator <(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmplt_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator != (const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpneq_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator != (const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_cmpneq_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 operator != (const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_cmpneq_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												True, if both vectors are identical, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector2f64& a, const Vector2f64& b)
	{
		return _mm_movemask_pd(_mm_cmpneq_pd(a._val, b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float64.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												True, if each vector component is equal to Float64, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector2f64& a, const Float64 b)
	{
		return _mm_movemask_pd(_mm_cmpneq_pd(a._val, _mm_set1_pd(b))) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float64 with each component of a vector.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												True, if each vector component is equal to Float64, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Float64 a, const Vector2f64& b)
	{
		return _mm_movemask_pd(_mm_cmpneq_pd(_mm_set1_pd(a), b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Min(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_min_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of each vector component compared to Float64.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Min(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_min_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum between a Float64 and each vector component.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Min(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_min_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Max(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_max_pd(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of each vector component compared to a Float64.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float64 B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Max(const Vector2f64 &a, const Float64 b)
	{
		return Vector2f64(_mm_max_pd(a._val, _mm_set1_pd(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum between a Float64 and each vector component.
	/// @param[in] a									Input Float64 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Max(const Float64 a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_max_pd(_mm_set1_pd(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the mask of the most significant bits (i.e. the sign bits). Bit n is set if Rn is negative.
	/// @return												The mask of the most significant bits (i.e. the sign bits).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE int GetMSBMask() const
	{
		return _mm_movemask_pd(_val);
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vectors. Note that the template arguments must be numeric constants and be either 0 or 1.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @tparam ma1										Decides which element of vector A becomes the new R0.
	/// @tparam mb1										Decides which element of vector B becomes the new R0.
	/// @return												A vector consisting of R0=A[ma1], R1=B[mb1]
	//----------------------------------------------------------------------------------------
	template <int mb1, int ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector2f64 Shuffle(const Vector2f64 &a, const Vector2f64 &b)
	{
		return Vector2f64(_mm_shuffle_pd(a._val, b._val, _MM_SHUFFLE2(mb1, ma1)));
	}

	//----------------------------------------------------------------------------------------
	/// All 0's in the mask become b and 1's become a.
	/// @param[in] mask								Input mask used to mask out components.
	/// @param[in] a									Input vector a.
	/// @param[in] b									Input vector b.
	/// @return												Returns a vector with the mask applied to it.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Select(const Vector2f64& mask, const Vector2f64& a, const Vector2f64& b)
	{
		return Vector2f64(_mm_or_pd(_mm_and_pd(mask._val, a._val), _mm_andnot_pd(mask._val, b._val)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the square root.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component square root of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Sqrt(const Vector2f64& a)
	{
		return Vector2f64(_mm_sqrt_pd(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the approximate reciprocal. The result of this function is not precise.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component reciprocal of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Reciprocal(const Vector2f64& a)
	{
		return 1.0 / a;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the absolute value of a vector.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component absolute value a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Abs(const Vector2f64& a)
	{
		__m128i mask = _mm_set_epi32(0x7fffffff, int(0xffffffff), 0x7fffffff, int(0xffffffff));
		return Vector2f64(_mm_and_pd(_mm_castsi128_pd(mask), a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Return a vector with the sign for each value.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component sign of vector a i.e. 1.0f or -1.0f.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 Sign(const Vector2f64& a)
	{
		__m128d mask = _mm_cmplt_pd(a._val, _mm_set1_pd(0.0));
		return Vector2f64(_mm_or_pd(_mm_and_pd(mask, _mm_set1_pd(-1.0)), _mm_andnot_pd(mask, _mm_set1_pd(1.0))));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if any component is not 0.0f.
	/// @param[in] a									The input vector.
	/// @return												Returns true if any of the components is not 0.0f.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsAnyNoZero(const Vector2f64& a)
	{
		return _mm_movemask_pd(a._val) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if all components are 0.0f.
	/// @param[in] a									The input vector.
	/// @return												Returns true all components are 0.0f.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool AreAllZero(const Vector2f64& a)
	{
		return _mm_movemask_pd(a._val) == 0;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 ReduceMin(const Vector2f64& a)
	{
		return (a.v[0] < a.v[1]) ? Vector2f64(a.v[0]) : Vector2f64(a.v[1]);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector2f64 ReduceMax(const Vector2f64& a)
	{
		return (a.v[0] > a.v[1]) ? Vector2f64(a.v[0]) : Vector2f64(a.v[1]);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Int SelectMin(const Vector2f64& mask, const Vector2f64& a)
	{
		const Vector2f64 selected = Select(mask, a, Vector2f64(MAXVALUE_FLOAT64));
		const Vector2f64 validMin	= mask & (selected == ReduceMin(selected));
		const Int32 value					= _mm_movemask_pd(IsAnyNoZero(validMin) ? validMin._val : mask._val);
		Int retValue							= Ctz(value);
		DebugAssert(retValue < 2);
		return retValue;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Int SelectMax(const Vector2f64& mask, const Vector2f64& a)
	{
		const Vector2f64 selected = Select(mask, a, Vector2f64(MINVALUE_FLOAT64));
		const Vector2f64 validMin	= mask & (selected == ReduceMax(selected));
		const Int32 value					= _mm_movemask_pd(IsAnyNoZero(validMin) ? validMin._val : mask._val);
		Int retValue							= Ctz(value);
		DebugAssert(retValue < 2);
		return retValue;
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float64& operator [](UInt i)
	{
		DebugAssert(i >= 0 && i < 2);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float64 operator [](UInt i) const
	{
		DebugAssert(i >= 0 && i < 2);
		return v[i];
	}

protected:
	/// The internal SSE vector
	union { __m128d _val; Float64 v[2]; };

#else // C4D_HAS_SSE2_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3.
	/// @param[in] d0									The value that is assigned to vector element 0.
	/// @param[in] d1									The value that is assigned to vector element 1.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector2f64(Float64 d0, Float64 d1)
	{
		v[0] = d0;
		v[1] = d1;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	/// @param[in] aligned						Should be set to true, if #p is known to be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector2f64(const Float64* p, Bool aligned)
	{
		v[0] = p[0];
		v[1] = p[1];
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float64* p)
	{
		for (Int32 i = 0; i < 2; ++i)
			v[i] = p[i];
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from. It must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float64* p)
	{
		for (Int32 i = 0; i < 2; ++i)
			v[i] = p[i];
	}

protected:
	alignas(16) union { Float64 v[2]; };

#endif // C4D_HAS_SSE2_CAPABILITY

};

} // namespace maxon

#endif // SSE_VECTOR_2F64_H__
