#ifndef VEC_H__ // This file is included several times, so it must not define the header guard.

#ifndef MAXON_VECTORMODE
#error "This file must not be included directly, include vector.h instead"
#endif

namespace maxon
{

/// A vector consisting of three components X, Y and Z.
#ifdef STRIDE
template <typename T> struct Vec3<T, 1>
#else
template <typename T, Int STRIDE = 1> struct Vec3
#endif
{
	template <typename U> using Rebind = Vec3<U, STRIDE>;
	using VectorStrideType = std::integral_constant<Int, STRIDE>;
	using ValueType = T;
	using ValueTypeParam = typename ByValueParam<T>::type;
	using Unstrided = Vec3<T, 1>;

	/// The type returned by comparisons. If the template argument for T is a SIMD type,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = decltype(T() == T());

#ifdef STRIDE
	T x;
	T y;
	T z;
#else
	union { T x; T _xpadding[STRIDE]; };
	union { T y; T _ypadding[STRIDE]; };
	union { T z; T _zpadding[STRIDE]; };
#endif

	/// Initializes all vector components with 0.0
	constexpr Vec3() : x(0), y(0), z(0) { }

	/// Initializes all vector components with a scalar
	explicit constexpr Vec3(ValueTypeParam in) : x(in), y(in), z(in) { }

	/// Initializes all vector components individually
	explicit constexpr Vec3(ValueTypeParam ix, ValueTypeParam iy, ValueTypeParam iz) : x(ix), y(iy), z(iz) { }

	/// Initializes components from another 3d vector.
	template <typename T2, Int S2> explicit constexpr Vec3(const Vec3<T2, S2>& v) : x((T)v.x), y((T)v.y), z((T)v.z) { }

	/// Initializes components from another 3d vector.
	template <typename T2, Int S2> explicit constexpr Vec3(const Col3<T2, S2>& v) : x((T)v.r), y((T)v.g), z((T)v.b) { }

	/// Initializes components from another 3d vector.
	template <Int S2> constexpr Vec3(const Vec3<T, S2>& v) : x(v.x), y(v.y), z(v.z) { }

	/// Initializes components from a 2d vector. The z-component is set to 0.0 unless an extra parameter is passed.
	template <typename T2, Int S2> explicit constexpr Vec3(const Vec2<T2, S2>& v, T vz = T()) : x((T)v.x), y((T)v.y), z(vz) { }

	/// Initializes components from a 4d vector. The w-component is omitted.
	template <typename T2, Int S2> explicit constexpr Vec3(const Vec4<T2, S2>& v) : x((T)v.x), y((T)v.y), z((T)v.z) { }

	/// Initializes components from a 4d vector. The w-component is omitted.
	template <typename T2, Int S2> explicit constexpr Vec3(const Col4<T2, S2>& v) : x((T)v.r), y((T)v.g), z((T)v.b) { }

	/// Skips initialization of vector (for better speed)
	explicit constexpr Vec3(ENUM_DONT_INITIALIZE v) { }

	/// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
	/// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
	MAXON_IMPLICIT constexpr Vec3(const typename std::conditional<STRIDE == 1, DummyParamType, Vec3>::type& src) : MAXON_MOVE_MEMBERS(x, y, z)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copies the source vector.
	/// @param[in] src								Source vector.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	constexpr Vec3& operator =(const typename std::conditional<STRIDE == 1, DummyParamType, Vec3>::type& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
		return *this;
	}

	/// Accesses vector component: index 0 is 'x', index 1 is 'y', index 2 is 'z'. All other values must not be used and will crash
	T& operator [](Int l)
	{
		DebugAssert(UInt(l) < 3);
		return ((T*)this)[STRIDE * l];
	}

	/// Accesses vector component: index 0 is 'x', index 1 is 'y', index 2 is 'z'.  All other values must not be used and will crash
	ValueTypeParam operator [](Int l) const
	{
		DebugAssert(UInt(l) < 3);
		return ((const T*)this)[STRIDE * l];
	}

	/// Adds two vectors
	template <typename T2, Int S2> constexpr Vec3& operator +=(const Vec3<T2, S2>& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be added.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	constexpr Vec3& operator +=(const Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	/// Subtracts two vectors
	template <typename T2, Int S2> constexpr Vec3& operator -=(const Vec3<T2, S2>& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be substracted from this.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	constexpr Vec3& operator -=(const Vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	/// Multiplies two vectors component-wise
	template <typename T2, Int S2> constexpr Vec3& operator *=(const Vec3<T2, S2>& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies with vector component-wise.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be multiplied with.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	constexpr Vec3& operator *=(const Vec3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	constexpr Vec3& operator *=(ValueTypeParam s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}

	/// Divides each vector component by a scalar. The passed argument is checked for 0.0
	constexpr Vec3& operator /=(ValueTypeParam s)
	{
		T is = Inverse(s);
		x *= is;
		y *= is;
		z *= is;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	friend constexpr Unstrided operator *(ValueTypeParam s, const Vec3& v)
	{
		return Unstrided(s * v.x, s * v.y, s * v.z);
	}

	/// Multiplies each vector component by a scalar
	constexpr Unstrided operator *(ValueTypeParam s) const
	{
		return Unstrided(x * s, y * s, z * s);
	}

	/// Multiplies each vector component by a scalar
	template <typename S> constexpr Vec3<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s) const
	{
		return Vec3<typename MultiplicativePromotion<T, S>::type, 1>(x * s, y * s, z * s);
	}

	/// Divides each vector component by a scalar. The scalar value is tested for 0.0
	constexpr Unstrided operator /(ValueTypeParam s) const
	{
		T is = Inverse(s);
		return Unstrided(x * is, y * is, z * is);
	}

	/// Multiplies two vectors component-wise
	constexpr Unstrided operator *(const Vec3& v) const
	{
		return Unstrided(x * v.x, y * v.y, z * v.z);
	}

	/// Adds two vectors
	constexpr Unstrided operator +(const Vec3& v) const
	{
		return Unstrided(x + v.x, y + v.y, z + v.z);
	}

	/// Subtracts vector v2 from v1
	constexpr Unstrided operator -(const Vec3& v) const
	{
		return Unstrided(x - v.x, y - v.y, z - v.z);
	}

	/// Negates vector v
	constexpr Unstrided operator -() const
	{
		return Unstrided(-x, -y, -z);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] v									Comparison vector.
	/// @return												True if this and v are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	template <typename T2, Int S2> constexpr BoolType operator ==(const Vec3<T2, S2>& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												True if this and v are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator ==(const Vec3& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] v									Comparison vector.
	/// @return												False if this and v are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	template <typename T2, Int S2> constexpr BoolType operator !=(const Vec3<T2, S2>& v) const
	{
		return !(x == v.x && y == v.y && z == v.z);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												False if this and v are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator !=(const Vec3& v) const
	{
		return !(x == v.x && y == v.y && z == v.z);
	}

	// This helper is used e.g. for the Range class. It cannot be defined as an operator, as the statement
	// LessThenOrEqual(a, b) == !LessThanOrEqual(b, a)
	// is not necessarily true.
	constexpr BoolType LessThanOrEqual(const Vec3& v) const
 	{
 		return x <= v.x && y <= v.y && z <= v.z;
 	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the vector (used for hash maps and comparisons).
	/// @return												The vector's hash code.
	//----------------------------------------------------------------------------------------
	constexpr HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(x, y, z);
	}

	/// Tests component-wise if the difference is no bigger than 'epsilon'
	constexpr BoolType IsEqual(const Vec3& other, ValueTypeParam epsilon) const
	{
		return Abs(x - other.x) <= epsilon && Abs(y - other.y) <= epsilon && Abs(z - other.z) <= epsilon;
	}

	/// Calculates dot product of v1 and v2
	friend constexpr T Dot(const Vec3& v1, const Vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	//----------------------------------------------------------------------------------------
	/// returns the vector with absolute value for each entry
	/// @param[in] v1									input vector to work on
	/// @return												component wise absolute value vector of input vector
	//----------------------------------------------------------------------------------------
	friend constexpr Unstrided Abs(const Vec3& v1)
	{
		return Unstrided(Abs(v1.x), Abs(v1.y), Abs(v1.z));
	}

	/// Calculates dot product of v1 and v2
	template <typename T2, Int S2> friend constexpr typename MultiplicativePromotion<T, T2>::type Dot(const Vec3& v1, const Vec3<T2, S2>& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	/// Checks if each component is zero.
	constexpr BoolType IsZero() const
	{
		return x == T(0) && y == T(0) && z == T(0);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if each component is smaller that epsilon
	/// @param[in] epsilon			epsilon value
	/// @return									False if one or more component are bigger than epsilon, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType IsZero(ValueTypeParam epsilon) const
	{
		return Abs(x) <= epsilon && Abs(y) <= epsilon && Abs(z) <= epsilon;
	}

	/// Sets all components to zero.
	constexpr void SetZero()
	{
		x = y = z = T(0);
	}

	/// Calculates the average value of 'x', 'y' and 'z'
	constexpr T GetAverage() const
	{
		return (x + y + z) * T(1.0 / 3.0);
	}

	/// Calculates the sum of 'x', 'y' and 'z'
	constexpr T GetSum() const
	{
		return x + y + z;
	}

	/// Calculates the minimum of each component.
	friend constexpr Unstrided Min(const Vec3& a, const Vec3& other)
	{
		return Unstrided(a.x < other.x ? a.x : other.x, a.y < other.y ? a.y : other.y, a.z < other.z ? a.z : other.z); 
	}

	/// Calculates the maximum of each component.
	friend constexpr Unstrided Max(const Vec3& a, const Vec3& other)
	{
		return Unstrided(a.x > other.x ? a.x : other.x, a.y > other.y ? a.y : other.y, a.z > other.z ? a.z : other.z); 
	}

	/// Set the minimum of each component.
	constexpr void ClampMin(const Vec3& other = Vec3())
	{
		maxon::SetMax(x, other.x);
		maxon::SetMax(y, other.y);
		maxon::SetMax(z, other.z);
	}

	/// Set the maximum of each component.
	constexpr void ClampMax(const Vec3& other)
	{
		maxon::SetMin(x, other.x);
		maxon::SetMin(y, other.y);
		maxon::SetMin(z, other.z);
	}

	/// Set the minimum of each component.
	friend constexpr void SetMin(Vec3& a, const Vec3& other)
	{
		a.ClampMax(other);
	}

	/// Set the maximum of each component.
	friend constexpr void SetMax(Vec3& a, const Vec3& other)
	{
		a.ClampMin(other);
	}

	/// Returns a vector that is clamped to the range [0.0 .. 1.0]
	constexpr Unstrided Clamp01() const
	{
		return Unstrided(maxon::Clamp01(x), maxon::Clamp01(y), maxon::Clamp01(z));
	}

	/// Returns the length of the vector
	constexpr T GetLength() const
	{
		return Sqrt(x * x + y * y + z * z);
	}

	/// Returns the squared length of the vector
	constexpr T	GetSquaredLength() const
	{
		return x * x + y * y + z * z;
	}

	/// Returns a normalized vector, so that GetLength(vector)==1.0
	constexpr Unstrided GetNormalized() const
	{
		T il = Inverse(Sqrt(x * x + y * y + z * z));
		return Unstrided(x * il, y * il, z * il);
	}

	/// Returns a normalized vector, so that GetLength(vector)==1.0
	constexpr Unstrided operator !() const
	{
		T il = Inverse(Sqrt(x * x + y * y + z * z));
		return Unstrided(x * il, y * il, z * il);
	}

	/// Normalizes this vector, so that GetLength()==1.0
	constexpr void Normalize()
	{
		T il = Inverse(Sqrt(x * x + y * y + z * z));
		x *= il;
		y *= il;
		z *= il;
	}

	/// Calculates angle (in radians) between v1 and v2
	friend constexpr T GetAngle(const Vec3& v1, const Vec3& v2)
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
		return "("_s + maxon::ToString(x, formatStatement) + ","_s + maxon::ToString(y, formatStatement) + ","_s + maxon::ToString(z, formatStatement) + ")"_s;
	}

	// the following functions are Vec3-specific, they cannot be copied to Vec2 and Vec4

	/// Reinterprets the vector as color.
	constexpr const Col3<T, STRIDE>& GetColor() const { return *(const Col3<T, STRIDE>*) this; }
	constexpr Col3<T, STRIDE>& GetColor() { return *(Col3<T, STRIDE>*) this; }

	/// Calculates cross product of v1 and v2
	friend constexpr Unstrided Cross(const Vec3& v1, const Vec3& v2)
	{
		return Unstrided(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}

	/// Calculates cross product of v1 and v2
	template <typename T2, Int S2> friend constexpr Vec3<typename MultiplicativePromotion<T, T2>::type, 1> Cross(const Vec3& v1, const Vec3<T2, S2>& v2)
	{
		return Vec3<typename MultiplicativePromotion<T, T2>::type, 1>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}

	/// Returns the minimum of 'x', 'y' and 'z'
	constexpr T GetMin() const
	{
		if (x < y)
		{
			return (z < x) ? z : x;
		}
		else
		{
			return (z < y) ? z : y;
		}
	}

	/// Returns the maximum of 'x', 'y' and 'z'
	constexpr T GetMax() const
	{
		if (x > y)
		{
			return (z > x) ? z : x;
		}
		else
		{
			return (z > y) ? z : y;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector where the components have been rotated to the right (in the usual (x, y, z)-representation). E.g.,
	/// with a value of 1 for rots, the result will be (z, x, y).
	/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 3.
	/// @return												Vector with rotated components.
	//----------------------------------------------------------------------------------------
	constexpr Unstrided GetRightRotated(Int rots) const
	{
		while (true)
		{
			switch (rots)
			{
				case 0:
					return *this;
				case 1:
				case -2:
					return Unstrided(z, x, y);
				case 2:
				case -1:
					return Unstrided(y, z, x);
				default:
					rots %= 3;
					break;
			}
		}
	}

	/// Transforms point by a matrix
	template <typename T2> constexpr Vec3& operator *=(const Mat3<T2>& m)
	{
		T xx = T(m.off.x + m.sqmat.v1.x * x + m.sqmat.v2.x * y + m.sqmat.v3.x * z);
		T yy = T(m.off.y + m.sqmat.v1.y * x + m.sqmat.v2.y * y + m.sqmat.v3.y * z);
		z = T(m.off.z + m.sqmat.v1.z * x + m.sqmat.v2.z * y + m.sqmat.v3.z * z);
		x = xx;
		y = yy;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the vector (see nullvalue.h for more details).
	/// @return												A null value of the vector.
	//----------------------------------------------------------------------------------------
	static constexpr const Vec3& NullValue()
	{
		return GetZeroRef<Vec3>();
	}
};

#ifndef STRIDE
/// Multiplies each vector component by a scalar
template <typename T, Int STR, typename S> inline Vec3<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s, const Vec3<T, STR>& v)
{
	return Vec3<typename MultiplicativePromotion<T, S>::type, 1>(v.x * s, v.y * s, v.z * s);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Vec3<T, 1>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY | GET_DATATYPE_POLICY::NO_DECAY>::Get() iferr_return;
	return ParametricTypes::Vec().Instantiate(t, ToSingletonBlock(Int64(3)));
}

template <typename T> struct IsZeroInitialized<Vec3<T, 1>> : public IsZeroInitialized<T> { };
#endif

}

#endif
