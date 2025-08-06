/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_joint_root.h
Description:	MMD joint root object

**************************************************************************/

#include "pch.h"
#include "mmd_joint_manager.h"
#include "mmd_bone_manager.h"
#include "mmd_rigid_manager.h"

#include "mmd_joint.h"
#include "mmd_model.h"
#include "description/OMMDJoint.h"

NodeData* MMDJointManagerObject::Alloc()
{
	return NewObjClear(MMDJointManagerObject);
}

Bool MMDJointManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	IOReadField(joint_name_index_);
	IOReadField(bone_manager_);
	IOReadField(rigid_manager_);
	if (bone_manager_)
		bone_manager_data_ = bone_manager_->GetNodeData<MMDBoneManagerObject>();
	if (rigid_manager_)
		rigid_manager_data_ = rigid_manager_->GetNodeData<MMDRigidManagerObject>();
	return SUPER::Read(node, hf, level);
}

Bool MMDJointManagerObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	IOWriteField(joint_name_index_);
	IOWriteField(bone_manager_);
	IOWriteField(rigid_manager_);
	return SUPER::Write(node, hf);
}

Bool MMDJointManagerObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	auto const dest_object = reinterpret_cast<MMDJointManagerObject*>(dest);
	dest_object->bone_manager_ = bone_manager_;
	dest_object->bone_manager_data_ = bone_manager_data_;
	dest_object->rigid_manager_ = rigid_manager_;
	dest_object->rigid_manager_data_ = rigid_manager_data_;
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

BaseObject* MMDJointManagerObject::AddJoint(const String& name, GeListNode* node)
{
	if (!node)
		node = Get();
	if (const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
	{
		if (BaseObject* new_joint = BaseObject::Alloc(ID_O_MMD_JOINT))
		{
			if (name.IsEmpty())
				new_joint->SetName(new_joint->GetName() + "." + String::IntToString(joint_name_index_++));
			else
				new_joint->SetName(name);

			new_joint->InsertUnder(node);
			{
				MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE, bc->GetInt32(JOINT_DISPLAY_TYPE), 0);
				new_joint->Message(ID_O_MMD_JOINT_MANAGER, &msg);
			}
			{
				MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, bc->GetInt32(JOINT_MODE));
				new_joint->Message(ID_O_MMD_JOINT_MANAGER, &msg);
			}
			return new_joint;
		}
	}
	return nullptr;
}

Bool MMDJointManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (!bc)
		{
			return(true);
		}
		if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_JOINT_BUTTON)
		{
			AddJoint({}, node);
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
			if (const auto msg = static_cast<MMDModelRootObjectMsg*>(data); msg != nullptr)
			{
				switch (msg->msg_type)
				{
					case MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE:
					{
						switch (msg->object_type)
						{
						case ManagerObjectType::BONE_MANAGER:
							{
								bone_manager_ = msg->object;
								if (bone_manager_)
									bone_manager_data_ = bone_manager_->GetNodeData<MMDBoneManagerObject>();
								break;
							}
						case ManagerObjectType::RIGID_MANAGER:
							{
								rigid_manager_ = msg->object;
								if (rigid_manager_)
									rigid_manager_data_ = rigid_manager_->GetNodeData<MMDRigidManagerObject>();
								break;
							}
						case ManagerObjectType::DEFAULT:
						case ManagerObjectType::MESH_MANAGER:
						case ManagerObjectType::JOINT_MANAGER:
						case ManagerObjectType::MODEL_MANAGER:
							break;
						}
					}
					case MMDModelRootObjectMsgType::MODEL_MODE_CHANGE:
					{
						auto flag = DESCFLAGS_SET::NONE;
						SetDParameter(node, ConstDescID(DescLevel(JOINT_MODE)),msg->model_mode, flag);
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

Bool MMDJointManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case JOINT_DISPLAY_TYPE:
	{
		MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE, t_data.GetInt32(), 0);
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_MANAGER, &msg);
		break;
	}
	case JOINT_MODE:
	{
		MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, t_data.GetInt32());
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_MANAGER, &msg);
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

MMDRigidManagerObject* MMDJointManagerObject::GetRigidManager() const
{
	return rigid_manager_data_;
}

namespace
{
	template <Int32 ID>
	void SetJointParameter(BaseObject* object ,GeData data)
	{
		object->SetParameter(ConstDescID(DescLevel(ID)), data, DESCFLAGS_SET::NONE);
	}
}

Bool MMDJointManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model,
	const CMTToolsSetting::ModelImport& setting)
{
	if (!pmx_model)
		return false;

	if (!pmx_model->GetPhysicsManager())
		return false;

	const auto pmx_joints = pmx_model->GetPhysicsManager()->GetJoints();
	if (!pmx_joints)
		return false;

	position_multiple_ = static_cast<float>(setting.position_multiple);

	const auto joint_count = pmx_file.m_joints.size();
	for (size_t joint_index = 0; joint_index < joint_count; ++joint_index)
	{
		const auto& pmx_joint = pmx_file.m_joints[joint_index];
		const maxon::String name_local{ pmx_joint.m_name.c_str() };
		const auto joint_object = AddJoint(name_local);
		if (!joint_object)
			return false;

		if (const auto joint_node = joint_object->GetNodeData<MMDJointObject>())
		{
			joint_node->joint_manager_ = reinterpret_cast<BaseObject*>(Get());
			joint_node->joint_manager_data_ = this;
			joint_node->mmd_joint_ = (*pmx_joints)[joint_index].get();
		}

		const maxon::String name_universal{ pmx_joint.m_englishName.c_str() };
		SetJointParameter<JOINT_NAME_LOCAL>(joint_object, name_local);
		SetJointParameter<JOINT_NAME_UNIVERSAL>(joint_object, name_universal);
		SetJointParameter<JOINT_NAME_IS>(joint_object, setting.import_english);

		SetJointParameter<JOINT_TYPE>(joint_object, static_cast<Int32>(pmx_joint.m_type));

		SetJointParameter<JOINT_LINK_RIGID_A_INDEX>(joint_object, pmx_joint.m_rigidbodyAIndex);
		SetJointParameter<JOINT_LINK_RIGID_B_INDEX>(joint_object, pmx_joint.m_rigidbodyBIndex);

		SetJointParameter<JOINT_ATTITUDE_POSITION_X>(joint_object, pmx_joint.m_translate.x);
		SetJointParameter<JOINT_ATTITUDE_POSITION_Y>(joint_object, pmx_joint.m_translate.y);
		SetJointParameter<JOINT_ATTITUDE_POSITION_Z>(joint_object, pmx_joint.m_translate.z);

		SetJointParameter<JOINT_ATTITUDE_ROTATION_X>(joint_object, pmx_joint.m_rotate.x);
		SetJointParameter<JOINT_ATTITUDE_ROTATION_Y>(joint_object, pmx_joint.m_rotate.y);
		SetJointParameter<JOINT_ATTITUDE_ROTATION_Z>(joint_object, pmx_joint.m_rotate.z);

		SetJointParameter<JOINT_PARAMETER_POSITION_X_MIN>(joint_object, pmx_joint.m_translateLowerLimit.x);
		SetJointParameter<JOINT_PARAMETER_POSITION_Y_MIN>(joint_object, pmx_joint.m_translateLowerLimit.y);
		SetJointParameter<JOINT_PARAMETER_POSITION_Z_MIN>(joint_object, pmx_joint.m_translateLowerLimit.z);
		SetJointParameter<JOINT_PARAMETER_POSITION_X_MAX>(joint_object, pmx_joint.m_translateUpperLimit.x);
		SetJointParameter<JOINT_PARAMETER_POSITION_Y_MAX>(joint_object, pmx_joint.m_translateUpperLimit.y);
		SetJointParameter<JOINT_PARAMETER_POSITION_Z_MAX>(joint_object, pmx_joint.m_translateUpperLimit.z);

		SetJointParameter<JOINT_PARAMETER_ROTATION_X_MIN>(joint_object, pmx_joint.m_rotateLowerLimit.x);
		SetJointParameter<JOINT_PARAMETER_ROTATION_Y_MIN>(joint_object, pmx_joint.m_rotateLowerLimit.y);
		SetJointParameter<JOINT_PARAMETER_ROTATION_Z_MIN>(joint_object, pmx_joint.m_rotateLowerLimit.z);
		SetJointParameter<JOINT_PARAMETER_ROTATION_X_MAX>(joint_object, pmx_joint.m_rotateUpperLimit.x);
		SetJointParameter<JOINT_PARAMETER_ROTATION_Y_MAX>(joint_object, pmx_joint.m_rotateUpperLimit.y);
		SetJointParameter<JOINT_PARAMETER_ROTATION_Z_MAX>(joint_object, pmx_joint.m_rotateUpperLimit.z);

		SetJointParameter<JOINT_SPRING_POSITION_X>(joint_object, pmx_joint.m_springTranslateFactor.x);
		SetJointParameter<JOINT_SPRING_POSITION_Y>(joint_object, pmx_joint.m_springTranslateFactor.y);
		SetJointParameter<JOINT_SPRING_POSITION_Z>(joint_object, pmx_joint.m_springTranslateFactor.z);

		SetJointParameter<JOINT_SPRING_ROTATION_X>(joint_object, pmx_joint.m_springRotateFactor.x);
		SetJointParameter<JOINT_SPRING_ROTATION_Y>(joint_object, pmx_joint.m_springRotateFactor.y);
		SetJointParameter<JOINT_SPRING_ROTATION_Z>(joint_object, pmx_joint.m_springRotateFactor.z);
	}

	return true;
}

MMDBoneManagerObject* MMDJointManagerObject::GetBoneManager() const
{
	return bone_manager_data_;
}
