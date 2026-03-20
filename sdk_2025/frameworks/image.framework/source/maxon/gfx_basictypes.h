#ifndef GFX_BASICTYPES_H__
#define GFX_BASICTYPES_H__

#include "maxon/string.h"
#include "maxon/datatype.h"
#include "maxon/vector2d.h"
#include "maxon/range.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Size of a window/drawing operation.
//----------------------------------------------------------------------------------------
template <typename T> struct DrawDimension
{
	T width, height;

	DrawDimension() : width(T()), height(T())
	{
	}

	DrawDimension(T w, T h) : width(w), height(h)
	{
	}

	MAXON_IMPLICIT DrawDimension(const Vec2<T, 1>& src) : width(src.x), height(src.y)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + Data(width).ToString(formatStatement) + ","_s + Data(height).ToString(formatStatement) + ")"_s;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(DrawDimension, width, height);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);
};

template <typename T> struct IsZeroInitialized<DrawDimension<T>> : public IsZeroInitialized<T> { };

//----------------------------------------------------------------------------------------
/// DrawDimension for Int types.
//----------------------------------------------------------------------------------------
using DrawDimensionInt = DrawDimension<Int>;
MAXON_DATATYPE(DrawDimensionInt, "net.maxon.image.drawdimensionint", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

//----------------------------------------------------------------------------------------
/// DrawDimension for Float types.
//----------------------------------------------------------------------------------------
using DrawDimensionFloat = DrawDimension<Float>;
MAXON_DATATYPE(DrawDimensionFloat, "net.maxon.image.drawdimensionfloat", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));


//----------------------------------------------------------------------------------------
/// Definition of a rectangle used for window/draw operations.
//----------------------------------------------------------------------------------------
template <typename T> struct DrawRect
{
public:
  DrawRect(Vec2<T, 1> positionValue, DrawDimension<T> sizeValue) : position(positionValue), size(sizeValue)
  {
  }

  DrawRect(T x, T y, T w, T h) : position(x, y), size(w, h)
  {
  }

	MAXON_IMPLICIT DrawRect(const Range<Vec2<T, 1>>& src) : position(src.GetMin()), size(src.GetMax() - src.GetMin())
	{
	}

public:
	Vec2<T, 1>       position;
	DrawDimension<T> size;

	DrawRect()
	{
	}

	const Vec2<T, 1>& GetOriginPoint() const
	{
		return position;
	}

	T GetEndX() const
	{
		return position.x + size.width;
	}

	T GetEndY() const
	{
		return position.y + size.height;
	}

	Vec2<T, 1> GetEndPoint() const
	{
		return Vec2<T, 1>(GetEndX(), GetEndY());
	}

	T GetLeftEdge() const
	{
		return Min(GetOriginPoint().x, GetEndX());
	}

	T GetTopEdge() const
	{
		return Min(GetOriginPoint().y, GetEndY());
	}

	T GetRightEdge() const
	{
		return Max(GetOriginPoint().x, GetEndX());
	}

	T GetBottomEdge() const
	{
		return Max(GetOriginPoint().y, GetEndY());
	}

	Vec2<T, 1> GetTopLeftPoint() const
	{
		return Vec2<T, 1>(GetLeftEdge(), GetTopEdge());
	}

	Vec2<T, 1> GetBottomRigthPoint() const
	{
		return Vec2<T, 1>(GetRightEdge(), GetBottomEdge());
	}

	T GetWidth() const
	{
		return size.width;
	}

	T GetWidthAbs() const
	{
		return Abs(size.width);
	}

	void SetWidth(T width)
	{
		size.width = width;
	}

	T GetHeight() const
	{
		return size.height;
	}

	T GetHeightAbs() const
	{
		return Abs(size.height);
	}

	void SetHeight(T height)
	{
		size.height = height;
	}

	Bool Contains(const Vec2<T, 1>& point) const
	{
		return GetLeftEdge() <= point.x && point.x < GetRightEdge() && GetTopEdge() <= point.y && point.y < GetBottomEdge();
	}

	Bool Intersects(const DrawRect& rect) const
	{
		return GetLeftEdge() < rect.GetRightEdge() && GetRightEdge() > rect.GetLeftEdge() && GetTopEdge() < rect.GetBottomEdge() && GetBottomEdge() > rect.GetTopEdge();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + position.ToString(formatStatement) + ","_s + Data(size).ToString(formatStatement) + ")"_s;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(DrawRect, position, size);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);
};


template <typename T> struct IsZeroInitialized<DrawRect<T>> : public IsZeroInitialized<T> { };


//----------------------------------------------------------------------------------------
/// DrawRect for Int types.
//----------------------------------------------------------------------------------------
using DrawRectInt = DrawRect<Int>;
MAXON_DATATYPE(DrawRectInt, "net.maxon.image.drawrectint", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

//----------------------------------------------------------------------------------------
/// DrawRect for Float types.
//----------------------------------------------------------------------------------------
using DrawRectFloat = DrawRect<Float>;
MAXON_DATATYPE(DrawRectFloat, "net.maxon.image.drawrectfloat", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

#include "gfx_basictypes1.hxx"
#include "gfx_basictypes2.hxx"

}

#endif // GFX_BASICTYPES_H__
