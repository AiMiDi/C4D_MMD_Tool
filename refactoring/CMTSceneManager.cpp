/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#include "pch.h"

#include "CMTSceneManager.h"
#include "module/tools/object/mmd_camera.h"

BaseObject* CMTSceneManager::LoadVMDCamera(const CMTToolsSetting::CameraImport& setting, const libmmd::vmd_animation* data)
{
	if(data->is_camera())
	{
		BaseObject* vmd_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
		if (!vmd_camera)
			return nullptr;
		SceneDocument->InsertObject(vmd_camera, nullptr, nullptr);

		iferr(SceneCameraList.Append(vmd_camera))
			return nullptr;

		vmd_camera->SetName(setting.fn.GetFileString());
		auto* vmd_camera_data = vmd_camera->GetNodeData<MMDCamera>();
		vmd_camera_data->CameraInit();
		

		const auto& vmd_camera_key_frame_array = data->get_vmd_camera_key_frame_array();
		const auto  vmd_camera_key_frame_num = static_cast<int>(vmd_camera_key_frame_array.size());

		const auto fps = SceneDocument->GetFps();
		for (auto frame_index = int(); frame_index < vmd_camera_key_frame_num; ++frame_index)
		{
			vmd_camera_data->SetFrom(vmd_camera_key_frame_array[frame_index], setting.position_multiple);
		}
		vmd_camera_data->UpdateAllInterpolator();

		SceneDocument->SetMaxTime(BaseTime( vmd_camera_key_frame_num, 1.0 ));

		return vmd_camera;
	}
	return nullptr;
}

CMTSceneManager& CMTSceneManager::GetSceneManager(BaseDocument* Document)
{
	return *SceneManagerMap.try_emplace(Document, std::make_unique<CMTSceneManager>(Document)).first->second;
}

Bool CMTSceneManager::RemoveSceneManager(BaseDocument* Document)
{
	if(SceneManagerMap.erase(Document) == 0)
	{
		return false;
	}
	
	return true;
}
