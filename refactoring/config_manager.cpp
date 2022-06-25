/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#include "config_manager.h"
#include <fstream>

const char* ConfigManager::getDialogElementName(const Int32 id)
{
	const char* dialog_elements_LUT[64] = {
"DLG_VMD_CAM_IMPORT_TITLE",
"DLG_VMD_CAM_IMPORT_SIZE",
"DLG_VMD_CAM_IMPORT_SIZE_NAME",
"DLG_VMD_CAM_IMPORT_OFFSET",
"DLG_VMD_CAM_IMPORT_OFFSET_NAME",
"DLG_VMD_CAM_IMPORT_BUTTON",
"DLG_VMD_CAM_EXPORT_TITLE",
"DLG_VMD_CAM_EXPORT_SIZE",
"DLG_VMD_CAM_EXPORT_SIZE_NAME",
"DLG_VMD_CAM_EXPORT_OFFSET",
"DLG_VMD_CAM_EXPORT_OFFSET_NAME",
"DLG_VMD_CAM_EXPORT_ROTATION_TWEEN_NAME",
"DLG_VMD_CAM_EXPORT_ROTATION_TWEEN",
"DLG_VMD_CAM_EXPORT_USE_BAKE",
"DLG_VMD_CAM_EXPORT_BUTTON",
"DLG_VMD_CAM_CONVER_DIS_NAME",
"DLG_VMD_CAM_CONVER_DIS",
"DLG_VMD_CAM_CONVER_ROTATION_TWEEN_NAME",
"DLG_VMD_CAM_CONVER_ROTATION_TWEEN",
"DLG_VMD_CAM_CONVER_BUTTON",
"DLG_VMD_MOT_IMPORT_SIZE_NAME",
"DLG_VMD_MOT_IMPORT_SIZE",
"DLG_VMD_MOT_IMPORT_OFFSET_NAME",
"DLG_VMD_MOT_IMPORT_OFFSET",
"DLG_VMD_MOT_IMPORT_MOTION",
"DLG_VMD_MOT_IMPORT_MORPH",
"DLG_VMD_MOT_IMPORT_MODEL_INFO",
"DLG_VMD_MOT_IMPORT_IGNORE_PHYSICAL",
"DLG_VMD_MOT_IMPORT_DELETE_PREVIOUS_ANIMATION",
"DLG_VMD_MOT_IMPORT_DETAIL",
"DLG_VMD_MOT_IMPORT_BUTTON",
"DLG_VMD_MOT_EXPORT_SIZE_NAME",
"DLG_VMD_MOT_EXPORT_SIZE",
"DLG_VMD_MOT_EXPORT_OFFSET_NAME",
"DLG_VMD_MOT_EXPORT_OFFSET",
"DLG_VMD_MOT_EXPORT_MOTION",
"DLG_VMD_MOT_EXPORT_MORPH",
"DLG_VMD_MOT_EXPORT_MODEL_INFO",
"DLG_VMD_MOT_EXPORT_USE_BAKE",
"DLG_VMD_MOT_EXPORT_ROTATION_TWEEN_NAME",
"DLG_VMD_MOT_EXPORT_ROTATION_TWEEN",
"DLG_VMD_MOT_EXPORT_BUTTON",
"DLG_VPD_POSE_IMPORT_BUTTON",
"DLG_PMX_MOD_IMPORT_SIZE_NAME",
"DLG_PMX_MOD_IMPORT_SIZE",
"DLG_PMX_MOD_IMPORT_POLYGON",
"DLG_PMX_MOD_IMPORT_NORMAL",
"DLG_PMX_MOD_IMPORT_UV",
"DLG_PMX_MOD_IMPORT_MATERIAL",
"DLG_PMX_MOD_IMPORT_BONE",
"DLG_PMX_MOD_IMPORT_WEIGHTS",
"DLG_PMX_MOD_IMPORT_IK",
"DLG_PMX_MOD_IMPORT_INHERIT",
"DLG_PMX_MOD_IMPORT_EXPRESSION",
"DLG_PMX_MOD_IMPORT_MULTIPART",
"DLG_PMX_MOD_IMPORT_ENGLISH",
"DLG_PMX_MOD_IMPORT_ENGLISH_CHECK",
"DLG_PMX_MOD_IMPORT_BUTTON",
"",
"",
"",
"",
"",
""
	};
	return dialog_elements_LUT[id - 10000];
}

ConfigManager::ConfigManager()
{
	std::string config_path((GeGetPluginResourcePath() + Filename("config.yaml")).GetString().GetCStringCopy(STRINGENCODING::UTF8));
	try {
		m_config = YAML::LoadFile(config_path);
	}
	catch (YAML::BadFile e) {
		GePrint("Failed to load the YAML file!"_s);
		m_config = {};
		

		m_config[getDialogElementName(DLG_VMD_CAM_IMPORT_SIZE)] = 8.5;
		m_config["VMD_CAM_IMPORT_OFFSET"] = 0;
		m_config["VMD_CAM_EXPORT_SIZE"] = 8.5;
		m_config["VMD_CAM_EXPORT_OFFSET"] = 0;
		m_config["VMD_CAM_EXPORT_USE_BAKE"] = true;
		m_config["VMD_CAM_EXPORT_ROTATION_TWEEN"] = 0;
		m_config["VMD_CAM_CONVER_DIS"] = 0;
		m_config["VMD_CAM_CONVER_ROTATION_TWEEN"] = 0;
		m_config["VMD_MOT_IMPORT_SIZE"] = 8.5;
		m_config["VMD_MOT_IMPORT_OFFSET"] = 0;
		m_config["VMD_MOT_IMPORT_MOTION"] = true;
		m_config["VMD_MOT_IMPORT_MORPH"] = true;
		m_config["VMD_MOT_IMPORT_MODEL_INFO"] = true;
		m_config["VMD_MOT_IMPORT_DELETE_PREVIOUS_ANIMATION"] = true;
		m_config["VMD_MOT_IMPORT_DETAIL"] = false;
		m_config["VMD_MOT_EXPORT_SIZE"] = 8.5;
		m_config["VMD_MOT_EXPORT_OFFSET"] = 0;
		m_config["VMD_MOT_EXPORT_ROTATION_TWEEN"] = 0;
		m_config["VMD_MOT_EXPORT_MOTION"] = true;
		m_config["VMD_MOT_EXPORT_MORPH"] = true;
		m_config["VMD_MOT_EXPORT_MODEL_INFO"] = true;
		m_config["VMD_MOT_EXPORT_USE_BAKE"] = true;
		m_config["PMX_MOD_IMPORT_SIZE"] = 8.5;
		m_config["PMX_MOD_IMPORT_POLYGON"] = true;
		m_config["PMX_MOD_IMPORT_NORMAL"] = true;
		m_config["PMX_MOD_IMPORT_UV"] = true;
		m_config["PMX_MOD_IMPORT_MATERIAL"] = true;
		m_config["PMX_MOD_IMPORT_BONE"] = true;
		m_config["PMX_MOD_IMPORT_WEIGHTS"] = true;
		m_config["PMX_MOD_IMPORT_IK"] = true;
		m_config["PMX_MOD_IMPORT_INHERIT"] = true;
		m_config["PMX_MOD_IMPORT_EXPRESSION"] = true;
		m_config["PMX_MOD_IMPORT_MULTIPART"] = true;
		m_config["PMX_MOD_IMPORT_ENGLISH"] = false;
		m_config["PMX_MOD_IMPORT_ENGLISH_CHECK"] = false;
		std::ofstream fout(config_path);
		if (fout.is_open()) {
			fout << m_config;
		}
	}
}
