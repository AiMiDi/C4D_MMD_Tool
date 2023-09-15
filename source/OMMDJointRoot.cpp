#include "OMMDJointRoot.h"
#include "OMMDModel.h"

namespace tool {
	Bool OMMDJointRoot::Init(GeListNode* node)
	{
		node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
		if (node != nullptr)
		{
			BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
			if (ProtectionTag != nullptr)
			{
				ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
				ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
			}
		}
		return(true);
	}
	Bool OMMDJointRoot::Read(GeListNode* node, HyperFile* hf, Int32 level)
	{
		if (level == 1) {
			AutoAlloc<BaseLink> bone_root_link;
			if (bone_root_link == nullptr)
				return false;
			if (!bone_root_link->Read(hf))
				return(false);
			this->BoneRoot = static_cast<BaseObject*>(bone_root_link->ForceGetLink());
			AutoAlloc<BaseLink> rigid_root_link;
			if (rigid_root_link == nullptr)
				return false;
			if (!rigid_root_link->Read(hf))
				return(false);
			this->RigidRoot = static_cast<BaseObject*>(rigid_root_link->ForceGetLink());
		}
		return(true);
	}
	Bool OMMDJointRoot::Write(GeListNode* node, HyperFile* hf)
	{
		AutoAlloc<BaseLink> bone_root_link;
		bone_root_link->SetLink(this->BoneRoot);
		if (!bone_root_link->Write(hf))
			return(false);
		AutoAlloc<BaseLink> rigid_root_link;
		rigid_root_link->SetLink(this->RigidRoot);
		if (!rigid_root_link->Write(hf))
			return(false);
		return(true);
	}
	Bool OMMDJointRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
	{
		OMMDJointRoot* const destObject = static_cast<OMMDJointRoot*>(dest);
		destObject->BoneRoot = this->BoneRoot;
		destObject->RigidRoot = this->RigidRoot;
		return(true);
	}
	Bool OMMDJointRoot::Message(GeListNode* node, Int32 type, void* data)
	{
		switch (type)
		{
		case MSG_DESCRIPTION_COMMAND:
		{
			BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
			if (bc == nullptr) {
				return(true);
			}
			DescriptionCommand* dc = (DescriptionCommand*)data;
			if (dc->_descId[0].id == ADD_JOINT_BUTTON)
			{
				BaseObject* newJoint = BaseObject::Alloc(ID_O_MMD_JOINT);
				if (newJoint != nullptr)
				{
					newJoint->SetName(newJoint->GetName() + "." + String::IntToString(this->name_cnt++));
					newJoint->InsertUnder(node);
					newJoint->Message(ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 0, bc->GetInt32(JOINT_DISPLAY_TYPE), 0).GetValue());
					newJoint->Message(ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 1, 0, bc->GetInt32(JOINT_MODE)).GetValue());
				}
			}
			break;
		}
		case ID_O_MMD_MODEL:
		{
			OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data);
			if (msg != nullptr)
			{
				if (msg->msg_type == OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA) {
					switch (msg->object_type)
					{
					case ToolObjectType::BoneRoot:
					{
						this->BoneRoot = msg->object;
						break;

					case ToolObjectType::RigidRoot:
					{
						this->RigidRoot = msg->object;
						break;
					}
					default:
						break;
					}
					}
				}
			}
			break;
		}
		default:
			break;
		}
		return(true);
	}
	Bool OMMDJointRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
	{
		switch (id[0].id)
		{
		case JOINT_DISPLAY_TYPE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 0, t_data.GetInt32(), 0).GetValue());
			break;
		}
		case JOINT_MODE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_JOINT_ROOT, NewObj(OMMDJointRoot_MSG, 1, 0, t_data.GetInt32()).GetValue());
			break;
		}
		default:
			break;
		}
		return(SUPER::SetDParameter(node, id, t_data, flags));
	}
}