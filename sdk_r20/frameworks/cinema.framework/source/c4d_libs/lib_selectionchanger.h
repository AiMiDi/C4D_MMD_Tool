/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

// Convenience class for changing BaseSelect selections from one mode to another
#ifndef LIB_SELECTIONCHANGER_H__
#define LIB_SELECTIONCHANGER_H__

#include "c4d_library.h"

/// @addtogroup group_selectionchangerlibrary Selection Changer
/// @ingroup group_library
/// @{

/// Selection changer library ID.
#define C4DSELECTIONCHANGER_LIB_ID		1019533

//----------------------------------------------------------------------------------------
/// Convenience class for changing a selection type i.e. polygon selection to edge selection. The class owns all returned selections. Must be initialized before use.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SelectionChanger
{
private:
	SelectionChanger() { }
	~SelectionChanger() { }
public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{selection changer}
	/// @return												@allocReturn{selection changer}
	//----------------------------------------------------------------------------------------
	static SelectionChanger *Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{selection changers}
	/// @param[in,out] node						@theToDestruct{selection changer}
	//----------------------------------------------------------------------------------------
	static void Free(SelectionChanger *&node);

	/// @}

	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the selection changer from a selection tag.
	/// @param[in] targtag						The selection tag used for input. @callerOwnsPointed{tag}
	/// @param[in] op									The object the tag is on. Generally required for most transformations to take place. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitFromTag(BaseTag *targtag, PolygonObject *op = nullptr);

	//----------------------------------------------------------------------------------------
	/// Initializes the selection changer from a selection object and a specific selection mode.
	/// @param[in] selection					The selection used for input.
	/// @param[in] selection_mode			The mode of the selection: @ref Mpoints or @ref Mpolygons or @ref Medges.
	/// @param[in] op									The object the tag is on. Generally required if the selection is on a polygon object (but not on a spline object).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitFromSelection(BaseSelect *selection, Int32 selection_mode, PolygonObject *op = nullptr);

	/// @}

	/// @name Get Conversion
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the converted selection in points mode.
	/// @return												The converted selection. @theOwnsPointed{selection changer,selection}
	//----------------------------------------------------------------------------------------
	BaseSelect *GetPointS(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the converted selection in polygon mode.
	/// @return												The converted selection. @theOwnsPointed{selection changer,selection}
	//----------------------------------------------------------------------------------------
	BaseSelect *GetPolygonS(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the converted selection in edge mode.
	/// @return												The converted selection. @theOwnsPointed{selection changer,selection}
	//----------------------------------------------------------------------------------------
	BaseSelect *GetEdgeS(void);

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iSelectionChanger;

struct SelectionChangerLibrary : public C4DLibrary
{
	Bool							(iSelectionChanger::*InitFromTag			)(BaseTag *targtag, PolygonObject *op);
	Bool							(iSelectionChanger::*InitFromSelection)(BaseSelect *selection, Int32 selection_mode, PolygonObject *op);
	BaseSelect*				(iSelectionChanger::*GetPointS				)();
	BaseSelect*				(iSelectionChanger::*GetEdgeS					)();
	BaseSelect*				(iSelectionChanger::*GetPolygonS			)();

	iSelectionChanger*(*Alloc	)();
	void							(*Free	)(iSelectionChanger *&node);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_SELECTIONCHANGER_H__
