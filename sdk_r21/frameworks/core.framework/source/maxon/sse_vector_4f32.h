#ifndef SSE_VECTOR_4F32_H__
#define SSE_VECTOR_4F32_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

namespace maxon
{

class Vector4i32;
class Vector2f64;
#ifdef C4D_HAS_AVX_CAPABILITY
class Vector8f32;
#endif // C4D_HAS_AVX_CAPABILITY
//----------------------------------------------------------------------------------------
/// The class and the default constructor are always defined. The functions of this class are only defined when C4D_HAS_SSE2_CAPABILITY is set. Instances of this class must be aligned to 16 bytes.
/// The layout in the memory is as follows:
/// address		+ 0		+ 1		+ 2		+ 3
/// 					R0		R1		R2		R3
//----------------------------------------------------------------------------------------
class Vector4f32
{
	friend Vector4f32 CastToVector4f32(const Vector4i32& a);
	friend Vector4f32 ConvertToVector4f32(const Vector4i32& a);
	friend Vector4i32 CastToVector4i32(const Vector4f32& a);
	friend Vector4i32 ConvertToVector4i32(const Vector4f32& a);
	friend Vector4f32 ConvertToVector4f32(const Vector2f64& a, const Vector2f64& b);
	friend Vector4f32 ConvertToVector4f32(const Vector2f64& a);
#ifdef C4D_HAS_AVX_CAPABILITY
	friend Vector8f32 ConvertToVector8f32(const Vector4f32& a, const Vector4f32& b);
	friend void ConvertToVectors4f32(const Vector8f32& a, Vector4f32& result1, Vector4f32& result2);
#endif // C4D_HAS_AVX_CAPABILITY
	friend void ConvertToVectors2f64(const Vector4f32& a, Vector2f64& result1, Vector2f64& result2);
public:
	using ValueType = Float32;

	/// Constructs the object. It does not set a default value.
	Vector4f32() = default;

#ifdef C4D_HAS_SSE2_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object with an SSE vector.
	/// @param[in] f									The SSE vector used to initialize this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(__m128 f)
	{
		_val = f;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets the value f.
	/// @param[in] f									The value that is assigned to all vector elements.
	/// @param[in] setAll							If true, all components of the vector are set. Otherwise only the x component is set, the others are zero.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(Float32 f, Bool setAll = true)
	{
		_val = (f == 0.0f) ? _mm_setzero_ps() : (setAll ? _mm_set1_ps(f) : _mm_set_ss(f));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3.
	/// @param[in] f0									The value that is assigned to vector element 0.
	/// @param[in] f1									The value that is assigned to vector element 1.
	/// @param[in] f2									The value that is assigned to vector element 2.
	/// @param[in] f3									The value that is assigned to vector element 3.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(Float32 f0, Float32 f1, Float32 f2, Float32 f3)
	{
		_val = _mm_set_ps(f3, f2, f1, f0);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3. The Float64 values are automatically converted to Float32.
	/// @param[in] d0									The value that is assigned to vector element 0.
	/// @param[in] d1									The value that is assigned to vector element 1.
	/// @param[in] d2									The value that is assigned to vector element 2.
	/// @param[in] d3									The value that is assigned to vector element 3.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(Float64 d0, Float64 d1, Float64 d2, Float64 d3)
	{
		__m128d xx = _mm_set_pd(d0, d1);
		__m128d yy = _mm_set_pd(d2, d3);
		_val = _mm_shuffle_ps(_mm_cvtpd_ps(xx), _mm_cvtpd_ps(yy), _MM_SHUFFLE(0, 1, 0, 1));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	/// @param[in] aligned						Should be set to true, if #p is known to be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(const Float32* p, Bool aligned)
	{
		_val = aligned ? _mm_load_ps(p) : _mm_loadu_ps(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float32* p)
	{
		_val = _mm_loadu_ps(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float32* p)
	{
		_val = _mm_load_ps(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float64* p)
	{
		__m128d xx = _mm_loadu_pd(p);
		__m128d yy = _mm_loadu_pd(p + 2);
		_val = _mm_shuffle_ps(_mm_cvtpd_ps(xx), _mm_cvtpd_ps(yy), _MM_SHUFFLE(1, 0, 1, 0));
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float64* p)
	{
		__m128d xx = _mm_load_pd(p);
		__m128d yy = _mm_load_pd(p + 2);
		_val = _mm_shuffle_ps(_mm_cvtpd_ps(xx), _mm_cvtpd_ps(yy), _MM_SHUFFLE(1, 0, 1, 0));
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Float32* p) const
	{
		_mm_storeu_ps(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Float32* p) const
	{
		_mm_store_ps(p, _val);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a single value into the first component of the vector.
	/// @param[in] f									The value to load.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadSingle(Float32 f)
	{
		_val = _mm_load_ss(&f);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the internal SSE vector.
	/// @return												The internal SSE vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE __m128 Get() const
	{
		return _val;
	}

	//----------------------------------------------------------------------------------------
	/// Adds two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator +(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_add_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float32 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator +(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_add_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float32 to each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator +(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_add_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator -(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_sub_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float32 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator -(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_sub_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float32 from each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator -(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_sub_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator *(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_mul_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator *(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_mul_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator *(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_mul_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator /(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_div_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Divides each component of a vector by a Float32
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator /(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_div_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Divides vectorized Float32 by each component of vector
	/// Divides each component of a vector by a Float32
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator /(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_div_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector to this.
	/// @param[in] a									The vector to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator +=(const Vector4f32& a)
	{
		_val = _mm_add_ps(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a Float32 to each vector component of this.
	/// @param[in] a									The Float32 to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator +=(const Float32 a)
	{
		_val = _mm_add_ps(_val, _mm_set_ps1(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector from this.
	/// @param[in] a									The vector to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator -=(const Vector4f32& a)
	{
		_val = _mm_sub_ps(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a Float32 from each vector component of this.
	/// @param[in] a									The Float32 to subtract.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator -=(const Float32 a)
	{
		_val = _mm_sub_ps(_val, _mm_set_ps1(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a vector with this.
	/// @param[in] a									The vector to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator *=(const Vector4f32& a)
	{
		_val = _mm_mul_ps(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 to each vector component of this.
	/// @param[in] a									The Float32 to multiply with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator *=(const Float32 a)
	{
		_val = _mm_mul_ps(_val, _mm_set_ps1(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides this by a vector.
	/// @param[in] a									The vector to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator /=(const Vector4f32& a)
	{
		_val = _mm_div_ps(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides each vector component of this by a Float32
	/// @param[in] a									The Float32 to divide with.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator /=(const Float32 a)
	{
		_val = _mm_div_ps(_val, _mm_set_ps1(a));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements of a vector.
	/// @param[in] a									The vector to build the horizontal sum from.
	/// @return												A vector that contains the sum of all elements of a in each element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 HorizontalAdd(const Vector4f32 &a)
	{
		__m128 x, y;
		x = _mm_shuffle_ps(a._val, a._val, _MM_SHUFFLE(1, 0, 1, 0));
		y = _mm_shuffle_ps(a._val, a._val, _MM_SHUFFLE(3, 2, 3, 2));
		x = _mm_add_ps(x, y);
		y = _mm_shuffle_ps(x, x, _MM_SHUFFLE(3, 1, 3, 1));
		x = _mm_shuffle_ps(x, x, _MM_SHUFFLE(2, 0, 2, 0));
		return Vector4f32(_mm_add_ps(x, y));
	}

	//----------------------------------------------------------------------------------------
	/// Performs a multiply-add operation. Make sure to call this function only if fused multiply-add is supported on the target machine.
	/// The function is using the FMA instruction, therefore the result has a higher precision than the result of a * b + c.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @param[in] c									The third operand.
	/// @return												The result of a * b + c.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 MultiplyAdd(const Vector4f32 &a, const Vector4f32 &b, const Vector4f32 &c)
	{
#ifdef C4D_HAS_FMADD_CAPABILITY
		return Vector4f32(_mm_fmadd_ps(a._val, b._val, c._val));
#else
		return Vector4f32(_mm_add_ps(_mm_mul_ps(a._val, b._val), c._val));
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator &(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_and_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a AND b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator &&(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_and_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator |(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_or_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a OR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator ||(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_or_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a XOR b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator ^(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_xor_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator &=(const Vector4f32 &a)
	{
		_val = _mm_and_ps(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator |=(const Vector4f32 &a)
	{
		_val = _mm_or_ps(_val, a._val);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise XOR of two vectors.
	/// @param[in] a									Input vector A.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator ^=(const Vector4f32 &a)
	{
		_val = _mm_xor_ps(_val, a._val);
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
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 Blend(const Vector4f32& b, const Vector4f32& mask) const
	{
		// TODO: (Anybody) with SSE4 we could use _mm_blendv_ps, same for Vector2f64 (see Vector8f32 which uses the AVX blend intrinsics)
		return Vector4f32(_mm_or_ps(_mm_andnot_ps(mask._val, _val), _mm_and_ps(mask._val, b._val)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator <=(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmple_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator <=(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_cmple_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a <= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator <=(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmple_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator ==(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpeq_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator ==(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_cmpeq_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a == b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator ==(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpeq_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator >=(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpge_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator >=(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_cmpge_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a >= b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator >=(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpge_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator >(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpgt_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator >(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_cmpgt_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a > b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator >(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpgt_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator <(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmplt_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator <(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_cmplt_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a < b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator <(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmplt_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator != (const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpneq_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator != (const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_cmpneq_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector. If the condition is true for an element of the vectors the result is 0xffffffff, otherwise 0.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component result of a != b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator != (const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_cmpneq_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Checks, if the first value of a is less or equal than the first value of b.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												True, the first value of a is smaller or equal than the first value of b, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool CompareLessEqualSingle(const Vector4f32& a, const Vector4f32& b)
	{
		return _mm_comile_ss(a._val, b._val) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												True, if both vectors are identical, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector4f32& a, const Vector4f32& b)
	{
		return _mm_movemask_ps(_mm_cmpneq_ps(a._val, b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares each component of a vector with a Float32.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												True, if each vector component is equal to Float32, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Vector4f32& a, const Float32 b)
	{
		return _mm_movemask_ps(_mm_cmpneq_ps(a._val, _mm_set_ps1(b))) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Compares a Float32 with each component of a vector.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												True, if each vector component is equal to Float32, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsEqual(const Float32 a, const Vector4f32& b)
	{
		return _mm_movemask_ps(_mm_cmpneq_ps(_mm_set_ps1(a), b._val)) == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Min(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_min_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of each vector component compared to Float32.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Min(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_min_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum between a Float32 and each vector component.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Min(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_min_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Max(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_max_ps(a._val, b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of each vector component compared to a Float32.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input Float32 B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Max(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(_mm_max_ps(a._val, _mm_set_ps1(b)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum between a Float32 and each vector component.
	/// @param[in] a									Input Float32 A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Max(const Float32 a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_max_ps(_mm_set_ps1(a), b._val));
	}

	//----------------------------------------------------------------------------------------
	/// Clamps all components of the input vector x to a and b.
	/// @param[in] x									Input vector.
	/// @param[in] a									Minimum value.
	/// @param[in] b									Maximum value.
	/// @return												The component-by-component result.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Clamp(const Vector4f32 &x, const Vector4f32 &a, const Vector4f32 &b)
	{
		return Min(Max(x, a), b);
	}

	//----------------------------------------------------------------------------------------
	/// Transposes the input vectors.
	/// @param[in,out] a							Input / Output vector a.
	/// @param[in,out] b							Input / Output vector b.
	/// @param[in,out] c							Input / Output vector c.
	/// @param[in,out] d							Input / Output vector d.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend void Transpose(Vector4f32 &a, Vector4f32 &b, Vector4f32 &c, Vector4f32 &d)
	{
		_MM_TRANSPOSE4_PS(a._val, b._val, c._val, d._val);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the mask of the most significant bits (i.e. the sign bits). Bit n is set if Rn is negative.
	/// @return												The mask of the most significant bits (i.e. the sign bits).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE int GetMSBMask() const
	{
		return _mm_movemask_ps(_val);
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
	template <Int32 ma4, Int32 ma3, Int32 ma2, Int32 ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 Shuffle(const Vector4f32 &a)
	{
		return Vector4f32(_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(a._val), _MM_SHUFFLE(ma4, ma3, ma2, ma1))));
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vectors. Note that the template arguments must be numeric constants and be 0 to 3.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @tparam ma1										Decides which element of vector A becomes the new R0.
	/// @tparam ma2										Decides which element of vector A becomes the new R1.
	/// @tparam mb1										Decides which element of vector B becomes the new R2.
	/// @tparam mb2										Decides which element of vector B becomes the new R3.
	/// @return												A vector consisting of R0=A[ma1], R1=A[ma2], R2=B[mb1], R3=B[mb2]
	//----------------------------------------------------------------------------------------
	template <Int32 mb2, Int32 mb1, Int32 ma2, Int32 ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 Shuffle(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_shuffle_ps(a._val, b._val, _MM_SHUFFLE(mb2, mb1, ma2, ma1)));
	}

	//----------------------------------------------------------------------------------------
	/// All 0's in the mask become b and 1's become a.
	/// @param[in] mask								Input mask used to mask out components.
	/// @param[in] a									Input vector a.
	/// @param[in] b									Input vector b.
	/// @return												Returns a vector with the mask applied to it.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Select(const Vector4f32& mask, const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(_mm_or_ps(_mm_and_ps(mask._val, a._val), _mm_andnot_ps(mask._val, b._val)));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the square root.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component square root of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Sqrt(const Vector4f32& a)
	{
		return Vector4f32(_mm_sqrt_ps(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the square root for the first component.
	/// @param[in] a									The input vector.
	/// @return												The square root of a[0].
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 SqrtSS(const Vector4f32& a)
	{
		return Vector4f32(_mm_sqrt_ss(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the inverse square root.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component inverse square root of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Rsqrt(const Vector4f32& a)
	{
		return Vector4f32(_mm_rsqrt_ps(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the approximate reciprocal. The result of this function is not precise.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component reciprocal of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Reciprocal(const Vector4f32& a)
	{
		const __m128 reciprocal = _mm_rcp_ps(a._val);
		return Vector4f32(_mm_mul_ps(reciprocal, _mm_sub_ps(_mm_set1_ps(2.0f), _mm_mul_ps(reciprocal, a._val))));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the reciprocal.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component reciprocal of a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 FastReciprocal(const Vector4f32& a)
	{
		return Vector4f32(_mm_rcp_ps(a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the absolute value of a vector.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component absolute value a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Abs(const Vector4f32& a)
	{
		return Vector4f32(_mm_and_ps(_mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)), a._val));
	}

	//----------------------------------------------------------------------------------------
	/// Return a vector with the sign for each value.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component sign of vector a i.e. 1.0f or -1.0f.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Sign(const Vector4f32& a)
	{
		__m128 mask = _mm_cmplt_ps(a._val, _mm_set_ps1(0.0f));
			return Vector4f32(_mm_or_ps(_mm_and_ps(mask, _mm_set_ps1(-1.0)), _mm_andnot_ps(mask, _mm_set_ps1(1.0))));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a masked out vector and leaves only the sign.
	/// @param[in] a									The input vector.
	/// @return												The component-by-component masked sign of vector a.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 SignMask(const Vector4f32& a)
	{
		return Vector4f32(_mm_and_ps(a._val, _mm_castsi128_ps(_mm_set1_epi32(0x80000000))));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if any component is not 0.0f.
	/// @param[in] a									The input vector.
	/// @return												Returns true if any of the components is not 0.0f.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool IsAnyNoZero(const Vector4f32& a)
	{
		return _mm_movemask_ps(a._val) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if all components are 0.0f.
	/// @param[in] a									The input vector.
	/// @return												Returns true all components are 0.0f.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Bool AreAllZero(const Vector4f32& a)
	{
		return _mm_movemask_ps(a._val) == 0;
	}

	//----------------------------------------------------------------------------------------
	// Reduction to find the minimum or maximum value in the vector.
	//----------------------------------------------------------------------------------------

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 ReduceMin(const Vector4f32& a)
	{
		const Vector4f32 first = Min(Shuffle<1, 0, 3, 2>(a), a);
		return Min(Shuffle<2, 3, 0, 1>(first), first);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 ReduceMax(const Vector4f32& a)
	{
		const Vector4f32 first = Max(Shuffle<1, 0, 3, 2>(a), a);
		return Max(Shuffle<2, 3, 0, 1>(first), first);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Int SelectMin(const Vector4f32& mask, const Vector4f32& a)
	{
		const Vector4f32 selected = Select(mask, a, Vector4f32(MAXVALUE_FLOAT32));
		const Vector4f32 validMin	= mask & (selected == ReduceMin(selected));
		const Int32 value					= _mm_movemask_ps(IsAnyNoZero(validMin) ? validMin._val : mask._val);
		Int retValue							= Ctz(value);
		DebugAssert(retValue < 4);
		return retValue;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Int SelectMax(const Vector4f32& mask, const Vector4f32& a)
	{
		const Vector4f32 selected = Select(mask, a, Vector4f32(MINVALUE_FLOAT32));
		const Vector4f32 validMin	= mask & (selected == ReduceMax(selected));
		const Int32 value					= _mm_movemask_ps(IsAnyNoZero(validMin) ? validMin._val : mask._val);
		Int retValue							= Ctz(value);
		DebugAssert(retValue < 4);
		return retValue;
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float32& operator [](UInt i)
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float32 operator [](UInt i) const
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector with all elements set to one.
	/// @return												A vector with all elements set to one.
	//----------------------------------------------------------------------------------------
	static Vector4f32 One()
	{
		return Vector4f32(_mm_set1_ps(1.0f));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector with all elements set to minus one.
	/// @return												A vector with all elements set to minus one.
	//----------------------------------------------------------------------------------------
	static Vector4f32 MinusOne()
	{
		return Vector4f32(_mm_set1_ps(-1.0f));
	}

protected:
	/// The internal SSE vector
	union { __m128 _val; Float32 v[4]; };

#else // C4D_HAS_SSE2_CAPABILITY

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f.
	/// @param[in] f									The value that is assigned to all vector elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(Float32 f, Bool setAll = true)
	{
		if (setAll)
		{
			v[0] = v[1] = v[2] = v[3] = f;
		}
		else
		{
			v[0] = f;
			v[1] = v[2] = v[3] = 0.0f;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the object and sets all values to f0...f3.
	/// @param[in] f0									The value that is assigned to vector element 0.
	/// @param[in] f1									The value that is assigned to vector element 1.
	/// @param[in] f2									The value that is assigned to vector element 2.
	/// @param[in] f3									The value that is assigned to vector element 3.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(Float32 f0, Float32 f1, Float32 f2, Float32 f3)
	{
		v[0] = f0;
		v[1] = f1;
		v[2] = f2;
		v[3] = f3;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	/// @param[in] aligned						Should be set to true, if #p is known to be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Vector4f32(const Float32* p, Bool aligned)
	{
		for (Int32 i = 0; i < 4; ++i)
			v[i] = p[i];
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float32* p)
	{
		for (Int32 i = 0; i < 4; ++i)
			v[i] = p[i];
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadUnaligned(const Float64* p)
	{
		for (Int32 i = 0; i < 4; ++i)
			v[i] = (Float32)p[i];
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float32* p)
	{
		LoadUnaligned(p);
	}

	//----------------------------------------------------------------------------------------
	/// Loads a vector from an address in the memory.
	/// @param[in] p									The address where the vector is loaded from, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float64* p)
	{
		LoadUnaligned(p);
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Float32* p) const
	{
		for (Int32 i = 0; i < 4; ++i)
			p[i] = v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Stores the contents of this vector to an address in the memory.
	/// @param[in] p									The address where the vector is to be stored, must be 16-byte aligned.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void StoreAligned(Float32* p) const
	{
		StoreUnaligned(p);
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float32& operator [](UInt i)
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets component i from the vector.
	/// @param[in] i									The index.
	/// @return												Vector element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Float32 operator [](UInt i) const
	{
		DebugAssert(i >= 0 && i < 4);
		return v[i];
	}

	//----------------------------------------------------------------------------------------
	/// Adds two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The sum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator +(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3]);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector to this.
	/// @param[in] a									The vector to add.
	/// @return												A reference to this vector.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32& operator +=(const Vector4f32& a)
	{
		v[0] += a.v[0];
		v[1] += a.v[1];
		v[2] += a.v[2];
		v[3] += a.v[3];

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a - b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator -(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3]);
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator *(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3]);
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a Float32 with each vector component.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The product of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator *(const Vector4f32 &a, const Float32 b)
	{
		return Vector4f32(a.v[0] * b, a.v[1] * b, a.v[2] * b, a.v[3] * b);
	}

	//----------------------------------------------------------------------------------------
	/// Divides two vectors.
	/// @param[in] a									The first operand.
	/// @param[in] b									The second operand.
	/// @return												The component-by-component result of a / b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator /(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3]);
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
	MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 Blend(const Vector4f32& b, const Vector4f32& mask) const
	{
		Vector4f32 ret;

		UInt32* r = reinterpret_cast<UInt32*>(ret.v);
		const UInt32* v1 = reinterpret_cast<const UInt32*>(v);
		const UInt32* v2 = reinterpret_cast<const UInt32*>(b.v);
		const UInt32* m = reinterpret_cast<const UInt32*>(mask.v);

		for (UChar i = 0; i < 4; ++i)
			r[i] = (v1[i] & ~m[i]) | (v2[i] & m[i]);

		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component minimum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Min(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(Min(a.v[0], b.v[0]), Min(a.v[1], b.v[1]), Min(a.v[2], b.v[2]), Min(a.v[3], b.v[3]));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of two vectors.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @return												The component-by-component maximum of a and b.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Max(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(Max(a.v[0], b.v[0]), Max(a.v[1], b.v[1]), Max(a.v[2], b.v[2]), Max(a.v[3], b.v[3]));
	}

	//----------------------------------------------------------------------------------------
	/// Clamps all components of the input vector x to a and b.
	/// @param[in] x									Input vector.
	/// @param[in] a									Minimum value.
	/// @param[in] b									Maximum value.
	/// @return												The component-by-component result.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 Clamp(const Vector4f32 &x, const Vector4f32 &a, const Vector4f32 &b)
	{
		return Min(Max(x, a), b);
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
	template <Int32 ma4, Int32 ma3, Int32 ma2, Int32 ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 Shuffle(const Vector4f32 &a)
	{
		return Vector4f32(a.v[ma1], a.v[ma2], a.v[ma3], a.v[ma4]);
	}

	//----------------------------------------------------------------------------------------
	/// Shuffles the components of the input vectors. Note that the template arguments must be numeric constants and be 0 to 3.
	/// @param[in] a									Input vector A.
	/// @param[in] b									Input vector B.
	/// @tparam ma1										Decides which element of vector A becomes the new R0.
	/// @tparam ma2										Decides which element of vector A becomes the new R1.
	/// @tparam mb1										Decides which element of vector B becomes the new R2.
	/// @tparam mb2										Decides which element of vector B becomes the new R3.
	/// @return												A vector consisting of R0=A[ma1], R1=A[ma2], R2=B[mb1], R3=B[mb2]
	//----------------------------------------------------------------------------------------
	template <Int32 mb2, Int32 mb1, Int32 ma2, Int32 ma1> static MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 Shuffle(const Vector4f32 &a, const Vector4f32 &b)
	{
		return Vector4f32(a.v[ma1], a.v[ma2], b.v[mb1], b.v[mb2]);
	}

	/// The internal SSE vector
	union { Float32 v[4]; };

#endif // C4D_HAS_SSE2_CAPABILITY

};

} // namespace maxon

#endif // SSE_VECTOR_4F32_H__
