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
#include "module/tools/material/mmd_redshift_toon_material.h"
#include "module/automation/mmd_automation.h"
#include "utils/cmt_automation_protocol.hpp"
#include "utils/mmd_bone_control_util.hpp"
#include <algorithm>
#include <vector>
#if defined(CMT_ENABLE_RUNTIME_REGRESSION)
#include "utils/cmt_runtime_regression_protocol.hpp"
#include "utils/filename_util.hpp"
#include "utils/string_util.hpp"
#include <exception>
#endif

namespace
{
	void AppendVpdUnmatchedNames(String& report, const String& label, const maxon::BaseList<String>& names)
	{
		if (names.GetCount() <= 0)
			return;

		report += FormatString("\n@ (@):\n", label, String::IntToString(names.GetCount()));
		for (const String& name : names)
			report += FormatString("@ ,", name);
		report += "\n"_s;
	}
}

Bool CMTSceneManager::GetCursorInfo(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd,
	const Float x, const Float y, BaseContainer& bc)
{
	const String name = mmd_bone_control_util::GetHoveredControlName(doc, bd, x, y);
	if (name.IsEmpty())
		return SUPER::GetCursorInfo(node, doc, bd, x, y, bc);
	bc.SetString(RESULT_BUBBLEHELP, name);
	return true;
}

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
	MessageDialog(GeLoadString(IDS_MES_EXPORT_TIME_ONLY_OK, String::FloatToString(timing.GetMilliseconds())));
}

void SavePmxModelLog::LogOK()
{
	timing.Stop();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_MOD_OK,
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

void LoadVpdPoseLog::LogOK()
{
	timing.Stop();
	String report = "VPD pose import OK\n"_s;
	report += FormatString("Bones: @/@\n",
	                       String::UIntToString(matched_bone_count),
	                       String::UIntToString(imported_bone_count));
	report += FormatString("Morphs: @/@\n",
	                       String::UIntToString(matched_morph_count),
	                       String::UIntToString(imported_morph_count));
	report += FormatString("Time: @ ms\n", String::FloatToString(timing.GetMilliseconds()));
	AppendVpdUnmatchedNames(report, "Unmatched bones"_s, not_find_bone_name_list);
	AppendVpdUnmatchedNames(report, "Unmatched morphs"_s, not_find_morph_name_list);
	MessageDialog(report);
}

void LoadVpdPoseLog::LogNotMMDModelError()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + "Not MMD model.");
}

void LoadVpdPoseLog::LogSelectError()
{
	MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
}

void SaveVpdPoseLog::LogOK()
{
	timing.Stop();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_POSE_OK,
		String::UIntToString(exported_bone_count),
		String::UIntToString(exported_morph_count),
		String::FloatToString(timing.GetMilliseconds())));
}

void SaveVpdPoseLog::LogNotMMDModelError()
{
	MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_MOT_TYPE_ERR));
}

void SaveVpdPoseLog::LogSelectError()
{
	MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
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

void SavePmxModelLog::Set(const libmmd::PMXFile& file, const CMTToolsSetting::ModelExport& setting)
{
	model_name_local = file.m_info.m_modelName.c_str();
	comments_local = file.m_info.m_comment.c_str();
	model_name_universal = file.m_info.m_englishModelName.c_str();
	comments_universal = file.m_info.m_englishComment.c_str();
	vertex_data_count = setting.export_polygon ? file.m_vertices.size() : 0;
	surface_data_count = setting.export_polygon ? file.m_faces.size() : 0;
	texture_data_count = setting.export_material ? file.m_textures.size() : 0;
	material_data_count = setting.export_material ? file.m_materials.size() : 0;
	bone_data_count = setting.export_bone ? file.m_bones.size() : 0;
	morph_data_count = setting.export_expression ? file.m_morphs.size() : 0;
}

void LoadModelLog::LogOK()
{
	timing.Stop();
	// Successful imports must return to the event loop without a modal wait.
	// Full PMX comments remain on the model and are printed to the console;
	// an unattended success dialog otherwise blocks later UI/MCP requests.
	GePrint(GeLoadString(IDS_MES_IMPORT_MOD_OK,
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
	if (!setting.doc || !animation)
		return nullptr;

	// create camera
	BaseObject* vmd_camera = BaseObject::Alloc(g_mmd_camera_object_id);
	if (!vmd_camera)
		return nullptr;

	setting.doc->InsertObject(vmd_camera, nullptr, nullptr);

	// init camera
	vmd_camera->SetName(setting.fn.GetFileString());
	auto* vmd_camera_data = vmd_camera->GetNodeData<MMDCamera>();
	if (!vmd_camera_data || !vmd_camera_data->InitCamera() ||
		!vmd_camera_data->LoadVMDCamera(animation, setting))
	{
		vmd_camera->Remove();
		BaseObject::Free(vmd_camera);
		return nullptr;
	}

	// set document with vmd length
	if(animation->GetKeyCount() > 0)
	{
		const BaseTime max_time(static_cast<Float>(animation->GetMaxKeyTime()) + setting.time_offset, 30.0);
		setting.doc->SetMaxTime(maxon::Max(setting.doc->GetMaxTime(), max_time));
		setting.doc->SetLoopMaxTime(maxon::Max(setting.doc->GetLoopMaxTime(), max_time));
	}
	EventAdd();

	return vmd_camera;
}

BaseObject* CMTSceneManager::SaveVMDCamera(const CMTToolsSetting::CameraExport& setting, libmmd::VMDFile& data)
{
	if (!setting.doc)
		return nullptr;

	BaseObject* select_object = setting.doc->GetActiveObject();
	if (select_object == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return nullptr;
	}
	BaseObject* camera_obj = nullptr;

	// 转化对象自动销毁
	AutoFree<BaseObject> convected_camera{};

	// 选择对象为普通摄像机则转化
	if (select_object->IsInstanceOf(Ocamera))
	{
		// Export conversions stay detached from the document. Their lifetime is
		// limited to serialization and they never become user-visible scene objects.
		convected_camera.Set(BaseObject::Alloc(g_mmd_camera_object_id));
		camera_obj = convected_camera;
		if (!camera_obj)
			return nullptr;
		auto* camera_data = camera_obj->GetNodeData<MMDCamera>();
		if (!camera_data || !camera_data->ConversionCamera(
			CMTToolsSetting::CameraConversion{setting.doc, 0., setting.use_rotation, select_object}))
			return nullptr;
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
	if (auto* vmd_camera_data = camera_obj->GetNodeData<MMDCamera>();
		!vmd_camera_data || !vmd_camera_data->InitCamera() || !vmd_camera_data->SaveVMDCamera(data, setting))
	{
		return nullptr;
	}

	// The temporary converted camera is freed on return. Return the stable source
	// object as the success token instead of returning a dangling pointer.
	return select_object;
}

BaseObject* CMTSceneManager::ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
{
	if (!setting.doc)
		return nullptr;
	BaseObject* vmd_camera = BaseObject::Alloc(g_mmd_camera_object_id);
	if(!vmd_camera)
		return nullptr;
	auto* camera_data = vmd_camera->GetNodeData<MMDCamera>();
	if (!camera_data || !camera_data->ConversionCamera(setting))
	{
		BaseObject::Free(vmd_camera);
		return nullptr;
	}
	setting.doc->InsertObject(vmd_camera, nullptr, nullptr);
	EventAdd();
	return vmd_camera;
}

Bool CMTSceneManager::LoadVMDMotion(const CMTToolsSetting::MotionImport& setting, const libmmd::VMDFile& vmd_file, LoadVmdMotionLog& log, BaseObject*
                                    select_object, const Bool merge)
{
	if (!setting.doc || !GeIsMainThread())
		return false;
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

	auto* const model = select_object->GetNodeData<MMDModelManagerObject>();
	if (!model || select_object->GetDocument() != setting.doc)
		return false;

	const BaseTime previous_time = setting.doc->GetTime();
	const BaseTime previous_max_time = setting.doc->GetMaxTime();
	const BaseTime previous_loop_max = setting.doc->GetLoopMaxTime();
	if (!setting.doc->StartUndo())
		return false;
	// CHANGE captures the model and its child/tag substructures before mutation.
	// A failed import can roll back allocated slots, marker tracks and mode edits
	// without replacing the artist's object manually or resetting other undos.
	if (!setting.doc->AddUndo(UNDOTYPE::CHANGE, select_object))
	{
		setting.doc->EndUndo();
		return false;
	}
	Bool imported = false;
	try
	{
		imported = model->LoadVMDMotion(vmd_file, setting, log, merge);
	}
	catch (...)
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] VMD import raised an exception; rolling back the import");
	}
	if (!imported)
	{
		const Bool rolled_back = setting.doc->DoUndo(true);
		setting.doc->SetMaxTime(previous_max_time);
		setting.doc->SetLoopMaxTime(previous_loop_max);
		setting.doc->SetTime(previous_time);
		if (!rolled_back)
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] VMD import failed; document undo rollback failed");
		EventAdd();
		return false;
	}
	setting.doc->EndUndo();

	setting.doc->SetTime(BaseTime(1, 30.));
	setting.doc->SetTime(BaseTime(0, 30.));
	EventAdd();

	return true;
}

Bool CMTSceneManager::LoadVPDPose(const CMTToolsSetting::PoseImport& setting, const libmmd::VPDFile& vpd_file, LoadVpdPoseLog& log, BaseObject*
                                  select_object)
{
	if (select_object == nullptr)
		select_object = setting.doc->GetActiveObject();

	if (select_object == nullptr)
	{
		LoadVpdPoseLog::LogSelectError();
		return false;
	}

	if (!select_object->IsInstanceOf(g_mmd_model_manager_object_id))
	{
		LoadVpdPoseLog::LogNotMMDModelError();
		return false;
	}

	if (!select_object->GetNodeData<MMDModelManagerObject>()->LoadVPDPose(vpd_file, setting, log))
	{
		return false;
	}

	EventAdd();
	return true;
}

Bool CMTSceneManager::SaveVPDPose(const CMTToolsSetting::PoseExport& setting, libmmd::VPDFile& data, SaveVpdPoseLog& log,
                                  BaseObject* select_object)
{
	if (select_object == nullptr)
		select_object = setting.doc->GetActiveObject();
	if (select_object == nullptr)
	{
		SaveVpdPoseLog::LogSelectError();
		return false;
	}

	if (!select_object->IsInstanceOf(g_mmd_model_manager_object_id))
	{
		SaveVpdPoseLog::LogNotMMDModelError();
		return false;
	}

	auto* const model_manager = select_object->GetNodeData<MMDModelManagerObject>();
	if (!model_manager || !model_manager->SaveVPDPose(data, setting))
	{
		return false;
	}

	log.exported_bone_count = data.m_bones.size();
	log.exported_morph_count = data.m_morphs.size();
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
	if (setting.import_material && setting.import_material_type == CMTToolsSetting::ModelImport::material_type::RedShiftToon)
	{
		String reason;
		if (!MMDRedShiftToonMaterialAdapter::IsAvailable(reason))
		{
			GePrint(String("[MMD] ") + reason);
			return nullptr;
		}
	}
	BaseObject* object = BaseObject::Alloc(g_mmd_model_manager_object_id);
	if (!object)
		return nullptr;

	setting.doc->InsertObject(object, nullptr, nullptr);

	object->SetName(setting.fn.GetFileString());
	auto* pmx_model_data = object->GetNodeData<MMDModelManagerObject>();
	pmx_model_data->CreateManagers();
	pmx_model_data->UpdateManagers();

	std::vector<BaseMaterial*> previous_materials;
	for (BaseMaterial* m = setting.doc->GetFirstMaterial(); m; m = static_cast<BaseMaterial*>(m->GetNext()))
		previous_materials.push_back(m);

	auto remove_imported_content = [&]()
	{
		// InsertMaterial can insert at the head. A remembered tail cannot identify
		// new materials in a document that already contains artist materials.
		BaseMaterial* mat = setting.doc->GetFirstMaterial();
		while (mat)
		{
			BaseMaterial* next = static_cast<BaseMaterial*>(mat->GetNext());
			if (std::find(previous_materials.begin(), previous_materials.end(), mat) == previous_materials.end())
			{
				mat->Remove();
				BaseMaterial::Free(mat);
			}
			mat = next;
		}
		object->Remove();
		BaseObject::Free(object);
		EventAdd();
	};
	Bool loaded = false;
	try
	{
		loaded = pmx_model_data->LoadPMX(pmx_file, setting);
	}
	catch (...)
	{
		remove_imported_content();
		throw;
	}
	if (!loaded)
	{
		remove_imported_content();
		return nullptr;
	}

	EventAdd();
	if (!setting.suppress_dialogs && setting.import_material &&
		setting.import_material_type == CMTToolsSetting::ModelImport::material_type::RedShift)
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

	if (!select_object->IsInstanceOf(g_mmd_model_manager_object_id))
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		return nullptr;
	}

	auto* pmx_model_data = select_object->GetNodeData<MMDModelManagerObject>();
	if (!pmx_model_data)
		return nullptr;

	const Bool restore_edit_mode = pmx_model_data->PreparePMXExportState(setting.doc);
	const Bool saved = pmx_model_data->SavePMX(data, setting);
	pmx_model_data->FinishPMXExportState(setting.doc, restore_edit_mode);
	if (!saved)
		return nullptr;

	return select_object;
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

Bool CMTSceneManager::Message(GeListNode* node, Int32 type, void* data)
{
	if (type == cmt::automation::kTransportMessage && data && node)
	{
		auto* packet = static_cast<BaseContainer*>(data);
		if (packet->GetId() == cmt::automation::kContainerId)
		{
			// A qualified production packet is consumed here. Forwarding it to
			// SUPER can invoke generic routing; it never enters persistent data.
			production_response_ = String{};
			auto* hook = static_cast<BaseList2D*>(node);
			const Bool dispatched = cmt::automation::Dispatch(hook->GetDocument(), packet);
			production_response_ = packet->GetString(cmt::automation::kResponseJson);
			return dispatched;
		}
	}
	if (type != g_cmt_scene_manager_scene_hook_id || data || !node)
		return SUPER::Message(node, type, data);
#if defined(CMT_ENABLE_RUNTIME_REGRESSION)
	auto* hook = static_cast<BaseList2D*>(node);
	auto* request = hook->GetDataInstance();
	if (!request || request->GetInt32(cmt_regression::Protocol) != cmt_regression::kProtocolVersion)
		return false;
	request->SetBool(cmt_regression::Success, false);
	request->SetString(cmt_regression::Error, "Operation failed"_s);
	for (const Int32 field : {cmt_regression::BoneCount, cmt_regression::MorphCount,
		cmt_regression::FrameCount, cmt_regression::CameraCount})
		request->SetInt32(field, 0);
	auto* document = hook->GetDocument();
	if (!document)
		return false;
	const auto operation = static_cast<cmt_regression::Operation>(request->GetInt32(cmt_regression::Action));
	if (operation == cmt_regression::Operation::ControlHover)
	{
		BaseContainer cursor;
		GetCursorInfo(static_cast<BaseSceneHook*>(node), document, document->GetActiveBaseDraw(),
			request->GetFloat(cmt_regression::HoverX), request->GetFloat(cmt_regression::HoverY), cursor);
		request->SetString(cmt_regression::HoverName, cursor.GetString(RESULT_BUBBLEHELP));
		request->SetBool(cmt_regression::Success, true);
		request->SetString(cmt_regression::Error, String());
		return true;
	}
	if ((operation >= cmt_regression::Operation::SizingStart && operation <= cmt_regression::Operation::SizingDialogClose) ||
        (operation >= cmt_regression::Operation::SizingBatchStart && operation <= cmt_regression::Operation::SizingSceneSlotStart))
	{
		try
		{
			if (!sizing_test_session_) sizing_test_session_ = std::make_unique<cmt::sizing::HostSession>();
			auto& session = *sizing_test_session_;
			const size_t stage = static_cast<size_t>(request->GetInt32(cmt_regression::SizingStage, 2));
			Bool success = true;
            libmmd::sizing::Options sizingOptions;
            const Int32 sizingFlags = request->GetInt32(cmt_regression::SizingFlags);
            sizingOptions.stance = (sizingFlags & 1) != 0;
            sizingOptions.twist = (sizingFlags & 2) != 0;
            sizingOptions.avoidance = (sizingFlags & 4) != 0;
            sizingOptions.wristContact = (sizingFlags & 8) != 0;
            sizingOptions.fingerContact = (sizingFlags & 16) != 0;
            sizingOptions.floorContact = (sizingFlags & 32) != 0;
            sizingOptions.multiContact = (sizingFlags & 64) != 0;
			switch (operation)
			{
			case cmt_regression::Operation::SizingStart:
				success = session.Start(document->GetActiveObject(), Filename(request->GetString(cmt_regression::SizingSourcePath)),
					Filename(request->GetString(cmt_regression::Path)), sizingOptions); break;
            case cmt_regression::Operation::SizingBatchStart:
            {
                std::vector<cmt::sizing::HostInput> inputs;
                for (auto* object = document->GetFirstObject(); object; object = object->GetNext())
                    if (object->IsInstanceOf(g_mmd_model_manager_object_id))
                        inputs.push_back({object, Filename(request->GetString(cmt_regression::SizingSourcePath)),
                            Filename(request->GetString(cmt_regression::Path)), sizingOptions});
                const String camera = request->GetString(cmt_regression::SizingCameraPath);
                success = session.StartBatch(inputs, Filename(camera), {camera.IsPopulated(), 5.});
                break;
            }
            case cmt_regression::Operation::SizingSelectCharacter:
                success = session.SelectCharacter(static_cast<size_t>(request->GetInt32(cmt_regression::SizingMember))); break;
            case cmt_regression::Operation::SizingExportCamera:
                success = session.ExportCamera(Filename(request->GetString(cmt_regression::Path))); break;
            case cmt_regression::Operation::SizingApplyCamera: success = session.ApplyCamera(); break;
            case cmt_regression::Operation::SizingSceneSlotStart:
            {
                BaseObject* object = document->GetActiveObject();
                auto* model = object ? object->GetNodeData<MMDModelManagerObject>() : nullptr;
                const Int32 slot = request->GetInt32(cmt_regression::SizingMember);
                if (!model || slot < 0 || slot >= model->GetAutomationAnimationSlots().GetCount())
                { success = false; break; }
                const UInt64 identity = model->GetAutomationAnimationSlots()[slot].runtime_identity;
                success = session.StartBatch({{object, Filename(request->GetString(cmt_regression::SizingSourcePath)),
                    Filename(), sizingOptions, identity}}, Filename(), {});
                break;
            }
			case cmt_regression::Operation::SizingPoll: session.Poll(); break;
			case cmt_regression::Operation::SizingPreview:
				success = session.Preview(stage, request->GetBool(cmt_regression::SizingOverlay)); break;
			case cmt_regression::Operation::SizingApply: success = session.Apply(stage); break;
			case cmt_regression::Operation::SizingExport:
				success = session.Export(stage, Filename(request->GetString(cmt_regression::Path))); break;
			case cmt_regression::Operation::SizingCancel: session.Cancel(); break;
			case cmt_regression::Operation::SizingClose: session.ClosePreview(); break;
            case cmt_regression::Operation::SizingDialogOpen:
                if (!sizing_test_dialog_) sizing_test_dialog_ = std::make_unique<MotionSizingDialog>();
                  success = sizing_test_dialog_->Open(DLG_TYPE::ASYNC, g_cmt_command_id, -1, -1, 720, 760, 1);
                break;
            case cmt_regression::Operation::SizingDialogClose:
                if (sizing_test_dialog_) sizing_test_dialog_->Close();
                sizing_test_dialog_.reset();
                break;
			default: break;
			}
			request->SetBool(cmt_regression::SizingRunning, session.IsRunning());
			request->SetBool(cmt_regression::SizingReady, session.GetResult().success);
			request->SetString(cmt_regression::SizingSummary, session.Summary());
			request->SetBool(cmt_regression::Success, success);
			request->SetString(cmt_regression::Error, session.GetError());
			return success;
		}
		catch (const std::exception& error)
		{
			request->SetString(cmt_regression::Error, String(error.what()));
			return false;
		}
	}
	if (operation == cmt_regression::Operation::Handshake)
	{
		request->SetBool(cmt_regression::Success, true);
		request->SetString(cmt_regression::Error, String{});
		return true;
	}

	BaseObject* selected = document->GetActiveObject();
	auto* model = selected && selected->IsInstanceOf(g_mmd_model_manager_object_id)
		? selected->GetNodeData<MMDModelManagerObject>() : nullptr;
	const Filename filename(request->GetString(cmt_regression::Path));
	const std::string path = string_util::GetStdString(filename.GetString());
	Bool success = false;
	try
	{
		if (operation == cmt_regression::Operation::ImportModel)
		{
			std::vector<uint8_t> bytes;
			libmmd::PMXFile pmx;
			std::string error;
			if (!filename_util::ReadFileData(filename, bytes) ||
				!libmmd::ReadPMXFile(&pmx, bytes.data(), bytes.size(), &error))
			{
				request->SetString(cmt_regression::Error, String(error.c_str()));
				return false;
			}
			CMTToolsSetting::ModelImport setting(document);
			setting.fn = filename;
			setting.position_multiple = request->GetFloat(cmt_regression::ImportScale, 1.);
			setting.import_polygon = setting.import_normal = setting.import_uv = true;
			setting.import_material = setting.import_bone = setting.import_weights = true;
			setting.import_ik = setting.import_inherit = setting.import_expression = true;
			BaseObject* imported = LoadPMXModel(pmx, setting);
			success = imported != nullptr;
			if (imported)
				document->SetActiveObject(imported, SELECTION_NEW);
			request->SetInt32(cmt_regression::BoneCount, static_cast<Int32>(pmx.m_bones.size()));
			request->SetInt32(cmt_regression::MorphCount, static_cast<Int32>(pmx.m_morphs.size()));
		}
		else if (operation == cmt_regression::Operation::ImportMotion && model)
		{
			std::vector<uint8_t> bytes;
			libmmd::VMDFile vmd;
			if (!filename_util::ReadFileData(filename, bytes) || !libmmd::ReadVMDFile(&vmd, bytes.data(), bytes.size()))
				return false;
			CMTToolsSetting::MotionImport setting(document);
			setting.fn = filename;
			setting.position_multiple = 1.;
			setting.time_offset = request->GetFloat(cmt_regression::TimeOffset, 0.);
			setting.import_motion = request->GetBool(cmt_regression::Motion, true);
			setting.import_morph = request->GetBool(cmt_regression::Morph, true);
			setting.import_model_info = request->GetBool(cmt_regression::ModelInfo, true);
			setting.delete_previous_animation = request->GetBool(cmt_regression::ReplaceAnimation, true);
			setting.ignore_physical = request->GetBool(cmt_regression::IgnorePhysics, false);
			LoadVmdMotionLog log;
			success = LoadVMDMotion(setting, vmd, log, selected);
			request->SetInt32(cmt_regression::FrameCount, static_cast<Int32>(vmd.m_motions.size()));
		}
		else if (operation == cmt_regression::Operation::ExportModel && model)
		{
			CMTToolsSetting::ModelExport setting(document);
			setting.fn = filename;
			setting.position_multiple = 1.;
			setting.export_polygon = setting.export_normal = setting.export_uv = true;
			setting.export_material = setting.export_bone = setting.export_weights = true;
			setting.export_ik = setting.export_inherit = setting.export_expression = true;
			libmmd::PMXFile pmx;
			success = SavePMXModel(setting, pmx) && libmmd::WritePMXFile(&pmx, path.c_str());
			request->SetInt32(cmt_regression::BoneCount, static_cast<Int32>(pmx.m_bones.size()));
			request->SetInt32(cmt_regression::MorphCount, static_cast<Int32>(pmx.m_morphs.size()));
		}
		else if (operation == cmt_regression::Operation::ExportMotion && model)
		{
			CMTToolsSetting::MotionExport setting(document);
			setting.fn = filename;
			setting.position_multiple = 1.;
			setting.time_offset = request->GetFloat(cmt_regression::TimeOffset, 0.);
			setting.export_motion = request->GetBool(cmt_regression::Motion, true);
			setting.export_morph = request->GetBool(cmt_regression::Morph, true);
			setting.export_model_info = request->GetBool(cmt_regression::ModelInfo, true);
			setting.use_bake = request->GetBool(cmt_regression::Bake, false);
			libmmd::VMDFile vmd;
			success = model->SaveVMDMotion(vmd, setting) && libmmd::WriteVMDFile(&vmd, path.c_str());
			request->SetInt32(cmt_regression::FrameCount, static_cast<Int32>(vmd.m_motions.size()));
		}
		else if (operation == cmt_regression::Operation::ImportCamera)
		{
			std::vector<uint8_t> bytes;
			libmmd::VMDFile vmd;
			auto animation = std::make_unique<libmmd::VMDCameraAnimation>();
			if (!filename_util::ReadFileData(filename, bytes) || !libmmd::ReadVMDFile(&vmd, bytes.data(), bytes.size()) ||
				!animation->Create(vmd))
				return false;
			CMTToolsSetting::CameraImport setting(document);
			setting.fn = filename;
			setting.position_multiple = 1.;
			BaseObject* camera = LoadVMDCamera(setting, std::move(animation));
			success = camera != nullptr;
			if (camera)
				document->SetActiveObject(camera, SELECTION_NEW);
		}
		else if (operation == cmt_regression::Operation::ExportCamera && selected &&
			(selected->IsInstanceOf(Ocamera) || selected->IsInstanceOf(g_mmd_camera_object_id)))
		{
			CMTToolsSetting::CameraExport setting(document);
			setting.fn = filename;
			setting.position_multiple = 1.;
			setting.use_bake = request->GetBool(cmt_regression::Bake, true);
			setting.time_offset = request->GetFloat(cmt_regression::TimeOffset, 0.);
			libmmd::VMDFile vmd;
			success = SaveVMDCamera(setting, vmd) && libmmd::WriteVMDFile(&vmd, path.c_str());
			request->SetInt32(cmt_regression::CameraCount, static_cast<Int32>(vmd.m_cameras.size()));
		}
		else if (operation == cmt_regression::Operation::DeleteMorph && model)
			success = model->DeleteMorphForRegression(request->GetInt32(cmt_regression::MorphIndex));
		else if (operation == cmt_regression::Operation::SetMorphStrength && model)
			success = model->SetMorphStrengthForRegression(request->GetInt32(cmt_regression::MorphIndex),
				request->GetFloat(cmt_regression::MorphStrength));
	}
	catch (const std::exception& error)
	{
		request->SetString(cmt_regression::Error, String(error.what()));
		return false;
	}
	request->SetBool(cmt_regression::Success, success);
	if (success)
		request->SetString(cmt_regression::Error, String{});
	return success;
#else
	return SUPER::Message(node, type, data);
#endif
}

SDK2024_GetDParameter(CMTSceneManager)
{
	if (id.GetDepth() > 0 && id[0].id == cmt::automation::kResponseJson)
	{
		t_data.SetString(production_response_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	}
	return SUPER::GetDParameter(node, id, t_data, flags);
}

Bool CMTSceneManager::SetDParameter(GeListNode* node, const DescID& id, const GeData& value, DESCFLAGS_SET& flags)
{
	if (id.GetDepth() > 0 && id[0].id == cmt::automation::kResponseJson)
		return false;
	return SUPER::SetDParameter(node, id, value, flags);
}
