/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_joint.cpp
Description:	C4D MMD joint object

**************************************************************************/

#include <c4d.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_joint.h"
#if CMT_SDK_HAS_CUSTOMGUI_ICONCHOOSER_HEADER
#include "c4d_customgui/customgui_iconchooser.h"
#endif
#include "description/OMMDJoint.h"
#include "customgui_priority.h"
#include "module/tools/object/mmd_bone_manager.h"
#include "module/tools/object/mmd_joint_manager.h"
#include "module/tools/object/mmd_rigid_manager.h"
#include <libMMD/Model/MMD/MMDPhysics.h>

namespace
{
	constexpr Int32 kJointPriorityOffset = 5300;

	Int32 NormalizeJointMode(const Int32 mode)
	{
		constexpr Int32 kLegacyJointModeVmd = 2;
		return mode == kLegacyJointModeVmd ? JOINT_MODE_ANIM : mode;
	}

	void MarkSceneTransformDirty(BaseObject* object)
	{
		if (!object)
			return;

		object->Touch();
		object->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA);
		object->Message(MSG_UPDATE);
	}

	Matrix BuildJointMatrix(const Eigen::Matrix4f& transform)
	{
		Matrix matrix{
			Vector(transform(0, 3), transform(1, 3), transform(2, 3)),
			Vector(transform(0, 0), transform(1, 0), transform(2, 0)),
			Vector(transform(0, 1), transform(1, 1), transform(2, 1)),
			Vector(transform(0, 2), transform(1, 2), transform(2, 2))
		};
		matrix.sqmat = matrix.sqmat.GetNormalized();
		return matrix;
	}

	void ConfigureJointExecutionPriority(GeListNode* node)
	{
		if (!node)
			return;

		BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (!bc)
			return;

		if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
		{
			if (auto* pd = GetCustomDataTypeWritable<PriorityData>(priority, CUSTOMGUI_PRIORITY_DATA))
			{
				pd->SetPriorityValue(PRIORITYVALUE_MODE, CYCLE_EXPRESSION);
				pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, kJointPriorityOffset);
				bc->SetData(EXPRESSION_PRIORITY, priority);
			}
		}
	}

}

SDK2024_ConstExpr Vector g_pmx_joint_colors[6] =
{
		Vector(255, 255, 70) / 255,
		Vector(255, 114, 131) / 255,
		Vector(233, 211, 255) / 255,
		Vector(174, 255, 112) / 255,
		Vector(109, 162, 255) / 255,
		Vector(255, 155, 230) / 255
};

MMDJointManagerObject* MMDJointObject::GetJointManager() const
{
	if (!joint_manager_data_)
	{
		if (auto* obj = io_util::ResolveObjectLink(joint_manager_link_))
			joint_manager_data_ = obj->GetNodeData<MMDJointManagerObject>();
	}
	return joint_manager_data_;
}

SDK2024_Init(MMDJointObject)
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
	ConfigureJointExecutionPriority(node);

	return SDK2024_SuperInit;
}

Bool MMDJointObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case JOINT_LINK_RIGID_A_INDEX:
	{
		if (auto* mgr = GetJointManager())
			link_rigid_a_->SetLink(mgr->GetRigidManager()->FindRigid(t_data.GetInt32()));
		break;
	}
	case JOINT_LINK_RIGID_B_INDEX:
	{
		if (auto* mgr = GetJointManager())
			link_rigid_b_->SetLink(mgr->GetRigidManager()->FindRigid(t_data.GetInt32()));
		break;
	}
	default:
		break;
	}
	return ObjectData::SetDParameter(node, id, t_data, flags);
}

SDK2024_GetDDescription(MMDJointObject)
{
	if (!node || !description)
	{
		return false;
	}

	if (!description->LoadDescription(node->GetType()))
	{
		return false;
	}

	if (auto* mgr = GetJointManager())
	{
		BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_LINK_RIGID_A_INDEX)), nullptr);

		if (settings != nullptr)
		{
			settings->SetContainer(DESC_CYCLE, mgr->GetRigidManager()->GetRigidItems());
		}

		settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_LINK_RIGID_B_INDEX)), nullptr);

		if (settings != nullptr)
		{
			settings->SetContainer(DESC_CYCLE, mgr->GetRigidManager()->GetRigidItems());
		}

		settings = description->GetParameterI(ConstDescID(DescLevel(JOINT_ATTITUDE_USE_BONE_INDEX)), nullptr);

		if (settings != nullptr)
		{
			settings->SetContainer(DESC_CYCLE, mgr->GetBoneManager()->GetBoneItems());
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}

SDK2024_GetDEnabling(MMDJointObject)
{
	if (joint_mode_ != JOINT_MODE_EDIT || id[0].id == ID_BASEOBJECT_REL_SCALE || id[0].id == ID_BASEOBJECT_FROZEN_SCALE)
		return false;

	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

void MMDJointObject::HandleJointModeChange(const Int32 mode)
{
	const Int32 normalized_mode = NormalizeJointMode(mode);
	BaseObject* const object = static_cast<BaseObject*>(Get());
	if (!object)
	{
		joint_mode_ = normalized_mode;
		return;
	}

	object->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	joint_mode_ = normalized_mode;
}

Bool MMDJointObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if CMT_SDK_HAS_CUSTOMGUI_ICONCHOOSER_HEADER
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
	case  g_mmd_joint_manager_object_id:
	{
		if (const auto* msg = static_cast<MMDJointRootObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE:
			{
				display_type_ = msg->display_type;
				break;
			}
			case MMDJointRootObjectMsgType::JOINT_MODE_CHANGE:
			{
				HandleJointModeChange(msg->mode);
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
			if (auto* mgr = GetJointManager())
			{
				String name = "<->"_s;
				if (const BaseObject* a_rigid_object = mgr->GetRigidManager()->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX)))
				{
					name = a_rigid_object->GetName() + name;
				}
				if (const BaseObject* b_rigid_object = mgr->GetRigidManager()->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX)))
				{
					name = name + b_rigid_object->GetName();
				}
				reinterpret_cast<BaseObject*>(node)->SetName(name);
			}
			break;
		}
		case JOINT_ATTITUDE_USE_BONE_BUTTON:
		{
			if (auto* mgr = GetJointManager(); mgr)
			if (const auto bone_ptr = mgr->GetBoneManager()->FindBone(bc->GetInt32(JOINT_ATTITUDE_USE_BONE_INDEX)))
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
			if (auto* mgr = GetJointManager())
				link_rigid_a_->SetLink(mgr->GetRigidManager()->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX)));
			break;
		}
		case JOINT_LINK_RIGID_B_INDEX:
		{
			if (auto* mgr = GetJointManager())
				link_rigid_b_->SetLink(mgr->GetRigidManager()->FindRigid(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX)));
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
			Matrix m = op->GetMg();
			m.sqmat = m.sqmat.GetNormalized();
			bd->SetMatrix_Matrix(nullptr, m);
			switch (display_type_)
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

void MMDJointObject::HandleJointIndexUpdate(BaseObject* op)
{
	if (const BaseObject* up_object = op->GetUp(); up_object && up_object->IsInstanceOf(g_mmd_joint_object_id))
	{
		if (SDK2024_Const BaseObject* pred_object = op->GetPred(); !pred_object)
		{
			op->SetParameter(ConstDescID(DescLevel(JOINT_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
		}
		else
		{
			GeData data;
			pred_object->GetParameter(ConstDescID(DescLevel(JOINT_INDEX)), data, DESCFLAGS_GET::NONE);
			op->SetParameter(ConstDescID(DescLevel(JOINT_INDEX)), String::IntToString(data.GetString().ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}
	}
}

EXECUTIONRESULT MMDJointObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
                                        EXECUTIONFLAGS flags)
{
	if (!op)
	{
		return EXECUTIONRESULT::OK;
	}

	if (joint_mode_ == JOINT_MODE_EDIT)
	{
		HandleJointIndexUpdate(op);
	}
	else if (joint_mode_ == JOINT_MODE_ANIM && mmd_joint_)
	{
		op->SetRelMl(BuildJointMatrix(mmd_joint_->GetTransform()));
		MarkSceneTransformDirty(op);
	}

	return EXECUTIONRESULT::OK;
}

SDK2024_CopyTo(MMDJointObject)
{
	const auto destObject = reinterpret_cast<MMDJointObject*>(dest);

	if (destObject == nullptr)
	{
		return false;
	}

	if (joint_manager_link_)
		joint_manager_link_->CopyTo(destObject->joint_manager_link_, flags, trn);
	if (link_rigid_a_)
		link_rigid_a_->CopyTo(destObject->link_rigid_a_, flags, trn);
	if (link_rigid_b_)
		link_rigid_b_->CopyTo(destObject->link_rigid_b_, flags, trn);
	destObject->joint_mode_ = joint_mode_;
	destObject->display_type_ = display_type_;

	return true;
}

Bool MMDJointObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	IOReadField(display_type_);
	IOReadField(joint_mode_);
	IOReadField(joint_manager_link_);
	IOReadField(link_rigid_a_);
	IOReadField(link_rigid_b_);
	joint_mode_ = NormalizeJointMode(joint_mode_);
	if (BaseContainer* const bc = node ? reinterpret_cast<BaseList2D*>(node)->GetDataInstance() : nullptr)
		bc->SetInt32(JOINT_MODE, joint_mode_);
	HandleJointModeChange(joint_mode_);
	ConfigureJointExecutionPriority(node);
	return true;
}

SDK2024_Write(MMDJointObject)
{
	IOWriteField(display_type_);
	IOWriteField(joint_mode_);
	IOWriteField(joint_manager_link_);
	IOWriteField(link_rigid_a_);
	IOWriteField(link_rigid_b_);

	return true;
}

Bool MMDJointObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);
	return true;
}

NodeData* MMDJointObject::Alloc()
{
	return NewObjClear(MMDJointObject);
}
