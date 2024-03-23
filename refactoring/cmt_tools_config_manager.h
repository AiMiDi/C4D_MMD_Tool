/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			cmt_tool_config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#ifndef CMT_TOOL_CONFIG_MANAGER_H__
#define CMT_TOOL_CONFIG_MANAGER_H__

#include "pch.h"

/**
 * \brief CMT configuration Manager. Responsible for saving GUI configuration.
 */
class CMTToolConfigManager
{
	typedef std::variant<bool, int, double> config_types;
	typedef std::tuple<const char*, config_types> confin_item_type;

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
	static CMTToolConfigManager& GetInstance()
	{
		static CMTToolConfigManager instance;
		return instance;
	}
	/**
	 * \brief Get configuration entry value. If the configuration entry does not exist, it is generated according to the default value.
	 * \tparam T configuration entry value type.
	 * \param id configuration entry id.
	 * \return configuration entry value.
	 */
	template <class T>
	T GetConfig(Int32 id)
	{
		id -= DLG_CMT_TOOL_ID_BEGIN;
		assert(id >= 0 && id < k_default_config_table_size);
		auto& [default_config_name, default_config_value] = k_default_config_table[id];
		try
		{
			return m_config[default_config_name].as<T>();
		}
		catch (YAML::BadConversion&)
		{
			const T& config_value = std::get<T>(default_config_value);
			m_config[default_config_name] = config_value;
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
	void SetConfig(Int32 id, const T& value)
	{
		id -= 10000;
		assert(id >= 0 && id < k_default_config_table_size);
		const auto& [default_config_name, default_config_value] = k_default_config_table[id];
		m_config[default_config_name] = value;
	}
	/**
	 * \brief Initialization dialog items by config.
	 * \param dlg dialog to initialization.
	 */
	void InitDialog(GeDialog* dlg);
	/**
	 * \brief Set the configuration entry to the default value.
	 * \param id configuration entry id.
	 */
	void InitConfig(Int32 id);
	/**
	 * \brief Initialization ConfigManager.
	 */
	void InitConfigManager();
	/**
	 * \brief Save the configuration file.
	 */
	void SaveConfig() const;

private:
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

	inline static constexpr int k_config_id_begin = DLG_CMT_TOOL_ID_BEGIN;
	inline static constexpr int k_config_id_end = DLG_CMT_TOOL_ID_END;
	inline static constexpr int k_default_config_table_size = k_config_id_end - k_config_id_begin;
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
		{{"DLG_CMT_TOOL_MOTION_IMPORT_BY_LOCAL_NAME"},{true}},
		{{"DIG_CMT_TOOL_MOTION_EXPORT_USE_BAKE"},{0}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_SIZE"},{8.5f}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_POLYGON"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_NORMAL"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_UV"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_MATERIAL"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_BONE"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_WEIGHTS"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_IK"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_INHERIT"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_EXPRESSION"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_MULTIPART"},{true}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_ENGLISH"},{false}},
		{{"DIG_CMT_TOOL_MODEL_IMPORT_ENGLISH_CHECK"},{false}}
	};
};

#endif //CMT_TOOL_CONFIG_MANAGER_H__
