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
#include "mmd_rigid.h"
#include "mmd_rigid_manager.h"
#include "customgui_priority.h"
#include "description/TMMDBone.h"
#include "maxon/queue.h"
#include "module/tools/tag/mmd_bone.h"
#include "utils/string_util.hpp"
#include "libMMD/Model/MMD/PMXModel.h"
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace
{
	Int32 NormalizeBoneMode(const Int32 mode)
	{
		constexpr Int32 kLegacyBoneModeVmd = 2;
		return mode == kLegacyBoneModeVmd ? BONE_MODE_ANIM : mode;
	}

	bool IsPhysicsDebugLoggingEnabled()
	{
		const char* const value = std::getenv("CMT_INITIAL_STATE_DEBUG");
		if (!value || !*value)
			return false;
		return std::strcmp(value, "0") != 0 && std::strcmp(value, "false") != 0 && std::strcmp(value, "FALSE") != 0;
	}

	String GetBoneTagName(const BaseTag* tag, const Bool use_local_name)
	{
		if (!tag)
			return String();

		GeData data;
		const Int32 param_id = use_local_name ? PMX_BONE_NAME_LOCAL : PMX_BONE_NAME_UNIVERSAL;
		if (tag->GetParameter(CreateDescID(DescLevel(param_id)), data, DESCFLAGS_GET::NONE))
		{
			const String name = data.GetString();
			if (!name.IsEmpty())
				return name;
		}

		if (const BaseObject* const object = tag->GetObject())
			return object->GetName();

		return String();
	}

	std::string BuildBoneDebugLabel(const BaseTag* tag, const Int32 bone_index)
	{
		String bone_name = GetBoneTagName(tag, true);
		if (bone_name.IsEmpty())
			bone_name = GetBoneTagName(tag, false);

		std::ostringstream stream;
		stream << bone_index;
		if (!bone_name.IsEmpty())
			stream << ":" << string_util::GetStdString(bone_name);
		return stream.str();
	}

	String JoinBoneDebugLabels(const std::vector<std::string>& labels)
	{
		std::ostringstream stream;
		for (size_t index = 0; index < labels.size(); ++index)
		{
			if (index > 0)
				stream << ", ";
			stream << labels[index];
		}
		return String(stream.str().c_str());
	}

	BaseTag* ResolveInheritSourceBoneTag(MMDBoneManagerObject* bone_manager, BaseTag* self_tag)
	{
		if (!bone_manager || !self_tag)
			return nullptr;

		const BaseContainer* const bc = self_tag->GetDataInstance();
		if (!bc)
			return nullptr;

		const BaseDocument* const doc = self_tag->GetDocument();
		GeData link_data;
		if (self_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link_data, DESCFLAGS_GET::NONE))
		{
			if (const BaseLink* const link = link_data.GetBaseLink())
			{
				const BaseList2D* linked = doc ? link->GetLink(doc) : link->ForceGetLink();
				BaseList2D* const linked_mutable = const_cast<BaseList2D*>(linked);
				if (linked_mutable)
				{
					if (linked_mutable->IsInstanceOf(g_mmd_bone_tag_id))
					{
						if (BaseTag* const linked_tag = static_cast<BaseTag*>(linked_mutable); linked_tag != self_tag)
							return linked_tag;
					}
					if (linked_mutable->IsInstanceOf(Ojoint))
					{
						if (BaseObject* const linked_object = static_cast<BaseObject*>(linked_mutable))
						{
							if (BaseTag* const linked_tag = linked_object->GetTag(g_mmd_bone_tag_id); linked_tag && linked_tag != self_tag)
								return linked_tag;
						}
					}
				}
			}
		}

		const Int32 source_index = bc->GetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX);
		if (source_index < 0)
			return nullptr;

		if (BaseTag* const source_tag = bone_manager->FindBone(source_index))
		{
			if (source_tag != self_tag)
				return source_tag;
		}
		return nullptr;
	}

	Int32 ReadBoneIndexParameter(const BaseTag* bone_tag)
	{
		if (!bone_tag)
			return NOTOK;

		GeData data;
		if (!bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), data, DESCFLAGS_GET::NONE))
			return NOTOK;
		return data.GetString().ToInt32(nullptr);
	}

	Int32 RemapRigidRelatedBoneIndices(BaseObject* rigid_manager_object, const std::unordered_map<Int32, Int32>& remap)
	{
		if (!rigid_manager_object || remap.empty())
			return 0;

		Int32 remapped_count = 0;
		for (BaseObject* rigid_object = rigid_manager_object->GetDown(); rigid_object; rigid_object = rigid_object->GetNext())
		{
			if (!rigid_object->IsInstanceOf(g_mmd_rigid_object_id))
				continue;

			const BaseContainer* const rigid_bc = rigid_object->GetDataInstance();
			if (!rigid_bc)
				continue;

			const Int32 old_bone_index = rigid_bc->GetInt32(RIGID_RELATED_BONE_INDEX);
			if (old_bone_index < 0)
				continue;

			const auto it = remap.find(old_bone_index);
			if (it == remap.end() || it->second == old_bone_index)
				continue;

			rigid_object->SetParameter(ConstDescID(DescLevel(RIGID_RELATED_BONE_INDEX)), it->second, DESCFLAGS_SET::NONE);
			rigid_object->SetDirty(DIRTYFLAGS::DATA);
			++remapped_count;
		}
		return remapped_count;
	}

	bool BoneNeedsPrephysicsPlayback(
		MMDBoneManagerObject* bone_manager,
		BaseTag* bone_tag,
		std::unordered_map<const BaseTag*, bool>& memo,
		std::unordered_set<const BaseTag*>& visiting)
	{
		if (!bone_manager || !bone_tag)
			return false;

		if (const auto it = memo.find(bone_tag); it != memo.end())
			return it->second;

		if (!visiting.insert(bone_tag).second)
			return false;

		auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
		const BaseContainer* const bc = bone_tag->GetDataInstance();
		Bool needs_prepare = false;
		if (bone_tag_node && bc)
		{
			needs_prepare = bc->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM);
			if (!needs_prepare && (bc->GetBool(PMX_BONE_INHERIT_ROTATION) || bc->GetBool(PMX_BONE_INHERIT_TRANSLATION)))
			{
				if (BaseTag* const source_tag = ResolveInheritSourceBoneTag(bone_manager, bone_tag))
					needs_prepare = BoneNeedsPrephysicsPlayback(bone_manager, source_tag, memo, visiting);
			}
		}

		visiting.erase(bone_tag);
		memo[bone_tag] = needs_prepare;
		return needs_prepare;
	}

	void ConfigureBoneManagerExecutionPriority(GeListNode* node)
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
				pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, 6000);
				bc->SetData(EXPRESSION_PRIORITY, priority);
			}
		}
	}

	Matrix BuildBoneRelativeMatrix(const Vector& translation, const std::array<Float32, 4>& rotation)
	{
		const Eigen::Matrix3f rot = Eigen::Quaternionf(rotation[3], rotation[0], rotation[1], rotation[2]).normalized().toRotationMatrix();
		return Matrix{
			translation,
			Vector(rot(0, 0), rot(1, 0), rot(2, 0)),
			Vector(rot(0, 1), rot(1, 1), rot(2, 1)),
			Vector(rot(0, 2), rot(1, 2), rot(2, 2))
		};
	}

	void MarkBoneTransformDirty(BaseObject* object)
	{
		if (!object)
			return;

		std::vector<BaseObject*> stack;
		stack.push_back(object);
		while (!stack.empty())
		{
			BaseObject* const current = stack.back();
			stack.pop_back();
			if (!current)
				continue;

			current->Touch();
			current->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
			current->Message(MSG_UPDATE);

			for (BaseTag* tag = current->GetFirstTag(); tag; tag = tag->GetNext())
				tag->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);

			for (BaseObject* child = current->GetDown(); child; child = child->GetNext())
				stack.push_back(child);
		}
	}

	void MarkSceneNodeDirty(BaseList2D* node)
	{
		if (!node)
			return;

		node->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		node->Message(MSG_UPDATE);
	}

	void MarkMeshHierarchyDirty(BaseObject* mesh_manager_object)
	{
		if (!mesh_manager_object)
			return;

		for (BaseObject* mesh_object = mesh_manager_object->GetDown(); mesh_object; mesh_object = mesh_object->GetNext())
		{
			MarkSceneNodeDirty(mesh_object);

			for (BaseTag* tag = mesh_object->GetFirstTag(); tag; tag = tag->GetNext())
			{
				if (tag->GetType() == Tweights)
					MarkSceneNodeDirty(tag);
			}

			for (BaseObject* child = mesh_object->GetDown(); child; child = child->GetNext())
				MarkSceneNodeDirty(child);
		}
	}

	struct BoolResetGuard
	{
		explicit BoolResetGuard(Bool* value) : value_(value) {}

		~BoolResetGuard()
		{
			if (value_)
				*value_ = false;
		}

	private:
		Bool* value_ = nullptr;
	};
}

NodeData* MMDBoneManagerObject::Alloc()
{
	return NewObjClear(MMDBoneManagerObject);
}

SDK2024_Init(MMDBoneManagerObject)
{
	if (!node)
		return false;

	if (!SDK2024_SuperInit)
		return false;

	if (BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
		bc->SetInt32(BONE_MODE, BONE_MODE_ANIM);

	ConfigureBoneManagerExecutionPriority(node);
	return true;
}

SDK2024_CopyTo(MMDBoneManagerObject)
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDBoneManagerObject*>(dest);
	dest_object->bone_name_index_ = bone_name_index_;
	dest_object->append_execution_order_dirty_ = true;
	dest_object->is_refreshing_append_execution_order_ = false;
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
	bone_items_.FlushAll();
	bone_items_.SetString(-1, "-"_s);
	bone_index_lookup_.Reset();
	is_syncing_bone_hierarchy_ = false;
	has_pending_bone_hierarchy_sync_ = false;
	append_execution_order_dirty_ = true;
	is_refreshing_append_execution_order_ = false;
	physics_overrides_.Reset();
	if (!SUPER::Read(node, hf, level))
		return false;
	if (BaseContainer* const bc = node ? reinterpret_cast<BaseList2D*>(node)->GetDataInstance() : nullptr)
		bc->SetInt32(BONE_MODE, NormalizeBoneMode(bc->GetInt32(BONE_MODE)));
	ConfigureBoneManagerExecutionPriority(node);
	return true;
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
		const GeData normalized_mode(NormalizeBoneMode(t_data.GetInt32()));
		MMDBoneManagerObjectMsg msg(MMDBoneManagerObjectMsgType::BONE_MODE_CHANGE, BONE_DISPLAY_TYPE_OFF, nullptr, normalized_mode.GetInt32());
		node->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &msg);
		return SUPER::SetDParameter(node, id, normalized_mode, flags);
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
		SynchronizeBoneHierarchy(reinterpret_cast<BaseObject*>(node));
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
	case MMDBoneTagMsgType::BONE_HIERARCHY_DIRTY:
		{
			SynchronizeBoneHierarchy(reinterpret_cast<BaseObject*>(node));
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
	return SynchronizeBoneHierarchy(reinterpret_cast<BaseObject*>(node));
}

bool MMDBoneManagerObject::CollectBoneHierarchyDFS(BaseObject* object, maxon::BaseArray<BoneHierarchySyncEntry>& entries) const
{
	iferr_scope_handler{
		return false;
	};

	for (BaseObject* current = object; current != nullptr; current = current->GetNext())
	{
		if (current->IsInstanceOf(Ojoint))
		{
			if (BaseTag* bone_tag = current->GetTag(g_mmd_bone_tag_id); bone_tag != nullptr)
			{
				auto& entry = entries.Append()iferr_return;
				entry.object = current;
				entry.tag = bone_tag;
				entry.bone_index = static_cast<Int32>(entries.GetCount() - 1);
			}
		}
		if (!CollectBoneHierarchyDFS(current->GetDown(), entries))
			return false;
	}
	return true;
}

void MMDBoneManagerObject::RefreshBoneHierarchyUI(BaseObject* bone_manager_object) const
{
	if (bone_manager_object)
		bone_manager_object->SetDirty(DIRTYFLAGS::DATA);

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
}

bool MMDBoneManagerObject::SynchronizeBoneHierarchy(BaseObject* bone_manager_object, const Bool update_ui)
{
	iferr_scope_handler{
		return false;
	};

	if (!bone_manager_object)
		bone_manager_object = reinterpret_cast<BaseObject*>(Get());
	if (!bone_manager_object)
		return false;

	if (is_syncing_bone_hierarchy_)
	{
		has_pending_bone_hierarchy_sync_ = true;
		return true;
	}

	is_syncing_bone_hierarchy_ = true;
	BoolResetGuard sync_guard(&is_syncing_bone_hierarchy_);
	do
	{
		has_pending_bone_hierarchy_sync_ = false;

		maxon::BaseArray<BoneHierarchySyncEntry> entries;
		if (!CollectBoneHierarchyDFS(bone_manager_object->GetDown(), entries))
			return false;

		bone_items_.FlushAll();
		bone_items_.SetString(-1, "-"_s);
		bone_list_.Reset();
		bone_index_lookup_.Reset();
		std::unordered_map<Int32, Int32> previous_to_current_index;

		for (const auto& entry : entries)
		{
			bone_index_lookup_.Insert(entry.object, entry.bone_index)iferr_return;
		}

		for (const auto& entry : entries)
		{
			BoneHierarchySyncEntry synchronized_entry = entry;
			const Int32 previous_index = ReadBoneIndexParameter(synchronized_entry.tag);
			if (previous_index >= 0)
				previous_to_current_index[previous_index] = synchronized_entry.bone_index;

			BaseObject* parent_object = synchronized_entry.object ? synchronized_entry.object->GetUp() : nullptr;
			if (parent_object)
			{
				if (const auto* parent_index = bone_index_lookup_.Find(parent_object))
				{
					synchronized_entry.parent_index = parent_index->GetValue();
					synchronized_entry.parent_name = parent_object->GetName();
				}
			}

			bone_items_.SetString(synchronized_entry.bone_index, synchronized_entry.object->GetName());

			auto& link = bone_list_.InsertKey(synchronized_entry.bone_index)iferr_return;
			link = maxon::BaseRef<AutoAlloc<BaseLink>, maxon::StrongRefHandler>::Create()iferr_return;
			(*link)->SetLink(synchronized_entry.tag);

			if (auto* bone_tag_node = synchronized_entry.tag->GetNodeData<MMDBoneTag>())
			{
				bone_tag_node->bone_object_ = synchronized_entry.object;
				bone_tag_node->bone_manager_data_ = this;
				bone_tag_node->bone_manager_link_->SetLink(bone_manager_object);
				bone_tag_node->hierarchy_parent_cache_ = parent_object;
				bone_tag_node->hierarchy_pred_cache_ = synchronized_entry.object ? synchronized_entry.object->GetPred() : nullptr;
				bone_tag_node->hierarchy_manager_cache_ = bone_manager_object;
			}

			synchronized_entry.tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)),
				String::IntToString(synchronized_entry.bone_index), DESCFLAGS_SET::NONE);
			synchronized_entry.tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_INDEX)),
				String::IntToString(synchronized_entry.parent_index), DESCFLAGS_SET::NONE);
			synchronized_entry.tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_NAME)),
				synchronized_entry.parent_name, DESCFLAGS_SET::NONE);
			synchronized_entry.tag->SetDirty(DIRTYFLAGS::DATA);
			if (synchronized_entry.object)
				synchronized_entry.object->SetDirty(DIRTYFLAGS::DATA);
		}

		if (MMDModelManagerObject* const model_manager = GetModelManagerData())
		{
			if (MMDRigidManagerObject* const rigid_manager = model_manager->GetRigidManagerData())
			{
				BaseObject* const rigid_manager_object = reinterpret_cast<BaseObject*>(rigid_manager->Get());
				const Int32 remapped_rigids = RemapRigidRelatedBoneIndices(rigid_manager_object, previous_to_current_index);
				if (remapped_rigids > 0 && IsPhysicsDebugLoggingEnabled())
				{
					DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
						"[CMT] SynchronizeBoneHierarchy remappedRigidBones=@",
						remapped_rigids);
				}
			}
		}
	}
	while (has_pending_bone_hierarchy_sync_);

	MarkAppendExecutionOrderDirty();
	if (!is_refreshing_append_execution_order_)
		EnsureAppendExecutionOrder();

	if (update_ui)
	{
		MMDBoneManagerObjectMsg hierarchy_msg{
			MMDBoneManagerObjectMsgType::BONE_HIERARCHY_UPDATE,
			BONE_DISPLAY_TYPE_ON,
			bone_manager_object
		};
		bone_manager_object->MultiMessage(MULTIMSG_ROUTE::BROADCAST, g_mmd_bone_manager_object_id, &hierarchy_msg);
		RefreshBoneHierarchyUI(bone_manager_object);
	}

	return true;
}

void MMDBoneManagerObject::MarkAppendExecutionOrderDirty()
{
	append_execution_order_dirty_ = true;
}

Int32 MMDBoneManagerObject::ComputeAppendRecursionDepth(const Int32 bone_index, maxon::BaseArray<Int32>& depth_cache, maxon::BaseArray<UChar>& visit_state) const
{
	if (bone_index < 0 || bone_index >= depth_cache.GetCount())
		return 0;
	if (depth_cache[bone_index] >= 0)
		return depth_cache[bone_index];
	if (visit_state[bone_index] == 1)
		return 0;

	visit_state[bone_index] = 1;
	Int32 depth = 0;

	if (BaseTag* const bone_tag = FindBone(bone_index))
	{
		if (const BaseContainer* const bc = bone_tag->GetDataInstance())
		{
			if (bc->GetBool(PMX_BONE_INHERIT_ROTATION) || bc->GetBool(PMX_BONE_INHERIT_TRANSLATION))
			{
				if (const auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>())
				{
					if (BaseTag* const source_tag = bone_tag_node->ResolveInheritSourceBoneTag())
					{
						const Int32 source_index = FindBoneIndex(source_tag);
						if (source_index >= 0 && source_index != bone_index)
							depth = ComputeAppendRecursionDepth(source_index, depth_cache, visit_state) + 1;
					}
				}
			}
		}
	}

	visit_state[bone_index] = 2;
	depth_cache[bone_index] = depth;
	return depth;
}

void MMDBoneManagerObject::EnsureAppendExecutionOrder()
{
	if (!append_execution_order_dirty_ || is_refreshing_append_execution_order_)
		return;

	is_refreshing_append_execution_order_ = true;
	BoolResetGuard refresh_guard(&is_refreshing_append_execution_order_);

	if (bone_index_lookup_.GetCount() != bone_list_.GetCount())
		SynchronizeBoneHierarchy(reinterpret_cast<BaseObject*>(Get()), false);

	if (bone_list_.IsEmpty())
	{
		append_execution_order_dirty_ = false;
		return;
	}

	iferr_scope_handler
	{
		return;
	};

	const Int32 bone_count = static_cast<Int32>(bone_list_.GetCount());
	maxon::BaseArray<Int32> depth_cache;
	maxon::BaseArray<UChar> visit_state;
	depth_cache.Resize(bone_count)iferr_return;
	visit_state.Resize(bone_count)iferr_return;
	for (Int32 i = 0; i < bone_count; ++i)
	{
		depth_cache[i] = -1;
		visit_state[i] = 0;
	}

	for (Int32 i = 0; i < bone_count; ++i)
		ComputeAppendRecursionDepth(i, depth_cache, visit_state);

	for (Int32 i = 0; i < bone_count; ++i)
	{
		BaseTag* const bone_tag = FindBone(i);
		if (!bone_tag)
			continue;

		if (auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>())
		{
			bone_tag_node->SetAppendRecursionDepth(depth_cache[i] < 0 ? 0 : depth_cache[i]);
			bone_tag_node->RefreshExecutionPriority(bone_tag);
		}

		bone_tag->SetDirty(DIRTYFLAGS::DATA);
		if (BaseObject* const bone_object = bone_tag->GetObject())
			bone_object->SetDirty(DIRTYFLAGS::DATA);
	}

	append_execution_order_dirty_ = false;
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
				case MMDModelManagerObjectMsgType::ACTIVE_ANIMATION_SLOT_CHANGE:
					SetAllActiveAnimationSlot(msg->active_animation_slot);
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

	const BaseObject* bone_object = bone_tag->GetObject();
	if (!bone_object)
	{
		return -1;
	}

	if (const auto* bone_index = bone_index_lookup_.Find(const_cast<BaseObject*>(bone_object)))
	{
		return bone_index->GetValue();
	}
	return -1;
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
	SynchronizeBoneHierarchy(reinterpret_cast<BaseObject*>(Get()));

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
				BaseTag* bone_tag = nullptr;
				if (bone_offset.m_boneIndex >= 0 && bone_offset.m_boneIndex < bone_list.GetCount())
				{
					BaseObject* const target_bone_object = bone_list[bone_offset.m_boneIndex];
					bone_tag = target_bone_object ? target_bone_object->GetTag(g_mmd_bone_tag_id) : nullptr;
				}
				if (!bone_tag)
					bone_tag = FindBone(bone_offset.m_boneIndex);

				if (bone_tag)
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

	SynchronizeBoneHierarchy(reinterpret_cast<BaseObject*>(Get()), false);

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
	if (bone_items_.GetIndexId(0) == NOTOK)
		bone_items_.SetString(-1, "-"_s);
	return bone_items_;
}

MMDModelManagerObject* MMDBoneManagerObject::GetModelManagerData()
{
	BaseObject* model_manager_object = io_util::ResolveObjectLink(model_manager_);
	if (!model_manager_object)
	{
		if (BaseObject* const parent = reinterpret_cast<BaseObject*>(Get())->GetUp(); parent && parent->IsInstanceOf(g_mmd_model_manager_object_id))
		{
			model_manager_->SetLink(parent);
			model_manager_object = parent;
		}
	}
	return model_manager_object ? model_manager_object->GetNodeData<MMDModelManagerObject>() : nullptr;
}

const MMDBoneManagerObject::PhysicsOverrideState* MMDBoneManagerObject::FindPhysicsOverride(const Int32 bone_index, const Int32 frame) const
{
	const auto* const entry = physics_overrides_.Find(bone_index);
	if (!entry)
		return nullptr;
	return entry->GetValue().frame == frame ? &entry->GetValue() : nullptr;
}

void MMDBoneManagerObject::SetPhysicsOverride(const Int32 bone_index, const Int32 frame, const Vector& translation, const std::array<Float32, 4>& rotation)
{
	if (bone_index < 0)
		return;

	if (auto* const bone_tag = FindBone(bone_index))
	{
		if (auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>())
			bone_tag_node->SetPlaybackRuntimeOverride(frame, translation, rotation);
	}

	PhysicsOverrideState state;
	state.frame = frame;
	state.translation = translation;
	state.rotation = rotation;
	iferr(physics_overrides_.Insert(bone_index, state))
	{
		if (auto* const existing = physics_overrides_.Find(bone_index))
			existing->GetValue() = state;
	}
}

EXECUTIONRESULT MMDBoneManagerObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	iferr_scope_handler
	{
		return EXECUTIONRESULT::OK;
	};

	if (!op || !doc)
		return EXECUTIONRESULT::OK;

	BaseObject* const model_manager_object = io_util::ResolveObjectLink(model_manager_);
	const BaseContainer* const model_bc = model_manager_object ? model_manager_object->GetDataInstance() : nullptr;
	if (!model_bc || model_bc->GetInt32(MODEL_MODE) != MODEL_MODE_ANIM)
		return EXECUTIONRESULT::OK;

	EnsureAppendExecutionOrder();
	const Bool debug_logging = IsPhysicsDebugLoggingEnabled();
	const Int32 current_frame = doc->GetTime().GetFrame(30);
	Int32 processed_bones = 0;
	Int32 self_override_bones = 0;
	Int32 inherit_override_bones = 0;
	Int32 applied_animation_bones = 0;
	Int32 post_physics_ik_candidates = 0;
	Int32 post_physics_ik_solved = 0;
	std::vector<std::string> inherit_override_labels;
	std::vector<std::string> applied_animation_labels;
	std::vector<std::string> post_physics_ik_labels;

	std::vector<Int32> sorted_indices;
	sorted_indices.reserve(bone_list_.GetCount());
	for (const auto& entry : bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));

	std::sort(sorted_indices.begin(), sorted_indices.end(), [this](const Int32 lhs, const Int32 rhs)
	{
		auto get_sort_key = [this](const Int32 bone_index) -> std::tuple<Int32, Int32, Int32>
		{
			BaseTag* const bone_tag = FindBone(bone_index);
			const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
			const Int32 layer = bc ? std::max(0, bc->GetInt32(PMX_BONE_LAYER)) : 0;
			const Int32 append_depth = bone_tag && bone_tag->GetNodeData<MMDBoneTag>()
				? bone_tag->GetNodeData<MMDBoneTag>()->append_recursion_depth_
				: 0;
			return std::make_tuple(layer, append_depth, bone_index);
		};
		return get_sort_key(lhs) < get_sort_key(rhs);
	});

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = FindBone(bone_index);
		if (!bone_tag)
			continue;

		auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
		BaseObject* const bone_object = bone_tag->GetObject();
		const BaseContainer* const bc = bone_tag->GetDataInstance();
		if (!bone_tag_node || !bone_object || !bc || bone_tag_node->bone_mode_ != BONE_MODE_ANIM)
			continue;

		++processed_bones;

		const Bool deform_after_physics = bc->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM);
		Vector source_translation;
		std::array<Float32, 4> source_rotation { 0.F, 0.F, 0.F, 1.F };
		const Bool has_self_override = FindPhysicsOverride(bone_index, current_frame) != nullptr
			&& bone_tag_node->GetPlaybackRuntimeOverride(source_translation, source_rotation);
		if (has_self_override)
			++self_override_bones;

		Bool inherit_source_has_override = false;
		if (BaseTag* const source_tag = bone_tag_node->ResolveInheritSourceBoneTag())
		{
			if (auto* const source_tag_node = source_tag->GetNodeData<MMDBoneTag>())
				inherit_source_has_override = source_tag_node->GetPlaybackRuntimeOverride(source_translation, source_rotation);
		}
		if (inherit_source_has_override)
		{
			++inherit_override_bones;
			if (debug_logging)
				inherit_override_labels.emplace_back(BuildBoneDebugLabel(bone_tag, bone_index));
		}

		if (!has_self_override && !deform_after_physics && !inherit_source_has_override)
			continue;

		if (has_self_override)
		{
			// #region agent log H3/H4
			const Vector dbg_rel_before = bone_object->GetRelMl().off;
			// #endregion
			bone_object->SetRelMl(BuildBoneRelativeMatrix(source_translation, source_rotation));
			MarkBoneTransformDirty(bone_object);
			// #region agent log H3/H4
			if (current_frame < 30)
			{
				const Vector dbg_rel_after = bone_object->GetRelMl().off;
				std::ostringstream s;
				s << "{\"frame\":" << current_frame
					<< ",\"boneIndex\":" << bone_index
					<< ",\"overrideT\":[" << source_translation.x << "," << source_translation.y << "," << source_translation.z << "]"
					<< ",\"relOffBefore\":[" << dbg_rel_before.x << "," << dbg_rel_before.y << "," << dbg_rel_before.z << "]"
					<< ",\"relOffAfter\":[" << dbg_rel_after.x << "," << dbg_rel_after.y << "," << dbg_rel_after.z << "]"
					<< "}";
				cmt_dbg::Log("H3", "mmd_bone_manager.cpp:Execute",
					"applied physics override to bone", s.str());
			}
			// #endregion
			if (!(deform_after_physics && bone_tag_node->is_IK))
				continue;
		}

		if (!has_self_override && !bone_tag_node->ApplyActiveAnimation(bone_object, doc, true))
			continue;
		if (!has_self_override)
		{
			++applied_animation_bones;
			if (debug_logging)
				applied_animation_labels.emplace_back(BuildBoneDebugLabel(bone_tag, bone_index));
		}

		if (deform_after_physics && bone_tag_node->is_IK)
		{
			++post_physics_ik_candidates;
			if (bone_tag_node->RunIKSolveAnimMode(bone_object, false))
			{
				++post_physics_ik_solved;
				if (debug_logging)
					post_physics_ik_labels.emplace_back(BuildBoneDebugLabel(bone_tag, bone_index));
			}
		}
	}

	DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
		"[CMT][Frame @] BoneManagerExecute bones=@ processed=@ selfOverride=@ inheritOverride=@ animApplied=@ postIK=@ solved=@",
		current_frame, bone_list_.GetCount(), processed_bones, self_override_bones, inherit_override_bones,
		applied_animation_bones, post_physics_ik_candidates, post_physics_ik_solved);
	if (debug_logging)
	{
		if (!inherit_override_labels.empty())
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT][Frame @] BoneManager inheritOverrideBones=@",
				current_frame, JoinBoneDebugLabels(inherit_override_labels));
		}
		if (!applied_animation_labels.empty())
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT][Frame @] BoneManager animAppliedBones=@",
				current_frame, JoinBoneDebugLabels(applied_animation_labels));
		}
		if (!post_physics_ik_labels.empty())
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT][Frame @] BoneManager postPhysicsIKBones=@",
				current_frame, JoinBoneDebugLabels(post_physics_ik_labels));
		}
	}

	if (self_override_bones > 0 || inherit_override_bones > 0 || applied_animation_bones > 0 || post_physics_ik_solved > 0)
	{
		if (MMDModelManagerObject* const model_manager = GetModelManagerData())
			MarkMeshHierarchyDirty(model_manager->GetMeshManagerObject());
	}

	return EXECUTIONRESULT::OK;
}

Bool MMDBoneManagerObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (!op || !list)
		return true;

	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);
	return true;
}

void MMDBoneManagerObject::PrepareSceneForPhysicsPlayback(BaseDocument* doc)
{
	iferr_scope_handler
	{
		return;
	};

	if (!doc)
		return;

	EnsureAppendExecutionOrder();
	const Bool debug_logging = IsPhysicsDebugLoggingEnabled();
	const Int32 current_frame = doc->GetTime().GetFrame(30);
	Int32 prepared_bones = 0;
	std::vector<std::string> prepared_bone_labels;
	std::unordered_map<const BaseTag*, bool> prepare_memo;
	std::unordered_set<const BaseTag*> prepare_visiting;

	std::vector<Int32> sorted_indices;
	sorted_indices.reserve(bone_list_.GetCount());
	for (const auto& entry : bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));

	std::sort(sorted_indices.begin(), sorted_indices.end(), [this](const Int32 lhs, const Int32 rhs)
	{
		auto get_sort_key = [this](const Int32 bone_index) -> std::tuple<Int32, Int32, Int32>
		{
			BaseTag* const bone_tag = FindBone(bone_index);
			const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
			const Int32 layer = bc ? std::max(0, bc->GetInt32(PMX_BONE_LAYER)) : 0;
			const Int32 append_depth = bone_tag && bone_tag->GetNodeData<MMDBoneTag>()
				? bone_tag->GetNodeData<MMDBoneTag>()->append_recursion_depth_
				: 0;
			return std::make_tuple(layer, append_depth, bone_index);
		};
		return get_sort_key(lhs) < get_sort_key(rhs);
	});

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = FindBone(bone_index);
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		auto* const bone_tag_node = bone_tag ? bone_tag->GetNodeData<MMDBoneTag>() : nullptr;
		if (!bone_object || !bone_tag_node || bone_tag_node->bone_mode_ != BONE_MODE_ANIM)
			continue;
		if (!BoneNeedsPrephysicsPlayback(this, bone_tag, prepare_memo, prepare_visiting))
			continue;

		bone_tag_node->BeginPrephysicsFrame(current_frame);
		if (bone_tag_node->ApplyActiveAnimation(bone_object, doc, true))
		{
			++prepared_bones;
			if (debug_logging)
				prepared_bone_labels.emplace_back(BuildBoneDebugLabel(bone_tag, bone_index));
		}
	}

	DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
		"[CMT][Frame @] PrepareSceneForPhysicsPlayback bones=@ prepared=@",
		current_frame, bone_list_.GetCount(), prepared_bones);
	if (debug_logging && !prepared_bone_labels.empty())
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
			"[CMT][Frame @] PrepareSceneForPhysicsPlayback bones=@",
			current_frame, JoinBoneDebugLabels(prepared_bone_labels));
	}
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

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
}

Bool MMDBoneManagerObject::EnsureAllAnimationSlotCount(const Int32 slot_count)
{
	iferr_scope_handler
	{
		return false;
	};

	for (const auto& entry : bone_list_)
	{
		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!tag)
			continue;

		auto* bone_tag = tag->GetNodeData<MMDBoneTag>();
		if (!bone_tag)
			continue;

		if (!bone_tag->EnsureAnimationSlotCount(slot_count))
			return false;
	}

	return true;
}

void MMDBoneManagerObject::SetAllActiveAnimationSlot(const Int32 slot_index)
{
	for (const auto& entry : bone_list_)
	{
		BaseTag* tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!tag)
			continue;

		auto* bone_tag = tag->GetNodeData<MMDBoneTag>();
		if (!bone_tag)
			continue;

		bone_tag->SetActiveAnimationSlot(slot_index);
	}

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
}

void MMDBoneManagerObject::CreateDisplayTag(GeListNode* node)
{}
