#ifndef VEC2_H__ // This file is included several times, so it must not define the header guard.

#ifndef MAXON_VECTORMODE
#error "This file must not be included directly, include vector2d.h instead"
#endif

namespace maxon
{

/// A vector consisting of three components X, Y and Z.
#ifdef STRIDE
template <typename T> struct Vec2<T, 1>
#else
template <typename T, Int STRIDE = 1> struct Vec2
#endif
{
	template <typename U> using Rebind = Vec2<U, STRIDE>;
	using VectorStrideType = std::integral_constant<Int, STRIDE>;
	using ValueType = T;
	using ValueTypeParam = typename ByValueParam<T>::type;
	using Unstrided = Vec2<T, 1>;

	/// The type returned by comparisons. If the template argument for T is a SIMD type,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = decltype(T() == T());

#ifdef STRIDE
	T x;
	T y;
#else
	union { T x; T _xpadding[STRIDE]; };
	union { T y; T _ypadding[STRIDE]; };
#endif

	/// Initializes all vector components with 0.0
	Vec2() : x(0), y(0) { }

	/// Initializes all vector components with a scalar
	explicit Vec2(ValueTypeParam in) : x(in), y(in) { }

	/// Initializes all vector components individually
	explicit Vec2(ValueTypeParam ix, ValueTypeParam iy) : x(ix), y(iy) { }

	/// Initializes components from another 2d vector.
	template <typename T2, Int S2> explicit Vec2(const Vec2<T2, S2>& v) : x((T)v.x), y((T)v.y) { }

	/// Initializes components from another 2d vector.
	template <Int S2> Vec2(const Vec2<T, S2>& v) : x(v.x), y(v.y) { }

	/// Initializes components from a 3d vector. The z-component of v is ignored.
	template <typename T2, Int S2> explicit Vec2(const Vec3<T2, S2>& v) : x((T)v.x), y((T)v.y) { }

	/// Skips initialization of vector (for better speed)
	explicit Vec2(ENUM_DONT_INITIALIZE v) { }

	/// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
	/// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
	MAXON_IMPLICIT Vec2(const typename std::conditional<STRIDE == 1, DummyParamType, Vec2>::type& src) : MAXON_MOVE_MEMBERS(x, y)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copies the source vector.
	/// @param[in] src								Source vector.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec2& operator =(const typename std::conditional<STRIDE == 1, DummyParamType, Vec2>::type& src)
	{
		x = src.x;
		y = src.y;
		return *this;
	}

	/// Accesses vector component: index 0 is 'x', index 1 is 'y'. All other values must not be used and will crash
	T& operator [](Int l)
	{
		DebugAssert(UInt(l) < 2);
		return ((T*)this)[STRIDE * l];
	}

	/// Accesses vector component: index 0 is 'x', index 1 is 'y'.  All other values must not be used and will crash
	ValueTypeParam operator [](Int l) const
	{
		DebugAssert(UInt(l) < 2);
		return ((const T*)this)[STRIDE * l];
	}

	/// Adds two vectors
	template <typename T2, Int S2> Vec2& operator +=(const Vec2<T2, S2>& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be added.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec2& operator +=(const Vec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	/// Subtracts two vectors
	template <typename T2, Int S2> Vec2& operator -=(const Vec2<T2, S2>& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be substracted from this.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec2& operator -=(const Vec2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	/// Multiplies two vectors component-wise
	template <typename T2, Int S2> Vec2& operator *=(const Vec2<T2, S2>& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies with vector component-wise.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be multiplied with.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec2& operator *=(const Vec2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	Vec2& operator *=(ValueTypeParam s)
	{
		x *= s;
		y *= s;
		return *this;
	}

	/// Divides each vector component by a scalar. The passed argument is checked for 0.0
	Vec2& operator /=(ValueTypeParam s)
	{
		T is = Inverse(s);
		x *= is;
		y *= is;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	friend Unstrided operator *(ValueTypeParam s, const Vec2& v)
	{
		return Unstrided(s * v.x, s * v.y);
	}

	/// Multiplies each vector component by a scalar
	Unstrided operator *(ValueTypeParam s) const
	{
		return Unstrided(x * s, y * s);
	}

	/// Multiplies each vector component by a scalar
	template <typename S> Vec2<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s) const
	{
		return Vec2<typename MultiplicativePromotion<T, S>::type, 1>(x * s, y * s);
	}

	/// Divides each vector component by a scalar. The scalar value is tested for 0.0
	Unstrided operator /(ValueTypeParam s) const
	{
		T is = Inverse(s);
		return Unstrided(x * is, y * is);
	}

	/// Multiplies two vectors component-wise
	Unstrided operator *(const Vec2& v) const
	{
		return Unstrided(x * v.x, y * v.y);
	}

	/// Adds two vectors
	Unstrided operator +(const Vec2& v) const
	{
		return Unstrided(x + v.x, y + v.y);
	}

	/// Subtracts vector v2 from v1
	Unstrided operator -(const Vec2& v) const
	{
		return Unstrided(x - v.x, y - v.y);
	}

	/// Negates vector v
	Unstrided operator -() const
	{
		return Unstrided(-x, -y);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												True if this and v are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	template <typename T2, Int S2> BoolType operator ==(const Vec2<T2, S2>& v) const
	{
		return x == v.x && y == v.y;
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												True if this and v are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	BoolType operator ==(const Vec2& v) const
	{
		return x == v.x && y == v.y;
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] v									Comparison vector.
	/// @return												False if this and v are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	template <typename T2, Int S2> BoolType operator !=(const Vec2<T2, S2>& v) const
	{
		return !(x == v.x && y == v.y);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												False if this and v are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	BoolType operator !=(const Vec2& v) const
	{
		return !(x == v.x && y == v.y);
	}

	// This helper is used e.g. for the Range class. It cannot be defined as an operator, as the statement
	// LessThenOrEqual(a, b) == !LessThanOrEqual(b, a)
	// is not necessarily true.
 	BoolType LessThanOrEqual(const Vec2& v) const
 	{
 		return x <= v.x && y <= v.y;
 	}

	// This helper is used e.g. for the Range class. It cannot be defined as an operator, as the statement
	// LessThen(a, b) == !LessThan(b, a)
	// is not necessarily true.
	BoolType LessThan(const Vec2& v) const
	{
		return x < v.x && y < v.y;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the vector (used for hash maps and comparisons).
	/// @return												The vector's hash code.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return MAXON_HASHCODE(x, y);
	}

	/// Tests component-wise if the difference is no bigger than 'epsilon'
	BoolType IsEqual(const Vec2& other, ValueTypeParam epsilon) const
	{
		return Abs(x - other.x) <= epsilon && Abs(y - other.y) <= epsilon;
	}

	/// Calculates dot product of v1 and v2
	friend T Dot(const Vec2& v1, const Vec2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	//----------------------------------------------------------------------------------------
	/// returns the vector with absolute value for each entry
	/// @param[in] v1									input vector to work on
	/// @return												component wise absolute value vector of input vector
	//----------------------------------------------------------------------------------------
	friend Unstrided Abs(const Vec2& v1)
	{
		return Unstrided(Abs(v1.x), Abs(v1.y));
	}

	/// Calculates dot product of v1 and v2
	template <typename T2, Int S2> friend typename MultiplicativePromotion<T, T2>::type Dot(const Vec2& v1, const Vec2<T2, S2>& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	/// Checks if each component is zero.
	BoolType IsZero() const
	{
		return x == T(0) && y == T(0);
	}

	/// Sets all components to zero.
	void SetZero()
	{
		x = y = T(0);
	}

	/// Calculates the average value of 'x', 'y' and 'z'
	T GetAverage() const
	{
		return (x + y) * T(0.5);
	}

	/// Calculates the sum of 'x', 'y' and 'z'
	T GetSum() const
	{
		return x + y;
	}

	/// Calculates the minimum of each component.
	friend Unstrided Min(const Vec2& a, const Vec2& other)
	{
		return Unstrided(a.x < other.x ? a.x : other.x, a.y < other.y ? a.y : other.y); 
	}

	/// Calculates the maximum of each component.
	friend Unstrided Max(const Vec2& a, const Vec2& other)
	{
		return Unstrided(a.x > other.x ? a.x : other.x, a.y > other.y ? a.y : other.y); 
	}

	/// Set the minimum of each component.
	void ClampMin(const Vec2& other = Vec2())
	{
		maxon::SetMax(x, other.x);
		maxon::SetMax(y, other.y);
	}

	/// Set the maximum of each component.
	void ClampMax(const Vec2& other)
	{
		maxon::SetMin(x, other.x);
		maxon::SetMin(y, other.y);
	}

	/// Set the minimum of each component.
	friend void SetMin(Vec2& a, const Vec2& other)
	{
		a.ClampMax(other);
	}

	/// Set the maximum of each component.
	friend void SetMax(Vec2& a, const Vec2& other)
	{
		a.ClampMin(other);
	}

	/// Returns a vector that is clamped to the range [0.0 .. 1.0]
	Unstrided Clamp01() const
	{
		return Unstrided(maxon::Clamp01(x), maxon::Clamp01(y));
	}

	/// Returns the length of the vector
	T GetLength() const
	{
		return Sqrt(x * x + y * y);
	}

	/// Returns the squared length of the vector
	T	GetSquaredLength() const
	{
		return x * x + y * y;
	}

	/// Returns a normalized vector, so that GetLength(vector)==1.0
	Unstrided GetNormalized() const
	{
		T il = Inverse(Sqrt(x * x + y * y));
		return Unstrided(x * il, y * il);
	}

	/// Returns a normalized vector, so that GetLength(vector)==1.0
	Unstrided operator !() const
	{
		T il = Inverse(Sqrt(x * x + y * y));
		return Unstrided(x * il, y * il);
	}

	/// Normalizes this vector, so that GetLength()==1.0
	void Normalize()
	{
		T il = Inverse(Sqrt(x * x + y * y));
		x *= il;
		y *= il;
	}

	/// Calculates angle (in radians) between v1 and v2
	friend T GetAngle(const Vec2& v1, const Vec2& v2)
	{
		T il = Inverse(v1.GetSquaredLength() * v2.GetSquaredLength());
		return ACos(Dot(v1, v2) * Sqrt(il));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + maxon::ToString(x, formatStatement) + ","_s + maxon::ToString(y, formatStatement) + ")"_s;
	}

	/// Calculates the cross product of a 2d vector. This is the vector (Y, -X), i.e., the clockwise rotation by 90 degrees.
	friend Unstrided Cross(const Vec2& v1)
	{
		return Unstrided(v1.y, -v1.x);
	}

	/// Returns the minimum of 'x' and 'y'
	T GetMin() const
	{
		return Min<T>(x, y);
	}

	/// Returns the maximum of 'x' and 'y'
	T GetMax() const
	{
		return Max<T>(x, y);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector where the components have been rotated to the right (in the usual (x, y)-representation). E.g.,
	/// with a value of 1 for rots, the result will be (y, x).
	/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 2.
	/// @return												Vector with rotated components.
	//----------------------------------------------------------------------------------------
	Unstrided GetRightRotated(Int rots) const
	{
		switch (rots & 1)
		{
			case 0:
				return *this;
				break;
			default:
				return Unstrided(y, x);
				break;
		}
	}

	/// Transforms point by a matrix
	template <typename T2> Vec2& operator *=(const Mat2<T2>& m)
	{
		T xx = T(m.off.x + m.sqmat.v1.x * x + m.sqmat.v2.x * y);
		y = T(m.off.y + m.sqmat.v1.y * x + m.sqmat.v2.y * y);
		x = xx;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the vector (see nullvalue.h for more details).
	/// @return												A null value of the vector.
	//----------------------------------------------------------------------------------------
	static const Vec2& NullValue()
	{
		return GetZeroRef<Vec2>();
	}
};

#ifndef STRIDE
/// Multiplies each vector component by a scalar
template <typename T, Int STR, typename S> inline Vec2<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s, const Vec2<T, STR>& v)
{
	return Vec2<typename MultiplicativePromotion<T, S>::type, 1>(v.x * s, v.y * s);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Vec2<T, 1>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY>::value>::Get() iferr_return;
	return ParametricTypes::Vec().Instantiate(t, ToSingletonBlock(Int64(2)));
}

template <typename T> struct IsZeroInitialized<Vec2<T, 1>> : public IsZeroInitialized<T> { };

#endif

}

#endif
