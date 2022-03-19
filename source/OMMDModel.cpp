#include "OMMDModel.h"
#include "TMMDBone.h"

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
	if (level == 1) {
		AutoAlloc<BaseLink> mesh_root_link;
		if (mesh_root_link == nullptr)
			return(false);
		AutoAlloc<BaseLink> rigid_root_link;
		if (rigid_root_link == nullptr)
			return(false);
		AutoAlloc<BaseLink> joint_root_link;
		if (joint_root_link == nullptr)
			return(false);
		AutoAlloc<BaseLink> bone_root_link;
		if (bone_root_link == nullptr)
			return(false);
		if (!mesh_root_link->Read(hf))
			return(false);
		if (!rigid_root_link->Read(hf))
			return(false);
		if (!joint_root_link->Read(hf))
			return(false);
		if (!bone_root_link->Read(hf))
			return(false);
		this->MeshRoot = static_cast<BaseObject*>(mesh_root_link->ForceGetLink());
		this->RigidRoot = static_cast<BaseObject*>(rigid_root_link->ForceGetLink());
		this->JointRoot = static_cast<BaseObject*>(joint_root_link->ForceGetLink());
		this->BoneRoot = static_cast<BaseObject*>(bone_root_link->ForceGetLink());
	}
	return true;
}
Bool mmd::OMMDModel::Write(GeListNode* node, HyperFile* hf) {
	AutoAlloc<BaseLink> mesh_root_link;
	if (mesh_root_link == nullptr)
		return(false);
	AutoAlloc<BaseLink> rigid_root_link;
	if (rigid_root_link == nullptr)
		return(false);
	AutoAlloc<BaseLink> joint_root_link;
	if (joint_root_link == nullptr)
		return(false);
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return(false);
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
								const Int32	BoneMorphCount = (Int32)pmx_bone_tag_data->GetMorphCount();
								for (Int32 index = 0; index < BoneMorphCount; index++)
								{
									auto* bone_morph = pmx_bone_tag_data->GetMorph(index);
									if (bone_morph == nullptr)
										break;
									CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph->strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(bone_morph->strength_id, 0, DESCFLAGS_SET::NONE);
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
								const Int32	BoneMorphCount = (Int32)pmx_bone_tag_data->GetMorphCount();
								for (Int32 index = 0; index < BoneMorphCount; index++)
								{
									auto* bone_morph = pmx_bone_tag_data->GetMorph(index);
									if (bone_morph == nullptr)
										break;
									CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph->strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(bone_morph->strength_id, 0, DESCFLAGS_SET::NONE);
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
								const Int32	BoneMorphCount = (Int32)pmx_bone_tag_data->GetMorphCount();
								for (Int32 index = 0; index < BoneMorphCount; index++)
								{
									auto* bone_morph = pmx_bone_tag_data->GetMorph(index);
									if (bone_morph == nullptr)
										break;
									CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph->strength_id);
									CTrack::Free(morph_track);
									node_bone_tag->SetParameter(bone_morph->strength_id, 0, DESCFLAGS_SET::NONE);
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