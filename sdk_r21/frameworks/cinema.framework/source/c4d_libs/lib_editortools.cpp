#include "lib_editortools.h"


ObjectListLib *lib_objectlist = nullptr;
EditorToolLib *lib_editortool = nullptr;


static ObjectListLib *CheckEditorToolsLib(Int32 offset)
{
	return (ObjectListLib*)CheckLib(LIBRARY_OBJECTLIST, offset, (C4DLibrary**)&lib_objectlist);
}

static EditorToolLib *CheckLibEditorToolLib(Int32 offset)
{
	return (EditorToolLib*)CheckLib(LIBRARY_EDITORTOOLS, offset, (C4DLibrary**)&lib_editortool);
}


C4DObjectList* C4DObjectList::Alloc()
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_Alloc)); if (!lib) return nullptr;
	return lib->ObjectList_Alloc();
}

void C4DObjectList::Free(C4DObjectList *&ptr)
{
	if (!ptr) return;
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_Free)); if (!lib) return;
	lib->ObjectList_Free(ptr);
	ptr = nullptr;
}

Int32 C4DObjectList::GetCount()
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_GetCount)); if (!lib) return 0;
	return lib->ObjectList_GetCount(this);
}

BaseObject*	C4DObjectList::GetObject(Int32 num)
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_GetObject)); if (!lib) return nullptr;
	return lib->ObjectList_GetObject(this, num);
}

Float C4DObjectList::GetZ(Int32 num)
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_GetZ)); if (!lib) return 0.0;
	return lib->ObjectList_GetZ(this, num);
}

Int32 C4DObjectList::GetPolyIdx(Int32 num)
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_GetPolyIdx)); if (!lib) return 0;
	return lib->ObjectList_GetPolyIdx(this, num);
}

Bool C4DObjectList::AddObject(BaseObject *op, Float z, Int32 polynum)
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_AddObject)); if (!lib) return 0;
	return lib->ObjectList_AddObject(this, op, z, polynum);
}

void C4DObjectList::Flush()
{
	ObjectListLib *lib = CheckEditorToolsLib(LIBOFFSET(ObjectListLib, ObjectList_Flush)); if (!lib) return;
	lib->ObjectList_Flush(this);
}

Bool SelectionListCreate(BaseDocument *doc, BaseObject *parent, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list, Bool use_selection_filter, Bool use_display_filter)
{
	EditorToolLib *lib = CheckLibEditorToolLib(LIBOFFSET(EditorToolLib, SelectionListCreate));
	if (!lib) return false;
	return lib->SelectionListCreate(doc, parent, bd, mx, my, ls, list, use_selection_filter, use_display_filter);
}

Bool FilteredSelectionListCreate(BaseDocument *doc, AtomArray *arr, BaseDraw *bd, Float mx, Float my, LassoSelection *ls, C4DObjectList *list, Bool use_selection_filter, Bool use_display_filter)
{
	EditorToolLib *lib = CheckLibEditorToolLib(LIBOFFSET(EditorToolLib, FilteredSelectionListCreate));
	if (!lib) return false;
	return lib->FilteredSelectionListCreate(doc, arr, bd, mx, my, ls, list, use_selection_filter, use_display_filter);
}

Int32 SelectionListShowMenu(BaseDocument *doc, Float screenx, Float screeny, C4DObjectList *list)
{
	EditorToolLib *lib = CheckLibEditorToolLib(LIBOFFSET(EditorToolLib, SelectionListShowMenu));
	if (!lib) return false;
	return lib->SelectionListShowMenu(doc, screenx, screeny, list);
}
