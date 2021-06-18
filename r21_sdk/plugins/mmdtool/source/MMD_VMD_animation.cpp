#include "MMD_VMD_animation.h"

void mmd::VMD_Cam_Obj::Free(GeListNode* node) {
	//GetActiveDocument()->FindSceneHook(ID_VMD_CAM_DRAW)->GetNodeData<VMD_Cam_Draw>()->DeleteDrawObj((BaseObject*)node);
	for (auto i : XCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : YCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : ZCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : RCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : DCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : VCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
}
Bool mmd::VMD_Cam_Obj::SplineDataCallBack(Int32 cid, const void* data)
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
		const Int32 KnotCount = splineData->GetKnotCount();
		for (Int32 i = 0; i < KnotCount; i++)
		{
			// 获取当前knot。
			CustomSplineKnot* knot = splineData->GetKnot(i);
			if (knot == nullptr)
				continue;
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
Bool mmd::VMD_Cam_Obj::GetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve) {
	switch (type)
	{
	case (VMD_CAM_OBJ_XCURVE): {
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
	case (VMD_CAM_OBJ_YCURVE): {
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
	case (VMD_CAM_OBJ_ZCURVE):
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
	case (VMD_CAM_OBJ_RCURVE): {
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
	case (VMD_CAM_OBJ_DCURVE): {
		auto dCurve_ptr = DCurve.Find(frame_on);
		if (dCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(dCurve_ptr->GetValue());
		}
		break;
	}
	case (VMD_CAM_OBJ_VCURVE): {
		auto vCurve_ptr = VCurve.Find(frame_on);
		if (vCurve_ptr == nullptr) {
			curve->ax = 20;
			curve->bx = 20;
			curve->ay = 20;
			curve->by = 20;
			return false;
		}
		else {
			*curve = *(vCurve_ptr->GetValue());
		}
		break;
	}
	case (VMD_CAM_OBJ_ACURVE): {
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
Bool mmd::VMD_Cam_Obj::SetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve) {
	BaseObject* obj = (BaseObject*)Get();
	if (obj == nullptr) {
		return false;
	}
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
	if (Frame_onTrack == nullptr) {
		Frame_onTrack = CTrack::Alloc(obj, DescID(VMD_CAM_OBJ_FRAME_ON));
		obj->InsertTrackSorted(Frame_onTrack);
	}
	CCurve* Frame_onCurve = Frame_onTrack->GetCurve();
	if (Frame_onCurve == nullptr) {
		return false;
	}
	CKey* KeyFrame_on = Frame_onCurve->AddKey(BaseTime(frame_on, 30));
	if (KeyFrame_on == nullptr) {
		return false;
	}
	KeyFrame_on->SetValue(Frame_onCurve, frame_on);
	KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	switch (type)
	{
	case (VMD_CAM_OBJ_XCURVE): {
		iferr(XCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (VMD_CAM_OBJ_YCURVE): {
		iferr(YCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (VMD_CAM_OBJ_ZCURVE): {
		iferr(ZCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (VMD_CAM_OBJ_RCURVE): {
		iferr(RCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (VMD_CAM_OBJ_DCURVE): {
		iferr(DCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (VMD_CAM_OBJ_VCURVE): {
		iferr(VCurve.Insert(frame_on, curve))return false;
		break;
	}
	case (VMD_CAM_OBJ_ACURVE): {
		iferr(XCurve.Insert(frame_on, curve))return false;
		iferr(YCurve.Insert(frame_on, curve))return false;
		iferr(ZCurve.Insert(frame_on, curve))return false;
		iferr(RCurve.Insert(frame_on, curve))return false;
		iferr(DCurve.Insert(frame_on, curve))return false;
		iferr(VCurve.Insert(frame_on, curve))return false;
		iferr(ACurve.Insert(frame_on, curve))return false;
		break;
	}
	default:
		return false;
		break;
	}
	return true;
}
Bool mmd::VMD_Cam_Obj::UpdateAllCurve() {
	BaseObject* op = static_cast<BaseObject*>(Get());
	CTrack* Frame_onTrack = op->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
	if (Frame_onTrack != nullptr) {
		CCurve* Frame_onCurve = Frame_onTrack->GetCurve();
		if (Frame_onCurve != nullptr) {
			const Int32 KeyCount = Frame_onCurve->GetKeyCount();
			for (Int32 i = 0; i < KeyCount; i++) {
				UpdateCurve(Frame_onCurve->GetKey(i)->GetValue());
			}
		}
	}
	return true;
}
Bool mmd::VMD_Cam_Obj::UpdateCurve(Int32 frame_on) {
	BaseObject* op = static_cast<BaseObject*>(Get());
	CTrack* frameTrack = op->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
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
		CTrack* TrackPX = op->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
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
		CTrack* TrackPY = op->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
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
		CTrack* TrackPZ = op->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
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
		CTrack* TrackRX = op->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
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
			CTrack* TrackRY = op->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
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
			CTrack* TrackRZ = op->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
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
	auto dCurve_ptr = DCurve.Find(frame_on);
	if (dCurve_ptr != nullptr) {
		mmd::VMD_Curve* dCurve = dCurve_ptr->GetValue();
		CTrack* TrackDistance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		if (TrackDistance != nullptr) {
			CCurve* CurveDistance = TrackDistance->GetCurve();
			if (CurveDistance != nullptr) {
				CKey* KeyDistance = CurveDistance->FindKey(BaseTime(frame_on, 30));
				if (KeyDistance != nullptr) {
					CKey* KeyDistance_next = CurveDistance->FindKey(next_time);
					if (KeyDistance_next != nullptr) {
						if (dCurve->ax == dCurve->ay && dCurve->bx == dCurve->by) {
							KeyDistance->SetInterpolation(CurveDistance, CINTERPOLATION::LINEAR);
						}
						else {
							Float ValueOfTwoFrames = KeyDistance_next->GetValue() - KeyDistance->GetValue();
							KeyDistance->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							KeyDistance_next->SetTimeLeft(CurveDistance, BaseTime(-TimeOfTwoFrames * ((Float)dCurve->bx / 127.0), 30));
							KeyDistance_next->SetValueLeft(CurveDistance, -ValueOfTwoFrames * ((Float)dCurve->by / 127.0));
							KeyDistance->SetTimeRight(CurveDistance, BaseTime(TimeOfTwoFrames * ((Float)dCurve->ax / 127.0), 30));
							KeyDistance->SetValueRight(CurveDistance, ValueOfTwoFrames * ((Float)dCurve->ay / 127.0));
						}
					}
				}
			}
		}
	}
	auto vCurve_ptr = VCurve.Find(frame_on);
	if (vCurve_ptr != nullptr) {
		mmd::VMD_Curve* vCurve = vCurve_ptr->GetValue();
		CTrack* TrackAOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
		if (TrackAOV != nullptr) {
			CCurve* CurveAOV = TrackAOV->GetCurve();
			if (CurveAOV != nullptr) {
				CKey* KeyAOV = CurveAOV->FindKey(BaseTime(frame_on, 30));
				if (KeyAOV != nullptr) {
					CKey* KeyAOV_next = CurveAOV->FindKey(next_time);
					if (KeyAOV_next != nullptr) {
						if (vCurve->ax == vCurve->ay && vCurve->bx == vCurve->by) {
							KeyAOV->SetInterpolation(CurveAOV, CINTERPOLATION::LINEAR);
						}
						else {
							Float ValueOfTwoFrames = KeyAOV_next->GetValue() - KeyAOV->GetValue();
							KeyAOV->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							KeyAOV_next->SetTimeLeft(CurveAOV, BaseTime(-TimeOfTwoFrames * ((Float)vCurve->bx / 127.0), 30));
							KeyAOV_next->SetValueLeft(CurveAOV, -ValueOfTwoFrames * ((Float)vCurve->by / 127.0));
							KeyAOV->SetTimeRight(CurveAOV, BaseTime(TimeOfTwoFrames * ((Float)vCurve->ax / 127.0), 30));
							KeyAOV->SetValueRight(CurveAOV, ValueOfTwoFrames * ((Float)vCurve->ay / 127.0));
						}
					}
				}
			}
		}
	}
	return true;
}
Bool mmd::VMD_Cam_Obj::CameraInit() {
	if (cam == nullptr) {
		BaseObject* down_obj = reinterpret_cast<BaseObject*>(Get()->GetDown());
		if (down_obj != nullptr) {
			if (down_obj->GetType() == Ocamera) {
				cam = down_obj;
			}
			else {
				cam = BaseObject::Alloc(Ocamera);//5103
				cam->SetName("Camera"_s);
				BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
				ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
				cam->InsertTag(ProtectionTag);
				cam->InsertUnder(Get());
			}
		}
		else {
			cam = BaseObject::Alloc(Ocamera);//5103
			cam->SetName("Camera"_s);
			BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
			ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
			cam->InsertTag(ProtectionTag);
			cam->InsertUnder(Get());
		}
	}
	return true;
}
Bool mmd::VMD_Cam_Obj::CurveInit() {
	if (Get() == nullptr)return false;
	BaseContainer* bc = ((BaseList2D*)Get())->GetDataInstance();
	GeData data = GeData(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
	SplineData* spline = (SplineData*)data.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
	if (spline!=nullptr)
	{
		spline->AdaptRange(0, 127, 127, 0, 127, 127);
		spline->InsertKnot(0.0, 0.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->InsertKnot(127.0, 127.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->SetUserCallback(mmd::VMD_Cam_Obj::SplineDataCallBack, nullptr);
		CustomSplineKnot* a = spline->GetKnot(0);
		CustomSplineKnot* b = spline->GetKnot(spline->GetKnotCount() - 1);
		a->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		b->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		a->vTangentRight = Vector(20, 20, 0);
		b->vTangentLeft = Vector(-20, -20, 0);
	}
	bc->SetData(VMD_CAM_OBJ_SPLINE, data);
	return true;
}
Bool mmd::VMD_Cam_Obj::Init(GeListNode* node) {
	if (node == nullptr)return false;
	node->SetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), 6, DESCFLAGS_SET::NONE);
	if (!CurveInit())return false;
	return true;
}
Bool mmd::VMD_Cam_Obj::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (id[0].id == VMD_CAM_OBJ_SPLINE)
	{
		((SplineData*)t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(mmd::VMD_Cam_Obj::SplineDataCallBack, nullptr);
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool mmd::VMD_Cam_Obj::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case(MSG_DESCRIPTION_COMMAND): {
		DescriptionCommand* dc = (DescriptionCommand*)data;
		switch (dc->_descId[0].id)
		{
		case(VMD_CAM_OBJ_INIT_CURVE_BUTTON):
		{
			CurveInit();
			break;
		}
		case(VMD_CAM_OBJ_REGISTER_CURVE_BUTTON):
		{
			BaseObject* obj = (BaseObject*)node;
			if (obj == nullptr) {
				return true;
			}
			BaseTime time = GetActiveDocument()->GetTime();
			Int32 frame = time.GetFrame(30);
			GeData data_, Curve_type_data;
			BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
			if (bc == nullptr) {
				return true;
			}
			data_ = bc->GetData(VMD_CAM_OBJ_SPLINE);
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
			CTrack* TrackDistance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
			if (TrackDistance == nullptr) {
				TrackDistance = CTrack::Alloc(cam, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
				cam->InsertTrackSorted(TrackDistance);
			}
			CTrack* TrackAOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
			if (TrackAOV == nullptr) {
				TrackAOV = CTrack::Alloc(cam, DescID(CAMERAOBJECT_APERTURE));
				cam->InsertTrackSorted(TrackAOV);
			}
			CTrack* Frame_onTrack = obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
			if (Frame_onTrack == nullptr) {
				Frame_onTrack = CTrack::Alloc(obj, DescID(VMD_CAM_OBJ_FRAME_ON));
				obj->InsertTrackSorted(Frame_onTrack);
			}

			CCurve* CurvePX = TrackPX->GetCurve();
			CCurve* CurvePY = TrackPY->GetCurve();
			CCurve* CurvePZ = TrackPZ->GetCurve();
			CCurve* CurveRX = TrackRX->GetCurve();
			CCurve* CurveRY = TrackRY->GetCurve();
			CCurve* CurveRZ = TrackRZ->GetCurve();
			CCurve* CurveDistance = TrackDistance->GetCurve();
			CCurve* CurveAOV = TrackAOV->GetCurve();
			CCurve* Frame_onCurve = Frame_onTrack->GetCurve();

			//确保获取成功
			if (CurvePX == nullptr || CurvePY == nullptr || CurvePZ == nullptr || CurveRX == nullptr || CurveRY == nullptr || CurveRZ == nullptr || CurveDistance == nullptr || CurveAOV == nullptr || Frame_onCurve == nullptr)
			{
				return true;
			}

			CKey* KeyPX = CurvePX->AddKeyAdaptTangent(time, true);
			if (KeyPX == nullptr) {
				return true;
			}
			KeyPX->SetValue(CurvePX, obj->GetRelPos().x);
			CKey* KeyPY = CurvePY->AddKeyAdaptTangent(time, true);
			if (KeyPY == nullptr) {
				return true;
			}
			KeyPY->SetValue(CurvePY, obj->GetRelPos().y);
			CKey* KeyPZ = CurvePZ->AddKeyAdaptTangent(time, true);
			if (KeyPZ == nullptr) {
				return true;
			}
			KeyPZ->SetValue(CurvePZ, obj->GetRelPos().z);
			CKey* KeyRX = CurveRX->AddKeyAdaptTangent(time, true);
			if (KeyRX == nullptr) {
				return true;
			}
			KeyRX->SetValue(CurveRX, obj->GetRelRot().x);
			CKey* KeyRY = CurveRY->AddKeyAdaptTangent(time, true);
			if (KeyRY == nullptr) {
				return true;
			}
			KeyRY->SetValue(CurveRY, obj->GetRelRot().y);
			CKey* KeyRZ = CurveRZ->AddKeyAdaptTangent(time, true);
			if (KeyRZ == nullptr) {
				return true;
			}
			KeyRZ->SetValue(CurveRZ, obj->GetRelRot().z);
			CKey* DistanceKey = CurveDistance->AddKeyAdaptTangent(time, true);
			if (DistanceKey == nullptr) {
				return true;
			}
			DistanceKey->SetValue(CurveDistance, cam->GetRelPos().z);
			CKey* AOVKey = CurveAOV->AddKeyAdaptTangent(time, true);
			if (AOVKey == nullptr) {
				return true;
			}
			AOVKey->SetValue(CurveAOV, static_cast<CameraObject*>(obj)->GetAperture());
			CKey* KeyFrame_on = Frame_onCurve->AddKey(time);
			if (KeyFrame_on == nullptr) {
				return true;
			}
			KeyFrame_on->SetValue(Frame_onCurve, time.GetFrame(30));
			KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
			KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
			KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
			const Int32 KnotCount = spline->GetKnotCount();
			for (int i = 0; i < KnotCount; i++)
			{
				// 获取当前knot。
				CustomSplineKnot* knot = spline->GetKnot(i);
				if (knot == nullptr) {
					return true;
				}
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

			node->GetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), Curve_type_data, DESCFLAGS_GET::NONE);
			Int32 Curve_type = Curve_type_data.GetInt32();
			switch (Curve_type)
			{
			case (VMD_CAM_OBJ_XCURVE): {
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
			case (VMD_CAM_OBJ_YCURVE): {
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
			case (VMD_CAM_OBJ_ZCURVE): {
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
			case (VMD_CAM_OBJ_RCURVE): {
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
			case (VMD_CAM_OBJ_DCURVE): {
				auto dCurvr_ptr = DCurve.Find(frame);
				if (dCurvr_ptr != nullptr) {
					mmd::VMD_Curve* dCurvr = dCurvr_ptr->GetValue();
					dCurvr->ax = ax;
					dCurvr->ay = ay;
					dCurvr->bx = bx;
					dCurvr->by = by;
				}
				else {
					iferr(DCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				break;
			}
			case (VMD_CAM_OBJ_VCURVE): {
				auto vCurvr_ptr = VCurve.Find(frame);
				if (vCurvr_ptr != nullptr) {
					mmd::VMD_Curve* vCurvr = vCurvr_ptr->GetValue();
					vCurvr->ax = ax;
					vCurvr->ay = ay;
					vCurvr->bx = bx;
					vCurvr->by = by;
				}
				else {
					iferr(VCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				break;
			}
			case (VMD_CAM_OBJ_ACURVE): {
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
				auto dCurvr_ptr = DCurve.Find(frame);
				if (dCurvr_ptr != nullptr) {
					mmd::VMD_Curve* dCurvr = dCurvr_ptr->GetValue();
					dCurvr->ax = ax;
					dCurvr->ay = ay;
					dCurvr->bx = bx;
					dCurvr->by = by;
				}
				else {
					iferr(DCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
				}
				auto vCurvr_ptr = VCurve.Find(frame);
				if (vCurvr_ptr != nullptr) {
					mmd::VMD_Curve* vCurvr = vCurvr_ptr->GetValue();
					vCurvr->ax = ax;
					vCurvr->ay = ay;
					vCurvr->bx = bx;
					vCurvr->by = by;
				}
				else {
					iferr(VCurve.Insert(frame, new  mmd::VMD_Curve(ax, ay, bx, by)))return false;
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
		case(VMD_CAM_OBJ_UPDATE_CURVE_BUTTON):
		{
			UpdateAllCurve();
			break;
		}
		case(VMD_CAM_OBJ_DELETE_CURVE_BUTTON):
		{
			BaseObject* obj = (BaseObject*)node;
			if (obj == nullptr) {
				return true;
			}
			BaseTime time = GetActiveDocument()->GetTime();
			Int32 frame = time.GetFrame(30);
			GeData data_, Curve_type_data;
			BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
			if (bc == nullptr) {
				return true;
			}
			data_ = bc->GetData(VMD_CAM_OBJ_SPLINE);
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
			CTrack* TrackDistance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
			if (TrackDistance == nullptr) {
				return true;
			}
			CTrack* TrackAOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
			if (TrackAOV == nullptr) {
				return true;
			}
			CTrack* Frame_onTrack = obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
			if (Frame_onTrack == nullptr) {
				return true;
			}

			CCurve* CurvePX = TrackPX->GetCurve();
			CCurve* CurvePY = TrackPY->GetCurve();
			CCurve* CurvePZ = TrackPZ->GetCurve();
			CCurve* CurveRX = TrackRX->GetCurve();
			CCurve* CurveRY = TrackRY->GetCurve();
			CCurve* CurveRZ = TrackRZ->GetCurve();
			CCurve* CurveDistance = TrackDistance->GetCurve();
			CCurve* CurveAOV = TrackAOV->GetCurve();
			CCurve* Frame_onCurve = Frame_onTrack->GetCurve();

			if (CurvePX == nullptr || CurvePY == nullptr || CurvePZ == nullptr || CurveRX == nullptr || CurveRY == nullptr || CurveRZ == nullptr || CurveDistance == nullptr || CurveAOV == nullptr || Frame_onCurve == nullptr)
			{
				return true;
			}

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
			CKey* DistanceKey = CurveDistance->FindKey(time);
			if (DistanceKey == nullptr) {
				return true;
			}
			CKey::Free(DistanceKey);
			CKey* AOVKey = CurveAOV->FindKey(time);
			AOVKey->SetValue(CurveAOV, static_cast<CameraObject*>(obj)->GetAperture());
			if (AOVKey == nullptr) {
				return true;
			}
			CKey::Free(AOVKey);
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
	case(MSG_MENUPREPARE): {
		if (!CameraInit())return true;
		node->SetParameter(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y), 85.0, DESCFLAGS_SET::NONE);
		cam->SetRelPos(Vector(0, 0, -382.5));
		break;
	}
	default:
		break;
	}
	return true;
}
Bool mmd::VMD_Cam_Obj::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (id[0].id == VMD_CAM_OBJ_FRAME_ON)return false;
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}
Bool mmd::VMD_Cam_Draw::Draw(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags) {
	if (!node || !doc || !bd || !bh) return false;
	if (flags != SCENEHOOKDRAW::DRAW_PASS) return true;
	BaseObject* op = doc->GetActiveObject();
	if (op != nullptr) {
		if (op->GetType() == ID_VMD_CAM_OBJ) {
			// store and set line width
			const GeData oldLineWidth = bd->GetDrawParam(DRAW_PARAMETER_LINEWIDTH);
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, GeData{ 4.0 });
			const Vector& screenSpacePos = bd->WS(op->GetMg().off);
			// set color
			bd->SetPen(Vector(255, 86, 137) / 255);
			// draw circle
			bd->DrawCircle2D(screenSpacePos.x, screenSpacePos.y, 16);
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, GeData{ 8 });
			bd->DrawCircle2D(screenSpacePos.x, screenSpacePos.y, 4);
			// reset matrix
			bd->SetMatrix_Matrix(NULL, Matrix(), 0);
			// reset parameter
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, oldLineWidth);
		}
	}
	if (bd->TestBreak())return true;
	return SUPER::Draw(node, doc, bd, bh, bt, flags);
}
EXECUTIONRESULT mmd::VMD_Cam_Obj::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
	if (op == nullptr || doc == nullptr) {
		return EXECUTIONRESULT::OK;
	}
	if (cam == nullptr) {
		BaseObject* down_obj = op->GetDown();
		if (down_obj != nullptr) {
			if (down_obj->GetType() == Ocamera) {
				cam = down_obj;
			}
			else {
				cam = BaseObject::Alloc(Ocamera);//5103
				cam->SetName("Camera"_s);
				BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
				ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
				cam->InsertTag(ProtectionTag);
				cam->InsertUnder(op);
			}
		}
		else {
			cam = BaseObject::Alloc(Ocamera);//5103
			cam->SetName("Camera"_s);
			BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
			ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
			cam->InsertTag(ProtectionTag);
			cam->InsertUnder(op);
		}
	}
	GeData data;
	op->GetParameter(DescID(VMD_CAM_OBJ_FRAME_ON), data, DESCFLAGS_GET::NONE);
	Int32 frame_on = data.GetInt32();
	op->GetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), data, DESCFLAGS_GET::NONE);
	Int32 curve_type = data.GetInt32();

	if (prev_frame != frame_on || prev_curve_type != curve_type)
	{
		BaseContainer* bc = ((BaseList2D*)op)->GetDataInstance();
		if (bc == nullptr) {
			return EXECUTIONRESULT::OK;
		}
		GeData data_ = bc->GetData(VMD_CAM_OBJ_SPLINE);
		SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
		if (spline == nullptr) {
			return EXECUTIONRESULT::OK;
		}
		switch (curve_type)
		{
		case (VMD_CAM_OBJ_XCURVE): {
			auto xCurve_ptr = XCurve.Find(frame_on);
			if (xCurve_ptr != nullptr) {
				mmd::VMD_Curve* xCurve = xCurve_ptr->GetValue();
				if (xCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
				spline->GetKnot(0)->vTangentRight = Vector(xCurve->ax, xCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(xCurve->bx, xCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (VMD_CAM_OBJ_YCURVE): {
			auto yCurve_ptr = YCurve.Find(frame_on);
			if (yCurve_ptr != nullptr) {
				mmd::VMD_Curve* yCurve = yCurve_ptr->GetValue();
				if (yCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
				spline->GetKnot(0)->vTangentRight = Vector(yCurve->ax, yCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(yCurve->bx, yCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (VMD_CAM_OBJ_ZCURVE): {
			auto zCurve_ptr = ZCurve.Find(frame_on);
			if (zCurve_ptr != nullptr) {
				mmd::VMD_Curve* zCurve = zCurve_ptr->GetValue();
				if (zCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
				spline->GetKnot(0)->vTangentRight = Vector(zCurve->ax, zCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(zCurve->bx, zCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (VMD_CAM_OBJ_RCURVE): {
			auto rCurve_ptr = RCurve.Find(frame_on);
			if (rCurve_ptr != nullptr) {
				mmd::VMD_Curve* rCurve = rCurve_ptr->GetValue();
				if (rCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
				spline->GetKnot(0)->vTangentRight = Vector(rCurve->ax, rCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(rCurve->bx, rCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (VMD_CAM_OBJ_DCURVE): {
			auto dCurve_ptr = DCurve.Find(frame_on);
			if (dCurve_ptr != nullptr) {
				mmd::VMD_Curve* dCurve = dCurve_ptr->GetValue();
				if (dCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
				spline->GetKnot(0)->vTangentRight = Vector(dCurve->ax, dCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(dCurve->bx, dCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (VMD_CAM_OBJ_VCURVE): {
			auto vCurve_ptr = VCurve.Find(frame_on);
			if (vCurve_ptr != nullptr) {
				mmd::VMD_Curve* vCurve = vCurve_ptr->GetValue();
				if (vCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
				spline->GetKnot(0)->vTangentRight = Vector(vCurve->ax, vCurve->ay, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = -Vector(vCurve->bx, vCurve->by, 0);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20, 20, 0);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20, -20, 0);
			}
			break;
		}
		case (VMD_CAM_OBJ_ACURVE): {
			auto aCurve_ptr = ACurve.Find(frame_on);
			if (aCurve_ptr != nullptr) {
				mmd::VMD_Curve* aCurve = aCurve_ptr->GetValue();
				if (aCurve == nullptr) {
					return EXECUTIONRESULT::OK;
				}
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
		bc->SetData(VMD_CAM_OBJ_SPLINE, data_);
		prev_frame = frame_on;
		prev_curve_type = curve_type;
	}
	return EXECUTIONRESULT::OK;
}
Bool mmd::VMD_Cam_Obj::AddToExecution(BaseObject* op, PriorityList* list) {
	if (list == nullptr || op == nullptr) {
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}
maxon::Result<BaseObject*> mmd::VMD_Cam_Obj::ConversionCamera(VMD_Conversion_Camera_settings setting) {
	//获取活动文档
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	BaseObject* SelectObject = nullptr;

	if (setting.str_cam == nullptr) //若传入的参数非空则使用传入参数
	{
		//获取选中对象
		SelectObject = doc->GetActiveObject();
		if (SelectObject == nullptr) {
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return maxon::NullptrError(MAXON_SOURCE_LOCATION);
		}
	}
	else //否则使用选择参数
	{
		SelectObject = setting.str_cam;
	}

	//判断选中对象类型是否为摄像机
	if (SelectObject->GetType() != Ocamera) {
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}

	//创建转换目标对象
	BaseObject* VMDCamera = BaseObject::Alloc(ID_VMD_CAM_OBJ);
	if (VMDCamera == nullptr) {
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}

	//创建要转化摄像机的副本，防止操作破坏原摄像机对象的数据
	BaseObject* SelectObjectClone = (BaseObject*)SelectObject->GetClone(COPYFLAGS::NO_HIERARCHY, nullptr);
	VMDCamera->SetName(SelectObjectClone->GetName());
	doc->InsertObject(VMDCamera, nullptr, nullptr);

	//获取目标对象内部的数据
	mmd::VMD_Cam_Obj* VMDCamera_data = VMDCamera->GetNodeData<VMD_Cam_Obj>();
	if (!VMDCamera_data->CameraInit()) {
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	BaseObject* VMDCameraDistance = VMDCamera_data->cam;

	//将时间设置为0
	doc->SetTime(BaseTime());

	//确保每个必要的参数都注册了CTrack，没有则创建一个
	CTrack* strTrackPX = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (strTrackPX == nullptr) {
		strTrackPX = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		strTrackPX->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackPX->GetCurve(), SelectObjectClone->GetRelPos().x);
		SelectObjectClone->InsertTrackSorted(strTrackPX);
	}
	CTrack* strTrackPY = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (strTrackPY == nullptr) {
		strTrackPY = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		strTrackPY->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackPY->GetCurve(), SelectObjectClone->GetRelPos().y);
		SelectObjectClone->InsertTrackSorted(strTrackPY);
	}
	CTrack* strTrackPZ = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (strTrackPZ == nullptr) {
		strTrackPZ = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		strTrackPZ->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackPZ->GetCurve(), SelectObjectClone->GetRelPos().z);
		SelectObjectClone->InsertTrackSorted(strTrackPZ);
	}
	CTrack* strTrackRX = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (strTrackRX == nullptr) {
		strTrackRX = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		strTrackRX->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackRX->GetCurve(), SelectObjectClone->GetRelRot().x);
		SelectObjectClone->InsertTrackSorted(strTrackRX);
	}
	CTrack* strTrackRY = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (strTrackRY == nullptr) {
		strTrackRY = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		strTrackRY->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackRY->GetCurve(), SelectObjectClone->GetRelRot().y);
		SelectObjectClone->InsertTrackSorted(strTrackRY);
	}
	CTrack* strTrackRZ = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (strTrackRZ == nullptr) {
		strTrackRZ = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		strTrackRZ->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackRZ->GetCurve(), SelectObjectClone->GetRelRot().z);
		SelectObjectClone->InsertTrackSorted(strTrackRZ);
	}
	CTrack* strTrackAOV = SelectObjectClone->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	if (strTrackAOV == nullptr) {
		strTrackAOV = CTrack::Alloc(SelectObjectClone, DescID(CAMERAOBJECT_APERTURE));
		strTrackAOV->GetCurve()->AddKeyAdaptTangent(BaseTime(), false)->SetValue(strTrackAOV->GetCurve(), ((CameraObject*)SelectObjectClone)->GetAperture());
		SelectObjectClone->InsertTrackSorted(strTrackAOV);
	}

	//确保生成成功
	if (strTrackPX == nullptr || strTrackPY == nullptr || strTrackPZ == nullptr || strTrackRX == nullptr || strTrackRY == nullptr || strTrackRZ == nullptr || strTrackAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}

	//获取曲线对象
	CCurve* strCurvePX = strTrackPX->GetCurve();
	CCurve* strCurvePY = strTrackPY->GetCurve();
	CCurve* strCurvePZ = strTrackPZ->GetCurve();
	CCurve* strCurveRX = strTrackRX->GetCurve();
	CCurve* strCurveRY = strTrackRY->GetCurve();
	CCurve* strCurveRZ = strTrackRZ->GetCurve();
	CCurve* strCurveAOV = strTrackAOV->GetCurve();

	//确保获取成功
	if (strCurvePX == nullptr || strCurvePY == nullptr || strCurvePZ == nullptr || strCurveRX == nullptr || strCurveRY == nullptr || strCurveRZ == nullptr || strCurveAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}

	//将所有参数的全部关键帧所在帧置入数组（frame_arr）
	maxon::BaseArray<Int32> frame_arr;
	const Int32 PXKeyCount = strCurvePX->GetKeyCount();
	for (Int32 i = 0; i < PXKeyCount; i++) {
		Int32 strframePX = strCurvePX->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframePX) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframePX))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}
	const Int32 PYKeyCount = strCurvePY->GetKeyCount();
	for (Int32 i = 0; i < PYKeyCount; i++) {
		Int32 strframePY = strCurvePY->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframePY) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframePY))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}
	const Int32 PZKeyCount = strCurvePZ->GetKeyCount();
	for (Int32 i = 0; i < PZKeyCount; i++) {
		Int32 strframePZ = strCurvePZ->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframePZ) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframePZ))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}
	const Int32 RXKeyCount = strCurveRX->GetKeyCount();
	for (Int32 i = 0; i < RXKeyCount; i++) {
		Int32 strframeRX = strCurveRX->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframeRX) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframeRX))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}
	const Int32 RYKeyCount = strCurveRY->GetKeyCount();
	for (Int32 i = 0; i < RYKeyCount; i++) {
		Int32 strframeRY = strCurveRY->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframeRY) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframeRY))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}
	const Int32 RZKeyCount = strCurveRZ->GetKeyCount();
	for (Int32 i = 0; i < RZKeyCount; i++) {
		Int32 strframeRZ = strCurveRZ->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframeRZ) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframeRZ))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}
	const Int32 AOVKeyCount = strCurveAOV->GetKeyCount();
	for (Int32 i = 0; i < AOVKeyCount; i++) {
		Int32 strframeAOV = strCurveAOV->GetKey(i)->GetTime().GetFrame(30);
		if (frame_arr.Find(strframeAOV) == maxon::BaseArray<Int32>::Iterator()) {
			iferr(frame_arr.Append(strframeAOV))return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}

	//为目标对象生成动画轨迹
	CTrack* CameraTrackPX = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* CameraTrackPY = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* CameraTrackPZ = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* CameraTrackRX = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* CameraTrackRY = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* CameraTrackRZ = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* CameraTrackDistance = CTrack::Alloc(VMDCameraDistance, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* CameraTrackAOV = CTrack::Alloc(VMDCameraDistance, DescID(CAMERAOBJECT_APERTURE));
	CTrack* Frame_onTrack = CTrack::Alloc(VMDCamera, DescID(VMD_CAM_OBJ_FRAME_ON));

	//确保生成成功
	if (CameraTrackPX == nullptr || CameraTrackPY == nullptr || CameraTrackPZ == nullptr || CameraTrackRX == nullptr || CameraTrackRY == nullptr || CameraTrackRZ == nullptr || CameraTrackDistance == nullptr || CameraTrackAOV == nullptr || Frame_onTrack == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	CCurve* CameraCurvePX = CameraTrackPX->GetCurve();
	CCurve* CameraCurvePY = CameraTrackPY->GetCurve();
	CCurve* CameraCurvePZ = CameraTrackPZ->GetCurve();
	CCurve* CameraCurveRX = CameraTrackRX->GetCurve();
	CCurve* CameraCurveRY = CameraTrackRY->GetCurve();
	CCurve* CameraCurveRZ = CameraTrackRZ->GetCurve();
	CCurve* CameraCurveDistance = CameraTrackDistance->GetCurve();
	CCurve* CameraCurveAOV = CameraTrackAOV->GetCurve();
	CCurve* Frame_onCurve = Frame_onTrack->GetCurve();

	//确保获取成功
	if (CameraCurvePX == nullptr || CameraCurvePY == nullptr || CameraCurvePZ == nullptr || CameraCurveRX == nullptr || CameraCurveRY == nullptr || CameraCurveRZ == nullptr || CameraCurveDistance == nullptr || CameraCurveAOV == nullptr || Frame_onCurve == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}

	//将生成的动画轨迹插入目标对象
	VMDCamera->InsertTrackSorted(CameraTrackPX);
	VMDCamera->InsertTrackSorted(CameraTrackPY);
	VMDCamera->InsertTrackSorted(CameraTrackPZ);
	VMDCamera->InsertTrackSorted(CameraTrackRX);
	VMDCamera->InsertTrackSorted(CameraTrackRY);
	VMDCamera->InsertTrackSorted(CameraTrackRZ);
	VMDCamera->InsertTrackSorted(Frame_onTrack);
	VMDCameraDistance->InsertTrackSorted(CameraTrackDistance);
	VMDCameraDistance->InsertTrackSorted(CameraTrackAOV);

	//确保每个参数在同一帧都注册了关键帧（根据frame_arr查找）
	for (Int32 i : frame_arr)
	{
		BaseTime frame_time(i, 30);
		if (strCurvePX->FindKey(frame_time) == nullptr) {
			strCurvePX->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurvePY->FindKey(frame_time) == nullptr) {
			strCurvePY->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurvePZ->FindKey(frame_time) == nullptr) {
			strCurvePZ->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveRX->FindKey(frame_time) == nullptr) {
			strCurveRX->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveRY->FindKey(frame_time) == nullptr) {
			strCurveRY->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveRZ->FindKey(frame_time) == nullptr) {
			strCurveRZ->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveAOV->FindKey(frame_time) == nullptr) {
			strCurveAOV->AddKeyAdaptTangent(frame_time, false);
		}
		if (CameraCurveDistance->FindKey(frame_time) == nullptr) {
			CameraCurveDistance->AddKeyAdaptTangent(frame_time, false);
		}
	}

	//转换移动和旋转写入对象，添加关键帧数据
	for (Int32 i : frame_arr)
	{
		BaseTime frame_time(i, 30);
		CameraCurvePX->AddKey(frame_time)->SetValue(CameraCurvePX, strCurvePX->FindKey(frame_time)->GetValue());
		CameraCurvePY->AddKey(frame_time)->SetValue(CameraCurvePY, strCurvePY->FindKey(frame_time)->GetValue());
		CameraCurvePZ->AddKey(frame_time)->SetValue(CameraCurvePZ, strCurvePZ->FindKey(frame_time)->GetValue());
		CameraCurveRX->AddKey(frame_time)->SetValue(CameraCurveRX, strCurveRX->FindKey(frame_time)->GetValue());
		CameraCurveRY->AddKey(frame_time)->SetValue(CameraCurveRY, strCurveRY->FindKey(frame_time)->GetValue());
		CameraCurveRZ->AddKey(frame_time)->SetValue(CameraCurveRZ, strCurveRZ->FindKey(frame_time)->GetValue());
		CameraCurveAOV->AddKey(frame_time)->SetValue(CameraCurveAOV, strCurveAOV->FindKey(frame_time)->GetValue());
		CameraCurveDistance->AddKey(frame_time)->SetValue(CameraCurveDistance, CameraCurveDistance->FindKey(frame_time)->GetValue());
		CKey* KeyFrame_on = Frame_onCurve->AddKey(frame_time);
		KeyFrame_on->SetValue(Frame_onCurve, i);
		KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
		KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
		KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	}

	Float ValueOfTwoFrames;
	Int32 TimeOfTwoFrames;
	Int32 frame_on, next_frame_on;
	Int32 frame_arr_count = frame_arr.GetCount();
	const Float Fps = doc->GetFps();
	//转换曲线并保存到对象
	CKey* Key = nullptr;
	CKey* NextKey = nullptr;
	Float64 KeyLeftX = 0., KeyLeftY = 0., KeyRightX = 0., KeyRightY = 0., NextKeyLeftX = 0., NextKeyLeftY = 0., NextKeyRightX = 0., NextKeyRightY = 0.;
	for (Int i = 0; i < frame_arr_count; i++)
	{
		frame_on = frame_arr[i];
		BaseTime frame_time(frame_on);
		if (i != frame_arr_count - 1) {
			next_frame_on = frame_arr[i + 1];
			BaseTime next_frame_time(next_frame_on);
			TimeOfTwoFrames = maxon::Abs(next_frame_on - frame_on);
			//PX
			Key = strCurvePX->GetKey(i);
			NextKey = strCurvePX->GetKey(i + 1);
			if (Key != nullptr && NextKey != nullptr) {
				ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
				strCurvePX->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurvePX->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				iferr(VMDCamera_data->XCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
			}

			Key = strCurvePY->GetKey(i);
			NextKey = strCurvePY->GetKey(i + 1);
			if (Key != nullptr && NextKey != nullptr) {
				ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
				strCurvePY->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurvePY->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				iferr(VMDCamera_data->YCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
			}

			Key = strCurvePZ->GetKey(i);
			NextKey = strCurvePZ->GetKey(i + 1);
			if (Key != nullptr && NextKey != nullptr) {
				ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
				strCurvePZ->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurvePZ->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				iferr(VMDCamera_data->ZCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
			}

			Key = strCurveAOV->GetKey(i);
			NextKey = strCurveAOV->GetKey(i + 1);
			if (Key != nullptr && NextKey != nullptr) {
				ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
				strCurveAOV->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurveAOV->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				iferr(VMDCamera_data->VCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
			}
			iferr(VMDCamera_data->DCurve.Insert(frame_on, new mmd::VMD_Curve()))return nullptr;
			switch (setting.use_rotation)
			{
			case 0:
				Key = strCurveRX->GetKey(i);
				NextKey = strCurveRX->GetKey(i + 1);
				if (Key != nullptr && NextKey != nullptr) {
					ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					strCurveRX->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
					strCurveRX->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
					iferr(VMDCamera_data->RCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
				}
				break;
			case 1:
				Key = strCurveRY->GetKey(i);
				NextKey = strCurveRY->GetKey(i + 1);
				if (Key != nullptr && NextKey != nullptr) {
					ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					strCurveRY->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
					strCurveRY->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
					iferr(VMDCamera_data->RCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
				}
				break;
			case 2:
				Key = strCurveRZ->GetKey(i);
				NextKey = strCurveRZ->GetKey(i + 1);
				if (Key != nullptr && NextKey != nullptr) {
					ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					strCurveRZ->GetTangents(i, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
					strCurveRZ->GetTangents(i + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
					iferr(VMDCamera_data->RCurve.Insert(frame_on, new mmd::VMD_Curve(maxon::Abs(KeyRightX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(KeyRightY / ValueOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftX * Fps / (Float)TimeOfTwoFrames * 127.0), maxon::Abs(NextKeyLeftY / ValueOfTwoFrames * 127.0))))return nullptr;
				}
				break;
			default:
				break;
			}
		}
	}
	CameraCurveDistance->AddKey(BaseTime(0, 30))->SetValue(CameraCurveDistance, setting.distance);
	EventAdd();
	if (!VMDCamera_data->UpdateAllCurve())return nullptr;
	doc->SetTime(BaseTime(1));
	doc->SetTime(BaseTime());
	return maxon::Result<BaseObject*>(VMDCamera);
}
mmd::VMDAnimation::~VMDAnimation()
{
	this->motion_frames.Reset();
	this->morph_frames.Reset();
	this->camera_frames.Reset();
	this->light_frames.Reset();
}
maxon::Result<void> mmd::VMDAnimation::LoadFromFile(BaseFile* const file)
{
	iferr_scope;
	Char VMDVersion[30]{ 0 };
	Char VMDModelName[20]{ 0 };
	mmd::VMD_Motion motion_frame;
	mmd::VMD_Morph morph_frame;
	mmd::VMD_Camera camera_frame;
	mmd::VMD_Light light_frame;
	if (!file->ReadBytes(VMDVersion, 30))return maxon::Error();
	if (!strncmp(VMDVersion, "Vocaloid Motion Data file", 26))
	{
		if (!file->ReadBytes(VMDModelName, 10))return maxon::Error();
		this->ModelName = EncodingConversion::JIStoUTF8(VMDModelName);
		if (!this->ModelName.LexComparePart("カメラ・照明"_s, 12, 0) == 0) {
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
	}
	else if (!strncmp(VMDVersion, "Vocaloid Motion Data 0002", 26))
	{
		if (!file->ReadBytes(VMDModelName, 20))return maxon::Error();
		this->ModelName = EncodingConversion::JIStoUTF8(VMDModelName);
		if (this->ModelName.LexComparePart("カメラ・照明"_s, 12, 0) == 0) {
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
		if (!file->ReadUInt32(&(this->MotionFrameNumber)))return maxon::Error();
		for (UInt32 i = 0; i < this->MotionFrameNumber; i++) {
			//111 bytes
			Char bone_name[15]{ 0 };
			if (!file->ReadBytes(bone_name, 15))return maxon::Error();
			if (!file->ReadUInt32(&(motion_frame.frame_no)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.position.x)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.position.y)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.position.z)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.rotation.x)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.rotation.y)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.rotation.z)))return maxon::Error();
			if (!file->ReadFloat32(&(motion_frame.rotation.w)))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.XCurve.ax)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.XCurve.bx)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.XCurve.ay)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.XCurve.by)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.YCurve.ax)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.YCurve.bx)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.YCurve.ay)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.YCurve.by)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.ZCurve.ax)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.ZCurve.bx)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.ZCurve.ay)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.ZCurve.by)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.RCurve.ax)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.RCurve.bx)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.RCurve.ay)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			if (!file->ReadUChar(&(motion_frame.RCurve.by)))return maxon::Error();
			if (!file->Seek(3))return maxon::Error();
			motion_frame.XCurve.bx = 127 - motion_frame.XCurve.bx;
			motion_frame.XCurve.by = 127 - motion_frame.XCurve.by;
			motion_frame.YCurve.bx = 127 - motion_frame.YCurve.bx;
			motion_frame.YCurve.by = 127 - motion_frame.YCurve.by;
			motion_frame.ZCurve.bx = 127 - motion_frame.ZCurve.bx;
			motion_frame.ZCurve.by = 127 - motion_frame.ZCurve.by;
			motion_frame.RCurve.bx = 127 - motion_frame.RCurve.bx;
			motion_frame.RCurve.by = 127 - motion_frame.RCurve.by;
			motion_frame.bone_name = EncodingConversion::JIStoUTF8(bone_name);
			this->motion_frames.Append(motion_frame)iferr_return;
		}

		if (!file->ReadUInt32(&(this->MorphFrameNumber)))return maxon::Error();
		for (UInt32 i = 0; i < this->MorphFrameNumber; i++) {
			//23 bytes
			Char morph_name[15]{ 0 };
			if (!file->ReadBytes(morph_name, 15))return maxon::Error();
			if (!file->ReadUInt32(&(morph_frame.frame_no)))return maxon::Error();
			if (!file->ReadFloat32(&(morph_frame.weight)))return maxon::Error();
			morph_frame.morph_name = EncodingConversion::JIStoUTF8(morph_name);
			this->morph_frames.Append(morph_frame)iferr_return;
		}
		if (!file->ReadUInt32(&(this->CameraFrameNumber)))return maxon::Error();
		for (UInt32 i = 0; i < this->CameraFrameNumber; i++) {
			//61 bytes
			if (!file->ReadUInt32(&(camera_frame.frame_no)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.distance)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.position.x)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.position.y)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.position.z)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.rotation.y)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.rotation.x)))return maxon::Error();
			if (!file->ReadFloat32(&(camera_frame.rotation.z)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.XCurve.ax)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.XCurve.bx)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.XCurve.ay)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.XCurve.by)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.YCurve.ax)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.YCurve.bx)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.YCurve.ay)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.YCurve.by)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.ZCurve.ax)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.ZCurve.bx)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.ZCurve.ay)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.ZCurve.by)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.RCurve.ax)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.RCurve.bx)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.RCurve.ay)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.RCurve.by)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.DCurve.ax)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.DCurve.bx)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.DCurve.ay)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.DCurve.by)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.VCurve.ax)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.VCurve.bx)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.VCurve.ay)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.VCurve.by)))return maxon::Error();
			camera_frame.XCurve.bx = 127 - camera_frame.XCurve.bx;
			camera_frame.XCurve.by = 127 - camera_frame.XCurve.by;
			camera_frame.YCurve.bx = 127 - camera_frame.YCurve.bx;
			camera_frame.YCurve.by = 127 - camera_frame.YCurve.by;
			camera_frame.ZCurve.bx = 127 - camera_frame.ZCurve.bx;
			camera_frame.ZCurve.by = 127 - camera_frame.ZCurve.by;
			camera_frame.RCurve.bx = 127 - camera_frame.RCurve.bx;
			camera_frame.RCurve.by = 127 - camera_frame.RCurve.by;
			camera_frame.DCurve.bx = 127 - camera_frame.DCurve.bx;
			camera_frame.DCurve.by = 127 - camera_frame.DCurve.by;
			camera_frame.VCurve.bx = 127 - camera_frame.VCurve.bx;
			camera_frame.VCurve.by = 127 - camera_frame.VCurve.by;
			if (!file->ReadUInt32(&(camera_frame.viewing_angle)))return maxon::Error();
			if (!file->ReadUChar(&(camera_frame.perspective)))return maxon::Error();
			this->camera_frames.Append(camera_frame)iferr_return;
		}

		if (!file->ReadUInt32(&(this->LightFrameNumber)))return maxon::Error();
		for (UInt32 i = 0; i < this->LightFrameNumber; i++) {
			//28 bytes
			if (!file->ReadBytes(&light_frame, 28))return maxon::Error();
			this->light_frames.Append(light_frame)iferr_return;
		}
	}
	else
	{
		GePrint("File corruption or unknown version"_s);
		MessageDialog("Import failed; File corruption or unknown version"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "File corruption or unknown version"_s);
	}
	return maxon::OK;
}
maxon::Result<void> mmd::VMDAnimation::WriteToFile(BaseFile* const file) {
	const Char VMDVersion[30] = "Vocaloid Motion Data 0002\0\0\0\0";
	if (!file->WriteBytes(VMDVersion, 30)) {
		MessageDialog("Write VMDVersion to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	Char* VMDModelName = EncodingConversion::UTF8toJIS(this->ModelName);
	if (!file->WriteBytes(VMDModelName, 20)) {
		GePrint("Write file error"_s);
		MessageDialog("Write ModelName to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	if (!file->WriteUInt32(this->MotionFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write MotionFrameNumber to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->MotionFrameNumber; i++) {
		if (!file->WriteBytes(&((this->motion_frames)[i]), 111)) {
			GePrint("Write file error"_s);
			MessageDialog("Write motions to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	if (!file->WriteUInt32(this->MorphFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->MorphFrameNumber; i++) {
		if (!file->WriteBytes(&((this->morph_frames)[i]), 23)) {
			GePrint("Write file error"_s);
			MessageDialog("Write MorphFrameNumber to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	if (!file->WriteUInt32(this->CameraFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write CameraFrameNumber to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->CameraFrameNumber; i++) {
		mmd::VMD_Camera camera_frame = (this->camera_frames)[i];
		camera_frame.XCurve.bx = 127 - camera_frame.XCurve.bx;
		camera_frame.XCurve.by = 127 - camera_frame.XCurve.by;
		camera_frame.YCurve.bx = 127 - camera_frame.YCurve.bx;
		camera_frame.YCurve.by = 127 - camera_frame.YCurve.by;
		camera_frame.ZCurve.bx = 127 - camera_frame.ZCurve.bx;
		camera_frame.ZCurve.by = 127 - camera_frame.ZCurve.by;
		camera_frame.RCurve.bx = 127 - camera_frame.RCurve.bx;
		camera_frame.RCurve.by = 127 - camera_frame.RCurve.by;
		camera_frame.DCurve.bx = 127 - camera_frame.DCurve.bx;
		camera_frame.DCurve.by = 127 - camera_frame.DCurve.by;
		camera_frame.VCurve.bx = 127 - camera_frame.VCurve.bx;
		camera_frame.VCurve.by = 127 - camera_frame.VCurve.by;
		if (!file->WriteUInt32(camera_frame.frame_no))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.distance))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.position.x))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.position.y))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.position.z))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.rotation.y))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.rotation.x))return maxon::Error();
		if (!file->WriteFloat32(camera_frame.rotation.z))return maxon::Error();
		if (!file->WriteUChar(camera_frame.XCurve.ax))return maxon::Error();
		if (!file->WriteUChar(camera_frame.XCurve.bx))return maxon::Error();
		if (!file->WriteUChar(camera_frame.XCurve.ay))return maxon::Error();
		if (!file->WriteUChar(camera_frame.XCurve.by))return maxon::Error();
		if (!file->WriteUChar(camera_frame.YCurve.ax))return maxon::Error();
		if (!file->WriteUChar(camera_frame.YCurve.bx))return maxon::Error();
		if (!file->WriteUChar(camera_frame.YCurve.ay))return maxon::Error();
		if (!file->WriteUChar(camera_frame.YCurve.by))return maxon::Error();
		if (!file->WriteUChar(camera_frame.ZCurve.ax))return maxon::Error();
		if (!file->WriteUChar(camera_frame.ZCurve.bx))return maxon::Error();
		if (!file->WriteUChar(camera_frame.ZCurve.ay))return maxon::Error();
		if (!file->WriteUChar(camera_frame.ZCurve.by))return maxon::Error();
		if (!file->WriteUChar(camera_frame.RCurve.ax))return maxon::Error();
		if (!file->WriteUChar(camera_frame.RCurve.bx))return maxon::Error();
		if (!file->WriteUChar(camera_frame.RCurve.ay))return maxon::Error();
		if (!file->WriteUChar(camera_frame.RCurve.by))return maxon::Error();
		if (!file->WriteUChar(camera_frame.DCurve.ax))return maxon::Error();
		if (!file->WriteUChar(camera_frame.DCurve.bx))return maxon::Error();
		if (!file->WriteUChar(camera_frame.DCurve.ay))return maxon::Error();
		if (!file->WriteUChar(camera_frame.DCurve.by))return maxon::Error();
		if (!file->WriteUChar(camera_frame.VCurve.ax))return maxon::Error();
		if (!file->WriteUChar(camera_frame.VCurve.bx))return maxon::Error();
		if (!file->WriteUChar(camera_frame.VCurve.ay))return maxon::Error();
		if (!file->WriteUChar(camera_frame.VCurve.by))return maxon::Error();
		if (!file->WriteUInt32(camera_frame.viewing_angle))return maxon::Error();
		if (!file->WriteUChar(camera_frame.perspective))return maxon::Error();
	}
	if (!file->WriteUInt32(this->LightFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->LightFrameNumber; i++) {
		if (!file->WriteBytes(&((this->light_frames)[i]), 28)) {
			GePrint("Write file error"_s);
			MessageDialog("Write to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	return maxon::OK;
}
maxon::Result<void> mmd::VMDAnimation::FromFileImportCamera(VMD_Camera_import_settings setting) {
	iferr_scope;
	Filename fn;
	AutoAlloc <BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE))) {
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s)))) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	StatusSetSpin();
	std::unique_ptr<mmd::VMDAnimation> mmd_animation(new mmd::VMDAnimation);
	if (mmd_animation == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	iferr(mmd_animation->LoadFromFile(file)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
	}
	if (mmd_animation->IsCamera) {
		doc->StartUndo();

		BaseObject* VMDCamera = BaseObject::Alloc(ID_VMD_CAM_OBJ);
		if (VMDCamera == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		VMDCamera->SetName(fn.GetFileString());
		doc->InsertObject(VMDCamera, nullptr, nullptr);
		mmd::VMD_Cam_Obj* VMDCamera_data = VMDCamera->GetNodeData<VMD_Cam_Obj>();
		VMDCamera_data->CameraInit();
		BaseObject* VMDCameraDistance = VMDCamera_data->GetCamera();

		CTrack* CameraTrackPX = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		CTrack* CameraTrackPY = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		CTrack* CameraTrackPZ = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		CTrack* CameraTrackRX = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		CTrack* CameraTrackRY = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		CTrack* CameraTrackRZ = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		CTrack* CameraTrackDistance = CTrack::Alloc(VMDCameraDistance, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		CTrack* CameraTrackAOV = CTrack::Alloc(VMDCameraDistance, DescID(CAMERAOBJECT_APERTURE));
		if (CameraTrackPX == nullptr || CameraTrackPY == nullptr || CameraTrackPZ == nullptr || CameraTrackRX == nullptr || CameraTrackRY == nullptr || CameraTrackRZ == nullptr || CameraTrackDistance == nullptr || CameraTrackAOV == nullptr)//确保生成成功 
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		CCurve* CameraCurvePX = CameraTrackPX->GetCurve();
		CCurve* CameraCurvePY = CameraTrackPY->GetCurve();
		CCurve* CameraCurvePZ = CameraTrackPZ->GetCurve();
		CCurve* CameraCurveRX = CameraTrackRX->GetCurve();
		CCurve* CameraCurveRY = CameraTrackRY->GetCurve();
		CCurve* CameraCurveRZ = CameraTrackRZ->GetCurve();
		CCurve* CameraCurveDistance = CameraTrackDistance->GetCurve();
		CCurve* CameraCurveAOV = CameraTrackAOV->GetCurve();
		if (CameraCurvePX == nullptr || CameraCurvePY == nullptr || CameraCurvePZ == nullptr || CameraCurveRX == nullptr || CameraCurveRY == nullptr || CameraCurveRZ == nullptr || CameraCurveDistance == nullptr || CameraCurveAOV == nullptr) //确保获取成功
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return maxon::NullptrError(MAXON_SOURCE_LOCATION);
		}
		VMDCamera->InsertTrackSorted(CameraTrackPX);
		VMDCamera->InsertTrackSorted(CameraTrackPY);
		VMDCamera->InsertTrackSorted(CameraTrackPZ);
		VMDCamera->InsertTrackSorted(CameraTrackRX);
		VMDCamera->InsertTrackSorted(CameraTrackRY);
		VMDCamera->InsertTrackSorted(CameraTrackRZ);
		VMDCameraDistance->InsertTrackSorted(CameraTrackDistance);
		VMDCameraDistance->InsertTrackSorted(CameraTrackAOV);

		Int32 Max30 = (doc->GetMaxTime()).GetFrame(30);
		Max30 = maxon::Max(Max30, (Int32)(mmd_animation->camera_frames.End() - 1).GetPtr()->frame_no);
		BaseTime KeyTime = BaseTime(0, 30);
		Int32 KeyFrame;
		mmd::VMD_Camera CameraFrame, NextCameraFrame;
		const UInt32 camera_frame_number = mmd_animation->CameraFrameNumber;
		for (UInt32 camera_frame_index = 0; camera_frame_index < camera_frame_number; camera_frame_index++)
		{
			StatusSetText("Import camera..."_s);
			StatusSetBar(camera_frame_index * 100 / camera_frame_number);
			if (camera_frame_index == 0 && camera_frame_number != 1)
			{
				CameraFrame = mmd_animation->camera_frames[camera_frame_index];
				NextCameraFrame = mmd_animation->camera_frames[camera_frame_index + 1];
			}
			else if (camera_frame_index == mmd_animation->CameraFrameNumber - 1)
			{
				CameraFrame = NextCameraFrame;
			}
			else
			{
				CameraFrame = NextCameraFrame;
				NextCameraFrame = mmd_animation->camera_frames[camera_frame_index + 1];
			}
			KeyFrame = CameraFrame.frame_no + setting.TimeOffset + 1.0;
			KeyTime = BaseTime(KeyFrame, 30);

			CKey* CameraKeyPX = CKey::Alloc();//PX
			CameraKeyPX->SetTime(CameraCurvePX, KeyTime);
			CameraKeyPX->SetValue(CameraCurvePX, CameraFrame.position.x * setting.PositionMultiple);
			CameraKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurvePX->InsertKey(CameraKeyPX);
			VMDCamera_data->SetCurve(VMD_CAM_OBJ_XCURVE, KeyFrame, new mmd::VMD_Curve(CameraFrame.XCurve));

			CKey* CameraKeyPY = CKey::Alloc();//PY
			CameraKeyPY->SetTime(CameraCurvePY, KeyTime);
			CameraKeyPY->SetValue(CameraCurvePY, CameraFrame.position.y * setting.PositionMultiple);
			CameraKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurvePY->InsertKey(CameraKeyPY);
			VMDCamera_data->SetCurve(VMD_CAM_OBJ_YCURVE, KeyFrame, new mmd::VMD_Curve(CameraFrame.YCurve));

			CKey* CameraKeyPZ = CKey::Alloc();//PZ
			CameraKeyPZ->SetTime(CameraCurvePZ, KeyTime);
			CameraKeyPZ->SetValue(CameraCurvePZ, CameraFrame.position.z * setting.PositionMultiple);
			CameraKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurvePZ->InsertKey(CameraKeyPZ);
			VMDCamera_data->SetCurve(VMD_CAM_OBJ_ZCURVE, KeyFrame, new mmd::VMD_Curve(CameraFrame.ZCurve));

			CKey* CameraKeyRX = CKey::Alloc();//RX
			CameraKeyRX->SetTime(CameraCurveRX, KeyTime);
			CameraKeyRX->SetValue(CameraCurveRX, CameraFrame.rotation.x);
			CameraKeyRX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveRX->InsertKey(CameraKeyRX);

			CKey* CameraKeyRY = CKey::Alloc();//RY
			CameraKeyRY->SetTime(CameraCurveRY, KeyTime);
			CameraKeyRY->SetValue(CameraCurveRY, CameraFrame.rotation.y);
			CameraKeyRY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveRY->InsertKey(CameraKeyRY);

			CKey* CameraKeyRZ = CKey::Alloc();//RZ
			CameraKeyRZ->SetTime(CameraCurveRZ, KeyTime);
			CameraKeyRZ->SetValue(CameraCurveRZ, CameraFrame.rotation.z);
			CameraKeyRZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveRZ->InsertKey(CameraKeyRZ);
			VMDCamera_data->SetCurve(VMD_CAM_OBJ_RCURVE, KeyFrame, new mmd::VMD_Curve(CameraFrame.RCurve));

			CKey* CameraKeyDistance = CKey::Alloc();;
			CameraKeyDistance->SetTime(CameraCurveDistance, KeyTime);
			CameraKeyDistance->SetValue(CameraCurveDistance, CameraFrame.distance * setting.PositionMultiple);
			CameraKeyDistance->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveDistance->InsertKey(CameraKeyDistance);
			VMDCamera_data->SetCurve(VMD_CAM_OBJ_DCURVE, KeyFrame, new mmd::VMD_Curve(CameraFrame.DCurve));

			CKey* CameraKeyAOV = CKey::Alloc();
			CameraKeyAOV->SetTime(CameraCurveAOV, KeyTime);
			CameraKeyAOV->SetValue(CameraCurveAOV, CameraFrame.viewing_angle);
			CameraKeyAOV->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveAOV->InsertKey(CameraKeyAOV);
			VMDCamera_data->SetCurve(VMD_CAM_OBJ_VCURVE, KeyFrame, new mmd::VMD_Curve(CameraFrame.VCurve));
		}
		VMDCamera_data->UpdateAllCurve();
		timing.Stop();
		StatusClear();
		doc->SetMaxTime(BaseTime(Max30 + 1, 30));
		doc->SetLoopMaxTime(BaseTime(Max30 + 1, 30));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_OK, maxon::String::UIntToString(mmd_animation->CameraFrameNumber), String::FloatToString(timing.GetMilliseconds())));
		EventAdd(EVENT::NONE);
		doc->SetTime(BaseTime(1, 30));
		doc->SetTime(BaseTime(0, 30));
		doc->EndUndo();
		return maxon::OK;
	}
	else {
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR));
	}
}
maxon::Result<void> mmd::VMDAnimation::FromDocumentExportCamera(VMD_Camera_export_settings setting) {
	iferr_scope;
	Filename fn;
	AutoAlloc<BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	setting.PositionMultiple /= 1;
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::SAVE, GeLoadString(IDS_MES_SAVEFILE)))
	{
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s)))) {
		fn.SetSuffix("vmd"_s);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::WRITE, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	BaseObject* CameraObj = nullptr;
	if (SelectObject->GetType() == Ocamera) //选择对象为普通摄像机则转化
	{
		auto res = VMD_Cam_Obj::ConversionCamera(VMD_Conversion_Camera_settings{ 0., setting.use_rotation, SelectObject });
		iferr(res.GetError())return maxon::Error();
		CameraObj = res.GetValue();
	}
	else if (SelectObject->GetType() == ID_VMD_CAM_OBJ) //选择对象为vmd摄像机则直接使用
	{
		CameraObj = SelectObject;
	}
	else //都不是则返回错误
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	//获取内置数据
	mmd::VMD_Cam_Obj* VMDCamera_data = CameraObj->GetNodeData<VMD_Cam_Obj>();
	if (VMDCamera_data == nullptr) {
		return maxon::Error();
	}
	BaseObject* VMDCameraDistance = VMDCamera_data->GetCamera();
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	CTrack* CameraTrackPX = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (CameraTrackPX == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PX"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PX"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackPY = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (CameraTrackPY == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PY"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PY"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackPZ = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
	if (CameraTrackPZ == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PZ"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PZ"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackRX = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (CameraTrackRX == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RX"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RX"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackRY = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (CameraTrackRY == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RY"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RY"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackRZ = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (CameraTrackRZ == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RZ"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RZ"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackFrame_on = CameraObj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));

	if (CameraTrackFrame_on == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Frame_on"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Frame_on"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackDistance = VMDCameraDistance->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (CameraTrackDistance == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack* CameraTrackAOV = VMDCameraDistance->FindCTrack(DescID(DescLevel(CAMERAOBJECT_APERTURE, DTYPE_REAL, 0)));
	if (CameraTrackAOV == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "AOV"_s));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CCurve* CameraCurvePX = CameraTrackPX->GetCurve();
	CCurve* CameraCurvePY = CameraTrackPY->GetCurve();
	CCurve* CameraCurvePZ = CameraTrackPZ->GetCurve();
	CCurve* CameraCurveRX = CameraTrackRX->GetCurve();
	CCurve* CameraCurveRY = CameraTrackRY->GetCurve();
	CCurve* CameraCurveRZ = CameraTrackRZ->GetCurve();
	CCurve* CameraCurveFrame_on = CameraTrackFrame_on->GetCurve();
	CCurve* CameraCurveDistance = CameraTrackDistance->GetCurve();
	CCurve* CameraCurveAOV = CameraTrackAOV->GetCurve();

	const Int32 FrameCount = CameraCurveFrame_on->GetKeyCount();

	std::unique_ptr<mmd::VMDAnimation> mmd_animation(new mmd::VMDAnimation);
	if (mmd_animation == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	for (Int32 frame_index = 0; frame_index < FrameCount; frame_index++)
	{
		StatusSetSpin();
		mmd::VMD_Camera CameraFrame;
		Int32 Frame_on = CameraCurveFrame_on->GetKey(frame_index)->GetValue();
		CameraFrame.frame_no = Frame_on + setting.TimeOffset;
		CameraFrame.position = vec3(CameraCurvePX->GetKey(frame_index)->GetValue() * setting.PositionMultiple, CameraCurvePY->GetKey(frame_index)->GetValue() * setting.PositionMultiple, CameraCurvePZ->GetKey(frame_index)->GetValue() * setting.PositionMultiple);
		CameraFrame.rotation = vec3(CameraCurveRX->GetKey(frame_index)->GetValue(), CameraCurveRY->GetKey(frame_index)->GetValue(), CameraCurveRZ->GetKey(frame_index)->GetValue());
		CameraFrame.distance = CameraCurveDistance->GetKey(frame_index)->GetValue() * setting.PositionMultiple;
		CameraFrame.viewing_angle = CameraCurveAOV->GetKey(frame_index)->GetValue();
		CameraFrame.perspective = 0;
		VMDCamera_data->GetCurve(VMD_CAM_OBJ_XCURVE, Frame_on, &CameraFrame.XCurve);
		VMDCamera_data->GetCurve(VMD_CAM_OBJ_YCURVE, Frame_on, &CameraFrame.YCurve);
		VMDCamera_data->GetCurve(VMD_CAM_OBJ_ZCURVE, Frame_on, &CameraFrame.ZCurve);
		VMDCamera_data->GetCurve(VMD_CAM_OBJ_RCURVE, Frame_on, &CameraFrame.RCurve);
		VMDCamera_data->GetCurve(VMD_CAM_OBJ_DCURVE, Frame_on, &CameraFrame.DCurve);
		VMDCamera_data->GetCurve(VMD_CAM_OBJ_VCURVE, Frame_on, &CameraFrame.VCurve);
		iferr(mmd_animation->camera_frames.Append(CameraFrame)) {
			GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
	}

	mmd_animation->ModelName = "カメラ・照明"_s;
	mmd_animation->IsCamera = true;
	mmd_animation->CameraFrameNumber = FrameCount;
	iferr(mmd_animation->WriteToFile(file))
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
	}
	timing.Stop();
	StatusClear();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_OK, maxon::String::UIntToString(mmd_animation->CameraFrameNumber), String::FloatToString(timing.GetMilliseconds())));
	return maxon::OK;
}
maxon::Result<void> mmd::VMDAnimation::FromFileImportMotions(VMD_Motions_import_settings setting) {
	iferr_scope;
	Filename fn;
	AutoAlloc<BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE))) {
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s)))) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	std::unique_ptr<mmd::VMDAnimation> mmd_animation(new mmd::VMDAnimation);
	if (mmd_animation == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	iferr(mmd_animation->LoadFromFile(file)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
	}
	if (mmd_animation->IsCamera == 1) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
	}

	maxon::HashMap<String, maxon::BaseList<bone_obj_tag>> bone_name_map;
	maxon::HashMap<String, maxon::BaseList<morph_id_tag>> morph_name_map;

	maxon::Queue<BaseObject*> nodes;
	nodes.Push(SelectObject)iferr_return;
	GeData data;

	while (!nodes.IsEmpty())
	{
		BaseObject* node = *(nodes.Pop());
		while (node != nullptr)
		{
			if (node->GetType() == Ojoint)
			{
				if (setting.ByTag) {
					BaseTag* node_tag = node->GetTag(ID_PMX_BONE_TAG);
					if (node_tag != nullptr) {
						PMX_Bone_Tag* pmx_bone_tag_data = node_tag->GetNodeData<PMX_Bone_Tag>();
						for(bone_morph_data& i : pmx_bone_tag_data->bone_morph_data_arr) {
							auto morph_arr_ptr = morph_name_map.Find(i.name);
							if (morph_arr_ptr == nullptr) {
								maxon::BaseList<morph_id_tag>morph_arr;
								morph_arr.Append(morph_id_tag{ i.strength_id,node_tag })iferr_return;
								morph_name_map.Insert(i.name, morph_arr)iferr_return;
							}
							else {
								morph_arr_ptr->GetValue().Append(morph_id_tag{ i.strength_id,node_tag })iferr_return;
							}
						}
						node_tag->GetParameter(DescID(BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
						String bone_name = data.GetString();
						auto bone_arr_ptr = bone_name_map.Find(bone_name);
						if (bone_arr_ptr == nullptr) {
							maxon::BaseList<bone_obj_tag>bone_arr;
							bone_arr.Append(bone_obj_tag{ node,node_tag })iferr_return;
							bone_name_map.Insert(bone_name, bone_arr)iferr_return;
						}
						else {
							bone_arr_ptr->GetValue().Append(bone_obj_tag{ node,node_tag })iferr_return;
						}

					}
					else {
						String bone_name = node->GetName();
						auto bone_arr_ptr = bone_name_map.Find(bone_name);
						if (bone_arr_ptr == nullptr) {
							maxon::BaseList<bone_obj_tag>bone_arr;
							bone_arr.Append(bone_obj_tag{ node,nullptr })iferr_return;
							bone_name_map.Insert(bone_name, bone_arr)iferr_return;
						}
						else {
							bone_arr_ptr->GetValue().Append(bone_obj_tag{ node,nullptr })iferr_return;
						}
					}
				}
				else {
					String bone_name = node->GetName();
					auto bone_arr_ptr = bone_name_map.Find(bone_name);
					if (bone_arr_ptr == nullptr) {
						maxon::BaseList<bone_obj_tag>bone_arr;
						bone_arr.Append(bone_obj_tag{ node,nullptr })iferr_return;
						bone_name_map.Insert(bone_name, bone_arr)iferr_return;
					}
					else {
						bone_arr_ptr->GetValue().Append(bone_obj_tag{ node,nullptr })iferr_return;
					}
				}
			}
			BaseTag* const tag = node->GetTag(Tposemorph);
			if (tag != nullptr && tag->IsInstanceOf(Tposemorph))
			{
				CAPoseMorphTag* const pose_morph_tag = static_cast<CAPoseMorphTag*>(tag);
				const Int32 MorphCount = pose_morph_tag->GetMorphCount();
				for (Int32 i = 0; i < MorphCount; i++)
				{
					String morph_name = pose_morph_tag->GetMorph(i)->GetName();
					auto morph_arr_ptr = morph_name_map.Find(morph_name);
					if (morph_arr_ptr == nullptr) {
						maxon::BaseList<morph_id_tag>morph_arr;
						morph_arr.Append(morph_id_tag{ pose_morph_tag->GetMorphID(i),tag })iferr_return;
						morph_name_map.Insert(morph_name, morph_arr)iferr_return;
					}
					else {
						morph_arr_ptr->GetValue().Append(morph_id_tag{ pose_morph_tag->GetMorphID(i),tag })iferr_return;
					}
				}
			}
			nodes.Push(node->GetDown())iferr_return;
			if (node != SelectObject) {
				node = node->GetNext();
			}
			else {
				break;
			}
		}
	}
	nodes.Reset();

	maxon::HashMap<String, maxon::BaseList<VMD_Motion>*> MotionFrameList_map;
	maxon::HashMap<String, maxon::BaseList<VMD_Morph>*> MorphFrameList_map;
	Int32 MotionFrameNumber = mmd_animation->MotionFrameNumber;
	for (Int32 motion_frame_index = 0; motion_frame_index < MotionFrameNumber; motion_frame_index++)
	{
		String bone_name = mmd_animation->motion_frames[motion_frame_index].bone_name;
		auto MotionFrame_ptr = MotionFrameList_map.Find(bone_name);
		if (MotionFrame_ptr == nullptr)
		{
			maxon::BaseList<VMD_Motion>* MotionFrame = new maxon::BaseList<VMD_Motion>;
			MotionFrame->Append(mmd_animation->motion_frames[motion_frame_index])iferr_return;
			MotionFrameList_map.Insert(bone_name, MotionFrame)iferr_return;
		}
		else
		{
			MotionFrame_ptr->GetValue()->Append(mmd_animation->motion_frames[motion_frame_index])iferr_return;
		}
	}
	Int32 MorphFrameNumber = mmd_animation->MorphFrameNumber;
	for (Int32 morph_frame_index = 0; morph_frame_index < MorphFrameNumber; morph_frame_index++)
	{
		String morph_name = mmd_animation->morph_frames[morph_frame_index].morph_name;
		auto MorphFrame_ptr = MorphFrameList_map.Find(morph_name);
		if (MorphFrame_ptr == nullptr)
		{
			maxon::BaseList<VMD_Morph>* MorphFrame = new maxon::BaseList<VMD_Morph>;
			MorphFrame->Append(mmd_animation->morph_frames[morph_frame_index])iferr_return;
			MorphFrameList_map.Insert(morph_name, MorphFrame)iferr_return;
		}
		else
		{
			MorphFrame_ptr->GetValue()->Append(mmd_animation->morph_frames[morph_frame_index])iferr_return;
		}
	}
	Int32 MaxTime;
	if (MorphFrameNumber != 0 && MotionFrameNumber != 0) {
		MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30), maxon::Max((Int32)mmd_animation->motion_frames[MotionFrameNumber - 1].frame_no, (Int32)mmd_animation->morph_frames[MorphFrameNumber - 1].frame_no));
	}
	else if (MorphFrameNumber != 0) {
		MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30), (Int32)mmd_animation->morph_frames[MorphFrameNumber - 1].frame_no);
	}
	else if (MotionFrameNumber != 0) {
		MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30), (Int32)mmd_animation->motion_frames[MotionFrameNumber - 1].frame_no);
	}
	else {
		MaxTime = doc->GetMaxTime().GetFrame(30);
	}


	mmd::VMD_Motion MotionFrame;
	mmd::VMD_Motion NextMotionFrame;
	BaseTime MotionKeyTime = BaseTime(0, 30);
	Float TimeOfTwoMotionFrames = 0.0;
	Float ValueOfTwoMotionFrames = 0.0;
	BaseTime MotionKeyTimeLeft[6] = { BaseTime(0.0, 30) };
	Float MotionKeyValueLeft[6] = { 0.0 };
	maxon::BaseArray<String> not_find_bone_S;
	Int bone_cnt = 0;
	Int32 motion_frame_bone_number = MotionFrameList_map.GetCount();
	String motion_frame_bone_number_S = String::IntToString(motion_frame_bone_number);
	for (String motion_bone_name : MotionFrameList_map.GetKeys())
	{
		maxon::BaseList<mmd::VMD_Motion>* MotionFrameList = MotionFrameList_map.Find(motion_bone_name)->GetValue();
		auto bone_ptr = bone_name_map.Find(motion_bone_name);

		if (bone_ptr != nullptr)
		{
			for (bone_obj_tag bone : bone_ptr->GetValue()) {
				if (bone.tag == nullptr) {
					if (bone.obj != nullptr)
					{
						if (setting.QuaternionRotationSW && bone.obj->IsQuaternionRotationMode() == false) {
							bone.obj->SetQuaternionRotationMode(true, false);
						}
						CTrack* BoneTrackPX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
						CTrack::Free(BoneTrackPX);
						BoneTrackPX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
						if (BoneTrackPX == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
						bone.obj->InsertTrackSorted(BoneTrackPX);
						CTrack* BoneTrackPY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
						CTrack::Free(BoneTrackPY);
						BoneTrackPY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
						if (BoneTrackPY == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
						bone.obj->InsertTrackSorted(BoneTrackPY);
						CTrack* BoneTrackPZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
						CTrack::Free(BoneTrackPZ);
						BoneTrackPZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
						if (BoneTrackPZ == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
						bone.obj->InsertTrackSorted(BoneTrackPZ);
						CTrack* BoneTrackRX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
						CTrack::Free(BoneTrackRX);
						BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
						if (BoneTrackRX == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
						bone.obj->InsertTrackSorted(BoneTrackRX);
						CTrack* BoneTrackRY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
						CTrack::Free(BoneTrackRY);
						BoneTrackRY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
						if (BoneTrackRY == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
						bone.obj->InsertTrackSorted(BoneTrackRY);
						CTrack* BoneTrackRZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
						CTrack::Free(BoneTrackRZ);
						BoneTrackRZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
						if (BoneTrackRZ == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
						bone.obj->InsertTrackSorted(BoneTrackRZ);

						CCurve* BoneCurvePX = BoneTrackPX->GetCurve();
						CCurve* BoneCurvePY = BoneTrackPY->GetCurve();
						CCurve* BoneCurvePZ = BoneTrackPZ->GetCurve();
						CCurve* BoneCurveRX = BoneTrackRX->GetCurve();
						CCurve* BoneCurveRY = BoneTrackRY->GetCurve();
						CCurve* BoneCurveRZ = BoneTrackRZ->GetCurve();
						Int32 motion_frame_number = MotionFrameList->GetCount();
						for (Int32 motion_index = 0; motion_index < motion_frame_number; motion_index++)
						{
							StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
							StatusSetBar(motion_index * 100 / motion_frame_number);
							if (motion_index == 0 && motion_frame_number != 1)
							{
								MotionFrame = MotionFrameList->operator[](motion_index);
								NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
							}
							else if (motion_index == motion_frame_number - 1)
							{
								MotionFrame = NextMotionFrame;
							}
							else
							{
								MotionFrame = NextMotionFrame;
								NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
							}
							TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
							MotionKeyTime = BaseTime(MotionFrame.frame_no + setting.TimeOffset, 30);

							Vector32 rotation;
							rotation.x = -maxon::ATan2(2 * MotionFrame.rotation.y * MotionFrame.rotation.w + 2 * MotionFrame.rotation.x * MotionFrame.rotation.z, 1 - 2 * (MotionFrame.rotation.x * MotionFrame.rotation.x + MotionFrame.rotation.y * MotionFrame.rotation.y));
							rotation.y = -maxon::ASin(2 * (MotionFrame.rotation.x * MotionFrame.rotation.w - MotionFrame.rotation.y * MotionFrame.rotation.z));
							rotation.z = -maxon::ATan2(2 * MotionFrame.rotation.z * MotionFrame.rotation.w + 2 * MotionFrame.rotation.x * MotionFrame.rotation.y, 1 - 2 * (MotionFrame.rotation.x * MotionFrame.rotation.x + MotionFrame.rotation.z * MotionFrame.rotation.z));
							Vector32 next_rotation;
							next_rotation.x = -maxon::ATan2(2 * NextMotionFrame.rotation.y * NextMotionFrame.rotation.w + 2 * NextMotionFrame.rotation.x * NextMotionFrame.rotation.z, 1 - 2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.x + NextMotionFrame.rotation.y * NextMotionFrame.rotation.y));
							next_rotation.y = -maxon::ASin(2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.w - NextMotionFrame.rotation.y * NextMotionFrame.rotation.z));
							next_rotation.z = -maxon::ATan2(2 * NextMotionFrame.rotation.z * NextMotionFrame.rotation.w + 2 * NextMotionFrame.rotation.x * NextMotionFrame.rotation.y, 1 - 2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.x + NextMotionFrame.rotation.z * NextMotionFrame.rotation.z));

							CKey* MotionKeyPX = CKey::Alloc();//PX
							MotionKeyPX->SetTime(BoneCurvePX, MotionKeyTime);
							MotionKeyPX->SetValue(BoneCurvePX, MotionFrame.position.x * setting.PositionMultiple);
							MotionKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							MotionKeyPX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
							ValueOfTwoMotionFrames = NextMotionFrame.position.x * setting.PositionMultiple - MotionFrame.position.x * setting.PositionMultiple;
							if (MotionFrame.XCurve.ax == 127 - MotionFrame.XCurve.bx && MotionFrame.XCurve.ay == 127 - MotionFrame.XCurve.by) {
								MotionKeyPX->SetInterpolation(BoneCurvePX, CINTERPOLATION::LINEAR);
							}
							else {
								MotionKeyPX->SetTimeLeft(BoneCurvePX, MotionKeyTimeLeft[0]);
								MotionKeyPX->SetValueLeft(BoneCurvePX, MotionKeyValueLeft[0]);
								MotionKeyPX->SetTimeRight(BoneCurvePX, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.ax / 127.0), 30));
								MotionKeyPX->SetValueRight(BoneCurvePX, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.ay / 127.0));
							}
							MotionKeyTimeLeft[0] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.bx / 127.0), 30);
							MotionKeyValueLeft[0] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.by / 127.0);
							BoneCurvePX->InsertKey(MotionKeyPX);

							CKey* MotionKeyPY = CKey::Alloc();//PY
							MotionKeyPY->SetTime(BoneCurvePY, MotionKeyTime);
							MotionKeyPY->SetValue(BoneCurvePY, MotionFrame.position.y * setting.PositionMultiple);
							MotionKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							MotionKeyPY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
							ValueOfTwoMotionFrames = NextMotionFrame.position.y * setting.PositionMultiple - MotionFrame.position.y * setting.PositionMultiple;
							if (MotionFrame.YCurve.ax == 127 - MotionFrame.YCurve.bx && MotionFrame.YCurve.ay == 127 - MotionFrame.YCurve.by) {
								MotionKeyPY->SetInterpolation(BoneCurvePY, CINTERPOLATION::LINEAR);
							}
							else {
								MotionKeyPY->SetTimeLeft(BoneCurvePY, MotionKeyTimeLeft[1]);
								MotionKeyPY->SetValueLeft(BoneCurvePY, MotionKeyValueLeft[1]);
								MotionKeyPY->SetTimeRight(BoneCurvePY, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.ax / 127.0), 30));
								MotionKeyPY->SetValueRight(BoneCurvePY, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.ay / 127.0));
							}
							MotionKeyTimeLeft[1] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.bx / 127.0), 30);
							MotionKeyValueLeft[1] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.by / 127.0);
							BoneCurvePY->InsertKey(MotionKeyPY);

							CKey* MotionKeyPZ = CKey::Alloc();//PZ
							MotionKeyPZ->SetTime(BoneCurvePZ, MotionKeyTime);
							MotionKeyPZ->SetValue(BoneCurvePZ, MotionFrame.position.z * setting.PositionMultiple);
							MotionKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							MotionKeyPZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
							ValueOfTwoMotionFrames = NextMotionFrame.position.z * setting.PositionMultiple - MotionFrame.position.z * setting.PositionMultiple;
							if (MotionFrame.ZCurve.ax == 127 - MotionFrame.ZCurve.bx && MotionFrame.ZCurve.ay == 127 - MotionFrame.ZCurve.by) {
								MotionKeyPZ->SetInterpolation(BoneCurvePZ, CINTERPOLATION::LINEAR);
							}
							else {
								MotionKeyPZ->SetTimeLeft(BoneCurvePZ, MotionKeyTimeLeft[2]);
								MotionKeyPZ->SetValueLeft(BoneCurvePZ, MotionKeyValueLeft[2]);
								MotionKeyPZ->SetTimeRight(BoneCurvePZ, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.ax / 127.0), 30));
								MotionKeyPZ->SetValueRight(BoneCurvePZ, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.ay / 127.0));
							}
							MotionKeyTimeLeft[2] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.bx / 127.0), 30);
							MotionKeyValueLeft[2] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.by / 127.0);
							BoneCurvePZ->InsertKey(MotionKeyPZ);

							CKey* MotionKeyRX = CKey::Alloc();//RX
							MotionKeyRX->SetTime(BoneCurveRX, MotionKeyTime);
							MotionKeyRX->SetValue(BoneCurveRX, rotation.x);
							if (!setting.QuaternionRotationSW) {
								MotionKeyRX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKeyRX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = next_rotation.x - rotation.x;
								if (MotionFrame.RCurve.ax == 127 - MotionFrame.RCurve.bx && MotionFrame.RCurve.ay == 127 - MotionFrame.RCurve.by) {
									MotionKeyRX->SetInterpolation(BoneCurveRX, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKeyRX->SetTimeLeft(BoneCurveRX, MotionKeyTimeLeft[3]);
									MotionKeyRX->SetValueLeft(BoneCurveRX, MotionKeyValueLeft[3]);
									MotionKeyRX->SetTimeRight(BoneCurveRX, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ax / 127.0), 30));
									MotionKeyRX->SetValueRight(BoneCurveRX, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ay / 127.0));
								}
								MotionKeyTimeLeft[3] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.bx / 127.0), 30);
								MotionKeyValueLeft[3] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.by / 127.0);
							}
							BoneCurveRX->InsertKey(MotionKeyRX);

							CKey* MotionKeyRY = CKey::Alloc();//RY
							MotionKeyRY->SetTime(BoneCurveRY, MotionKeyTime);
							MotionKeyRY->SetValue(BoneCurveRY, rotation.y);
							if (!setting.QuaternionRotationSW) {
								MotionKeyRY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKeyRY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = next_rotation.y - rotation.y;
								if (MotionFrame.RCurve.ax == 127 - MotionFrame.RCurve.bx && MotionFrame.RCurve.ay == 127 - MotionFrame.RCurve.by) {
									MotionKeyRY->SetInterpolation(BoneCurveRY, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKeyRY->SetTimeLeft(BoneCurveRY, MotionKeyTimeLeft[4]);
									MotionKeyRY->SetValueLeft(BoneCurveRY, MotionKeyValueLeft[4]);
									MotionKeyRY->SetTimeRight(BoneCurveRY, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ax / 127.0), 30));
									MotionKeyRY->SetValueRight(BoneCurveRY, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ay / 127.0));
								}
								MotionKeyTimeLeft[4] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.bx / 127.0), 30);
								MotionKeyValueLeft[4] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.by / 127.0);
							}
							BoneCurveRY->InsertKey(MotionKeyRY);

							CKey* MotionKeyRZ = CKey::Alloc();//RZ
							MotionKeyRZ->SetTime(BoneCurveRZ, MotionKeyTime);
							MotionKeyRZ->SetValue(BoneCurveRZ, rotation.z);
							if (!setting.QuaternionRotationSW) {
								MotionKeyRZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKeyRZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = next_rotation.z - rotation.z;
								if (MotionFrame.RCurve.ax == 127 - MotionFrame.RCurve.bx && MotionFrame.RCurve.ay == 127 - MotionFrame.RCurve.by) {
									MotionKeyRZ->SetInterpolation(BoneCurveRZ, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKeyRZ->SetTimeLeft(BoneCurveRZ, MotionKeyTimeLeft[5]);
									MotionKeyRZ->SetValueLeft(BoneCurveRZ, MotionKeyValueLeft[5]);
									MotionKeyRZ->SetTimeRight(BoneCurveRZ, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ax / 127.0), 30));
									MotionKeyRZ->SetValueRight(BoneCurveRZ, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ay / 127.0));
								}
								MotionKeyTimeLeft[5] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.bx / 127.0), 30);
								MotionKeyValueLeft[5] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.by / 127.0);
							}
							BoneCurveRZ->InsertKey(MotionKeyRZ);
						}
						bone_cnt++;
					}
				}
				else {
					if (setting.QuaternionRotationSW && bone.obj->IsQuaternionRotationMode() == false) {
						bone.obj->SetQuaternionRotationMode(true, false);
					}
					PMX_Bone_Tag* tag_data = bone.tag->GetNodeData<PMX_Bone_Tag>();
					GeData Ge_data;
					const Bool Is_physical = tag_data->Is_physical;
					bone.tag->GetParameter(DescID(TRANSLATABLE), Ge_data, DESCFLAGS_GET::NONE);
					const Bool Is_translatable = Ge_data.GetBool();
					bone.tag->GetParameter(DescID(ROTATABLE), Ge_data, DESCFLAGS_GET::NONE);
					const Bool Is_rotatable = Ge_data.GetBool();
					CTrack* BoneTrackPX = nullptr;
					CTrack* BoneTrackPY = nullptr;
					CTrack* BoneTrackPZ = nullptr;
					CTrack* BoneTrackRX = nullptr;
					CTrack* BoneTrackRY = nullptr;
					CTrack* BoneTrackRZ = nullptr;
					CCurve* BoneCurvePX = nullptr;
					CCurve* BoneCurvePY = nullptr;
					CCurve* BoneCurvePZ = nullptr;
					CCurve* BoneCurveRX = nullptr;
					CCurve* BoneCurveRY = nullptr;
					CCurve* BoneCurveRZ = nullptr;
					if (!Is_physical) {
						if (Is_translatable) {
							bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPX);
							BoneTrackPX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
							bone.obj->InsertTrackSorted(BoneTrackPX);
							BoneTrackPY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPY);
							BoneTrackPY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							if (BoneTrackPY == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
							bone.obj->InsertTrackSorted(BoneTrackPY);
							BoneTrackPZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPZ);
							BoneTrackPZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							if (BoneTrackPZ == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
							bone.obj->InsertTrackSorted(BoneTrackPZ);
							BoneCurvePX = BoneTrackPX->GetCurve();
							BoneCurvePY = BoneTrackPY->GetCurve();
							BoneCurvePZ = BoneTrackPZ->GetCurve();
						}
						if (Is_rotatable) {
							BoneTrackRX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRX);
							BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							if (BoneTrackRX == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
							bone.obj->InsertTrackSorted(BoneTrackRX);
							BoneTrackRY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRY);
							BoneTrackRY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							if (BoneTrackRY == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
							bone.obj->InsertTrackSorted(BoneTrackRY);
							BoneTrackRZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRZ);
							BoneTrackRZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							if (BoneTrackRZ == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
							bone.obj->InsertTrackSorted(BoneTrackRZ);
							BoneCurveRX = BoneTrackRX->GetCurve();
							BoneCurveRY = BoneTrackRY->GetCurve();
							BoneCurveRZ = BoneTrackRZ->GetCurve();
						}

						Int32 motion_frame_number = MotionFrameList->GetCount();
						for (Int32 motion_index = 0; motion_index < motion_frame_number; motion_index++)
						{
							StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
							StatusSetBar(motion_index * 100 / motion_frame_number);
							if (motion_index == 0 && motion_frame_number != 1)
							{
								MotionFrame = MotionFrameList->operator[](motion_index);
								NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
							}
							else if (motion_index == motion_frame_number - 1)
							{
								MotionFrame = NextMotionFrame;
							}
							else
							{
								MotionFrame = NextMotionFrame;
								NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
							}
							TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
							Int32 frame_no = MotionFrame.frame_no + setting.TimeOffset;
							MotionKeyTime = BaseTime(frame_no, 30);
							if (Is_translatable) {
								BoneCurvePX->AddKey(MotionKeyTime)->SetValue(BoneCurvePX, MotionFrame.position.x * setting.PositionMultiple);
								tag_data->SetCurve(PMX_BONE_TAG_XCURVE, frame_no, new mmd::VMD_Curve(MotionFrame.XCurve));
								BoneCurvePY->AddKey(MotionKeyTime)->SetValue(BoneCurvePY, MotionFrame.position.y * setting.PositionMultiple);
								tag_data->SetCurve(PMX_BONE_TAG_YCURVE, frame_no, new mmd::VMD_Curve(MotionFrame.YCurve));
								BoneCurvePZ->AddKey(MotionKeyTime)->SetValue(BoneCurvePZ, MotionFrame.position.z * setting.PositionMultiple);
								tag_data->SetCurve(PMX_BONE_TAG_ZCURVE, frame_no, new mmd::VMD_Curve(MotionFrame.ZCurve));
							}
							if (Is_rotatable) {
								Vector32 rotation;
								rotation.x = -maxon::ATan2(2 * MotionFrame.rotation.y * MotionFrame.rotation.w + 2 * MotionFrame.rotation.x * MotionFrame.rotation.z, 1 - 2 * (MotionFrame.rotation.x * MotionFrame.rotation.x + MotionFrame.rotation.y * MotionFrame.rotation.y));
								rotation.y = -maxon::ASin(2 * (MotionFrame.rotation.x * MotionFrame.rotation.w - MotionFrame.rotation.y * MotionFrame.rotation.z));
								rotation.z = -maxon::ATan2(2 * MotionFrame.rotation.z * MotionFrame.rotation.w + 2 * MotionFrame.rotation.x * MotionFrame.rotation.y, 1 - 2 * (MotionFrame.rotation.x * MotionFrame.rotation.x + MotionFrame.rotation.z * MotionFrame.rotation.z));
								Vector32 next_rotation;
								next_rotation.x = -maxon::ATan2(2 * NextMotionFrame.rotation.y * NextMotionFrame.rotation.w + 2 * NextMotionFrame.rotation.x * NextMotionFrame.rotation.z, 1 - 2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.x + NextMotionFrame.rotation.y * NextMotionFrame.rotation.y));
								next_rotation.y = -maxon::ASin(2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.w - NextMotionFrame.rotation.y * NextMotionFrame.rotation.z));
								next_rotation.z = -maxon::ATan2(2 * NextMotionFrame.rotation.z * NextMotionFrame.rotation.w + 2 * NextMotionFrame.rotation.x * NextMotionFrame.rotation.y, 1 - 2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.x + NextMotionFrame.rotation.z * NextMotionFrame.rotation.z));
								BoneCurveRX->AddKey(MotionKeyTime)->SetValue(BoneCurveRX, rotation.x);
								BoneCurveRY->AddKey(MotionKeyTime)->SetValue(BoneCurveRY, rotation.y);
								BoneCurveRZ->AddKey(MotionKeyTime)->SetValue(BoneCurveRZ, rotation.z);
								if (!setting.QuaternionRotationSW) {
									tag_data->SetCurve(PMX_BONE_TAG_RCURVE, frame_no, new mmd::VMD_Curve(MotionFrame.RCurve));
								}
							}
						}				
					bone_cnt++;
					}
				}
			}
		}
		else
		{
			not_find_bone_S.Append(motion_bone_name)iferr_return;
		}
	}

	mmd::VMD_Morph MorphFrame;
	maxon::BaseArray<String> not_find_morph_S;
	Int32 morph_cnt = 0;
	Int32 motion_frame_morph_number = MorphFrameList_map.GetCount();
	String motion_frame_morph_number_S = String::IntToString(motion_frame_morph_number);
	for (String morph_motion_name : MorphFrameList_map.GetKeys())
	{
		maxon::BaseList<mmd::VMD_Morph>* MorphFrameList = (MorphFrameList_map.Find(morph_motion_name)->GetValue());
		auto morph_ptr = morph_name_map.Find(morph_motion_name);
		if (morph_ptr != nullptr)
		{
			for (morph_id_tag& morph_id_tag_ : morph_ptr->GetValue()) {
				DescID morphID = morph_id_tag_.id;
				BaseTag* pose_morph_tag = morph_id_tag_.tag;
				CTrack* MorphTrack = pose_morph_tag->FindCTrack(morphID);
				if (MorphTrack == nullptr)
				{
					MorphTrack = CTrack::Alloc(pose_morph_tag, morphID);
					if (MorphTrack == nullptr)
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					pose_morph_tag->InsertTrackSorted(MorphTrack);
				}
				CCurve* MorphCurve = MorphTrack->GetCurve();
				Int32 morph_frame_number = MorphFrameList->GetCount();
				for (Int32 morph_index = 0; morph_index < morph_frame_number; morph_index++)
				{
					StatusSetText("Import motion of morph " + String::IntToString(morph_cnt) + "/" + motion_frame_morph_number_S);
					StatusSetBar(morph_index * 100 / morph_frame_number);
					MorphFrame = (*MorphFrameList)[morph_index];
					CKey* MorphKey = CKey::Alloc();
					MorphKey->SetTime(MorphCurve, BaseTime(MorphFrame.frame_no + setting.TimeOffset, 30));
					MorphKey->SetValue(MorphCurve, MorphFrame.weight);
					MorphCurve->InsertKey(MorphKey);
				}
				morph_cnt++;
			}
		}
		else
		{
			not_find_morph_S.Append(morph_motion_name)iferr_return;
		}
	}
	timing.Stop();
	StatusClear();
	doc->SetMaxTime(BaseTime(MaxTime, 30));
	doc->SetLoopMaxTime(BaseTime(MaxTime, 30));
	EventAdd(EVENT::NONE);
	doc->SetTime(BaseTime(1, 30));
	doc->SetTime(BaseTime(0, 30));
	String report = GeLoadString(IDS_MES_IMPORT_MOT_OK, String::IntToString(bone_cnt), String::IntToString(morph_cnt), String::IntToString(motion_frame_bone_number + motion_frame_morph_number), String::FloatToString(timing.GetMilliseconds())) + "\n";
	if (setting.DetailReport == 1) {
		report += GeLoadString(IDS_MES_IMPORT_MOT_CF_BONE, String::IntToString(not_find_bone_S.GetCount())) + ":\n";
		for (String i : not_find_bone_S)
		{
			report += "\"" + i + "\" ";
		}
		report += "\n" + GeLoadString(IDS_MES_IMPORT_MOT_CF_MORPH, String::IntToString(not_find_morph_S.GetCount())) + ":\n";
		for (String i : not_find_morph_S)
		{
			report += "\"" + i + "\" ";
		}
	}
	MessageDialog(report);
	bone_name_map.Reset();
	morph_name_map.Reset();
	for (auto i : MorphFrameList_map.GetValues()) {
		if (i != nullptr)delete i;
	}
	MorphFrameList_map.Reset();
	for (auto i : MotionFrameList_map.GetValues()) {
		if (i != nullptr)delete i;
	}
	MotionFrameList_map.Reset();
	not_find_bone_S.Reset();
	not_find_morph_S.Reset();
	return maxon::OK;
}
