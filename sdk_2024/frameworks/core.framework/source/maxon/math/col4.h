#ifndef COL4_H__ // This file is included several times, so it must not define the header guard.

#ifndef MAXON_VECTORMODE
#error "This file must not be included directly, include vector4d.h instead"
#endif

namespace maxon
{

/// A color consisting of three components R, G, B and an alpha.
#ifdef STRIDE
template <typename T> struct Col4<T, 1>
#else
template <typename T, Int STRIDE = 1> struct Col4
#endif
{
	template <typename U> using Rebind = Col4<U, STRIDE>;
	using VectorStrideType = std::integral_constant<Int, STRIDE>;
	using ValueType = T;
	using ValueTypeParam = typename ByValueParam<T>::type;
	using Unstrided = Col4<T, 1>;

	/// The type returned by comparisons. If the template argument for T is a SIMD type,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = decltype(T() == T());

#ifdef STRIDE
	T r;
	T g;
	T b;
	T a;

	static constexpr Bool TriviallyHashable() { return IsTriviallyHashable<T>::value; }
#else
	union { T r; T _xpadding[STRIDE]; };
	union { T g; T _ypadding[STRIDE]; };
	union { T b; T _zpadding[STRIDE]; };
	union { T a; T _wpadding[STRIDE]; };
#endif

	/// Initializes all color components with 0.0 and the alpha with 1.0.
	constexpr Col4() : r(0), g(0), b(0), a(T(1)) { }

	/// Initializes all color components with a scalar and the alpha with 1.0.
	explicit constexpr Col4(ValueTypeParam in) : r(in), g(in), b(in), a(T(1)) { }

	/// Initializes all vector components individually
	explicit constexpr Col4(ValueTypeParam ix, ValueTypeParam iy, ValueTypeParam iz, ValueTypeParam iw) : r(ix), g(iy), b(iz), a(iw) { }

	/// Initializes components from another 4d vector.
	template <typename T2, Int S2> explicit constexpr Col4(const Col4<T2, S2>& v) : r((T)v.r), g((T)v.g), b((T)v.b), a((T)v.a) { }
	template <typename T2, Int S2> explicit constexpr Col4(const Vec4<T2, S2>& v) : r((T)v.x), g((T)v.y), b((T)v.z), a((T)v.w) { }

	template <Int S2> constexpr Col4(const Col4<T, S2>& v) : r(v.r), g(v.g), b(v.b), a(v.a) { }

	/// Initializes components from a 3d vector and add an additional value for the a-component.
	/// The default value for the alpha is 1.0.
	template <typename T2, Int S2> explicit constexpr Col4(const Col3<T2, S2>& v, T iw = T(1)) : r((T)v.r), g((T)v.g), b((T)v.b), a(iw) { }

	/// Skips initialization of vector (for better speed)
	explicit constexpr Col4(ENUM_DONT_INITIALIZE v) { }

	/// Reinterprets the color as vector.
	constexpr const Vec4<T, STRIDE>& GetVector() const { return *(const Vec4<T, STRIDE>*) this; }
	constexpr Vec4<T, STRIDE>& GetVector() { return *(Vec4<T, STRIDE>*) this; }

	/// Gets the r/g/b components as a color without alpha.
	constexpr const Col3<T, STRIDE>& GetColor3() const { return *(const Col3<T, STRIDE>*) this; }

	// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
	// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
	MAXON_IMPLICIT constexpr Col4(const typename std::conditional<STRIDE == 1, DummyParamType, Col4>::type& src) : MAXON_MOVE_MEMBERS(r, g, b, a)
	{
	}

	constexpr Col4& operator =(const typename std::conditional<STRIDE == 1, DummyParamType, Col4>::type& src)
	{
		r = src.r;
		g = src.g;
		b = src.b;
		a = src.a;
		return *this;
	}

	/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'. All other values must not be used and will crash
	T& operator[](Int l)
	{
		DebugAssert(UInt(l) < 4);
		return reinterpret_cast<T*>(this)[STRIDE * l];
	}

	/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'.  All other values must not be used and will crash
	ValueTypeParam operator[](Int l) const
	{
		DebugAssert(UInt(l) < 4);
		return reinterpret_cast<const T*>(this)[STRIDE * l];
	}

	/// Adds two vectors
	template <typename T2, Int S2> constexpr Col4& operator +=(const Col4<T2, S2>& v)
	{
		r += v.r;
		g += v.g;
		b += v.b;
		a += v.a;
		return *this;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	constexpr Col4& operator +=(const Col4& v)
	{
		r += v.r;
		g += v.g;
		b += v.b;
		a += v.a;
		return *this;
	}

	/// Subtracts two vectors
	template <typename T2, Int S2> constexpr Col4& operator -=(const Col4<T2, S2>& v)
	{
		r -= v.r;
		g -= v.g;
		b -= v.b;
		a -= v.a;
		return *this;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	constexpr Col4& operator -=(const Col4& v)
	{
		r -= v.r;
		g -= v.g;
		b -= v.b;
		a -= v.a;
		return *this;
	}

	/// Multiplies two vectors component-wise
	template <typename T2, Int S2> constexpr Col4& operator *=(const Col4<T2, S2>& v)
	{
		r *= v.r;
		g *= v.g;
		b *= v.b;
		a *= v.a;
		return *this;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	constexpr Col4& operator *=(const Col4& v)
	{
		r *= v.r;
		g *= v.g;
		b *= v.b;
		a *= v.a;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	constexpr Col4& operator *=(ValueTypeParam s)
	{
		r *= s;
		g *= s;
		b *= s;
		a *= s;
		return *this;
	}

	/// Divides each vector component by a scalar. The passed argument is checked for 0.0
	constexpr Col4& operator /=(ValueTypeParam s)
	{
		T is = Inverse(s);
		r *= is;
		g *= is;
		b *= is;
		a *= is;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	friend constexpr Unstrided operator *(ValueTypeParam s, const Col4& v)
	{
		return Unstrided(s * v.r, s * v.g, s * v.b, s * v.a);
	}

	/// Multiplies each vector component by a scalar
	constexpr Unstrided operator *(ValueTypeParam s) const
	{
		return Unstrided(r * s, g * s, b * s, a * s);
	}

	/// Multiplies each vector component by a scalar
	template <typename S> constexpr Col4<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s) const
	{
		return Col4<typename MultiplicativePromotion<T, S>::type, 1>(r * s, g * s, b * s, a * s);
	}

	/// Divides each vector component by a scalar. The scalar value is tested for 0.0
	constexpr Unstrided operator /(ValueTypeParam s) const
	{
		T is = Inverse(s);
		return Unstrided(r * is, g * is, b * is, a * is);
	}

	/// Multiplies two vectors component-wise
	constexpr Unstrided operator *(const Col4& v) const
	{
		return Unstrided(r * v.r, g * v.g, b * v.b, a * v.a);
	}

	/// Adds two vectors
	constexpr Unstrided operator +(const Col4& v) const
	{
		return Unstrided(r + v.r, g + v.g, b + v.b, a + v.a);
	}

	/// Subtracts vector v2 from v1
	constexpr Unstrided operator -(const Col4& v) const
	{
		return Unstrided(r - v.r, g - v.g, b - v.b, a - v.a);
	}

	/// Negates vector v
	constexpr Unstrided operator -() const
	{
		return Unstrided(-r, -g, -b, -a);
	}

	template <typename T2, Int S2> constexpr BoolType operator ==(const Col4<T2, S2>& v) const
	{
		return r == v.r && g == v.g && b == v.b && a == v.a;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	constexpr BoolType operator ==(const Col4& v) const
	{
		return r == v.r && g == v.g && b == v.b && a == v.a;
	}

	template <typename T2, Int S2> constexpr BoolType operator !=(const Col4<T2, S2>& v) const
	{
		return !(r == v.r && g == v.g && b == v.b && a == v.a);
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	constexpr BoolType operator !=(const Col4& v) const
	{
		return !(r == v.r && g == v.g && b == v.b && a == v.a);
	}

	//----------------------------------------------------------------------------------------
	/// Compares this color with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of colors it can happen that neither @c{v <= w} nor @c{v >= w}.
	/// @param[in] v									Comparison color.
	/// @return												True if this.c <= v.c for all components c of the colors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator <=(const Col4& v) const
	{
		return r <= v.r && g <= v.g && b <= v.b && a <= v.a;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this color with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of colors it can happen that neither @c{v <= w} nor @c{v >= w}.
	/// @param[in] v									Comparison color.
	/// @return												True if this.c >= v.c for all components c of the colors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator >=(const Col4& v) const
	{
		return r >= v.r && g >= v.g && b >= v.b && a >= v.a;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this color with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of colors it can happen that neither @c{v < w} nor @c{v > w} nor @c{v == w}.
	/// Also note that @c{v < w} is not the same as @c{v <= w && v != w}.
	/// @param[in] v									Comparison color.
	/// @return												True if this.c < v.c for all components c of the colors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator <(const Col4& v) const
	{
		return r < v.r && g < v.g && b < v.b && a < v.a;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this color with v. Note that this doesn't define a total order but just
	/// a partial order, so for a pair of colors it can happen that neither @c{v < w} nor @c{v > w} nor @c{v == w}.
	/// Also note that @c{v > w} is not the same as @c{v >= w && v != w}.
	/// @param[in] v									Comparison color.
	/// @return												True if this.c > v.c for all components c of the colors, false otherwise.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator >(const Col4& v) const
	{
		return r > v.r && g > v.g && b > v.b && a > v.a;
	}

	constexpr HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(r, g, b, a);
	}

	UniqueHash GetUniqueHashCode() const
	{
#ifdef STRIDE
		if constexpr (IsTriviallyHashable<T>::value)
			return UniqueHash::GetUniqueHashCode(ToBlock(&r, 4));
		else
#endif
			return DefaultCompare::GetCombinedUniqueHash(r, g, b, a);
	}

	/// Tests component-wise if the difference is no bigger than 'epsilon'
	constexpr BoolType IsEqual(const Col4& other, ValueTypeParam epsilon) const
	{
		return Abs(r - other.r) <= epsilon && Abs(g - other.g) <= epsilon && Abs(b - other.b) <= epsilon && Abs(a - other.a) <= epsilon;
	}

	/// Calculates dot product of v1 and v2
	friend constexpr T Dot(const Col4& v1, const Col4& v2)
	{
		return v1.r * v2.r + v1.g * v2.g + v1.b * v2.b + v1.a * v2.a;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the vector with absolute value for each entry
	/// @param[in] v1									input vector to work on
	/// @return												component wise absolute value vector of input vector
	//----------------------------------------------------------------------------------------
	friend constexpr Unstrided Abs(const Col4& v1)
	{
		return Unstrided(Abs(v1.r), Abs(v1.g), Abs(v1.b), Abs(v1.a));
	}

	/// Calculates dot product of v1 and v2
	template <typename T2, Int S2> friend constexpr typename MultiplicativePromotion<T, T2>::type Dot(const Col4& v1, const Col4<T2, S2>& v2)
	{
		return v1.r * v2.r + v1.g * v2.g + v1.b * v2.b + v1.a * v2.a;
	}

	/// Checks if each component is zero.
	constexpr BoolType IsZero() const
	{
		return r == T(0) && g == T(0) && b == T(0) && a == T(0);
	}

	/// Sets all components to zero.
	constexpr void SetZero()
	{
		r = g = b = a = T(0);
	}

	/// Calculates the average value of 'r', 'g', 'b' and 'a'.
	constexpr T GetAverage() const
	{
		return (r + g + b + a) * T(0.25);
	}

	/// Calculates the sum of 'r', 'g', 'b' and 'a'.
	constexpr T GetSum() const
	{
		return r + g + b + a;
	}

	/// Calculates the minimum of each component.
	friend constexpr Unstrided Min(const Col4& th, const Col4& other)
	{
		return Unstrided(th.r < other.r ? th.r : other.r, th.g < other.g ? th.g : other.g, th.b < other.b ? th.b : other.b, th.a < other.a ? th.a : other.a); 
	}

	/// Calculates the maximum of each component.
	friend constexpr Unstrided Max(const Col4& th, const Col4& other)
	{
		return Unstrided(th.r > other.r ? th.r : other.r, th.g > other.g ? th.g : other.g, th.b > other.b ? th.b : other.b, th.a > other.a ? th.a : other.a); 
	}

	/// Set the minimum of each component.
	constexpr void ClampMin(const Col4& other = Col4())
	{
		maxon::SetMax(r, other.r);
		maxon::SetMax(g, other.g);
		maxon::SetMax(b, other.b);
		maxon::SetMax(a, other.a);
	}

	/// Set the maximum of each component.
	constexpr void ClampMax(const Col4& other)
	{
		maxon::SetMin(r, other.r);
		maxon::SetMin(g, other.g);
		maxon::SetMin(b, other.b);
		maxon::SetMin(a, other.a);
	}

	/// Set the minimum of each component.
	friend constexpr void SetMin(Col4& th, const Col4& other)
	{
		th.ClampMax(other);
	}

	/// Set the maximum of each component.
	friend constexpr void SetMax(Col4& th, const Col4& other)
	{
		th.ClampMin(other);
	}

	/// Returns a vector that is clamped to the range [0.0 .. 1.0]
	constexpr Unstrided Clamp01() const
	{
		return Unstrided(maxon::Clamp01(r), maxon::Clamp01(g), maxon::Clamp01(b), maxon::Clamp01(a));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + maxon::ToString(r, formatStatement) + ","_s + maxon::ToString(g, formatStatement) + ","_s + maxon::ToString(b, formatStatement) + ","_s + maxon::ToString(a, formatStatement) + ")"_s;
	}

	/// Returns the minimum of 'r', 'g', 'b' and 'a'.
	constexpr T GetMin() const
	{
		return Min(Min(r, g), Min(b, a));
	}

	/// Returns the maximum of 'r', 'g', 'b' and 'a'.
	constexpr T GetMax() const
	{
		return Max(Max(r, g), Max(b, a));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector where the components have been rotated to the right (in the usual (r, g, b, a)-representation). E.g.,
	/// with a value of 1 for rots, the result will be (a, r, g, b).
	/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 4.
	/// @return												Vector with rotated components.
	//----------------------------------------------------------------------------------------
	constexpr Col4 GetRightRotated(Int rots) const
	{
		switch (rots & 3)
		{
			case 0:
				return *this;
			case 1:
				return Col4(a, r, g, b);
			case 2:
				return Col4(b, a, r, g);
		}
		return Col4(g, b, a, r);
	}

	/// Multiplies vector by a matrix
	template <typename V> constexpr Col4& operator *=(const SqrMat4<V>& m)
	{
		T xx = T(m.v1.r * r + m.v2.r * g + m.v3.r * b + m.v4.r * a);
		T yy = T(m.v1.g * r + m.v2.g * g + m.v3.g * b + m.v4.g * a);
		T zz = T(m.v1.b * r + m.v2.b * g + m.v3.b * b + m.v4.b * a);
		a = T(m.v1.a * r + m.v2.a * g + m.v3.a * b + m.v4.a * a);
		r = xx;
		g = yy;
		b = zz;
		return *this;
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE const Col4& DefaultValue()
	{
		return maxon::DefaultDefaultValue<Col4>::value;
	}
};

#ifndef STRIDE
/// Multiplies each vector component by a scalar
template <typename T, Int STR, typename S> inline Col4<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar, S)>::type, 1> operator *(S s, const Col4<T, STR>& v)
{
	return Col4<typename MultiplicativePromotion<T, S>::type, 1>(v.r * s, v.g * s, v.b * s, v.a * s);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Col4<T, 1>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	return ParametricTypes::Col().Instantiate(t, ToSingletonBlock(Int64(4)));
}
#endif

}

#endif
