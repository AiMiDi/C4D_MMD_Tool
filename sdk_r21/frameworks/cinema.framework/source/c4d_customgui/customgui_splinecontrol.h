/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_SPLINECONTROL_H__
#define CUSTOMGUI_SPLINECONTROL_H__

#include "customgui_base.h"
#include "c4d_customdatatype.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

/// Spline GUI ID.
#define CUSTOMGUI_SPLINE					1009059

/// Spline data type ID.
#define CUSTOMDATATYPE_SPLINE			1009060

/// Plugin ID for the Spline GUI preset type.\n
/// Can be used to filter a list of presets for the Content Browser.
#define ID_SPLINEGUI_BROWSERPRESET	1027658

/// @markPrivate
#define ID_SPLINEGUI_POPUPDIALOG		1027659

class SplineCustomGui;

//----------------------------------------------------------------------------------------
/// %User callback set by SplineData::SetUserCallback.
/// @param[in] id									The type of call: @enumerateEnum{SPLINE_CALLBACK}
/// @param[in] d									The callback data. Can be either SplineDataCallbackDraw, SplineDataCallbackCursorInfo or SplineDataCallbackCoreMessage depending on the callback call @formatParam{id}.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*SplineDataCallback)(Int32 id, const void* d);

/// @addtogroup SPLINE_CALLBACK
/// @ingroup group_enumeration
/// @{
/// Spline callback IDs.
/// @see SplineData::SetUserCallback()
#define SPLINE_CALLBACK_DRAW					0			///< Called when the spline GUI is drawn. The corresponding data is SplineDataCallbackDraw.
#define SPLINE_CALLBACK_CURSORINFO		1			///< Called to display cursor information. The corresponding data is SplineDataCallbackCursorInfo.
#define SPLINE_CALLBACK_CORE_MESSAGE	2			///< Called when core messages are sent. The corresponding data is SplineDataCallbackCoreMessage.
/// @}

#ifndef _INTERNAL_DEF_
#define IDC_SPLINE_PRESET_POPUPMENU		1023				///< Command ID for the Spline GUI Preset popup menu.
																									///< @see SplineCustomGui::Command()
/// @addtogroup IDC_SPLINE
/// @ingroup group_enumeration
/// @{
/// @see SplineCustomGui::Command()
#define IDC_SPLINE_FRAME_ALL					900016			///< Command container value for the Spline GUI Frame All menu.
#define IDC_SPLINE_FRAME_SEL					900017			///< Command container value for the Spline GUI Frame Sel menu.
#define IDC_SPLINE_FRAME_MINMAX				900023			///< Command container value for the Spline GUI Frame Min/Max menu.
/// @}
#endif

//----------------------------------------------------------------------------------------
/// Callback struct for the @ref SPLINE_CALLBACK_DRAW call.
//----------------------------------------------------------------------------------------
struct SplineDataCallbackDraw
{
	void* pCallbackData;						///< %User data passed to SplineData::SetUserCallback
	SplineCustomGui* pGUI;					///< Custom GUI of the spline data.
	GeUserArea* pUserArea;					///< Custom GUI's user area.
	const BaseContainer* pObjects;	///< Array of links that hold the objects.
	const DescID* pDescID;					///< Description ID of the spline GUI.
	const BaseContainer* pDrawMsg;	///< Container that was originally passed to the user area's @link GeUserArea::DrawMsg DrawMsg()@endlink
	GeClipMap* pClipmap;						///< Clipmap that can be drawn into.
};

//----------------------------------------------------------------------------------------
/// Callback struct for the @ref SPLINE_CALLBACK_CURSORINFO call.
//----------------------------------------------------------------------------------------
struct SplineDataCallbackCursorInfo
{
	void* pCallbackData;						///< %User data passed to SplineData::SetUserCallback
	SplineCustomGui* pGUI;					///< Custom GUI of the spline data.
	GeUserArea* pUserArea;					///< Custom GUI's user area.
	const BaseContainer* pObjects;	///< Array of links that hold the objects.
	const DescID* pDescID;					///< Description ID of the spline GUI.
	Int32 x,												///< X position of the cursor in local space.
				y;												///< Y position of the cursor in local space.
};

//----------------------------------------------------------------------------------------
/// Callback struct for the @ref SPLINE_CALLBACK_CORE_MESSAGE call.
//----------------------------------------------------------------------------------------
struct SplineDataCallbackCoreMessage
{
	void* pCallbackData;						///< %User data passed to SplineData::SetUserCallback
	SplineCustomGui* pGUI;					///< Custom GUI of the spline data.
	GeUserArea* pUserArea;					///< Custom GUI's user area.
	const BaseContainer* pObjects;	///< Array of links that hold the objects.
	const DescID* pDescID;					///< Description ID of the spline GUI.
	Int32 lID;											///< Core message's ID.
	const BaseContainer* pMessage;	///< Core message's container.
};

/// @addtogroup SplineCustomGuiSettings
/// @ingroup group_containerid
/// @{
/// SplineCustomGui settings.
enum
{
	SPLINECONTROL_GRID_H					= 10000,		///< Show horizontal grid.
	SPLINECONTROL_GRID_V,											///< Show vertical grid.
	SPLINECONTROL_VALUE_EDIT_H,								///< Show edit field for horizontal value.
	SPLINECONTROL_VALUE_EDIT_V,								///< Show edit field for vertical value.
	SPLINECONTROL_VALUE_LABELS_H_LEGACY,			///< Deprecated.
	SPLINECONTROL_VALUE_LABELS_V_LEGACY,			///< Deprecated.
	SPLINECONTROL_X_MIN,											///< Minimum X value.
	SPLINECONTROL_X_MAX,											///< Maximum X value.
	SPLINECONTROL_X_STEPS,										///< X step for edit field.
	SPLINECONTROL_Y_MIN,											///< Minimum Y value.
	SPLINECONTROL_Y_MAX,											///< Maximum Y value.
	SPLINECONTROL_Y_STEPS,										///< Y step for edit field.
	SPLINECONTROL_PRESET_BTN_LEGACY,					///< Deprecated.
	SPLINECONTROL_ROUND_SLIDER_LEGACY,				///< Deprecated.
	SPLINECONTROL_GRIDLINES_H_LEGACY,					///< Deprecated.
	SPLINECONTROL_GRIDLINES_V_LEGACY,					///< Deprecated.
	SPLINECONTROL_MINSIZE_H,									///< Minimum horizontal size.
	SPLINECONTROL_MINSIZE_V,									///< Minimum vertical size.
	SPLINECONTROL_X_MIN_TEXT_LEGACY,					///< Deprecated.
	SPLINECONTROL_X_MAX_TEXT_LEGACY,					///< Deprecated.
	SPLINECONTROL_Y_MIN_TEXT_LEGACY,					///< Deprecated.
	SPLINECONTROL_Y_MAX_TEXT_LEGACY,					///< Deprecated.
	SPLINECONTROL_X_TEXT,											///< X text.
	SPLINECONTROL_Y_TEXT,											///< Y text.

	SPLINECONTROL_NEW_NO_HORIZ_LEGACY,				///< Deprecated.
	SPLINECONTROL_NEW_NO_VERT_LEGACY,					///< Deprecated.
	SPLINECONTROL_HIDE_GRID_H_LEGACY,					///< Deprecated.
	SPLINECONTROL_HIDE_GRID_V_LEGACY,					///< Deprecated.
	SPLINECONTROL_HIDE_PRESET_BTN_LEGACY,			///< Deprecated.
	SPLINECONTROL_HIDE_ROUND_SLIDER_LEGACY,		///< Deprecated.
	SPLINECONTROL_HIDE_VALUE_EDIT_H_LEGACY,		///< Deprecated.
	SPLINECONTROL_HIDE_VALUE_EDIT_V_LEGACY,		///< Deprecated.
	SPLINECONTROL_HIDE_VALUE_LABELS_H_LEGACY,	///< Deprecated.
	SPLINECONTROL_HIDE_VALUE_LABELS_V_LEGACY,	///< Deprecated.

	SPLINECONTROL_ALLOW_HORIZ_SCALE_MOVE,			///< Allow horizontal scale and move.
	SPLINECONTROL_ALLOW_VERT_SCALE_MOVE,			///< Allow vertical scale and move.

	SPLINECONTROL_OPTIMAL,										///< Use optimal area.
	SPLINECONTROL_OPTIMAL_X_MIN,							///< Optimal X minimum.
	SPLINECONTROL_OPTIMAL_Y_MIN,							///< Optimal Y minimum.
	SPLINECONTROL_OPTIMAL_X_MAX,							///< Optimal X maximum.
	SPLINECONTROL_OPTIMAL_Y_MAX,							///< Optimal Y maximum.

	SPLINECONTROL_SQUARE,											///< Area is square.

	SPLINECONTROL_CUSTOMCOLOR_SET,						///< The custom color specified in @ref SPLINECONTROL_CUSTOMCOLOR_COL is used for the curves.
	SPLINECONTROL_CUSTOMCOLOR_COL,						///< The custom color.

	SPLINECONTROL_NO_FLOATING_WINDOW,					///< No entry in the popup menu to open the spline in a floating window.
	SPLINECONTROL_NO_PRESETS,									///< No load/save preset buttons.
	///< @note The property is set like this in a @em res file:\n
	/// @code
	/// SPLINE MYSPLINE { NOPRESETS; }
	/// @endcode
	_SPLINECONTROL_DUMMY_
};
/// @}

/// @addtogroup FLAG_KNOT
/// @ingroup group_enumeration
/// @{
#define FLAG_KNOT_T_BREAK								(1 << 4)		///< Break knot tangents.
#define FLAG_KNOT_LOCK_X								(1 << 5)		///< Lock knot's X movement.
#define FLAG_KNOT_LOCK_Y								(1 << 6)		///< Lock knot's Y movement.
#define FLAG_KNOT_T_LOCK_A							(1 << 7)		///< Lock knot's tangent angle.
#define FLAG_KNOT_T_LOCK_L							(1 << 8)		///< Lock knot's tangent length.
#define FLAG_KNOT_T_KEEPVISUALANGLE			(1 << 9)		///< Keep visual angle between knot's tangents.
#define ADD_KNOT_ADAPT_TANGENTS					(1 << 16)		///< Tangents of new knots are set in such a way that the resulting spline will match the curvature of the original spline.
/// @}

/// Gets the ID of a CustomSplineKnot. Usage:
/// @code
/// Int32 id = SPLINE_KNOT_GET_ID(knot.lFlags);
/// @endcode
#define SPLINE_KNOT_GET_ID(flags) ((flags >> 16) & 0x0000ffff)

/// Sets the ID of a CustomSplineKnot. Usage:
/// @code
/// SPLINE_KNOT_SET_ID(knot.lFlags, id);
/// @endcode
#define SPLINE_KNOT_SET_ID(flags, flag_id) (flags = (flags & 65535) | ((flag_id & 0x0000ffff) << 16))

/// @addtogroup CustomSplineKnotInterpolation
/// @ingroup group_enumeration
/// @{
/// Spline knot interpolation types.
enum CustomSplineKnotInterpolation
{
	CustomSplineKnotInterpolationBezier,	///< Bezier interpolation.
	CustomSplineKnotInterpolationLinear,	///< Linear interpolation.
	CustomSplineKnotInterpolationCubic		///< Cubic interpolation.
};
/// @}

//----------------------------------------------------------------------------------------
/// Represents a knot in a @link SplineData spline@endlink.
//----------------------------------------------------------------------------------------
struct CustomSplineKnot
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	CustomSplineKnot()
	{
		bSelect = false;
		interpol = CustomSplineKnotInterpolationBezier;
	}

	Vector vPos;															///< Knot position.
	Int32 lFlagsSettings;											///< Knot flags: @enumerateEnum{FLAG_KNOT}\n
																						///< @note	The flags must be accessed using |= and &=. Also contains the point ID. \n
																						///<				The knot ID must only be retrieved using the helpers SPLINE_KNOT_GET_ID() and SPLINE_KNOT_SET_ID().
	Bool bSelect;															///< Internal select state. Do not change this.
	Vector vTangentLeft,											///< Left tangent.
				vTangentRight;											///< Right tangent.
	CustomSplineKnotInterpolation interpol;		///< Spline knot's interpolation: @enumerateEnum{CustomSplineKnotInterpolation}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if two knots are equal.
	/// @param[in] k									A spline knot.
	/// @return												@trueIfOtherwiseFalse{the knots are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (CustomSplineKnot& k);

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if two knots are not equal.
	/// @param[in] k									A spline knot.
	/// @return												@trueIfOtherwiseFalse{the knots are not equal}
	//----------------------------------------------------------------------------------------
	Bool operator != (CustomSplineKnot& k);

	/// @}
};

/// @addtogroup SPLINE_TYPE
/// @ingroup group_enumeration
/// @{
enum
{
	SPLINE_TYPE_SOFT = 0,			///< Soft.
	SPLINE_TYPE_EASEIN,				///< Ease in.
	SPLINE_TYPE_EASEOUT,			///< Ease out.
	SPLINE_TYPE_EASEEASE,			///< Ease ease.
	SPLINE_TYPE_ZERO,					///< Zero angle/length.
	SPLINE_TYPE_UNIFY					///< Unify.
};
/// @}


//-------------------------------------------------------------------------------------------------
/// Spline data type (@ref CUSTOMDATATYPE_SPLINE) for SplineCustomGui.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class SplineData : public CustomDataType
{
private:
	SplineData();
	~SplineData();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{spline data}
	/// @return												@allocReturn{spline data}
	//----------------------------------------------------------------------------------------
	static SplineData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{spline data}
	/// @param[in,out] pData					@theToDestruct{spline data}
	//----------------------------------------------------------------------------------------
	static void Free(SplineData *&pData);

	/// @}

	/// @name Knot
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of knots .
	/// @return												The knot count.
	//----------------------------------------------------------------------------------------
	Int32 GetKnotCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets the spline knot at position @formatParam{l}.
	/// @param[in] l									The position index. @em 0 <= @formatParam{l} < GetKnotCount()
	/// @return												The spline knot.
	//----------------------------------------------------------------------------------------
	CustomSplineKnot* GetKnot(Int32 l);

	//----------------------------------------------------------------------------------------
	/// Sets the spline knot at position @formatParam{l}.
	/// @param[in] l									The knot index. @em 0 <= @formatParam{l} < GetKnotCount()
	/// @param[in] knot								The spline knot.
	/// @return												@trueIfOtherwiseFalse{the spline knot was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetKnot(Int32 l, const CustomSplineKnot& knot);

	//----------------------------------------------------------------------------------------
	/// Inserts a knot.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[in] lFlags							The knot flags: @enumerateEnum{FLAG_KNOT}
	/// @return												The index of the inserted knot.
	//----------------------------------------------------------------------------------------
	Int32 InsertKnot(Float x, Float y, Int32 lFlags = 0);

	//----------------------------------------------------------------------------------------
	/// Deletes a knot.
	/// @param[in] a									The index of the knot to delete. @em 0 <= @formatParam{a} < GetKnotCount()
	/// @return												@trueIfOtherwiseFalse{the knot was deleted successfully}
	//----------------------------------------------------------------------------------------
	Bool DeleteKnot(Int32 a);

	//----------------------------------------------------------------------------------------
	/// Sorts the knots.
	/// @param[out] lActiveKnot				Assigned the new index of the active knot.
	//----------------------------------------------------------------------------------------
	void SortKnots(Int32 &lActiveKnot);

	//----------------------------------------------------------------------------------------
	/// Gets the number of selected knots.
	/// @return												The selected knot count.
	//----------------------------------------------------------------------------------------
	Int32 GetSelectCount() const;

	/// @}

	/// @name Point
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a point from its X coordinate.
	/// @param[in] r									The X coordinate.
	/// @return												The retrieved point.
	//----------------------------------------------------------------------------------------
	Vector GetPoint(Float r) const;

	//----------------------------------------------------------------------------------------
	/// Deletes all points.
	//----------------------------------------------------------------------------------------
	void DeleteAllPoints();

	/// @}

	/// @name Make Spline
	/// @{

	//----------------------------------------------------------------------------------------
	/// Makes an uninitialized spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakePointBuffer(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a linear spline with @formatParam{lPoints} points. The spline knots' is linear.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeLinearSplineLinear(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a linear spline with @formatParam{lPoints} points. The spline knots' interpolation is Bezier.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeLinearSplineBezier(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a square spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeSquareSpline(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a cubic spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeCubicSpline(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a root spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeRootSpline(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes an inverse spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeInversSpline(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a sinus spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeSinSpline(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes an absolute cosine spline with @formatParam{lPoints} points.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeAbsCosSpline(Int32 lPoints = -1);

	//----------------------------------------------------------------------------------------
	/// Makes a user spline from @formatParam{str} with @formatParam{lPoints} number of points.
	/// @param[in] str								The user spline string. Any valid formula can be used.
	/// @param[in] lPoints						The number of points, or @em -1 to get the default value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MakeUserSpline(const maxon::String &str, Int32 lPoints = -1);

	/// @}

	/// @name Spline Knots Manipulation
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Selects all points.
	//-------------------------------------------------------------------------------------------------
	void SelectAll();

	//-------------------------------------------------------------------------------------------------
	/// Flips the spline.
	//-------------------------------------------------------------------------------------------------
	void Flip();

	//-------------------------------------------------------------------------------------------------
	/// Mirrors the spline.
	//-------------------------------------------------------------------------------------------------
	void Mirror();

	//-------------------------------------------------------------------------------------------------
	/// Makes all Y coordinates greater than or equal to @em 0.
	//-------------------------------------------------------------------------------------------------
	void Minimum();

	//-------------------------------------------------------------------------------------------------
	/// Makes all Y coordinates less than or equal to @em 1.
	//-------------------------------------------------------------------------------------------------
	void Maximum();

	/// @}

	/// @name Set Type/Zero
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the interpolation type of the selected knots.
	/// @param[in] id									The interpolation type: @enumerateEnum{SPLINE_TYPE}
	/// @param[in] bAll								Pass @formatConstant{true} to set all knots, @formatConstant{false} to set selected knots only.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetType(Int32 id, Bool bAll = false);

	//----------------------------------------------------------------------------------------
	/// Sets the tangents of the selected knots to zero.
	/// @param[in] bY									Pass @formatConstant{true} to set the tangents' Y coordinate to zero, @formatConstant{false} to set the X coordinate.
	/// @param[in] bAll								Pass @formatConstant{true} to set all tangents, @formatConstant{false} to set the tangents of selected knots only.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetZero(Bool bY, Bool bAll = false);

	/// @}

	/// @name Range
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the range of the spline.
	/// @warning Only valid if the spline is shown in the spline GUI.
	/// @param[out] xmin							Assigned the minimum X value.
	/// @param[out] xmax							Assigned the maximum X value.
	/// @param[out] xsteps						Assigned the X steps value.
	/// @param[out] ymin							Assigned the minimum Y value.
	/// @param[out] ymax							Assigned the maximum Y value.
	/// @param[out] ysteps						Assigned the Y steps value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetRange(Float* xmin, Float* xmax, Float* xsteps, Float* ymin, Float* ymax, Float* ysteps) const;

	//----------------------------------------------------------------------------------------
	/// Sets the range of the spline.
	/// @warning Only valid if the spline is shown in the spline GUI.
	/// @param[in] xmin								The minimum X value.
	/// @param[in] xmax								The maximum X value.
	/// @param[in] xsteps							The X steps value.
	/// @param[in] ymin								The minimum Y value.
	/// @param[in] ymax								The maximum Y value.
	/// @param[in] ysteps							The Y steps value.
	//----------------------------------------------------------------------------------------
	void SetRange(Float xmin, Float xmax, Float xsteps, Float ymin, Float ymax, Float ysteps);

	//----------------------------------------------------------------------------------------
	/// Adapts the internal [@em 0, @em 1] range of the old spline GUI to the range set by [@formatParam{xmin}, @formatParam{xmax}, @formatParam{ymin}, @formatParam{ymax}].
	/// @warning Only valid if the spline is shown in the spline GUI.
	/// @param[in] xmin								The minimum X value.
	/// @param[in] xmax								The maximum X value.
	/// @param[in] xsteps							The X steps value.
	/// @param[in] ymin								The minimum Y value.
	/// @param[in] ymax								The maximum Y value.
	/// @param[in] ysteps							The Y steps value.
	//----------------------------------------------------------------------------------------
	void AdaptRange(Float xmin, Float xmax, Float xsteps, Float ymin, Float ymax, Float ysteps);

	/// @}

	/// @name Tension
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the tension value.
	/// @return												The tension value.
	//----------------------------------------------------------------------------------------
	Float GetTension() const;

	//----------------------------------------------------------------------------------------
	/// Sets the tension value. Effective range goes from 0.0 (no tension - softer splines) to 1.0 (full tension - harder splines)
	/// @param[in] tension						The new tension value.
	//----------------------------------------------------------------------------------------
	void SetTension(Float tension);

	/// @}

	/// @name User Callback
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the user callback function pointer.
	/// @param[out] pData							Assigned the user data of the callback.
	/// @return												The user callback.
	//----------------------------------------------------------------------------------------
	SplineDataCallback GetUserCallback(void *&pData) const;

	//----------------------------------------------------------------------------------------
	/// Sets the user callback function.
	/// @param[in] fn									The pointer to the callback function.
	/// @param[in] pData							The user data passed to the callback function.
	//----------------------------------------------------------------------------------------
	void SetUserCallback(SplineDataCallback fn, void* pData);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies this spline dat values into the destination spline data @formatParam{pDest}.
	/// @param[in] pDest							The destination spline data. @callerOwnsPointed{spline data}
	/// @return												@trueIfOtherwiseFalse{this spline data was successfully copied to @formatParam{pDest}}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(SplineData* pDest);

	//----------------------------------------------------------------------------------------
	/// Initializes the knot flag for selected knots.
	/// @param[in] flag								A combination of these flags: @enumerateEnum{FLAG_KNOT}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitDefaultFlag(Int32 flag);

	//BaseBitmap* GetBackgroundImage();
	//Bool SetBackgoundImage(BaseBitmap* pBmp);

	/// @}
};

/// @see SplineCustomGui::SetMessageFunctions to register the spline control message callback.
class SplineControlMessages
{
public:
	//----------------------------------------------------------------------------------------
	/// Called when a knot was moved.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	//----------------------------------------------------------------------------------------
	virtual void KnotMoved(Float x, Float y) { }

	//----------------------------------------------------------------------------------------
	/// Called when a knot was inserted.
	/// @param[in] lKnot							The knot index.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	//----------------------------------------------------------------------------------------
	virtual void KnotInserted(Int32 lKnot, Float x, Float y) { }

	//----------------------------------------------------------------------------------------
	/// Called when a knot's left tangent was moved.
	/// @param[in] x									The tangent's X coordinate.
	/// @param[in] y									The tangent's Y coordinate.
	//----------------------------------------------------------------------------------------
	virtual void LeftTangentMoved(Float x, Float y) { }

	//----------------------------------------------------------------------------------------
	/// Called when a knot's right tangent was moved.
	/// @param[in] x									The tangent's X coordinate.
	/// @param[in] y									The tangent's Y coordinate.
	//----------------------------------------------------------------------------------------
	virtual void RightTangentMoved(Float x, Float y) { }
};

//----------------------------------------------------------------------------------------
/// Spline GUI (@ref CUSTOMGUI_SPLINE) for SplineData.\n
/// Here are the settings: @enumerateEnum{SplineCustomGuiSettings}
//----------------------------------------------------------------------------------------
class SplineCustomGui : public BaseCustomGui<CUSTOMGUI_SPLINE>
{
	SplineCustomGui();
	~SplineCustomGui();

public:
	//----------------------------------------------------------------------------------------
	/// Registers a set of message functions.
	/// @param[in] pFuncs							The message functions.
	//----------------------------------------------------------------------------------------
	void SetMessageFunctions(SplineControlMessages* pFuncs);

	//----------------------------------------------------------------------------------------
	/// Gets the spline data.
	/// @return												The spline data. @theOwnsPointed{spline GUI, data}
	//----------------------------------------------------------------------------------------
	SplineData* GetSplineData(void);

	//----------------------------------------------------------------------------------------
	/// Sets the spline data.
	/// @param[in] pData							The spline data to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetSpline(SplineData* pData);

	//----------------------------------------------------------------------------------------
	/// Sets the label text.
	/// @param[in] strXMin						The minimum X value text to set, or @formatConstant{nullptr} (default).
	/// @param[in] strXMax						The maximum X value text to set, or @formatConstant{nullptr} (default).
	/// @param[in] strYMin						The minimum Y value text to set, or @formatConstant{nullptr} (default).
	/// @param[in] strYMax						The maximum Y value text to set, or @formatConstant{nullptr} (default).
	/// @param[in] strX								The new X text, or @formatConstant{nullptr} (default).
	/// @param[in] strY								The new Y text, or @formatConstant{nullptr} (default).
	//----------------------------------------------------------------------------------------
	void SetLabelText(maxon::String* strXMin = nullptr, maxon::String* strXMax = nullptr, maxon::String* strYMin = nullptr, maxon::String* strYMax = nullptr, maxon::String* strX = nullptr, maxon::String* strY = nullptr);

	//----------------------------------------------------------------------------------------
	/// Sets the custom color for the curve.
	/// @param[in] bSet								Pass @formatConstant{true} if a custom color should be used.
	/// @param[in] col								The custom color.
	//----------------------------------------------------------------------------------------
	void SetCustomColor(Bool bSet = false, Vector col = Vector(0.0, 0.0, 0.0));

	//----------------------------------------------------------------------------------------
	/// Gets the screen position for a spline value.
	/// @param[in] v									The spline value.
	/// @param[out] x									Assigned the screen X position.
	/// @param[out] y									Assigned the screen Y position.
	//----------------------------------------------------------------------------------------
	void GetScreenPosition(const Vector &v, Int32 &x, Int32 &y) const;

	//----------------------------------------------------------------------------------------
	/// Gets the spline value for a screen position.
	/// @param[in] x									The screen X position.
	/// @param[in] y									The screen Y position.
	/// @param[out] v									Assigned the spline value.
	//----------------------------------------------------------------------------------------
	void GetValue(const Int32 x, const Int32 y, Vector &v) const;

	//----------------------------------------------------------------------------------------
	/// Triggers internal spline GUI commands.
	/// @b Example:
	/// @code
	/// // Prepare the command message container
	/// // We will make the SplineCustomGui frame the selected points
	/// BaseContainer splineMsg;
	/// splineMsg.SetInt32(0, IDC_SPLINE_FRAME_SEL);
	///
	/// // Get pointer to the SplineCustomGui
	/// SplineCustomGui* pGui = (SplineCustomGui*)FindCustomGui(MYSPLINE, CUSTOMDATATYPE_SPLINE);
	///
	/// // Talk the SplineCustomGui into performing a command from its popup menu
	/// if (pGui)
	/// 	pGui->Command(IDC_SPLINE_PRESET_POPUPMENU, splineMsg);
	/// @endcode
	/// @param[in] id									The command ID: @ref IDC_SPLINE_PRESET_POPUPMENU.
	/// @param[in] msg								The command message container: @enumerateEnum{IDC_SPLINE}
	/// @return												@trueIfOtherwiseFalse{the command was successfully sent}
	//----------------------------------------------------------------------------------------
	Bool Command(Int32 id, const BaseContainer &msg);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class SplineControlMessagesF
{
public:
	// Spline control version 0
	void KnotMoved(SplineControlMessages* pFuncs, Float x, Float y);
	void KnotInserted(SplineControlMessages* pFuncs, Int32 l, Float x, Float y);
	// Spline control version 1
	void LeftTangentMoved(SplineControlMessages* pFuncs, Float x, Float y);
	void RightTangentMoved(SplineControlMessages* pFuncs, Float x, Float y);
};

struct SplineControlFunctionTable
{
	// Spline control version 0
	void (SplineControlMessagesF::*KnotMoved)(SplineControlMessages* pFuncs, Float x, Float y);
	void (SplineControlMessagesF::*KnotInserted)(SplineControlMessages* pFuncs, Int32 l, Float x, Float y);

	// Spline control version 1
	void (SplineControlMessagesF::*LeftTangentMoved)(SplineControlMessages* pFuncs, Float x, Float y);
	void (SplineControlMessagesF::*RightTangentMoved)(SplineControlMessages* pFuncs, Float x, Float y);

	void* dummy[(15 - 4) * C4DPL_MEMBERMULTIPLIER];
};

#ifndef _INTERNAL_DEF_
	class iSplineCustomGui
	{
	};
	class iSpline
	{
	};
#else
	class iSplineCustomGui;
	class iSpline;
#endif

struct CustomGuiSplineLib : public BaseCustomGuiLib
{
	Int32								(iSpline::*GetKnotCount)() const;
	CustomSplineKnot*		(iSpline::*GetKnot)(Int32 l);

	Vector							(iSpline::*GetPoint)(Float r) const;
	Vector							(iSpline::*GetPointFromX)(Float r, Int32 lMaxIter, Float rMaxEps) const;

	void								(iSpline::*DeleteAllPoints)();
	Bool								(iSpline::*MakePointBuffer)(Int32 lPoints);

	Bool								(iSpline::*MakeLinearSplineBezier)(Int32 lPoints);
	Bool								(iSpline::*MakeSquareSpline)(Int32 lPoints);
	Bool								(iSpline::*MakeCubicSpline)(Int32 lPoints);
	Bool								(iSpline::*MakeRootSpline)(Int32 lPoints);
	Bool								(iSpline::*MakeInversSpline)(Int32 lPoints);
	Bool								(iSpline::*MakeSinSpline)(Int32 lPoints);
	Bool								(iSpline::*MakeAbsCosSpline)(Int32 lPoints);

	void								(iSpline::*Flip)();
	void								(iSpline::*Mirror)();
	void								(iSpline::*Maximum)();
	void								(iSpline::*Minimum)();

	void								(iSpline::*SetRoundEx)(Float r);
	Float								(iSpline::*GetRoundEx)() const;
	void								(iSpline::*SortKnots)(Int32 &lActiveKnot);

	Int32								(iSpline::*InsertKnot)(Float x, Float y, Int32 lFlags);
	Bool								(iSpline::*DeleteKnot)(Int32 a);
	Int32								(iSpline::*GetSelectCount)() const;

	void								(iSplineCustomGui::*SetMessageFunctions)(SplineControlFunctionTable* f, Int32 lSize, SplineControlMessagesF *pControl, SplineControlMessages* pFunctions);
	SplineData*					(iSplineCustomGui::*GetSplineData)(void);
	Bool								(iSplineCustomGui::*SetSpline)(SplineData* pData);
	void								(iSplineCustomGui::*SetLabelText)(maxon::String* strXMin, maxon::String* strXMax, maxon::String* strYMin, maxon::String* strYMax, maxon::String* strX, maxon::String* strY);

	Bool								(iSpline::*GetRange)(Float* xmin, Float* xmax, Float* xsteps, Float* ymin, Float* ymax, Float* ysteps) const;
	void								(iSpline::*SetRange)(Float xmin, Float xmax, Float xsteps, Float ymin, Float ymax, Float ysteps);

	SplineData*					(*Spline_Alloc)();
	void								(*Spline_Free)(SplineData *&pData);
	void								(iSpline::*SelectAll)();
	Bool								(iSpline::*MakeUserSpline)(const maxon::String &str, Int32 lPoints);
//BaseBitmap*					(iSpline::*GetBackgroundImage)() const;
//Bool								(iSpline::*SetBackgoundImage)(BaseBitmap* pBmp);
	Bool								(iSpline::*SetZero)(Bool bY, Bool bAll);
	Bool								(iSpline::*SetType)(Int32 id, Bool bAll);
	Bool								(iSpline::*MakeLinearSplineLinear)(Int32 lPoints);
	void								(iSpline::*AdaptRange)(Float xmin, Float xmax, Float xsteps, Float ymin, Float ymax, Float ysteps);

	void								(iSpline::*SetUserCallback)(SplineDataCallback fn, void* pData);
	SplineDataCallback	(iSpline::*GetUserCallback)(void *&pData) const;
	void								(iSplineCustomGui::*GetScreenPosition)(const Vector &v, Int32 &x, Int32 &y) const;
	void								(iSplineCustomGui::*GetValue)(const Int32 x, const Int32 y, Vector &v) const;

	Bool								(iSpline::*InitDefaultFlag)(Int32 flag);

	void								(iSplineCustomGui::*SetCustomColor)(Bool bSet, Vector col);
	Bool								(iSpline::*CopyTo)(SplineData* pDest);

	Bool								(iSplineCustomGui::*Command)(Int32 id, const BaseContainer &msg);
	Bool								(iSpline::*SetKnot)(Int32 l, const CustomSplineKnot& knot);

	void								(iSpline::*SetTension)(Float tension);
	Float 							(iSpline::*GetTension)() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_SPLINECONTROL_H__
