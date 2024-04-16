/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/10/7
File:			o_mmd_interpolator.h
Description:	C4D MMD interpolator object

**************************************************************************/

#ifndef _MMD_INTERPOLATOR_H_
#define _MMD_INTERPOLATOR_H_

#include "module/MMD/vmd_interpolator.h"

template<
	typename NODE_DATE_TYPE,
	size_t TRACK_COUNT,
	size_t INTERPOLATOR_COUNT,
	Int32 SPLINE_DESC_ID,
	Int32 CURVE_TYPE_DESC_ID,
	Int32 FRAME_AT_DESC_ID,
	Int32 FRAME_AT_STR_DESC_ID>
class MMDInterpolatorNode : public NODE_DATE_TYPE
{
	INSTANCEOF(MMDInterpolatorNode, NODE_DATE_TYPE)
protected:
	// Constants for interpolator and track count.
	static constexpr size_t m_interpolator_count = INTERPOLATOR_COUNT;
	static constexpr size_t m_track_count = TRACK_COUNT;

	DescID m_frame_at_desc = ConstDescID(DescLevel(FRAME_AT_DESC_ID));

	// Tween curve data
	maxon::HashMap<Int32, VMDInterpolator> m_interpolator_maps[m_interpolator_count];
private:
	// Previous frame and interpolator type to check for updates.
	Int32 m_prev_frame = -1;
	Int32 m_prev_interpolator_type = -1;
public:
	/**
	 * \brief Refreshes the spline data.
	 * \param spline_data The spline data to be refreshed.
	 */
	static void RefreshSplineData(SplineData* spline_data);

	/**
	 * \brief Callback function used to restrict SplineData.
	 * \param cid An integer value, typically representing a component or channel ID.
	 * \param data A pointer to data associated with the callback, its interpretation depends on the callback's context.
	 * \return Boolean indicating whether the restriction was successful or not.
	 */
	static Bool SplineDataCallBack(const Int32 cid, const void* data);

	/**
	 * \brief Get the interpolator value.
	 * \param type The type of interpolator.
	 * \param frame_on The frame number.
	 * \param interpolator The output interpolator value.
	 * \return Boolean indicating success or failure.
	 */
	Bool GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator) const;

	/**
	 * \brief Load interpolator from VMD format.
	 * \param type The type of interpolator.
	 * \param frame_at The frame number.
	 * \param vmd_interpolator The VMD interpolator data to load from.
	 * \return Boolean indicating success or failure.
	 */
	Bool LoadVMDInterpolator(Int32 type, Int32 frame_at, const libmmd::vmd_interpolator& vmd_interpolator);

	/**
	 * \brief Save interpolator to VMD format.
	 * \param type The type of interpolator.
	 * \param frame_at The frame number.
	 * \param vmd_interpolator The VMD interpolator data to save to.
	 * \return Boolean indicating success or failure.
	 */
	Bool SaveVMDInterpolator(Int32 type, Int32 frame_at, libmmd::vmd_interpolator& vmd_interpolator);

	/**
	 * \brief Sets the interpolator value.
	 * \param interpolator_type Type of the interpolator to be set.
	 * \param frame_at Frame number for which the interpolator value should be set.
	 * \param fps Frame rate (frames per second) for the animation.
	 * \param args Variable arguments required for setting the interpolator.
	 * \return Boolean indicating success or failure.
	 */
	template<typename ...Args>
	Bool SetInterpolator(size_t interpolator_type, Int32 frame_at, Float fps, Args&& ...args);

	/**
	 * \brief Registers a keyframe for animation.
	 * \param frame_at Frame number at which the keyframe should be registered.
	 * \param node Pointer to the node associated with the keyframe.
	 * \return Boolean indicating success or failure.
	 */
	Bool RegisterKeyFrame(Int32 frame_at, GeListNode* node = nullptr);

	/**
	 * \brief Updates all interpolator tracks.
	 * \param node Pointer to the node for which tracks should be updated.
	 * \return Boolean indicating success or failure.
	 */
	Bool UpdateAllInterpolator(GeListNode* node = nullptr);

	/**
	 * \brief Initializes interpolator tracks.
	 * \param node Pointer to the node for which tracks should be initialized.
	 * \return Boolean indicating success or failure.
	 */
	Bool InitInterpolator(GeListNode* node = nullptr) SDK2024_NotConst;

	/**
	 * \brief Deletes a specified keyframe.
	 * \param frame_on Frame number of the keyframe to be deleted.
	 * \param node Pointer to the node from which the keyframe should be deleted.
	 * \return Boolean indicating success or failure.
	 */
	Bool DeleteKeyFrame(Int32 frame_on, GeListNode* node = nullptr);

	/**
	 * \brief Deletes all keyframes for the specified node.
	 * \param node Pointer to the node for which all keyframes should be deleted.
	 * \return Boolean indicating success or failure.
	 */
	Bool DeleteAllKeyFrame(GeListNode* node = nullptr);

	/**
	 * \brief Reads entity data from a HyperFile.
	 * \param node Pointer to the node associated with the entity.
	 * \param hf HyperFile instance from which data should be read.
	 * \param level Level of detail or depth for reading.
	 * \return Boolean indicating success or failure.
	 */
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;

	/**
	 * \brief Writes entity data to a HyperFile.
	 * \param node Pointer to the node associated with the entity.
	 * \param hf HyperFile instance to which data should be written.
	 * \return Boolean indicating success or failure.
	 */
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;

	/**
	 * \brief Copies all values from the current object to a destination object.
	 * \param dest Destination object to which values should be copied.
	 * \param snode Source node associated with the current object.
	 * \param dnode Destination node associated with the dest object.
	 * \param flags Flags indicating how copying should be performed.
	 * \param trn AliasTrans instance for any required translation during copy.
	 * \return Boolean indicating success or failure.
	 */
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;

	/**
	 * \brief Executes the object at a specified point in the priority pipeline.
	 * \param op BaseObject for the operation.
	 * \param doc BaseDocument in which the operation occurs.
	 * \param bt BaseThread associated with the execution.
	 * \param priority Execution priority level.
	 * \param flags Execution flags.
	 * \return Result of the execution.
	 */
	EXECUTIONRESULT ExecuteImpl(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);

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
	/**
	 * \brief Constructor.
	 */
	MMDInterpolatorNode() = default;

	/**
	 * \brief Destructor.
	 */
	~MMDInterpolatorNode() override = default;

	/**
	 * \brief Default copy constructor.
	 * \param other The object to be copied from.
	 */
	MMDInterpolatorNode(const MMDInterpolatorNode& other) = delete;

	/**
	 * \brief Default copy assignment operator.
	 * \param other The object to be copied from.
	 * \return A reference to this object.
	 */
	MMDInterpolatorNode& operator=(const MMDInterpolatorNode& other) = delete;

	/**
	 * \brief Default move constructor.
	 * \param other The object to be moved from.
	 */
	MMDInterpolatorNode(MMDInterpolatorNode&& other) noexcept = default;

	/**
	 * \brief Default move assignment operator.
	 * \param other The object to be moved from.
	 * \return A reference to this object.
	 */
	MMDInterpolatorNode& operator=(MMDInterpolatorNode&& other) noexcept = default;
};



// ----- Implementation -----

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
void MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::RefreshSplineData(SplineData* spline_data)
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::SplineDataCallBack(const Int32 cid, const void* data)
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator) const
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::LoadVMDInterpolator(Int32 type, Int32 frame_at, const libmmd::vmd_interpolator& vmd_interpolator)
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID, Int32 FRAME_AT_STR_DESC_ID >
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::SaveVMDInterpolator(Int32 type, Int32 frame_at, libmmd::vmd_interpolator& vmd_interpolator)
{
	if(auto interpolator_ptr = m_interpolator_maps[type].FindValue(frame_at); interpolator_ptr)
	{
		interpolator_ptr->Save(vmd_interpolator);
		return true;
	}
	return false;
}

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
template <typename ... Args>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::SetInterpolator(size_t interpolator_type, Int32 frame_at, const Float fps, Args&&... args)
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
	CKey* key_frame_at = frame_curve->AddKey(BaseTime(frame_at, fps));
	if (key_frame_at == nullptr)
	{
		return false;
	}
	key_frame_at->SetValue(frame_curve, frame_at);
	key_frame_at->SetInterpolation(frame_curve, CINTERPOLATION::STEP);
	key_frame_at->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
	key_frame_at->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	auto& entry = m_interpolator_maps[interpolator_type].InsertEntry(frame_at)iferr_return;
	VMDInterpolator& interpolator = entry.GetValue();
	interpolator.Set(std::forward<Args&&>(args)...);
	return true;
}

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::RegisterKeyFrame(const Int32 frame_at, GeListNode* node)
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

	const BaseTime time(frame_at, fps);
	GeData curve_type_data;
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return true;
	}
	GeData ge_data = bc->GetData(SPLINE_DESC_ID);
	auto* spline = DataGetCustomDataType(ge_data, SplineData, CUSTOMDATATYPE_SPLINE);

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
	if (const auto interpolator_type = bc->GetInt32(CURVE_TYPE_DESC_ID); interpolator_type == m_interpolator_count - 1)
	{
		for (size_t track_index = 0; track_index < m_interpolator_count; ++track_index)
		{
			if (!SetInterpolator(track_index, frame_at, fps, spline))
				return false;
		}
	}
	// not all curve
	else
	{
		if (!SetInterpolator(interpolator_type, frame_at, fps, spline))
			return false;
	}

	this->UpdateAllInterpolator(node);
	return true;
}

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::UpdateAllInterpolator(GeListNode* node)

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
	if (!frame_track)
	{
				return false;
	}
	CCurve* frame_curve = frame_track->GetCurve();
	if (!frame_curve)
	{
				return false;
	}

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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::InitInterpolator(GeListNode* node) SDK2024_NotConst
{
	if (!node)
	{
		node = this->Get();
		if (!node)
		{
			return false;
		}
	}
	auto data = GeData(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
	if (auto* spline = DataGetCustomDataType(data, SplineData, CUSTOMDATATYPE_SPLINE); spline)
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
	reinterpret_cast<BaseList2D*>(node)->GetDataInstance()->SetData(SPLINE_DESC_ID, data);
	return true;
}

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::DeleteKeyFrame(Int32 frame_on, GeListNode* node)
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::DeleteAllKeyFrame(GeListNode* node)
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::Read(GeListNode* node, HyperFile* hf, Int32 level)
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
Bool MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode,
	GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
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

template <typename NODE_DATE_TYPE, size_t TRACK_COUNT, size_t INTERPOLATOR_COUNT, Int32 SPLINE_DESC_ID, Int32 CURVE_TYPE_DESC_ID, Int32 FRAME_AT_DESC_ID,Int32 FRAME_AT_STR_DESC_ID>
EXECUTIONRESULT MMDInterpolatorNode<NODE_DATE_TYPE, TRACK_COUNT, INTERPOLATOR_COUNT, SPLINE_DESC_ID, CURVE_TYPE_DESC_ID, FRAME_AT_DESC_ID, FRAME_AT_STR_DESC_ID>::ExecuteImpl(BaseObject* op, BaseDocument* doc,
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

	const GeData& spline_data = bc->GetData(SPLINE_DESC_ID);
	auto* spline = DataGetCustomDataType(const_cast<GeData&>(spline_data), SplineData, CUSTOMDATATYPE_SPLINE);
	if (spline == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const Int32 left_knot_index = spline->GetKnotCount() - 1;

	static constexpr Vector def_tangent_left{ -20., -20., 0. };
	static constexpr Vector def_tangent_right{ 20., 20., 0. };

	const Int32 frame_on = bc->GetInt32(FRAME_AT_DESC_ID);
	const Int32 interpolator_type_int = bc->GetInt32(CURVE_TYPE_DESC_ID);
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
		
		bc->SetString(FRAME_AT_STR_DESC_ID, maxon::String::IntToString(frame_on));
		m_prev_frame = frame_on;
		m_prev_interpolator_type = interpolator_type_int;
	}
	return EXECUTIONRESULT::OK;
}

#endif // !_MMD_INTERPOLATOR_H
