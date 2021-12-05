#ifndef LIB_MATH_H__
#define LIB_MATH_H__

#include "maxon/general_math.h"
#include "maxon/fid.h"

/// @file
/// high-level mathematical functions

namespace maxon
{

/// @addtogroup MATH
/// @{

/// Linear congruential random value generator.
/// The class will always produce the same output if the initialization seed was matching.
template <typename FLOAT> class LinearCongruentialRandom
{
public:
	LinearCongruentialRandom() { Init(100); }

	//----------------------------------------------------------------------------------------
	/// Initialize the random class with a custom seed value. The seed initially is advanced
	/// to avoid clustering close to 0 for typical user-adjusted values.
	/// @param[in] seed								Seed value.
	//----------------------------------------------------------------------------------------
	void Init(UInt32 seed);

	/// Returns the next random value in the range of [0..1].
	FLOAT Get01();

	/// Returns the next random value in the range of [-1..1].
	FLOAT Get11() { return Get01() * FLOAT(2.0) - FLOAT(1.0); }

	/// Returns the next 32-bit random value.
	UInt32 GetUInt32();

	/// Returns the current seed value.
	UInt32 GetSeed() const { return _seed; }

	/// Changes the seed value (@see Init).
	void SetSeed(UInt32 seed) { _seed = seed; }

private:
	UInt32 _seed;
};

/// Pseudo random value generator. Only left in for compatibility.
/// The class will always produce the same output if the initialization seed was matching.
template <typename FLOAT> class PseudoRandom
{
public:
	PseudoRandom() { Init(100); }

	//----------------------------------------------------------------------------------------
	/// Initialize the random class with a custom seed value.
	/// @param[in] seed								Seed value.
	//----------------------------------------------------------------------------------------
	void Init(UInt32 seed);

	/// Returns the next random value in the range of 0..1
	FLOAT Get01();

	/// Returns the next random value in the range of -1..1
	FLOAT Get11() { return Get01() * FLOAT(2.0) - FLOAT(1.0); }

	/// Returns the current seed value.
	/// Note that this is no longer the same value that the class was initialized with
	inline Int32 GetRaw() const { return (Int32)seed; }

private:
	UInt32 seed;
};

#define MATH_VECTOR Vec3<FLOAT>
#define MATH_COLOR Col3<FLOAT>
#define MATH_MATRIX Mat3<Vec3<FLOAT>>
#define MATH_SQUAREMATRIX SqMat3<Vec3<FLOAT>>

/// Calculates a matrix to move / translate.
template <typename FLOAT> MATH_MATRIX GetTranslationMatrix(const MATH_VECTOR& translation);

/// Calculates a matrix to scale.
template <typename FLOAT> MATH_SQUAREMATRIX GetScaleMatrix(const MATH_VECTOR& scale);

/// Calculates a matrix to rotate around the X axis. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixX(FLOAT angle);

/// Calculates a matrix to rotate around the Y axis. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixY(FLOAT angle);

/// Calculates a matrix to rotate around the Z axis. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixZ(FLOAT angle);


#define MATH_VECTOR2 Vec2<FLOAT>
#define MATH_MATRIX2 Mat2<Vec2<FLOAT>>
#define MATH_SQUAREMATRIX2 SqMat2<Vec2<FLOAT>>

/// Calculates a matrix to move / translate.
template <typename FLOAT> MATH_MATRIX2 GetTranslationMatrix(const MATH_VECTOR2& translation);

/// Calculates a matrix to scale.
template <typename FLOAT> MATH_SQUAREMATRIX2 GetScaleMatrix(const MATH_VECTOR2& scale);

/// Calculates a rotation matrix. A positive angle rotates counter-clockwise.
/// Note that the 2d rotation is different from the GetRotationMatrixZ rotation in 3d - the latter one rotates looking onto the axis, thus clockwise if you look from the front.
template <typename FLOAT> MATH_SQUAREMATRIX2 GetRotationMatrix(FLOAT angle);


/// Defines in which order rotations are executed.
/// Global means that the rotation will always be done around the world axes.
/// Local means that the rotation will always be done around an already rotated axis of an axis system.
/// For each global rotation there is a local counterpart and vice versa.
/// All rotations are done so that a positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
enum class ROTATIONORDER
{
	ZXYGLOBAL	=	0,
	ZYXGLOBAL	=	1,
	YXZGLOBAL	=	2,
	YZXGLOBAL	=	3,
	XZYGLOBAL	=	4,
	XYZGLOBAL	=	5,

	YXZLOCAL	= 0,
	XYZLOCAL	= 1,
	ZXYLOCAL	= 2,
	XZYLOCAL	= 3,
	YZXLOCAL	= 4,
	ZYXLOCAL	= 5,
} MAXON_ENUM_LIST(ROTATIONORDER);

//----------------------------------------------------------------------------------------
/// Calculates rotation values of a matrix.
/// @param[in] m									Matrix. The axes do not need to be normalized, but should be perpendicular. The 'offset' component has no influence on the outcome.
/// @param[in] rotationOrder			Rotation order in which the rotations shall be executed.
/// @return												Calculated rotation values, which can be used to re-create the matrix again using GetRotationMatrix. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_VECTOR GetRotationAngles(const MATH_SQUAREMATRIX& m, ROTATIONORDER rotationOrder);

//----------------------------------------------------------------------------------------
/// Calculates a rotation from a given direction vector.
/// @param[in] direction					Direction vector, does not need to be normalized. The direction vector defines the first rotation axis of any (global) rotation order. So, e.g. for ROTATIONORDER::XYZGLOBAL 'direction' defines the +X direction.
/// @param[in] rotationOrder			Rotation order in which the rotations shall be executed.
/// @return												Rotation that can be transformed into a matrix using GetRotationMatrix. The first rotation axis (according to the rotation order) will be parallel to 'direction' (e.g. for ROTATIONORDER::XYZGLOBAL this is the +X axis).
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_VECTOR GetRotationAngles(const MATH_VECTOR& direction, ROTATIONORDER rotationOrder);

//----------------------------------------------------------------------------------------
/// Constructs a rotation matrix from a given rotation. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
/// @param[in] rotation						Rotation value that is interpreted depending on the rotation order.
/// @param[in] rotationOrder			Rotation order in which the rotations shall be executed.
/// @return												A matrix with normalized, perpendicular vectors and offset 0.0.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrix(const MATH_VECTOR& rotation, ROTATIONORDER rotationOrder);

//----------------------------------------------------------------------------------------
/// Constructs a matrix from a given position, scale and rotation. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
/// @param[in] position						Translation value (offset of the resulting matrix).
/// @param[in] scale							Scale value (length of the resulting axes).
/// @param[in] rotation						Rotation value that is interpreted depending on the rotation order.
/// @param[in] rotationOrder			Rotation order in which the rotations shall be executed.
/// @return												A matrix with normalized, perpendicular vectors and offset 0.0.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_MATRIX GetPSRMatrix(const MATH_VECTOR& position, const MATH_VECTOR& scale, const MATH_VECTOR& rotation, ROTATIONORDER rotationOrder);

//----------------------------------------------------------------------------------------
/// Corrects a new rotational value to match an old one as close as possible. This will avoid singularity effects (sudden 'flips' when a rotation jumps from 360 to 0 degrees).
/// @param[in] oldRotation				Last rotation value.
/// @param[in] newRotation				New rotation value that needs to be corrected.
/// @param[in] rotationOrder			Rotation order in which the rotations shall be executed.
/// @return												The rotation value that is closest to oldRotation, but creates the same matrix.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_VECTOR GetOptimumRotation(const MATH_VECTOR& oldRotation, const MATH_VECTOR& newRotation, ROTATIONORDER rotationOrder);

//----------------------------------------------------------------------------------------
/// Calculates the closest point on a line.
/// @param[in] lineOrigin					The starting point of the line.
/// @param[in] lineDirection			The direction vector of the line (does not need to be normalized)
/// @param[in] point							The point.
/// @return												The closest point on the line (with the minimum distance to the given point). If lineDirection was a null vector, the result will be lineOrigin.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_VECTOR GetClosestPointOnLine(const MATH_VECTOR& lineOrigin, const MATH_VECTOR& lineDirection, const MATH_VECTOR& point);

//----------------------------------------------------------------------------------------
/// Calculates the distance of a point and a line.
/// @param[in] lineOrigin					The starting point of the line.
/// @param[in] lineDirection			The direction vector of the line (does not need to be normalized)
/// @param[in] point							The point.
/// @return												The minimum distance of the given line and point. If lineDirection was a null vector, the result will be 0.0.
//----------------------------------------------------------------------------------------
template <typename FLOAT> FLOAT GetPointLineDistance(const MATH_VECTOR& lineOrigin, const MATH_VECTOR& lineDirection, const MATH_VECTOR& point);

//----------------------------------------------------------------------------------------
/// Reflects a ray on a surface.
/// @param[in] direction					The direction of the ray, must be normalized.
/// @param[in] normal							Surface normal, must be normalized.
/// @return												The reflected ray, which is also normalized.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_VECTOR ReflectRay(const MATH_VECTOR& direction, const MATH_VECTOR& normal);

//----------------------------------------------------------------------------------------
/// Converts RGB into HSV color space.
/// @param[in] color							The RGB color (with r/g/b >= 0.0)
/// @return												The HSV (hue, saturation, value) color.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_VECTOR	RGBToHSV(const MATH_COLOR& color);

//----------------------------------------------------------------------------------------
/// Converts HSV into RGB color space.
/// @param[in] color							The HSV (hue, saturation, value) color (with h/s/v >= 0.0)
/// @return												The RGB color.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_COLOR HSVToRGB(const MATH_VECTOR& color);

//----------------------------------------------------------------------------------------
/// Calculates axis and rotation from a matrix. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
/// @param[in] m									Matrix with perpendicular vectors. Its vectors do not need to be normalized.
/// @param[out] axisVector				The calculated axis (normalized vector)
/// @param[out] axisRotation			The calculated rotation. If the matrix was singular a null vector will be returned for axisVector.
//----------------------------------------------------------------------------------------
template <typename FLOAT> void GetRotationAxis(const MATH_SQUAREMATRIX& m, MATH_VECTOR& axisVector, FLOAT& axisRotation);

//----------------------------------------------------------------------------------------
/// Calculates matrix from axis and rotation. A positive angle rotates counter-clockwise (when the rotation axis is facing towards the viewer).
/// @param[in] axisVector					Axis vector, does not need to be normalized.
/// @param[in] axisRotation				The rotation.
/// @return												The calculated matrix (perpendicular & normalized vectors). If the passed axis was a null vector an identity matrix will be returned.
//----------------------------------------------------------------------------------------
template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixFromAxis(const MATH_VECTOR& axisVector, FLOAT axisRotation);

//----------------------------------------------------------------------------------------
/// Returns the sum of all elements.
//----------------------------------------------------------------------------------------
template <typename ITERABLETYPE> MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ITERABLETYPE>::type::ValueType GetSum(ITERABLETYPE&& array)
{
	typename std::remove_reference<ITERABLETYPE>::type::ValueType sum = typename std::remove_reference<ITERABLETYPE>::type::ValueType();
	for (const auto& val : std::forward<ITERABLETYPE>(array))
	{
		sum += val;
	}
	return sum;
}

//----------------------------------------------------------------------------------------
/// Returns the average of all elements.
//----------------------------------------------------------------------------------------
template <typename ITERABLETYPE> MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ITERABLETYPE>::type::ValueType GetAverage(ITERABLETYPE&& array)
{
	Int cnt = 0;
	typename std::remove_reference<ITERABLETYPE>::type::ValueType sum = typename std::remove_reference<ITERABLETYPE>::type::ValueType();
	for (const auto& val : std::forward<ITERABLETYPE>(array))
	{
		sum += val;
		cnt++;
	}
	return cnt ? sum / (Float)cnt : typename std::remove_reference<ITERABLETYPE>::type::ValueType();
}

using TransformColorDelegate32 = Delegate<Color32(const Color32&)>;
using TransformColorDelegate64 = Delegate<Color64(const Color64&)>;
#ifdef MAXON_TARGET_SINGLEPRECISION
using TransformColorDelegate = TransformColorDelegate32;
#else
using TransformColorDelegate = TransformColorDelegate64;
#endif

/// @}

} // namespace maxon

#endif // LIB_MATH_H__
