/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_bone_manager.h"
#include "cmt_tools_setting.h"
#include "mmd_model_manager.h"
#include "description/TMMDBone.h"
#include "maxon/queue.h"
#include "module/tools/tag/mmd_bone.h"
#include "utils/string_util.hpp"
#include "libMMD/Model/MMD/PMXModel.h"

NodeData* MMDBoneManagerObject::Alloc()
{
	return NewObjClear(MMDBoneManagerObject);
}

SDK2024_CopyTo(MMDBoneManagerObject)
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDBoneManagerObject*>(dest);
	dest_object->bone_name_index_ = bone_name_index_;
	for (const auto& entry : bone_list_)
	{
		auto& link = dest_object->bone_list_.InsertKey(entry.GetKey())iferr_return;
		link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
		(*entry.GetValue())->CopyTo(*link, flags, trn);
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDBoneManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	IOReadField(bone_name_index_);
	if (!io_util::ReadHashMap(hf, bone_list_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] BoneManager::Read: FAILED at bone_list_");
		return false;
	}
	return SUPER::Read(node, hf, level);
}

SDK2024_Write(MMDBoneManagerObject)
{
	IOWriteField(bone_name_index_);
	if (!io_util::WriteHashMap(hf, bone_list_))
		return false;
	return SUPER::Write(node, hf);
}

Bool MMDBoneManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	const auto op = reinterpret_cast<BaseObject*>(node);

	switch (id[0].id)
	{
	case BONE_DISPLAY_TYPE:
		switch (t_data.GetInt32())
		{
		case BONE_DISPLAY_TYPE_ON:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg { MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_ON };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_OFF };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_MOVABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_MOVABLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_VISIBLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_VISIBLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_ROTATABLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ENABLED:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_ENABLED };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_IK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_IK };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
			break;
		}
		default:
			break;
		}
		break;
	case BONE_MODE:
	{
		MMDBoneManagerObjectMsg msg(MMDBoneManagerObjectMsgType::BONE_MODE_CHANGE, BONE_DISPLAY_TYPE_OFF, nullptr, t_data.GetInt32());
		node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

void MMDBoneManagerObject::HandleDescriptionCommandMessage(GeListNode* node, void* data)
{
	if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_BONE_BUTTON)
	{
		BaseObject* new_bone = BaseObject::Alloc(Ojoint);
		if (!new_bone)
		{
			return;
		}
		const auto new_bone_tag = new_bone->MakeTag(g_mmd_bone_tag_id);
		if(!new_bone_tag)
		{
			return;
		}
		const auto new_bone_node = new_bone_tag->GetNodeData<MMDBoneTag>();
		if(!new_bone_node)
		{
			return;
		}
		new_bone->SetName(new_bone->GetName() + "." + String::IntToString(bone_name_index_++));
		new_bone_node->bone_object_ = new_bone;
		new_bone_node->bone_manager_data_ = this;
		new_bone_node->bone_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));
		new_bone_node->RefreshColor();
		new_bone->InsertUnder(node);
	}
}

bool MMDBoneManagerObject::HandleMMDBoneTagMessage(GeListNode* node, void* data)
{
	iferr_scope_handler{
		return false;
	};
	if(!data)
		return false;
	bool need_update_morph = false;
	const auto* msg = static_cast<MMDBoneTagMsg*>(data);
	switch (msg->type)
	{
	case MMDBoneTagMsgType::BONE_INDEX_CHANGE:
		{
			HandleBoneIndexChangeMessage(node);
			break;
		}
	case MMDBoneTagMsgType::BONE_MORPH_ADD:
	{
		auto* entry = bone_morph_map_.Find(msg->name);
		maxon::PointerArray<MorphUIData>* morph_list;
		if (entry)
		{
			morph_list = &entry->GetValue();
			for (const auto& hub : *morph_list)
			{
				if (hub.Compare(msg->bone_tag, msg->strength_id))
					goto EXIT;
			}
		}
		else
		{
			morph_list = &bone_morph_map_.InsertKey(msg->name)iferr_return;
		}
		morph_list->Append(MorphUIData(msg->bone_tag, msg->strength_id))iferr_return;
		need_update_morph = true;
		break;
	}
	case MMDBoneTagMsgType::BONE_MORPH_DELETE:
	{
		auto* entry = bone_morph_map_.Find(msg->name);
		if (entry)
		{
			auto& morph_list = entry->GetValue();
			for (Int i = 0; i < morph_list.GetCount(); i++)
			{
				if (morph_list[i].Compare(msg->bone_tag, msg->strength_id))
				{
					morph_list.Erase(i)iferr_return;
					need_update_morph = true;
					break;
				}
			}
			if (morph_list.IsEmpty())
			{
				bone_morph_map_.Erase(msg->name)iferr_return;
			}
		}
		break;
	}
	case MMDBoneTagMsgType::BONE_MORPH_RENAME:
	{
		auto* old_entry = bone_morph_map_.Find(msg->name_old);
		if (old_entry)
		{
			auto& old_list = old_entry->GetValue();
			for (Int i = 0; i < old_list.GetCount(); i++)
			{
				if (old_list[i].Compare(msg->bone_tag, msg->strength_id))
				{
					auto* new_entry = bone_morph_map_.Find(msg->name);
					maxon::PointerArray<MorphUIData>* new_list;
					if (new_entry)
					{
						new_list = &new_entry->GetValue();
						for (const auto& hub : *new_list)
						{
							if (hub.Compare(msg->bone_tag, msg->strength_id))
								goto EXIT;
						}
					}
					else
					{
						new_list = &bone_morph_map_.InsertKey(msg->name)iferr_return;
					}
					new_list->Append(std::move(old_list[i]))iferr_return;
					old_list.Erase(i)iferr_return;
					need_update_morph = true;
					break;
				}
			}
			if (old_list.IsEmpty())
			{
				bone_morph_map_.Erase(msg->name_old)iferr_return;
			}
		}
		break;
	}
	case MMDBoneTagMsgType::DEFAULT:
		break;
	}
EXIT:
	if (need_update_morph)
	{
		if (auto* model_mgr = io_util::ResolveObjectLink(model_manager_))
		{
			MMDBoneManagerObjectMsg morph_msg{ MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE };
			model_mgr->Message(g_mmd_bone_manager_object_id, &morph_msg);
		}
	}
	return true;
}

bool MMDBoneManagerObject::HandleBoneIndexChangeMessage(GeListNode* node)
{
	iferr_scope_handler{
		return false;
	};
	const auto op = reinterpret_cast<BaseObject*>(node);
	bone_items_.FlushAll();
	bone_items_.SetString(-1, "-"_s);
	bone_list_.Reset();
	maxon::Queue<BaseObject*> objects;
	objects.Push(op)iferr_return;
	while (!objects.IsEmpty())
	{
		BaseObject* object = *objects.Pop();
		while (object)
		{
			if (object->GetType() == Ojoint)
			{
				if (SDK2024_Const BaseTag* node_bone_tag = object->GetTag(g_mmd_bone_tag_id); node_bone_tag != nullptr)
				{
					GeData ge_data;
					node_bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), ge_data, DESCFLAGS_GET::NONE);
					const Int32 bone_index_from_node = node_bone_tag->GetNodeData<MMDBoneTag>()->GetBoneIndex();
					const auto bone_index = (bone_index_from_node >= 0) ? bone_index_from_node : ge_data.GetString().ToInt32(nullptr);
					bone_items_.SetString(bone_index, object->GetName());
					auto& link = bone_list_.InsertKey(bone_index)iferr_return;
					link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
					(*link)->SetLink(node_bone_tag);
				}
			}
			objects.Push(object->GetDown())iferr_return;
			if (object != op)
				object = object->GetNext();
			else
				break;
		}
	}
	objects.Reset();
	return true;
}

Bool MMDBoneManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return SUPER::Message(node, type, data);
	};
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		HandleDescriptionCommandMessage(node, data);
		break;
	}
	case g_mmd_bone_tag_id:
	{
		if (!HandleMMDBoneTagMessage(node, data))
			return SUPER::Message(node, type, data);
		break;
	}
	case g_mmd_model_manager_object_id:
	{
		if (const auto* msg = static_cast<MMDModelManagerObjectMsg*>(data); msg != nullptr)
		{
			switch (msg->msg_type)
			{
				case MMDModelManagerObjectMsgType::MANAGER_OBJECT_UPDATE:
					model_manager_->SetLink(msg->object);
					break;
				case MMDModelManagerObjectMsgType::MODEL_MODE_CHANGE:
					node->SetParameter(ConstDescID(DescLevel(BONE_MODE)), msg->model_mode, DESCFLAGS_SET::NONE);
					break;
				case MMDModelManagerObjectMsgType::DEFAULT:
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

BaseTag* MMDBoneManagerObject::FindBone(const Int32 index) const
{
	// find index in bone_list_
	if (const auto bone_link_ptr = bone_list_.Find(index); bone_link_ptr)
	{
		return reinterpret_cast<BaseTag*>((*bone_link_ptr->GetValue())->ForceGetLink());
	}
	return nullptr;
}

Int32 MMDBoneManagerObject::FindBoneIndex(const BaseTag* bone_tag) const
{
	if(!bone_tag)
	{
		return -1;
	}
	// get index from bone
	const auto bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
	if(!bone_tag_node)
	{
		return -1;
	}
	const Int32 bone_index = bone_tag_node->GetBoneIndex();
	// find index in bone_list_
	if(!bone_list_.Contains(bone_index))
	{
		return -1;
	}
	return bone_index;
}

Bool MMDBoneManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, maxon::BaseArray<BaseObject*>& bone_list, const CMTToolsSetting::ModelImport& setting)
{
	iferr_scope_handler{
		return false;
	};

	const auto& pmx_bones = pmx_file.m_bones;
	const auto pmx_bone_num = pmx_bones.size();
	if (pmx_bone_num == 0)
		return true;

	bone_items_.FlushAll();
	bone_items_.SetString(-1, "-"_s);

	// create bone
	bone_list.SetCapacityHint(static_cast<Int>(pmx_bone_num))iferr_return;
	for (auto pmx_bone_index = decltype(pmx_bone_num){}; pmx_bone_index < pmx_bone_num; ++pmx_bone_index)
	{
		BaseObject* new_bone = BaseObject::Alloc(Ojoint);
		if (new_bone == nullptr)
			continue;
		new_bone->MakeTag(g_mmd_bone_tag_id);
		bone_list.Append(new_bone)iferr_return;
	}

	// set bone data
	for (auto mmd_bone_index = decltype(pmx_bone_num){}; mmd_bone_index < pmx_bone_num; ++mmd_bone_index)
	{
		const auto& mmd_bone = pmx_bones[mmd_bone_index];

		const auto bone_object = bone_list[static_cast<Int>(mmd_bone_index)];
		if(!bone_object)
			continue;

		const auto bone_tag = bone_object->GetTag(g_mmd_bone_tag_id);
		const auto bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();

		bone_tag_node->bone_object_ = bone_object;
		bone_tag_node->mmd_node_ = mmd_node_manager_->GetMMDNode(mmd_bone_index);
		bone_tag_node->bone_manager_data_ = this;
		bone_tag_node->bone_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));

		// bone name
		const maxon::String bone_name_local{ mmd_bone.m_name.c_str() };
		const maxon::String bone_name_universal{ mmd_bone.m_englishName.c_str() };
		bone_items_.SetString(static_cast<Int32>(mmd_bone_index), bone_name_local);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_LOCAL)), bone_name_local, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_UNIVERSAL)), bone_name_universal, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_IS)), setting.import_english, DESCFLAGS_SET::NONE);

		// set bone position
		const auto& bone_position = mmd_bone.m_position;
		Vector position(bone_position[0], bone_position[1], bone_position[2]);

		auto add_bone_to_manager = [&bone_object, &bone_tag, &position, this]()
		{
			bone_object->SetFrozenPos(position);
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_POSITION)), position, DESCFLAGS_SET::NONE);
			bone_object->InsertUnder(Get());
		};

		// set parent bone
		if (const auto parent_bone_index = mmd_bone.m_parentBoneIndex; parent_bone_index == -1)
		{
			add_bone_to_manager();
		}
		else
		{
			if (const auto parent_bone = bone_list[parent_bone_index]; parent_bone)
			{
				bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_POSITION)), position, DESCFLAGS_SET::NONE);
				const auto& parent_position = pmx_bones[parent_bone_index].m_position;
				position -= Vector(parent_position[0], parent_position[1], parent_position[2]);
				bone_object->SetFrozenPos(position);
				bone_object->InsertUnder(parent_bone);
			}
			else
			{
				add_bone_to_manager();
			}
		}
		//bone_tag_node->HandleBoneIndexUpdate(bone_tag, bone_object, bone_tag->GetDataInstance());

		// set layer
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LAYER)), mmd_bone.m_deformDepth, DESCFLAGS_SET::NONE);

		// set rotatable
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_ROTATABLE)),
			static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AllowRotate), DESCFLAGS_SET::NONE);

		// set movable
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TRANSLATABLE)),
			static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AllowTranslate), DESCFLAGS_SET::NONE);

		// set visible
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_VISIBLE)),
			static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::Visible), DESCFLAGS_SET::NONE);

		// set enabled
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_ENABLED)),
			static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AllowControl), DESCFLAGS_SET::NONE);

		// set physics after deform
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PHYSICS_AFTER_DEFORM)),
			static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::DeformAfterPhysics), DESCFLAGS_SET::NONE);

		// set append local
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_LOCAL)),
			static_cast<bool>(static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AppendLocal)), DESCFLAGS_SET::NONE);

		// set outer parent
		const auto have_outer_parent = static_cast<bool>(static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::DeformOuterParent));
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_OUTER_PARENT)), have_outer_parent, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_OUTER_PARENT_KEY)),
			have_outer_parent ? mmd_bone.m_keyValue : 0, DESCFLAGS_SET::NONE);

		/// tail

		// set tail use index
		const bool is_tail_use_index = static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::TargetShowMode);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_IS_INDEX)), is_tail_use_index, DESCFLAGS_SET::NONE);

		if(is_tail_use_index)
		{
			// set tail index
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_INDEX)), mmd_bone.m_linkBoneIndex, DESCFLAGS_SET::NONE);
		}
		else
		{
			// set tail position
			const auto& tail_position = mmd_bone.m_positionOffset;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_POSITION)), Vector(tail_position[0], tail_position[1], tail_position[2]), DESCFLAGS_SET::NONE);
		}

		/// append bone

		// set have append rotation
		const auto have_append_rotation = static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AppendRotate);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_ROTATION)), have_append_rotation, DESCFLAGS_SET::NONE);

		// set have append translation
		const auto have_append_translation = static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AppendTranslate);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_TRANSLATION)), have_append_translation, DESCFLAGS_SET::NONE);

		if (have_append_rotation || have_append_translation)
		{
			// set inherit bone parent
			if (const auto append_parent_bone_index = mmd_bone.m_appendBoneIndex; append_parent_bone_index >= 0 && append_parent_bone_index < bone_list.GetCount())
				if (const auto inherit_parent_bone = bone_list[append_parent_bone_index]; inherit_parent_bone)
				{
					BaseLink* link = BaseLink::Alloc();
					link->SetLink(inherit_parent_bone);
					bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link, DESCFLAGS_SET::NONE);
				}

			// set inherit rate
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE)), mmd_bone.m_appendWeight, DESCFLAGS_SET::NONE);
		}

		/// fixed axis

		// set have fixed axis
		const auto have_fixed_axis = static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::FixedAxis);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IS_FIXED_AXIS)), have_fixed_axis, DESCFLAGS_SET::NONE);

		if (have_fixed_axis)
		{
			// set fixed axis
			const auto& fixed_axis = mmd_bone.m_fixedAxis;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_FIXED_AXIS)), Vector(fixed_axis[0], fixed_axis[1], fixed_axis[2]), DESCFLAGS_SET::NONE);
		}

		/// local axis

		// set have local axis
		const auto have_local_axis = static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::LocalAxis);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_IS_COORDINATE)), have_local_axis, DESCFLAGS_SET::NONE);

		if (have_local_axis)
		{
			// set local axis x
			const auto& local_axis_x = mmd_bone.m_localXAxis;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_X)), Vector(local_axis_x[0], local_axis_x[1], local_axis_x[2]), DESCFLAGS_SET::NONE);

			// set local axis z
			const auto& local_axis_z = mmd_bone.m_localZAxis;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_Z)), Vector(local_axis_z[0], local_axis_z[1], local_axis_z[2]), DESCFLAGS_SET::NONE);
		}

		/// IK

		// set is IK
		const auto& is_IK = bone_tag_node->is_IK = static_cast<uint16_t>(mmd_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::IK);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IS_IK)), is_IK, DESCFLAGS_SET::NONE);

		if(is_IK)
		{
			if (auto* pmx_node = static_cast<libmmd::PMXNode*>(mmd_node_manager_->GetMMDNode(mmd_bone_index)))
				bone_tag_node->ik_solver_ = pmx_node->GetIKSolver();
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IK_TARGET_BONE_INDEX)), mmd_bone.m_ikTargetBoneIndex, DESCFLAGS_SET::NONE);
			MAXON_SCOPE // set IK target link
			{
				BaseLink* ik_target_link = BaseLink::Alloc();
				ik_target_link->SetLink(bone_list[mmd_bone.m_ikTargetBoneIndex]);
				bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IK_TARGET_BONE_LINK)), ik_target_link, DESCFLAGS_SET::NONE);
			}
			// 直接写容器并同步 solver，避免 SetParameter 在描述未就绪时崩溃
			if (BaseContainer* const bc = bone_tag->GetDataInstance())
			{
				bc->SetInt32(PMX_BONE_IK_ITERATION, mmd_bone.m_ikIterationCount);
				bc->SetFloat(PMX_BONE_IK_UNIT_ANGLE, static_cast<Float>(mmd_bone.m_ikLimit));
			}
			if (bone_tag_node->ik_solver_)
			{
				bone_tag_node->ik_solver_->SetIterateCount(static_cast<uint32_t>(mmd_bone.m_ikIterationCount));
				bone_tag_node->ik_solver_->SetLimitAngle(static_cast<float>(mmd_bone.m_ikLimit));
			}
			if (DynamicDescription* const dynamic_description = bone_tag->GetDynamicDescriptionWritable())
			{
/*			pmx bone ik link UI:
 *			pmx_bone_ik_link_grp
 *			|-- ik_bone_index_grp
 *				|-- ik_bone_index
 *				|-- ik_bone_link
 *			|-- pmx_bone_ik_link_enable_limit
 *			|-- pmx_bone_ik_link_limit_min
 *			|-- pmx_bone_ik_link_limit_max
 */
				const auto pmx_bone_ik_link_num = mmd_bone.m_ikLinks.size();
				for (size_t i = 0; i < pmx_bone_ik_link_num; ++i)
				{
					const auto& pmx_bone_ik_link = mmd_bone.m_ikLinks[i];

					BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
					bc.SetString(DESC_NAME, String(pmx_bones[pmx_bone_ik_link.m_ikBoneIndex].m_name.c_str()));
					bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(PMX_BONE_IK_LINKS_GRP))));
					const auto pmx_bone_ik_link_grp = dynamic_description->Alloc(bc);

					MAXON_SCOPE // IK bone group
					{
						bc = GetCustomDataTypeDefault(DTYPE_GROUP);
						bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(pmx_bone_ik_link_grp));
						bc.SetInt32(DESC_COLUMNS, 2);
						const auto ik_bone_index_grp = dynamic_description->Alloc(bc);

						bc = GetCustomDataTypeDefault(DTYPE_LONG);
						bc.SetString(DESC_NAME, GeLoadString(IDS_CMT_MODEL_MANAGER_IK_BONE));
						bc.SetInt32(DESC_DEFAULT, pmx_bone_ik_link.m_ikBoneIndex);
						bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
						bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ik_bone_index_grp));
						const auto ik_bone_idx_id = dynamic_description->Alloc(bc);
						bone_tag->SetParameter(ik_bone_idx_id, GeData(static_cast<Int32>(pmx_bone_ik_link.m_ikBoneIndex)), DESCFLAGS_SET::NONE);

						bc = GetCustomDataTypeDefault(DTYPE_BASELISTLINK);
						MAXON_SCOPE // set IK bone link
						{
							BaseLink* ik_bone_link = BaseLink::Alloc();
							ik_bone_link->SetLink(bone_list[pmx_bone_ik_link.m_ikBoneIndex]);
							bc.SetData(DESC_DEFAULT, ik_bone_link);
						}
						bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
						bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ik_bone_index_grp));
						const auto ik_bone_link_id = dynamic_description->Alloc(bc);
						MAXON_SCOPE
						{
							BaseLink* ik_bone_link = BaseLink::Alloc();
							ik_bone_link->SetLink(bone_list[pmx_bone_ik_link.m_ikBoneIndex]);
							bone_tag->SetParameter(ik_bone_link_id, GeData(ik_bone_link), DESCFLAGS_SET::NONE);
						}
					}

				bc = GetCustomDataTypeDefault(DTYPE_BOOL);
				bc.SetString(DESC_NAME, GeLoadString(IDS_CMT_MODEL_MANAGER_IK_ENABLE_LIMIT));
				bc.SetBool(DESC_DEFAULT, pmx_bone_ik_link.m_enableLimit);
				bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
				bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(pmx_bone_ik_link_grp));
				const auto enable_limit_id = dynamic_description->Alloc(bc);
				bone_tag->SetParameter(enable_limit_id, GeData(pmx_bone_ik_link.m_enableLimit), DESCFLAGS_SET::NONE);

				bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
				bc.SetString(DESC_NAME, GeLoadString(IDS_CMT_MODEL_MANAGER_IK_LIMIT_MIN));
				const Vector limit_min(pmx_bone_ik_link.m_limitMin.x(), pmx_bone_ik_link.m_limitMin.y(), pmx_bone_ik_link.m_limitMin.z());
				bc.SetVector(DESC_DEFAULT, limit_min);
				bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
				bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(pmx_bone_ik_link_grp));
				const auto limit_min_id = dynamic_description->Alloc(bc);
				bone_tag->SetParameter(limit_min_id, GeData(limit_min), DESCFLAGS_SET::NONE);

				bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
				bc.SetString(DESC_NAME, GeLoadString(IDS_CMT_MODEL_MANAGER_IK_LIMIT_MAX));
				const Vector limit_max(pmx_bone_ik_link.m_limitMax.x(), pmx_bone_ik_link.m_limitMax.y(), pmx_bone_ik_link.m_limitMax.z());
				bc.SetVector(DESC_DEFAULT, limit_max);
				bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
				bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(pmx_bone_ik_link_grp));
				const auto limit_max_id = dynamic_description->Alloc(bc);
				bone_tag->SetParameter(limit_max_id, GeData(limit_max), DESCFLAGS_SET::NONE);
				}
			}
		}
	}

	// send bone index change msg
	HandleBoneIndexChangeMessage(Get());

	// send description check update msg
	{
		DescriptionCheckUpdate msg;
		static auto desc_id = ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK));
		msg.descid = &desc_id;
		Get()->MultiMessage(MULTIMSG_ROUTE::BROADCAST, MSG_DESCRIPTION_CHECKUPDATE, &msg);
	}

	if (setting.import_expression)
	{
		for (const auto& pmx_morph : pmx_file.m_morphs)
		{
			if (pmx_morph.m_morphType != libmmd::PMXMorphType::Bone)
				continue;

			const maxon::String morph_name_local{ pmx_morph.m_name.c_str() };

			if (pmx_morph.m_boneMorph.empty())
				continue;

			for (const auto& bone_offset : pmx_morph.m_boneMorph)
			{
				if (const auto bone_tag = FindBone(bone_offset.m_boneIndex); bone_tag)
				{
					const auto bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
					const auto added_morph_index = bone_tag_node->AddBoneMorph(morph_name_local);
					if (added_morph_index == NOTOK)
						continue;
					const auto& pos = bone_offset.m_position;
					const auto& quat = bone_offset.m_quaternion;
					const auto euler = quat.toRotationMatrix().canonicalEulerAngles(0, 1, 2);
					bone_tag_node->SetBoneMorphTranslationNoCheck(added_morph_index,
						Vector(pos.x(), pos.y(), pos.z()));
					bone_tag_node->SetBoneMorphRotationNoCheck(added_morph_index,
						Vector(euler.x(), euler.y(), euler.z()));
				}
			}
		}
	}

	return true;
}

Bool MMDBoneManagerObject::SavePMX(libmmd::PMXFile& pmx_model, const CMTToolsSetting::ModelExport& setting)
{
		iferr_scope_handler{
		return false;
	};

	const auto bone_num = bone_list_.GetCount();
	if (bone_num == 0)
		return true;

	auto& pmx_bone_array = pmx_model.m_bones;
	pmx_bone_array.resize(pmx_bone_array.size() + bone_num);
	// set bone data
	for (const auto& bone_data : bone_list_)
	{
		const auto bone_tag = reinterpret_cast<BaseTag*>((*bone_data.GetSecond())->ForceGetLink());
		const auto bone_index = bone_data.GetFirst();

		auto& pmx_bone = pmx_bone_array[bone_index];

		// bone name
		GeData data;
		bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_LOCAL)), data, DESCFLAGS_GET::NONE);
		pmx_bone.m_name = string_util::GetStdString(data.GetString());

		bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_UNIVERSAL)), data, DESCFLAGS_GET::NONE);
		pmx_bone.m_englishName = string_util::GetStdString(data.GetString());

		// set bone position
		bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_POSITION)), data, DESCFLAGS_GET::NONE);
		const Vector position = data.GetVector();
		pmx_bone.m_position = { maxon::SafeConvert<float>(position.x), maxon::SafeConvert<float>(position.y), maxon::SafeConvert<float>(position.z) };

		// set parent bone
		bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_INDEX)), data, DESCFLAGS_GET::NONE);
		bool error = false;
		pmx_bone.m_parentBoneIndex = data.GetString().ToInt32(&error);
		if (error)
			pmx_bone.m_parentBoneIndex = -1;
	}
	return true;
}

const BaseContainer& MMDBoneManagerObject::GetBoneItems() const
{
	if (bone_items_.GetIndexId(0) == NOTOK ||
		(bone_items_.GetIndexId(0) == -1 && bone_items_.GetIndexId(1) == NOTOK))
	{
		bone_items_.FlushAll();
		bone_items_.SetString(-1, "-"_s);
		SDK2024_Const BaseDocument* doc = Get()->GetDocument();
		if (!doc)
			doc = GetActiveDocument();
		for (const auto& entry : bone_list_)
		{
			if (entry.GetValue() && *entry.GetValue())
			{
				const BaseTag* tag = static_cast<const BaseTag*>((*entry.GetValue())->GetLink(doc));
				if (tag)
				{
					if (const BaseObject* obj = const_cast<BaseTag*>(tag)->GetObject())
						bone_items_.SetString(static_cast<Int32>(entry.GetKey()), obj->GetName());
				}
			}
		}
	}
	return bone_items_;
}

Bool MMDBoneManagerObject::RebuildNodes(libmmd::PMXModel* model)
{
	iferr_scope_handler{
		return false;
	};
	if (bone_list_.IsEmpty())
		return true;

	std::vector<Int32> sorted_indices;
	for (const auto& entry : bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	const Int32 bone_count = static_cast<Int32>(sorted_indices.size());

	for (Int32 i = 0; i < bone_count; ++i)
	{
		if (sorted_indices[i] != i)
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildNodes: index gap at i=@, sorted_indices[i]=@", i, sorted_indices[i]);
			return false;
		}
	}

	auto* node_manager = model->GetNodeManager();

	// Build reverse lookup: BaseObject* -> bone_index (using C4D hierarchy instead of STATICTEXT PMX_BONE_PARENT_BONE_INDEX)
	maxon::HashMap<BaseObject*, Int32> obj_to_bone_index;
	for (const auto& entry : bone_list_)
	{
		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (tag && tag->GetObject())
		{
			obj_to_bone_index.Insert(tag->GetObject(), static_cast<Int32>(entry.GetKey()))iferr_return;
		}
	}

	// Determine parent bone index for each bone from C4D joint hierarchy
	maxon::BaseArray<Int32> parent_indices;
	parent_indices.Resize(bone_count)iferr_return;
	for (Int32 i = 0; i < bone_count; ++i)
	{
		parent_indices[i] = -1;
		BaseTag* tag = FindBone(i);
		if (!tag || !tag->GetObject()) continue;

		BaseObject* parent_obj = tag->GetObject()->GetUp();
		if (!parent_obj) continue;

		if (auto* found = obj_to_bone_index.Find(parent_obj))
			parent_indices[i] = found->GetValue();
	}

	// Pass 1: create nodes with basic properties
	for (Int32 i = 0; i < bone_count; ++i)
	{
		BaseTag* tag = FindBone(i);
		if (!tag) continue;

		const BaseContainer* bc = tag->GetDataInstance();
		if (!bc) continue;

		auto* node = model->AddNode();
		node->SetName(string_util::GetStdString(bc->GetString(PMX_BONE_NAME_LOCAL)));
		node->SetDeformDepth(bc->GetInt32(PMX_BONE_LAYER));
		node->EnableDeformAfterPhysics(bc->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM));
	}

	maxon::BaseArray<Eigen::Vector3f> raw_positions;
	raw_positions.Resize(bone_count)iferr_return;

	for (Int32 i = 0; i < bone_count; ++i)
	{
		BaseTag* tag = FindBone(i);
		if (!tag) continue;

		const BaseContainer* bc = tag->GetDataInstance();
		if (!bc) continue;

		const Vector c4d_pos = bc->GetVector(PMX_BONE_POSITION);
		raw_positions[i] = Eigen::Vector3f(
			static_cast<float>(c4d_pos.x),
			static_cast<float>(c4d_pos.y),
			static_cast<float>(c4d_pos.z));
	}

	// Pass 2: hierarchy and transforms
	for (Int32 i = 0; i < bone_count; ++i)
	{
		BaseTag* tag = FindBone(i);
		if (!tag) continue;

		const BaseContainer* bc = tag->GetDataInstance();
		if (!bc) continue;

		auto* node = static_cast<libmmd::PMXNode*>(node_manager->GetMMDNode(i));
		const Int32 parent_bone_index = parent_indices[i];

		Eigen::Vector3f node_translate;
		if (parent_bone_index >= 0 && parent_bone_index < bone_count)
		{
			auto* parent_node = node_manager->GetMMDNode(parent_bone_index);
			parent_node->AddChild(node);
			node_translate = raw_positions[i] - raw_positions[parent_bone_index];
		}
		else
		{
			node_translate = raw_positions[i];
		}
		node->SetTranslate(node_translate);

		Eigen::Matrix4f init = Eigen::Matrix4f::Identity();
		init.block<3,1>(0,3) = raw_positions[i];
		node->SetGlobalTransform(init);
		node->CalculateInverseInitTransform();
	}

	// Pass 3: append properties + SaveInitialTRS
	for (Int32 i = 0; i < bone_count; ++i)
	{
		BaseTag* tag = FindBone(i);
		if (!tag) continue;

		const BaseContainer* bc = tag->GetDataInstance();
		if (!bc) continue;

		auto* node = static_cast<libmmd::PMXNode*>(node_manager->GetMMDNode(i));

		const bool has_inherit_rot = bc->GetBool(PMX_BONE_INHERIT_ROTATION);
		const bool has_inherit_trans = bc->GetBool(PMX_BONE_INHERIT_TRANSLATION);
		node->EnableAppendRotate(has_inherit_rot);
		node->EnableAppendTranslate(has_inherit_trans);

		if (has_inherit_rot || has_inherit_trans)
		{
			node->EnableAppendLocal(bc->GetBool(PMX_BONE_INHERIT_LOCAL));
			node->SetAppendWeight(static_cast<float>(bc->GetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE)));

			GeData link_data;
			tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link_data, DESCFLAGS_GET::NONE);
			if (const BaseLink* link = link_data.GetBaseLink())
			{
				if (BaseList2D* linked_obj = link->GetLink(tag->GetDocument()))
				{
					auto* append_obj = static_cast<BaseObject*>(linked_obj);
					if (auto* found = obj_to_bone_index.Find(append_obj))
					{
						const Int32 append_index = found->GetValue();
						if (append_index >= 0 && append_index < bone_count)
							node->SetAppendNode(static_cast<libmmd::PMXNode*>(node_manager->GetMMDNode(append_index)));
					}
				}
			}
		}

		node->SaveInitialTRS();
	}

	// Pass 4: IK solvers
	const String name_ik_bone = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_BONE);
	const String name_enable_limit = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_ENABLE_LIMIT);
	const String name_limit_min = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_LIMIT_MIN);
	const String name_limit_max = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_LIMIT_MAX);
	Int32 ik_solver_count = 0;

	for (Int32 i = 0; i < bone_count; ++i)
	{
		BaseTag* tag = FindBone(i);
		if (!tag) continue;

		const BaseContainer* bc = tag->GetDataInstance();
		if (!bc || !bc->GetBool(PMX_BONE_IS_IK)) continue;

		auto* solver = model->AddIKSolver();
		auto* ik_node = static_cast<libmmd::PMXNode*>(node_manager->GetMMDNode(i));
		solver->SetIKNode(ik_node);
		ik_node->SetIKSolver(solver);

		const Int32 target_index = bc->GetInt32(PMX_BONE_IK_TARGET_BONE_INDEX);
		if (target_index >= 0 && target_index < static_cast<Int32>(node_manager->GetNodeCount()))
			solver->SetTargetNode(node_manager->GetMMDNode(target_index));

		solver->SetIterateCount(static_cast<uint32_t>(bc->GetInt32(PMX_BONE_IK_ITERATION)));
		solver->SetLimitAngle(static_cast<float>(bc->GetFloat(PMX_BONE_IK_UNIT_ANGLE)));

		DynamicDescription* dyn_desc = tag->GetDynamicDescriptionWritable();
		if (dyn_desc)
		{
			struct ChainEntry
			{
				Int32 bone_idx = -1;
				Bool enable_limit = false;
				Vector limit_min;
				Vector limit_max;
			};
			maxon::BaseArray<ChainEntry> entries;

			void* browse_handle = dyn_desc->BrowseInit();
			DescID dyn_id;
			const BaseContainer* dyn_bc = nullptr;

			while (dyn_desc->BrowseGetNext(browse_handle, &dyn_id, &dyn_bc))
			{
				if (!dyn_bc) continue;

				const String name = dyn_bc->GetString(DESC_NAME);
				GeData value;

				if (name == name_ik_bone)
				{
					ChainEntry entry;
					if (tag->GetParameter(dyn_id, value, DESCFLAGS_GET::NONE))
						entry.bone_idx = value.GetInt32();
					entries.Append(std::move(entry))iferr_ignore("IK chain rebuild"_s);
				}
				else if (!entries.IsEmpty())
				{
					auto& cur = entries[entries.GetCount() - 1];
					if (name == name_enable_limit)
					{
						if (tag->GetParameter(dyn_id, value, DESCFLAGS_GET::NONE))
							cur.enable_limit = value.GetBool();
					}
					else if (name == name_limit_min)
					{
						if (tag->GetParameter(dyn_id, value, DESCFLAGS_GET::NONE))
							cur.limit_min = value.GetVector();
					}
					else if (name == name_limit_max)
					{
						if (tag->GetParameter(dyn_id, value, DESCFLAGS_GET::NONE))
							cur.limit_max = value.GetVector();
					}
				}
			}
			dyn_desc->BrowseFree(browse_handle);

			for (const auto& entry : entries)
			{
				if (entry.bone_idx < 0 || entry.bone_idx >= static_cast<Int32>(node_manager->GetNodeCount()))
					continue;
				auto* chain_node = node_manager->GetMMDNode(entry.bone_idx);
				if (!chain_node) continue;

				if (entry.enable_limit)
				{
					const Eigen::Vector3f lmin(
						static_cast<float>(entry.limit_min.x),
						static_cast<float>(entry.limit_min.y),
						static_cast<float>(entry.limit_min.z));
					const Eigen::Vector3f lmax(
						static_cast<float>(entry.limit_max.x),
						static_cast<float>(entry.limit_max.y),
						static_cast<float>(entry.limit_max.z));
					solver->AddIKChain(chain_node, true, lmin, lmax);
				}
				else
				{
					solver->AddIKChain(chain_node);
				}
				chain_node->EnableIK(true);
			}

		}

		solver->BuildChainPath();
		++ik_solver_count;
	}

	DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildNodes: IK solvers created=@", ik_solver_count);
	model->SortNodes();
	DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildNodes: complete. nodes=@", model->GetNodeManager()->GetNodeCount());
	return true;
}

void MMDBoneManagerObject::ReconnectNodePointers(libmmd::MMDNodeManager* node_manager, libmmd::MMDIKManager* ik_manager)
{
	maxon::HashMap<BaseObject*, Int32> obj_to_index;
	for (const auto& entry : bone_list_)
	{
		const Int32 bone_index = static_cast<Int32>(entry.GetKey());
		if (bone_index < 0 || bone_index >= static_cast<Int32>(node_manager->GetNodeCount()))
			continue;

		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!tag) continue;

		auto* bone_tag = tag->GetNodeData<MMDBoneTag>();
		if (!bone_tag) continue;

		bone_tag->mmd_node_ = node_manager->GetMMDNode(bone_index);
		bone_tag->bone_object_ = tag->GetObject();
		bone_tag->bone_manager_data_ = this;
		bone_tag->bone_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));

		tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), String::IntToString(bone_index), DESCFLAGS_SET::NONE);
		if (tag->GetObject())
		{
			obj_to_index.Insert(tag->GetObject(), bone_index)iferr_ignore("");
		}

		const BaseContainer* bc = tag->GetDataInstance();
		if (bc && bc->GetBool(PMX_BONE_IS_IK) && bone_tag->mmd_node_)
		{
			auto* pmx_node = static_cast<libmmd::PMXNode*>(bone_tag->mmd_node_);
			bone_tag->ik_solver_ = pmx_node->GetIKSolver();
			bone_tag->is_IK = true;
			const auto state = tag->GetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), true);
			tag->SetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), ~DESCIDSTATE::HIDDEN & state);
		}
		else
		{
			const auto state = tag->GetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), true);
			tag->SetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), DESCIDSTATE::HIDDEN | state);
		}
	}

	for (const auto& entry : bone_list_)
	{
		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!tag || !tag->GetObject()) continue;

		BaseObject* parent_obj = tag->GetObject()->GetUp();
		if (parent_obj)
		{
			if (auto* found = obj_to_index.Find(parent_obj))
				tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_INDEX)), String::IntToString(found->GetValue()), DESCFLAGS_SET::NONE);
			else
				tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_INDEX)), "-1"_s, DESCFLAGS_SET::NONE);
		}
		else
		{
			tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_INDEX)), "-1"_s, DESCFLAGS_SET::NONE);
		}
	}

	mmd_node_manager_ = node_manager;

	Int32 mismatch_count = 0;
	for (const auto& entry : bone_list_)
	{
		const Int32 bone_index = static_cast<Int32>(entry.GetKey());
		if (bone_index < 0 || bone_index >= static_cast<Int32>(node_manager->GetNodeCount()))
			continue;

		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!tag || !tag->GetObject()) continue;

		auto* mmd_node = node_manager->GetMMDNode(bone_index);
		if (!mmd_node) continue;

		const Int32 mmd_parent_idx = mmd_node->GetParent()
			? static_cast<Int32>(mmd_node->GetParent()->GetIndex()) : -1;

		Int32 c4d_parent_idx = -1;
		if (BaseObject* parent_obj = tag->GetObject()->GetUp())
		{
			if (auto* found = obj_to_index.Find(parent_obj))
				c4d_parent_idx = found->GetValue();
		}

		if (mmd_parent_idx != c4d_parent_idx)
		{
			if (mismatch_count < 10)
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] MISMATCH bone[@] '@': libmmd_parent=@ c4d_parent=@",
					bone_index, String(mmd_node->GetName().c_str()), mmd_parent_idx, c4d_parent_idx);
			mismatch_count++;
		}

		const String c4d_name = tag->GetDataInstance()->GetString(PMX_BONE_NAME_LOCAL);
		const String mmd_name(mmd_node->GetName().c_str());
		if (c4d_name != mmd_name)
		{
			if (mismatch_count < 10)
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] NAME MISMATCH bone[@]: c4d='@' libmmd='@'",
					bone_index, c4d_name, mmd_name);
			mismatch_count++;
		}
	}
	DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] ReconnectNodePointers: verified @ bones, @ mismatches",
		bone_list_.GetCount(), mismatch_count);
}

void MMDBoneManagerObject::SetAllBoneMode(const Int32 mode)
{
	for (const auto& entry : bone_list_)
	{
		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!tag) continue;

		auto* bone_tag = tag->GetNodeData<MMDBoneTag>();
		if (!bone_tag) continue;

		bone_tag->HandleBoneModeChange(mode);
	}
}

void MMDBoneManagerObject::CreateDisplayTag(GeListNode* node)
{}
