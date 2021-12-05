/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASESELECT_H__
#define C4D_BASESELECT_H__

#ifdef __API_INTERN__
	#include "baseselect.h"
#else

#include "operatingsystem.h"
#include "c4d_file.h"

/// @markPrivate
struct BaseSelectData
{
	Int32 a, b;
};

//----------------------------------------------------------------------------------------
/// This class is used to keep track of point and polygon selections, it may also be used to track other types of element selections.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BaseSelect
{
private:
	BaseSelect();
	~BaseSelect();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base selection}
	/// @return												@allocReturn{base selection}
	//----------------------------------------------------------------------------------------
	static BaseSelect* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base selections}
	/// @param[in,out] bs							@theToDestruct{base selection}
	//----------------------------------------------------------------------------------------
	static void Free(BaseSelect*& bs);

	/// @}

	/// @name Selection/Segment Count
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of selected elements.
	/// @return												The number of selected elements.
	//----------------------------------------------------------------------------------------
	Int32 GetCount(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of segments that contain elements.
	/// @note For example: with the selections @em 0..@em 4, @em 6..@em 7, @em 9..@em 12, GetSegments() would return @em 3 and GetCount() would return @em 11.
	/// @return												The number of segments with selected elements.
	//----------------------------------------------------------------------------------------
	Int32 GetSegments(void) const;

	/// @}

	/// @name Select/Deselect/Toggle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Selects an element.
	/// @param[in] num								The element index to select.
	/// @return												@trueIfOtherwiseFalse{the element was already selected}
	//----------------------------------------------------------------------------------------
	Bool Select(Int32 num);

	//----------------------------------------------------------------------------------------
	/// Selects all elements in the given range.
	/// @param[in] min								The first element to select.
	/// @param[in] max								The last element in the range to select.
	/// @param[in] deselectAll				Since R17. Deselects all previously selected elements before creating the new selection (equivalent to @ref SELECTION_NEW).
	/// @return												Success of selecting the elements.
	//----------------------------------------------------------------------------------------
	Bool SelectAll(Int32 min, Int32 max, Bool deselectAll = true);

	//----------------------------------------------------------------------------------------
	/// Deselects an element.
	/// @param[in] num								The element index to deselect.
	/// @return												@trueIfOtherwiseFalse{the element was already deselected}
	//----------------------------------------------------------------------------------------
	Bool Deselect(Int32 num);

	//----------------------------------------------------------------------------------------
	/// Deselects all elements.
	/// @return												Success of deselecting all elements.
	//----------------------------------------------------------------------------------------
	Bool DeselectAll(void);

	//----------------------------------------------------------------------------------------
	/// Toggles the selection state of an element.
	/// @param[in] num								The element index to toggle.
	/// @return												Success of changing the selection state of the element.
	//----------------------------------------------------------------------------------------
	Bool Toggle(Int32 num);

	//----------------------------------------------------------------------------------------
	/// Toggles the selection state of all elements in the given range.
	/// @param[in] min								The first element to toggle.
	/// @param[in] max								The last element to toggle in the range.
	/// @return												Success of changing the selection state.
	//----------------------------------------------------------------------------------------
	Bool ToggleAll(Int32 min, Int32 max);

	/// @}

	/// @name Get/Check Selection
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the selected elements contained in a segment.
	/// @param[in] seg								The segment to get the elements for. @em 0 <= @formatParam{seg} < GetSegments()
	/// @param[in] maxElements				The maximum value for @formatParam{a} and @formatParam{b}. Makes sure @formatParam{a} and @formatParam{b} are < @formatParam{maxElements}. Pass LIMIT<Int32>::MAX for no additional checks.
	/// @param[out] a									Assigned the index of the first selected element.
	/// @param[out] b									Assigned the index of the last selected element.
	/// @return												@trueIfOtherwiseFalse{if the range was successfully retrieved} Only @formatConstant{false} if @formatParam{seg} is not @em 0 <= @formatParam{seg} < GetSegments()\n
	/// 															The spans are always sorted (spans with higher index have higher numbers for @formatParam{a}/@formatParam{b}), also @formatParam{b} is always >= @formatParam{a}.
	//----------------------------------------------------------------------------------------
	Bool GetRange(Int32 seg, Int32 maxElements, Int32* a, Int32* b) const;

	//----------------------------------------------------------------------------------------
	/// Checks the selection state of an element.\n
	/// To efficiently go through selections use the following code:
	/// @code
	/// Int32 seg = 0, a, b, i;
	/// while (bs->GetRange(seg++, LIMIT<Int32>::MAX, &a, &b))
	/// {
	/// 	for (i=a; i<=b; ++i)
	/// 	{
	/// 		// Do something. 'i' is the selected element
	/// 	}
	/// }
	/// @endcode
	/// This is faster than:
	/// @code
	/// for (i=0; i<maxelements; i++)
	/// {
	/// 	if (bs->IsSelected(i))
	/// 	{
	/// 		// Do something
	/// 	}
	/// }
	/// @endcode
	/// @param[in] num								The element index to get the state for.
	/// @return												@trueIfOtherwiseFalse{the element @formatParam{num} is selected}
	//----------------------------------------------------------------------------------------
	Bool IsSelected(Int32 num) const { return C4DOS.Bs->IsSelected(this, num); }

	/// @}

	/// @name Copy/Clone
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the selection elements to another BaseSelect.
	/// @param[out] dest							The destination selection. @callerOwnsPointed{selection}
	/// @return												@trueIfOtherwiseFalse{selection elements were copied successfully}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(BaseSelect* dest) const;

	//----------------------------------------------------------------------------------------
	/// Makes a duplicate of the selection with its elements.
	/// @return												The cloned BaseSelect or @formatConstant{nullptr} if failed. @callerOwnsPointed{BaseSelect}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetClone(void) const;

	/// @}

	/// @name Merge/Deselect/cross
	/// @{

	//----------------------------------------------------------------------------------------
	/// Selects all elements that are in @formatParam{src}.
	/// @param[in] src								The source selection. @callerOwnsPointed{selection}
	/// @return												@trueIfOtherwiseFalse{the selection elements were merged successfully}
	//----------------------------------------------------------------------------------------
	Bool Merge(const BaseSelect* src);

	//----------------------------------------------------------------------------------------
	/// Deselects all elements that are in @formatParam{src}.
	/// @param[in] src								The source selection. @callerOwnsPointed{selection}
	/// @return												@trueIfOtherwiseFalse{the selection elements were deselected successfully}
	//----------------------------------------------------------------------------------------
	Bool Deselect(const BaseSelect* src);

	//----------------------------------------------------------------------------------------
	/// Intersects all elements in @formatParam{src}.
	/// @param[in] src								The source selection. @callerOwnsPointed{selection}
	/// @return												@trueIfOtherwiseFalse{the selection elements were crossed successfully}
	//----------------------------------------------------------------------------------------
	Bool Cross(const BaseSelect* src);

	/// @}

	/// @name Conversion from/to Array
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a number of selected elements from an array. The elements in the array are interpreted as ::Bool: @em 0 means the element is unselected, and @em 1 means it is selected.
	/// @warning The old selection will completely be overridden.
	/// @param[in] selection					An array of elements to select. @callerOwnsPointed{array}
	/// @param[in] count							The number of elements in the array.
	/// @return												@trueIfOtherwiseFalse{the elements from the array were selected successfully}
	//----------------------------------------------------------------------------------------
	Bool FromArray(UChar* selection, Int32 count);

	//----------------------------------------------------------------------------------------
	/// Gets an array of selected elements. The elements in the array are interpreted as ::Bool: @em 0 means the element is unselected, and @em 1 means it is selected.
	/// @warning The array is created with NewMemClear() and must be freed with DeleteMem() afterward.
	/// @param[in] count							The number of elements to place into the array.
	/// @return												The array containing the selected elements or @formatConstant{nullptr} if failed. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	UChar* ToArray(Int32 count) const;

	//----------------------------------------------------------------------------------------
	/// @return												@trueIfOtherwiseFalse{the elements from the array were selected successfully}
	//----------------------------------------------------------------------------------------
	Bool ToBitSet(Int32 count, maxon::BaseBitSet<maxon::DefaultAllocator>& bitSet) const;

	/// @}

	/// @name Read/Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads a selection from a file.
	/// @param[in] hf									The file to read a selection from. @callerOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{a selection was successfully read}
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile* hf);

	//----------------------------------------------------------------------------------------
	/// Writes the selection to a file.
	/// @param[in] hf									The file to write the selection to. @callerOwnsPointed{hyper file}
	//----------------------------------------------------------------------------------------
	void Write(HyperFile* hf);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Calculates which segment contains the element @formatParam{num} and returns it in @formatParam{segment}.
	/// @param[in] num								An element number.
	/// @param[out] segment						Assigned the found segment index.
	/// @return												@trueIfOtherwiseFalse{the segment was found}
	//----------------------------------------------------------------------------------------
	Bool FindSegment(Int32 num, Int32* segment) const { return C4DOS.Bs->FindSegment(this, num, segment); }

	//----------------------------------------------------------------------------------------
	/// Gets the dirty counter of the selection.
	/// @note The dirty counter is increased every time a function that changes the selection is called.
	/// @return												The dirty counter.
	//----------------------------------------------------------------------------------------
	Int32 GetDirty() const { return C4DOS.Bs->GetDirty(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the last selected element, e.g. the last element selected through Select().
	/// @return												The last selected element.
	//----------------------------------------------------------------------------------------
	Int32 GetLastElement(void) const { return C4DOS.Bs->GetLastElement(this); }

	//----------------------------------------------------------------------------------------
	/// Checks if all elements from zero to num-1 are selected.
	/// @param[in] num								Number of elements to check.
	/// @return												True, if all elements are selected.
	//----------------------------------------------------------------------------------------
	inline Bool IsAllSelected(Int32 num) const 
	{
		if (GetSegments() != 1)
			return false;
		const BaseSelectData* data = const_cast<BaseSelect*>(this)->GetData();
		return data[0].a == 0 && data[0].b >= num - 1; 
	}

	//----------------------------------------------------------------------------------------
	/// Checks if nothing is selected.
	/// @return												True, if nothing is selected.
	//----------------------------------------------------------------------------------------
	inline Bool IsNothingSelected() const { return GetCount() == 0; }

	/// @}

	/// @name Private
	/// @{

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	BaseSelectData* GetData() { return C4DOS.Bs->GetData(this); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(BaseSelectData* ndata, Int32 ncnt) { return C4DOS.Bs->CopyFrom(this, ndata, ncnt); }

	/// @}
};

class EdgeBaseSelect : public BaseSelect
{
private:
	EdgeBaseSelect();
	~EdgeBaseSelect();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{edge base selection}
	/// @return												@allocReturn{edge base selection}
	//----------------------------------------------------------------------------------------
	static EdgeBaseSelect* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{edge base selections}
	/// @param[in,out] bs							@theToDestruct{edge base selection}
	//----------------------------------------------------------------------------------------
	static void Free(EdgeBaseSelect*& bs);

	//----------------------------------------------------------------------------------------
	/// Gets a number of selected elements from an array. There is one byte per polygon in the array. The bits 0 to 3 of each byte define which edge of the polygon is selected.
	/// @warning The old selection will completely be overridden.
	/// @param[in] selection					An array of elements to select. @callerOwnsPointed{array}
	/// @param[in] count							The number of elements in the array. This is usually the polygon count.
	/// @return												@trueIfOtherwiseFalse{the elements from the array were selected successfully}
	//----------------------------------------------------------------------------------------
	Bool FromArrayCompact(const UChar *selection, Int32 count);

	//----------------------------------------------------------------------------------------
	/// Gets an array of selected elements. There is one byte per polygon in the array. The bits 0 to 3 of each byte define which edge of the polygon is selected.
	/// @warning The array is created with NewMemClear() and must be freed with DeleteMem() afterward.
	/// @param[in] count							The number of elements to place into the array. This is usually the polygon count.
	/// @return												The array containing the selected elements or @formatConstant{nullptr} if failed. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	UChar* ToArrayCompact(Int32 count) const;
};

#endif

#endif // C4D_BASESELECT_H__
