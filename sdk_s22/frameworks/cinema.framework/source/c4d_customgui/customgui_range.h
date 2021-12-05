/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_RANGE_H__
#define CUSTOMGUI_RANGE_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

/// RangeCustomGui ID. @since R19
static const Int32 CUSTOMGUI_RANGE = 431000177;

/// RangeData ID. @since R19
static const Int32 CUSTOMDATATYPE_RANGE = 431000178;

/// @addtogroup RANGECUSTOMGUI_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
/// @since R19
enum
{
	RANGE_ALLOWRANGEEDIT = 1000, 				///< ::Bool @formatConstant{true} allows user to add or remove ranges.
	RANGE_ALLOWVALUEEDIT,								///< ::Bool @formatConstant{true} allows the user to edit the LOD value.
	RANGE_ALLOWVALUEEDIT_NONUMERICAL,		///< ::Bool @formatConstant{true} allows value editing for the slider only, not for numerical entry.
	RANGE_ALLOWRANGESLELECION,					///< ::Bool @formatConstant{true} to select ranges by clicking on the range.
	RANGE_SHOWVALUE,										///< ::Bool @formatConstant{true} to show numerical value.
	RANGE_SHOWVALUEPOINTER,							///< ::Bool @formatConstant{true} to show value indicator.
	RANGE_ALLOWCOLOREDIT,								///< ::Bool The color control is visible and the color can be changed by the user.
	RANGE_REVERSEVALUE,									///< ::Bool If @formatConstant{true} the value on the lod bar will be reversed, @em 100% on left and @em 0% on the right.
	RANGE_SHOWNUMBERONBAR,							///< ::Bool If @formatConstant{true} the range index is displayed on the bar.
	RANGE_REMAPVALUE,										///< ::Bool If @formatConstant{true} the value will be remapped using defined units, min and max.
	RANGE_REMAPUNIT,										///< ::Int32 The unit to be used for remapping: can be ::DESC_UNIT_METER, ::DESC_UNIT_PERCENT, ::DESC_UNIT_DEGREE, ::DESC_UNIT_FLOAT.
	RANGE_REMAPMIN,											///< ::Float The minimum remapping value.
	RANGE_REMAPMAX,											///< ::Float The maximum remapping value.
	RANGE_VALUESTRING,									///< ::String The string value to be used inside the GUI to decode the current value (e.g. "lod Value" for lod object).
	RANGE_CURSORICON										///< ::Int32 The icon ID for custom cursor.
};
/// @}

/// @addtogroup MSG_DESCRIPTION_RANGEGUI
/// @ingroup group_enumeration
/// @{
/// RangeCustomGui message sub IDs.
/// @since R19
enum
{
	MSG_DESCRIPTION_RANGEGUI_KNOTSELECTED = 0,							///< Selection was changed.
	MSG_DESCRIPTION_RANGEGUI_KNOTDELETED,										///< Knot was deleted.
	MSG_DESCRIPTION_RANGEGUI_KNOTADDED,											///< Knot was added.
	MSG_DESCRIPTION_RANGEGUI_RANGESINVERTED,								///< Ranges were inverted.
	MSG_DESCRIPTION_RANGEGUI_USERCURRENTVALUECHANGED,				///< %User changed current value.
};
/// @}

/// @addtogroup MSG_DESCRIPTION_RANGEGUI
/// @ingroup group_containerid
/// @{
/// @since R19
static const Int32 MSG_DESCRIPTION_RANGEGUI_KNOTSELECTED_INDEX = 0;						///< Selected index.
static const Int32 MSG_DESCRIPTION_RANGEGUI_KNOTDELETED_INDEX = 0;						///< Deleted index.
static const Int32 MSG_DESCRIPTION_RANGEGUI_KNOTADDED_INDEX = 0;							///< Added index.

static const Int32 MSG_DESCRIPTION_RANGEGUI_USERCURRENTVALUECHANGED_MODE = 1000;				///< User changed current value mode.
static const Int32 MSG_DESCRIPTION_RANGEGUI_USERCURRENTVALUECHANGED_VALUE = 10001;			///< User changed current value value.
static const Int32 MSG_DESCRIPTION_USERCURRENTVALUECHANGED_START = 0;										///< User changed current value start.
static const Int32 MSG_DESCRIPTION_USERCURRENTVALUECHANGED_DRAG = 1;										///< User changed current value drag.
static const Int32 MSG_DESCRIPTION_USERCURRENTVALUECHANGED_END = 2;											///< User changed current value end.
/// @}


//-------------------------------------------------------------------------------------------------
/// Stores a range for RangeData.
/// @since R19
//-------------------------------------------------------------------------------------------------
class RangePair
{
public:

	/// @name Constructors
	/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RangePair(Float min = 0.0, Float max = 0.0) : _min(min), _max(max) { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RangePair.
	//----------------------------------------------------------------------------------------
	RangePair(const RangePair& src) : _min(src._min), _max(src._max) { }

	/// @}
	
	/// @name Functions
	/// @{ 

	//----------------------------------------------------------------------------------------
	/// Checks if the range contains the given @formatParam{value}.
	/// @param[in] value							The value to check.
	/// @return												@trueIfOtherwiseFalse{the @formatParam{value} is within the range}
	//----------------------------------------------------------------------------------------
	Bool Contains(Float value) const { return value >= _min && value <= _max; }

	
	//----------------------------------------------------------------------------------------
	/// Retrieves the minimum range value.
	/// @return												The minimum range value.
	//----------------------------------------------------------------------------------------
	Float GetMin() const { return _min; }
	
	//----------------------------------------------------------------------------------------
	/// Retrieves the maximum range value.
	/// @return												The maximum range value.
	//----------------------------------------------------------------------------------------
	Float GetMax() const { return _max; }
	
	//----------------------------------------------------------------------------------------
	/// Calculates the center value for the range.
	/// @return												The center value for the range.
	//----------------------------------------------------------------------------------------
	Float GetCenter() const { return Blend(_min, _max, 0.5); }

	/// @}

private:
	Float _min;
	Float _max;
};

//-------------------------------------------------------------------------------------------------
/// Range data type (@ref CUSTOMDATATYPE_RANGE) for RangeCustomGui.
/// @addAllocFreeAutoAllocNote
/// @since R19
//-------------------------------------------------------------------------------------------------
class RangeData : public CustomDataType
{
private:

	/// @name Private Constructor/Destructor
	/// @{

	RangeData();
	~RangeData();

	/// @}

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{RangeData}
	/// @return												@allocReturn{range data}
	//----------------------------------------------------------------------------------------
	static RangeData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{RangeDatas}
	/// @param[in,out] data						@theToDestruct{RangeData}
	//----------------------------------------------------------------------------------------
	static void Free(RangeData*& data);

	/// @}

	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the range data with the passed range number. The interval in between ranges will be the same.
	/// @param[in] rangeNumber				The number of ranges.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(Int rangeNumber);

	/// @}

	/// @name Reset
	/// @{

	//----------------------------------------------------------------------------------------
	/// Resets the range data to the initial state.
	/// @param[in] invalidateObject		@formatConstant{true} to initialize the ranges after reset operation, otherwise the object will be initialized but functions with one single range.
	//----------------------------------------------------------------------------------------
	void Reset(Bool invalidateObject = false);

	/// @}

	/// @name Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copy the range data over to @formatParam{dst}.
	/// @param[in,out] dst						The destination range data. @callerOwnsPointed{range data}.
	//----------------------------------------------------------------------------------------
	void CopyTo(RangeData* dst);

	/// @}

	/// @name Value
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a value and split existing range.
	/// @param[in] value							The value to add.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AddValue(Float value);

	//----------------------------------------------------------------------------------------
	/// Retrieves The current value.
	/// @return												The current value.
	//----------------------------------------------------------------------------------------
	Float GetCurrentValue() const;

	//----------------------------------------------------------------------------------------
	/// Sets the current value.
	/// @param[in] value							The value, must be in the range @em [0.0, 1.0].
	//----------------------------------------------------------------------------------------
	void SetCurrentValue(Float value);

	/// @}

	/// @name Knots
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the numbers of knots.
	/// @return												The numbers of knots.
	//----------------------------------------------------------------------------------------
	Int GetKnotsCount()const;

	//----------------------------------------------------------------------------------------
	/// Sets the value at the specified knot index.
	/// @param[in] knotIndex					The knot index to set the value.
	/// @param[in] value							The value to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetKnotValue(Int knotIndex, Float value);

	//----------------------------------------------------------------------------------------
	/// Retrieves the value at the specified knot index.
	/// @param[in] knotIndex					The knot index.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Float GetKnotValue(Int knotIndex) const;

	//----------------------------------------------------------------------------------------
	/// Searches for a knot with the passed value.
	/// @param[in] value							The value used to search the knot.
	/// @return												The knot index, or ::NOTOK if not found.
	//----------------------------------------------------------------------------------------
	Int GetKnotIndexByValue(Float value) const;

	//----------------------------------------------------------------------------------------
	/// Deletes a knot at the specified knot index.
	/// @param[in] knotIndex					The knot index to delete.
	//----------------------------------------------------------------------------------------
	void DeleteKnot(Int knotIndex);

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected knot.
	/// @return												The selected knot index, or ::NOTOK if not found.
	//----------------------------------------------------------------------------------------
	Int GetSelectedKnot() const;

	//----------------------------------------------------------------------------------------
	/// Sets the selected knot.
	/// @param[in] knotIndex					The index to select, or ::NOTOK to deselect all.
	//----------------------------------------------------------------------------------------
	void SetSelectedKnot(Int knotIndex);

	/// @}

	/// @name Range
	/// @{

	//----------------------------------------------------------------------------------------
	/// The number of ranges, must be >= @em 1.
	/// @return												The number of ranges.
	//----------------------------------------------------------------------------------------
	Int GetRangesCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the range at the specified @formatParam{index}.
	/// @param[in] index							The range index.
	/// @return												The range.
	//----------------------------------------------------------------------------------------
	RangePair GetRange(Int index) const;

	//----------------------------------------------------------------------------------------
	/// Returns a range index a value for the specified @formatParam{value}.
	/// @param[in] value							The value, must be in range @em [0.0, 1.0].
	/// @return												The range index.
	//----------------------------------------------------------------------------------------
	Int GetRangeIndex(Float value) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the range color for the specified range @formatParam{index}.
	/// @param[in] index							The range index to get the color.
	/// @return												The range Color.
	//----------------------------------------------------------------------------------------
	Vector GetRangeColor(Int index) const;

	//----------------------------------------------------------------------------------------
	/// Sets the range color at the specified range @formatParam{index}.
	/// @note If IsPerRangeColorMode() returns @formatConstant{false} the range @formatParam{index} is not evaluated and the color is stored always at the first index.
	/// @param[in] index							The index of the range to set the color.
	/// @param[in] color							The color to be assigned to the range.
	//----------------------------------------------------------------------------------------
	void SetRangeColor(Int index, const Vector& color);

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected range.
	/// @return												The selected range index, or ::NOTOK if not found.
	//----------------------------------------------------------------------------------------
	Int GetSelectedRange() const;

	//----------------------------------------------------------------------------------------
	/// Sets the selected range.
	/// @param[in] rangeIndex					The index to select, or ::NOTOK to deselect all.
	//----------------------------------------------------------------------------------------
	void SetSelectedRange(Int rangeIndex);

	/// @}

	/// @name Color Modes
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the color mode is stored per range, or just as single color.
	/// @return												@trueIfOtherwiseFalse{the color is stored is stored per range}
	//----------------------------------------------------------------------------------------
	Bool IsPerRangeColorMode() const;

	//----------------------------------------------------------------------------------------
	/// Sets the mode indicating if the color need to be stored per range, or just as single color.
	/// @param[in] perRange						@formatConstant{true} to store the color per range, @formatConstant{false} to store it just as single color.
	//----------------------------------------------------------------------------------------
	void SetColorMode(Bool perRange);

	//----------------------------------------------------------------------------------------
	/// Checks if the colors are randomized or user defined.
	/// @return												@trueIfOtherwiseFalse{the colors are randomized}
	//----------------------------------------------------------------------------------------
	Bool IsRandomColorMode() const;

	//----------------------------------------------------------------------------------------
	/// Sets the random color mode.
	/// @param[in] random							@trueOtherwiseFalse{to randomize colors}
	//----------------------------------------------------------------------------------------
	void SetRandomColorMode(Bool random);

	/// @}
};


//----------------------------------------------------------------------------------------
/// Range custom GUI (@ref CUSTOMGUI_RANGE) for RangeData.\n
/// Here are the settings: @enumerateEnum{RANGECUSTOMGUI_CUSTOMGUISETTINGS}
/// @since R19
//----------------------------------------------------------------------------------------
class RangeCustomGui : public BaseCustomGui<CUSTOMGUI_RANGE>
{
	/// @name Private Destructor
	/// @{

	~RangeCustomGui() = delete;

	/// @}

public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _RANGESLIDER_INTERNAL_DEF_
class iRangeCustomGui : public iBaseCustomGui
{
	iRangeCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
};
class iRangeData
{
};
#else
class iRangeCustomGui;
class iRangeData;
#endif

struct RangeSliderLib : public BaseCustomGuiLib
{
	RangeData* 						(*AllocRangeData)();
	void									(*FreeRangeData)(RangeData*& data);
	void 									(iRangeData::*CopyTo)(RangeData* dst) const;
	Bool 									(iRangeData::*Init)(Int rangeNumber);
	Bool									(iRangeData::*AddValue)(Float value);
	Int 									(iRangeData::*GetRangesCount)() const;
	Int 									(iRangeData::*GetKnotsCount)()const;
	Bool 									(iRangeData::*SetKnotValue)(Int knotIndex, Float value);
	Float 								(iRangeData::*GetKnotValue)(Int knotIndex) const;
	Int 									(iRangeData::*GetKnotIndexByValue)(Float value) const;
	void 									(iRangeData::*DeleteKnot)(Int knotIndex);
	Float 								(iRangeData::*GetCurrentValue)() const;
	void 									(iRangeData::*SetCurrentValue)(Float value);
	RangePair 						(iRangeData::*GetRange)(Int index) const;
	Int 									(iRangeData::*GetRangeIndex)(Float value) const;
	Int 									(iRangeData::*GetSelectedRange)() const;
	Int 									(iRangeData::*GetSelectedKnot)() const;
	void 									(iRangeData::*SetSelectedRange)(Int rangeIndex);
	void 									(iRangeData::*SetSelectedKnot)(Int knotIndex);
	Bool 									(iRangeData::*IsPerRangeColorMode)() const;
	void 									(iRangeData::*SetColorMode)(Bool perRange);
	Vector 								(iRangeData::*GetRangeColor)(Int index) const;
	void 									(iRangeData::*SetRangeColor)(Int index, const Vector& color);
	void 									(iRangeData::*Reset)(Bool invalidateObject);

	Bool 									(iRangeData::*IsRandomColorMode)() const;
	void 									(iRangeData::*SetRandomColorMode)(Bool random);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_RANGE_H__
