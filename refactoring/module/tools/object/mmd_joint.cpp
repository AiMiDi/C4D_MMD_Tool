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

constexpr Vector g_pmx_joint_colors[6] =
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
	if (!node)
	{
		return false;
	}
	
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
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
		m_link_rigid_a = m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
		                        ->FindRigid(t_data.GetInt32());
		break;
	}
	case JOINT_LINK_RIGID_B_INDEX:
	{
		m_link_rigid_b = m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
		                        ->FindRigid(t_data.GetInt32());
		break;
	}
	default:
		break;
	}
	return ObjectData::SetDParameter(node, id, t_data, flags);
}

Bool MMDJointObject::GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const
{
	if (!node || !description)
	{
		return false;
	}

	if (!description->LoadDescription(node->GetType()))
	{
		return false;
	}

	if (m_joint_root)
	{
		BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_LINK_RIGID_A_INDEX)), nullptr);

		if (settings != nullptr)
		{
			settings->SetContainer(DESC_CYCLE, m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()->GetRigidItems());
		}

		settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_LINK_RIGID_B_INDEX)), nullptr);

		if (settings != nullptr)
		{
			settings->SetContainer(DESC_CYCLE, m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()->GetRigidItems());
		}

		settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_ATTITUDE_USE_BONE_INDEX)), nullptr);

		if (settings != nullptr)
		{
			settings->SetContainer(DESC_CYCLE, m_joint_root->GetNodeData<MMDJointRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()->GetBoneItems());
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}

Bool MMDJointObject::GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags,
								  const BaseContainer* itemdesc) SDK2024_Const
{
	switch (id[0].id)
	{
	case JOINT_TYPE: [[fallthrough]];
	case ID_BASEOBJECT_REL_POSITION: [[fallthrough]];
	case ID_BASEOBJECT_REL_ROTATION: [[fallthrough]];
	case ID_BASEOBJECT_FROZEN_POSITION: [[fallthrough]];
	case ID_BASEOBJECT_FROZEN_ROTATION: [[fallthrough]];
	case JOINT_LINK_RIGID_A_INDEX: [[fallthrough]];
	case JOINT_LINK_RIGID_B_INDEX: [[fallthrough]];
	case JOINT_ATTITUDE_POSITION_X: [[fallthrough]];
	case JOINT_ATTITUDE_POSITION_Y: [[fallthrough]];
	case JOINT_ATTITUDE_POSITION_Z: [[fallthrough]];
	case JOINT_ATTITUDE_ROTATION_X: [[fallthrough]];
	case JOINT_ATTITUDE_ROTATION_Y: [[fallthrough]];
	case JOINT_ATTITUDE_ROTATION_Z: [[fallthrough]];
	case JOINT_ATTITUDE_USE_BONE_INDEX: [[fallthrough]];
	case JOINT_PARAMETER_POSITION_X_MIN: [[fallthrough]];
	case JOINT_PARAMETER_POSITION_X_MAX: [[fallthrough]];
	case JOINT_PARAMETER_POSITION_Y_MIN: [[fallthrough]];
	case JOINT_PARAMETER_POSITION_Y_MAX: [[fallthrough]];
	case JOINT_PARAMETER_POSITION_Z_MIN: [[fallthrough]];
	case JOINT_PARAMETER_POSITION_Z_MAX: [[fallthrough]];
	case JOINT_PARAMETER_ROTATION_X_MIN: [[fallthrough]];
	case JOINT_PARAMETER_ROTATION_X_MAX: [[fallthrough]];
	case JOINT_PARAMETER_ROTATION_Y_MIN: [[fallthrough]];
	case JOINT_PARAMETER_ROTATION_Y_MAX: [[fallthrough]];
	case JOINT_PARAMETER_ROTATION_Z_MIN: [[fallthrough]];
	case JOINT_PARAMETER_ROTATION_Z_MAX: [[fallthrough]];
	case JOINT_SPRING_POSITION_X: [[fallthrough]];
	case JOINT_SPRING_POSITION_Y: [[fallthrough]];
	case JOINT_SPRING_POSITION_Z: [[fallthrough]];
	case JOINT_SPRING_ROTATION_X: [[fallthrough]];
	case JOINT_SPRING_ROTATION_Y: [[fallthrough]];
	case JOINT_SPRING_ROTATION_Z: [[fallthrough]];
	case JOINT_LINK_RIGID_SET_NAME_BUTTON: [[fallthrough]];
	case JOINT_ATTITUDE_USE_BONE_BUTTON: [[fallthrough]];
	case JOINT_PARAMETER_RESET_BUTTON: [[fallthrough]];
	case JOINT_SPRING_RESET_BUTTON:
	{
		if (m_joint_mode == JOINT_MODE_ANIM)
		{
			return false;
		}
		return true;
	}
	case ID_BASEOBJECT_REL_SCALE: [[fallthrough]];
	case ID_BASEOBJECT_FROZEN_SCALE:
		return false;
	default:
		break;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

Bool MMDJointObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if API_VERSION >= 21000
	case MSG_GETCUSTOMICON:
	{
		GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);

		if (cid == nullptr)
		{
			break;
		}

		CustomIconSettings	settings;
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();

		if (!bc)
		{
			break;
		}

		FillCustomIconSettingsFromBaseList2D(settings, *bc, node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(g_pmx_joint_colors[bc->GetInt32(JOINT_TYPE)]);
		GetCustomIcon(*cid, settings, false, nullptr, nullptr);
		break;
	}
#endif
	case  ID_O_MMD_JOINT_ROOT:
	{
		if (const auto* msg = static_cast<MMDJointRootObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE:
			{
				m_display_type = msg->display_type;
				break;
			}
			case MMDJointRootObjectMsgType::JOINT_MODE_CHANGE:
			{
				m_joint_mode = msg->mode;
				if (protection_tag != nullptr)
				{
					if (m_joint_mode == RIGID_MODE_ANIM)
					{
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), true, DESCFLAGS_SET::NONE);
					}
					else
					{
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), false, DESCFLAGS_SET::NONE);
					}
				}
				break;
			}
			case MMDJointRootObjectMsgType::DEFAULT:
				break;
			}
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		const DescriptionCommand* dc = static_cast<DescriptionCommand*>(data);
		BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (!bc)
			return true;
		switch (dc->_descId[0].id)
		{
		case JOINT_LINK_RIGID_SET_NAME_BUTTON:
		{
			String name = "<->"_s;
			if (const BaseObject* a_rigid_object = m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
			                                                ->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX)))
			{
				name = a_rigid_object->GetName() + name;
			}
			if (const BaseObject* b_rigid_object = m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
			                                                                         ->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX)))
			{
				name = name + b_rigid_object->GetName();
			}
			
			reinterpret_cast<BaseObject*>(node)->SetName(name);
			break;
		}
		case JOINT_ATTITUDE_USE_BONE_BUTTON:
		{
			if (const auto bone_ptr = m_joint_root->GetNodeData<MMDJointRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()
																					->FindBone(bc->GetInt32(JOINT_ATTITUDE_USE_BONE_INDEX)))
			{
				reinterpret_cast<BaseObject*>(node)->SetAbsPos(bone_ptr->GetObject()->GetAbsPos());
			}
			break;
		}
		case JOINT_PARAMETER_RESET_BUTTON:
		{
			bc->SetFloat(JOINT_PARAMETER_POSITION_X_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_X_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Y_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Y_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Z_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_POSITION_Z_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_X_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_X_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Y_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Y_MAX, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Z_MIN, 0.0);
			bc->SetFloat(JOINT_PARAMETER_ROTATION_Z_MAX, 0.0);
			break;
		}
		case JOINT_SPRING_RESET_BUTTON:
		{
			bc->SetFloat(JOINT_SPRING_POSITION_X, 0.0);
			bc->SetFloat(JOINT_SPRING_POSITION_Y, 0.0);
			bc->SetFloat(JOINT_SPRING_POSITION_Z, 0.0);
			bc->SetFloat(JOINT_SPRING_ROTATION_X, 0.0);
			bc->SetFloat(JOINT_SPRING_ROTATION_Y, 0.0);
			bc->SetFloat(JOINT_SPRING_ROTATION_Z, 0.0);
			break;
		}
		default:
			break;
		}
		break;
	}
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32	id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		switch (id)
		{
		case JOINT_LINK_RIGID_A_INDEX:
		{
			m_link_rigid_a = m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
				->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX));
			break;
		}
		case JOINT_LINK_RIGID_B_INDEX:
		{
			m_link_rigid_b = m_joint_root->GetNodeData<MMDJointRootObject>()->GetRigidRoot()->GetNodeData<MMDRigidRootObject>()
				->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX));
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
	return SUPER::Message(node, type, data);
}

void MMDJointObject::DrawBox(const BaseObject* op, BaseDraw* bd, const BaseContainer* bc, Bool wire)
{
	if (op != GetActiveDocument()->GetActiveObject())
	{
		bd->DrawBox(Matrix(), 2, g_pmx_joint_colors[bc->GetInt32(JOINT_TYPE)], wire);
	}
	else
	{
		bd->DrawBox(Matrix(), 2, Vector(0.698, 0, 1), wire);
	}
}

DRAWRESULT MMDJointObject::Draw(BaseObject* op, const DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass == DRAWPASS::OBJECT)
	{
		if (op == nullptr || bd == nullptr || bh == nullptr)
		{
			return DRAWRESULT::FAILURE;
		}
		if (const BaseContainer* bc = op->GetDataInstance(); bc)
		{
			bd->SetMatrix_Matrix(nullptr, op->GetMg());
			switch (m_display_type)
			{
			case JOINT_DISPLAY_TYPE_ON:
			{
				DrawBox(op, bd, bc, false);
				break;
			}
			case JOINT_DISPLAY_TYPE_WIRE:
			{
				DrawBox(op, bd, bc, true);
				break;
			}
			case JOINT_DISPLAY_TYPE_OFF:
			default:
				break;
			}
		}
	}
	return SUPER::Draw(op, drawpass, bd, bh);
}

EXECUTIONRESULT MMDJointObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
	EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const BaseObject* PredObject = op->GetPred();
	BaseObject* UpObject = op->GetUp();

	if (UpObject == nullptr && m_joint_root != nullptr)
	{
		op->Remove();
		op->InsertUnderLast(m_joint_root);
	}

	if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_JOINT_ROOT))
	{
		if (PredObject == nullptr)
		{
			op->SetParameter(ConstDescID(DescLevel(JOINT_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
		}
		else
		{
			GeData data;
			PredObject->GetParameter(ConstDescID(DescLevel(JOINT_INDEX)), data, DESCFLAGS_GET::NONE);
			const String RigidIndex = data.GetString();
			op->SetParameter(ConstDescID(DescLevel(JOINT_INDEX)), String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}

		if (m_joint_root == nullptr)
		{
			m_joint_root = UpObject;
		}

	}

	if (protection_tag == nullptr)
	{
		protection_tag = op->MakeTag(Tprotection);
		protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	}

	return EXECUTIONRESULT::OK;
}

Bool MMDJointObject::CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) const
{
	const auto destObject = reinterpret_cast<MMDJointObject*>(dest);

	if (destObject == nullptr)
	{
		return false;
	}

	destObject->m_joint_root = m_joint_root;
	destObject->m_link_rigid_a = m_link_rigid_a;
	destObject->m_link_rigid_b = m_link_rigid_b;
	destObject->m_joint_mode = m_joint_mode;
	destObject->m_display_type = m_display_type;

	return true;
}

Bool MMDJointObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	hf->ReadInt32(&m_display_type);
	hf->ReadInt32(&m_joint_mode);

	AutoAlloc<BaseLink> link;
	if (!link)
	{
		return false;
	}

	if (!link->Read(hf))
	{
		return false;
	}
	m_joint_root = reinterpret_cast<BaseObject*>(link->GetLink(GetActiveDocument()));

	if (!link->Read(hf))
	{
		return false;
	}
	m_link_rigid_a = reinterpret_cast<BaseObject*>(link->GetLink(GetActiveDocument()));
	
	if (!link->Read(hf))
	{
		return false;
	}
	m_link_rigid_b = reinterpret_cast<BaseObject*>(link->GetLink(GetActiveDocument()));
	return true;
}

Bool MMDJointObject::Write(const GeListNode* node, HyperFile* hf) const
{
	hf->WriteInt32(m_display_type);
	hf->WriteInt32(m_joint_mode);

	AutoAlloc<BaseLink> link;
	if(!link)
	{
		return false;
	}

	link->SetLink(m_joint_root);

	if (!link->Write(hf))
	{
		return false;
	}

	link->SetLink(m_link_rigid_a);
	if (!link->Write(hf))
	{
		return false;
	}

	link->SetLink(m_link_rigid_b);
	if (!link->Write(hf))
	{
		return false;
	}

	return true;
}

Bool MMDJointObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}

NodeData* MMDJointObject::Alloc()
{
	return NewObjClear(MMDJointObject);
}
