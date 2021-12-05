#include "c4d_operatorplugin.h"
#include "lib_description.h"

////////////////////////////////

const String	GvOperatorData::GetDetailedText(GvNode *bn) { return String(); }
const String	GvOperatorData::GetText(GvNode *bn) { return String(); }
const String	GvOperatorData::GetTitle(GvNode *bn) { return String(); }
BaseBitmap*		GvOperatorData::GetPortIcon(GvNode *bn, Int32 id, GvLayoutType layout_type) { return nullptr; }
const Vector	GvOperatorData::GetBodyColor(GvNode *bn) { return C4DOS.Gv->globals->GetDefaultBodyColor(bn); }
void					GvOperatorData::GetBodySize(GvNode *bn, Int32 *width, Int32 *height) { C4DOS.Gv->globals->GetDefaultBodySize(width, height); }
void					GvOperatorData::EditorDraw(GvNode *bn, GvNodeGUI *gui, GeUserArea *da, Int32 x1, Int32 y1, Int32 x2, Int32 y2) { C4DOS.Gv->globals->OperatorDefaultDraw(bn, gui, da, x1, y1, x2, y2); }
Bool					GvOperatorData::GetOperatorDescription(GvNode *bn, GvOperatorDescription *od) { return false; }
Bool					GvOperatorData::QueryCalculation(GvNode *bn, GvQuery *query) { return true; }
Bool					GvOperatorData::InitCalculation(GvNode *bn, GvCalc *calc, GvRun *run) { return true; }
void					GvOperatorData::FreeCalculation(GvNode *bn, GvCalc *calc) { }
Bool					GvOperatorData::Calculate(GvNode *bn, GvPort *port, GvRun *run, GvCalc *calc) { return false; }
Bool					GvOperatorData::AddToCalculationTable(GvNode *bn, GvRun *run) { return false; }
Bool					GvOperatorData::SetRecalculate(GvNode *bn, GvPort *port, GvRun *r, Bool force_set) { return C4DOS.Gv->globals->DefaultSetRecalculate(bn, port, r, force_set); }
Bool					GvOperatorData::SetData(GvNode *bn, GvDataType type, void *data, GvOpSetDataMode mode) { return false; }
Bool					GvOperatorData::IsSetDataAllowed(GvNode *bn, GvDataType type, void *data, GvOpSetDataMode mode) { return false; }
Int32					GvOperatorData::FillPortMenu(GvNode *bn, BaseContainer& menu, Int32 port_id, Int32 first_menu_id) { return false; }
Bool					GvOperatorData::PortMenuCommand(GvNode *bn, Int32 menu_id, Int32 port_id, Int32 mx, Int32 my) { return false; }
Int32					GvOperatorData::FillOperatorMenu(GvNode *bn, BaseContainer& menu, Int32 first_menu_id) { return false; }
Bool					GvOperatorData::OperatorMenuCommand(GvNode *bn, Int32 menu_id, Int32 mx, Int32 my) { return false; }
Int32					GvOperatorData::FillPortsMenu(GvNode *bn, BaseContainer &names, BaseContainer &ids, GvValueID value_type, GvPortIO port, Int32 first_menu_id) { return C4DOS.Gv->globals->FillPortsMenu(bn, names, ids, value_type, port, first_menu_id); }
Bool					GvOperatorData::BodyMessage(GvNode *bn, GvNodeGUI *gui, Int32 x, Int32 y, Int32 chn, Int32 qua, const BaseContainer &msg) { return false; }
Bool					GvOperatorData::EditSettings(GvNode *bn, GvNodeGUI *gui) { return true; }
const String  GvOperatorData::GetErrorString(GvNode *bn, Int32 error) { return String::IntToString(error); }
Bool					GvOperatorData::SceneDraw(GvNode *bn, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, SCENEHOOKDRAW flags, void *data, UInt32 counter) { return false; }
Int32					GvOperatorData::GetMainID(GvNode *bn, GvPortIO io, const DescID &desc_id) { return GV_PORT_INVALID_ID; };
const DescID	GvOperatorData::GetDescID(GvNode *bn, GvPortIO io, Int32 main_id) { return DescID(); }
Bool					GvOperatorData::CreatePortDescriptionCache(GvNode *bn, Bool lock_only) { return true; }
void					GvOperatorData::FreePortDescriptionCache(GvNode *bn) { }


Bool GvOperatorData::Init(GeListNode *bn)
{
	return GetNode(bn) != nullptr;
}

Bool GvOperatorData::iCreateOperator(GvNode *bn)
{
	return C4DOS.Gv->node->CreateOperator(bn, 1);
}

void GvOperatorData::iGetPortList(GvNode *bn, GvPortIO port, GvPortList &portlist)
{
	C4DOS.Gv->node->GetPortList(bn, port, portlist, 1);
}

Bool GvOperatorData::iGetPortDescription(GvNode *bn, GvPortIO port, Int32 id, GvPortDescription *pd)
{
	return C4DOS.Gv->node->GetPortDescription(bn, port, id, pd, 1);
}

const DESCFLAGS_DESC		DESCFLAGS_DESC_SUPERCALL		= DESCFLAGS_DESC(1 << 31);
const DESCFLAGS_GET			DESCFLAGS_GET_SUPERCALL			= DESCFLAGS_GET(1 << 31);
const DESCFLAGS_SET			DESCFLAGS_SET_SUPERCALL			= DESCFLAGS_SET(1 << 31);
const DESCFLAGS_ENABLE	DESCFLAGS_ENABLE_SUPERCALL	= DESCFLAGS_ENABLE(1 << 31);

Bool GvOperatorData::GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &t_flags)
{
	DESCFLAGS_DESC flags = t_flags|DESCFLAGS_DESC_SUPERCALL;

	NodeData *data = node->GetNodeData<NodeData>();
	NODEPLUGIN* tab = (C4DOS.Bl->RetrieveTableX(data, 0));
	Bool res = (data->*tab->GetDDescription)(node, description, flags);

	t_flags = flags&~DESCFLAGS_DESC_SUPERCALL;
	return res;
}

Bool GvOperatorData::GetDEnabling(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE t_flags, const BaseContainer *itemdesc)
{
	DESCFLAGS_ENABLE flags = t_flags|DESCFLAGS_ENABLE_SUPERCALL;

	NodeData *data = node->GetNodeData<NodeData>();
	NODEPLUGIN* tab = (C4DOS.Bl->RetrieveTableX(data, 0));
	Bool res = (data->*tab->GetDEnabling)(node, id, t_data, flags, itemdesc);

	return res;
}

Bool GvOperatorData::GetDParameter(GeListNode *node, const DescID &id, GeData &t_data, DESCFLAGS_GET &t_flags)
{
	DESCFLAGS_GET flags = t_flags|DESCFLAGS_GET_SUPERCALL;

	NodeData *data = node->GetNodeData<NodeData>();
	NODEPLUGIN* tab = (C4DOS.Bl->RetrieveTableX(data, 0));
	Bool res = (data->*tab->GetDParameter)(node, id, t_data, flags);

	t_flags = flags&~DESCFLAGS_GET_SUPERCALL;
	return res;
}

Bool GvOperatorData::SetDParameter(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_SET &t_flags)
{
	DESCFLAGS_SET flags = t_flags|DESCFLAGS_SET_SUPERCALL;

	NodeData *data = node->GetNodeData<NodeData>();
	NODEPLUGIN* tab = (C4DOS.Bl->RetrieveTableX(data, 0));
	Bool res = (data->*tab->SetDParameter)(node, id, t_data, flags);

	t_flags = flags&~DESCFLAGS_SET_SUPERCALL;
	return res;
}

////////////////////////////////

Bool GvRegisterOperatorPlugin(GvOperatorID operator_id, const maxon::String &str, Int32 info, DataAllocator *at, const maxon::String &description, Int32 disklevel, GvOpClassID op_class, GvOpGroupID op_group, Int32 op_owner, BaseBitmap *icon)
{
	if (!C4DOS.Gv->globals || !C4DOS.Gv->globals->RegisterOperatorPlugin) return false;

	if (description.IsPopulated() && !RegisterDescription(operator_id, description)) return false;

	OPERATORPLUGIN ap;
	ClearMem(&ap, sizeof(ap));
	FillNodePlugin(&ap, info, at, nullptr, disklevel);

	ap.iCreateOperator						= &GvOperatorData::iCreateOperator;
	ap.GetDetailedText						= &GvOperatorData::GetDetailedText;
	ap.GetText										= &GvOperatorData::GetText;
	ap.GetTitle										= &GvOperatorData::GetTitle;
	ap.GetPortIcon								= &GvOperatorData::GetPortIcon;
	ap.GetBodySize								= &GvOperatorData::GetBodySize;
	ap.GetBodyColor								= &GvOperatorData::GetBodyColor;
	ap.EditorDraw									= &GvOperatorData::EditorDraw;
	ap.iGetPortList								= &GvOperatorData::iGetPortList;
	ap.iGetPortDescription				= &GvOperatorData::iGetPortDescription;
	ap.GetOperatorDescription			= &GvOperatorData::GetOperatorDescription;
	ap.QueryCalculation						= &GvOperatorData::QueryCalculation;
	ap.InitCalculation						= &GvOperatorData::InitCalculation;
	ap.FreeCalculation						= &GvOperatorData::FreeCalculation;
	ap.Calculate									= &GvOperatorData::Calculate;
	ap.AddToCalculationTable			= &GvOperatorData::AddToCalculationTable;
	ap.SetRecalculate							= &GvOperatorData::SetRecalculate;
	ap.SetData										= &GvOperatorData::SetData;
	ap.IsSetDataAllowed						= &GvOperatorData::IsSetDataAllowed;
	ap.FillPortMenu								= &GvOperatorData::FillPortMenu;
	ap.PortMenuCommand						= &GvOperatorData::PortMenuCommand;
	ap.FillOperatorMenu						= &GvOperatorData::FillOperatorMenu;
	ap.OperatorMenuCommand				= &GvOperatorData::OperatorMenuCommand;
	ap.FillPortsMenu							= &GvOperatorData::FillPortsMenu;
	ap.BodyMessage								= &GvOperatorData::BodyMessage;
	ap.EditSettings								= &GvOperatorData::EditSettings;
	ap.GetErrorString							= &GvOperatorData::GetErrorString;
	ap.SceneDraw									= &GvOperatorData::SceneDraw;
	ap.GetMainID									= &GvOperatorData::GetMainID;
	ap.GetDescID									= &GvOperatorData::GetDescID;
	ap.CreatePortDescriptionCache = &GvOperatorData::CreatePortDescriptionCache;
	ap.FreePortDescriptionCache		= &GvOperatorData::FreePortDescriptionCache;

	return C4DOS.Gv->globals->RegisterOperatorPlugin(operator_id, str, info, at, disklevel, op_class, op_group, op_owner, &ap, icon);
}

////////////////////////////////
