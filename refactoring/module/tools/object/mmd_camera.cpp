/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
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

Bool MMDCamera::CameraInit(GeListNode* node)
{
	if (!m_camera)
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
				m_camera = down_obj;
				return true;
			}
			down_obj = down_obj->GetNext();
		}

		m_camera = BaseObject::Alloc(Ocamera); 
		m_camera->SetName("Camera"_s);
		UniqueIDWriter::AddUniqueID(m_camera, "MMDCamera001"_s, ID_O_MMD_CAMERA);
		m_protection_tag = BaseTag::Alloc(Tprotection);
		m_protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
		m_protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		m_protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		m_camera->InsertTag(m_protection_tag);
		m_camera->InsertUnder(node);
	}
	return true;
}

Bool MMDCamera::SetFromVMD(const libmmd::vmd_camera_key_frame& data, const Float position_multiple, Float time_offset)
{
	const auto object = reinterpret_cast<BaseObject*>(Get());

	const auto frame_at = static_cast<int32_t>(data.get_frame_at() + time_offset);
	const auto frame_at_time = BaseTime(frame_at, 30.0);

	CTrack* tracks[m_track_count]{ nullptr };
	CCurve* curves[m_track_count]{ nullptr };

	const auto track_objects = GetTrackObjects(object);
	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < m_track_count; ++track_index)
	{
		auto& track = tracks[track_index];
		auto& track_ID = track_desc_IDs[track_index];
		const auto& track_object = track_objects[track_index];
		track = track_object->FindCTrack(track_ID);
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
	CTrack* frame_at_track = object->FindCTrack(m_frame_at_desc);
	if(!frame_at_track)
	{
		frame_at_track = CTrack::Alloc(object, m_frame_at_desc);
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
	CKey* frame_key = frame_at_curve->AddKey(frame_at_time);
	frame_key->SetValue(frame_at_curve, frame_at);

	const auto& position = data.get_position();

	auto* position_x_curve = curves[POSITION_X];
	CKey* position_x_key = position_x_curve->AddKey(frame_at_time);
	position_x_key->SetValue(position_x_curve, maxon::SafeConvert<Float>(position[0]) * position_multiple);
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_POSITION_X, frame_at, data.get_position_x_interpolator());

	auto* position_y_curve = curves[POSITION_Y];
	CKey* position_y_key = position_y_curve->AddKey(frame_at_time);
	position_y_key->SetValue(position_y_curve, maxon::SafeConvert<Float>(position[1]) * position_multiple);
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_POSITION_Y, frame_at, data.get_position_y_interpolator());

	auto* position_z_curve = curves[POSITION_Z];
	CKey* position_z_key = position_z_curve->AddKey(frame_at_time);
	position_z_key->SetValue(position_z_curve, maxon::SafeConvert<Float>(position[2]) * position_multiple);
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_POSITION_Z, frame_at, data.get_position_z_interpolator());

	const auto& rotation = data.get_rotation();

	auto* rotation_x_curve = curves[ROTATION_X];
	CKey* rotation_x_key = rotation_x_curve->AddKey(frame_at_time);
	rotation_x_key->SetValue(rotation_x_curve, maxon::SafeConvert<Float>(rotation[0]));
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_ROTATION, frame_at, data.get_rotation_interpolator());

	auto* rotation_y_curve = curves[ROTATION_Y];
	CKey* rotation_y_key = rotation_y_curve->AddKey(frame_at_time);
	rotation_y_key->SetValue(rotation_y_curve, maxon::SafeConvert<Float>(rotation[1]));
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_ROTATION, frame_at, data.get_rotation_interpolator());

	auto* rotation_z_curve = curves[ROTATION_Z];
	CKey* rotation_z_key = rotation_z_curve->AddKey(frame_at_time);
	rotation_z_key->SetValue(rotation_z_curve, maxon::SafeConvert<Float>(rotation[2]));
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_ROTATION, frame_at, data.get_rotation_interpolator());

	auto* distance_curve = curves[DISTANCE];
	CKey* distance_key = distance_curve->AddKey(frame_at_time);
	distance_key->SetValue(distance_curve, maxon::SafeConvert<Float>(data.get_distance()) * position_multiple);
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_DISTANCE, frame_at, data.get_distance_interpolator());

	auto* aov_curve = curves[AOV];
	CKey* aov_key = aov_curve->AddKey(frame_at_time);
	aov_key->SetValue(aov_curve, data.get_view_angle());
	LoadInterpolator(VMD_CAM_OBJ_INTERPOLATOR_AOV, frame_at, data.get_view_angle_interpolator());

	return true;
}

Bool MMDCamera::SetToVMD(libmmd::vmd_camera_key_frame& data, Float position_multiple, Float time_offset)
{

	return true;
}

bool MMDCamera::ConversionCameraCurve(MMDCamera* camera_data, CCurve* src_curve_position, const size_t& curve_type, const Int32& frame_count, const Float&
                                      fps)
{
	Float key_left_x = .0, key_left_y = .0, key_right_x = .0, key_right_y = .0,
		next_key_left_x = .0, next_key_left_y = .0, next_key_right_x = .0, next_key_right_y = .0;
	if (src_curve_position->GetKeyCount() != frame_count) {

		CKey* now_key, * next_key = nullptr;
		BaseTime now_key_time, next_key_time;

		BaseTime time_of_two_frames;
		Float value_of_two_frames;

		//第一帧
		if (frame_count > 0) //第一帧不是最后一帧
		{
			now_key = src_curve_position->GetKey(0);
			now_key_time = now_key->GetTime();

			next_key = src_curve_position->GetKey(1);
			next_key_time = next_key->GetTime();

			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime() - now_key_time;

			src_curve_position->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
			src_curve_position->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);

			if (!camera_data->SetInterpolator(curve_type, now_key_time.GetFrame(fps), fps,
				maxon::SafeConvert<UChar>(maxon::Abs(key_right_x / time_of_two_frames.Get()) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(key_right_y / value_of_two_frames) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x / time_of_two_frames.Get()) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y / value_of_two_frames) * 127)))
				return true;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_time = next_key_time;

			next_key = src_curve_position->GetKey(key_index + 1);
			next_key_time = next_key->GetTime();

			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime() - now_key_time;

			key_left_x = next_key_left_x;
			key_left_y = next_key_left_y;
			key_right_x = next_key_right_x;
			key_right_y = next_key_right_y;
			src_curve_position->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);

			if (!camera_data->SetInterpolator(curve_type, now_key_time.GetFrame(fps), fps,
				maxon::SafeConvert<UChar>(maxon::Abs(key_right_x / time_of_two_frames.Get()) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(key_right_y / value_of_two_frames) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x / time_of_two_frames.Get()) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y / value_of_two_frames) * 127)))
				return true;

		}
		//最后一帧
		if (!camera_data->SetInterpolator(curve_type, src_curve_position->GetKey(frame_count)->GetTime().GetFrame(fps), fps)) {
			return true;
		}
	}
	return false;
}

BaseObject* MMDCamera::ConversionCamera(const CMTToolsSetting::CameraConversion& setting)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return nullptr;
	};
	/* 获取活动文档 */
	if (setting.doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		return nullptr;
	}
	const Float fps = setting.doc->GetFps();

	BaseObject* select_object;

	if (setting.src_cam == nullptr) /* 若传入的参数非空则使用传入参数 */
	{
		/* 获取选中对象 */
		select_object = setting.doc->GetActiveObject();
		if (select_object == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return nullptr;
		}
	}
	else { /* 否则使用选择参数 */
		select_object = setting.src_cam;
	}

	/* 判断选中对象类型是否为摄像机 */
	if (select_object->GetType() != Ocamera)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		return nullptr;
	}

	/* 创建转换目标对象 */
	BaseObject* VMD_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
	if (VMD_camera == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return nullptr;
	}

	/* 创建要转化摄像机的副本，防止操作破坏原摄像机对象的数据 */
	auto* select_object_clone = reinterpret_cast<BaseObject*>(select_object->GetClone(COPYFLAGS::NO_HIERARCHY, nullptr));
	VMD_camera->SetName(select_object_clone->GetName());
	setting.doc->InsertObject(VMD_camera, nullptr, nullptr);

	/* 获取目标对象内部的数据 */
	auto* VMD_camera_data = VMD_camera->GetNodeData<MMDCamera>();
	if (!VMD_camera_data->CameraInit())
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return nullptr;
	}
	BaseObject* VMD_camera_distance = VMD_camera_data->m_camera;

	default_distance = setting.distance;

	// 将时间设置为0 
	setting.doc->SetTime(BaseTime{});

	constexpr auto src_track_count = 7;

	const Vector RelPos = select_object_clone->GetRelPos();
	const Vector RelRot = select_object_clone->GetRelRot();

	const Float src_key_default_value[src_track_count]
	{
		RelPos.x,RelPos.y,RelPos.z,
		RelRot.x,RelRot.y,RelRot.z,
		reinterpret_cast<CameraObject*>(select_object_clone)->GetAperture()
	};

	const DescID src_track_desc_IDs[src_track_count]
	{
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z),
		DescID(CAMERAOBJECT_APERTURE)
	};

	CTrack* src_tracks[src_track_count]{ nullptr };
	CCurve* src_curves[src_track_count]{ nullptr };

	// 所有参数的全部关键帧所在帧数组
	maxon::HashSet<HashTime> frame_set;

	// Init src tracks info.
	for (int track_index = 0; track_index < src_track_count; ++track_index)
	{
		auto& src_track = src_tracks[track_index];
		const auto& src_track_desc_ID = src_track_desc_IDs[track_index];

		// 确保每个参数都注册了CTrack，没有则创建一个
		src_track = select_object_clone->FindCTrack(src_track_desc_ID);
		// 没有则生成轨道
		if (src_track)
		{
			src_track = CTrack::Alloc(select_object_clone, src_track_desc_ID);
			select_object_clone->InsertTrackSorted(src_track);
		}
		// 确保生成成功
		if (!src_track)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return nullptr;
		}

		// 获取曲线对象
		auto& src_curve = src_curves[track_index];
		src_curve = src_track->GetCurve();

		// 确保获取成功
		if (!src_curve)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return nullptr;
		}
		// 添加默认值
		src_curve->AddKey(BaseTime{})->SetValue(src_curve, src_key_default_value[track_index]);

		const Int32 key_count = src_curve->GetKeyCount();
		for (Int32 key_index = 0; key_index < key_count; key_index++)
		{
			frame_set.Insert(src_curve->GetKey(key_index)->GetTime())iferr_return;
		}

		/* 确保每个参数在同一帧都注册了关键帧（根据frame_set查找） */
		for (const BaseTime& frame_time : frame_set)
		{
			if (src_curve->FindKey(frame_time) == nullptr)
			{
				src_curve->AddKeyAdaptTangent(frame_time, false);
			}
		}
	}

	// 只需循环第2到最后一个
	const Int32 frame_count = static_cast<Int32>(frame_set.GetCount()) - 1;

	constexpr auto dst_track_count = m_track_count;

	const auto& dst_track_desc_IDs = GetTrackDescIDsImpl();

	CTrack* dst_tracks[dst_track_count]{ nullptr };
	CCurve* dst_curves[dst_track_count]{ nullptr };

	for (size_t track_index = 0; track_index < dst_track_count; ++track_index)
	{
		auto& dst_track = dst_tracks[track_index];
		const auto& dst_track_desc_ID = dst_track_desc_IDs[track_index];

		// 为目标对象生成动画轨迹
		auto* dst_object = track_index < 6 ? VMD_camera : VMD_camera_distance;
		dst_track = CTrack::Alloc(dst_object, dst_track_desc_ID);

		// 确保生成成功
		if (!dst_track)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return nullptr;
		}

		// 将生成的动画轨迹插入目标对象
		dst_object->InsertTrackSorted(dst_track);

		// 获取曲线对象
		auto& dst_curve = dst_curves[track_index];
		dst_curve = dst_track->GetCurve();

		// 确保获取成功
		if (!dst_curve)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return nullptr;
		}

		// 转换移动和旋转写入对象，添加关键帧数据
		if (track_index != DISTANCE)
		{
			const auto& src_curve = src_curves[track_index];
			for (const BaseTime& frame_time : frame_set)
			{
				dst_curve->AddKey(frame_time)->SetValue(dst_curve, src_curve->FindKey(frame_time)->GetValue());
			}

			if (track_index <= POSITION_Z)
			{
				if (!ConversionCameraCurve(VMD_camera_data, src_curve, track_index, frame_count, fps))
					return nullptr;
			}
			// rotation_curve
			else if (track_index <= ROTATION_Z)
			{
				// 根据setting使用对应旋转曲线
				if (!ConversionCameraCurve(VMD_camera_data, src_curves[3 + setting.use_rotation], track_index, frame_count, fps))
					return nullptr;
			}
			// aov_curve
			else if (track_index == AOV)
			{
				if (!ConversionCameraCurve(VMD_camera_data, src_curve, VMD_CAM_OBJ_INTERPOLATOR_AOV, frame_count, fps))
					return nullptr;
			}

		}
		// distance_curve
		else
		{
			for (const BaseTime& frame_time : frame_set)
			{
				dst_curve->AddKey(frame_time)->SetValue(dst_curve, setting.distance);

				// 距离没有曲线，顺便在循环里设置线性曲线
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_INTERPOLATOR_DISTANCE, frame_time.GetFrame(fps), fps))
					return nullptr;
			}
		}
	}
	
	EventAdd();
	if (!VMD_camera_data->UpdateAllInterpolator())
		return nullptr;
	setting.doc->SetTime(BaseTime(1));
	setting.doc->SetTime(BaseTime());
	return VMD_camera;
}

Bool MMDCamera::Init(GeListNode* node)
{
	if (node == nullptr)
		return false;

	node->SetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), VMD_CAM_OBJ_INTERPOLATOR_ALL, DESCFLAGS_SET::NONE);

	InitInterpolator(node);

	return true;
}

Bool MMDCamera::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	if (m_camera)
	{
		auto* const destObject = reinterpret_cast<MMDCamera*>(dest);
		destObject->m_camera = reinterpret_cast<BaseObject*>(m_camera->GetClone(COPYFLAGS::NONE, nullptr));
		if(m_protection_tag && destObject->m_camera)
		{
			destObject->m_protection_tag = reinterpret_cast<BaseTag*>(m_protection_tag->GetClone(COPYFLAGS::NONE, nullptr));
			if(destObject->m_protection_tag)
			{
				destObject->m_camera->InsertTag(destObject->m_protection_tag);
			}
		}
	}
		
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDCamera::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (id[0].id == VMD_CAM_OBJ_SPLINE)
	{
		reinterpret_cast<SplineData*>(t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(SplineDataCallBack, nullptr);
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDCamera::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return false;
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND: {
		switch (const DescriptionCommand* dc = static_cast<DescriptionCommand*>(data); dc->_descId[0].id)
		{
		case VMD_CAM_OBJ_INIT_CURVE_BUTTON:
		{
			InitInterpolator(node);
			break;
		}
		case VMD_CAM_OBJ_REGISTER_CURVE_BUTTON:
		{
			BaseDocument* doc = node->GetDocument();
			const BaseTime time = doc->GetTime();
			RegisterKeyFrame(time.GetFrame(doc->GetFps()), node);
			doc->SetTime(BaseTime{});
			doc->SetTime(time);
			break;
		}
		case VMD_CAM_OBJ_UPDATE_CURVE_BUTTON:
		{
			UpdateAllInterpolator(node);
			break;
		}
		case VMD_CAM_OBJ_DELETE_CURVE_BUTTON:
		{
			if (QuestionDialog(IDS_MES_DELETE_CAM_CURVE))
			{
				BaseDocument* doc = node->GetDocument();
				const BaseTime time = doc->GetTime();
				DeleteKeyFrame(time.GetFrame(doc->GetFps()), node);
				doc->SetTime(BaseTime{});
				doc->SetTime(time);
			}
			break;
		}
		case VMD_CAM_OBJ_DELETE_ALL_CURVE_BUTTON:
		{
			if (QuestionDialog(IDS_MES_DELETE_CAM_ALL_CURVE))
			{
				BaseDocument* doc = node->GetDocument();
				DeleteAllKeyFrame(node);
				InitInterpolator(node);
				doc->SetTime(BaseTime{1.0});
				doc->SetTime(BaseTime{});
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	case MSG_MENUPREPARE:
	{
		if (!CameraInit(node))
		{
			return true;
		}
		node->SetParameter(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y), 85.0, DESCFLAGS_SET::NONE);
		m_camera->SetRelPos(Vector(0, 0, -382.5));
		break;
	}
	default:
		break;
	}
	return true;
}

EXECUTIONRESULT MMDCamera::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op || !doc)
	{
		return EXECUTIONRESULT::OK;
	}
	CameraInit(op);
	std::call_once(m_init_flag, AddToSceneManager, op);
	return SUPER::Execute(op, doc, bt, priority, flags);
}

MMDCamera::TrackDescIDArray MMDCamera::GetTrackDescIDsImpl()
{
	static const TrackDescIDArray track_desc_IDs
	{
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z),
		DescID(CAMERAOBJECT_APERTURE)
	};
	return track_desc_IDs;
}

void MMDCamera::AddToSceneManager(BaseObject* object)
{
	if(const auto scene_manager = CMTSceneManager::GetSceneManager(object->GetDocument()))
		scene_manager->AddMMDCamera(object);
}

inline MMDCamera::TrackDescIDArray MMDCamera::GetTrackDescIDs()
{
	return GetTrackDescIDsImpl();
}

MMDCamera::TrackObjectArray MMDCamera::GetTrackObjects(GeListNode* node)
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
		m_camera,	// DISTANCE
		m_camera	// AOV
	};
	return track_objects;
}

MMDCamera::CurrentValuesArray MMDCamera::GetCurrentValues(GeListNode* node)
{
	const auto obj = reinterpret_cast<BaseObject*>(node);

	const Vector RelPos = obj->GetRelPos();
	const Vector RelRot = obj->GetRelRot();

	const CurrentValuesArray current_values
	{
		RelPos.x,													// POSITION_X
		RelPos.y,													// POSITION_Y
		RelPos.z,													// POSITION_Z
		RelRot.x,													// ROTATION_X
		RelRot.y,													// ROTATION_Y
		RelRot.z,													// ROTATION_Z
		m_camera->GetRelPos().z,									// DISTANCE
		reinterpret_cast<CameraObject*>(m_camera)->GetAperture()	// AOV
	};

	return current_values;
}

MMDCamera::InterpolatorTrackTableArray MMDCamera::GetTrackInterpolatorMap()
{
	static constexpr InterpolatorTrackTableArray track_interpolator_map
	{
		VMD_CAM_OBJ_INTERPOLATOR_POSITION_X,
		VMD_CAM_OBJ_INTERPOLATOR_POSITION_Y,
		VMD_CAM_OBJ_INTERPOLATOR_POSITION_Z,
		VMD_CAM_OBJ_INTERPOLATOR_ROTATION,
		VMD_CAM_OBJ_INTERPOLATOR_ROTATION,
		VMD_CAM_OBJ_INTERPOLATOR_ROTATION,
		VMD_CAM_OBJ_INTERPOLATOR_DISTANCE,
		VMD_CAM_OBJ_INTERPOLATOR_AOV
	};
	return track_interpolator_map;
}
