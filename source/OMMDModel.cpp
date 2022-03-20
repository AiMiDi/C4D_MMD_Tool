#include "OMMDModel.h"
#include "TMMDBone.h"
#include "OMMDMeshRoot.h"
#include "OMMDBoneRoot.h"

namespace tool {
	void GroupMorph::MorphUpdata(OMMDModel* model) {
		if (model == nullptr)
			return;
		GeListNode* node = model->Get();
		for (auto& name : m_data) {
			auto* morph_ptr = model->m_morph_map.Find(name);
			if (morph_ptr == nullptr)
				return;
			IMorph* morph = morph_ptr->GetValue();
			if(morph == nullptr)
				return;
			morph->SetStrength(node, this->GetStrength(node));
		}
	}
	void FlipMorph::MorphUpdata(OMMDModel* model) {
		if (model == nullptr)
			return;
		GeListNode* node = model->Get();
		for (auto& name : m_data) {
			auto* morph_ptr = model->m_morph_map.Find(name);
			if (morph_ptr == nullptr)
				return;
			IMorph* morph = morph_ptr->GetValue();
			if (morph == nullptr)
				return;
			morph->SetStrength(node, this->GetStrength(node) >= 0.5 ? 1.0 : 0.0);;
		}
	}
	void MeshMorph::MorphUpdata(OMMDModel* model)
	{
		if (model == nullptr)
			return;
		if (model->m_MeshRoot_ptr == nullptr)
			return;
		auto& mesh_morph_map = model->m_MeshRoot_ptr->GetNodeData<OMMDMeshRoot>()->m_mesh_morph_map;
		auto* mesh_morph_ptr = mesh_morph_map.Find(m_name);
		if (mesh_morph_ptr == nullptr)
			return;
		auto& mesh_morph = mesh_morph_ptr->GetValue();
		mesh_morph.SetStrength(this->GetStrength(model->Get()));

	}
	void BoneMorph::MorphUpdata(OMMDModel* model)
	{
		if (model == nullptr)
			return;
		if (model->m_BoneRoot_ptr == nullptr)
			return;
		auto& bone_morph_map = model->m_BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->m_bone_morph_map;
		auto* bone_morph_ptr = bone_morph_map.Find(m_name);
		if (bone_morph_ptr == nullptr)
			return;
		auto& bone_morph = bone_morph_ptr->GetValue();
		bone_morph.SetStrength(this->GetStrength(model->Get()));
	}
	Bool OMMDModel::Init(GeListNode* node)
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
	Bool OMMDModel::Read(GeListNode* node, HyperFile* hf, Int32 level) {
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
			this->m_MeshRoot_ptr = static_cast<BaseObject*>(mesh_root_link->ForceGetLink());
			this->m_RigidRoot_ptr = static_cast<BaseObject*>(rigid_root_link->ForceGetLink());
			this->m_JointRoot_ptr = static_cast<BaseObject*>(joint_root_link->ForceGetLink());
			this->m_BoneRoot_ptr = static_cast<BaseObject*>(bone_root_link->ForceGetLink());
		}
		return true;
	}
	Bool OMMDModel::Write(GeListNode* node, HyperFile* hf) {
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
		mesh_root_link->SetLink(this->m_MeshRoot_ptr);
		rigid_root_link->SetLink(this->m_RigidRoot_ptr);
		joint_root_link->SetLink(this->m_JointRoot_ptr);
		bone_root_link->SetLink(this->m_BoneRoot_ptr);
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
	Bool OMMDModel::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
	{
		OMMDModel* const destObject = static_cast<OMMDModel*>(dest);
		destObject->m_BoneRoot_ptr = this->m_BoneRoot_ptr;
		destObject->m_JointRoot_ptr = this->m_JointRoot_ptr;
		destObject->m_RigidRoot_ptr = this->m_RigidRoot_ptr;
		destObject->m_MeshRoot_ptr = this->m_MeshRoot_ptr;
		return(true);
	}
	Bool OMMDModel::UpdataRoot(BaseObject* op)
	{
		if (op == nullptr)
			op = static_cast<BaseObject*>(Get());
		BaseObject* MeshRoot_ = nullptr;
		BaseObject* BoneRoot_ = nullptr;
		BaseObject* RigidRoot_ = nullptr;
		BaseObject* JointRoot_ = nullptr;
		maxon::Queue<BaseObject*>	nodes;
		iferr(nodes.Push(op->GetDown())) return false;
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
				iferr(nodes.Push(node->GetNext())) return false;
			}
		}
		nodes.Reset();
		if (m_JointRoot_ptr == nullptr) {
			if (JointRoot_ == nullptr)
			{
				BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
				tmp->InsertUnder(op);
				this->m_JointRoot_ptr = tmp;
			}
			else {
				this->m_JointRoot_ptr = JointRoot_;
			}
			m_initializ = false;
		}
		if (m_RigidRoot_ptr == nullptr) {
			if (RigidRoot_ == nullptr)
			{
				BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
				tmp->InsertUnder(op);
				this->m_RigidRoot_ptr = tmp;
			}
			else {
				this->m_RigidRoot_ptr = RigidRoot_;
			}
			m_initializ = false;
		}
		if (m_BoneRoot_ptr == nullptr) {
			if (BoneRoot_ == nullptr)
			{
				BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
				tmp->InsertUnder(op);
				this->m_BoneRoot_ptr = tmp;
			}
			else {
				this->m_BoneRoot_ptr = BoneRoot_;
			}
			m_initializ = false;
		}
		if (m_MeshRoot_ptr == nullptr) {
			if (MeshRoot_ == nullptr)
			{
				BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
				tmp->InsertUnder(op);
				this->m_MeshRoot_ptr = tmp;
			}
			else {
				this->m_MeshRoot_ptr = MeshRoot_;
			}
			m_initializ = false;
		}
		if (m_initializ == false) {
			this->m_MeshRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::Model, op });
			this->m_BoneRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::RigidRoot, this->m_RigidRoot_ptr });
			this->m_BoneRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::JointRoot, this->m_JointRoot_ptr });
			this->m_BoneRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::Model, op });
			this->m_RigidRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::BoneRoot, this->m_BoneRoot_ptr });
			this->m_RigidRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::JointRoot, this->m_JointRoot_ptr });
			this->m_JointRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::BoneRoot, this->m_BoneRoot_ptr });
			this->m_JointRoot_ptr->Message(ID_O_MMD_MODEL, &OMMDModel_MSG{
				OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::RigidRoot, this->m_RigidRoot_ptr });
			m_initializ = true;
		}
		return true;
	}
	EXECUTIONRESULT OMMDModel::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
	{
		if (op == nullptr || doc == nullptr)
		{
			return(EXECUTIONRESULT::OK);
		}
		if (UpdataRoot(op) == false)
			return(EXECUTIONRESULT::OK);
		return(EXECUTIONRESULT::OK);
	}
	Bool OMMDModel::CreateRoot()
	{
		BaseObject* op = static_cast<BaseObject*>(Get());
		const BaseDocument* doc = GetActiveDocument();
		if (op != nullptr && doc != nullptr)
		{
			if (this->m_JointRoot_ptr == nullptr)
			{
				BaseObject* joint_root_object = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
				joint_root_object->InsertUnder(op);
				this->m_JointRoot_ptr = joint_root_object;
			}
			if (this->m_RigidRoot_ptr == nullptr)
			{
				BaseObject* rigid_root_object = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
				rigid_root_object->InsertUnder(op);
				this->m_RigidRoot_ptr = rigid_root_object;
			}
			if (this->m_BoneRoot_ptr == nullptr)
			{
				BaseObject* bone_root_object = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
				bone_root_object->InsertUnder(op);
				this->m_BoneRoot_ptr = bone_root_object;
			}
			if (this->m_MeshRoot_ptr == nullptr)
			{
				BaseObject* mesh_root_object = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
				mesh_root_object->InsertUnder(op);
				this->m_MeshRoot_ptr = mesh_root_object;
			}
			return(true);
		}
		return(false);
	}
	Bool OMMDModel::AddToExecution(BaseObject* op, PriorityList* list)
	{
		if (list == nullptr || op == nullptr)
		{
			return(true);
		}
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
		return(true);
	}
	Bool OMMDModel::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
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
	Bool OMMDModel::Message(GeListNode* node, Int32 type, void* data)
	{
		switch (type)
		{
		case ID_O_MMD_MESH_ROOT:
		{
			OMMDMeshRoot_MSG* msg = static_cast<OMMDMeshRoot_MSG*>(data);
			if (msg->type == OMMDMeshRoot_MSG_Type::MESH_MORPH_CHANGE) {

			}
			break;
		}
		case ID_O_MMD_BONE_ROOT:
		{
			OMMDBoneRoot_MSG* msg = static_cast<OMMDBoneRoot_MSG*>(data);
			if (msg->type == OMMDBoneRoot_MSG_Type::BONE_MORPH_CHANGE) {

			}
			break;
		}
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
									TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
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
									TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
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
									TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
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
}