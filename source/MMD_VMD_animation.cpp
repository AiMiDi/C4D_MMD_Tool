#include "MMD_VMD_animation.h"

void mmd::OMMDCamera::Free(GeListNode* node)
{
	/* GetActiveDocument()->FindSceneHook(ID_S_MMD_CAM_DRAW)->GetNodeData<VMD_Cam_Draw>()->DeleteDrawObj((BaseObject*)node); */
	this->interpolator_X_map.Reset();
	this->interpolator_Y_map.Reset();
	this->interpolator_Z_map.Reset();
	this->interpolator_R_map.Reset();
	this->interpolator_D_map.Reset();
	this->interpolator_V_map.Reset();
	this->interpolator_A_map.Reset();
}


Bool mmd::OMMDCamera::SplineDataCallBack(Int32 cid, const void* data)
{
	/* 还有其他一些回调类型，我们在这里仅使用SPLINE_CALLBACK_CORE_MESSAGE */
	if (cid == SPLINE_CALLBACK_CORE_MESSAGE)
	{
		if (data == nullptr)
			return(true);

		/* 数据信息... */
		SplineData* splineData = ((SplineDataCallbackCoreMessage*)data)->pGUI->GetSplineData();
		if (splineData == nullptr)
			return(true);


		/*
		 * 现在我们只需检查所有的knot并限制它们。我只是限制在这里的每个切线的[0，1]区间，
		 * 限制就是把切线控制点正交投影切线到“[0，1]”。
		 * 如果要缩放向量，使位于[0，1]区间外部的控制柄以该控制柄接触该框边界的方式进行缩放。
		 */
		const Int32 KnotCount = splineData->GetKnotCount();
		for (Int32 i = 0; i < KnotCount; i++)
		{
			/* 获取当前knot。 */
			CustomSplineKnot* knot = splineData->GetKnot(i);
			if (knot == nullptr)
				continue;
			/* 切线存在于相对于其顶点的向量空间中，因此我们首先使切线向量全局化，然后限制它们。 */
			Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
			globalLeftTangent.ClampMax(Vector(127., 127., 0.));
			globalLeftTangent.ClampMin(Vector(0.0));
			Vector globalRightTangent = knot->vPos + knot->vTangentRight;
			globalRightTangent.ClampMax(Vector(127., 127., 0.));
			globalRightTangent.ClampMin(Vector(0.0));
			/* 然后我们把切线转换回它们的局部切线空间，然后写回去。 */
			knot->vTangentLeft = globalLeftTangent - knot->vPos;
			knot->vTangentRight = globalRightTangent - knot->vPos;
		}
	}
	return(true);
}


inline Bool mmd::OMMDCamera::GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator)
{
	switch (type)
	{
	case (VMD_CAM_OBJ_XCURVE): {
		auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_x_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_x_ptr->GetValue();
		}
		break;
	}
	case (VMD_CAM_OBJ_YCURVE): {
		auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_y_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_y_ptr->GetValue();
		}
		break;
	}
	case (VMD_CAM_OBJ_ZCURVE):
	{
		auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_z_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_z_ptr->GetValue();
		}
		break;
	}
	case (VMD_CAM_OBJ_RCURVE): {
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_r_ptr->GetValue();
		}
		break;
	}
	case (VMD_CAM_OBJ_DCURVE): {
		auto interpolator_d_ptr = interpolator_D_map.Find(frame_on);
		if (interpolator_d_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_d_ptr->GetValue();
		}
		break;
	}
	case (VMD_CAM_OBJ_VCURVE): {
		auto interpolator_v_ptr = interpolator_V_map.Find(frame_on);
		if (interpolator_v_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_v_ptr->GetValue();
		}
		break;
	}
	case (VMD_CAM_OBJ_ACURVE): {
		auto interpolator_a_ptr = interpolator_A_map.Find(frame_on);
		if (interpolator_a_ptr == nullptr)
		{
			interpolator.ax = 20;
			interpolator.bx = 107;
			interpolator.ay = 20;
			interpolator.by = 107;
			return(false);
		}
		else {
			interpolator = interpolator_a_ptr->GetValue();
		}
		break;
	}
	default:
		return(false);
		break;
	}
	return(true);
}


inline Bool mmd::OMMDCamera::SetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator)
{
	iferr_scope_handler{
	return false;
	};
	BaseObject* obj = (BaseObject*)Get();
	if (obj == nullptr)
	{
		return(false);
	}
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
	if (Frame_onTrack == nullptr)
	{
		Frame_onTrack = CTrack::Alloc(obj, DescID(VMD_CAM_OBJ_FRAME_ON));
		obj->InsertTrackSorted(Frame_onTrack);
	}
	CCurve* Frame_onCurve = Frame_onTrack->GetCurve();
	if (Frame_onCurve == nullptr)
	{
		return(false);
	}
	CKey* KeyFrame_on = Frame_onCurve->AddKey(BaseTime(frame_on, 30));
	if (KeyFrame_on == nullptr)
	{
		return(false);
	}
	KeyFrame_on->SetValue(Frame_onCurve, frame_on);
	KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
	KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	switch (type)
	{
	case (VMD_CAM_OBJ_XCURVE): {
		auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_x_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_x = interpolator_x_ptr->GetValue();
			interpolator_x = interpolator;
		}
		else {
			interpolator_X_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (VMD_CAM_OBJ_YCURVE): {
		auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_y_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_y = interpolator_y_ptr->GetValue();
			interpolator_y = interpolator;
		}
		else {
			interpolator_Y_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (VMD_CAM_OBJ_ZCURVE): {
		auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_z_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_z = interpolator_z_ptr->GetValue();
			interpolator_z = interpolator;
		}
		else {
			interpolator_Z_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (VMD_CAM_OBJ_RCURVE): {
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_r = interpolator_r_ptr->GetValue();
			interpolator_r = interpolator;
		}
		else {
			interpolator_R_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (VMD_CAM_OBJ_DCURVE): {
		auto interpolator_d_ptr = interpolator_D_map.Find(frame_on);
		if (interpolator_d_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_d = interpolator_d_ptr->GetValue();
			interpolator_d = interpolator;
		}
		else {
			interpolator_D_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (VMD_CAM_OBJ_VCURVE): {
		auto interpolator_v_ptr = interpolator_V_map.Find(frame_on);
		if (interpolator_v_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_v = interpolator_v_ptr->GetValue();
			interpolator_v = interpolator;
		}
		else {
			interpolator_V_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (VMD_CAM_OBJ_ACURVE): {
		auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_x_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_x = interpolator_x_ptr->GetValue();
			interpolator_x = interpolator;
		}
		else {
			interpolator_X_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_y_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_y = interpolator_y_ptr->GetValue();
			interpolator_y = interpolator;
		}
		else {
			interpolator_Y_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_z_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_z = interpolator_z_ptr->GetValue();
			interpolator_z = interpolator;
		}
		else {
			interpolator_Z_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_r = interpolator_r_ptr->GetValue();
			interpolator_r = interpolator;
		}
		else {
			interpolator_R_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_d_ptr = interpolator_D_map.Find(frame_on);
		if (interpolator_d_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_d = interpolator_d_ptr->GetValue();
			interpolator_d = interpolator;
		}
		else {
			interpolator_D_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_v_ptr = interpolator_V_map.Find(frame_on);
		if (interpolator_v_ptr != nullptr)
		{
			mmd::VMDInterpolator& interpolator_v = interpolator_v_ptr->GetValue();
			interpolator_v = interpolator;
		}
		else {
			interpolator_V_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	default:
		return(false);
		break;
	}
	return(true);
}


inline Bool mmd::OMMDCamera::RegisterKeyFrame(Int32 frame_on, GeListNode* node) {
	iferr_scope_handler{
		return false;
	};
	if (node == nullptr)
	{
		node = Get();
	}
	BaseObject* obj = (BaseObject*)node;
	if (obj == nullptr)
	{
		return false;
	}
	if (cam == nullptr)
	{
		return false;
	}
	BaseTime	time = BaseTime(Float(frame_on), 30.);
	GeData		data_, Curve_type_data;
	BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
	if (bc == nullptr)
	{
		return(true);
	}
	data_ = bc->GetData(VMD_CAM_OBJ_SPLINE);
	SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);

	CTrack* Track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (Track_position_x == nullptr)
	{
		Track_position_x = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		obj->InsertTrackSorted(Track_position_x);
	}
	CTrack* Track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (Track_position_y == nullptr)
	{
		Track_position_y = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		obj->InsertTrackSorted(Track_position_y);
	}
	CTrack* Track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (Track_position_z == nullptr)
	{
		Track_position_z = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		obj->InsertTrackSorted(Track_position_z);
	}
	CTrack* Track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (Track_rotation_x == nullptr)
	{
		Track_rotation_x = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		obj->InsertTrackSorted(Track_rotation_x);
	}
	CTrack* Track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (Track_rotation_y == nullptr)
	{
		Track_rotation_y = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		obj->InsertTrackSorted(Track_rotation_y);
	}
	CTrack* Track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (Track_rotation_z == nullptr)
	{
		Track_rotation_z = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		obj->InsertTrackSorted(Track_rotation_z);
	}
	CTrack* TrackD = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (TrackD == nullptr)
	{
		TrackD = CTrack::Alloc(cam, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		cam->InsertTrackSorted(TrackD);
	}
	CTrack* TrackV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	if (TrackV == nullptr)
	{
		TrackV = CTrack::Alloc(cam, DescID(CAMERAOBJECT_APERTURE));
		cam->InsertTrackSorted(TrackV);
	}

	CCurve* Curve_position_x = Track_position_x->GetCurve();
	CCurve* Curve_position_y = Track_position_y->GetCurve();
	CCurve* Curve_position_z = Track_position_z->GetCurve();
	CCurve* Curve_rotation_x = Track_rotation_x->GetCurve();
	CCurve* Curve_rotation_y = Track_rotation_y->GetCurve();
	CCurve* Curve_rotation_z = Track_rotation_z->GetCurve();
	CCurve* CurveD = TrackD->GetCurve();
	CCurve* CurveV = TrackV->GetCurve();

	/* 确保获取成功 */
	if (Curve_position_x == nullptr || Curve_position_y == nullptr || Curve_position_z == nullptr || Curve_rotation_x == nullptr || Curve_rotation_y == nullptr || Curve_rotation_z == nullptr || CurveD == nullptr || CurveV == nullptr)
	{
		return(true);
	}
	Vector RelPos = obj->GetRelPos();
	Vector RelRot = obj->GetRelRot();

	CKey* Key_position_x = Curve_position_x->FindKey(time);
	if (Key_position_x == nullptr)
	{
		Key_position_x = Curve_position_x->AddKey(time);
		if (Key_position_x == nullptr)
		{
			return(true);
		}
	}
	else {
		Key_position_x->SetValue(Curve_position_x, RelPos.x);
	}
	CKey* Key_position_y = Curve_position_y->FindKey(time);
	if (Key_position_y == nullptr)
	{
		Key_position_y = Curve_position_y->AddKey(time);
		if (Key_position_y == nullptr)
		{
			return(true);
		}
	}
	else {
		Key_position_y->SetValue(Curve_position_y, RelPos.y);
	}
	CKey* Key_position_z = Curve_position_z->FindKey(time);
	if (Key_position_z == nullptr)
	{
		Key_position_z = Curve_position_z->AddKey(time);
		if (Key_position_z == nullptr)
		{
			return(true);
		}
	}
	else {
		Key_position_z->SetValue(Curve_position_z, RelPos.z);
	}
	CKey* Key_rotation_x = Curve_rotation_x->FindKey(time);
	if (Key_rotation_x == nullptr)
	{
		Key_rotation_x = Curve_rotation_x->AddKey(time);
		if (Key_rotation_x == nullptr)
		{
			return(true);
		}
	}
	else {
		Key_rotation_x->SetValue(Curve_rotation_x, RelRot.x);
	}
	CKey* Key_rotation_y = Curve_rotation_y->FindKey(time);
	Key_rotation_y = Curve_rotation_y->AddKey(time);
	if (Key_rotation_y == nullptr)
	{
		Key_rotation_y = Curve_rotation_y->AddKey(time);
		if (Key_rotation_y == nullptr)
		{
			return(true);
		}
	}
	else {
		Key_rotation_y->SetValue(Curve_rotation_y, RelRot.y);
	}
	CKey* Key_rotation_z = Curve_rotation_z->FindKey(time);
	if (Key_rotation_z == nullptr)
	{
		Key_rotation_z = Curve_rotation_z->AddKey(time);
		if (Key_rotation_z == nullptr)
		{
			return(true);
		}
	}
	else {
		Key_rotation_z->SetValue(Curve_rotation_z, RelRot.z);
	}
	CKey* KeyD = CurveD->FindKey(time);
	if (KeyD == nullptr)
	{
		KeyD = CurveD->AddKey(time);
		if (KeyD == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyD->SetValue(CurveD, cam->GetRelPos().z);
	}
	CKey* KeyV = CurveV->FindKey(time);
	if (KeyV == nullptr)
	{
		KeyV = CurveV->AddKey(time);
		if (KeyV == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyV->SetValue(CurveV, static_cast<CameraObject*>(cam)->GetAperture());
	}

	const Int32 KnotCount = spline->GetKnotCount();
	for (Int32 KnotIndex = 0; KnotIndex < KnotCount; KnotIndex++)
	{
		/* 获取当前knot。 */
		CustomSplineKnot* knot = spline->GetKnot(KnotIndex);
		if (knot == nullptr)
		{
			return(true);
		}
		/* 切线存在于相对于其顶点的向量空间中，因此我们首先使切线向量全局化，然后限制它们。 */
		Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
		globalLeftTangent.ClampMax(Vector(127, 127, 0));
		globalLeftTangent.ClampMin(Vector(0, 0, 0));
		Vector globalRightTangent = knot->vPos + knot->vTangentRight;
		globalRightTangent.ClampMax(Vector(127, 127, 0));
		globalRightTangent.ClampMin(Vector(0, 0, 0));
		/* 然后我们把切线转换回它们的局部切线空间，然后写回去。 */
		knot->vTangentLeft = globalLeftTangent - knot->vPos;
		knot->vTangentRight = globalRightTangent - knot->vPos;
	}

	node->GetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), Curve_type_data, DESCFLAGS_GET::NONE);
	Int32 interpolator_type = Curve_type_data.GetInt32();
	switch (interpolator_type)
	{
	case (VMD_CAM_OBJ_XCURVE): {
			if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
				spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
				127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
				127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
				return false;
			if (!this->SetInterpolator(VMD_CAM_OBJ_YCURVE, frame_on, VMDInterpolator()))
				return false;
			if (!this->SetInterpolator(VMD_CAM_OBJ_ZCURVE, frame_on, VMDInterpolator()))
				return false;
			if (!this->SetInterpolator(VMD_CAM_OBJ_RCURVE, frame_on, VMDInterpolator()))
				return false;
			if (!this->SetInterpolator(VMD_CAM_OBJ_DCURVE, frame_on, VMDInterpolator()))
				return false;
			if (!this->SetInterpolator(VMD_CAM_OBJ_VCURVE, frame_on, VMDInterpolator()))
				return false;
		break;
	}
	case (VMD_CAM_OBJ_YCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_RCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_DCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_VCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (VMD_CAM_OBJ_ZCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_RCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_DCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_VCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (VMD_CAM_OBJ_RCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_DCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_VCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (VMD_CAM_OBJ_DCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_RCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_VCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (VMD_CAM_OBJ_VCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_RCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(VMD_CAM_OBJ_DCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (VMD_CAM_OBJ_ACURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		break;
	}
	default:
		break;
	}
	this->UpdateAllInterpolator(node);
	return true;
}


inline Bool mmd::OMMDCamera::UpdateAllInterpolator(GeListNode* node)
{
	if (node == nullptr)
	{
		node = Get();
	}
	BaseObject* obj = static_cast<BaseObject*>(node);
	if (obj == nullptr)
	{
		return(false);
	}
	CTrack* track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* track_distance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* track_AOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	CTrack* track_frame = obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));

	if (track_position_x == nullptr || track_position_y == nullptr || track_position_z == nullptr || track_rotation_x == nullptr || track_rotation_y == nullptr || track_rotation_z == nullptr || track_distance == nullptr || track_AOV == nullptr || track_frame == nullptr)
	{
		return false;
	}

	CCurve* curve_position_x = track_position_x->GetCurve();
	CCurve* curve_position_y = track_position_y->GetCurve();
	CCurve* curve_position_z = track_position_z->GetCurve();
	CCurve* curve_rotation_x = track_rotation_x->GetCurve();
	CCurve* curve_rotation_y = track_rotation_y->GetCurve();
	CCurve* curve_rotation_z = track_rotation_z->GetCurve();
	CCurve* curve_distance = track_distance->GetCurve();
	CCurve* curve_AOV = track_AOV->GetCurve();
	CCurve* curve_frame = track_frame->GetCurve();

	if (curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr || curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr || curve_distance == nullptr || curve_AOV == nullptr || curve_frame == nullptr)
	{
		return false;
	}

	Int32 frame_on = 0.;
	Float ValueOfTwoFrames = 0.;
	Float TimeOfTwoFrames = 0.;
	BaseTime time = BaseTime();
	BaseTime next_time = BaseTime();
	CKey* key = nullptr;
	CKey* next_key = nullptr;
	CKey* frame_next = nullptr;
	maxon::HashMap<Int32, mmd::VMDInterpolator>::Entry* interpolator_ptr;

	const Int32 kKeyCount = curve_frame->GetKeyCount();
	for (Int32 frame_index = 0; frame_index < kKeyCount; frame_index++)
	{
		frame_on = curve_frame->GetKey(frame_index)->GetValue();
		time = BaseTime(frame_on, 30.);
		frame_next = curve_frame->FindKey(BaseTime(frame_on + 1, 30.), nullptr, FINDANIM::RIGHT); /* 加一排除所在的那一帧 */
		if (frame_next == nullptr)
		{
			break;
		}
		next_time = frame_next->GetTime();
		TimeOfTwoFrames = next_time.GetFrame(30.) - time.GetFrame(30.);

		interpolator_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_position_x->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_position_x->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_position_x, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_position_x, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_position_x, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_position_x, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_position_y->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_position_y->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_position_y, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_position_y, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_position_y, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_position_y, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_position_z->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_position_z->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_position_z, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_position_z, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_position_z, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_position_z, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_rotation_x->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_rotation_x->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_rotation_x, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_rotation_x, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_rotation_x, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_rotation_x, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_rotation_y->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_rotation_y->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_rotation_y, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_rotation_y, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_rotation_y, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_rotation_y, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_rotation_z->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_rotation_z->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_rotation_z, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_rotation_z, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_rotation_z, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_rotation_z, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_D_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_distance->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_distance->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_distance, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_distance, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_distance, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_distance, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_V_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = curve_AOV->FindKey(time);
			if (key != nullptr)
			{
				next_key = curve_AOV->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(curve_AOV, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(curve_AOV, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(curve_AOV, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(curve_AOV, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
	}
	return(true);
}


inline Bool mmd::OMMDCamera::CameraInit(GeListNode* node)
{
	if (node == nullptr)
	{
		node = Get();
	}
	if (cam == nullptr)
	{
		BaseObject* down_obj = reinterpret_cast<BaseObject*>(node->GetDown());
		if (down_obj != nullptr)
		{
			if (down_obj->GetType() == Ocamera)
			{
				cam = down_obj;
			}
			else {
				cam = BaseObject::Alloc(Ocamera); /* 5103 */
				cam->SetName("Camera"_s);
				BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
				ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
				cam->InsertTag(ProtectionTag);
				cam->InsertUnder(node);
			}
		}
		else {
			cam = BaseObject::Alloc(Ocamera); /* 5103 */
			cam->SetName("Camera"_s);
			BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
			ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
			cam->InsertTag(ProtectionTag);
			cam->InsertUnder(node);
		}
	}
	return(true);
}


inline Bool mmd::OMMDCamera::InitInterpolator(GeListNode* node)
{
	if (node == nullptr)
	{
		node = Get();
	}
	BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
	GeData		data = GeData(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
	SplineData* spline = (SplineData*)data.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
	if (spline != nullptr)
	{
		spline->AdaptRange(0.0, 127.0, 127.0, 0.0, 127.0, 127.0);
		spline->InsertKnot(0.0, 0.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->InsertKnot(127.0, 127.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->SetUserCallback(mmd::OMMDCamera::SplineDataCallBack, nullptr);
		CustomSplineKnot* a = spline->GetKnot(0);
		CustomSplineKnot* b = spline->GetKnot(spline->GetKnotCount() - 1);
		a->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		b->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		a->vTangentRight = Vector(20.0, 20.0, 0.0);
		b->vTangentLeft = Vector(-20.0, -20., 0.0);
	}
	bc->SetData(VMD_CAM_OBJ_SPLINE, data);
	return(true);
}


inline Bool mmd::OMMDCamera::DeleteKeyFrame(Int32 frame_on, GeListNode* node) {
	if (node == nullptr)
	{
		node = Get();
	}
	BaseObject* obj = (BaseObject*)node;
	if (obj == nullptr)
	{
		return(true);
	}
	BaseTime time = BaseTime(Float(frame_on), 30.);

	auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
	if (interpolator_x_ptr != nullptr)
	{
		interpolator_X_map.Erase(interpolator_x_ptr);
	}
	auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
	if (interpolator_y_ptr != nullptr)
	{
		interpolator_Y_map.Erase(interpolator_y_ptr);
	}
	auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
	if (interpolator_z_ptr != nullptr)
	{
		interpolator_Z_map.Erase(interpolator_z_ptr);
	}
	auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
	if (interpolator_r_ptr != nullptr)
	{
		interpolator_R_map.Erase(interpolator_r_ptr);
	}
	auto interpolator_d_ptr = interpolator_D_map.Find(frame_on);
	if (interpolator_d_ptr != nullptr)
	{
		interpolator_D_map.Erase(interpolator_d_ptr);
	}
	auto interpolator_v_ptr = interpolator_V_map.Find(frame_on);
	if (interpolator_v_ptr != nullptr)
	{
		interpolator_V_map.Erase(interpolator_v_ptr);
	}
	auto interpolator_a_ptr = interpolator_A_map.Find(frame_on);
	if (interpolator_a_ptr != nullptr)
	{
		interpolator_A_map.Erase(interpolator_a_ptr);
	}

	CTrack* Track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (Track_position_x != nullptr)
	{
		CKey* Key_position_x = Track_position_x->GetCurve()->FindKey(time);
		CKey::Free(Key_position_x);
	}
	CTrack* Track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (Track_position_y != nullptr)
	{
		CKey* Key_position_y = Track_position_y->GetCurve()->FindKey(time);
		CKey::Free(Key_position_y);
	}
	CTrack* Track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (Track_position_z != nullptr)
	{
		CKey* Key_position_z = Track_position_z->GetCurve()->FindKey(time);
		CKey::Free(Key_position_z);
	}
	CTrack* Track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (Track_rotation_x != nullptr)
	{
		CKey* Key_rotation_x = Track_rotation_x->GetCurve()->FindKey(time);
		CKey::Free(Key_rotation_x);
	}
	CTrack* Track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (Track_rotation_y != nullptr)
	{
		CKey* Key_rotation_y = Track_rotation_y->GetCurve()->FindKey(time);
		CKey::Free(Key_rotation_y);
	}
	CTrack* Track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (Track_rotation_z != nullptr)
	{
		CKey* Key_rotation_z = Track_rotation_z->GetCurve()->FindKey(time);
		CKey::Free(Key_rotation_z);
	}
	CTrack* TrackDistance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (TrackDistance != nullptr)
	{
		CKey* DistanceKey = TrackDistance->GetCurve()->FindKey(time);
		CKey::Free(DistanceKey);
	}
	CTrack* TrackAOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	if (TrackAOV != nullptr)
	{
		CKey* AOVKey = TrackAOV->GetCurve()->FindKey(time);
		CKey::Free(AOVKey);
	}
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	if (Frame_onTrack != nullptr)
	{
		CKey* KeyFrame_on = Frame_onTrack->GetCurve()->FindKey(time);
		CKey::Free(KeyFrame_on);
	}
	return true;
}


inline Bool mmd::OMMDCamera::DeleteAllKeyFrame(GeListNode* node) {
	if (node == nullptr)
	{
		node = Get();
	}
	BaseObject* obj = static_cast<BaseObject*>(node);
	if (obj == nullptr)
	{
		return(false);
	}
	this->interpolator_X_map.Reset();
	this->interpolator_Y_map.Reset();
	this->interpolator_Z_map.Reset();
	this->interpolator_R_map.Reset();
	this->interpolator_D_map.Reset();
	this->interpolator_V_map.Reset();
	this->interpolator_A_map.Reset();
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	CTrack::Free(Frame_onTrack);
	CTrack* Track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack::Free(Track_position_x);
	CTrack* Track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack::Free(Track_position_y);
	CTrack* Track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack::Free(Track_position_z);
	CTrack* Track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack::Free(Track_rotation_x);
	CTrack* Track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack::Free(Track_rotation_y);
	CTrack* Track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack::Free(Track_rotation_z);
	CTrack* TrackDistance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack::Free(TrackDistance);
	CTrack* TrackAOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	CTrack::Free(TrackAOV);
	obj->SetRelPos(Vector());
	obj->SetRelRot(Vector());
	cam->SetRelPos(Vector(0.,0.,45.));
	cam->SetRelRot(Vector());
	static_cast<CameraObject*>(cam)->SetAperture(30);
	return true;
}


Bool mmd::OMMDCamera::Init(GeListNode* node)
{
	if (node == nullptr)
		return(false);
	node->SetParameter(DescID(VMD_CAM_OBJ_CURVE_TYPE), 6, DESCFLAGS_SET::NONE);
	if (!InitInterpolator(node))
		return(false);
	return(true);
}


Bool mmd::OMMDCamera::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (id[0].id == VMD_CAM_OBJ_SPLINE)
	{
		((SplineData*)t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(mmd::OMMDCamera::SplineDataCallBack, nullptr);
	}
	return(SUPER::SetDParameter(node, id, t_data, flags));
}


Bool mmd::OMMDCamera::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return(true);
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND: {
		DescriptionCommand* dc = (DescriptionCommand*)data;
		switch (dc->_descId[0].id)
		{
		case (VMD_CAM_OBJ_INIT_CURVE_BUTTON):
		{
			InitInterpolator(node);
			break;
		}
		case (VMD_CAM_OBJ_REGISTER_CURVE_BUTTON):
		{
			BaseTime time = GetActiveDocument()->GetTime();
			RegisterKeyFrame(time.GetFrame(30.), node);
			node->GetDocument()->SetTime(BaseTime());
			node->GetDocument()->SetTime(time);
			break;
		}
		case (VMD_CAM_OBJ_UPDATE_CURVE_BUTTON):
		{
			UpdateAllInterpolator(node);
			break;
		}
		case (VMD_CAM_OBJ_DELETE_CURVE_BUTTON):
		{
			if (QuestionDialog(IDS_MES_DELETE_CAM_CURVE))
			{
				BaseTime time = GetActiveDocument()->GetTime();
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
			return(true);
		node->SetParameter(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y), 85.0, DESCFLAGS_SET::NONE);
		cam->SetRelPos(Vector(0, 0, -382.5));
		break;
	}
	default:
		break;
	}
	return(true);
}


Bool mmd::OMMDCamera::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (id[0].id == VMD_CAM_OBJ_FRAME_ON)
		return(false);
	return(SUPER::GetDEnabling(node, id, t_data, flags, itemdesc));
}


Bool mmd::VMD_Cam_Draw::Draw(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags)
{
	if (!node || !doc || !bd || !bh)
		return(false);
	if (flags != SCENEHOOKDRAW::DRAW_PASS)
		return(true);
	BaseObject* op = doc->GetActiveObject();
	if (op != nullptr)
	{
		if (op->GetType() == ID_O_MMD_CAMERA)
		{
			/* store and set line width */
			const GeData kOldLineWidth = bd->GetDrawParam(DRAW_PARAMETER_LINEWIDTH);
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, GeData{ 4.0 });
			const Vector& screenSpacePos = bd->WS(op->GetMg().off);
			/* set color */
			bd->SetPen(Vector(255, 86, 137) / 255);
			/* draw circle */
			bd->DrawCircle2D(screenSpacePos.x, screenSpacePos.y, 16);
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, GeData{ 8 });
			bd->DrawCircle2D(screenSpacePos.x, screenSpacePos.y, 4);
			/* reset matrix */
			bd->SetMatrix_Matrix(NULL, Matrix(), 0);
			/* reset parameter */
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, kOldLineWidth);
		}
	}
	if (bd->TestBreak())
		return(true);
	return(SUPER::Draw(node, doc, bd, bh, bt, flags));
}


EXECUTIONRESULT mmd::OMMDCamera::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	if (cam == nullptr)
	{
		BaseObject* down_obj = op->GetDown();
		if (down_obj != nullptr)
		{
			if (down_obj->GetType() == Ocamera)
			{
				cam = down_obj;
			}
			else {
				cam = BaseObject::Alloc(Ocamera); /* 5103 */
				cam->SetName("Camera"_s);
				BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
				ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
				cam->InsertTag(ProtectionTag);
				cam->InsertUnder(op);
			}
		}
		else {
			cam = BaseObject::Alloc(Ocamera); /* 5103 */
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

	if (prev_frame != frame_on || prev_interpolator_type != curve_type)
	{
		BaseContainer* bc = ((BaseList2D*)op)->GetDataInstance();
		if (bc == nullptr)
		{
			return(EXECUTIONRESULT::OK);
		}
		GeData		data_ = bc->GetData(VMD_CAM_OBJ_SPLINE);
		SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
		if (spline == nullptr)
		{
			return(EXECUTIONRESULT::OK);
		}
		switch (curve_type)
		{
		case (VMD_CAM_OBJ_XCURVE): {
			auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
			if (interpolator_x_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_x = interpolator_x_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_x.ax, interpolator_x.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_x.bx - 127., interpolator_x.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (VMD_CAM_OBJ_YCURVE): {
			auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
			if (interpolator_y_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_y = interpolator_y_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_y.ax, interpolator_y.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_y.bx - 127., interpolator_y.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (VMD_CAM_OBJ_ZCURVE): {
			auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
			if (interpolator_z_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_z = interpolator_z_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_z.ax, interpolator_z.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_z.bx - 127., interpolator_z.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (VMD_CAM_OBJ_RCURVE): {
			auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
			if (interpolator_r_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_r = interpolator_r_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_r.ax, interpolator_r.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_r.bx - 127., interpolator_r.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (VMD_CAM_OBJ_DCURVE): {
			auto interpolator_d_ptr = interpolator_D_map.Find(frame_on);
			if (interpolator_d_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_d = interpolator_d_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_d.ax, interpolator_d.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_d.bx - 127., interpolator_d.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (VMD_CAM_OBJ_VCURVE): {
			auto interpolator_v_ptr = interpolator_V_map.Find(frame_on);
			if (interpolator_v_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_v = interpolator_v_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_v.ax, interpolator_v.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_v.bx - 127., interpolator_v.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (VMD_CAM_OBJ_ACURVE): {
			auto interpolator_a_ptr = interpolator_A_map.Find(frame_on);
			if (interpolator_a_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_a = interpolator_a_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_a.ax, interpolator_a.ay, 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_a.bx - 127., interpolator_a.by - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		default:
			break;
		}
		bc->SetData(VMD_CAM_OBJ_SPLINE, data_);
		prev_frame = frame_on;
		prev_interpolator_type = curve_type;
	}
	return(EXECUTIONRESULT::OK);
}


Bool mmd::OMMDCamera::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return(true);
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return(true);
}


maxon::Result<BaseObject*> mmd::OMMDCamera::ConversionCamera(VMD_Conversion_Camera_settings setting)
{
	iferr_scope_handler{
		return(nullptr);
	};
	/* 获取活动文档 */
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + "error");
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	BaseObject* select_object = nullptr;

	if (setting.str_cam == nullptr) /* 若传入的参数非空则使用传入参数 */
	{
		/* 获取选中对象 */
		select_object = doc->GetActiveObject();
		if (select_object == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
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
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	/* 创建转换目标对象 */
	BaseObject* VMD_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
	if (VMD_camera == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}

	/* 创建要转化摄像机的副本，防止操作破坏原摄像机对象的数据 */
	BaseObject* select_object_clone = (BaseObject*)select_object->GetClone(COPYFLAGS::NO_HIERARCHY, nullptr);
	VMD_camera->SetName(select_object_clone->GetName());
	doc->InsertObject(VMD_camera, nullptr, nullptr);

	/* 获取目标对象内部的数据 */
	mmd::OMMDCamera* VMD_camera_data = VMD_camera->GetNodeData<OMMDCamera>();
	if (!VMD_camera_data->CameraInit())
	{
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	BaseObject* VMD_camera_distance = VMD_camera_data->cam;

	/* 将时间设置为0 */
	doc->SetTime(BaseTime(0.));

	/* 确保每个必要的参数都注册了CTrack，没有则创建一个 */
	CTrack* str_track_position_x = select_object_clone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (str_track_position_x == nullptr)
	{
		str_track_position_x = CTrack::Alloc(select_object_clone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		str_track_position_x->GetCurve()->AddKey(BaseTime())->SetValue(str_track_position_x->GetCurve(), select_object_clone->GetRelPos().x);
		select_object_clone->InsertTrackSorted(str_track_position_x);
	}
	CTrack* str_track_position_y = select_object_clone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (str_track_position_y == nullptr)
	{
		str_track_position_y = CTrack::Alloc(select_object_clone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		str_track_position_y->GetCurve()->AddKey(BaseTime())->SetValue(str_track_position_y->GetCurve(), select_object_clone->GetRelPos().y);
		select_object_clone->InsertTrackSorted(str_track_position_y);
	}
	CTrack* str_track_position_z = select_object_clone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (str_track_position_z == nullptr)
	{
		str_track_position_z = CTrack::Alloc(select_object_clone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		str_track_position_z->GetCurve()->AddKey(BaseTime())->SetValue(str_track_position_z->GetCurve(), select_object_clone->GetRelPos().z);
		select_object_clone->InsertTrackSorted(str_track_position_z);
	}
	CTrack* str_track_rotation_x = select_object_clone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (str_track_rotation_x == nullptr)
	{
		str_track_rotation_x = CTrack::Alloc(select_object_clone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		str_track_rotation_x->GetCurve()->AddKey(BaseTime())->SetValue(str_track_rotation_x->GetCurve(), select_object_clone->GetRelRot().x);
		select_object_clone->InsertTrackSorted(str_track_rotation_x);
	}
	CTrack* strTrack_rotation_y = select_object_clone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (strTrack_rotation_y == nullptr)
	{
		strTrack_rotation_y = CTrack::Alloc(select_object_clone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		strTrack_rotation_y->GetCurve()->AddKey(BaseTime())->SetValue(strTrack_rotation_y->GetCurve(), select_object_clone->GetRelRot().y);
		select_object_clone->InsertTrackSorted(strTrack_rotation_y);
	}
	CTrack* str_track_rotation_z = select_object_clone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (str_track_rotation_z == nullptr)
	{
		str_track_rotation_z = CTrack::Alloc(select_object_clone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		str_track_rotation_z->GetCurve()->AddKey(BaseTime())->SetValue(str_track_rotation_z->GetCurve(), select_object_clone->GetRelRot().z);
		select_object_clone->InsertTrackSorted(str_track_rotation_z);
	}
	CTrack* str_track_AOV = select_object_clone->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	if (str_track_AOV == nullptr)
	{
		str_track_AOV = CTrack::Alloc(select_object_clone, DescID(CAMERAOBJECT_APERTURE));
		str_track_AOV->GetCurve()->AddKey(BaseTime())->SetValue(str_track_AOV->GetCurve(), ((CameraObject*)select_object_clone)->GetAperture());
		select_object_clone->InsertTrackSorted(str_track_AOV);
	}

	/* 确保生成成功 */
	if (str_track_position_x == nullptr || str_track_position_y == nullptr || str_track_position_z == nullptr || str_track_rotation_x == nullptr || strTrack_rotation_y == nullptr || str_track_rotation_z == nullptr || str_track_AOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}

	/* 获取曲线对象 */
	CCurve* str_curve_position_x = str_track_position_x->GetCurve();
	CCurve* str_curve_position_y = str_track_position_y->GetCurve();
	CCurve* str_curve_position_z = str_track_position_z->GetCurve();
	CCurve* str_curve_rotation_x = str_track_rotation_x->GetCurve();
	CCurve* str_curve_rotation_y = strTrack_rotation_y->GetCurve();
	CCurve* str_curve_rotation_z = str_track_rotation_z->GetCurve();
	CCurve* str_curve_AOV = str_track_AOV->GetCurve();

	/* 确保获取成功 */
	if (str_curve_position_x == nullptr || str_curve_position_y == nullptr || str_curve_position_z == nullptr || str_curve_rotation_x == nullptr || str_curve_rotation_y == nullptr || str_curve_rotation_z == nullptr || str_curve_AOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}

	/* 将所有参数的全部关键帧所在帧置入数组（frame_arr） */
	maxon::HashSet<MyBaseTime> frame_set;
	Int32		frame_count = str_curve_position_x->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_position_x->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = str_curve_position_y->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_position_y->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = str_curve_position_z->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_position_z->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = str_curve_rotation_x->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_rotation_x->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = str_curve_rotation_y->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_rotation_y->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = str_curve_rotation_z->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_rotation_z->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = str_curve_AOV->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(str_curve_AOV->GetKey(i)->GetTime())iferr_return;
	}

	/* 为目标对象生成动画轨迹 */
	CTrack* camera_track_position_x = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* camera_track_position_y = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* camera_track_position_z = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* camera_track_rotation_x = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* camera_track_rotation_y = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* camera_track_rotation_z = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* camera_track_distance = CTrack::Alloc(VMD_camera_distance, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* camera_track_AOV = CTrack::Alloc(VMD_camera_distance, DescID(CAMERAOBJECT_APERTURE));

	/* 确保生成成功 */
	if (camera_track_position_x == nullptr || camera_track_position_y == nullptr || camera_track_position_z == nullptr || camera_track_rotation_x == nullptr || camera_track_rotation_y == nullptr || camera_track_rotation_z == nullptr || camera_track_distance == nullptr || camera_track_AOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	CCurve* camera_curve_position_x = camera_track_position_x->GetCurve();
	CCurve* camera_curve_position_y = camera_track_position_y->GetCurve();
	CCurve* camera_curve_position_z = camera_track_position_z->GetCurve();
	CCurve* camera_curve_rotation_x = camera_track_rotation_x->GetCurve();
	CCurve* camera_curve_rotation_y = camera_track_rotation_y->GetCurve();
	CCurve* camera_curve_rotation_z = camera_track_rotation_z->GetCurve();
	CCurve* camera_curve_istance = camera_track_distance->GetCurve();
	CCurve* camera_curve_AOV = camera_track_AOV->GetCurve();

	/* 确保获取成功 */
	if (camera_curve_position_x == nullptr || camera_curve_position_y == nullptr || camera_curve_position_z == nullptr || camera_curve_rotation_x == nullptr || camera_curve_rotation_y == nullptr || camera_curve_rotation_z == nullptr || camera_curve_istance == nullptr || camera_curve_AOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	/* 将生成的动画轨迹插入目标对象 */
	VMD_camera->InsertTrackSorted(camera_track_position_x);
	VMD_camera->InsertTrackSorted(camera_track_position_y);
	VMD_camera->InsertTrackSorted(camera_track_position_z);
	VMD_camera->InsertTrackSorted(camera_track_rotation_x);
	VMD_camera->InsertTrackSorted(camera_track_rotation_y);
	VMD_camera->InsertTrackSorted(camera_track_rotation_z);
	VMD_camera_distance->InsertTrackSorted(camera_track_distance);
	VMD_camera_distance->InsertTrackSorted(camera_track_AOV);

	/* 确保每个参数在同一帧都注册了关键帧（根据frame_arr查找） */
	for (const BaseTime& frame_time : frame_set)
	{
		if (str_curve_position_x->FindKey(frame_time) == nullptr)
		{
			str_curve_position_x->AddKeyAdaptTangent(frame_time,false);
		}
		if (str_curve_position_y->FindKey(frame_time) == nullptr)
		{
			str_curve_position_y->AddKeyAdaptTangent(frame_time, false);
		}
		if (str_curve_position_z->FindKey(frame_time) == nullptr)
		{
			str_curve_position_z->AddKeyAdaptTangent(frame_time, false);
		}
		if (str_curve_rotation_x->FindKey(frame_time) == nullptr)
		{
			str_curve_rotation_x->AddKeyAdaptTangent(frame_time, false);
		}
		if (str_curve_rotation_y->FindKey(frame_time) == nullptr)
		{
			str_curve_rotation_y->AddKeyAdaptTangent(frame_time, false);
		}
		if (str_curve_rotation_z->FindKey(frame_time) == nullptr)
		{
			str_curve_rotation_z->AddKeyAdaptTangent(frame_time, false);
		}
		if (str_curve_AOV->FindKey(frame_time) == nullptr)
		{
			str_curve_AOV->AddKeyAdaptTangent(frame_time, false);
		}
		if (camera_curve_istance->FindKey(frame_time) == nullptr)
		{
			camera_curve_istance->AddKeyAdaptTangent(frame_time, false);
		}
	}

	/* 转换移动和旋转写入对象，添加关键帧数据 */
	for (const BaseTime& frame_time : frame_set)
	{
		camera_curve_position_x->AddKey(frame_time)->SetValue(camera_curve_position_x, str_curve_position_x->FindKey(frame_time)->GetValue());
		camera_curve_position_y->AddKey(frame_time)->SetValue(camera_curve_position_y, str_curve_position_y->FindKey(frame_time)->GetValue());
		camera_curve_position_z->AddKey(frame_time)->SetValue(camera_curve_position_z, str_curve_position_z->FindKey(frame_time)->GetValue());
		camera_curve_rotation_x->AddKey(frame_time)->SetValue(camera_curve_rotation_x, str_curve_rotation_x->FindKey(frame_time)->GetValue());
		camera_curve_rotation_y->AddKey(frame_time)->SetValue(camera_curve_rotation_y, str_curve_rotation_y->FindKey(frame_time)->GetValue());
		camera_curve_rotation_z->AddKey(frame_time)->SetValue(camera_curve_rotation_z, str_curve_rotation_z->FindKey(frame_time)->GetValue());
		camera_curve_AOV->AddKey(frame_time)->SetValue(camera_curve_AOV, str_curve_AOV->FindKey(frame_time)->GetValue());
		camera_curve_istance->AddKey(frame_time)->SetValue(camera_curve_istance, camera_curve_istance->FindKey(frame_time)->GetValue());
	}
	camera_curve_istance->AddKey(BaseTime(0, 30.))->SetValue(camera_curve_istance, setting.distance);

	Float		value_of_two_frames;
	Int32		time_of_two_frames;
	Int32		frame_on, next_frame_on;
	frame_count = frame_set.GetCount() - 1;// 只需循环第2到最后一个
	frame_set.Reset();
	const Float	Fps = doc->GetFps();
	/* 转换曲线并保存到对象 */
	Float key_left_x = 0., key_left_y = 0., key_right_x = 0., key_right_y = 0., next_key_left_x = 0., next_key_left_y = 0., next_key_right_x = 0., next_key_right_y = 0.;
	CKey* now_key = nullptr;
	CKey* next_key = nullptr;
	Int32 now_key_frame = 0;
	Int32 next_key_frame = 0;

	if (str_curve_position_x->GetKeyCount() != frame_count) {
		//第一帧
		now_key = str_curve_position_x->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = str_curve_position_x->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			str_curve_position_x->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
			str_curve_position_x->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
		}
		//最后一帧
		if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, str_curve_position_x->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = str_curve_position_x->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
			str_curve_position_x->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;

		}
	}
	if (str_curve_position_y->GetKeyCount() != frame_count) {
		//第一帧
		now_key = str_curve_position_y->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = str_curve_position_y->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			str_curve_position_y->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
			str_curve_position_y->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
		}
		//最后一帧
		if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, str_curve_position_y->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = str_curve_position_y->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
			str_curve_position_y->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
		}
	}
	if (str_curve_position_z->GetKeyCount() != frame_count) {
		//第一帧
		now_key = str_curve_position_z->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = str_curve_position_z->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			str_curve_position_z->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
			str_curve_position_z->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
		}
		//最后一帧
		if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, str_curve_position_z->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = str_curve_position_z->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
			str_curve_position_z->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
		}
	}

	switch (setting.use_rotation)
	{
	case 0:
		if (str_curve_rotation_x->GetKeyCount() != frame_count) {
			//第一帧
			now_key = str_curve_rotation_x->GetKey(0);
			now_key_frame = now_key->GetTime().GetFrame(30.);
			if (frame_count > 0) //第一帧不是最后一帧
			{
				next_key = str_curve_rotation_x->GetKey(1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				value_of_two_frames = next_key->GetValue() - now_key->GetValue();
				time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				str_curve_rotation_x->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
				str_curve_rotation_x->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
					return false;
			}
			//最后一帧
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, str_curve_rotation_x->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
				return false;
			}
			// 循环第2到最后一个
			for (Int32 key_index = 1; key_index < frame_count; key_index++)
			{
				now_key = next_key;
				now_key_frame = next_key_frame;
				next_key = str_curve_rotation_x->GetKey(key_index + 1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				value_of_two_frames = next_key->GetValue() - now_key->GetValue();
				time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
				str_curve_rotation_x->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
					return false;
			}
		}
		break;
	case 1:
		if (str_curve_rotation_y->GetKeyCount() != frame_count) {
			//第一帧
			now_key = str_curve_rotation_y->GetKey(0);
			now_key_frame = now_key->GetTime().GetFrame(30.);
			if (frame_count > 0) //第一帧不是最后一帧
			{
				next_key = str_curve_rotation_y->GetKey(1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				value_of_two_frames = next_key->GetValue() - now_key->GetValue();
				time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				str_curve_rotation_y->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
				str_curve_rotation_y->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
					return false;
			}
			//最后一帧
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, str_curve_rotation_y->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
				return false;
			}
			// 循环第2到最后一个
			for (Int32 key_index = 1; key_index < frame_count; key_index++)
			{
				now_key = next_key;
				now_key_frame = next_key_frame;
				next_key = str_curve_rotation_y->GetKey(key_index + 1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				value_of_two_frames = next_key->GetValue() - now_key->GetValue();
				time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
				str_curve_rotation_y->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
					return false;
			}
		}
		break;
	case 2:
		if (str_curve_rotation_z->GetKeyCount() != frame_count) {
			//第一帧
			now_key = str_curve_rotation_z->GetKey(0);
			now_key_frame = now_key->GetTime().GetFrame(30.);
			if (frame_count > 0) //第一帧不是最后一帧
			{
				next_key = str_curve_rotation_z->GetKey(1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				value_of_two_frames = next_key->GetValue() - now_key->GetValue();
				time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				str_curve_rotation_z->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
				str_curve_rotation_z->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
					return false;
			}
			//最后一帧
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, str_curve_rotation_z->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
				return false;
			}
			// 循环第2到最后一个
			for (Int32 key_index = 1; key_index < frame_count; key_index++)
			{
				now_key = next_key;
				now_key_frame = next_key_frame;
				next_key = str_curve_rotation_z->GetKey(key_index + 1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				value_of_two_frames = next_key->GetValue() - now_key->GetValue();
				time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
				str_curve_rotation_z->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
				if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
					return false;
			}
		}
		break;
	default:
		break;
	}
	if (str_curve_rotation_x->GetKeyCount() != frame_count) {
		//第一帧
		now_key = str_curve_AOV->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = str_curve_AOV->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			str_curve_AOV->GetTangents(0, &key_left_y, &key_right_y, &key_left_x, &key_right_x);
			str_curve_AOV->GetTangents(1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
		}
		//最后一帧
		if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, str_curve_AOV->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}

		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = str_curve_AOV->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			value_of_two_frames = next_key->GetValue() - now_key->GetValue();
			time_of_two_frames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			key_left_x = next_key_left_x, key_left_y = next_key_left_y, key_right_x = next_key_right_x, key_right_y = next_key_right_y;
			str_curve_AOV->GetTangents(key_index + 1, &next_key_left_y, &next_key_right_y, &next_key_left_x, &next_key_right_x);
			if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(key_right_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(key_right_y * 127.0 / value_of_two_frames)), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_x * Fps * 127.0 / Float(time_of_two_frames))), maxon::SafeConvert<UChar>(maxon::Abs(next_key_left_y * 127.0 / value_of_two_frames)))))
				return false;
			
		}
	}
	frame_count += 1;
	for (Int32 key_index = 0; key_index < frame_count; key_index++)
	{
		// 距离没有曲线，顺便在循环里设置线性曲线
		if (!VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_DCURVE, now_key_frame, VMDInterpolator()))
			return false;
	}

	EventAdd();
	if (!VMD_camera_data->UpdateAllInterpolator())
		return(nullptr);
	doc->SetTime(BaseTime(1));
	doc->SetTime(BaseTime());
	return(maxon::Result<BaseObject*>(VMD_camera));
}


Bool mmd::OMMDCamera::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return(false);
	};
	if (!hf->ReadInt32(&this->prev_frame))
		return(false);
	if (!hf->ReadInt32(&this->prev_interpolator_type))
		return(false);
	Int32	count = 0;
	Int	size = sizeof(mmd::VMDInterpolator);
	void* data;
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_X_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_Y_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_Z_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_R_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_D_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_V_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count))
		return(false);
	for (Int32 i = 0; i < count; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_A_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}

	return(SUPER::Read(node, hf, level));
}


Bool mmd::OMMDCamera::Write(GeListNode* node, HyperFile* hf)
{
	if (!hf->WriteInt32(this->prev_frame))
		return(false);
	if (!hf->WriteInt32(this->prev_interpolator_type))
		return(false);
	Int32 count = this->interpolator_X_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_X_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_X_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count = this->interpolator_Y_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_Y_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_Y_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count = this->interpolator_Z_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_Z_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_Z_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count = this->interpolator_R_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_R_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_R_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count = this->interpolator_D_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_D_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_D_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count = this->interpolator_V_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_V_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_V_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count = this->interpolator_A_map.GetCount();
	if (!hf->WriteInt32(count))
		return(false);
	for (auto i : this->interpolator_A_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_A_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}

	return(SUPER::Write(node, hf));
}


Bool mmd::OMMDCamera::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	iferr_scope_handler{
		return(false);
	};
	OMMDCamera* const destObject = static_cast<OMMDCamera*>(dest);
	if (destObject == nullptr)
	{
		return(false);
	}
	destObject->prev_frame = this->prev_frame;
	destObject->prev_interpolator_type = this->prev_interpolator_type;
	destObject->interpolator_X_map.CopyFrom(this->interpolator_X_map) iferr_return;
	destObject->interpolator_Y_map.CopyFrom(this->interpolator_Y_map) iferr_return;
	destObject->interpolator_Z_map.CopyFrom(this->interpolator_Z_map) iferr_return;
	destObject->interpolator_R_map.CopyFrom(this->interpolator_R_map) iferr_return;
	destObject->interpolator_D_map.CopyFrom(this->interpolator_D_map) iferr_return;
	destObject->interpolator_V_map.CopyFrom(this->interpolator_V_map) iferr_return;
	destObject->interpolator_A_map.CopyFrom(this->interpolator_A_map) iferr_return;
	return(SUPER::CopyTo(dest, snode, dnode, flags, trn));
}


inline maxon::Vector4d32 mmd::VMDAnimation::EulerToQuaternion(maxon::Vector& euler) {

	// pitch(H), roll(-P), yaw(Z)
	const Float sx = sin(-euler.y * 0.5);
	const Float sy = sin(euler.x * 0.5);
	const Float sz = sin(euler.z * 0.5);
	const Float cx = cos(-euler.y * 0.5);
	const Float cy = cos(euler.x * 0.5);
	const Float cz = cos(euler.z * 0.5);

	const Float w = (cz * cy * cx) + (sz * sy * sx);
	const Float x = (cz * cy * sx) + (sz * sy * cx);
	const Float y = (sz * cy * sx) - (cz * sy * cx);
	const Float z = (cz * sy * sx) - (sz * cy * cx);

	return maxon::Vector4d32(x, y, z, w);
}


inline maxon::Vector mmd::VMDAnimation::QuaternionToEuler(maxon::Vector4d32& quaternion)
{
	//pitch(y - axis rotation)
	const Float sinr_cosp = 2.0 * (quaternion.w * quaternion.y + quaternion.x * quaternion.z);
	const Float cosr_cosp = 1.0 - (2.0 * (quaternion.x * quaternion.x + quaternion.y * quaternion.y));
	const Float pitch = -atan2(sinr_cosp, cosr_cosp);

	//yaw(z - axis rotation)
	const Float siny_cosp = 2.0 * (-quaternion.w * quaternion.z - quaternion.x * quaternion.y);
	const Float cosy_cosp = 1.0 - (2.0 * (quaternion.x * quaternion.x + quaternion.z * quaternion.z));
	const Float yaw = atan2(siny_cosp, cosy_cosp);
	
	//roll(x - axis rotation)
	Float roll = 0.0;
	const Float sinp = 2.0 * (quaternion.z * quaternion.y - quaternion.w * quaternion.x);
	if (sinp >= 1.0)
	{
		roll = -PI05; // use 90 degrees if out of range
	}
	else if (sinp <= -1.0)
	{
		roll = PI05;
	}
	else {
		roll = -asin(sinp);
	}

	//fixing the x rotation, part 1
	if (quaternion.x * quaternion.x > 0.5f || quaternion.w < 0.0f)
	{
		if (quaternion.x < 0.0f)
		{
			roll = -PI - roll;
		}
		else
		{
			roll = PI * copysign(1.0, quaternion.w) - roll;
		}
	}

	//fixing the x rotation, part 2
	if (roll > PI05) 
	{
		roll = PI - roll;
	}
	else if (roll < -PI05)
	{
		roll = -PI - roll;
	}
	return maxon::Vector(pitch, -roll, yaw);// HPB
}


maxon::Result<void> mmd::VMDAnimation::LoadFromFile(Filename& fn)
{
	iferr_scope;

	AutoAlloc<BaseFile>	file;
	if (file == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR)));
	}

	Char VMD_version[30]{ 0 };
	Char VMD_model_name[20]{ 0 };

	if (!file->ReadBytes(VMD_version, 30))
		return(maxon::Error());
	if (!strncmp(VMD_version, "Vocaloid Motion Data", 21))
	{
		if (!file->ReadBytes(VMD_model_name, 10))
			return(maxon::Error());
		EncodingConversion::SJIStoUTF8(VMD_model_name, this->ModelName);
		if (this->ModelName.LexComparePart(L"\u30ab\u30e1\u30e9\u30fb\u7167\u660e"_s, 12, 0) == 0) /* カメラ・照明 */
		{
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
	}
	else if (!strncmp(VMD_version, "Vocaloid Motion Data 0002", 26))
	{
		if (!file->ReadBytes(VMD_model_name, 20))
			return(maxon::Error());
		EncodingConversion::SJIStoUTF8(VMD_model_name, this->ModelName);
		if (this->ModelName.LexComparePart(L"\u30ab\u30e1\u30e9\u30fb\u7167\u660e"_s, 12, 0) == 0) /* カメラ・照明 */
		{
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
	}
	else {
		GePrint("File corruption or unknown version"_s);
		MessageDialog("Import failed; File corruption or unknown version"_s);
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "File corruption or unknown version"_s));
	}
	if (file->GetPosition() < file->GetLength()) {
		register UInt32 motion_frame_number = 0;
		if (!file->ReadUInt32(&(motion_frame_number)))
			return(maxon::Error());
		while (motion_frame_number--)
		{
			/* 111 bytes */
			mmd::VMD_Motion* motion_frame = NewObj(mmd::VMD_Motion) iferr_return;
			if (motion_frame == nullptr)
				return(maxon::Error());
			Char bone_name[15]{ 0 };
			if (!file->ReadBytes(bone_name, 15))
				return(maxon::Error());
			if (!file->ReadUInt32(&(motion_frame->frame_no)))
				return(maxon::Error());
			if (!file->ReadBytes(&(motion_frame->position), sizeof(Vector32)))
				return(maxon::Error());
			if (!file->ReadBytes(&(motion_frame->rotation), sizeof(Vector4d32)))
				return(maxon::Error());
			if (!motion_frame->interpolator_x.ReadBoneInterpolator(file))
				return(maxon::Error());
			if (!motion_frame->interpolator_y.ReadBoneInterpolator(file))
				return(maxon::Error());
			if (!motion_frame->interpolator_z.ReadBoneInterpolator(file))
				return(maxon::Error());
			if (!motion_frame->interpolator_r.ReadBoneInterpolator(file))
				return(maxon::Error());
			EncodingConversion::SJIStoUTF8(bone_name, motion_frame->bone_name);
			this->motion_frames.AppendPtr(motion_frame) iferr_return;
		}
	}
	if (file->GetPosition() < file->GetLength()) {
		register UInt32 morph_frame_number = 0;
		if (!file->ReadUInt32(&(morph_frame_number)))
			return(maxon::Error());
		while (morph_frame_number--)
		{
			/* 23 bytes */
			mmd::VMD_Morph* morph_frame = NewObj(mmd::VMD_Morph) iferr_return;
			if (morph_frame == nullptr)
				return(maxon::Error());
			Char		morph_name[15]{ 0 };
			if (!file->ReadBytes(morph_name, 15))
				return(maxon::Error());
			if (!file->ReadUInt32(&morph_frame->frame_no))
				return(maxon::Error());
			if (!file->ReadFloat32(&morph_frame->weight))
				return(maxon::Error());
			EncodingConversion::SJIStoUTF8(morph_name, morph_frame->morph_name);
			this->morph_frames.AppendPtr(morph_frame) iferr_return;
		}
	}
	if (file->GetPosition() < file->GetLength()) {
		register UInt32 camera_frame_number = 0;
		if (!file->ReadUInt32(&(camera_frame_number)))
			return(maxon::Error());
		while (camera_frame_number--)
		{
			/* 61 bytes */
			mmd::VMD_Camera* camera_frame = NewObj(mmd::VMD_Camera) iferr_return;
			if (camera_frame == nullptr)
				return(maxon::Error());
			if (!file->ReadUInt32(&(camera_frame->frame_no)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(camera_frame->distance)))
				return(maxon::Error());
			if (!file->ReadVector32(&(camera_frame->position)))
				return(maxon::Error());
			if (!file->ReadBytes(&(camera_frame->rotation), sizeof(Vector32)))
				return(maxon::Error());
			if (!camera_frame->interpolator_x.ReadCameraInterpolator(file))
				return(maxon::Error());
			if (!camera_frame->interpolator_y.ReadCameraInterpolator(file))
				return(maxon::Error());
			if (!camera_frame->interpolator_z.ReadCameraInterpolator(file))
				return(maxon::Error());
			if (!camera_frame->interpolator_r.ReadCameraInterpolator(file))
				return(maxon::Error());
			if (!camera_frame->interpolator_d.ReadCameraInterpolator(file))
				return(maxon::Error());
			if (!camera_frame->interpolator_v.ReadCameraInterpolator(file))
				return(maxon::Error());
			if (!file->ReadUInt32(&(camera_frame->viewing_angle)))
				return(maxon::Error());
			if (!file->ReadUChar(&(camera_frame->perspective)))
				return(maxon::Error());
			this->camera_frames.AppendPtr(camera_frame) iferr_return;
		}
	}
	if (file->GetPosition() < file->GetLength()) {
		register UInt32 light_frame_number = 0;
		if (!file->ReadUInt32(&(light_frame_number)))
			return(maxon::Error());
		while (light_frame_number--)
		{
			/* 28 bytes */
			mmd::VMD_Light* light_frame = NewObj(mmd::VMD_Light) iferr_return;
			if (light_frame == nullptr)
				return(maxon::Error());
			if (!file->ReadBytes(light_frame, sizeof(mmd::VMD_Light)))
				return(maxon::Error());
			this->light_frames.AppendPtr(light_frame) iferr_return;
		}
	}
	if (file->GetPosition() < file->GetLength()) {
		register UInt32 shadow_frame_number = 0;
		if (!file->ReadUInt32(&(shadow_frame_number)))
			return(maxon::Error());
		while (shadow_frame_number--)
		{
			/* 12 bytes */
			mmd::VMD_Shadow* shadow_frame = NewObj(mmd::VMD_Shadow) iferr_return;
			if (shadow_frame == nullptr)
				return(maxon::Error());
			if (!file->ReadBytes(shadow_frame, sizeof(mmd::VMD_Shadow)))
				return(maxon::Error());
			this->shadow_frames.AppendPtr(shadow_frame) iferr_return;
		}
	}
	if (file->GetPosition() < file->GetLength()) {
		register UInt32 model_frame_number = 0;
		if (!file->ReadUInt32(&(model_frame_number)))
			return(maxon::Error());
		while (model_frame_number--)
		{
			mmd::VMD_Model* model_frame = NewObj(mmd::VMD_Model) iferr_return;
			if (model_frame == nullptr)
				return(maxon::Error());
			if (!file->ReadUInt32(&model_frame->frame_no))
				return(maxon::Error());
			if (!file->ReadBool(&model_frame->show))
				return(maxon::Error());
			UInt32 ik_info_number = 0;
			if (!file->ReadUInt32(&ik_info_number))
				return(maxon::Error());
			while (ik_info_number--)
			{
				Bool	ik_enable;
				Char	ik_name[20]{ 0 };
				if (!file->ReadBytes(ik_name, 20))
					return(maxon::Error());
				if (!file->ReadBool(&ik_enable))
					return(maxon::Error());
				String ik_name_;
				EncodingConversion::SJIStoUTF8(ik_name, ik_name_);
				model_frame->ik_Infos.AppendPtr(NewObj(mmd::VMD_IkInfo, ik_name_, ik_enable).GetValue()) iferr_return;
			}
			this->model_frames.AppendPtr(model_frame) iferr_return;
		}
	}
	
	return(maxon::OK);
}


maxon::Result<void> mmd::VMDAnimation::SaveToFile(Filename& fn)
{
	iferr_scope;

	AutoAlloc<BaseFile>	file;
	if (file == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	if (!file->Open(fn, FILEOPEN::WRITE, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA))
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR)));
	}

	const Char VMDVersion[30] = "Vocaloid Motion Data 0002\0\0\0\0";
	if (!file->WriteBytes(VMDVersion, 30))
		return(maxon::Error());
	maxon::AutoMem<maxon::Char> VMDModelName = NewMemClear(maxon::Char, (this->ModelName.GetCStringLen(STRINGENCODING::UTF8) + 1) * 2) iferr_return;
	EncodingConversion::UTF8toSJIS(this->ModelName, VMDModelName);
	if (!file->WriteBytes(VMDModelName, 20))
		return(maxon::Error());
	register UInt32 motion_frame_number = this->motion_frames.GetCount();
	if (!file->WriteUInt32(motion_frame_number))
		return(maxon::Error());
	while (motion_frame_number--)
	{
		mmd::VMD_Motion motion_frame = (this->motion_frames)[motion_frame_number];
		maxon::AutoMem<maxon::Char> bone_name = NewMemClear(maxon::Char, (motion_frame.bone_name.GetCStringLen(STRINGENCODING::UTF8) + 1) * 2) iferr_return;
		EncodingConversion::UTF8toSJIS(motion_frame.bone_name, bone_name);
		if (!file->WriteBytes(bone_name, 15))
			return(maxon::Error());
		if (!file->WriteUInt32(motion_frame.frame_no))
			return(maxon::Error());
		if (!file->WriteBytes(&(motion_frame.position), sizeof(Vector32)))
			return(maxon::Error());
		if (!file->WriteBytes(&(motion_frame.rotation), sizeof(Vector4d32)))
			return(maxon::Error());
		if (!motion_frame.interpolator_x.WriteBoneInterpolator(file))
			return(maxon::Error());
		if (!motion_frame.interpolator_y.WriteBoneInterpolator(file))
			return(maxon::Error());
		if (!motion_frame.interpolator_z.WriteBoneInterpolator(file))
			return(maxon::Error());
		if (!motion_frame.interpolator_r.WriteBoneInterpolator(file))
			return(maxon::Error());
	}
	register UInt32 morph_frame_number = this->morph_frames.GetCount();
	if (!file->WriteUInt32(morph_frame_number))
		return(maxon::Error());
	while (morph_frame_number--)
	{
		mmd::VMD_Morph morph_frame = (this->morph_frames)[morph_frame_number];
		maxon::AutoMem<maxon::Char> morph_name = NewMemClear(maxon::Char, (morph_frame.morph_name.GetCStringLen(STRINGENCODING::UTF8) + 1) * 2) iferr_return;
		EncodingConversion::UTF8toSJIS(morph_frame.morph_name, morph_name);
		if (!file->WriteBytes(morph_name, 15))
			return(maxon::Error());
		if (!file->WriteUInt32(morph_frame.frame_no))
			return(maxon::Error());
		if (!file->WriteFloat32(morph_frame.weight))
			return(maxon::Error());
	}
	register UInt32 camera_frame_number = this->camera_frames.GetCount();
	if (!file->WriteUInt32(camera_frame_number))
		return(maxon::Error());
	while (camera_frame_number--)
	{
		mmd::VMD_Camera camera_frame = (this->camera_frames)[camera_frame_number];
		if (!file->WriteUInt32(camera_frame.frame_no))
			return(maxon::Error());
		if (!file->WriteFloat32(camera_frame.distance))
			return(maxon::Error());
		if (!file->WriteBytes(&(camera_frame.position), sizeof(Vector32)))
			return(maxon::Error());
		if (!file->WriteBytes(&(camera_frame.rotation), sizeof(Vector32)))
			return(maxon::Error());
		if (!camera_frame.interpolator_x.WriteCameraInterpolator(file))
			return(maxon::Error());
		if (!camera_frame.interpolator_y.WriteCameraInterpolator(file))
			return(maxon::Error());
		if (!camera_frame.interpolator_z.WriteCameraInterpolator(file))
			return(maxon::Error());
		if (!camera_frame.interpolator_r.WriteCameraInterpolator(file))
			return(maxon::Error());
		if (!camera_frame.interpolator_d.WriteCameraInterpolator(file))
			return(maxon::Error());
		if (!camera_frame.interpolator_v.WriteCameraInterpolator(file))
			return(maxon::Error());
		if (!file->WriteUInt32(camera_frame.viewing_angle))
			return(maxon::Error());
		if (!file->WriteUChar(camera_frame.perspective))
			return(maxon::Error());
	}
	register UInt32 light_frame_number = this->light_frames.GetCount();
	if (!file->WriteUInt32(light_frame_number))
		return(maxon::Error());
	while(light_frame_number--)
	{
		if (!file->WriteBytes(&((this->light_frames)[light_frame_number]), sizeof(mmd::VMD_Light)))
			return(maxon::Error());
	}
	register UInt32 shadow_frame_number = this->shadow_frames.GetCount();
	if (!file->WriteUInt32(shadow_frame_number))
		return(maxon::Error());
	while (shadow_frame_number--)
	{
		if (!file->WriteBytes(&((this->shadow_frames)[shadow_frame_number]), sizeof(mmd::VMD_Shadow)))
			return(maxon::Error());
	}
	register UInt32 model_frame_number = this->model_frames.GetCapacityCount();
	if (!file->WriteUInt32(model_frame_number))
		return(maxon::Error());
	while (model_frame_number--)
	{
		const mmd::VMD_Model& model_frame = (this->model_frames)[model_frame_number];
		if (!file->WriteUInt32(model_frame.frame_no))
			return(maxon::Error());
		if (!file->WriteBool(model_frame.show))
			return(maxon::Error());
		UInt32 ikInfoCount = model_frame.ik_Infos.GetCount();
		if (!file->WriteUInt32(ikInfoCount))
			return(maxon::Error());
		while (ikInfoCount--)
		{
			VMD_IkInfo ikInfo = model_frame.ik_Infos[ikInfoCount];
			maxon::AutoMem<maxon::Char> ik_name_ = NewMemClear(maxon::Char, (ikInfo.name.GetCStringLen(STRINGENCODING::UTF8) + 1) * 2) iferr_return;
			EncodingConversion::UTF8toSJIS(ikInfo.name, ik_name_);
			if (!file->WriteBytes(ik_name_, 20))
				return(maxon::Error());
			if (!file->WriteUChar(ikInfo.enable))
				return(maxon::Error());
		}
	}
	return(maxon::OK);
}


maxon::Result<void> mmd::VMDAnimation::FromFileImportCamera(VMD_Camera_import_settings setting)
{
	iferr_scope;
	Filename		fn;
	BaseDocument* doc;
	if (setting.doc == nullptr)
	{
		doc = GetActiveDocument();
		if (doc == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
	}
	else {
		doc = setting.doc;
	}
	if (setting.fn == Filename())
	{
		if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE)))
		{
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
	}
	else {
		fn = setting.fn;
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s))))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		return(maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR)));
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	maxon::UniqueRef<mmd::VMDAnimation> mmd_animation = NewObj(mmd::VMDAnimation)iferr_return;

	iferr(mmd_animation->LoadFromFile(fn))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR)));
	}
	if (mmd_animation->IsCamera)
	{
		doc->StartUndo();

		BaseObject* VMD_camera = BaseObject::Alloc(ID_O_MMD_CAMERA);
		if (VMD_camera == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		VMD_camera->SetName(fn.GetFileString());
		doc->InsertObject(VMD_camera, nullptr, nullptr);
		mmd::OMMDCamera* VMD_camera_data = VMD_camera->GetNodeData<OMMDCamera>();
		VMD_camera_data->CameraInit();
		BaseObject* VMD_camera_distance = VMD_camera_data->GetCamera();

		CTrack* camera_track_position_x = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		CTrack* camera_track_position_y = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		CTrack* camera_track_position_z = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		CTrack* camera_track_rotation_x = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		CTrack* camera_track_rotation_y = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		CTrack* camera_track_rotation_z = CTrack::Alloc(VMD_camera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		CTrack* camera_track_distance = CTrack::Alloc(VMD_camera_distance, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		CTrack* camera_track_AOV = CTrack::Alloc(VMD_camera_distance, DescID(CAMERAOBJECT_APERTURE));
		if (camera_track_position_x == nullptr || camera_track_position_y == nullptr || camera_track_position_z == nullptr || camera_track_rotation_x == nullptr || camera_track_rotation_y == nullptr || camera_track_rotation_z == nullptr || camera_track_distance == nullptr || camera_track_AOV == nullptr) /* 确保生成成功 */
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		CCurve* camera_curve_position_x = camera_track_position_x->GetCurve();
		CCurve* camera_curve_position_y = camera_track_position_y->GetCurve();
		CCurve* camera_curve_position_z = camera_track_position_z->GetCurve();
		CCurve* camera_curve_rotation_x = camera_track_rotation_x->GetCurve();
		CCurve* camera_curve_rotation_y = camera_track_rotation_y->GetCurve();
		CCurve* camera_curve_rotation_z = camera_track_rotation_z->GetCurve();
		CCurve* camera_curve_distance = camera_track_distance->GetCurve();
		CCurve* camera_curve_AOV = camera_track_AOV->GetCurve();
		if (camera_curve_position_x == nullptr || camera_curve_position_y == nullptr || camera_curve_position_z == nullptr || camera_curve_rotation_x == nullptr || camera_curve_rotation_y == nullptr || camera_curve_rotation_z == nullptr || camera_curve_distance == nullptr || camera_curve_AOV == nullptr) /* 确保获取成功 */
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
		VMD_camera->InsertTrackSorted(camera_track_position_x);
		VMD_camera->InsertTrackSorted(camera_track_position_y);
		VMD_camera->InsertTrackSorted(camera_track_position_z);
		VMD_camera->InsertTrackSorted(camera_track_rotation_x);
		VMD_camera->InsertTrackSorted(camera_track_rotation_y);
		VMD_camera->InsertTrackSorted(camera_track_rotation_z);
		VMD_camera_distance->InsertTrackSorted(camera_track_distance);
		VMD_camera_distance->InsertTrackSorted(camera_track_AOV);

		const BaseTime kMaxTime = maxon::Max(doc->GetMaxTime(), BaseTime((mmd_animation->camera_frames.End() - 1).GetPtr()->frame_no, 30.));
		BaseTime	key_on_time = BaseTime(0, 30.);
		Int32		key_on_frame = 0;
		mmd::VMD_Camera now_camera_frame, next_camera_frame;
		const Int	camera_frame_number = mmd_animation->camera_frames.GetCount();
		for (Int camera_frame_index = 0; camera_frame_index < camera_frame_number; camera_frame_index++)
		{
			StatusSetText("Import camera..."_s);
			StatusSetSpin();
			if (camera_frame_index == 0 && camera_frame_number != 1)
			{
				now_camera_frame = mmd_animation->camera_frames[camera_frame_index];
				next_camera_frame = mmd_animation->camera_frames[camera_frame_index + 1];
			}
			else if (camera_frame_index == camera_frame_number - 1)
			{
				now_camera_frame = next_camera_frame;
			}
			else {
				now_camera_frame = next_camera_frame;
				next_camera_frame = mmd_animation->camera_frames[camera_frame_index + 1];
			}
			key_on_frame = Int32(now_camera_frame.frame_no) + maxon::SafeConvert<Int32>(setting.time_offset);
			key_on_time = BaseTime(key_on_frame, 30.);

			CKey* camera_key_position_x = CKey::Alloc();      /* _position_x */
			camera_key_position_x->SetTime(camera_curve_position_x, key_on_time);
			camera_key_position_x->SetValue(camera_curve_position_x, now_camera_frame.position.x * setting.position_multiple);
			camera_key_position_x->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_position_x->InsertKey(camera_key_position_x);
			VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, key_on_frame,std::move(now_camera_frame.interpolator_x));

			CKey* camera_key_position_y = CKey::Alloc();      /* _position_y */
			camera_key_position_y->SetTime(camera_curve_position_y, key_on_time);
			camera_key_position_y->SetValue(camera_curve_position_y, now_camera_frame.position.y * setting.position_multiple);
			camera_key_position_y->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_position_y->InsertKey(camera_key_position_y);
			VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, key_on_frame, std::move(now_camera_frame.interpolator_y));

			CKey* camera_key_position_z = CKey::Alloc();      /* _position_z */
			camera_key_position_z->SetTime(camera_curve_position_z, key_on_time);
			camera_key_position_z->SetValue(camera_curve_position_z, now_camera_frame.position.z * setting.position_multiple);
			camera_key_position_z->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_position_z->InsertKey(camera_key_position_z);
			VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, key_on_frame, std::move(now_camera_frame.interpolator_z));

			CKey* camera_key_rotation_x = CKey::Alloc();      /* RH(y) */
			camera_key_rotation_x->SetTime(camera_curve_rotation_x, key_on_time);
			camera_key_rotation_x->SetValue(camera_curve_rotation_x, now_camera_frame.rotation.y);
			camera_key_rotation_x->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_rotation_x->InsertKey(camera_key_rotation_x);

			CKey* camera_key_rotation_y = CKey::Alloc();      /* RP(x) */
			camera_key_rotation_y->SetTime(camera_curve_rotation_y, key_on_time);
			camera_key_rotation_y->SetValue(camera_curve_rotation_y, now_camera_frame.rotation.x);
			camera_key_rotation_y->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_rotation_y->InsertKey(camera_key_rotation_y);

			CKey* camera_key_rotation_z = CKey::Alloc();      /* RB(z) */
			camera_key_rotation_z->SetTime(camera_curve_rotation_z, key_on_time);
			camera_key_rotation_z->SetValue(camera_curve_rotation_z, now_camera_frame.rotation.z);
			camera_key_rotation_z->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_rotation_z->InsertKey(camera_key_rotation_z);
			VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, key_on_frame, std::move(now_camera_frame.interpolator_r));

			CKey* camera_key_distance = CKey::Alloc();;
			camera_key_distance->SetTime(camera_curve_distance, key_on_time);
			camera_key_distance->SetValue(camera_curve_distance, now_camera_frame.distance * setting.position_multiple);
			camera_key_distance->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_distance->InsertKey(camera_key_distance);
			VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_DCURVE, key_on_frame, std::move(now_camera_frame.interpolator_d));

			CKey* camera_key_AOV = CKey::Alloc();
			camera_key_AOV->SetTime(camera_curve_AOV, key_on_time);
			camera_key_AOV->SetValue(camera_curve_AOV, now_camera_frame.viewing_angle);
			camera_key_AOV->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			camera_curve_AOV->InsertKey(camera_key_AOV);
			VMD_camera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, key_on_frame, std::move(now_camera_frame.interpolator_v));
		}
		VMD_camera_data->UpdateAllInterpolator();
		timing.Stop();
		StatusClear();
		doc->SetMaxTime(kMaxTime);
		doc->SetLoopMaxTime(kMaxTime);
		EventAdd(EVENT::NONE);
		doc->SetTime(BaseTime(1., 30.));
		doc->SetTime(BaseTime(0., 30.));
		doc->EndUndo();
		MessageDialog(GeLoadString(IDS_MES_IMPORT_OK, maxon::String::IntToString(camera_frame_number), String::FloatToString(timing.GetMilliseconds())));
		return(maxon::OK);
	}
	else {
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR)));
	}
}


maxon::Result<void> mmd::VMDAnimation::FromDocumentExportCamera(VMD_Camera_export_settings setting)
{
	iferr_scope;
	Filename		fn;
	BaseDocument* doc = GetActiveDocument();
	setting.position_multiple = 1.0 / setting.position_multiple;
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	BaseObject* select_object = doc->GetActiveObject();
	if (select_object == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	doc->SetTime(BaseTime(0.));
	BaseObject* camera_obj = nullptr;
	AutoFree<BaseObject> camera_object_tmp;					  /*转化对象自动销毁 */

	/*选择对象为普通摄像机则转化 */
	if (select_object->GetType() == Ocamera)               
	{
		auto res = OMMDCamera::ConversionCamera(VMD_Conversion_Camera_settings{ 0., setting.use_rotation, select_object });
		camera_object_tmp.Assign(res.GetValue());
		iferr(res.GetError()) 
			return(maxon::Error());
		camera_obj = camera_object_tmp;
	}
	/*选择对象为vmd摄像机则直接使用 */
	else if(select_object->GetType() == ID_O_MMD_CAMERA) 
	{
		camera_obj = select_object;
	}
	/*都不是则返回错误 */
	else 
	{ 
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::SAVE, GeLoadString(IDS_MES_SAVEFILE), "vmd"_s))
	{
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	
	/* 获取内置数据 */
	mmd::OMMDCamera* VMD_camera_data = camera_obj->GetNodeData<OMMDCamera>();
	if (VMD_camera_data == nullptr)
	{
		return(maxon::Error());
	}
	BaseObject* VMD_camera_distance = VMD_camera_data->GetCamera();
	maxon::TimeValue	timing = maxon::TimeValue::GetTime();
	CTrack* camera_track_position_x = camera_obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (camera_track_position_x == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_position_x"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_position_x"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* camera_track_position_y = camera_obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (camera_track_position_y == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_position_y"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_position_y"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* camera_track_position_z = camera_obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
	if (camera_track_position_z == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_position_z"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_position_z"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* camera_track_rotation_x = camera_obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (camera_track_rotation_x == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_rotation_x"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_rotation_x"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* camera_track_rotation_y = camera_obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (camera_track_rotation_y == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_rotation_y"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_rotation_y"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* camera_track_rotation_z = camera_obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (camera_track_rotation_z == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_rotation_z"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "_rotation_z"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* camera_track_frame_on = camera_obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));
	if (camera_track_frame_on == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Frame_on"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Frame_on"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackDistance = VMD_camera_distance->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
	if (CameraTrackDistance == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackAOV = VMD_camera_distance->FindCTrack(DescID(DescLevel(CAMERAOBJECT_APERTURE, DTYPE_REAL, 0)));
	if (CameraTrackAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "AOV"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CCurve* camera_curve_position_x = camera_track_position_x->GetCurve();
	CCurve* camera_curve_position_y = camera_track_position_y->GetCurve();
	CCurve* camera_curve_position_z = camera_track_position_z->GetCurve();
	CCurve* camera_curve_rotation_x = camera_track_rotation_x->GetCurve();
	CCurve* camera_curve_rotation_y = camera_track_rotation_y->GetCurve();
	CCurve* camera_curve_rotation_z = camera_track_rotation_z->GetCurve();
	CCurve* camera_curve_distance = CameraTrackDistance->GetCurve();
	CCurve* camera_curve_AOV = CameraTrackAOV->GetCurve();	
	CCurve* camera_curve_frame_on = camera_track_frame_on->GetCurve();
	const Int32 kFps = doc->GetFps();
	maxon::UniqueRef<mmd::VMDAnimation> mmd_animation = NewObj(mmd::VMDAnimation)iferr_return;
	if (setting.use_bake == true) {
		register const BaseTime kEndFrame = maxon::Max(maxon::Max(maxon::Max(maxon::Max(maxon::Max(maxon::Max(maxon::Max(
			camera_curve_position_x->GetEndTime(),
			camera_curve_position_y->GetEndTime()),
			camera_curve_position_z->GetEndTime()),
			camera_curve_rotation_x->GetEndTime()),
			camera_curve_rotation_y->GetEndTime()),
			camera_curve_rotation_z->GetEndTime()),
			camera_curve_distance->GetEndTime()),
			camera_curve_AOV->GetEndTime());
		register const BaseTime kTimeOne = BaseTime(1, kFps);
		for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
		{
			StatusSetSpin();
			mmd::VMD_Camera* camera_frame = NewObj(mmd::VMD_Camera)iferr_return;
			camera_frame->frame_no = time_on.GetFrame(kFps) + setting.time_offset;
			camera_frame->position = Vector32(camera_curve_position_x->GetValue(time_on) * setting.position_multiple, camera_curve_position_y->GetValue(time_on) * setting.position_multiple, camera_curve_position_z->GetValue(time_on) * setting.position_multiple);
			camera_frame->rotation = Vector32(camera_curve_rotation_y->GetValue(time_on), camera_curve_rotation_x->GetValue(time_on), camera_curve_rotation_z->GetValue(time_on)); /*H(y) P(x) B(z)*/
			camera_frame->distance = Float32(camera_curve_distance->GetValue(time_on) * setting.position_multiple);
			camera_frame->viewing_angle = maxon::SafeConvert<UInt32>(camera_curve_AOV->GetValue(time_on));
			mmd_animation->camera_frames.AppendPtr(camera_frame)iferr_return;
		}
	}
	else {
		register const Int32 kFrameCount = camera_curve_frame_on->GetKeyCount();
		for (register Int32 frame_index = 0; frame_index < kFrameCount; frame_index++)
		{
			StatusSetSpin();
			mmd::VMD_Camera* camera_frame = NewObj(mmd::VMD_Camera)iferr_return;
			Int32 Frame_on = camera_curve_frame_on->GetKey(frame_index)->GetValue();
			camera_frame->frame_no = Frame_on + setting.time_offset;
			camera_frame->position = Vector32(camera_curve_position_x->GetKey(frame_index)->GetValue() * setting.position_multiple, camera_curve_position_y->GetKey(frame_index)->GetValue() * setting.position_multiple, camera_curve_position_z->GetKey(frame_index)->GetValue() * setting.position_multiple);
			camera_frame->rotation = Vector32(camera_curve_rotation_y->GetKey(frame_index)->GetValue(), camera_curve_rotation_x->GetKey(frame_index)->GetValue(), camera_curve_rotation_z->GetKey(frame_index)->GetValue()); /*H(y) P(x) B(z)*/
			camera_frame->distance = Float32(camera_curve_distance->GetKey(frame_index)->GetValue() * setting.position_multiple);
			camera_frame->viewing_angle = maxon::SafeConvert<UInt32>(camera_curve_AOV->GetKey(frame_index)->GetValue());
			camera_frame->perspective = 0;
			VMD_camera_data->GetInterpolator(VMD_CAM_OBJ_XCURVE, Frame_on, camera_frame->interpolator_x);
			VMD_camera_data->GetInterpolator(VMD_CAM_OBJ_YCURVE, Frame_on, camera_frame->interpolator_y);
			VMD_camera_data->GetInterpolator(VMD_CAM_OBJ_ZCURVE, Frame_on, camera_frame->interpolator_z);
			VMD_camera_data->GetInterpolator(VMD_CAM_OBJ_RCURVE, Frame_on, camera_frame->interpolator_r);
			VMD_camera_data->GetInterpolator(VMD_CAM_OBJ_DCURVE, Frame_on, camera_frame->interpolator_d);
			VMD_camera_data->GetInterpolator(VMD_CAM_OBJ_VCURVE, Frame_on, camera_frame->interpolator_v);
			mmd_animation->camera_frames.AppendPtr(camera_frame)iferr_return;
		}
	}
	mmd_animation->ModelName = "カメラ・照明"_s;
	mmd_animation->IsCamera = true;
	iferr(mmd_animation->SaveToFile(fn))
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR)));
	}
	timing.Stop();
	StatusClear();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_OK, maxon::String::IntToString(mmd_animation->camera_frames.GetCount()), String::FloatToString(timing.GetMilliseconds())));
	return(maxon::OK);
}


maxon::Result<void> mmd::VMDAnimation::FromFileImportMotions(VMD_Motions_import_settings setting)
{
	maxon::HashMap<String, maxon::BaseList<bone_obj_tag>*>	bone_name_map;
	maxon::HashMap<String, maxon::BaseList<morph_id_tag>*>	morph_name_map;
	maxon::HashMap<String, maxon::BaseList<BaseTag*>*>	ik_tag_map;
	maxon::HashMap<String, maxon::BaseList<VMD_Motion>*>	MotionFrameList_map;
	maxon::HashMap<String, maxon::BaseList<VMD_Morph>*>	MorphFrameList_map;
	iferr_scope_handler{
		EXIT_FromFileImportMotions
		return err;
	};	
	
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	Filename fn;
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE)))
	{
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s))))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		return(maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR)));
	}

	maxon::TimeValue			timing = maxon::TimeValue::GetTime();
	maxon::UniqueRef<mmd::VMDAnimation>	mmd_animation = NewObj(mmd::VMDAnimation)iferr_return;

	iferr(mmd_animation->LoadFromFile(fn))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR)));
	}
	if (mmd_animation->IsCamera == 1)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
		return(maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR)));
	}

	maxon::Queue<BaseObject*> nodes;
	nodes.Push(SelectObject) iferr_return;
	GeData data;
	if (setting.delete_previous_animation == true) 
	{
		if (setting.import_motion == true && setting.import_morph == true)
		{
			while (!nodes.IsEmpty())
			{
				BaseObject* node = *(nodes.Pop());
				while (node != nullptr)
				{
					if (node->GetType() == Ojoint)
					{
						BaseTag* node_bone_tag = node->GetTag(ID_T_MMD_BONE);
						if (node_bone_tag != nullptr)
						{
							TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
							const Int	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
							for (Int index = 0; index < BoneMorphCount; index++)
							{
								bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
								CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph.strength_id);
								CTrack::Free(morph_track);
								node_bone_tag->SetParameter(bone_morph.strength_id, 0, DESCFLAGS_SET::NONE);
								auto			morph_arr_ptr = morph_name_map.Find(bone_morph.name);
								if (morph_arr_ptr == nullptr)
								{
									maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
									morph_arr->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
									morph_name_map.Insert(bone_morph.name, morph_arr) iferr_return;
								}
								else {
									morph_arr_ptr->GetValue()->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
								}
							}
							node_bone_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
							String	bone_name = data.GetString();
							auto	bone_arr_ptr = bone_name_map.Find(bone_name);
							if (bone_arr_ptr == nullptr)
							{
								maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;
								bone_arr->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
								bone_name_map.Insert(bone_name, bone_arr) iferr_return;
							}
							else {
								bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
							}
							pmx_bone_tag_data->DeleteAllKeyFrame();
						}
						else {
							String	bone_name = node->GetName();
							auto	bone_arr_ptr = bone_name_map.Find(bone_name);
							if (bone_arr_ptr == nullptr)
							{
								maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;;
								bone_arr->Append(bone_obj_tag{ node, nullptr }) iferr_return;
								bone_name_map.Insert(bone_name, bone_arr) iferr_return;
							}
							else {
								bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, nullptr }) iferr_return;
							}
							CTrack* BoneTrack_position_x = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_position_x);
							CTrack* BoneTrack_position_y = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_position_y);
							CTrack* BoneTrack_position_z = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_position_z);
							CTrack* BoneTrack_rotation_x = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_rotation_x);
							CTrack* BoneTrack_rotation_y = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_rotation_y);
							CTrack* BoneTrack_rotation_z = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_rotation_z);
							node->SetRelPos(Vector(0));
							node->SetRelRot(Vector(0));
						}
						BaseTag* node_ik_tag = node->GetTag(1019561);
						if (node_ik_tag != nullptr)
						{
							CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
							CTrack::Free(ik_enable_track);
							node_ik_tag->SetParameter(ID_CA_IK_TAG_ENABLE, true, DESCFLAGS_SET::NONE);
							String	ik_tag_name = node_ik_tag->GetName();
							auto	ik_tag_list_ptr = ik_tag_map.Find(ik_tag_name);
							if (ik_tag_list_ptr == nullptr)
							{
								maxon::BaseList<BaseTag*>* ik_tag_list = NewObj(maxon::BaseList<BaseTag*>)iferr_return;;
								ik_tag_list->Append(node_ik_tag) iferr_return;
								ik_tag_map.Insert(ik_tag_name, ik_tag_list) iferr_return;
							}
							else {
								ik_tag_list_ptr->GetValue()->Append(node_ik_tag) iferr_return;
							}
						}
					}
					else {
						BaseTag* const node_morph_tag = node->GetTag(Tposemorph);
						if (node_morph_tag != nullptr)
						{
							CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
							const Int		MorphCount = pose_morph_tag->GetMorphCount();
							for (Int index = 1; index < MorphCount; index++)
							{
								CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(index));
								CTrack::Free(morph_track);
								pose_morph_tag->GetMorph(index)->SetStrength(0);
								String	morph_name = pose_morph_tag->GetMorph(index)->GetName();
								auto	morph_arr_ptr = morph_name_map.Find(morph_name);
								if (morph_arr_ptr == nullptr)
								{
									maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
									morph_arr->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), node_morph_tag }) iferr_return;
									morph_name_map.Insert(morph_name, morph_arr) iferr_return;
								}
								else {
									morph_arr_ptr->GetValue()->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), node_morph_tag }) iferr_return;
								}
							}
						}
					}
					nodes.Push(node->GetDown()) iferr_return;
					if (node != SelectObject)
					{
						node = node->GetNext();
					}
					else {
						break;
					}
				}
			}
		}
		else if (setting.import_motion == true && setting.import_morph == false)
		{
			while (!nodes.IsEmpty())
			{
				BaseObject* node = *(nodes.Pop());
				while (node != nullptr)
				{
					if (node->GetType() == Ojoint)
					{
						BaseTag* node_bone_tag = node->GetTag(ID_T_MMD_BONE);
						if (node_bone_tag != nullptr)
						{
							TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
							const Int	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
							for (Int index = 0; index < BoneMorphCount; index++)
							{
								bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
								auto			morph_arr_ptr = morph_name_map.Find(bone_morph.name);
								if (morph_arr_ptr == nullptr)
								{
									maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
									morph_arr->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
									morph_name_map.Insert(bone_morph.name, morph_arr) iferr_return;
								}
								else {
									morph_arr_ptr->GetValue()->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
								}
							}
							node_bone_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
							String	bone_name = data.GetString();
							auto	bone_arr_ptr = bone_name_map.Find(bone_name);
							if (bone_arr_ptr == nullptr)
							{
								maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;
								bone_arr->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
								bone_name_map.Insert(bone_name, bone_arr) iferr_return;
							}
							else {
								bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
							}
							pmx_bone_tag_data->DeleteAllKeyFrame();
						}
						else {
							String	bone_name = node->GetName();
							auto	bone_arr_ptr = bone_name_map.Find(bone_name);
							if (bone_arr_ptr == nullptr)
							{
								maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;;
								bone_arr->Append(bone_obj_tag{ node, nullptr }) iferr_return;
								bone_name_map.Insert(bone_name, bone_arr) iferr_return;
							}
							else {
								bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, nullptr }) iferr_return;
							}
							CTrack* BoneTrack_position_x = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_position_x);
							CTrack* BoneTrack_position_y = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_position_y);
							CTrack* BoneTrack_position_z = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_position_z);
							CTrack* BoneTrack_rotation_x = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_rotation_x);
							CTrack* BoneTrack_rotation_y = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_rotation_y);
							CTrack* BoneTrack_rotation_z = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrack_rotation_z);
							node->SetRelPos(Vector(0));
							node->SetRelRot(Vector(0));
						}
						BaseTag* node_ik_tag = node->GetTag(1019561);
						if (node_ik_tag != nullptr)
						{
							CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
							CTrack::Free(ik_enable_track);
							node_ik_tag->SetParameter(ID_CA_IK_TAG_ENABLE, true, DESCFLAGS_SET::NONE);
							String	ik_tag_name = node_ik_tag->GetName();
							auto	ik_tag_list_ptr = ik_tag_map.Find(ik_tag_name);
							if (ik_tag_list_ptr == nullptr)
							{
								maxon::BaseList<BaseTag*>* ik_tag_list = NewObj(maxon::BaseList<BaseTag*>)iferr_return;;
								ik_tag_list->Append(node_ik_tag) iferr_return;
								ik_tag_map.Insert(ik_tag_name, ik_tag_list) iferr_return;
							}
							else {
								ik_tag_list_ptr->GetValue()->Append(node_ik_tag) iferr_return;
							}
						}
					}
					else {
						BaseTag* const node_morph_tag = node->GetTag(Tposemorph);
						if (node_morph_tag != nullptr)
						{
							CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
							const Int		MorphCount = pose_morph_tag->GetMorphCount();
							for (Int index = 1; index < MorphCount; index++)
							{
								String	morph_name = pose_morph_tag->GetMorph(index)->GetName();
								auto	morph_arr_ptr = morph_name_map.Find(morph_name);
								if (morph_arr_ptr == nullptr)
								{
									maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
									morph_arr->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), node_morph_tag }) iferr_return;
									morph_name_map.Insert(morph_name, morph_arr) iferr_return;
								}
								else {
									morph_arr_ptr->GetValue()->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), node_morph_tag }) iferr_return;
								}
							}
						}
					}
					nodes.Push(node->GetDown()) iferr_return;
					if (node != SelectObject)
					{
						node = node->GetNext();
					}
					else {
						break;
					}
				}
			}
		}
		else if (setting.import_motion == false && setting.import_morph == true)
		{
			while (!nodes.IsEmpty())
			{
				BaseObject* node = *(nodes.Pop());
				while (node != nullptr)
				{
					if (node->GetType() == Ojoint)
					{
						BaseTag* node_bone_tag = node->GetTag(ID_T_MMD_BONE);
						if (node_bone_tag != nullptr)
						{
							TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
							const Int	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
							for (Int index = 0; index < BoneMorphCount; index++)
							{
								bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
								CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph.strength_id);
								CTrack::Free(morph_track);
								node_bone_tag->SetParameter(bone_morph.strength_id, 0, DESCFLAGS_SET::NONE);
								auto			morph_arr_ptr = morph_name_map.Find(bone_morph.name);
								if (morph_arr_ptr == nullptr)
								{
									maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
									morph_arr->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
									morph_name_map.Insert(bone_morph.name, morph_arr) iferr_return;
								}
								else {
									morph_arr_ptr->GetValue()->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
								}
							}
							node_bone_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
							String	bone_name = data.GetString();
							auto	bone_arr_ptr = bone_name_map.Find(bone_name);
							if (bone_arr_ptr == nullptr)
							{
								maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;
								bone_arr->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
								bone_name_map.Insert(bone_name, bone_arr) iferr_return;
							}
							else {
								bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
							}
						}
						else {
							String	bone_name = node->GetName();
							auto	bone_arr_ptr = bone_name_map.Find(bone_name);
							if (bone_arr_ptr == nullptr)
							{
								maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;;
								bone_arr->Append(bone_obj_tag{ node, nullptr }) iferr_return;
								bone_name_map.Insert(bone_name, bone_arr) iferr_return;
							}
							else {
								bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, nullptr }) iferr_return;
							}
						}
						BaseTag* node_ik_tag = node->GetTag(1019561);
						if (node_ik_tag != nullptr)
						{
							CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
							if (ik_enable_track != nullptr)
							{
								CTrack::Free(ik_enable_track);
							}
							String	ik_tag_name = node_ik_tag->GetName();
							auto	ik_tag_list_ptr = ik_tag_map.Find(ik_tag_name);
							if (ik_tag_list_ptr == nullptr)
							{
								maxon::BaseList<BaseTag*>* ik_tag_list = NewObj(maxon::BaseList<BaseTag*>)iferr_return;;
								ik_tag_list->Append(node_ik_tag) iferr_return;
								ik_tag_map.Insert(ik_tag_name, ik_tag_list) iferr_return;
							}
							else {
								ik_tag_list_ptr->GetValue()->Append(node_ik_tag) iferr_return;
							}
						}
					}
					else {
						BaseTag* const node_morph_tag = node->GetTag(Tposemorph);
						if (node_morph_tag != nullptr)
						{
							CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
							const Int		MorphCount = pose_morph_tag->GetMorphCount();
							for (Int index = 1; index < MorphCount; index++)
							{
								CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(index));
								CTrack::Free(morph_track);
								pose_morph_tag->GetMorph(index)->SetStrength(0);
								String	morph_name = pose_morph_tag->GetMorph(index)->GetName();
								auto	morph_arr_ptr = morph_name_map.Find(morph_name);
								if (morph_arr_ptr == nullptr)
								{
									maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
									morph_arr->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), node_morph_tag }) iferr_return;
									morph_name_map.Insert(morph_name, morph_arr) iferr_return;
								}
								else {
									morph_arr_ptr->GetValue()->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), node_morph_tag }) iferr_return;
								}
							}
						}
					}
					nodes.Push(node->GetDown()) iferr_return;
					if (node != SelectObject)
					{
						node = node->GetNext();
					}
					else {
						break;
					}
				}
			}
		}
		if (setting.import_model_info == true) {
			CTrack* ModelEditorDisplayTrack = SelectObject->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
			CTrack::Free(ModelEditorDisplayTrack);
			SelectObject->SetParameter(ID_BASEOBJECT_VISIBILITY_EDITOR, 2, DESCFLAGS_SET::NONE);
			CTrack* ModelRenderDisplayTrack = SelectObject->FindCTrack(ID_BASEOBJECT_VISIBILITY_RENDER);
			SelectObject->SetParameter(ID_BASEOBJECT_VISIBILITY_RENDER, 2, DESCFLAGS_SET::NONE);
			CTrack::Free(ModelRenderDisplayTrack);
		}
	}
	else {
		while (!nodes.IsEmpty())
		{
			BaseObject* node = *(nodes.Pop());
			while (node != nullptr)
			{
				if (node->GetType() == Ojoint)
				{
					BaseTag* node_bone_tag = node->GetTag(ID_T_MMD_BONE);
					if (node_bone_tag != nullptr)
					{
						TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
						const Int	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
						for (Int index = 0; index < BoneMorphCount; index++)
						{
							bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
							auto			morph_arr_ptr = morph_name_map.Find(bone_morph.name);
							if (morph_arr_ptr == nullptr)
							{
								maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
								morph_arr->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
								morph_name_map.Insert(bone_morph.name, morph_arr) iferr_return;
							}
							else {
								morph_arr_ptr->GetValue()->Append(morph_id_tag{ bone_morph.strength_id, node_bone_tag }) iferr_return;
							}
						}
						node_bone_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
						String	bone_name = data.GetString();
						auto	bone_arr_ptr = bone_name_map.Find(bone_name);
						if (bone_arr_ptr == nullptr)
						{
							maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;
							bone_arr->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
							bone_name_map.Insert(bone_name, bone_arr) iferr_return;
						}
						else {
							bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, node_bone_tag }) iferr_return;
						}
					}
					else {
						String	bone_name = node->GetName();
						auto	bone_arr_ptr = bone_name_map.Find(bone_name);
						if (bone_arr_ptr == nullptr)
						{
							maxon::BaseList<bone_obj_tag>* bone_arr = NewObj(maxon::BaseList<bone_obj_tag>)iferr_return;;
							bone_arr->Append(bone_obj_tag{ node, nullptr }) iferr_return;
							bone_name_map.Insert(bone_name, bone_arr) iferr_return;
						}
						else {
							bone_arr_ptr->GetValue()->Append(bone_obj_tag{ node, nullptr }) iferr_return;
						}
					}
					BaseTag* node_ik_tag = node->GetTag(1019561);
					if (node_ik_tag != nullptr)
					{
						CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
						if (ik_enable_track != nullptr)
						{
							CTrack::Free(ik_enable_track);
						}
						String	ik_tag_name = node_ik_tag->GetName();
						auto	ik_tag_list_ptr = ik_tag_map.Find(ik_tag_name);
						if (ik_tag_list_ptr == nullptr)
						{
							maxon::BaseList<BaseTag*>* ik_tag_list = NewObj(maxon::BaseList<BaseTag*>)iferr_return;;
							ik_tag_list->Append(node_ik_tag) iferr_return;
							ik_tag_map.Insert(ik_tag_name, ik_tag_list) iferr_return;
						}
						else {
							ik_tag_list_ptr->GetValue()->Append(node_ik_tag) iferr_return;
						}
					}
				}
				else {
					BaseTag* const tag = node->GetTag(Tposemorph);
					if (tag != nullptr)
					{
						CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(tag);
						const Int		MorphCount = pose_morph_tag->GetMorphCount();
						for (Int index = 1; index < MorphCount; index++)
						{
							String	morph_name = pose_morph_tag->GetMorph(index)->GetName();
							auto	morph_arr_ptr = morph_name_map.Find(morph_name);
							if (morph_arr_ptr == nullptr)
							{
								maxon::BaseList<morph_id_tag>* morph_arr = NewObj(maxon::BaseList<morph_id_tag>)iferr_return;
								morph_arr->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), tag }) iferr_return;
								morph_name_map.Insert(morph_name, morph_arr) iferr_return;
							}
							else {
								morph_arr_ptr->GetValue()->Append(morph_id_tag{ pose_morph_tag->GetMorphID(index), tag }) iferr_return;
							}
						}
					}
				}
				nodes.Push(node->GetDown()) iferr_return;
				if (node != SelectObject)
				{
					node = node->GetNext();
				}
				else {
					break;
				}
			}
		}
	}
	nodes.Reset();
	maxon::BaseArray<String> motion_bone_name_array;
	maxon::BaseArray<String> motion_morph_name_array;
	const Int32 MotionFrameNumber = mmd_animation->motion_frames.GetCount();
	if (setting.import_motion == true) 
	{
		for (Int32 motion_frame_index = 0; motion_frame_index < MotionFrameNumber; motion_frame_index++)
		{
			String	bone_name = mmd_animation->motion_frames[motion_frame_index].bone_name;
			auto	MotionFrame_ptr = MotionFrameList_map.Find(bone_name);
			if (MotionFrame_ptr == nullptr)
			{
				maxon::BaseList<VMD_Motion>* MotionFrame = NewObj(maxon::BaseList<VMD_Motion>) iferr_return;
				MotionFrame->Append(mmd_animation->motion_frames[motion_frame_index]) iferr_return;
				MotionFrameList_map.Insert(bone_name, MotionFrame) iferr_return;
				motion_bone_name_array.Append(bone_name)iferr_return;
			}
			else {
				MotionFrame_ptr->GetValue()->Append(mmd_animation->motion_frames[motion_frame_index]) iferr_return;
			}
		}
	}
	const Int32 MorphFrameNumber = mmd_animation->morph_frames.GetCount();
	if (setting.import_morph == true) {
		for (Int32 morph_frame_index = 0; morph_frame_index < MorphFrameNumber; morph_frame_index++)
		{
			String	morph_name = mmd_animation->morph_frames[morph_frame_index].morph_name;
			auto	MorphFrame_ptr = MorphFrameList_map.Find(morph_name);
			if (MorphFrame_ptr == nullptr)
			{
				maxon::BaseList<VMD_Morph>* MorphFrame = NewObj(maxon::BaseList<VMD_Morph>) iferr_return;
				MorphFrame->Append(mmd_animation->morph_frames[morph_frame_index]) iferr_return;
				MorphFrameList_map.Insert(morph_name, MorphFrame) iferr_return;
				motion_morph_name_array.Append(morph_name)iferr_return;
			}
			else {
				MorphFrame_ptr->GetValue()->Append(mmd_animation->morph_frames[morph_frame_index]) iferr_return;
			}
		}
	}

	doc->SetTime(BaseTime(0.));

	Int32 MaxTime;
	if (MorphFrameNumber != 0 && MotionFrameNumber != 0)
	{
		MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30.), maxon::Max((Int32)mmd_animation->motion_frames[MotionFrameNumber - 1].frame_no, (Int32)mmd_animation->morph_frames[MorphFrameNumber - 1].frame_no));
	}
	else if (MorphFrameNumber != 0)
	{
		MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30.), (Int32)mmd_animation->morph_frames[MorphFrameNumber - 1].frame_no);
	}
	else if (MotionFrameNumber != 0)
	{
		MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30.), (Int32)mmd_animation->motion_frames[MotionFrameNumber - 1].frame_no);
	}
	else {
		MaxTime = doc->GetMaxTime().GetFrame(30.);
	}

	/*ImportMotion*/
	Int	insideCount = 0;
	Int				bone_cnt = 0;
	Int				motion_frame_bone_number = motion_bone_name_array.GetCount();
	String			motion_frame_bone_number_S = String::IntToString(motion_frame_bone_number);
	maxon::BaseArray<String>	not_find_bone_S;
	if (setting.import_motion == true) {
		if (setting.delete_previous_animation == true) {

			insideCount = 0;
			maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, motion_frame_bone_number - 1,
				[](LocalData& context)
				{
					context.localCount = 0;
				}, 
				[&MotionFrameList_map, &bone_name_map,&setting,
					&not_find_bone_S,&motion_frame_bone_number_S,
					&bone_cnt,&motion_bone_name_array](const Int motion_bone_name_index, LocalData& context)->maxon::Result<void>
				{
					iferr_scope;
					String motion_bone_name = motion_bone_name_array[motion_bone_name_index];
					mmd::VMD_Motion			MotionFrame;
					mmd::VMD_Motion			NextMotionFrame;
					BaseTime			MotionKeyTime = BaseTime(0, 30.);
					Float				TimeOfTwoMotionFrames = 0.0;
					Float				ValueOfTwoMotionFrames = 0.0;
					BaseTime			MotionKeyTimeLeft[6] = { BaseTime(0.0, 30.) };
					Float				MotionKeyValueLeft[6] = { 0.0 };
					maxon::BaseList<mmd::VMD_Motion>* MotionFrameList = MotionFrameList_map.Find(motion_bone_name)->GetValue();
					auto				bone_ptr = bone_name_map.Find(motion_bone_name);

					if (bone_ptr != nullptr)
					{
						for (bone_obj_tag bone : *bone_ptr->GetValue())
						{
							if (bone.tag == nullptr)
							{
								if (bone.obj != nullptr)
								{
									bone.obj->SetQuaternionRotationMode(true, false);
									CTrack* BoneTrack_position_x = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrack_position_x);
									BoneTrack_position_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrack_position_x == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_position_x);
									CTrack* BoneTrack_position_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrack_position_x);
									BoneTrack_position_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrack_position_y == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_position_y);
									CTrack* BoneTrack_position_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrack_position_x);
									BoneTrack_position_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrack_position_z == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_position_z);
									CTrack* BoneTrack_rotation_x = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrack_position_x);
									BoneTrack_rotation_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrack_rotation_x == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_rotation_x);
									CTrack* BoneTrack_rotation_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrack_position_x);
									BoneTrack_rotation_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrack_rotation_y == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_rotation_y);
									CTrack* BoneTrack_rotation_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrack_position_x);
									BoneTrack_rotation_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrack_rotation_z == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_rotation_z);

									CCurve* BoneCurve_position_x = BoneTrack_position_x->GetCurve();
									CCurve* BoneCurve_position_y = BoneTrack_position_y->GetCurve();
									CCurve* BoneCurve_position_z = BoneTrack_position_z->GetCurve();
									CCurve* BoneCurve_rotation_x = BoneTrack_rotation_x->GetCurve();
									CCurve* BoneCurve_rotation_y = BoneTrack_rotation_y->GetCurve();
									CCurve* BoneCurve_rotation_z = BoneTrack_rotation_z->GetCurve();
									Int	motion_frame_number = MotionFrameList->GetCount();
									for (Int motion_index = 0; motion_index < motion_frame_number; motion_index++)
									{
										if (motion_index == 0 && motion_frame_number != 1)
										{
											MotionFrame = MotionFrameList->operator[](motion_index);
											NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
										}
										else if (motion_index == motion_frame_number - 1)
										{
											MotionFrame = NextMotionFrame;
										}
										else {
											MotionFrame = NextMotionFrame;
											NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
										}
										TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
										MotionKeyTime = BaseTime(Float(MotionFrame.frame_no) + setting.time_offset, 30.);

										Vector rotation = QuaternionToEuler(MotionFrame.rotation);
										Vector next_rotation = QuaternionToEuler(NextMotionFrame.rotation);

										CKey* MotionKey_position_x = CKey::Alloc(); /* _position_x */
										MotionKey_position_x->SetTime(BoneCurve_position_x, MotionKeyTime);
										MotionKey_position_x->SetValue(BoneCurve_position_x, MotionFrame.position.x * setting.position_multiple);
										MotionKey_position_x->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
										MotionKey_position_x->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
										ValueOfTwoMotionFrames = NextMotionFrame.position.x * setting.position_multiple - MotionFrame.position.x * setting.position_multiple;
										if (MotionFrame.interpolator_x.ax == 127 - MotionFrame.interpolator_x.bx && MotionFrame.interpolator_x.ay == 127 - MotionFrame.interpolator_x.by)
										{
											MotionKey_position_x->SetInterpolation(BoneCurve_position_x, CINTERPOLATION::LINEAR);
										}
										else {
											MotionKey_position_x->SetTimeLeft(BoneCurve_position_x, MotionKeyTimeLeft[0]);
											MotionKey_position_x->SetValueLeft(BoneCurve_position_x, MotionKeyValueLeft[0]);
											MotionKey_position_x->SetTimeRight(BoneCurve_position_x, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ax / 127.0), 30.));
											MotionKey_position_x->SetValueRight(BoneCurve_position_x, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ay / 127.0));
										}
										MotionKeyTimeLeft[0] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.bx / 127.0), 30.);
										MotionKeyValueLeft[0] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.by / 127.0);
										BoneCurve_position_x->InsertKey(MotionKey_position_x);

										CKey* MotionKey_position_y = CKey::Alloc(); /* _position_y */
										MotionKey_position_y->SetTime(BoneCurve_position_y, MotionKeyTime);
										MotionKey_position_y->SetValue(BoneCurve_position_y, MotionFrame.position.y * setting.position_multiple);
										MotionKey_position_y->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
										MotionKey_position_y->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
										ValueOfTwoMotionFrames = NextMotionFrame.position.y * setting.position_multiple - MotionFrame.position.y * setting.position_multiple;
										if (MotionFrame.interpolator_y.ax == 127 - MotionFrame.interpolator_y.bx && MotionFrame.interpolator_y.ay == 127 - MotionFrame.interpolator_y.by)
										{
											MotionKey_position_y->SetInterpolation(BoneCurve_position_y, CINTERPOLATION::LINEAR);
										}
										else {
											MotionKey_position_y->SetTimeLeft(BoneCurve_position_y, MotionKeyTimeLeft[1]);
											MotionKey_position_y->SetValueLeft(BoneCurve_position_y, MotionKeyValueLeft[1]);
											MotionKey_position_y->SetTimeRight(BoneCurve_position_y, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ax / 127.0), 30.));
											MotionKey_position_y->SetValueRight(BoneCurve_position_y, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ay / 127.0));
										}
										MotionKeyTimeLeft[1] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.bx / 127.0), 30.);
										MotionKeyValueLeft[1] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.by / 127.0);
										BoneCurve_position_y->InsertKey(MotionKey_position_y);

										CKey* MotionKey_position_z = CKey::Alloc(); /* _position_z */
										MotionKey_position_z->SetTime(BoneCurve_position_z, MotionKeyTime);
										MotionKey_position_z->SetValue(BoneCurve_position_z, MotionFrame.position.z * setting.position_multiple);
										MotionKey_position_z->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
										MotionKey_position_z->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
										ValueOfTwoMotionFrames = NextMotionFrame.position.z * setting.position_multiple - MotionFrame.position.z * setting.position_multiple;
										if (MotionFrame.interpolator_z.ax == 127 - MotionFrame.interpolator_z.bx && MotionFrame.interpolator_z.ay == 127 - MotionFrame.interpolator_z.by)
										{
											MotionKey_position_z->SetInterpolation(BoneCurve_position_z, CINTERPOLATION::LINEAR);
										}
										else {
											MotionKey_position_z->SetTimeLeft(BoneCurve_position_z, MotionKeyTimeLeft[2]);
											MotionKey_position_z->SetValueLeft(BoneCurve_position_z, MotionKeyValueLeft[2]);
											MotionKey_position_z->SetTimeRight(BoneCurve_position_z, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ax / 127.0), 30.));
											MotionKey_position_z->SetValueRight(BoneCurve_position_z, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ay / 127.0));
										}
										MotionKeyTimeLeft[2] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.bx / 127.0), 30.);
										MotionKeyValueLeft[2] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.by / 127.0);
										BoneCurve_position_z->InsertKey(MotionKey_position_z);

										CKey* MotionKey_rotation_x = CKey::Alloc(); /* _rotation_x */
										MotionKey_rotation_x->SetTime(BoneCurve_rotation_x, MotionKeyTime);
										MotionKey_rotation_x->SetValue(BoneCurve_rotation_x, rotation.x);
										BoneCurve_rotation_x->InsertKey(MotionKey_rotation_x);

										CKey* MotionKey_rotation_y = CKey::Alloc(); /* _rotation_y */
										MotionKey_rotation_y->SetTime(BoneCurve_rotation_y, MotionKeyTime);
										MotionKey_rotation_y->SetValue(BoneCurve_rotation_y, rotation.y);
										BoneCurve_rotation_y->InsertKey(MotionKey_rotation_y);

										CKey* MotionKey_rotation_z = CKey::Alloc(); /* _rotation_z */
										MotionKey_rotation_z->SetTime(BoneCurve_rotation_z, MotionKeyTime);
										MotionKey_rotation_z->SetValue(BoneCurve_rotation_z, rotation.z);
										BoneCurve_rotation_z->InsertKey(MotionKey_rotation_z);
									}
									bone_cnt++;
								}
							}
							else {
								bone.obj->SetQuaternionRotationMode(true, false);
								TMMDBone* tag_data = bone.tag->GetNodeData<TMMDBone>();
								BaseContainer* bc = bone.tag->GetDataInstance();
								const Bool	Is_physical = tag_data->IsPhysical();
								const Bool	Is_translatable = bc->GetBool(PMX_BONE_TRANSLATABLE);
								const Bool	Is_rotatable = bc->GetBool(PMX_BONE_ROTATABLE);
								const Bool	Is_inherit = bc->GetBool(PMX_BONE_INHERIT_TRANSLATION) || bc->GetBool(PMX_BONE_INHERIT_ROTATION);
								CTrack* BoneTrack_position_x = nullptr;
								CTrack* BoneTrack_position_y = nullptr;
								CTrack* BoneTrack_position_z = nullptr;
								CTrack* BoneTrack_rotation_x = nullptr;
								CTrack* BoneTrack_rotation_y = nullptr;
								CTrack* BoneTrack_rotation_z = nullptr;
								CCurve* BoneCurve_position_x = nullptr;
								CCurve* BoneCurve_position_y = nullptr;
								CCurve* BoneCurve_position_z = nullptr;
								CCurve* BoneCurve_rotation_x = nullptr;
								CCurve* BoneCurve_rotation_y = nullptr;
								CCurve* BoneCurve_rotation_z = nullptr;
								if (!(Is_physical || Is_inherit))
								{
									if (Is_translatable)
									{
										bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrack_position_x);
										BoneTrack_position_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										if (BoneTrack_position_x == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrack_position_x);
										BoneTrack_position_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrack_position_y);
										BoneTrack_position_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										if (BoneTrack_position_y == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrack_position_y);
										BoneTrack_position_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrack_position_z);
										BoneTrack_position_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										if (BoneTrack_position_z == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrack_position_z);
										BoneCurve_position_x = BoneTrack_position_x->GetCurve();
										BoneCurve_position_y = BoneTrack_position_y->GetCurve();
										BoneCurve_position_z = BoneTrack_position_z->GetCurve();
									}
									if (Is_rotatable)
									{
										BoneTrack_rotation_x = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrack_rotation_x);
										BoneTrack_rotation_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										if (BoneTrack_rotation_x == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrack_rotation_x);
										BoneTrack_rotation_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrack_rotation_y);
										BoneTrack_rotation_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										if (BoneTrack_rotation_y == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrack_rotation_y);
										BoneTrack_rotation_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrack_rotation_z);
										BoneTrack_rotation_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										if (BoneTrack_rotation_z == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrack_rotation_z);
										BoneCurve_rotation_x = BoneTrack_rotation_x->GetCurve();
										BoneCurve_rotation_y = BoneTrack_rotation_y->GetCurve();
										BoneCurve_rotation_z = BoneTrack_rotation_z->GetCurve();
									}

									Int motion_frame_number = MotionFrameList->GetCount();
									for (Int motion_index = 0; motion_index < motion_frame_number; motion_index++)
									{
										if (motion_index == 0 && motion_frame_number != 1)
										{
											MotionFrame = MotionFrameList->operator[](motion_index);
											NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
										}
										else if (motion_index == motion_frame_number - 1)
										{
											MotionFrame = NextMotionFrame;
										}
										else {
											MotionFrame = NextMotionFrame;
											NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
										}
										TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
										Int32 frame_no = Int32(MotionFrame.frame_no) + Int32(setting.time_offset);
										MotionKeyTime = BaseTime(Float(frame_no), 30.);

										if (Is_translatable)
										{
											CKey* MotionKey_position_x = CKey::Alloc(); /* _position_x */
											MotionKey_position_x->SetValue(BoneCurve_position_x, MotionFrame.position.x * setting.position_multiple);
											MotionKey_position_x->SetTime(BoneCurve_rotation_x, MotionKeyTime);
											BoneCurve_position_x->InsertKey(MotionKey_position_x);
											tag_data->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_no,MotionFrame.interpolator_x);
											CKey* MotionKey_position_y = CKey::Alloc(); /* _position_y */
											MotionKey_position_y->SetValue(BoneCurve_position_y, MotionFrame.position.y * setting.position_multiple);
											MotionKey_position_y->SetTime(BoneCurve_position_y, MotionKeyTime);
											BoneCurve_position_y->InsertKey(MotionKey_position_y);
											tag_data->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_no, MotionFrame.interpolator_y);
											CKey* MotionKey_position_z = CKey::Alloc(); /* _position_z */
											MotionKey_position_z->SetValue(BoneCurve_position_z, MotionFrame.position.z * setting.position_multiple);
											MotionKey_position_z->SetTime(BoneCurve_position_z, MotionKeyTime);
											BoneCurve_position_z->InsertKey(MotionKey_position_z);
											tag_data->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_no,  MotionFrame.interpolator_z);
										}
										if (Is_rotatable)
										{
											Vector rotation = QuaternionToEuler(MotionFrame.rotation);
											CKey* MotionKey_rotation_x = CKey::Alloc(); /* _rotation_x */
											MotionKey_rotation_x->SetValue(BoneCurve_rotation_x, rotation.x);
											MotionKey_rotation_x->SetTime(BoneCurve_rotation_x, MotionKeyTime);
											BoneCurve_rotation_x->InsertKey(MotionKey_rotation_x);
											CKey* MotionKey_rotation_y = CKey::Alloc(); /* _rotation_y */
											MotionKey_rotation_y->SetValue(BoneCurve_rotation_y, rotation.y);
											MotionKey_rotation_y->SetTime(BoneCurve_rotation_y, MotionKeyTime);
											BoneCurve_rotation_y->InsertKey(MotionKey_rotation_y);
											CKey* MotionKey_rotation_z = CKey::Alloc(); /* _rotation_z */
											MotionKey_rotation_z->SetValue(BoneCurve_rotation_z, rotation.z);
											MotionKey_rotation_z->SetTime(BoneCurve_rotation_z, MotionKeyTime);
											BoneCurve_rotation_z->InsertKey(MotionKey_rotation_z);
											tag_data->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_no, MotionFrame.interpolator_r);
										}
									}
									tag_data->UpdateAllInterpolator();
									bone_cnt++;
								}
							}
						}
					}
					else {
						g_spinlock.Lock();
						not_find_bone_S.Append(motion_bone_name) iferr_return;
						g_spinlock.Unlock();
					}
		context.localCount++;
		if (GeIsMainThread())
		{
			StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
			StatusSetSpin();
		}
		return(maxon::OK);
	}, [&insideCount,&motion_frame_bone_number](LocalData& context)
	{
		insideCount += context.localCount;
		if (GeIsMainThread())
			StatusSetText("Import bone " + String::IntToString(insideCount) + " of " + String::IntToString(motion_frame_bone_number));
	}) iferr_return;
		}
		else {
		insideCount = 0;
		maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, motion_frame_bone_number - 1,
			[](LocalData& context)
			{
				context.localCount = 0;
			},
			[&MotionFrameList_map, &bone_name_map, &setting,
				&not_find_bone_S, &motion_frame_bone_number_S,
				&bone_cnt,&motion_bone_name_array](const Int motion_bone_name_index, LocalData& context)->maxon::Result<void>
			{
				iferr_scope;
				String motion_bone_name = motion_bone_name_array[motion_bone_name_index];
				mmd::VMD_Motion			MotionFrame;
				mmd::VMD_Motion			NextMotionFrame;
				BaseTime			MotionKeyTime = BaseTime(0, 30.);
				Float				TimeOfTwoMotionFrames = 0.0;
				Float				ValueOfTwoMotionFrames = 0.0;
				BaseTime			MotionKeyTimeLeft[6] = { BaseTime(0.0, 30.) };
				Float				MotionKeyValueLeft[6] = { 0.0 };
			maxon::BaseList<mmd::VMD_Motion>* MotionFrameList = MotionFrameList_map.Find(motion_bone_name)->GetValue();
			auto				bone_ptr = bone_name_map.Find(motion_bone_name);

			if (bone_ptr != nullptr)
			{
				for (bone_obj_tag bone : *bone_ptr->GetValue())
				{
					if (bone.tag == nullptr)
					{
						if (bone.obj != nullptr)
						{
							bone.obj->SetQuaternionRotationMode(true, false);
							CTrack* BoneTrack_position_x = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							if (BoneTrack_position_x == nullptr)
							{
								BoneTrack_position_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrack_position_x == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrack_position_x);
							}
							CTrack* BoneTrack_position_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							if (BoneTrack_position_x == nullptr)
							{
								BoneTrack_position_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrack_position_y == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrack_position_y);
							}
							CTrack* BoneTrack_position_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							if (BoneTrack_position_x == nullptr)
							{
								BoneTrack_position_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrack_position_z == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrack_position_z);
							}
							CTrack* BoneTrack_rotation_x = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							if (BoneTrack_position_x == nullptr)
							{
								BoneTrack_rotation_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_x == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrack_rotation_x);
							}
							CTrack* BoneTrack_rotation_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							if (BoneTrack_position_x == nullptr)
							{
								BoneTrack_rotation_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_y == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrack_rotation_y);
							}
							CTrack* BoneTrack_rotation_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							if (BoneTrack_position_x == nullptr)
							{
								BoneTrack_rotation_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_z == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrack_rotation_z);
							}
							CCurve* BoneCurve_position_x = BoneTrack_position_x->GetCurve();
							CCurve* BoneCurve_position_y = BoneTrack_position_y->GetCurve();
							CCurve* BoneCurve_position_z = BoneTrack_position_z->GetCurve();
							CCurve* BoneCurve_rotation_x = BoneTrack_rotation_x->GetCurve();
							CCurve* BoneCurve_rotation_y = BoneTrack_rotation_y->GetCurve();
							CCurve* BoneCurve_rotation_z = BoneTrack_rotation_z->GetCurve();

							Int	motion_frame_number = MotionFrameList->GetCount();
							for (Int motion_index = 0; motion_index < motion_frame_number; motion_index++)
							{
								StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
								StatusSetSpin();
								if (motion_index == 0 && motion_frame_number != 1)
								{
									MotionFrame = MotionFrameList->operator[](motion_index);
									NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
								}
								else if (motion_index == motion_frame_number - 1)
								{
									MotionFrame = NextMotionFrame;
								}
								else {
									MotionFrame = NextMotionFrame;
									NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
								}
								TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
								MotionKeyTime = BaseTime(Float(MotionFrame.frame_no) + setting.time_offset, 30.);

								Vector rotation = QuaternionToEuler(MotionFrame.rotation);
								Vector next_rotation = QuaternionToEuler(NextMotionFrame.rotation);

								CKey* MotionKey_position_x = CKey::Alloc(); /* _position_x */
								MotionKey_position_x->SetTime(BoneCurve_position_x, MotionKeyTime);
								MotionKey_position_x->SetValue(BoneCurve_position_x, MotionFrame.position.x * setting.position_multiple);
								MotionKey_position_x->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKey_position_x->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = NextMotionFrame.position.x * setting.position_multiple - MotionFrame.position.x * setting.position_multiple;
								if (MotionFrame.interpolator_x.ax == 127 - MotionFrame.interpolator_x.bx && MotionFrame.interpolator_x.ay == 127 - MotionFrame.interpolator_x.by)
								{
									MotionKey_position_x->SetInterpolation(BoneCurve_position_x, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKey_position_x->SetTimeLeft(BoneCurve_position_x, MotionKeyTimeLeft[0]);
									MotionKey_position_x->SetValueLeft(BoneCurve_position_x, MotionKeyValueLeft[0]);
									MotionKey_position_x->SetTimeRight(BoneCurve_position_x, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ax / 127.0), 30.));
									MotionKey_position_x->SetValueRight(BoneCurve_position_x, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ay / 127.0));
								}
								MotionKeyTimeLeft[0] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.bx / 127.0), 30.);
								MotionKeyValueLeft[0] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.by / 127.0);
								BoneCurve_position_x->InsertKey(MotionKey_position_x);

								CKey* MotionKey_position_y = CKey::Alloc(); /* _position_y */
								MotionKey_position_y->SetTime(BoneCurve_position_y, MotionKeyTime);
								MotionKey_position_y->SetValue(BoneCurve_position_y, MotionFrame.position.y * setting.position_multiple);
								MotionKey_position_y->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKey_position_y->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = NextMotionFrame.position.y * setting.position_multiple - MotionFrame.position.y * setting.position_multiple;
								if (MotionFrame.interpolator_y.ax == 127 - MotionFrame.interpolator_y.bx && MotionFrame.interpolator_y.ay == 127 - MotionFrame.interpolator_y.by)
								{
									MotionKey_position_y->SetInterpolation(BoneCurve_position_y, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKey_position_y->SetTimeLeft(BoneCurve_position_y, MotionKeyTimeLeft[1]);
									MotionKey_position_y->SetValueLeft(BoneCurve_position_y, MotionKeyValueLeft[1]);
									MotionKey_position_y->SetTimeRight(BoneCurve_position_y, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ax / 127.0), 30.));
									MotionKey_position_y->SetValueRight(BoneCurve_position_y, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ay / 127.0));
								}
								MotionKeyTimeLeft[1] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.bx / 127.0), 30.);
								MotionKeyValueLeft[1] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.by / 127.0);
								BoneCurve_position_y->InsertKey(MotionKey_position_y);

								CKey* MotionKey_position_z = CKey::Alloc(); /* _position_z */
								MotionKey_position_z->SetTime(BoneCurve_position_z, MotionKeyTime);
								MotionKey_position_z->SetValue(BoneCurve_position_z, MotionFrame.position.z * setting.position_multiple);
								MotionKey_position_z->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKey_position_z->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = NextMotionFrame.position.z * setting.position_multiple - MotionFrame.position.z * setting.position_multiple;
								if (MotionFrame.interpolator_z.ax == 127 - MotionFrame.interpolator_z.bx && MotionFrame.interpolator_z.ay == 127 - MotionFrame.interpolator_z.by)
								{
									MotionKey_position_z->SetInterpolation(BoneCurve_position_z, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKey_position_z->SetTimeLeft(BoneCurve_position_z, MotionKeyTimeLeft[2]);
									MotionKey_position_z->SetValueLeft(BoneCurve_position_z, MotionKeyValueLeft[2]);
									MotionKey_position_z->SetTimeRight(BoneCurve_position_z, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ax / 127.0), 30.));
									MotionKey_position_z->SetValueRight(BoneCurve_position_z, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ay / 127.0));
								}
								MotionKeyTimeLeft[2] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.bx / 127.0), 30.);
								MotionKeyValueLeft[2] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.by / 127.0);
								BoneCurve_position_z->InsertKey(MotionKey_position_z);

								CKey* MotionKey_rotation_x = CKey::Alloc(); /* _rotation_x */
								MotionKey_rotation_x->SetTime(BoneCurve_rotation_x, MotionKeyTime);
								MotionKey_rotation_x->SetValue(BoneCurve_rotation_x, rotation.x);
								BoneCurve_rotation_x->InsertKey(MotionKey_rotation_x);

								CKey* MotionKey_rotation_y = CKey::Alloc(); /* _rotation_y */
								MotionKey_rotation_y->SetTime(BoneCurve_rotation_y, MotionKeyTime);
								MotionKey_rotation_y->SetValue(BoneCurve_rotation_y, rotation.y);
								BoneCurve_rotation_y->InsertKey(MotionKey_rotation_y);

								CKey* MotionKey_rotation_z = CKey::Alloc(); /* _rotation_z */
								MotionKey_rotation_z->SetTime(BoneCurve_rotation_z, MotionKeyTime);
								MotionKey_rotation_z->SetValue(BoneCurve_rotation_z, rotation.z);
								BoneCurve_rotation_z->InsertKey(MotionKey_rotation_z);
							}
							bone_cnt++;
						}
					}
					else {
					bone.obj->SetQuaternionRotationMode(true, false);
						TMMDBone* tag_data = bone.tag->GetNodeData<TMMDBone>();
						BaseContainer* bc = bone.tag->GetDataInstance();
						const Bool	Is_physical = tag_data->IsPhysical();
						const Bool	Is_translatable = bc->GetBool(PMX_BONE_TRANSLATABLE);
						const Bool	Is_rotatable = bc->GetBool(PMX_BONE_ROTATABLE);
						const Bool	Is_inherit = bc->GetBool(PMX_BONE_INHERIT_TRANSLATION) || bc->GetBool(PMX_BONE_INHERIT_ROTATION);
						CTrack* BoneTrack_position_x = nullptr;
						CTrack* BoneTrack_position_y = nullptr;
						CTrack* BoneTrack_position_z = nullptr;
						CTrack* BoneTrack_rotation_x = nullptr;
						CTrack* BoneTrack_rotation_y = nullptr;
						CTrack* BoneTrack_rotation_z = nullptr;
						CCurve* BoneCurve_position_x = nullptr;
						CCurve* BoneCurve_position_y = nullptr;
						CCurve* BoneCurve_position_z = nullptr;
						CCurve* BoneCurve_rotation_x = nullptr;
						CCurve* BoneCurve_rotation_y = nullptr;
						CCurve* BoneCurve_rotation_z = nullptr;
						if (!(Is_physical || Is_inherit))
						{
							if (Is_translatable)
							{
								bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrack_position_x == nullptr)
								{
									BoneTrack_position_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrack_position_x == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_position_x);
								}
								BoneTrack_position_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrack_position_y == nullptr)
								{
									BoneTrack_position_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrack_position_y == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_position_y);
								}
								BoneTrack_position_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrack_position_z == nullptr)
								{
									BoneTrack_position_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrack_position_z == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_position_z);
								}
								BoneCurve_position_x = BoneTrack_position_x->GetCurve();
								BoneCurve_position_y = BoneTrack_position_y->GetCurve();
								BoneCurve_position_z = BoneTrack_position_z->GetCurve();
							}
							if (Is_rotatable)
							{
								BoneTrack_rotation_x = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_x == nullptr)
									BoneTrack_rotation_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_x == nullptr)
								{
									BoneTrack_rotation_x = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrack_rotation_x == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_rotation_x);
								}
								BoneTrack_rotation_y = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_y == nullptr)
								{
									BoneTrack_rotation_y = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrack_rotation_y == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_rotation_y);
								}
								BoneTrack_rotation_z = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrack_rotation_z == nullptr)
								{
									BoneTrack_rotation_z = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrack_rotation_z == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrack_rotation_z);
								}
								BoneCurve_rotation_x = BoneTrack_rotation_x->GetCurve();
								BoneCurve_rotation_y = BoneTrack_rotation_y->GetCurve();
								BoneCurve_rotation_z = BoneTrack_rotation_z->GetCurve();
							}

							Int motion_frame_number = MotionFrameList->GetCount();
							for (Int motion_index = 0; motion_index < motion_frame_number; motion_index++)
							{
								StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
								StatusSetSpin();
								if (motion_index == 0 && motion_frame_number != 1)
								{
									MotionFrame = MotionFrameList->operator[](motion_index);
									NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
								}
								else if (motion_index == motion_frame_number - 1)
								{
									MotionFrame = NextMotionFrame;
								}
								else {
									MotionFrame = NextMotionFrame;
									NextMotionFrame = MotionFrameList->operator[](motion_index + 1);
								}
								TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
								Int32 frame_no = Int32(MotionFrame.frame_no) + maxon::SafeConvert<Int32>(setting.time_offset);
								MotionKeyTime = BaseTime(Float(frame_no), 30.);


								if (Is_translatable)
								{
									CKey* MotionKey_position_x = CKey::Alloc(); /* _position_x */
									MotionKey_position_x->SetValue(BoneCurve_position_x, MotionFrame.position.x * setting.position_multiple);
									MotionKey_position_x->SetTime(BoneCurve_rotation_x, MotionKeyTime);
									BoneCurve_position_x->InsertKey(MotionKey_position_x);
									tag_data->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_no, MotionFrame.interpolator_x);
									CKey* MotionKey_position_y = CKey::Alloc(); /* _position_y */
									MotionKey_position_y->SetValue(BoneCurve_position_y, MotionFrame.position.y * setting.position_multiple);
									MotionKey_position_y->SetTime(BoneCurve_position_y, MotionKeyTime);
									BoneCurve_position_y->InsertKey(MotionKey_position_y);
									tag_data->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_no, MotionFrame.interpolator_y);
									CKey* MotionKey_position_z = CKey::Alloc(); /* _position_z */
									MotionKey_position_z->SetValue(BoneCurve_position_z, MotionFrame.position.z * setting.position_multiple);
									MotionKey_position_z->SetTime(BoneCurve_position_z, MotionKeyTime);
									BoneCurve_position_z->InsertKey(MotionKey_position_z);
									tag_data->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_no, MotionFrame.interpolator_z);
								}
								if (Is_rotatable)
								{
									Vector rotation = QuaternionToEuler(MotionFrame.rotation);
									CKey* MotionKey_rotation_x = CKey::Alloc(); /* _rotation_x */
									MotionKey_rotation_x->SetValue(BoneCurve_rotation_x, rotation.x);
									MotionKey_rotation_x->SetTime(BoneCurve_rotation_x, MotionKeyTime);
									BoneCurve_rotation_x->InsertKey(MotionKey_rotation_x);
									CKey* MotionKey_rotation_y = CKey::Alloc(); /* _rotation_y */
									MotionKey_rotation_y->SetValue(BoneCurve_rotation_y, rotation.y);
									MotionKey_rotation_y->SetTime(BoneCurve_rotation_y, MotionKeyTime);
									BoneCurve_rotation_y->InsertKey(MotionKey_rotation_y);
									CKey* MotionKey_rotation_z = CKey::Alloc(); /* _rotation_z */
									MotionKey_rotation_z->SetValue(BoneCurve_rotation_z, rotation.z);
									MotionKey_rotation_z->SetTime(BoneCurve_rotation_z, MotionKeyTime);
									BoneCurve_rotation_z->InsertKey(MotionKey_rotation_z);
									tag_data->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_no,MotionFrame.interpolator_r);
								}
							}
							tag_data->UpdateAllInterpolator();
							bone_cnt++;
						}
					}
				}
			}
			else {
				g_spinlock.Lock();
				not_find_bone_S.Append(motion_bone_name) iferr_return;
				g_spinlock.Unlock();
			}
			context.localCount++;
			if (GeIsMainThread())
			{
				StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
				StatusSetSpin();
			}
			return(maxon::OK);
	}, [&insideCount, &motion_frame_bone_number](LocalData& context)
	{
		insideCount += context.localCount;
		if (GeIsMainThread())
			StatusSetText("Import bone " + String::IntToString(insideCount) + " of " + String::IntToString(motion_frame_bone_number));
	}) iferr_return;
		}
	}
	motion_bone_name_array.Reset();

	/*ImportMorph*/
	Int				morph_cnt = 0;
	Int				motion_frame_morph_number = motion_morph_name_array.GetCount();
	String				motion_frame_morph_number_S = String::IntToString(motion_frame_morph_number);
	maxon::BaseArray<String>	not_find_morph_S;
	if (setting.import_morph == true) {

		insideCount = 0;
		maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, motion_frame_morph_number - 1,
			[](LocalData& context)
			{
				context.localCount = 0;
			},
			[&MorphFrameList_map, &motion_morph_name_array, &morph_name_map,
				&morph_cnt, &not_find_morph_S, &motion_frame_morph_number_S, &setting](const Int motion_morph_name_index, LocalData& context)->maxon::Result<void>
			{
				iferr_scope;
				String morph_motion_name = motion_morph_name_array[motion_morph_name_index];
				mmd::VMD_Morph			MorphFrame;
				maxon::BaseList<mmd::VMD_Morph>* MorphFrameList = (MorphFrameList_map.Find(morph_motion_name)->GetValue());
				auto morph_ptr = morph_name_map.Find(morph_motion_name);
				if (morph_ptr != nullptr)
				{
					for (morph_id_tag& morph_id_tag_data : *morph_ptr->GetValue())
					{
						DescID	morphID = morph_id_tag_data.id;
						BaseTag* pose_morph_tag = morph_id_tag_data.tag;
						CTrack* MorphTrack = pose_morph_tag->FindCTrack(morphID);
						if (MorphTrack == nullptr)
						{
							MorphTrack = CTrack::Alloc(pose_morph_tag, morphID);
							if (MorphTrack == nullptr)
							{
								return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
							}
							pose_morph_tag->InsertTrackSorted(MorphTrack);
						}
						CCurve* MorphCurve = MorphTrack->GetCurve();
						Int	morph_frame_number = MorphFrameList->GetCount();
						for (Int morph_index = 0; morph_index < morph_frame_number; morph_index++)
						{
							MorphFrame = (*MorphFrameList)[morph_index];
							CKey* MorphKey = CKey::Alloc();
							MorphKey->SetTime(MorphCurve, BaseTime(MorphFrame.frame_no + setting.time_offset, 30.));
							MorphKey->SetValue(MorphCurve, MorphFrame.weight);
							MorphCurve->InsertKey(MorphKey);
						}
						morph_cnt++;
					}
				}
				else {
					g_spinlock.Lock();
					not_find_morph_S.Append(morph_motion_name) iferr_return;
					g_spinlock.Unlock();
				}
				context.localCount++;
				if (GeIsMainThread())
				{
					StatusSetText("Import motion of morph " + String::IntToString(morph_cnt) + "/" + motion_frame_morph_number_S);
					StatusSetSpin();
				}
				return(maxon::OK);
			}, [&insideCount, &motion_frame_morph_number](LocalData& context)
			{
				insideCount += context.localCount;
				if (GeIsMainThread()) {
					StatusSetText("Import morph " + String::IntToString(insideCount) + " of " + String::IntToString(motion_frame_morph_number));
				}
			}) iferr_return;
	}
	motion_morph_name_array.Reset();

	/*ImportMotion*/
	if (setting.import_model_info == true)
	{
		CTrack* ModelEditorDisplayTrack = SelectObject->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
		if (ModelEditorDisplayTrack == nullptr)
		{
			ModelEditorDisplayTrack = CTrack::Alloc(SelectObject, ID_BASEOBJECT_VISIBILITY_EDITOR);
			if (ModelEditorDisplayTrack == nullptr) 
			{
				EXIT_FromFileImportMotions
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
			}
			SelectObject->InsertTrackSorted(ModelEditorDisplayTrack);
		}
		CCurve* ModelEditorDisplayCurve = ModelEditorDisplayTrack->GetCurve();
		CTrack* ModelRenderDisplayTrack = SelectObject->FindCTrack(ID_BASEOBJECT_VISIBILITY_RENDER);
		if (ModelRenderDisplayTrack == nullptr)
		{
			ModelRenderDisplayTrack = CTrack::Alloc(SelectObject, ID_BASEOBJECT_VISIBILITY_RENDER);
			if (ModelRenderDisplayTrack == nullptr) 
			{
				EXIT_FromFileImportMotions
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
			}
			SelectObject->InsertTrackSorted(ModelRenderDisplayTrack);
		}
		CCurve* ModelRenderDisplayCurve = ModelRenderDisplayTrack->GetCurve();
		const Int ModelFrameNumber = mmd_animation->model_frames.GetCount();
		for (Int model_frame_index = 0; model_frame_index < ModelFrameNumber; model_frame_index++)
		{
			StatusSetSpin();
			const mmd::VMD_Model& model_frame = mmd_animation->model_frames[model_frame_index];
			BaseTime		time = BaseTime(model_frame.frame_no + setting.time_offset, 30.);
			CKey* ModelEditorDisplayKey = CKey::Alloc();
			ModelEditorDisplayKey->SetTime(ModelEditorDisplayCurve, time);
			ModelEditorDisplayKey->SetValue(ModelEditorDisplayCurve,!model_frame.show);
			ModelEditorDisplayCurve->InsertKey(ModelEditorDisplayKey);
			CKey* ModelRenderDisplayKey = CKey::Alloc();
			ModelRenderDisplayKey->SetTime(ModelRenderDisplayCurve, time);
			ModelRenderDisplayKey->SetValue(ModelRenderDisplayCurve, !model_frame.show);
			ModelRenderDisplayCurve->InsertKey(ModelRenderDisplayKey);
			for (const mmd::VMD_IkInfo& ikInfo : model_frame.ik_Infos)
			{
				auto ikTagListPtr = ik_tag_map.Find(ikInfo.name);
				if (ikTagListPtr != nullptr)
				{
					maxon::BaseList<BaseTag*>* ikTagList = ikTagListPtr->GetValue();
					for (BaseTag* ikTag : *ikTagList)
					{
						CTrack* IKEnableTrack = ikTag->FindCTrack(ID_CA_IK_TAG_ENABLE);
						if (IKEnableTrack == nullptr) {
							IKEnableTrack = CTrack::Alloc(ikTag, ID_CA_IK_TAG_ENABLE);
							if (IKEnableTrack == nullptr) 
							{
								EXIT_FromFileImportMotions
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
							}
							ikTag->InsertTrackSorted(IKEnableTrack);
						}
						CCurve* IKEnableCurve = IKEnableTrack->GetCurve();
						CKey* IKEnableKey = CKey::Alloc();
						IKEnableKey->SetTime(IKEnableCurve, time);
						IKEnableKey->SetGeData(IKEnableCurve, ikInfo.enable);
						IKEnableCurve->InsertKey(IKEnableKey);
					}
				}
			}
		}
	}

	timing.Stop();
	StatusClear();
	doc->SetMaxTime(BaseTime(MaxTime, 30.));
	doc->SetLoopMaxTime(BaseTime(MaxTime, 30.));
	EventAdd(EVENT::NONE);
	doc->SetTime(BaseTime(1, 30.));
	doc->SetTime(BaseTime(0, 30.));
	String report = GeLoadString(IDS_MES_IMPORT_MOT_OK, String::IntToString(bone_cnt), String::IntToString(morph_cnt), String::IntToString(motion_frame_bone_number + motion_frame_morph_number), String::FloatToString(timing.GetMilliseconds())) + "\n";
	if (setting.detail_report == 1)
	{
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
	return(maxon::OK);
}


maxon::Result<void> mmd::VMDAnimation::FromDocumentExportMotions(VMD_Motions_export_settings setting) {
	iferr_scope;
	Filename		fn;
	BaseDocument* doc = GetActiveDocument();
	setting.position_multiple = 1.0 / setting.position_multiple;
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	BaseObject* select_object = doc->GetActiveObject();
	if (select_object == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::SAVE, GeLoadString(IDS_MES_SAVEFILE)))
	{
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s))))
	{
		fn.SetSuffix("vmd"_s);
	}
	
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	maxon::UniqueRef<mmd::VMDAnimation> mmd_animation = NewObj(mmd::VMDAnimation)iferr_return;
	mmd_animation->ModelName = select_object->GetName();
	mmd_animation->IsCamera = false;
	maxon::HashSet<bone_obj_tag>	bone_set;
	maxon::HashSet<morph_id_tag>	morph_set;
	maxon::HashSet<BaseTag*>		ik_tag_set;
	maxon::Queue<BaseObject*> nodes;
	nodes.Push(select_object) iferr_return;
	GeData data;
	/*Walk through the scene, inserting bones and tags into the Set.*/
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *(nodes.Pop()); 
		while (node != nullptr)
		{
			if (node->GetType() == Ojoint)
			{
				BaseTag* node_tag = node->GetTag(ID_T_MMD_BONE);
				if (node_tag != nullptr)
				{
					TMMDBone* pmx_bone_tag_data = node_tag->GetNodeData<TMMDBone>();
					const Int	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
					for (Int index = 0; index < BoneMorphCount; index++)
					{
						bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
						morph_set.Insert(morph_id_tag{ bone_morph.strength_id, node_tag }) iferr_return;
					}
					node_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
					bone_set.Insert(bone_obj_tag{ node, node_tag }) iferr_return;
				}
				else {
					bone_set.Insert(bone_obj_tag{ node, nullptr }) iferr_return;
				}
				/*The 1019561 is ik tag id.*/
				BaseTag* node_ik_tag = node->GetTag(1019561);
				if (node_ik_tag != nullptr)
				{
					ik_tag_set.Insert(node_ik_tag) iferr_return;
				}
			}
			BaseTag* const tag = node->GetTag(Tposemorph);
			if (tag != nullptr)
			{
				CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(tag);
				const Int kMorphCount = pose_morph_tag->GetMorphCount();
				/*Because the data with an index of 0 is a basic deformation, traversal starts at 1.*/
				for (Int index = 1; index < kMorphCount; index++)
				{
					morph_set.Insert(morph_id_tag{ pose_morph_tag->GetMorphID(index), tag ,pose_morph_tag->GetMorph(index)->GetName() }) iferr_return;
				}
			}
			nodes.Push(node->GetDown()) iferr_return;
			if (node != select_object)
			{
				node = node->GetNext();
			}
			else {
				break;
			}
		}
	}
	nodes.Reset();
	doc->SetTime(BaseTime(0.));
	const Int32 kFps = doc->GetFps();
	if (setting.export_motion == true) {
		if(setting.use_bake==true){
			for (const bone_obj_tag& bone : bone_set)
			{
				String  bone_name = bone.obj->GetName();		
				CCurve* curve_position_x = nullptr;
				CCurve* curve_position_y = nullptr;
				CCurve* curve_position_z = nullptr;
				CCurve* curve_rotation_x = nullptr;
				CCurve* curve_rotation_y = nullptr;
				CCurve* curve_rotation_z = nullptr;
				register BaseTime kEndFrame = BaseTime(0.);
				CTrack* track_position_x = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
				if (track_position_x != nullptr) {
					curve_position_x = track_position_x->GetCurve();
					 maxon::SetMax(kEndFrame,curve_position_x->GetEndTime());
				}
				CTrack* track_position_y = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
				if (track_position_y != nullptr) {
					curve_position_y = track_position_y->GetCurve();
					maxon::SetMax(kEndFrame, curve_position_y->GetEndTime());
				}
				CTrack* track_position_z = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
				if (track_position_z != nullptr) {
					curve_position_z = track_position_z->GetCurve();
					maxon::SetMax(kEndFrame, curve_position_z->GetEndTime());
				}
				CTrack* track_rotation_x = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
				if (track_rotation_x != nullptr) {
					curve_rotation_x = track_rotation_x->GetCurve();
					maxon::SetMax(kEndFrame, curve_rotation_x->GetEndTime());
				}
				CTrack* track_rotation_y = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
				if (track_rotation_y != nullptr) {
					curve_rotation_y = track_rotation_y->GetCurve();
					maxon::SetMax(kEndFrame, curve_rotation_y->GetEndTime());
				}
				CTrack* track_rotation_z = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
				if (track_rotation_z != nullptr) {
					curve_rotation_z = track_rotation_z->GetCurve();
					maxon::SetMax(kEndFrame, curve_rotation_z->GetEndTime());
				}				
				mmd::VMD_Motion* vmd_motion_data = nullptr;
				register const BaseTime kTimeOne = BaseTime(1, kFps);
				if ((curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr) && (curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr)) 
				{
					/*None of the animations can be found. Skip it.*/
					continue;
				}
				else if (curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr)
				{
					/*No position animation, read current position.*/
					Vector bone_position = bone.obj->GetRelPos();
					Vector rotation = Vector();
					for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
					{
						StatusSetSpin();
						vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
						vmd_motion_data->bone_name = bone_name;
						vmd_motion_data->frame_no = maxon::SafeConvert<UInt32>(time_on.GetFrame(kFps) + setting.time_offset);
						vmd_motion_data->position.x = bone_position.x;
						vmd_motion_data->position.y = bone_position.y;
						vmd_motion_data->position.z = bone_position.z;
						rotation.x = curve_rotation_x->GetValue(time_on);
						rotation.y = curve_rotation_y->GetValue(time_on);
						rotation.z = curve_rotation_z->GetValue(time_on);
						vmd_motion_data->rotation = EulerToQuaternion(rotation);
						/*The interpolation curve is linear and the default values are used.*/
						mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
					}
				}
				else if (curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr) 
				{
					/*No rotation animation, read current rotation.*/
					Vector4d32 bone_rotation = EulerToQuaternion(bone.obj->GetRelRot());
					for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
					{
						StatusSetSpin();
						vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
						vmd_motion_data->bone_name = bone_name;
						vmd_motion_data->frame_no = maxon::SafeConvert<UInt32>(time_on.GetFrame(kFps) + setting.time_offset);
						vmd_motion_data->position.x = curve_position_x->GetValue(time_on) * setting.position_multiple;
						vmd_motion_data->position.y = curve_position_y->GetValue(time_on) * setting.position_multiple;
						vmd_motion_data->position.z = curve_position_z->GetValue(time_on) * setting.position_multiple;	
						vmd_motion_data->rotation = bone_rotation;
						/*The interpolation curve is linear and the default values are used.*/
						mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
					}
				}
				else
				{
					/*Can find all the animations.*/
					Vector rotation = Vector();
					for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
					{
						StatusSetSpin();
						vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
						vmd_motion_data->bone_name = bone_name;
						vmd_motion_data->frame_no = maxon::SafeConvert<UInt32>(time_on.GetFrame(kFps) + setting.time_offset);
						vmd_motion_data->position.x = curve_position_x->GetValue(time_on) * setting.position_multiple;
						vmd_motion_data->position.y = curve_position_y->GetValue(time_on) * setting.position_multiple;
						vmd_motion_data->position.z = curve_position_z->GetValue(time_on) * setting.position_multiple;
						rotation.x = curve_rotation_x->GetValue(time_on);
						rotation.y = curve_rotation_y->GetValue(time_on);
						rotation.z = curve_rotation_z->GetValue(time_on);
						vmd_motion_data->rotation = EulerToQuaternion(rotation);
						/*The interpolation curve is linear and the default values are used.*/
						mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
					}
				}
			}
		}
		else {
			for (const bone_obj_tag& bone : bone_set)
			{
				if (bone.tag != nullptr)
				{
					GeData ge_data;
					bone.tag->GetParameter(PMX_BONE_NAME_LOCAL, ge_data, DESCFLAGS_GET::NONE);
					TMMDBone* bone_tag_data = bone.tag->GetNodeData<TMMDBone>();
					String  bone_name = ge_data.GetString();
					/*
					TODO:
					bone_tag_data->AutoRegisterKeyFrame(setting.use_rotation);
					*/
					CCurve* curve_position_x = nullptr;
					CCurve* curve_position_y = nullptr;
					CCurve* curve_position_z = nullptr;
					CCurve* curve_rotation_x = nullptr;
					CCurve* curve_rotation_y = nullptr;
					CCurve* curve_rotation_z = nullptr;
					CTrack* track_position_x = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
					if (track_position_x != nullptr) {
						curve_position_x = track_position_x->GetCurve();
					}
					CTrack* track_position_y = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
					if (track_position_y != nullptr) {
						curve_position_y = track_position_y->GetCurve();
					}
					CTrack* track_position_z = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
					if (track_position_z != nullptr) {
						curve_position_z = track_position_z->GetCurve();
					}
					CTrack* track_rotation_x = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
					if (track_rotation_x != nullptr) {
						curve_rotation_x = track_rotation_x->GetCurve();
					}
					CTrack* track_rotation_y = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
					if (track_rotation_y != nullptr) {
						curve_rotation_y = track_rotation_y->GetCurve();
					}
					CTrack* track_rotation_z = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
					if (track_rotation_z != nullptr) {
						curve_rotation_z = track_rotation_z->GetCurve();
					}
					CKey* key = nullptr;
					mmd::VMD_Motion* vmd_motion_data = nullptr;
					const Int32 bone_key_count = curve_position_x->GetKeyCount();
					if ((curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr) && (curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr))
					{
						/*None of the animations can be found. Skip it.*/
						continue;
					}
					else if (curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr)
					{
						/*No position animation, read current position.*/
						Vector bone_position = bone.obj->GetRelPos();
						Vector rotation = Vector();
						for (Int32 key_index = 0; key_index < bone_key_count; key_index++)
						{
							vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
							vmd_motion_data->bone_name = bone_name;
							key = curve_rotation_x->GetKey(key_index);
							vmd_motion_data->frame_no = key->GetTime().GetFrame(30.);
							vmd_motion_data->position.x = bone_position.x;
							vmd_motion_data->position.y = bone_position.y;
							vmd_motion_data->position.z = bone_position.z;
							key = curve_rotation_x->GetKey(key_index);
							rotation.x = key->GetValue();
							key = curve_rotation_y->GetKey(key_index);
							rotation.y = key->GetValue();
							key = curve_rotation_z->GetKey(key_index);
							rotation.z = key->GetValue();
							vmd_motion_data->rotation = EulerToQuaternion(rotation);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_XCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_x);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_YCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_y);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_ZCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_z);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_RCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_r);
							vmd_motion_data->frame_no += setting.time_offset;
							mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
						}
					}
					else if (curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr)
					{
						/*No rotation animation, read current rotation.*/
						Vector4d32 bone_rotation = EulerToQuaternion(bone.obj->GetRelRot());
						for (Int32 key_index = 0; key_index < bone_key_count; key_index++)
						{
							vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
							vmd_motion_data->bone_name = bone_name;
							key = curve_position_x->GetKey(key_index);
							vmd_motion_data->frame_no = key->GetTime().GetFrame(30.);
							vmd_motion_data->position.x = key->GetValue() * setting.position_multiple;
							key = curve_position_y->GetKey(key_index);
							vmd_motion_data->position.y = key->GetValue() * setting.position_multiple;
							key = curve_position_z->GetKey(key_index);
							vmd_motion_data->position.z = key->GetValue() * setting.position_multiple;
							vmd_motion_data->rotation = bone_rotation;
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_XCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_x);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_YCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_y);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_ZCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_z);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_RCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_r);
							vmd_motion_data->frame_no += setting.time_offset;
							mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
						}
					}
					else
					{
						/*Can find all the animations.*/
						Vector rotation = Vector();
						for (Int32 key_index = 0; key_index < bone_key_count; key_index++)
						{
							vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
							vmd_motion_data->bone_name = bone_name;
							key = curve_position_x->GetKey(key_index);
							vmd_motion_data->frame_no = key->GetTime().GetFrame(30.);
							vmd_motion_data->position.x = key->GetValue() * setting.position_multiple;
							key = curve_position_y->GetKey(key_index);
							vmd_motion_data->position.y = key->GetValue() * setting.position_multiple;
							key = curve_position_z->GetKey(key_index);
							vmd_motion_data->position.z = key->GetValue() * setting.position_multiple;
							key = curve_rotation_x->GetKey(key_index);
							rotation.x = key->GetValue();
							key = curve_rotation_y->GetKey(key_index);
							rotation.y = key->GetValue();
							key = curve_rotation_z->GetKey(key_index);
							rotation.z = key->GetValue();
							vmd_motion_data->rotation = EulerToQuaternion(rotation);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_XCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_x);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_YCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_y);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_ZCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_z);
							bone_tag_data->GetInterpolator(PMX_BONE_TAG_RCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_r);
							vmd_motion_data->frame_no += setting.time_offset;
							mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
						}
					}
				
				}
				else {
					String  bone_name = bone.obj->GetName();
					const Bool kIsQuaternionRotation = bone.obj->IsQuaternionRotationMode();
					if (kIsQuaternionRotation == true) {
						bone.obj->SetQuaternionRotationMode(false, false);
					}
					CCurve* curve_position_x = nullptr;
					CCurve* curve_position_y = nullptr;
					CCurve* curve_position_z = nullptr;
					CCurve* curve_rotation_x = nullptr;
					CCurve* curve_rotation_y = nullptr;
					CCurve* curve_rotation_z = nullptr;
					register BaseTime kEndFrame = BaseTime(0.);
					CTrack* track_position_x = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
					if (track_position_x != nullptr) {
						curve_position_x = track_position_x->GetCurve();
						maxon::SetMax(kEndFrame, curve_position_x->GetEndTime());
					}
					CTrack* track_position_y = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
					if (track_position_y != nullptr) {
						curve_position_y = track_position_y->GetCurve();
						maxon::SetMax(kEndFrame, curve_position_y->GetEndTime());
					}
					CTrack* track_position_z = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
					if (track_position_z != nullptr) {
						curve_position_z = track_position_z->GetCurve();
						maxon::SetMax(kEndFrame, curve_position_z->GetEndTime());
					}
					CTrack* track_rotation_x = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
					if (track_rotation_x != nullptr) {
						curve_rotation_x = track_rotation_x->GetCurve();
						maxon::SetMax(kEndFrame, curve_rotation_x->GetEndTime());
					}
					CTrack* track_rotation_y = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
					if (track_rotation_y != nullptr) {
						curve_rotation_y = track_rotation_y->GetCurve();
						maxon::SetMax(kEndFrame, curve_rotation_y->GetEndTime());
					}
					CTrack* track_rotation_z = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
					if (track_rotation_z != nullptr) {
						curve_rotation_z = track_rotation_z->GetCurve();
						maxon::SetMax(kEndFrame, curve_rotation_z->GetEndTime());
					}
					mmd::VMD_Motion* vmd_motion_data = nullptr;
					register const BaseTime kTimeOne = BaseTime(1, kFps);
					if ((curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr) && (curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr))
					{
						/*None of the animations can be found. Skip it.*/
						continue;
					}
					else if (curve_position_x == nullptr || curve_position_y == nullptr || curve_position_z == nullptr)
					{
						/*No position animation, read current position.*/
						Vector bone_position = bone.obj->GetRelPos();
						Vector rotation = Vector();
						for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
						{
							StatusSetSpin();
							vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
							vmd_motion_data->bone_name = bone_name;
							vmd_motion_data->frame_no = maxon::SafeConvert<UInt32>(time_on.GetFrame(kFps) + setting.time_offset);
							vmd_motion_data->position.x = bone_position.x;
							vmd_motion_data->position.y = bone_position.y;
							vmd_motion_data->position.z = bone_position.z;
							rotation.x = curve_rotation_x->GetValue(time_on);
							rotation.y = curve_rotation_y->GetValue(time_on);
							rotation.z = curve_rotation_z->GetValue(time_on);
							vmd_motion_data->rotation = EulerToQuaternion(rotation);
							/*The interpolation curve is linear and the default values are used.*/
							mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
						}
					}
					else if (curve_rotation_x == nullptr || curve_rotation_y == nullptr || curve_rotation_z == nullptr)
					{
						/*No rotation animation, read current rotation.*/
						Vector4d32 bone_rotation = EulerToQuaternion(bone.obj->GetRelRot());
						for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
						{
							StatusSetSpin();
							vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
							vmd_motion_data->bone_name = bone_name;
							vmd_motion_data->frame_no = maxon::SafeConvert<UInt32>(time_on.GetFrame(kFps) + setting.time_offset);
							vmd_motion_data->position.x = curve_position_x->GetValue(time_on) * setting.position_multiple;
							vmd_motion_data->position.y = curve_position_y->GetValue(time_on) * setting.position_multiple;
							vmd_motion_data->position.z = curve_position_z->GetValue(time_on) * setting.position_multiple;
							vmd_motion_data->rotation = bone_rotation;
							/*The interpolation curve is linear and the default values are used.*/
							mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
						}
					}
					else
					{
						/*Can find all the animations.*/
						Vector rotation = Vector();
						for (register BaseTime time_on = BaseTime(); time_on < kEndFrame; time_on = time_on + kTimeOne)
						{
							StatusSetSpin();
							vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
							vmd_motion_data->bone_name = bone_name;
							vmd_motion_data->frame_no = maxon::SafeConvert<UInt32>(time_on.GetFrame(kFps) + setting.time_offset);
							vmd_motion_data->position.x = curve_position_x->GetValue(time_on) * setting.position_multiple;
							vmd_motion_data->position.y = curve_position_y->GetValue(time_on) * setting.position_multiple;
							vmd_motion_data->position.z = curve_position_z->GetValue(time_on) * setting.position_multiple;
							rotation.x = curve_rotation_x->GetValue(time_on);
							rotation.y = curve_rotation_y->GetValue(time_on);
							rotation.z = curve_rotation_z->GetValue(time_on);
							vmd_motion_data->rotation = EulerToQuaternion(rotation);
							/*The interpolation curve is linear and the default values are used.*/
							mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
						}
					}
					if (kIsQuaternionRotation == true) {
						bone.obj->SetQuaternionRotationMode(true, false);
					}
				}
			}
		}
	}

	if (setting.export_morph == true) {
		for (const morph_id_tag& morph : morph_set) {
			CTrack* morph_track = morph.tag->FindCTrack(morph.id);
			if (morph_track != nullptr) {
				CCurve* morph_curve = morph_track->GetCurve();
				if (morph_curve != nullptr) {
					const Int32 kMorphKeyCount = morph_curve->GetKeyCount();
					for (Int32 key_index = 0; key_index < kMorphKeyCount; key_index++) {
						mmd::VMD_Morph* vmd_morph_data = NewObj(mmd::VMD_Morph)iferr_return;
						CKey* key = morph_curve->GetKey(key_index);
						vmd_morph_data->frame_no = key->GetTime().GetFrame(30.) + setting.time_offset;
						vmd_morph_data->weight = key->GetValue();
						vmd_morph_data->morph_name = morph.name;
						mmd_animation->morph_frames.AppendPtr(vmd_morph_data)iferr_return;
					}
				}
			}
		}
	}

	if (setting.export_model_info == true)
	{
		maxon::HashSet<MyBaseTime> time_set;

		CTrack* ModelEditorDisplayTrack = select_object->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
		if (ModelEditorDisplayTrack != nullptr)
		{
			CCurve* ModelEditorDisplayCurve = ModelEditorDisplayTrack->GetCurve();
			const Int32 ModelFrameNumber = ModelEditorDisplayCurve->GetKeyCount();
			for (Int32 model_frame_index = 0; model_frame_index < ModelFrameNumber; model_frame_index++)
			{
				time_set.Insert(ModelEditorDisplayCurve->GetKey(model_frame_index)->GetTime())iferr_return;
			}

			for (BaseTag* ikTag : ik_tag_set) {
				CTrack* IKEnableTrack = ikTag->FindCTrack(ID_CA_IK_TAG_ENABLE);
				if (IKEnableTrack != nullptr) {
					CCurve* IKEnableCurve = IKEnableTrack->GetCurve();
					Int32 IKEnableKeyCount = IKEnableCurve->GetKeyCount();
					for (Int32 IKEnableKeyIndex = 0; IKEnableKeyIndex < IKEnableKeyCount; IKEnableKeyIndex++) {
						time_set.Insert(IKEnableCurve->GetKey(IKEnableKeyIndex)->GetTime())iferr_return;
					}
				}
			}

			for (const BaseTime& time : time_set)
			{
				mmd::VMD_Model* model_frame = NewObj(mmd::VMD_Model)iferr_return;
				model_frame->frame_no = time.GetFrame(kFps) + setting.time_offset;
				if (ModelEditorDisplayCurve->GetValue(time) == 2) {
					model_frame->show = false;
				}
				else {
					model_frame->show = true;
				}
				for (BaseTag* ikTag : ik_tag_set) {
					mmd::VMD_IkInfo* ikInfo = NewObj(mmd::VMD_IkInfo)iferr_return;
					ikTag->GetParameter(ID_CA_IK_TAG_TARGET, data, DESCFLAGS_GET::NONE);
					ikInfo->name = data.GetBaseLink()->GetLink(doc)->GetName();
					CTrack* IKEnableTrack = ikTag->FindCTrack(ID_CA_IK_TAG_ENABLE);
					CCurve* IKEnableCurve = nullptr;
					if (IKEnableTrack == nullptr) {
						IKEnableTrack = CTrack::Alloc(ikTag, ID_CA_IK_TAG_ENABLE);
						if (IKEnableTrack == nullptr)
						{
							return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
						}
						IKEnableCurve = IKEnableTrack->GetCurve();
						IKEnableCurve->AddKey(BaseTime(0.))->SetGeData(IKEnableCurve, 1);
						ikTag->InsertTrackSorted(IKEnableTrack);
					}
					else {
						IKEnableCurve = IKEnableTrack->GetCurve();
					}
					CKey* IKEnableKey = IKEnableCurve->FindKey(time);
					if (IKEnableKey == nullptr) {
						IKEnableKey = IKEnableCurve->AddKey(time);
						if (IKEnableKey == nullptr) {
							return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
						}
					}
					ikInfo->enable = IKEnableKey->GetGeData().GetBool();
					model_frame->ik_Infos.AppendPtr(ikInfo)iferr_return;
				}
				mmd_animation->model_frames.AppendPtr(model_frame)iferr_return;
			}
		}
		else {
			mmd::VMD_Model* model_frame = NewObj(mmd::VMD_Model)iferr_return;
			model_frame->frame_no = setting.time_offset;
			model_frame->show = true;
			for (BaseTag* ikTag : ik_tag_set) {
				mmd::VMD_IkInfo* ikInfo = NewObj(mmd::VMD_IkInfo)iferr_return;
				ikTag->GetParameter(ID_CA_IK_TAG_TARGET, data, DESCFLAGS_GET::NONE);
				ikInfo->name = data.GetBaseLink()->GetLink(doc)->GetName();
				ikInfo->enable = true;
				model_frame->ik_Infos.AppendPtr(ikInfo)iferr_return;
			}
			mmd_animation->model_frames.AppendPtr(model_frame)iferr_return;
		}
	}

	iferr(mmd_animation->SaveToFile(fn))
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR)));
	}
	timing.Stop();
	StatusClear();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_OK, maxon::String::IntToString(mmd_animation->motion_frames.GetCount() + mmd_animation->morph_frames.GetCount() + mmd_animation->model_frames.GetCount()), String::FloatToString(timing.GetMilliseconds())));
	return(maxon::OK);
}


Bool mmd::VMDLoaderData::VMDLoaderCameraDialog::CreateLayout(void)
{
	SetTitle(GeLoadString(IDS_VMD_TOOL_TITLE));
	Images = NewObj(ImagesGUI, "mmd_tool_title.png"_s, 300, 78).GetValue();
	C4DGadget* userAreaGadget = this->AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(78));
	if (userAreaGadget != nullptr)
		this->AttachUserArea((*Images), userAreaGadget);
	GroupBegin(1001, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_CAM_IMPORT_TITLE), 0, 0, 0);
	GroupBorder(BORDER_GROUP_IN);
	GroupBorderSpace(5, 5, 5, 10);
	GroupSpace(2, 5);

	GroupBegin(1002, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
	AddStaticText(100001, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_IMPORT_SIZE), BORDER_NONE);
	AddEditNumberArrows(100002, BFH_LEFT, 250, 10);
	GroupEnd();

	GroupBegin(1003, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
	AddStaticText(100003, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_IMPORT_OFFSET), BORDER_NONE);
	AddEditNumberArrows(100004, BFH_LEFT, 250, 10);
	GroupEnd();


	GroupBegin(1004, BFH_CENTER, 2, 1, ""_s, 0, 350, 10);
	GroupSpace(50, 0);
	AddButton(100005, BFH_CENTER, 100, 30, GeLoadString(IDS_VMD_CAM_IMPORT_BUTTON));
	AddButton(100006, BFH_CENTER, 100, 30, GeLoadString(IDS_MSG_RENAME_CANCEL));
	GroupEnd();
	return(true);
}


Bool mmd::VMDLoaderData::VMDLoaderCameraDialog::InitValues(void)
{
	SetFloat(100002, 8.5);
	SetFloat(100004, 0);
	return(true);
}


Bool mmd::VMDLoaderData::VMDLoaderCameraDialog::Command(Int32 id, const BaseContainer& msg)
{
	iferr_scope;
	switch (id)
	{
	case 100005:
	{
		mmd::VMD_Camera_import_settings setting_;
		setting_.fn = fn;
		setting_.doc = doc;
		GetFloat(100002, setting_.position_multiple);
		GetFloat(100004, setting_.time_offset);
		iferr(mmd::VMDAnimation::FromFileImportCamera(setting_))
		{
			return(false);
		}
		this->Close();
		break;
	}
	case 100006:
	{
		this->Close();
		break;
	}
	default:
		break;
	}
	return(true);
}


Bool mmd::VMDLoaderData::Identify(BaseSceneLoader* node, const Filename& name, UChar* probe, Int32 size)
{
	Char	VMDVersion[30]{ 0 };
	Char	VMDModelName[20]{ 0 };
	CopyMem(probe, VMDVersion, 30);
	CopyMem(probe + 30, VMDModelName, 20);
	if (!(name.CheckSuffix("vmd"_s) || name.CheckSuffix("Vmd"_s) || name.CheckSuffix("VMd"_s) || name.CheckSuffix("VMD"_s) || name.CheckSuffix("vMD"_s) || name.CheckSuffix("vmD"_s)))
	{
		return(false);
	}
	if (strncmp(VMDVersion, "Vocaloid Motion Data file", 26) || strncmp(VMDVersion, "Vocaloid Motion Data 0002", 26))
	{
		String ModelName;
		EncodingConversion::SJIStoUTF8(VMDModelName, ModelName);
		if (ModelName.LexComparePart(L"\u30ab\u30e1\u30e9\u30fb\u7167\u660e"_s, 12, 0) == 0) /* カメラ・照明 */
		{
			IsCamera = 1;
		}
		return(true);
	}
	return(false);
}


FILEERROR mmd::VMDLoaderData::Load(BaseSceneLoader* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags, maxon::String* error, BaseThread* bt)
{
	if (IsCamera)
	{
		VMDLoaderCameraDialog dlg_Camera(name, doc);
		dlg_Camera.Open(DLG_TYPE::MODAL, ID_L_MMD_VMD_IMPORT, -1, -1, 350, 80);
		IsCamera = 0;
	}
	else {
		MessageDialog(GeLoadString(IDS_MES_IMPORT_VMD_CAM_ONLY));
	}
	return(FILEERROR::NONE);
}