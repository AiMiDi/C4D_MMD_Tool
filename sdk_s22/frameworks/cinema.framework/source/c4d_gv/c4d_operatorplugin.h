/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_OPERATORPLUGIN_H__
#define C4D_OPERATORPLUGIN_H__

#include "ge_math.h"
#include "c4d_operatordata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct OPERATORPLUGIN : public NODEPLUGIN
{
	Int					op_group;
	Int					op_class;
	Int					op_owner;

	Bool					(GvOperatorData::*iCreateOperator							)(GvNode *bn);
	const String	(GvOperatorData::*GetDetailedText							)(GvNode *bn);
	const String	(GvOperatorData::*GetText											)(GvNode *bn);
	const String	(GvOperatorData::*GetTitle										)(GvNode *bn);
	BaseBitmap*		(GvOperatorData::*GetPortIcon									)(GvNode *bn, Int32 id, GvLayoutType layout_type);
	void					(GvOperatorData::*GetBodySize									)(GvNode *bn, Int32 *width, Int32 *height);
	const Vector	(GvOperatorData::*GetBodyColor								)(GvNode *bn);
	void					(GvOperatorData::*EditorDraw									)(GvNode *bn, GvNodeGUI* gui, GeUserArea *da, Int32 x1, Int32 y1, Int32 x2, Int32 y2);
	void					(GvOperatorData::*iGetPortList								)(GvNode *bn, GvPortIO port, GvPortList &portlist);
	Bool					(GvOperatorData::*iGetPortDescription					)(GvNode *bn, GvPortIO port, Int32 id, GvPortDescription *pd);
	Bool					(GvOperatorData::*GetOperatorDescription			)(GvNode *bn, GvOperatorDescription *od);
	Bool					(GvOperatorData::*QueryCalculation						)(GvNode *bn, GvQuery *query);
	Bool					(GvOperatorData::*InitCalculation							)(GvNode *bn, GvCalc *calc, GvRun *run);
	void					(GvOperatorData::*FreeCalculation							)(GvNode *bn, GvCalc *calc);
	Bool					(GvOperatorData::*Calculate										)(GvNode *bn, GvPort *port, GvRun *run, GvCalc *calc);
	Bool					(GvOperatorData::*AddToCalculationTable				)(GvNode *bn, GvRun *run);
	Bool					(GvOperatorData::*SetRecalculate							)(GvNode *bn, GvPort *port, GvRun *run, Bool force_set);
	Bool					(GvOperatorData::*SetData											)(GvNode *bn, GvDataType type, void *data, GvOpSetDataMode mode);
	Bool					(GvOperatorData::*IsSetDataAllowed						)(GvNode *bn, GvDataType type, void *data, GvOpSetDataMode mode);
	Int32					(GvOperatorData::*FillPortMenu								)(GvNode *bn, BaseContainer &menu, Int32 port_id, Int32 first_menu_id);
	Bool					(GvOperatorData::*PortMenuCommand							)(GvNode *bn, Int32 menu_id, Int32 port_id, Int32 mx, Int32 my);
	Int32					(GvOperatorData::*FillOperatorMenu						)(GvNode *bn, BaseContainer &menu, Int32 first_menu_id);
	Bool					(GvOperatorData::*OperatorMenuCommand					)(GvNode *bn, Int32 menu_id, Int32 mx, Int32 my);
	Int32					(GvOperatorData::*FillPortsMenu								)(GvNode *bn, BaseContainer &names, BaseContainer &ids, GvValueID value_type, GvPortIO port, Int32 first_menu_id);
	Bool					(GvOperatorData::*BodyMessage									)(GvNode *bn, GvNodeGUI *gui, Int32 x, Int32 y, Int32 chn, Int32 qua, const BaseContainer &msg);
	Bool					(GvOperatorData::*EditSettings								)(GvNode *bn, GvNodeGUI *gui);
	const String	(GvOperatorData::*GetErrorString							)(GvNode *bn, Int32 error);
	Bool					(GvOperatorData::*SceneDraw										)(GvNode *bn, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, SCENEHOOKDRAW flags, void *data, UInt32 counter);
	Int32					(GvOperatorData::*GetMainID										)(GvNode *bn, GvPortIO io, const DescID &desc_id);
	const DescID	(GvOperatorData::*GetDescID										)(GvNode *bn, GvPortIO io, Int32 main_id);
	Bool					(GvOperatorData::*CreatePortDescriptionCache	)(GvNode *bn, Bool lock_only);
	void					(GvOperatorData::*FreePortDescriptionCache		)(GvNode *bn);

	void* reserved[(64-32)*C4DPL_MEMBERMULTIPLIER-3];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_OPERATORPLUGIN_H__
