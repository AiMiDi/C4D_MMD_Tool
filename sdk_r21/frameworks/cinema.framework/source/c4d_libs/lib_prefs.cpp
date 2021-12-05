#include "lib_prefs.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "c4d_baselist.h"
#include "c4d_resource.h"
#include "c4d_general.h"
#include "c4d_plugin.h"

#ifdef __API_INTERN__
	#include "ge_event.h"
	#include "world.h"
	#include "cgui_main.h"
#endif


static PrefsLib *lib_prefs = nullptr;


static PrefsLib *CheckPrefsLib(Int32 offset)
{
	return (PrefsLib*)CheckLib(LIBRARY_PREFS, offset, (C4DLibrary**)&lib_prefs);
}


Bool PrefsLib_InitPrefs()
{
	PrefsLib *lib = CheckPrefsLib(LIBOFFSET(PrefsLib, PrefsLib_InitPrefs));
	if (!lib || !lib->PrefsLib_InitPrefs) return false;
	return (*lib->PrefsLib_InitPrefs)();
}

Bool PrefsLib_OpenDialog(Int32 page)
{
	PrefsLib *lib = CheckPrefsLib(LIBOFFSET(PrefsLib, PrefsLib_OpenDialog));
	if (!lib || !lib->PrefsLib_OpenDialog) return false;
	return (*lib->PrefsLib_OpenDialog)(page);
}


static void FillPrefsPlugin(PREFSPLUGIN *np, DataAllocator *npalloc, Int32 info, BaseBitmap *icon)
{
	FillNodePlugin(np, info, npalloc, icon, 0);

	np->icon				= icon;
}

static Bool RegisterPrefsPlugin(Int32 id, const String &str, Int32 info, DataAllocator *npalloc, const String &description, BaseBitmap *icon)
{
	if (description.IsPopulated() && !RegisterDescription(id, description)) return false;

	PREFSPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillPrefsPlugin(&np, npalloc, info, icon);

	return GeRegisterPlugin(PLUGINTYPE::PREFS, id, str, &np, sizeof(np));
}

PrefsDialogObject::PrefsDialogObject()
{

}

BasePlugin *PrefsDialogObject::Register(Int32 id, DataAllocator *allocfunc, const String &name, const String &description, Int32 parentid, Int32 sortid)
{
	if (!RegisterPrefsPlugin(id, name, 0, allocfunc, description, nullptr))
		return nullptr;

	BasePlugin *o = FindPlugin(id, PLUGINTYPE::PREFS);
	if (!o) return nullptr;

#ifdef __API_INTERN__
	o->data.SetInt32(IDPREFS_SORTID, sortid);
	o->data.SetInt32(IDPREFS_PARENTID, parentid);
#else
	o->GetDataInstance()->SetInt32(IDPREFS_SORTID, sortid);
	o->GetDataInstance()->SetInt32(IDPREFS_PARENTID, parentid);
#endif
	return o;
}

#ifdef __API_INTERN__
	static BaseContainer *GetWorldContainerInstance()
	{
		return &world->prefs;
	}
#endif

void PrefsDialogObject::SetPrefsValue(Int32 id, const GeData &data, DESCFLAGS_SET &flags, Bool refresh)
{
	GetWorldContainerInstance()->SetData(id, data);
	flags |= DESCFLAGS_SET::PARAM_SET;
	GeUpdateUI();
	if (refresh)
		EventAdd(EVENT::FORCEREDRAW);
	else
		EventAdd();
}

void PrefsDialogObject::InitPrefsValue(Int32 id, const GeData &data, Description* desc, const DescID &descid, BaseContainer* pBC)
{
	if (!desc)
	{
		if (!pBC) pBC = GetWorldContainerInstance();
		if (pBC->GetData(id) == GeData() || pBC->GetData(id).GetType() != data.GetType()) pBC->SetData(id, data);
	}
	else
	{
		const DescID *singleid = nullptr;
		singleid = desc->GetSingleDescID();
		if (!singleid || descid.IsPartOf(*singleid, nullptr))
		{
#ifdef __API_INTERN__
			BaseContainer temp1;
			AtomArray ar;
			BaseContainer *idbc = desc->GetParameterI(descid, temp1, ar);
#else
			BaseContainer *idbc = desc->GetParameterI(descid, nullptr);
#endif
			if (idbc) idbc->SetData(DESC_DEFAULT, data);
		}
	}
}


void PrefsDialogObject::SetPrefsValue(Int32 id, Int32 data, DESCFLAGS_SET &flags, const PrefsMapTable *table)
{
	Int32 i, newval = NOTOK;
	for (i = 0; table[i].guiid != NOTOK; i++)
	{
		if (table[i].guiid == data)
		{
			newval = table[i].prefsid;
			break;
		}
	}
	if (newval != NOTOK)
	{
		GetWorldContainerInstance()->SetData(id, newval);
		flags |= DESCFLAGS_SET::PARAM_SET;
		GeUpdateUI();
		EventAdd();
	}
}

void PrefsDialogObject::GetPrefsValue(Int32 id, GeData &data, DESCFLAGS_GET &flags)
{
	data = GetWorldContainerInstance()->GetData(id);
	flags |= DESCFLAGS_GET::PARAM_GET;
}

void PrefsDialogObject::GetPrefsValue(Int32 id, GeData &data, DESCFLAGS_GET &flags, const PrefsMapTable *table)
{
	Int32 i, val = GetWorldContainerInstance()->GetData(id).GetInt32();

	for (i = 0; table[i].guiid != NOTOK; i++)
	{
		if (table[i].prefsid == val)
		{
			data = table[i].guiid;
			flags |= DESCFLAGS_GET::PARAM_GET;
			break;
		}
	}
}
