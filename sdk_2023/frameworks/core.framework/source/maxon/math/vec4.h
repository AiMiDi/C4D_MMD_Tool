#ifndef VEC4_H__ // This file is included several times, so it must not define the header guard.

#ifndef MAXON_VECTORMODE
#error "This file must not be included directly, include vector4d.h instead"
#endif

namespace maxon
{

/// A vector consisting of four components X, Y, Z and W.
#ifdef STRIDE
template <typename T> struct Vec4<T, 1>
#else
template <typename T, Int STRIDE = 1> struct Vec4
#endif
{
	template <typename U> using Rebind = Vec4<U, STRIDE>;
	using VectorStrideType = std::integral_constant<Int, STRIDE>;
	using ValueType = T;
	using ValueTypeParam = typename ByValueParam<T>::type;
	using Unstrided = Vec4<T, 1>;

	/// The type returned by comparisons. If the template argument for T is a SIMD type,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = decltype(T() == T());

#ifdef STRIDE
	T x;
	T y;
	T z;
	T w;

	static constexpr Bool TriviallyHashable() { return IsTriviallyHashable<T>::value; }
#else
	union { T x; T _xpadding[STRIDE]; };
	union { T y; T _ypadding[STRIDE]; };
	union { T z; T _zpadding[STRIDE]; };
	union { T w; T _wpadding[STRIDE]; };
#endif

	/// Initializes all vector components with 0.0
	constexpr Vec4() : x(0), y(0), z(0), w(0) { }

	/// Initializes all vector components with a scalar
	explicit constexpr Vec4(ValueTypeParam in) : x(in), y(in), z(in), w(in) { }

	/// Initializes all vector components individually
	explicit constexpr Vec4(ValueTypeParam ix, ValueTypeParam iy, ValueTypeParam iz, ValueTypeParam iw) : x(ix), y(iy), z(iz), w(iw) { }

	/// Initializes components from another 4d vector.
	template <typename T2, Int S2> explicit constexpr Vec4(const Vec4<T2, S2>& v) : x((T)v.x), y((T)v.y), z((T)v.z), w((T)v.w) { }

	/// Initializes components from another 4d vector.
	template <typename T2, Int S2> explicit constexpr Vec4(const Col4<T2, S2>& v) : x((T)v.r), y((T)v.g), z((T)v.b), w((T)v.a) { }

	/// Initializes components from another 4d vector.
	template <Int S2> constexpr Vec4(const Vec4<T, S2>& v) : x(v.x), y(v.y), z(v.z), w(v.w) { }

	/// Initializes components from a 3d vector and add an additional value for the w-component.
	/// The default value for w is 1.0.
	template <typename T2, Int S2> explicit constexpr Vec4(const Vec3<T2, S2>& v, T iw = T(1)) : x((T)v.x), y((T)v.y), z((T)v.z), w(iw) { }

	/// Skips initialization of vector (for better speed)
	explicit constexpr Vec4(ENUM_DONT_INITIALIZE v) { }

	/// Reinterprets the vector as color.
	constexpr const Col4<T, STRIDE>& GetColor() const { return *(const Col4<T, STRIDE>*) this; }

	/// Reinterprets the vector as color.
	Col4<T, STRIDE>& GetColor() { return *(Col4<T, STRIDE>*) this; }

	/// Gets the x/y/z components without w.
	constexpr const Vec3<T, STRIDE>& GetVector3() const { return *(const Vec3<T, STRIDE>*) this; }
  
  /// Gets the writable x/y/z components without w.
  Vec3<T, STRIDE>& GetVector3() { return *(Vec3<T, STRIDE>*) this; }

	/// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
	/// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
	MAXON_IMPLICIT constexpr Vec4(const typename std::conditional<STRIDE == 1, DummyParamType, Vec4>::type& src) : MAXON_MOVE_MEMBERS(x, y, z, w)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copies the source vector.
	/// @param[in] src								Source vector.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec4& operator =(const typename std::conditional<STRIDE == 1, DummyParamType, Vec4>::type& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = src.w;
		return *this;
	}

	/// Accesses vector component: index 0 is 'x', index 1 is 'y', index 2 is 'z'. All other values must not be used and will crash
	T& operator [](Int l)
	{
		DebugAssert(UInt(l) < 4);
		return ((T*)this)[STRIDE * l];
	}

	/// Accesses vector component: index 0 is 'x', index 1 is 'y', index 2 is 'z'.  All other values must not be used and will crash
	ValueTypeParam operator[](Int l) const
	{
		DebugAssert(UInt(l) < 4);
		return ((const T*)this)[STRIDE * l];
	}

	/// Adds two vectors
	template <typename T2, Int S2> Vec4& operator +=(const Vec4<T2, S2>& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a vector.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be added.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec4& operator +=(const Vec4& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	/// Subtracts two vectors
	template <typename T2, Int S2> Vec4& operator -=(const Vec4<T2, S2>& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a vector.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be substracted from this.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec4& operator -=(const Vec4& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	/// Multiplies two vectors component-wise
	template <typename T2, Int S2> Vec4& operator *=(const Vec4<T2, S2>& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies with vector component-wise.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
	/// @param[in] v									Vector to be multiplied with.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	Vec4& operator *=(const Vec4& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	Vec4& operator *=(ValueTypeParam s)
	{
		x *= s;
		y *= s;
		z *= s;
		w *= s;
		return *this;
	}

	/// Divides each vector component by a scalar. The passed argument is checked for 0.0
	Vec4& operator /=(ValueTypeParam s)
	{
		T is = Inverse(s);
		x *= is;
		y *= is;
		z *= is;
		w *= is;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	friend constexpr Unstrided operator *(ValueTypeParam s, const Vec4& v)
	{
		return Unstrided(s * v.x, s * v.y, s * v.z, s * v.w);
	}

	/// Multiplies each vector component by a scalar
	constexpr Unstrided operator *(ValueTypeParam s) const
	{
		return Unstrided(x * s, y * s, z * s, w * s);
	}

	/// Multiplies each vector component by a scalar
	template <typename S> constexpr Vec4<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s) const
	{
		return Vec4<typename MultiplicativePromotion<T, S>::type, 1>(x * s, y * s, z * s, w * s);
	}

	/// Divides each vector component by a scalar. The scalar value is tested for 0.0
	constexpr Unstrided operator /(ValueTypeParam s) const
	{
		T is = Inverse(s);
		return Unstrided(x * is, y * is, z * is, w * is);
	}

	/// Multiplies two vectors component-wise
	constexpr Unstrided operator *(const Vec4& v) const
	{
		return Unstrided(x * v.x, y * v.y, z * v.z, w * v.w);
	}

	/// Adds two vectors
	constexpr Unstrided operator +(const Vec4& v) const
	{
		return Unstrided(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	/// Subtracts vector v2 from v1
	constexpr Unstrided operator -(const Vec4& v) const
	{
		return Unstrided(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	/// Negates vector v
	constexpr Unstrided operator -() const
	{
		return Unstrided(-x, -y, -z, -w);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] v									Comparison vector.
	/// @return												True if this and v are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	template <typename T2, Int S2> constexpr BoolType operator ==(const Vec4<T2, S2>& v) const
	{
		return x == v.x && y == v.y && z == v.z && w == v.w;
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												True if this and v are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator ==(const Vec4& v) const
	{
		return x == v.x && y == v.y && z == v.z && w == v.w;
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] v									Comparison vector.
	/// @return												False if this and v are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	template <typename T2, Int S2> constexpr BoolType operator !=(const Vec4<T2, S2>& v) const
	{
		return !(x == v.x && y == v.y && z == v.z && w == v.w);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	/// @param[in] v									Comparison vector.
	/// @return												False if this and v are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator !=(const Vec4& v) const
	{
		return !(x == v.x && y == v.y && z == v.z && w == v.w);
	}

	//----------------------------------------------------------------------------------------
	/// Compares this vector with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of vectors it can happen that neither @c{v <= w} nor @c{v >= w}.
	/// @param[in] v									Comparison vector.
	/// @return												True if this.c <= v.c for all components c of the vectors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator <=(const Vec4& v) const
	{
		return x <= v.x && y <= v.y && z <= v.z && w <= v.w;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this vector with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of vectors it can happen that neither @c{v <= w} nor @c{v >= w}.
	/// @param[in] v									Comparison vector.
	/// @return												True if this.c >= v.c for all components c of the vectors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator >=(const Vec4& v) const
	{
		return x >= v.x && y >= v.y && z >= v.z && w >= v.w;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this vector with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of vectors it can happen that neither @c{v < w} nor @c{v > w} nor @c{v == w}.
	/// Also note that @c{v < w} is not the same as @c{v <= w && v != w}.
	/// @param[in] v									Comparison vector.
	/// @return												True if this.c < v.c for all components c of the vectors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator <(const Vec4& v) const
	{
		return x < v.x && y < v.y && z < v.z && w < v.w;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this vector with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of vectors it can happen that neither @c{v < w} nor @c{v > w} nor @c{v == w}.
	/// Also note that @c{v > w} is not the same as @c{v >= w && v != w}.
	/// @param[in] v									Comparison vector.
	/// @return												True if this.c > v.c for all components c of the vectors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator >(const Vec4& v) const
	{
		return x > v.x && y > v.y && z > v.z && w > v.w;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the vector (used for hash maps and comparisons).
	/// @return												The vector's hash code.
	//----------------------------------------------------------------------------------------
	constexpr HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(x, y, z, w);
	}

	UniqueHash GetUniqueHashCode() const
	{
#ifdef STRIDE
		if constexpr (IsTriviallyHashable<T>::value)
			return UniqueHash::GetUniqueHashCode(ToBlock(&x, 4));
		else
#endif
			return DefaultCompare::GetCombinedUniqueHash(x, y, z, w);
	}

	/// Tests component-wise if the difference is no bigger than 'epsilon'
	BoolType IsEqual(const Vec4& other, ValueTypeParam epsilon) const
	{
		return Abs(x - other.x) <= epsilon && Abs(y - other.y) <= epsilon && Abs(z - other.z) <= epsilon && Abs(w - other.w) <= epsilon;
	}

	/// Calculates dot product of v1 and v2
	friend constexpr T Dot(const Vec4& v1, const Vec4& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the vector with absolute value for each entry
	/// @param[in] v1									input vector to work on
	/// @return												component wise absolute value vector of input vector
	//----------------------------------------------------------------------------------------
	friend Unstrided Abs(const Vec4& v1)
	{
		return Unstrided(Abs(v1.x), Abs(v1.y), Abs(v1.z), Abs(v1.w));
	}

	/// Calculates dot product of v1 and v2
	template <typename T2, Int S2> friend constexpr typename MultiplicativePromotion<T, T2>::type Dot(const Vec4& v1, const Vec4<T2, S2>& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	/// Checks if each component is zero.
	constexpr BoolType IsZero() const
	{
		return x == T(0) && y == T(0) && z == T(0) && w == T(0);
	}

	/// Sets all components to zero.
	void SetZero()
	{
		x = y = z = w = T(0);
	}

	/// Calculates the average value of 'x', 'y', 'z' and 'w'.
	constexpr T GetAverage() const
	{
		return (x + y + z + w) * T(0.25);
	}

	/// Calculates the sum of 'x', 'y', 'z' and 'w'.
	constexpr T GetSum() const
	{
		return x + y + z + w;
	}

	/// Calculates the minimum of each component.
	friend constexpr Unstrided Min(const Vec4& a, const Vec4& other)
	{
		return Unstrided(a.x < other.x ? a.x : other.x, a.y < other.y ? a.y : other.y, a.z < other.z ? a.z : other.z, a.w < other.w ? a.w : other.w); 
	}

	/// Calculates the maximum of each component.
	friend constexpr Unstrided Max(const Vec4& a, const Vec4& other)
	{
		return Unstrided(a.x > other.x ? a.x : other.x, a.y > other.y ? a.y : other.y, a.z > other.z ? a.z : other.z, a.w > other.w ? a.w : other.w); 
	}

	/// Set the minimum of each component.
	void ClampMin(const Vec4& other = Vec4())
	{
		maxon::SetMax(x, other.x);
		maxon::SetMax(y, other.y);
		maxon::SetMax(z, other.z);
		maxon::SetMax(w, other.w);
	}

	/// Set the maximum of each component.
	void ClampMax(const Vec4& other)
	{
		maxon::SetMin(x, other.x);
		maxon::SetMin(y, other.y);
		maxon::SetMin(z, other.z);
		maxon::SetMin(w, other.w);
	}

	/// Set the minimum of each component.
	friend void SetMin(Vec4& a, const Vec4& other)
	{
		a.ClampMax(other);
	}

	/// Set the maximum of each component.
	friend void SetMax(Vec4& a, const Vec4& other)
	{
		a.ClampMin(other);
	}

	/// Returns a vector that is clamped to the range [0.0 .. 1.0]
	constexpr Unstrided Clamp01() const
	{
		return Unstrided(maxon::Clamp01(x), maxon::Clamp01(y), maxon::Clamp01(z), maxon::Clamp01(w));
	}

	/// Returns the length of the vector
	T GetLength() const
	{
		return Sqrt(x * x + y * y + z * z + w * w);
	}

	/// Returns the squared length of the vector
	constexpr T	GetSquaredLength() const
	{
		return x * x + y * y + z * z + w * w;
	}

	/// Returns a normalized vector, so that GetLength(vector)==1.0
	Unstrided GetNormalized() const
	{
		T il = Inverse(Sqrt(x * x + y * y + z * z + w * w));
		return Unstrided(x * il, y * il, z * il, w * il);
	}

	/// Returns a normalized vector, so that GetLength(vector)==1.0
	Unstrided operator !() const
	{
		T il = Inverse(Sqrt(x * x + y * y + z * z + w * w));
		return Unstrided(x * il, y * il, z * il, w * il);
	}

	/// Normalizes this vector, so that GetLength()==1.0
	void Normalize()
	{
		T il = Inverse(Sqrt(x * x + y * y + z * z + w * w));
		x *= il;
		y *= il;
		z *= il;
		w *= il;
	}

	/// Calculates angle (in radians) between v1 and v2
	friend T GetAngle(const Vec4& v1, const Vec4& v2)
	{
		T il = Inverse(v1.GetSquaredLength() * v2.GetSquaredLength());
		return ACos(Dot(v1, v2) * Sqrt(il));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + maxon::ToString(x, formatStatement) + ","_s + maxon::ToString(y, formatStatement) + ","_s + maxon::ToString(z, formatStatement) + ","_s + maxon::ToString(w, formatStatement) + ")"_s;
	}

	/// Returns the minimum of 'x', 'y', 'z' and 'w'.
	constexpr T GetMin() const
	{
		return Min(Min(x, y), Min(z, w));
	}

	/// Returns the maximum of 'x', 'y', 'z' and 'w'.
	constexpr T GetMax() const
	{
		return Max(Max(x, y), Max(z, w));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector where the components have been rotated to the right (in the usual (x, y, z, w)-representation). E.g.,
	/// with a value of 1 for rots, the result will be (w, x, y, z).
	/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 4.
	/// @return												Vector with rotated components.
	//----------------------------------------------------------------------------------------
	constexpr Vec4 GetRightRotated(Int rots) const
	{
		switch (rots & 3)
		{
			case 0:
				return *this;
			case 1:
				return Vec4(w, x, y, z);
			case 2:
				return Vec4(z, w, x, y);
			default:
				return Vec4(y, z, w, x);
		}
	}

	/// Scales this vector such that w equals 1.
	void NormalizeW()
	{
		if (w == T(0))
		{
			x = LIMIT<T>::MAX;
			y = LIMIT<T>::MAX;
			z = LIMIT<T>::MAX;
		}
		else
		{
			T iw = Inverse(w);
			x *= iw;
			y *= iw;
			z *= iw;
		}
		w = T(1);
	}

	/// Multiplies vector by a matrix
	template <typename V> Vec4& operator *=(const SqrMat4<V>& m)
	{
		T xx = T(m.v1.x * x + m.v2.x * y + m.v3.x * z + m.v4.x * w);
		T yy = T(m.v1.y * x + m.v2.y * y + m.v3.y * z + m.v4.y * w);
		T zz = T(m.v1.z * x + m.v2.z * y + m.v3.z * z + m.v4.z * w);
		w = T(m.v1.w * x + m.v2.w * y + m.v3.w * z + m.v4.w * w);
		x = xx;
		y = yy;
		z = zz;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the vector (see nullvalue.h for more details).
	/// @return												A null value of the vector.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE const Vec4& NullValue()
	{
		return GetZeroRef<Vec4>();
	}
};

#ifndef STRIDE
/// Multiplies each vector component by a scalar
template <typename T, Int STR, typename S> inline Vec4<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s, const Vec4<T, STR>& v)
{
	return Vec4<typename MultiplicativePromotion<T, S>::type, 1>(v.x * s, v.y * s, v.z * s, v.w * s);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Vec4<T, 1>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	return ParametricTypes::Vec().Instantiate(t, ToSingletonBlock(Int64(4)));
}

template <typename T> struct IsZeroInitialized<Vec4<T, 1>> : public IsZeroInitialized<T> { };
#endif

}

#endif
