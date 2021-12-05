#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_listview.h"
#include "c4d_gui.h"




GeListView::GeListView(void)
{
	cd = nullptr;
	lv = (_GeListView*)C4DOS.Cu->GeListView_Alloc();
}

GeListView::~GeListView(void)
{
	C4DOS.Cu->GeListView_Free(lv);
	lv = nullptr;
	cd = nullptr;
}

void GeListView::LvCallBack(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1)
{
}

Int GeListView::LvCallBackLong(void* secret, Int32 cmd, Int32 line, Int32 col, void* data1)
{
	Int32 res_type = 0;
	void* result = nullptr;
	LvCallBack(res_type, result, secret, cmd, line, col, data1);
	if (res_type != LV_RES_INT)
		return 0;
	return (Int)result;
}

void GeListView::LvSuperCall(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col)
{
	C4DOS.Cu->GeListView_LvSuperCall(lv, res_type, result, secret, cmd, line, col);
}

void GeListView::Redraw(void)
{
	C4DOS.Cu->GeListView_Redraw(lv);
}

void GeListView::DataChanged(void)
{
	C4DOS.Cu->GeListView_DataChanged(lv);
}

Bool GeListView::ExtractMouseInfo(void* secret, MouseDownInfo& info, Int32 size)
{
	return C4DOS.Cu->GeListView_ExtractMouseInfo(lv, secret, info, size);
}
void GeListView::ShowCell(Int32 line, Int32 col)
{
	C4DOS.Cu->GeListView_ShowCell(lv, line, col);
}

Bool GeListView::ExtractDrawInfo(void* secret, DrawInfo& info, Int32 size)
{
	return C4DOS.Cu->GeListView_ExtractDrawInfo(lv, secret, info, size);
}

Bool GeListView::SendParentMessage(const BaseContainer& msg)
{
	return C4DOS.Cu->GeListView_SendParentMessage(lv, &msg);
}

Int32 GeListView::GetId(void)
{
	return C4DOS.Cu->GeListView_GetId(lv);
}

static void ListViewCallBackFunc(Int32& res_type, void*& result, void* userdata, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1)
{
	GeListView* lv = (GeListView*)userdata;
	if (lv)
		lv->LvCallBack(res_type, result, secret, cmd, line, col, data1);
}


Bool GeListView::AttachListView(GeDialog* dlg, Int32 id)
{
	return C4DOS.Cu->GeListView_Attach(lv, dlg->Get(), id, ListViewCallBackFunc, this);
}

SimpleListView::SimpleListView()
{
	// okay ... because the parent class allocates already a gelistview
	C4DOS.Cu->GeListView_Free(lv);
	lv = (_GeListView*)C4DOS.Cu->SimpleListView_Alloc();
}

SimpleListView::~SimpleListView()
{
}

Bool SimpleListView::SetLayout(Int32 columns, const BaseContainer& data)
{
	return C4DOS.Cu->SimpleListView_SetLayout((_SimpleListView*)lv, columns, data);
}

Bool SimpleListView::SetItem(Int32 id, const BaseContainer& data)
{
	return C4DOS.Cu->SimpleListView_SetItem((_SimpleListView*)lv, id, data);
}

Bool SimpleListView::GetItem(Int32 id, BaseContainer* data)
{
	return C4DOS.Cu->SimpleListView_GetItem((_SimpleListView*)lv, id, data);
}

Int32 SimpleListView::GetItemCount(void)
{
	return C4DOS.Cu->SimpleListView_GetItemCount((_SimpleListView*)lv);
}

Bool SimpleListView::GetItemLine(Int32 num, Int32* id, BaseContainer* data)
{
	return C4DOS.Cu->SimpleListView_GetItemLine((_SimpleListView*)lv, num, id, data);
}

Bool SimpleListView::RemoveItem(Int32 id)
{
	return C4DOS.Cu->SimpleListView_RemoveItem((_SimpleListView*)lv, id);
}

void SimpleListView::LvCallBack(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1)
{
}

Int32 SimpleListView::GetSelection(BaseSelect* selection)
{
	return C4DOS.Cu->SimpleListView_GetSelection((_SimpleListView*)lv, selection);
}

Bool SimpleListView::SetSelection(BaseSelect* selection)
{
	return C4DOS.Cu->SimpleListView_SetSelection((_SimpleListView*)lv, selection);
}

Bool SimpleListView::SetProperty(Int32 id, Int32 val)
{
	return C4DOS.Cu->SimpleListView_SetProperty((_SimpleListView*)lv, id, val);
}

Int32 SimpleListView::GetProperty(Int32 id)
{
	return C4DOS.Cu->SimpleListView_GetProperty((_SimpleListView*)lv, id);
}

void SimpleListView::ShowCell(Int32 line, Int32 col)
{
	return C4DOS.Cu->SimpleListView_ShowCell((_SimpleListView*)lv, line, col);
}
