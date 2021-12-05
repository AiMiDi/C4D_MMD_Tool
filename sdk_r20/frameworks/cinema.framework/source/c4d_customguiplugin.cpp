#include "c4d_customguiplugin.h"
#include "c4d_general.h"


Bool RegisterCustomGuiPlugin(const maxon::String& str, Int32 info, CustomGuiData* dat)
{
	if (!dat)
		return false;

	CUSTOMGUIPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.adr	= dat;
	np.info	= info;
	np.Destructor	= &BaseData::Destructor;
	np.Alloc = &CustomGuiData::Alloc;
	np.Free	 = &CustomGuiData::Free;
	np.GetResourceSym	= &CustomGuiData::GetResourceSym;
	np.GetProperties	= &CustomGuiData::GetProperties;
	np.GetResourceDataType = &CustomGuiData::GetResourceDataType;

	return GeRegisterPlugin(PLUGINTYPE::CUSTOMGUI, dat->GetId(), str, &np, sizeof(np));
}

CUSTOMGUIPLUGIN* FindCustomGuiPlugin(Int32 type)
{
	BasePlugin* plug = FindPlugin(type, PLUGINTYPE::CUSTOMGUI);
	if (!plug)
		return nullptr;

	return (CUSTOMGUIPLUGIN*)plug->GetPluginStructure();
}
