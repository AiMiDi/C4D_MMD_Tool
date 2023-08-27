/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/7
File:			o_mmd_interpolator.h
Description:	C4D MMD interpolator object

**************************************************************************/

#ifndef _MMD_INTERPOLATOR_H_
#define _MMD_INTERPOLATOR_H_

#include "module/MMD/vmd_interpolator.h"

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT>
class MMDInterpolatorNode : public NODE_DATE_TYPE
{
	INSTANCEOF(MMDInterpolatorNode, NODE_DATE_TYPE)
protected:
	static constexpr size_t m_interpolator_count = INTERPOLATOR_COUNT;
	static constexpr size_t m_track_count = TRACK_COUNT;

	Int32 m_spline_desc_id;
	Int32 m_curve_type_desc_id;
	Int32 m_frame_at_desc_id;
	Int32 m_frame_at_str_desc_id;

	DescID m_frame_at_desc{ m_frame_at_desc_id };

	// Tween curve data
	maxon::HashMap<Int32, VMDInterpolator> m_interpolator_maps[m_interpolator_count];
private:
	// Save the previous frame to determine the update status
	Int32 m_prev_frame = -1;

	// Save the previous curve type to determine the update status
	Int32 m_prev_interpolator_type = -1;
public:
	static void RefreshSplineData(SplineData* spline_data);

	// Callback function used to restrict SplineData
	static Bool SplineDataCallBack(Int32, const void*);

	// Get interpolator value
	Bool GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator) const;

	// Load interpolator from libmmd::vmd_interpolator
	Bool LoadInterpolator(Int32 type, Int32 frame_at, const libmmd::vmd_interpolator& vmd_interpolator);

	// Save interpolator to libmmd::vmd_interpolator
	Bool SaveInterpolator(Int32 type, Int32 frame_at, libmmd::vmd_interpolator& vmd_interpolator);

	// Set interpolator value
	template<typename ...Args>
	Bool SetInterpolator(size_t interpolator_type, Int32 frame_on, Float fps, Args&& ...args);

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
	using TrackDescIDArray = std::array<const DescID, TRACK_COUNT>;
	using TrackObjectArray = std::array<BaseObject*, TRACK_COUNT>;
	using InterpolatorTrackTableArray = std::array<const Int32, TRACK_COUNT>;
	using CurrentValuesArray = std::array<const Float, TRACK_COUNT>;

	virtual TrackDescIDArray GetTrackDescIDs() = 0;
	virtual TrackObjectArray GetTrackObjects(GeListNode* node) = 0;
	virtual InterpolatorTrackTableArray GetTrackInterpolatorMap() = 0;
	virtual CurrentValuesArray GetCurrentValues(GeListNode* node) = 0;
public:
	// Constructor function
	MMDInterpolatorNode(const Int32& spline_desc_id , const Int32& curve_type_desc_id, const Int32& frame_on_desc_id, const Int32& frame_at_str_desc_id):
	m_spline_desc_id(spline_desc_id), m_curve_type_desc_id(curve_type_desc_id), m_frame_at_desc_id(frame_on_desc_id), m_frame_at_str_desc_id(frame_at_str_desc_id){}

	// Destructor function
	~MMDInterpolatorNode() override = default;
};



// ----- Implementation -----

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT>
void MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT>::RefreshSplineData(SplineData* spline_data)
{
	// Now we just go over all knots and clamp them. This could also be done more elegantly
	// with line-line intersections, I am just clamping each tangent here to the interval [0, 1],
	// which effectively equates orthogonally projecting the tangents onto that "[0,  1] box". If you
	// want to scale vectors so that a handle which is outside that [0, 1] box, is scaled in such
	// manner that the handle touches the border of that box, you will have to use line-line 
	// intersections.
	const Int32 KnotCount = spline_data->GetKnotCount();
	for (Int32 i = 0; i < KnotCount; i++)
	{
		// Get the current knot.
		CustomSplineKnot* knot = spline_data->GetKnot(i);
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

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT,  TRACK_COUNT>::SplineDataCallBack(const Int32 cid, const void* data)
{
	// The callback function which does clamp the SplineData
	if (cid == SPLINE_CALLBACK_CORE_MESSAGE)
	{
		if (!data)
			return false;

		// Get pointer to the SplineCustomGui
		const auto pGui = static_cast<const SplineDataCallbackCoreMessage*>(data)->pGUI;
		
		if (!pGui)
			return false;

		// Get data massaging
		SplineData* spline_data = pGui->GetSplineData();
		if (!spline_data)
			return false;

		RefreshSplineData(spline_data);

		// Prepare the command message container
		// We will make the SplineCustomGui frame the selected points
		BaseContainer splineMsg;
		splineMsg.SetInt32(0, IDC_SPLINE_FRAME_ALL);

		// Talk the SplineCustomGui into performing a command from its popup menu
		pGui->Command(IDC_SPLINE_PRESET_POPUPMENU, splineMsg);
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT>::SaveInterpolator(Int32 type, Int32 frame_at, libmmd::vmd_interpolator& vmd_interpolator)
{
	if(auto interpolator_ptr = m_interpolator_maps[type].FindValue(frame_at); interpolator_ptr)
	{
		interpolator_ptr->Save(vmd_interpolator);
		return true;
	}
	return false;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
template <typename ... Args>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT, TRACK_COUNT>::SetInterpolator(size_t interpolator_type, Int32 frame_on, const Float fps, Args&&... args)
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
	CTrack* frame_track = object->FindCTrack(m_frame_at_desc);
	if (frame_track == nullptr)
	{
		frame_track = CTrack::Alloc(object, m_frame_at_desc);
		object->InsertTrackSorted(frame_track);
	}
	CCurve* frame_curve = frame_track->GetCurve();
	if (frame_curve == nullptr)
	{
		return false;
	}
	CKey* key_frame_at = frame_curve->AddKey(BaseTime(frame_on, fps));
	if (key_frame_at == nullptr)
	{
		return false;
	}
	key_frame_at->SetValue(frame_curve, frame_on);
	key_frame_at->SetInterpolation(frame_curve, CINTERPOLATION::STEP);
	key_frame_at->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
	key_frame_at->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	auto& entry = m_interpolator_maps[interpolator_type].InsertEntry(frame_on)iferr_return;
	VMDInterpolator& interpolator = entry.GetValue();
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

	const BaseDocument* doc = node->GetDocument();
	if (!doc)
		return false;

	const Float fps = doc->GetFps();

	const BaseTime time(frame_on, fps);
	GeData curve_type_data;
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return true;
	}
	const GeData ge_data = bc->GetData(m_spline_desc_id);
	auto* spline = reinterpret_cast<SplineData*>(ge_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE));

	const auto track_objects = GetTrackObjects(node);

	const auto key_current_value = GetCurrentValues(node);

	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < m_track_count; ++track_index)
	{
		auto& track_ID = track_desc_IDs[track_index];
		BaseObject* track_object = track_objects[track_index];
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
		
		CCurve* curve = track->GetCurve();
		if (!curve)
		{
			return false;
		}
		CKey* key = curve->FindKey(time); 
		if (!key)
		{
			key = curve->AddKey(time);
			if (!key)
			{
				return false;
			}
		}
		key->SetValue(curve, key_current_value[track_index]);
	}

	RefreshSplineData(spline);

	// all interpolator curve
	// m_interpolator_count == XXX_INTERPOLATOR_ALL
	if (const auto interpolator_type = bc->GetInt32(m_curve_type_desc_id); interpolator_type == m_interpolator_count - 1)
	{
		for (size_t track_index = 0; track_index < m_interpolator_count; ++track_index)
		{
			if (!SetInterpolator(track_index, frame_on, fps, spline))
				return false;
		}
	}
	// not all curve
	else
	{
		if (!SetInterpolator(interpolator_type, frame_on, fps, spline))
			return false;
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

	CTrack* frame_track = object->FindCTrack(m_frame_at_desc);
	CCurve* frame_curve = frame_track->GetCurve();

	const auto track_objects = GetTrackObjects(node);

	const auto track_desc_IDs = GetTrackDescIDs();

	const auto  track_interpolator_map = GetTrackInterpolatorMap();

	for (size_t interpolator_track_index = 0; interpolator_track_index < m_track_count; ++interpolator_track_index)
	{
		const auto& track_desc_ID = track_desc_IDs[interpolator_track_index];
		const auto& track_object = track_objects[interpolator_track_index];

		CTrack* track = track_object->FindCTrack(track_desc_ID);
		if (!track)
		{
			continue;
		}
		
		CCurve* curve = track->GetCurve();
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
			next_key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);

			const Float value_of_two_frames = next_key->GetValue() - key->GetValue();
			next_key->SetTimeLeft(curve, time_of_two_frames * interpolator.GetTimeLeft());
			next_key->SetValueLeft(curve, value_of_two_frames * interpolator.GetValueLeft());
			key->SetTimeRight(curve, time_of_two_frames * interpolator.GetTimeRight());
			key->SetValueRight(curve, value_of_two_frames * interpolator.GetValueRight());
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
	reinterpret_cast<BaseList2D*>(node)->GetDataInstance()->SetData(m_spline_desc_id, data);
	return true;
}

template <typename NODE_DATE_TYPE, size_t INTERPOLATOR_COUNT, size_t TRACK_COUNT>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, INTERPOLATOR_COUNT, TRACK_COUNT>::DeleteKeyFrame(Int32 frame_on, GeListNode* node)
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

	const BaseDocument* doc = node->GetDocument();
	if (!doc)
		return false;

	const BaseTime time(frame_on, doc->GetFps());

	for (auto& interpolator_map : m_interpolator_maps)
	{
		if (const auto interpolator_ptr = interpolator_map.Find(frame_on); interpolator_ptr != nullptr)
		{
			interpolator_map.Erase(interpolator_ptr);
		}
	}

	CTrack* frame_at_track = object->FindCTrack(m_frame_at_desc);
	if (!frame_at_track)
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
	if(auto frame_at_key = frame_at_curve->FindKey(time))
		CKey::Free(frame_at_key);

	const auto track_objects = GetTrackObjects(node);
	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < m_track_count; ++track_index)
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
		if(auto key = curve->FindKey(time))
			CKey::Free(key);
	}
	UpdateAllInterpolator(node);
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
	const auto object = reinterpret_cast<BaseObject*>(node);

	for (auto& map : m_interpolator_maps)
	{
		map.Reset();
	}

	if (CTrack* frame_at_track = object->FindCTrack(m_frame_at_desc))
	{
		CTrack::Free(frame_at_track);
	}

	const auto track_objects = GetTrackObjects(node);
	const auto track_desc_IDs = GetTrackDescIDs();

	for (size_t track_index = 0; track_index < m_track_count; ++track_index)
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
	UpdateAllInterpolator(node);
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

	BaseContainer* bc = op->GetDataInstance();
	if (bc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const GeData& spline_data = bc->GetData(m_spline_desc_id);
	auto* spline = reinterpret_cast<SplineData*>(spline_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE));
	if (spline == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const Int32 left_knot_index = spline->GetKnotCount() - 1;

	static constexpr Vector def_tangent_left{ -20., -20., 0. };
	static constexpr Vector def_tangent_right{ 20., 20., 0. };

	const Int32 frame_on = bc->GetInt32(m_frame_at_desc_id);
	const Int32 interpolator_type_int = bc->GetInt32(m_curve_type_desc_id);
	if (m_prev_frame != frame_on || m_prev_interpolator_type != interpolator_type_int)
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
		
		bc->SetString(m_frame_at_str_desc_id, maxon::String::IntToString(frame_on));
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
