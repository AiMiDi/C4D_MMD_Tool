/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#include "pch.h"
#include "cmt_scene_manager.h"

#include "module/tools/object/mmd_camera.h"

bool SceneManager::Init()
{
	m_document = GetActiveDocument();
	if(!m_document)
		return false;
	return true;
}

BaseObject* SceneManager::LoadVMDCamera(const cmt_tools_setting::CameraImport& setting, libmmd::vmd_animation* data) const
{
	if(data->is_camera())
	{
		BaseObject* vmd_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
		if (!vmd_camera)
			return nullptr;
		m_document->InsertObject(vmd_camera, nullptr, nullptr);

		vmd_camera->SetName(setting.fn.GetFileString());
		auto* vmd_camera_data = vmd_camera->GetNodeData<MMDCamera>();
		vmd_camera_data->CameraInit();

		const auto& vmd_camera_key_frame_array = data->get_vmd_camera_key_frame_array();
		const int  vmd_camera_key_frame_num = vmd_camera_key_frame_array.size();

		for (auto frame_index = int(); frame_index < vmd_camera_key_frame_num; ++frame_index)
		{
			vmd_camera_data->SetFrom(vmd_camera_key_frame_array[frame_index]);
		}

		return vmd_camera;
	}
	return nullptr;
}
