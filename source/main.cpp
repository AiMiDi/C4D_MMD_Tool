#include "main.h"

Bool PluginStart()
{
	if (!RegisterMMDTool())
		return(false);
	if (!RegisterTMMDBone())
		return(false);
	if (!RegisterOMMDCamera())
		return(false);
	if (!RegisterOMMDRigid())
		return(false);
	if (!RegisterOMMDJoint())
		return(false);
	if (!RegisterOMMDMeshRoot())
		return(false);
	if (!RegisterOMMDBoneRoot())
		return(false);
	if (!RegisterOMMDRigidRoot())
		return(false);
	if (!RegisterOMMDJointRoot())
		return(false);
	if (!RegisterOMMDModelObject())
		return(false);
	if (!RegisterVMDCamDrawSceneHook())
		return(false);
	/*
	 * if (!RegisterC4DBulletTest())
	 * return false;
	 */
	if (!RegisterVMDImport())
		return(false);
	return(true);
}


void PluginEnd()
{
}


Bool PluginMessage(Int32 id, void* data)
{
	switch (id)
	{
	case (C4DPL_INIT_SYS):
	{
		if (!g_resource.Init())
		{
			return(false); /* 没有资源就不要启动插件 */
		}
		return(true);
		break;
	}
	}

	return(false);
}


