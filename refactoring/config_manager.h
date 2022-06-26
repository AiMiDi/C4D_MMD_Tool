/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/6/25
File:			config_manager.h
Description:	Manager of plugin configuration

**************************************************************************/

#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include "pch.h"

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
