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

class CMTSceneManager final 
{
public:
	/**
	 * \brief Default constructor function
	 */
	explicit CMTSceneManager(BaseDocument* Document) : SceneDocument(Document){}
	/**
	 * \brief Destructor function
	 */
	~CMTSceneManager() = default;

	BaseObject* LoadVMDCamera(const CMTToolsSetting::CameraImport& setting, const libmmd::vmd_animation* data);

	static CMTSceneManager& GetSceneManager(BaseDocument* Document);
	static Bool RemoveSceneManager(BaseDocument* Document);

private:
	BaseDocument* SceneDocument{};
	maxon::BaseArray<BaseObject*> SceneCameraList;
	
	inline static std::unordered_map<BaseDocument*, std::unique_ptr<CMTSceneManager>> SceneManagerMap{};
};

#endif // !_CMT_SCENE_MANAGER_H_
