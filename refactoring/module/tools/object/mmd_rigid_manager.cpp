/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_rigid_root.h
Description:	MMD rigid root object

**************************************************************************/

#include "pch.h"
#include "mmd_model.h"
#include "mmd_rigid_manager.h"
#include "mmd_rigid.h"

Bool MMDRigidManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	if (!hf->ReadInt64(&m_rigid_name_index))
		return false;
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		if (!temp_link->Read(hf))
			return false;
		m_bone_manager = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_joint_manager = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
	}
	// m_rigid_list
	{
		Int64 rigid_list_count = 0;
		if (!hf->ReadInt64(&rigid_list_count))
			return false;
		while (rigid_list_count--)
		{
			Int32 rigid_index = 0;
			if (!hf->ReadInt32(&rigid_index))
				return false;
			auto& link = m_rigid_list.InsertKey(rigid_index)iferr_return;
			link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
			if (!(*link)->Read(hf))
				return false;
		}
	}
	return SUPER::Read(node, hf, level);
}

Bool MMDRigidManagerObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	if (!hf->WriteInt64(m_rigid_name_index))
		return false;
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		temp_link->SetLink(m_bone_manager);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_joint_manager);
		if (!temp_link->Write(hf))
			return false;
	}
	// m_rigid_list
	{
		if (!hf->WriteInt64(m_rigid_list.GetCount()))
			return false;
		for (const auto& rigid_link : m_rigid_list)
		{
			if (hf->WriteInt32(!rigid_link.GetKey()))
				return false;
			if (!(*rigid_link.GetValue())->Write(hf))
				return false;
		}
	}
	return SUPER::Write(node, hf);
}

Bool MMDRigidManagerObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDRigidManagerObject*>(dest);
	dest_object->m_rigid_name_index = m_rigid_name_index;
	dest_object->m_bone_manager = m_bone_manager;
	dest_object->m_joint_manager = m_joint_manager;
	for (const auto& entry : m_rigid_list)
	{
		auto& link = dest_object->m_rigid_list.InsertKey(entry.GetKey())iferr_return;
		link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
		(*entry.GetValue())->CopyTo(*link, flags, trn);
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

BaseObject* MMDRigidManagerObject::AddRigidbody(const String& name, GeListNode* node)
{
	if (!node)
		node = Get();
	if (const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
	{
		if (BaseObject* new_rigid = BaseObject::Alloc(ID_O_MMD_RIGID))
		{
			if (name.IsEmpty())
				new_rigid->SetName(new_rigid->GetName() + "." + String::IntToString(m_rigid_name_index++));
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
			AddRigidbody({}, node);
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
						m_bone_manager = msg->object;
					}
					else if (msg->object_type == ManagerObjectType::JOINT_MANAGER)
					{
						m_joint_manager = msg->object;
					}
					break;
				}
			case MMDModelRootObjectMsgType::MODEL_MODE_CHANGE:
				{
					auto flag = DESCFLAGS_SET::NONE;
					SetDParameter(node, ConstDescID(DescLevel(RIGID_MODE)), GeData(msg->model_mode), flag);
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
		switch (t_data.GetInt32())
		{
		case RIGID_MODE_ANIM:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF, RIGID_MODE_ANIM);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_MANAGER, &msg);
			break;
		}
		case RIGID_MODE_EDIT:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF, RIGID_MODE_EDIT);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_RIGID_MANAGER, &msg);
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

NodeData* MMDRigidManagerObject::Alloc()
{
	return NewObjClear(MMDRigidManagerObject);
}

BaseObject* MMDRigidManagerObject::FindRigid(const Int32 index) const
{
	// find index in m_rigid_list
	if (const auto bone_link_ptr = m_rigid_list.Find(index); bone_link_ptr)
	{
		return static_cast<BaseObject*>((*bone_link_ptr->GetValue())->ForceGetLink());
	}
	return nullptr;
}

const BaseContainer& MMDRigidManagerObject::GetRigidItems() const
{
	return rigid_items;
}

BaseObject* MMDRigidManagerObject::GetBoneManager() const
{
	return m_bone_manager;
}

namespace
{
	template <Int32 ID>
	void SetRigidParameterT(BaseObject* object ,GeData data)
	{
		object->SetParameter(ConstDescID(DescLevel(ID)), data, DESCFLAGS_SET::NONE);
	}

	template<int... I>
	void SetNonCollisionGroups(BaseObject* rigid_object, uint16_t collisionGroup, std::integer_sequence<int, I...>)
	{
		(SetRigidParameterT<RIGID_NON_COLLISION_GROUP_0 + I>(rigid_object, (collisionGroup >> I) & 0x01), ...);
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

	const auto rigid_count = pmx_file.m_rigidbodies.size();
	for (size_t rigid_index = 0; rigid_index < rigid_count; ++rigid_index)
	{
		const auto& pmx_rigidbody = pmx_file.m_rigidbodies[rigid_index];
		const maxon::String name_local{ pmx_rigidbody.m_name.c_str() };
		auto rigid_object = AddRigidbody(name_local);
		if (!rigid_object)
			return false;
		const maxon::String name_universal{ pmx_rigidbody.m_englishName.c_str() };
		SetRigidParameterT<RIGID_NAME_LOCAL>(rigid_object, name_local);
		SetRigidParameterT<RIGID_NAME_UNIVERSAL>(rigid_object, name_universal);
		SetRigidParameterT<RIGID_NAME_IS>(rigid_object, setting.import_english);

		SetRigidParameterT<RIGID_GROUP_ID>(rigid_object, pmx_rigidbody.m_group);
		SetRigidParameterT<RIGID_RELATED_BONE_INDEX>(rigid_object, pmx_rigidbody.m_boneIndex);
		SetRigidParameterT<RIGID_PHYSICS_MODE>(rigid_object, static_cast<uint8_t>(pmx_rigidbody.m_op));
		SetRigidParameterT<RIGID_SHAPE_TYPE>(rigid_object, static_cast<uint8_t>(pmx_rigidbody.m_shape));

		const auto shape_size = pmx_rigidbody.m_shapeSize * static_cast<float>(setting.position_multiple);
		SetRigidParameterT<RIGID_SHAPE_SIZE_X>(rigid_object, shape_size.x);
		SetRigidParameterT<RIGID_SHAPE_SIZE_Y>(rigid_object, shape_size.y);
		SetRigidParameterT<RIGID_SHAPE_SIZE_Z>(rigid_object, shape_size.z);

		const auto translate = pmx_rigidbody.m_translate * static_cast<float>(setting.position_multiple);
		SetRigidParameterT<RIGID_SHAPE_POSITION_X>(rigid_object, translate.x);
		SetRigidParameterT<RIGID_SHAPE_POSITION_Y>(rigid_object, translate.y);
		SetRigidParameterT<RIGID_SHAPE_POSITION_Z>(rigid_object, translate.z);

		SetRigidParameterT<RIGID_SHAPE_ROTATION_X>(rigid_object, pmx_rigidbody.m_rotate.x);
		SetRigidParameterT<RIGID_SHAPE_ROTATION_Y>(rigid_object, pmx_rigidbody.m_rotate.y);
		SetRigidParameterT<RIGID_SHAPE_ROTATION_Z>(rigid_object, pmx_rigidbody.m_rotate.z);

		SetNonCollisionGroups(rigid_object, pmx_rigidbody.m_collisionGroup, std::make_integer_sequence<int, 16>{});

		SetRigidParameterT<RIGID_MASS>(rigid_object, pmx_rigidbody.m_mass);
		SetRigidParameterT<RIGID_REPULSION>(rigid_object, pmx_rigidbody.m_repulsion);
		SetRigidParameterT<RIGID_FRICTION_FORCE>(rigid_object, pmx_rigidbody.m_friction);
		SetRigidParameterT<RIGID_MOVE_ATTENUATION>(rigid_object, pmx_rigidbody.m_translateDimmer);
		SetRigidParameterT<RIGID_ROTATION_DAMPING>(rigid_object, pmx_rigidbody.m_rotateDimmer);

		if (const auto rigid_node = rigid_object->GetNodeData<MMDRigidObject>())
		{
			rigid_node->m_rigid_body = (*pmx_rigidbodies)[rigid_index].get();
		}
	}

	return true;
}

