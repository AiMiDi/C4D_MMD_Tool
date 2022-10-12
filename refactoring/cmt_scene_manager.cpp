/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#include "pch.h"
#include "cmt_scene_manager.h"

#include "module/tools/o_mmd_camera.h"

bool SceneManager::Init()
{
	m_document = GetActiveDocument();
	if(!m_document)
		return false;
	return true;
}

BaseObject* SceneManager::LoadVMDCamera(const cmt_tools_setting::CameraImport& setting, const VMD& data)
{
	if(data.IsCamera())
	{
		BaseObject* vmd_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
		if (!vmd_camera)
			return nullptr;
		m_document->InsertObject(vmd_camera, nullptr, nullptr);

		vmd_camera->SetName(setting.fn.GetFileString());
		auto* vmd_camera_data = vmd_camera->GetNodeData<OMMDCamera>();
		vmd_camera_data->CameraInit();

		return vmd_camera;
	}
	return nullptr;
}
