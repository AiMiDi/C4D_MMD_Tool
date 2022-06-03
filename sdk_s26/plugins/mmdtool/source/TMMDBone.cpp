#include "TMMDBone.h"
#include "OMMDBoneRoot.h"
#include "description/OMMDBoneRoot.h"

namespace tool {
inline Int32 TMMDBone::AddBondMorph(String morph_name)
{
	if (morph_name.IsEmpty())
	{
		morph_name = "morph_" + String::IntToString(bone_morph_name_index);
		bone_morph_name_index++;
	}
	BaseTag* pmx_bone_tag = static_cast<BaseTag*>(Get());
	DynamicDescription* const	ddesc = pmx_bone_tag->GetDynamicDescription();
	if (ddesc == nullptr)
		return(-1);
	const auto& res = bone_morph_data_arr.AppendPtr(NewObj(bone_morph_data).GetValue());
	iferr(res)
		return(-1);
	auto* data = res.GetValue();
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, DescID(PMX_BONE_MORPH_GRP) });
	data->grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, data->grp_id });
	data->strength_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_TRANSLATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, data->grp_id });
	data->translation_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_ROTATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, data->grp_id });
	data->rotation_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 2);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, data->grp_id });
	data->button_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, data->button_grp_id });
	data->button_delete_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, data->button_grp_id });
	data->button_rename_id = ddesc->Alloc(bc);
	const Int32 index = static_cast<Int32>(bone_morph_data_arr.GetIndex(*data));
	iferr(button_id_map.Insert(data->button_delete_id, index))
		return(-1);
	iferr(button_id_map.Insert(data->button_rename_id, index))
		return(-1);
	// BONE_MORPH_ADD
	const maxon::StrongRef<TMMDBone_MSG> msg(NewObj(TMMDBone_MSG, TMMDBone_MSG_Type::BONE_MORPH_ADD, morph_name, data->strength_id, static_cast<BaseTag*>(Get())).GetValue());
	this->m_BoneRoot_ptr->Message(ID_T_MMD_BONE, msg);
	data->name = std::move(morph_name);
	if (GeIsMainThread())
	{
		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
		EventAdd();
	}
	return(index);
}
Bool TMMDBone::SplineDataCallBack(Int32 cid, const void* data)
{
	/* 还有其他一些回调类型，我们在这里仅使用SPLINE_CALLBACK_CORE_MESSAGE */
	if (cid == SPLINE_CALLBACK_CORE_MESSAGE)
	{
		if (data == nullptr)
			return(true);

		/* 数据信息... */
		SplineData* splineData = (static_cast<const SplineDataCallbackCoreMessage*>(data))->pGUI->GetSplineData();
		if (splineData == nullptr)
			return(true);


		/*
		 * 现在我们只需检查所有的knot并限制它们。我只是限制在这里的每个切线的[0，1]区间，
		 * 限制就是把切线控制点正交投影切线到“[0，1]”。
		 * 如果要缩放向量，使位于[0，1]区间外部的控制柄以该控制柄接触该框边界的方式进行缩放。
		 */
		for (int i = 0; i < splineData->GetKnotCount(); i++)
		{
			/* 获取当前knot。 */
			CustomSplineKnot* knot = splineData->GetKnot(i);
			/* 切线存在于相对于其顶点的向量空间中，因此我们首先使切线向量全局化，然后限制它们。 */
			Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
			globalLeftTangent.ClampMax(Vector(127., 127., 0.));
			globalLeftTangent.ClampMin(Vector(0.0));
			Vector globalRightTangent = knot->vPos + knot->vTangentRight;
			globalRightTangent.ClampMax(Vector(127, 127, 0));
			globalRightTangent.ClampMin(Vector(0.0));
			/* 然后我们把切线转换回它们的局部切线空间，然后写回去。 */
			knot->vTangentLeft = globalLeftTangent - knot->vPos;
			knot->vTangentRight = globalRightTangent - knot->vPos;
		}
	}
	return(true);
}
Bool TMMDBone::GetInterpolator(const Int32& type, const Int32& frame_on, mmd::VMDInterpolator& interpolator) const
{
	switch (type)
	{
	case (PMX_BONE_TAG_XCURVE): {
		auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_x_ptr == nullptr)
		{
			/*Set the interpolator as the default*/
			interpolator.SetValue();
			return(false);
		}
		else {
			interpolator = interpolator_x_ptr->GetValue();
		}
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
		auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_y_ptr == nullptr)
		{
			/*Set the interpolator as the default*/
			interpolator.SetValue();
			return(false);
		}
		else {
			interpolator = interpolator_y_ptr->GetValue();
		}
		break;
	}
	case (PMX_BONE_TAG_ZCURVE):
	{
		auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_z_ptr == nullptr)
		{
			/*Set the interpolator as the default*/
			interpolator.SetValue();
			return(false);
		}
		else {
			interpolator = interpolator_z_ptr->GetValue();
		}
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr == nullptr)
		{
			/*Set the interpolator as the default*/
			interpolator.SetValue();
			return(false);
		}
		else {
			interpolator = interpolator_r_ptr->GetValue();
		}
		break;
	}
	case (PMX_BONE_TAG_ACURVE): {
		auto interpolator_a_ptr = interpolator_A_map.Find(frame_on);
		if (interpolator_a_ptr == nullptr)
		{
			/*Set the interpolator as the default*/
			interpolator.SetValue();
			return(false);
		}
		else {
			interpolator = interpolator_a_ptr->GetValue();
		}
		break;
	}
	default:
		return(false);
	}
	return(true);
}
Bool TMMDBone::SetInterpolator(const Int32& type, const Int32& frame_on, mmd::VMDInterpolator&& interpolator, Bool cover)
{
	iferr_scope_handler{
		return false;
	};
	BaseTag* tag = static_cast<BaseTag*>(Get());
	if (tag == nullptr)
	{
		return(false);
	}
	CTrack* Frame_onTrack = tag->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	if (Frame_onTrack == nullptr)
	{
		Frame_onTrack = CTrack::Alloc(tag, DescID(PMX_BONE_TAG_FRAME_ON));
		tag->InsertTrackSorted(Frame_onTrack);
	}
	CCurve* Frame_onCurve = Frame_onTrack->GetCurve();
	BaseTime time(frame_on, 30);
	CKey* KeyFrame_on = Frame_onCurve->FindKey(time);
	if (KeyFrame_on == nullptr) {
		KeyFrame_on = Frame_onCurve->AddKey(time);
		KeyFrame_on->SetInterpolation(Frame_onCurve, CINTERPOLATION::STEP);
		KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
		KeyFrame_on->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
	}
	KeyFrame_on->SetValue(Frame_onCurve, time.GetFrame(30.));
	switch (type)
	{
	case (PMX_BONE_TAG_XCURVE): {
		auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_x_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_x = interpolator_x_ptr->GetValue();
				interpolator_position_x = std::move(interpolator);
			}
		}
		else {
			interpolator_X_map.Insert(frame_on, std::move(interpolator)) iferr_return;
		}
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
		auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_y_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_y = interpolator_y_ptr->GetValue();
				interpolator_position_y = std::move(interpolator);
			}
		}
		else {
			interpolator_Y_map.Insert(frame_on, std::move(interpolator)) iferr_return;
		}
		break;
	}
	case (PMX_BONE_TAG_ZCURVE): {
		auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_z_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_z = interpolator_z_ptr->GetValue();
				interpolator_position_z = std::move(interpolator);
			}
		}
		else {
			interpolator_Z_map.Insert(frame_on, std::move(interpolator)) iferr_return;
		}
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_rotation = interpolator_r_ptr->GetValue();
				interpolator_rotation = std::move(interpolator);
			}
		}
		else {
			interpolator_R_map.Insert(frame_on, std::move(interpolator)) iferr_return;
		}
		break;
	}
	case (PMX_BONE_TAG_ACURVE): {
		auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_x_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_x = interpolator_x_ptr->GetValue();
				interpolator_position_x = interpolator;
			}
		}
		else {
			interpolator_X_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_y_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_y = interpolator_y_ptr->GetValue();
				interpolator_position_y = interpolator;
			}
		}
		else {
			interpolator_Y_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_z_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_z = interpolator_z_ptr->GetValue();
				interpolator_position_z = interpolator;
			}
		}
		else {
			interpolator_Z_map.Insert(frame_on, interpolator) iferr_return;
		}
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_rotation = interpolator_r_ptr->GetValue();
				interpolator_rotation = std::move(interpolator);
			}
		}
		else {
			interpolator_R_map.Insert(frame_on, std::move(interpolator)) iferr_return;
		}
		break;
	}
	default:
		return(false);
	}
	return(true);
}
Bool TMMDBone::AutoRegisterKeyFrame(Int32 use_rotation, GeListNode* node) {
	iferr_scope_handler{
		return false;
	};
	if (node == nullptr)
	{
		node = Get();
	}
	if (obj == nullptr)
	{
		return(false);
	}

	Bool quaternion_rotation_mode = obj->IsQuaternionRotationMode();
	if (quaternion_rotation_mode == true) {
		obj->SetQuaternionRotationMode(false, false);
	}

	CCurve* Curve_position_x = nullptr;
	CCurve* Curve_position_y = nullptr;
	CCurve* Curve_position_z = nullptr;
	CCurve* Curve_rotation_x = nullptr;
	CCurve* Curve_rotation_y = nullptr;
	CCurve* Curve_rotation_z = nullptr;

	GetActiveDocument()->SetTime(BaseTime(0.));

	CTrack* Track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	if (Track_position_x == nullptr)
	{
		Track_position_x = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
		Curve_position_x = Track_position_x->GetCurve();
		Curve_position_x->AddKey(BaseTime());
		obj->InsertTrackSorted(Track_position_x);
	}
	else {
		Curve_position_x = Track_position_x->GetCurve();
	}
	CTrack* Track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	if (Track_position_y == nullptr)
	{
		Track_position_y = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
		Curve_position_y = Track_position_y->GetCurve();
		Curve_position_y->AddKey(BaseTime());
		obj->InsertTrackSorted(Track_position_y);
	}
	else {
		Curve_position_y = Track_position_y->GetCurve();
	}
	CTrack* Track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	if (Track_position_z == nullptr)
	{
		Track_position_z = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
		Curve_position_z = Track_position_z->GetCurve();
		Curve_position_z->AddKey(BaseTime());
		obj->InsertTrackSorted(Track_position_z);
	}
	else {
		Curve_position_z = Track_position_z->GetCurve();
	}
	CTrack* Track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	if (Track_rotation_x == nullptr)
	{
		Track_rotation_x = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
		Curve_rotation_x = Track_rotation_x->GetCurve();
		Curve_rotation_x->AddKey(BaseTime());
		obj->InsertTrackSorted(Track_rotation_x);
	}
	else {
		Curve_rotation_x = Track_rotation_x->GetCurve();
	}
	CTrack* Track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	if (Track_rotation_y == nullptr)
	{
		Track_rotation_y = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
		Curve_rotation_y = Track_rotation_y->GetCurve();
		Curve_rotation_y->AddKey(BaseTime());
		obj->InsertTrackSorted(Track_rotation_y);
	}
	else {
		Curve_rotation_y = Track_rotation_y->GetCurve();
	}
	CTrack* Track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	if (Track_rotation_z == nullptr)
	{
		Track_rotation_z = CTrack::Alloc(obj, DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
		Curve_rotation_z = Track_rotation_z->GetCurve();
		Curve_rotation_z->AddKey(BaseTime());
		obj->InsertTrackSorted(Track_rotation_z);
	}
	else {
		Curve_rotation_z = Track_rotation_z->GetCurve();
	}

	maxon::HashSet<MyBaseTime> frame_set;
	Int32 frame_count = Curve_position_x->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(Curve_position_x->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = Curve_position_y->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(Curve_position_y->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = Curve_position_z->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(Curve_position_z->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = Curve_rotation_x->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(Curve_rotation_x->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = Curve_rotation_y->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(Curve_rotation_y->GetKey(i)->GetTime())iferr_return;
	}
	frame_count = Curve_rotation_z->GetKeyCount();
	for (Int32 i = 0; i < frame_count; i++)
	{
		frame_set.Insert(Curve_rotation_z->GetKey(i)->GetTime())iferr_return;
	}
	for (const BaseTime& time : frame_set)
	{
		CKey* Key_position_x = Curve_position_x->FindKey(time);
		if (Key_position_x == nullptr) {
			Key_position_x = Curve_position_x->AddKeyAdaptTangent(time, true);
		}
		CKey* Key_position_y = Curve_position_y->FindKey(time);
		if (Key_position_y == nullptr) {
			Key_position_y = Curve_position_y->AddKeyAdaptTangent(time, true);
		}
		CKey* Key_position_z = Curve_position_z->FindKey(time);
		if (Key_position_z == nullptr) {
			Key_position_z = Curve_position_z->AddKeyAdaptTangent(time, true);
		}
		CKey* Key_rotation_x = Curve_rotation_x->FindKey(time);
		if (Key_rotation_x == nullptr) {
			Key_rotation_x = Curve_rotation_x->AddKeyAdaptTangent(time, true);
		}
		CKey* Key_rotation_y = Curve_rotation_y->FindKey(time);
		if (Key_rotation_y == nullptr) {
			Key_rotation_y = Curve_rotation_y->AddKeyAdaptTangent(time, true);
		}
		CKey* Key_rotation_z = Curve_rotation_z->FindKey(time);
		if (Key_rotation_z == nullptr) {
			Key_rotation_z = Curve_rotation_z->AddKeyAdaptTangent(time, true);
		}
	}

	frame_count = Int32(frame_set.GetCount() - 1);
	frame_set.Reset();
	const Float	Fps = GetActiveDocument()->GetFps();
	Float		ValueOfTwoFrames;
	Int32		TimeOfTwoFrames;
	Float KeyLeftX = 0., KeyLeftY = 0., KeyRightX = 0., KeyRightY = 0., NextKeyLeftX = 0., NextKeyLeftY = 0., NextKeyRightX = 0., NextKeyRightY = 0.;
	CKey* now_key = nullptr;
	CKey* next_key = nullptr;
	Int32 now_key_frame = 0;
	Int32 next_key_frame = 0;

	//第一帧
	now_key = Curve_position_x->GetKey(0);
	now_key_frame = now_key->GetTime().GetFrame(Fps);
	if (frame_count > 0) //第一帧不是最后一帧
	{
		next_key = Curve_position_x->GetKey(1);
		next_key_frame = next_key->GetTime().GetFrame(Fps);
		ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
		TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
		Curve_position_x->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
		Curve_position_x->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
			return false;
	}
	//最后一帧
	if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, Curve_position_x->GetKey(frame_count)->GetTime().GetFrame(Fps), mmd::VMDInterpolator())) {
		return false;
	}
	// 循环第2到最后一个
	for (Int32 key_index = 1; key_index < frame_count; key_index++)
	{
		now_key = next_key;
		now_key_frame = next_key_frame;
		next_key = Curve_position_x->GetKey(key_index + 1);
		next_key_frame = next_key->GetTime().GetFrame(Fps);
		ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
		TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
		KeyLeftX = NextKeyLeftX;
		KeyLeftY = NextKeyLeftY;
		KeyRightX = NextKeyRightX;
		KeyRightY = NextKeyRightY;
		Curve_position_x->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
			return false;

	}

	//第一帧
	now_key = Curve_position_y->GetKey(0);
	now_key_frame = now_key->GetTime().GetFrame(Fps);
	if (frame_count > 0) //第一帧不是最后一帧
	{
		next_key = Curve_position_y->GetKey(1);
		next_key_frame = next_key->GetTime().GetFrame(Fps);
		ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
		TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
		Curve_position_y->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
		Curve_position_y->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
			return false;
	}
	//最后一帧
	if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, Curve_position_y->GetKey(frame_count)->GetTime().GetFrame(Fps), mmd::VMDInterpolator())) {
		return false;
	}
	// 循环第2到最后一个
	for (Int32 key_index = 1; key_index < frame_count; key_index++)
	{
		now_key = next_key;
		now_key_frame = next_key_frame;
		next_key = Curve_position_y->GetKey(key_index + 1);
		next_key_frame = next_key->GetTime().GetFrame(Fps);
		ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
		TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
		KeyLeftX = NextKeyLeftX;
		KeyLeftY = NextKeyLeftY;
		KeyRightX = NextKeyRightX;
		KeyRightY = NextKeyRightY;
		Curve_position_y->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
			return false;
	}

	//第一帧
	now_key = Curve_position_z->GetKey(0);
	now_key_frame = now_key->GetTime().GetFrame(Fps);
	if (frame_count > 0) //第一帧不是最后一帧
	{
		next_key = Curve_position_z->GetKey(1);
		next_key_frame = next_key->GetTime().GetFrame(Fps);
		ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
		TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
		Curve_position_z->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
		Curve_position_z->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
			return false;
	}
	//最后一帧
	if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, Curve_position_z->GetKey(frame_count)->GetTime().GetFrame(Fps), mmd::VMDInterpolator())) {
		return false;
	}
	// 循环第2到最后一个
	for (Int32 key_index = 1; key_index < frame_count; key_index++)
	{
		now_key = next_key;
		now_key_frame = next_key_frame;
		next_key = Curve_position_z->GetKey(key_index + 1);
		next_key_frame = next_key->GetTime().GetFrame(Fps);
		ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
		TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
		KeyLeftX = NextKeyLeftX;
		KeyLeftY = NextKeyLeftY;
		KeyRightX = NextKeyRightX;
		KeyRightY = NextKeyRightY;
		Curve_position_z->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
			return false;
	}
	switch (use_rotation)
	{
	case 0:
		//第一帧
		now_key = Curve_rotation_x->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(Fps);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = Curve_rotation_x->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(Fps);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
			Curve_rotation_x->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			Curve_rotation_x->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
				return false;
		}
		//最后一帧
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, Curve_rotation_x->GetKey(frame_count)->GetTime().GetFrame(Fps), mmd::VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = Curve_rotation_x->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(Fps);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
			KeyLeftX = NextKeyLeftX;
			KeyLeftY = NextKeyLeftY;
			KeyRightX = NextKeyRightX;
			KeyRightY = NextKeyRightY;
			Curve_rotation_x->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
				return false;
		}
		break;
	case 1:
		//第一帧
		now_key = Curve_rotation_y->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(Fps);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = Curve_rotation_y->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(Fps);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
			Curve_rotation_y->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			Curve_rotation_y->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
				return false;
		}
		//最后一帧
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, Curve_rotation_y->GetKey(frame_count)->GetTime().GetFrame(Fps), mmd::VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = Curve_rotation_y->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(Fps);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
			KeyLeftX = NextKeyLeftX;
			KeyLeftY = NextKeyLeftY;
			KeyRightX = NextKeyRightX;
			KeyRightY = NextKeyRightY;
			Curve_rotation_y->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
				return false;
		}
		break;
	case 2:
		//第一帧
		now_key = Curve_rotation_z->GetKey(0);
		now_key_frame = now_key->GetTime().GetFrame(Fps);
		if (frame_count > 0) //第一帧不是最后一帧
		{
			next_key = Curve_rotation_z->GetKey(1);
			next_key_frame = next_key->GetTime().GetFrame(Fps);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
			Curve_rotation_z->GetTangents(0, &KeyLeftY, &KeyRightY, &KeyLeftX, &KeyRightX);
			Curve_rotation_z->GetTangents(1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
				return false;
		}
		//最后一帧
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, Curve_rotation_z->GetKey(frame_count)->GetTime().GetFrame(Fps), mmd::VMDInterpolator())) {
			return false;
		}
		// 循环第2到最后一个
		for (Int32 key_index = 1; key_index < frame_count; key_index++)
		{
			now_key = next_key;
			now_key_frame = next_key_frame;
			next_key = Curve_rotation_z->GetKey(key_index + 1);
			next_key_frame = next_key->GetTime().GetFrame(Fps);
			ValueOfTwoFrames = next_key->GetValue() - now_key->GetValue();
			TimeOfTwoFrames = next_key->GetTime().GetFrame(Fps) - now_key_frame;
			KeyLeftX = NextKeyLeftX;
			KeyLeftY = NextKeyLeftY;
			KeyRightX = NextKeyRightX;
			KeyRightY = NextKeyRightY;
			Curve_rotation_z->GetTangents(key_index + 1, &NextKeyLeftY, &NextKeyRightY, &NextKeyLeftX, &NextKeyRightX);
			if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))), false))
				return false;
		}
		break;
	default:
		break;
	}
	obj->SetQuaternionRotationMode(quaternion_rotation_mode, false);
	this->UpdateAllInterpolator(node);
	return true;
}
inline Bool TMMDBone::RegisterKeyFrame(Int32 frame_on, GeListNode* node) {
	iferr_scope_handler{
		return false;
	};
	if (node == nullptr)
	{
		node = Get();
	}
	if (obj == nullptr)
	{
		return(false);
	}
	const BaseTime	time = BaseTime(Float(frame_on), 30.);

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

	CCurve* Curve_position_x = Track_position_x->GetCurve();
	CCurve* Curve_position_y = Track_position_y->GetCurve();
	CCurve* Curve_position_z = Track_position_z->GetCurve();
	CCurve* Curve_rotation_x = Track_rotation_x->GetCurve();
	CCurve* Curve_rotation_y = Track_rotation_y->GetCurve();
	CCurve* Curve_rotation_z = Track_rotation_z->GetCurve();

	Vector RelPos = obj->GetRelPos();
	Vector RelRot = obj->GetRelRot();

	CKey* Key_position_x = Curve_position_x->FindKey(time);
	if (Key_position_x == nullptr) {
		Curve_position_x->AddKey(time);
	}
	else {
		Key_position_x->SetValue(Curve_position_x, RelPos.x);
	}
	CKey* Key_position_y = Curve_position_y->FindKey(time);
	if (Key_position_y == nullptr) {
		Curve_position_y->AddKey(time);
	}
	else {
		Key_position_y->SetValue(Curve_position_y, RelPos.y);
	}
	CKey* Key_position_z = Curve_position_z->FindKey(time);
	if (Key_position_z == nullptr) {
		Curve_position_z->AddKey(time);
	}
	else {
		Key_position_z->SetValue(Curve_position_z, RelPos.z);
	}
	CKey* Key_rotation_x = Curve_rotation_x->FindKey(time);
	if (Key_rotation_x == nullptr) {
		Curve_rotation_x->AddKey(time);
	}
	else {
		Key_rotation_x->SetValue(Curve_rotation_x, RelRot.x);
	}
	CKey* Key_rotation_y = Curve_rotation_y->FindKey(time);
	if (Key_rotation_y == nullptr) {
		Curve_rotation_y->AddKey(time);
	}
	else {
		Key_rotation_y->SetValue(Curve_rotation_y, RelRot.y);
	}
	CKey* Key_rotation_z = Curve_rotation_z->FindKey(time);
	if (Key_rotation_z == nullptr) {
		Curve_rotation_z->AddKey(time);
	}
	else {
		Key_rotation_z->SetValue(Curve_rotation_z, RelRot.z);
	}
	GeData	spline_data;
	BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();
	spline_data = bc->GetData(PMX_BONE_TAG_SPLINE);
	SplineData* spline = (SplineData*)spline_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
	const Int32 KnotCount = spline->GetKnotCount();
	for (int i = 0; i < KnotCount; i++)
	{
		/* 获取当前knot。 */
		CustomSplineKnot* knot = spline->GetKnot(i);
		/* 切线存在于相对于其顶点的向量空间中，首先使切线向量全局化，限制。 */
		Vector globalLeftTangent = knot->vPos + knot->vTangentLeft;
		globalLeftTangent.ClampMax(Vector(127., 127., 0.));
		globalLeftTangent.ClampMin(Vector(0.0));
		Vector globalRightTangent = knot->vPos + knot->vTangentRight;
		globalRightTangent.ClampMax(Vector(127., 127., 0.));
		globalRightTangent.ClampMin(Vector(0.0));
		/* 把切线转换回它们的局部切线空间，写回。 */
		knot->vTangentLeft = globalLeftTangent - knot->vPos;
		knot->vTangentRight = globalRightTangent - knot->vPos;
	}

	Int32 interpolator_type = bc->GetInt32(PMX_BONE_TAG_CURVE_TYPE);
	switch (interpolator_type)
	{
	case (PMX_BONE_TAG_XCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, mmd::VMDInterpolator(
			(UChar)spline->GetKnot(0)->vTangentRight.x, (UChar)spline->GetKnot(0)->vTangentRight.y,
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, mmd::VMDInterpolator(
			(UChar)spline->GetKnot(0)->vTangentRight.x, (UChar)spline->GetKnot(0)->vTangentRight.y,
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_ZCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, mmd::VMDInterpolator(
			(UChar)spline->GetKnot(0)->vTangentRight.x, (UChar)spline->GetKnot(0)->vTangentRight.y,
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, mmd::VMDInterpolator(
			(UChar)spline->GetKnot(0)->vTangentRight.x, (UChar)spline->GetKnot(0)->vTangentRight.y,
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_on, mmd::VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_ACURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, mmd::VMDInterpolator(
			(UChar)spline->GetKnot(0)->vTangentRight.x, (UChar)spline->GetKnot(0)->vTangentRight.y,
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			(UChar)127U + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		break;
	}
	default:
		break;
	}
	this->UpdateAllInterpolator(node);
	return true;
}
inline Bool TMMDBone::UpdateAllInterpolator(GeListNode* node)
{
	if (obj == nullptr)
	{
		return(false);
	}

	BaseTag* tag = static_cast<BaseTag*>(Get());
	CTrack* Track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* Track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* Track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* Track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* Track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* Track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* frameTrack = tag->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));

	if (Track_position_x == nullptr || Track_position_y == nullptr || Track_position_z == nullptr ||
		Track_rotation_x == nullptr || Track_rotation_y == nullptr || Track_rotation_z == nullptr || frameTrack == nullptr)
	{
		return false;
	}

	CCurve* Curve_position_x = Track_position_x->GetCurve();
	CCurve* Curve_position_y = Track_position_y->GetCurve();
	CCurve* Curve_position_z = Track_position_z->GetCurve();
	CCurve* Curve_rotation_x = Track_rotation_x->GetCurve();
	CCurve* Curve_rotation_y = Track_rotation_y->GetCurve();
	CCurve* Curve_rotation_z = Track_rotation_z->GetCurve();
	CCurve* frameCurve = frameTrack->GetCurve();

	if (Curve_position_x == nullptr || Curve_position_y == nullptr || Curve_position_z == nullptr ||
		Curve_rotation_x == nullptr || Curve_rotation_y == nullptr || Curve_rotation_z == nullptr || frameCurve == nullptr)
	{
		return false;
	}

	Int32 frame_on = 0;
	Float value_between_frame;
	BaseTime time_between_frame = BaseTime();
	BaseTime time = BaseTime();
	BaseTime next_time = BaseTime();
	CKey* key;
	CKey* next_key;

	const Int32 KeyCount = frameCurve->GetKeyCount();
	for (Int32 frame_index = 0; frame_index < KeyCount; frame_index++)
	{
		const CKey* frame_key = frameCurve->GetKey(frame_index);
		frame_on = maxon::SafeConvert<Int32>(frame_key->GetValue());
		time = frame_key->GetTime();
		const CKey* frame_next = frameCurve->FindKey(time + BaseTime(1., 100.), nullptr, FINDANIM::RIGHT); /* 加0.1排除所在的那一帧 */
		if (frame_next == nullptr)
		{
			break;
		}
		next_time = frame_next->GetTime();
		time_between_frame = next_time - time;

		maxon::HashMap<Int32, mmd::VMDInterpolator>::Entry* interpolator_ptr = interpolator_X_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const mmd::VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_position_x->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_position_x->FindKey(next_time);
				if (next_key != nullptr)
				{
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					if (interpolator.IsLinear())
					{
						key->SetInterpolation(Curve_position_x, CINTERPOLATION::LINEAR);
					}
					else {
						value_between_frame = next_key->GetValue() - key->GetValue();
						next_key->SetTimeLeft(Curve_position_x, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::bx) - 127.0), 127.0));
						next_key->SetValueLeft(Curve_position_x, value_between_frame * Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::by) - 127) / 127.0);
						key->SetTimeRight(Curve_position_x, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ax)), 127.0));
						key->SetValueRight(Curve_position_x, value_between_frame * (Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ay)) / 127.0));
					}
				}
			}
		}
		interpolator_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const mmd::VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_position_y->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_position_y->FindKey(next_time);
				if (next_key != nullptr)
				{
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					if (interpolator.IsLinear())
					{
						key->SetInterpolation(Curve_position_y, CINTERPOLATION::LINEAR);
					}
					else {
						value_between_frame = next_key->GetValue() - key->GetValue();
						next_key->SetTimeLeft(Curve_position_y, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::bx) - 127.0), 127.0));
						next_key->SetValueLeft(Curve_position_y, value_between_frame * Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::by) - 127) / 127.0);
						key->SetTimeRight(Curve_position_y, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ax)), 127.0));
						key->SetValueRight(Curve_position_y, value_between_frame * (Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ay)) / 127.0));
					}
				}
			}
		}
		interpolator_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const mmd::VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_position_z->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_position_z->FindKey(next_time);
				if (next_key != nullptr)
				{
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					if (interpolator.IsLinear())
					{
						key->SetInterpolation(Curve_position_z, CINTERPOLATION::LINEAR);
					}
					else {
						value_between_frame = next_key->GetValue() - key->GetValue();
						next_key->SetTimeLeft(Curve_position_z, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::bx) - 127.0), 127.0));
						next_key->SetValueLeft(Curve_position_z, value_between_frame * Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::by) - 127) / 127.0);
						key->SetTimeRight(Curve_position_z, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ax)), 127.0));
						key->SetValueRight(Curve_position_z, value_between_frame * (Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ay)) / 127.0));
					}
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const mmd::VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_rotation_x->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_rotation_x->FindKey(next_time);
				if (next_key != nullptr)
				{
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					if (interpolator.IsLinear())
					{
						key->SetInterpolation(Curve_rotation_x, CINTERPOLATION::LINEAR);
					}
					else {
						value_between_frame = next_key->GetValue() - key->GetValue();
						next_key->SetTimeLeft(Curve_rotation_x, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::bx) - 127.0), 127.0));
						next_key->SetValueLeft(Curve_rotation_x, value_between_frame * Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::by) - 127) / 127.0);
						key->SetTimeRight(Curve_rotation_x, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ax)), 127.0));
						key->SetValueRight(Curve_rotation_x, value_between_frame * (Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ay)) / 127.0));
					}
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const mmd::VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_rotation_y->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_rotation_y->FindKey(next_time);
				if (next_key != nullptr)
				{
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					if (interpolator.IsLinear())
					{
						key->SetInterpolation(Curve_rotation_y, CINTERPOLATION::LINEAR);
					}
					else {
						value_between_frame = next_key->GetValue() - key->GetValue();
						next_key->SetTimeLeft(Curve_rotation_y, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::bx) - 127.0), 127.0));
						next_key->SetValueLeft(Curve_rotation_y, value_between_frame * Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::by) - 127) / 127.0);
						key->SetTimeRight(Curve_rotation_y, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ax)), 127.0));
						key->SetValueRight(Curve_rotation_y, value_between_frame * (Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ay)) / 127.0));
					}
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const mmd::VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_rotation_z->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_rotation_z->FindKey(next_time);
				if (next_key != nullptr)
				{
					key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
					if (interpolator.IsLinear())
					{
						key->SetInterpolation(Curve_rotation_z, CINTERPOLATION::LINEAR);
					}
					else {
						value_between_frame = next_key->GetValue() - key->GetValue();
						next_key->SetTimeLeft(Curve_rotation_z, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::bx) - 127.0), 127.0));
						next_key->SetValueLeft(Curve_rotation_z, value_between_frame * Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::by) - 127) / 127.0);
						key->SetTimeRight(Curve_rotation_z, time_between_frame * BaseTime(Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ax)), 127.0));
						key->SetValueRight(Curve_rotation_z, value_between_frame * (Float(interpolator.GetValue(mmd::VMDInterpolator::PartType::ay)) / 127.0));
					}
				}
			}
		}
	}
	return(true);
}
inline Bool TMMDBone::DeleteKeyFrame(Int32 frame_on, GeListNode* node) {
	if (obj == nullptr)
	{
		return(false);
	}
	if (node == nullptr)
	{
		node = Get();
	}
	const BaseTime	time = BaseTime(Float(frame_on), 30.);

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
	CTrack* Frame_onTrack = static_cast<BaseTag*>(node)->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	if (Frame_onTrack != nullptr)
	{
		CKey* KeyFrame_on = Frame_onTrack->GetCurve()->FindKey(time);
		CKey::Free(KeyFrame_on);
	}
	return true;
}
inline Bool  TMMDBone::DeleteAllKeyFrame(GeListNode* node) {
	if (obj == nullptr)
	{
		return(false);
	}
	if (node == nullptr)
	{
		node = Get();
	}
	this->interpolator_X_map.Reset();
	this->interpolator_Y_map.Reset();
	this->interpolator_Z_map.Reset();
	this->interpolator_R_map.Reset();
	this->interpolator_A_map.Reset();
	CTrack* Frame_onTrack = static_cast<BaseTag*>(node)->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
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
	obj->SetRelPos(Vector());
	obj->SetRelRot(Vector());
	return true;
}
inline Bool TMMDBone::InitInterpolator(GeListNode* node)
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
		spline->SetUserCallback(TMMDBone::SplineDataCallBack, nullptr);
		CustomSplineKnot* a = spline->GetKnot(0);
		CustomSplineKnot* b = spline->GetKnot(spline->GetKnotCount() - 1);
		a->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		b->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		a->vTangentRight = Vector(20., 20., 0.);
		b->vTangentLeft = Vector(-20., -20., 0.);
	}
	bc->SetData(PMX_BONE_TAG_SPLINE, data);
	return(true);
}
Bool TMMDBone::Init(GeListNode* node)
{
	if (node == nullptr)
		return(false);
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return(false);

	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_T_MMD_BONE));
	bc->SetString(PMX_BONE_NAME_LOCAL, "bone"_s);
	bc->SetInt32(PMX_BONE_NAME_IS_LOCAL, 2);
	bc->SetString(PMX_BONE_NAME_UNIVERSAL, "bone"_s);
	bc->SetString(PMX_BONE_PARENT_BONE_INDEX, "-1"_s);
	bc->SetString(PMX_BONE_PARENT_BONE_NAME, ""_s);
	bc->SetInt32(PMX_BONE_ROTATABLE, 1);
	bc->SetInt32(PMX_BONE_VISIBLE, 1);
	bc->SetInt32(PMX_BONE_ENABLED, 1);
	bc->SetInt32(PMX_BONE_TAIL_INDEX, 0);
	bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, -1);
	bc->SetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, 1.0);
	bc->SetVector(PMX_BONE_LOCAL_X, Vector(1, 0, 0));
	bc->SetVector(PMX_BONE_LOCAL_Z, Vector(0, 0, 1));
	GeData priority;
	if (node->GetParameter(DescLevel(EXPRESSION_PRIORITY), priority, DESCFLAGS_GET::NONE))
	{
		PriorityData* pd = (PriorityData*)priority.GetCustomDataType(CUSTOMGUI_PRIORITY_DATA);
		if (pd)
		{
			pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, 1);
		}

		bc->SetData(EXPRESSION_PRIORITY, priority);
	}
	if (!InitInterpolator(node))
		return(false);
	return(true);
}
Bool TMMDBone::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (id[0].id == PMX_BONE_TAG_FRAME_ON)
	{
		return(false);
	}
	if (id[0].id == PMX_BONE_TAIL_INDEX)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == PMX_BONE_TAIL_IS_POSITION)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_TAIL_POSITION)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == PMX_BONE_TAIL_IS_INDEX)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_INHERIT_BONE_PARENT_INDEX)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_INHERIT_BONE_PARENT_LINK)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_FIXED_AXIS)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_IS_FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
		Bool fixed_axis = Ge_data.GetBool();
		if (fixed_axis == 0)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_LOCAL_X)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_LOCAL_IS_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0)
		{
			return(false);
		}
	}
	if (id[0].id == PMX_BONE_LOCAL_Z)
	{
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_LOCAL_IS_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0)
		{
			return(false);
		}
	}
	return(SUPER::GetDEnabling(node, id, t_data, flags, itemdesc));
}
EXECUTIONRESULT TMMDBone::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (tag == nullptr || op == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	BaseContainer* bc = static_cast<BaseList2D*>(tag)->GetDataInstance();
	if (bc == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	obj = op;
	BaseTag* protection_tag = op->GetTag(Tprotection);
	if (protection_tag == nullptr)
	{
		protection_tag = op->MakeTag(Tprotection);
		if (protection_tag == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(EXECUTIONRESULT::OK);
		}
		protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		protection_tag->SetParameter(DescID(PROTECTION_ALLOW_EXPRESSIONS), true, DESCFLAGS_SET::NONE);
		if (bc->GetBool(PMX_BONE_ROTATABLE) == true)
		{
			protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
		}
		else
		{
			protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
		}
		if (bc->GetBool(PMX_BONE_TRANSLATABLE) == true)
		{
			protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
		}
		else
		{
			protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
		}
	}
	GeData		Ge_data;
	BaseObject* up_obj = op->GetUp();
	BaseObject* pred_obj = op->GetPred();
	const Int32	pred_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
	if (up_obj != nullptr)
	{
		BaseObject* tmp_lase_obj;
		BaseObject* lase_obj;
		BaseTag* lase_tag;
		if (!up_obj->IsInstanceOf(ID_O_MMD_BONE_ROOT))
		{
			tag->SetParameter(DescID(PMX_BONE_PARENT_BONE_NAME), up_obj->GetName(), DESCFLAGS_SET::NONE);
			BaseTag* up_tag = up_obj->GetTag(ID_T_MMD_BONE);
			if (up_tag != nullptr)
			{
				up_tag->GetParameter(DescID(PMX_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
				bc->SetData(PMX_BONE_PARENT_BONE_INDEX, Ge_data);
			}
			if (pred_obj == nullptr)
			{
				if (up_tag != nullptr)
				{
					up_tag->GetParameter(DescID(PMX_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
					bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
				}
			}
			else {
				lase_obj = pred_obj;
				/* 获取上一个骨骼 */
				while (pred_obj != nullptr && !pred_obj->IsInstanceOf(Ojoint)) {
					lase_obj = pred_obj;
					pred_obj = pred_obj->GetPred();
				}
				/* 获取到最后一个骨骼 */
				tmp_lase_obj = lase_obj->GetDownLast();
				while (tmp_lase_obj != nullptr)
				{
					if (tmp_lase_obj->IsInstanceOf(Ojoint)) {
						lase_obj = tmp_lase_obj;
						tmp_lase_obj = tmp_lase_obj->GetDownLast();
					}
					else {
						tmp_lase_obj = tmp_lase_obj->GetPred();
					}
				}
				lase_tag = lase_obj->GetTag(ID_T_MMD_BONE);
				if (lase_tag != nullptr)
				{
					lase_tag->GetParameter(PMX_BONE_INDEX, Ge_data, DESCFLAGS_GET::NONE);
					bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
				}
			}
		}
		else {
			if (pred_obj == nullptr)
			{
				if (this->m_BoneRoot_ptr == nullptr) {
					this->m_BoneRoot_ptr = up_obj;
					const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
						NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::BONEROOT_UPDATA, 0, up_obj).GetValue());
					op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				}
				bc->SetString(PMX_BONE_INDEX, "0"_s);
			}
			else {
				lase_obj = pred_obj;
				/* 获取上一个骨骼 */
				while (pred_obj != nullptr && !pred_obj->IsInstanceOf(Ojoint)) {
					lase_obj = pred_obj;
					pred_obj = pred_obj->GetPred();
				}
				/* 获取到最后一个骨骼 */
				tmp_lase_obj = lase_obj->GetDownLast();
				while (tmp_lase_obj != nullptr)
				{
					if (tmp_lase_obj->IsInstanceOf(Ojoint)) {
						lase_obj = tmp_lase_obj;
						tmp_lase_obj = tmp_lase_obj->GetDownLast();
					}
					else {
						tmp_lase_obj = tmp_lase_obj->GetPred();
					}
				}
				lase_tag = lase_obj->GetTag(ID_T_MMD_BONE);
				if (lase_tag != nullptr)
				{
					lase_tag->GetParameter(PMX_BONE_INDEX, Ge_data, DESCFLAGS_GET::NONE);
					bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
				}
			}
		}
	}
	else {
		this->m_BoneRoot_ptr = nullptr;
		const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
			NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::BONEROOT_UPDATA, 0, nullptr).GetValue());
		op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
		bc->SetString(PMX_BONE_INDEX, "0"_s);
	}
	Int32 now_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
	if (now_index != pred_index && this->m_BoneRoot_ptr != nullptr) {
		// BONE_INDEX_CHANGE
		const maxon::StrongRef<TMMDBone_MSG> msg(NewObj(TMMDBone_MSG, TMMDBone_MSG_Type::BONE_INDEX_CHANGE).GetValue());
		this->m_BoneRoot_ptr->Message(ID_T_MMD_BONE, msg);
	}
	Int32	frame_on = bc->GetInt32(PMX_BONE_TAG_FRAME_ON);
	Int32	curve_type = bc->GetInt32(PMX_BONE_TAG_CURVE_TYPE);
	if (prev_frame != frame_on || prev_interpolator_type != curve_type)
	{
		GeData		data_ = bc->GetData(PMX_BONE_TAG_SPLINE);
		SplineData* spline = (SplineData*)data_.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
		switch (curve_type)
		{
		case (PMX_BONE_TAG_XCURVE): {
			auto interpolator_x_ptr = interpolator_X_map.Find(frame_on);
			if (interpolator_x_ptr != nullptr)
			{
				mmd::VMDInterpolator& xCurve = interpolator_x_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(xCurve.GetValue(mmd::VMDInterpolator::PartType::ax), xCurve.GetValue(mmd::VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(xCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., xCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_YCURVE): {
			auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
			if (interpolator_y_ptr != nullptr)
			{
				mmd::VMDInterpolator& yCurve = interpolator_y_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(yCurve.GetValue(mmd::VMDInterpolator::PartType::ax), yCurve.GetValue(mmd::VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(yCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., yCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_ZCURVE): {
			auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
			if (interpolator_z_ptr != nullptr)
			{
				mmd::VMDInterpolator& zCurve = interpolator_z_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(zCurve.GetValue(mmd::VMDInterpolator::PartType::ax), zCurve.GetValue(mmd::VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(zCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., zCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_RCURVE): {
			auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
			if (interpolator_r_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_rotation = interpolator_r_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_rotation.GetValue(mmd::VMDInterpolator::PartType::ax), interpolator_rotation.GetValue(mmd::VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_rotation.GetValue(mmd::VMDInterpolator::PartType::by) - 127., interpolator_rotation.GetValue(mmd::VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight = Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_ACURVE): {
			auto interpolator_a_ptr = interpolator_A_map.Find(frame_on);
			if (interpolator_a_ptr != nullptr)
			{
				mmd::VMDInterpolator& aCurve = interpolator_a_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(aCurve.GetValue(mmd::VMDInterpolator::PartType::ax), aCurve.GetValue(mmd::VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(aCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., aCurve.GetValue(mmd::VMDInterpolator::PartType::by) - 127., 0.);
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
		bc->SetData(PMX_BONE_TAG_SPLINE, data_);
		prev_frame = frame_on;
		prev_interpolator_type = curve_type;
	}

	if (bc->GetBool(PMX_BONE_INHERIT_ROTATION) == 1)
	{
		if (inherit_bone_parent == nullptr)
		{
			BaseLink* inherit_bone_parent_link = bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK);
			if (inherit_bone_parent_link != nullptr)
				inherit_bone_parent = (BaseObject*)inherit_bone_parent_link->GetLink(tag->GetDocument());
		}
		else {
			op->SetRelRot(inherit_bone_parent->GetRelRot() * bc->GetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE));
		}
	}
	if (bc->GetBool(PMX_BONE_INHERIT_TRANSLATION) == 1)
	{
		if (inherit_bone_parent == nullptr)
		{
			BaseLink* inherit_bone_parent_link = bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK);
			if (inherit_bone_parent_link != nullptr)
				inherit_bone_parent = (BaseObject*)inherit_bone_parent_link->GetLink(tag->GetDocument());
		}
		else {
			op->SetRelPos(inherit_bone_parent->GetRelPos() * bc->GetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE));
		}
	}
	op->GetParameter(DescID(ID_BASEOBJECT_FROZEN_POSITION), Ge_data, DESCFLAGS_GET::NONE);
	Vector op_position = Ge_data.GetVector() - prev_position;
	prev_position = Vector(0);
	op->GetParameter(DescID(ID_BASEOBJECT_FROZEN_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
	Vector op_rotation = Ge_data.GetVector() - prev_rotation;
	prev_rotation = Vector(0);
	for (bone_morph_data& id : bone_morph_data_arr)
	{
		Float strength = 0;
		if (tag->GetParameter(id.strength_id, Ge_data, DESCFLAGS_GET::NONE))
		{
			strength = Ge_data.GetFloat();
		}
		if (tag->GetParameter(id.translation_id, Ge_data, DESCFLAGS_GET::NONE))
		{
			prev_position += Ge_data.GetVector() * strength;
		}
		if (tag->GetParameter(id.rotation_id, Ge_data, DESCFLAGS_GET::NONE))
		{
			prev_rotation += Ge_data.GetVector() * strength;
		}
	}
	op->SetParameter(DescID(ID_BASEOBJECT_FROZEN_POSITION), op_position + prev_position, DESCFLAGS_SET::NONE);
	op->SetParameter(DescID(ID_BASEOBJECT_FROZEN_ROTATION), op_rotation + prev_rotation, DESCFLAGS_SET::NONE);

	return(EXECUTIONRESULT::OK);
}
Bool TMMDBone::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return(false);
	}
	switch (id[0].id)
	{
	case PMX_BONE_TAG_SPLINE:
	{
		static_cast<SplineData*>(t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(TMMDBone::SplineDataCallBack, nullptr);
		break;
	}
	case PMX_BONE_ROTATABLE:
	{
		if (obj == nullptr)
			return(true);
		if (t_data.GetBool() == true)
		{
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag != nullptr)
			{
				protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
			}
		}
		else {
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag != nullptr)
			{
				protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
			}
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (obj == nullptr)
			return(true);
		if (t_data.GetBool() == true)
		{
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag != nullptr)
			{
				protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
			}
		}
		else {
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag != nullptr)
			{
				protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
			}
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (obj == nullptr)
			return(true);
		if (t_data.GetBool() == false)
		{
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else {
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INDEXED_TAIL_POSITION:
	{
		if (obj == nullptr)
			return(true);
		switch (t_data.GetInt32())
		{
		case PMX_BONE_TAIL_IS_INDEX:
		{
			if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
			{
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		case PMX_BONE_TAIL_POSITION:
		{
			if (bc->GetVector(PMX_BONE_TAIL_POSITION) == Vector())
			{
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	case PMX_BONE_TAIL_INDEX:
	{
		if (obj == nullptr)
			return(true);
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
		{
			if (t_data.GetInt32() == -1)
			{
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_TAIL_POSITION:
	{
		if (obj == nullptr)
			return(true);
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
		{
			if (t_data.GetVector() == Vector())
			{
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_NAME_IS:
	{
		if (obj == nullptr)
			return(true);
		if (t_data.GetInt32() == true)
		{
			obj->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			obj->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_NAME_UNIVERSAL:
	case PMX_BONE_NAME_LOCAL:
	{
		if (obj == nullptr)
			return(true);
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			obj->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			obj->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		if (node->GetEnabling(PMX_BONE_INHERIT_BONE_PARENT_LINK, GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
			if (this->m_BoneRoot_ptr != nullptr) {
				BaseLink* inherit_bone_parent_link = t_data.GetBaseLink();
				if (inherit_bone_parent_link != nullptr) {
					inherit_bone_parent = static_cast<BaseObject*>(inherit_bone_parent_link->GetLink(GetActiveDocument()));
					auto inherit_bone_parent_index_ptr = this->m_BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->m_BoneToIndex_map.Find(inherit_bone_parent);
					if (inherit_bone_parent_index_ptr != nullptr) {
						bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, inherit_bone_parent_index_ptr->GetValue());
					}
				}
			}
		}
		break;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	{
		if (node->GetEnabling(PMX_BONE_INHERIT_BONE_PARENT_INDEX, GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
			if (this->m_BoneRoot_ptr != nullptr) {
				Int32 inherit_bone_parent_index = t_data.GetInt32();
				auto inherit_bone_parent_link_ptr = this->m_BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->m_IndexToBone_map.Find(inherit_bone_parent_index);
				if (inherit_bone_parent_link_ptr != nullptr) {
					BaseLink* inherit_bone_parent_link = bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK);
					if (inherit_bone_parent_link == nullptr) {
						inherit_bone_parent_link = BaseLink::Alloc();
						node->SetParameter(PMX_BONE_INHERIT_BONE_PARENT_LINK, inherit_bone_parent_link, DESCFLAGS_SET::NONE);
					}
					inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
				}
			}
		}
		break;
	}
	case PMX_BONE_IS_IK:
	case PMX_BONE_IS_FIXED_AXIS:
	case PMX_BONE_INHERIT_ROTATION:
	case PMX_BONE_INHERIT_TRANSLATION:
	{
		this->RefreshColor(node);
		break;
	}
	default:
		break;
	}
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
inline Bool TMMDBone::RefreshColor(GeListNode* node, BaseObject* op)
{
	if (op == nullptr)
	{
		op = this->obj;
	}
	if (node == nullptr)
	{
		node = Get();
	}
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return(false);
	}
	Int32	color = 0;
	Vector	colors[6]{
		Vector(0.56640625, 0.78125, 1),       /* Is_rotatable == 1 */
		Vector(0.703125, 1, 0.546875),        /* Is_translatable == 1 */
		Vector(0.984375, 0.375, 0),           /* Is_IK == 1 */
		Vector(0.4, 0.4, 0.4),                /* Is_visible == 0 */
		Vector(0.7265625, 0.328125, 1),       /* Fixed_axis == 1 */
		Vector(0.682353, 0.64453125, 1),      /* Inherit_rotation == 1||Inherit_translation == 1 */
	};
	if (bc->GetBool(PMX_BONE_ROTATABLE) == 1)
		color = 0;
	if (bc->GetBool(PMX_BONE_TRANSLATABLE) == 1)
		color = 1;
	if (bc->GetBool(PMX_BONE_IS_IK) == 1)
		color = 2;
	if (bc->GetBool(PMX_BONE_VISIBLE) == 0)
		color = 3;
	if (bc->GetBool(PMX_BONE_IS_FIXED_AXIS) == 1)
		color = 4;
	if (bc->GetBool(PMX_BONE_INHERIT_ROTATION) == 1 || bc->GetBool(PMX_BONE_INHERIT_TRANSLATION))
		color = 5;
	if (node != nullptr)
	{
#if API_VERSION >= 21000
		node->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		node->SetParameter(DescID(ID_BASELIST_ICON_COLOR), colors[color], DESCFLAGS_SET::NONE);
#endif
	}
	if (op != nullptr)
	{
#if API_VERSION >= 21000
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), colors[color], DESCFLAGS_SET::NONE);
#endif
		ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS, colors[color], true };
		op->SetColorProperties(&objColor);
	}
	return(true);
}
Bool TMMDBone::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return(true);
	};
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return(true);
	}
	switch (type)
	{
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32	id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		switch (id)
		{
		case PMX_BONE_ROTATABLE:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetBool(id) == 1)
			{
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag != nullptr)
				{
					protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
				}
			}
			else {
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag != nullptr)
				{
					protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
				}
			}
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_TRANSLATABLE:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetBool(id) == 1)
			{
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag != nullptr)
				{
					protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
				}
			}
			else {
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag != nullptr)
				{
					protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
					protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
				}
			}
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_VISIBLE:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetBool(id) == 0)
			{
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
			}
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_INDEXED_TAIL_POSITION:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetBool(id) == 1)
			{
				if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
				{
					obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
				}
				else {
					obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
				}
			}
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_TAIL_INDEX:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetBool(PMX_BONE_INDEXED_TAIL_POSITION) == 1)
			{
				if (bc->GetInt32(id) == -1)
				{
					obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
				}
				else {
					obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
				}
			}
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_NAME_IS:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetInt32(id) == 1)
			{
				obj->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
			}
			else {
				obj->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
			}
			break;
		}
		case PMX_BONE_NAME_UNIVERSAL:
		case PMX_BONE_NAME_LOCAL:
		{
			if (obj == nullptr)
				return(true);
			if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
			{
				obj->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
			}
			else {
				obj->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
			}
			break;
		}
		case PMX_BONE_INHERIT_BONE_PARENT_LINK:
		{
			if (node->GetEnabling(PMX_BONE_INHERIT_BONE_PARENT_LINK, GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
				if (this->m_BoneRoot_ptr != nullptr) {
					BaseLink* inherit_bone_parent_link = bc->GetBaseLink(id);
					if (inherit_bone_parent_link != nullptr) {
						inherit_bone_parent = static_cast<BaseObject*>(inherit_bone_parent_link->GetLink(GetActiveDocument()));
						auto inherit_bone_parent_index_ptr = this->m_BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->m_BoneToIndex_map.Find(inherit_bone_parent);
						if (inherit_bone_parent_index_ptr != nullptr) {
							bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, inherit_bone_parent_index_ptr->GetValue());
						}
					}
				}
			}
			break;
		}
		case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
		{
			if (node->GetEnabling(PMX_BONE_INHERIT_BONE_PARENT_INDEX, GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
				if (this->m_BoneRoot_ptr != nullptr) {
					Int32 inherit_bone_parent_index = bc->GetInt32(id);
					auto inherit_bone_parent_link_ptr = this->m_BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->m_IndexToBone_map.Find(inherit_bone_parent_index);
					if (inherit_bone_parent_link_ptr != nullptr) {
						BaseLink* inherit_bone_parent_link = bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK);
						if (inherit_bone_parent_link == nullptr) {
							inherit_bone_parent_link = BaseLink::Alloc();
							node->SetParameter(PMX_BONE_INHERIT_BONE_PARENT_LINK, inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						}
						inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
					}
				}
			}
			break;
		}
		case PMX_BONE_IS_IK:
		case PMX_BONE_IS_FIXED_AXIS:
		case PMX_BONE_INHERIT_ROTATION:
		case PMX_BONE_INHERIT_TRANSLATION:
		{
			this->RefreshColor(node);
			break;
		}
		default:
			break;
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc == nullptr)
			return(false);
		BaseDocument* doc = node->GetDocument();
		/* check if it is a user data button */
		if (dc->_descId.GetDepth() == 2 && dc->_descId[0].id == ID_USERDATA)
		{
			auto button_on_id_ptr = button_id_map.Find(dc->_descId);
			if (button_on_id_ptr != nullptr)
			{
				DynamicDescription* const ddesc = node->GetDynamicDescription();
				if (ddesc == nullptr)
					return(true);
				Int32 button_on_id = button_on_id_ptr->GetValue();
				if (button_on_id == -1)
					return(true);
				bone_morph_data& morph_data = bone_morph_data_arr[button_on_id];
				if (dc->_descId == morph_data.button_delete_id)
				{
					if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, morph_data.name))
					{
						ddesc->Remove(morph_data.button_delete_id);
						ddesc->Remove(morph_data.button_rename_id);
						ddesc->Remove(morph_data.button_grp_id);
						ddesc->Remove(morph_data.rotation_id);
						ddesc->Remove(morph_data.translation_id);
						ddesc->Remove(morph_data.strength_id);
						ddesc->Remove(morph_data.grp_id);			
						iferr(button_id_map.Erase(morph_data.button_delete_id))
							return true;
						iferr(button_id_map.Erase(morph_data.button_rename_id))
							return true;
						for (auto& i : button_id_map.GetKeys())
						{
							Int32* index = button_id_map.FindValue(i);
							if (*index > button_on_id)
							{
								(*index)--;
							}
						}
						// BONE_MORPH_DELETE
						const maxon::StrongRef<TMMDBone_MSG> msg(NewObj(TMMDBone_MSG, TMMDBone_MSG_Type::BONE_MORPH_DELETE, morph_data.name, morph_data.strength_id, static_cast<BaseTag*>(Get())).GetValue());
						this->m_BoneRoot_ptr->Message(ID_T_MMD_BONE, msg);	
						iferr(bone_morph_data_arr.Erase(button_on_id))
							return(true);
						::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
						if (::GeIsMainThread())
						{
							::EventAdd();
						}
					}
					return(true);
				}
				if (dc->_descId == morph_data.button_rename_id)
				{
					utility::RenameDialog dlg;
					dlg.Open(DLG_TYPE::MODAL, 99999, -1, -1, 0, 0);
					if (!dlg.Rename.IsEmpty())
					{
						BaseContainer descbc = *ddesc->Find(morph_data.grp_id);
						descbc.SetString(DESC_NAME, dlg.Rename);
						ddesc->Set(morph_data.grp_id, descbc, nullptr);
						descbc = *ddesc->Find(morph_data.strength_id);
						descbc.SetString(DESC_NAME, dlg.Rename);
						ddesc->Set(morph_data.strength_id, descbc, nullptr);
						// BONE_MORPH_RENAME
						const maxon::StrongRef<TMMDBone_MSG> msg(
							NewObj(TMMDBone_MSG, TMMDBone_MSG_Type::BONE_MORPH_RENAME, dlg.Rename, morph_data.strength_id, static_cast<BaseTag*>(Get()),morph_data.name).GetValue());
						this->m_BoneRoot_ptr->Message(ID_T_MMD_BONE, msg);
						morph_data.name = std::move(dlg.Rename);
						::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
						if (::GeIsMainThread())
						{
							::EventAdd();
						}
					}
					return(true);
				}
			}
		}
		else {
			switch (dc->_descId[0].id)
			{
			case PMX_BONE_TAG_INIT_CURVE_BUTTON:
			{
				this->InitInterpolator(node);
				break;
			}
			case PMX_BONE_TAG_REGISTER_CURVE_BUTTON:
			{
				BaseTime time = GetActiveDocument()->GetTime();
				this->RegisterKeyFrame(time.GetFrame(30.), node);
				doc->SetTime(BaseTime());
				doc->SetTime(time);
				break;
			}
			case PMX_BONE_TAG_UPDATE_CURVE_BUTTON:
			{
				this->UpdateAllInterpolator(node);
				break;
			}
			case PMX_BONE_TAG_DELETE_CURVE_BUTTON:
			{
				if (QuestionDialog(IDS_MES_DELETE_BONE_CURVE))
				{
					BaseTime time = GetActiveDocument()->GetTime();
					this->DeleteKeyFrame(time.GetFrame(30.), node);
					this->InitInterpolator(node);
					doc->SetTime(BaseTime());
					doc->SetTime(time);
				}
				break;
			}
			case PMX_BONE_TAG_DELETE_ALL_CURVE_BUTTON:
			{
				if (QuestionDialog(IDS_MES_DELETE_BONE_ALL_CURVE))
				{
					this->DeleteAllKeyFrame(node);
					this->InitInterpolator(node);
					doc->SetTime(BaseTime(1));
					doc->SetTime(BaseTime());
				}
				break;
			}
			case PMX_BONE_MORPH_ADD_BUTTON:
			{
				GeData Ge_data;
				node->GetParameter(DescID(PMX_BONE_MORPH_ADD_NAME), Ge_data, DESCFLAGS_GET::NONE);
				String morph_name = Ge_data.GetString();
				this->AddBondMorph(morph_name);
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case MSG_MENUPREPARE:
	{
		BaseDocument* doc = (BaseDocument*)data;
		if (doc != nullptr)
		{
			BaseObject* op = doc->GetActiveObject();
			if (op != nullptr)
			{
				String name = op->GetName();
				node->SetParameter(DescID(PMX_BONE_NAME_LOCAL), name, DESCFLAGS_SET::NONE);
				node->SetParameter(DescID(PMX_BONE_NAME_UNIVERSAL), name, DESCFLAGS_SET::NONE);
				this->RefreshColor(node, op);
			}
		}
		break;
	}
	case  ID_O_MMD_BONE_ROOT:
	{
		if (const auto* msg = static_cast<OMMDBoneRoot_MSG*>(data); msg != nullptr && bc != nullptr)
		{
			switch (msg->type)
			{
			case OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE:
			{
				switch (msg->display_type)
				{
				case BONE_DISPLAY_TYPE_MOVABLE:
				{
					if (bc->GetBool(PMX_BONE_TRANSLATABLE))
					{
						obj->SetEditorMode(MODE_ON);
						obj->SetRenderMode(MODE_ON);
					}
					else {
						obj->SetEditorMode(MODE_OFF);
						obj->SetRenderMode(MODE_OFF);
					}
					break;
				}
				case BONE_DISPLAY_TYPE_ROTATABLE:
				{
					if (bc->GetBool(PMX_BONE_ROTATABLE))
					{
						obj->SetEditorMode(MODE_ON);
						obj->SetRenderMode(MODE_ON);
					}
					else {
						obj->SetEditorMode(MODE_OFF);
						obj->SetRenderMode(MODE_OFF);
					}
					break;
				}
				case BONE_DISPLAY_TYPE_VISIBLE:
				{
					if (bc->GetBool(PMX_BONE_VISIBLE))
					{
						obj->SetEditorMode(MODE_ON);
						obj->SetRenderMode(MODE_ON);
					}
					else {
						obj->SetEditorMode(MODE_OFF);
						obj->SetRenderMode(MODE_OFF);
					}
					break;
				}
				case BONE_DISPLAY_TYPE_ENABLED:
				{
					if (bc->GetBool(PMX_BONE_ENABLED))
					{
						obj->SetEditorMode(MODE_ON);
						obj->SetRenderMode(MODE_ON);
					}
					else {
						obj->SetEditorMode(MODE_OFF);
						obj->SetRenderMode(MODE_OFF);
					}
					break;
				}
				case BONE_DISPLAY_TYPE_IK:
				{
					if (bc->GetBool(PMX_BONE_IS_IK))
					{
						obj->SetEditorMode(MODE_ON);
						obj->SetRenderMode(MODE_ON);
					}
					else {
						obj->SetEditorMode(MODE_OFF);
						obj->SetRenderMode(MODE_OFF);
					}
					break;
				}
				default:
					obj->SetEditorMode(MODE_UNDEF);
					obj->SetRenderMode(MODE_UNDEF);
					break;
				}
				break;
			}
			case OMMDBoneRoot_MSG_Type::BONEROOT_UPDATA:
			{
				this->m_BoneRoot_ptr = msg->object;
				if (obj != nullptr) {
					GeData		Ge_data;
					BaseObject* up_obj = obj->GetUp();
					BaseObject* pred_obj = obj->GetPred();
					Int32		pred_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
					if (up_obj != nullptr)
					{
						if (!up_obj->IsInstanceOf(ID_O_MMD_BONE_ROOT))
						{
							BaseTag* up_tag = up_obj->GetTag(ID_T_MMD_BONE);
							if (up_tag != nullptr)
							{
								up_tag->GetParameter(DescID(PMX_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
								bc->SetData(PMX_BONE_PARENT_BONE_INDEX, Ge_data);
							}
							if (pred_obj == nullptr)
							{
								if (up_tag != nullptr)
								{
									up_tag->GetParameter(DescID(PMX_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
									bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
								}
							}
							else {
								BaseObject* lase_obj = pred_obj;
								while (lase_obj->GetDownLast() != nullptr)
								{
									lase_obj = lase_obj->GetDownLast();
								}

								BaseTag* lase_tag = lase_obj->GetTag(ID_T_MMD_BONE);
								if (lase_tag != nullptr)
								{
									lase_tag->GetParameter(PMX_BONE_INDEX, Ge_data, DESCFLAGS_GET::NONE);
									bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
								}
							}
						}
						else {
							if (pred_obj == nullptr)
							{
								bc->SetString(PMX_BONE_INDEX, "0"_s);
							}
							else {
								BaseTag* pred_tag = pred_obj->GetTag(ID_T_MMD_BONE);
								if (pred_tag != nullptr)
								{
									pred_tag->GetParameter(PMX_BONE_INDEX, Ge_data, DESCFLAGS_GET::NONE);
									bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
								}
							}
						}
					}
					else {
						bc->SetString(PMX_BONE_INDEX, "0"_s);
					}
					Int32 now_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
					if (now_index != pred_index && this->m_BoneRoot_ptr != nullptr)
						this->m_BoneRoot_ptr->Message(ID_T_MMD_BONE, nullptr);
				}
				break;
			}
			case OMMDBoneRoot_MSG_Type::DEFAULT: 
			case OMMDBoneRoot_MSG_Type::BONE_MORPH_CHANGE: 
			default:
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return(true);
}
Bool TMMDBone::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return(false);
	};
	if (level >= 1)
	{
		AutoAlloc<BaseLink> bone_root_link;
		if (bone_root_link == nullptr)
			return false;
		if (!bone_root_link->Read(hf))
			return(false);
		this->m_BoneRoot_ptr = static_cast<BaseObject*>(bone_root_link->ForceGetLink());
	}
	if (!hf->ReadInt32(&this->bone_morph_name_index))
		return(false);
	if (!hf->ReadInt32(&this->prev_frame))
		return(false);
	if (!hf->ReadInt32(&this->prev_interpolator_type))
		return(false);
	if (!hf->ReadVector64(&this->prev_position))
		return(false);
	if (!hf->ReadVector64(&this->prev_rotation))
		return(false);
	Int32 count_temp = 0;
	Int32 temp_index = 0;
	Int	size = sizeof(mmd::VMDInterpolator);
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		void* data;
		temp_index = 0;
		if (!hf->ReadInt32(&temp_index))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_X_map.Insert(temp_index, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	count_temp = 0;
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		void* data;
		temp_index = 0;
		if (!hf->ReadInt32(&temp_index))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_Y_map.Insert(temp_index, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		void* data;
		temp_index = 0;
		if (!hf->ReadInt32(&temp_index))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_Z_map.Insert(temp_index, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	count_temp = 0;
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		void* data;
		temp_index = 0;
		if (!hf->ReadInt32(&temp_index))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_R_map.Insert(temp_index, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	count_temp = 0;
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		void* data;
		temp_index = 0;
		if (!hf->ReadInt32(&temp_index))
			return(false);
		if (!hf->ReadMemory(&data, &size))
			return(false);
		this->interpolator_A_map.Insert(temp_index, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	DescID TempID;
	count_temp = 0;
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		if (!TempID.Read(hf))
			return(false);
		temp_index = 0;
		if (!hf->ReadInt32(&temp_index))
			return(false);
		this->button_id_map.Insert(TempID, temp_index) iferr_return;
	}
	
	count_temp = 0;
	if (!hf->ReadInt32(&count_temp))
		return(false);
	for (Int32 i = 0; i < count_temp; i++)
	{
		bone_morph_data* TempData = NewObj(bone_morph_data)iferr_return;
		this->bone_morph_data_arr.AppendPtr(TempData) iferr_return;
		if (!TempData->Read(hf))
			return(false);	
	}
	return(SUPER::Read(node, hf, level));
}
Bool TMMDBone::Write(GeListNode* node, HyperFile* hf)
{
	// level >= 1
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	bone_root_link->SetLink(this->m_BoneRoot_ptr);
	// level >= 0
	if (!bone_root_link->Write(hf))
		return(false);
	if (!hf->WriteInt32(this->bone_morph_name_index))
		return(false);
	if (!hf->WriteInt32(this->prev_frame))
		return(false);
	if (!hf->WriteInt32(this->prev_interpolator_type))
		return(false);
	if (!hf->WriteVector64(this->prev_position))
		return(false);
	if (!hf->WriteVector64(this->prev_rotation))
		return(false);
	Int32 count_temp = static_cast<Int32>(this->interpolator_X_map.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (auto& i : this->interpolator_X_map)
	{
		if (!hf->WriteInt32(i.GetKey()))
			return(false);
		if (!hf->WriteMemory(&i.GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count_temp = static_cast<Int32>(this->interpolator_Y_map.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (auto& i : this->interpolator_Y_map)
	{
		if (!hf->WriteInt32(i.GetKey()))
			return(false);
		if (!hf->WriteMemory(&i.GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count_temp = static_cast<Int32>(this->interpolator_Z_map.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (auto& i : this->interpolator_Z_map)
	{
		if (!hf->WriteInt32(i.GetKey()))
			return(false);
		if (!hf->WriteMemory(&i.GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count_temp = static_cast<Int32>(this->interpolator_R_map.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (auto& i : this->interpolator_R_map)
	{
		if (!hf->WriteInt32(i.GetKey()))
			return(false);
		if (!hf->WriteMemory(&i.GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count_temp = static_cast<Int32>(this->interpolator_A_map.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (auto& i : this->interpolator_A_map)
	{
		if (!hf->WriteInt32(i.GetKey()))
			return(false);
		if (!hf->WriteMemory(&i.GetValue(), sizeof(mmd::VMDInterpolator)))
			return(false);
	}
	count_temp = static_cast<Int32>(this->button_id_map.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (auto& i : this->button_id_map)
	{
		if (!const_cast<DescID&>(i.GetKey()).Write(hf))
			return(false);
		if (!hf->WriteInt32(i.GetValue()))
			return(false);
	}
	count_temp = static_cast<Int32>(this->bone_morph_data_arr.GetCount());
	if (!hf->WriteInt32(count_temp))
		return(false);
	for (bone_morph_data& i : this->bone_morph_data_arr)
	{
		if (!i.Write(hf))
			return(false);
	}
	return(SUPER::Write(node, hf));
}
void TMMDBone::Free(GeListNode* node)
{
	this->interpolator_X_map.Reset();
	this->interpolator_Y_map.Reset();
	this->interpolator_Z_map.Reset();
	this->interpolator_R_map.Reset();
	this->interpolator_A_map.Reset();
	this->bone_morph_data_arr.Reset();
}
}