/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white
Date:			2022/6/21
File:			main.h
Description:	Entrance of the plugin

**************************************************************************/

#include <c4d.h>

#include "register_entity.h"

Bool PluginStart()
{
	if (!cmt_register::RigisterPlugin())
	{
		return false;
	}
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
			//	no resource
			return(false);
		}
		return(true);
		break;
	}
	}

	return(false);
}
