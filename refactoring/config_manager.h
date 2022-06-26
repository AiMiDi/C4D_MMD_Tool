/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include <optional>
#include <variant>
#include <tuple>
#include "c4d.h"
#include "yaml-cpp/yaml.h"


typedef std::variant<bool, int, float> config_types;
typedef std::tuple<const char*, config_types> confin_inital_value;

enum
{
	DLG_VMD_CAM_IMPORT_TITLE = 10000,
	DLG_VMD_CAM_IMPORT_SIZE,
	DLG_VMD_CAM_IMPORT_SIZE_NAME,
	DLG_VMD_CAM_IMPORT_OFFSET,
	DLG_VMD_CAM_IMPORT_OFFSET_NAME,
	DLG_VMD_CAM_IMPORT_BUTTON,

	DLG_VMD_CAM_EXPORT_TITLE,
	DLG_VMD_CAM_EXPORT_SIZE,
	DLG_VMD_CAM_EXPORT_SIZE_NAME,
	DLG_VMD_CAM_EXPORT_OFFSET,
	DLG_VMD_CAM_EXPORT_OFFSET_NAME,
	DLG_VMD_CAM_EXPORT_ROTATION_TWEEN_NAME,
	DLG_VMD_CAM_EXPORT_ROTATION_TWEEN,
	DLG_VMD_CAM_EXPORT_USE_BAKE,
	DLG_VMD_CAM_EXPORT_BUTTON,

	DLG_VMD_CAM_CONVER_DIS_NAME,
	DLG_VMD_CAM_CONVER_DIS,
	DLG_VMD_CAM_CONVER_ROTATION_TWEEN_NAME,
	DLG_VMD_CAM_CONVER_ROTATION_TWEEN,
	DLG_VMD_CAM_CONVER_BUTTON,


	DLG_VMD_MOT_IMPORT_SIZE_NAME,
	DLG_VMD_MOT_IMPORT_SIZE,
	DLG_VMD_MOT_IMPORT_OFFSET_NAME,
	DLG_VMD_MOT_IMPORT_OFFSET,
	DLG_VMD_MOT_IMPORT_MOTION,
	DLG_VMD_MOT_IMPORT_MORPH,
	DLG_VMD_MOT_IMPORT_MODEL_INFO,
	DLG_VMD_MOT_IMPORT_IGNORE_PHYSICAL,
	DLG_VMD_MOT_IMPORT_DELETE_PREVIOUS_ANIMATION,
	DLG_VMD_MOT_IMPORT_DETAIL,
	DLG_VMD_MOT_IMPORT_BUTTON,

	DLG_VMD_MOT_EXPORT_SIZE_NAME,
	DLG_VMD_MOT_EXPORT_SIZE,
	DLG_VMD_MOT_EXPORT_OFFSET_NAME,
	DLG_VMD_MOT_EXPORT_OFFSET,
	DLG_VMD_MOT_EXPORT_MOTION,
	DLG_VMD_MOT_EXPORT_MORPH,
	DLG_VMD_MOT_EXPORT_MODEL_INFO,
	DLG_VMD_MOT_EXPORT_USE_BAKE,
	DLG_VMD_MOT_EXPORT_ROTATION_TWEEN_NAME,
	DLG_VMD_MOT_EXPORT_ROTATION_TWEEN,
	DLG_VMD_MOT_EXPORT_BUTTON,

	DLG_VPD_POSE_IMPORT_BUTTON,

	DLG_PMX_MOD_IMPORT_SIZE_NAME,
	DLG_PMX_MOD_IMPORT_SIZE,
	DLG_PMX_MOD_IMPORT_POLYGON,     /* 多边形Polygon */
	DLG_PMX_MOD_IMPORT_NORMAL,      /* 法线Normal */
	DLG_PMX_MOD_IMPORT_UV,          /* UV */
	DLG_PMX_MOD_IMPORT_MATERIAL,    /* 材质Material */
	DLG_PMX_MOD_IMPORT_BONE,        /* 骨骼Bone */
	DLG_PMX_MOD_IMPORT_WEIGHTS,     /* 权重Weights */
	DLG_PMX_MOD_IMPORT_IK,          /* IK */
	DLG_PMX_MOD_IMPORT_INHERIT,     /* 付予Inherit */
	DLG_PMX_MOD_IMPORT_EXPRESSION,  /* 表情Expression */
	DLG_PMX_MOD_IMPORT_MULTIPART,   /* 分部分Multipart */
	DLG_PMX_MOD_IMPORT_ENGLISH,
	DLG_PMX_MOD_IMPORT_ENGLISH_CHECK,
	DLG_PMX_MOD_IMPORT_BUTTON,
};

/**
 * \brief CMT configuration Manager. Responsible for saving GUI configuration.
 */
class ConfigManager
{
	/**
	 * \brief Configuration file path.
	 */
	const std::string m_config_path{
		(GeGetPluginResourcePath() + Filename("config.yaml")).GetString().GetCStringCopy(STRINGENCODING::UTF8)
	};
	/**
	 * \brief Configuration YAML root node.
	 */
	YAML::Node m_config;
	~ConfigManager() = default;
public:
	ConfigManager() = default;

	/**
	 * \brief Get ConfigManager instance.
	 * \return ConfigManager instance.
	 */
	static ConfigManager& Get()
	{
		static ConfigManager instance;
		return instance;
	}
	/**
	 * \brief Get configuration entry value. If the configuration entry does not exist, it is generated according to the default value.
	 * \tparam T configuration entry value type.
	 * \param id configuration entry id.
	 * \return configuration entry value.
	 */
	template <class T>
	static T GetConfig(Int32 id);
	/**
	 * \brief Set configuration entry value.
	 * \tparam T configuration entry value type.
	 * \param id configuration entry id.
	 * \param value configuration entry value.
	 * \return If the configuration entry exists and the setting is successful, it returns true, and the rest is false.
	 */
	template <class T>
	static bool SetConfig(Int32 id,const T& value);
	/**
	 * \brief Set the configuration entry to the default value.
	 * \param id configuration entry id.
	 */
	static void InitConfig(Int32 id);
	/**
	 * \brief Initialization ConfigManager.
	 */
	static void InitConfigManager();
	/**
	 * \brief Save the configuration file.
	 */
	static void SaveConfig();
};

#endif
