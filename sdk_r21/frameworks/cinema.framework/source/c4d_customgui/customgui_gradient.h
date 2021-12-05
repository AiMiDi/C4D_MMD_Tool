/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_GRADIENT_H__
#define CUSTOMGUI_GRADIENT_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"
#include "customgui_base.h"

/// Gradient custom GUI ID.
#define CUSTOMGUI_GRADIENT			1000480

/// Gradient custom data ID.
#define CUSTOMDATATYPE_GRADIENT 1000481

/// Plugin ID for the Gradient GUI preset type.\n
/// Can be used to filter a list of presets for the Content Browser.
#define ID_GRADIENTGUI_BROWSERPRESET	1027759

/// @markPrivate
#define ID_GRADIENTGUI_POPUPDIALOG		1027760

/// @addtogroup GRADIENTPROPERTY_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
///< These 2 options are allowed from ::DTYPE_COLOR:\n
///< - ::DR_COLORFIELD_ICC_BASEDOC: Use ICC profile of the current document.
///< - ::DR_COLORFIELD_ICC_BPTEX: Use ICC profile of the current @em BodyPain3D texture.
#define GRADIENTPROPERTY_ALPHA_WITH_COLOR		10000			///< ::Bool If @ref GRADIENTPROPERTY_ALPHA is set to true, this creates a Gradient with Color and Alpha, and shows controls to handle both gradients.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { COLOR; }
																											/// @endcode
#define GRADIENTPROPERTY_ALPHA							10001			///< ::Bool Creates an Alpha gradient.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { ALPHA; }
																											/// @endcode
#define GRADIENTPROPERTY_NOEDITCOLOR				10002			///< ::Bool No color editing.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { NOEDITCOLOR; }
																											/// @endcode
#define GRADIENTPROPERTY_NOPRESETS					10003			///< ::Bool No load/save preset buttons.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { NOPRESETS; }
																											/// @endcode
#define GRADIENTPROPERTY_NOINTERPOLATION		10004			///< ::Bool No Interpolation parameter.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { NOINTERPOLATION; }
																											/// @endcode
#define GRADIENTPROPERTY_NOKNOTPOSITION			10005			///< ::Bool No Knot Position parameter.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { NOKNOTPOSITION; }
																											/// @endcode
#define GRADIENTPROPERTY_NOBIASPOSITION			10006			///< ::Bool No Bias Position parameter.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { NOBIASPOSITION; }
																											/// @endcode
#define GRADIENTPROPERTY_NOBRIGHTNESS				10007			///< ::Bool No Brightness parameter.
																											///< @note The property is used like this in a @em res file:
																											/// @code
																											/// GRADIENT MYGRADIENT { NOBRIGHTNESS; }
																											/// @endcode

/// @}

/// @addtogroup GRADIENT_INTERPOLATION
/// @ingroup group_enumeration
/// @{
/// Gradient interpolation types.
enum
{
	GRADIENT_INTERPOLATION_CUBICKNOT						= 0,			///< Cubic knot.
	GRADIENT_INTERPOLATION_CUBICBIAS						= 1,			///< Cubic Bias.
	GRADIENT_INTERPOLATION_SMOOTHKNOT						= 2,			///< Smooth knot.
	GRADIENT_INTERPOLATION_LINEARKNOT						= 3,			///< Linear knot.
	GRADIENT_INTERPOLATION_NONE									= 5,			///< Step.
	GRADIENT_INTERPOLATION_EXP_UP								= 6,			///< Exponential up (legacy).
	GRADIENT_INTERPOLATION_EXP_DOWN							= 7,			///< Exponential down (legacy).
	GRADIENT_INTERPOLATION_BLEND								= 8				///< Blend.
};
/// @}

/// @addtogroup GRADIENTMODE
/// @ingroup group_enumeration
/// @{
#define GRADIENTMODE_COLOR					0			///< Color only.
#define GRADIENTMODE_ALPHA					1			///< Alpha only.
#define GRADIENTMODE_COLORALPHA			2			///< Color and alpha.
/// @}

/// @addtogroup GRADIENT_CONTAINERIDS
/// @ingroup group_containerid
/// @{
#define GRADIENT_KNOT						1001			///< BaseContainer Holds the gradient knots as sub-containers: @enumerateEnum{GRADIENTKNOT_CONTAINERIDS}
#define GRADIENT_MODE						1002			///< ::Int32 Gradient mode: @enumerateEnum{GRADIENTMODE}
#define GRADIENT_UNCLAMPED			1003			///< ::Bool Unclamped.
/// @}

/// @addtogroup GRADIENTKNOT_CONTAINERIDS
/// @ingroup group_containerid
/// @{
#define GRADIENTKNOT_COLOR					1000			///< ::Vector Color.
#define GRADIENTKNOT_BRIGHTNESS			1001			///< ::Float Brightness.
#define GRADIENTKNOT_POSITION				1002			///< ::Float Position.
#define GRADIENTKNOT_BIAS						1003			///< ::Float Bias.
#define GRADIENTKNOT_ID							1004			///< ::Int32 Index.
#define GRADIENTKNOT_INTERPOLATION	1005			///< ::Int32 Interpolation: @enumerateEnum{GRADIENT_INTERPOLATION}
/// @}

//-------------------------------------------------------------------------------------------------
/// Represents a knot in a @link Gradient gradient@endlink.
//-------------------------------------------------------------------------------------------------
struct GradientKnot
{
	Vector col = Vector(1.0);																	///< Color.
	Float	 brightness = 1.0;																	///< Brightness.
	Float	 pos = 0.0;																					///< Position.
	Float	 bias = 0.5;																				///< Bias.
	Int32	 index = 0;																					///< Index.
	Int32	 interpolation = GRADIENT_INTERPOLATION_SMOOTHKNOT; ///< Interpolation
};

namespace maxon
{

class Gradient;

};

//-------------------------------------------------------------------------------------------------
/// Gradient data type (@ref CUSTOMDATATYPE_GRADIENT) for GradientCustomGui.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class Gradient : public CustomDataType
{
private:
		Gradient();
		~Gradient();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{gradient data}
	/// @return												@allocReturn{gradient data}
	//----------------------------------------------------------------------------------------
	static Gradient *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{gradient data}
	/// @param[in,out] grad						@theToDestruct{gradient data}
	//----------------------------------------------------------------------------------------
	static void Free(Gradient *&grad);

	/// @}

	/// @name Knots
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inverts the knots.
	/// @return												@trueIfOtherwiseFalse{the knots were successfully inverted}
	//----------------------------------------------------------------------------------------
	Bool InvertKnots();

	//----------------------------------------------------------------------------------------
	/// Doubles the knots.
	/// @return												@trueIfOtherwiseFalse{the knots were successfully doubled}
	//----------------------------------------------------------------------------------------
	Bool DoubleKnots();

	//----------------------------------------------------------------------------------------
	/// Distributes the knots evenly.
	/// @return												@trueIfOtherwiseFalse{the knots were successfully distributed}
	//----------------------------------------------------------------------------------------
	Bool DistributeKnots();

	//-------------------------------------------------------------------------------------------------
	/// Flushes all the knots.
	//-------------------------------------------------------------------------------------------------
	void FlushKnots();

	/// @}

	/// @name Render
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the gradient data for render.
	/// @note Call before CalcGradientPixel().
	/// @param[in] irs								A struct with information about the upcoming gradient calculation.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InitRender(const InitRenderStruct &irs);

	//-------------------------------------------------------------------------------------------------
	/// Frees the gradient data from render.
	/// @note Call after gradient calculation is finished.
	//-------------------------------------------------------------------------------------------------
	void FreeRender();

	//----------------------------------------------------------------------------------------
	/// Calculates a gradient pixel.
	/// @param[in] pos								The X position.
	/// @return												The calculated gradient pixel.
	//----------------------------------------------------------------------------------------
	Vector CalcGradientPixel(Float pos) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the knot at @formatParam{index} between InitRender() and FreeRender().
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetRenderKnotCount()
	/// @return												The render knot at @formatParam{index}. @theOwnsPointed{gradient data,knot}
	//----------------------------------------------------------------------------------------
	const GradientKnot *GetRenderKnot(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of knots for GetRenderKnot().
	/// @return												The render knot count.
	//----------------------------------------------------------------------------------------
	Int32 GetRenderKnotCount() const;

	/// @}

	/// @name Knot
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of knots.
	/// @return												The knot count.
	//----------------------------------------------------------------------------------------
	Int32 GetKnotCount() const;

	//----------------------------------------------------------------------------------------
	/// Inserts a knot.
	/// @param[in] knot								The knot to insert.
	/// @return												The index of the inserted knot: GetKnotCount() - @em 1
	//----------------------------------------------------------------------------------------
	Int32 InsertKnot(const GradientKnot &knot);

	//----------------------------------------------------------------------------------------
	/// Removes a knot.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @return												@trueIfOtherwiseFalse{the knot was successfully removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveKnot(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the knot at @formatParam{index}.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @return												The knot.
	//----------------------------------------------------------------------------------------
	GradientKnot GetKnot(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Sets knot at @formatParam{index}.
	/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
	/// @param[in] k									The knot.
	//----------------------------------------------------------------------------------------
	void SetKnot(Int32 index, const GradientKnot &k);

	/// @}

	/// @name Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets data from the gradient container.
	/// @param[in] id									The gradient data ID: @enumerateEnum{GRADIENT_CONTAINERIDS}
	/// @return												The data.
	//----------------------------------------------------------------------------------------
	GeData GetData(Int32 id) const;

	//----------------------------------------------------------------------------------------
	/// Sets data in the gradient container.
	/// @param[in] id									The gradient data ID: @enumerateEnum{GRADIENT_CONTAINERIDS}
	/// @param[in] data								The data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetData(Int32 id, const GeData &data);

	/// @}

	/// @name Alpha
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the alpha gradient.
	/// @return												The alpha gradient. @theOwnsPointed{gradient data,alpha gradient}
	//----------------------------------------------------------------------------------------
	Gradient* GetAlphaGradient();

	//----------------------------------------------------------------------------------------
	/// Allocates an alpha gradient.
	/// @return												The allocated alpha gradient, or @formatConstant{nullptr} if the allocation failed. @theOwnsPointed{gradient data,alpha gradient}
	//----------------------------------------------------------------------------------------
	Gradient* AllocAlphaGradient();

	//----------------------------------------------------------------------------------------
	/// Converts this gradient to an alpha gradient.
	//----------------------------------------------------------------------------------------
	void ConvertToAlphaGradient();

	//----------------------------------------------------------------------------------------
	/// Copies all gradient data from the source gradient.
	/// @since R19
	/// @param[in] src								The source gradient.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(const Gradient *src);

	//----------------------------------------------------------------------------------------
	/// Converts a gradient within a container into an alpha gradient.
	/// @param[in] bc									The container holding the gradient. @callerOwnsPointed{container}
	/// @param[in] id									The ID of the gradient within the container.
	//----------------------------------------------------------------------------------------
	static void ConvertToAlphaGradient(BaseContainer* bc, Int32 id);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a checksum of the whole gradient state, including the knots, colors and interpolation type.
	/// @return												The checksum.
	//----------------------------------------------------------------------------------------
	UInt32 GetChecksum() const;

	//----------------------------------------------------------------------------------------
	/// Gets the internal gradient.
	//----------------------------------------------------------------------------------------
	void GetGradient(maxon::Gradient& gradient) const;

	//----------------------------------------------------------------------------------------
	/// Sets the internal gradient.
	//----------------------------------------------------------------------------------------
	void SetGradient(maxon::Gradient& gradient);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Gradient GUI (@ref CUSTOMGUI_GRADIENT) for the Gradient data type.
/// Here are the settings: @enumerateEnum{GRADIENTPROPERTY_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class GradientCustomGui : public BaseCustomGui<CUSTOMGUI_GRADIENT>
{
private:
	GradientCustomGui();
	~GradientCustomGui();

public:

	/// @name Gradient Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the gradient data.
	/// @return												The gradient data.
	//----------------------------------------------------------------------------------------
	Gradient *GetGradient();

	//----------------------------------------------------------------------------------------
	/// Sets the gradient data.
	/// @warning Unlike SetData() it sends a parent GUI message, causing parent GUI elements (e.g. a shader or dialog that contains the gradient custom GUI) to update automatically.
	/// @note	It is recommended to call SetData() instead, because SetGradient() just sets @formatParam{grad} instance and if there is an alpha gradient, it will be destroyed.\n
	///				With SetData() it needs some more lines of code but alpha gradients will be preserved.
	/// @param[in] grad								The gradient data to set. @callerOwnsPointed{gradient data}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetGradient(Gradient *grad);

	/// @}

	/// @name Active Knots/Biasses
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the active knot or bias control index.
	/// @param[in] bias								Assigned @formatConstant{true} if the returned index is for a bias control, otherwise it is for a knot.
	/// @return												The active knot index.
	//----------------------------------------------------------------------------------------
	Int32 GetActiveKnot(Bool &bias);

	//----------------------------------------------------------------------------------------
	/// Sets the active knot or bias control.
	/// @param[in] index							The knot or bias index to set.
	/// @param[in] bias								Pass @formatConstant{true} to set a bias, otherwise a knot.
	//----------------------------------------------------------------------------------------
	void SetActiveKnot(Int32 index, Bool bias);

	//----------------------------------------------------------------------------------------
	/// Gets the active knots or biassses control indexes.
	/// @param[in] bias								Set to @formatConstant{true} to get the active biasses index, otherwise it will get the active knots indexes.
	/// @return												The active knot index list.
	//----------------------------------------------------------------------------------------
	maxon::Result<maxon::BaseArray<Int32>> GetActiveKnots(Bool bias);

	//----------------------------------------------------------------------------------------
	/// Sets the active knots or biasses controls.
	/// @param[in] activeIndexList		The knots or biasses index list to set.
	/// @param[in] bias								Pass @formatConstant{true} to select biasses, otherwise knots.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SetActiveKnots(const maxon::BaseArray<Int32>& activeIndexList, Bool bias, Bool addToSelection);

	/// @}
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iGradientCustomGui
	{
	};
	class iGradient
	{
	};
#else
	class iGradientCustomGui;
	class iGradient;
#endif

struct CustomGuiGradientLib : public BaseCustomGuiLib
{
	Bool							(iGradient::*InvertKnots)();
	Bool							(iGradient::*DoubleKnots)();
	Bool							(iGradient::*DistributeKnots)();
	void							(iGradient::*FlushKnots)();

	maxon::Result<void> (iGradient::*InitRender)(const InitRenderStruct &irs);
	void							(iGradient::*FreeRender)();
	Vector						(iGradient::*CalcGradientPixel)(Float pos) const;

	Int32							(iGradient::*GetKnotCount)() const;

	Int32							(iGradient::*InsertKnot)(const GradientKnot &knot);
	Bool							(iGradient::*RemoveKnot)(Int32 index);

	GradientKnot			(iGradient::*GetKnot)(Int32 index) const;
	void							(iGradient::*SetKnot)(Int32 index, const GradientKnot &k);

	GeData						(iGradient::*iGetData)(Int32 id) const;
	Bool							(iGradient::*iSetData)(Int32 id, const GeData &data);

	const GradientKnot*	(iGradient::*GetRenderKnot)(Int32 index) const;
	Int32							(iGradient::*GetRenderKnotCount)() const;

	Gradient*					(iGradient::*GetAlphaGradient)();

	Gradient*					(*AllocGradient)();
	void							(*FreeGradient)(Gradient *grad);

	Gradient*					(iGradientCustomGui::*GetGradient)();

	maxon::Result<maxon::BaseArray<Int32>>		(iGradientCustomGui::*GetActiveKnots)(Bool bias);
	maxon::Result<void>												(iGradientCustomGui::*SetActiveKnots)(const maxon::BaseArray<Int32>& activeKnots, Bool bias, Bool addToSelection);

	UInt32						(iGradient::*GetChecksum)() const;

	Gradient*					(iGradient::*AllocAlphaGradient)();
	void							(iGradient::*ConvertToAlphaGradient)();

	Bool							(iGradientCustomGui::*SetGradient)(Gradient *grad);
	Bool							(iGradient::*CopyFrom)(const Gradient *src);
	void							(iGradient::*GetInternalGradient)(maxon::Gradient& gradient) const;
	void							(iGradient::*SetInternalGradient)(maxon::Gradient& gradient);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_GRADIENT_H__
