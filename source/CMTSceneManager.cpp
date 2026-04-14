/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#include "CMTSceneManager.h"
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/tools/object/mmd_camera.h"
#include "module/tools/object/mmd_model_manager.h"

void IOLog::LogOutMem()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
}

void IOLog::LogReadFileErr()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
}

void IOLog::LogWriteFileErr()
{
	MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
}

void LoadVmdCameraLog::LogOK()
{
	timing.Stop();
	MessageDialog(GeLoadString(IDS_MES_IMPORT_OK, maxon::String::UIntToString(camera_frame_number), String::FloatToString(timing.GetMilliseconds())));
}

void LoadVmdCameraLog::LogNotCameraError()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR));
}

void SaveVmdCameraLog::LogOK()
{
	timing.Stop();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_OK, String::FloatToString(timing.GetMilliseconds())));
}

void ConversionVmdCameraLog::LogOK()
{
	timing.Stop();
	// MessageDialog(GeLoadString(IDS_MES_EXPORT_OK, String::FloatToString(timing.GetMilliseconds())));
}

void LoadVmdMotionLog::LogOK(const Bool detail)
{
	timing.Stop();
	String report = GeLoadString(IDS_MES_IMPORT_MOT_OK,
	                             String::UIntToString(imported_bone_count),
	                             String::UIntToString(imported_morph_count),
	                             String::UIntToString(imported_motion_count),
	                             String::FloatToString(timing.GetMilliseconds())) + "\n";
	if (detail)
	{
		report += GeLoadString(IDS_MES_IMPORT_MOT_CF_BONE, String::IntToString(not_find_bone_name_list.GetCount())) + ":\n";
		for (const String& name : not_find_bone_name_list)
		{
			report += FormatString("@ ,", name);
		}
		report += "\n" + GeLoadString(IDS_MES_IMPORT_MOT_CF_MORPH, String::IntToString(not_find_morph_name_list.GetCount())) + ":\n";
		for (const String& name : not_find_morph_name_list)
		{
			report += FormatString("@ ,", name);
		}
	}
	MessageDialog(report);
}

void LoadVmdMotionLog::LogNotMMDModelError()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + "Not MMD model.");
}

void LoadVmdMotionLog::LogNotMotionError()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
}

void LoadVmdMotionLog::LogSelectError()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
}

void SaveVmdMotionLog::LogOK()
{
	timing.Stop();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_MOT_OK,
		String::UIntToString(exported_bone_count),
		String::UIntToString(exported_morph_count),
		String::UIntToString(exported_frame_count),
		String::FloatToString(timing.GetMilliseconds())));
}

void SaveVmdMotionLog::LogNotMMDModelError()
{
	MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_MOT_TYPE_ERR));
}

void SaveVmdMotionLog::LogSelectError()
{
	MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
}

void SaveVmdMotionLog::LogNoAnimationError()
{
	MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_MOT_NO_ANIM));
}

void LoadModelLog::Set(const libmmd::PMXFile& file, const CMTToolsSetting::ModelImport& setting)
{
	model_name_local = file.m_info.m_modelName.c_str();
	comments_local = file.m_info.m_comment.c_str();
	model_name_universal = file.m_info.m_englishModelName.c_str();
	comments_universal = file.m_info.m_englishComment.c_str();
	vertex_data_count = setting.import_polygon ? file.m_vertices.size() : 0;
	surface_data_count = setting.import_polygon ? file.m_faces.size() : 0;
	texture_data_count = setting.import_material ? file.m_textures.size() : 0;
	material_data_count = setting.import_material ? file.m_materials.size() : 0;
	bone_data_count = setting.import_bone ? file.m_bones.size() : 0;
	morph_data_count = setting.import_expression ? file.m_morphs.size() : 0;
}

void LoadModelLog::LogOK()
{
	timing.Stop();
	MessageDialog(GeLoadString(IDS_MES_IMPORT_MOD_OK,
	                    model_name_local + "\n",
	                    "\n" + comments_local + "\n",
	                    model_name_universal + "\n",
	                    "\n" + comments_universal + "\n") +
		GeLoadString(IDS_MES_IMPORT_MOD_INFO_A,
		             String::UIntToString(vertex_data_count) + "\n",
		             String::UIntToString(surface_data_count) + "\n",
		             String::UIntToString(texture_data_count) + "\n",
		             String::UIntToString(material_data_count) + "\n"
		) +
		GeLoadString(IDS_MES_IMPORT_MOD_INFO_B,
		             String::UIntToString(bone_data_count) + "\n",
		             String::UIntToString(morph_data_count) + "\n",
		             String::FloatToString(timing.GetMilliseconds())));
}

BaseObject* CMTSceneManager::LoadVMDCamera(const CMTToolsSetting::CameraImport& setting, std::unique_ptr<libmmd::VMDCameraAnimation> animation)
{
	// create camera
	BaseObject* vmd_camera = BaseObject::Alloc(g_mmd_camera_object_id);
	if (!vmd_camera)
		return nullptr;

	setting.doc->InsertObject(vmd_camera, nullptr, nullptr);

	// init camera
	vmd_camera->SetName(setting.fn.GetFileString());
	auto* vmd_camera_data = vmd_camera->GetNodeData<MMDCamera>();
	vmd_camera_data->InitCamera();
	EventAdd();

	// set document with vmd length
	if(animation->GetKeyCount() > 0)
		setting.doc->SetMaxTime(maxon::Max(setting.doc->GetMaxTime(), BaseTime(animation->GetMaxKeyTime(), 30.0)));
	setting.doc->SetTime(BaseTime{ 1.0 });
	setting.doc->SetTime(BaseTime{});

	// set camera with vmd data
	vmd_camera_data->LoadVMDCamera(animation, setting);

	return vmd_camera;
}

BaseObject* CMTSceneManager::SaveVMDCamera(const CMTToolsSetting::CameraExport& setting, libmmd::VMDFile& data)
{
	BaseObject* select_object = setting.doc->GetActiveObject();
	if (select_object == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return nullptr;
	}
	setting.doc->SetTime(BaseTime(0.));
	BaseObject* camera_obj;

	// 转化对象自动销毁
	AutoFree<BaseObject> convected_camera{};

	// 选择对象为普通摄像机则转化
	if (select_object->IsInstanceOf(Ocamera))
	{
		const auto convected_camera_ = ConversionCamera(CMTToolsSetting::CameraConversion{ setting.doc, 0., setting.use_rotation, select_object });
		convected_camera.Set(convected_camera_);
		camera_obj = convected_camera_;
	}
	// 选择对象为vmd摄像机则直接使用
	else if (select_object->IsInstanceOf(g_mmd_camera_object_id))
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
	if(auto* vmd_camera_data = camera_obj->GetNodeData<MMDCamera>(); !vmd_camera_data->SaveVMDCamera(data, setting))
	{
		return nullptr;
	}

	return camera_obj;
}

BaseObject* CMTSceneManager::ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
{
	BaseObject* vmd_camera = BaseObject::Alloc(g_mmd_camera_object_id);
	if(!vmd_camera)
		return nullptr;
	if(!vmd_camera->GetNodeData<MMDCamera>()->ConversionCamera(setting))
	{
		BaseObject::Free(vmd_camera);
		return nullptr;
	}
	setting.doc->InsertObject(vmd_camera, nullptr, nullptr);
	EventAdd();
	setting.doc->SetTime(BaseTime{ 1.0 });
	setting.doc->SetTime(BaseTime{});
	return vmd_camera;
}

Bool CMTSceneManager::LoadVMDMotion(const CMTToolsSetting::MotionImport& setting, const libmmd::VMDFile& vmd_file, LoadVmdMotionLog& log, BaseObject*
                                    select_object)
{
	if (select_object == nullptr)
		select_object = setting.doc->GetActiveObject();

	if (select_object == nullptr)
	{
		LoadVmdMotionLog::LogSelectError();
		return false;
	}

	if (!select_object->IsInstanceOf(g_mmd_model_manager_object_id))
	{
		LoadVmdMotionLog::LogNotMMDModelError();
		return false;
	}

	if(!select_object->GetNodeData<MMDModelManagerObject>()->LoadVMDMotion(vmd_file, setting, log))
	{
		return false;
	}

	setting.doc->SetTime(BaseTime(1, 30.));
	setting.doc->SetTime(BaseTime(0, 30.));
	EventAdd();

	return true;
}

Bool CMTSceneManager::SaveVMDMotion(const CMTToolsSetting::MotionExport& setting, libmmd::VMDFile& data,
	SaveVmdMotionLog& log)
{
	BaseObject* select_object = setting.doc->GetActiveObject();
	if (select_object == nullptr)
	{
		SaveVmdMotionLog::LogSelectError();
		return false;
	}

	if (!select_object->IsInstanceOf(g_mmd_model_manager_object_id))
	{
		SaveVmdMotionLog::LogNotMMDModelError();
		return false;
	}

	if (!select_object->GetNodeData<MMDModelManagerObject>()->SaveVMDMotion(data, setting))
	{
		SaveVmdMotionLog::LogNoAnimationError();
		return false;
	}

	return true;
}

BaseObject* CMTSceneManager::LoadPMXModel(const libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelImport& setting)
{
	BaseObject* object = BaseObject::Alloc(g_mmd_model_manager_object_id);
	if (!object)
		return nullptr;

	setting.doc->InsertObject(object, nullptr, nullptr);

	object->SetName(setting.fn.GetFileString());
	auto* pmx_model_data = object->GetNodeData<MMDModelManagerObject>();
	pmx_model_data->CreateManagers();
	pmx_model_data->UpdateManagers();

	BaseMaterial* last_mat_before = nullptr;
	for (BaseMaterial* m = setting.doc->GetFirstMaterial(); m; m = static_cast<BaseMaterial*>(m->GetNext()))
		last_mat_before = m;

	if (!pmx_model_data->LoadPMX(pmx_file, setting))
	{
		BaseMaterial* mat = last_mat_before
			? static_cast<BaseMaterial*>(last_mat_before->GetNext())
			: setting.doc->GetFirstMaterial();
		while (mat)
		{
			BaseMaterial* next = static_cast<BaseMaterial*>(mat->GetNext());
			mat->Remove();
			BaseMaterial::Free(mat);
			mat = next;
		}
		object->Remove();
		BaseObject::Free(object);
		EventAdd();
		return nullptr;
	}

	EventAdd();
	if (setting.import_material == DLG_CMT_MATERIAL_TYPE_REDSHIFT)
	{
		CallCommand(1040218);
	}
	return object;
}

BaseObject* CMTSceneManager::SavePMXModel(const CMTToolsSetting::ModelExport& setting, libmmd::PMXFile& data)
{

	BaseObject* select_object = setting.doc->GetActiveObject();
	if (select_object == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return nullptr;
	}

	if (select_object->IsInstanceOf(g_mmd_model_manager_object_id))
	{
		if(auto* pmx_model_data = select_object->GetNodeData<MMDModelManagerObject>(); !pmx_model_data->SavePMX(data, setting))
		{
			return nullptr;
		}
	}
	else
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		return nullptr;
	}

	return nullptr;
}

void CMTSceneManager::AddMMDCamera(SDK2024_Const BaseObject* camera)
{
	if (SDK2024_Const BaseDocument* doc = Get()->GetDocument(); doc)
	{
		if (SceneCameraArray.Find(camera, doc) == NOTOK)
		{
			SceneCameraArray.Append(camera);
		}
	}
}

CMTSceneManager* CMTSceneManager::GetSceneManager(const BaseDocument* Document)
{
	return Document->FindSceneHook(g_cmt_scene_manager_scene_hook_id)->GetNodeData<CMTSceneManager>();
}
