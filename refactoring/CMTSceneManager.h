/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#ifndef CMT_SCENE_MANAGER_H__
#define CMT_SCENE_MANAGER_H__

#include "cmt_tools_setting.h"

class CMTSceneManager final : SceneHookData
{
	INSTANCEOF(CMTSceneManager, SceneHookData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit CMTSceneManager() = default;
	/**
	 * \brief Destructor function
	 */
	~CMTSceneManager() override = default;

	static NodeData* Alloc()
	{
		return NewObjClear(CMTSceneManager);
	}

	static BaseObject* LoadVMDCamera(const CMTToolsSetting::CameraImport& setting, const libmmd::vmd_animation& data);
	static BaseObject* SaveVMDCamera(const CMTToolsSetting::CameraExport& setting, libmmd::vmd_animation* data);
	static BaseObject* ConversionCamera(const CMTToolsSetting::CameraConversion& setting);

	void AddMMDCamera(BaseObject* camera);

	static CMTSceneManager* GetSceneManager(const BaseDocument* Document);

private:
	BaseLinkArray SceneCameraArray;
	
};

#endif // !CMT_SCENE_MANAGER_H__
