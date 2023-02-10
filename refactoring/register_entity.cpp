#include "pch.h"
#include "register_entity.h"
#include "module/ui/cmt_tools_dialog.h"
#include "module/tools/vmd_loader_data.h"

Bool RegisterCMTTool()
{
	return RegisterCommandPlugin(ID_MMD_TOOL, "MMDTool"_s, 0, AutoBitmap("MMDIcon.png"_s), "MMD tool for C4D"_s, NewObjClear(CMTToolCommand));
}

Bool RegisterVMDLoader()
{
	return RegisterSceneLoaderPlugin(ID_L_MMD_VMD_IMPORT, "VMD(.vmd)"_s, 0, VMDLoaderData::Alloc, "Import VMD Camera."_s);
}

Bool cmt_register::RigisterPlugin()
{
	if (!RegisterCMTTool())
		return FALSE;
	if (!RegisterVMDLoader())
		return FALSE;
	return TRUE;
}
