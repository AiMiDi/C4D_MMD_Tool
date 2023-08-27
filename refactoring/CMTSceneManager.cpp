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
		// create camera
		BaseObject* vmd_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
		if (!vmd_camera)
			return nullptr;

		setting.doc->InsertObject(vmd_camera, nullptr, nullptr);

		// init camera
		vmd_camera->SetName(setting.fn.GetFileString());
		auto* vmd_camera_data = vmd_camera->GetNodeData<MMDCamera>();
		vmd_camera_data->CameraInit();

		// set camera with vmd data
		const auto& vmd_camera_key_frame_array = data->get_vmd_camera_key_frame_array();
		const auto  vmd_camera_key_frame_num = static_cast<int>(vmd_camera_key_frame_array.size());
		for (auto frame_index = int(); frame_index < vmd_camera_key_frame_num; ++frame_index)
		{
			vmd_camera_data->SetFromVMD(vmd_camera_key_frame_array[frame_index], setting.position_multiple, setting.time_offset);
		}
		vmd_camera_data->UpdateAllInterpolator();

		EventAdd();
		// set document with vmd length
		setting.doc->SetMaxTime(BaseTime( vmd_camera_key_frame_num, 1.0 ));
		setting.doc->SetTime(BaseTime{ 1.0 });
		setting.doc->SetTime(BaseTime{});

		return vmd_camera;
	}
	return nullptr;
}

BaseObject* CMTSceneManager::SaveVMDCamera(const CMTToolsSetting::CameraExport& setting, libmmd::vmd_animation* data)
{
	BaseObject* select_object = setting.doc->GetActiveObject();
	if (select_object == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return nullptr;
	}
	setting.doc->SetTime(BaseTime(0.));
	BaseObject* camera_obj = nullptr;

	// 转化对象自动销毁
	AutoFree<BaseObject> convected_camera;

	// 选择对象为普通摄像机则转化
	if (select_object->IsInstanceOf(Ocamera))
	{
		const auto convected_camera_ = ConversionCamera(CMTToolsSetting::CameraConversion{ setting.doc, 0., setting.use_rotation, select_object });
		convected_camera.Assign(convected_camera_);
		camera_obj = convected_camera_;
	}
	// 选择对象为vmd摄像机则直接使用
	else if (select_object->IsInstanceOf(ID_O_MMD_CAMERA))
	{
		camera_obj = select_object;
	}
	// 都不是则返回错误
	else
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		return nullptr;
	}
	auto* vmd_camera_data = camera_obj->GetNodeData<MMDCamera>();


	return nullptr;
}

BaseObject* CMTSceneManager::ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
{
	BaseObject* vmd_camera = MMDCamera::ConversionCamera(setting);
	EventAdd();
	setting.doc->SetTime(BaseTime{ 1.0 });
	setting.doc->SetTime(BaseTime{});
	return vmd_camera;
}

void CMTSceneManager::AddMMDCamera(BaseObject* camera)
{
	if (BaseDocument* doc = Get()->GetDocument(); doc)
	{
		if (SceneCameraArray.Find(camera, doc) == NOTOK)
		{
			SceneCameraArray.Append(camera);
		}
	}
}

CMTSceneManager* CMTSceneManager::GetSceneManager(const BaseDocument* Document)
{
	return Document->FindSceneHook(ID_SCENE_HOOK_CMT_SCENE_MANAGER)->GetNodeData<CMTSceneManager>();
}
