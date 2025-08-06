/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_rigid_root.h
Description:	MMD rigid root object

**************************************************************************/

#include "pch.h"
#include "mmd_model_manager.h"
#include "mmd_rigid_manager.h"

#include "mmd_bone_manager.h"
#include "mmd_rigid.h"

Bool MMDRigidManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	IOReadField(m_rigid_name_index_);
	IOReadField(bone_manager_);
	IOReadField(joint_manager_);
	if (!io_util::ReadHashMap(hf, rigid_list_))
		return false;
	bone_manager_data_ = bone_manager_->GetNodeData<MMDBoneManagerObject>();
	return SUPER::Read(node, hf, level);
}

Bool MMDRigidManagerObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	IOWriteField(m_rigid_name_index_);
	IOWriteField(bone_manager_);
	IOWriteField(joint_manager_);
	if (!io_util::WriteHashMap(hf, rigid_list_))
		return false;
	return SUPER::Write(node, hf);
}

Bool MMDRigidManagerObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDRigidManagerObject*>(dest);
	dest_object->m_rigid_name_index_ = m_rigid_name_index_;
	dest_object->bone_manager_ = bone_manager_;
	dest_object->bone_manager_data_ = bone_manager_data_;
	dest_object->joint_manager_ = joint_manager_;
	for (const auto& entry : rigid_list_)
	{
		auto& link = dest_object->rigid_list_.InsertKey(entry.GetKey())iferr_return;
		link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
		(*entry.GetValue())->CopyTo(*link, flags, trn);
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

BaseObject* MMDRigidManagerObject::AddRigid(const String& name, GeListNode* node)
{
	if (!node)
		node = Get();
	if (const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
	{
		if (BaseObject* new_rigid = BaseObject::Alloc(ID_O_MMD_RIGID))
		{
			if (name.IsEmpty())
				new_rigid->SetName(new_rigid->GetName() + "." + String::IntToString(m_rigid_name_index_++));
			else
				new_rigid->SetName(name);

			new_rigid->InsertUnder(node);
			{
				MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, bc->GetInt32(RIGID_DISPLAY_TYPE));
				new_rigid->Message(ID_O_MMD_RIGID_MANAGER, &msg);
			}
			{
				MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF,bc->GetInt32(RIGID_MODE));
				new_rigid->Message(ID_O_MMD_RIGID_MANAGER, &msg);
			}
			return new_rigid;
		}
	}
	return nullptr;
}

Bool MMDRigidManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
	return true;
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_RIGID_BUTTON)
		{
			AddRigid({}, node);
		}
		break;
	}
	case ID_O_MMD_RIGID:
	{
		const auto op = reinterpret_cast<BaseObject*>(node);
		rigid_items_.FlushAll();
		rigid_items_.SetString(-1, "-"_s);
		rigid_list_.Reset();
		GeData ge_data;
		BaseObject* node_ = op->GetDown();
		while (node_)
		{
			if (node_->GetType() == ID_O_MMD_RIGID)
			{
				node_->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), ge_data, DESCFLAGS_GET::NONE);
				Int32 rigid_index = ge_data.GetString().ToInt32(nullptr);
				this->rigid_items_.SetString(rigid_index, node_->GetName());
				auto& link = rigid_list_.InsertKey(rigid_index)iferr_return;
				link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
				(*link)->SetLink(node_);
			}
			node_ = node_->GetNext();
		}
		break;
	}
	case ID_O_MMD_MODEL:
	{
		if (const auto msg = static_cast<MMDModelRootObjectMsg*>(data))
		{
			switch (msg->msg_type)
			{
			case MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE:
				{
					if(msg->object_type == ManagerObjectType::BONE_MANAGER)
					{
						bone_manager_ = msg->object;
						bone_manager_data_ = bone_manager_->GetNodeData<MMDBoneManagerObject>();
					}
					else if (msg->object_type == ManagerObjectType::JOINT_MANAGER)
					{
						joint_manager_ = msg->object;
					}
					break;
				}
			case MMDModelRootObjectMsgType::MODEL_MODE_CHANGE:
				{
					auto flag = DESCFLAGS_SET::NONE;
					node->SetParameter(ConstDescID(DescLevel(RIGID_MODE)), msg->model_mode, DESCFLAGS_SET::NONE);
					break;
				}
			case MMDModelRootObjectMsgType::DEFAULT:
				break;
			}

		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

Bool MMDRigidManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
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
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_MANAGER, &msg);
			break;
		}
		case RIGID_DISPLAY_TYPE_ON:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_ON);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_MANAGER, &msg);
			CreateDisplayTag(node);
			m_display_tag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE)), DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_WIRE);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_MANAGER, &msg);
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
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF, t_data.GetInt32());
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_MANAGER, &msg);
			break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

NodeData* MMDRigidManagerObject::Alloc()
{
	return NewObjClear(MMDRigidManagerObject);
}

BaseObject* MMDRigidManagerObject::FindRigid(const Int32 index) const
{
	// find index in rigid_list_
	if (const auto bone_link_ptr = rigid_list_.Find(index); bone_link_ptr)
	{
		return reinterpret_cast<BaseObject*>((*bone_link_ptr->GetValue())->ForceGetLink());
	}
	return nullptr;
}

const BaseContainer& MMDRigidManagerObject::GetRigidItems() const
{
	return rigid_items_;
}

const BaseContainer& MMDRigidManagerObject::GetBoneItems() const
{
	return bone_manager_data_->GetBoneItems();
}

namespace
{
	template <Int32 ID>
	void SetRigidParameter(BaseObject* object ,GeData data)
	{
		object->SetParameter(ConstDescID(DescLevel(ID)), data, DESCFLAGS_SET::NONE);
	}

	template<int... I>
	void SetNonCollisionGroups(BaseObject* rigid_object, uint16_t collisionGroup, std::integer_sequence<int, I...>)
	{
		(SetRigidParameter<RIGID_NON_COLLISION_GROUP_0 + I>(rigid_object, (collisionGroup >> I) & 0x01), ...);
	}
}

Bool MMDRigidManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting)
{
	if (!pmx_model)
		return false;

	if (!pmx_model->GetPhysicsManager())
		return false;

	const auto pmx_rigidbodies = pmx_model->GetPhysicsManager()->GetRigidBodys();
	if (!pmx_rigidbodies)
		return false;

	position_multiple_ = static_cast<float>(setting.position_multiple);

	const auto rigid_count = pmx_file.m_rigidbodies.size();
	for (size_t rigid_index = 0; rigid_index < rigid_count; ++rigid_index)
	{
		const auto& pmx_rigidbody = pmx_file.m_rigidbodies[rigid_index];
		const maxon::String name_local{ pmx_rigidbody.m_name.c_str() };
		const auto rigid_object = AddRigid(name_local);
		if (!rigid_object)
			return false;

		if (const auto rigid_node = rigid_object->GetNodeData<MMDRigidObject>())
		{
			rigid_node->mmd_rigidbody_ = (*pmx_rigidbodies)[rigid_index].get();
			rigid_node->rigid_manager_ = reinterpret_cast<BaseObject*>(Get());
			rigid_node->rigid_manager_data_ = this;
		}

		const maxon::String name_universal{ pmx_rigidbody.m_englishName.c_str() };
		SetRigidParameter<RIGID_NAME_LOCAL>(rigid_object, name_local);
		SetRigidParameter<RIGID_NAME_UNIVERSAL>(rigid_object, name_universal);
		SetRigidParameter<RIGID_NAME_IS>(rigid_object, setting.import_english);

		SetRigidParameter<RIGID_GROUP_ID>(rigid_object, pmx_rigidbody.m_group);
		SetRigidParameter<RIGID_RELATED_BONE_INDEX>(rigid_object, pmx_rigidbody.m_boneIndex);
		SetRigidParameter<RIGID_PHYSICS_MODE>(rigid_object, static_cast<uint8_t>(pmx_rigidbody.m_op));
		SetRigidParameter<RIGID_SHAPE_TYPE>(rigid_object, static_cast<uint8_t>(pmx_rigidbody.m_shape));

		const auto shape_size = pmx_rigidbody.m_shapeSize * position_multiple_;
		SetRigidParameter<RIGID_SHAPE_SIZE_X>(rigid_object, shape_size.x);
		SetRigidParameter<RIGID_SHAPE_SIZE_Y>(rigid_object, shape_size.y);
		SetRigidParameter<RIGID_SHAPE_SIZE_Z>(rigid_object, shape_size.z);

		SetRigidParameter<RIGID_SHAPE_POSITION_X>(rigid_object, pmx_rigidbody.m_translate.x);
		SetRigidParameter<RIGID_SHAPE_POSITION_Y>(rigid_object, pmx_rigidbody.m_translate.y);
		SetRigidParameter<RIGID_SHAPE_POSITION_Z>(rigid_object, pmx_rigidbody.m_translate.z);

		SetRigidParameter<RIGID_SHAPE_ROTATION_X>(rigid_object, pmx_rigidbody.m_rotate.x);
		SetRigidParameter<RIGID_SHAPE_ROTATION_Y>(rigid_object, pmx_rigidbody.m_rotate.y);
		SetRigidParameter<RIGID_SHAPE_ROTATION_Z>(rigid_object, pmx_rigidbody.m_rotate.z);

		SetNonCollisionGroups(rigid_object, pmx_rigidbody.m_collisionGroup, std::make_integer_sequence<int, 16>{});

		SetRigidParameter<RIGID_MASS>(rigid_object, pmx_rigidbody.m_mass);
		SetRigidParameter<RIGID_REPULSION>(rigid_object, pmx_rigidbody.m_repulsion);
		SetRigidParameter<RIGID_FRICTION_FORCE>(rigid_object, pmx_rigidbody.m_friction);
		SetRigidParameter<RIGID_MOVE_ATTENUATION>(rigid_object, pmx_rigidbody.m_translateDimmer);
		SetRigidParameter<RIGID_ROTATION_DAMPING>(rigid_object, pmx_rigidbody.m_rotateDimmer);
	}

	return true;
}

