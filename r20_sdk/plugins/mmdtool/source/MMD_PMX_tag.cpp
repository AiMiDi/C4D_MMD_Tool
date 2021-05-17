#include "MMD_PMX_tag.h"

Bool mmd::PMX_Model_Tag::Init(GeListNode* node)
{
	if (node == nullptr)
		return false;
	node->SetParameter(DescID(ID_BASELIST_NAME), GeLoadString(IDS_PMX_MODEL_TAG), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(PMX_VERSION), 2.1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(MODEL_NAME_LOCAL), "name"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(MODEL_NAME_UNIVERSAL), "name"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(COMMENTS_LOCAL), "description"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(COMMENTS_UNIVERSAL), "description"_s, DESCFLAGS_SET::NONE);
	return true;
}
Bool mmd::PMX_Model_Tag::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	if (!description->LoadDescription("PMX_Model_Tag"_s))
		return false;
	const DescID* singleid = description->GetSingleDescID();
	if (singleid == nullptr) {
		return SUPER::GetDDescription(node, description, flags);
	}
	MAXON_SCOPE
	{
		DescID cid = DescID(MODEL_INFO_GRP);
		if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
		{
			BaseContainer* settings = description->GetParameterI(cid, nullptr);
			if (settings)settings->SetBool(DESC_GROUPSCALEV, true);
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;

	return SUPER::GetDDescription(node, description, flags);
}
EXECUTIONRESULT mmd::PMX_Model_Tag::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 	priority, EXECUTIONFLAGS flags) {
	if (tag == nullptr || op == nullptr) {
		return EXECUTIONRESULT::OK;
	}

	return EXECUTIONRESULT::OK;
}
Bool mmd::PMX_Model_Tag::AddToExecution(BaseTag* tag, PriorityList* list) {
	//list->Add(tag, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}

Bool mmd::PMX_Bone_Tag::SplineDataCallBack(Int32 cid, const void* data)
{
	// 还有其他一些回调类型，我们在这里仅使用SPLINE_CALLBACK_CORE_MESSAGE
	if (cid == SPLINE_CALLBACK_CORE_MESSAGE)
	{
		if (data == nullptr)
			return true;

		// 数据信息...
		SplineData* splineData = ((SplineDataCallbackCoreMessage*)data)->pGUI->GetSplineData();
		if (splineData == nullptr)
			return true;
		/*
		现在我们只需检查所有的knot并限制它们。我只是限制在这里的每个切线的[0，1]区间，
		限制就是把切线控制点正交投影切线到“[0，1]”。
		如果要缩放向量，使位于[0，1]区间外部的控制柄以该控制柄接触该框边界的方式进行缩放。
		*/
		for (int i = 0; i < splineData->GetKnotCount(); i++)
		{
			// 获取当前knot。
			CustomSplineKnot* knot = splineData->GetKnot(i);
			// 切线存在于相对于其顶点的向量空间中，因此我们首先使切线向量全局化，然后限制它们。
			Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
			globalLeftTangent.ClampMax(Vector(127, 127, 0));
			globalLeftTangent.ClampMin(Vector(0, 0, 0));
			Vector globalRightTangent = knot->vPos + knot->vTangentRight;
			globalRightTangent.ClampMax(Vector(127, 127, 0));
			globalRightTangent.ClampMin(Vector(0, 0, 0));
			// 然后我们把切线转换回它们的局部切线空间，然后写回去。
			knot->vTangentLeft = globalLeftTangent - knot->vPos;
			knot->vTangentRight = globalRightTangent - knot->vPos;
		}
	}
	return true;
}
Bool mmd::PMX_Bone_Tag::GetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve) {
	switch (type)
	{
	case (PMX_BONE_TAG_XCURVE): {
		auto xCurve_ptr = XCurve.Find(frame_on);
		if (xCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(xCurve_ptr->GetValue());
		}
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
		auto yCurve_ptr = YCurve.Find(frame_on);
		if (yCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(yCurve_ptr->GetValue());
		}
		break;
	}
	case (PMX_BONE_TAG_ZCURVE):
	{
		auto zCurve_ptr = ZCurve.Find(frame_on);
		if (zCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(zCurve_ptr->GetValue());
		}
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		auto rCurve_ptr = RCurve.Find(frame_on);
		if (rCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(rCurve_ptr->GetValue());
		}
		break;
	}
	case (PMX_BONE_TAG_ACURVE): {
		auto aCurve_ptr = ACurve.Find(frame_on);
		if (aCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(aCurve_ptr->GetValue());
		}
		break;
	}
	default:
		return false;
		break;
	}
	return true;
}
Bool mmd::PMX_Bone_Tag::SetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve) {
	BaseTag* tag = (BaseTag*)Get();
	if (tag == nullptr) {
		return false;
	}
	CTrack* Frame_onTrack = tag->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	if (Frame_onTrack == nullptr) {
		Frame_onTrack = CTrack::Alloc(tag, DescID(PMX_BONE_TAG_FRAME_ON));
		tag->InsertTrackSorted(Frame_onTrack);
	}
	CCurve* Frame_onCurve = Frame_onTrack->GetCurve();
	CKey* KeyFrame_on = Frame_onCurve->AddKey(BaseTime(frame_on, 30));
	KeyFrame_on->SetValue(Frame_onCurve, frame_on);
	KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	switch (type)
	{
	case (PMX_BONE_TAG_XCURVE): {
		iferr(XCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
		iferr(YCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (PMX_BONE_TAG_ZCURVE): {
		iferr(ZCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		iferr(RCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (PMX_BONE_TAG_ACURVE): {
		iferr(XCurve.Insert(frame_on, curve))return false;
		iferr(YCurve.Insert(frame_on, curve))return false;
		iferr(ZCurve.Insert(frame_on, curve))return false;
		iferr(RCurve.Insert(frame_on, curve))return false;
		iferr(ACurve.Insert(frame_on, curve))return false;
		break;
	}
	default:
		return false;
		break;
	}
	return true;
}
Bool mmd::PMX_Bone_Tag::UpdateAllCurve() {
	if (obj == nullptr) {
		return false;
	}
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	if (Frame_onTrack != nullptr) {
		CCurve* Frame_onCurve = Frame_onTrack->GetCurve();
		if (Frame_onCurve != nullptr) {
			for (Int32 i = 0; i < Frame_onCurve->GetKeyCount(); i++) {
				UpdateCurve(Frame_onCurve->GetKey(i)->GetValue());
			}
		}
	}
	return true;
}
Bool mmd::PMX_Bone_Tag::UpdateCurve(Int32 frame_on) {
	if (obj == nullptr) {
		return false;
	}
	CTrack* frameTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	if (frameTrack == nullptr) {
		return false;
	}
	CCurve* frameCurve = frameTrack->GetCurve();
	if (frameCurve == nullptr) {
		return false;
	}
	CKey* Keyframe_next = frameCurve->FindKey(BaseTime(frame_on + 1, 30), nullptr, FINDANIM::RIGHT);//加一排除所在的那一帧
	if (Keyframe_next == nullptr) {
		return false;
	}
	BaseTime next_time = Keyframe_next->GetTime();
	Float TimeOfTwoFrames = next_time.GetFrame(30) - frame_on;

	auto xCurve_ptr = XCurve.Find(frame_on);
	if (xCurve_ptr != nullptr) {
		mmd::VMD_Curve* xCurve = xCurve_ptr->GetValue();
		CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		if (TrackPX != nullptr) {
			CCurve* CurvePX = TrackPX->GetCurve();
			if (CurvePX != nullptr) {
				CKey* KeyPX = CurvePX->FindKey(BaseTime(frame_on, 30));
				if (KeyPX != nullptr) {
					CKey* KeyPX_next = CurvePX->FindKey(next_time);
					if (KeyPX_next != nullptr) {
						if (xCurve->ax == xCurve->ay && xCurve->bx == xCurve->by) {
							KeyPX->SetInterpolation(CurvePX, CINTERPOLATION::LINEAR);
						}
						else {
							Float ValueOfTwoFrames = KeyPX_next->GetValue() - KeyPX->GetValue();
							KeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							KeyPX_next->SetTimeLeft(CurvePX, BaseTime(-TimeOfTwoFrames * ((Float)xCurve->bx / 127.0), 30));
							KeyPX_next->SetValueLeft(CurvePX, -ValueOfTwoFrames * ((Float)xCurve->by / 127.0));
							KeyPX->SetTimeRight(CurvePX, BaseTime(TimeOfTwoFrames * ((Float)xCurve->ax / 127.0), 30));
							KeyPX->SetValueRight(CurvePX, ValueOfTwoFrames * ((Float)xCurve->ay / 127.0));
						}
					}
				}
			}
		}
	}
	auto yCurve_ptr = YCurve.Find(frame_on);
	if (yCurve_ptr != nullptr) {
		mmd::VMD_Curve* yCurve = yCurve_ptr->GetValue();
		CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		if (TrackPY != nullptr) {
			CCurve* CurvePY = TrackPY->GetCurve();
			if (CurvePY != nullptr) {
				CKey* KeyPY = CurvePY->FindKey(BaseTime(frame_on, 30));
				if (KeyPY != nullptr) {
					CKey* KeyPY_next = CurvePY->FindKey(next_time);
					if (KeyPY_next != nullptr) {
						if (yCurve->ax == yCurve->ay && yCurve->bx == yCurve->by) {
							KeyPY->SetInterpolation(CurvePY, CINTERPOLATION::LINEAR);
						}
						else {
							Float ValueOfTwoFrames = KeyPY_next->GetValue() - KeyPY->GetValue();
							KeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							KeyPY_next->SetTimeLeft(CurvePY, BaseTime(-TimeOfTwoFrames * ((Float)yCurve->bx / 127.0), 30));
							KeyPY_next->SetValueLeft(CurvePY, -ValueOfTwoFrames * ((Float)yCurve->by / 127.0));
							KeyPY->SetTimeRight(CurvePY, BaseTime(TimeOfTwoFrames * ((Float)yCurve->ax / 127.0), 30));
							KeyPY->SetValueRight(CurvePY, ValueOfTwoFrames * ((Float)yCurve->ay / 127.0));
						}
					}
				}
			}
		}
	}
	auto zCurve_ptr = ZCurve.Find(frame_on);
	if (zCurve_ptr != nullptr) {
		mmd::VMD_Curve* zCurve = zCurve_ptr->GetValue();
		CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		if (TrackPZ != nullptr) {
			CCurve* CurvePZ = TrackPZ->GetCurve();
			if (CurvePZ != nullptr) {
				CKey* KeyPZ = CurvePZ->FindKey(BaseTime(frame_on, 30));
				if (KeyPZ != nullptr) {
					CKey* KeyPZ_next = CurvePZ->FindKey(next_time);
					if (KeyPZ_next != nullptr) {
						if (zCurve->ax == zCurve->ay && zCurve->bx == zCurve->by) {
							KeyPZ->SetInterpolation(CurvePZ, CINTERPOLATION::LINEAR);
						}
						else {
							Float ValueOfTwoFrames = KeyPZ_next->GetValue() - KeyPZ->GetValue();
							KeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							KeyPZ_next->SetTimeLeft(CurvePZ, BaseTime(-TimeOfTwoFrames * ((Float)zCurve->bx / 127.0), 30));
							KeyPZ_next->SetValueLeft(CurvePZ, -ValueOfTwoFrames * ((Float)zCurve->by / 127.0));
							KeyPZ->SetTimeRight(CurvePZ, BaseTime(TimeOfTwoFrames * ((Float)zCurve->ax / 127.0), 30));
							KeyPZ->SetValueRight(CurvePZ, ValueOfTwoFrames * ((Float)zCurve->ay / 127.0));
						}
					}
				}
			}
		}
	}
	auto rCurve_ptr = RCurve.Find(frame_on);
	if (rCurve_ptr != nullptr) {
		mmd::VMD_Curve* rCurve = rCurve_ptr->GetValue();
		CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		if (TrackRX != nullptr) {
			CCurve* CurveRX = TrackRX->GetCurve();
			if (CurveRX != nullptr) {
				CKey* KeyRX = CurveRX->FindKey(BaseTime(frame_on, 30));
				if (KeyRX != nullptr) {
					CKey* KeyRX_next = CurveRX->FindKey(next_time);
					if (KeyRX_next != nullptr) {
						if (rCurve->ax == rCurve->ay && rCurve->bx == rCurve->by) {
						}
						else {
							Float ValueOfTwoFrames = KeyRX_next->GetValue() - KeyRX->GetValue();
							KeyRX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							KeyRX_next->SetTimeLeft(CurveRX, BaseTime(-TimeOfTwoFrames * ((Float)rCurve->bx / 127.0), 30));
							KeyRX_next->SetValueLeft(CurveRX, -ValueOfTwoFrames * ((Float)rCurve->by / 127.0));
							KeyRX->SetTimeRight(CurveRX, BaseTime(TimeOfTwoFrames * ((Float)rCurve->ax / 127.0), 30));
							KeyRX->SetValueRight(CurveRX, ValueOfTwoFrames * ((Float)rCurve->ay / 127.0));
						}
					}
				}
			}
			CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
			if (TrackRY != nullptr) {
				CCurve* CurveRY = TrackRY->GetCurve();
				if (CurveRY != nullptr) {
					CKey* KeyRY = CurveRY->FindKey(BaseTime(frame_on, 30));
					if (KeyRY != nullptr) {
						CKey* KeyRY_next = CurveRY->FindKey(next_time);
						if (KeyRY_next != nullptr) {
							if (rCurve->ax == rCurve->ay && rCurve->bx == rCurve->by) {
								KeyRY->SetInterpolation(CurveRY, CINTERPOLATION::LINEAR);
							}
							else {
								Float ValueOfTwoFrames = KeyRY_next->GetValue() - KeyRY->GetValue();
								KeyRY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								KeyRY_next->SetTimeLeft(CurveRY, BaseTime(-TimeOfTwoFrames * ((Float)rCurve->bx / 127.0), 30));
								KeyRY_next->SetValueLeft(CurveRY, -ValueOfTwoFrames * ((Float)rCurve->by / 127.0));
								KeyRY->SetTimeRight(CurveRY, BaseTime(TimeOfTwoFrames * ((Float)rCurve->ax / 127.0), 30));
								KeyRY->SetValueRight(CurveRY, ValueOfTwoFrames * ((Float)rCurve->ay / 127.0));
							}
						}
					}
				}
			}
			CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
			if (TrackRZ != nullptr) {
				CCurve* CurveRZ = TrackRZ->GetCurve();
				if (CurveRZ != nullptr) {
					CKey* KeyRZ = CurveRZ->FindKey(BaseTime(frame_on, 30));
					if (KeyRZ != nullptr) {
						CKey* KeyRZ_next = CurveRZ->FindKey(next_time);
						if (KeyRZ_next != nullptr) {
							if (rCurve->ax == rCurve->ay && rCurve->bx == rCurve->by) {
								KeyRZ->SetInterpolation(CurveRZ, CINTERPOLATION::LINEAR);
							}
							else {
								Float ValueOfTwoFrames = KeyRZ_next->GetValue() - KeyRZ->GetValue();
								KeyRZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								KeyRZ_next->SetTimeLeft(CurveRZ, BaseTime(-TimeOfTwoFrames * ((Float)rCurve->bx / 127.0), 30));
								KeyRZ_next->SetValueLeft(CurveRZ, -ValueOfTwoFrames * ((Float)rCurve->by / 127.0));
								KeyRZ->SetTimeRight(CurveRZ, BaseTime(TimeOfTwoFrames * ((Float)rCurve->ax / 127.0), 30));
								KeyRZ->SetValueRight(CurveRZ, ValueOfTwoFrames * ((Float)rCurve->ay / 127.0));
							}
						}
					}
				}
			}
		}
	}
	return true;
}
Bool mmd::PMX_Bone_Tag::CurveInit() {
	if (Get() == nullptr)return false;
	BaseContainer* bc = ((BaseList2D*)Get())->GetDataInstance();
	GeData data = GeData(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
	SplineData* spline = (SplineData*)data.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
	if (spline != nullptr)
	{
		spline->AdaptRange(0, 127, 127, 0, 127, 127);
		spline->InsertKnot(0.0, 0.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->InsertKnot(127.0, 127.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->SetUserCallback(mmd::PMX_Bone_Tag::SplineDataCallBack, nullptr);
		CustomSplineKnot* a = spline->GetKnot(0);
		CustomSplineKnot* b = spline->GetKnot(spline->GetKnotCount() - 1);
		a->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		b->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		a->vTangentRight = Vector(20, 20, 0);
		b->vTangentLeft = Vector(-20, -20, 0);
	}
	bc->SetData(PMX_BONE_TAG_SPLINE, data);
	return true;
}
Bool mmd::PMX_Bone_Tag::Init(GeListNode* node)
{
	if (node == nullptr)return false;
	node->SetParameter(DescID(ID_BASELIST_NAME), GeLoadString(IDS_PMX_MODEL_TAG), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_NAME_LOCAL), "bone"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(NAME_IS_LOCAL), 2, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_NAME_UNIVERSAL), "bone"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(PARENT_BONE_INDEX), -1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(ROTATABLE), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(VISIBLE), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(ENABLED), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(TAIL_INDEX), -1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(INHERIT_BONE_PARENT_INDEX), -1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), 1.0, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_LOCAL_X), Vector(1, 0, 0), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_LOCAL_Z), Vector(0, 0, 1), DESCFLAGS_SET::NONE);
	if (!CurveInit())return false;
	return true;
}
Bool mmd::PMX_Bone_Tag::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (id[0].id == PMX_BONE_TAG_FRAME_ON) {
		return false;
	}
	if (id[0].id == PARENT_BONE_LINK) {
		GeData Ge_data;
		node->GetParameter(DescID(PARENT_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
		Int32 parent_bone_index = Ge_data.GetInt32();
		if (parent_bone_index == -1) {
			return false;
		}
	}
	if (id[0].id == TAIL_INDEX) {
		GeData Ge_data;
		node->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == 0) {
			return false;
		}
	}
	if (id[0].id == TAIL_POSITION) {
		GeData Ge_data;
		node->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == 1) {
			return false;
		}
	}
	if (id[0].id == INHERIT_BONE_PARENT_INDEX) {
		GeData Ge_data;
		node->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id[0].id == INHERIT_BONE_PARENT_INFLUENCE) {
		GeData Ge_data;
		node->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id[0].id == INHERIT_BONE_PARENT_LINK) {
		GeData Ge_data;
		node->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id[0].id == BONE_FIXED_AXIS) {
		GeData Ge_data;
		node->GetParameter(DescID(FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
		Bool fixed_axis = Ge_data.GetBool();
		if (fixed_axis == 0) {
			return false;
		}
	}
	if (id[0].id == BONE_LOCAL_X) {
		GeData Ge_data;
		node->GetParameter(DescID(LOCAL_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0) {
			return false;
		}
	}
	if (id[0].id == BONE_LOCAL_Z) {
		GeData Ge_data;
		node->GetParameter(DescID(LOCAL_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0) {
			return false;
		}
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}
EXECUTIONRESULT mmd::PMX_Bone_Tag::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 	priority, EXECUTIONFLAGS flags) {
	if (tag == nullptr || op == nullptr) {
		return EXECUTIONRESULT::OK;
	}
	if (obj == nullptr) {
		obj = op;
	}
	GeData Ge_data;
	BaseObject* up_obj = op->GetUp();
	if (up_obj != nullptr) {
		if (up_obj->GetName() != "Bones"_s) {
			BaseLink* parent_bone_link = BaseLink::Alloc();
			if (parent_bone_link == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return EXECUTIONRESULT::OK;
			}
			parent_bone_link->SetLink(up_obj);
			tag->SetParameter(DescID(PARENT_BONE_LINK), parent_bone_link, DESCFLAGS_SET::NONE);
			BaseTag* up_tag = up_obj->GetTag(ID_PMX_BONE_TAG);
			if (up_tag != nullptr) {
				up_tag->GetParameter(DescID(BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
				tag->SetParameter(DescID(PARENT_BONE_INDEX), Ge_data.GetString().ToInt32(nullptr), DESCFLAGS_SET::NONE);
			}
		}
	}
	tag->GetParameter(DescID(PMX_BONE_TAG_FRAME_ON), Ge_data, DESCFLAGS_GET::NONE);
	Int32 frame_on = Ge_data.GetInt32();
	tag->GetParameter(DescID(PMX_BONE_TAG_CURVE_TYPE), Ge_data, DESCFLAGS_GET::NONE);
	Int32 curve_type = Ge_data.GetInt32();
	if (prev_frame != frame_on || prev_curve_type != curve_type)
	{
		BaseContainer* bc = ((BaseList2D*)tag)->GetDataInstance();
		GeData data_ = bc->GetData(PMX_BONE_TAG_SPLINE);
		SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
		switch (curve_type)
		{
		case (PMX_BONE_TAG_XCURVE): {
			auto xCurve_ptr = XCurve.Find(frame_on);
			if (xCurve_ptr != nullptr) {
				mmd::VMD_Curve* xCurve = xCurve_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(xCurve->ax, xCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(xCurve->bx, xCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (PMX_BONE_TAG_YCURVE): {
			auto yCurve_ptr = YCurve.Find(frame_on);
			if (yCurve_ptr != nullptr) {
				mmd::VMD_Curve* yCurve = yCurve_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(yCurve->ax, yCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(yCurve->bx, yCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (PMX_BONE_TAG_ZCURVE): {
			auto zCurve_ptr = ZCurve.Find(frame_on);
			if (zCurve_ptr != nullptr) {
				mmd::VMD_Curve* zCurve = zCurve_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(zCurve->ax, zCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(zCurve->bx, zCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (PMX_BONE_TAG_RCURVE): {
			auto rCurve_ptr = RCurve.Find(frame_on);
			if (rCurve_ptr != nullptr) {
				mmd::VMD_Curve* rCurve = rCurve_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(rCurve->ax, rCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(rCurve->bx, rCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (PMX_BONE_TAG_ACURVE): {
			auto aCurve_ptr = ACurve.Find(frame_on);
			if (aCurve_ptr != nullptr) {
				mmd::VMD_Curve* aCurve = aCurve_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(aCurve->ax, aCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(aCurve->bx, aCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		default:
			break;
		}
		bc->SetData(PMX_BONE_TAG_SPLINE, data_);
		prev_frame = frame_on;
		prev_curve_type = curve_type;
	}
	tag->GetParameter(DescID(BONE_NAME_IS), Ge_data, DESCFLAGS_GET::NONE);
	Int32 bone_name_is = Ge_data.GetInt32();
	if (bone_name_is) {
		tag->GetParameter(DescID(BONE_NAME_UNIVERSAL), Ge_data, DESCFLAGS_GET::NONE);
		op->SetName(Ge_data.GetString());
	}
	else {
		tag->GetParameter(DescID(BONE_NAME_LOCAL), Ge_data, DESCFLAGS_GET::NONE);
		op->SetName(Ge_data.GetString());
	}

	tag->GetParameter(DescID(ROTATABLE), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_rotatable = Ge_data.GetBool();
	if (Is_rotatable == 1) {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
	}
	else {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(TRANSLATABLE), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_translatable = Ge_data.GetBool();
	if (Is_translatable == 1) {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
	}
	else {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(IS_IK), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_IK = Ge_data.GetBool();
	if (Is_IK == 1) {
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(VISIBLE), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_visible = Ge_data.GetBool();
	if (Is_visible == 0) {
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
	}
	else {
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
	Bool Fixed_axis = Ge_data.GetBool();
	if (Fixed_axis == 1) {
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
	Float Inherit_bone_parent_influence = Ge_data.GetFloat();
	tag->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
	Bool Inherit_rotation = Ge_data.GetBool();
	tag->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
	Bool Inherit_translation = Ge_data.GetBool();
	if (Inherit_rotation == 1) {
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		tag->GetParameter(DescID(INHERIT_BONE_PARENT_LINK), Ge_data, DESCFLAGS_GET::NONE);
		BaseLink* inherit_bone_parent_link = Ge_data.GetBaseLink();
		if (inherit_bone_parent_link != nullptr) {
			BaseObject* inherit_bone_parent = (BaseObject*)inherit_bone_parent_link->GetLink(doc);
			if (inherit_bone_parent != nullptr) {
				tag->GetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
				Float32 Inherit_bone_parent_influence_ = Ge_data.GetFloat();
				op->SetRelRot(inherit_bone_parent->GetRelRot() * Inherit_bone_parent_influence_);
			}
		}
	}
	if (Inherit_translation == 1) {
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		tag->GetParameter(DescID(INHERIT_BONE_PARENT_LINK), Ge_data, DESCFLAGS_GET::NONE);
		BaseLink* inherit_bone_parent_link = Ge_data.GetBaseLink();
		if (inherit_bone_parent_link != nullptr) {
			BaseObject* inherit_bone_parent = (BaseObject*)inherit_bone_parent_link->GetLink(doc);
			if (inherit_bone_parent != nullptr) {
				tag->GetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
				Float32 Inherit_bone_parent_influence_ = Ge_data.GetFloat();
				op->SetRelPos(inherit_bone_parent->GetRelPos() * Inherit_bone_parent_influence_);
			}
		}
	}

	tag->GetParameter(DescID(TAIL_INDEX), Ge_data, DESCFLAGS_GET::NONE);
	Int32 Tail_index = Ge_data.GetInt32();
	tag->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
	Bool Indexed_tail_position = Ge_data.GetBool();
	if (Indexed_tail_position == 1) {
		if (Tail_index == -1) {
			op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
		}
		else {
			op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
		}
	}
	return EXECUTIONRESULT::OK;
}
Bool mmd::PMX_Bone_Tag::AddToExecution(BaseTag* tag, PriorityList* list) {
	if (list == nullptr || tag == nullptr) {
		return true;
	}
	list->Add(tag, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}
Bool mmd::PMX_Bone_Tag::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (id[0].id == PMX_BONE_TAG_SPLINE)
	{
		((SplineData*)t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(mmd::PMX_Bone_Tag::SplineDataCallBack, nullptr);
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool mmd::PMX_Bone_Tag::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case(MSG_DESCRIPTION_COMMAND): {
		DescriptionCommand* dc = (DescriptionCommand*)data;
		switch (dc->_descId[0].id)
		{
		case(PMX_BONE_TAG_INIT_CURVE_BUTTON):
		{
			CurveInit();
			break;
		}
		case(PMX_BONE_TAG_REGISTER_CURVE_BUTTON):
		{
			if (obj == nullptr) {
				return false;
			}
			BaseTime time = GetActiveDocument()->GetTime();
			Int32 frame = time.GetFrame(30);
			GeData data_, Curve_type_data;
			BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
			data_ = bc->GetData(PMX_BONE_TAG_SPLINE);
			SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);

			CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
			if (TrackPX == nullptr) {
				TrackPX = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
				obj->InsertTrackSorted(TrackPX);
			}
			CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
			if (TrackPY == nullptr) {
				TrackPY = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
				obj->InsertTrackSorted(TrackPY);
			}
			CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
			if (TrackPZ == nullptr) {
				TrackPZ = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
				obj->InsertTrackSorted(TrackPZ);
			}
			CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
			if (TrackRX == nullptr) {
				TrackRX = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
				obj->InsertTrackSorted(TrackRX);
			}
			CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
			if (TrackRY == nullptr) {
				TrackRY = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
				obj->InsertTrackSorted(TrackRY);
			}
			CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
			if (TrackRZ == nullptr) {
				TrackRZ = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
				obj->InsertTrackSorted(TrackRZ);
			}
			CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
			if (Frame_onTrack == nullptr) {
				Frame_onTrack = CTrack::Alloc(obj, DescID(PMX_BONE_TAG_FRAME_ON));
				obj->InsertTrackSorted(Frame_onTrack);
			}

			CCurve* CurvePX = TrackPX->GetCurve();
			CCurve* CurvePY = TrackPY->GetCurve();
			CCurve* CurvePZ = TrackPZ->GetCurve();
			CCurve* CurveRX = TrackRX->GetCurve();
			CCurve* CurveRY = TrackRY->GetCurve();
			CCurve* CurveRZ = TrackRZ->GetCurve();
			CCurve* Frame_onCurve = Frame_onTrack->GetCurve();

			CKey* KeyPX = CurvePX->AddKeyAdaptTangent(time, true);
			KeyPX->SetValue(CurvePX, obj->GetRelPos().x);
			CKey* KeyPY = CurvePY->AddKeyAdaptTangent(time, true);
			KeyPY->SetValue(CurvePY, obj->GetRelPos().y);
			CKey* KeyPZ = CurvePZ->AddKeyAdaptTangent(time, true);
			KeyPZ->SetValue(CurvePZ, obj->GetRelPos().z);
			CKey* KeyRX = CurveRX->AddKeyAdaptTangent(time, true);
			KeyRX->SetValue(CurveRX, obj->GetRelRot().x);
			CKey* KeyRY = CurveRY->AddKeyAdaptTangent(time, true);
			KeyRY->SetValue(CurveRY, obj->GetRelRot().y);
			CKey* KeyRZ = CurveRZ->AddKeyAdaptTangent(time, true);
			KeyRZ->SetValue(CurveRZ, obj->GetRelRot().z);
			CKey* KeyFrame_on = Frame_onCurve->AddKey(time);
			KeyFrame_on->SetValue(Frame_onCurve, time.GetFrame(30));
			KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
			KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
			KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);

			for (int i = 0; i < spline->GetKnotCount(); i++)
			{
				// 获取当前knot。
				CustomSplineKnot* knot = spline->GetKnot(i);
				// 切线存在于相对于其顶点的向量空间中，因此我们首先使切线向量全局化，然后限制它们。
				Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
				globalLeftTangent.ClampMax(Vector(127, 127, 0));
				globalLeftTangent.ClampMin(Vector(0, 0, 0));
				Vector globalRightTangent = knot->vPos + knot->vTangentRight;
				globalRightTangent.ClampMax(Vector(127, 127, 0));
				globalRightTangent.ClampMin(Vector(0, 0, 0));
				// 然后我们把切线转换回它们的局部切线空间，然后写回去。
				knot->vTangentLeft = globalLeftTangent - knot->vPos;
				knot->vTangentRight = globalRightTangent - knot->vPos;
			}

			UChar ax = spline->GetKnot(0)->vTangentRight.x;
			UChar ay = spline->GetKnot(0)->vTangentRight.y;
			UChar bx = -spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x;
			UChar by = -spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y;

			node->GetParameter(DescID(PMX_BONE_TAG_CURVE_TYPE), Curve_type_data, DESCFLAGS_GET::NONE);
			Int32 Curve_type = Curve_type_data.GetInt32();
			switch (Curve_type)
			{
			case (PMX_BONE_TAG_XCURVE): {
				auto xCurvr_ptr = XCurve.Find(frame);
				if (xCurvr_ptr != nullptr) {
					mmd::VMD_Curve* xCurvr = xCurvr_ptr->GetValue();
					xCurvr->ax = ax;
					xCurvr->ay = ay;
					xCurvr->bx = bx;
					xCurvr->by = by;
				}
				else {
					iferr(XCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				break;
			}
			case (PMX_BONE_TAG_YCURVE): {
				auto yCurvr_ptr = YCurve.Find(frame);
				if (yCurvr_ptr != nullptr) {
					mmd::VMD_Curve* yCurvr = yCurvr_ptr->GetValue();
					yCurvr->ax = ax;
					yCurvr->ay = ay;
					yCurvr->bx = bx;
					yCurvr->by = by;
				}
				else {
					iferr(YCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				break;
			}
			case (PMX_BONE_TAG_ZCURVE): {
				auto zCurvr_ptr = ZCurve.Find(frame);
				if (zCurvr_ptr != nullptr) {
					mmd::VMD_Curve* zCurvr = zCurvr_ptr->GetValue();
					zCurvr->ax = ax;
					zCurvr->ay = ay;
					zCurvr->bx = bx;
					zCurvr->by = by;
				}
				else {
					iferr(ZCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				break;
			}
			case (PMX_BONE_TAG_RCURVE): {
				auto rCurvr_ptr = RCurve.Find(frame);
				if (rCurvr_ptr != nullptr) {
					mmd::VMD_Curve* rCurvr = rCurvr_ptr->GetValue();
					rCurvr->ax = ax;
					rCurvr->ay = ay;
					rCurvr->bx = bx;
					rCurvr->by = by;
				}
				else {
					iferr(RCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				break;
			}
			case (PMX_BONE_TAG_ACURVE): {
				auto xCurvr_ptr = XCurve.Find(frame);
				if (xCurvr_ptr != nullptr) {
					mmd::VMD_Curve* xCurvr = xCurvr_ptr->GetValue();
					xCurvr->ax = ax;
					xCurvr->ay = ay;
					xCurvr->bx = bx;
					xCurvr->by = by;
				}
				else {
					iferr(XCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				auto yCurvr_ptr = YCurve.Find(frame);
				if (yCurvr_ptr != nullptr) {
					mmd::VMD_Curve* yCurvr = yCurvr_ptr->GetValue();
					yCurvr->ax = ax;
					yCurvr->ay = ay;
					yCurvr->bx = bx;
					yCurvr->by = by;
				}
				else {
					iferr(YCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				auto zCurvr_ptr = ZCurve.Find(frame);
				if (zCurvr_ptr != nullptr) {
					mmd::VMD_Curve* zCurvr = zCurvr_ptr->GetValue();
					zCurvr->ax = ax;
					zCurvr->ay = ay;
					zCurvr->bx = bx;
					zCurvr->by = by;
				}
				else {
					iferr(ZCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				auto rCurvr_ptr = RCurve.Find(frame);
				if (rCurvr_ptr != nullptr) {
					mmd::VMD_Curve* rCurvr = rCurvr_ptr->GetValue();
					rCurvr->ax = ax;
					rCurvr->ay = ay;
					rCurvr->bx = bx;
					rCurvr->by = by;
				}
				else {
					iferr(RCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				auto aCurvr_ptr = ACurve.Find(frame);
				if (aCurvr_ptr != nullptr) {
					mmd::VMD_Curve* aCurvr = aCurvr_ptr->GetValue();
					aCurvr->ax = ax;
					aCurvr->ay = ay;
					aCurvr->bx = bx;
					aCurvr->by = by;
				}
				else {
					iferr(ACurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				UpdateCurve(frame);
				break;
			}
			default:
				break;
			}
			break;
		}
		case(PMX_BONE_TAG_UPDATE_CURVE_BUTTON):
		{
			UpdateAllCurve();
			break;
		}
		case(PMX_BONE_TAG_DELETE_CURVE_BUTTON):
		{
			if (obj == nullptr) {
				return false;
			}
			BaseTime time = GetActiveDocument()->GetTime();
			Int32 frame = time.GetFrame(30);
			GeData data_, Curve_type_data;
			BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
			data_ = bc->GetData(PMX_BONE_TAG_SPLINE);
			SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);

			CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
			if (TrackPX == nullptr) {
				return true;
			}
			CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
			if (TrackPY == nullptr) {
				return true;
			}
			CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
			if (TrackPZ == nullptr) {
				return true;
			}
			CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
			if (TrackRX == nullptr) {
				return true;
			}
			CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
			if (TrackRY == nullptr) {
				return true;
			}
			CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
			if (TrackRZ == nullptr) {
				return true;
			}
			CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
			if (Frame_onTrack == nullptr) {
				return true;
			}

			CCurve* CurvePX = TrackPX->GetCurve();
			CCurve* CurvePY = TrackPY->GetCurve();
			CCurve* CurvePZ = TrackPZ->GetCurve();
			CCurve* CurveRX = TrackRX->GetCurve();
			CCurve* CurveRY = TrackRY->GetCurve();
			CCurve* CurveRZ = TrackRZ->GetCurve();
			CCurve* Frame_onCurve = Frame_onTrack->GetCurve();

			CKey* KeyPX = CurvePX->FindKey(time);
			if (KeyPX == nullptr) {
				return true;
			}
			CKey::Free(KeyPX);
			CKey* KeyPY = CurvePY->FindKey(time);
			if (KeyPY == nullptr) {
				return true;
			}
			CKey::Free(KeyPY);
			CKey* KeyPZ = CurvePZ->FindKey(time);
			if (KeyPZ == nullptr) {
				return true;
			}
			CKey::Free(KeyPZ);
			CKey* KeyRX = CurveRX->FindKey(time);
			if (KeyRX == nullptr) {
				return true;
			}
			CKey::Free(KeyRX);
			CKey* KeyRY = CurveRY->FindKey(time);
			if (KeyRY == nullptr) {
				return true;
			}
			CKey::Free(KeyRY);
			CKey* KeyRZ = CurveRZ->FindKey(time);
			if (KeyRZ == nullptr) {
				return true;
			}
			CKey::Free(KeyRZ);
			CKey* KeyFrame_on = Frame_onCurve->FindKey(time);
			if (KeyFrame_on == nullptr) {
				return true;
			}
			CKey::Free(KeyFrame_on);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
	return true;
}
