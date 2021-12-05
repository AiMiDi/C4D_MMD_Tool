#include "customgui_listview.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "c4d_general.h"

TreeViewLib *lib_tree = nullptr;

static TreeViewLib *CheckListview(Int32 offset)
{
	return (TreeViewLib*)CheckLib(CUSTOMGUI_TREEVIEW, offset, (C4DLibrary**)&lib_tree);
}

#define TreeViewGuiCall(b) 		TreeViewLib *lib = CheckListview(LIBOFFSET(TreeViewLib, b)); \
															if (!lib || !lib->b) return; \
															(((iTreeViewCustomGui*)this)->*lib->b)

#define TreeViewGuiCallR(a, b) TreeViewLib *lib = CheckListview(LIBOFFSET(TreeViewLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iTreeViewCustomGui*)this)->*lib->b)

static TreeViewLib *CheckListViewLib(Int32 offset)
{
	return (TreeViewLib*)CheckLib(CUSTOMGUI_TREEVIEW, offset, (C4DLibrary**)&lib_tree);
}

// Navigation Functions
void*  TreeViewF::GetFirst(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ return pFuncs->GetFirst(root, userdata); }

void*  TreeViewF::GetDown(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->GetDown(root, userdata, obj); }

void*  TreeViewF::GetNext(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->GetNext(root, userdata, obj); }

void*  TreeViewF::GetPred(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->GetPred(root, userdata, obj); }

// Layout&Draw functions
Int32   TreeViewF::GetColumnWidth(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, GeUserArea* area)
{ return pFuncs->GetColumnWidth(root, userdata, obj, col, area); }

Int32   TreeViewF::GetHeaderColumnWidth(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 col, GeUserArea* area)
{ return pFuncs->GetHeaderColumnWidth(root, userdata, col, area); }

Int32   TreeViewF::GetMinHeaderHeight(TreeViewFunctions* pFuncs, void *root, void *userdata, GeUserArea* area)
{ return pFuncs->GetMinHeaderHeight(root, userdata, area); }

Int32   TreeViewF::GetLineHeight(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, GeUserArea* area)
{ return pFuncs->GetLineHeight(root, userdata, obj, col, area); }

void   TreeViewF::GetColors(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, GeData* pNormal, GeData* pSelected)
{ pFuncs->GetColors(root, userdata, obj, pNormal, pSelected); }

void   TreeViewF::GetBackgroundColor(TreeViewFunctions* pFuncs, void* root, void* userdata, void* obj, Int32 line, GeData* col)
{ pFuncs->GetBackgroundColor(root, userdata, obj, line, col); }

void   TreeViewF::DrawCell(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, DrawInfo *drawinfo, const GeData &bgColor)
{ pFuncs->DrawCell(root, userdata, obj, col, drawinfo, bgColor); }

Bool   TreeViewF::DrawHeaderCell(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 col, DrawInfo *drawinfo)
{ return pFuncs->DrawHeaderCell(root, userdata, col, drawinfo); }

// Get Functions
Bool   TreeViewF::IsSelected(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->IsSelected(root, userdata, obj); }

Bool   TreeViewF::IsOpened(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->IsOpened(root, userdata, obj); }

String TreeViewF::GetName(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->GetName(root, userdata, obj); }

Int  TreeViewF::GetId(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->GetId(root, userdata, obj); }

Int32   TreeViewF::GetDragType(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->GetDragType(root, userdata, obj); }

Int32   TreeViewF::DragStart(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ return pFuncs->DragStart(root, userdata, obj); }

Int32		TreeViewF::IsChecked(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn)
{ return pFuncs->IsChecked(root, userdata, obj, lColumn); }

Bool   TreeViewF::IsTristate(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ return pFuncs->IsTristate(root, userdata); }

// Set Functions
void   TreeViewF::Open(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Bool onoff)
{ pFuncs->Open(root, userdata, obj, onoff); }

void   TreeViewF::SetName(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, const maxon::String &str)
{ pFuncs->SetName(root, userdata, obj, str); }

void   TreeViewF::Select(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 mode)
{ pFuncs->Select(root, userdata, obj, mode); }

Int32   TreeViewF::AcceptDragObject(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Bool &bAllowCopy)
{ return pFuncs->AcceptDragObject(root, userdata, obj, dragtype, dragobject, bAllowCopy); }

void   TreeViewF::InsertObject(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Int32 insertmode, Bool bCopy)
{ pFuncs->InsertObject(root, userdata, obj, dragtype, dragobject, insertmode, bCopy); }

void		TreeViewF::SetCheck(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Bool bCheck, const BaseContainer& bcMsg)
{ pFuncs->SetCheck(root, userdata, obj, lColumn, bCheck, bcMsg); }

// GUI and Drag&Drop
void   TreeViewF::CreateContextMenu(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, BaseContainer* bc)
{ pFuncs->CreateContextMenu(root, userdata, obj, lColumn, bc); }

void   TreeViewF::SetDragObject(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj)
{ pFuncs->SetDragObject(root, userdata, obj); }

void   TreeViewF::GenerateDragArray(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, AtomArray* ar)
{ pFuncs->GenerateDragArray(root, userdata, obj, ar); }

void   TreeViewF::GenerateDragData(TreeViewFunctions* pFuncs, void *root, void *userdata, void* obj, void **dragdata)
{ pFuncs->GenerateDragData(root, userdata, obj, dragdata); }

void   TreeViewF::FreeDragData(TreeViewFunctions* pFuncs, void *root, void *userdata, void *dragdata)
{ pFuncs->FreeDragData(root, userdata, dragdata); }

Int32   TreeViewF::GetHeaderSortArrow(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID)
{ return pFuncs->GetHeaderSortArrow(root, userdata, lColID); }

Bool   TreeViewF::IsResizeColAllowed(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID)
{ return pFuncs->IsResizeColAllowed(root, userdata, lColID); }

Bool   TreeViewF::IsMoveColAllowed(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID)
{ return pFuncs->IsMoveColAllowed(root, userdata, lColID); }

Bool		TreeViewF::InputEvent(TreeViewFunctions* pFuncs, void* root, void* userdata, GeUserArea* pArea, const BaseContainer &msg)
{ return pFuncs->InputEvent(root, userdata, pArea, msg); }

Bool   TreeViewF::MouseDown(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo, Bool rightButton)
{ return pFuncs->MouseDown(root, userdata, obj, col, mouseinfo, rightButton); }

Int32  TreeViewF::DoubleClick(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo)
{ return pFuncs->DoubleClick(root, userdata, obj, col, mouseinfo); }

void   TreeViewF::DeletePressed(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ pFuncs->DeletePressed(root, userdata); }

// notifications
void		TreeViewF::Scrolled(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 h, Int32 v, Int32 x, Int32 y)
{ pFuncs->Scrolled(root, userdata, h, v, x, y); }

void		TreeViewF::PaintFinished(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ pFuncs->PaintFinished(root, userdata); }

Bool   TreeViewF::ColumnMoved(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID, Int32 lInsertBeforeColIndex, Int32* plIndexMap, const BaseContainer* pbcLayout)
{ return pFuncs->ColumnMoved(root, userdata, lColID, lInsertBeforeColIndex, plIndexMap, pbcLayout); }

void   TreeViewF::SelectionChanged(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ pFuncs->SelectionChanged(root, userdata); }

Bool TreeViewF::HeaderClick(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID, Int32 lChannel, Bool bDbl, Int32 mouseX, Int32 mouseY, GeUserArea* ua)
{ return pFuncs->HeaderClick(root, userdata, lColID, lChannel, bDbl, mouseX, mouseY, ua); }

Bool   TreeViewF::ContextMenuCall(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Int32 lCommand)
{
	if (lCommand == ID_TREEVIEW_CONTEXT_REMOVE)
	{
		DeletePressed(pFuncs, root, userdata);
		return true;
	}
	return pFuncs->ContextMenuCall(root, userdata, obj, lColumn, lCommand);
}

void TreeViewF::InitCache(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ pFuncs->InitCache(root, userdata); }

Bool TreeViewF::PythonCleanup(TreeViewFunctions* pFuncs, void *root, void *userdata)
{ return pFuncs->PythonCleanup(root, userdata); }

void TreeViewF::GetDropDownMenu(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, TreeViewDropDownMenuInfo* menuInfo)
{
	pFuncs->GetDropDownMenu(root, userdata, obj, lColumn, menuInfo);
}

void TreeViewF::SetDropDownMenu(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Int32 entry)
{
	pFuncs->SetDropDownMenu(root, userdata, obj, lColumn, entry);
}

void TreeViewF::GetFloatValue(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, TreeViewFloatSliderInfo* sliderInfo)
{
	pFuncs->GetFloatValue(root, userdata, obj, lColumn, sliderInfo);
}

void TreeViewF::SetFloatValueEx(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Float value)
{
	pFuncs->SetFloatValue(root, userdata, obj, lColumn, value, false);
}

void TreeViewF::SetFloatValue(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Float value, Bool finalValue)
{
	pFuncs->SetFloatValue(root, userdata, obj, lColumn, value, finalValue);
}

Bool TreeViewF::AddRow(TreeViewFunctions* pFuncs, void* root, void* userdata)
{
	return pFuncs->AddRow(root, userdata);
}

String TreeViewF::EmptyText(TreeViewFunctions* pFuncs, void* root, void* userdata)
{
	return pFuncs->EmptyText(root, userdata);
}

String TreeViewF::GetBubbleHelp(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, CellInfo* info)
{
	return pFuncs->GetBubbleHelp(root, userdata, obj, col, info);
}

// may not be a member of TreeViewCustomGui, an internal copy is created
InternalFunctionTable TreeViewInternalFunctionTable;
TreeViewF TreeViewControlFunctions;

Bool TreeViewCustomGui::SetRoot(void *root, TreeViewFunctions *functions, void *userdata)
{
	TreeViewLib *lib = CheckListViewLib(LIBOFFSET(TreeViewLib, SetRoot));
	if (!lib || !lib->SetRoot) return false;

	InternalFunctionTable* f = &TreeViewInternalFunctionTable;
	ClearMem(f, sizeof(InternalFunctionTable), 0);

	f->GetFirst            = &TreeViewF::GetFirst;
	f->GetDown             = &TreeViewF::GetDown;
	f->GetNext             = &TreeViewF::GetNext;
	f->GetPred             = &TreeViewF::GetPred;
	f->GetColumnWidth      = &TreeViewF::GetColumnWidth;
	f->GetHeaderColumnWidth = &TreeViewF::GetHeaderColumnWidth;
	f->GetLineHeight       = &TreeViewF::GetLineHeight;
	f->DrawCell            = &TreeViewF::DrawCell;
	f->DrawHeaderCell      = &TreeViewF::DrawHeaderCell;
	f->IsSelected          = &TreeViewF::IsSelected;
	f->IsOpened            = &TreeViewF::IsOpened;
	f->GetName             = &TreeViewF::GetName;
	f->GetId               = &TreeViewF::GetId;
	f->GetDragType         = &TreeViewF::GetDragType;
	f->DragStart	         = &TreeViewF::DragStart;
	f->GetColors           = &TreeViewF::GetColors;
	f->GetBackgroundColor  = &TreeViewF::GetBackgroundColor;
	f->GetMinHeaderHeight  = &TreeViewF::GetMinHeaderHeight;
	f->IsChecked           = &TreeViewF::IsChecked;
	f->CreateContextMenu   = &TreeViewF::CreateContextMenu;
	f->ContextMenuCall     = &TreeViewF::ContextMenuCall;
	f->IsTristate          = &TreeViewF::IsTristate;
	f->Open                = &TreeViewF::Open;
	f->Select              = &TreeViewF::Select;
	f->AcceptDragObject    = &TreeViewF::AcceptDragObject;
	f->InsertObject        = &TreeViewF::InsertObject;
	f->SetCheck            = &TreeViewF::SetCheck;
	f->SetName             = &TreeViewF::SetName;
	f->SetDragObject       = &TreeViewF::SetDragObject;
	f->GenerateDragArray   = &TreeViewF::GenerateDragArray;
	f->MouseDown           = &TreeViewF::MouseDown;
	f->DoubleClick         = &TreeViewF::DoubleClick;
	f->DeletePressed       = &TreeViewF::DeletePressed;
	f->SelectionChanged    = &TreeViewF::SelectionChanged;
	f->GetHeaderSortArrow  = &TreeViewF::GetHeaderSortArrow;
	f->HeaderClick         = &TreeViewF::HeaderClick;
	f->IsResizeColAllowed  = &TreeViewF::IsResizeColAllowed;
	f->IsMoveColAllowed    = &TreeViewF::IsMoveColAllowed;
	f->ColumnMoved         = &TreeViewF::ColumnMoved;
	f->GenerateDragData    = &TreeViewF::GenerateDragData;
	f->FreeDragData        = &TreeViewF::FreeDragData;
	f->InitCache					 = &TreeViewF::InitCache;
	f->InputEvent					 = &TreeViewF::InputEvent;
	f->GetTableSize        = &TreeViewF::GetTableSize;
	f->Scrolled            = &TreeViewF::Scrolled;
	f->PaintFinished       = &TreeViewF::PaintFinished;
	f->PythonCleanup       = &TreeViewF::PythonCleanup;
	f->GetDropDownMenu	 	 = &TreeViewF::GetDropDownMenu;
	f->SetDropDownMenu		 = &TreeViewF::SetDropDownMenu;
	f->GetFloatValue			 = &TreeViewF::GetFloatValue;
	f->SetFloatValue			 = &TreeViewF::SetFloatValue;
	f->AddRow							 = &TreeViewF::AddRow;
	f->EmptyText					 = &TreeViewF::EmptyText;
	f->GetBubbleHelp			 = &TreeViewF::GetBubbleHelp;

	return (((iTreeViewCustomGui*)this)->*lib->SetRoot)(root, f, userdata, sizeof(InternalFunctionTable), &TreeViewControlFunctions, functions);
}

void TreeViewCustomGui::Refresh()
{
	TreeViewGuiCall(Refresh)();
	return;
}

Bool TreeViewCustomGui::SetLayout(Int32 columns, const BaseContainer &data)
{
	TreeViewGuiCallR(false, SetLayout)(columns, data);
}

Bool TreeViewCustomGui::SetHeaderText(Int32 lColumnID, const maxon::String &str)
{
	TreeViewGuiCallR(false, SetHeaderText)(lColumnID, str);
}

GeUserArea* TreeViewCustomGui::GetTreeViewArea()
{
	TreeViewGuiCallR(nullptr, GetTreeViewArea)();
}

GeUserArea* TreeViewCustomGui::GetHeaderArea()
{
	TreeViewGuiCallR(nullptr, GetHeaderArea)();
}

Int32 TreeViewCustomGui::GetAutoColumnWidth(Int32 lColID)
{
	TreeViewGuiCallR(0, GetAutoColumnWidth)(lColID);
}

Int32 TreeViewCustomGui::GetColumnWidthUser(Int32 lColID)
{
	TreeViewGuiCallR(0, GetColumnWidthUser)(lColID);
}

Int32 TreeViewCustomGui::GetRealColumnWidth(Int32 lColID)
{
	TreeViewGuiCallR(0, GetRealColumnWidth)(lColID);
}

Bool TreeViewCustomGui::SetColumnWidthUser(Int32 lColID, Int32 lWidth)
{
	TreeViewGuiCallR(false, SetColumnWidthUser)(lColID, lWidth);
}

Bool TreeViewCustomGui::MakeVisible(void* pObj)
{
	TreeViewGuiCallR(false, MakeVisible)(pObj);
}

Bool TreeViewCustomGui::GetCellPosition(void* pObj, Int32 lColID, GeUserArea *&pArea, Int32 &x, Int32 &y, Int32 &w, Int32 &h, Int32 &lTextOffset)
{
	TreeViewGuiCallR(false, GetCellPosition)(pObj, lColID, pArea, x, y, w, h, lTextOffset);
}

Bool TreeViewCustomGui::GetVisibleScrollArea(Int32& x1, Int32& y1, Int32& x2, Int32& y2)
{
	TreeViewGuiCallR(false, GetVisibleScrollArea)(x1, y1, x2, y2);
}

Bool TreeViewCustomGui::SetVisibleScrollArea(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	TreeViewGuiCallR(false, SetVisibleScrollArea)(x1, y1, x2, y2);
}

Int32 TreeViewCustomGui::GetVisibleLineCount()
{
	TreeViewGuiCallR(0, GetVisibleLineCount)();
}

Bool TreeViewCustomGui::IsFocusItem(void* pObj)
{
	TreeViewGuiCallR(false, IsFocusItem)(pObj);
}

Bool TreeViewCustomGui::ShowObject(void* pObj)
{
	TreeViewGuiCallR(false, ShowObject)(pObj);
}

void* TreeViewCustomGui::GetFocusItem()
{
	TreeViewGuiCallR(nullptr, GetFocusItem)();
}

void TreeViewCustomGui::SetFocusItem(void* pItem)
{
	TreeViewGuiCall(SetFocusItem)(pItem);
}

void* TreeViewCustomGui::GetSelectionItem()
{
	TreeViewGuiCallR(nullptr, GetSelectionItem)();
}

void TreeViewCustomGui::SetSelectionItem(void* pItem)
{
	TreeViewGuiCall(SetSelectionItem)(pItem);
}

void* TreeViewCustomGui::GetObject(Int32 line, Int32 *level)
{
	TreeViewGuiCallR(nullptr, GetObject)(line, level);
}

const BaseContainer* TreeViewCustomGui::GetLayout()
{
	TreeViewGuiCallR(nullptr, GetLayout)();
}


void*	TreeViewFunctions::GetPred(void *root, void *userdata, void *obj)
{
	return nullptr;
}

Int32 TreeViewFunctions::GetColumnWidth(void *root, void *userdata, void *obj, Int32 col, GeUserArea* area)
{
	return 0;
}

Int32 TreeViewFunctions::GetHeaderColumnWidth(void *root, void *userdata, Int32 col, GeUserArea* area)
{
	return -1;
}

Int32 TreeViewFunctions::GetLineHeight(void *root, void *userdata, void *obj, Int32 col, GeUserArea* area)
{
	return 0;
}

void TreeViewFunctions::DrawCell(void *root, void *userdata, void *obj, Int32 col, DrawInfo *drawinfo, const GeData& bgColor)
{
}

Bool TreeViewFunctions::DrawHeaderCell(void *root, void *userdata, Int32 col, DrawInfo *drawinfo)
{
	// let the tree view draw its header
	return false;
}

Int32 TreeViewFunctions::DragStart(void *root, void *userdata, void *obj)
{
	return TREEVIEW_DRAGSTART_ALLOW | TREEVIEW_DRAGSTART_SELECT;
}

void TreeViewFunctions::GetColors(void *root, void *userdata, void *obj, GeData* pNormal, GeData* pSelected)
{
}

void TreeViewFunctions::GetBackgroundColor(void* root, void* userdata, void* obj, Int32 line, GeData* col)
{
}

Int32 TreeViewFunctions::GetMinHeaderHeight(void *root, void *userdata, GeUserArea* area)
{
	return -1;
}

void TreeViewFunctions::Open(void *root, void *userdata, void *obj, Bool onoff)
{
}

void TreeViewFunctions::Select(void *root, void *userdata, void *obj, Int32 mode)
{
}

Int32 TreeViewFunctions::AcceptDragObject(void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Bool &bAllowCopy)
{
	return 0;
}

void TreeViewFunctions::InsertObject(void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Int32 insertmode, Bool bCopy)
{
}

void TreeViewFunctions::SetName(void *root, void *userdata, void *obj, const maxon::String &str)
{
}

void TreeViewFunctions::SetDragObject(void *root, void *userdata, void *obj)
{
}

void TreeViewFunctions::GenerateDragArray(void *root, void *userdata, void *obj, AtomArray* ar)
{
}

Bool TreeViewFunctions::MouseDown(void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo, Bool rightButton)
{
	return false;
}

Int32 TreeViewFunctions::DoubleClick(void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo)
{
	return false;
}

void TreeViewFunctions::DeletePressed(void *root, void *userdata)
{
}

void TreeViewFunctions::SelectionChanged(void *root, void *userdata)
{
}

Int32 TreeViewFunctions::GetHeaderSortArrow(void *root, void *userdata, Int32 lColID)
{
	return 0;
}

void TreeViewFunctions::CreateContextMenu(void *root, void *userdata, void *obj, Int32 lColumn, BaseContainer* bc)
{
}

Bool TreeViewFunctions::ContextMenuCall(void *root, void *userdata, void *obj, Int32 lColumn, Int32 lCommand)
{
	return false;
}

Bool TreeViewFunctions::IsTristate(void *root, void *userdata)
{
	return false;
}

Bool TreeViewFunctions::HeaderClick(void *root, void *userdata, Int32 lColID, Int32 lChannel, Bool bDblClk, Int32 mouseX, Int32 mouseY, GeUserArea* ua)
{
	return false;
}

Bool TreeViewFunctions::IsResizeColAllowed(void *root, void *userdata, Int32 lColID)
{
	return true;
}

Bool TreeViewFunctions::IsMoveColAllowed(void *root, void *userdata, Int32 lColID)
{
	return true;
}

Bool TreeViewFunctions::ColumnMoved(void *root, void *userdata, Int32 lColID, Int32 lInsertBeforeCol, Int32* plIndexMap, const BaseContainer* pbcLayout)
{
	return true;
}

void TreeViewFunctions::GenerateDragData(void *root, void *userdata, void* obj, void **dragdata)
{
}

void TreeViewFunctions::FreeDragData(void *root, void *userdata, void *dragdata)
{
}

Int32 TreeViewFunctions::IsChecked(void *root, void *userdata, void *obj, Int32 lColumn)
{
	return 0;
}

void TreeViewFunctions::SetCheck(void *root, void *userdata, void *obj, Int32 lColumn, Bool bCheck, const BaseContainer& bcMsg)
{
}

void TreeViewFunctions::Scrolled(void *root, void *userdata, Int32 h, Int32 v, Int32 x, Int32 y)
{
}

void TreeViewFunctions::PaintFinished(void *root, void *userdata)
{
}

void TreeViewFunctions::InitCache(void *root, void *userdata)
{
}

Bool TreeViewFunctions::PythonCleanup(void *root, void *userdata)
{
	return false;
}

void TreeViewFunctions::GetDropDownMenu(void *root, void *userdata, void *obj, Int32 lColumn, TreeViewDropDownMenuInfo* menuInfo)
{
}

void TreeViewFunctions::SetDropDownMenu(void *root, void *userdata, void *obj, Int32 lColumn, Int32 entry)
{
}

void TreeViewFunctions::GetFloatValue(void *root, void *userdata, void *obj, Int32 lColumn, TreeViewFloatSliderInfo* sliderInfo)
{
}

void TreeViewFunctions::SetFloatValueEx(void *root, void *userdata, void *obj, Int32 lColumn, Float value)
{
}

void TreeViewFunctions::SetFloatValue(void *root, void *userdata, void *obj, Int32 lColumn, Float value, Bool finalValue)
{
}

Bool TreeViewFunctions::AddRow(void* root, void* userdata)
{
	return false;
}

String TreeViewFunctions::EmptyText(void* root, void* userdata)
{
	return "";
}

String TreeViewFunctions::GetBubbleHelp(void* root, void* userdata, void* obj, Int32 col, CellInfo* info)
{
	return "";
}

Bool TreeViewFunctions::InputEvent(void* root, void* userdata, GeUserArea* pArea, const BaseContainer &msg)
{
	return true;
}

Bool TreeViewFunctions::VisitChildren(void* root, void* obj, VisitChildrenCallback fn, void* userdata, void* data1, void* data2)
{
	Bool b;
	b = true;

	if (obj != root)
	{
		if (!fn(root, obj, userdata, data1, data2, b)) return false;
	}

	void* n;
	if (obj == root)
		n = GetFirst(root, userdata);
	else
		n = GetDown(root, userdata, obj);

	while (n && b)
	{
		if (!VisitChildren(root, n, fn, userdata, data1, data2)) return false;
		n = GetNext(root, userdata, n);
	}

	return true;
}
