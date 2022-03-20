#include "OMMDBoneRoot.h"
#include "description/TMMDBone.h"
#include "description/OMMDBoneRoot.h"

namespace tool {
	Bool OMMDBoneRoot::Init(GeListNode* node)
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
	Bool OMMDBoneRoot::Read(GeListNode* node, HyperFile* hf, Int32 level)
	{
		if (level == 1) {
			AutoAlloc<BaseLink> rigid_root_link;
			if (!rigid_root_link->Read(hf))
				return(false);
			if (rigid_root_link == nullptr)
				return false;
			this->m_RigidRoot_ptr = static_cast<BaseObject*>(rigid_root_link->ForceGetLink());
			AutoAlloc<BaseLink> joint_root_link;
			if (joint_root_link == nullptr)
				return false;
			if (!joint_root_link->Read(hf))
				return(false);
			this->m_JointRoot_ptr = static_cast<BaseObject*>(joint_root_link->ForceGetLink());
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
				iferr(this->IndexToBoneMap.Insert(index, static_cast<BaseObject*>(tmp->ForceGetLink())))
					return(false);
				iferr(this->BoneToIndexMap.Insert(static_cast<BaseObject*>(tmp->ForceGetLink()), index))
					return(false);
			}
		}
		return true;
	}
	Bool OMMDBoneRoot::Write(GeListNode* node, HyperFile* hf)
	{
		AutoAlloc<BaseLink> rigid_root_link;
		if (rigid_root_link == nullptr)
			return false;
		rigid_root_link->SetLink(this->m_RigidRoot_ptr);
		if (!rigid_root_link->Write(hf))
			return(false);
		AutoAlloc<BaseLink> joint_root_link;
		if (joint_root_link == nullptr)
			return false;
		joint_root_link->SetLink(this->m_JointRoot_ptr);
		if (!joint_root_link->Write(hf))
			return(false);
		if (!hf->WriteInt64(this->IndexToBoneMap.GetCount()))
			return(false);
		for (auto& i : this->IndexToBoneMap.GetKeys())
		{
			AutoAlloc<BaseLink> tmp;
			if (tmp == nullptr)
				return false;
			tmp->SetLink(IndexToBoneMap.Find(i)->GetValue());
			if (!hf->WriteInt32(i))
				return(false);
			if (!tmp->Write(hf))
				return(false);
		}
		return true;
	}
	Bool OMMDBoneRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
	{
		OMMDBoneRoot* const destObject = static_cast<OMMDBoneRoot*>(dest);
		destObject->m_RigidRoot_ptr = this->m_RigidRoot_ptr;
		destObject->m_JointRoot_ptr = this->m_JointRoot_ptr;
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
	Bool OMMDBoneRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
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
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ON).GetValue());
				break;
			}
			case BONE_DISPLAY_TYPE_OFF:
			{
				op->SetEditorMode(MODE_OFF);
				op->SetRenderMode(MODE_OFF);
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF).GetValue());
				break;
			}
			case BONE_DISPLAY_TYPE_MOVABLE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_MOVABLE).GetValue());
				break;
			}
			case BONE_DISPLAY_TYPE_VISIBLE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_VISIBLE).GetValue());
				break;
			}
			case BONE_DISPLAY_TYPE_ROTATABLE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ROTATABLE).GetValue());
				break;
			}
			case BONE_DISPLAY_TYPE_ENABLED:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ENABLED).GetValue());
				break;
			}
			case BONE_DISPLAY_TYPE_IK:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_IK).GetValue());
				break;
			}
			default:
				break;
			}
		}
		return(SUPER::SetDParameter(node, id, t_data, flags));
	}
	Bool OMMDBoneRoot::Message(GeListNode* node, Int32 type, void* data)
	{
		iferr_scope_handler{
			return SUPER::Message(node, type, data);
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
				if (msg->msg_type == OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA) {
					switch (msg->object_type)
					{
					case ToolObjectType::JointRoot:
					{
						this->m_JointRoot_ptr = msg->object;
						break;
					}
					case ToolObjectType::RigidRoot:
					{
						this->m_RigidRoot_ptr = msg->object;
						break;
					}
					case ToolObjectType::Model:
					{
						this->m_Model_ptr = msg->object;
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
		return SUPER::Message(node, type, data);
	}
	EXECUTIONRESULT OMMDBoneRoot::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
	{
		iferr_scope_handler{ return EXECUTIONRESULT::OK; };
		Bool need_update_morph = false;
		maxon::Queue<BaseObject*> nodes;
		nodes.Push(op)iferr_return;
		while (!nodes.IsEmpty())
		{
			BaseObject* node = *(nodes.Pop());
			while (node != nullptr)
			{
				if (node->GetType() == Ojoint)
				{
					BaseTag* const node_morph_tag = node->GetTag(ID_T_MMD_BONE);
					if (node_morph_tag != nullptr)
					{
						TMMDBone* bone_tag_data = node_morph_tag->GetNodeData<TMMDBone>();
						const Int morph_count = bone_tag_data->GetMorphCount();
						for (Int32 index = 0; index < morph_count; index++)
						{
							auto* morph = bone_tag_data->GetMorph(index);
							String morph_name = morph->name;
							auto bone_morph_map_ptr = m_bone_morph_map.Find(morph_name);
							while (bone_morph_map_ptr != nullptr)
							{
								if (bone_morph_map_ptr->GetValue().data == morph)
									goto NEXT_MORPH;
								bone_morph_map_ptr = bone_morph_map_ptr->GetNextWithSameKey();
							}
							auto& morph_data = m_bone_morph_map.InsertMultiEntry(morph_name).GetValue().GetValue();
							morph_data.bone_tag = node_morph_tag;
							morph_data.data = morph;
							need_update_morph = true;
						NEXT_MORPH:
							continue;
						}
					}
				}
				nodes.Push(node->GetDown()) iferr_return;
				if (node != op)
				{
					node = node->GetNext();
				}
				else {
					break;
				}
			}
		}
		if (need_update_morph == true) {
			if (m_Model_ptr != nullptr) {
				m_Model_ptr->Message(ID_O_MMD_BONE_ROOT, NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::BONE_MORPH_CHANGE).GetValue());
			}
		}
		return EXECUTIONRESULT::OK;
	}
	Bool OMMDBoneRoot::AddToExecution(BaseObject* op, PriorityList* list)
	{
		if (list == nullptr || op == nullptr)
		{
			return(true);
		}
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
		return(true);
	}
}