/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			o_mmd_camera.cpp
Description:	C4D MMD camera object

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_camera.h"
#include "CMTSceneManager.h"
#include "tprotection.h"
#include "description/OMMDCamera.h"
#include "maxon/sortedarray.h"
#include "utils/unique_id_util.hpp"
#include "utils/time_util.hpp"
#include "utils/cmt_camera_fov.hpp"
#include <cmath>
#include <functional>
#include <limits>

namespace
{
	constexpr Float32 kVmdCameraFps = 30.0f;

	Bool IsGeneratedCameraChild(SDK2024_Const BaseObject* object)
	{
		if (!object || !object->IsInstanceOf(Ocamera))
			return false;
		const auto* metadata = object->GetDataInstance();
		return UniqueIDReader::FindUniqueID(object, g_mmd_camera_object_id) ||
			(metadata && metadata->GetBool(g_mmd_camera_object_id));
	}

	Bool MarkGeneratedCameraChild(BaseObject* object)
	{
		if (!object || !object->GetDataInstance())
			return false;
		// Cinema 4D deliberately drops AddUniqueID data in GetClone(). A role marker
		// in the generated child's persisted container survives hierarchy cloning.
		// The plugin's registered ID isolates it from ordinary camera parameters.
		auto* metadata = object->GetDataInstance();
		if (!metadata->GetBool(g_mmd_camera_object_id))
		{
			metadata->SetBool(g_mmd_camera_object_id, true);
			object->SetDirty(DIRTYFLAGS::DATA);
		}
		return UniqueIDReader::FindUniqueID(object, g_mmd_camera_object_id) ||
			UniqueIDWriter::AddUniqueID(object, "CMT::MMDCamera"_s, g_mmd_camera_object_id);
	}
}

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
	if (!node)
		node = Get();
	if (!node)
		return false;

	if (!camera_)
	{
		auto* down_obj = reinterpret_cast<BaseObject*>(node->GetDown());
		while (down_obj)
		{
			if (IsGeneratedCameraChild(down_obj))
			{
				camera_ = down_obj;
				if (!MarkGeneratedCameraChild(camera_))
					return false;
				protection_tag_ = camera_->GetTag(Tprotection);
				return EnsureCameraAnimationSchema(node);
			}
			down_obj = down_obj->GetNext();
		}

		camera_ = BaseObject::Alloc(Ocamera);
		if (!camera_)
			return false;
		camera_->SetName("Camera"_s);
		if (!MarkGeneratedCameraChild(camera_))
		{
			BaseObject::Free(camera_);
			return false;
		}
		protection_tag_ = BaseTag::Alloc(Tprotection);
		if (!protection_tag_)
		{
			BaseObject::Free(camera_);
			return false;
		}
		protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
		protection_tag_->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		protection_tag_->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		camera_->InsertTag(protection_tag_);
		camera_->InsertUnder(node);
		static_cast<BaseObject*>(node)->GetDataInstance()->SetInt32(MMD_CAMERA_ANIMATION_SCHEMA_VERSION,
			MMD_CAMERA_ANIMATION_SCHEMA_VERTICAL_FOV_RADIANS);
	}
	return EnsureCameraAnimationSchema(node);
}

Bool MMDCamera::EnsureCameraAnimationSchema(GeListNode* node)
{
	auto* object = static_cast<BaseObject*>(node);
	auto* metadata = object ? object->GetDataInstance() : nullptr;
	if (!metadata || !camera_ || !UniqueIDReader::FindUniqueID(camera_, g_mmd_camera_object_id))
		return false;
	if (metadata->GetInt32(MMD_CAMERA_ANIMATION_SCHEMA_VERSION) >= MMD_CAMERA_ANIMATION_SCHEMA_VERTICAL_FOV_RADIANS)
		return true;

	const DescID aperture_id = ConstDescID(DescLevel(CAMERAOBJECT_APERTURE));
	const DescID fov_id = ConstDescID(DescLevel(CAMERAOBJECT_FOV_VERTICAL));
	CTrack* legacy_track = camera_->FindCTrack(aperture_id);
	const CCurve* legacy_curve = legacy_track ? legacy_track->GetCurve() : nullptr;
	// Only old generated child cameras without an existing FOV track qualify.
	// Existing FOV tracks take precedence, and an ordinary artist camera is never
	// considered for migration because it has no generated-child UniqueID.
	if (!legacy_curve || legacy_curve->GetKeyCount() == 0 || camera_->FindCTrack(fov_id))
	{
		metadata->SetInt32(MMD_CAMERA_ANIMATION_SCHEMA_VERSION, MMD_CAMERA_ANIMATION_SCHEMA_VERTICAL_FOV_RADIANS);
		return true;
	}

	for (Int32 index = 0; index < legacy_curve->GetKeyCount(); ++index)
	{
		const CKey* key = legacy_curve->GetKey(index);
		if (!key || !cmt_camera_fov::IsValidRadians(cmt_camera_fov::DegreesToRadians(key->GetValue())) ||
			!std::isfinite(key->GetValueLeft()) || !std::isfinite(key->GetValueRight()))
			return false;
	}
	// Prepare a complete clone before changing the live scene. Cloning retains
	// interpolation modes, key flags, time tangents and track loop settings.
	AutoFree<CTrack> migrated_track;
	migrated_track.Set(static_cast<CTrack*>(legacy_track->GetClone(COPYFLAGS::NONE, nullptr)));
	if (!migrated_track || !migrated_track->SetDescriptionID(camera_, fov_id))
		return false;
	CCurve* migrated_curve = migrated_track->GetCurve();
	if (!migrated_curve)
		return false;
	for (Int32 index = 0; index < migrated_curve->GetKeyCount(); ++index)
	{
		CKey* key = migrated_curve->GetKey(index);
		const CKey* source_key = legacy_curve->GetKey(index);
		const Float value = source_key->GetValue();
		const Float left = source_key->GetValueLeft();
		const Float right = source_key->GetValueRight();
		key->SetValue(migrated_curve, cmt_camera_fov::DegreesToRadians(value));
		key->SetValueLeft(migrated_curve, cmt_camera_fov::DegreesToRadians(left));
		key->SetValueRight(migrated_curve, cmt_camera_fov::DegreesToRadians(right));
	}
	BaseDocument* document = object->GetDocument();
	const BaseTime time = document ? document->GetTime() : BaseTime{};
	const Float current_fov = cmt_camera_fov::DegreesToRadians(legacy_curve->GetValue(time));
	if (!cmt_camera_fov::IsValidRadians(current_fov) || !camera_->SetParameter(fov_id, current_fov, DESCFLAGS_SET::NONE))
		return false;
	camera_->InsertTrackSorted(migrated_track.Release());
	legacy_track->Remove();
	CTrack::Free(legacy_track);
	metadata->SetInt32(MMD_CAMERA_ANIMATION_SCHEMA_VERSION, MMD_CAMERA_ANIMATION_SCHEMA_VERTICAL_FOV_RADIANS);
	camera_->SetDirty(DIRTYFLAGS::DATA);
	object->SetDirty(DIRTYFLAGS::DATA);
	return true;
}

Bool MMDCamera::LoadVMDCamera(const std::unique_ptr<libmmd::VMDCameraAnimation>& animation, const CMTToolsSetting::CameraImport& setting)
{
	if (!animation || !setting.doc)
		return false;

	const auto object = reinterpret_cast<BaseObject*>(Get());
	if (!object || !InitCamera(object))
		return false;
	const Int32 max_vmd_frame = animation->GetMaxKeyTime();
	for (Int32 vmd_frame = 0; vmd_frame <= max_vmd_frame; ++vmd_frame)
	{
		const BaseTime time(static_cast<Float>(vmd_frame) + setting.time_offset, kVmdCameraFps);
		animation->Evaluate(static_cast<float>(vmd_frame));
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

		auto set_curve_value = [&time, &curves](const uint8_t& curve_index, const Float& value)
		{
			CCurve* curve = curves[curve_index];
			if (CKey* key = curve->AddKey(time); key)
			{
				key->SetValue(curve, value);
				key->SetInterpolation(curve, CINTERPOLATION::LINEAR);
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
		if (!set_curve_value(ROTATION_X, maxon::SafeConvert<Float>(rotation[1])))
			return false;
		if (!set_curve_value(ROTATION_Y, maxon::SafeConvert<Float>(rotation[0])))
			return false;
		if (!set_curve_value(ROTATION_Z, maxon::SafeConvert<Float>(rotation[2])))
			return false;
		if (!set_curve_value(DISTANCE, maxon::SafeConvert<Float>(camera_data.m_distance) * setting.position_multiple))
			return false;
		if (!cmt_camera_fov::IsValidRadians(camera_data.m_fov) ||
			!set_curve_value(AOV, maxon::SafeConvert<Float>(camera_data.m_fov)))
			return false;
	}
	EventAdd();
	return true;
}

Bool MMDCamera::SaveVMDCamera(libmmd::VMDFile& vmd_data, const CMTToolsSetting::CameraExport& setting)
{
	iferr_scope_handler
	{
		return false;
	};
	const auto object = reinterpret_cast<BaseObject*>(Get());
	if (!object || !setting.doc || !InitCamera(object) ||
		!std::isfinite(setting.time_offset) || !std::isfinite(setting.position_multiple))
		return false;

	std::array<CCurve*, track_count> curves{ nullptr };
	std::array<Float, track_count> static_values{};

	const auto track_objects = GetTrackObjects(object);
	const auto track_desc_IDs = GetTrackDescIDs();
	class KeySortedArray : public maxon::SortedArray<KeySortedArray, maxon::BaseArray<BaseTime>>
	{
	public:
		static Bool LessThan(const BaseTime& a, const BaseTime& b) { return a < b; }
		static Bool IsEqual(const BaseTime& a, const BaseTime& b) { return a == b; }
	};
	KeySortedArray sorted_key;
	{
		maxon::HashSet<HashTime> key_set;
		for (size_t track_index = 0; track_index < track_count; ++track_index)
		{
			auto& track_ID = track_desc_IDs[track_index];
			const auto& track_object = track_objects[track_index];
			GeData value;
			if (!track_object || !track_object->GetParameter(track_ID, value, DESCFLAGS_GET::NONE))
				return false;
			static_values[track_index] = value.GetFloat();
			CTrack* track = track_object->FindCTrack(track_ID);
			CCurve* curve = track ? track->GetCurve() : nullptr;
			curves[track_index] = curve;
			if (!curve)
				continue;

			const auto key_count = curve->GetKeyCount();
			for (int key_index = 0; key_index < key_count; ++key_index)
			{
				key_set.Insert(curve->GetKey(key_index)->GetTime())iferr_return;
			}
		}

		for (const auto& frame_at_time : key_set)
		{
			sorted_key.Append(frame_at_time) iferr_return;
		}
	}
	// Missing tracks retain the object's static parameter. Export must not add
	// empty tracks to the source scene or replace unanimated values with zero.
	if (sorted_key.GetCount() == 0)
	{
		sorted_key.Append(BaseTime{}) iferr_return;
	}

	std::vector<libmmd::VMDCamera> camera_keys;
	const auto append_key = [&](const BaseTime& time) -> Bool
	{
		const Float output_frame = static_cast<Float>(time.GetFrame(kVmdCameraFps)) + setting.time_offset;
		if (output_frame < 0. || output_frame > static_cast<Float>(std::numeric_limits<uint32_t>::max()))
			return false;
		const auto value = [&](size_t index)
		{
			const auto* curve = curves[index];
			return curve && curve->GetKeyCount() > 0 ? curve->GetValue(time) : static_values[index];
		};
		for (size_t index = 0; index < track_count; ++index)
			if (!std::isfinite(value(index)))
				return false;
		uint32_t angle = 0;
		if (!cmt_camera_fov::ToVmdDegrees(value(AOV), angle))
			return false;
		constexpr std::array<uint8_t, 24> linear_interpolation{
			20, 107, 20, 107, 20, 107, 20, 107, 20, 107, 20, 107,
			20, 107, 20, 107, 20, 107, 20, 107, 20, 107, 20, 107};
		camera_keys.emplace_back(static_cast<uint32_t>(output_frame),
			maxon::SafeConvert<float>(value(DISTANCE) * setting.position_multiple),
			Eigen::Vector3f(maxon::SafeConvert<float>(value(POSITION_X) * setting.position_multiple),
				maxon::SafeConvert<float>(value(POSITION_Y) * setting.position_multiple),
				maxon::SafeConvert<float>(value(POSITION_Z) * setting.position_multiple)),
			Eigen::Vector3f(maxon::SafeConvert<float>(value(ROTATION_Y)),
				maxon::SafeConvert<float>(value(ROTATION_X)), maxon::SafeConvert<float>(value(ROTATION_Z))),
			angle, 0, linear_interpolation);
		return true;
	};
	if (setting.use_bake)
	{
		Int32 last_frame = 0;
		for (const auto& time : sorted_key)
			last_frame = maxon::Max(last_frame, time.GetFrame(kVmdCameraFps));
		for (Int32 frame = 0; ; ++frame)
		{
			if (!append_key(BaseTime(frame, kVmdCameraFps)))
				return false;
			if (frame == last_frame)
				break;
		}
	}
	else
	{
		for (const auto& time : sorted_key)
			if (!append_key(time))
				return false;
	}
	vmd_data.m_header.m_header.Set("Vocaloid Motion Data 0002");
	const auto camera_name = libmmd::ConvertU16ToSjisString(u"\u30ab\u30e1\u30e9\u30fb\u7167\u660e");
	vmd_data.m_header.m_modelName.Set(camera_name.c_str());
	vmd_data.m_cameras = std::move(camera_keys);

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

	AutoFree<BaseObject> select_object_clone;
	select_object_clone.Set(static_cast<BaseObject*>(select_object->GetClone(COPYFLAGS::NO_HIERARCHY, nullptr)));
	auto* object = static_cast<BaseObject*>(Get());
	if (!select_object_clone || !object || !InitCamera())
		return false;
	object->SetName(select_object_clone->GetName());

	constexpr auto src_track_count = 7;

	const DescID src_track_desc_IDs[src_track_count]
	{
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(CAMERAOBJECT_FOV_VERTICAL))
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
			const size_t source_index = track_index > DISTANCE ? track_index - 1 : track_index;
			auto* src_curve = src_curves[source_index];
			if (src_curve && src_curve->GetKeyCount() > 0)
			{
				if (!src_curve->CopyTo(dst_curve, COPYFLAGS::NONE, nullptr))
					return false;
			}
			else
			{
				GeData value;
				// Vertical FOV is virtual and depends on document render settings.
				// Read it from the live source, whose document context is intact.
				SDK2024_Const BaseObject* parameter_source = track_index == AOV
					? select_object : static_cast<BaseObject*>(select_object_clone);
				if (!parameter_source->GetParameter(src_track_desc_IDs[source_index], value, DESCFLAGS_GET::NONE))
					return false;
				auto* key = dst_curve->AddKey(start_time);
				if (!key)
					return false;
				key->SetValue(dst_curve, value.GetFloat());
				key->SetInterpolation(dst_curve, CINTERPOLATION::LINEAR);
			}
		}
		else
		{
			auto* first_key = dst_curve->AddKey(start_time);
			if (!first_key)
				return false;
			first_key->SetValue(dst_curve, setting.distance);
			first_key->SetInterpolation(dst_curve, CINTERPOLATION::LINEAR);
			if (end_time != start_time)
			{
				auto* last_key = dst_curve->AddKey(end_time);
				if (!last_key)
					return false;
				last_key->SetValue(dst_curve, setting.distance);
				last_key->SetInterpolation(dst_curve, CINTERPOLATION::LINEAR);
			}
		}
	}
	EventAdd();
	return true;
}

NodeData* MMDCamera::Alloc()
{
	return NewObjClear(MMDCamera);
}

SDK2024_Init(MMDCamera)
{
	if (node == nullptr)
		return false;

	return true;
}

SDK2024_CopyTo(MMDCamera)
{
	auto* const destination = static_cast<MMDCamera*>(dest);
	if (!destination)
		return false;
	// C4D clones the actual child hierarchy. Runtime pointers must reconnect to
	// those children rather than refer to separately cloned, detached cameras.
	destination->camera_ = nullptr;
	destination->protection_tag_ = nullptr;

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
		Bool had_generated_camera = false;
		for (auto* child = static_cast<BaseObject*>(node->GetDown()); child; child = child->GetNext())
		{
			if (IsGeneratedCameraChild(child))
			{
				had_generated_camera = true;
				break;
			}
		}
		if (!InitCamera(node))
		{
			return true;
		}
		if (!had_generated_camera)
		{
			node->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)), 85.0, DESCFLAGS_SET::NONE);
			camera_->SetRelPos(Vector(0, 0, -382.5));
		}
	}
	return true;
}

EXECUTIONRESULT MMDCamera::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op || !doc)
	{
		return EXECUTIONRESULT::OK;
	}
	if (!InitCamera(op))
		return EXECUTIONRESULT::OK;
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
		ConstDescID(DescLevel(CAMERAOBJECT_FOV_VERTICAL))
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
