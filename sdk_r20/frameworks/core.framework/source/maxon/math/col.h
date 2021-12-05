// This file must have no header guards

#ifndef MAXON_VECTORMODE
#error "This file must not be included directly, include vector.h instead"
#endif

/// A color consisting of three components R, G and B.
#ifdef STRIDE
template <typename T> struct Col3<T, 1>
#else
template <typename T, Int STRIDE = 1> struct Col3
#endif
{
// TODO: (Ingo) remove when at least GCC 4.9.4 is used.
#ifdef MAXON_COMPILER_GCC
	template <typename U> struct Workaround
	{
		using type = Col3<U, STRIDE>;
	};
	template <typename U> using Rebind = typename Workaround<U>::type;
#else
	template <typename U> using Rebind = Col3<U, STRIDE>;
#endif
	using VectorStrideType = std::integral_constant<Int, STRIDE>;
	using ValueType = T;
	using ValueTypeParam = typename ByValueParam<T>::type;
	using Unstrided = Col3<T, 1>;

	/// The type returned by comparisons. If the template argument for T is a SIMD type,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = decltype(T() == T());

#ifdef STRIDE
	T r;
	T g;
	T b;
#else	
	union { T r; T _xpadding[STRIDE]; };
	union { T g; T _ypadding[STRIDE]; };
	union { T b; T _zpadding[STRIDE]; };
#endif

	/// Initializes all vector components with 0.0
	Col3() : r(0), g(0), b(0) { }

	/// Initializes all vector components with a scalar
	explicit Col3(ValueTypeParam in) : r(in), g(in), b(in) { }

	/// Initializes all vector components individually
	explicit Col3(ValueTypeParam ix, ValueTypeParam iy, ValueTypeParam iz) : r(ix), g(iy), b(iz) { }

	/// Initializes components from another 3d vector.
	template <typename T2, Int S2> explicit Col3(const Col3<T2, S2>& v) : r((T)v.r), g((T)v.g), b((T)v.b) { }
	template <typename T2, Int S2> explicit Col3(const Vec3<T2, S2>& v) : r((T)v.x), g((T)v.y), b((T)v.z) { }
	template <typename T2, Int S2> explicit Col3(const Col4<T2, S2>& v) : r((T)v.r * (T)v.a), g((T)v.g * (T)v.a), b((T)v.b * (T)v.a) { }

	template <Int S2> Col3(const Col3<T, S2>& v) : r(v.r), g(v.g), b(v.b) { }

	/// Skips initialization of vector (for better speed)
	explicit Col3(ENUM_DONT_INITIALIZE v) { }

	// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
	// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
	MAXON_IMPLICIT Col3(const typename std::conditional<STRIDE == 1, DummyParamType, Col3>::type& src) : MAXON_MOVE_MEMBERS(r, g, b)
	{
	}

	Col3& operator =(const typename std::conditional<STRIDE == 1, DummyParamType, Col3>::type& src)
	{
		r = src.r;
		g = src.g;
		b = src.b;
		return *this;
	}

	/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'. All other values must not be used and will crash
	T& operator [](Int l)
	{
		DebugAssert(UInt(l) < 3);
		return ((T*)this)[STRIDE * l];
	}

	/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'.  All other values must not be used and will crash
	ValueTypeParam operator [](Int l) const
	{
		DebugAssert(UInt(l) < 3);
		return ((const T*)this)[STRIDE * l];
	}

	/// Adds two vectors
	template <typename T2, Int S2> Col3& operator +=(const Col3<T2, S2>& v)
	{
		r += v.r;
		g += v.g;
		b += v.b;
		return *this;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	Col3& operator +=(const Col3& v)
	{
		r += v.r;
		g += v.g;
		b += v.b;
		return *this;
	}

	/// Subtracts two vectors
	template <typename T2, Int S2> Col3& operator -=(const Col3<T2, S2>& v)
	{
		r -= v.r;
		g -= v.g;
		b -= v.b;
		return *this;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	Col3& operator -=(const Col3& v)
	{
		r -= v.r;
		g -= v.g;
		b -= v.b;
		return *this;
	}

	/// Multiplies two vectors component-wise
	template <typename T2, Int S2> Col3& operator *=(const Col3<T2, S2>& v)
	{
		r *= v.r;
		g *= v.g;
		b *= v.b;
		return *this;
	}

	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	Col3& operator *=(const Col3& v)
	{
		r *= v.r;
		g *= v.g;
		b *= v.b;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	Col3& operator *=(ValueTypeParam s)
	{
		r *= s;
		g *= s;
		b *= s;
		return *this;
	}

	/// Divides each vector component by a scalar. The passed argument is checked for 0.0
	Col3& operator /=(ValueTypeParam s)
	{
		T is = Inverse(s);
		r *= is;
		g *= is;
		b *= is;
		return *this;
	}

	/// Multiplies each vector component by a scalar
	friend Unstrided operator *(ValueTypeParam s, const Col3& v)
	{
		return Unstrided(s * v.r, s * v.g, s * v.b);
	}

	/// Multiplies each vector component by a scalar
	Unstrided operator *(ValueTypeParam s) const
	{
		return Unstrided(r * s, g * s, b * s);
	}

	/// Multiplies each vector component by a scalar
	template <typename S> Col3<typename MultiplicativePromotion<T, S, std::is_scalar<S>::value>::type, 1> operator *(S s) const
	{
		return Col3<typename MultiplicativePromotion<T, S>::type, 1>(r * s, g * s, b * s);
	}

	/// Divides each vector component by a scalar. The scalar value is tested for 0.0
	Unstrided operator /(ValueTypeParam s) const
	{
		T is = Inverse(s);
		return Unstrided(r * is, g * is, b * is);
	}

	/// Multiplies two vectors component-wise
	Unstrided operator *(const Col3& v) const
	{
		return Unstrided(r * v.r, g * v.g, b * v.b);
	}

	/// Adds two vectors
	Unstrided operator +(const Col3& v) const
	{
		return Unstrided(r + v.r, g + v.g, b + v.b);
	}

	/// Subtracts vector v2 from v1
	Unstrided operator -(const Col3& v) const
	{
		return Unstrided(r - v.r, g - v.g, b - v.b);
	}

	/// Negates vector v
	Unstrided operator -() const
	{
		return Unstrided(-r, -g, -b);
	}

	template <typename T2, Int S2> BoolType operator ==(const Col3<T2, S2>& v) const
	{
		return r == v.r && g == v.g && b == v.b;
	}
	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	BoolType operator ==(const Col3& v) const
	{
		return r == v.r && g == v.g && b == v.b;
	}

	template <typename T2, Int S2> BoolType operator !=(const Col3<T2, S2>& v) const
	{
		return !(r == v.r && g == v.g && b == v.b);
	}
	// we repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
	BoolType operator !=(const Col3& v) const
	{
		return !(r == v.r && g == v.g && b == v.b);
	}

	UInt GetHashCode() const
	{
		return MAXON_HASHCODE(r, g, b);
	}

	/// Tests component-wise if the difference is no bigger than 'epsilon'
	BoolType IsEqual(const Col3& other, ValueTypeParam epsilon) const
	{
		return Abs(r - other.r) < epsilon && Abs(g - other.g) < epsilon && Abs(b - other.b) < epsilon;
	}

	//----------------------------------------------------------------------------------------
	/// returns the vector with absolute value for each entry
	/// @param[in] v1									input vector to work on
	/// @return												component wise absolute value vector of input vector
	//----------------------------------------------------------------------------------------
	friend Unstrided Abs(const Col3& v1)
	{
		return Unstrided(Abs(v1.r), Abs(v1.g), Abs(v1.b));
	}

	/// Checks if each component is zero.
	BoolType IsZero() const
	{
		return r == T(0) && g == T(0) && b == T(0);
	}

	/// Sets all components to zero.
	void SetZero()
	{
		r = g = b = T(0);
	}

	/// Calculates the average value of 'r', 'g' and 'b'
	T GetAverage() const
	{
		return (r + g + b) * T(1.0 / 3.0);
	}

	/// Calculates the sum of 'r', 'g' and 'b'
	T GetSum() const
	{
		return r + g + b;
	}

	/// Calculates the minimum of each component.
	friend Unstrided Min(const Col3& a, const Col3& other)
	{
		return Unstrided(a.r < other.r ? a.r : other.r, a.g < other.g ? a.g : other.g, a.b < other.b ? a.b : other.b); 
	}

	/// Calculates the maximum of each component.
	friend Unstrided Max(const Col3& a, const Col3& other)
	{
		return Unstrided(a.r > other.r ? a.r : other.r, a.g > other.g ? a.g : other.g, a.b > other.b ? a.b : other.b); 
	}

	/// Set the minimum of each component.
	void ClampMin(const Col3& other = Col3())
	{
		maxon::SetMax(r, other.r);
		maxon::SetMax(g, other.g);
		maxon::SetMax(b, other.b);
	}

	/// Set the maximum of each component.
	void ClampMax(const Col3& other)
	{
		maxon::SetMin(r, other.r);
		maxon::SetMin(g, other.g);
		maxon::SetMin(b, other.b);
	}

	/// Set the minimum of each component.
	friend void SetMin(Col3& a, const Col3& other)
	{
		a.ClampMax(other);
	}

	/// Set the maximum of each component.
	friend void SetMax(Col3& a, const Col3& other)
	{
		a.ClampMin(other);
	}

	/// Returns a vector that is clamped to the range [0.0 .. 1.0]
	Unstrided Clamp01() const
	{
		return Unstrided(maxon::Clamp01(r), maxon::Clamp01(g), maxon::Clamp01(b));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + maxon::ToString(r, formatStatement) + ","_s + maxon::ToString(g, formatStatement) + ","_s + maxon::ToString(b, formatStatement) + ")"_s;
	}

	// the following functions are Col3-specific, they cannot be copied to Vec2 and Vec4

	/// Reinterprets the color as vector.
	const Vec3<T, STRIDE>& GetVector() const { return *(const Vec3<T, STRIDE>*) this; }
	Vec3<T, STRIDE>& GetVector() { return *(Vec3<T, STRIDE>*) this; }

	/// Returns the minimum of 'r', 'g' and 'b'
	T GetMin() const
	{
		if (r < g)
		{
			return (b < r) ? b : r;
		}
		else
		{
			return (b < g) ? b : g;
		}
	}

	/// Returns the maximum of 'r', 'g' and 'b'
	T GetMax() const
	{
		if (r > g)
		{
			return (b > r) ? b : r;
		}
		else
		{
			return (b > g) ? b : g;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns a vector where the components have been rotated to the right (in the usual (r, g, b)-representation). E.g.,
	/// with a value of 1 for rots, the result will be (b, r, g).
	/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 3.
	/// @return												Vector with rotated components.
	//----------------------------------------------------------------------------------------
	Unstrided GetRightRotated(Int rots) const
	{
		while (true)
		{
			switch (rots)
			{
				case 0:
					return *this;
				case 1:
				case -2:
					return Unstrided(b, r, g);
				case 2:
				case -1:
					return Unstrided(g, b, r);
				default:
					rots %= 3;
					break;
			}
		}
	}

	/// Transforms color by a matrix
	template <typename T2> Col3& operator *=(const Mat3<T2>& m)
	{
		T xx = T(m.off.x + m.sqmat.v1.x * r + m.sqmat.v2.x * g + m.sqmat.v3.x * b);
		T yy = T(m.off.y + m.sqmat.v1.y * r + m.sqmat.v2.y * g + m.sqmat.v3.y * b);
		b = T(m.off.z + m.sqmat.v1.z * r + m.sqmat.v2.z * g + m.sqmat.v3.z * b);
		r = xx;
		g = yy;
		return *this;
	}

	static const Col3& NullValue()
	{
		return GetZeroRef<Col3>();
	}
};

#ifndef STRIDE
/// Multiplies each vector component by a scalar
template <typename T, Int STR, typename S> inline Col3<typename MultiplicativePromotion<T, S, std::is_scalar<S>::value>::type, 1> operator *(S s, const Col3<T, STR>& v)
{
	return Col3<typename MultiplicativePromotion<T, S>::type, 1>(v.r * s, v.g * s, v.b * s);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(Col3<T, 1>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, POLICY | GET_DATATYPE_POLICY::NO_DECAY>() iferr_return;
	return ParametricTypes::Col().Instantiate(t, ToSingletonBlock(Int64(3)));
}

template <typename T> struct IsZeroInitialized<Col3<T, 1>> : public IsZeroInitialized<T> { };
#endif
