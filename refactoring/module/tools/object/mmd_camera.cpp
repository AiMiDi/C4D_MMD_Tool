/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			o_mmd_camera.cpp
Description:	C4D MMD camera object

**************************************************************************/


#include "pch.h"
#include "mmd_camera.h"

#include <functional>

#include "CMTSceneManager.h"
#include "utils/unique_id_util.hpp"

MMDCamera::MMDCamera(MMDCamera&& other) noexcept
	: ObjectData()
	, camera_(other.camera_)
	, protection_tag_(other.protection_tag_)
{
	other.camera_ = nullptr;
	other.protection_tag_ = nullptr;
}

MMDCamera& MMDCamera::operator=(MMDCamera&& other) noexcept
{
	if (this != &other)
	{
		camera_ = other.camera_;
		protection_tag_ = other.protection_tag_;
		other.camera_ = nullptr;
		other.protection_tag_ = nullptr;
	}
	return *this;
}

BaseObject* MMDCamera::GetCamera() const
{
	return camera_;
}

Bool MMDCamera::InitCamera(GeListNode* node)
{
	if (!camera_)
	{
		if (!node)
		{
			node = Get();
			if (!node)
			{
				return false;
			}
		}
		auto* down_obj = reinterpret_cast<BaseObject*>(node->GetDown());
		while (down_obj)
		{
			if(down_obj->GetType() == Ocamera && UniqueIDReader::FindUniqueID(down_obj, ID_O_MMD_CAMERA))
			{
				camera_ = down_obj;
				return true;
			}
			down_obj = down_obj->GetNext();
		}

		camera_ = BaseObject::Alloc(Ocamera);
		camera_->SetName("Camera"_s);
		UniqueIDWriter::AddUniqueID(camera_, "CMT::MMDCamera"_s, ID_O_MMD_CAMERA);
		protection_tag_ = BaseTag::Alloc(Tprotection);
		protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
		protection_tag_->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		protection_tag_->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		camera_->InsertTag(protection_tag_);
		camera_->InsertUnder(node);
	}
	return true;
}

Bool MMDCamera::LoadVMDCamera(const std::unique_ptr<libmmd::VMDCameraAnimation>& animation, const CMTToolsSetting::CameraImport& setting)
{
	const auto object = reinterpret_cast<BaseObject*>(Get());
	const auto fps = setting.doc->GetFps();
	const auto max_time = BaseTime(animation->GetMaxKeyTime(), fps);
	for (BaseTime time{}; time < max_time; time = time + BaseTime(1, fps))
	{
		animation->Evaluate(static_cast<float>(time.Get()));
		const auto& camera_data = animation->GetCamera();

		std::array<CCurve*, track_count> curves{ nullptr };

		const auto track_objects = GetTrackObjects(object);
		const auto track_desc_ids = GetTrackDescIDs();

		for (auto track_index = size_t{}; track_index < track_count; ++track_index)
		{
			auto& track_id = track_desc_ids[track_index];
			const auto& track_object = track_objects[track_index];
			CTrack* track = track_object->FindCTrack(track_id);
			if (!track)
			{
				track = CTrack::Alloc(track_object, track_id);
				if (!track)
				{
					return false;
				}
				track_object->InsertTrackSorted(track);
			}

			auto& curve = curves[track_index];
			curve = track->GetCurve();
			if (!curve)
			{
				return false;
			}
		}
		CTrack* frame_at_track = object->FindCTrack(frame_at_desc);
		if (!frame_at_track)
		{
			frame_at_track = CTrack::Alloc(object, frame_at_desc);
			if (!frame_at_track)
			{
				return false;
			}
			object->InsertTrackSorted(frame_at_track);
		}
		CCurve* frame_at_curve = frame_at_track->GetCurve();
		if (!frame_at_curve)
		{
			return false;
		}
		CKey* frame_key = frame_at_curve->AddKey(time);
		frame_key->SetValue(frame_at_curve, time.GetNumerator());

		auto set_curve_value = [&time, &curves](const uint8_t& curve_index, const Float& value)
		{
			CCurve* curve = curves[curve_index];
			if (CKey* key = curve->AddKey(time); key)
			{
				key->SetValue(curve, value);
				return true;
			}
			return false;
		};

		const auto& position = camera_data.m_interest;
		if (!set_curve_value(POSITION_X, maxon::SafeConvert<Float>(position[0]) * setting.position_multiple))
			return false;
		if (!set_curve_value(POSITION_Y, maxon::SafeConvert<Float>(position[1]) * setting.position_multiple))
			return false;
		if (!set_curve_value(POSITION_Z, maxon::SafeConvert<Float>(position[2]) * setting.position_multiple))
			return false;
		const auto& rotation = camera_data.m_rotate;
		if (!set_curve_value(ROTATION_X, maxon::SafeConvert<Float>(rotation[0])))
			return false;
		if (!set_curve_value(ROTATION_Y, maxon::SafeConvert<Float>(rotation[1])))
			return false;
		if (!set_curve_value(ROTATION_Z, maxon::SafeConvert<Float>(rotation[2])))
			return false;
		if (!set_curve_value(DISTANCE, maxon::SafeConvert<Float>(camera_data.m_distance) * setting.position_multiple))
			return false;
		if (!set_curve_value(AOV, maxon::SafeConvert<Float>(camera_data.m_fov)))
			return false;
	}
	EventAdd();
	return true;
}

Bool MMDCamera::SaveVMDCamera(libmmd::VMDFile& vmd_data, const CMTToolsSetting::CameraExport& setting)
{
	const auto object = reinterpret_cast<BaseObject*>(Get());

	std::array<CCurve*, track_count> curves{ nullptr };

	const auto track_objects = GetTrackObjects(object);
	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < track_count; ++track_index)
	{
		auto& track_ID = track_desc_IDs[track_index];
		const auto& track_object = track_objects[track_index];
		CTrack* track = track_object->FindCTrack(track_ID);
		if (!track)
		{
			track = CTrack::Alloc(track_object, track_ID);
			if (!track)
			{
				return false;
			}
			track_object->InsertTrackSorted(track);
		}

		auto& curve = curves[track_index];
		curve = track->GetCurve();
		if (!curve)
		{
			return false;
		}
	}

	CTrack* frame_at_track = object->FindCTrack(frame_at_desc);
	if (!frame_at_track)
	{
		return false;
	}
	const CCurve* frame_at_curve = frame_at_track->GetCurve();
	if (!frame_at_curve)
	{
		return false;
	}
	auto& vmd_camera_key_frame_array = vmd_data.m_cameras;
	auto not_bake_func = [this, &frame_at_curve, &vmd_camera_key_frame_array, &setting, &curves]()
		{
			const Int32 frame_count = frame_at_curve->GetKeyCount();
			vmd_camera_key_frame_array.reserve(frame_count);
			for (Int32 frame_index = 0; frame_index < frame_count; ++frame_index)
			{
				BaseTime frame_at_time = frame_at_curve->GetKey(frame_index)->GetTime();
				const Int32 frame_at = frame_at_time.GetFrame(30.);

				auto get_curve_value = [&frame_at_time, &curves](const uint8_t& curve_index)
					{
						const CCurve* curve = curves[curve_index];
						if (const CKey* key = curve->FindKey(frame_at_time))
						{
							return key->GetValue();
						}
						return curve->GetValue(frame_at_time);
					};

				vmd_camera_key_frame_array.emplace_back(
					frame_at + static_cast<uint32_t>(setting.time_offset),
					maxon::SafeConvert<float>(get_curve_value(DISTANCE) * setting.position_multiple),
					glm::vec3{ maxon::SafeConvert<float>(get_curve_value(POSITION_X) * setting.position_multiple),
					maxon::SafeConvert<float>(get_curve_value(POSITION_Y) * setting.position_multiple),
					maxon::SafeConvert<float>(get_curve_value(POSITION_Z) * setting.position_multiple) },
					glm::vec3{ maxon::SafeConvert<float>(get_curve_value(ROTATION_X)),
					maxon::SafeConvert<float>(get_curve_value(ROTATION_Y)),
					maxon::SafeConvert<float>(get_curve_value(ROTATION_Z)) },
					static_cast<uint32_t>(get_curve_value(AOV)));
			}
			return true;
		};

	auto bake_func = [this, &vmd_camera_key_frame_array, &setting, &curves]()
		{
			std::vector<BaseTime> time_list{ track_count };
			std::transform(curves.begin(), curves.end(), time_list.begin(), [](const CCurve* curve) { return curve->GetEndTime(); });
			const auto max_time = *std::max_element(time_list.begin(), time_list.end());
			const auto time_step = BaseTime{ 1., 30. };
			const Int32 frame_count = max_time.GetFrame(30.) + 1;
			vmd_camera_key_frame_array.resize(frame_count);
			Int32 frame_index = 0;
			for (BaseTime time_at = {}; time_at <= max_time; time_at = time_at + time_step)
			{
				auto get_curve_value = [&time_at, &curves](const uint8_t& curve_index)
					{
						const CCurve* curve = curves[curve_index];
						return curve->GetValue(time_at);
					};
				auto& camera_key_frame = vmd_camera_key_frame_array[frame_index++];

				// frame_at
				camera_key_frame.m_frame =time_at.GetFrame(30.) + static_cast<uint32_t>(setting.time_offset);

				// position
				camera_key_frame.m_interest = glm::vec3{ maxon::SafeConvert<float>(get_curve_value(POSITION_X) * setting.position_multiple),
												maxon::SafeConvert<float>(get_curve_value(POSITION_Y) * setting.position_multiple),
												maxon::SafeConvert<float>(get_curve_value(POSITION_Z) * setting.position_multiple) };

				// rotation
				camera_key_frame.m_rotate = glm::vec3{ maxon::SafeConvert<float>(get_curve_value(ROTATION_X)),
												maxon::SafeConvert<float>(get_curve_value(ROTATION_Y)),
												maxon::SafeConvert<float>(get_curve_value(ROTATION_Z)) };
				// distance
				camera_key_frame.m_distance = maxon::SafeConvert<float>(get_curve_value(DISTANCE) * setting.position_multiple);

				// view_angle
				camera_key_frame.m_viewAngle = static_cast<uint32_t>(get_curve_value(AOV));

				// LINEAR
				camera_key_frame.m_interpolation = {
					20,20,107,107,
					20,20,107,107,
					20,20,107,107,
					20,20,107,107,
					20,20,107,107,
					20,20,107,107};
			}
			return true;
		};

	if(!(setting.use_bake ? bake_func() : not_bake_func()))
	{
		return false;
	}

	return true;
}

Bool MMDCamera::ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return false;
	};
	if (setting.doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		return false;
	}
	const Float fps = setting.doc->GetFps();

	BaseObject* select_object;
	if (setting.src_cam == nullptr)
	{
		/* 获取选中对象 */
		select_object = setting.doc->GetActiveObject();
		if (select_object == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return false;
		}
	}
	else {
		select_object = setting.src_cam;
	}

	if (select_object->GetType() != Ocamera)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		return false;
	}

	auto* select_object_clone = reinterpret_cast<BaseObject*>(select_object->GetClone(COPYFLAGS::NO_HIERARCHY, nullptr));
	reinterpret_cast<BaseObject*>(Get())->SetName(select_object_clone->GetName());

	InitCamera();

	setting.doc->SetTime(BaseTime{});

	constexpr auto src_track_count = 7;

	const DescID src_track_desc_IDs[src_track_count]
	{
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(CAMERAOBJECT_APERTURE))
	};

	std::array<CTrack*, src_track_count> src_tracks{ nullptr };
	std::array<CCurve*, src_track_count> src_curves{ nullptr };

	BaseTime start_time, end_time;

	for (size_t track_index = 0; track_index < src_tracks.size(); ++track_index)
	{
		auto& src_track = src_tracks[track_index];
		const auto& src_track_desc_ID = src_track_desc_IDs[track_index];

		src_track = select_object_clone->FindCTrack(src_track_desc_ID);
		if (!src_track)
			continue;

		auto& src_curve = src_curves[track_index];
		src_curve = src_track->GetCurve();

		if (!src_curve)
			continue;

		const auto curve_min_time = src_curve->GetStartTime();
		const auto curve_max_time = src_curve->GetEndTime();

		start_time = curve_min_time < start_time ? curve_min_time : start_time;
		end_time = curve_max_time > end_time ? curve_max_time : end_time;
	}

	const auto dst_track_desc_IDs = GetTrackDescIDs();
	const auto dst_objects = GetTrackObjects(Get());

	std::array<CTrack*, track_count> dst_tracks{ nullptr };
	std::array<CCurve*, track_count> dst_curves{ nullptr };
	const auto time_step = BaseTime{ 1., fps };

	for (size_t track_index = 0; track_index < dst_tracks.size(); ++track_index)
	{
		auto& dst_track = dst_tracks[track_index];
		const auto& dst_track_desc_ID = dst_track_desc_IDs[track_index];

		auto* dst_object = dst_objects[track_index];
		dst_track = CTrack::Alloc(dst_object, dst_track_desc_ID);

		if (!dst_track)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return false;
		}

		dst_object->InsertTrackSorted(dst_track);

		auto& dst_curve = dst_curves[track_index];
		dst_curve = dst_track->GetCurve();

		if (!dst_curve)
		{
			return false;
		}

		if (track_index != DISTANCE)
		{
			const auto& src_curve = src_curves[track_index > DISTANCE ? track_index - 1 : track_index];
			src_curve->CopyTo(dst_curve, COPYFLAGS::NONE, nullptr);
		}
		else
		{
			dst_curve->AddKey(start_time)->SetValue(dst_curve,  setting.distance);
			dst_curve->AddKey(end_time)->SetValue(dst_curve, setting.distance);
		}
	}
	EventAdd();
	return true;
}

NodeData* MMDCamera::Alloc()
{
	return NewObjClear(MMDCamera);
}

Bool MMDCamera::Init(GeListNode* node SDK2024_InitParaName)
{
	if (node == nullptr)
		return false;

	return true;
}

Bool MMDCamera::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
{
	if (camera_)
	{
		auto* const destObject = reinterpret_cast<MMDCamera*>(dest);
		destObject->camera_ = reinterpret_cast<BaseObject*>(camera_->GetClone(COPYFLAGS::NONE, nullptr));
		if(protection_tag_ && destObject->camera_)
		{
			destObject->protection_tag_ = reinterpret_cast<BaseTag*>(protection_tag_->GetClone(COPYFLAGS::NONE, nullptr));
			if(destObject->protection_tag_)
			{
				destObject->camera_->InsertTag(destObject->protection_tag_);
			}
		}
	}

	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDCamera::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return false;
	};
	if (type == MSG_MENUPREPARE)
	{
		if (!InitCamera(node))
		{
			return true;
		}
		node->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)), 85.0, DESCFLAGS_SET::NONE);
		camera_->SetRelPos(Vector(0, 0, -382.5));
	}
	return true;
}

EXECUTIONRESULT MMDCamera::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op || !doc)
	{
		return EXECUTIONRESULT::OK;
	}
	InitCamera(op);
	std::call_once(added_to_manager_flag_, AddToSceneManager, op);
	return SUPER::Execute(op, doc, bt, priority, flags);
}

Bool MMDCamera::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (!list || !op)
		return true;
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}

MMDCamera::TrackDescIDArray MMDCamera::GetTrackDescIDs()
{
	static const TrackDescIDArray track_desc_IDs
	{
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(CAMERAOBJECT_APERTURE))
	};
	return track_desc_IDs;
}

void MMDCamera::AddToSceneManager(BaseObject* object)
{
	if(const auto scene_manager = CMTSceneManager::GetSceneManager(object->GetDocument()))
		scene_manager->AddMMDCamera(object);
}

MMDCamera::TrackObjectArray MMDCamera::GetTrackObjects(GeListNode* node) const
{
	const auto object = reinterpret_cast<BaseObject*>(node);
	const TrackObjectArray track_objects
	{
		object,		// POSITION_X
		object,		// POSITION_Y
		object,		// POSITION_Z
		object,		// ROTATION_X
		object,		// ROTATION_Y
		object,		// ROTATION_Z
		camera_,	// DISTANCE
		camera_	   // AOV
	};
	return track_objects;
}
