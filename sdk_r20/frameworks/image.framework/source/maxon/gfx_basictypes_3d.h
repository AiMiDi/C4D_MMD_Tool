#ifndef GFX_BASICTYPES_3D_H__
#define GFX_BASICTYPES_3D_H__

#include "maxon/apibase.h"
#include "maxon/string.h"
#include "maxon/datatype.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// X and Y coordinate of a point used for window/drawing operations.
//----------------------------------------------------------------------------------------
template <typename T> struct DrawPoint3d
{
	T x, y, z;

	DrawPoint3d() : x(T()), y(T()), z(T())
	{
	}

	DrawPoint3d(T xValue, T yValue, T zValue) : x(xValue), y(yValue), z(zValue)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + Data(x).ToString(formatStatement) + ", "_s + Data(y).ToString(formatStatement) + ", "_s + Data(z).ToString(formatStatement) + ")"_s;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(DrawPoint3d, x, y, z);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);
};

//----------------------------------------------------------------------------------------
/// DrawPoint3d for Int types.
//----------------------------------------------------------------------------------------
using DrawPoint3dInt = DrawPoint3d<Int>;
MAXON_DATATYPE(DrawPoint3dInt, "net.maxon.image.drawpoint3dint");

//----------------------------------------------------------------------------------------
/// DrawPoint3d for Float types.
//----------------------------------------------------------------------------------------
using DrawPoint3dFloat = DrawPoint3d<Float>;
MAXON_DATATYPE(DrawPoint3dFloat, "net.maxon.image.drawpoint3dfloat");


//----------------------------------------------------------------------------------------
/// Size of a window/drawing operation.
//----------------------------------------------------------------------------------------
template <typename T> struct DrawDimension3d
{
	T width, height, depth;

	DrawDimension3d() : width(T()), height(T()), depth(T())
	{
	}

	DrawDimension3d(T w, T h, T d) : width(w), height(h), depth(d)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + Data(width).ToString(formatStatement) + ", "_s + Data(height).ToString(formatStatement) + ", "_s + Data(depth).ToString(formatStatement) + ")"_s;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(DrawDimension3d, width, height, depth);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);
};

//----------------------------------------------------------------------------------------
/// DrawDimension3d for Int types.
//----------------------------------------------------------------------------------------
using DrawDimension3dInt = DrawDimension3d<Int>;
MAXON_DATATYPE(DrawDimension3dInt, "net.maxon.image.drawdimension3dint");

//----------------------------------------------------------------------------------------
/// DrawDimension3d for Float types.
//----------------------------------------------------------------------------------------
using DrawDimension3dFloat = DrawDimension3d<Float>;
MAXON_DATATYPE(DrawDimension3dFloat, "net.maxon.image.drawdimension3dfloat");


//----------------------------------------------------------------------------------------
/// Definition of a rectangle used for window/draw operations.
//----------------------------------------------------------------------------------------
template <typename T> struct DrawVolume
{
	DrawPoint3d<T> position;
	DrawDimension3d<T> size;

	DrawVolume()
	{
	}

	DrawVolume(DrawPoint3d<T> positionValue, DrawDimension3d<T> sizeValue) : position(positionValue), size(sizeValue)
	{
	}

	DrawVolume(T x, T y, T z, T w, T h, T d) : position(x, y, z), size(w, h, d)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + position.ToString(formatStatement) + ", "_s + Data(size).ToString(formatStatement) + ")"_s;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(DrawVolume, position, size);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);
};

//----------------------------------------------------------------------------------------
/// DrawVolume for Int types.
//----------------------------------------------------------------------------------------
using DrawVolumeInt = DrawVolume<Int>;
MAXON_DATATYPE(DrawVolumeInt, "net.maxon.image.drawvolumeint");

//----------------------------------------------------------------------------------------
/// DrawVolume for Float types.
//----------------------------------------------------------------------------------------
using DrawVolumeFloat = DrawVolume<Float>;
MAXON_DATATYPE(DrawVolumeFloat, "net.maxon.image.drawvolumefloat");

}

#endif // GFX_BASICTYPES_3D_H__
