#ifndef SIMPLEMESH_H__
#define SIMPLEMESH_H__

#include "maxon/basearray.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Template class for simple triangles/quadrangles.
/// The class stores 4 indices. In case of a quadrangle the third and fourth are identical.
//----------------------------------------------------------------------------------------
template <typename T> class Poly
{
public:
	Poly() : a(), b(), c(), d() { }

	explicit Poly(ENUM_DONT_INITIALIZE) { }

	Poly(const T& av, const T& bv, const T& cv) : a(av), b(bv), c(cv), d(cv)
	{
	}

	Poly(const T& av, const T& bv, const T& cv, const T& dv) : a(av), b(bv), c(cv), d(dv)
	{
	}

	Poly(const Poly& src) : a(src.a), b(src.b), c(src.c), d(src.d)
	{
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(Poly);

	T& operator [](Int index)
	{
		DebugAssert((UInt) index < 4);
		return (&a)[index];
	}

	const T& operator [](Int index) const
	{
		DebugAssert((UInt) index < 4);
		return (&a)[index];
	}

	Bool IsTriangle() const
	{
		return c == d;
	}

	Int FindCornerIndex(const T& value) const
	{
		return (d == value ? 3 : (c == value ? 2 : (b == value ? 1 : (a == value ? 0 : NOTOK))));
	}

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

	void GetEdgeValues(Int edge, T& av, T& bv) const
	{
		av = (&a)[edge & 3];
		bv = (&a)[(edge + 1) & 3];
	}

	Int GetMemorySize() const
	{
		return SIZEOF(Poly);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(Poly, a, b, c, d);

	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + maxon::ToString(a, formatStatement) + ","_s + maxon::ToString(b, formatStatement)
			+ ","_s + maxon::ToString(c, formatStatement) + ","_s + maxon::ToString(d, formatStatement) + ")"_s;
	}

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

	T a;
	T b;
	T c;
	T d;
};

//----------------------------------------------------------------------------------------
/// Polygon class for simple triangles/quadrangles that is compatible with Melange.
/// It uses Int32 as data type while the new MeshPolygon uses MeshValue/UInt32.
//----------------------------------------------------------------------------------------
using SimplePolygon = Poly<Int32>;
MAXON_DATATYPE(SimplePolygon, "net.maxon.geom.simplepolygon");

// Definition for melange.
using UVWPolygon = Poly<Vector>;
MAXON_DATATYPE(UVWPolygon, "net.maxon.geom.uvwpolygon");

// Simple object definition for melange interface.
class SimpleMeshObject
{
public:
	Int GetMemorySize() const;

	BaseArray<Vector>					_vertex;
	BaseArray<SimplePolygon>	_polygon;
	BaseArray<UVWPolygon>			_uvw;
};

// TODO: (Franz) for now is a tuple as it will work weel with node editor, should be possibly a vec2
using TangentPair = Tuple<Vector, Vector>; /// < 3d Tangent basic data type
using TangentPair2d = Tuple<Vector2d, Vector2d>; /// < 2d Tangent basic data type

#include "simplemesh1.hxx"
#include "simplemesh2.hxx"

} // namespace maxon

#endif // MESH_H__
