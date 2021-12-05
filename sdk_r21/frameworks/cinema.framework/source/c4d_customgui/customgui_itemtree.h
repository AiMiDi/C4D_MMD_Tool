/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_ITEMTREE_H__
#define CUSTOMGUI_ITEMTREE_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

class ItemTreeNodeData;
class ItemTreeNodeIndex;

#define CUSTOMDATA_ITEMTREE			1024869
#define CUSTOMGUI_ITEMTREE			1024868


#define ITEMTREE_ID_LIST_FLAG									2000
#define ITEMTREE_ID_DRAG_FLAG									2001
#define ITEMTREE_ID_HEADERS_FLAG							2002
#define ITEMTREE_ID_ROWS											2003
#define ITEMTREE_ID_CHECKBOX_FLAG							2004
#define ITEMTREE_ID_FOLDERS_FLAG							2005
#define ITEMTREE_ID_PADLOCK_FLAG							2006
#define ITEMTREE_ID_COLOR_FLAG								2007
#define ITEMTREE_ID_ICON_FLAG									2008
#define ITEMTREE_ID_MULTIPLE_FLAG							2009
#define ITEMTREE_ID_NO_RENAME									2010
#define ITEMTREE_ID_NO_MENU										2011
#define ITEMTREE_ID_NO_LAYOUTMODE							2012 ///< Deprecated.
#define ITEMTREE_ID_ROWS_MAX									2013
#define ITEMTREE_ID_FOLD_FOLDERS_CMD_FLAG			2014
#define ITEMTREE_ID_HIDE_FOLDERS_CMD_FLAG			2015
#define ITEMTREE_ID_SHOW_BL_DEBUG_NAME				2016
#define ITEMTREE_ID_RESIZABLE									2017 ///< Deprecated.
#define ITEMTREE_ID_INCREMENT_FOLDER_NAME			2018

#define ITEMTREE_ID_HEADERS_DATA			5000
#define ITEMTREE_ID_HEADERS_IDS				5001
#define ITEMTREE_USER_COL_TYPES				5002
#define ITEMTREE_USER_COL_ACTIVE			5003
#define ITEMTREE_CHECKBOX_FRONT				5004

#define ITEMTREE_HEADER_DATA_ID				1000
#define ITEMTREE_HEADER_DATA_STRINGS	5000

#define ITEMTREE_OBJECT_COL						10000
#define ITEMTREE_ENABLE_COL						10001
#define ITEMTREE_LOCK_COL							10002
#define ITEMTREE_COLOR_COL						10003

#define ITEMTREE_USER_COL							50000

#define MSG_ITEMTREE_CALLBACK 1024875

#define ITEMTREE_FLAG_SIMPLELIST (ITEMTREE_FLAG_NOLINK|ITEMTREE_FLAG_NODRAG|ITEMTREE_FLAG_OPEN)

#define ITEMTREE_FLAG_INSERT_BEFORE	(1 << 0)
#define ITEMTREE_FLAG_INSERT_AFTER	(1 << 1)
#define ITEMTREE_FLAG_INSERT_UNDER	(1 << 2)
#define ITEMTREE_FLAG_OPEN					(1 << 3)
#define ITEMTREE_FLAG_SELECT				(1 << 4)
#define ITEMTREE_FLAG_ENABLE				(1 << 5)
#define ITEMTREE_FLAG_NOLINK				(1 << 6)
#define ITEMTREE_FLAG_NODRAG				(1 << 7)
#define ITEMTREE_FLAG_BL_NAME				(1 << 8)
#define ITEMTREE_FLAG_NO_RENAME			(1 << 9)
#define ITEMTREE_FLAG_LOCK					(1 << 10)
#define ITEMTREE_FLAG_DIRTY					(1 << 11)
#define ITEMTREE_FLAG_FOLDER				(1 << 12)
#define ITEMTREE_FLAG_NO_LOCK				(1 << 13)
#define ITEMTREE_FLAG_NO_ENABLE			(1 << 14)
#define ITEMTREE_FLAG_NO_COLOR			(1 << 15)
#define ITEMTREE_FLAG_NULLLINK			(1 << 16)
#define ITEMTREE_FLAG_MARK					(1 << 17)
#define ITEMTREE_FLAG_NOREMOVE			(1 << 18)
#define ITEMTREE_FLAG_FORCELINK			(1 << 19)
#define ITEMTREE_FLAG_HIDDEN				(1 << 20)
#define ITEMTREE_FLAG_INCREMENT_NAME (1 << 21)
#define ITEMTREE_FLAG_GREYED_OUT		(1 << 22)

#define ITEMTREE_CALLBACK_DRAGACCEPT			1
#define ITEMTREE_CALLBACK_INSERT					2
#define ITEMTREE_CALLBACK_OPEN						3
#define ITEMTREE_CALLBACK_CREATEMENU			4
#define ITEMTREE_CALLBACK_CALLMENU				5
#define ITEMTREE_CALLBACK_DELETE					6
#define ITEMTREE_CALLBACK_SELECTIONCHG		7
#define ITEMTREE_CALLBACK_DBLCLICK				8
#define ITEMTREE_CALLBACK_INSERTNODE			9
#define ITEMTREE_CALLBACK_GETCOLWIDTH			10
#define ITEMTREE_CALLBACK_GETLINEHEIGHT		11
#define ITEMTREE_CALLBACK_DRAWCELL				12
#define ITEMTREE_CALLBACK_CHECKBOX				13
#define ITEMTREE_CALLBACK_GETDRAGTYPE			14
#define ITEMTREE_CALLBACK_CALLMENU_PASTE	15
#define ITEMTREE_CALLBACK_MOVENODE				16
#define ITEMTREE_CALLBACK_RENAME					17
#define ITEMTREE_CALLBACK_LOCK						18
#define ITEMTREE_CALLBACK_DELETE_NODE			19
#define ITEMTREE_CALLBACK_DELETE_END			20
#define ITEMTREE_CALLBACK_MOUSEDOWN				21
#define ITEMTREE_CALLBACK_PAINT_FINISHED	22
#define ITEMTREE_CALLBACK_CALLPOSTMENU		23
#define ITEMTREE_CALLBACK_HEADERCLICK			24
#define ITEMTREE_CALLBACK_GETDROPDOWNMENU 25
#define ITEMTREE_CALLBACK_SETDROPDOWNMENU 26
#define ITEMTREE_SELECTIONCHG_SELECTIONID	27
#define ITEMTREE_SELECTIONCHG_FOCUSID			28

#define ITEMTREE_DRAG_TYPE		1000
#define ITEMTREE_DRAG_OBJECT	1001
#define ITEMTREE_DRAG_NODE		1002
#define ITEMTREE_DRAG_MASK		1003
#define ITEMTREE_INSERT_INSERTLAST 1004

#define ITEMTREE_SETDROPDOWNMENU_COLUMN 1005
#define ITEMTREE_SETDROPDOWNMENU_ENTRY 1006

#define ITEMTREE_MENU_COPY					ID_TREEVIEW_FIRST_NEW_ID
#define ITEMTREE_MENU_PASTE					(ID_TREEVIEW_FIRST_NEW_ID+1)
#define ITEMTREE_MENU_SELECT				(ID_TREEVIEW_FIRST_NEW_ID+2)
#define ITEMTREE_MENU_LOCK					(ID_TREEVIEW_FIRST_NEW_ID+3)
#define ITEMTREE_MENU_LOCK_ALL			(ID_TREEVIEW_FIRST_NEW_ID+4)
#define ITEMTREE_MENU_UNLOCK				(ID_TREEVIEW_FIRST_NEW_ID+5)
#define ITEMTREE_MENU_UNLOCK_ALL		(ID_TREEVIEW_FIRST_NEW_ID+6)
#define ITEMTREE_MENU_NEW_FOLDER		(ID_TREEVIEW_FIRST_NEW_ID+7)
#define ITEMTREE_MENU_REPLACE				(ID_TREEVIEW_FIRST_NEW_ID+8)
#define ITEMTREE_MENU_ENABLE				(ID_TREEVIEW_FIRST_NEW_ID+9)
#define ITEMTREE_MENU_ENABLE_ALL		(ID_TREEVIEW_FIRST_NEW_ID+10)
#define ITEMTREE_MENU_DISABLE_ALL		(ID_TREEVIEW_FIRST_NEW_ID+11)
#define ITEMTREE_MENU_DISABLE				(ID_TREEVIEW_FIRST_NEW_ID+12)
#define ITEMTREE_MENU_SELECT_ALL		(ID_TREEVIEW_FIRST_NEW_ID+13)
#define ITEMTREE_MENU_DESELECT_ALL	(ID_TREEVIEW_FIRST_NEW_ID+14)
#define ITEMTREE_MENU_FOLD					(ID_TREEVIEW_FIRST_NEW_ID+15)
#define ITEMTREE_MENU_UNFOLD				(ID_TREEVIEW_FIRST_NEW_ID+16)
#define ITEMTREE_MENU_HIDE					(ID_TREEVIEW_FIRST_NEW_ID+17)
#define ITEMTREE_MENU_UNHIDE				(ID_TREEVIEW_FIRST_NEW_ID+18)
#define ITEMTREE_MENU_UNHIDE_ALL		(ID_TREEVIEW_FIRST_NEW_ID+19)
#define ITEMTREE_MENU_HIDE_UNSELECTED	(ID_TREEVIEW_FIRST_NEW_ID+20)

#define ITEMTREE_MENU_CUSTOM				(ID_TREEVIEW_FIRST_NEW_ID+1000)


class ItemTreeNode;

class ItemTreeData : public CustomDataType
{
private:
	ItemTreeData();
	~ItemTreeData();
public:
	static ItemTreeData *Alloc();
	static void Free(ItemTreeData *&data);

	ItemTreeNode *AddItem(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, Bool aslast = true);
	ItemTreeNode *AddNode(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast = true);
	ItemTreeNodeData *GetNodeData(ItemTreeNode *node);

	ItemTreeNode *GetiNext(ItemTreeNode *node, ItemTreeNode *topnode = nullptr);
	ItemTreeNode *GetNext(ItemTreeNode *node);
	ItemTreeNode *GetPrev(ItemTreeNode *node);
	ItemTreeNode *GetUp(ItemTreeNode *node);
	ItemTreeNode *GetDown(ItemTreeNode *node);
	ItemTreeNode *GetRoot();
	ItemTreeNode *GetFirst();

	void Remove(ItemTreeNode *node);
	void FreeNode(ItemTreeNode *&node);
	void Insert(ItemTreeNode *node, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast = true);

	void SetOwner(BaseList2D *bl);
	BaseContainer *GetUserData();
	Int32 GetSelected(ItemTreeNode ***table, Bool children = true);

	ItemTreeNode *Find(UInt64 guid, ItemTreeNode *node = nullptr);
	ItemTreeNode *Find(UInt64 guid, Int32 id, Bool child = true, ItemTreeNode *node = nullptr);

	void ClearSelection();
	UInt64 GetSelectedID();
	void SetSelectedID(UInt64 guid);
	void SetSelected(ItemTreeNode *node);
	ItemTreeNode *GetFirstSelected();
	void AddToSelected(ItemTreeNode *node);

	void Reset();
	ItemTreeNodeIndex *BuildIndexTable(Int32 &tcnt, Bool sorted);

	Int32 GetClipCount();
	ItemTreeNode **GetClipArray();

	Int32 GetNodeTable(ItemTreeNode ***table);
	void RemoveSelected();

	UInt64 GetChecksum();
	void SortNames(BaseDocument *doc);

	void Validate(BaseDocument *doc);
	Bool CopyFrom(ItemTreeData *src);
};


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iItemTreeData;

struct CustomGuiItemTreeLib : public BaseCustomGuiLib
{
	ItemTreeData		*(*Alloc	)();
	void						(*Free		)(ItemTreeData *&pData);
	ItemTreeNode				*(iItemTreeData::*AddItem						)(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, Bool aslast);
	ItemTreeNode				*(iItemTreeData::*AddNode						)(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast);
	void								(iItemTreeData::*SetOwner						)(BaseList2D *bl);
	BaseContainer				*(iItemTreeData::*GetUserData				)();
	ItemTreeNodeData		*(iItemTreeData::*GetNodeData				)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetiNext					)(ItemTreeNode *node, ItemTreeNode *topnode);
	ItemTreeNode				*(iItemTreeData::*GetNext						)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetPrev						)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetUp							)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetDown						)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetRoot						)();
	ItemTreeNode				*(iItemTreeData::*GetFirst					)();
	void								(iItemTreeData::*Remove							)(ItemTreeNode *node);
	void								(iItemTreeData::*FreeNode						)(ItemTreeNode *&node);
	void								(iItemTreeData::*Insert							)(ItemTreeNode *node, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast);
	Int32								(iItemTreeData::*GetSelected				)(ItemTreeNode ***table, Bool children);
	ItemTreeNode				*(iItemTreeData::*Find							)(UInt64 guid, ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*FindID						)(UInt64 guid, Int32 id, Bool child, ItemTreeNode *node);
	void								(iItemTreeData::*ClearSelection			)();
	void								(iItemTreeData::*SetSelectedID			)(UInt64 guid);
	void								(iItemTreeData::*SetSelected				)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetFirstSelected	)();
	void								(iItemTreeData::*Reset							)();
	ItemTreeNodeIndex		*(iItemTreeData::*BuildIndexTable		)(Int32 &tcnt, Bool sorted);
	Int32								(iItemTreeData::*GetClipCount				)();
	ItemTreeNode				**(iItemTreeData::*GetClipArray			)();
	Int32								(iItemTreeData::*GetNodeTable				)(ItemTreeNode ***table);
	void								(iItemTreeData::*RemoveSelected			)();
	UInt64							(iItemTreeData::*GetChecksum				)();
	void								(iItemTreeData::*SortNames					)(BaseDocument *doc);
	UInt64							(iItemTreeData::*GetSelectedID			)();
	void								(iItemTreeData::*Validate						)(BaseDocument *doc);
	Bool								(iItemTreeData::*CopyFrom						)(ItemTreeData *src);

	Int32		(*itnodeGetID)(ItemTreeNode *iNode);
	Int32		(*itnodeGetFlags)(ItemTreeNode *iNode);

	void								(iItemTreeData::*AddToSelected			)(ItemTreeNode *node);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_ITEMTREE_H__
