/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone_root.h"

#include "cmt_tools_setting.h"
#include "description/OMMDModel.h"

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

Bool MMDBoneRootObject::LoadBones(const libmmd::pmx_model::pmx_bone_array& pmx_bone_array, const CMTToolsSetting::ModelImport& setting)
{
	iferr_scope_handler{
		return false;
	};

	// bone map
	maxon::HashMap<Int32, BaseObject*> bone_map;

	// create bone
	const auto  pmx_bone_num = static_cast<int>(pmx_bone_array.size());
	for (auto pmx_bone_index = int(); pmx_bone_index < pmx_bone_num; ++pmx_bone_index)
	{
		BaseObject* new_bone = BaseObject::Alloc(Ojoint);
		if (new_bone == nullptr)
			continue;

		bone_map.Insert(pmx_bone_index, new_bone)iferr_return;
	}

	// set bone data
	for (auto pmx_bone_index = int(); pmx_bone_index < pmx_bone_num; ++pmx_bone_index)
	{
		const auto& pmx_bone = pmx_bone_array[pmx_bone_index];

		if(!bone_map.Contains(pmx_bone_index))
			continue;

		const auto bone_object = bone_map.Find(pmx_bone_index)->GetValue();
		const auto bone_tag = bone_object->MakeTag(ID_T_MMD_BONE);
		const auto bone_node = bone_tag->GetNodeData<MMDBoneTag>();

		// init bone tag
		bone_node->SetBoneObject(bone_object);
		bone_node->SetBoneRoot(reinterpret_cast<BaseObject*>(this));

		// bone name
		const maxon::String bone_name_local{ pmx_bone.get_bone_name_local().c_str() };
		const maxon::String bone_name_universal{ pmx_bone.get_bone_name_universal().c_str() };
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_LOCAL)), bone_name_local, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_UNIVERSAL)), bone_name_universal, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_IS)), setting.import_english, DESCFLAGS_SET::NONE);

		// set bone position
		const auto& bone_position = pmx_bone.get_position();
		Vector position(bone_position[0], bone_position[1], bone_position[2]);
		position *= setting.position_multiple;
		bone_object->SetFrozenPos(position);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_POSITION)), position, DESCFLAGS_SET::NONE);

		// set parent bone
		if (const auto parent_bone_index = pmx_bone.get_parent_bone_index(); parent_bone_index == -1)
		{
			bone_object->InsertUnder(this->Get());
		}
		else
		{
			if (const auto parent_bone_ptr = bone_map.Find(parent_bone_index); parent_bone_ptr != nullptr)
			{
				bone_object->InsertUnder(parent_bone_ptr->GetValue());
			}
			else
			{
				bone_object->InsertUnder(this->Get());
			}
		}

		// set layer
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LAYER)), pmx_bone.get_layer(), DESCFLAGS_SET::NONE);

		// set rotatable
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_ROTATABLE)), pmx_bone.is_rotatable(), DESCFLAGS_SET::NONE);

		// set movable
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TRANSLATABLE)), pmx_bone.is_translatable(), DESCFLAGS_SET::NONE);

		// set visible
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_VISIBLE)), pmx_bone.is_visible(), DESCFLAGS_SET::NONE);

		// set enabled
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_ENABLED)), pmx_bone.is_enabled(), DESCFLAGS_SET::NONE);

		// set physics after deform
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PHYSICS_AFTER_DEFORM)), pmx_bone.is_physics_after_deform(), DESCFLAGS_SET::NONE);

		/// tail

		// set tail use index
		const auto is_tail_use_index = pmx_bone.is_tail_use_index();
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_IS_INDEX)), is_tail_use_index, DESCFLAGS_SET::NONE);

		if(is_tail_use_index)
		{
			// set tail index
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_INDEX)), pmx_bone.get_tail_index(), DESCFLAGS_SET::NONE);
		}
		else
		{
			// set tail position
			const auto& tail_position = pmx_bone.get_tail_position();
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_POSITION)), Vector(tail_position[0], tail_position[1], tail_position[2]) * setting.position_multiple, DESCFLAGS_SET::NONE);
		}

		/// inherit bone

		// set have inherit rotation
		const auto have_inherit_rotation = pmx_bone.have_inherit_rotation();
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_ROTATION)), have_inherit_rotation, DESCFLAGS_SET::NONE);

		// set have inherit translation
		const auto have_inherit_translation = pmx_bone.have_inherit_translation();
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_TRANSLATION)), have_inherit_translation, DESCFLAGS_SET::NONE);

		if (have_inherit_rotation || have_inherit_translation)
		{
			// set inherit bone parent
			const auto inherit_parent_bone_index = pmx_bone.get_inherit_bone_parent_index();
			if (const auto inherit_parent_bone_ptr = bone_map.Find(inherit_parent_bone_index); inherit_parent_bone_ptr)
			{
				AutoAlloc<BaseLink> link;
				link->SetLink(inherit_parent_bone_ptr->GetValue());
				bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link.GetPointer(), DESCFLAGS_SET::NONE);
			}

			// set inherit rate
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE)), pmx_bone.get_inherit_bone_parent_influence(), DESCFLAGS_SET::NONE);
		}

		/// fixed axis

		// set have fixed axis
		const auto have_fixed_axis = pmx_bone.have_fixed_axis();
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_FIXED_AXIS)), have_fixed_axis, DESCFLAGS_SET::NONE);

		if (have_fixed_axis)
		{
			// set fixed axis
			const auto& fixed_axis = pmx_bone.get_bone_fixed_axis();
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_FIXED_AXIS)), Vector(fixed_axis[0], fixed_axis[1], fixed_axis[2]), DESCFLAGS_SET::NONE);
		}

		/// local axis
		
		// set have local axis
		const auto have_local_axis = pmx_bone.have_local_coordinate();
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_IS_COORDINATE)), have_local_axis, DESCFLAGS_SET::NONE);

		if (have_local_axis)
		{
			// set local axis x
			const auto& local_axis_x = pmx_bone.get_bone_local_coordinate_x();
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_X)), Vector(local_axis_x[0], local_axis_x[1], local_axis_x[2]), DESCFLAGS_SET::NONE);

			// set local axis z
			const auto& local_axis_z = pmx_bone.get_bone_local_coordinate_z();
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_Z)), Vector(local_axis_z[0], local_axis_z[1], local_axis_z[2]), DESCFLAGS_SET::NONE);
		}

		/// IK

		// set is IK
		const auto is_ik = pmx_bone.is_IK();
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IS_IK)), is_ik, DESCFLAGS_SET::NONE);

		if(is_ik)
		{
			const auto& ik_array = pmx_bone.get_IK_link_array();
			const auto ik_bone_num = static_cast<int>(ik_array.size());
			if(ik_bone_num == 0)
				return true;
			if(const auto ik_beging_bone_ptr = bone_map.Find(ik_array[ik_bone_num - 1].get_bone_index()); ik_beging_bone_ptr)
			{
				// create ik tag
				BaseObject* ik_beging_bone = ik_beging_bone_ptr->GetValue();
				BaseTag* ik_tag = ik_beging_bone->MakeTag(1019561); // Ik tag ID : 1019561
				if(setting.import_english)
				{
					ik_tag->SetName(bone_name_universal);
				}
				else
				{
					ik_tag->SetName(bone_name_local);
				}
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_SOLVER)), ID_CA_IK_TAG_SOLVER_3D, DESCFLAGS_SET::NONE);
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_PREFERRED_WEIGHT)), 1, DESCFLAGS_SET::NONE);

				// set target link
				AutoAlloc<BaseLink> target_link;
				target_link->SetLink(bone_object);
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_TARGET)), target_link.GetPointer(), DESCFLAGS_SET::NONE);

				// set tip link
				AutoAlloc<BaseLink> tip_link;
				if(const auto ik_target_bone_ptr = bone_map.Find(pmx_bone.get_IK_target_index()); ik_target_bone_ptr)
				{
					tip_link->SetLink(ik_target_bone_ptr->GetValue());
				}
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_TIP)), tip_link.GetPointer(), DESCFLAGS_SET::NONE);

				// add to model_root description
				if (auto* dynamic_description = m_model_root->GetDynamicDescriptionWritable())
				{
					BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BASELISTLINK);
					bc.SetString(DESC_NAME, bone_name_local);
					bc.SetData(DESC_PARENTGROUP, DescIDGeData(ConstDescID(DescLevel(MODEL_IK_GRP))));
					auto ik_link_id = dynamic_description->Alloc(bc);
					AutoAlloc<BaseLink> ik_link;
					ik_link->SetLink(ik_tag);
					m_model_root->SetParameter(ik_link_id, ik_link.GetPointer(), DESCFLAGS_SET::NONE);
				}

				// set ik limit
				for (auto ik_link_bone_index = int(); ik_link_bone_index < ik_bone_num; ++ik_link_bone_index)
				{
					const auto& pmx_ik_link_bone = ik_array[ik_link_bone_index];
					if(const auto ik_link_bone_ptr = bone_map.Find(pmx_ik_link_bone.get_bone_index()); ik_link_bone_ptr)
					{
						if(!pmx_ik_link_bone.have_limits())
							continue;

						BaseObject* ik_link_bone = ik_link_bone_ptr->GetValue();

						const auto& limit_min = pmx_ik_link_bone.get_limit_min();
						const auto& limit_max = pmx_ik_link_bone.get_limit_max();

						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_MIN_ROT)),
							Vector(limit_min[0], limit_min[1], limit_min[2]) * setting.position_multiple, DESCFLAGS_SET::NONE);
						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_MAX_ROT)),
							Vector(limit_max[0], limit_max[1], limit_max[2]) * setting.position_multiple, DESCFLAGS_SET::NONE);
						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_H)), 1, DESCFLAGS_SET::NONE);
						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_B)), 1, DESCFLAGS_SET::NONE);
					}
				}
			}
		}
	}

	// send bone index change msg
	{
		MMDBoneTagBoneIndexChangeMsg msg;
		Get()->Message(ID_T_MMD_BONE, &msg);
	}

	// send description check update msg
	{
		DescriptionCheckUpdate msg;
		const auto msg_descid = ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK));
		msg.descid = &msg_descid;
		Get()->MultiMessage(MULTIMSG_ROUTE::BROADCAST, MSG_DESCRIPTION_CHECKUPDATE, &msg);
	}

	return true;
}

void MMDBoneRootObject::CreateDisplayTag(GeListNode* node)
{}
