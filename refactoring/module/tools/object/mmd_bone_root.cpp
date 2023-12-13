/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone_root.h"

Bool MMDBoneRootObject::Init(GeListNode* node SDK2024_InitPara)
{
	if(!node)
		return true;
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if(!m_protection_tag)
	{
		m_protection_tag = reinterpret_cast<BaseObject*>(node)->MakeTag(Tprotection);
		m_protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		m_protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
	}
	return true;
}

Bool MMDBoneRootObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
{
	auto const dest_object = reinterpret_cast<MMDBoneRootObject*>(dest);
	dest_object->m_rigid_root = m_rigid_root;
	dest_object->m_joint_root = m_joint_root;
	for (const auto& bone_link: m_bone_list)
	{
		if(!dest_object->m_bone_list.Append(bone_link->ForceGetLink()))
			return false;
	}
	for (const auto & entry : m_bone_morph_data)
	{
		iferr(dest_object->m_bone_morph_data.Insert(entry.GetKey(), entry.GetValue()))
			return false;
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
	if (!temp_link->Read(hf))
		return false;
	m_protection_tag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
	// m_bone_list
	{
		Int32 bone_list_count = 0;
		if (!hf->ReadInt32(&bone_list_count))
			return false;
		while (bone_list_count--)
		{
			if (!temp_link->Read(hf))
				return false;
			if (!m_bone_list.Append(temp_link->ForceGetLink()))
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
	temp_link->SetLink(m_protection_tag);
	if (!temp_link->Write(hf))
		return false;
	// m_bone_list
	{
		if (!hf->WriteInt32(m_bone_list.GetCount()))
			return false;
		for (const auto& bone_link : m_bone_list)
		{
			if (!bone_link->Write(hf))
				return false;
		}
	}
	// m_bone_morph_data
	{
		if (!hf->WriteInt64(m_bone_morph_data.GetCount()))
			return false;
		for (const auto& entry : m_bone_morph_data)
		{
			if (!hf->WriteString(entry.GetFirst()))
				return false;
			const auto& bone_morph_ui_data_list = entry.GetSecond();
			if (!hf->WriteInt64(bone_morph_ui_data_list.GetCount()))
				return false;
			for (const auto & bone_morph_ui_data : bone_morph_ui_data_list)
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
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ON).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		case BONE_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		case BONE_DISPLAY_TYPE_MOVABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_MOVABLE).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		case BONE_DISPLAY_TYPE_VISIBLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_VISIBLE).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ROTATABLE).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ENABLED:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_ENABLED).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		case BONE_DISPLAY_TYPE_IK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			const maxon::StrongRef<MMDBoneRootObjectMSG> bone_root_msg(
				NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::SET_BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_IK).GetValue());
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, bone_root_msg);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
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
		break;
	}
	case ID_T_MMD_BONE:
	{
		const auto msg = static_cast<MMDBoneTagMsg*>(data);
		Bool need_update_morph = false;

		switch (msg->type)
		{
		case MMDBoneTagMsgType::BONE_INDEX_CHANGE:
		{
			const auto op = reinterpret_cast<BaseObject*>(node);
			m_bone_items.FlushAll();
			m_bone_items.SetString(-1, "-"_s);
			m_bone_list.FlushAll();
			maxon::Queue<BaseObject*> nodes;
			Int32 bone_index = 0;
			iferr(nodes.Push(op)) return(true);
			while (!nodes.IsEmpty())
			{
				BaseObject* node_ = *nodes.Pop();
				while (node_ != nullptr)
				{
					if (node_->GetType() == Ojoint)
					{
						if (const BaseTag* node_bone_tag = node_->GetTag(ID_T_MMD_BONE); node_bone_tag != nullptr)
						{
							GeData ge_data;
							node_bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), ge_data, DESCFLAGS_GET::NONE);
							bone_index = ge_data.GetString().ToInt32(nullptr);
							m_bone_items.SetString(bone_index, node_->GetName());
							if (!m_bone_list.Append(node_bone_tag))
								return false;
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
		case MMDBoneTagMsgType::BONE_MORPH_ADD:
		{
			maxon::BaseList<BoneMorphUIData>* bone_morph_list;
			if (const auto bone_morph_map_ptr = m_bone_morph_data.Find(msg->name); bone_morph_map_ptr != nullptr)
			{
				bone_morph_list = &bone_morph_map_ptr->GetValue();
				for (auto& morph_hub_data : *bone_morph_list) {
					if (morph_hub_data == msg->bone_morph_UI_data)
						goto EXIT;
				}
			}
			else {
				bone_morph_list = &m_bone_morph_data.InsertEntry(msg->name).GetValue().GetValue();
			}
			bone_morph_list->Append(msg->bone_morph_UI_data)iferr_return;
			need_update_morph = true;
			break;
		}
		case MMDBoneTagMsgType::BONE_MORPH_DELETE:
		{
			if (auto* bone_morph_map_ptr = m_bone_morph_data.Find(msg->name);
				bone_morph_map_ptr)
			{
				maxon::BaseList<BoneMorphUIData>& bone_morph_list = bone_morph_map_ptr->GetValue();
				for (auto morph_hub_data_it = bone_morph_list.Begin(); morph_hub_data_it != bone_morph_list.End(); ++morph_hub_data_it) {
					if (*morph_hub_data_it == msg->bone_morph_UI_data)
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
			break;
		}
		case MMDBoneTagMsgType::BONE_MORPH_RENAME:
		{
			if (auto* old_bone_morph_map_ptr = m_bone_morph_data.Find(msg->name_old);
				old_bone_morph_map_ptr)
			{
				maxon::BaseList<BoneMorphUIData>& old_bone_morph_list = old_bone_morph_map_ptr->GetValue();
				for (auto morph_hub_data_it = old_bone_morph_list.Begin(); morph_hub_data_it != old_bone_morph_list.End(); ++morph_hub_data_it) {
					if (auto& morph_hub_data = *morph_hub_data_it; morph_hub_data == msg->bone_morph_UI_data)
					{
						maxon::BaseList<BoneMorphUIData>* new_bone_morph_list;
						if (auto* new_bone_morph_map_ptr = m_bone_morph_data.Find(msg->name))
						{
							new_bone_morph_list = &new_bone_morph_map_ptr->GetValue();
							for (auto& new_morph_data : *new_bone_morph_list) {
								if (new_morph_data == msg->bone_morph_UI_data)
									goto EXIT;
							}
						}
						else {
							new_bone_morph_list = &m_bone_morph_data.InsertEntry(msg->name).GetValue().GetValue();
						}
						new_bone_morph_list->Append(std::move(*morph_hub_data_it))iferr_return;
						morph_hub_data_it = old_bone_morph_list.Erase(morph_hub_data_it);
						need_update_morph = true;
						break;
					}
				}
				if (old_bone_morph_list.IsEmpty())
				{
					m_bone_morph_data.Erase(msg->name_old)iferr_return;
				}
			}
			break;
		}
		case MMDBoneTagMsgType::DEFAULT: 
		default:
			break;
		}
	EXIT:
		if (need_update_morph) {
			if (m_model_root) {
				const maxon::StrongRef<MMDBoneRootObjectMSG> Model_msg(
					NewObj(MMDBoneRootObjectMSG, MMDBoneRootObjectMSGType::BONE_MORPH_CHANGE).GetValue());
				m_model_root->Message(ID_O_MMD_BONE_ROOT, Model_msg);
			}
		}
		break;
	}
	default: ;
	}
	return SUPER::Message(node, type, data);
}

BaseList2D* MMDBoneRootObject::FindBone(const Int32 index, BaseDocument* doc) const
{
	return reinterpret_cast<BaseList2D*>(m_bone_list.GetIndex(index, doc));
}

Int32 MMDBoneRootObject::FindBoneIndex(const BaseList2D* bone_tag, const BaseDocument* doc) const
{
	return m_bone_list.Find(bone_tag, doc);
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
		if(const auto bone_tag = reinterpret_cast< BaseTag*>(bone_morph_ui_data.bone_tag_link->ForceGetLink()); bone_tag)
		{
			if(!bone_tag->SetParameter(bone_morph_ui_data.strength_id, strength, DESCFLAGS_SET::NONE))
				return false;
		}
	}
	return true;
}
