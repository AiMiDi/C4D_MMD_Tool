#include "OMMDRigidRoot.h"
#include "OMMDModel.h"
#include "description/OMMDRigid.h"

Bool mmd::OMMDRigidRoot::Init(GeListNode* node)
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
		BaseTag* DisplayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		if (DisplayTag != nullptr)
		{
			DisplayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
			DisplayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			DisplayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return(true);
}
void mmd::OMMDRigidRoot::Free(GeListNode* node)
{

}
Bool mmd::OMMDRigidRoot::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	if (level == 1) {
		AutoAlloc<BaseLink> bone_root_link;
		if (bone_root_link == nullptr)
			return false;
		if (!bone_root_link->Read(hf))
			return(false);
		this->BoneRoot = static_cast<BaseObject*>(bone_root_link->ForceGetLink());
		AutoAlloc<BaseLink> joint_root_link;
		if (joint_root_link == nullptr)
			return false;
		if (!joint_root_link->Read(hf))
			return(false);
		this->JointRoot = static_cast<BaseObject*>(joint_root_link->ForceGetLink());
		Int64 rigid_map_count = 0;
		if (!hf->ReadInt64(&rigid_map_count))
			return(false);
		Int32 index = 0;
		for (Int64 i = 0; i < rigid_map_count; i++)
		{
			if (!hf->ReadInt32(&index))
				return(false);
			AutoAlloc<BaseLink> tmp;
			if (!tmp->Read(hf))
				return(false);
			iferr(this->IndexToRigidMap.Insert(index, static_cast<BaseObject*>(tmp->ForceGetLink())))
				return(false);
		}
	}
	return(true);
}
Bool mmd::OMMDRigidRoot::Write(GeListNode* node, HyperFile* hf)
{
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	bone_root_link->SetLink(this->BoneRoot);
	if (!bone_root_link->Write(hf))
		return(false);
	AutoAlloc<BaseLink> joint_root_link;
	if (joint_root_link == nullptr)
		return false;
	joint_root_link->SetLink(this->JointRoot);
	if (!joint_root_link->Write(hf))
		return(false);
	if (!hf->WriteInt64(this->IndexToRigidMap.GetCount()))
		return(false);
	for (auto& i : this->IndexToRigidMap.GetKeys())
	{
		if (!hf->WriteInt32(i))
			return(false);
		AutoAlloc<BaseLink> tmp;
		tmp->SetLink(this->IndexToRigidMap.Find(i)->GetValue());
		if (!tmp->Write(hf))
			return(false);
	}
	return(true);
}
Bool mmd::OMMDRigidRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	OMMDRigidRoot* const destObject = static_cast<OMMDRigidRoot*>(dest);
	destObject->BoneRoot = this->BoneRoot;
	destObject->JointRoot = this->JointRoot;
	return(true);
}
Bool mmd::OMMDRigidRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseObject* op = static_cast<BaseObject*>(node);
	switch (id[0].id)
	{
	case RIGID_DISPLAY_TYPE:
	{
		switch (t_data.GetInt32())
		{
		case RIGID_DISPLAY_TYPE_OFF:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, RIGID_DISPLAY_TYPE_OFF).GetValue());
			break;
		}
		case RIGID_DISPLAY_TYPE_ON:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, RIGID_DISPLAY_TYPE_ON).GetValue());
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, RIGID_DISPLAY_TYPE_WIRE).GetValue());
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
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
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 1, 0, RIGID_MODE_ANIM).GetValue());
			break;
		}
		case RIGID_MODE_EDIT:
		{
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 1, 0, RIGID_MODE_EDIT).GetValue());
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
	return(SUPER::SetDParameter(node, id, t_data, flags));
}
Bool mmd::OMMDRigidRoot::Message(GeListNode* node, Int32 type, void* data)
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
			BaseObject* newRigid = BaseObject::Alloc(ID_O_MMD_RIGID);
			if (newRigid != nullptr)
			{
				newRigid->SetName(newRigid->GetName() + "." + String::IntToString(this->name_cnt++));
				newRigid->InsertUnder(node);
				newRigid->Message(ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 0, bc->GetInt32(RIGID_DISPLAY_TYPE), 0).GetValue());
				newRigid->Message(ID_O_MMD_RIGID_ROOT, NewObj(OMMDRigidRoot_MSG, 1, 0, bc->GetInt32(RIGID_MODE)).GetValue());
			}
		}
		break;
	}
	case ID_O_MMD_RIGID:
	{
		BaseObject* op = static_cast<BaseObject*>(node);
		this->rigid_items.FlushAll();
		this->rigid_items.SetString(-1, "-"_s);
		this->IndexToRigidMap.Reset();
		GeData ge_data;
		BaseObject* node_ = op->GetDown();
		while (node_ != nullptr)
		{
			if (node_->GetType() == ID_O_MMD_RIGID)
			{
				node_->GetParameter(RIGID_INDEX, ge_data, DESCFLAGS_GET::NONE);
				Int32 rigid_index = ge_data.GetString().ToInt32(nullptr);
				this->rigid_items.SetString(rigid_index, node_->GetName());
				this->IndexToRigidMap.Insert(rigid_index, node_)iferr_return;
			}
			node_ = node_->GetNext();
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data);
		if (msg != nullptr)
		{
			switch (msg->type)
			{
			case  OMMDModel_Root_type::BoneRoot:
			{
				this->BoneRoot = msg->Root;
				break;
			}
			case OMMDModel_Root_type::JointRoot:
			{
				this->JointRoot = msg->Root;
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return(true);
}