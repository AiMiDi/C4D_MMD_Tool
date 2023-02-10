/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			cmt_tool_config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#ifndef _CMT_TOOL_CONFIG_MANAGER_H_
#define _CMT_TOOL_CONFIG_MANAGER_H_

#include "pch.h"

/**
 * \brief CMT configuration Manager. Responsible for saving GUI configuration.
 */
class CMTToolConfigManager
{
	typedef std::variant<bool, int, double> config_types;
	typedef std::tuple<const char*, config_types> confin_item_type;
	/**
	 * \brief Configuration file path.
	 */
	const std::string m_config_path{
		(GeGetPluginResourcePath() + Filename("cmt_config.yaml")).GetString().GetCStringCopy(STRINGENCODING::UTF8)
	};
	/**
	 * \brief Configuration YAML root node.
	 */
	YAML::Node m_config;
	~CMTToolConfigManager() = default;
	CMTToolConfigManager() = default;
public:
	CMTToolConfigManager(CMTToolConfigManager&&) = delete;
	void operator =(CMTToolConfigManager&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(CMTToolConfigManager)
		/**
		 * \brief Get ConfigManager instance.
		 * \return ConfigManager instance.
		 */
		static CMTToolConfigManager& Get()
	{
		static CMTToolConfigManager instance;
		return instance;
	}
	inline static constexpr int k_config_id_begin = DIG_CMT_TOOL_CAMERA_IMPORT_SIZE;
	inline static constexpr int k_config_id_end = DIG_CMT_TOOL_MODLE_IMPORT_ENGLISH_CHECK;
	inline static constexpr int k_default_config_table_size = k_config_id_end - k_config_id_begin + 1;
	/**
	* \brief Configuration entry initial value table.
	*/
	inline static constexpr confin_item_type k_default_config_table[k_default_config_table_size]
	{
		{{"DIG_CMT_TOOL_CAMERA_IMPORT_SIZE"},{8.5f}},
		{{"DIG_CMT_TOOL_CAMERA_IMPORT_OFFSET"},{0.f}},
		{{"DIG_CMT_TOOL_CAMERA_EXPORT_SIZE"},{8.5f}},
		{{"DIG_CMT_TOOL_CAMERA_EXPORT_OFFSET"},{0.f}},
		{{"DIG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN"},{0}},
		{{"DIG_CMT_TOOL_CAMERA_EXPORT_USE_BAKE"},{true}},
		{{"DIG_CMT_TOOL_CAMERA_CONVER_DIS"},{0.f}},
		{{"DIG_CMT_TOOL_CAMERA_CONV_ROTATION_TWEEN"},{0}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_SIZE"},{8.5f}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_OFFSET"},{0.f}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_MOTION"},{true}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_MORPH"},{true}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_MODEL_INFO"},{true}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_IGNORE_PHYSICAL"},{true}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_DELETE_PREVIOUS_ANIMATION"},{true}},
		{{"DIG_CMT_TOOL_MOTION_IMPORT_DETAIL"},{false}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_SIZE"},{8.5f}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_OFFSET"},{0.f}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN"},{true}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_MOTION"},{true}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_MORPH"},{true}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_MODEL_INFO"},{true}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_USE_BAKE"},{0}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_SIZE"},{8.5f}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_POLYGON"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_NORMAL"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_UV"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_MATERIAL"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_BONE"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_WEIGHTS"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_IK"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_INHERIT"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_EXPRESSION"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_MULTIPART"},{true}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_ENGLISH"},{false}},
		{{"DIG_CMT_TOOL_MODLE_IMPORT_ENGLISH_CHECK"},{false}}
	};
	/**
	 * \brief Get configuration entry value. If the configuration entry does not exist, it is generated according to the default value.
	 * \tparam T configuration entry value type.
	 * \param id configuration entry id.
	 * \return configuration entry value.
	 */
	template <class T>
	static T GetConfig(Int32 id)
	{
		id -= 10000;
		assert(id >= 0 && id < k_default_config_table_size);
		auto& [default_config_name, default_config_value] = k_default_config_table[id];
		try {
			return Get().m_config[default_config_name].as<T>();
		}
		catch (YAML::BadConversion&) {
			const T& config_value = std::get<T>(default_config_value);
			Get().m_config[default_config_name] = config_value;
			return config_value;
		}
	}
	/**
	 * \brief Set configuration entry value.
	 * \tparam T configuration entry value type.
	 * \param id configuration entry id.
	 * \param value configuration entry value.
	 */
	template <class T>
	static void SetConfig(Int32 id, const T& value)
	{
		id -= 10000;
		assert(id >= 0 && id < k_default_config_table_size);
		const auto& [default_config_name, default_config_value] = k_default_config_table[id];
		Get().m_config[default_config_name] = value;
	}
	/**
	 * \brief Initialization dialog items by config.
	 * \param dlg dialog to initialization.
	 */
	static void InitDialog(GeDialog* dlg);
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

#endif //_CMT_TOOL_CONFIG_MANAGER_H_
