/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_joint_root.h
Description:	MMD joint root object

**************************************************************************/

#include "pch.h"
#include "mmd_joint_root.h"

#include "mmd_model.h"

NodeData* MMDJointRootObject::Alloc()
{
	return NewObjClear(MMDJointRootObject);
}

Bool MMDJointRootObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	if (!hf->ReadInt64(&m_joint_name_index))
		return false;
	AutoAlloc<BaseLink> temp_link;
	if (!temp_link)
		return false;
	if (!temp_link->Read(hf))
		return false;
	m_bone_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
	if (!temp_link->Read(hf))
		return false;
	m_rigid_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
	return SUPER::Read(node, hf, level);
}

Bool MMDJointRootObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	if (!hf->WriteInt64(m_joint_name_index))
		return false;
	AutoAlloc<BaseLink> temp_link;
	if (!temp_link)
		return false;
	temp_link->SetLink(m_bone_root);
	if (!temp_link->Write(hf))
		return false;
	temp_link->SetLink(m_rigid_root);
	if (!temp_link->Write(hf))
		return false;
	return SUPER::Write(node, hf);
}

Bool MMDJointRootObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	auto const dest_object = reinterpret_cast<MMDJointRootObject*>(dest);
	dest_object->m_bone_root = m_bone_root;
	dest_object->m_rigid_root = m_rigid_root;
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDJointRootObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr) {
			return(true);
		}
		if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_JOINT_BUTTON)
		{
			if (BaseObject* new_joint = BaseObject::Alloc(ID_O_MMD_JOINT); new_joint != nullptr)
			{
				new_joint->SetName(new_joint->GetName() + "." + String::IntToString(m_joint_name_index++));
				new_joint->InsertUnder(node);
				new_joint->Message(ID_O_MMD_JOINT_ROOT, NewObj(MMDJointRootObjectMsg, MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE, bc->GetInt32(JOINT_DISPLAY_TYPE), 0).GetValue());
				new_joint->Message(ID_O_MMD_JOINT_ROOT, NewObj(MMDJointRootObjectMsg, MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, bc->GetInt32(JOINT_MODE)).GetValue());
			}
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		if (const auto msg = static_cast<MMDModelObjectMsg*>(data); msg != nullptr)
		{
			if (msg->msg_type == MMDModelObjectMsgType::TOOL_OBJECT_UPDATE) {
				switch (msg->object_type)
				{
				case CMTObjectType::BoneRoot:
				{
					m_bone_root = msg->object;
					break;
				}
				case CMTObjectType::RigidRoot:
				{
					m_rigid_root = msg->object;
					break;
				}
				case CMTObjectType::DEFAULT:
				case CMTObjectType::MeshRoot:
				case CMTObjectType::JointRoot:
				case CMTObjectType::ModelRoot:
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

Bool MMDJointRootObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case JOINT_DISPLAY_TYPE:
	{
		MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE, t_data.GetInt32(), 0);
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, &msg);
		break;
	}
	case JOINT_MODE:
	{
		MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, t_data.GetInt32());
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, &msg);
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

BaseObject* MMDJointRootObject::GetRigidRoot() const
{
	return m_rigid_root; 
}

BaseObject* MMDJointRootObject::GetBoneRoot() const
{
	return m_bone_root;
}
