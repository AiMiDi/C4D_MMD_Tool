#include "pch.h"
#include "register_entity.h"

#include "CMTSceneManager.h"
#include "module/ui/cmt_tools_dialog.h"
#include "module/tools/loader/vmd_loader.h"
#include "module/tools/tag/mmd_bone.h"
#include "module/tools/object/mmd_model.h"
#include "module/tools/object/mmd_camera.h"
#include "module/tools/object/mmd_joint.h"
#include "module/tools/object/mmd_rigid.h"
#include "module/tools/object/mmd_bone_manager.h"
#include "module/tools/object/mmd_joint_manager.h"
#include "module/tools/object/mmd_mesh_manager.h"
#include "module/tools/object/mmd_rigid_manager.h"


static Bool RegisterCMTTool()
{
	return RegisterCommandPlugin(ID_COMMAND_CMT_TOOL, "MMDTool"_s, 0, AutoBitmap("MMDIcon.png"_s), "MMD tool for C4D"_s, NewObjClear(CMTToolCommand));
}

static Bool RegisterCMTSceneManager()
{
	return RegisterSceneHookPlugin(ID_SCENE_HOOK_CMT_SCENE_MANAGER, "CMTSceneManager"_s, 0, CMTSceneManager::Alloc, 0, 0);
}

static Bool RegisterVMDLoader()
{
	return RegisterSceneLoaderPlugin(ID_L_MMD_VMD_IMPORT, "VMD(.vmd)"_s, 0, VMDLoaderData::Alloc, ""_s);
}

static Bool RegisterMMDCamera()
{
	return(RegisterObjectPlugin(ID_O_MMD_CAMERA, GeLoadString(IDS_O_MMD_CAMERA), OBJECT_CALL_ADDEXECUTION, MMDCamera::Alloc, "OMMDCamera"_s, AutoBitmap("OMMDCamera.png"_s), 0));
}

static Bool RegisterMMDRigid()
{
		return RegisterObjectPlugin(ID_O_MMD_RIGID, GeLoadString(IDS_O_MMD_RIGID), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDRigidObject::Alloc, "OMMDRigid"_s, AutoBitmap("OMMDRigid.png"_s), 0);
}

static Bool RegisterMMDJoint()
{
	return RegisterObjectPlugin(ID_O_MMD_JOINT, GeLoadString(IDS_O_MMD_JOINT), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDJointObject::Alloc, "OMMDJoint"_s, AutoBitmap("OMMDJoint.png"_s), 0);
}

static Bool RegisterMMDModelManager()
{
	return RegisterObjectPlugin(ID_O_MMD_MODEL, GeLoadString(IDS_O_MMD_MODEL_MANAGER), OBJECT_CALL_ADDEXECUTION, MMDModelManagerObject::Alloc, "OMMDModelManager"_s, AutoBitmap(1021433), 0);
}

static Bool RegisterMMDBoneManager()
{
	return RegisterObjectPlugin(ID_O_MMD_BONE_MANAGER, GeLoadString(IDS_O_MMD_BONE_MANAGER), PLUGINFLAG_HIDEPLUGINMENU, MMDBoneManagerObject::Alloc, "OMMDBoneManager"_s, AutoBitmap("OMMDBoneManager.png"_s), 0);
}

static Bool RegisterMMDMeshManager()
{
	return RegisterObjectPlugin(ID_O_MMD_MESH_MANAGER, GeLoadString(IDS_O_MMD_MESH_MANAGER), PLUGINFLAG_HIDEPLUGINMENU | OBJECT_CALL_ADDEXECUTION, MMDMeshManagerObject::Alloc, "OMMDMeshManager"_s, AutoBitmap("OMMDMeshManager.png"_s), 0);
}

static Bool RegisterMMDRigidManager()
{
	return RegisterObjectPlugin(ID_O_MMD_RIGID_MANAGER, GeLoadString(IDS_O_MMD_RIGID_MANAGER), PLUGINFLAG_HIDEPLUGINMENU , MMDRigidManagerObject::Alloc, "OMMDRigidManager"_s, AutoBitmap("OMMDRigidManager.png"_s), 0);
}

static Bool RegisterMMDJointManager()
{
	return RegisterObjectPlugin(ID_O_MMD_JOINT_MANAGER, GeLoadString(IDS_O_MMD_JOINT_MANAGER), PLUGINFLAG_HIDEPLUGINMENU , MMDJointManagerObject::Alloc, "OMMDJointManager"_s, AutoBitmap("OMMDJointManager.png"_s), 0);
}

static Bool RegisterMMDBoneTag()
{
	return RegisterTagPlugin(ID_T_MMD_BONE, GeLoadString(IDS_T_MMD_BONE), TAG_VISIBLE | TAG_EXPRESSION, MMDBoneTag::Alloc, "TMMDBone"_s, AutoBitmap("TMMDBone.png"_s), 0);
}

Bool cmt_register::RegisterPlugin()
{
	if (!RegisterCMTTool())
		return false;
	if (!RegisterCMTSceneManager())
		return false;
	if (!RegisterVMDLoader())
		return false;
	if (!RegisterMMDCamera())
		return false;
	if (!RegisterMMDRigid())
		return false;
	if (!RegisterMMDJoint())
		return false;
	if (!RegisterMMDModelManager())
		return false;
	if (!RegisterMMDBoneManager())
		return false;
	if (!RegisterMMDMeshManager())
		return false;
	if (!RegisterMMDRigidManager())
		return false;
	if (!RegisterMMDJointManager())
		return false;
	if (!RegisterMMDBoneTag())
		return false;

	return true;
}
