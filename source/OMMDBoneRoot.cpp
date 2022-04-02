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
		if (level >= 1) {
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
			this->m_IndexToBone_map.Reset();
			this->m_BoneToIndex_map.Reset();
			Int32 index = 0;
			for (Int64 i = 0; i < bone_map_count; i++)
			{
				if (!hf->ReadInt32(&index))
					return(false);
				AutoAlloc<BaseLink> tmp;
				if (!tmp->Read(hf))
					return(false);
				iferr(this->m_IndexToBone_map.Insert(index, static_cast<BaseObject*>(tmp->ForceGetLink())))
					return(false);
				iferr(this->m_BoneToIndex_map.Insert(static_cast<BaseObject*>(tmp->ForceGetLink()), index))
					return(false);
			}
		}
		if (level >= 2) {
			AutoAlloc<BaseLink> Model_link;
			if (!Model_link->Read(hf))
				return(false);
			if (Model_link == nullptr)
				return false;
			this->m_Model_ptr = static_cast<BaseObject*>(Model_link->ForceGetLink());
			Int64 data_countA = 0;
			if (!hf->ReadInt64(&data_countA))
				return false;
			for (Int64 i = 0; i < data_countA;++i)
			{
				String name;
				if (!hf->ReadString(&name))
					return false;
				auto& data = m_MorphData_map.InsertKey(std::move(name)).GetValue();
				Int64 data_countB = 0;
				if (!hf->ReadInt64(&data_countB))
					return false;
				for (Int64 j = 0; j < data_countB; ++j)
				{
					bone_morph_hub_data& bone_morph_data = data.Append().GetValue();
					if (!bone_morph_data.Read(hf))
						return false;		
				}
			}
		}
		return true;
	}
	Bool OMMDBoneRoot::Write(GeListNode* node, HyperFile* hf)
	{
		//level >= 1
		AutoAlloc<BaseLink> rigid_root_link;
		if (rigid_root_link == nullptr)
			return false;
		rigid_root_link->SetLink(this->m_RigidRoot_ptr);
		if (!rigid_root_link->Write(hf))
			return false;
		AutoAlloc<BaseLink> joint_root_link;
		if (joint_root_link == nullptr)
			return false;
		joint_root_link->SetLink(this->m_JointRoot_ptr);
		if (!joint_root_link->Write(hf))
			return false;
		if (!hf->WriteInt64(this->m_IndexToBone_map.GetCount()))
			return false;
		for (auto& i : this->m_IndexToBone_map)
		{
			AutoAlloc<BaseLink> tmp;
			if (tmp == nullptr)
				return false;
			tmp->SetLink(i.GetValue());
			if (!hf->WriteInt32(i.GetKey()))
				return false;
			if (!tmp->Write(hf))
				return false;
		}
		//level >= 2
		AutoAlloc<BaseLink> Model_link;
		if (Model_link == nullptr)
			return false;
		Model_link->SetLink(this->m_Model_ptr);
		if (!Model_link->Write(hf))
			return false;
		if (!hf->WriteInt64(this->m_MorphData_map.GetCount()))
			return false;
		for (auto& i : m_MorphData_map)
		{
			if (!hf->WriteString(i.GetKey()))
				return false;
			auto& data = i.GetValue();
			if (!hf->WriteInt64(data.GetCount()))
				return false;
			for (auto& j : data)
			{
				if (!j.Write(hf))
					return false;
			}
		}
		return true;
	}
	Bool OMMDBoneRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
	{
		OMMDBoneRoot* const dest_object = static_cast<OMMDBoneRoot*>(dest);
		dest_object->m_RigidRoot_ptr = m_RigidRoot_ptr;
		dest_object->m_JointRoot_ptr = m_JointRoot_ptr;
		dest_object->m_IndexToBone_map.Reset();
		dest_object->m_BoneToIndex_map.Reset();
		for (auto& i : m_IndexToBone_map)
		{
			iferr(dest_object->m_IndexToBone_map.Insert(i.GetKey(), i.GetValue()))
				return(false);
			iferr(dest_object->m_BoneToIndex_map.Insert(i.GetValue(), i.GetKey()))
				return(false);
		}
		for (auto& i : m_MorphData_map)
		{
			iferr(dest_object->m_MorphData_map.InsertKey(i.GetKey()).GetValue().CopyFrom(i.GetValue()))
				return(false);			
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
			this->m_bone_items.FlushAll();
			this->m_bone_items.SetString(-1, "-"_s);
			this->m_IndexToBone_map.Reset();
			this->m_BoneToIndex_map.Reset();
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
							this->m_bone_items.SetString(bone_index, node_->GetName());
							this->m_IndexToBone_map.Insert(bone_index, node_)iferr_return;
							this->m_BoneToIndex_map.Insert(node_, bone_index)iferr_return;
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
		maxon::HashSet<String> morph_name_list;
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
							String& morph_name = morph->name;
							morph_name_list.Insert(morph_name)iferr_return;
							maxon::BaseList<bone_morph_hub_data>* bone_morph_list = nullptr;
							auto bone_morph_map_ptr = m_MorphData_map.Find(morph_name);
							if (bone_morph_map_ptr != nullptr)
							{
								bone_morph_list = &bone_morph_map_ptr->GetValue();
								for (auto& morph_data : *bone_morph_list) {
									if (morph_data.strength_id == morph->strength_id)
										goto NEXT_MORPH;
								}
							}
							else {
								bone_morph_list = &m_MorphData_map.InsertEntry(morph_name).GetValue().GetValue();
							}
							auto& morph_data = bone_morph_list->Append()iferr_return;
							morph_data.bone_tag = node_morph_tag;
							morph_data.strength_id = morph->strength_id;
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
		// 去除已经删除的表情
		for (auto name_it = m_MorphData_map.GetKeys().begin(); name_it != m_MorphData_map.GetKeys().end(); ++name_it) {
			auto& name = *name_it;
			if (morph_name_list.Find(name) == nullptr) {
				m_MorphData_map.Erase(name)iferr_return;
				need_update_morph = true;
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