#ifndef GRADIENT_H__
#define GRADIENT_H__

#include "maxon/error.h"
#include "maxon/lib_math.h"
#include "maxon/hashmap.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

class Gradient;
class GradientRenderData;

/// @addtogroup GRADIENT_INTERPOLATION_TYPE
/// @ingroup group_enumeration
/// @{
/// Gradient interpolation types.
enum class GRADIENT_INTERPOLATION_TYPE
{
	CUBICKNOT		= 0,		///< Cubic knot.
	CUBICBIAS		= 1, 		///< Cubic bias.
	SMOOTHKNOT	= 2,		///< Smooth knot.
	LINEARKNOT	= 3,		///< Linear knot.
	NONE				= 5,		///< Step.
	EXP_UP			= 6,		///< Exponential up (legacy).
	EXP_DOWN		= 7, 		///< Exponential down (legacy).
	BLEND				= 8			///< Blend.
} MAXON_ENUM_ORDERED_LIST(GRADIENT_INTERPOLATION_TYPE);
/// @}

//-------------------------------------------------------------------------------------------------
/// Represents a knot in a @link Gradient gradient@endlink.
//-------------------------------------------------------------------------------------------------
struct GradientKnot
{
	Color		col = Color(1.0);	///< Color.
	Float		brightness = 1.0;		///< Brightness.
	Float		pos = 0.0;					///< Position.
	Float		bias = 0.5;					///< Bias.
	Int32		index = 0;					///< Knot ID in GradientInterface, knot index in GradientRenderDataInterface.
	GRADIENT_INTERPOLATION_TYPE	interpolation = GRADIENT_INTERPOLATION_TYPE::SMOOTHKNOT;
};

inline COMPARERESULT Compare(const GradientKnot& a, const GradientKnot& b)
{
	return LexicographicalCompare(a.col.r, b.col.r, a.col.g, b.col.g, a.col.b, b.col.b, a.brightness, b.brightness, a.pos, b.pos, a.bias, b.bias, a.index, b.index, a.interpolation, b.interpolation);
}

/// This is the interface for the Gradient data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
/// Alpha Gradients ONLY set Brightness, Color is always 1.0
/// Regular Gradients can set Brightness & Color
class GradientInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GradientInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.gradient");

public:
	//----------------------------------------------------------------------------------------
	/// Allocates an alpha gradient.
	/// @return												The alpha gradient.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Gradient*> AllocAlphaGradient();

	//----------------------------------------------------------------------------------------
	/// Returns the internal alpha gradient.
	/// @return												The alpha gradient.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Gradient* GetAlphaGradient();

	/// @name Knots
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of knots.
	/// @return												The knot count.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetKnotCount() const;

	//----------------------------------------------------------------------------------------
	/// Inserts a knot.
	/// @param[in] knot								The knot to insert.
	/// @param[in] keepId							Specifies if the knot ID should be taken from knot or if a new one should be generated.
	/// @return												The index of the inserted knot, GetKnotCount() - @em 1
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> InsertKnot(const GradientKnot &knot, Bool keepId = false);

	//----------------------------------------------------------------------------------------
	/// Removes a knot.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveKnot(Int index);

	//----------------------------------------------------------------------------------------
	/// Gets the knot at @formatParam{index}.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @return												The knot.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GradientKnot GetKnot(Int index) const;

	//----------------------------------------------------------------------------------------
	/// Sets knot at @formatParam{index}.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @param[in] k									The knot.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetKnot(Int index, const GradientKnot &k);

	//----------------------------------------------------------------------------------------
	/// Converts the current gradient to an alpha gradient.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ConvertToAlphaGradient();

	//----------------------------------------------------------------------------------------
	/// Sorts the knots according to their position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SortKnots();

	//----------------------------------------------------------------------------------------
	/// Inverts the knots.
	/// @return												True if any knot inverted, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> InvertKnots();

	//----------------------------------------------------------------------------------------
	/// Doubles the knots.
	/// @return												True if any knot doubled, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> DoubleKnots();

	//----------------------------------------------------------------------------------------
	/// Distributes the knots evenly.
	/// @return												True if any knot distributed, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool DistributeKnots();

	//-------------------------------------------------------------------------------------------------
	/// Flushes all the knots.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void Flush();

	/// @}

	//----------------------------------------------------------------------------------------
	/// Sets the alpha mode.
	/// @param[in] alphaGradient			The gradient alpha type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIsAlphaGradient(Bool alphaGradient);

	//----------------------------------------------------------------------------------------
	/// Checks if this is an alpha gradient.
	/// @return												True, if this is an alpha gradient.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsAlphaGradient() const;

	//----------------------------------------------------------------------------------------
	/// Compares this with another gradient.
	/// @param[in] arg2								The other gradient to compare with.
	/// @return												The comparison result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const GradientInterface* arg2) const;

	//----------------------------------------------------------------------------------------
	/// Gets the hash code for the gradient.
	/// @return												The checksum.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Initializes the gradient for rendering.
	/// @param[in] transformColorDelegate	A delegate to transform the color of a gradient knot.
	/// @return												The render data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GradientRenderData> InitRender(const TransformColorDelegate& transformColorDelegate) const;
};

/// This is the interface for the render data of the Gradient data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
class GradientRenderDataInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GradientRenderDataInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.gradientrenderdata");

public:
	//----------------------------------------------------------------------------------------
	/// Calculates a gradient pixel.
	/// @param[in] pos								The X position.
	/// @return												The calculated gradient pixel.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Color CalcGradientPixel(Float pos) const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of knots for GetRenderKnot().
	/// @return												The render knot count.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetKnotCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the knot at @formatParam{index}.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @return												The render knot at @formatParam{index}. @theOwnsPointed{gradient data,knot}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const GradientKnot* GetKnot(Int index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a read only reference to internal knot list for fast access.
	/// @return												The knot list.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<GradientKnot>& GetKnots() const;

	//----------------------------------------------------------------------------------------
	/// Compares this with another GradientRenderData value.
	/// @param[in] arg2								The other GradientRenderData value to compare with.
	/// @return												The comparison result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const GradientRenderDataInterface* arg2) const;

	//----------------------------------------------------------------------------------------
	/// Gets the checksum of the gradient render data.
	/// @return												The checksum of the gradient render data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;
};

// include autogenerated headerfile here
#include "gradient1.hxx"

// include autogenerated headerfile here
#include "gradient2.hxx"

/// @}

} // namespace maxon

#endif // GRADIENT_H__
