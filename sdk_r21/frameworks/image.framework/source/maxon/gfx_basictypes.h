#ifndef GFX_BASICTYPES_H__
#define GFX_BASICTYPES_H__

#include "maxon/apibase.h"
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
	String ToString(const FormatStatement* formatStatement) const
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
MAXON_DATATYPE(DrawDimensionInt, "net.maxon.image.drawdimensionint");

//----------------------------------------------------------------------------------------
/// DrawDimension for Float types.
//----------------------------------------------------------------------------------------
using DrawDimensionFloat = DrawDimension<Float>;
MAXON_DATATYPE(DrawDimensionFloat, "net.maxon.image.drawdimensionfloat");


//----------------------------------------------------------------------------------------
/// Definition of a rectangle used for window/draw operations.
//----------------------------------------------------------------------------------------
template <typename T> struct DrawRect
{
public:
  DrawRect(Vec2<T,1> positionValue, DrawDimension<T> sizeValue) : position(positionValue), size(sizeValue)
  {
  }

  DrawRect(T x, T y, T w, T h) : position(x, y), size(w, h)
  {
  }

	MAXON_IMPLICIT DrawRect(const Range<Vec2<T, 1>>& src) : position(src.GetMin()), size(src.GetMax() - src.GetMin())
	{
	}

public:
	Vec2<T,1> position;
	DrawDimension<T> size;

	DrawRect()
	{
	}


	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
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
MAXON_DATATYPE(DrawRectInt, "net.maxon.image.drawrectint");

//----------------------------------------------------------------------------------------
/// DrawRect for Float types.
//----------------------------------------------------------------------------------------
using DrawRectFloat = DrawRect<Float>;
MAXON_DATATYPE(DrawRectFloat, "net.maxon.image.drawrectfloat");

}

#endif // GFX_BASICTYPES_H__
