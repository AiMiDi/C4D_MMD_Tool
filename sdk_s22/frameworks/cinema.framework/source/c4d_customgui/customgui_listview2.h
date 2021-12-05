/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_LISTVIEW2_H__
#define CUSTOMGUI_LISTVIEW2_H__

#include "lib_description.h"
#include "customgui_base.h"

#define CUSTOMDATA_LISTVIEW	1018397
#define CUSTOMGUI_LISTVIEW	1018398

class iListViewData;

class ListViewData : public CustomDataType
{
private:
	ListViewData();
	~ListViewData();
public:
	static ListViewData* Alloc();
	static void Free(ListViewData *&pData);

	Bool AddItem(Int32 id, const maxon::String &name, const GeData &data);
	Bool UpdateItem(Int32 id, const maxon::String &name, const GeData &data);
	void RemoveItem(Int32 id);

	Int32 GetCount();
	Int32 GetSelected();
	void Select(Int32 index);

	GeData GetData(Int32 index);
	String GetName(Int32 index);
	Int32 GetID(Int32 index);

	void SetData(Int32 index, const GeData &data);
	void SetName(Int32 index, const maxon::String &name);
	void SetID(Int32 index, Int32 id);

	Int32 FindIndex(Int32 id);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct CustomGuiListViewLib : public BaseCustomGuiLib
{
	iListViewData		*(*Alloc	)();
	void						(*Free		)(iListViewData *&pData);

	Bool		(iListViewData::*AddItem			)(Int32 id, const maxon::String &name, const GeData &data);
	Bool		(iListViewData::*UpdateItem		)(Int32 id, const maxon::String &name, const GeData &data);
	void		(iListViewData::*RemoveItem		)(Int32 id);
	Int32		(iListViewData::*GetCount			)();
	Int32		(iListViewData::*GetSelected	)();
	void		(iListViewData::*Select				)(Int32 index);
	GeData	(iListViewData::*GetData			)(Int32 index);
	String	(iListViewData::*GetName			)(Int32 index);
	Int32		(iListViewData::*GetID				)(Int32 index);
	void		(iListViewData::*SetData			)(Int32 index, const GeData &data);
	void		(iListViewData::*SetName			)(Int32 index, const maxon::String &name);
	void		(iListViewData::*SetID				)(Int32 index, Int32 id);
	Int32		(iListViewData::*FindIndex		)(Int32 id);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_LISTVIEW2_H__
