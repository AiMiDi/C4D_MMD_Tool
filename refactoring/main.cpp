/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white
Date:			2022/6/21
File:			main.h
Description:	Entrance of the plugin

**************************************************************************/

#include "pch.h"
#include "register_entity.h"
#include "config_manager.h"

Bool PluginStart()
{
	if (!cmt_register::RigisterPlugin())
	{
		return false;
	}
	ConfigManager::InitConfigManager();
	return true;
}

void PluginEnd()
{
	ConfigManager::SaveConfig();
}

Bool PluginMessage(Int32 id, void* data)
{
	switch (id)
	{
	case (C4DPL_INIT_SYS):
	{
		if (!g_resource.Init())
		{
			//	no resource
			return(false);
		}
		return(true);
	}
	default: ;
	}

	return(false);
}
