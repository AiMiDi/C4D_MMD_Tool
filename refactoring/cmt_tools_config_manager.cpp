/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			cmt_tool_config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "cmt_tools_config_manager.h"

void CMTToolConfigManager::InitDialog(GeDialog* dlg)
{
	for (int config_id = k_config_id_begin; config_id < k_config_id_end; ++config_id)
	{
		switch (const auto& [default_config_name, default_config_value] = k_default_config_table[config_id - k_config_id_begin]; default_config_value.index())
		{
		// bool
		case 0:
		{
			dlg->SetBool(config_id, GetConfig<bool>(config_id));
			break;
		}
		// int
		case 1:
		{
			dlg->SetInt32(config_id, GetConfig<int>(config_id));
			break;
		}
		// float
		case 2:
		{
			dlg->SetFloat(config_id, GetConfig<double>(config_id));
			break;
		}
		default: break;
		}
	}
}

void CMTToolConfigManager::InitConfig(Int32 id)
{
	id -= DLG_CMT_TOOL_ID_BEGIN;
	assert(id >= 0 && id < k_default_config_table_size);
	const auto& default_config_item = k_default_config_table[id];
	switch (const auto& [default_config_name, default_config_value] = default_config_item; default_config_value.index())
	{
		// bool
	case 0:
	{
		m_config[default_config_name] = std::get<bool>(default_config_value);
		break;
	}
	// int
	case 1:
	{
		m_config[default_config_name] = std::get<int>(default_config_value);
		break;
	}
	// float
	case 2:
	{
		m_config[default_config_name] = std::get<double>(default_config_value);
		break;
	}
	default: break;
	}
}

void CMTToolConfigManager::InitConfigManager()
{
	m_config = cmt_json::ReadJsonFile(m_config_path);
	if (m_config.empty())
	{
		ApplicationOutput("Failed to load config file, using defaults."_s);
		for (int config_id = k_config_id_begin; config_id < k_config_id_end; ++config_id)
		{
			InitConfig(config_id);
		}
		SaveConfig();
	}
}

void CMTToolConfigManager::SaveConfig() const
{
	cmt_json::WriteJsonFile(m_config_path, m_config);
}
