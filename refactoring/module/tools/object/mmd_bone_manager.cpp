/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone_manager.h"
#include "cmt_tools_setting.h"
#include "mmd_model_manager.h"
#include "description/TMMDBone.h"
#include "module/tools/tag/mmd_bone.h"

NodeData* MMDBoneManagerObject::Alloc()
{
	return NewObjClear(MMDBoneManagerObject);
}

Bool MMDBoneManagerObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDBoneManagerObject*>(dest);
	dest_object->bone_name_index = bone_name_index;
	dest_object->rigid_manager_ = rigid_manager_;
	dest_object->joint_manager_ = joint_manager_;
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
	IOReadField(bone_name_index);
	IOReadField(model_manager_);
	IOReadField(rigid_manager_);
	IOReadField(joint_manager_);
	if (!io_util::ReadHashMap(hf, bone_list_))
		return false;
	return SUPER::Read(node, hf, level);
}

Bool MMDBoneManagerObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	IOWriteField(bone_name_index);
	IOWriteField(model_manager_);
	IOWriteField(rigid_manager_);
	IOWriteField(joint_manager_);
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
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_OFF };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_MOVABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_MOVABLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_VISIBLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_VISIBLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_ROTATABLE };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_ENABLED:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_ENABLED };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		case BONE_DISPLAY_TYPE_IK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE, BONE_DISPLAY_TYPE_IK };
			node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
			break;
		}
		default:
			break;
		}
		break;
	case BONE_MODE:
	{
		MMDBoneManagerObjectMsg msg(MMDBoneManagerObjectMsgType::BONE_MODE_CHANGE, BONE_DISPLAY_TYPE_OFF, nullptr, t_data.GetInt32());
		node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_MANAGER, &msg);
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
		const auto new_bone_tag = new_bone->MakeTag(ID_T_MMD_BONE);
		if(!new_bone_tag)
		{
			return;
		}
		const auto new_bone_node = new_bone_tag->GetNodeData<MMDBoneTag>();
		if(!new_bone_node)
		{
			return;
		}
		new_bone->SetName(new_bone->GetName() + "." + String::IntToString(bone_name_index++));
		new_bone_node->bone_tag_ = new_bone_tag;
		new_bone_node->bone_object_ = new_bone;
		new_bone_node->bone_manager_ = reinterpret_cast<BaseObject*>(node);
		new_bone_node->bone_manager_node_ = this;
		new_bone_node->RefreshColor();
		new_bone->InsertUnder(node);
	}
}

bool MMDBoneManagerObject::HandleMMDBoneTagMessage(GeListNode* node, void* data)
{
	iferr_scope_handler{
		return false;
	};
	Bool need_update_morph = false;
	switch (static_cast<MMDBoneTagMsg*>(data)->type)
	{
	case MMDBoneTagMsgType::BONE_INDEX_CHANGE:
		{
			HandleBoneIndexChangeMessage(node);
			break;
		}
	case MMDBoneTagMsgType::DEFAULT:
		break;
	}
	if (need_update_morph && model_manager_)
	{
		MMDBoneManagerObjectMsg msg{ MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE };
		model_manager_->Message(ID_O_MMD_BONE_MANAGER, &msg);
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
	maxon::Queue<BaseObject*> nodes;
	iferr(nodes.Push(op)) return true;
	while (!nodes.IsEmpty())
	{
		BaseObject* node_ = *nodes.Pop();
		while (node_)
		{
			if (node_->GetType() == Ojoint)
			{
				if (SDK2024_Const BaseTag* node_bone_tag = node_->GetTag(ID_T_MMD_BONE); node_bone_tag != nullptr)
				{
					GeData ge_data;
					node_bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), ge_data, DESCFLAGS_GET::NONE);
					const auto bone_index = node_bone_tag->GetNodeData<MMDBoneTag>()->GetBoneIndex();
					bone_items_.SetString(bone_index, node_->GetName());
					auto& link = bone_list_.InsertKey(bone_index)iferr_return;
					link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
					(*link)->SetLink(node_bone_tag);
				}
			}
			iferr(nodes.Push(node_->GetDown()))
				return true;
			if (node_ != op)
			{
				node_ = node_->GetNext();
			}
			else {
				break;
			}
		}
	}
	nodes.Reset();
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
	case ID_T_MMD_BONE:
	{
		if (!HandleMMDBoneTagMessage(node, data))
			return SUPER::Message(node, type, data);
		break;
	}
	case ID_O_MMD_MODEL:
	{
		if (const auto* msg = static_cast<MMDModelRootObjectMsg*>(data); msg != nullptr)
		{
			switch (msg->msg_type)
			{
				case MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE:
				{
					switch (msg->object_type)
					{
					case ManagerObjectType::JOINT_MANAGER:
					{
						joint_manager_ = msg->object;
						break;
					}
					case ManagerObjectType::RIGID_MANAGER:
					{
						rigid_manager_ = msg->object;
						break;
					}
					case ManagerObjectType::MODEL_MANAGER:
					{
						model_manager_ = msg->object;
						break;
					}
					case ManagerObjectType::DEFAULT: [[fallthrough]];
					case ManagerObjectType::MESH_MANAGER: [[fallthrough]];
					case ManagerObjectType::BONE_MANAGER:
						break;
					}
					break;
				}
				case MMDModelRootObjectMsgType::MODEL_MODE_CHANGE:
				{
					node->SetParameter(ConstDescID(DescLevel(BONE_MODE)), msg->model_mode, DESCFLAGS_SET::NONE);
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

Bool MMDBoneManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, maxon::BaseArray<BaseObject*>& bone_list, const CMTToolsSetting::ModelImport& setting)
{
	iferr_scope_handler{
		return false;
	};

	position_multiple = setting.position_multiple;

	if (!pmx_model)
		return false;

	node_manager_ = pmx_model->GetNodeManager();
	morph_manager_ = pmx_model->GetMorphManager();

	const auto& pmx_bones = pmx_file.m_bones;
	const auto pmx_bone_num = pmx_bones.size();
	if (pmx_bone_num == 0)
		return true;

	// create bone
	bone_list.EnsureCapacity(static_cast<Int>(pmx_bone_num))iferr_return;
	for (auto pmx_bone_index = decltype(pmx_bone_num){}; pmx_bone_index < pmx_bone_num; ++pmx_bone_index)
	{
		BaseObject* new_bone = BaseObject::Alloc(Ojoint);
		if (new_bone == nullptr)
			continue;
		new_bone->MakeTag(ID_T_MMD_BONE);
		bone_list.Append(new_bone)iferr_return;
	}

	// set bone data
	for (auto pmx_bone_index = decltype(pmx_bone_num){}; pmx_bone_index < pmx_bone_num; ++pmx_bone_index)
	{
		const auto& pmx_bone = pmx_bones[pmx_bone_index];

		const auto bone_object = bone_list[static_cast<Int>(pmx_bone_index)];
		if(!bone_object)
			continue;

		const auto bone_tag = bone_object->GetTag(ID_T_MMD_BONE);
		const auto bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();

		// init bone tag
		bone_tag_node->bone_tag_ = bone_tag;
		bone_tag_node->bone_object_ = bone_object;
		bone_tag_node->mmd_node_ = node_manager_->GetMMDNode(pmx_bone_index);
		bone_tag_node->bone_manager_ = reinterpret_cast<BaseObject*>(Get());
		bone_tag_node->bone_manager_node_ = this;

		// bone name
		const maxon::String bone_name_local{ pmx_bone.m_name.c_str() };
		const maxon::String bone_name_universal{ pmx_bone.m_englishName.c_str() };
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_LOCAL)), bone_name_local, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_UNIVERSAL)), bone_name_universal, DESCFLAGS_SET::NONE);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_IS)), setting.import_english, DESCFLAGS_SET::NONE);

		// set bone position
		const auto& bone_position = pmx_bone.m_position;
		Vector position(bone_position[0], bone_position[1], bone_position[2]);

		auto add_bone_to_root = [&bone_object, &bone_tag, &position, &setting, this]()
		{
			position *= setting.position_multiple;
			bone_object->SetFrozenPos(position);
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_POSITION)), position, DESCFLAGS_SET::NONE);
			bone_object->InsertUnder(Get());
		};

		// set parent bone
		if (const auto parent_bone_index = pmx_bone.m_parentBoneIndex; parent_bone_index == -1)
		{
			add_bone_to_root();
		}
		else
		{
			if (const auto parent_bone = bone_list[parent_bone_index]; parent_bone)
			{
				// set child position
				bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_POSITION)), position, DESCFLAGS_SET::NONE);
				const auto& parent_position = pmx_bones[parent_bone_index].m_position;
				position -= Vector(parent_position[0], parent_position[1], parent_position[2]);
				position *= setting.position_multiple;
				bone_object->SetFrozenPos(position);
				bone_object->InsertUnder(parent_bone);
			}
			else
			{
				add_bone_to_root();
			}
		}
		//bone_tag_node->HandleBoneIndexUpdate(bone_tag, bone_object, bone_tag->GetDataInstance());

		// set layer
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LAYER)), pmx_bone.m_deformDepth, DESCFLAGS_SET::NONE);

		// set rotatable
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_ROTATABLE)),
			static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AllowRotate), DESCFLAGS_SET::NONE);

		// set movable
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TRANSLATABLE)),
			static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AllowTranslate), DESCFLAGS_SET::NONE);

		// set visible
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_VISIBLE)),
			static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::Visible), DESCFLAGS_SET::NONE);

		// set enabled
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_ENABLED)),
			static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AllowControl), DESCFLAGS_SET::NONE);

		// set physics after deform
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PHYSICS_AFTER_DEFORM)),
			static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::DeformAfterPhysics), DESCFLAGS_SET::NONE);

		/// tail

		// set tail use index
		const bool is_tail_use_index = static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::TargetShowMode);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_IS_INDEX)), is_tail_use_index, DESCFLAGS_SET::NONE);

		if(is_tail_use_index)
		{
			// set tail index
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_INDEX)), pmx_bone.m_linkBoneIndex, DESCFLAGS_SET::NONE);
		}
		else
		{
			// set tail position
			const auto& tail_position = pmx_bone.m_positionOffset;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_TAIL_POSITION)), Vector(tail_position[0], tail_position[1], tail_position[2]) * setting.position_multiple, DESCFLAGS_SET::NONE);
		}

		/// inherit bone

		// set have append rotation
		const auto have_append_rotation = static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AppendRotate);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_ROTATION)), have_append_rotation, DESCFLAGS_SET::NONE);

		// set have append translation
		const auto have_append_translation = static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::AppendTranslate);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_TRANSLATION)), have_append_translation, DESCFLAGS_SET::NONE);

		if (have_append_rotation || have_append_translation)
		{
			// set inherit bone parent
			if (const auto append_parent_bone_index = pmx_bone.m_appendBoneIndex; append_parent_bone_index >= 0 && append_parent_bone_index < bone_list.GetCount())
				if (const auto inherit_parent_bone = bone_list[append_parent_bone_index]; inherit_parent_bone)
				{
					BaseLink* link = BaseLink::Alloc();
					link->SetLink(inherit_parent_bone);
					bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link, DESCFLAGS_SET::NONE);
				}

			// set inherit rate
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE)), pmx_bone.m_appendWeight, DESCFLAGS_SET::NONE);
		}

		/// fixed axis

		// set have fixed axis
		const auto have_fixed_axis = static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::FixedAxis);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IS_FIXED_AXIS)), have_fixed_axis, DESCFLAGS_SET::NONE);

		if (have_fixed_axis)
		{
			// set fixed axis
			const auto& fixed_axis = pmx_bone.m_fixedAxis;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_FIXED_AXIS)), Vector(fixed_axis[0], fixed_axis[1], fixed_axis[2]), DESCFLAGS_SET::NONE);
		}

		/// local axis

		// set have local axis
		const auto have_local_axis = static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::LocalAxis);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_IS_COORDINATE)), have_local_axis, DESCFLAGS_SET::NONE);

		if (have_local_axis)
		{
			// set local axis x
			const auto& local_axis_x = pmx_bone.m_localXAxis;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_X)), Vector(local_axis_x[0], local_axis_x[1], local_axis_x[2]), DESCFLAGS_SET::NONE);

			// set local axis z
			const auto& local_axis_z = pmx_bone.m_localZAxis;
			bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_Z)), Vector(local_axis_z[0], local_axis_z[1], local_axis_z[2]), DESCFLAGS_SET::NONE);
		}

		/// IK

		// set is IK
		const auto is_ik = static_cast<uint16_t>(pmx_bone.m_boneFlag) & static_cast<uint16_t>(libmmd::PMXBoneFlags::IK);
		bone_tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_IS_IK)), is_ik, DESCFLAGS_SET::NONE);

		if(is_ik)
		{
			/*const auto& ik_array = pmx_bone.m_ikLinks;
			const auto ik_bone_num = ik_array.size();
			if(ik_bone_num == 0)
				return true;
			if(const auto ik_begin_bone = bone_list[ik_array[ik_bone_num - 1].m_ikBoneIndex]; ik_begin_bone)
			{
				// create ik tag
				BaseTag* ik_tag = ik_begin_bone->MakeTag(1019561); // Ik tag ID : 1019561
				if(setting.import_english)
				{
					ik_tag->SetName(bone_name_universal);
				}
				else
				{
					ik_tag->SetName(bone_name_local);
				}
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_SOLVER)), ID_CA_IK_TAG_SOLVER_3D, DESCFLAGS_SET::NONE);
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_PREFERRED_WEIGHT)), 1, DESCFLAGS_SET::NONE);

				// set target link
				AutoAlloc<BaseLink> target_link;
				target_link->SetLink(bone_object);
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_TARGET)), target_link.Release(), DESCFLAGS_SET::NONE);

				// set tip link
				AutoAlloc<BaseLink> tip_link;
				if(const auto ik_target_bone = bone_list[pmx_bone.m_ikTargetBoneIndex]; ik_target_bone)
				{
					tip_link->SetLink(ik_target_bone);
				}
				ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_TIP)), tip_link.Release(), DESCFLAGS_SET::NONE);

				// add to model_root description
				if(!model_manager_->GetNodeData<MMDModelManagerObject>()->AddIKBoneDescription(bone_name_local, ik_tag))
					return false;

				// set ik limit
				for (auto ik_link_bone_index = size_t(); ik_link_bone_index < ik_bone_num; ++ik_link_bone_index)
				{
					const auto& pmx_ik_link_bone = ik_array[ik_link_bone_index];
					if(const auto ik_link_bone = bone_list[pmx_ik_link_bone.m_ikBoneIndex]; ik_link_bone)
					{
						if(!pmx_ik_link_bone.m_enableLimit)
							continue;

						const auto& limit_min = pmx_ik_link_bone.m_limitMin;
						const auto& limit_max = pmx_ik_link_bone.m_limitMax;

						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_MIN_ROT)),
							Vector(limit_min[0], limit_min[1], limit_min[2]) * setting.position_multiple, DESCFLAGS_SET::NONE);
						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_MAX_ROT)),
							Vector(limit_max[0], limit_max[1], limit_max[2]) * setting.position_multiple, DESCFLAGS_SET::NONE);
						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_H)), 1, DESCFLAGS_SET::NONE);
						ik_link_bone->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_B)), 1, DESCFLAGS_SET::NONE);
					}
				}
			}*/
		}
	}

	// send bone index change msg
	{
		/*MMDBoneTagBoneIndexChangeMsg msg;
		Get()->Message(ID_T_MMD_BONE, &msg);*/
	}

	// send description check update msg
	{
		DescriptionCheckUpdate msg;
		static auto msg_descid = ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK));
		msg.descid = &msg_descid;
		Get()->MultiMessage(MULTIMSG_ROUTE::BROADCAST, MSG_DESCRIPTION_CHECKUPDATE, &msg);
	}

	if (setting.import_expression)
	{
		/*const auto& pmx_morph_array = pmx_file.get_pmx_morph_array();
		const auto pmx_morph_num = pmx_morph_array.size();
		for (auto morph_index = decltype(pmx_morph_num){}; morph_index < pmx_morph_num; ++morph_index)
		{
			const auto& pmx_morph = pmx_morph_array[morph_index];
			if (pmx_morph.get_morph_offset_type() != libmmd::pmx_morph::morph_type::BONE)
				continue;

			const maxon::String morph_name_local{ pmx_morph.get_morph_name_local().c_str() };

			const auto& pmx_bone_morph_offset_array = pmx_morph.get_morph_offset_array();
			const auto pmx_bone_morph_offset_num = pmx_bone_morph_offset_array.size();

			if (pmx_bone_morph_offset_num == 0)
				continue;

			for (auto offset_index = decltype(pmx_bone_morph_offset_num){}; offset_index < pmx_bone_morph_offset_num; ++offset_index)
			{
				const auto& pmx_bone_morph_offset = reinterpret_cast<const libmmd::pmx_bone_morph_offset&>(pmx_bone_morph_offset_array[offset_index]);
				if (const auto bone_tag = FindBone(pmx_bone_morph_offset.get_bone_index()); bone_tag)
				{
					const auto bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
					const auto added_morph_index = bone_tag_node->AddBoneMorph(morph_name_local);
					if(added_morph_index == NOTOK)
						continue;
					const auto bone_translation = pmx_bone_morph_offset.get_bone_translation();
					const auto bone_rotation = pmx_bone_morph_offset.get_bone_rotation();
					bone_tag_node->SetBoneMorphTranslationNoCheck(added_morph_index, Vector(bone_translation[0], bone_translation[1], bone_translation[2]) * setting.position_multiple);
					bone_tag_node->SetBoneMorphRotationNoCheck(added_morph_index, Vector(bone_rotation[0], bone_rotation[1], bone_rotation[2]));
				}
			}
		}*/
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
	return bone_items_;
}

void MMDBoneManagerObject::CreateDisplayTag(GeListNode* node)
{}
