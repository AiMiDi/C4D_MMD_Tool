/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi/walter white
Date:			2022/6/21
File:			main.h
Description:	Entrance of the plugin

**************************************************************************/

#include "pch.h"

#include "cmt_tools_config_manager.h"
#include "register_entity.h"
#include "module/ui/cmt_name_conversion_dialog.h"

Bool CINEMA_NAMESPASE PluginStart()
{
	if (!cmt_register::RegisterPlugin())
	{
		return FALSE;
	}
	UpdateNameConversionDialog::Init();
	CMTToolConfigManager::GetInstance().InitConfigManager();
	return TRUE;
}

void CINEMA_NAMESPASE PluginEnd()
{
	CMTToolConfigManager::GetInstance().SaveConfig();
}

Bool CINEMA_NAMESPASE PluginMessage(Int32 id, void* data)
{
	switch (id)
	{
	case (C4DPL_INIT_SYS):
	{
		if (!g_resource.Init())
		{
			//	no resource
			return(FALSE);
		}
		return(TRUE);
	}
	default: ;
	}

	return(FALSE);
}
