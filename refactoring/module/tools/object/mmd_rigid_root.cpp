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

Bool MMDRigidRootObject::Init(GeListNode* node SDK2024_InitPara)
{
	if(!node)
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
	return true;
}

Bool MMDRigidRootObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	return ObjectData::Read(node, hf, level);
}

Bool MMDRigidRootObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	return ObjectData::Write(node, hf);
}

Bool MMDRigidRootObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	return ObjectData::CopyTo(dest, snode, dnode, flags, trn);
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
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr) {
			return(true);
		}
		DescriptionCommand* dc = (DescriptionCommand*)data;
		if (dc->_descId[0].id == ADD_RIGID_BUTTON)
		{
			if (BaseObject* newRigid = BaseObject::Alloc(ID_O_MMD_RIGID))
			{
				newRigid->SetName(newRigid->GetName() + "." + String::IntToString(m_rigid_named_number++));
				newRigid->InsertUnder(node);
				{
					MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, bc->GetInt32(RIGID_DISPLAY_TYPE));
					newRigid->Message(ID_O_MMD_RIGID_ROOT, &msg);
				}
				{
					MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF,bc->GetInt32(RIGID_MODE));
					newRigid->Message(ID_O_MMD_RIGID_ROOT, &msg);
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
				link->SetLink(node_);
			}
			node_ = node_->GetNext();
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		if (const auto msg = static_cast<MMDModelObjectMsg*>(data))
		{
			if (msg->msg_type == MMDModelObjectMsgType::TOOL_OBJECT_UPDATE) {
				switch (msg->object_type)
				{
				case  CMTObjectType::BoneRoot:
				{
					m_bone_root = msg->object;
					break;
				}
				case CMTObjectType::JointRoot:
				{
					m_joint_root = msg->object;
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
			if (m_displayTag)
				m_displayTag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE)), DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_WIRE);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, &msg);
			if (m_displayTag)
				m_displayTag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE)), DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
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
	return(NewObjClear(MMDRigidRootObject));
}
