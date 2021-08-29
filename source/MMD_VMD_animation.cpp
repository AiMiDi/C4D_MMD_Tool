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

	CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (TrackPX == nullptr)
	{
		TrackPX = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		obj->InsertTrackSorted(TrackPX);
	}
	CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (TrackPY == nullptr)
	{
		TrackPY = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		obj->InsertTrackSorted(TrackPY);
	}
	CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (TrackPZ == nullptr)
	{
		TrackPZ = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		obj->InsertTrackSorted(TrackPZ);
	}
	CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (TrackRX == nullptr)
	{
		TrackRX = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		obj->InsertTrackSorted(TrackRX);
	}
	CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (TrackRY == nullptr)
	{
		TrackRY = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		obj->InsertTrackSorted(TrackRY);
	}
	CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (TrackRZ == nullptr)
	{
		TrackRZ = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		obj->InsertTrackSorted(TrackRZ);
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

	CCurve* CurvePX = TrackPX->GetCurve();
	CCurve* CurvePY = TrackPY->GetCurve();
	CCurve* CurvePZ = TrackPZ->GetCurve();
	CCurve* CurveRX = TrackRX->GetCurve();
	CCurve* CurveRY = TrackRY->GetCurve();
	CCurve* CurveRZ = TrackRZ->GetCurve();
	CCurve* CurveD = TrackD->GetCurve();
	CCurve* CurveV = TrackV->GetCurve();

	/* 确保获取成功 */
	if (CurvePX == nullptr || CurvePY == nullptr || CurvePZ == nullptr || CurveRX == nullptr || CurveRY == nullptr || CurveRZ == nullptr || CurveD == nullptr || CurveV == nullptr)
	{
		return(true);
	}
	Vector RelPos = obj->GetRelPos();
	Vector RelRot = obj->GetRelRot();

	CKey* KeyPX = CurvePX->FindKey(time);
	if (KeyPX == nullptr)
	{
		KeyPX = CurvePX->AddKey(time);
		if (KeyPX == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyPX->SetValue(CurvePX, RelPos.x);
	}
	CKey* KeyPY = CurvePY->FindKey(time);
	if (KeyPY == nullptr)
	{
		KeyPY = CurvePY->AddKey(time);
		if (KeyPY == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyPY->SetValue(CurvePY, RelPos.y);
	}
	CKey* KeyPZ = CurvePZ->FindKey(time);
	if (KeyPZ == nullptr)
	{
		KeyPZ = CurvePZ->AddKey(time);
		if (KeyPZ == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyPZ->SetValue(CurvePZ, RelPos.z);
	}
	CKey* KeyRX = CurveRX->FindKey(time);
	if (KeyRX == nullptr)
	{
		KeyRX = CurveRX->AddKey(time);
		if (KeyRX == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyRX->SetValue(CurveRX, RelRot.x);
	}
	CKey* KeyRY = CurveRY->FindKey(time);
	KeyRY = CurveRY->AddKey(time);
	if (KeyRY == nullptr)
	{
		KeyRY = CurveRY->AddKey(time);
		if (KeyRY == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyRY->SetValue(CurveRY, RelRot.y);
	}
	CKey* KeyRZ = CurveRZ->FindKey(time);
	if (KeyRZ == nullptr)
	{
		KeyRZ = CurveRZ->AddKey(time);
		if (KeyRZ == nullptr)
		{
			return(true);
		}
	}
	else {
		KeyRZ->SetValue(CurveRZ, RelRot.z);
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
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* TrackDistance = cam->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* TrackAOV = cam->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	CTrack* frameTrack = obj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));

	if (TrackPX == nullptr || TrackPY == nullptr || TrackPZ == nullptr || TrackRX == nullptr || TrackRY == nullptr || TrackRZ == nullptr || TrackDistance == nullptr || TrackAOV == nullptr || frameTrack == nullptr)
	{
		return false;
	}

	CCurve* CurvePX = TrackPX->GetCurve();
	CCurve* CurvePY = TrackPY->GetCurve();
	CCurve* CurvePZ = TrackPZ->GetCurve();
	CCurve* CurveRX = TrackRX->GetCurve();
	CCurve* CurveRY = TrackRY->GetCurve();
	CCurve* CurveRZ = TrackRZ->GetCurve();
	CCurve* CurveDistance = TrackDistance->GetCurve();
	CCurve* CurveAOV = TrackAOV->GetCurve();
	CCurve* frameCurve = frameTrack->GetCurve();

	if (CurvePX == nullptr || CurvePY == nullptr || CurvePZ == nullptr || CurveRX == nullptr || CurveRY == nullptr || CurveRZ == nullptr || CurveDistance == nullptr || CurveAOV == nullptr || frameCurve == nullptr)
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

	const Int32 KeyCount = frameCurve->GetKeyCount();
	for (Int32 frame_index = 0; frame_index < KeyCount; frame_index++)
	{
		frame_on = frameCurve->GetKey(frame_index)->GetValue();
		time = BaseTime(frame_on, 30.);
		frame_next = frameCurve->FindKey(BaseTime(frame_on + 1, 30.), nullptr, FINDANIM::RIGHT); /* 加一排除所在的那一帧 */
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
			key = CurvePX->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurvePX->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurvePX, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurvePX, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurvePX, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurvePX, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurvePY->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurvePY->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurvePY, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurvePY, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurvePY, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurvePY, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurvePZ->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurvePZ->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurvePZ, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurvePZ, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurvePZ, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurvePZ, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurveRX->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurveRX->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurveRX, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurveRX, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurveRX, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurveRX, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurveRY->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurveRY->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurveRY, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurveRY, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurveRY, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurveRY, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurveRZ->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurveRZ->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurveRZ, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurveRZ, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurveRZ, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurveRZ, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_D_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurveDistance->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurveDistance->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurveDistance, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurveDistance, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurveDistance, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurveDistance, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_V_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = CurveAOV->FindKey(time);
			if (key != nullptr)
			{
				next_key = CurveAOV->FindKey(next_time);
				if (next_key != nullptr)
				{
					ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					next_key->SetTimeLeft(CurveAOV, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.bx / 127.0), 30.));
					next_key->SetValueLeft(CurveAOV, -ValueOfTwoFrames * ((Float)interpolator.by / 127.0));
					key->SetTimeRight(CurveAOV, BaseTime(TimeOfTwoFrames * ((Float)interpolator.ax / 127.0), 30.));
					key->SetValueRight(CurveAOV, ValueOfTwoFrames * ((Float)interpolator.ay / 127.0));
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
	BaseTime	time = BaseTime(Float(frame_on), 30.);

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

	CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (TrackPX != nullptr)
	{
		CKey* KeyPX = TrackPX->GetCurve()->FindKey(time);
		CKey::Free(KeyPX);
	}
	CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (TrackPY != nullptr)
	{
		CKey* KeyPY = TrackPY->GetCurve()->FindKey(time);
		CKey::Free(KeyPY);
	}
	CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (TrackPZ != nullptr)
	{
		CKey* KeyPZ = TrackPZ->GetCurve()->FindKey(time);
		CKey::Free(KeyPZ);
	}
	CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (TrackRX != nullptr)
	{
		CKey* KeyRX = TrackRX->GetCurve()->FindKey(time);
		CKey::Free(KeyRX);
	}
	CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (TrackRY != nullptr)
	{
		CKey* KeyRY = TrackRY->GetCurve()->FindKey(time);
		CKey::Free(KeyRY);
	}
	CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (TrackRZ != nullptr)
	{
		CKey* KeyRZ = TrackRZ->GetCurve()->FindKey(time);
		CKey::Free(KeyRZ);
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
	CTrack* TrackPX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack::Free(TrackPX);
	CTrack* TrackPY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack::Free(TrackPY);
	CTrack* TrackPZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack::Free(TrackPZ);
	CTrack* TrackRX = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack::Free(TrackRX);
	CTrack* TrackRY = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack::Free(TrackRY);
	CTrack* TrackRZ = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack::Free(TrackRZ);
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
			const GeData oldLineWidth = bd->GetDrawParam(DRAW_PARAMETER_LINEWIDTH);
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
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, oldLineWidth);
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
	BaseObject* SelectObject = nullptr;

	if (setting.str_cam == nullptr) /* 若传入的参数非空则使用传入参数 */
	{
		/* 获取选中对象 */
		SelectObject = doc->GetActiveObject();
		if (SelectObject == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
	}
	else { /* 否则使用选择参数 */
		SelectObject = setting.str_cam;
	}

	/* 判断选中对象类型是否为摄像机 */
	if (SelectObject->GetType() != Ocamera)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_CONVER_TYPE_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	/* 创建转换目标对象 */
	BaseObject* VMDCamera = BaseObject::Alloc(ID_O_MMD_CAMERA);
	if (VMDCamera == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}

	/* 创建要转化摄像机的副本，防止操作破坏原摄像机对象的数据 */
	BaseObject* SelectObjectClone = (BaseObject*)SelectObject->GetClone(COPYFLAGS::NO_HIERARCHY, nullptr);
	VMDCamera->SetName(SelectObjectClone->GetName());
	doc->InsertObject(VMDCamera, nullptr, nullptr);

	/* 获取目标对象内部的数据 */
	mmd::OMMDCamera* VMDCamera_data = VMDCamera->GetNodeData<OMMDCamera>();
	if (!VMDCamera_data->CameraInit())
	{
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	BaseObject* VMDCameraDistance = VMDCamera_data->cam;

	/* 将时间设置为0 */
	doc->SetTime(BaseTime(0.));

	/* 确保每个必要的参数都注册了CTrack，没有则创建一个 */
	CTrack* strTrackPX = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (strTrackPX == nullptr)
	{
		strTrackPX = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		strTrackPX->GetCurve()->AddKey(BaseTime())->SetValue(strTrackPX->GetCurve(), SelectObjectClone->GetRelPos().x);
		SelectObjectClone->InsertTrackSorted(strTrackPX);
	}
	CTrack* strTrackPY = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (strTrackPY == nullptr)
	{
		strTrackPY = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		strTrackPY->GetCurve()->AddKey(BaseTime())->SetValue(strTrackPY->GetCurve(), SelectObjectClone->GetRelPos().y);
		SelectObjectClone->InsertTrackSorted(strTrackPY);
	}
	CTrack* strTrackPZ = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (strTrackPZ == nullptr)
	{
		strTrackPZ = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		strTrackPZ->GetCurve()->AddKey(BaseTime())->SetValue(strTrackPZ->GetCurve(), SelectObjectClone->GetRelPos().z);
		SelectObjectClone->InsertTrackSorted(strTrackPZ);
	}
	CTrack* strTrackRX = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (strTrackRX == nullptr)
	{
		strTrackRX = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		strTrackRX->GetCurve()->AddKey(BaseTime())->SetValue(strTrackRX->GetCurve(), SelectObjectClone->GetRelRot().x);
		SelectObjectClone->InsertTrackSorted(strTrackRX);
	}
	CTrack* strTrackRY = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (strTrackRY == nullptr)
	{
		strTrackRY = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		strTrackRY->GetCurve()->AddKey(BaseTime())->SetValue(strTrackRY->GetCurve(), SelectObjectClone->GetRelRot().y);
		SelectObjectClone->InsertTrackSorted(strTrackRY);
	}
	CTrack* strTrackRZ = SelectObjectClone->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (strTrackRZ == nullptr)
	{
		strTrackRZ = CTrack::Alloc(SelectObjectClone, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		strTrackRZ->GetCurve()->AddKey(BaseTime())->SetValue(strTrackRZ->GetCurve(), SelectObjectClone->GetRelRot().z);
		SelectObjectClone->InsertTrackSorted(strTrackRZ);
	}
	CTrack* strTrackAOV = SelectObjectClone->FindCTrack(DescID(CAMERAOBJECT_APERTURE));
	if (strTrackAOV == nullptr)
	{
		strTrackAOV = CTrack::Alloc(SelectObjectClone, DescID(CAMERAOBJECT_APERTURE));
		strTrackAOV->GetCurve()->AddKey(BaseTime())->SetValue(strTrackAOV->GetCurve(), ((CameraObject*)SelectObjectClone)->GetAperture());
		SelectObjectClone->InsertTrackSorted(strTrackAOV);
	}

	/* 确保生成成功 */
	if (strTrackPX == nullptr || strTrackPY == nullptr || strTrackPZ == nullptr || strTrackRX == nullptr || strTrackRY == nullptr || strTrackRZ == nullptr || strTrackAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}

	/* 获取曲线对象 */
	CCurve* strCurvePX = strTrackPX->GetCurve();
	CCurve* strCurvePY = strTrackPY->GetCurve();
	CCurve* strCurvePZ = strTrackPZ->GetCurve();
	CCurve* strCurveRX = strTrackRX->GetCurve();
	CCurve* strCurveRY = strTrackRY->GetCurve();
	CCurve* strCurveRZ = strTrackRZ->GetCurve();
	CCurve* strCurveAOV = strTrackAOV->GetCurve();

	/* 确保获取成功 */
	if (strCurvePX == nullptr || strCurvePY == nullptr || strCurvePZ == nullptr || strCurveRX == nullptr || strCurveRY == nullptr || strCurveRZ == nullptr || strCurveAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}

	Int32 frame_count_px = strCurvePX->GetKeyCount();
	Int32 frame_count_py = strCurvePY->GetKeyCount();
	Int32 frame_count_pz = strCurvePZ->GetKeyCount();
	Int32 frame_count_rx = strCurveRX->GetKeyCount();
	Int32 frame_count_ry = strCurveRY->GetKeyCount();
	Int32 frame_count_rz = strCurveRZ->GetKeyCount();
	Int32 frame_count_v = strCurveAOV->GetKeyCount();

	/* 将所有参数的全部关键帧所在帧置入数组（frame_arr） */
	maxon::HashSet<MyBaseTime> frame_set;
	Int32		frame_count = strCurvePX->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurvePX->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = strCurvePY->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurvePY->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = strCurvePZ->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurvePZ->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = strCurveRX->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurveRX->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = strCurveRY->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurveRY->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = strCurveRZ->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurveRZ->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = strCurveAOV->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(strCurveAOV->GetKey(i)->GetTime())iferr_return;
	}

	/* 为目标对象生成动画轨迹 */
	CTrack* CameraTrackPX = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* CameraTrackPY = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* CameraTrackPZ = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* CameraTrackRX = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* CameraTrackRY = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* CameraTrackRZ = CTrack::Alloc(VMDCamera, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* CameraTrackDistance = CTrack::Alloc(VMDCameraDistance, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* CameraTrackAOV = CTrack::Alloc(VMDCameraDistance, DescID(CAMERAOBJECT_APERTURE));

	/* 确保生成成功 */
	if (CameraTrackPX == nullptr || CameraTrackPY == nullptr || CameraTrackPZ == nullptr || CameraTrackRX == nullptr || CameraTrackRY == nullptr || CameraTrackRZ == nullptr || CameraTrackDistance == nullptr || CameraTrackAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	CCurve* CameraCurvePX = CameraTrackPX->GetCurve();
	CCurve* CameraCurvePY = CameraTrackPY->GetCurve();
	CCurve* CameraCurvePZ = CameraTrackPZ->GetCurve();
	CCurve* CameraCurveRX = CameraTrackRX->GetCurve();
	CCurve* CameraCurveRY = CameraTrackRY->GetCurve();
	CCurve* CameraCurveRZ = CameraTrackRZ->GetCurve();
	CCurve* CameraCurveDistance = CameraTrackDistance->GetCurve();
	CCurve* CameraCurveAOV = CameraTrackAOV->GetCurve();

	/* 确保获取成功 */
	if (CameraCurvePX == nullptr || CameraCurvePY == nullptr || CameraCurvePZ == nullptr || CameraCurveRX == nullptr || CameraCurveRY == nullptr || CameraCurveRZ == nullptr || CameraCurveDistance == nullptr || CameraCurveAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	/* 将生成的动画轨迹插入目标对象 */
	VMDCamera->InsertTrackSorted(CameraTrackPX);
	VMDCamera->InsertTrackSorted(CameraTrackPY);
	VMDCamera->InsertTrackSorted(CameraTrackPZ);
	VMDCamera->InsertTrackSorted(CameraTrackRX);
	VMDCamera->InsertTrackSorted(CameraTrackRY);
	VMDCamera->InsertTrackSorted(CameraTrackRZ);
	VMDCameraDistance->InsertTrackSorted(CameraTrackDistance);
	VMDCameraDistance->InsertTrackSorted(CameraTrackAOV);

	/* 确保每个参数在同一帧都注册了关键帧（根据frame_arr查找） */
	for (const BaseTime& frame_time : frame_set)
	{
		if (strCurvePX->FindKey(frame_time) == nullptr)
		{
			strCurvePX->AddKeyAdaptTangent(frame_time,false);
		}
		if (strCurvePY->FindKey(frame_time) == nullptr)
		{
			strCurvePY->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurvePZ->FindKey(frame_time) == nullptr)
		{
			strCurvePZ->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveRX->FindKey(frame_time) == nullptr)
		{
			strCurveRX->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveRY->FindKey(frame_time) == nullptr)
		{
			strCurveRY->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveRZ->FindKey(frame_time) == nullptr)
		{
			strCurveRZ->AddKeyAdaptTangent(frame_time, false);
		}
		if (strCurveAOV->FindKey(frame_time) == nullptr)
		{
			strCurveAOV->AddKeyAdaptTangent(frame_time, false);
		}
		if (CameraCurveDistance->FindKey(frame_time) == nullptr)
		{
			CameraCurveDistance->AddKeyAdaptTangent(frame_time, false);
		}
	}

	/* 转换移动和旋转写入对象，添加关键帧数据 */
	for (const BaseTime& frame_time : frame_set)
	{
		CameraCurvePX->AddKey(frame_time)->SetValue(CameraCurvePX, strCurvePX->FindKey(frame_time)->GetValue());
		CameraCurvePY->AddKey(frame_time)->SetValue(CameraCurvePY, strCurvePY->FindKey(frame_time)->GetValue());
		CameraCurvePZ->AddKey(frame_time)->SetValue(CameraCurvePZ, strCurvePZ->FindKey(frame_time)->GetValue());
		CameraCurveRX->AddKey(frame_time)->SetValue(CameraCurveRX, strCurveRX->FindKey(frame_time)->GetValue());
		CameraCurveRY->AddKey(frame_time)->SetValue(CameraCurveRY, strCurveRY->FindKey(frame_time)->GetValue());
		CameraCurveRZ->AddKey(frame_time)->SetValue(CameraCurveRZ, strCurveRZ->FindKey(frame_time)->GetValue());
		CameraCurveAOV->AddKey(frame_time)->SetValue(CameraCurveAOV, strCurveAOV->FindKey(frame_time)->GetValue());
		CameraCurveDistance->AddKey(frame_time)->SetValue(CameraCurveDistance, CameraCurveDistance->FindKey(frame_time)->GetValue());
	}
	CameraCurveDistance->AddKey(BaseTime(0, 30.))->SetValue(CameraCurveDistance, setting.distance);

	Float		ValueOfTwoFrames;
	Int32		TimeOfTwoFrames;
	Int32		frame_on, next_frame_on;
	frame_count = frame_set.GetCount() - 1;// 只需循环第2到最后一个
	frame_set.Reset();
	const Float	Fps = doc->GetFps();
	/* 转换曲线并保存到对象 */
	Float KeyLeftX = 0., KeyLeftY = 0., KeyRightX = 0., KeyRightY = 0., NextKeyLeftX = 0., NextKeyLeftY = 0., NextKeyRightX = 0., NextKeyRightY = 0.;
	CKey* now_key = nullptr;
	CKey* next_key = nullptr;
	Int32 now_key_frame = 0;
	Int32 next_key_frame = 0;

	if (frame_count_px != frame_count) {
		//第一帧
		now_key = strCurvePX->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = strCurvePX->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			strCurvePX->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			strCurvePX->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
		}
		//最后一帧
		if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, strCurvePX->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = strCurvePX->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
			strCurvePX->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;

		}
	}
	if (frame_count_py != frame_count) {
		//第一帧
		now_key = strCurvePY->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = strCurvePY->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			strCurvePY->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			strCurvePY->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
		}
		//最后一帧
		if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, strCurvePY->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = strCurvePY->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
			strCurvePY->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
		}
	}
	if (frame_count_pz != frame_count) {
		//第一帧
		now_key = strCurvePZ->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = strCurvePZ->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			strCurvePZ->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			strCurvePZ->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
		}
		//最后一帧
		if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, strCurvePZ->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = strCurvePZ->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
			strCurvePZ->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
		}
	}

	switch (setting.use_rotation)
	{
	case 0:
		if (frame_count_rx != frame_count) {
			//第一帧
			now_key = strCurveRX->GetKey(0);
			now_key_frame = now_key->GetTime().GetFrame(30.);
			if (frame_count > 0) //第一帧不是最后一帧
			{
				next_key = strCurveRX->GetKey(1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
				TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				strCurveRX->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurveRX->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
					return false;
			}
			//最后一帧
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, strCurveRX->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
				return false;
			}
			// 循环第2到最后一个
			for (Int32 key_index = 1; key_index < frame_count; key_index++)
			{
				now_key = next_key;
				now_key_frame = next_key_frame;
				next_key = strCurveRX->GetKey(key_index + 1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
				TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
				strCurveRX->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
					return false;
			}
		}
		break;
	case 1:
		if (frame_count_ry != frame_count) {
			//第一帧
			now_key = strCurveRY->GetKey(0);
			now_key_frame = now_key->GetTime().GetFrame(30.);
			if (frame_count > 0) //第一帧不是最后一帧
			{
				next_key = strCurveRY->GetKey(1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
				TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				strCurveRY->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurveRY->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
					return false;
			}
			//最后一帧
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, strCurveRY->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
				return false;
			}
			// 循环第2到最后一个
			for (Int32 key_index = 1; key_index < frame_count; key_index++)
			{
				now_key = next_key;
				now_key_frame = next_key_frame;
				next_key = strCurveRY->GetKey(key_index + 1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
				TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
				strCurveRY->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
					return false;
			}
		}
		break;
	case 2:
		if (frame_count_rz != frame_count) {
			//第一帧
			now_key = strCurveRZ->GetKey(0);
			now_key_frame = now_key->GetTime().GetFrame(30.);
			if (frame_count > 0) //第一帧不是最后一帧
			{
				next_key = strCurveRZ->GetKey(1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
				TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				strCurveRZ->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
				strCurveRZ->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
					return false;
			}
			//最后一帧
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, strCurveRZ->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
				return false;
			}
			// 循环第2到最后一个
			for (Int32 key_index = 1; key_index < frame_count; key_index++)
			{
				now_key = next_key;
				now_key_frame = next_key_frame;
				next_key = strCurveRZ->GetKey(key_index + 1);
				next_key_frame = next_key->GetTime().GetFrame(30.);
				ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
				TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
				KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
				strCurveRZ->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
				if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
					return false;
			}
		}
		break;
	default:
		break;
	}
	if (frame_count_rx != frame_count) {
		//第一帧
		now_key = strCurveAOV->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(30.);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = strCurveAOV->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			strCurveAOV->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			strCurveAOV->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
		}
		//最后一帧
		if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, strCurveAOV->GetKey(frame_count)->GetTime().GetFrame(30.), VMDInterpolator())) {
			return false;
		}

		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = strCurveAOV->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(30.);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(30.) - now_key_frame;
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
			strCurveAOV->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, now_key_frame, VMDInterpolator( maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames)))))
				return false;
			
		}
	}
	frame_count += 1;
	for (Int32 key_index = 0; key_index < frame_count; key_index++)
	{
		// 距离没有曲线，顺便在循环里设置线性曲线
		if (!VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_DCURVE, now_key_frame, VMDInterpolator()))
			return false;
	}

	EventAdd();
	if (!VMDCamera_data->UpdateAllInterpolator())
		return(nullptr);
	doc->SetTime(BaseTime(1));
	doc->SetTime(BaseTime());
	return(maxon::Result<BaseObject*>(VMDCamera));
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
	Int32	CountTemp = 0;
	Int	size = sizeof(mmd::VMDInterpolator);
	void* data;
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_X_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_Y_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_Z_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_R_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_D_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_V_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
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
	Int32 CountTemp = this->interpolator_X_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->interpolator_X_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_X_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	CountTemp = this->interpolator_Y_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->interpolator_Y_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_Y_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	CountTemp = this->interpolator_Z_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->interpolator_Z_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_Z_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	CountTemp = this->interpolator_R_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->interpolator_R_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_R_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	CountTemp = this->interpolator_D_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->interpolator_D_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_D_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	CountTemp = this->interpolator_V_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->interpolator_V_map.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		if (!hf->WriteMemory(&this->interpolator_V_map.Find(i)->GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	CountTemp = this->interpolator_A_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
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
	Float sx = sin(-euler.y * 0.5);
	Float sy = sin(euler.x * 0.5);
	Float sz = sin(euler.z * 0.5);
	Float cx = cos(-euler.y * 0.5);
	Float cy = cos(euler.x * 0.5);
	Float cz = cos(euler.z * 0.5);

	Float w = (cz * cy * cx) + (sz * sy * sx);
	Float x = (cz * cy * sx) + (sz * sy * cx);
	Float y = (sz * cy * sx) - (cz * sy * cx);
	Float z = (cz * sy * sx) - (sz * cy * cx);

	return maxon::Vector4d32(x, y, z, w);
}


inline maxon::Vector mmd::VMDAnimation::QuaternionToEuler(maxon::Vector4d32& quaternion)
{
	//pitch(y - axis rotation)
	Float sinr_cosp = 2.0 * (quaternion.w * quaternion.y + quaternion.x * quaternion.z);
	Float cosr_cosp = 1.0 - (2.0 * (quaternion.x * quaternion.x + quaternion.y * quaternion.y));
	Float pitch = -atan2(sinr_cosp, cosr_cosp);

	//yaw(z - axis rotation)
	Float siny_cosp = 2.0 * (-quaternion.w * quaternion.z - quaternion.x * quaternion.y);
	Float cosy_cosp = 1.0 - (2.0 * (quaternion.x * quaternion.x + quaternion.z * quaternion.z));
	Float yaw = atan2(siny_cosp, cosy_cosp);
	
	//roll(x - axis rotation)
	Float roll = 0.0;
	Float sinp = 2.0 * (quaternion.z * quaternion.y - quaternion.w * quaternion.x);
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

	Char	VMDVersion[30]{ 0 };
	Char	VMDModelName[20]{ 0 };

	if (!file->ReadBytes(VMDVersion, 30))
		return(maxon::Error());
	if (!strncmp(VMDVersion, "Vocaloid Motion Data", 21))
	{
		if (!file->ReadBytes(VMDModelName, 10))
			return(maxon::Error());
		EncodingConversion::SJIStoUTF8(VMDModelName, this->ModelName);
		if (this->ModelName.LexComparePart(L"\u30ab\u30e1\u30e9\u30fb\u7167\u660e"_s, 12, 0) == 0) /* カメラ・照明 */
		{
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
	}
	else if (!strncmp(VMDVersion, "Vocaloid Motion Data 0002", 26))
	{
		if (!file->ReadBytes(VMDModelName, 20))
			return(maxon::Error());
		EncodingConversion::SJIStoUTF8(VMDModelName, this->ModelName);
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
		UInt32 MotionFrameNumber = 0;
		if (!file->ReadUInt32(&(MotionFrameNumber)))
			return(maxon::Error());
		for (UInt32 i = 0; i < MotionFrameNumber; i++)
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
		UInt32 MorphFrameNumber = 0;
		if (!file->ReadUInt32(&(MorphFrameNumber)))
			return(maxon::Error());
		for (UInt32 i = 0; i < MorphFrameNumber; i++)
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
		UInt32 CameraFrameNumber = 0;
		if (!file->ReadUInt32(&(CameraFrameNumber)))
			return(maxon::Error());
		for (UInt32 i = 0; i < CameraFrameNumber; i++)
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
		UInt32 LightFrameNumber = 0;
		if (!file->ReadUInt32(&(LightFrameNumber)))
			return(maxon::Error());
		for (UInt32 i = 0; i < LightFrameNumber; i++)
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
		UInt32 ShadowFrameNumber = 0;
		if (!file->ReadUInt32(&(ShadowFrameNumber)))
			return(maxon::Error());
		for (UInt32 i = 0; i < ShadowFrameNumber; i++)
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
		UInt32 ModelFrameNumber = 0;
		if (!file->ReadUInt32(&(ModelFrameNumber)))
			return(maxon::Error());
		for (UInt32 i = 0; i < ModelFrameNumber; i++)
		{
			mmd::VMD_Model* model_frame = NewObj(mmd::VMD_Model) iferr_return;
			if (model_frame == nullptr)
				return(maxon::Error());
			if (!file->ReadUInt32(&model_frame->frame_no))
				return(maxon::Error());
			if (!file->ReadBool(&model_frame->show))
				return(maxon::Error());
			UInt32 ikInfoCount = 0;
			if (!file->ReadUInt32(&ikInfoCount))
				return(maxon::Error());
			while (ikInfoCount--)
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
	Int MotionFrameNumber = this->motion_frames.GetCount();
	if (!file->WriteUInt32(MotionFrameNumber))
		return(maxon::Error());
	for (Int i = 0; i < MotionFrameNumber; i++)
	{
		mmd::VMD_Motion motion_frame = (this->motion_frames)[i];
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
	Int MorphFrameNumber = this->morph_frames.GetCount();
	if (!file->WriteUInt32(MorphFrameNumber))
		return(maxon::Error());
	for (Int i = 0; i < MorphFrameNumber; i++)
	{
		mmd::VMD_Morph morph_frame = (this->morph_frames)[i];
		maxon::AutoMem<maxon::Char> morph_name = NewMemClear(maxon::Char, (morph_frame.morph_name.GetCStringLen(STRINGENCODING::UTF8) + 1) * 2) iferr_return;
		EncodingConversion::UTF8toSJIS(morph_frame.morph_name, morph_name);
		if (!file->WriteBytes(morph_name, 15))
			return(maxon::Error());
		if (!file->WriteUInt32(morph_frame.frame_no))
			return(maxon::Error());
		if (!file->WriteFloat32(morph_frame.weight))
			return(maxon::Error());
	}
	Int CameraFrameNumber = this->camera_frames.GetCount();
	if (!file->WriteUInt32(CameraFrameNumber))
		return(maxon::Error());
	for (Int i = 0; i < CameraFrameNumber; i++)
	{
		mmd::VMD_Camera camera_frame = (this->camera_frames)[i];
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
	Int LightFrameNumber = this->light_frames.GetCount();
	if (!file->WriteUInt32(LightFrameNumber))
		return(maxon::Error());
	for (Int i = 0; i < LightFrameNumber; i++)
	{
		if (!file->WriteBytes(&((this->light_frames)[i]), sizeof(mmd::VMD_Light)))
			return(maxon::Error());
	}
	Int ShadowFrameNumber = this->shadow_frames.GetCount();
	if (!file->WriteUInt32(ShadowFrameNumber))
		return(maxon::Error());
	for (Int i = 0; i < ShadowFrameNumber; i++)
	{
		if (!file->WriteBytes(&((this->shadow_frames)[i]), sizeof(mmd::VMD_Shadow)))
			return(maxon::Error());
	}
	Int ModelFrameNumber = this->model_frames.GetCapacityCount();
	if (!file->WriteUInt32(ModelFrameNumber))
		return(maxon::Error());
	for (Int i = 0; i < ModelFrameNumber; i++)
	{
		const mmd::VMD_Model& model_frame = (this->model_frames)[i];
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
	StatusSetSpin();
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

		BaseObject* VMDCamera = BaseObject::Alloc(ID_O_MMD_CAMERA);
		if (VMDCamera == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		VMDCamera->SetName(fn.GetFileString());
		doc->InsertObject(VMDCamera, nullptr, nullptr);
		mmd::OMMDCamera* VMDCamera_data = VMDCamera->GetNodeData<OMMDCamera>();
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
		if (CameraTrackPX == nullptr || CameraTrackPY == nullptr || CameraTrackPZ == nullptr || CameraTrackRX == nullptr || CameraTrackRY == nullptr || CameraTrackRZ == nullptr || CameraTrackDistance == nullptr || CameraTrackAOV == nullptr) /* 确保生成成功 */
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		CCurve* CameraCurvePX = CameraTrackPX->GetCurve();
		CCurve* CameraCurvePY = CameraTrackPY->GetCurve();
		CCurve* CameraCurvePZ = CameraTrackPZ->GetCurve();
		CCurve* CameraCurveRX = CameraTrackRX->GetCurve();
		CCurve* CameraCurveRY = CameraTrackRY->GetCurve();
		CCurve* CameraCurveRZ = CameraTrackRZ->GetCurve();
		CCurve* CameraCurveDistance = CameraTrackDistance->GetCurve();
		CCurve* CameraCurveAOV = CameraTrackAOV->GetCurve();
		if (CameraCurvePX == nullptr || CameraCurvePY == nullptr || CameraCurvePZ == nullptr || CameraCurveRX == nullptr || CameraCurveRY == nullptr || CameraCurveRZ == nullptr || CameraCurveDistance == nullptr || CameraCurveAOV == nullptr) /* 确保获取成功 */
		{
			GePrint(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			MessageDialog(GeLoadString(IDS_MES_CONVER_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
		VMDCamera->InsertTrackSorted(CameraTrackPX);
		VMDCamera->InsertTrackSorted(CameraTrackPY);
		VMDCamera->InsertTrackSorted(CameraTrackPZ);
		VMDCamera->InsertTrackSorted(CameraTrackRX);
		VMDCamera->InsertTrackSorted(CameraTrackRY);
		VMDCamera->InsertTrackSorted(CameraTrackRZ);
		VMDCameraDistance->InsertTrackSorted(CameraTrackDistance);
		VMDCameraDistance->InsertTrackSorted(CameraTrackAOV);

		BaseTime	MaxTime = maxon::Max(doc->GetMaxTime(), BaseTime((mmd_animation->camera_frames.End() - 1).GetPtr()->frame_no, 30.));
		BaseTime	KeyTime = BaseTime(0, 30.);
		Int32		KeyFrame = 0;
		mmd::VMD_Camera CameraFrame, NextCameraFrame;
		const Int	camera_frame_number = mmd_animation->camera_frames.GetCount();
		for (Int camera_frame_index = 0; camera_frame_index < camera_frame_number; camera_frame_index++)
		{
			StatusSetText("Import camera..."_s);
			StatusSetSpin();
			if (camera_frame_index == 0 && camera_frame_number != 1)
			{
				CameraFrame = mmd_animation->camera_frames[camera_frame_index];
				NextCameraFrame = mmd_animation->camera_frames[camera_frame_index + 1];
			}
			else if (camera_frame_index == camera_frame_number - 1)
			{
				CameraFrame = NextCameraFrame;
			}
			else {
				CameraFrame = NextCameraFrame;
				NextCameraFrame = mmd_animation->camera_frames[camera_frame_index + 1];
			}
			KeyFrame = Int32(CameraFrame.frame_no) + maxon::SafeConvert<Int32>(setting.TimeOffset);
			KeyTime = BaseTime(KeyFrame, 30.);

			CKey* CameraKeyPX = CKey::Alloc();      /* PX */
			CameraKeyPX->SetTime(CameraCurvePX, KeyTime);
			CameraKeyPX->SetValue(CameraCurvePX, CameraFrame.position.x * setting.PositionMultiple);
			CameraKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurvePX->InsertKey(CameraKeyPX);
			VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_XCURVE, KeyFrame,std::move(CameraFrame.interpolator_x));

			CKey* CameraKeyPY = CKey::Alloc();      /* PY */
			CameraKeyPY->SetTime(CameraCurvePY, KeyTime);
			CameraKeyPY->SetValue(CameraCurvePY, CameraFrame.position.y * setting.PositionMultiple);
			CameraKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurvePY->InsertKey(CameraKeyPY);
			VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_YCURVE, KeyFrame, std::move(CameraFrame.interpolator_y));

			CKey* CameraKeyPZ = CKey::Alloc();      /* PZ */
			CameraKeyPZ->SetTime(CameraCurvePZ, KeyTime);
			CameraKeyPZ->SetValue(CameraCurvePZ, CameraFrame.position.z * setting.PositionMultiple);
			CameraKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurvePZ->InsertKey(CameraKeyPZ);
			VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_ZCURVE, KeyFrame, std::move(CameraFrame.interpolator_z));

			CKey* CameraKeyRX = CKey::Alloc();      /* RH(y) */
			CameraKeyRX->SetTime(CameraCurveRX, KeyTime);
			CameraKeyRX->SetValue(CameraCurveRX, CameraFrame.rotation.y);
			CameraKeyRX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveRX->InsertKey(CameraKeyRX);

			CKey* CameraKeyRY = CKey::Alloc();      /* RP(x) */
			CameraKeyRY->SetTime(CameraCurveRY, KeyTime);
			CameraKeyRY->SetValue(CameraCurveRY, CameraFrame.rotation.x);
			CameraKeyRY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveRY->InsertKey(CameraKeyRY);

			CKey* CameraKeyRZ = CKey::Alloc();      /* RB(z) */
			CameraKeyRZ->SetTime(CameraCurveRZ, KeyTime);
			CameraKeyRZ->SetValue(CameraCurveRZ, CameraFrame.rotation.z);
			CameraKeyRZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveRZ->InsertKey(CameraKeyRZ);
			VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_RCURVE, KeyFrame, std::move(CameraFrame.interpolator_r));

			CKey* CameraKeyDistance = CKey::Alloc();;
			CameraKeyDistance->SetTime(CameraCurveDistance, KeyTime);
			CameraKeyDistance->SetValue(CameraCurveDistance, CameraFrame.distance * setting.PositionMultiple);
			CameraKeyDistance->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveDistance->InsertKey(CameraKeyDistance);
			VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_DCURVE, KeyFrame, std::move(CameraFrame.interpolator_d));

			CKey* CameraKeyAOV = CKey::Alloc();
			CameraKeyAOV->SetTime(CameraCurveAOV, KeyTime);
			CameraKeyAOV->SetValue(CameraCurveAOV, CameraFrame.viewing_angle);
			CameraKeyAOV->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraCurveAOV->InsertKey(CameraKeyAOV);
			VMDCamera_data->SetInterpolator(VMD_CAM_OBJ_VCURVE, KeyFrame, std::move(CameraFrame.interpolator_v));
		}
		VMDCamera_data->UpdateAllInterpolator();
		timing.Stop();
		StatusClear();
		doc->SetMaxTime(MaxTime);
		doc->SetLoopMaxTime(MaxTime);
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
	setting.PositionMultiple = 1.0 / setting.PositionMultiple;
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	doc->SetTime(BaseTime(0.));
	BaseObject* CameraObj = nullptr;
	AutoFree<BaseObject> CameraObj_tmp;					  /*转化对象自动销毁 */

	/*选择对象为普通摄像机则转化 */
	if (SelectObject->GetType() == Ocamera)               
	{
		auto res = OMMDCamera::ConversionCamera(VMD_Conversion_Camera_settings{ 0., setting.use_rotation, SelectObject });
		CameraObj_tmp.Assign(res.GetValue());
		iferr(res.GetError()) 
			return(maxon::Error());
		CameraObj = CameraObj_tmp;
	}
	/*选择对象为vmd摄像机则直接使用 */
	else if(SelectObject->GetType() == ID_O_MMD_CAMERA) 
	{
		CameraObj = SelectObject;
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
	mmd::OMMDCamera* VMDCamera_data = CameraObj->GetNodeData<OMMDCamera>();
	if (VMDCamera_data == nullptr)
	{
		return(maxon::Error());
	}
	BaseObject* VMDCameraDistance = VMDCamera_data->GetCamera();
	maxon::TimeValue	timing = maxon::TimeValue::GetTime();
	CTrack* CameraTrackPX = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (CameraTrackPX == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PX"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PX"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackPY = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (CameraTrackPY == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PY"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PY"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackPZ = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
	if (CameraTrackPZ == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PZ"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PZ"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackRX = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (CameraTrackRX == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RX"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RX"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackRY = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (CameraTrackRY == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RY"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RY"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackRZ = CameraObj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (CameraTrackRZ == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RZ"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RZ"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackFrame_on = CameraObj->FindCTrack(DescID(VMD_CAM_OBJ_FRAME_ON));

	if (CameraTrackFrame_on == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Frame_on"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Frame_on"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackDistance = VMDCameraDistance->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (CameraTrackDistance == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	CTrack* CameraTrackAOV = VMDCameraDistance->FindCTrack(DescID(DescLevel(CAMERAOBJECT_APERTURE, DTYPE_REAL, 0)));
	if (CameraTrackAOV == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "AOV"_s));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
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

	maxon::UniqueRef<mmd::VMDAnimation> mmd_animation = NewObj(mmd::VMDAnimation)iferr_return;

	for (Int32 frame_index = 0; frame_index < FrameCount; frame_index++)
	{
		StatusSetSpin();
		mmd::VMD_Camera* CameraFrame =NewObj(mmd::VMD_Camera)iferr_return;
		Int32 Frame_on = CameraCurveFrame_on->GetKey(frame_index)->GetValue();
		CameraFrame->frame_no = Frame_on + setting.TimeOffset;
		CameraFrame->position = Vector32(CameraCurvePX->GetKey(frame_index)->GetValue() * setting.PositionMultiple, CameraCurvePY->GetKey(frame_index)->GetValue() * setting.PositionMultiple, CameraCurvePZ->GetKey(frame_index)->GetValue() * setting.PositionMultiple);
		CameraFrame->rotation = Vector32(CameraCurveRY->GetKey(frame_index)->GetValue(), CameraCurveRX->GetKey(frame_index)->GetValue(), CameraCurveRZ->GetKey(frame_index)->GetValue()); /*H(y) P(x) B(z)*/
		CameraFrame->distance = Float32(CameraCurveDistance->GetKey(frame_index)->GetValue() * setting.PositionMultiple);
		CameraFrame->viewing_angle = maxon::SafeConvert<UInt32>(CameraCurveAOV->GetKey(frame_index)->GetValue());
		CameraFrame->perspective = 0;
		VMDCamera_data->GetInterpolator(VMD_CAM_OBJ_XCURVE, Frame_on, CameraFrame->interpolator_x);
		VMDCamera_data->GetInterpolator(VMD_CAM_OBJ_YCURVE, Frame_on, CameraFrame->interpolator_y);
		VMDCamera_data->GetInterpolator(VMD_CAM_OBJ_ZCURVE, Frame_on, CameraFrame->interpolator_z);
		VMDCamera_data->GetInterpolator(VMD_CAM_OBJ_RCURVE, Frame_on, CameraFrame->interpolator_r);
		VMDCamera_data->GetInterpolator(VMD_CAM_OBJ_DCURVE, Frame_on, CameraFrame->interpolator_d);
		VMDCamera_data->GetInterpolator(VMD_CAM_OBJ_VCURVE, Frame_on, CameraFrame->interpolator_v);
		mmd_animation->camera_frames.AppendPtr(CameraFrame)iferr_return;
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
	if (setting.DeletePreviousAnimation == true) 
	{
		if (setting.ImportMotion == true && setting.ImportMorph == true)
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
							CTrack* BoneTrackPX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPX);
							CTrack* BoneTrackPY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPY);
							CTrack* BoneTrackPZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPZ);
							CTrack* BoneTrackRX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRX);
							CTrack* BoneTrackRY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRY);
							CTrack* BoneTrackRZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRZ);
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
		else if (setting.ImportMotion == true && setting.ImportMorph == false)
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
							CTrack* BoneTrackPX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPX);
							CTrack* BoneTrackPY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPY);
							CTrack* BoneTrackPZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPZ);
							CTrack* BoneTrackRX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRX);
							CTrack* BoneTrackRY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRY);
							CTrack* BoneTrackRZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRZ);
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
		else if (setting.ImportMotion == false && setting.ImportMorph == true)
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
		if (setting.ImportModelInfo == true) {
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
	if (setting.ImportMotion == true) 
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
	if (setting.ImportMorph == true) {
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
	String				motion_frame_bone_number_S = String::IntToString(motion_frame_bone_number);
	maxon::BaseArray<String>	not_find_bone_S;
	if (setting.ImportMotion == true) {
		if (setting.DeletePreviousAnimation == true) {

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
									CTrack* BoneTrackPX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									BoneTrackPX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrackPX == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackPX);
									CTrack* BoneTrackPY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									BoneTrackPY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrackPY == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackPY);
									CTrack* BoneTrackPZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									BoneTrackPZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrackPZ == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackPZ);
									CTrack* BoneTrackRX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrackRX == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackRX);
									CTrack* BoneTrackRY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									BoneTrackRY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrackRY == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackRY);
									CTrack* BoneTrackRZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									BoneTrackRZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrackRZ == nullptr) {
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackRZ);

									CCurve* BoneCurvePX = BoneTrackPX->GetCurve();
									CCurve* BoneCurvePY = BoneTrackPY->GetCurve();
									CCurve* BoneCurvePZ = BoneTrackPZ->GetCurve();
									CCurve* BoneCurveRX = BoneTrackRX->GetCurve();
									CCurve* BoneCurveRY = BoneTrackRY->GetCurve();
									CCurve* BoneCurveRZ = BoneTrackRZ->GetCurve();
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
										MotionKeyTime = BaseTime(MotionFrame.frame_no + setting.TimeOffset, 30.);

										Vector rotation = QuaternionToEuler(MotionFrame.rotation);
										Vector next_rotation = QuaternionToEuler(NextMotionFrame.rotation);

										CKey* MotionKeyPX = CKey::Alloc(); /* PX */
										MotionKeyPX->SetTime(BoneCurvePX, MotionKeyTime);
										MotionKeyPX->SetValue(BoneCurvePX, MotionFrame.position.x * setting.PositionMultiple);
										MotionKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
										MotionKeyPX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
										ValueOfTwoMotionFrames = NextMotionFrame.position.x * setting.PositionMultiple - MotionFrame.position.x * setting.PositionMultiple;
										if (MotionFrame.interpolator_x.ax == 127 - MotionFrame.interpolator_x.bx && MotionFrame.interpolator_x.ay == 127 - MotionFrame.interpolator_x.by)
										{
											MotionKeyPX->SetInterpolation(BoneCurvePX, CINTERPOLATION::LINEAR);
										}
										else {
											MotionKeyPX->SetTimeLeft(BoneCurvePX, MotionKeyTimeLeft[0]);
											MotionKeyPX->SetValueLeft(BoneCurvePX, MotionKeyValueLeft[0]);
											MotionKeyPX->SetTimeRight(BoneCurvePX, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ax / 127.0), 30.));
											MotionKeyPX->SetValueRight(BoneCurvePX, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ay / 127.0));
										}
										MotionKeyTimeLeft[0] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.bx / 127.0), 30.);
										MotionKeyValueLeft[0] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.by / 127.0);
										BoneCurvePX->InsertKey(MotionKeyPX);

										CKey* MotionKeyPY = CKey::Alloc(); /* PY */
										MotionKeyPY->SetTime(BoneCurvePY, MotionKeyTime);
										MotionKeyPY->SetValue(BoneCurvePY, MotionFrame.position.y * setting.PositionMultiple);
										MotionKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
										MotionKeyPY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
										ValueOfTwoMotionFrames = NextMotionFrame.position.y * setting.PositionMultiple - MotionFrame.position.y * setting.PositionMultiple;
										if (MotionFrame.interpolator_y.ax == 127 - MotionFrame.interpolator_y.bx && MotionFrame.interpolator_y.ay == 127 - MotionFrame.interpolator_y.by)
										{
											MotionKeyPY->SetInterpolation(BoneCurvePY, CINTERPOLATION::LINEAR);
										}
										else {
											MotionKeyPY->SetTimeLeft(BoneCurvePY, MotionKeyTimeLeft[1]);
											MotionKeyPY->SetValueLeft(BoneCurvePY, MotionKeyValueLeft[1]);
											MotionKeyPY->SetTimeRight(BoneCurvePY, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ax / 127.0), 30.));
											MotionKeyPY->SetValueRight(BoneCurvePY, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ay / 127.0));
										}
										MotionKeyTimeLeft[1] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.bx / 127.0), 30.);
										MotionKeyValueLeft[1] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.by / 127.0);
										BoneCurvePY->InsertKey(MotionKeyPY);

										CKey* MotionKeyPZ = CKey::Alloc(); /* PZ */
										MotionKeyPZ->SetTime(BoneCurvePZ, MotionKeyTime);
										MotionKeyPZ->SetValue(BoneCurvePZ, MotionFrame.position.z * setting.PositionMultiple);
										MotionKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
										MotionKeyPZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
										ValueOfTwoMotionFrames = NextMotionFrame.position.z * setting.PositionMultiple - MotionFrame.position.z * setting.PositionMultiple;
										if (MotionFrame.interpolator_z.ax == 127 - MotionFrame.interpolator_z.bx && MotionFrame.interpolator_z.ay == 127 - MotionFrame.interpolator_z.by)
										{
											MotionKeyPZ->SetInterpolation(BoneCurvePZ, CINTERPOLATION::LINEAR);
										}
										else {
											MotionKeyPZ->SetTimeLeft(BoneCurvePZ, MotionKeyTimeLeft[2]);
											MotionKeyPZ->SetValueLeft(BoneCurvePZ, MotionKeyValueLeft[2]);
											MotionKeyPZ->SetTimeRight(BoneCurvePZ, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ax / 127.0), 30.));
											MotionKeyPZ->SetValueRight(BoneCurvePZ, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ay / 127.0));
										}
										MotionKeyTimeLeft[2] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.bx / 127.0), 30.);
										MotionKeyValueLeft[2] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.by / 127.0);
										BoneCurvePZ->InsertKey(MotionKeyPZ);

										CKey* MotionKeyRX = CKey::Alloc(); /* RX */
										MotionKeyRX->SetTime(BoneCurveRX, MotionKeyTime);
										MotionKeyRX->SetValue(BoneCurveRX, rotation.x);
										BoneCurveRX->InsertKey(MotionKeyRX);

										CKey* MotionKeyRY = CKey::Alloc(); /* RY */
										MotionKeyRY->SetTime(BoneCurveRY, MotionKeyTime);
										MotionKeyRY->SetValue(BoneCurveRY, rotation.y);
										BoneCurveRY->InsertKey(MotionKeyRY);

										CKey* MotionKeyRZ = CKey::Alloc(); /* RZ */
										MotionKeyRZ->SetTime(BoneCurveRZ, MotionKeyTime);
										MotionKeyRZ->SetValue(BoneCurveRZ, rotation.z);
										BoneCurveRZ->InsertKey(MotionKeyRZ);
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
								if (!(Is_physical || Is_inherit))
								{
									if (Is_translatable)
									{
										bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrackPX);
										BoneTrackPX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										if (BoneTrackPX == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrackPX);
										BoneTrackPY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrackPY);
										BoneTrackPY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										if (BoneTrackPY == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrackPY);
										BoneTrackPZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrackPZ);
										BoneTrackPZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										if (BoneTrackPZ == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrackPZ);
										BoneCurvePX = BoneTrackPX->GetCurve();
										BoneCurvePY = BoneTrackPY->GetCurve();
										BoneCurvePZ = BoneTrackPZ->GetCurve();
									}
									if (Is_rotatable)
									{
										BoneTrackRX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrackRX);
										BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
										if (BoneTrackRX == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrackRX);
										BoneTrackRY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrackRY);
										BoneTrackRY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
										if (BoneTrackRY == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrackRY);
										BoneTrackRZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										CTrack::Free(BoneTrackRZ);
										BoneTrackRZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
										if (BoneTrackRZ == nullptr) {
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
										}
										bone.obj->InsertTrackSorted(BoneTrackRZ);
										BoneCurveRX = BoneTrackRX->GetCurve();
										BoneCurveRY = BoneTrackRY->GetCurve();
										BoneCurveRZ = BoneTrackRZ->GetCurve();
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
										Int32 frame_no = Int32(MotionFrame.frame_no) + Int32(setting.TimeOffset);
										MotionKeyTime = BaseTime(Float(frame_no), 30.);

										if (Is_translatable)
										{
											CKey* MotionKeyPX = CKey::Alloc(); /* PX */
											MotionKeyPX->SetValue(BoneCurvePX, MotionFrame.position.x * setting.PositionMultiple);
											MotionKeyPX->SetTime(BoneCurveRX, MotionKeyTime);
											BoneCurvePX->InsertKey(MotionKeyPX);
											tag_data->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_no, std::move( MotionFrame.interpolator_x));
											CKey* MotionKeyPY = CKey::Alloc(); /* PY */
											MotionKeyPY->SetValue(BoneCurvePY, MotionFrame.position.y * setting.PositionMultiple);
											MotionKeyPY->SetTime(BoneCurvePY, MotionKeyTime);
											BoneCurvePY->InsertKey(MotionKeyPY);
											tag_data->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_no, std::move( MotionFrame.interpolator_y));
											CKey* MotionKeyPZ = CKey::Alloc(); /* PZ */
											MotionKeyPZ->SetValue(BoneCurvePZ, MotionFrame.position.z * setting.PositionMultiple);
											MotionKeyPZ->SetTime(BoneCurvePZ, MotionKeyTime);
											BoneCurvePZ->InsertKey(MotionKeyPZ);
											tag_data->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_no, std::move( MotionFrame.interpolator_z));
										}
										if (Is_rotatable)
										{
											Vector rotation = QuaternionToEuler(MotionFrame.rotation);
											CKey* MotionKeyRX = CKey::Alloc(); /* RX */
											MotionKeyRX->SetValue(BoneCurveRX, rotation.x);
											MotionKeyRX->SetTime(BoneCurveRX, MotionKeyTime);
											BoneCurveRX->InsertKey(MotionKeyRX);
											CKey* MotionKeyRY = CKey::Alloc(); /* RY */
											MotionKeyRY->SetValue(BoneCurveRY, rotation.y);
											MotionKeyRY->SetTime(BoneCurveRY, MotionKeyTime);
											BoneCurveRY->InsertKey(MotionKeyRY);
											CKey* MotionKeyRZ = CKey::Alloc(); /* RZ */
											MotionKeyRZ->SetValue(BoneCurveRZ, rotation.z);
											MotionKeyRZ->SetTime(BoneCurveRZ, MotionKeyTime);
											BoneCurveRZ->InsertKey(MotionKeyRZ);
											tag_data->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_no, std::move( MotionFrame.interpolator_r));
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
							CTrack* BoneTrackPX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)
							{
								BoneTrackPX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrackPX == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrackPX);
							}
							CTrack* BoneTrackPY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)
							{
								BoneTrackPY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrackPY == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrackPY);
							}
							CTrack* BoneTrackPZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)
							{
								BoneTrackPZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrackPZ == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrackPZ);
							}
							CTrack* BoneTrackRX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)
							{
								BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrackRX == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrackRX);
							}
							CTrack* BoneTrackRY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)
							{
								BoneTrackRY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrackRY == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrackRY);
							}
							CTrack* BoneTrackRZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							if (BoneTrackPX == nullptr)
							{
								BoneTrackRZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrackRZ == nullptr)
								{
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
								}
								bone.obj->InsertTrackSorted(BoneTrackRZ);
							}
							CCurve* BoneCurvePX = BoneTrackPX->GetCurve();
							CCurve* BoneCurvePY = BoneTrackPY->GetCurve();
							CCurve* BoneCurvePZ = BoneTrackPZ->GetCurve();
							CCurve* BoneCurveRX = BoneTrackRX->GetCurve();
							CCurve* BoneCurveRY = BoneTrackRY->GetCurve();
							CCurve* BoneCurveRZ = BoneTrackRZ->GetCurve();
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
								MotionKeyTime = BaseTime(MotionFrame.frame_no + setting.TimeOffset, 30.);

								Vector rotation = QuaternionToEuler(MotionFrame.rotation);
								Vector next_rotation = QuaternionToEuler(NextMotionFrame.rotation);

								CKey* MotionKeyPX = CKey::Alloc(); /* PX */
								MotionKeyPX->SetTime(BoneCurvePX, MotionKeyTime);
								MotionKeyPX->SetValue(BoneCurvePX, MotionFrame.position.x * setting.PositionMultiple);
								MotionKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKeyPX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = NextMotionFrame.position.x * setting.PositionMultiple - MotionFrame.position.x * setting.PositionMultiple;
								if (MotionFrame.interpolator_x.ax == 127 - MotionFrame.interpolator_x.bx && MotionFrame.interpolator_x.ay == 127 - MotionFrame.interpolator_x.by)
								{
									MotionKeyPX->SetInterpolation(BoneCurvePX, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKeyPX->SetTimeLeft(BoneCurvePX, MotionKeyTimeLeft[0]);
									MotionKeyPX->SetValueLeft(BoneCurvePX, MotionKeyValueLeft[0]);
									MotionKeyPX->SetTimeRight(BoneCurvePX, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ax / 127.0), 30.));
									MotionKeyPX->SetValueRight(BoneCurvePX, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.ay / 127.0));
								}
								MotionKeyTimeLeft[0] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.bx / 127.0), 30.);
								MotionKeyValueLeft[0] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_x.by / 127.0);
								BoneCurvePX->InsertKey(MotionKeyPX);

								CKey* MotionKeyPY = CKey::Alloc(); /* PY */
								MotionKeyPY->SetTime(BoneCurvePY, MotionKeyTime);
								MotionKeyPY->SetValue(BoneCurvePY, MotionFrame.position.y * setting.PositionMultiple);
								MotionKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKeyPY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = NextMotionFrame.position.y * setting.PositionMultiple - MotionFrame.position.y * setting.PositionMultiple;
								if (MotionFrame.interpolator_y.ax == 127 - MotionFrame.interpolator_y.bx && MotionFrame.interpolator_y.ay == 127 - MotionFrame.interpolator_y.by)
								{
									MotionKeyPY->SetInterpolation(BoneCurvePY, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKeyPY->SetTimeLeft(BoneCurvePY, MotionKeyTimeLeft[1]);
									MotionKeyPY->SetValueLeft(BoneCurvePY, MotionKeyValueLeft[1]);
									MotionKeyPY->SetTimeRight(BoneCurvePY, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ax / 127.0), 30.));
									MotionKeyPY->SetValueRight(BoneCurvePY, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.ay / 127.0));
								}
								MotionKeyTimeLeft[1] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.bx / 127.0), 30.);
								MotionKeyValueLeft[1] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_y.by / 127.0);
								BoneCurvePY->InsertKey(MotionKeyPY);

								CKey* MotionKeyPZ = CKey::Alloc(); /* PZ */
								MotionKeyPZ->SetTime(BoneCurvePZ, MotionKeyTime);
								MotionKeyPZ->SetValue(BoneCurvePZ, MotionFrame.position.z * setting.PositionMultiple);
								MotionKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
								MotionKeyPZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
								ValueOfTwoMotionFrames = NextMotionFrame.position.z * setting.PositionMultiple - MotionFrame.position.z * setting.PositionMultiple;
								if (MotionFrame.interpolator_z.ax == 127 - MotionFrame.interpolator_z.bx && MotionFrame.interpolator_z.ay == 127 - MotionFrame.interpolator_z.by)
								{
									MotionKeyPZ->SetInterpolation(BoneCurvePZ, CINTERPOLATION::LINEAR);
								}
								else {
									MotionKeyPZ->SetTimeLeft(BoneCurvePZ, MotionKeyTimeLeft[2]);
									MotionKeyPZ->SetValueLeft(BoneCurvePZ, MotionKeyValueLeft[2]);
									MotionKeyPZ->SetTimeRight(BoneCurvePZ, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ax / 127.0), 30.));
									MotionKeyPZ->SetValueRight(BoneCurvePZ, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.ay / 127.0));
								}
								MotionKeyTimeLeft[2] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.bx / 127.0), 30.);
								MotionKeyValueLeft[2] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.interpolator_z.by / 127.0);
								BoneCurvePZ->InsertKey(MotionKeyPZ);

								CKey* MotionKeyRX = CKey::Alloc(); /* RX */
								MotionKeyRX->SetTime(BoneCurveRX, MotionKeyTime);
								MotionKeyRX->SetValue(BoneCurveRX, rotation.x);
								BoneCurveRX->InsertKey(MotionKeyRX);

								CKey* MotionKeyRY = CKey::Alloc(); /* RY */
								MotionKeyRY->SetTime(BoneCurveRY, MotionKeyTime);
								MotionKeyRY->SetValue(BoneCurveRY, rotation.y);
								BoneCurveRY->InsertKey(MotionKeyRY);

								CKey* MotionKeyRZ = CKey::Alloc(); /* RZ */
								MotionKeyRZ->SetTime(BoneCurveRZ, MotionKeyTime);
								MotionKeyRZ->SetValue(BoneCurveRZ, rotation.z);
								BoneCurveRZ->InsertKey(MotionKeyRZ);
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
						if (!(Is_physical || Is_inherit))
						{
							if (Is_translatable)
							{
								bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrackPX == nullptr)
								{
									BoneTrackPX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrackPX == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackPX);
								}
								BoneTrackPY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrackPY == nullptr)
								{
									BoneTrackPY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrackPY == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackPY);
								}
								BoneTrackPZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrackPZ == nullptr)
								{
									BoneTrackPZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrackPZ == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackPZ);
								}
								BoneCurvePX = BoneTrackPX->GetCurve();
								BoneCurvePY = BoneTrackPY->GetCurve();
								BoneCurvePZ = BoneTrackPZ->GetCurve();
							}
							if (Is_rotatable)
							{
								BoneTrackRX = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrackRX == nullptr)
									BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								if (BoneTrackRX == nullptr)
								{
									BoneTrackRX = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									if (BoneTrackRX == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackRX);
								}
								BoneTrackRY = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								if (BoneTrackRY == nullptr)
								{
									BoneTrackRY = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									if (BoneTrackRY == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackRY);
								}
								BoneTrackRZ = bone.obj->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								if (BoneTrackRZ == nullptr)
								{
									BoneTrackRZ = CTrack::Alloc(bone.obj, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									if (BoneTrackRZ == nullptr)
									{
											return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION));
									}
									bone.obj->InsertTrackSorted(BoneTrackRZ);
								}
								BoneCurveRX = BoneTrackRX->GetCurve();
								BoneCurveRY = BoneTrackRY->GetCurve();
								BoneCurveRZ = BoneTrackRZ->GetCurve();
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
								Int32 frame_no = Int32(MotionFrame.frame_no) + Int32(setting.TimeOffset);
								MotionKeyTime = BaseTime(Float(frame_no), 30.);


								if (Is_translatable)
								{
									CKey* MotionKeyPX = CKey::Alloc(); /* PX */
									MotionKeyPX->SetValue(BoneCurvePX, MotionFrame.position.x * setting.PositionMultiple);
									MotionKeyPX->SetTime(BoneCurveRX, MotionKeyTime);
									BoneCurvePX->InsertKey(MotionKeyPX);
									tag_data->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_no, std::move( MotionFrame.interpolator_x));
									CKey* MotionKeyPY = CKey::Alloc(); /* PY */
									MotionKeyPY->SetValue(BoneCurvePY, MotionFrame.position.y * setting.PositionMultiple);
									MotionKeyPY->SetTime(BoneCurvePY, MotionKeyTime);
									BoneCurvePY->InsertKey(MotionKeyPY);
									tag_data->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_no, std::move( MotionFrame.interpolator_y));
									CKey* MotionKeyPZ = CKey::Alloc(); /* PZ */
									MotionKeyPZ->SetValue(BoneCurvePZ, MotionFrame.position.z * setting.PositionMultiple);
									MotionKeyPZ->SetTime(BoneCurvePZ, MotionKeyTime);
									BoneCurvePZ->InsertKey(MotionKeyPZ);
									tag_data->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_no, std::move( MotionFrame.interpolator_z));
								}
								if (Is_rotatable)
								{
									Vector rotation = QuaternionToEuler(MotionFrame.rotation);
									CKey* MotionKeyRX = CKey::Alloc(); /* RX */
									MotionKeyRX->SetValue(BoneCurveRX, rotation.x);
									MotionKeyRX->SetTime(BoneCurveRX, MotionKeyTime);
									BoneCurveRX->InsertKey(MotionKeyRX);
									CKey* MotionKeyRY = CKey::Alloc(); /* RY */
									MotionKeyRY->SetValue(BoneCurveRY, rotation.y);
									MotionKeyRY->SetTime(BoneCurveRY, MotionKeyTime);
									BoneCurveRY->InsertKey(MotionKeyRY);
									CKey* MotionKeyRZ = CKey::Alloc(); /* RZ */
									MotionKeyRZ->SetValue(BoneCurveRZ, rotation.z);
									MotionKeyRZ->SetTime(BoneCurveRZ, MotionKeyTime);
									BoneCurveRZ->InsertKey(MotionKeyRZ);
									tag_data->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_no, std::move( MotionFrame.interpolator_r));
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
	if (setting.ImportMorph == true) {

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
							StatusSetText("Import motion of morph " + String::IntToString(morph_cnt) + "/" + motion_frame_morph_number_S);
							StatusSetSpin();
							MorphFrame = (*MorphFrameList)[morph_index];
							CKey* MorphKey = CKey::Alloc();
							MorphKey->SetTime(MorphCurve, BaseTime(MorphFrame.frame_no + setting.TimeOffset, 30.));
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
				if (GeIsMainThread())
					StatusSetText("Import morph " + String::IntToString(insideCount) + " of " + String::IntToString(motion_frame_morph_number));
			}) iferr_return;
	}
	motion_morph_name_array.Reset();

	/*ImportMotion*/
	if (setting.ImportModelInfo == true)
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
		for (Int morph_frame_index = 0; morph_frame_index < ModelFrameNumber; morph_frame_index++)
		{
			const mmd::VMD_Model& model_frame = mmd_animation->model_frames[morph_frame_index];
			BaseTime		time = BaseTime(model_frame.frame_no + setting.TimeOffset, 30.);
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
	if (setting.DetailReport == 1)
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
	setting.PositionMultiple = 1.0 / setting.PositionMultiple;
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}

	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr)
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
	
	maxon::TimeValue	timing = maxon::TimeValue::GetTime();
	maxon::UniqueRef<mmd::VMDAnimation> mmd_animation = NewObj(mmd::VMDAnimation)iferr_return;
	mmd_animation->ModelName = SelectObject->GetName();
	mmd_animation->IsCamera = false;

	maxon::HashSet<bone_obj_tag>	bone_set;
	maxon::HashSet<morph_id_tag>	morph_set;
	maxon::HashSet<BaseTag*>		ik_tag_set;

	maxon::Queue<BaseObject*> nodes;
	nodes.Push(SelectObject) iferr_return;
	GeData data;

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
				const Int		MorphCount = pose_morph_tag->GetMorphCount();
				for (Int index = 1; index < MorphCount; index++)
				{
					morph_set.Insert(morph_id_tag{ pose_morph_tag->GetMorphID(index), tag ,pose_morph_tag->GetMorph(index)->GetName() }) iferr_return;
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
	nodes.Reset();

	doc->SetTime(BaseTime(0.));

	if (setting.ExportMotion == true) {
		for (const bone_obj_tag& bone : bone_set)
		{
			if (bone.tag != nullptr)
			{
				GeData ge_data;
				bone.tag->GetParameter(PMX_BONE_NAME_LOCAL, ge_data, DESCFLAGS_GET::NONE);
				TMMDBone* bone_tag_data = bone.tag->GetNodeData<TMMDBone>();
				String  bone_name = ge_data.GetString();
				// bone_tag_data->AutoRegisterKeyFrame(setting.use_rotation);

				CTrack* TrackPX = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
				CTrack* TrackPY = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
				CTrack* TrackPZ = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
				CTrack* TrackRX = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
				CTrack* TrackRY = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
				CTrack* TrackRZ = bone.obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));

				if (TrackPX == nullptr || TrackPY == nullptr || TrackPZ == nullptr || TrackRX == nullptr || TrackRY == nullptr || TrackRZ == nullptr)
				{
					continue;
				}

				CCurve* CurvePX = TrackPX->GetCurve();
				CCurve* CurvePY = TrackPY->GetCurve();
				CCurve* CurvePZ = TrackPZ->GetCurve();
				CCurve* CurveRX = TrackRX->GetCurve();
				CCurve* CurveRY = TrackRY->GetCurve();
				CCurve* CurveRZ = TrackRZ->GetCurve();

				if (CurvePX == nullptr || CurvePY == nullptr || CurvePZ == nullptr || CurveRX == nullptr || CurveRY == nullptr || CurveRZ == nullptr)
				{
					continue;
				}

				CKey* key = nullptr;
				const Int32 bone_key_count = CurvePX->GetKeyCount();
				for (Int32 key_index = 0; key_index < bone_key_count; key_index++)
				{
					mmd::VMD_Motion* vmd_motion_data = NewObj(mmd::VMD_Motion)iferr_return;
					vmd_motion_data->bone_name = bone_name;
					key = CurvePX->GetKey(key_index);
					vmd_motion_data->frame_no = key->GetTime().GetFrame(30.);
					vmd_motion_data->position.x = key->GetValue() * setting.PositionMultiple;
					key = CurvePY->GetKey(key_index);
					vmd_motion_data->position.y = key->GetValue() * setting.PositionMultiple;
					key = CurvePZ->GetKey(key_index);
					vmd_motion_data->position.z = key->GetValue() * setting.PositionMultiple;
					Vector rotation = Vector();
					key = CurveRX->GetKey(key_index);
					rotation.x = key->GetValue();
					key = CurveRY->GetKey(key_index);
					rotation.y = key->GetValue();
					key = CurveRZ->GetKey(key_index);
					rotation.z = key->GetValue();
					vmd_motion_data->rotation = EulerToQuaternion(rotation);
					bone_tag_data->GetInterpolator(PMX_BONE_TAG_XCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_x);
					bone_tag_data->GetInterpolator(PMX_BONE_TAG_YCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_y);
					bone_tag_data->GetInterpolator(PMX_BONE_TAG_ZCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_z);
					bone_tag_data->GetInterpolator(PMX_BONE_TAG_RCURVE, vmd_motion_data->frame_no, vmd_motion_data->interpolator_r);
					vmd_motion_data->frame_no += setting.TimeOffset;
					mmd_animation->motion_frames.AppendPtr(vmd_motion_data)iferr_return;
				}
			}
			else {
				String  bone_name = bone.obj->GetName();

			}
		}
	}

	if (setting.ExportMorph == true) {
		for (const morph_id_tag& morph : morph_set) {
			CTrack* morph_track = morph.tag->FindCTrack(morph.id);
			if (morph_track != nullptr) {
				CCurve* morph_curve = morph_track->GetCurve();
				if (morph_curve != nullptr) {
					const Int32 morph_key_count = morph_curve->GetKeyCount();
					for (Int32 key_index = 0; key_index < morph_key_count; key_index++) {
						mmd::VMD_Morph* vmd_morph_data = NewObj(mmd::VMD_Morph)iferr_return;
						CKey* key = morph_curve->GetKey(key_index);
						vmd_morph_data->frame_no = key->GetTime().GetFrame(30.) + setting.TimeOffset;
						vmd_morph_data->weight = key->GetValue();
						vmd_morph_data->morph_name = morph.name;
						mmd_animation->morph_frames.AppendPtr(vmd_morph_data)iferr_return;
					}
				}
			}
		}
	}

	if (setting.ExportModelInfo == true)
	{
		maxon::HashSet<MyBaseTime> time_set;

		CTrack* ModelEditorDisplayTrack = SelectObject->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
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
				model_frame->frame_no = time.GetFrame(30.) + setting.TimeOffset;
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
					ikInfo->enable = IKEnableKey->GetValue();
					model_frame->ik_Infos.AppendPtr(ikInfo)iferr_return;
				}
				mmd_animation->model_frames.AppendPtr(model_frame)iferr_return;
			}
		}
		else {
			mmd::VMD_Model* model_frame = NewObj(mmd::VMD_Model)iferr_return;
			model_frame->frame_no = setting.TimeOffset;
			model_frame->show = true;
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
		GetFloat(100002, setting_.PositionMultiple);
		GetFloat(100004, setting_.TimeOffset);
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