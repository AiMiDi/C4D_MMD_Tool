#include "c4d_graphview.h"
#include "c4d_operatordata.h"
#include "c4d_particles.h"

////////////////////////////////

const String GvGetOperatorDetailedText(GvOperatorData *op, GvNode *bn)
{
	String text = op->GetText(bn);
	if (text.IsPopulated()) text = String(" (") + text + String(")");
	return bn->GetTitle() + text;
}

const String GvGetOperatorTitle(GvNode *bn, Int32 string_id)
{
	String title = bn->GetName(); return title.IsPopulated() ? title : GeLoadString(string_id);
}

////////////////////////////////

Bool GvGetPortDescription(GvPortsDescInfo *info, GvPortIO port, Int32 id, GvPortDescription *pd)
{
	if (info)
	{
		if (port == GV_PORT_INPUT || port == GV_PORT_INPUT_OR_GEDATA)
		{
			for (const auto& p : info->in._portInfo)
			{
				if (p.id == id)
				{
					pd->name = p.name;
					pd->data_id = p.type;
					pd->flags = (GvPortDescFlags)p.flag;
					pd->parent_id = GV_PORT_INVALID_ID;
					return true;
				}
			}
		}
		else if (port == GV_PORT_OUTPUT)
		{
			for (const auto& p : info->out._portInfo)
			{
				if (p.id == id)
				{
					pd->name = p.name;
					pd->data_id = p.type;
					pd->flags = (GvPortDescFlags)p.flag;
					pd->parent_id = GV_PORT_INVALID_ID;
					return true;
				}
			}
		}
	}
	return false;
}

////////////////////////////////

void GvFreeValuesTable(GvNode *bn, maxon::BaseArray<GvValue*>& ports)
{
	for (GvValue*& val : ports)
	{
		if (val)
			bn->FreeCalculationHandler(val);
	}
	ports.Reset();
}

void GvFreeValuesTable(GvNode *bn, GvValuesInfo &info)
{
	if (!bn) return;

	for (GvValue*& val : info.in_values)
	{
		if (val)
			bn->FreeCalculationHandler(val);
	}

	info.in_values.Reset();
	info.out_ports.Reset();
}

Bool GvBuildInValuesTable(GvNode *bn, maxon::BaseArray<GvValue*>& ports, GvCalc *c, GvRun *r, GvIdTablePtr ids)
{
	Int32 i, entries = 0; GvPortDescription pd; GvPortListEntry *entry; Bool valid;

	ports.Flush();

	if (ids == GV_EXISTING_PORTS)
	{
		entries = bn->GetInPortCount();
		if (!entries) 
			return true;

		iferr (ports.Resize(entries))
			goto error;

		for (i = 0; i < entries; ++i)
		{
			GvPort *port = bn->GetInPort(i); if (!port) goto error;
			ports[i] = bn->AllocCalculationHandler(port->GetMainID(), c, r, i);
			if (!ports[i]) goto error;
		}
	}
	else if (ids == GV_DEFINED_PORTS)
	{
		AutoAlloc<GvPortList> portlist; if (!portlist) return false;
		bn->GetPortList(GV_PORT_INPUT, portlist);
		entries = portlist->GetCount();
		if (!entries) 
			return true;

		iferr (ports.Resize(entries))
			goto error;

		for (i = 0; i < entries; ++i)
		{
			entry = portlist->GetIndex(i);
			if (!entry || !bn->GetPortDescription(GV_PORT_INPUT, entry->id, &pd)) goto error;
			GvPort* port = bn->GetInPortFirstMainID(entry->id);
			if (!port && pd.ports_min > 0) goto error;

			valid = pd.flags & GV_PORTDESCRIPTION_MULTIPLE ?  port != nullptr : true;
			if (valid)
			{
				ports[i] = bn->AllocCalculationHandler(entry->id, c, r, GV_MULTIPLE_PORTS);
				if (!ports[i]) goto error;
			}
		}
	}
	else
	{
		for (entries = 0; ids[entries];) ++entries;
		if (!entries) 
			return true;

		iferr (ports.Resize(entries))
			goto error;

		for (i = 0; i < entries; ++i)
		{
			if (!bn->GetPortDescription(GV_PORT_INPUT, ids[i], &pd)) goto error;
			GvPort* port = bn->GetInPortFirstMainID(ids[i]);
			if (!port && pd.ports_min > 0) goto error;

			valid = pd.flags & GV_PORTDESCRIPTION_MULTIPLE ?  port != nullptr : true;
			if (valid)
			{
				ports[i] = bn->AllocCalculationHandler(ids[i], c, r, GV_MULTIPLE_PORTS);
				if (!ports[i]) goto error;
			}
		}
	}
	return true;

error:
	GvFreeValuesTable(bn, ports);
	return false;
}

Bool GvCalculateInValuesTable(GvNode *bn, GvRun *run, GvCalc *calc, GvValuesInfo &info, Int32 singleport, BaseTime *time)
{
	for (GvValue*& val : info.in_values)
	{
		if (val)
		{
			if (!val->Calculate(bn, GV_PORT_INPUT, run, calc, singleport, time)) 
				return false;
		}
	}
	return true;
}

Bool GvBuildOutPortsTable(GvNode *bn, maxon::BaseArray<GvPort*>& ports)
{
	ports.Flush();

	Int32 j = bn->GetOutPortCount();
	if (!j) 
		return true;
	iferr (ports.Resize(j))
		goto error;

	for (Int i = 0; i < ports.GetCount(); i++)
	{
		ports[i] = bn->GetOutPort((Int32)i); 
		if (!ports[i]) 
			goto error;
	}
	return true;

error:
	ports.Reset();
	return false;
}

////////////////////////////////

GvWorld* GvGetWorld(void)
{
	return C4DOS.Gv->globals->GetWorld();
}

const	String GvGetEmptyString(void)
{
	return C4DOS.Gv->globals->GetEmptyString();
}

const String GvGetErrorString(const maxon::String &command, Int32 err)
{
	return C4DOS.Gv->globals->GetErrorString(command, err);
}

void GvGetPortList(GvPortsDescInfo *info, GvPortIO port, GvPortList &portlist)
{
	C4DOS.Gv->globals->GetPortList(info, port, portlist);
}

Bool GvGetAllDataTypes(GvPortDescInfo *info, UInt32 default_flag, Int32 first_id)
{
	return C4DOS.Gv->globals->GetAllDataTypes(info, default_flag, first_id);
}

void GvFreePortDescInfo(GvPortDescInfo *info)
{
	if (C4DOS.Gv->globals->FreePortDescInfo) C4DOS.Gv->globals->FreePortDescInfo(info);
}

Bool GvRegisterValueType(GV_VALUE_HANDLER *data, Int32 struct_size)
{
	if (!C4DOS.Gv->globals || !C4DOS.Gv->globals->RegisterValueType) return false;
	return C4DOS.Gv->globals->RegisterValueType(data, struct_size);
}

Bool GvRegisterDataType(GV_DATA_HANDLER *data, Int32 struct_size, const char *symbol)
{
	if (!C4DOS.Gv->globals || !C4DOS.Gv->globals->RegisterDataType) return false;
	return C4DOS.Gv->globals->RegisterDataType(data, struct_size, symbol);
}

Bool GvRegisterValGroupType(GV_VALGROUP_HANDLER *data, Int32 struct_size)
{
	if (!C4DOS.Gv->globals || !C4DOS.Gv->globals->RegisterValGroupType) return false;
	return C4DOS.Gv->globals->RegisterValGroupType(data, struct_size);
}

Bool GvRegisterOpClassType(GV_OPCLASS_HANDLER *data, Int32 struct_size)
{
	if (!C4DOS.Gv->globals || !C4DOS.Gv->globals->RegisterOpClassType) return false;
	return C4DOS.Gv->globals->RegisterOpClassType(data, struct_size);
}

Bool GvRegisterOpGroupType(GV_OPGROUP_HANDLER *data, Int32 struct_size)
{
	if (!C4DOS.Gv->globals || !C4DOS.Gv->globals->RegisterOpGroupType) return false;
	return C4DOS.Gv->globals->RegisterOpGroupType(data, struct_size);
}

GV_OPCLASS_HANDLER* GvFindRegisteredOpClass(GvOpClassID id)
{
	return C4DOS.Gv->globals->FindRegisteredOpClass(id);
}

GV_OPGROUP_HANDLER* GvFindRegisteredOpGroup(GvOpGroupID id)
{
	return C4DOS.Gv->globals->FindRegisteredOpGroup(id);
}

////////////////////////////////
