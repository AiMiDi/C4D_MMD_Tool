#include "main.h"

Bool PluginStart()
{
	if (!RegisterMMDTool())
		return false;
	if (!RegisterPMXModelTag())
		return false;
	return true;
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
		if (!g_resource.Init()) {
			return false;		// 没有资源就不要启动插件
		}			
		return true;		
		break;
	}
	}
	return false;
}
