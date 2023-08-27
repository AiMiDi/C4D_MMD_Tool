#include "pch.h"
#include "register_entity.h"

#include "CMTSceneManager.h"
#include "module/tools/object/mmd_camera.h"
#include "module/ui/cmt_tools_dialog.h"
#include "module/tools/loader/vmd_loader.h"

Bool RegisterCMTTool()
{
	return RegisterCommandPlugin(ID_COMMAND_CMT_TOOL, "MMDTool"_s, 0, AutoBitmap("MMDIcon.png"_s), "MMD tool for C4D"_s, NewObjClear(CMTToolCommand));
}

Bool RegisterCMTSceneManager()
{
	return RegisterSceneHookPlugin(ID_SCENE_HOOK_CMT_SCENE_MANAGER, "CMTSceneManager"_s, 0, CMTSceneManager::Alloc, 0, 0);
}

Bool RegisterVMDLoader()
{
	return RegisterSceneLoaderPlugin(ID_L_MMD_VMD_IMPORT, "VMD(.vmd)"_s, 0, VMDLoaderData::Alloc, ""_s);
}

Bool RegisterMMDCamera()
{
	return(RegisterObjectPlugin(ID_O_MMD_CAMERA, GeLoadString(IDS_O_MMD_CAMERA), OBJECT_CALL_ADDEXECUTION, MMDCamera::Alloc, "MMDCamera"_s, AutoBitmap("MMDCamera.png"_s), 0));
}

Bool cmt_register::RigisterPlugin()
{
	if (!RegisterCMTTool())
		return FALSE;
	if (!RegisterCMTSceneManager())
		return FALSE;
	if (!RegisterVMDLoader())
		return FALSE;
	if(!RegisterMMDCamera())
		return FALSE;
	return TRUE;
}
