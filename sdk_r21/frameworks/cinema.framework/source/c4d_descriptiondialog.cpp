#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

// MatrixExtrudeDialolg.cpp
//////////////////////////////////////////////////////////////////////

#include "c4d_descriptiondialog.h"
#include "c4d_basedocument.h"
#include "c4d_general.h"
#include "lib_description.h"
#include "toolbase.h"

void DescriptionToolData::InitDefaultSettings(BaseDocument* pDoc, BaseContainer& data)
{
	data.SetInt32(MDATA_INTERACTIVE, true);

	ToolData::InitDefaultSettings(pDoc, data);
}

Bool DescriptionToolData::GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags)
{
	if (description->LoadDescription(GetToolPluginId()))
	{
		flags |= DESCFLAGS_DESC::LOADED;
		return true;
	}
	return ToolData::GetDDescription(doc, data, description, flags);
}

Bool DescriptionToolData::TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	return ToolData::TranslateDescID(doc, data, id, res_id, res_at);
}

Bool DescriptionToolData::GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	switch (id[0].id)
	{
		case MDATA_NEWTRANSFORM:		break;
		case MDATA_DEFAULTVALUES:		break;
		case MDATA_APPLY:
			if (!firstaction &&/*(*dcu->descid)[0].id!=MDATA_DEFAULTVALUES && */ (data.GetInt32(MDATA_INTERACTIVE) || data.GetInt32(MDATA_TEMPINTERACTIVE)))
				return false;
			break;

		case MDATA_INTERACTIVE:			break;
	}
	return SUPER::GetDEnabling(doc, data, id, t_data, flags, itemdesc);
}

Bool DescriptionToolData::InteractiveModeling_Restart(BaseDocument* doc)
{
	firstaction = false;
	return ::InteractiveModeling_Restart(doc);
}

Bool DescriptionToolData::InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt)
{
	firstaction = true;
	last_dirty = NOTOK;
	return true;
}

void DescriptionToolData::FreeTool(BaseDocument* doc, BaseContainer& data)
{
	firstaction = true;
	last_dirty = NOTOK;
}

Bool DescriptionToolData::Message(BaseDocument* doc, BaseContainer& data, Int32 type, void* t_data)
{
	if (type == MSG_TOOL_RESTART)
	{
		firstaction = true;
	}
	if (type == MSG_DESCRIPTION_COMMAND)
	{
		DescriptionCommand* dc = (DescriptionCommand*) t_data;
		if (dc->_descId[0].id == MDATA_NEWTRANSFORM)
		{
			InteractiveModeling_Restart(GetActiveDocument());
			data.SetInt32(MDATA_TEMPINTERACTIVE, true);
			return true;
		}
		else if (dc->_descId[0].id == MDATA_DEFAULTVALUES)
		{
			InitDefaultSettings(doc, data);
			return true;
		}
		else if (dc->_descId[0].id == MDATA_APPLY || dc->_descId[0].id == IDC_OK)
		{
			AutoAlloc<Description> desc;

			if (desc != nullptr)	// ITEM#65673 Bug in Modeling tools
			{
				BasePlugin* toolPlug	= FindPlugin(GetToolPluginId(), PLUGINTYPE::TOOL);

				if (toolPlug != nullptr && toolPlug->GetDescription(desc, DESCFLAGS_DESC::NONE))
				{
					BaseContainer *groupData = desc->GetParameterI(MDATA_COMMANDGROUP, nullptr);
					if (groupData != nullptr && groupData->GetBool(DESC_HIDE))
						return true;

					BaseContainer *applyData = desc->GetParameterI(MDATA_APPLY, nullptr);
					if (applyData != nullptr && applyData->GetBool(DESC_HIDE))
						return true;
				}
			}

			data.SetInt32(MDATA_TEMPINTERACTIVE, true);
			firstaction = false;
		}
	}
	if (type == MSG_DESCRIPTION_CHECKUPDATE)
	{
		DescriptionCheckUpdate* dcu = (DescriptionCheckUpdate*)t_data;
		dcu->drawflags |= MSG_DESCRIPTION_CHECKUPDATE_DOCUMENT | MSG_DESCRIPTION_CHECKUPDATE_SYNC;

		BasePlugin* plug	= FindPlugin(GetToolPluginId(), PLUGINTYPE::TOOL);
		Int32				dirty = 0;
		if (plug)
			dirty = plug->GetDirty(DIRTYFLAGS::NONE);
		if (dirty != last_dirty && !firstaction &&/*(*dcu->descid)[0].id!=MDATA_DEFAULTVALUES && */ (data.GetInt32(MDATA_INTERACTIVE) || data.GetInt32(MDATA_TEMPINTERACTIVE)))
		{
			data.SetInt32(MDATA_TEMPINTERACTIVE, false);
			if (plug)
				dirty = plug->GetDirty(DIRTYFLAGS::NONE);
			last_dirty = dirty;

			AutoAlloc<AtomArray> pActive;
			if (!doc || !pActive)
				return true;

			// undo the step before
			InteractiveModeling_Rewind(doc);

			ModelingCommandData mu;

			doc->GetActiveObjects(*pActive, GETACTIVEOBJECTFLAGS::CHILDREN);
			ModelingCommandData md;
			md.bc	 = &data;
			md.arr = pActive;
			md.doc = doc;
			md.flags = MODELINGCOMMANDFLAGS::CREATEUNDO;
			switch (doc->GetMode())
			{
				case Mpoints: md.mode = MODELINGCOMMANDMODE::POINTSELECTION; break;
				case Mpolygons: md.mode = MODELINGCOMMANDMODE::POLYGONSELECTION; break;
				case Medges: md.mode = MODELINGCOMMANDMODE::EDGESELECTION; break;
				default: md.mode = MODELINGCOMMANDMODE::ALL; break;
			}

			// ATInteractStart(md.doc);

			StopAllThreads();
			if (md.doc)
				md.doc->StartUndo();

			SendModelingCommand(GetToolPluginId(), md);
			if (md.doc)
				md.doc->EndUndo();
			// ATInteractEnd(md.doc);
		}
	}
	return ToolData::Message(doc, data, type, t_data);
}

