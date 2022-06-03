#ifndef SPLINEMAPPER_H__
#define SPLINEMAPPER_H__

#include "maxon/error.h"
#include "maxon/lib_math.h"
#include "maxon/dataserialize.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

class SplineMapper;


/// Gets the ID of a SplineMapperKnot. Usage:
/// @code
/// Int32 id = SPLINEMAPPER_KNOT_GET_ID(point.flags);
/// @endcode
#define SPLINEMAPPER_KNOT_GET_ID(flags) ((Int(flags) >> 16) & 0x0000ffff)

/// Sets the ID of a SplineMapperKnot. Usage:
/// @code
/// SPLINEMAPPER_KNOT_SET_ID(point.flags, id);
/// @endcode
#define SPLINEMAPPER_KNOT_SET_ID(flags, flag_id) (flags = SPLINEMAPPER_KNOT_FLAGS((Int(flags) & 65535) | ((flag_id & 0x0000ffff) << 16)))

/// @addtogroup SPLINEMAPPER_INTERPOLATION_TYPE
/// @ingroup group_enumeration
/// @{
/// Spline Mapper interpolation types.
enum class SPLINEMAPPER_KNOT_INTERPOLATION_TYPE
{
	BEZIER,	///< Bezier (aka Spline) interpolation, uses tangents settings to calculate the interpolation.
	LINEAR,	///< Linear interpolation.
	CUBIC		///< Cubic interpolation.
} MAXON_ENUM_ORDERED_LIST(SPLINEMAPPER_KNOT_INTERPOLATION_TYPE);
/// @}

/// @addtogroup SPLINEMAPPER_KNOT_FLAGS
/// @ingroup group_enumeration
/// @{
/// Spline Mapper Knot settings flags,
enum class SPLINEMAPPER_KNOT_FLAGS : Int
{
	NONE            = 0,
	BREAK_TANGENTS	= (1 << 0),	///< Break knot tangents (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
	LOCK_X					= (1 << 1),	///< Lock knot's X movement.
	LOCK_Y					= (1 << 2),	///< Lock knot's Y movement.
	LOCK_ANGLE			= (1 << 3),	///< Lock knot's tangent angle. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
	LOCK_LENGTH			= (1 << 4),	///< Lock knot's tangent length. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
	KEEPVISUALANGLE	= (1 << 5), ///< Keep visual angle between knot's tangents. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
	SELECTED				= (1 << 6), ///< selected in ui
} MAXON_ENUM_FLAGS(SPLINEMAPPER_KNOT_FLAGS);
/// @}

//-------------------------------------------------------------------------------------------------
/// Represents a generator point in a @link SplineMapper spline@endlink.
//-------------------------------------------------------------------------------------------------
struct SplineMapperKnot
{

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if two knots are equal.
	/// @param[in] k									A spline knot.
	/// @return												@trueIfOtherwiseFalse{the knots are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const SplineMapperKnot& k) const
	{
		return position == k.position && tangentLeft == k.tangentLeft && tangentRight == k.tangentRight && flags == k.flags && interpolation == k.interpolation;
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if two knots are not equal.
	/// @param[in] k									A spline knot.
	/// @return												@trueIfOtherwiseFalse{the knots are not equal}
	//----------------------------------------------------------------------------------------
	Bool operator != (const SplineMapperKnot& k) const
	{
		return !(*this == k);
	}

	HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(position, interpolation, tangentLeft, tangentRight, flags);
	}

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream)
	{
		iferr_scope;
		
		PrepareDescribe(stream, SplineMapperKnot);
		
		Describe("position", position, Vector2d, DESCRIBEFLAGS::NONE) iferr_return;
		Describe("interpolation", interpolation, SPLINEMAPPER_KNOT_INTERPOLATION_TYPE, DESCRIBEFLAGS::NONE) iferr_return;
		Describe("tangentLeft", tangentLeft, Vector2d, DESCRIBEFLAGS::NONE) iferr_return;
		Describe("tangentRight", tangentRight, Vector2d, DESCRIBEFLAGS::NONE) iferr_return;
		Describe("flags", flags, SPLINEMAPPER_KNOT_FLAGS, DESCRIBEFLAGS::NONE) iferr_return;
		
		return OK;
	}
	

	Vector2d position;																																					///< Position. To make sure position of new/modified knots are inside spline range (@see SplineMapper::GetRange(). SplineMapper::SetRange()) , use @ref SplineMapper::ClampPosition().
	SPLINEMAPPER_KNOT_INTERPOLATION_TYPE interpolation = SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER;		///< Interpolation.
	Vector2d tangentLeft;																																				///< Left Tangent. Used only with Bezier interpolation type. Ignored by first point.
	Vector2d tangentRight;																																			///< Right Tangent. Used only with Bezier interpolation type. Ignored by last point.
	SPLINEMAPPER_KNOT_FLAGS flags = SPLINEMAPPER_KNOT_FLAGS::NONE;															///< @note Flag settings for Bezier interpolation. @see SPLINEMAPPER_KNOT_FLAGS. The flags must be accessed using |= and &=. Also contains the point ID. \n
																																															///< The point ID must only be retrieved using the helpers SPLINE_KNOT_GET_ID() and SPLINE_KNOT_SET_ID()
};

MAXON_DATATYPE(SplineMapperKnot, "net.maxon.datatype.splinemapperknot");

/// @addtogroup SPLINEMAPPER_SPLINE_TYPE
/// @ingroup group_enumeration
/// @{
enum class SPLINEMAPPER_SPLINE_TYPE
{
	SOFT,					///< Soft.
	EASEIN,				///< Ease in.
	EASEOUT,			///< Ease out.
	EASEEASE,			///< Ease ease.
	ZERO,					///< Zero angle/length.
	UNIFY					///< Unify.
} MAXON_ENUM_ORDERED_LIST(SPLINEMAPPER_SPLINE_TYPE);
/// @}

/// @addtogroup SPLINEMAPPER_RANGE_STATE
/// @ingroup group_enumeration
/// @{
enum class SPLINEMAPPER_RANGE_STATE
{
	NONE,
	SET,
	UISET
} MAXON_ENUM_ORDERED_LIST(SPLINEMAPPER_RANGE_STATE);
/// @}

/// This is the interface for the SplineMapper data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
class SplineMapperInterface
{

MAXON_INTERFACE_NONVIRTUAL(SplineMapperInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.splinemapper");

public:

	//----------------------------------------------------------------------------------------
	/// Gets a point from its X coordinate. If out of range, the first or last spline knots will be returned.
	/// @note Make sure knots are sorted before calling this (@see SortKnots)
	/// @param[in] positionX					The X coordinate.
	/// @return												The retrieved position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Vector2d GetPoint(Float positionX) const;

	MAXON_METHOD void GetRange(Vector2d& min, Vector2d& max) const;
	MAXON_METHOD void SetRange(const Vector2d& min, const Vector2d& max);
	MAXON_METHOD void AdaptRange(const Vector2d& min, const Vector2d& max);
	MAXON_METHOD Float GetTension() const;
	MAXON_METHOD void SetTension(Float tension);
	MAXON_METHOD Int GetKnotCount() const;
	MAXON_METHOD SplineMapperKnot* GetKnot(Int knotIndex);
	MAXON_METHOD Bool SetKnot(Int knotIndex, const SplineMapperKnot& knot);

	//----------------------------------------------------------------------------------------
	/// Compares this SplineMapper with another if both are identical.
	/// @param[in] other							The other SplineMapper to compare this object with.
	/// @return												True if the object is identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const SplineMapperInterface* other, EQUALITY equality) const;

	//----------------------------------------------------------------------------------------
	/// Returns a hash code for this SplineMapper which depends on the content.
	/// @return												Hash code for the SplineMapper.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD HashInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Inserts a new knot at index position (0 <= position <= GetCount()).
	/// @param[in] knotIndex							Insert index (the internal array size will increase and if (0 <= position < GetCount()), the existing elements are moved, but if (position == GetCount()), then element is appended to the end).
	/// @param[in] knot										The knot to insert
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot);

	MAXON_METHOD Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents);
	MAXON_METHOD Result<void> DeleteKnot(Int knotIndex);
	MAXON_METHOD void DeleteAllKnots();

	//----------------------------------------------------------------------------------------
	/// Gets the internal array for read-only operations.
	/// @return 		Reference to internal array.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<SplineMapperKnot>& GetKnots() const;

	//----------------------------------------------------------------------------------------
	/// Gets the internal array for read/write operations.
	/// @return Pointer to internal array. It's guaranteed to be valid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BaseArray<SplineMapperKnot>* GetKnotsRW();

	//----------------------------------------------------------------------------------------
	/// Sorts the knots by its position X. Call this when an new knot is added or if a knot postion X has been modified.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SortKnots();

	//----------------------------------------------------------------------------------------
	/// Clamps a position to the defined range (@see GetRange(), SetRange()).
	/// @param[in] position 							The position.
	/// @return														The clamped position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Vector2d ClampPosition(const Vector2d& position) const;
	
	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);
};

// include autogenerated headerfile here
#include "splinemapper1.hxx"

// include autogenerated headerfile here
#include "splinemapper2.hxx"


/// @}

} // namespace maxon

#endif	// SPLINEMAPPER_H__
