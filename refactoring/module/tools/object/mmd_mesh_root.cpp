/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_mesh_root.h
Description:	MMD mesh root object

**************************************************************************/

#include "pch.h"
#include "mmd_mesh_root.h"

#include "mmd_model.h"
#include "tcaposemorph.h"
#include "description/OMMDMeshRoot.h"

NodeData* MMDMeshRootObject::Alloc()
{
	return NewObjClear(MMDMeshRootObject);
}

Bool MMDMeshRootObject::Init(GeListNode* node SDK2024_InitPara)
{
	if (!node)
		return false;
	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	if (!m_protection_tag)
	{
		m_protection_tag = reinterpret_cast<BaseObject*>(node)->MakeTag(Tprotection);
		m_protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		m_protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
	}
	if (!m_displayTag)
	{
		m_displayTag = reinterpret_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		m_displayTag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_AFFECT_DISPLAYMODE)), true, DESCFLAGS_SET::NONE);
		m_displayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		m_displayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
	}
	return SUPER::Init(node, isCloneInit);
}

Bool MMDMeshRootObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		if (!temp_link->Read(hf))
			return false;
		m_model_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_displayTag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_protection_tag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
	}

	// m_tag_mode_map
	{
		Int64 tag_mode_num = 0;
		if (!hf->ReadInt64(&tag_mode_num))
			return false;
		AutoAlloc<BaseLink> temp_link;
		for (Int64 index = 0; index < tag_mode_num; index++)
		{
			if (!temp_link->Read(hf))
				return false;
			auto tag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
			Int32 mode = 0;
			if (!hf->ReadInt32(&mode))
				return false;
			m_tag_mode_map.Insert(tag, mode)iferr_return;
		}
	}

	// m_mesh_morph_data
	{
		Int64 mesh_morph_data_num = 0;
		if (!hf->ReadInt64(&mesh_morph_data_num))
			return false;
		for (Int64 index = 0; index < mesh_morph_data_num; index++)
		{
			String morph_name;
			if (!hf->ReadString(&morph_name))
				return false;
			Int64 morph_count = 0;
			if (!hf->ReadInt64(&morph_count))
				return false;
			maxon::BaseList<MorphUIData>* morph_ui_data_list;
			if (const auto morph_ui_data_list_ptr = m_mesh_morph_data.Find(morph_name); morph_ui_data_list_ptr)
			{
				morph_ui_data_list = &morph_ui_data_list_ptr->GetValue();
			}
			else
			{
				morph_ui_data_list = &m_mesh_morph_data.InsertEntry(std::move(morph_name)).GetValue().GetValue();
			}
			for (Int64 morph_index = 0; morph_index < morph_count; morph_index++)
			{
				MorphUIData morph_ui_data;
				if (!morph_ui_data.Read(hf))
					return false;
				morph_ui_data_list->Append(std::move(morph_ui_data))iferr_return;
			}
		}
	}
	return SUPER::Read(node, hf, level);
}

Bool MMDMeshRootObject::Write(const GeListNode* node, HyperFile* hf) const
{
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		temp_link->SetLink(m_model_root);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_displayTag);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_protection_tag);
		if (!temp_link->Write(hf))
			return false;
	}
	// m_tag_mode_map
	{
		if (!hf->WriteInt64(m_tag_mode_map.GetCount()))
			return false;
		AutoAlloc<BaseLink> temp_link;
		for (const auto& entry : m_tag_mode_map)
		{
			temp_link->SetLink(entry.GetKey());
			if (!temp_link->Write(hf))
				return false;
			if (!hf->WriteInt32(entry.GetValue()))
				return false;
		}
	}
	// m_mesh_morph_data
	{
		if (!hf->WriteInt64(m_mesh_morph_data.GetCount()))
			return false;
		for (const auto& entry : m_mesh_morph_data)
		{
			if (!hf->WriteString(entry.GetKey()))
				return false;
			const auto& morph_ui_data_list = entry.GetValue();
			if (!hf->WriteInt64(morph_ui_data_list.GetCount()))
				return false;
			for (const auto& morph_ui_data : morph_ui_data_list)
			{
				if (!morph_ui_data.Write(hf))
					return false;
			}
		}
	}
	return SUPER::Write(node, hf);
}

Bool MMDMeshRootObject::CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDMeshRootObject*>(dest);
	dest_object->m_model_root = m_model_root;
	dest_object->m_displayTag = m_displayTag;
	dest_object->m_protection_tag = m_protection_tag;
	for (const auto& entry : m_tag_mode_map)
	{
		dest_object->m_tag_mode_map.Insert(entry.GetKey(), entry.GetValue())iferr_return;
	}
	for (const auto& entry : m_mesh_morph_data)
	{
		dest_object->m_mesh_morph_data.Insert(entry.GetKey(), entry.GetValue())iferr_return;
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDMeshRootObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	const auto op = reinterpret_cast<BaseObject*>(node);
	if (id[0].id == MESH_DISPLAY_TYPE && m_displayTag != nullptr)
	{
		const auto display_mode_DescID = ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE));
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
			m_displayTag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_ON_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_displayTag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_GOURAUD_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_displayTag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_QUICK, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_displayTag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_QUICK_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_HIDDENLINE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_displayTag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_HIDDENLINE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_displayTag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDMeshRootObject::Message(GeListNode* node, Int32 type, void* data)
{
	if(type == ID_O_MMD_MODEL)
	{
		if (const auto msg = static_cast<MMDModelObjectMsg*>(data); msg->msg_type == MMDModelObjectMsgType::TOOL_OBJECT_UPDATE)
		{
			m_model_root = msg->object;
		}
	}
	return SUPER::Message(node, type, data);
}

EXECUTIONRESULT MMDMeshRootObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
	EXECUTIONFLAGS flags)
{
	if (!m_model_root)
	{
		if (BaseObject* up_object = op->GetUp(); up_object->IsInstanceOf(ID_O_MMD_MODEL))
		{
			m_model_root = up_object;
		}
	}
	RefreshMeshMorphData(op);
	return SUPER::Execute(op, doc, bt, priority, flags);
}

Bool MMDMeshRootObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list && op)
	{
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION - 2, EXECUTIONFLAGS::NONE);
	}
	return SUPER::AddToExecution(op, list);
}

const maxon::HashMap<String, maxon::BaseList<MorphUIData>>& MMDMeshRootObject::GetMeshMorphData() const
{
	return m_mesh_morph_data;
}

Bool MMDMeshRootObject::SetMeshMorphStrength(const String& morph_name, Float strength)
{
	const auto morph_ptr = m_mesh_morph_data.Find(morph_name);
	if (!morph_ptr)
	{
		return false;
	}
	for (const auto& mesh_morph_ui_data : morph_ptr->GetSecond())
	{
		if (const auto mesh_morph_tag = mesh_morph_ui_data.GetMorphTag(); mesh_morph_tag)
		{
			if (!mesh_morph_tag->SetParameter(mesh_morph_ui_data.GetStrengthID(), strength, DESCFLAGS_SET::NONE))
				return false;
		}
	}
	return true;
}

void MMDMeshRootObject::RefreshMeshMorphData(BaseObject* op)
{
	iferr_scope_handler{};

	Bool need_update_morph = false;
	maxon::Queue<BaseObject*> nodes;
	maxon::HashSet<String> morph_name_list;
	nodes.Push(op)iferr_return;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *nodes.Pop();
		while (node)
		{
			if (node->IsInstanceOf(Opolygon))
			{
				if (const auto morph_tag = node->GetTag(Tposemorph); morph_tag)
				{
					const auto pose_morph_tag = reinterpret_cast<CAPoseMorphTag*>(morph_tag);
					const auto morph_mode = pose_morph_tag->GetMode();
					const auto morph_count = pose_morph_tag->GetMorphCount();
					for (Int32 morph_index = 1; morph_index < morph_count; morph_index++)
					{
						morph_name_list.Insert(pose_morph_tag->GetMorph(morph_index)->GetName())iferr_return;
					}
					bool is_no_update_mode = false;
					if (const auto morph_previous_model_ptr = m_tag_mode_map.Find(pose_morph_tag); morph_previous_model_ptr != nullptr)
					{
						if (morph_mode == morph_previous_model_ptr->GetValue() || morph_mode == ID_CA_POSE_MODE_EDIT)
						{
							morph_previous_model_ptr->SetValue(morph_mode);
							is_no_update_mode = true;
						}
						morph_previous_model_ptr->SetValue(morph_mode);
					}
					else
					{
						m_tag_mode_map.Insert(morph_tag, morph_mode)iferr_return;
					}
					if(!is_no_update_mode)
					{
						for (Int32 index = 1; index < morph_count; index++)
						{
							auto* morph = pose_morph_tag->GetMorph(index);
							String morph_name = morph->GetName();
							DescID morph_id = pose_morph_tag->GetMorphID(index);
							maxon::BaseList<MorphUIData>* mesh_morph_list;
							if (const auto mesh_morph_map_ptr = m_mesh_morph_data.Find(morph_name); mesh_morph_map_ptr)
							{
								mesh_morph_list = &mesh_morph_map_ptr->GetValue();
								bool is_find = false;
								for (auto& morph_data : *mesh_morph_list)
								{
									if (morph_data.GetMorphTag() == pose_morph_tag && morph_data.GetStrengthID() == morph_id)
										is_find = true;
								}
								if (is_find)
									continue;
							}
							else {
								mesh_morph_list = &m_mesh_morph_data.InsertEntry(morph_name).GetValue().GetValue();
							}
							mesh_morph_list->Append(pose_morph_tag, morph_id)iferr_return;
							need_update_morph = true;
						}
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
	// Remove deleted mesh morph
	if (m_mesh_morph_data.GetCount() > morph_name_list.GetCount())
	{
		for (auto it = maxon::Iterable::EraseIterator(m_mesh_morph_data); it; ++it)
		{
			if (!morph_name_list.Find(it->GetKey()))
			{
				it.Erase();
				need_update_morph = true;
			}
		}
	}
	if (need_update_morph == true) {
		if (m_model_root != nullptr) {
			MMDMeshRootObjectMsg msg{ MMDMeshRootObjectMsgType::MESH_MORPH_CHANGE };
			m_model_root->Message(ID_O_MMD_MESH_ROOT, &msg);
		}
	}
}
