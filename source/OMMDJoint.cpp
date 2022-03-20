#include "OMMDJoint.h"
#include "OMMDRigid.h"
#include "OMMDRigidRoot.h"
#include "OMMDJointRoot.h"
#include "OMMDBoneRoot.h"

namespace tool {
	const Vector PMX_Joint_Color[6] = {
		Vector(255, 255, 70) / 255,
		Vector(255, 114, 131) / 255,
		Vector(233, 211, 255) / 255,
		Vector(174, 255, 112) / 255,
		Vector(109, 162, 255) / 255,
		Vector(255, 155, 230) / 255
	};
	Bool OMMDJoint::Init(GeListNode* node)
	{
		if (node == nullptr)
			return(false);
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr)
			return(false);
		node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
		bc->SetString(JOINT_NAME_LOCAL, "Joint"_s);
		bc->SetString(JOINT_NAME_UNIVERSAL, "Joint"_s);
		bc->SetInt32(JOINT_LINK_RIGID_A_INDEX, -1);
		bc->SetInt32(JOINT_LINK_RIGID_B_INDEX, -1);
		bc->SetInt32(JOINT_ATTITUDE_USE_BONE_INDEX, -1);
		return(true);
	}
	Bool OMMDJoint::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
	{
		if (!(node && description))
			return(false);
		if (!description->LoadDescription(node->GetType()))
			return(false);
		BaseContainer* settings = nullptr;
		settings = description->GetParameterI(JOINT_LINK_RIGID_A_INDEX, nullptr);
		if (settings != nullptr) {
			settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->rigid_items);
		}
		settings = description->GetParameterI(JOINT_LINK_RIGID_B_INDEX, nullptr);
		if (settings != nullptr) {
			settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->rigid_items);
		}
		settings = description->GetParameterI(JOINT_ATTITUDE_USE_BONE_INDEX, nullptr);
		if (settings != nullptr) {
			settings->SetContainer(DESC_CYCLE, this->JointRoot->GetNodeData<OMMDJointRoot>()->BoneRoot->GetNodeData<OMMDBoneRoot>()->bone_items);
		}
		flags |= DESCFLAGS_DESC::LOADED;
		return(SUPER::GetDDescription(node, description, flags));
	}
	Bool OMMDJoint::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
	{
		switch (id[0].id)
		{
		case JOINT_LINK_RIGID_A_INDEX:
		{
			auto link_rigid_a_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(t_data.GetInt32());
			if (link_rigid_a_ptr != nullptr) {
				link_rigid_a = link_rigid_a_ptr->GetValue();
			}
			break;
		}
		case JOINT_LINK_RIGID_B_INDEX:
		{
			auto link_rigid_b_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(t_data.GetInt32());
			if (link_rigid_b_ptr != nullptr) {
				link_rigid_b = link_rigid_b_ptr->GetValue();
			}
			break;
		}
		default:
			break;
		}
		return(SUPER::SetDParameter(node, id, t_data, flags));
	}
	Bool OMMDJoint::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
	{
		switch (id[0].id)
		{
		case ID_BASEOBJECT_REL_POSITION:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case ID_BASEOBJECT_REL_ROTATION:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case ID_BASEOBJECT_FROZEN_POSITION:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case ID_BASEOBJECT_FROZEN_ROTATION:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_TYPE:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_LINK_RIGID_A_INDEX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_LINK_RIGID_B_INDEX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_POSITION_X:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_POSITION_Y:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_POSITION_Z:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_ROTATION_X:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_ROTATION_Y:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_ROTATION_Z:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_USE_BONE_INDEX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_POSITION_X_MIN:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_POSITION_X_MAX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_POSITION_Y_MIN:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_POSITION_Y_MAX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_POSITION_Z_MIN:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_POSITION_Z_MAX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_ROTATION_X_MIN:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_ROTATION_X_MAX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_ROTATION_Y_MIN:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_ROTATION_Y_MAX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_ROTATION_Z_MIN:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_ROTATION_Z_MAX:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_POSITION_X:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_POSITION_Y:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_POSITION_Z:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_ROTATION_X:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_ROTATION_Y:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_ROTATION_Z:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_LINK_RIGID_SET_NAME_BUTTON:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_ATTITUDE_USE_BONE_BUTTON:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_PARAMETER_RESET_BUTTON:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case JOINT_SPRING_RESET_BUTTON:
		{
			if (this->mode == JOINT_MODE_ANIM)
			{
				return(false);
			}
			else {
				return(true);
			}
		}
		case ID_BASEOBJECT_REL_SCALE:
			return(false);
		case ID_BASEOBJECT_FROZEN_SCALE:
			return(false);
		default:
			break;
		}
		return(SUPER::GetDEnabling(node, id, t_data, flags, itemdesc));
	}
	Bool OMMDJoint::Message(GeListNode* node, Int32 type, void* data)
	{
		switch (type)
		{
#if API_VERSION >= 21000
		case MSG_GETCUSTOMICON:
		{
			GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);
			if (cid == nullptr)
				break;
			CustomIconSettings	settings;
			BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
			if (bc == nullptr)
			{
				break;
			}
			BaseContainer& bcr = static_cast<BaseObject*>(node)->GetDataInstanceRef();
			FillCustomIconSettingsFromBaseList2D(settings, bcr, node->GetType(), true);
			settings._colorMode = 1;
			settings._customColor = maxon::Color(PMX_Joint_Color[bc->GetInt32(JOINT_TYPE)]);
			GetCustomIcon(*cid, settings, false, nullptr, nullptr);
			break;
		}
#endif
		case  ID_O_MMD_JOINT_ROOT:
		{
			OMMDJointRoot_MSG* msg = static_cast<OMMDJointRoot_MSG*>(data);
			if (msg != nullptr)
			{
				switch (msg->type)
				{
				case 0:
				{
					this->DisplayType = msg->DisplayType;
					break;
				}
				case 1:
				{
					this->mode = msg->mode;
					if (protection_tag != nullptr) {
						if (this->mode == RIGID_MODE_ANIM) {
							this->protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
						}
						else {
							this->protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
							this->protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
						}
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case MSG_DESCRIPTION_COMMAND:
		{
			DescriptionCommand* dc = (DescriptionCommand*)data;
			BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
			if (bc == nullptr)
				return(true);
			switch (dc->_descId[0].id)
			{
			case JOINT_LINK_RIGID_SET_NAME_BUTTON:
			{
				String name = "<->"_s;
				auto a_rigid_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX));
				if (a_rigid_ptr != nullptr) {
					BaseObject* a_rigid_object = a_rigid_ptr->GetValue();
					if (a_rigid_object != nullptr) {
						name = a_rigid_object->GetName() + name;
					}
				}
				auto b_rigid_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX));
				if (b_rigid_ptr != nullptr) {
					BaseObject* b_rigid_object = b_rigid_ptr->GetValue();
					if (b_rigid_object != nullptr) {
						name = name + b_rigid_object->GetName();
					}
				}
				static_cast<BaseObject*>(node)->SetName(name);
				break;
			}
			case JOINT_ATTITUDE_USE_BONE_BUTTON:
			{
				auto bone_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->BoneRoot->GetNodeData<OMMDBoneRoot>()->IndexToBoneMap.Find(bc->GetInt32(JOINT_ATTITUDE_USE_BONE_INDEX));
				if (bone_ptr != nullptr) {
					static_cast<BaseObject*>(node)->SetAbsPos(bone_ptr->GetValue()->GetAbsPos());
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
			BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
			switch (id)
			{
			case JOINT_LINK_RIGID_A_INDEX:
			{
				auto link_rigid_a_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX));
				if (link_rigid_a_ptr != nullptr) {
					link_rigid_a = link_rigid_a_ptr->GetValue();
				}
				break;
			}
			case JOINT_LINK_RIGID_B_INDEX:
			{
				auto link_rigid_b_ptr = this->JointRoot->GetNodeData<OMMDJointRoot>()->RigidRoot->GetNodeData<OMMDRigidRoot>()->IndexToRigidMap.Find(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX));
				if (link_rigid_b_ptr != nullptr) {
					link_rigid_b = link_rigid_b_ptr->GetValue();
				}
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
		return(SUPER::Message(node, type, data));
	}
	DRAWRESULT OMMDJoint::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
	{
		if (drawpass == DRAWPASS::OBJECT)
		{
			if (op == nullptr || bd == nullptr || bh == nullptr)
			{
				return(DRAWRESULT::FAILURE);
			}
			BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
			if (bc != nullptr)
			{
				bd->SetMatrix_Matrix(nullptr, op->GetMg());
				switch (this->DisplayType)
				{
				case JOINT_DISPLAY_TYPE_ON:
				{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						bd->DrawBox(Matrix(), 2, Vector(0.698, 0, 1), false);
					}
					else {
						bd->DrawBox(Matrix(), 2, PMX_Joint_Color[(bc->GetInt32(JOINT_TYPE))], false);
					}
					bd->DrawBox(Matrix(), 2, Vector(), true);
					break;
				}
				case JOINT_DISPLAY_TYPE_WIRE:
				{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						bd->DrawBox(Matrix(), 2, Vector(0.698, 0, 1), true);
					}
					else {
						bd->DrawBox(Matrix(), 2, PMX_Joint_Color[(bc->GetInt32(JOINT_TYPE))], true);
					}
					break;
				}
				default:
					break;
				}
			}
		}
		return(SUPER::Draw(op, drawpass, bd, bh));
	}
	EXECUTIONRESULT OMMDJoint::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
	{
		if (op == nullptr || doc == nullptr)
		{
			return(EXECUTIONRESULT::OK);
		}
		BaseObject* PredObject = op->GetPred();
		BaseObject* UpObject = op->GetUp();
		if (UpObject == nullptr && this->JointRoot != nullptr)
		{
			op->Remove();
			op->InsertUnderLast(this->JointRoot);
		}
		if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_JOINT_ROOT))
		{
			if (PredObject == nullptr)
			{
				op->SetParameter(JOINT_INDEX, "0"_s, DESCFLAGS_SET::NONE);
			}
			else {
				GeData data;
				PredObject->GetParameter(JOINT_INDEX, data, DESCFLAGS_GET::NONE);
				String RigidIndex = data.GetString();
				op->SetParameter(JOINT_INDEX, String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
			}
			if (this->JointRoot == nullptr)
			{
				this->JointRoot = UpObject;
			}
		}
		if (this->protection_tag == nullptr) {
			this->protection_tag = op->MakeTag(Tprotection);
			this->protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			this->protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
			this->protection_tag->SetParameter(DescID(PROTECTION_ALLOW_EXPRESSIONS), true, DESCFLAGS_SET::NONE);
		}
		return(EXECUTIONRESULT::OK);
	}
	Bool OMMDJoint::AddToExecution(BaseObject* op, PriorityList* list)
	{
		if (list == nullptr || op == nullptr)
		{
			return(true);
		}
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
		return(true);
	}
	Bool OMMDJoint::Read(GeListNode* node, HyperFile* hf, Int32 level)
	{
		hf->ReadInt32(&this->DisplayType);
		hf->ReadInt32(&this->mode);
		AutoAlloc<BaseLink> joint_root_link;
		if (!joint_root_link->Read(hf))
			return(false);
		this->JointRoot = static_cast<BaseObject*>(joint_root_link->GetLink(GetActiveDocument()));
		AutoAlloc<BaseLink> link_rigid_a_link;
		if (!link_rigid_a_link->Read(hf))
			return(false);
		this->link_rigid_a = static_cast<BaseObject*>(link_rigid_a_link->GetLink(GetActiveDocument()));
		AutoAlloc<BaseLink> link_rigid_b_link;
		if (!link_rigid_b_link->Read(hf))
			return(false);
		this->link_rigid_b = static_cast<BaseObject*>(link_rigid_b_link->GetLink(GetActiveDocument()));
		return true;
	}
	Bool OMMDJoint::Write(GeListNode* node, HyperFile* hf)
	{
		hf->WriteInt32(this->DisplayType);
		hf->WriteInt32(this->mode);
		AutoAlloc<BaseLink> joint_root_link;
		joint_root_link->SetLink(this->JointRoot);
		if (!joint_root_link->Write(hf))
			return(false);
		AutoAlloc<BaseLink> link_rigid_a_link;
		link_rigid_a_link->SetLink(this->link_rigid_a);
		if (!link_rigid_a_link->Write(hf))
			return(false);
		AutoAlloc<BaseLink> link_rigid_b_link;
		link_rigid_b_link->SetLink(this->link_rigid_b);
		if (!link_rigid_b_link->Write(hf))
			return(false);
		return true;
	}
	Bool OMMDJoint::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
	{
		OMMDJoint* const destObject = static_cast<OMMDJoint*>(dest);
		if (destObject == nullptr)
			return(false);
		destObject->JointRoot = this->JointRoot;
		destObject->link_rigid_a = this->link_rigid_a;
		destObject->link_rigid_b = this->link_rigid_b;
		destObject->mode = this->mode;
		destObject->DisplayType = this->DisplayType;
		return(true);
	}
}