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
struct LoadVmdMotionLog
{
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	UInt64 imported_bone_count = 0;
	UInt64 imported_morph_count = 0;
	UInt64 imported_motion_count = 0;

	maxon::BaseList<String> not_find_bone_name_list;
	maxon::BaseList<String> not_find_morph_name_list;

	String log(Bool detail);
};
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

	static Bool LoadVMDMotion(const CMTToolsSetting::MotionImport& setting, const libmmd::vmd_animation& data);

	static BaseObject* LoadPMXModel(const CMTToolsSetting::ModelImport& setting, const libmmd::pmx_model& data);

	void AddMMDCamera(BaseObject* camera);

	static CMTSceneManager* GetSceneManager(const BaseDocument* Document);

private:
	BaseLinkArray SceneCameraArray;
	
};

#endif // !CMT_SCENE_MANAGER_H__
