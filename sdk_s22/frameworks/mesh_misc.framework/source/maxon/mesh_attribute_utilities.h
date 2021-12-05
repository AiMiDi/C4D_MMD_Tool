#ifndef MESH_ATTRIBUTE_UTILITIES_H__
#define MESH_ATTRIBUTE_UTILITIES_H__

#include "maxon/apibase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Template class used to attach data to polygon vertices.
/// The polygon could be either a triangle or a quadrangle.
//----------------------------------------------------------------------------------------
template <typename T> class PolyData
{
public:

	using ValueType = T;

	PolyData() : a(), b(), c(), d() { }

	explicit PolyData(ENUM_DONT_INITIALIZE) { }

	PolyData(const T& av, const T& bv, const T& cv, const T& dv) : a(av), b(bv), c(cv), d(dv)
	{
	}

	PolyData(const PolyData& src) : a(src.a), b(src.b), c(src.c), d(src.d)
	{
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(PolyData);

	//----------------------------------------------------------------------------------------
	/// Vertex data array operator.
	/// Accesses the polygon's vertex values through their polygon vertex numbers (@em 0 - @em 3) instead of @ref a, @ref b, @ref c, @ref d.
	/// @param[in] index							The vertex index (@em 0 - @em 3) to retrieve in the polygon.
	/// @return												The vertex value.
	//----------------------------------------------------------------------------------------
	T& operator [](Int index)
	{
		DebugAssert((UInt) index < 4);
		return (&a)[index];
	}

	//----------------------------------------------------------------------------------------
	/// Vertex data array operator.
	/// Accesses the polygon's vertex values through their polygon vertex numbers (@em 0 - @em 3) instead of @ref a, @ref b, @ref c, @ref d.
	/// @param[in] index							The vertex index (@em 0 - @em 3) to retrieve in the polygon.
	/// @return												The vertex value.
	//----------------------------------------------------------------------------------------
	const T& operator [](Int index) const
	{
		DebugAssert((UInt) index < 4);
		return (&a)[index];
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the polygon is a triangle.
	/// @return												@trueIfOtherwiseFalse{the polygon is a triangle}
	//----------------------------------------------------------------------------------------
	Bool IsTriangle() const
	{
		return c == d;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if one of the polygon vertex value is equal to value and returns the found polygon vertex number (@em 0 - @em 3, equals @ref a - @ref d).
	/// @param[in] value							The vertex value to check.
	/// @return												The matching polygon vertex number (@em 0 - @em 3, equals @ref a - @ref d). @ref NOTOK is returned if there is no match.
	//----------------------------------------------------------------------------------------
	Int FindCornerIndex(const T& value) const
	{
		return (d == value ? 3 : (c == value ? 2 : (b == value ? 1 : (a == value ? 0 : NOTOK))));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the polygon edge that contains vertex values @formatParam{value1} and @formatParam{value2} and returns the edge index within (@em 0 - @em 3).
	/// @param[in] value1							The index of the first edge vertex.
	/// @param[in] value2							The index of the second edge vertex.
	/// @return												The found polygon edge index (@em 0 - @em 3), or @ref NOTOK if there is no match.
	//----------------------------------------------------------------------------------------
	Int FindEdge(const T& value1, const T& value2) const
	{
		if (d == value1)
			return a == value2 ? 3 : (c == d ? (b == value2 ? 1 : NOTOK) : (c == value2 ? 2 : NOTOK));
		if (c == value1)
			return b == value2 ? 1 : (c == d ? (a == value2 ? 3 : NOTOK) : (d == value2 ? 2 : NOTOK));
		if (b == value1)
			return c == value2 ? 1 : (a == value2 ? 0 : NOTOK);
		if (a == value1)
			return b == value2 ? 0 : (d == value2 ? 3 : NOTOK);
		return NOTOK;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the vertex values for a polygon @formatParam{edge} index within (@em 0 - @em 3).
	/// @param[in] edge								The polygon edge index.
	/// @param[out] av								Assigned the value of the first edge vertex.
	/// @param[out] bv								Assigned the value of the second edge vertex.
	//----------------------------------------------------------------------------------------
	void GetEdgeValues(Int edge, T& av, T& bv) const
	{
		av = (&a)[edge & 3];
		bv = (&a)[(edge + 1) & 3];
	}

	//----------------------------------------------------------------------------------------
	/// Returns the size of the data.
	/// @return												The size of the data.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		return SIZEOF(PolyData);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(PolyData, a, b, c, d);

	//----------------------------------------------------------------------------------------
	/// Returns a string which represents the data.
	/// @param[in] formatStatement		Optional format statement.
	/// @return												A human readable string.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + maxon::ToString(a, formatStatement) + ","_s + maxon::ToString(b, formatStatement)
		+ ","_s + maxon::ToString(c, formatStatement) + ","_s + maxon::ToString(d, formatStatement) + ")"_s;
	}

	T a;	///< Value of the first polygon vertex.
	T	b;	///< Value of the second polygon vertex.
	T	c;	///< Value of the third polygon vertex.
	T	d;	///< Value of the fourth polygon vertex.
};

} // namespace maxon

#endif // MESH_ATTRIBUTE_UTILITIES_H__
