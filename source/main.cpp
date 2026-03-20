/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi/walter white
Date:			2022/6/21
File:			main.h
Description:	Entrance of the plugin

**************************************************************************/

#include "register_entity.h"
#include "cmt_tools_config_manager.h"
#include "module/core/cmt_marco.h"
#include "module/ui/cmt_name_conversion_dialog.h"
#include "maxon/string.h"

Bool CINEMA_NAMESPACE PluginStart()
{
	if (!cmt_register::RegisterPlugin())
	{
		return FALSE;
	}
	UpdateNameConversionDialog::Init();
	CMTToolConfigManager::GetInstance().InitConfigManager();
	return TRUE;
}

void CINEMA_NAMESPACE PluginEnd()
{
	CMTToolConfigManager::GetInstance().SaveConfig();
}

Bool CINEMA_NAMESPACE PluginMessage(Int32 id, void* data)
{
	switch (id)
	{
	case C4DPL_INIT_SYS:
	{
		if (!g_resource.Init())
		{
			//	no resource
			return false;
		}
		return true;
	}
	default: ;
	}

	return false;
}

// R20：部分模板实例化会生成对全局命名空间 ToString(maxon::String,...) 的引用，而 SDK 仅在 maxon 内联提供；补一个转发定义以满足链接。
#if CMT_SDK_NEEDS_GLOBAL_TOSTRING_STRING_LINK
maxon::String ToString(const String& str, const maxon::FormatStatement* formatStatement, Bool checkDataType)
{
	return maxon::ToString(str, formatStatement, checkDataType);
}
#endif
