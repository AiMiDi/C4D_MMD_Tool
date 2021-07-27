#include "MMD_PMX_Control.h"

//*******************
// PMX Model Tag
//*******************

Bool mmd::OMMDModel::Init(GeListNode* node)
{
	if (node == nullptr)
		return false;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_O_MMD_MODEL));
	bc->SetFloat(PMX_VERSION, 2.0);
	bc->SetString(MODEL_NAME_LOCAL, "model"_s);
	bc->SetString(MODEL_NAME_UNIVERSAL, "model"_s);
	bc->SetString(COMMENTS_LOCAL, "description"_s);
	bc->SetString(COMMENTS_UNIVERSAL, "description"_s);
	return true;
}
EXECUTIONRESULT mmd::OMMDModel::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
	if (op == nullptr || doc == nullptr) {
		return EXECUTIONRESULT::OK;
	}
	BaseObject* MeshRoot_ = nullptr;
	BaseObject* BoneRoot_ = nullptr;
	BaseObject* RigidRoot_ = nullptr;
	BaseObject* JointRoot_ = nullptr;
		maxon::Queue<BaseObject*> nodes;
		iferr(nodes.Push(op->GetDown()))return EXECUTIONRESULT::OK;
		while (!nodes.IsEmpty())
		{
			BaseObject* node = *(nodes.Pop());
			if (node != nullptr) {
				if (node->IsInstanceOf(ID_O_MMD_MESH_ROOT))
					MeshRoot_ = node;
				else if (node->IsInstanceOf(ID_O_MMD_BONE_ROOT))
					BoneRoot_ = node;
				else if (node->IsInstanceOf(ID_O_MMD_RIGID_ROOT))
					RigidRoot_ = node;
				else if (node->IsInstanceOf(ID_O_MMD_JOINT_ROOT))
					JointRoot_ = node;
				iferr(nodes.Push(node->GetNext()))return EXECUTIONRESULT::OK;
			}
		}
		nodes.Reset();
	if (MeshRoot_ == nullptr) {
		this->MeshRoot = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
		this->MeshRoot->InsertUnder(op);
	}
	else {
		this->MeshRoot = MeshRoot_;
	}
	if (BoneRoot_ == nullptr) {
		this->BoneRoot = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
		this->BoneRoot->InsertUnder(op);
	}else{
		this->BoneRoot = BoneRoot_;
	}
	if (RigidRoot_ == nullptr) {
		this->RigidRoot = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
		this->RigidRoot->InsertUnder(op);
	}
	else {
		this->RigidRoot = RigidRoot_;
	}
	if (JointRoot_ == nullptr) {
		this->JointRoot = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
		this->JointRoot->InsertUnder(op);
	}
	else {
		this->JointRoot = JointRoot_;
	}
	return EXECUTIONRESULT::OK;
}
Bool mmd::OMMDModel::CreateRoot() {
	BaseObject* op = static_cast<BaseObject*>(Get());
	if (op != nullptr) {
		if (this->MeshRoot == nullptr) {
			this->MeshRoot = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
			this->MeshRoot->InsertUnder(op);
		}
		if (this->BoneRoot == nullptr) {
			this->BoneRoot = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
			this->BoneRoot->InsertUnder(op);
		}
		if (this->RigidRoot == nullptr) {
			this->RigidRoot = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
			this->RigidRoot->InsertUnder(op);
		}
		if (this->JointRoot == nullptr) {
			this->JointRoot = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
			this->JointRoot->InsertUnder(op);
		}
		return true;
	}
	return false;
}
Bool mmd::OMMDModel::AddToExecution(BaseObject* op, PriorityList* list) {
	if (list == nullptr || op == nullptr) {
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}
Bool mmd::OMMDModel::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	if (!description->LoadDescription("OMMDModel"_s))
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
Bool mmd::OMMDModel::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		switch (dc->_descId[0].id)
		{
		case MODEL_DEL_BONE_ANIM_BUTTON:
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr) {
				GePrint("error"_s);
				MessageDialog("error"_s);
				return true;
			}
			BaseObject* op = static_cast<BaseObject*>(node);
			if (op == nullptr) {
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return true;
			}
			CTrack* ModelEditorDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
			CTrack::Free(ModelEditorDisplayTrack);
			op->SetParameter(ID_BASEOBJECT_VISIBILITY_EDITOR, 2, DESCFLAGS_SET::NONE);
			CTrack* ModelRenderDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_RENDER);
			op->SetParameter(ID_BASEOBJECT_VISIBILITY_RENDER, 2, DESCFLAGS_SET::NONE);
			CTrack::Free(ModelRenderDisplayTrack);
			if (QuestionDialog(IDS_MES_DELETE_BONE_ANIM)) {
				maxon::Queue<BaseObject*> nodes;
				iferr(nodes.Push(op))return true;
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{
						if (node_->GetType() == Ojoint)
						{
							BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
							if (node_bone_tag != nullptr && node_bone_tag->IsInstanceOf(ID_T_MMD_BONE)) {
								mmd::TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<mmd::TMMDBone>();
								for (mmd::bone_morph_data& i : pmx_bone_tag_data->bone_morph_data_arr) {
									CTrack* morph_track = node_bone_tag->FindCTrack(i.strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(i.strength_id, 0, DESCFLAGS_SET::NONE);
								}
							}
							CTrack* BoneTrackPX = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPX);
							CTrack* BoneTrackPY = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPY);
							CTrack* BoneTrackPZ = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPZ);
							CTrack* BoneTrackRX = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRX);
							CTrack* BoneTrackRY = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRY);
							CTrack* BoneTrackRZ = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRZ);
							node_->SetRelPos(Vector(0));
							node_->SetRelRot(Vector(0));
							BaseTag* const node_ik_tag = node_->GetTag(1019561);//IK tag
							if (node_ik_tag != nullptr && node_ik_tag->IsInstanceOf(1019561)) {
								CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
								CTrack::Free(ik_enable_track);
								node_ik_tag->SetParameter(ID_CA_IK_TAG_ENABLE, true, DESCFLAGS_SET::NONE);
							}
						}
						iferr(nodes.Push(node_->GetDown()))return true;
						if (node_ != op) {
							node_ = node_->GetNext();
						}
						else {
							break;
						}
					}
				}
				nodes.Reset();
				doc->SetTime(BaseTime(1, 30));
				doc->SetTime(BaseTime(0, 30));
			}
			break;
		}
		case MODEL_DEL_MORPH_ANIM_BUTTON:
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr) {
				GePrint("error"_s);
				MessageDialog("error"_s);
				return true;
			}
			BaseObject* op = static_cast<BaseObject*>(node);
			if (op == nullptr) {
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return true;
			}
			if (QuestionDialog(IDS_MES_DELETE_MORPH_ANIM)) {
				maxon::Queue<BaseObject*> nodes;
				iferr(nodes.Push(op))return true;
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{	
						BaseTag* const node_morph_tag = node_->GetTag(Tposemorph);
						if (node_morph_tag != nullptr && node_morph_tag->IsInstanceOf(Tposemorph))
							{
								CAPoseMorphTag* const pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
								const Int32 MorphCount = pose_morph_tag->GetMorphCount();
								for (Int32 i = 0; i < MorphCount; i++)
								{
									CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(i));
									CTrack::Free(morph_track);
									pose_morph_tag->GetMorph(i)->SetStrength(0);
								}
						}					
						iferr(nodes.Push(node_->GetDown()))return true;
						if (node_ != op) {
							node_ = node_->GetNext();
						}
						else {
							break;
						}
					}
				}
				nodes.Reset();
				doc->SetTime(BaseTime(1, 30));
				doc->SetTime(BaseTime(0, 30));
			}
			break;
		}
		case MODEL_DEL_ALL_ANIM_BUTTON:
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr) {
				GePrint("error"_s);
				MessageDialog("error"_s);
				return true;
			}
			BaseObject* op = static_cast<BaseObject*>(node);
			if (op == nullptr) {
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return true;
			}
			CTrack* ModelEditorDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
			CTrack::Free(ModelEditorDisplayTrack);
			op->SetParameter(ID_BASEOBJECT_VISIBILITY_EDITOR, 2, DESCFLAGS_SET::NONE);
			CTrack* ModelRenderDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_RENDER);
			op->SetParameter(ID_BASEOBJECT_VISIBILITY_RENDER, 2, DESCFLAGS_SET::NONE);
			CTrack::Free(ModelRenderDisplayTrack);
			if (QuestionDialog(IDS_MES_DELETE_ALL_ANIM)) {
				maxon::Queue<BaseObject*> nodes;
				iferr(nodes.Push(op))return true;
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{
						if (node_->GetType() == Ojoint)
						{
							BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
							if (node_bone_tag != nullptr && node_bone_tag->IsInstanceOf(ID_T_MMD_BONE)) {
								mmd::TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<mmd::TMMDBone>();
								for (mmd::bone_morph_data& i : pmx_bone_tag_data->bone_morph_data_arr) {
									CTrack* morph_track = node_bone_tag->FindCTrack(i.strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(i.strength_id, 0, DESCFLAGS_SET::NONE);
								}
							}
							CTrack* BoneTrackPX = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPX);
							CTrack* BoneTrackPY = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPY);
							CTrack* BoneTrackPZ = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackPZ);
							CTrack* BoneTrackRX = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRX);
							CTrack* BoneTrackRY = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRY);
							CTrack* BoneTrackRZ = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
							CTrack::Free(BoneTrackRZ);
							node_->SetRelPos(Vector(0));
							node_->SetRelRot(Vector(0));
							BaseTag* const node_ik_tag = node_->GetTag(1019561);//IK tag
							if (node_ik_tag != nullptr && node_ik_tag->IsInstanceOf(1019561)) {
								CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
								CTrack::Free(ik_enable_track);
								node_ik_tag->SetParameter(ID_CA_IK_TAG_ENABLE, true, DESCFLAGS_SET::NONE);
							}
						}
						else {
							BaseTag* const node_morph_tag = node_->GetTag(Tposemorph);
							if (node_morph_tag != nullptr && node_morph_tag->IsInstanceOf(Tposemorph))
							{
								CAPoseMorphTag* const pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
								const Int32 MorphCount = pose_morph_tag->GetMorphCount();
								for (Int32 i = 0; i < MorphCount; i++)
								{
									CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(i));
									CTrack::Free(morph_track);
									pose_morph_tag->GetMorph(i)->SetStrength(0);
								}
							}
						}
						iferr(nodes.Push(node_->GetDown()))return true;
						if (node_ != op) {
							node_ = node_->GetNext();
						}
						else {
							break;
						}
					}
				}
				nodes.Reset();
				doc->SetTime(BaseTime(1, 30));
				doc->SetTime(BaseTime(0, 30));
			}
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
//*******************
// PMX Bone Tag
//*******************

Int32 mmd::TMMDBone::AddBondMorph(String morph_name) {
	if (morph_name.IsEmpty()) {
		morph_name = "morph_" + String::IntToString(bone_morph_name_index);
		bone_morph_name_index++;
	}
	BaseTag* pmx_bone_tag = (BaseTag*)Get();
	DynamicDescription* const ddesc = pmx_bone_tag->GetDynamicDescription();
	if (ddesc == nullptr)
		return -1;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, DescID(PMX_BONE_MORPH_GRP) });
	DescID grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, grp_id });
	DescID strength_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_BONE_TRANSLATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, grp_id });
	DescID translation_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_BONE_ROTATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, grp_id });
	DescID rotation_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 2);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, grp_id });
	DescID button_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_BONE_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, button_grp_id });
	DescID delete_button_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_BONE_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData{ CUSTOMDATATYPE_DESCID, button_grp_id });
	DescID rename_button_id = ddesc->Alloc(bc);
	auto& res = bone_morph_data_arr.Append(bone_morph_data{ grp_id, strength_id ,translation_id ,rotation_id,button_grp_id, delete_button_id, rename_button_id, morph_name });
	iferr(res)
		return -1;
	Int32 index = bone_morph_data_arr.GetIndex(res.GetValue());
	iferr(button_id_map.Insert(delete_button_id, index))
		return -1;
	iferr(button_id_map.Insert(rename_button_id, index))
		return -1;
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); //Refresh the AM to see the changes in real time  
	EventAdd();
	return index;
}
Bool mmd::TMMDBone::SplineDataCallBack(Int32 cid, const void* data)
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
Bool mmd::TMMDBone::GetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve) {
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
Bool mmd::TMMDBone::SetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve) {
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
Bool mmd::TMMDBone::UpdateAllCurve() {
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
Bool mmd::TMMDBone::UpdateCurve(Int32 frame_on) {
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
inline Bool mmd::TMMDBone::CurveInit() {
	if (Get() == nullptr)return false;
	BaseContainer* bc = ((BaseList2D*)Get())->GetDataInstance();
	GeData data = GeData(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
	SplineData* spline = (SplineData*)data.GetCustomDataType(CUSTOMDATATYPE_SPLINE);
	if (spline != nullptr)
	{
		spline->AdaptRange(0, 127, 127, 0, 127, 127);
		spline->InsertKnot(0.0, 0.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->InsertKnot(127.0, 127.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
		spline->SetUserCallback(mmd::TMMDBone::SplineDataCallBack, nullptr);
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
Bool mmd::TMMDBone::Init(GeListNode* node)
{
	if (node == nullptr)
		return false;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_T_MMD_BONE));
	bc->SetString(PMX_BONE_NAME_LOCAL, "bone"_s);
	bc->SetInt32(PMX_BONE_NAME_IS_LOCAL, 2);
	bc->SetString(PMX_BONE_NAME_UNIVERSAL, "bone"_s);
	bc->SetInt32(PMX_BONE_PARENT_BONE_INDEX, -1);
	bc->SetInt32(PMX_BONE_ROTATABLE, 1);
	bc->SetInt32(PMX_BONE_VISIBLE, 1);
	bc->SetInt32(PMX_BONE_ENABLED, 1);
	bc->SetInt32(PMX_BONE_TAIL_INDEX, -1);
	bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, -1);
	bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, 1.0);
	bc->SetVector(PMX_BONE_LOCAL_X, Vector(1, 0, 0));
	bc->SetVector(PMX_BONE_LOCAL_Z, Vector(0, 0, 1));
	GeData priority;
	if (node->GetParameter(DescLevel(EXPRESSION_PRIORITY), priority, DESCFLAGS_GET::NONE))
	{
		PriorityData* pd = (PriorityData*)priority.GetCustomDataType(CUSTOMGUI_PRIORITY_DATA);
		if (pd) {
			pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, 1);
		}

		bc->SetData(EXPRESSION_PRIORITY, priority);
	}
	if (!CurveInit())return false;
	return true;
}
Bool mmd::TMMDBone::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (id[0].id == PMX_BONE_TAG_FRAME_ON) {
		return false;
	}
	if (id[0].id == PMX_BONE_PARENT_BONE_LINK) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_PARENT_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
		Int32 parent_bone_index = Ge_data.GetInt32();
		if (parent_bone_index == -1) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_TAIL_INDEX) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == PMX_BONE_TAIL_IS_POSITION) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_TAIL_POSITION) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == PMX_BONE_TAIL_IS_INDEX) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_INHERIT_BONE_PARENT_INDEX) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_INHERIT_BONE_PARENT_LINK) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_FIXED_AXIS) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_IS_FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
		Bool fixed_axis = Ge_data.GetBool();
		if (fixed_axis == 0) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_LOCAL_X) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_LOCAL_IS_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0) {
			return false;
		}
	}
	if (id[0].id == PMX_BONE_LOCAL_Z) {
		GeData Ge_data;
		node->GetParameter(DescID(PMX_BONE_LOCAL_IS_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0) {
			return false;
		}
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}
EXECUTIONRESULT mmd::TMMDBone::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 	priority, EXECUTIONFLAGS flags) {
	if (tag == nullptr || op == nullptr) {
		return EXECUTIONRESULT::OK;
	}
	obj = op;
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
			tag->SetParameter(DescID(PMX_BONE_PARENT_BONE_LINK), parent_bone_link, DESCFLAGS_SET::NONE);
			BaseTag* up_tag = up_obj->GetTag(ID_T_MMD_BONE);
			if (up_tag != nullptr) {
				up_tag->GetParameter(DescID(PMX_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
				tag->SetParameter(DescID(PMX_BONE_PARENT_BONE_INDEX), Ge_data.GetString().ToInt32(nullptr), DESCFLAGS_SET::NONE);
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

	tag->GetParameter(DescID(PMX_BONE_NAME_IS), Ge_data, DESCFLAGS_GET::NONE);
	Int32 bone_name_is = Ge_data.GetInt32();
	if (bone_name_is) {
		tag->GetParameter(DescID(PMX_BONE_NAME_UNIVERSAL), Ge_data, DESCFLAGS_GET::NONE);
		op->SetName(Ge_data.GetString());
	}
	else {
		tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), Ge_data, DESCFLAGS_GET::NONE);
		op->SetName(Ge_data.GetString());
	}

	tag->GetParameter(DescID(PMX_BONE_ROTATABLE), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_rotatable = Ge_data.GetBool();
	if (Is_rotatable == 1) {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
			protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_ALLOW_EXPRESSIONS), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
	}
	else {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
			protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_ALLOW_EXPRESSIONS), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(PMX_BONE_TRANSLATABLE), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_translatable = Ge_data.GetBool();
	if (Is_translatable == 1) {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
			protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_ALLOW_EXPRESSIONS), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
	}
	else {
		BaseTag* protection_tag = op->GetTag(Tprotection);
		if (protection_tag == nullptr) {
			protection_tag = op->MakeTag(Tprotection);
			protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		if (protection_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return EXECUTIONRESULT::OK;
		}
		protection_tag->SetParameter(DescID(PROTECTION_ALLOW_EXPRESSIONS), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
		protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(PMX_BONE_IS_IK), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_IK = Ge_data.GetBool();
	if (Is_IK == 1) {
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(PMX_BONE_VISIBLE), Ge_data, DESCFLAGS_GET::NONE);
	Bool Is_visible = Ge_data.GetBool();
	if (Is_visible == 0) {
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.4, 0.4, 0.4), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.4, 0.4, 0.4), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
	}
	else {
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(PMX_BONE_IS_FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
	Bool Fixed_axis = Ge_data.GetBool();
	if (Fixed_axis == 1) {
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
	}

	tag->GetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
	Float Inherit_bone_parent_influence = Ge_data.GetFloat();
	tag->GetParameter(DescID(PMX_BONE_INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
	Bool Inherit_rotation = Ge_data.GetBool();
	tag->GetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
	Bool Inherit_translation = Ge_data.GetBool();
	if (Inherit_rotation == 1) {
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		tag->GetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_LINK), Ge_data, DESCFLAGS_GET::NONE);
		BaseLink* inherit_bone_parent_link = Ge_data.GetBaseLink();
		if (inherit_bone_parent_link != nullptr) {
			BaseObject* inherit_bone_parent = (BaseObject*)inherit_bone_parent_link->GetLink(doc);
			if (inherit_bone_parent != nullptr) {
				tag->GetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
				Float32 Inherit_bone_parent_influence_ = Ge_data.GetFloat();
				op->SetRelRot(inherit_bone_parent->GetRelRot() * Inherit_bone_parent_influence_);
			}
		}
	}
	if (Inherit_translation == 1) {
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		op->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
		tag->GetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_LINK), Ge_data, DESCFLAGS_GET::NONE);
		BaseLink* inherit_bone_parent_link = Ge_data.GetBaseLink();
		if (inherit_bone_parent_link != nullptr) {
			BaseObject* inherit_bone_parent = (BaseObject*)inherit_bone_parent_link->GetLink(doc);
			if (inherit_bone_parent != nullptr) {
				tag->GetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
				Float32 Inherit_bone_parent_influence_ = Ge_data.GetFloat();
				op->SetRelPos(inherit_bone_parent->GetRelPos() * Inherit_bone_parent_influence_);
			}
		}
	}

	tag->GetParameter(DescID(PMX_BONE_TAIL_INDEX), Ge_data, DESCFLAGS_GET::NONE);
	Int32 Tail_index = Ge_data.GetInt32();
	tag->GetParameter(DescID(PMX_BONE_INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
	Bool Indexed_tail_position = Ge_data.GetBool();
	if (Indexed_tail_position == 1) {
		if (Tail_index == -1) {
			op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
		}
		else {
			op->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
		}
	}

	op->GetParameter(DescID(ID_BASEOBJECT_FROZEN_POSITION), Ge_data, DESCFLAGS_GET::NONE);
	Vector op_position = Ge_data.GetVector();
	op_position = op_position - prev_position;
	prev_position = Vector(0);
	op->GetParameter(DescID(ID_BASEOBJECT_FROZEN_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
	Vector op_rotation = Ge_data.GetVector();
	op_rotation = op_rotation - prev_rotation;
	prev_rotation = Vector(0);
	for (bone_morph_data& id : bone_morph_data_arr) {
		Float strength = 0;
		if (tag->GetParameter(id.strength_id, Ge_data, DESCFLAGS_GET::NONE)) {
			strength = Ge_data.GetFloat();
		}
		if (tag->GetParameter(id.translation_id, Ge_data, DESCFLAGS_GET::NONE)) {
			prev_position += Ge_data.GetVector() * strength;
		}
		if (tag->GetParameter(id.rotation_id, Ge_data, DESCFLAGS_GET::NONE)) {
			prev_rotation += Ge_data.GetVector() * strength;
		}
	}
	op->SetParameter(DescID(ID_BASEOBJECT_FROZEN_POSITION), op_position + prev_position, DESCFLAGS_SET::NONE);
	op->SetParameter(DescID(ID_BASEOBJECT_FROZEN_ROTATION), op_rotation + prev_rotation, DESCFLAGS_SET::NONE);

	return EXECUTIONRESULT::OK;
}
Bool mmd::TMMDBone::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case PMX_BONE_TAG_SPLINE:
	{
		((SplineData*)t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(mmd::TMMDBone::SplineDataCallBack, nullptr);
		break;
	}

	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool mmd::TMMDBone::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32 id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		switch (id)
		{

		default:
			break;
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc == nullptr)
			return false;
		if (dc->_descId.GetDepth() == 2)
		{
			// check if it is a user data button
			if (dc->_descId[0].id == ID_USERDATA)
			{
				auto button_on_id_ptr = button_id_map.Find(dc->_descId);
				if (button_on_id_ptr != nullptr) {
					DynamicDescription* const ddesc = node->GetDynamicDescription();
					if (ddesc == nullptr)
						return true;
					Int32 button_on_id = button_on_id_ptr->GetValue();
					if (button_on_id == -1)
						return true;
					bone_morph_data& id = bone_morph_data_arr[button_on_id];
					if (dc->_descId == id.button_delete_id) {
						if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, id.name)) {
							ddesc->Remove(id.grp_id);
							ddesc->Remove(id.button_grp_id);
							iferr(bone_morph_data_arr.Erase(button_on_id))
								return true;
							for (auto& i : button_id_map.GetKeys()) {
								Int32* index = button_id_map.FindValue(i);
								if (*index > button_on_id) {
									(*index)--;
								}
							}
							SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); //Refresh the AM to see the changes in real time  
							EventAdd();
						}
						return true;
					}
					if (dc->_descId == id.button_rename_id) {
						RenameDialog dlg;
						dlg.Open(DLG_TYPE::MODAL, 99999, -1, -1, 0, 0);
						if (!dlg.Rename.IsEmpty()) {
							BaseContainer bc = *ddesc->Find(id.grp_id);
							bc.SetString(DESC_NAME, dlg.Rename);
							ddesc->Set(id.grp_id, bc, nullptr);
							bc = *ddesc->Find(id.strength_id);
							bc.SetString(DESC_NAME, dlg.Rename);
							ddesc->Set(id.strength_id, bc, nullptr);
							id.name = dlg.Rename;
						}
						return true;
					}
				}
			}
		}
		switch (dc->_descId[0].id)
		{
		case PMX_BONE_TAG_INIT_CURVE_BUTTON:
		{
			CurveInit();
			break;
		}
		case PMX_BONE_TAG_REGISTER_CURVE_BUTTON:
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
		case PMX_BONE_TAG_UPDATE_CURVE_BUTTON:
		{
			UpdateAllCurve();
			break;
		}
		case PMX_BONE_TAG_DELETE_CURVE_BUTTON:
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
		case PMX_BONE_MORPH_ADD_BUTTON:
		{
			GeData Ge_data;
			node->GetParameter(DescID(PMX_BONE_MORPH_ADD_NAME), Ge_data, DESCFLAGS_GET::NONE);
			String morph_name = Ge_data.GetString();
			AddBondMorph(morph_name);
			break;
		}
		default:
			break;
		}
		break;
	}
	case MSG_MENUPREPARE:
	{
		BaseDocument* doc = (BaseDocument*)data;
		if (doc != nullptr) {
			BaseObject* op = doc->GetActiveObject();
			if (op != nullptr) {
				String& name = op->GetName();
				node->SetParameter(DescID(PMX_BONE_NAME_LOCAL), name, DESCFLAGS_SET::NONE);
				node->SetParameter(DescID(PMX_BONE_NAME_UNIVERSAL), name, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case  ID_O_MMD_BONE_ROOT:
	{
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		OMMDBoneRoot_MSG* msg = static_cast<OMMDBoneRoot_MSG*>(data);
		if (msg != nullptr && bc != nullptr) {
			if (msg->type == 0) {
				switch (msg->DisplayType)
				{
				case BONE_DISPLAY_TYPE_MOVABLE:
				{
					if (bc->GetBool(PMX_BONE_TRANSLATABLE)) {
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
					if (bc->GetBool(PMX_BONE_ROTATABLE)) {
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
					if (bc->GetBool(PMX_BONE_VISIBLE)) {
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
					if (bc->GetBool(PMX_BONE_ENABLED)) {
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
					if (bc->GetBool(PMX_BONE_IS_IK)) {
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
			}
		}
		break;
	}
	default:
		break;
	}
	return true;
}
Bool mmd::TMMDBone::Read(GeListNode* node, HyperFile* hf, Int32 level) {
	if (!hf->ReadInt32(&this->bone_morph_name_index))
		return false;
	if (!hf->ReadInt32(&this->prev_frame))
		return false;
	if (!hf->ReadInt32(&this->prev_curve_type))
		return false;
	if (!hf->ReadVector64(&this->prev_position))
		return false;
	if (!hf->ReadVector64(&this->prev_rotation))
		return false;
	Int32 CountTemp = 0;
	Int size = sizeof(mmd::VMD_Curve);
	void* data;
	if (!hf->ReadInt32(&CountTemp))
		return false;
	for (Int32 i = 0; i < CountTemp; i++) {
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return false;
		if (!hf->ReadMemory(&data, &size))
			return false;
		iferr(this->XCurve.Insert(TempIndex, new mmd::VMD_Curve(*static_cast<mmd::VMD_Curve*>(data))))
			return false;
	}
	if (!hf->ReadInt32(&CountTemp))
		return false;
	for (Int32 i = 0; i < CountTemp; i++) {
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return false;
		if (!hf->ReadMemory(&data, &size))
			return false;
		iferr(this->YCurve.Insert(TempIndex, new mmd::VMD_Curve(*static_cast<mmd::VMD_Curve*>(data))))
			return false;
	}
	if (!hf->ReadInt32(&CountTemp))
		return false;
	for (Int32 i = 0; i < CountTemp; i++) {
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return false;
		if (!hf->ReadMemory(&data, &size))
			return false;
		iferr(this->ZCurve.Insert(TempIndex, new mmd::VMD_Curve(*static_cast<mmd::VMD_Curve*>(data))))
			return false;
	}
	if (!hf->ReadInt32(&CountTemp))
		return false;
	for (Int32 i = 0; i < CountTemp; i++) {
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return false;
		if (!hf->ReadMemory(&data, &size))
			return false;
		iferr(this->RCurve.Insert(TempIndex, new mmd::VMD_Curve(*static_cast<mmd::VMD_Curve*>(data))))
			return false;
	}
	if (!hf->ReadInt32(&CountTemp))
		return false;
	for (Int32 i = 0; i < CountTemp; i++) {
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return false;
		if (!hf->ReadMemory(&data, &size))
			return false;
		iferr(this->ACurve.Insert(TempIndex, new mmd::VMD_Curve(*static_cast<mmd::VMD_Curve*>(data))))
			return false;
	}
	if (!hf->ReadInt32(&CountTemp))
		return false;
	for (Int32 i = 0; i < CountTemp; i++) {
		DescID TempID;
		if (!TempID.Read(hf))
			return false;
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return false;
		iferr(this->button_id_map.Insert(TempID, TempIndex))
			return false;
	}
	hf->ReadInt32(&CountTemp);
	for (Int32 i = 0; i < CountTemp; i++) {
		bone_morph_data TempData;
		if (!TempData.grp_id.Read(hf))
			return false;
		if (!TempData.strength_id.Read(hf))
			return false;
		if (!TempData.translation_id.Read(hf))
			return false;
		if (!TempData.rotation_id.Read(hf))
			return false;
		if (!TempData.button_grp_id.Read(hf))
			return false;
		if (!TempData.button_delete_id.Read(hf))
			return false;
		if (!TempData.button_rename_id.Read(hf))
			return false;
		if (!hf->ReadString(&TempData.name))
			return false;
		iferr(this->bone_morph_data_arr.Append(TempData))
			return false;
	}
	return SUPER::Read(node, hf, level);
}
Bool mmd::TMMDBone::Write(GeListNode* node, HyperFile* hf) {
	if (!hf->WriteInt32(this->bone_morph_name_index))
		return false;
	if (!hf->WriteInt32(this->prev_frame))
		return false;
	if (!hf->WriteInt32(this->prev_curve_type))
		return false;
	if (!hf->WriteVector64(this->prev_position))
		return false;
	if (!hf->WriteVector64(this->prev_rotation))
		return false;
	Int32 CountTemp = this->XCurve.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (auto i : this->XCurve.GetKeys()) {
		if (!hf->WriteInt32(i))
			return false;
		if (!hf->WriteMemory(this->XCurve.Find(i)->GetValue(), sizeof(mmd::VMD_Curve)))
			return false;
	}
	CountTemp = this->YCurve.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (auto i : this->YCurve.GetKeys()) {
		if (!hf->WriteInt32(i))
			return false;
		if (!hf->WriteMemory(this->YCurve.Find(i)->GetValue(), sizeof(mmd::VMD_Curve)))
			return false;
	}
	CountTemp = this->ZCurve.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (auto i : this->ZCurve.GetKeys()) {
		if (!hf->WriteInt32(i))
			return false;
		if (!hf->WriteMemory(this->ZCurve.Find(i)->GetValue(), sizeof(mmd::VMD_Curve)))
			return false;
	}
	CountTemp = this->RCurve.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (auto i : this->RCurve.GetKeys()) {
		if (!hf->WriteInt32(i))
			return false;
		if (!hf->WriteMemory(this->RCurve.Find(i)->GetValue(), sizeof(mmd::VMD_Curve)))
			return false;
	}
	CountTemp = this->ACurve.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (auto i : this->ACurve.GetKeys()) {
		if (!hf->WriteInt32(i))
			return false;
		if (!hf->WriteMemory(this->ACurve.Find(i)->GetValue(), sizeof(mmd::VMD_Curve)))
			return false;
	}
	CountTemp = this->button_id_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (auto i : this->button_id_map.GetKeys()) {
		if (!i.Write(hf))
			return false;
		if (!hf->WriteInt32(this->button_id_map.Find(i)->GetValue()))
			return false;
	}
	CountTemp = this->bone_morph_data_arr.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return false;
	for (bone_morph_data& i : this->bone_morph_data_arr) {
		if (!i.grp_id.Write(hf))
			return false;
		if (!i.strength_id.Write(hf))
			return false;
		if (!i.translation_id.Write(hf))
			return false;
		if (!i.rotation_id.Write(hf))
			return false;
		if (!i.button_grp_id.Write(hf))
			return false;
		if (!i.button_delete_id.Write(hf))
			return false;
		if (!i.button_rename_id.Write(hf))
			return false;
		if (!hf->WriteString(i.name))
			return false;
	}
	return SUPER::Write(node, hf);
}
void mmd::TMMDBone::Free(GeListNode* node) {
	for (auto i : this->XCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : this->YCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : this->ZCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : this->RCurve.GetValues()) {
		if (i != nullptr)delete i;
	}
	for (auto i : this->ACurve.GetValues()) {
		if (i != nullptr)delete i;
	}
}

//*******************
// PMX Rigid Object
//*******************

const Vector PMX_Rigid_Color[16] = {
	Vector(255,212,127) / 255,
	Vector(212,255,127) / 255,
	Vector(127,255,127) / 255,
	Vector(127,212,255) / 255,
	Vector(127,212,255) / 255,
	Vector(127,127,255) / 255,
	Vector(212,127,255) / 255,
	Vector(255,84,0) / 255,
	Vector(255,255,0) / 255,
	Vector(0,255,85) / 255,
	Vector(0,255,255) / 255,
	Vector(0,85,255) / 255,
	Vector(84,0,255) / 255,
	Vector(255,0,255) / 255,
	Vector(255,0,84) / 255,
	Vector(127,127,0) / 255
};
const Vector PMX_Rigid_Wire_Color[3] = {
	Vector(200,255,150) / 255,
	Vector(255,200,150) / 255,
	Vector(255,255,150) / 255,
};
Bool mmd::OMMDRigid::Init(GeListNode* node) {
	if (node == nullptr)
		return false;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	bc->SetFloat(RIGID_SHAPE_SIZE_X, 17.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Y, 17.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Z, 17.);
	bc->SetFloat(RIGID_MASS, 1.);
	bc->SetFloat(RIGID_FRICTION_FORCE, 0.5);
	bc->SetFloat(RIGID_MOVE_ATTENUATION, 0.5);
	bc->SetFloat(RIGID_ROTATION_DAMPING, 0.5);
	bc->SetInt32(ID_BASELIST_ICON_COLORIZE_MODE, ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM);
	return true;
}
Bool mmd::OMMDRigid::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags) {
	if (!(node && description))
		return false;
	if (!description->LoadDescription(node->GetType()))
		return false;
	BaseContainer* settings = nullptr;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc != nullptr) {
		switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
		case SPHERICAL:
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_X, nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_Y, nullptr);
			if (settings != nullptr)
				settings->SetBool(DESC_HIDE, true);
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_Z, nullptr);
			if (settings != nullptr)
				settings->SetBool(DESC_HIDE, true);
			break;
		case BOX:
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_X, nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_L));
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_Y, nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_Z, nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_W));
			break;
		case CAPLETS:
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_X, nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_Y, nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			settings = description->GetParameterI(RIGID_SHAPE_SIZE_Z, nullptr);
			if (settings != nullptr)
				settings->SetBool(DESC_HIDE, true);
			break;
		default:
			break;
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}
Bool mmd::OMMDRigid::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) {
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	switch (id[0].id)
	{
	case RIGID_SHAPE_TYPE:
	{
		if (bc != nullptr) {
			switch (t_data.GetInt32()) {
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj = BaseObject::Alloc(Osphere);
					pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj = BaseObject::Alloc(Ocube);
					pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj = BaseObject::Alloc(Ocapsule);
					pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case RIGID_SHAPE_SIZE_X:
	{
		if (bc != nullptr) {
			switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case RIGID_SHAPE_SIZE_Y:
	{
		if (bc != nullptr) {
			switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case RIGID_SHAPE_SIZE_Z:
	{
		if (bc != nullptr) {
			switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (this->pdraw_obj != nullptr) {
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool  mmd::OMMDRigid::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) {
	switch (id[0].id)
	{
	case ID_BASEOBJECT_REL_POSITION:
		return false;
	case ID_BASEOBJECT_REL_ROTATION:
		return false;
	default:
		break;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}
Bool mmd::OMMDRigid::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_GETCUSTOMICON:
	{
		GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);
		if (cid == nullptr)
			break;
		CustomIconSettings settings;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr) {
			break;
		}
		BaseContainer& bcr = static_cast<BaseObject*>(node)->GetDataInstanceRef();
		FillCustomIconSettingsFromBaseList2D(settings, bcr, node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)]);
		CustomIconGetIdDelegate getIdCallback = [bc]() -> Int32
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
			case SPHERICAL:
				return Osphere;
			case BOX:
				return Ocube;
			case CAPLETS:
				return Ocapsule;
			default:
				break;
			}
			return Osphere;
		};
		GetCustomIcon(*cid, settings, false, &getIdCallback);
		break;
	}
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32 id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		switch (id)
		{
		case RIGID_SHAPE_TYPE:
		{
			if (bc != nullptr) {
				switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj = BaseObject::Alloc(Osphere);
						pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj = BaseObject::Alloc(Ocube);
						pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj = BaseObject::Alloc(Ocapsule);
						pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case RIGID_SHAPE_SIZE_X:
		{
			if (bc != nullptr) {
				switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case RIGID_SHAPE_SIZE_Y:
		{
			if (bc != nullptr) {
				switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (this->pdraw_obj != nullptr) {
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case RIGID_SHAPE_SIZE_Z:
		{
				if (bc != nullptr) {
					switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
					case SPHERICAL:
					{
						if (this->pdraw_obj != nullptr) {
							BaseObject::Free(draw_obj);
							ModelingCommandData cd;
							cd.doc = GetActiveDocument();
							pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
						}
						break;
					}
					case BOX:
					{
						if (this->pdraw_obj != nullptr) {
							BaseObject::Free(draw_obj);
							ModelingCommandData cd;
							cd.doc = GetActiveDocument();
							pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
						}
						break;
					}
					case CAPLETS:
					{
						if (this->pdraw_obj != nullptr) {
							BaseObject::Free(draw_obj);
							ModelingCommandData cd;
							cd.doc = GetActiveDocument();
							pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
							pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
						}
						break;
					}
					default:
						break;
					}
				}
				break;
			}
		default:
			break;
		}	
		break;
	}
	case  ID_O_MMD_RIGID_ROOT:
	{
		OMMDRigidRoot_MSG* msg = static_cast<OMMDRigidRoot_MSG*>(data);
		if (msg != nullptr) {
			if (msg->type == 0) {
				this->DisplayType = msg->DisplayType;
				if (draw_obj == nullptr) {
					if (this->DisplayType != RIGID_DISPLAY_TYPE_OFF) {
						BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
						if (bc != nullptr) {
							BaseObject::Free(draw_obj);
							BaseObject::Free(pdraw_obj);
							ModelingCommandData cd;
							switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
							case SPHERICAL:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Osphere);
								pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case BOX:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocube);
								pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case CAPLETS:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocapsule);
								pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							default:
								break;
							}
						}
					}
				}
				else if (this->DisplayType == RIGID_DISPLAY_TYPE_OFF) {
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
				}
			}
			else {
				this->Mode = msg->Mode;
			}
		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}
DRAWRESULT mmd::OMMDRigid::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) {
	if (drawpass == DRAWPASS::OBJECT) {
		if (op == nullptr || bd == nullptr || bh == nullptr) {
			return DRAWRESULT::FAILURE;
		}
			BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
			bd->SetMatrix_Matrix(nullptr, op->GetMg());
			if (bc != nullptr) {
				switch (this->DisplayType)
				{
				case RIGID_DISPLAY_TYPE_ON:
				{			
					if (draw_obj != nullptr) {
						if (op == GetActiveDocument()->GetActiveObject()) {
							ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS ,PMX_Rigid_Color[(bc->GetInt32(RIGID_GROUP_ID))],false };
							draw_obj->SetColorProperties(&objColor);
							bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
						}
						else {
							ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS ,PMX_Rigid_Color[(bc->GetInt32(RIGID_GROUP_ID))],true };
							draw_obj->SetColorProperties(&objColor);
							bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR | DRAWOBJECT::XRAY_ON, drawpass);
						}
					}
					else {
						if (bc != nullptr) {
							BaseObject::Free(draw_obj);
							BaseObject::Free(pdraw_obj);
							ModelingCommandData cd;
							switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
							case SPHERICAL:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Osphere);
								pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case BOX:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocube);
								pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case CAPLETS:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocapsule);
								pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							default:
								break;
							}
						}
					}
					break;
				}
				case RIGID_DISPLAY_TYPE_WIRE:
				{
					if (draw_obj != nullptr) {
						if (op == GetActiveDocument()->GetActiveObject()) {
							ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS ,Vector(1,0.21,0.21),false };
							draw_obj->SetColorProperties(&objColor);
							bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR , drawpass);
						}
						else {
							ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS ,PMX_Rigid_Wire_Color[(bc->GetInt32(RIGID_PHYSICS_MODE))],false };
							draw_obj->SetColorProperties(&objColor);
							bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR , drawpass);
						}
					}
					else {
						if (bc != nullptr) {
							BaseObject::Free(draw_obj);
							BaseObject::Free(pdraw_obj);
							ModelingCommandData cd;
							switch (bc->GetInt32(RIGID_SHAPE_TYPE)) {
							case SPHERICAL:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Osphere);
								pdraw_obj->SetParameter(PRIM_SPHERE_RAD, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case BOX:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocube);
								pdraw_obj->SetParameter(PRIM_CUBE_LEN, Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case CAPLETS:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocapsule);
								pdraw_obj->SetParameter(PRIM_CAPSULE_RADIUS, bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								pdraw_obj->SetParameter(PRIM_CAPSULE_HEIGHT, bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							default:
								break;
							}
						}
					}
					break;
				}
				default:
					break;
			}	
		}
	}
	return SUPER::Draw(op, drawpass, bd, bh);
}
EXECUTIONRESULT mmd::OMMDRigid::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
	if (op == nullptr || doc == nullptr) {
		return EXECUTIONRESULT::OK;
	}
	BaseObject* PredObject = op->GetPred();
	BaseObject* UpObject = op->GetUp();
	if (UpObject == nullptr && this->RigidRoot != nullptr) {
		op->Remove();
		op->InsertUnderLast(this->RigidRoot);
	}
	if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_RIGID_ROOT)) {
		if (PredObject == nullptr) {
			op->SetParameter(RIGID_INDEX, "0"_s, DESCFLAGS_SET::NONE);
		}
		else {
			GeData data;
			PredObject->GetParameter(RIGID_INDEX, data, DESCFLAGS_GET::NONE);
			String RigidIndex = data.GetString();
			op->SetParameter(RIGID_INDEX, String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}
		if (this->RigidRoot == nullptr) {
			this->RigidRoot = UpObject;
		}
	}
	return EXECUTIONRESULT::OK;
}
Bool  mmd::OMMDRigid::AddToExecution(BaseObject* op, PriorityList* list) {
	if (list == nullptr || op == nullptr) {
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}
Bool mmd::OMMDRigid::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) {
	OMMDRigid* const destObject = static_cast<OMMDRigid*>(dest);
	if (destObject == nullptr)
		return false;
	destObject->RigidRoot = this->RigidRoot;
	destObject->DisplayType == this->DisplayType;
	return true;
}
void  mmd::OMMDRigid::Free(GeListNode* node) {
	BaseObject::Free(pdraw_obj);
	BaseObject::Free(draw_obj);
}

//*******************
// PMX Joint Object
//*******************

const Vector PMX_Joint_Color[6] = {
	Vector(255,255,70) / 255,
	Vector(255,114,131) / 255,
	Vector(233,211,255) / 255,
	Vector(174,255,112) / 255,
	Vector(109,162,255) / 255,
	Vector(255,155,230) / 255
};
Bool mmd::OMMDJoint::Init(GeListNode* node) {
	if (node == nullptr)
		return false;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	bc->SetString(JOINT_NAME_LOCAL, "Joint"_s);
	bc->SetString(JOINT_NAME_UNIVERSAL, "Joint"_s);
	bc->SetInt32(JOINT_LINK_RIGID_A_INDEX, -1);
	bc->SetInt32(JOINT_LINK_RIGID_B_INDEX, -1);
	bc->SetInt32(JOINT_ATTITUDE_USE_BONE_INDEX, -1);
	return true;
}
Bool mmd::OMMDJoint::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags) {
	if (!(node && description))
		return false;
	if (!description->LoadDescription(node->GetType()))
		return false;
	BaseContainer* settings = nullptr;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}
Bool mmd::OMMDJoint::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) {
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool mmd::OMMDJoint::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_GETCUSTOMICON:
	{
		GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);
		if (cid == nullptr)
			break;
		CustomIconSettings settings;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr) {
			break;
		}
		BaseContainer& bcr = static_cast<BaseObject*>(node)->GetDataInstanceRef();
		FillCustomIconSettingsFromBaseList2D(settings, bcr, node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(PMX_Joint_Color[bc->GetInt32(JOINT_TYPE)]);
		CustomIconGetIdDelegate getIdCallback = [bc]() -> Int32
		{
				return Ocube;
		};
		GetCustomIcon(*cid, settings, false, &getIdCallback);
		break;
	}
	case  ID_O_MMD_JOINT_ROOT:
	{
		OMMDJointRoot_MSG* msg = static_cast<OMMDJointRoot_MSG*>(data);
		if (msg != nullptr) {
			if (msg->type == 0) {
				this->DisplayType = msg->DisplayType;
			}
			else {
				this->Mode = msg->Mode;
			}
		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}
DRAWRESULT mmd::OMMDJoint::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) {
	if (drawpass == DRAWPASS::OBJECT) {
		if (op == nullptr || bd == nullptr || bh == nullptr) {
			return DRAWRESULT::FAILURE;
		}
		BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
		if (bc != nullptr) {
			bd->SetMatrix_Matrix(nullptr, op->GetMg());
			switch (this->DisplayType)
			{
			case JOINT_DISPLAY_TYPE_ON:
			{
				if (op == GetActiveDocument()->GetActiveObject()) {
					bd->DrawBox(Matrix(), 2, Vector(0.698, 0, 1), false);
				}
				else {
					bd->DrawBox(Matrix(), 2, PMX_Joint_Color[(bc->GetInt32(JOINT_TYPE))], false);
				}
				bd->DrawBox(Matrix(), 2, Vector(), true);
				break;
			}
			case JOINT_DISPLAY_TYPE_WIRE:
			{
				if (op == GetActiveDocument()->GetActiveObject()) {
					bd->DrawBox(Matrix(), 2, Vector(0.698, 0, 1), true);
				}
				else {
					bd->DrawBox(Matrix(), 2, PMX_Joint_Color[(bc->GetInt32(JOINT_TYPE))], true);
				}
				break;
			}
			default:
				break;
			}
		}
	}
	return SUPER::Draw(op, drawpass, bd, bh);
}
EXECUTIONRESULT mmd::OMMDJoint::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
	if (op == nullptr || doc == nullptr) {
		return EXECUTIONRESULT::OK;
	}
	BaseObject* PredObject = op->GetPred();
	BaseObject* UpObject = op->GetUp();
	if (UpObject == nullptr && this->JointRoot != nullptr) {
		op->Remove();
		op->InsertUnderLast(this->JointRoot);
	}
	if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_JOINT_ROOT)) {
		if (PredObject == nullptr) {
			op->SetParameter(JOINT_INDEX, "0"_s, DESCFLAGS_SET::NONE);
		}
		else {
			GeData data;
			PredObject->GetParameter(JOINT_INDEX, data, DESCFLAGS_GET::NONE);
			String RigidIndex = data.GetString();
			op->SetParameter(JOINT_INDEX, String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}
		if (this->JointRoot == nullptr) {
			this->JointRoot = UpObject;
		}
	}
	return EXECUTIONRESULT::OK;
}
Bool  mmd::OMMDJoint::AddToExecution(BaseObject* op, PriorityList* list) {
	if (list == nullptr || op == nullptr) {
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}
Bool mmd::OMMDJoint::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) {
	OMMDJoint* const destObject = static_cast<OMMDJoint*>(dest);
	if (destObject == nullptr)
		return false;
	destObject->JointRoot = this->JointRoot;
	destObject->DisplayType== this->DisplayType;
	return true;
}

//*******************
// PMX Mesh Root Object
//*******************

Bool mmd::OMMDMeshRoot::Init(GeListNode* node) {
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr) {
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr) {
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		BaseTag* DisplayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		if (DisplayTag != nullptr) {	
			DisplayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
			DisplayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			DisplayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return true;
}
Bool mmd::OMMDMeshRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) {
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == MESH_DISPLAY_TYPE) {
		switch (t_data.GetInt32())
		{
		case MESH_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			break;
		}
		case MESH_DISPLAY_TYPE_ON:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_ON_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_QUICK, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_QUICK_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_HIDDENLINE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_HIDDENLINE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

//*******************
// PMX Bone Root Object
//*******************

Bool mmd::OMMDBoneRoot::Init(GeListNode* node) {
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr) {
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr) {
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return true;
}
Bool mmd::OMMDBoneRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) {
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == BONE_DISPLAY_TYPE) {
		switch (t_data.GetInt32())
		{
		case BONE_DISPLAY_TYPE_ON:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_ON));
			break;
		}
		case BONE_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_OFF));
			break;
		}
		case BONE_DISPLAY_TYPE_MOVABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_MOVABLE));
			break;
		}
		case BONE_DISPLAY_TYPE_VISIBLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_VISIBLE));
			break;
		}
		case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_ROTATABLE));
			break;
		}
		case BONE_DISPLAY_TYPE_ENABLED:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_ENABLED));
			break;
		}
		case BONE_DISPLAY_TYPE_IK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, new OMMDBoneRoot_MSG(0, BONE_DISPLAY_TYPE_IK));
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool mmd::OMMDBoneRoot::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc->_descId[0].id == ADD_BONE_BUTTON) {
			BaseObject* newBone = BaseObject::Alloc(Ojoint);
			if (newBone != nullptr) {
				newBone->MakeTag(ID_T_MMD_BONE);
				newBone->InsertUnder(node);
			}
		}
		break;
	}
	default:
		break;
	}
	return true;
}

//*******************
// PMX Rigid Root Object
//*******************

Bool mmd::OMMDRigidRoot::Init(GeListNode* node) {
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr) {
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr) {
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		BaseTag* DisplayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		if (DisplayTag != nullptr) {
			DisplayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
			DisplayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			DisplayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return true;
}
Bool mmd::OMMDRigidRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) {
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == RIGID_DISPLAY_TYPE) {
		switch (t_data.GetInt32())
		{
		case RIGID_DISPLAY_TYPE_OFF:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, new OMMDRigidRoot_MSG(0,RIGID_DISPLAY_TYPE_OFF));
			break;
		}
		case RIGID_DISPLAY_TYPE_ON:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, new OMMDRigidRoot_MSG(0,RIGID_DISPLAY_TYPE_ON));
			if(op->GetTag(Tdisplay)!=nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, new OMMDRigidRoot_MSG(0,RIGID_DISPLAY_TYPE_WIRE));
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
Bool mmd::OMMDRigidRoot::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc->_descId[0].id == ADD_RIGID_BUTTON) {
			BaseObject* newRigid = BaseObject::Alloc(ID_O_MMD_RIGID);
			if (newRigid != nullptr) {
				newRigid->InsertUnder(node);
			}
		}
		break;
	}
	default:
		break;
	}
	return true;
}

//*******************
// PMX Joint Root Object
//*******************

Bool mmd::OMMDJointRoot::Init(GeListNode* node) {
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr) {
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr) {
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return true;
}
Bool mmd::OMMDJointRoot::Message(GeListNode* node, Int32 type, void* data) {
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc->_descId[0].id == ADD_JOINT_BUTTON) {
			BaseObject* newJoint = BaseObject::Alloc(ID_O_MMD_JOINT);
			if (newJoint != nullptr) {
				newJoint->InsertUnder(node);
			}
		}
		break;
	}
	default:
		break;
	}
	return true;
}
Bool mmd::OMMDJointRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) {
	if (id[0].id == JOINT_DISPLAY_TYPE) {
		switch (t_data.GetInt32())
		{
		case JOINT_DISPLAY_TYPE_OFF:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, new OMMDJointRoot_MSG(0, JOINT_DISPLAY_TYPE_OFF));
			break;
		}
		case JOINT_DISPLAY_TYPE_ON:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, new OMMDJointRoot_MSG(0, JOINT_DISPLAY_TYPE_ON));
			break;
		}
		case JOINT_DISPLAY_TYPE_WIRE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, new OMMDJointRoot_MSG(0, JOINT_DISPLAY_TYPE_WIRE));
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}
