#include "c4d_commandplugin.h"
#include "c4d_general.h"
#include "c4d_gui.h"
#ifdef __API_INTERN__
	#include "plugincommand.h"
#endif

Bool CommandData::Execute(BaseDocument* doc, GeDialog* parentManager)
{
	return true;
}

Int32 CommandData::GetState(BaseDocument* doc, GeDialog* parentManager)
{
	return CMD_ENABLED;
}

Bool CommandData::RestoreLayout(void* secret)
{
	return true;
}

Bool CommandData::Message(Int32 type, void* data)
{
	return true;
}

String CommandData::GetScriptName(void)
{
	return String();
}

Bool CommandData::ExecuteSubID(BaseDocument* doc, Int32 subid, GeDialog* parentManager)
{
	return false;
}

Bool CommandData::ExecuteOptionID(BaseDocument* doc, Int32 plugid, Int32 subid, GeDialog* parentManager)
{
	return false;
}

Bool CommandData::GetSubContainer(BaseDocument* doc, BaseContainer& submenu, GeDialog* parentManager)
{
	return false;
}

Bool RegisterCommandPlugin(Int32 id, const maxon::String& str, Int32 info, BaseBitmap* icon, const maxon::String& help, CommandData* dat)
{
	if (!dat)
		return false;

	COMMANDPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.adr	= dat;
	np.help	= (String*)&help;
	np.command_icon	= icon;
	np.info	= info;
	np.Destructor	= &CommandData::Destructor;
	np.Execute	= &CommandData::Execute;
	np.GetState	= &CommandData::GetState;
	np.RestoreLayout = &CommandData::RestoreLayout;
	np.Message = &CommandData::Message;
	np.GetScriptName = &CommandData::GetScriptName;
	np.GetSubContainer = &CommandData::GetSubContainer;
	np.ExecuteSubID = &CommandData::ExecuteSubID;
	np.ExecuteOptionID = &CommandData::ExecuteOptionID;

	return GeRegisterPlugin(PLUGINTYPE::COMMAND, id, str, &np, sizeof(np));
}

Bool RegisterManagerInformation(Int32 id, const maxon::String& str, Int32 info)
{
	MANAGERINFORMATION np;
	ClearMem(&np, sizeof(np));

	np.adr	= nullptr;
	np.info	= info;

	return GeRegisterPlugin(PLUGINTYPE::MANAGERINFORMATION, id, str, &np, sizeof(np));
}
