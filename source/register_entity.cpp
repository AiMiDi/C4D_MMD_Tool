#include "register_entity.h"
#include "plugin_resource.h"
#include "CMTSceneManager.h"
#include "module/ui/cmt_tools_dialog.h"
#include "module/tools/loader/vmd_loader.h"
#include "module/tools/tag/mmd_bone.h"
#include "module/tools/object/mmd_joint.h"
#include "module/tools/object/mmd_rigid.h"
#include "module/tools/object/mmd_camera.h"
#include "module/tools/object/mmd_model_manager.h"
#include "module/tools/object/mmd_bone_manager.h"
#include "module/tools/object/mmd_joint_manager.h"
#include "module/tools/object/mmd_mesh_manager.h"
#include "module/tools/object/mmd_rigid_manager.h"

namespace
{
	Bool RegisterCMTTool()
	{
		return RegisterCommandPlugin(g_cmt_command_id, "MMDTool"_s, 0, AutoBitmap("MMDIcon.png"_s), "MMD tool for C4D"_s, NewObjClear(CMTToolCommand));
	}

	Bool RegisterCMTSceneManager()
	{
		return RegisterSceneHookPlugin(g_cmt_scene_manager_scene_hook_id, "CMTSceneManager"_s, 0, CMTSceneManager::Alloc, 0, 0);
	}

	Bool RegisterVMDLoader()
	{
		return RegisterSceneLoaderPlugin(g_mmd_vmd_loader_id, "VMD(.vmd)"_s, 0, VMDLoaderData::Alloc, ""_s);
	}

	Bool RegisterMMDCamera()
	{
		return(RegisterObjectPlugin(g_mmd_camera_object_id, GeLoadString(IDS_O_MMD_CAMERA), OBJECT_CALL_ADDEXECUTION, MMDCamera::Alloc, "OMMDCamera"_s, AutoBitmap("OMMDCamera.png"_s), 0));
	}

	Bool RegisterMMDRigid()
	{
		return RegisterObjectPlugin(g_mmd_rigid_object_id, GeLoadString(IDS_O_MMD_RIGID), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDRigidObject::Alloc, "OMMDRigid"_s, AutoBitmap("OMMDRigid.png"_s), 0);
	}

	Bool RegisterMMDJoint()
	{
		return RegisterObjectPlugin(g_mmd_joint_object_id, GeLoadString(IDS_O_MMD_JOINT), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDJointObject::Alloc, "OMMDJoint"_s, AutoBitmap("OMMDJoint.png"_s), 0);
	}

	Bool RegisterMMDModelManager()
	{
		return RegisterObjectPlugin(g_mmd_model_manager_object_id, GeLoadString(IDS_O_MMD_MODEL_MANAGER), OBJECT_CALL_ADDEXECUTION, MMDModelManagerObject::Alloc, "OMMDModelManager"_s, AutoBitmap(1021433), 3);
	}

	Bool RegisterMMDBoneManager()
	{
		return RegisterObjectPlugin(g_mmd_bone_manager_object_id, GeLoadString(IDS_O_MMD_BONE_MANAGER), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, MMDBoneManagerObject::Alloc, "OMMDBoneManager"_s, AutoBitmap("OMMDBoneManager.png"_s), 1);
	}

	Bool RegisterMMDMeshManager()
	{
		return RegisterObjectPlugin(g_mmd_mesh_manager_object_id, GeLoadString(IDS_O_MMD_MESH_MANAGER), PLUGINFLAG_HIDEPLUGINMENU | OBJECT_CALL_ADDEXECUTION, MMDMeshManagerObject::Alloc, "OMMDMeshManager"_s, AutoBitmap("OMMDMeshManager.png"_s), 0);
	}
					
	Bool RegisterMMDRigidManager()
	{
		return RegisterObjectPlugin(g_mmd_rigid_manager_object_id, GeLoadString(IDS_O_MMD_RIGID_MANAGER), PLUGINFLAG_HIDEPLUGINMENU , MMDRigidManagerObject::Alloc, "OMMDRigidManager"_s, AutoBitmap("OMMDRigidManager.png"_s), 0);
	}

	Bool RegisterMMDJointManager()
	{
		return RegisterObjectPlugin(g_mmd_joint_manager_object_id, GeLoadString(IDS_O_MMD_JOINT_MANAGER), PLUGINFLAG_HIDEPLUGINMENU , MMDJointManagerObject::Alloc, "OMMDJointManager"_s, AutoBitmap("OMMDJointManager.png"_s), 0);
	}

	Bool RegisterMMDBoneTag()
	{
		return RegisterTagPlugin(g_mmd_bone_tag_id, GeLoadString(IDS_T_MMD_BONE), TAG_VISIBLE | TAG_EXPRESSION, MMDBoneTag::Alloc, "TMMDBone"_s, AutoBitmap("TMMDBone.png"_s), 2);
	}
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


