/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_joint.cpp
Description:	C4D MMD joint object

**************************************************************************/

#include "pch.h"

#include "mmd_joint.h"

#include "description/OMMDJoint.h"
#include "module/tools/object/mmd_bone_root.h"
#include "module/tools/object/mmd_joint_root.h"
#include "module/tools/object/mmd_rigid_root.h"

const Vector PMX_Joint_Color[6] =
{
		Vector(255, 255, 70) / 255,
		Vector(255, 114, 131) / 255,
		Vector(233, 211, 255) / 255,
		Vector(174, 255, 112) / 255,
		Vector(109, 162, 255) / 255,
		Vector(255, 155, 230) / 255
};

Bool MMDJointObject::Init(GeListNode* node SDK2024_InitParaName)
{
	if (node == nullptr)
	{
		return(false);
	}

	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();

	if (bc == nullptr)
	{
		return(false);
	}

	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	bc->SetString(JOINT_NAME_LOCAL, "Joint"_s);
	bc->SetString(JOINT_NAME_UNIVERSAL, "Joint"_s);
	bc->SetInt32(JOINT_LINK_RIGID_A_INDEX, -1);
	bc->SetInt32(JOINT_LINK_RIGID_B_INDEX, -1);
	bc->SetInt32(JOINT_ATTITUDE_USE_BONE_INDEX, -1);

	return SUPER::Init(node SDK2024_InitPara);
}

Bool MMDJointObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case JOINT_LINK_RIGID_A_INDEX:
	{
		link_rigid_a = static_cast<BaseObject*>(JointRoot->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
		                                                 ->FindRigid(t_data.GetInt32()));
		break;
	}
	case JOINT_LINK_RIGID_B_INDEX:
	{
		link_rigid_b = static_cast<BaseObject*>(JointRoot->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
														 ->FindRigid(t_data.GetInt32()));
		break;
	}
	default:
		break;
	}
	return ObjectData::SetDParameter(node, id, t_data, flags);
}

Bool MMDJointObject::GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const
{
	if (!(node && description))
	{
		return(false);
	}

	if (!description->LoadDescription(node->GetType()))
	{
		return(false);
	}

	BaseContainer* settings = nullptr;
	settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_LINK_RIGID_A_INDEX)), nullptr);

	if (settings != nullptr)
	{
		settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()->GetRigidItems());
	}

	settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_LINK_RIGID_B_INDEX)), nullptr);

	if (settings != nullptr)
	{
		settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()->GetRigidItems());
	}

	settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_ATTITUDE_USE_BONE_INDEX)), nullptr);

	if (settings != nullptr)
	{
		settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<MMDJointRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()->GetBoneItems());
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}


