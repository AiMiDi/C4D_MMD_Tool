/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/7
File:			o_mmd_interpolator.h
Description:	C4D MMD interpolator object

**************************************************************************/

#ifndef _MMD_INTERPOLATOR_H_
#define _MMD_INTERPOLATOR_H_

#include "utils/span_util.hpp.h"
#include "module/MMD/vmd_interpolator.h"

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT = TRACK_COUNT - 1ULL>
class MMDInterpolatorNode : public NODE_DATE_TYPE
{
	INSTANCEOF(OMMDInterpolator, NODE_DATE_TYPE)
protected:
	static constexpr size_t m_interpolator_count = INTERPOLATOR_COUNT;
	static constexpr size_t m_track_count = TRACK_COUNT;

	Int32 m_spline_desc_id = 0;
	Int32 m_curve_type_desc_id = 0;
	Int32 m_frame_on_desc_id = 0;
	Int32 m_curve_type_count = 0;

	// Tween curve data
	maxon::HashMap<Int32, VMDInterpolator> m_interpolator_maps[m_interpolator_count];
private:
	// Save the previous frame to determine the update status
	Int32 m_prev_frame = -1;

	// Save the previous curve type to determine the update status
	Int32 m_prev_interpolator_type = -1;
public:
	// Callback function used to restrict SplineData
	static Bool SplineDataCallBack(Int32, const void*);

	// Get interpolator value
	Bool GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator) const;

	// Set interpolator from libmmd::vmd_interpolator
	Bool LoadInterpolator(Int32 type, Int32 frame_at, const libmmd::vmd_interpolator& vmd_interpolator);

	// Set interpolator value
	template<typename ...Args>
	Bool SetInterpolator(Int32 type, Int32 frame_on, Args&& ...args);

	// Register Keyframe
	Bool RegisterKeyFrame(Int32 frame_on, GeListNode* node = nullptr);

	// Update all tracks
	Bool UpdateAllInterpolator(GeListNode* node = nullptr);

	// Initialization tracks
	Bool InitInterpolator(GeListNode* node = nullptr) const;

	// Delete the track
	Bool DeleteKeyFrame(Int32 frame_on, GeListNode* node = nullptr);

	// Delete all tracks
	Bool DeleteAllKeyFrame(GeListNode* node = nullptr);

	// Reads the entity from the given HyperFile.
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;

	// Writes the entity to the given HyperFile.
	Bool Write(GeListNode* node, HyperFile* hf) override;

	// Copies all values from *this to *dst.
	Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override;

	// Called at the point in the priority pipeline specified by AddToExecution, or the lack thereof.
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

	// Called to add execution priorities.
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
protected:
	using TrackDescIDSpan = span_namespace::span<const DescID, TRACK_COUNT>;
	using TrackObjectSpan = span_namespace::span<BaseObject*, TRACK_COUNT>;
	using KeyDefaultValueSpan = span_namespace::span<const Float, INTERPOLATOR_COUNT>;
	using TrackInterpolatorSpan = span_namespace::span<const Int32, INTERPOLATOR_COUNT>;

	virtual TrackDescIDSpan GetTrackDescIDs() = 0;

	virtual TrackObjectSpan GetTrackObjects(GeListNode* node) = 0;

	virtual KeyDefaultValueSpan GetKeyDefaultValue(GeListNode* node) = 0;

	virtual TrackInterpolatorSpan GetTrackInterpolatorMap() = 0;
public:
	// Constructor function
	MMDInterpolatorNode(const Int32& spline_desc_id , const Int32& curve_type_desc_id, const Int32& frame_on_desc_id, const Int32& curve_type_count):
	m_spline_desc_id(spline_desc_id), m_curve_type_desc_id(curve_type_desc_id), m_frame_on_desc_id(frame_on_desc_id), m_curve_type_count(curve_type_count) {}

	// Destructor function
	~MMDInterpolatorNode() override = default;
};



// ----- Implementation -----

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::SplineDataCallBack(const Int32 cid, const void* data)
{
	// The callback function which does clamp the SplineData
	if (cid == SPLINE_CALLBACK_CORE_MESSAGE)
	{
		if (!data)
			return false;

		// Some data massaging ...
		SplineData* splineData = static_cast<const SplineDataCallbackCoreMessage*>(data)->pGUI->GetSplineData();
		if (!splineData)
			return false;


		// Now we just go over all knots and clamp them. This could also be done more elegantly
		// with line-line intersections, I am just clamping each tangent here to the interval [0, 1],
		// which effectively equates orthogonally projecting the tangents onto that "[0,  1] box". If you
		// want to scale vectors so that a handle which is outside that [0, 1] box, is scaled in such
		// manner that the handle touches the border of that box, you will have to use line-line 
		// intersections.
		const Int32 KnotCount = splineData->GetKnotCount();
		for (Int32 i = 0; i < KnotCount; i++)
		{
			// Get the current knot.
			CustomSplineKnot* knot = splineData->GetKnot(i);
			if (knot == nullptr)
				continue;
			// Tangents live in a vector space relative to their vertex, so we make the tangent vectors
			// global first and then clamp them.
			Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
			globalLeftTangent.ClampMax(Vector(127., 127., 0.));
			globalLeftTangent.ClampMin(Vector(0.0));
			Vector globalRightTangent = knot->vPos + knot->vTangentRight;
			globalRightTangent.ClampMax(Vector(127., 127., 0.));
			globalRightTangent.ClampMin(Vector(0.0));
			// And then we convert the tangents back to their local tangent space and write them back.
			knot->vTangentLeft = globalLeftTangent - knot->vPos;
			knot->vTangentRight = globalRightTangent - knot->vPos;
		}
	}
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT, TRACK_COUNT>::GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator) const
{
	if (const auto interpolator_ptr = m_interpolator_maps[type].Find(frame_on); interpolator_ptr == nullptr)
	{
		/*Set the interpolator as the default*/
		interpolator.Reset();
		return false;
	}
	else {
		interpolator = interpolator_ptr->GetValue();
	}
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT, TRACK_COUNT>::LoadInterpolator(Int32 type, Int32 frame_at, const libmmd::vmd_interpolator& vmd_interpolator)
{
	iferr_scope_handler
	{
		return false;
	};
	auto& entry = m_interpolator_maps[type].InsertEntry(frame_at)iferr_return;
	auto& interpolator = entry.GetValue();
	interpolator.Load(vmd_interpolator);
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
template <typename ... Args>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT, TRACK_COUNT>::SetInterpolator(Int32 type, Int32 frame_on, Args&&... args)
{
	iferr_scope_handler
	{
		return false;
	};
	auto* object = reinterpret_cast<BaseObject*>(this->Get());
	if (!object)
	{
		return false;
	}
	CTrack* frame_track = object->FindCTrack(DescID(m_frame_on_desc_id));
	if (frame_track == nullptr)
	{
		frame_track = CTrack::Alloc(object, DescID(m_frame_on_desc_id));
		object->InsertTrackSorted(frame_track);
	}
	CCurve* frame_curve = frame_track->GetCurve();
	if (frame_curve == nullptr)
	{
		return false;
	}
	CKey* KeyFrame_on = frame_curve->AddKey(BaseTime(frame_on, 30));
	if (KeyFrame_on == nullptr)
	{
		return false;
	}
	KeyFrame_on->SetValue(frame_curve, frame_on);
	KeyFrame_on->SetInterpolation(frame_curve, CINTERPOLATION::STEP);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	auto& entry = m_interpolator_maps[type].InsertEntry(frame_on)iferr_return;
	auto& interpolator = entry.GetValue();
	interpolator.Set(std::forward<Args&&>(args)...);
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::RegisterKeyFrame(const Int32 frame_on, GeListNode* node)
{
	iferr_scope_handler{
		ApplicationOutput(err.ToString(nullptr));
		return false;
	};

	if (!node)
	{
		node = this->Get();
		if (!node)
		{
			return false;
		}
	}

	const BaseTime time{ static_cast<Float>(frame_on), 30. };
	GeData curve_type_data;
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return true;
	}
	const GeData ge_data = bc->GetData(m_spline_desc_id);
	auto* spline = reinterpret_cast<SplineData*>(ge_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE));

	CTrack* tracks[m_track_count]{ nullptr };
	CCurve* curves[m_track_count]{ nullptr };

	const auto track_objects = GetTrackObjects(node);

	const auto key_default_value = GetKeyDefaultValue(node);

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
		if (CKey* key = curve->FindKey(time); !key)
		{
			key = curve->AddKey(time);
			if (!key)
			{
				return false;
			}
		}
		else {
			key->SetValue(curve, key_default_value[track_index]);
		}
	}

	SplineDataCallBack(SPLINE_CALLBACK_CORE_MESSAGE, spline);

	node->GetParameter(DescID(m_curve_type_desc_id), curve_type_data, DESCFLAGS_GET::NONE);

	// all curve
	if (const auto set_curve_type = curve_type_data.GetInt32(); set_curve_type == m_curve_type_count)
	{
		if (!this->SetInterpolator(set_curve_type, frame_on, spline))
			return false;
	}
	// not all curve
	else
	{
		for (int curve_type = 0; curve_type < m_curve_type_count; ++curve_type)
		{
			if (curve_type == set_curve_type)
			{
				if (!this->SetInterpolator(curve_type, frame_on, spline))
					return false;
			}
			else
			{
				if (!this->SetInterpolator(curve_type, frame_on))
					return false;
			}
		}
	}

	this->UpdateAllInterpolator(node);
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::UpdateAllInterpolator(GeListNode* node)

{
	if (!node)
	{
		node = this->Get();
		if (!node)
		{
			return false;
		}
	}
	const auto object = reinterpret_cast<BaseObject*>(node);

	CTrack* frame_track = object->FindCTrack(DescID(m_frame_on_desc_id));
	CCurve* frame_curve = frame_track->GetCurve();

	CTrack* tracks[m_interpolator_count]{ nullptr };
	CCurve* curves[m_interpolator_count]{ nullptr };

	const auto track_objects = GetTrackObjects(node);

	const auto track_desc_IDs = GetTrackDescIDs();

	const auto  track_interpolator_map = GetTrackInterpolatorMap();

	for (size_t interpolator_track_index = 0; interpolator_track_index < m_interpolator_count; ++interpolator_track_index)
	{
		auto& track = tracks[interpolator_track_index];
		const auto& track_ID = track_desc_IDs[interpolator_track_index];
		const auto& track_object = track_objects[interpolator_track_index];

		track = track_object->FindCTrack(track_ID);
		if (!track)
		{
			continue;
		}

		auto& curve = curves[interpolator_track_index];
		curve = track->GetCurve();
		if (!curve)
		{
			continue;
		}

		const Int32 key_count = frame_curve->GetKeyCount();
		for (Int32 frame_index = 0; frame_index < key_count; frame_index++)
		{
			const CKey* now_frame_key = frame_curve->GetKey(frame_index);
			auto frame = maxon::SafeConvert<Int32>(now_frame_key->GetValue());
			BaseTime now_time = now_frame_key->GetTime();
			// Add 0.01 to exclude the frame.
			const CKey* next_frame_key = frame_curve->FindKey(now_time + BaseTime(1., 1000.), nullptr, FINDANIM::RIGHT);
			if (!next_frame_key)
			{
				break;
			}
			BaseTime next_time = next_frame_key->GetTime();
			BaseTime time_of_two_frames = next_time - now_time;
			auto* interpolator_ptr = m_interpolator_maps[track_interpolator_map[interpolator_track_index]].Find(frame);
			if (!interpolator_ptr)
			{
				break;
			}
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			CKey* key = curve->FindKey(now_time);
			if (!key)
			{
				continue;
			}
			CKey* next_key = curve->FindKey(next_time);
			if (!next_key)
			{
				break;
			}
			key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			if (interpolator.IsLinear())
			{
				key->SetInterpolation(curve, CINTERPOLATION::LINEAR);
			}
			else {
				const Float value_of_two_frames = next_key->GetValue() - key->GetValue();
				next_key->SetTimeLeft(curve, time_of_two_frames * interpolator.GetTimeLeft());
				next_key->SetValueLeft(curve, value_of_two_frames * interpolator.GetValueLeft());
				key->SetTimeRight(curve, time_of_two_frames * interpolator.GetTimeRight());
				key->SetValueRight(curve, value_of_two_frames * interpolator.GetValueRight());
			}
		}
	}

	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::InitInterpolator(GeListNode* node) const
{
	if (!node)
	{
		node = this->Get();
		if (!node)
		{
			return false;
		}
	}
	const auto data = GeData(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
	if (auto* spline = reinterpret_cast<SplineData*>(data.GetCustomDataType(CUSTOMDATATYPE_SPLINE)); spline)
	{
		spline->AdaptRange(0.0, 127.0, 127.0, 0.0, 127.0, 127.0);
		spline->InsertKnot(0.0, 0.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->InsertKnot(127.0, 127.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->SetUserCallback(SplineDataCallBack, nullptr);
		CustomSplineKnot* a = spline->GetKnot(0);
		CustomSplineKnot* b = spline->GetKnot(spline->GetKnotCount() - 1);
		a->interpol = CustomSplineKnotInterpolationBezier;
		b->interpol = CustomSplineKnotInterpolationBezier;
		a->vTangentRight = Vector(20.0, 20.0, 0.0);
		b->vTangentLeft = Vector(-20.0, -20., 0.0);
	}
	reinterpret_cast<BaseList2D*>(node)->GetDataInstance()->SetData(m_curve_type_desc_id, data);
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::DeleteKeyFrame(Int32 frame_on, GeListNode* node)
{
	if (!node)
	{
		node = this->Get();
		if (!node)
		{
			return false;
		}
	}

	const BaseTime time(frame_on, this->GetDocument(node)->GetFps());

	for (auto& interpolator_map : m_interpolator_maps)
	{
		if (const auto interpolator_ptr = interpolator_map.Find(frame_on); interpolator_ptr != nullptr)
		{
			interpolator_map.Erase(interpolator_ptr);
		}
	}

	const auto track_objects = GetTrackObjects(node);

	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < m_interpolator_count; ++track_index)
	{
		const auto& track_ID = track_desc_IDs[track_index];
		const auto& track_object = track_objects[track_index];

		auto* track = track_object->FindCTrack(track_ID);
		if (!track)
		{
			continue;
		}
		auto* curve = track->GetCurve();
		if (!curve)
		{
			continue;
		}
		auto key = curve->FindKey(time);
		CKey::Free(key);
	}
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::DeleteAllKeyFrame(GeListNode* node)
{
	if (!node)
	{
		node = this->Get();
		if (!node)
		{
			return false;
		}
	}
	for (auto& map : m_interpolator_maps)
	{
		map.Reset();
	}

	const auto track_objects = GetTrackObjects(node);

	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < m_interpolator_count; ++track_index)
	{
		const auto& track_ID = track_desc_IDs[track_index];
		const auto& track_object = track_objects[track_index];

		auto* track = track_object->FindCTrack(track_ID);
		if (!track)
		{
			continue;
		}
		CTrack::Free(track);
	}
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		ApplicationOutput(err.ToString(nullptr));
		return false;
	};

	if (!hf->ReadInt32(&this->m_prev_frame))
		return false;
	if (!hf->ReadInt32(&this->m_prev_interpolator_type))
		return false;

	for (auto& interpolator_map : m_interpolator_maps)
	{
		Int32 count = 0;
		if (!hf->ReadInt32(&count))
			return false;
		for (Int32 i = 0; i < count; i++)
		{
			VMDInterpolator interpolator;
			Int	size = sizeof interpolator;
			void* data = &interpolator;
			Int32 TempIndex = 0;
			if (!hf->ReadInt32(&TempIndex))
				return false;
			if (!hf->ReadMemory(&data, &size))
				return false;
			interpolator_map.Insert(TempIndex, std::move(interpolator)) iferr_return;
		}
	}
	return SUPER::Read(node, hf, level);
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::Write(GeListNode* node, HyperFile* hf)
{
	if (!hf->WriteInt32(this->m_prev_frame))
		return false;
	if (!hf->WriteInt32(this->m_prev_interpolator_type))
		return false;

	for (const auto& interpolator_map : m_interpolator_maps)
	{
		if (const auto count = static_cast<Int32>(interpolator_map.GetCount()); !hf->WriteInt32(count))
			return false;

		for (const auto& entry : interpolator_map)
		{
			if (!hf->WriteInt32(entry.GetKey()))
				return false;
			const auto& interpolator = entry.GetValue();
			if (!hf->WriteMemory(&interpolator, sizeof interpolator))
				return false;
		}
	}

	return SUPER::Write(node, hf);
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::CopyTo(NodeData* dest, GeListNode* snode,
	GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	iferr_scope_handler{
		ApplicationOutput(err.ToString(nullptr));
		return false;
	};

	auto* const destObject = reinterpret_cast<MMDInterpolatorNode*>(dest);
	if (!destObject)
	{
		return false;
	}
	destObject->m_prev_frame = this->m_prev_frame;
	destObject->m_prev_interpolator_type = this->m_prev_interpolator_type;

	for (size_t map_index = 0; map_index < m_interpolator_count; ++map_index)
	{
		destObject->m_interpolator_maps[map_index].CopyFrom(m_interpolator_maps[map_index])iferr_return;
	}

	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
EXECUTIONRESULT MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::Execute(BaseObject* op, BaseDocument* doc,
	BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op || !doc)
	{
		return EXECUTIONRESULT::OK;
	}

	GeData data;
	op->GetParameter(DescID(m_frame_on_desc_id), data, DESCFLAGS_GET::NONE);
	const Int32 frame_on = data.GetInt32();
	op->GetParameter(DescID(m_curve_type_desc_id), data, DESCFLAGS_GET::NONE);


	BaseContainer* bc = op->GetDataInstance();
	if (bc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}
	const GeData spline_data = bc->GetData(m_spline_desc_id);
	auto* spline = reinterpret_cast<SplineData*>(spline_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE));
	if (spline == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const Int32 left_knot_index = spline->GetKnotCount() - 1;

	constexpr Vector def_tangent_left{ -20., -20., 0. };
	constexpr Vector def_tangent_right{ 20., 20., 0. };

	if (const Int32 interpolator_type_int = data.GetInt32(); m_prev_frame != frame_on || m_prev_interpolator_type != interpolator_type_int)
	{
		if (const auto interpolator_ptr = m_interpolator_maps[interpolator_type_int].Find(frame_on); interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator_position = interpolator_ptr->GetValue();
			spline->GetKnot(0)->vTangentRight = interpolator_position.GetTangentRight();
			spline->GetKnot(left_knot_index)->vTangentLeft = interpolator_position.GetTangentLeft();
		}
		else {
			spline->GetKnot(0)->vTangentRight = def_tangent_right;
			spline->GetKnot(left_knot_index)->vTangentLeft = def_tangent_left;
		}

		bc->SetData(m_spline_desc_id, spline_data);
		m_prev_frame = frame_on;
		m_prev_interpolator_type = interpolator_type_int;
	}
	return EXECUTIONRESULT::OK;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (!list || !op)
		return true;
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}

#endif // !_MMD_INTERPOLATOR_H
