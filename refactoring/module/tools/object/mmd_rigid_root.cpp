/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_rigid_root.h
Description:	MMD rigid root object

**************************************************************************/

#include "pch.h"
#include "mmd_rigid_root.h"

#include "mmd_model.h"
#include "description/OMMDRigid.h"

Bool MMDRigidRootObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	if (!hf->ReadInt64(&m_rigid_name_index))
		return false;
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		if (!temp_link->Read(hf))
			return false;
		m_bone_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_joint_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
	}
	// m_rigid_list
	{
		Int64 rigid_list_count = 0;
		if (!hf->ReadInt64(&rigid_list_count))
			return false;
		while (rigid_list_count--)
		{
			Int32 rigid_index = 0;
			if (!hf->ReadInt32(&rigid_index))
				return false;
			auto& link = m_rigid_list.InsertKey(rigid_index)iferr_return;
			link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
			if (!(*link)->Read(hf))
				return false;
		}
	}
	return SUPER::Read(node, hf, level);
}

Bool MMDRigidRootObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	if (!hf->WriteInt64(m_rigid_name_index))
		return false;
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		temp_link->SetLink(m_bone_root);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_joint_root);
		if (!temp_link->Write(hf))
			return false;
	}
	// m_rigid_list
	{
		if (!hf->WriteInt64(m_rigid_list.GetCount()))
			return false;
		for (const auto& rigid_link : m_rigid_list)
		{
			if (hf->WriteInt32(!rigid_link.GetKey()))
				return false;
			if (!(*rigid_link.GetValue())->Write(hf))
				return false;
		}
	}
	return SUPER::Write(node, hf);
}

Bool MMDRigidRootObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDRigidRootObject*>(dest);
	dest_object->m_rigid_name_index = m_rigid_name_index;
	dest_object->m_bone_root = m_bone_root;
	dest_object->m_joint_root = m_joint_root;
	for (const auto& entry : m_rigid_list)
	{
		auto& link = dest_object->m_rigid_list.InsertKey(entry.GetKey())iferr_return;
		link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
		(*entry.GetValue())->CopyTo(*link, flags, trn);
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDRigidRootObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
	return true;
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (!bc) {
			return true;
		}
		if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_RIGID_BUTTON)
		{
			if (BaseObject* new_rigid = BaseObject::Alloc(ID_O_MMD_RIGID))
			{
				new_rigid->SetName(new_rigid->GetName() + "." + String::IntToString(m_rigid_name_index++));
				new_rigid->InsertUnder(node);
				{
					MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, bc->GetInt32(RIGID_DISPLAY_TYPE));
					new_rigid->Message(ID_O_MMD_RIGID_ROOT, &msg);
				}
				{
					MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF,bc->GetInt32(RIGID_MODE));
					new_rigid->Message(ID_O_MMD_RIGID_ROOT, &msg);
				}
			}
		}
		break;
	}
	case ID_O_MMD_RIGID:
	{
		const auto op = reinterpret_cast<BaseObject*>(node);
		rigid_items.FlushAll();
		rigid_items.SetString(-1, "-"_s);
		m_rigid_list.Reset();
		GeData ge_data;
		BaseObject* node_ = op->GetDown();
		while (node_)
		{
			if (node_->GetType() == ID_O_MMD_RIGID)
			{
				node_->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), ge_data, DESCFLAGS_GET::NONE);
				Int32 rigid_index = ge_data.GetString().ToInt32(nullptr);
				this->rigid_items.SetString(rigid_index, node_->GetName());
				auto& link = m_rigid_list.InsertKey(rigid_index)iferr_return;
				(*link)->SetLink(node_);
			}
			node_ = node_->GetNext();
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		if (const auto msg = static_cast<MMDModelObjectMsg*>(data))
		{
			if (msg->msg_type == MMDModelObjectMsgType::TOOL_OBJECT_UPDATE)
			{
				if(msg->object_type == CMTObjectType::BoneRoot)
				{
					m_bone_root = msg->object;
				}
				else if (msg->object_type == CMTObjectType::JointRoot)
				{
					m_joint_root = msg->object;
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

Bool MMDRigidRootObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case RIGID_DISPLAY_TYPE:
	{
		switch (t_data.GetInt32())
		{
		case RIGID_DISPLAY_TYPE_OFF:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_OFF);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, &msg);
			break;
		}
		case RIGID_DISPLAY_TYPE_ON:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_ON);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, &msg);
			CreateDisplayTag(node);
			m_display_tag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE)), DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_WIRE);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, &msg);
			CreateDisplayTag(node);
			m_display_tag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE)), DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
		break;
	}
	case RIGID_MODE:
	{
		switch (t_data.GetInt32())
		{
		case RIGID_MODE_ANIM:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF, RIGID_MODE_ANIM);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, &msg);
			break;
		}
		case RIGID_MODE_EDIT:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_OFF, RIGID_MODE_EDIT);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, &msg);
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
	return SUPER::SetDParameter(node, id, t_data, flags);
}

NodeData* MMDRigidRootObject::Alloc()
{
	return NewObjClear(MMDRigidRootObject);
}
