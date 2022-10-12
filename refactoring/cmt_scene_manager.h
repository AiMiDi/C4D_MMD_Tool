/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#ifndef _CMT_SCENE_MANAGER_H_
#define _CMT_SCENE_MANAGER_H_
#include "cmt_tools_setting.h"
#include "module/MMD/vmd.h"

class SceneManager
{
	BaseDocument* m_document{};

public:
	/**
	 * \brief Default constructor function
	 */
	SceneManager()
	{
		this->Init();
	}
	/**
	 * \brief Destructor function
	 */
	~SceneManager() = default;
public:
	bool Init();

	BaseObject* LoadVMDCamera(const cmt_tools_setting::CameraImport& setting, const VMD& data);
};

#endif // !_CMT_SCENE_MANAGER_H_
