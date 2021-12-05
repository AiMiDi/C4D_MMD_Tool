/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_EDITORTOOLS_H__
#define LIB_EDITORTOOLS_H__

#include "c4d_library.h"

class LassoSelection;

/// @addtogroup group_editortoolslibrary Editor Tools
/// @ingroup group_library
/// @{

//----------------------------------------------------------------------------------------
/// A class representing a set of objects in the editor.\n
/// Most often allocate a copy of this object and then let SelectionListCreate() fill it.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class C4DObjectList
{
	private:
		C4DObjectList();
		~C4DObjectList();
	public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesAN{object list}
	/// @return												@allocReturn{object list}
	//----------------------------------------------------------------------------------------
		static C4DObjectList* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{object lists}
	/// @param[in,out] ptr						@theToDestruct{object list}
	//----------------------------------------------------------------------------------------
		static void Free(C4DObjectList *&ptr);

	/// @}

	/// @name Object List
	/// @{

		//----------------------------------------------------------------------------------------
		/// Get the number of objects stored in the list.
		/// @return												The number of objects.
		//----------------------------------------------------------------------------------------
		Int32 GetCount();

		//----------------------------------------------------------------------------------------
		/// Gets a stored object pointer by index.
		/// @param[in] num								An object index: @em 0 <= @formatParam{num} < GetCount()
		/// @return												The object at index @formatParam{num}. @cinemaOwnsPointed{object}
		//----------------------------------------------------------------------------------------
		BaseObject* GetObject(Int32 num);

		//----------------------------------------------------------------------------------------
		/// Gets the Z distance to a stored object by index.
		/// @param[in] num								An object index: @em 0 <= @formatParam{num} < GetCount()
		/// @return												The Z distance to the object at index @formatParam{num}.
		//----------------------------------------------------------------------------------------
		Float GetZ(Int32 num);

		//----------------------------------------------------------------------------------------
		/// Gets the polygon index of a stored object by index.
		/// @param[in] num								An object index: @em 0 <= @formatParam{num} < GetCount()
		/// @return												The polygon index.
		//----------------------------------------------------------------------------------------
		Int32 GetPolyIdx(Int32 num);

		//----------------------------------------------------------------------------------------
		/// Adds an object to the list at a certain Z distance.
		/// @param[in] op									The object to add. @callerOwnsPointed{object}
		/// @param[in] z									The Z distance to @formatParam{op}.
		/// @param[in] polynum						The number of polygons.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool AddObject(BaseObject *op, Float z, Int32 polynum);

		//----------------------------------------------------------------------------------------
		/// Clears the object list.
		//----------------------------------------------------------------------------------------
		void Flush();

	/// @}
};

//----------------------------------------------------------------------------------------
/// Creates a valid object list for the given coordinate (@formatParam{mx},@formatParam{my}) and specific base draw by adding objects to the provided list.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] parent							An optional parent object or @formatConstant{nullptr}. @callerOwnsPointed{object}\n
/// 															When this is provided the search is limited to the parent and its descendants.
/// @param[in] bd									The base draw for the search. @callerOwnsPointed{base draw}
/// @param[in] mx									The screen X coordinate.
/// @param[in] my									The screen Y coordinate.
/// @param[in] ls									An optional initialized lasso selection object or @formatConstant{nullptr}. @callerOwnsPointed{object}\n
/// 															When this is provided the search is extended to include all objects that are within the lasso selection.
/// @param[in,out] list						The list to fill. The found objects are sorted by Z distance so that the first object is the closest. @callerOwnsPointed{list}
/// @param[in] use_selection_filter	Use @C4D's selection filter.
/// @param[in] use_display_filter	Use @C4D's display filter.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool SelectionListCreate(BaseDocument *doc, BaseObject *parent, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list, Bool use_selection_filter = true, Bool use_display_filter = true);

//----------------------------------------------------------------------------------------
/// Creates a valid object list for a number of objects included in @formatParam{arr} for the given coordinate (@formatParam{mx},@formatParam{my}) for a specific base draw by adding objects to the provided list.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] arr								The array of objects to limit the search. @callerOwnsPointed{array}
/// @param[in] bd									The base draw for the search. @callerOwnsPointed{base draw}
/// @param[in] mx									The screen X coordinate.
/// @param[in] my									The screen Y coordinate.
/// @param[in] ls									An optional initialized lasso selection object or @formatConstant{nullptr}. @callerOwnsPointed{object}\n
/// 															When this is provided the search is extended to include all objects that are within the lasso selection.
/// @param[in,out] list						The list to fill. The found objects are sorted by Z distance so that the first object is the closest. @callerOwnsPointed{list}
/// @param[in] use_selection_filter	Use @C4D's selection filter.
/// @param[in] use_display_filter	Use @C4D's display filter.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool FilteredSelectionListCreate(BaseDocument *doc, AtomArray *arr, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list, Bool use_selection_filter = true, Bool use_display_filter = true);

//----------------------------------------------------------------------------------------
/// Shows a popup menu with the given object list and lets the user choose an object.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] screenx						The screen X coordinate of the menu or @ref MOUSEPOS for the current mouse coordinates.
/// @param[in] screeny						The screen Y coordinate of the menu or @ref MOUSEPOS for the current mouse coordinates.
/// @param[in] list								The list to build the menu from. @callerOwnsPointed{list}
/// @return												The user choice or @ref NOTOK if nothing was selected.
//----------------------------------------------------------------------------------------
Int32 SelectionListShowMenu(BaseDocument *doc, Float screenx, Float screeny, C4DObjectList *list);

/// Editor Tools / C4DObjectList library ID.
#define LIBRARY_OBJECTLIST		1000464

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class C4DObjectList;

struct ObjectListLib : public C4DLibrary
{
	C4DObjectList*	(*ObjectList_Alloc			)();
	void						(*ObjectList_Free				)(C4DObjectList *ptr);
	Int32						(*ObjectList_GetCount		)(C4DObjectList *ptr);
	BaseObject*			(*ObjectList_GetObject	)(C4DObjectList *ptr, Int32 num);
	Float						(*ObjectList_GetZ				)(C4DObjectList *ptr, Int32 num);
	Bool						(*ObjectList_AddObjectEx)(C4DObjectList *ptr, BaseObject *op, Float z);
	Bool						(*ObjectList_AddObject	)(C4DObjectList *ptr, BaseObject *op, Float z, Int32 polynum);
	Int32						(*ObjectList_GetPolyIdx	)(C4DObjectList *ptr, Int32 num);
	void						(*ObjectList_Flush			)(C4DObjectList *ptr);
};

// Example implementation editor tools, internal stuff

#define LIBRARY_EDITORTOOLS		1000465

struct EditorToolLib : public C4DLibrary
{
	Bool				(*SelectionListCreateEx)(BaseDocument *doc, BaseObject *parent, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list);
	Int32				(*SelectionListShowMenu)(BaseDocument *doc, Float screenx, Float screeny, C4DObjectList *list);
	Bool				(*SelectionListCreate)(BaseDocument *doc, BaseObject *parent, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list, Bool use_selection_filter, Bool use_display_filter);
	Bool				(*FilteredSelectionListCreate)(BaseDocument *doc, AtomArray *arr, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list, Bool use_selection_filter, Bool use_display_filter);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_EDITORTOOLS_H__
