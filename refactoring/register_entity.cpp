#include "pch.h"
#include "register_entity.h"

#include "CMTSceneManager.h"
#include "module/ui/cmt_tools_dialog.h"
#include "module/tools/loader/vmd_loader.h"
#include "module/tools/object/mmd_joint_root.h"
#include "module/tools/object/mmd_mesh_root.h"
#include "module/tools/object/mmd_model.h"
#include "module/tools/object/mmd_rigid_root.h"
#include "module/tools/object/mmd_bone_root.h"
#include "module/tools/object/mmd_camera.h"
#include "module/tools/object/mmd_joint.h"
#include "module/tools/object/mmd_rigid.h"
#include "module/tools/tag/mmd_bone.h"


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
	return(RegisterObjectPlugin(ID_O_MMD_CAMERA, GeLoadString(IDS_O_MMD_CAMERA), OBJECT_CALL_ADDEXECUTION, MMDCamera::Alloc, "OMMDCamera"_s, AutoBitmap("OMMDCamera.png"_s), 0));
}

Bool RegisterMMDRigid()
{
		return RegisterObjectPlugin(ID_O_MMD_RIGID, GeLoadString(IDS_O_MMD_RIGID), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDRigidObject::Alloc, "OMMDRigid"_s, AutoBitmap("OMMDRigid.png"_s), 0);
}

Bool RegisterMMDJoint()
{
	return RegisterObjectPlugin(ID_O_MMD_JOINT, GeLoadString(IDS_O_MMD_JOINT), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDJointObject::Alloc, "OMMDJoint"_s, AutoBitmap("OMMDJoint.png"_s), 0);
}

Bool RegisterMMDModelRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_MODEL, GeLoadString(IDS_O_MMD_MODEL), OBJECT_CALL_ADDEXECUTION, MMDModelRootObject::Alloc, "OMMDModel"_s, AutoBitmap("OMMDModel.png"_s), 0);
}

Bool RegisterMMDBoneRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_BONE_ROOT, GeLoadString(IDS_O_MMD_BONE_ROOT), PLUGINFLAG_HIDEPLUGINMENU, MMDBoneRootObject::Alloc, "OMMDBoneRoot"_s, AutoBitmap("OMMDBoneRoot.png"_s), 0);
}

Bool RegisterMMDMeshRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_MESH_ROOT, GeLoadString(IDS_O_MMD_MESH_ROOT), PLUGINFLAG_HIDEPLUGINMENU | OBJECT_CALL_ADDEXECUTION, MMDMeshRootObject::Alloc, "OMMDMeshRoot"_s, AutoBitmap("OMMDMeshRoot.png"_s), 0);
}

Bool RegisterMMDRigidRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_RIGID_ROOT, GeLoadString(IDS_O_MMD_RIGID_ROOT), PLUGINFLAG_HIDEPLUGINMENU , MMDRigidRootObject::Alloc, "OMMDRigidRoot"_s, AutoBitmap("OMMDRigidRoot.png"_s), 0);
}

Bool RegisterMMDJointRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_JOINT_ROOT, GeLoadString(IDS_O_MMD_JOINT_ROOT), PLUGINFLAG_HIDEPLUGINMENU , MMDJointRootObject::Alloc, "OMMDJointRoot"_s, AutoBitmap("OMMDJointRoot.png"_s), 0);
}

Bool RegisterMMDBoneTag()
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
	if (!RegisterMMDModelRoot())
		return false;
	if (!RegisterMMDBoneRoot())
		return false;
	if (!RegisterMMDMeshRoot())
		return false;
	if (!RegisterMMDRigidRoot())
		return false;
	if (!RegisterMMDJointRoot())
		return false;
	if (!RegisterMMDBoneTag())
		return false;

	return true;
}
