/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_rigid_root.h
Description:	MMD rigid root object

**************************************************************************/

#include "plugin_resource.h"
#include "mmd_bone.h"
#include "mmd_model_manager.h"
#include "mmd_rigid_manager.h"
#include "mmd_bone_manager.h"
#include "mmd_rigid.h"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include "utils/string_util.hpp"

namespace
{
	Int32 NormalizeRigidMode(const Int32 mode)
	{
		constexpr Int32 kLegacyRigidModeVmd = 2;
		return mode == kLegacyRigidModeVmd ? RIGID_MODE_ANIM : mode;
	}

	Int32 ResolveImportedBoneIndex(const maxon::BaseArray<BaseObject*>& bone_list, MMDBoneManagerObject* bone_manager, const Int32 imported_index)
	{
		if (imported_index < 0)
			return imported_index;
		if (imported_index >= bone_list.GetCount())
			return imported_index;

		BaseObject* const imported_bone_object = bone_list[imported_index];
		BaseTag* const imported_bone_tag = imported_bone_object ? imported_bone_object->GetTag(g_mmd_bone_tag_id) : nullptr;
		if (!imported_bone_tag || !bone_manager)
			return imported_index;

		const Int32 current_index = bone_manager->FindBoneIndex(imported_bone_tag);
		return current_index >= 0 ? current_index : imported_index;
	}
}

Bool MMDRigidManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	IOReadField(m_rigid_name_index_);
	if (!io_util::ReadHashMap(hf, rigid_list_))
		return false;
	if (!SUPER::Read(node, hf, level))
		return false;
	if (BaseContainer* const bc = node ? reinterpret_cast<BaseList2D*>(node)->GetDataInstance() : nullptr)
		bc->SetInt32(RIGID_MODE, NormalizeRigidMode(bc->GetInt32(RIGID_MODE)));
	return true;
}

SDK2024_Write(MMDRigidManagerObject)
{
	IOWriteField(m_rigid_name_index_);
	if (!io_util::WriteHashMap(hf, rigid_list_))
		return false;
	return SUPER::Write(node, hf);
}

SDK2024_CopyTo(MMDRigidManagerObject)
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDRigidManagerObject*>(dest);
	dest_object->m_rigid_name_index_ = m_rigid_name_index_;
	for (const auto& entry : rigid_list_)
	{
		auto& link = dest_object->rigid_list_.InsertKey(entry.GetKey())iferr_return;
		link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
		(*entry.GetValue())->CopyTo(*link, flags, trn);
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

BaseObject* MMDRigidManagerObject::AddRigid(const String& name, libmmd::MMDRigidBody* mmd_rigidbody, GeListNode* node)
{
	if (!node)
		node = Get();
	if (const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
	{
		if (BaseObject* new_rigid = BaseObject::Alloc(g_mmd_rigid_object_id))
		{
			if (name.IsEmpty())
				new_rigid->SetName(new_rigid->GetName() + "." + String::IntToString(m_rigid_name_index_++));
			else
				new_rigid->SetName(name);

			const auto new_rigid_data = new_rigid->GetNodeData<MMDRigidObject>();
			new_rigid_data->rigid_manager_data_ = this;
			new_rigid_data->rigid_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));
			new_rigid_data->mmd_rigidbody_ = mmd_rigidbody;

			new_rigid->InsertUnderLast(node);
			{
				MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, bc->GetInt32(RIGID_DISPLAY_TYPE));
				new_rigid->Message(g_mmd_rigid_manager_object_id, &msg);
			}
			{
				MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF, NormalizeRigidMode(bc->GetInt32(RIGID_MODE)));
				new_rigid->Message(g_mmd_rigid_manager_object_id, &msg);
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
			if (AddRigid({}, nullptr, node))
				UpdateRigidList();
			if (BaseObject* const parent = reinterpret_cast<BaseObject*>(node)->GetUp(); parent && parent->IsInstanceOf(g_mmd_model_manager_object_id))
			{
				if (auto* const model = parent->GetNodeData<MMDModelManagerObject>())
					model->InvalidateStandaloneRuntime();
			}
		}
		break;
	}
	case g_mmd_model_manager_object_id:
	{
		if (const auto msg = static_cast<MMDModelManagerObjectMsg*>(data); msg && msg->msg_type == MMDModelManagerObjectMsgType::MODEL_MODE_CHANGE)
		{
			node->SetParameter(ConstDescID(DescLevel(RIGID_MODE)), msg->model_mode, DESCFLAGS_SET::NONE);
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
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_rigid_manager_object_id, &msg);
			break;
		}
		case RIGID_DISPLAY_TYPE_ON:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_ON);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_rigid_manager_object_id, &msg);
			CreateDisplayTag(node);
			m_display_tag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE)), DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE, RIGID_DISPLAY_TYPE_WIRE);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_rigid_manager_object_id, &msg);
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
			const GeData normalized_mode(NormalizeRigidMode(t_data.GetInt32()));
			MMDRigidRootObjectMsg msg(MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE, RIGID_DISPLAY_TYPE_OFF, normalized_mode.GetInt32());
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_rigid_manager_object_id, &msg);
			return SUPER::SetDParameter(node, id, normalized_mode, flags);
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

Bool MMDRigidManagerObject::UpdateRigidList()
{
	iferr_scope_handler{
		return false;
	};
	const auto op = reinterpret_cast<BaseObject*>(Get());
	rigid_items_.FlushAll();
	rigid_items_.SetString(-1, "-"_s);
	rigid_list_.Reset();
	GeData ge_data;
	BaseObject* node_ = op->GetDown();
	while (node_)
	{
		if (node_->GetType() == g_mmd_rigid_object_id)
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
	return true;
}

const BaseContainer& MMDRigidManagerObject::GetRigidItems() const
{
	return rigid_items_;
}

const BaseContainer& MMDRigidManagerObject::GetBoneItems()
{
	return GetBoneManagerData()->GetBoneItems();
}

MMDBoneManagerObject* MMDRigidManagerObject::GetBoneManagerData()
{
	if (!bone_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(bone_manager_link_))
			bone_manager_data_ = obj->GetNodeData<MMDBoneManagerObject>();
	if (!bone_manager_data_)
	{
		if (auto* parent = reinterpret_cast<BaseObject*>(Get())->GetUp())
			if (parent->IsInstanceOf(g_mmd_model_manager_object_id))
				if (auto* model = parent->GetNodeData<MMDModelManagerObject>())
					if (auto* mgr = model->GetBoneManagerData())
					{
						bone_manager_data_ = mgr;
						bone_manager_link_->SetLink(reinterpret_cast<BaseObject*>(mgr->Get()));
					}
	}
	return bone_manager_data_;
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

Bool MMDRigidManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const maxon::BaseArray<BaseObject*>& bone_list, const CMTToolsSetting::ModelImport& setting)
{
	rigid_items_.FlushAll();
	rigid_items_.SetString(-1, "-"_s);
	MMDBoneManagerObject* const bone_manager = GetBoneManagerData();

	const auto rigid_count = pmx_file.m_rigidbodies.size();
	for (size_t rigid_index = 0; rigid_index < rigid_count; ++rigid_index)
	{
		const auto& pmx_rigidbody = pmx_file.m_rigidbodies[rigid_index];
		const maxon::String name_local{ pmx_rigidbody.m_name.c_str() };
		const auto rigid_object = AddRigid(name_local, nullptr);

		if (!rigid_object)
			return false;

		rigid_object->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)),
			String::IntToString(static_cast<Int32>(rigid_index)), DESCFLAGS_SET::NONE);

		rigid_items_.SetString(static_cast<Int32>(rigid_index), name_local);
		const maxon::String name_universal{ pmx_rigidbody.m_englishName.c_str() };
		SetRigidParameter<RIGID_NAME_LOCAL>(rigid_object, name_local);
		SetRigidParameter<RIGID_NAME_UNIVERSAL>(rigid_object, name_universal);
		SetRigidParameter<RIGID_NAME_IS>(rigid_object, setting.import_english);

		SetRigidParameter<RIGID_GROUP_ID>(rigid_object, pmx_rigidbody.m_group);
		SetRigidParameter<RIGID_RELATED_BONE_INDEX>(rigid_object,
			ResolveImportedBoneIndex(bone_list, bone_manager, pmx_rigidbody.m_boneIndex));
		SetRigidParameter<RIGID_PHYSICS_MODE>(rigid_object, static_cast<uint8_t>(pmx_rigidbody.m_op));
		SetRigidParameter<RIGID_SHAPE_TYPE>(rigid_object, static_cast<uint8_t>(pmx_rigidbody.m_shape));

		const Eigen::Vector3f& shape_size = pmx_rigidbody.m_shapeSize;
		SetRigidParameter<RIGID_SHAPE_SIZE_X>(rigid_object, shape_size.x());
		SetRigidParameter<RIGID_SHAPE_SIZE_Y>(rigid_object, shape_size.y());
		SetRigidParameter<RIGID_SHAPE_SIZE_Z>(rigid_object, shape_size.z());

		const Eigen::Vector3f& translate = pmx_rigidbody.m_translate;
		SetRigidParameter<RIGID_SHAPE_POSITION_X>(rigid_object, translate.x());
		SetRigidParameter<RIGID_SHAPE_POSITION_Y>(rigid_object, translate.y());
		SetRigidParameter<RIGID_SHAPE_POSITION_Z>(rigid_object, translate.z());
		rigid_object->SetRelPos(Vector(translate.x(), translate.y(), translate.z()));

		SetRigidParameter<RIGID_SHAPE_ROTATION_X>(rigid_object, pmx_rigidbody.m_rotate.x());
		SetRigidParameter<RIGID_SHAPE_ROTATION_Y>(rigid_object, pmx_rigidbody.m_rotate.y());
		SetRigidParameter<RIGID_SHAPE_ROTATION_Z>(rigid_object, pmx_rigidbody.m_rotate.z());

		SetNonCollisionGroups(rigid_object, pmx_rigidbody.m_collisionGroup, std::make_integer_sequence<int, 16>{});

		SetRigidParameter<RIGID_MASS>(rigid_object, pmx_rigidbody.m_mass);
		SetRigidParameter<RIGID_REPULSION>(rigid_object, pmx_rigidbody.m_repulsion);
		SetRigidParameter<RIGID_FRICTION_FORCE>(rigid_object, pmx_rigidbody.m_friction);
		SetRigidParameter<RIGID_MOVE_ATTENUATION>(rigid_object, pmx_rigidbody.m_translateDimmer);
		SetRigidParameter<RIGID_ROTATION_DAMPING>(rigid_object, pmx_rigidbody.m_rotateDimmer);
	}

	if (!UpdateRigidList())
		return false;

	return true;
}

namespace
{
	template <Int32 ID>
	Float32 GetRigidFloat(const BaseContainer* bc)
	{
		return static_cast<Float32>(bc->GetFloat(ID));
	}

	uint16_t ReadCollisionGroupMask(const BaseContainer* bc)
	{
		uint16_t mask = 0;
		for (int i = 0; i < 16; ++i)
		{
			if (bc->GetInt32(RIGID_NON_COLLISION_GROUP_0 + i))
				mask |= static_cast<uint16_t>(1 << i);
		}
		return mask;
	}
}

Bool MMDRigidManagerObject::BuildStandaloneRigidBodies(libmmd::MMDPhysicsManager* physics_manager, const std::function<libmmd::IMMDNode*(Int32)>& get_node)
{
	if (!physics_manager)
		return false;

	const auto op = reinterpret_cast<BaseObject*>(Get());
	Int32 created = 0;
	Int32 unbound = 0;
	Int32 failed = 0;

	std::vector<std::pair<Int32, BaseObject*>> sorted_children;
	for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
	{
		if (child->GetType() == g_mmd_rigid_object_id)
		{
			GeData ge_data;
			child->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), ge_data, DESCFLAGS_GET::NONE);
			const Int32 rigid_index = ge_data.GetString().ToInt32(nullptr);
			sorted_children.emplace_back(rigid_index, child);
		}
	}
	std::stable_sort(sorted_children.begin(), sorted_children.end(),
		[](const auto& a, const auto& b) { return a.first < b.first; });

	for (const auto& [rigid_index, child] : sorted_children)
	{
		const BaseContainer* bc = child->GetDataInstance();
		if (!bc)
			return false;

		const auto shape = static_cast<libmmd::PMXRigidbody::Shape>(bc->GetInt32(RIGID_SHAPE_TYPE));
		const Eigen::Vector3f shapeSize(
			GetRigidFloat<RIGID_SHAPE_SIZE_X>(bc),
			GetRigidFloat<RIGID_SHAPE_SIZE_Y>(bc),
			GetRigidFloat<RIGID_SHAPE_SIZE_Z>(bc)
		);
		const Eigen::Vector3f translate(
			GetRigidFloat<RIGID_SHAPE_POSITION_X>(bc),
			GetRigidFloat<RIGID_SHAPE_POSITION_Y>(bc),
			GetRigidFloat<RIGID_SHAPE_POSITION_Z>(bc)
		);
		const Eigen::Vector3f rotate(
			GetRigidFloat<RIGID_SHAPE_ROTATION_X>(bc),
			GetRigidFloat<RIGID_SHAPE_ROTATION_Y>(bc),
			GetRigidFloat<RIGID_SHAPE_ROTATION_Z>(bc)
		);

		const auto mass = GetRigidFloat<RIGID_MASS>(bc);
		const auto linearDamping = GetRigidFloat<RIGID_MOVE_ATTENUATION>(bc);
		const auto angularDamping = GetRigidFloat<RIGID_ROTATION_DAMPING>(bc);
		const auto repulsion = GetRigidFloat<RIGID_REPULSION>(bc);
		const auto friction = GetRigidFloat<RIGID_FRICTION_FORCE>(bc);

		const auto op_mode = static_cast<libmmd::PMXRigidbody::Operation>(bc->GetInt32(RIGID_PHYSICS_MODE));
		const auto group = static_cast<uint8_t>(bc->GetInt32(RIGID_GROUP_ID));
		const auto collisionGroup = ReadCollisionGroupMask(bc);

		libmmd::PMXRigidbody pmx_rigidbody;
		pmx_rigidbody.m_shape = shape;
		pmx_rigidbody.m_shapeSize = shapeSize;
		pmx_rigidbody.m_translate = translate;
		pmx_rigidbody.m_rotate = rotate;
		pmx_rigidbody.m_mass = mass;
		pmx_rigidbody.m_translateDimmer = linearDamping;
		pmx_rigidbody.m_rotateDimmer = angularDamping;
		pmx_rigidbody.m_repulsion = repulsion;
		pmx_rigidbody.m_friction = friction;
		pmx_rigidbody.m_op = op_mode;
		pmx_rigidbody.m_group = group;
		pmx_rigidbody.m_collisionGroup = collisionGroup;
		pmx_rigidbody.m_boneIndex = bc->GetInt32(RIGID_RELATED_BONE_INDEX);
		pmx_rigidbody.m_name = string_util::GetStdString(child->GetName());

		auto* rb = physics_manager->AddRigidBody();
		libmmd::IMMDNode* const node = get_node ? get_node(pmx_rigidbody.m_boneIndex) : nullptr;
		if (node == nullptr)
			++unbound;

		if (!rb->Create(pmx_rigidbody, node))
		{
			++failed;
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT] BuildStandaloneRigidBodies[@]: Create FAILED, name='@' boneIndex=@",
				rigid_index, child->GetName(), pmx_rigidbody.m_boneIndex);
			continue;
		}

		++created;
		if (created <= 3)
		{
			const auto transform = rb->GetTransform();
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT] BuildStandaloneRigidBodies[@]: name='@' boneIndex=@ bodyOff=(@,@,@) shapeOff=(@,@,@)",
				rigid_index, child->GetName(), pmx_rigidbody.m_boneIndex,
				transform(0, 3), transform(1, 3), transform(2, 3),
				pmx_rigidbody.m_translate.x(), pmx_rigidbody.m_translate.y(), pmx_rigidbody.m_translate.z());
		}
	}

	if (!UpdateRigidList())
		return false;

	DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
		"[CMT] BuildStandaloneRigidBodies: total=@ created=@ unbound=@ failed=@",
		sorted_children.size(), created, unbound, failed);
	return true;
}

void MMDRigidManagerObject::ReconnectRigidBodyPointers(libmmd::MMDPhysicsManager* physics_manager)
{
	if (!physics_manager)
		return;

	auto* rigid_bodies = physics_manager->GetRigidBodys();
	if (!rigid_bodies)
		return;

	const auto op = reinterpret_cast<BaseObject*>(Get());

	std::vector<std::pair<Int32, BaseObject*>> sorted_children;
	for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
	{
		if (child->GetType() == g_mmd_rigid_object_id)
		{
			GeData ge_data;
			child->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), ge_data, DESCFLAGS_GET::NONE);
			const Int32 rigid_index = ge_data.GetString().ToInt32(nullptr);
			sorted_children.emplace_back(rigid_index, child);
		}
	}
	std::stable_sort(sorted_children.begin(), sorted_children.end(),
		[](const auto& a, const auto& b) { return a.first < b.first; });

	for (size_t i = 0; i < sorted_children.size() && i < rigid_bodies->size(); ++i)
	{
		auto* rigid_data = sorted_children[i].second->GetNodeData<MMDRigidObject>();
		rigid_data->mmd_rigidbody_ = (*rigid_bodies)[i].get();
		rigid_data->rigid_manager_data_ = this;
		rigid_data->rigid_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));
	}
}

