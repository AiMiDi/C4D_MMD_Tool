/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#include "config_manager.h"

#include <fstream>

static std::optional<confin_inital_value> g_init_config_LUT[64]{
{},// DLG_VMD_CAM_IMPORT_TITLE
{{{"VMD_CAM_IMPORT_SIZE"},{8.5f}}},
{},// DLG_VMD_CAM_IMPORT_SIZE_NAME
{{{"VMD_CAM_IMPORT_OFFSET"},{0.f}}},
{},// DLG_VMD_CAM_IMPORT_OFFSET_NAME
{},// DLG_VMD_CAM_IMPORT_BUTTON

{},// DLG_VMD_CAM_EXPORT_TITLE
{{{"VMD_CAM_EXPORT_SIZE"},{8.5f}}},
{},// DLG_VMD_CAM_EXPORT_SIZE_NAME
{{{"VMD_CAM_EXPORT_OFFSET"},{0.f}}},
{},// DLG_VMD_CAM_EXPORT_OFFSET_NAME
{},// DLG_VMD_CAM_EXPORT_ROTATION_TWEEN_NAME
{{{"VMD_CAM_EXPORT_ROTATION_TWEEN"},{0}}},
{{{"VMD_CAM_EXPORT_USE_BAKE"},{true}}},
{},// DLG_VMD_CAM_EXPORT_BUTTON

{},// DLG_VMD_CAM_CONVER_DIS_NAME
{{{"VMD_CAM_CONVER_DIS"},{0.f}}},
{},// DLG_VMD_CAM_CONVER_ROTATION_TWEEN_NAME
{{{"VMD_CAM_CONVER_ROTATION_TWEEN"},{0}}},
{},// DLG_VMD_CAM_CONVER_BUTTON

{},// DLG_VMD_MOT_IMPORT_SIZE_NAME
{{{"VMD_MOT_IMPORT_SIZE"},{8.5f}}},
{},// DLG_VMD_MOT_IMPORT_OFFSET_NAME
{{{"VMD_MOT_IMPORT_OFFSET"},{0.f}}},
{{{"VMD_MOT_IMPORT_MOTION"},{true}}},
{{{"VMD_MOT_IMPORT_MORPH"},{true}}},
{{{"VMD_MOT_IMPORT_MODEL_INFO"},{true}}},
{{{"VMD_MOT_IMPORT_IGNORE_PHYSICAL"},{true}}},
{{{"VMD_MOT_IMPORT_DELETE_PREVIOUS_ANIMATION"},{true}}},
{{{"VMD_MOT_IMPORT_DETAIL"},{false}}},
{},// DLG_VMD_MOT_IMPORT_BUTTON

{},// DLG_VMD_MOT_EXPORT_SIZE_NAME
{{{"VMD_MOT_EXPORT_SIZE"},{8.5f}}},
{},// DLG_VMD_MOT_EXPORT_OFFSET_NAME
{{{"VMD_MOT_EXPORT_OFFSET"},{0.f}}},
{{{"VMD_MOT_EXPORT_MOTION"},{true}}},
{{{"VMD_MOT_EXPORT_MORPH"},{true}}},
{{{"VMD_MOT_EXPORT_MODEL_INFO"},{true}}},
{{{"VMD_MOT_EXPORT_USE_BAKE"},{true}}},
{},// DLG_VMD_MOT_EXPORT_ROTATION_TWEEN_NAME
{{{"VMD_MOT_EXPORT_ROTATION_TWEEN"},{0}}},
{},// DLG_VMD_MOT_EXPORT_BUTTON

{},// DLG_VPD_POSE_IMPORT_BUTTON

{},// DLG_PMX_MOD_IMPORT_SIZE_NAME
{{{"PMX_MOD_IMPORT_SIZE"},{8.5f}}},
{{{"PMX_MOD_IMPORT_POLYGON"},{true}}},
{{{"PMX_MOD_IMPORT_NORMAL"},{true}}},
{{{"PMX_MOD_IMPORT_UV"},{true}}},
{{{"PMX_MOD_IMPORT_MATERIAL"},{true}}},
{{{"PMX_MOD_IMPORT_BONE"},{}}},
{{{"PMX_MOD_IMPORT_WEIGHTS"},{true}}},
{{{"PMX_MOD_IMPORT_IK"},{true}}},
{{{"PMX_MOD_IMPORT_INHERIT"},{true}}},
{{{"PMX_MOD_IMPORT_EXPRESSION"},{true}}},
{{{"PMX_MOD_IMPORT_MULTIPART"},{true}}},
{{{"PMX_MOD_IMPORT_ENGLISH"},{false}}},
{{{"PMX_MOD_IMPORT_ENGLISH_CHECK"},{false}}},
{}, // DLG_PMX_MOD_IMPORT_BUTTON

{},
{},
{},
{},
{},
{}
};

template<class T>
T ConfigManager::GetConfig(Int32 id)
{
	id -= 10000;
	if (id > 0 && id < 64)
	{
		const auto& config_item = g_init_config_LUT[id];
		auto& [config_name, config_value] = config_item.value();
		try {
			return Get().m_config[config_name].as<T>();
		}
		catch (YAML::BadConversion) {
			T& res = std::get<T>(config_value);
			Get().m_config[config_name] = res;
			return res;
		}
	}
	return {};
}

template <class T>
bool ConfigManager::SetConfig(Int32 id, const T& value)
{
	id -= 10000;
	if (id > 0 && id < 64)
	{
		const auto& config_item = g_init_config_LUT[id];
		auto& [config_name, config_value] = config_item.value();
		Get().m_config[config_name] = value;
		return true;
	}
	return false;
}

void ConfigManager::InitConfig(Int32 id)
{
	id -= 10000;
	if (id > 0 && id < 64) 
	{
		if (const auto& config_item = g_init_config_LUT[id]; config_item.has_value())
		{
			switch (auto& [config_name, config_value] = config_item.value(); config_value.index())
			{
				// bool
			case 0:
			{
				Get().m_config[config_name] = std::get<bool>(config_value);
				break;
			}
			// int
			case 1:
			{
				Get().m_config[config_name] = std::get<int>(config_value);
				break;
			}
			// float
			case 2:
			{
				Get().m_config[config_name] = std::get<float>(config_value);
				break;
			}
			default: break;
			}
		}
	}
}

void ConfigManager::InitConfigManager()
{
	auto& config = Get().m_config;
	try {
		config = YAML::LoadFile(Get().m_config_path);
	}
	catch (YAML::BadFile) {
		GePrint("Failed to load the YAML file!"_s);
		config = {};
		for (int config_id = 10000; config_id < 10063; ++config_id)
		{
			InitConfig(config_id);
		}
		std::ofstream fout(Get().m_config_path);
		if (fout.is_open()) {
			fout << config;
		}
		fout.close();
	}
}

void ConfigManager::SaveConfig()
{
	std::ofstream fout(Get().m_config_path);
	if (fout.is_open()) {
		fout << Get().m_config;
	}
	fout.close();
}
