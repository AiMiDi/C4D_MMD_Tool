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
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ON).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				break;
			}
			case BONE_DISPLAY_TYPE_OFF:
			{
				op->SetEditorMode(MODE_OFF);
				op->SetRenderMode(MODE_OFF);
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				break;
			}
			case BONE_DISPLAY_TYPE_MOVABLE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_MOVABLE).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				break;
			}
			case BONE_DISPLAY_TYPE_VISIBLE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_VISIBLE).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				break;
			}
			case BONE_DISPLAY_TYPE_ROTATABLE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ROTATABLE).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				break;
			}
			case BONE_DISPLAY_TYPE_ENABLED:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ENABLED).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				break;
			}
			case BONE_DISPLAY_TYPE_IK:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(
					NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_IK).GetValue());
				node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
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
			TMMDBone_MSG* msg = static_cast<TMMDBone_MSG*>(data);
			Bool need_update_morph = false;

			switch (msg->type)
			{
			case TMMDBone_MSG_Type::BONE_INDEX_CHANGE:
			{
				BaseObject* op = static_cast<BaseObject*>(node);
				this->m_bone_items.FlushAll();
				this->m_bone_items.SetString(-1, "-"_s);
				this->m_IndexToBone_map.Reset();
				this->m_BoneToIndex_map.Reset();
				maxon::Queue<BaseObject*> nodes;
				GeData ge_data;
				Int32 bone_index = 0;
				iferr(nodes.Push(op)) return(true);
				while (!nodes.IsEmpty())
				{
					BaseObject* node_ = *(nodes.Pop());
					while (node_ != nullptr)
					{
						if (node_->GetType() == Ojoint)
						{
							BaseTag* node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
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
			case TMMDBone_MSG_Type::BONE_MORPH_ADD:
			{
				maxon::BaseList<bone_morph_hub_data>* bone_morph_list;
				if (const auto bone_morph_map_ptr = m_MorphData_map.Find(msg->name); bone_morph_map_ptr != nullptr)
				{
					bone_morph_list = &bone_morph_map_ptr->GetValue();
					for (auto& morph_hub_data : *bone_morph_list) {
						if (morph_hub_data == msg->morph_hub_data)
							goto EXIT;
					}
				}
				else {
					bone_morph_list = &m_MorphData_map.InsertEntry(msg->name).GetValue().GetValue();
				}
				bone_morph_list->Append(msg->morph_hub_data)iferr_return;
				need_update_morph = true;
				break;
			}
			case TMMDBone_MSG_Type::BONE_MORPH_DELETE:
			{
				auto* bone_morph_map_ptr = m_MorphData_map.Find(msg->name);
				if (bone_morph_map_ptr != nullptr)
				{
					maxon::BaseList<bone_morph_hub_data>& bone_morph_list = bone_morph_map_ptr->GetValue();
					for (auto morph_hub_data_it = bone_morph_list.Begin(); morph_hub_data_it != bone_morph_list.End(); ++morph_hub_data_it) {
						if (*morph_hub_data_it == msg->morph_hub_data)
						{
							morph_hub_data_it = bone_morph_list.Erase(morph_hub_data_it);
							need_update_morph = true;
							break;
						}
					}
					if (bone_morph_list.IsEmpty())
					{
						m_MorphData_map.Erase(msg->name)iferr_return;
					}
				}		
				break;
			}
			case TMMDBone_MSG_Type::BONE_MORPH_RENAME:
			{
				auto* old_bone_morph_map_ptr = m_MorphData_map.Find(msg->name_old);
				if (old_bone_morph_map_ptr != nullptr)
				{
					maxon::BaseList<bone_morph_hub_data>& old_bone_morph_list = old_bone_morph_map_ptr->GetValue();
					for (auto morph_hub_data_it = old_bone_morph_list.Begin(); morph_hub_data_it != old_bone_morph_list.End(); ++morph_hub_data_it) {
						auto& morph_hub_data = *morph_hub_data_it;
						if (morph_hub_data == msg->morph_hub_data)
						{
							maxon::BaseList<bone_morph_hub_data>* new_bone_morph_list;
							auto* new_bone_morph_map_ptr = m_MorphData_map.Find(msg->name);
							if (new_bone_morph_map_ptr != nullptr)
							{
								new_bone_morph_list = &new_bone_morph_map_ptr->GetValue();
								for (auto& new_morph_data : *new_bone_morph_list) {
									if (new_morph_data == msg->morph_hub_data)
										goto EXIT;
								}
							}
							else {
								new_bone_morph_list = &m_MorphData_map.InsertEntry(msg->name).GetValue().GetValue();
							}
							new_bone_morph_list->Append(std::move(*morph_hub_data_it))iferr_return;
							morph_hub_data_it = old_bone_morph_list.Erase(morph_hub_data_it);
							need_update_morph = true;
							break;
						}
					}
					if (old_bone_morph_list.IsEmpty()) 
					{
						m_MorphData_map.Erase(msg->name_old)iferr_return;
					}
				}
				break;
			}
			case TMMDBone_MSG_Type::DEFAULT: break;
			default:
				break;
			}
		EXIT:
			if (need_update_morph == true) {
				if (m_Model_ptr != nullptr) {
					const maxon::StrongRef<OMMDBoneRoot_MSG> Model_msg(
						NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::BONE_MORPH_CHANGE).GetValue());
					m_Model_ptr->Message(ID_O_MMD_BONE_ROOT, Model_msg);
				}
			}
			break;
		}
		case ID_O_MMD_MODEL:
		{
			if (const OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data); msg != nullptr)
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
}