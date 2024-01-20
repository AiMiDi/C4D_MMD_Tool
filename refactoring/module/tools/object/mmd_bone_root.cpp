/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone_root.h"

NodeData* MMDBoneRootObject::Alloc()
{
	return NewObjClear(MMDBoneRootObject);
}

Bool MMDBoneRootObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDBoneRootObject*>(dest);
	dest_object->bone_name_index = bone_name_index;
	dest_object->m_rigid_root = m_rigid_root;
	dest_object->m_joint_root = m_joint_root;
	for (const auto& entry : m_bone_list)
	{
		auto& link = dest_object->m_bone_list.InsertKey(entry.GetKey())iferr_return;
		link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
		(*entry.GetValue())->CopyTo(*link, flags, trn);
	}
	for (const auto & entry : m_bone_morph_data)
	{
		dest_object->m_bone_morph_data.Insert(entry.GetKey(), entry.GetValue())iferr_return;
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDBoneRootObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	if (!hf->ReadInt64(&bone_name_index))
		return false;
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		if (!temp_link->Read(hf))
			return false;
		m_model_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_rigid_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_joint_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
	}
	// m_bone_list
	{
		Int64 bone_list_count = 0;
		if (!hf->ReadInt64(&bone_list_count))
			return false;
		while (bone_list_count--)
		{
			Int32 bone_index = 0;
			if (!hf->ReadInt32(&bone_index))
				return false;
			auto& link = m_bone_list.InsertKey(bone_index)iferr_return;
			link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
			if (!(*link)->Read(hf))
				return false;
		}
	}
	// m_bone_morph_data
	{
		Int bone_morph_data_count = 0;
		if (!hf->ReadInt64(&bone_morph_data_count))
			return false;
		while (bone_morph_data_count--)
		{
			String bone_morph_name;
			if (!hf->ReadString(&bone_morph_name))
				return false;
			auto& bone_morph_ui_data_list = m_bone_morph_data.InsertKey(bone_morph_name)iferr_return;
			Int bone_morph_ui_data_list_count = 0;
			if (!hf->ReadInt64(&bone_morph_ui_data_list_count))
				return false;
			while (bone_morph_ui_data_list_count--)
			{
				auto& bone_morph_ui_data = bone_morph_ui_data_list.Append()iferr_return;
				if(!bone_morph_ui_data.Read(hf))
					return false;
			}
		}
	}
	return SUPER::Read(node, hf, level);
}

Bool MMDBoneRootObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	if(!hf->WriteInt64(bone_name_index))
		return false;
	{
		AutoAlloc<BaseLink> temp_link;
		if(!temp_link)
			return false;
		temp_link->SetLink(m_model_root);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_rigid_root);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_joint_root);
		if (!temp_link->Write(hf))
			return false;
	}
	// m_bone_list
	{
		if (!hf->WriteInt64(m_bone_list.GetCount()))
			return false;
		for (const auto& bone_link : m_bone_list)
		{
			if (hf->WriteInt32(!bone_link.GetKey()))
				return false;
			if (!(*bone_link.GetValue())->Write(hf))
				return false;
		}
	}
	// m_bone_morph_data
	{
		if (!hf->WriteInt64(m_bone_morph_data.GetCount()))
			return false;
		for (SDK2024_Const auto& entry : m_bone_morph_data)
		{
			if (!hf->WriteString(entry.GetFirst()))
				return false;
			SDK2024_Const auto& bone_morph_ui_data_list = entry.GetSecond();
			if (!hf->WriteInt64(bone_morph_ui_data_list.GetCount()))
				return false;
			for (SDK2024_Const auto & bone_morph_ui_data : bone_morph_ui_data_list)
			{
				if (!bone_morph_ui_data.Write(hf))
					return false;
			}
		}
	}
	return SUPER::Write(node, hf);
}

Bool MMDBoneRootObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	const auto op = reinterpret_cast<BaseObject*>(node);
	if (id[0].id == BONE_DISPLAY_TYPE)
	{
		switch (t_data.GetInt32())
		{
		case BONE_DISPLAY_TYPE_ON:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneRootObjectMsg msg { MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ON };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_MOVABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_MOVABLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_VISIBLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_VISIBLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ROTATABLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ENABLED:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ENABLED };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_IK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_IK };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, &msg);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

void MMDBoneRootObject::HandleDescriptionCommandMessage(GeListNode* node, void* data)
{
	if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_BONE_BUTTON)
	{
		if (BaseObject* new_bone = BaseObject::Alloc(Ojoint); new_bone != nullptr)
		{
			const auto bone_node = new_bone->MakeTag(ID_T_MMD_BONE)->GetNodeData<MMDBoneTag>();
			new_bone->SetName(new_bone->GetName() + "." + String::IntToString(bone_name_index++));
			bone_node->SetBoneObject(new_bone);
			bone_node->SetBoneRoot(reinterpret_cast<BaseObject*>(node));
			bone_node->RefreshColor();
			new_bone->InsertUnder(node);
		}
	}
}

bool MMDBoneRootObject::HandleMMDBoneTagMessage(GeListNode* node, void* data)
{
	iferr_scope_handler{
		return false;
	};
	Bool need_update_morph = false;
	switch (static_cast<MMDBoneTagMsg*>(data)->type)
	{
	case MMDBoneTagMsgType::BONE_INDEX_CHANGE:
		{
			HandleBoneIndexChangeMessage(node, data, need_update_morph);
			break;
		}
	case MMDBoneTagMsgType::BONE_MORPH_ADD:
		{
			HandleBoneMorphAdd(node, data, need_update_morph);
			break;
		}
	case MMDBoneTagMsgType::BONE_MORPH_DELETE:
		{
			HandleBoneMorphDelete(node, data, need_update_morph);
			break;
		}
	case MMDBoneTagMsgType::BONE_MORPH_RENAME:
		{
			HandleBoneMorphRename(node, data, need_update_morph);
			break;
		}
	case MMDBoneTagMsgType::DEFAULT: 
		break;
	}
	if (need_update_morph && m_model_root)
	{
		MMDBoneRootObjectMsg msg{ MMDBoneRootObjectMsgType::BONE_MORPH_CHANGE };
		m_model_root->Message(ID_O_MMD_BONE_ROOT, &msg);
	}
	return true;
}

bool MMDBoneRootObject::HandleBoneIndexChangeMessage(GeListNode* node, void* data, bool& need_update_morph)
{
	iferr_scope_handler{
		return false;
	};
	const auto op = reinterpret_cast<BaseObject*>(node);
	m_bone_items.FlushAll();
	m_bone_items.SetString(-1, "-"_s);
	m_bone_list.Reset();
	maxon::Queue<BaseObject*> nodes;
	iferr(nodes.Push(op)) return true;
	while (!nodes.IsEmpty())
	{
		BaseObject* node_ = *nodes.Pop();
		while (node_)
		{
			if (node_->GetType() == Ojoint)
			{
				if (SDK2024_Const BaseTag* node_bone_tag = node_->GetTag(ID_T_MMD_BONE); node_bone_tag != nullptr)
				{
					GeData ge_data;
					node_bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), ge_data, DESCFLAGS_GET::NONE);
					const auto bone_index = node_bone_tag->GetNodeData<MMDBoneTag>()->GetBoneIndex();
					m_bone_items.SetString(bone_index, node_->GetName());
					auto& link = m_bone_list.InsertKey(bone_index)iferr_return;
					link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
					(*link)->SetLink(node_bone_tag);
				}
			}
			iferr(nodes.Push(node_->GetDown()))
				return true;
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
	return true;
}

bool MMDBoneRootObject::HandleBoneMorphAdd(GeListNode* node, void* data, bool& need_update_morph)
{
	iferr_scope_handler{
		return false;
	};
	maxon::BaseList<MorphUIData>* bone_morph_list;
	const auto msg = static_cast<MMDBoneTagBoneMorphAddMsg*>(data);
	bool isExit = false;
	if (const auto bone_morph_map_ptr = m_bone_morph_data.Find(msg->name); bone_morph_map_ptr != nullptr)
	{
		bone_morph_list = &bone_morph_map_ptr->GetValue();
		for (auto& morph_hub_data : *bone_morph_list) {
			if (morph_hub_data.Compare(msg->bone_morph_UI_data) ) {
				isExit = true;
				break;
			}
		}
	}
	else {
		bone_morph_list = &m_bone_morph_data.InsertEntry(msg->name).GetValue().GetValue();
	}
	if (!isExit) {
		bone_morph_list->Append(msg->bone_morph_UI_data)iferr_return;
		need_update_morph = true;
	}
	return true;
}

bool MMDBoneRootObject::HandleBoneMorphDelete(GeListNode* node, void* data, bool& need_update_morph)
{
	iferr_scope_handler{
		return false;
	};
	const auto msg = static_cast<MMDBoneTagBoneMorphDeleteMsg*>(data);
	if (auto* bone_morph_map_ptr = m_bone_morph_data.Find(msg->name);
		bone_morph_map_ptr)
	{
		maxon::BaseList<MorphUIData>& bone_morph_list = bone_morph_map_ptr->GetValue();
		for (auto morph_hub_data_it = bone_morph_list.Begin(); morph_hub_data_it != bone_morph_list.End(); ++morph_hub_data_it)
		{
			if (morph_hub_data_it->Compare(msg->bone_morph_UI_data))
			{
				morph_hub_data_it = bone_morph_list.Erase(morph_hub_data_it);
				need_update_morph = true;
				break;
			}
		}
		if (bone_morph_list.IsEmpty())
		{
			m_bone_morph_data.Erase(msg->name)iferr_return;
		}
	}
	return true;
}

bool MMDBoneRootObject::HandleBoneMorphRename(GeListNode* node, void* data, bool& need_update_morph)
{
	iferr_scope_handler{
		return false;
	};
	const auto msg = static_cast<MMDBoneTagBoneMorphRenameMsg*>(data);
	if (auto* old_bone_morph_map_ptr = m_bone_morph_data.Find(msg->old_name);
		old_bone_morph_map_ptr)
	{
		maxon::BaseList<MorphUIData>& old_bone_morph_list = old_bone_morph_map_ptr->GetValue();
		bool isExit = false;
		for (auto morph_hub_data_it = old_bone_morph_list.Begin(); morph_hub_data_it != old_bone_morph_list.End(); ++morph_hub_data_it) {
			if (auto& morph_hub_data = *morph_hub_data_it; morph_hub_data.Compare(msg->bone_morph_UI_data))
			{
				maxon::BaseList<MorphUIData>* new_bone_morph_list;
				if (auto* new_bone_morph_map_ptr = m_bone_morph_data.Find(msg->new_name))
				{
					new_bone_morph_list = &new_bone_morph_map_ptr->GetValue();
					for (auto& new_morph_data : *new_bone_morph_list) {
						if (new_morph_data.Compare(msg->bone_morph_UI_data)) {
							isExit = true;
							break;
						}
					}
				}
				else {
					new_bone_morph_list = &m_bone_morph_data.InsertEntry(msg->new_name).GetValue().GetValue();
				}
				if (!isExit) {
					new_bone_morph_list->Append(std::move(*morph_hub_data_it))iferr_return;
					morph_hub_data_it = old_bone_morph_list.Erase(morph_hub_data_it);
					need_update_morph = true;
					break;
				}
			}
		}
		if (old_bone_morph_list.IsEmpty())
		{
			m_bone_morph_data.Erase(msg->old_name)iferr_return;
		}
	}
	return true;
}

Bool MMDBoneRootObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return SUPER::Message(node, type, data);
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		HandleDescriptionCommandMessage(node, data);
		break;
	}
	case ID_T_MMD_BONE:
	{
		if (!HandleMMDBoneTagMessage(node, data))
			return SUPER::Message(node, type, data);
		break;
	}
	default: ;
	}
	return SUPER::Message(node, type, data);
}

const maxon::HashMap<String, maxon::BaseList<MorphUIData>>& MMDBoneRootObject::GetBoneMorphData() const
{
	return m_bone_morph_data;
}

BaseList2D* MMDBoneRootObject::FindBone(const Int32 index) const
{
	// find index in m_bone_list
	if (const auto bone_link_ptr = m_bone_list.Find(index); bone_link_ptr)
	{
		return (*bone_link_ptr->GetValue())->ForceGetLink();
	}
	return nullptr;
}

Int32 MMDBoneRootObject::FindBoneIndex(const BaseList2D* bone_tag) const
{
	// get index from bone
	const auto bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
	if(!bone_tag_node)
	{
		return -1;
	}
	const Int32 bone_index = bone_tag_node->GetBoneIndex();
	// find index in m_bone_list
	if(!m_bone_list.Contains(bone_index))
	{
		return -1;
	}
	return bone_index;
}

Bool MMDBoneRootObject::SetBoneMorphStrength(const String& morph_name, const Float strength)
{
	const auto morph_ptr = m_bone_morph_data.Find(morph_name);
	if (!morph_ptr)
	{
		return false;
	}
	for (auto& bone_morph_ui_data : morph_ptr->GetSecond())
	{
		if(const auto bone_tag = bone_morph_ui_data.GetMorphTag(); bone_tag)
		{
			if(!bone_tag->SetParameter(bone_morph_ui_data.GetStrengthID(), strength, DESCFLAGS_SET::NONE))
				return false;
		}
	}
	return true;
}

void MMDBoneRootObject::CreateDisplayTag(GeListNode* node)
{}
