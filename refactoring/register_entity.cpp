#include "register_entity.h"
#include "module/ui/cmt_tools_dialog.h"

Bool RegisterCMTTool()
{
	return RegisterCommandPlugin(ID_MMD_TOOL, "MMDTool"_s, 0, AutoBitmap("MMDIcon.png"_s), "MMD tool for C4D"_s, NewObjClear(CMTToolCommand));
}

Bool cmt_register::RigisterPlugin()
{
	if (!RegisterCMTTool())
		return FALSE;
	return TRUE;
}
