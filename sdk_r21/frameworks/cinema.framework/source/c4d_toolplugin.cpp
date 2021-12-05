#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_toolplugin.h"
#include "c4d_basebitmap.h"
#include "c4d_general.h"
#include "c4d_resource.h"

Bool ToolData::InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt)
{
	return true;
}

void ToolData::FreeTool(BaseDocument* doc, BaseContainer& data)
{
}

Bool ToolData::DoCommand(ModelingCommandData& mdat)
{
	return false;
}

void ToolData::InitDefaultSettings(BaseDocument* pDoc, BaseContainer& data)
{
}

const String ToolData::GetResourceSymbol()
{
	return String();
}

Bool ToolData::MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	return true;
}

Bool ToolData::KeyboardInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	return false;
}

Int32 ToolData::GetState(BaseDocument* doc)
{
	return CMD_ENABLED;
}

Bool ToolData::GetCursorInfo(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc)
{
	return false;
}

TOOLDRAW ToolData::Draw(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, TOOLDRAWFLAGS flags)
{
	return TOOLDRAW::AXIS;
}

CDialog* ToolData::AllocDialog(BaseContainer* bc, CDialog* cd_parent, Int32 dlg_id)
{
	if (!cd_parent)
		return nullptr;
	SubDialog* dlg = AllocSubDialog(bc);
	if (!dlg)
		return nullptr;
	C4DOS.Cd->AttachSubDialog(cd_parent, dlg_id, dlg->Get());
	return dlg->Get();
}

void ToolData::FreeDialog(CDialog* cd)
{
	SubDialog* dlg = (SubDialog*)C4DOS.Cd->GetUserData(cd);
	DeleteObj(dlg);
}

Bool ToolData::InitDisplayControl(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active)
{
	return false;
}

void ToolData::FreeDisplayControl(void)
{
}

Bool ToolData::DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
{
	return true;
}

SubDialog* ToolData::AllocSubDialog(BaseContainer* bc)
{
	return nullptr;
}

Bool ToolData::GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags)
{
	return false;
}

Bool ToolData::TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	return false;
}

Bool ToolData::GetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags)
{
	if (flags & DESCFLAGS_GET::PARAM_GET)
		return true;
	return false;
}

Bool ToolData::GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	return true;
}

Bool ToolData::SetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (flags & DESCFLAGS_SET::PARAM_SET)
		return true;
	return false;
}

Bool ToolData::Message(BaseDocument* doc, BaseContainer& data, Int32 type, void* t_data)
{
	return false;
}

BaseContainer* GetToolData(BaseDocument* doc, Int32 pluginid)
{
	return C4DOS.Ge->GetToolData(doc, pluginid);
}

Float GetToolScale(BaseDraw* bd, AtomArray* arr, Int32 all, Int32 mode)
{
	return C4DOS.Ge->GetToolScale(bd, arr, all, mode);
}

class ToolNodeData : public NodeData
{
public:
	static NodeData *Alloc(void) { return NewObjClear(NodeData); }
};

Bool RegisterToolPlugin(Int32 id, const maxon::String& str, Int32 info, BaseBitmap* icon, const maxon::String& help, ToolData* dat)
{
	if (!dat)
		return false;

	TOOLPLUGIN np;
	ClearMem(&np, sizeof(np));

	const String description = dat->GetResourceSymbol();

	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	np.adr	= dat;
	np.help	= (String*)&help;
	np.command_icon	= icon;
	np.info	= info;

	np.Destructor	= &ToolData::Destructor;
	np.MouseInput	= &ToolData::MouseInput;
	np.KeyboardInput = &ToolData::KeyboardInput;
	np.GetState	= &ToolData::GetState;
	np.GetCursorInfo = &ToolData::GetCursorInfo;
	np.Draw	= &ToolData::Draw;
	np.AllocDialog = &ToolData::AllocDialog;
	np.FreeDialog	 = &ToolData::FreeDialog;
	np.InitTool	= &ToolData::InitTool;
	np.FreeTool	= &ToolData::FreeTool;
	np.InitDisplayControl = &ToolData::InitDisplayControl;
	np.FreeDisplayControl = &ToolData::FreeDisplayControl;
	np.DisplayControl	= &ToolData::DisplayControl;

	np.GetDDescription = &ToolData::GetDDescription;
	np.GetDParameter = &ToolData::GetDParameter;
	np.GetDEnabling	 = &ToolData::GetDEnabling;
	np.SetDParameter = &ToolData::SetDParameter;
	np.Message = &ToolData::Message;
	np.InitDefaultSettings = &ToolData::InitDefaultSettings;
	np.DoCommand = &ToolData::DoCommand;
	np.GetResourceSymbol = &ToolData::GetResourceSymbol;
	np.TranslateDescID = &ToolData::TranslateDescID;

	if (!GeRegisterPlugin(PLUGINTYPE::TOOL, id, str, &np, sizeof(np)))
		return false;

	return RegisterNodePlugin(id, str, info|PLUGINFLAG_HIDEPLUGINMENU|PLUGINFLAG_HIDE, ToolNodeData::Alloc, icon, 0, nullptr);
}

void EditorWindow::DrawXORLine(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	C4DOS.Ge->EwDrawXORLine(this, x1, y1, x2, y2);
}

void EditorWindow::MouseDragStart(Int32 button, Float mx, Float my, MOUSEDRAGFLAGS flag)
{
	C4DOS.Ge->EwMouseDragStart(this, button, mx, my, flag);
}

MOUSEDRAGRESULT EditorWindow::MouseDrag(Float* mx, Float* my, BaseContainer* channels)
{
	return C4DOS.Ge->EwMouseDrag(this, mx, my, channels);
}

MOUSEDRAGRESULT EditorWindow::MouseDragEnd(void)
{
	return C4DOS.Ge->EwMouseDragEnd(this);
}

Bool EditorWindow::BfGetInputState(Int32 askdevice, Int32 askchannel, BaseContainer* res)
{
	return C4DOS.Ge->EwBfGetInputState(this, askdevice, askchannel, res);
}

Bool EditorWindow::BfGetInputEvent(Int32 askdevice, BaseContainer* res)
{
	return C4DOS.Ge->EwBfGetInputEvent(this, askdevice, res);
}

HOTKEYFLAGS EditorWindow::IsHotkeyDown(Int32 id)
{
	return C4DOS.Ge->EwBfIsHotkeyDown(this, id);
}

void EditorWindow::StatusSetText(const maxon::String& str)
{
	C4DOS.Ge->StatusSetText(str);
}

Bool EditorWindow::Screen2Local(Int32* x, Int32* y)
{
	return C4DOS.Ge->EWScreen2Local(this, x, y);
}

Bool EditorWindow::Local2Screen(Int32* x, Int32* y)
{
	return C4DOS.Ge->EWLocal2Screen(this, x, y);
}

Bool EditorWindow::Global2Local(Int32* x, Int32* y)
{
	return C4DOS.Ge->EWGlobal2Local(this, x, y);
}

Bool EditorWindow::Local2Global(Int32* x, Int32* y)
{
	return C4DOS.Ge->EWLocal2Global(this, x, y);
}

