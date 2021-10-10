#include "MMD_PMX_Control.h"

/*
 * *******************
 * PMX Model Object
 * *******************
 */

Bool mmd::OMMDModel::Init(GeListNode* node)
{
	if (node == nullptr)
		return(false);
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return(false);
	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_O_MMD_MODEL));
	bc->SetFloat(PMX_VERSION, 2.0);
	bc->SetString(MODEL_NAME_LOCAL, "model"_s);
	bc->SetString(MODEL_NAME_UNIVERSAL, "model"_s);
	bc->SetString(COMMENTS_LOCAL, "description"_s);
	bc->SetString(COMMENTS_UNIVERSAL, "description"_s);
	return(true);
}
Bool mmd::OMMDModel::Read(GeListNode* node, HyperFile* hf, Int32 level) {
	AutoAlloc<BaseLink> mesh_root_link;
	AutoAlloc<BaseLink> rigid_root_link;
	AutoAlloc<BaseLink> joint_root_link;
	AutoAlloc<BaseLink> bone_root_link;
	if (!mesh_root_link->Read(hf))
		return(false);
	if (!rigid_root_link->Read(hf))
		return(false);
	if (!joint_root_link->Read(hf))
		return(false);
	if (!bone_root_link->Read(hf))
		return(false);
	this->MeshRoot = static_cast<BaseObject*>(mesh_root_link->GetLink(GetActiveDocument()));
	this->RigidRoot = static_cast<BaseObject*>(rigid_root_link->GetLink(GetActiveDocument()));
	this->JointRoot = static_cast<BaseObject*>(joint_root_link->GetLink(GetActiveDocument()));
	this->BoneRoot = static_cast<BaseObject*>(bone_root_link->GetLink(GetActiveDocument()));
	return true;
}
Bool mmd::OMMDModel::Write(GeListNode* node, HyperFile* hf) {
	AutoAlloc<BaseLink> mesh_root_link;
	AutoAlloc<BaseLink> rigid_root_link;
	AutoAlloc<BaseLink> joint_root_link;
	AutoAlloc<BaseLink> bone_root_link;
	mesh_root_link->SetLink(this->MeshRoot);
	rigid_root_link->SetLink(this->RigidRoot);
	joint_root_link->SetLink(this->JointRoot);
	bone_root_link->SetLink(this->BoneRoot);
	if (!mesh_root_link->Write(hf))
		return(false);
	if (!rigid_root_link->Write(hf))
		return(false);
	if (!joint_root_link->Write(hf))
		return(false);
	if (!bone_root_link->Write(hf))
		return(false);
	return true;
}
Bool mmd::OMMDModel::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDModel* const destObject = static_cast<OMMDModel*>(dest);
	destObject->BoneRoot = this->BoneRoot;
	destObject->JointRoot = this->JointRoot;
	destObject->RigidRoot = this->RigidRoot;
	destObject->MeshRoot = this->MeshRoot;
	return(true);
}
EXECUTIONRESULT mmd::OMMDModel::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	BaseObject* MeshRoot_ = nullptr;
	BaseObject* BoneRoot_ = nullptr;
	BaseObject* RigidRoot_ = nullptr;
	BaseObject* JointRoot_ = nullptr;
	maxon::Queue<BaseObject*>	nodes;
	iferr(nodes.Push(op->GetDown())) return(EXECUTIONRESULT::OK);
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *(nodes.Pop());
		if (node != nullptr)
		{
			if (node->IsInstanceOf(ID_O_MMD_JOINT_ROOT))
				JointRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_RIGID_ROOT))
				RigidRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_BONE_ROOT))
				BoneRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_MESH_ROOT))
				MeshRoot_ = node;
			iferr(nodes.Push(node->GetNext())) return(EXECUTIONRESULT::OK);
		}
	}
	nodes.Reset();
	if (JointRoot_ == nullptr)
	{
		BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
		tmp->InsertUnder(op);
		this->JointRoot = tmp;
	}
	else {
		this->JointRoot = JointRoot_;
	}
	if (RigidRoot_ == nullptr)
	{
		BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
		tmp->InsertUnder(op);
		this->RigidRoot = tmp;
	}
	else {
		this->RigidRoot = RigidRoot_;
	}
	if (BoneRoot_ == nullptr)
	{
		BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
		tmp->InsertUnder(op);
		this->BoneRoot = tmp;
	}
	else {
		this->BoneRoot = BoneRoot_;
	}
	if (MeshRoot_ == nullptr)
	{
		BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
		tmp->InsertUnder(op);
		this->MeshRoot = tmp;
	}
	else {
		this->MeshRoot = MeshRoot_;
	}
	this->BoneRoot->Message(ID_O_MMD_MODEL, NewObj(mmd::OMMDModel_MSG, OMMDModel_Root_type::RigidRoot, this->RigidRoot).GetValue());
	this->BoneRoot->Message(ID_O_MMD_MODEL, NewObj(mmd::OMMDModel_MSG, OMMDModel_Root_type::JointRoot, this->JointRoot).GetValue());
	this->RigidRoot->Message(ID_O_MMD_MODEL, NewObj(mmd::OMMDModel_MSG, OMMDModel_Root_type::BoneRoot, this->BoneRoot).GetValue());
	this->RigidRoot->Message(ID_O_MMD_MODEL, NewObj(mmd::OMMDModel_MSG, OMMDModel_Root_type::JointRoot, this->JointRoot).GetValue());
	this->JointRoot->Message(ID_O_MMD_MODEL, NewObj(mmd::OMMDModel_MSG, OMMDModel_Root_type::BoneRoot, this->BoneRoot).GetValue());
	this->JointRoot->Message(ID_O_MMD_MODEL, NewObj(mmd::OMMDModel_MSG, OMMDModel_Root_type::RigidRoot, this->RigidRoot).GetValue());
	return(EXECUTIONRESULT::OK);
}
Bool mmd::OMMDModel::CreateRoot()
{
    BaseObject* op = static_cast<BaseObject*>(Get());
	const BaseDocument* doc = GetActiveDocument();
	if (op != nullptr && doc != nullptr)
	{
		if (this->JointRoot == nullptr)
		{
			BaseObject* joint_root_object = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
			joint_root_object->InsertUnder(op);
			this->JointRoot = joint_root_object;
		}
		if (this->RigidRoot == nullptr)
		{
			BaseObject* rigid_root_object = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
			rigid_root_object->InsertUnder(op);
			this->RigidRoot = rigid_root_object;
		}
		if (this->BoneRoot == nullptr)
		{
			BaseObject* bone_root_object = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
			bone_root_object->InsertUnder(op);
			this->BoneRoot = bone_root_object;
		}
		if (this->MeshRoot == nullptr)
		{
			BaseObject* mesh_root_object = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
			mesh_root_object->InsertUnder(op);
			this->MeshRoot = mesh_root_object;
		}
		return(true);
	}
	return(false);
}
Bool mmd::OMMDModel::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return(true);
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return(true);
}
Bool mmd::OMMDModel::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	if (!description->LoadDescription("OMMDModel"_s))
		return(false);
	const DescID* singleid = description->GetSingleDescID();
	if (singleid == nullptr)
	{
		return(SUPER::GetDDescription(node, description, flags));
	}
	MAXON_SCOPE
	{
		DescID cid = DescID(MODEL_INFO_GRP);
		if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
		{
			BaseContainer* settings = description->GetParameterI(cid, nullptr);
			if (settings)
				settings->SetBool(DESC_GROUPSCALEV, true);
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;

	return(SUPER::GetDDescription(node, description, flags));
}
Bool mmd::OMMDModel::Message(GeListNode* node, Int32 type, void* data)
{
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
			if (doc == nullptr)
			{
				GePrint("error"_s);
				MessageDialog("error"_s);
				return(true);
			}
			BaseObject* op = static_cast<BaseObject*>(node);
			if (op == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return(true);
			}
			CTrack* ModelEditorDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
			CTrack::Free(ModelEditorDisplayTrack);
			op->SetParameter(ID_BASEOBJECT_VISIBILITY_EDITOR, 2, DESCFLAGS_SET::NONE);
			CTrack* ModelRenderDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_RENDER);
			op->SetParameter(ID_BASEOBJECT_VISIBILITY_RENDER, 2, DESCFLAGS_SET::NONE);
			CTrack::Free(ModelRenderDisplayTrack);
			if (QuestionDialog(IDS_MES_DELETE_BONE_ANIM))
			{
				maxon::Queue<BaseObject*> nodes;
				iferr(nodes.Push(op)) return(true);
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{
						if (node_->GetType() == Ojoint)
						{
							BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
							if (node_bone_tag != nullptr)
							{
								mmd::TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<mmd::TMMDBone>();
								const Int32	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
								for (Int32 index = 0; index < BoneMorphCount; index++)
								{
									bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
									CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph.strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(bone_morph.strength_id, 0, DESCFLAGS_SET::NONE);
								}
								pmx_bone_tag_data->DeleteAllKeyFrame();
							}
							else {
								CTrack* BoneTrack_position_x = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_position_x);
								CTrack* BoneTrack_position_y = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_position_y);
								CTrack* BoneTrack_position_z = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_position_z);
								CTrack* BoneTrack_rotation_x = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_rotation_x);
								CTrack* BoneTrack_rotation_y = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_rotation_y);
								CTrack* BoneTrack_rotation_z = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_rotation_z);
								node_->SetRelPos(Vector(0));
								node_->SetRelRot(Vector(0));
							}
							BaseTag* const node_ik_tag = node_->GetTag(1019561); /* IK tag */
							if (node_ik_tag != nullptr)
							{
								CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
								CTrack::Free(ik_enable_track);
								node_ik_tag->SetParameter(ID_CA_IK_TAG_ENABLE, true, DESCFLAGS_SET::NONE);
							}
						}
						iferr(nodes.Push(node_->GetDown())) return(true);
						if (node_ != op)
						{
							node_ = node_->GetNext();
						}
						else {
							break;
						}
					}
				}
				nodes.Reset();
				EventAdd();
				doc->SetTime(BaseTime(1, 30));
				doc->SetTime(BaseTime(0, 30));
			}
			break;
		}
		case MODEL_DEL_MORPH_ANIM_BUTTON:
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr)
			{
				GePrint("error"_s);
				MessageDialog("error"_s);
				return(true);
			}
			BaseObject* op = static_cast<BaseObject*>(node);
			if (op == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return(true);
			}
			if (QuestionDialog(IDS_MES_DELETE_MORPH_ANIM))
			{
				maxon::Queue<BaseObject*> nodes;
				iferr(nodes.Push(op)) return(true);
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{
						if (node_->GetType() == Ojoint)
						{
							BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
							if (node_bone_tag != nullptr)
							{
								mmd::TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<mmd::TMMDBone>();
								const Int32	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
								for (Int32 index = 0; index < BoneMorphCount; index++)
								{
									bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
									CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph.strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(bone_morph.strength_id, 0, DESCFLAGS_SET::NONE);
								}	
							}
						}
						BaseTag* const node_morph_tag = node_->GetTag(Tposemorph);
						if (node_morph_tag != nullptr)
						{
							CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
							const Int32		MorphCount = pose_morph_tag->GetMorphCount();
							for (Int32 index = 0; index < MorphCount; index++)
							{
								CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(index));
								CTrack::Free(morph_track);
								pose_morph_tag->GetMorph(index)->SetStrength(0);
							}
						}
						iferr(nodes.Push(node_->GetDown())) return(true);
						if (node_ != op)
						{
							node_ = node_->GetNext();
						}
						else {
							break;
						}
					}
				}
				nodes.Reset();
				EventAdd();
				doc->SetTime(BaseTime(1, 30));
				doc->SetTime(BaseTime(0, 30));
			}
			break;
		}
		case MODEL_DEL_ALL_ANIM_BUTTON:
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr)
			{
				GePrint("error"_s);
				MessageDialog("error"_s);
				return(true);
			}
			BaseObject* op = static_cast<BaseObject*>(node);
			if (op == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return(true);
			}		
			if (QuestionDialog(IDS_MES_DELETE_ALL_ANIM))
			{
				CTrack* ModelEditorDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_EDITOR);
				CTrack::Free(ModelEditorDisplayTrack);
				op->SetParameter(ID_BASEOBJECT_VISIBILITY_EDITOR, 2, DESCFLAGS_SET::NONE);
				CTrack* ModelRenderDisplayTrack = op->FindCTrack(ID_BASEOBJECT_VISIBILITY_RENDER);
				op->SetParameter(ID_BASEOBJECT_VISIBILITY_RENDER, 2, DESCFLAGS_SET::NONE);
				CTrack::Free(ModelRenderDisplayTrack);
				maxon::Queue<BaseObject*> nodes;
				iferr(nodes.Push(op)) return(true);
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{
						if (node_->GetType() == Ojoint)
						{
							BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
							if (node_bone_tag != nullptr)
							{
								mmd::TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<mmd::TMMDBone>();
								const Int32	BoneMorphCount = pmx_bone_tag_data->GetMorphCount();
								for (Int32 index = 0; index < BoneMorphCount; index++)
								{
									bone_morph_data& bone_morph = pmx_bone_tag_data->GetMorph(index);
									CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph.strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(bone_morph.strength_id, 0, DESCFLAGS_SET::NONE);
								}
								pmx_bone_tag_data->DeleteAllKeyFrame();
							}
							else {
								CTrack* BoneTrack_position_x = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_position_x);
								CTrack* BoneTrack_position_y = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_position_y);
								CTrack* BoneTrack_position_z = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_position_z);
								CTrack* BoneTrack_rotation_x = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_rotation_x);
								CTrack* BoneTrack_rotation_y = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_rotation_y);
								CTrack* BoneTrack_rotation_z = node_->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
								CTrack::Free(BoneTrack_rotation_z);
								node_->SetRelPos(Vector(0));
								node_->SetRelRot(Vector(0));
							}
							BaseTag* const node_ik_tag = node_->GetTag(1019561); /* IK tag */
							if (node_ik_tag != nullptr)
							{
								CTrack* ik_enable_track = node_ik_tag->FindCTrack(ID_CA_IK_TAG_ENABLE);
								CTrack::Free(ik_enable_track);
								node_ik_tag->SetParameter(ID_CA_IK_TAG_ENABLE, true, DESCFLAGS_SET::NONE);
							}
						}
						else {
							BaseTag* const node_morph_tag = node_->GetTag(Tposemorph);
							if (node_morph_tag != nullptr)
							{
								CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
								const Int32		MorphCount = pose_morph_tag->GetMorphCount();
								for (Int32 index = 0; index < MorphCount; index++)
								{
									CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(index));
									CTrack::Free(morph_track);
									pose_morph_tag->GetMorph(index)->SetStrength(0);
								}
							}
						}
						iferr(nodes.Push(node_->GetDown())) return(true);
						if (node_ != op)
						{
							node_ = node_->GetNext();
						}
						else {
							break;
						}
					}
				}
				nodes.Reset();
				EventAdd();
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
	return(true);
}

/*
 * *******************
 * PMX Bone Tag
 * *******************
 */

inline Int32 mmd::TMMDBone::AddBondMorph(String morph_name)
{
	if (morph_name.IsEmpty())
	{
		morph_name = "morph_" + String::IntToString(bone_morph_name_index);
		bone_morph_name_index++;
	}
	BaseTag* pmx_bone_tag = (BaseTag*)Get();
	DynamicDescription* const	ddesc = pmx_bone_tag->GetDynamicDescription();
	if (ddesc == nullptr)
		return(-1);
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
	DescID	rename_button_id = ddesc->Alloc(bc);
	const auto& res = bone_morph_data_arr.AppendPtr(NewObj(mmd::bone_morph_data, grp_id, strength_id, translation_id, rotation_id, button_grp_id, delete_button_id, rename_button_id, morph_name).GetValue());
	iferr(res)
		return(-1);
	Int32 index = bone_morph_data_arr.GetIndex(*res.GetValue());
	iferr(button_id_map.Insert(delete_button_id, index))
		return(-1);
	iferr(button_id_map.Insert(rename_button_id, index))
		return(-1);
	if (GeIsMainThread())
	{
		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
		EventAdd();
	}
	return(index);
}
Bool mmd::TMMDBone::SplineDataCallBack(Int32 cid, const void* data)
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
Bool mmd::TMMDBone::GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator)
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
Bool mmd::TMMDBone::SetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator,Bool cover)
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
				interpolator_position_x = interpolator;
			}
		}
		else {
			interpolator_X_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
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
		break;
	}
	case (PMX_BONE_TAG_ZCURVE): {
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
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_r_ptr != nullptr)
		{
			if (cover == true) {
				mmd::VMDInterpolator& interpolator_position_r = interpolator_r_ptr->GetValue();
				interpolator_position_r = interpolator;
			}
		}
		else {
			interpolator_R_map.Insert(frame_on, interpolator) iferr_return;
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
				mmd::VMDInterpolator& interpolator_position_r = interpolator_r_ptr->GetValue();
				interpolator_position_r = interpolator;
			}
		}
		else {
			interpolator_R_map.Insert(frame_on, interpolator) iferr_return;
		}
		break;
	}
	default:
		return(false);
		break;
	}
	return(true);
}
Bool mmd::TMMDBone::AutoRegisterKeyFrame(Int32 use_rotation,GeListNode* node){
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

	frame_count = frame_set.GetCount() - 1;
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
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, now_key_frame, mmd::VMDInterpolator(maxon::SafeConvert<UChar>(maxon::Abs(KeyRightX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(KeyRightY * 127.0 / ValueOfTwoFrames)), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftX * Fps * 127.0 / Float(TimeOfTwoFrames))), maxon::SafeConvert<UChar>(maxon::Abs(NextKeyLeftY * 127.0 / ValueOfTwoFrames))),false))
			return false;
	}
	//最后一帧
	if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, Curve_position_x->GetKey(frame_count)->GetTime().GetFrame(Fps), VMDInterpolator())) {
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
		KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
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
	if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, Curve_position_y->GetKey(frame_count)->GetTime().GetFrame(Fps), VMDInterpolator())) {
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
		KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
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
	if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, Curve_position_z->GetKey(frame_count)->GetTime().GetFrame(Fps), VMDInterpolator())) {
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
		KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
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
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, Curve_rotation_x->GetKey(frame_count)->GetTime().GetFrame(Fps), VMDInterpolator())) {
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
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
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
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, Curve_rotation_y->GetKey(frame_count)->GetTime().GetFrame(Fps), VMDInterpolator())) {
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
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
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
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, Curve_rotation_z->GetKey(frame_count)->GetTime().GetFrame(Fps), VMDInterpolator())) {
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
			KeyLeftX = NextKeyLeftX, KeyLeftY = NextKeyLeftY, KeyRightX = NextKeyRightX, KeyRightY = NextKeyRightY;
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
inline Bool mmd::TMMDBone::RegisterKeyFrame(Int32 frame_on, GeListNode* node) {
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
		Key_position_x = Curve_position_x->AddKey(time);
	}
	else {
		Key_position_x->SetValue(Curve_position_x, RelPos.x);
	}
	CKey* Key_position_y = Curve_position_y->FindKey(time);
	if (Key_position_y == nullptr) {
		Key_position_y = Curve_position_y->AddKey(time);
	}
	else {
		Key_position_y->SetValue(Curve_position_y, RelPos.y);
	}
	CKey* Key_position_z = Curve_position_z->FindKey(time);
	if (Key_position_z == nullptr) {
		Key_position_z = Curve_position_z->AddKey(time);
	}
	else {
		Key_position_z->SetValue(Curve_position_z, RelPos.z);
	}
	CKey* Key_rotation_x = Curve_rotation_x->FindKey(time);
	if (Key_rotation_x == nullptr) {
		Key_rotation_x = Curve_rotation_x->AddKey(time);
	}
	else {
		Key_rotation_x->SetValue(Curve_rotation_x, RelRot.x);
	}
	CKey* Key_rotation_y = Curve_rotation_y->FindKey(time);
	if (Key_rotation_y == nullptr) {
		Key_rotation_y = Curve_rotation_y->AddKey(time);
	}
	else {
		Key_rotation_y->SetValue(Curve_rotation_y, RelRot.y);
	}
	CKey* Key_rotation_z = Curve_rotation_z->FindKey(time);
	if (Key_rotation_z == nullptr) {
		Key_rotation_z = Curve_rotation_z->AddKey(time);
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
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_YCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_ZCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_RCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_RCURVE): {
		if (!this->SetInterpolator(interpolator_type, frame_on, VMDInterpolator(
			spline->GetKnot(0)->vTangentRight.x, spline->GetKnot(0)->vTangentRight.y,
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.x),
			127 + maxon::SafeConvert<UChar>(spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft.y))))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_XCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_YCURVE, frame_on, VMDInterpolator()))
			return false;
		if (!this->SetInterpolator(PMX_BONE_TAG_ZCURVE, frame_on, VMDInterpolator()))
			return false;
		break;
	}
	case (PMX_BONE_TAG_ACURVE): {
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
inline Bool mmd::TMMDBone::UpdateAllInterpolator(GeListNode* node)
{	
	if (obj == nullptr)
	{
		return(false);
	}

	BaseTag* tag = static_cast<BaseTag*>(Get());
	CTrack* Frame_onTrack = obj->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));
	CTrack* Track_position_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X));
	CTrack* Track_position_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y));
	CTrack* Track_position_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z));
	CTrack* Track_rotation_x = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X));
	CTrack* Track_rotation_y = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y));
	CTrack* Track_rotation_z = obj->FindCTrack(DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z));
	CTrack* frameTrack = tag->FindCTrack(DescID(PMX_BONE_TAG_FRAME_ON));

	if (Track_position_x == nullptr || Track_position_y == nullptr || Track_position_z == nullptr || Track_rotation_x == nullptr || Track_rotation_y == nullptr || Track_rotation_z == nullptr|| frameTrack==nullptr)
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

	if (Curve_position_x == nullptr || Curve_position_y == nullptr || Curve_position_z == nullptr || Curve_rotation_x == nullptr || Curve_rotation_y == nullptr || Curve_rotation_z == nullptr|| frameCurve==nullptr)
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
		frame_next = frameCurve->FindKey(BaseTime(frame_on+1., 30.), nullptr, FINDANIM::RIGHT); /* 加0.01排除所在的那一帧 */
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
			key = Curve_position_x->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_position_x->FindKey(next_time);
				if (next_key != nullptr)
				{
						ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
						key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						next_key->SetTimeLeft(Curve_position_x, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::bx) / 127.0), 30.));
						next_key->SetValueLeft(Curve_position_x, -ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::by) / 127.0));
						key->SetTimeRight(Curve_position_x, BaseTime(TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ax) / 127.0), 30.));
						key->SetValueRight(Curve_position_x, ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ay) / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_Y_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_position_y->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_position_y->FindKey(next_time);
				if (next_key != nullptr)
				{
						ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
						key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						next_key->SetTimeLeft(Curve_position_y, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::bx) / 127.0), 30.));
						next_key->SetValueLeft(Curve_position_y, -ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::by) / 127.0));
						key->SetTimeRight(Curve_position_y, BaseTime(TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ax) / 127.0), 30.));
						key->SetValueRight(Curve_position_y, ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ay) / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_Z_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_position_z->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_position_z->FindKey(next_time);
				if (next_key != nullptr)
				{
						ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
						key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						next_key->SetTimeLeft(Curve_position_z, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::bx) / 127.0), 30.));
						next_key->SetValueLeft(Curve_position_z, -ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::by) / 127.0));
						key->SetTimeRight(Curve_position_z, BaseTime(TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ax) / 127.0), 30.));
						key->SetValueRight(Curve_position_z, ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ay) / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_rotation_x->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_rotation_x->FindKey(next_time);
				if (next_key != nullptr)
				{
						ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
						key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						next_key->SetTimeLeft(Curve_rotation_x, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::bx) / 127.0), 30.));
						next_key->SetValueLeft(Curve_rotation_x, -ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::by) / 127.0));
						key->SetTimeRight(Curve_rotation_x, BaseTime(TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ax) / 127.0), 30.));
						key->SetValueRight(Curve_rotation_x, ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ay) / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_rotation_y->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_rotation_y->FindKey(next_time);
				if (next_key != nullptr)
				{
						ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
						key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						next_key->SetTimeLeft(Curve_rotation_y, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::bx) / 127.0), 30.));
						next_key->SetValueLeft(Curve_rotation_y, -ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::by) / 127.0));
						key->SetTimeRight(Curve_rotation_y, BaseTime(TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ax) / 127.0), 30.));
						key->SetValueRight(Curve_rotation_y, ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ay) / 127.0));
				}
			}
		}
		interpolator_ptr = interpolator_R_map.Find(frame_on);
		if (interpolator_ptr != nullptr)
		{
			const VMDInterpolator& interpolator = interpolator_ptr->GetValue();
			key = Curve_rotation_z->FindKey(time);
			if (key != nullptr)
			{
				next_key = Curve_rotation_z->FindKey(next_time);
				if (next_key != nullptr)
				{
						ValueOfTwoFrames = next_key->GetValue() - key->GetValue();
						key->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						next_key->SetTimeLeft(Curve_rotation_z, BaseTime(-TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::bx) / 127.0), 30.));
						next_key->SetValueLeft(Curve_rotation_z, -ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::by) / 127.0));
						key->SetTimeRight(Curve_rotation_z, BaseTime(TimeOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ax) / 127.0), 30.));
						key->SetValueRight(Curve_rotation_z, ValueOfTwoFrames * ((Float)interpolator.GetValue(VMDInterpolator::PartType::ay) / 127.0));
				}
			}
		}
	}
	return(true);
}
inline Bool mmd::TMMDBone::DeleteKeyFrame(Int32 frame_on, GeListNode* node){
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
inline Bool  mmd::TMMDBone::DeleteAllKeyFrame(GeListNode* node) {
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
inline Bool mmd::TMMDBone::InitInterpolator(GeListNode* node)
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
		spline->SetUserCallback(mmd::TMMDBone::SplineDataCallBack, nullptr);
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
Bool mmd::TMMDBone::Init(GeListNode* node)
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
	bc->SetInt32(PMX_BONE_TAIL_INDEX, -1);
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
Bool mmd::TMMDBone::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
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
EXECUTIONRESULT mmd::TMMDBone::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
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
	BaseTag* lase_tag = nullptr;
	BaseObject* lase_obj = nullptr;
	BaseObject* tmp_lase_obj = nullptr;
	Int32		pred_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
	if (up_obj != nullptr)
	{
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
				/* 获取上一个骨骼 */
				while (!pred_obj->IsInstanceOf(Ojoint)) {
					pred_obj = pred_obj->GetPred();
				}
				lase_obj = pred_obj;
				/* 获取到最后一个骨骼 */
				tmp_lase_obj = lase_obj->GetDownLast();
				while (tmp_lase_obj != nullptr)
				{
					if (tmp_lase_obj->IsInstanceOf(Ojoint)) {
						lase_obj = tmp_lase_obj;
					}
					else {
						tmp_lase_obj = tmp_lase_obj->GetPred();
					}
					tmp_lase_obj = tmp_lase_obj->GetDownLast();
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
				if (this->BoneRoot == nullptr) {
					this->BoneRoot = up_obj;
					op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 1, 0, up_obj).GetValue());
				}
				bc->SetString(PMX_BONE_INDEX, "0"_s);
			}
			else {
				/* 获取上一个骨骼 */
				while (!pred_obj->IsInstanceOf(Ojoint)) {
					pred_obj = pred_obj->GetPred();
				}
				lase_obj = pred_obj;
				/* 获取到最后一个骨骼 */
				tmp_lase_obj = lase_obj->GetDownLast();
				while (tmp_lase_obj!=nullptr)
				{
					if (tmp_lase_obj->IsInstanceOf(Ojoint)) {
						lase_obj = tmp_lase_obj;
					}
					else {
						tmp_lase_obj = tmp_lase_obj->GetPred();
					}
					tmp_lase_obj = tmp_lase_obj->GetDownLast();
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
		this->BoneRoot = nullptr;
		op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 1, 0, nullptr).GetValue());
		bc->SetString(PMX_BONE_INDEX, "0"_s);
	}
	Int32 now_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
	if (now_index != pred_index && this->BoneRoot != nullptr) {
		this->BoneRoot->Message(ID_T_MMD_BONE, nullptr);
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
				spline->GetKnot(0)->vTangentRight = Vector(xCurve.GetValue(VMDInterpolator::PartType::ax), xCurve.GetValue(VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(xCurve.GetValue(VMDInterpolator::PartType::by) - 127., xCurve.GetValue(VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight =  Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_YCURVE): {
			auto interpolator_y_ptr = interpolator_Y_map.Find(frame_on);
			if (interpolator_y_ptr != nullptr)
			{
				mmd::VMDInterpolator& yCurve = interpolator_y_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(yCurve.GetValue(VMDInterpolator::PartType::ax), yCurve.GetValue(VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(yCurve.GetValue(VMDInterpolator::PartType::by) - 127., yCurve.GetValue(VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight =  Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_ZCURVE): {
			auto interpolator_z_ptr = interpolator_Z_map.Find(frame_on);
			if (interpolator_z_ptr != nullptr)
			{
				mmd::VMDInterpolator& zCurve = interpolator_z_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(zCurve.GetValue(VMDInterpolator::PartType::ax), zCurve.GetValue(VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(zCurve.GetValue(VMDInterpolator::PartType::by) - 127., zCurve.GetValue(VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight =  Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_RCURVE): {
			auto interpolator_r_ptr = interpolator_R_map.Find(frame_on);
			if (interpolator_r_ptr != nullptr)
			{
				mmd::VMDInterpolator& interpolator_position_r = interpolator_r_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(interpolator_position_r.GetValue(VMDInterpolator::PartType::ax), interpolator_position_r.GetValue(VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(interpolator_position_r.GetValue(VMDInterpolator::PartType::by) - 127., interpolator_position_r.GetValue(VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight =  Vector(20., 20., 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(-20., -20., 0.);
			}
			break;
		}
		case (PMX_BONE_TAG_ACURVE): {
			auto interpolator_a_ptr = interpolator_A_map.Find(frame_on);
			if (interpolator_a_ptr != nullptr)
			{
				mmd::VMDInterpolator& aCurve = interpolator_a_ptr->GetValue();
				spline->GetKnot(0)->vTangentRight = Vector(aCurve.GetValue(VMDInterpolator::PartType::ax), aCurve.GetValue(VMDInterpolator::PartType::ay), 0.);
				spline->GetKnot(spline->GetKnotCount() - 1)->vTangentLeft = Vector(aCurve.GetValue(VMDInterpolator::PartType::by) - 127., aCurve.GetValue(VMDInterpolator::PartType::by) - 127., 0.);
			}
			else {
				spline->GetKnot(0)->vTangentRight =  Vector(20., 20., 0.);
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
		}else{
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
		}else{
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
Bool mmd::TMMDBone::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
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
		((SplineData*)t_data.GetCustomDataType(CUSTOMDATATYPE_SPLINE))->SetUserCallback(mmd::TMMDBone::SplineDataCallBack, nullptr);
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
		if (t_data.GetBool() == 1)
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
		if (bc->GetBool(PMX_BONE_INDEXED_TAIL_POSITION) == true)
		{
			if (t_data.GetInt32() == -1)
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
			if (this->BoneRoot != nullptr) {
				BaseLink* inherit_bone_parent_link = t_data.GetBaseLink();
				if (inherit_bone_parent_link != nullptr) {
					inherit_bone_parent = static_cast<BaseObject*>(inherit_bone_parent_link->GetLink(GetActiveDocument()));
					auto inherit_bone_parent_index_ptr = this->BoneRoot->GetNodeData<OMMDBoneRoot>()->BoneToIndexMap.Find(inherit_bone_parent);
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
			if (this->BoneRoot != nullptr) {
				Int32 inherit_bone_parent_index = t_data.GetInt32();
				auto inherit_bone_parent_link_ptr = this->BoneRoot->GetNodeData<OMMDBoneRoot>()->IndexToBoneMap.Find(inherit_bone_parent_index);
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
	{
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_IS_FIXED_AXIS:
	{
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INHERIT_ROTATION:
	{
		this->RefreshColor(node);
		break;
	}
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
inline Bool mmd::TMMDBone::RefreshColor(GeListNode* node, BaseObject* op)
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
Bool mmd::TMMDBone::Message(GeListNode* node, Int32 type, void* data)
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
				if (this->BoneRoot != nullptr) {
					BaseLink* inherit_bone_parent_link = bc->GetBaseLink(id);
					if (inherit_bone_parent_link != nullptr) {
						inherit_bone_parent = static_cast<BaseObject*>(inherit_bone_parent_link->GetLink(GetActiveDocument()));
						auto inherit_bone_parent_index_ptr = this->BoneRoot->GetNodeData<OMMDBoneRoot>()->BoneToIndexMap.Find(inherit_bone_parent);
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
				if (this->BoneRoot != nullptr) {
					Int32 inherit_bone_parent_index = bc->GetInt32(id);
					auto inherit_bone_parent_link_ptr = this->BoneRoot->GetNodeData<OMMDBoneRoot>()->IndexToBoneMap.Find(inherit_bone_parent_index);
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
		{
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_IS_FIXED_AXIS:
		{
			this->RefreshColor(node);
			break;
		}
		case PMX_BONE_INHERIT_ROTATION:
		{
			this->RefreshColor(node);
			break;
		}
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
		if (dc->_descId.GetDepth() == 2)
		{
			/* check if it is a user data button */
			if (dc->_descId[0].id == ID_USERDATA)
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
					bone_morph_data& id = bone_morph_data_arr[button_on_id];
					if (dc->_descId == id.button_delete_id)
					{
						if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, id.name))
						{
							ddesc->Remove(id.grp_id);
							ddesc->Remove(id.button_grp_id);
							iferr(bone_morph_data_arr.Erase(button_on_id))
								return(true);
							for (auto& i : button_id_map.GetKeys())
							{
								Int32* index = button_id_map.FindValue(i);
								if (*index > button_on_id)
								{
									(*index)--;
								}
							}
							if (GeIsMainThread())
							{
								SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
								EventAdd();
							}
						}
						return(true);
					}
					if (dc->_descId == id.button_rename_id)
					{
						RenameDialog dlg;
						dlg.Open(DLG_TYPE::MODAL, 99999, -1, -1, 0, 0);
						if (!dlg.Rename.IsEmpty())
						{
							BaseContainer descbc = *ddesc->Find(id.grp_id);
							descbc.SetString(DESC_NAME, dlg.Rename);
							ddesc->Set(id.grp_id, descbc, nullptr);
							descbc = *ddesc->Find(id.strength_id);
							descbc.SetString(DESC_NAME, dlg.Rename);
							ddesc->Set(id.strength_id, descbc, nullptr);
							id.name = dlg.Rename;
							if (GeIsMainThread())
							{
								SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
								EventAdd();
							}
						}
						return(true);
					}
				}
			}
		}
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
		OMMDBoneRoot_MSG* msg = static_cast<OMMDBoneRoot_MSG*>(data);
		BaseDocument* doc = GetActiveDocument();
		if (msg != nullptr && bc != nullptr)
		{
			switch (msg->type)
			{
			case 0:
			{
				switch (msg->DisplayType)
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
			case 1:
			{
					this->BoneRoot = msg->BoneRoot;
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
						if (now_index != pred_index && this->BoneRoot != nullptr)
							this->BoneRoot->Message(ID_T_MMD_BONE, nullptr);
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
	return(true);
}
Bool mmd::TMMDBone::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return(false);
	};
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	if (!bone_root_link->Read(hf))
		return(false);
	this->BoneRoot = static_cast<BaseObject*>(bone_root_link->GetLink(GetActiveDocument()));
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
		this->interpolator_A_map.Insert(TempIndex, std::move(*static_cast<mmd::VMDInterpolator*>(data))) iferr_return;
	}
	if (!hf->ReadInt32(&CountTemp))
		return(false);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		DescID TempID;
		if (!TempID.Read(hf))
			return(false);
		Int32 TempIndex = 0;
		if (!hf->ReadInt32(&TempIndex))
			return(false);
		this->button_id_map.Insert(TempID, TempIndex) iferr_return;
	}
	hf->ReadInt32(&CountTemp);
	for (Int32 i = 0; i < CountTemp; i++)
	{
		bone_morph_data TempData;
		if (!TempData.grp_id.Read(hf))
			return(false);
		if (!TempData.strength_id.Read(hf))
			return(false);
		if (!TempData.translation_id.Read(hf))
			return(false);
		if (!TempData.rotation_id.Read(hf))
			return(false);
		if (!TempData.button_grp_id.Read(hf))
			return(false);
		if (!TempData.button_delete_id.Read(hf))
			return(false);
		if (!TempData.button_rename_id.Read(hf))
			return(false);
		if (!hf->ReadString(&TempData.name))
			return(false);
		this->bone_morph_data_arr.Append(TempData) iferr_return;
	}
	return(SUPER::Read(node, hf, level));
}
Bool mmd::TMMDBone::Write(GeListNode* node, HyperFile* hf)
{
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	bone_root_link->SetLink(this->BoneRoot);
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
	Int CountTemp = this->interpolator_X_map.GetCount();
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
	CountTemp = this->button_id_map.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (auto i : this->button_id_map.GetKeys())
	{
		if (!i.Write(hf))
			return(false);
		if (!hf->WriteInt32(this->button_id_map.Find(i)->GetValue()))
			return(false);
	}
	CountTemp = this->bone_morph_data_arr.GetCount();
	if (!hf->WriteInt32(CountTemp))
		return(false);
	for (bone_morph_data& i : this->bone_morph_data_arr)
	{
		if (!i.grp_id.Write(hf))
			return(false);
		if (!i.strength_id.Write(hf))
			return(false);
		if (!i.translation_id.Write(hf))
			return(false);
		if (!i.rotation_id.Write(hf))
			return(false);
		if (!i.button_grp_id.Write(hf))
			return(false);
		if (!i.button_delete_id.Write(hf))
			return(false);
		if (!i.button_rename_id.Write(hf))
			return(false);
		if (!hf->WriteString(i.name))
			return(false);
	}
	return(SUPER::Write(node, hf));
}
void mmd::TMMDBone::Free(GeListNode* node)
{
	this->interpolator_X_map.Reset();
	this->interpolator_Y_map.Reset();
	this->interpolator_Z_map.Reset();
	this->interpolator_R_map.Reset();
	this->interpolator_A_map.Reset();
	this->bone_morph_data_arr.Reset();
}

/*
 * *******************
 * PMX Rigid Object
 * *******************
 */

const Vector	PMX_Rigid_Color[16] = {
	Vector(255, 212, 127) / 255,
	Vector(212, 255, 127) / 255,
	Vector(127, 255, 127) / 255,
	Vector(127, 212, 255) / 255,
	Vector(127, 212, 255) / 255,
	Vector(127, 127, 255) / 255,
	Vector(212, 127, 255) / 255,
	Vector(255, 84,  0) / 255,
	Vector(255, 255, 0) / 255,
	Vector(0,   255, 85) / 255,
	Vector(0,   255, 255) / 255,
	Vector(0,   85,  255) / 255,
	Vector(84,  0,	  255) / 255,
	Vector(255, 0,	  255) / 255,
	Vector(255, 0,	  84) / 255,
	Vector(127, 127, 0) / 255
};
const Vector	PMX_Rigid_Wire_Color[3] = {
	Vector(200, 255, 150) / 255,
	Vector(255, 200, 150) / 255,
	Vector(255, 255, 150) / 255,
};
Bool mmd::OMMDRigid::Init(GeListNode* node)
{
	if (node == nullptr)
		return(false);
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return(false);
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	bc->SetInt32(RIGID_RELATED_BONE_INDEX, -1);
	bc->SetFloat(RIGID_SHAPE_SIZE_X, 17.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Y, 17.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Z, 17.);
	bc->SetFloat(RIGID_MASS, 1.);
	bc->SetFloat(RIGID_FRICTION_FORCE, 0.5);
	bc->SetFloat(RIGID_MOVE_ATTENUATION, 0.5);
	bc->SetFloat(RIGID_ROTATION_DAMPING, 0.5);
#if API_VERSION >= 21000
	bc->SetInt32(ID_BASELIST_ICON_COLORIZE_MODE, ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM);
#endif
	return(true);
}
Bool mmd::OMMDRigid::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	if (!(node && description))
		return(false);
	if (!description->LoadDescription(node->GetType()))
		return(false);
	BaseContainer* settings = nullptr;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc != nullptr)
	{
		switch (bc->GetInt32(RIGID_SHAPE_TYPE))
		{
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
	settings = description->GetParameterI(RIGID_RELATED_BONE_INDEX, nullptr);
	if (settings != nullptr) {
		settings->SetContainer(DESC_CYCLE, this->RigidRoot->GetNodeData<OMMDRigidRoot>()->BoneRoot->GetNodeData<OMMDBoneRoot>()->bone_items);
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return(SUPER::GetDDescription(node, description, flags));
}
Bool mmd::OMMDRigid::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	switch (id[0].id)
	{
	case RIGID_SHAPE_TYPE:
	{
		if (bc != nullptr)
		{
			switch (t_data.GetInt32())
			{
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
		if (bc != nullptr)
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
		if (bc != nullptr)
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
		if (bc != nullptr)
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
			{
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
				if (this->pdraw_obj != nullptr)
				{
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
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
Bool mmd::OMMDRigid::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	switch (id[0].id)
	{
	case ID_BASEOBJECT_REL_POSITION:
		return(false);
	case ID_BASEOBJECT_REL_ROTATION:
		return(false);
	default:
		break;
	}
	return(SUPER::GetDEnabling(node, id, t_data, flags, itemdesc));
}
Bool mmd::OMMDRigid::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if API_VERSION >= 21000
case MSG_GETCUSTOMICON:
	{
		GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);
		if (cid == nullptr)
			break;
		CustomIconSettings	settings;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr)
		{
			break;
		}
		BaseContainer& bcr = static_cast<BaseObject*>(node)->GetDataInstanceRef();
		FillCustomIconSettingsFromBaseList2D(settings, bcr, node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)]);
		CustomIconGetIdDelegate getIdCallback = [bc]()->Int32
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
				return(Osphere);
			case BOX:
				return(Ocube);
			case CAPLETS:
				return(Ocapsule);
			default:
				break;
			}
			return(Osphere);
		};
		GetCustomIcon(*cid, settings, false, &getIdCallback);
		break;
	}
#endif
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32	id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		switch (id)
		{
		case RIGID_SHAPE_TYPE:
		{
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
					if (this->pdraw_obj != nullptr)
					{
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
		if (msg != nullptr)
		{
			if (msg->type == 0)
			{
				this->DisplayType = msg->DisplayType;
				if (draw_obj == nullptr)
				{
					if (this->DisplayType != RIGID_DISPLAY_TYPE_OFF)
					{
						BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
						if (bc != nullptr)
						{
							BaseObject::Free(draw_obj);
							BaseObject::Free(pdraw_obj);
							ModelingCommandData cd;
							switch (bc->GetInt32(RIGID_SHAPE_TYPE))
							{
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
				else if (this->DisplayType == RIGID_DISPLAY_TYPE_OFF)
				{
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
				}
			}
			this->Mode = msg->Mode;
		}
		break;
	}
	default:
		break;
	}
	return(SUPER::Message(node, type, data));
}
DRAWRESULT mmd::OMMDRigid::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass == DRAWPASS::OBJECT)
	{
		if (op == nullptr || bd == nullptr || bh == nullptr)
		{
			return(DRAWRESULT::FAILURE);
		}
		BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
		bd->SetMatrix_Matrix(nullptr, op->GetMg());
		if (bc != nullptr)
		{
			switch (this->DisplayType)
			{
			case RIGID_DISPLAY_TYPE_ON:
			{
				if (draw_obj != nullptr)
				{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS, PMX_Rigid_Color[(bc->GetInt32(RIGID_GROUP_ID))], false };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else {
						ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS, PMX_Rigid_Color[(bc->GetInt32(RIGID_GROUP_ID))], true };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR | DRAWOBJECT::XRAY_ON, drawpass);
					}
				}
				else {
					if (bc != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						switch (bc->GetInt32(RIGID_SHAPE_TYPE))
						{
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
				if (draw_obj != nullptr)
				{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS, Vector(1, 0.21, 0.21), false };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else {
						ObjectColorProperties objColor{ ID_BASEOBJECT_USECOLOR_ALWAYS, PMX_Rigid_Wire_Color[(bc->GetInt32(RIGID_PHYSICS_MODE))], false };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
				}
				else {
					if (bc != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						switch (bc->GetInt32(RIGID_SHAPE_TYPE))
						{
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
	return(SUPER::Draw(op, drawpass, bd, bh));
}
EXECUTIONRESULT mmd::OMMDRigid::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
	if (bc == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	BaseObject* PredObject = op->GetPred();
	BaseObject* UpObject = op->GetUp();
	BaseObject* rigid_root_object = this->RigidRoot;
	if (UpObject == nullptr && rigid_root_object != nullptr)
	{
		op->Remove();
		op->InsertUnderLast(rigid_root_object);
	}
	Int32 pred_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr);
	if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_RIGID_ROOT))
	{
		if (PredObject == nullptr)
		{
			op->SetParameter(RIGID_INDEX, "0"_s, DESCFLAGS_SET::NONE);
		}
		else {
			while (PredObject!=nullptr && !PredObject->IsInstanceOf(ID_O_MMD_RIGID))
			{
				PredObject = PredObject->GetPred();
			}
			GeData data;
			PredObject->GetParameter(RIGID_INDEX, data, DESCFLAGS_GET::NONE);
			String RigidIndex = data.GetString();
			op->SetParameter(RIGID_INDEX, String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}
		if (rigid_root_object == nullptr)
		{
			this->RigidRoot=UpObject;
		}
	}
	Int32 now_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr);
	if (now_index != pred_index && this->RigidRoot != nullptr)
		this->RigidRoot->Message(ID_O_MMD_RIGID, NewObj(mmd::OMMDRigid_MSG, pred_index, now_index, op).GetValue());
	return(EXECUTIONRESULT::OK);
}
Bool mmd::OMMDRigid::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return(true);
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return(true);
}
Bool mmd::OMMDRigid::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	AutoAlloc<BaseLink> rigid_root_link;
	if (rigid_root_link == nullptr)
		return false;
	if (!rigid_root_link->Read(hf))
		return(false);
	this->RigidRoot = static_cast<BaseObject*>(rigid_root_link->GetLink(GetActiveDocument()));
	return true;
}
Bool mmd::OMMDRigid::Write(GeListNode* node, HyperFile* hf)
{
	AutoAlloc<BaseLink> rigid_root_link;
	if (rigid_root_link == nullptr)
		return false;
	rigid_root_link->SetLink(this->RigidRoot);
	if (!rigid_root_link->Write(hf))
		return(false);
	return true;
}
Bool mmd::OMMDRigid::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDRigid* const destObject = static_cast<OMMDRigid*>(dest);
	if (destObject == nullptr)
		return(false);
	destObject->RigidRoot = this->RigidRoot;
	destObject->DisplayType == this->DisplayType;
	return(true);
}
void mmd::OMMDRigid::Free(GeListNode* node)
{
	BaseObject::Free(this->pdraw_obj);
	BaseObject::Free(this->draw_obj);
}

/*
 * *******************
 * PMX Joint Object
 * *******************
 */

const Vector PMX_Joint_Color[6] = {
	Vector(255, 255, 70) / 255,
	Vector(255, 114, 131) / 255,
	Vector(233, 211, 255) / 255,
	Vector(174, 255, 112) / 255,
	Vector(109, 162, 255) / 255,
	Vector(255, 155, 230) / 255
};
Bool mmd::OMMDJoint::Init(GeListNode* node)
{
	if (node == nullptr)
		return(false);
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return(false);
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	bc->SetString(JOINT_NAME_LOCAL, "Joint"_s);
	bc->SetString(JOINT_NAME_UNIVERSAL, "Joint"_s);
	bc->SetInt32(JOINT_LINK_RIGID_A_INDEX, -1);
	bc->SetInt32(JOINT_LINK_RIGID_B_INDEX, -1);
	bc->SetInt32(JOINT_ATTITUDE_USE_BONE_INDEX, -1);
	return(true);
}
Bool mmd::OMMDJoint::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	if (!(node && description))
		return(false);
	if (!description->LoadDescription(node->GetType()))
		return(false);
	BaseContainer* settings = nullptr;
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	settings = description->GetParameterI(JOINT_LINK_RIGID_A_INDEX, nullptr);
	if (settings != nullptr) {
		settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->rigid_items);
	}
	settings = description->GetParameterI(JOINT_LINK_RIGID_B_INDEX, nullptr);
	if (settings != nullptr) {
		settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->rigid_items);
	}
	settings = description->GetParameterI(JOINT_ATTITUDE_USE_BONE_INDEX, nullptr);
	if (settings != nullptr) {
		settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<OMMDJointRoot>()->BoneRoot->GetNodeData<OMMDBoneRoot>()->bone_items);
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return(SUPER::GetDDescription(node, description, flags));
}
Bool mmd::OMMDJoint::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
Bool mmd::OMMDJoint::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if API_VERSION >= 21000
	case MSG_GETCUSTOMICON:
	{
		GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);
		if (cid == nullptr)
			break;
		CustomIconSettings	settings;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr)
		{
			break;
		}
		BaseContainer& bcr = static_cast<BaseObject*>(node)->GetDataInstanceRef();
		FillCustomIconSettingsFromBaseList2D(settings, bcr, node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(PMX_Joint_Color[bc->GetInt32(JOINT_TYPE)]);
		CustomIconGetIdDelegate getIdCallback = [bc]()->Int32
		{
			return(Ocube);
		};
		GetCustomIcon(*cid, settings, false, &getIdCallback);
		break;
	}
#endif
	case  ID_O_MMD_JOINT_ROOT:
	{
		OMMDJointRoot_MSG* msg = static_cast<OMMDJointRoot_MSG*>(data);
		if (msg != nullptr)
		{
			if (msg->type == 0)
			{
				this->DisplayType = msg->DisplayType;
			}
			else {
				this->Mode = msg->Mode;
			}
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr)
			return(true);
		switch (dc->_descId[0].id)
		{
		case JOINT_LINK_RIGID_SET_NAME_BUTTON:
		{
			String name = "<->"_s;
			auto a_rigid_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX));
			if (a_rigid_ptr != nullptr) {
				BaseObject* a_rigid_object = a_rigid_ptr->GetValue();
				if (a_rigid_object != nullptr) {
					name = a_rigid_object->GetName() + name;
				}
			}
			auto b_rigid_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX));
			if (b_rigid_ptr != nullptr) {
				BaseObject* b_rigid_object = b_rigid_ptr->GetValue();
				if (b_rigid_object != nullptr) {
					name = name + b_rigid_object->GetName();
				}
			}
			static_cast<BaseObject*>(node)->SetName(name);
			break;
		}
		case JOINT_ATTITUDE_USE_BONE_BUTTON:
		{
			auto bone_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->BoneRoot->GetNodeData<OMMDBoneRoot>()->IndexToBoneMap.Find(bc->GetInt32(JOINT_ATTITUDE_USE_BONE_INDEX));
			if (bone_ptr != nullptr) {
				static_cast<BaseObject*>(node)->SetAbsPos(bone_ptr->GetValue()->GetAbsPos());
			}
			break;
		}
		case JOINT_PARAMETER_RESET_BUTTON:
		{
			bc->SetFloat(JOINT_PARAMETER_POSITION_X_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_X_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Y_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Y_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Z_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Z_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_X_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_X_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Y_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Y_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Z_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Z_MAX, 0.0);
			break;
		}
		case JOINT_SPRING_RESET_BUTTON:
		{
			bc->SetFloat(JOINT_SPRING_POSITION_X, 0.0);
			bc->SetFloat(JOINT_SPRING_POSITION_Y, 0.0);
			bc->SetFloat(JOINT_SPRING_POSITION_Z, 0.0);
			bc->SetFloat(JOINT_SPRING_ROTATION_X, 0.0);
			bc->SetFloat(JOINT_SPRING_ROTATION_Y, 0.0);
			bc->SetFloat(JOINT_SPRING_ROTATION_Z, 0.0);
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
	return(SUPER::Message(node, type, data));
}
DRAWRESULT mmd::OMMDJoint::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass == DRAWPASS::OBJECT)
	{
		if (op == nullptr || bd == nullptr || bh == nullptr)
		{
			return(DRAWRESULT::FAILURE);
		}
		BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
		if (bc != nullptr)
		{
			bd->SetMatrix_Matrix(nullptr, op->GetMg());
			switch (this->DisplayType)
			{
			case JOINT_DISPLAY_TYPE_ON:
			{
				if (op == GetActiveDocument()->GetActiveObject())
				{
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
				if (op == GetActiveDocument()->GetActiveObject())
				{
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
	return(SUPER::Draw(op, drawpass, bd, bh));
}
EXECUTIONRESULT mmd::OMMDJoint::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return(EXECUTIONRESULT::OK);
	}
	BaseObject* PredObject = op->GetPred();
	BaseObject* UpObject = op->GetUp();
	if (UpObject == nullptr && this->JointRoot != nullptr)
	{
		op->Remove();
		op->InsertUnderLast(this->JointRoot);
	}
	if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_JOINT_ROOT))
	{
		if (PredObject == nullptr)
		{
			op->SetParameter(JOINT_INDEX, "0"_s, DESCFLAGS_SET::NONE);
		}
		else {
			GeData data;
			PredObject->GetParameter(JOINT_INDEX, data, DESCFLAGS_GET::NONE);
			String RigidIndex = data.GetString();
			op->SetParameter(JOINT_INDEX, String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}
		if (this->JointRoot == nullptr)
		{
			this->JointRoot = UpObject;
		}
	}
	return(EXECUTIONRESULT::OK);
}
Bool mmd::OMMDJoint::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return(true);
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return(true);
}
Bool mmd::OMMDJoint::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	AutoAlloc<BaseLink> joint_root_link;
	if (!joint_root_link->Read(hf))
		return(false);
	this->JointRoot = static_cast<BaseObject*>(joint_root_link->GetLink(GetActiveDocument()));
	return true;
}
Bool mmd::OMMDJoint::Write(GeListNode* node, HyperFile* hf)
{
	AutoAlloc<BaseLink> joint_root_link;
	joint_root_link->SetLink(this->JointRoot);
	if (!joint_root_link->Write(hf))
		return(false);
	return true;
}
Bool mmd::OMMDJoint::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDJoint* const destObject = static_cast<OMMDJoint*>(dest);
	if (destObject == nullptr)
		return(false);
	destObject->JointRoot = this->JointRoot;
	destObject->DisplayType = this->DisplayType;
	return(true);
}

/*
 * *******************
 * PMX Mesh Root Object
 * *******************
 */

Bool mmd::OMMDMeshRoot::Init(GeListNode* node)
{
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr)
	{
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr)
		{
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		BaseTag* DisplayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		if (DisplayTag != nullptr)
		{
			DisplayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
			DisplayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			DisplayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return(true);
}
Bool mmd::OMMDMeshRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == MESH_DISPLAY_TYPE)
	{
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
	return(SUPER::SetDParameter(node, id, t_data, flags));
}

/*
 * *******************
 * PMX Bone Root Object
 * *******************
 */

Bool mmd::OMMDBoneRoot::Init(GeListNode* node)
{
	this->RigidRoot = BaseLink::Alloc();
	this->JointRoot = BaseLink::Alloc();
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr)
	{
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr)
		{
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return(true);
}
void mmd::OMMDBoneRoot::Free(GeListNode* node) {
	BaseLink::Free(this->RigidRoot);
	BaseLink::Free(this->JointRoot);
}
Bool mmd::OMMDBoneRoot::Read(GeListNode* node, HyperFile* hf, Int32 level) 
{
	if (!this->RigidRoot->Read(hf))
		return(false);
	if (!this->JointRoot->Read(hf))
		return(false);
	Int64 bone_map_count = 0;
	if (!hf->ReadInt64(&bone_map_count))
		return(false);
	this->IndexToBoneMap.Reset();
	this->BoneToIndexMap.Reset();
	Int32 index = 0;
	for (Int64 i = 0; i < bone_map_count; i++)
	{	
		if (!hf->ReadInt32(&index))
			return(false);
		AutoAlloc<BaseLink> tmp;
		if (!tmp->Read(hf))
			return(false);
		iferr(this->IndexToBoneMap.Insert(index,static_cast<BaseObject*>(tmp->GetLink(GetActiveDocument()))))		
			return(false);
		iferr(this->BoneToIndexMap.Insert(static_cast<BaseObject*>(tmp->GetLink(GetActiveDocument())), index))
			return(false);
	}
	return true;
}
Bool mmd::OMMDBoneRoot::Write(GeListNode* node, HyperFile* hf) 
{
	if (!this->RigidRoot->Write(hf))
		return(false);
	if (!this->JointRoot->Write(hf))
		return(false);
	if (!hf->WriteInt64(this->IndexToBoneMap.GetCount()))
		return(false);
	for (auto& i : this->IndexToBoneMap.GetKeys())
	{
		AutoAlloc<BaseLink> tmp;
		tmp->SetLink(IndexToBoneMap.Find(i)->GetValue());
		if (!hf->WriteInt32(i))
			return(false);
		if (!tmp->Write(hf))
			return(false);
	}
	return true;
}
Bool mmd::OMMDBoneRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDBoneRoot* const destObject = static_cast<OMMDBoneRoot*>(dest);
	BaseLink::Free(destObject->RigidRoot);
	destObject->RigidRoot=this->RigidRoot->GetClone(flags, trn);
	BaseLink::Free(destObject->JointRoot);
	destObject->JointRoot=this->JointRoot->GetClone(flags, trn);
	BaseObject* tmp = nullptr;
	this->IndexToBoneMap.Reset();
	this->BoneToIndexMap.Reset();
	for (auto& i : this->IndexToBoneMap.GetKeys())
	{
		tmp = this->IndexToBoneMap.Find(i)->GetValue();
		iferr(destObject->IndexToBoneMap.Insert(i, tmp))
			return(false);
		iferr(destObject->BoneToIndexMap.Insert(tmp, i))
			return(false);
		tmp = nullptr;
	}
	return true;
}
Bool mmd::OMMDBoneRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == BONE_DISPLAY_TYPE)
	{
		switch (t_data.GetInt32())
		{
		case BONE_DISPLAY_TYPE_ON:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_ON).GetValue());
			break;
		}
		case BONE_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_OFF).GetValue());
			break;
		}
		case BONE_DISPLAY_TYPE_MOVABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_MOVABLE).GetValue());
			break;
		}
		case BONE_DISPLAY_TYPE_VISIBLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_VISIBLE).GetValue());
			break;
		}
		case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_ROTATABLE).GetValue());
			break;
		}
		case BONE_DISPLAY_TYPE_ENABLED:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_ENABLED).GetValue());
			break;
		}
		case BONE_DISPLAY_TYPE_IK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, 0, BONE_DISPLAY_TYPE_IK).GetValue());
			break;
		}
		default:
			break;
		}
	}
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
Bool mmd::OMMDBoneRoot::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return(true);
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = static_cast<DescriptionCommand*>(data);
		if (dc->_descId[0].id == ADD_BONE_BUTTON)
		{
			BaseObject* newBone = BaseObject::Alloc(Ojoint);
			if (newBone != nullptr)
			{
				auto bone_node = newBone->MakeTag(ID_T_MMD_BONE)->GetNodeData<TMMDBone>();
				newBone->SetName(newBone->GetName() + "." + String::IntToString(this->name_cnt++));
				bone_node->SetObj(newBone);
				bone_node->SetRootObject(static_cast<BaseObject*>(node));
				bone_node->RefreshColor();
				newBone->InsertUnder(node);
			}
		}
		break;
	}
	case ID_T_MMD_BONE:
	{		
		BaseObject* op = static_cast<BaseObject*>(node);
		this->bone_items.FlushAll();
		this->bone_items.SetString(-1, "-"_s);
		this->IndexToBoneMap.Reset();
		this->BoneToIndexMap.Reset();
		maxon::Queue<BaseObject*> nodes;
		GeData ge_data;
		Int32 bone_index = 0;
		BaseTag* node_bone_tag = nullptr;
		iferr(nodes.Push(op)) return(true);
		while (!nodes.IsEmpty())
		{
			BaseObject* node_ = *(nodes.Pop());
			while (node_ != nullptr)
			{
				if (node_->GetType() == Ojoint)
				{
					node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
					if (node_bone_tag != nullptr)
					{
						node_bone_tag->GetParameter(PMX_BONE_INDEX, ge_data, DESCFLAGS_GET::NONE);
						bone_index = ge_data.GetString().ToInt32(nullptr);
						this->bone_items.SetString(bone_index, node_->GetName());
						this->IndexToBoneMap.Insert(bone_index, node_)iferr_return;
						this->BoneToIndexMap.Insert(node_, bone_index)iferr_return;
					}
				}
				iferr(nodes.Push(node_->GetDown()))
					return(true);
				if (node_ != op)
				{
					node_ = node_->GetNext();
				}
				else {
					break;
				}
			}
		}
		nodes.Reset();
		break;
	}
	case ID_O_MMD_MODEL:
	{
		OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data);
		if (msg != nullptr)
		{
			switch (msg->type)
			{
			case OMMDModel_Root_type::JointRoot:
			{
				this->JointRoot->SetLink(msg->Root);
				break;

			case OMMDModel_Root_type::RigidRoot:
			{
				this->RigidRoot->SetLink(msg->Root);
				break;
			}
			default:
				break;
			}
			}
			break;
		}
	}
	default:
		break;
	}
	return(true);
}

/*
 * *******************
 * PMX Rigid Root Object
 * *******************
 */

Bool mmd::OMMDRigidRoot::Init(GeListNode* node)
{
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr)
	{
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr)
		{
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
		BaseTag* DisplayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		if (DisplayTag != nullptr)
		{
			DisplayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
			DisplayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			DisplayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return(true);
}
void mmd::OMMDRigidRoot::Free(GeListNode* node) 
{

}
Bool mmd::OMMDRigidRoot::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	if (!bone_root_link->Read(hf))
		return(false);
	this->BoneRoot = static_cast<BaseObject*>(bone_root_link->GetLink(GetActiveDocument()));
	AutoAlloc<BaseLink> joint_root_link;
	if (joint_root_link == nullptr)
		return false;
	if (!joint_root_link->Read(hf))
		return(false);
	this->JointRoot = static_cast<BaseObject*>(joint_root_link->GetLink(GetActiveDocument()));
	Int64 rigid_map_count = 0;
	if (!hf->ReadInt64(&rigid_map_count))
		return(false);
	Int32 index = 0;
	for (Int64 i = 0; i < rigid_map_count; i++)
	{
		if (!hf->ReadInt32(&index))
			return(false);
		AutoAlloc<BaseLink> tmp;
		if (!tmp->Read(hf))
			return(false);
		iferr(this->IndexToRigidMap.Insert(index, static_cast<BaseObject*>(tmp->GetLink(GetActiveDocument()))))
			return(false);
	}
	return(true);
}
Bool mmd::OMMDRigidRoot::Write(GeListNode* node, HyperFile* hf)
{
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	bone_root_link->SetLink(this->BoneRoot);
	if (!bone_root_link->Write(hf))
		return(false);
	AutoAlloc<BaseLink> joint_root_link;
	if (joint_root_link == nullptr)
		return false;
	joint_root_link->SetLink(this->JointRoot);
	if (!joint_root_link->Write(hf))
		return(false);
	if (!hf->WriteInt64(this->IndexToRigidMap.GetCount()))
		return(false);
	for (auto& i : this->IndexToRigidMap.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		AutoAlloc<BaseLink> tmp;
		tmp->SetLink(this->IndexToRigidMap.Find(i)->GetValue());
		if (!tmp->Write(hf))
			return(false);
	}
	return(true);
}
Bool mmd::OMMDRigidRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDRigidRoot* const destObject = static_cast<OMMDRigidRoot*>(dest);
	destObject->BoneRoot = this->BoneRoot;
	destObject->JointRoot = this->JointRoot;
	return(true);
}
Bool mmd::OMMDRigidRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == RIGID_DISPLAY_TYPE)
	{
		switch (t_data.GetInt32())
		{
		case RIGID_DISPLAY_TYPE_OFF:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, RIGID_DISPLAY_TYPE_OFF).GetValue());
			break;
		}
		case RIGID_DISPLAY_TYPE_ON:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, RIGID_DISPLAY_TYPE_ON).GetValue());
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, RIGID_DISPLAY_TYPE_WIRE).GetValue());
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
	}
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
Bool mmd::OMMDRigidRoot::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
	return(true);
	};
	BaseDocument* doc = GetActiveDocument();
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc->_descId[0].id == ADD_RIGID_BUTTON)
		{
			BaseObject* newRigid = BaseObject::Alloc(ID_O_MMD_RIGID);
			if (newRigid != nullptr)
			{
				newRigid->SetName(newRigid->GetName() + "." + String::IntToString(this->name_cnt++));
				newRigid->InsertUnder(node);
			}
		}
		break;
	}
	case ID_O_MMD_RIGID:
	{
		BaseObject* op = static_cast<BaseObject*>(node);
		this->rigid_items.FlushAll();
		this->rigid_items.SetString(-1, "-"_s);
		this->IndexToRigidMap.Reset();
		GeData ge_data;
		BaseObject* node_ = op->GetDown();
		while (node_ != nullptr)
		{
			if (node_->GetType() == ID_O_MMD_RIGID)
			{
				node_->GetParameter(RIGID_INDEX, ge_data, DESCFLAGS_GET::NONE);
				Int32 rigid_index = ge_data.GetString().ToInt32(nullptr);
				this->rigid_items.SetString(rigid_index, node_->GetName());
				this->IndexToRigidMap.Insert(rigid_index, node_)iferr_return;
			}
			node_ = node_->GetNext();
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data);
		if (msg != nullptr)
		{
			switch (msg->type)
			{
			case  OMMDModel_Root_type::BoneRoot:
			{
				this->BoneRoot = msg->Root;
				break;
			}
			case OMMDModel_Root_type::JointRoot:
			{
				this->JointRoot = msg->Root;
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
	return(true);
}

/*
 * *******************
 * PMX Joint Root Object
 * *******************
 */

Bool mmd::OMMDJointRoot::Init(GeListNode* node)
{
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (node != nullptr)
	{
		BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
		if (ProtectionTag != nullptr)
		{
			ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return(true);
}
Bool mmd::OMMDJointRoot::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	AutoAlloc<BaseLink> bone_root_link;
	if (!bone_root_link->Read(hf))
		return(false);
	this->BoneRoot = static_cast<BaseObject*>(bone_root_link->GetLink(GetActiveDocument()));
	AutoAlloc<BaseLink> rigid_root_link;
	if (!rigid_root_link->Read(hf))
		return(false);
	this->RigidRoot = static_cast<BaseObject*>(rigid_root_link->GetLink(GetActiveDocument()));
	return(true);
}
Bool mmd::OMMDJointRoot::Write(GeListNode* node, HyperFile* hf)
{
	AutoAlloc<BaseLink> bone_root_link;
	bone_root_link->SetLink(this->BoneRoot);
	if (!bone_root_link->Write(hf))
		return(false);
	AutoAlloc<BaseLink> rigid_root_link;
	rigid_root_link->SetLink(this->RigidRoot);
	if (!rigid_root_link->Write(hf))
		return(false);
	return(true);
}
Bool mmd::OMMDJointRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDJointRoot* const destObject = static_cast<OMMDJointRoot*>(dest);
	destObject->BoneRoot = this->BoneRoot;
	destObject->RigidRoot = this->RigidRoot;
	return(true);
}
Bool mmd::OMMDJointRoot::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc->_descId[0].id == ADD_JOINT_BUTTON)
		{
			BaseObject* newJoint = BaseObject::Alloc(ID_O_MMD_JOINT);
			if (newJoint != nullptr)
			{
				newJoint->SetName(newJoint->GetName() + "." + String::IntToString(this->name_cnt++));
				newJoint->InsertUnder(node);
			}
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data);
		if (msg != nullptr)
		{
			switch (msg->type)
			{
			case OMMDModel_Root_type::BoneRoot:
			{
				this->BoneRoot = msg->Root;
				break;

			case OMMDModel_Root_type::RigidRoot:
			{
				this->RigidRoot = msg->Root;
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
	return(true);
}
Bool mmd::OMMDJointRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (id[0].id == JOINT_DISPLAY_TYPE)
	{
		switch (t_data.GetInt32())
		{
		case JOINT_DISPLAY_TYPE_OFF:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 0, JOINT_DISPLAY_TYPE_OFF).GetValue());
			break;
		}
		case JOINT_DISPLAY_TYPE_ON:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 0, JOINT_DISPLAY_TYPE_ON).GetValue());
			break;
		}
		case JOINT_DISPLAY_TYPE_WIRE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 0, JOINT_DISPLAY_TYPE_WIRE).GetValue());
			break;
		}
		default:
			break;
		}
	}
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
