#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2006 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////

// helper class to quickly change an input selection into another selection mode
#include "lib_selectionchanger.h"

SelectionChangerLibrary* selchangelib_cache;

static SelectionChangerLibrary* CheckSelectionChangerLib(Int32 offset)
{
	return (SelectionChangerLibrary*)CheckLib(C4DSELECTIONCHANGER_LIB_ID, offset, (C4DLibrary**)&selchangelib_cache);
}

Bool SelectionChanger::InitFromTag(BaseTag *targtag, PolygonObject *op)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, InitFromTag));
	if (!sclib || !sclib->InitFromTag) return false;

	return (((iSelectionChanger*)this)->*(sclib->InitFromTag))(targtag, op);
}

Bool SelectionChanger::InitFromSelection(BaseSelect *selection, Int32 selection_mode, PolygonObject *op)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, InitFromSelection));
	if (!sclib || !sclib->InitFromSelection) return false;

	return (((iSelectionChanger*)this)->*(sclib->InitFromSelection))(selection, selection_mode, op);
}

BaseSelect *SelectionChanger::GetPointS(void)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, GetPointS));
	if (!sclib || !sclib->GetPointS) return nullptr;

	return (((iSelectionChanger*)this)->*(sclib->GetPointS))();
}

BaseSelect *SelectionChanger::GetEdgeS(void)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, GetEdgeS));
	if (!sclib || !sclib->GetEdgeS) return nullptr;

	return (((iSelectionChanger*)this)->*(sclib->GetEdgeS))();
}

BaseSelect *SelectionChanger::GetPolygonS(void)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, GetPolygonS));
	if (!sclib || !sclib->GetPolygonS) return nullptr;

	return (((iSelectionChanger*)this)->*(sclib->GetPolygonS))();
}

SelectionChanger *SelectionChanger::Alloc(void)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, Alloc));
	if (!sclib || !sclib->Alloc) return nullptr;

	return (SelectionChanger*)sclib->Alloc();
}

void SelectionChanger::Free(SelectionChanger *&node)
{
	SelectionChangerLibrary *sclib = CheckSelectionChangerLib(LIBOFFSET(SelectionChangerLibrary, Free));
	if (!sclib || !sclib->Free) return;

	iSelectionChanger *tmp = (iSelectionChanger*)node;
	sclib->Free(tmp);
	node = nullptr;
}
