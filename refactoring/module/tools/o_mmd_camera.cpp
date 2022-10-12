/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			o_mmd_camera.cpp
Description:	C4D MMD camera object

**************************************************************************/


#include "pch.h"
#include "o_mmd_camera.h"

#include "utils/unique_id_util.hpp"

Bool OMMDCamera::CameraInit(GeListNode* node)
{
	if (!node)
	{
		node = Get();
		if (!node)
		{
			return false;
		}
	}
	if (!m_camera)
	{
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
		UniqueIDWriter::AddUniqueID(m_camera, "001"_s, ID_O_MMD_CAMERA);
		BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
		ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
		m_camera->InsertTag(ProtectionTag);
		m_camera->InsertUnder(node);
	}
	return true;
}

bool OMMDCamera::ConversionCameraCurve(OMMDCamera* camera_data, CCurve* src_curve_position, const Int32 curve_type, const Int32 frame_count)
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

			if (!camera_data->SetInterpolator(curve_type, now_key_time.GetFrame(30.),
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

			if (!camera_data->SetInterpolator(curve_type, now_key_time.GetFrame(30.),
				maxon::SafeConvert<UChar>(maxon::Abs(key_right_x / time_of_two_frames.Get()) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(key_right_y / value_of_two_frames) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x / time_of_two_frames.Get()) * 127),
				maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y / value_of_two_frames) * 127)))
				return true;

		}
		//最后一帧
		if (!camera_data->SetInterpolator(curve_type, src_curve_position->GetKey(frame_count)->GetTime().GetFrame(30.))) {
			return true;
		}
	}
	return false;
}

BaseObject* OMMDCamera::ConversionCamera(const cmt_tools_setting::CameraConversion& setting)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return nullptr;
	};
	/* 获取活动文档 */
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		return nullptr;
	}
	BaseObject* select_object;

	if (setting.str_cam == nullptr) /* 若传入的参数非空则使用传入参数 */
	{
		/* 获取选中对象 */
		select_object = doc->GetActiveObject();
		if (select_object == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return nullptr;
		}
	}
	else { /* 否则使用选择参数 */
		select_object = setting.str_cam;
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
	doc->InsertObject(VMD_camera, nullptr, nullptr);

	/* 获取目标对象内部的数据 */
	auto* VMD_camera_data = VMD_camera->GetNodeData<OMMDCamera>();
	if (!VMD_camera_data->CameraInit())
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return nullptr;
	}
	BaseObject* VMD_camera_distance = VMD_camera_data->m_camera;

	default_distance = setting.distance;

	// 将时间设置为0 
	doc->SetTime(BaseTime{});

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

	constexpr auto dst_track_count = 8;

	const auto& dst_track_desc_IDs = m_track_desc_IDs;

	CTrack* dst_tracks[dst_track_count]{ nullptr };
	CCurve* dst_curves[dst_track_count]{ nullptr };

	for (int track_index = 0; track_index < dst_track_count; ++track_index)
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
		if (track_index != 7)
		{
			const auto& src_curve = src_curves[track_index];
			for (const BaseTime& frame_time : frame_set)
			{
				dst_curve->AddKey(frame_time)->SetValue(dst_curve, src_curve->FindKey(frame_time)->GetValue());
			}

			if (track_index <= 2)
			{
				if (!ConversionCameraCurve(VMD_camera_data, src_curve, track_index, frame_count))
					return nullptr;
			}
			// rotation_curve
			else if (track_index <= 3)
			{
				// 根据stting使用对应旋转曲线
				if (!ConversionCameraCurve(VMD_camera_data, src_curves[3 + setting.use_rotation], track_index, frame_count))
					return nullptr;
			}
			// aov_curve
			else if (track_index == 6)
			{
				if (!ConversionCameraCurve(VMD_camera_data, src_curve, VMD_CAM_OBJ_VCURVE, frame_count))
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
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_DCURVE, frame_time.GetFrame(30.)))
					return nullptr;
			}
		}
	}
	
	EventAdd();
	if (!VMD_camera_data->UpdateAllInterpolator())
		return nullptr;
	doc->SetTime(BaseTime(1));
	doc->SetTime(BaseTime());
	return VMD_camera;
}

Bool OMMDCamera::Init(GeListNode* node)
{
	if (node == nullptr)
		return false;
	node->SetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), VMD_CAM_OBJ_ACURVE, DESCFLAGS_SET::NONE);
	if (!InitInterpolator(node))
		return false;
	return true;
}

Bool OMMDCamera::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (id[0].id == VMD_CAM_OBJ_SPLINE)
	{
		reinterpret_cast<SplineData*>(t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(SplineDataCallBack, nullptr);
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool OMMDCamera::Message(GeListNode* node, Int32 type, void* data)
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
			const BaseTime time = GetActiveDocument()->GetTime();
			RegisterKeyFrame(time.GetFrame(30.), node);
			node->GetDocument()->SetTime(BaseTime());
			node->GetDocument()->SetTime(time);
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
				const BaseTime time = GetActiveDocument()->GetTime();
				DeleteKeyFrame(time.GetFrame(30.), node);
				node->GetDocument()->SetTime(BaseTime());
				node->GetDocument()->SetTime(time);
			}
			break;
		}
		case VMD_CAM_OBJ_DELETE_ALL_CURVE_BUTTON:
		{
			if (QuestionDialog(IDS_MES_DELETE_CAM_ALL_CURVE))
			{
				DeleteAllKeyFrame(node);
				this->InitInterpolator(node);
				node->GetDocument()->SetTime(BaseTime(1));
				node->GetDocument()->SetTime(BaseTime());
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	case MSG_MENUPREPARE: {
		if (!CameraInit(node))
			return true;
		node->SetParameter(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y), 85.0, DESCFLAGS_SET::NONE);
		m_camera->SetRelPos(Vector(0, 0, -382.5));
		break;
	}
	default:
		break;
	}
	return true;
}

Bool OMMDCamera::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (id[0].id == VMD_CAM_OBJ_FRAME_ON)
		return false;
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

EXECUTIONRESULT OMMDCamera::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op || !doc)
	{
		return EXECUTIONRESULT::OK;
	}
	CameraInit(op);
	return SUPER::Execute(op, doc, bt, priority, flags);
}

OMMDCameraBase::TrackDescIDSpan OMMDCamera::GetTrackDescIDs()
{
	return span_namespace::make_span(m_track_desc_IDs);
}

OMMDCameraBase::TrackObjectSpan OMMDCamera::GetTrackObjects(GeListNode* node)
{
	const auto obj = reinterpret_cast<BaseObject*>(node);
	static BaseObject* track_objcts[9];
	track_objcts[0] = obj;
	track_objcts[1] = obj;
	track_objcts[2] = obj;
	track_objcts[3] = obj;
	track_objcts[4] = obj;
	track_objcts[5] = obj;
	track_objcts[6] = m_camera;
	track_objcts[7] = m_camera;
	track_objcts[8] = obj;
	return span_namespace::make_span(track_objcts);
}

OMMDCameraBase::KeyDefaultValueSpan OMMDCamera::GetKeyDefaultValue(GeListNode* node)
{
	const auto obj = reinterpret_cast<BaseObject*>(node);

	const Vector RelPos = obj->GetRelPos();
	const Vector RelRot = obj->GetRelRot();

	static Float key_default_value[8];
	key_default_value[0] = RelPos.x;
	key_default_value[1] = RelPos.y;
	key_default_value[2] = RelPos.z;
	key_default_value[3] = RelRot.x;
	key_default_value[4] = RelRot.y;
	key_default_value[5] = RelRot.z;
	key_default_value[6] = reinterpret_cast<CameraObject*>(m_camera)->GetAperture();
	key_default_value[7] = default_distance;

	return span_namespace::make_span(key_default_value);
}

OMMDCameraBase::MapIndexSpan OMMDCamera::GetMapIndexs()
{
	static constexpr Int32 map_indexs[8]
	{
		0,1,2,3,3,3,4,5
	};
	return span_namespace::make_span(map_indexs);
}
