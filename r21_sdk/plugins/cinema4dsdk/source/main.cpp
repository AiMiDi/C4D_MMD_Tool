#include "main.h"

Bool PluginStart()
{
	if (!RegisterMMDTool())
		return false;
	// shader plugin examples
	return true;
}

void PluginEnd()
{
}

Bool PluginMessage(Int32 id, void* data)
{
	switch (id)
	{
	case C4DPL_INIT_SYS:
		if (!g_resource.Init()) {
			return false;		// 没有资源就不要启动插件
		}			
		return true;
		break;

	case C4DPL_COMMANDLINEARGS:
		ApplicationOutput("VMDCameraTool loading complete! v0.0.1");
		break;

	case C4DPL_BUILDMENU:
		/*
		BaseContainer* const mainMenu = GetMenuResource("M_EDITOR"_s);
		if (mainMenu == nullptr)
			return false;

		// 创建自定义菜单项
		//BaseContainer menu;
		//menu.InsData(MENURESOURCE_SUBTITLE, "VMD");

		// 将创建多维数据集的命令添加到自定义菜单
		//menu.InsData(MENURESOURCE_COMMAND,"PLUGIN_CMD_" + String::IntToString(1035357));

		// 添加新菜单项
		//mainMenu->InsData(MENURESOURCE_SUBMENU, menu);

		return true;*/
		break;
	}

	return false;
}
