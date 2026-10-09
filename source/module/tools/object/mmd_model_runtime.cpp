// ModelManager standalone runtime implementation. ObjectData registration and
// persistence remain in mmd_model_manager.cpp; this unit owns execution only.
#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_model_manager.h"
#include "mmd_bone_manager.h"
#include "mmd_joint_manager.h"
#include "mmd_mesh_manager.h"
#include "mmd_rigid_manager.h"
#include "mmd_morph.h"
#include "module/tools/tag/mmd_bone.h"
#include "plugin_resource.h"
#include "description/TMMDBone.h"
#include "description/OMMDRigid.h"
#include "description/tcaconstraint.h"
#include "customgui_priority.h"
#include "utils/mmd_bone_control_util.hpp"
#include "utils/string_util.hpp"
#include "utils/cmt_runtime_profile.hpp"
#include "utils/cmt_anim_flow_debug.hpp"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include <btBulletDynamicsCommon.h>
#include <algorithm>
#include <limits>

namespace
{
	// Tcaconstraint is not declared by the R20 SDK, but the native plugin ID
	// and its PSR description are shared by the supported Cinema 4D versions.
	constexpr Int32 kNativeConstraintTagId = 1019364;
	Int32 NormalizeModelMode(const Int32 mode)
	{
		constexpr Int32 kLegacyModelModeVmd = 2;
		return mode == kLegacyModelModeVmd ? MODEL_MODE_ANIM : mode;
	}

	String GetBoneTagName(const BaseTag* tag, const Bool use_local_name)
	{
		if (!tag)
			return ""_s;

		GeData data;
		const Int32 param_id = use_local_name ? PMX_BONE_NAME_LOCAL : PMX_BONE_NAME_UNIVERSAL;
		if (GetAtomParameter(tag, CreateDescID(DescLevel(param_id)), data, DESCFLAGS_GET::NONE))
		{
			const String name = data.GetString();
			if (!name.IsEmpty())
				return name;
		}

		if (BaseObject* object = const_cast<BaseTag*>(tag)->GetObject())
			return object->GetName();

		return ""_s;
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

}

void MMDModelManagerObject::PrepareExternalBonePoses(BaseDocument* doc)
{
	const Bool had_external_input = HasExternalBonePoses();
	external_bone_poses_.clear();
	external_pose_captured_ = false;
	external_pose_refresh_ = had_external_input;
	if (!doc || model_mode_ != MODEL_MODE_ANIM || !bone_manager_data_)
		return;

	bone_manager_data_->EnsurePlaybackExecutionPlan();
	for (const Int32 bone_index : bone_manager_data_->GetPlaybackBoneIndices())
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		BaseObject* const bone = bone_tag ? bone_tag->GetObject() : nullptr;
		const auto* const bone_node = bone_tag ? bone_tag->GetNodeData<MMDBoneTag>() : nullptr;
		if (!bone || !bone_node || bone_node->bone_mode_ != BONE_MODE_ANIM)
			continue;
		ExternalBonePose pose;
		for (BaseTag* tag = bone->GetFirstTag(); tag; tag = tag->GetNext())
		{
			if (tag->GetType() != kNativeConstraintTagId)
				continue;
			const BaseContainer& data = tag->GetDataInstanceRef();
			if (!data.GetBool(EXPRESSION_ENABLE, true) || !data.GetBool(ID_CA_CONSTRAINT_TAG_PSR)
				|| data.GetFloat(ID_CA_CONSTRAINT_TAG_PSR_TWEIGHT) <= 0.0)
				continue;
			GeData priority;
			if (!tag->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
				continue;
			const auto* const priority_data = GetCustomDataTypeWritable<PriorityData>(priority, CUSTOMGUI_PRIORITY_DATA);
			if (!priority_data || priority_data->GetPriorityValue(PRIORITYVALUE_MODE).GetInt32() != CYCLE_EXPRESSION)
				continue;
			const Int32 offset = priority_data->GetPriorityValue(PRIORITYVALUE_PRIORITY).GetInt32();
			if (offset <= -500 || offset >= 500)
				continue;

			const Bool position_axes = data.GetBool(ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_P_X)
				|| data.GetBool(ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_P_Y) || data.GetBool(ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_P_Z);
			const Bool rotation_axes = data.GetBool(ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_R_X)
				|| data.GetBool(ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_R_Y) || data.GetBool(ID_CA_CONSTRAINT_TAG_PSR_CONSTRAIN_R_Z);
			// Native PSR targets use ten IDs per row: link +1, weight +2,
			// position +5, scale +6, rotation +7 (the SDK reserves 10000..19999).
			constexpr Int32 target_stride = 10;
			constexpr Int32 max_targets = (ID_CA_CONSTRAINT_TAG_PSR_TARGET_COUNT_END - ID_CA_CONSTRAINT_TAG_PSR_TARGET_COUNT + 1) / target_stride;
			const Int32 count = std::min(std::max(data.GetInt32(ID_CA_CONSTRAINT_TAG_PSR_TARGET_COUNT), 0), max_targets);
			for (Int32 row = 0; row < count; ++row)
			{
				const Int32 base = ID_CA_CONSTRAINT_TAG_PSR_TARGET_COUNT + row * target_stride;
				if (!data.GetLink(base + 1, doc) || data.GetFloat(base + 2) <= 0.0)
					continue;
				pose.position = pose.position || (position_axes && data.GetBool(base + 5));
				pose.rotation = pose.rotation || (rotation_axes && data.GetBool(base + 7));
			}
		}
		if (pose.position || pose.rotation)
			external_bone_poses_.emplace(bone_index, pose);
	}

	external_pose_refresh_ = had_external_input || HasExternalBonePoses();
	if (!external_pose_refresh_)
		return;
	if (has_transient_vpd_pose_ && doc->GetTime() != transient_vpd_pose_time_)
		ClearTransientVPDPoseState(doc);
	PrepareSameFrameReevaluation(doc);
	if (!HasExternalBonePoses())
		return;

	// Only prepare animation here. Bullet and IK run once, after native tags.
	for (const Bool after_physics : { false, true })
	{
		for (const Int32 layer : bone_manager_data_->GetPlaybackLayers())
			bone_manager_data_->PrepareSceneForPhysicsPlaybackLayer(doc, layer, after_physics);
	}
}

void MMDModelManagerObject::CaptureExternalBonePoses()
{
	for (auto& entry : external_bone_poses_)
	{
		BaseTag* const bone_tag = bone_manager_data_ ? bone_manager_data_->FindBone(entry.first) : nullptr;
		if (BaseObject* const bone = bone_tag ? bone_tag->GetObject() : nullptr)
			entry.second.relative = bone->GetRelMl();
	}
	external_pose_captured_ = true;
}

Bool MMDModelManagerObject::GetExternalBonePose(const Int32 bone_index, Matrix& relative, Bool& position, Bool& rotation) const
{
	if (!external_pose_captured_)
		return false;
	const auto entry = external_bone_poses_.find(bone_index);
	if (entry == external_bone_poses_.end())
		return false;
	relative = entry->second.relative;
	position = entry->second.position;
	rotation = entry->second.rotation;
	return true;
}

Bool MMDModelManagerObject::HasExternalBoneRotation(const Int32 bone_index) const
{
	const auto entry = external_bone_poses_.find(bone_index);
	return external_pose_captured_ && entry != external_bone_poses_.end() && entry->second.rotation;
}

libmmd::MMDIkSolver* MMDModelManagerObject::GetStandaloneIKSolver(const Int32 bone_index) const
{
	if (!ik_manager_own_ || bone_index < 0)
		return nullptr;

	auto* bone_manager = const_cast<MMDModelManagerObject*>(this)->GetBoneManagerData();
	if (!bone_manager)
		return nullptr;

	BaseTag* const bone_tag = bone_manager->FindBone(bone_index);
	if (!bone_tag)
		return nullptr;

	String solver_name = GetBoneTagName(bone_tag, true);
	if (solver_name.IsEmpty())
		solver_name = GetBoneTagName(bone_tag, false);
	if (solver_name.IsEmpty())
		return nullptr;

	const size_t solver_index = ik_manager_own_->FindIKSolverIndex(string_util::GetStdString(solver_name));
	if (solver_index == static_cast<size_t>(-1))
		return nullptr;
	return ik_manager_own_->GetMMDIKSolver(solver_index);
}

C4DIKChainNodeAdapter* MMDModelManagerObject::GetBoneAdapter(const Int32 bone_index) const
{
	if (const auto* const entry = physics_bone_adapters_.Find(bone_index))
		return entry->GetValue();
	return nullptr;
}

void MMDModelManagerObject::SyncStandaloneBoneAdaptersFromScene(const Bool reset_ik_rotation)
{
	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter)
			adapter->SyncCurrentTransformsFromBoneObject(reset_ik_rotation);
	}

	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter && adapter->GetParent() == nullptr)
			adapter->UpdateGlobalTransform();
	}
}

void MMDModelManagerObject::SyncStandaloneBoneAdaptersLocalFromGlobal(const maxon::BaseArray<Int32>& bone_indices) const
{
	for (const Int32 bone_index : bone_indices)
	{
		if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index))
			adapter->SyncLocalTransformFromGlobal();
	}

	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter && adapter->GetParent() == nullptr)
			adapter->UpdateGlobalTransform();
	}
}

Bool MMDModelManagerObject::SolveStandaloneIKBeforePhysics(const Bool include_after_physics_bones)
{
	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return false;

	Bool solved = false;
	bone_manager_data_->EnsurePlaybackExecutionPlan();
	for (const Int32 layer : bone_manager_data_->GetPlaybackLayers())
	{
		solved = SolveStandaloneIKForLayer(layer, false) > 0 || solved;
		if (include_after_physics_bones)
			solved = SolveStandaloneIKForLayer(layer, true) > 0 || solved;
	}
	return solved;
}

Int32 MMDModelManagerObject::SolveStandaloneIKForLayer(const Int32 layer, const Bool after_physics, const Bool sync_from_scene)
{
	cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::IK);
	if (!ik_manager_own_)
		return 0;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return 0;

	auto has_static_pose_keyframe_at_time = [](MMDBoneTag* bone_tag, const BaseDocument* doc) -> Bool
	{
		return bone_tag && bone_tag->HasStaticPoseAnimationSegmentAtTime(doc);
	};

	auto ik_chain_has_authored_pose = [this, &has_static_pose_keyframe_at_time](MMDBoneTag* ik_bone_tag, const BaseDocument* doc) -> Bool
	{
		if (!ik_bone_tag || !doc)
			return false;

		maxon::BaseArray<Int32> affected_indices;
		ik_bone_tag->CollectIKAffectedBoneIndices(affected_indices);
		for (const Int32 affected_index : affected_indices)
		{
			// A driven IK goal is an input to this solver, not a competing FK
			// rotation. Direct rotation constraints on its limb take ownership.
			if (affected_index != ik_bone_tag->GetBoneIndex() && HasExternalBoneRotation(affected_index))
				return true;
			BaseTag* const affected_tag = bone_manager_data_ ? bone_manager_data_->FindBone(affected_index) : nullptr;
			if (affected_index != ik_bone_tag->GetBoneIndex() && mmd_bone_control_util::HasActiveControlRotation(affected_tag))
				return true;
			auto* const affected_tag_node = affected_tag ? affected_tag->GetNodeData<MMDBoneTag>() : nullptr;
			if (affected_tag_node && (affected_tag_node->HasStaticPoseRuntimeOverride(doc) || has_static_pose_keyframe_at_time(affected_tag_node, doc)))
				return true;
		}
		return false;
	};

	std::vector<Int32> ik_indices;
	const auto& planned_ik_indices = bone_manager_data_->GetPlaybackIKBonesForLayer(layer, after_physics);
	ik_indices.reserve(planned_ik_indices.size());
	for (const Int32 bone_index : planned_ik_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		auto* const bone_tag_node = bone_tag ? bone_tag->GetNodeData<MMDBoneTag>() : nullptr;
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		if (!bone_tag_node || !bone_object || !bc || !bc->GetBool(PMX_BONE_IS_IK))
			continue;
		if (std::max(0, bc->GetInt32(PMX_BONE_LAYER)) != layer)
			continue;
		if (bc->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM) != after_physics)
			continue;

		libmmd::MMDIkSolver* const ik_solver = GetStandaloneIKSolver(bone_index);
		if (!ik_solver || !ik_solver->Enabled() || !ik_solver->GetIKNode() || !ik_solver->GetTargetNode())
			continue;
		if (ik_chain_has_authored_pose(bone_tag_node, bone_object->GetDocument()))
			continue;
		ik_indices.emplace_back(bone_index);
	}
	if (ik_indices.empty())
		return 0;

	if (sync_from_scene)
		SyncStandaloneBoneAdaptersFromScene(true);

	Int32 solved_count = 0;
	for (const Int32 bone_index : ik_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		auto* const bone_tag_node = bone_tag ? bone_tag->GetNodeData<MMDBoneTag>() : nullptr;
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		if (!bone_tag_node || !bone_object)
			continue;

		libmmd::MMDIkSolver* const ik_solver = GetStandaloneIKSolver(bone_index);
		if (!ik_solver || !ik_solver->Enabled() || !ik_solver->GetIKNode() || !ik_solver->GetTargetNode())
			continue;
		if (ik_chain_has_authored_pose(bone_tag_node, bone_object->GetDocument()))
			continue;

		bone_tag_node->BuildStandaloneIKChains();

		ik_solver->Solve();

		maxon::BaseArray<Int32> affected_indices;
		bone_tag_node->CollectIKAffectedBoneIndices(affected_indices);
		ApplyStandaloneBoneAdaptersToScene(affected_indices);

		if (BaseDocument* const doc = bone_object->GetDocument())
		{
			bone_tag_node->last_ik_solve_time_ = doc->GetTime();
			bone_tag_node->CacheIKSolveRuntimeOverrides(doc);
			bone_tag_node->MarkPrephysicsIKChainUpdated(doc);
		}
		++solved_count;
	}

	return solved_count;
}

Bool MMDModelManagerObject::RunLayeredBonePass(BaseDocument* doc, const Bool after_physics)
{
	if (!doc)
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return false;

	Bool touched = false;
	bone_manager_data_->EnsurePlaybackExecutionPlan();
	for (const Int32 layer : bone_manager_data_->GetPlaybackLayers())
	{
		Int32 anim_count = 0;
		{
			cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::Animation);
			anim_count = bone_manager_data_->PrepareSceneForPhysicsPlaybackLayer(doc, layer, after_physics);
			SyncStandaloneBoneAdaptersFromScene(true);
		}
		const Int32 ik_count = SolveStandaloneIKForLayer(layer, after_physics, false);
		touched = touched || anim_count > 0 || ik_count > 0;
	}
	return touched;
}

void MMDModelManagerObject::ApplyStandaloneBoneAdaptersToScene() const
{
	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter)
			adapter->ApplyLocalToBoneObject();
	}
}

void MMDModelManagerObject::ApplyStandaloneBoneAdaptersToScene(const maxon::BaseArray<Int32>& bone_indices) const
{
	for (const Int32 bone_index : bone_indices)
	{
		if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index))
			adapter->ApplyLocalToBoneObject();
	}
}

void MMDModelManagerObject::InvalidateStandaloneRuntime()
{
	std::ignore = CaptureModelInfoAnimationSlotFromTracks(animation_index_);
	// Bone tags cache raw solver pointers and same-frame runtime overrides. Clear
	// those before destroying the standalone managers so a rebuilt solver cannot
	// be mistaken for the old one when the allocator reuses an address.
	if (BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_))
	{
		if (auto* const bone_manager = bone_manager_object->GetNodeData<MMDBoneManagerObject>())
			bone_manager->InvalidatePlaybackRuntimeState();
	}
	ResetStandaloneRuntimeCaches();
}

void MMDModelManagerObject::ResetStandaloneRuntimeCaches()
{
	external_bone_poses_.clear();
	external_pose_captured_ = false;
	external_pose_refresh_ = false;
	ik_manager_own_.reset();
	physics_manager_own_.reset();
	physics_bone_pool_.clear();
	physics_bone_adapters_.Reset();
	iferr(physics_dynamic_bone_indices_.Resize(0)) {}
	*is_runtime_initialized_.Write() = false;
	is_animation_initialized_ = false;
	prev_time_ = BaseTime(-1.);
	bone_morph_state_checksum_ = 0;
	has_bone_morph_state_checksum_ = false;
	bone_morph_pose_dirty_ = false;
}

void MMDModelManagerObject::PrepareSameFrameReevaluation(BaseDocument* doc)
{
	if (!bone_manager_data_ || !doc)
		return;

	struct TransientPoseOverride
	{
		Int32 bone_index = -1;
		Vector translation;
		std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };
	};
	std::vector<TransientPoseOverride> transient_overrides;
	if (has_transient_vpd_pose_ && doc->GetTime() == transient_vpd_pose_time_)
	{
		for (const Int32 bone_index : transient_vpd_bone_indices_)
		{
			BaseTag* const tag = bone_manager_data_->FindBone(bone_index);
			const auto* const bone = tag ? tag->GetNodeData<MMDBoneTag>() : nullptr;
			TransientPoseOverride state;
			state.bone_index = bone_index;
			if (bone && bone->HasStaticPoseRuntimeOverride(doc) &&
				bone->GetPlaybackRuntimeOverride(state.translation, state.rotation))
				transient_overrides.push_back(state);
		}
	}

	// Recompute IK/append results when a control, morph, or external pose changes.
	// In particular, old IK rotations must not overwrite a newly active FK control.
	// Keep the Bullet world and explicit transient VPD pose; neither is a new frame.
	bone_manager_data_->InvalidatePlaybackRuntimeState();
	for (const auto& state : transient_overrides)
	{
		BaseTag* const tag = bone_manager_data_->FindBone(state.bone_index);
		if (auto* const bone = tag ? tag->GetNodeData<MMDBoneTag>() : nullptr)
			bone->SetPlaybackRuntimeOverride(doc, state.translation, state.rotation, true);
	}
}

Bool MMDModelManagerObject::BuildStandaloneBoneAdapters()
{
	iferr_scope_handler{ return false; };

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return true;

	if (BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_))
		bone_manager_data_->HandleBoneIndexChangeMessage(bone_manager_object);

	physics_bone_pool_.clear();
	physics_bone_adapters_.Reset();

	std::vector<Int32> sorted_indices;
	for (const auto& entry : bone_manager_data_->bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	physics_bone_pool_.reserve(sorted_indices.size());
	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		if (!bone_tag || !bone_tag->GetObject())
			continue;

		auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
		if (!bone_tag_node)
			continue;

		String bone_name = GetBoneTagName(bone_tag, true);
		if (bone_name.IsEmpty())
			bone_name = GetBoneTagName(bone_tag, false);

		auto adapter = std::make_unique<C4DIKChainNodeAdapter>();
		adapter->SetupFromBone(bone_tag->GetObject(), bone_tag_node, string_util::GetStdString(bone_name));

		C4DIKChainNodeAdapter* const adapter_ptr = adapter.get();
		physics_bone_pool_.push_back(std::move(adapter));
		physics_bone_adapters_.Insert(bone_index, adapter_ptr)iferr_return;
	}

	for (const Int32 bone_index : sorted_indices)
	{
		C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index);
		if (!adapter)
			continue;

		adapter->ClearChildren();
		adapter->SetParentAdapter(nullptr);

		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		if (!bone_object)
			continue;

		if (BaseObject* const parent_object = bone_object->GetUp())
		{
			if (BaseTag* const parent_tag = parent_object->GetTag(g_mmd_bone_tag_id))
			{
				const Int32 parent_index = bone_manager_data_->FindBoneIndex(parent_tag);
				if (C4DIKChainNodeAdapter* const parent_adapter = GetBoneAdapter(parent_index))
				{
					adapter->SetParentAdapter(parent_adapter);
					parent_adapter->AddChildAdapter(adapter);
				}
			}
		}
	}

	for (const Int32 bone_index : sorted_indices)
	{
		C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index);
		if (adapter && adapter->GetParent() == nullptr)
		{
			adapter->UpdateInitialGlobalTransform();
			adapter->ResetCurrentTransformToInitial();
		}
	}

	return true;
}

Bool MMDModelManagerObject::BuildStandaloneIKManager()
{
	iferr_scope_handler{ return false; };

	ik_manager_own_ = std::make_unique<StandaloneIKManager>();
	if (!ik_manager_own_)
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return true;

	std::vector<Int32> sorted_indices;
	for (const auto& entry : bone_manager_data_->bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		if (!bone_tag)
			continue;

		const BaseContainer* const bc = bone_tag->GetDataInstance();
		if (!bc || !bc->GetBool(PMX_BONE_IS_IK))
			continue;

		C4DIKChainNodeAdapter* const control_adapter = GetBoneAdapter(bone_index);
		if (!control_adapter)
			continue;

		auto* const solver = ik_manager_own_->AddIKSolver();
		String solver_name = GetBoneTagName(bone_tag, true);
		if (solver_name.IsEmpty())
			solver_name = GetBoneTagName(bone_tag, false);
		solver->SetName(string_util::GetStdString(solver_name));
		solver->SetIKNode(control_adapter);

		// PMX convention (matches libMMD PMXModel loader):
		//   - IK node    = the control/goal bone (external, position stays fixed)
		//   - target node = the effector bone at the end of the chain (descendant)
		// SolveCore reads m_ikNode position once (must be stable); m_ikTarget
		// is re-read per chain (moves with rotation).  BuildChainPath walks
		// from m_ikTarget upward to find chain nodes.
		// PMX_BONE_IK_TARGET_BONE_* stores the effector bone, not the control IK
		// bone itself. Resolve that effector via the stable BaseLink instead of
		// the stale PMX-file index.
		Int32 effector_index = -1;
		C4DIKChainNodeAdapter* effector_adapter = nullptr;
		BaseDocument* const tag_doc = bone_tag->GetDocument();
		if (GeData link_data; bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_IK_TARGET_BONE_LINK)), link_data, DESCFLAGS_GET::NONE))
		{
			BaseList2D* linked = nullptr;
			if (tag_doc)
				linked = const_cast<BaseList2D*>(link_data.GetLink(tag_doc));
			if (!linked)
			{
				if (const BaseLink* const raw_link = link_data.GetBaseLink())
					linked = static_cast<BaseList2D*>(raw_link->ForceGetLink());
			}
			if (linked && linked->IsInstanceOf(Obase))
			{
				if (BaseTag* const target_tag = static_cast<BaseObject*>(linked)->GetTag(g_mmd_bone_tag_id))
				{
					const Int32 resolved = bone_manager_data_->FindBoneIndex(target_tag);
					if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(resolved))
					{
						effector_index = resolved;
						effector_adapter = adapter;
					}
				}
			}
		}
		// Legacy fallback: older scenes/cases without the link may still carry
		// a usable DFS index in the container.
		if (!effector_adapter)
		{
			const Int32 legacy = bc->GetInt32(PMX_BONE_IK_TARGET_BONE_INDEX);
			if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(legacy))
			{
				effector_index = legacy;
				effector_adapter = adapter;
			}
		}

		if (effector_adapter)
			solver->SetTargetNode(effector_adapter);
		const Int32 iter_count = bc->GetInt32(PMX_BONE_IK_ITERATION);
		const Float unit_angle = bc->GetFloat(PMX_BONE_IK_UNIT_ANGLE);
		solver->SetIterateCount(static_cast<uint32_t>(iter_count <= 0 ? 4 : iter_count));
		solver->SetLimitAngle(static_cast<float>(unit_angle));

		const auto* const enabled_state = ik_solver_enable_states_.Find(solver_name);
		const Bool enabled = enabled_state ? enabled_state->GetValue() : bc->GetBool(PMX_BONE_IS_IK);
		solver->Enable(enabled);
	}

	return true;
}

Bool MMDModelManagerObject::BuildStandalonePhysics()
{
	iferr_scope_handler{ return false; };

	physics_manager_own_ = std::make_unique<libmmd::MMDPhysicsManager>();
	if (!physics_manager_own_ || !physics_manager_own_->Create())
		return false;

	iferr(physics_dynamic_bone_indices_.Resize(0))
		return false;

	if (rigid_manager_data_)
	{
		rigid_manager_data_->mmd_physics_manager_ = physics_manager_own_.get();
		if (!rigid_manager_data_->BuildStandaloneRigidBodies(physics_manager_own_.get(), [this](const Int32 bone_index) -> libmmd::IMMDNode*
		{
			return GetBoneAdapter(bone_index);
		}))
		{
			return false;
		}

		auto* const physics = physics_manager_own_->GetMMDPhysics();
		auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
		if (physics && rigid_bodies)
		{
			for (const auto& rigid_body : *rigid_bodies)
				physics->AddRigidBody(rigid_body.get());
		}

		if (BaseObject* const rigid_manager_object = io_util::ResolveObjectLink(rigid_manager_))
		{
			for (BaseObject* child = rigid_manager_object->GetDown(); child; child = child->GetNext())
			{
				if (!child->IsInstanceOf(g_mmd_rigid_object_id))
					continue;

				const BaseContainer* const bc = child->GetDataInstance();
				if (!bc)
					continue;

				const auto op_mode = static_cast<libmmd::PMXRigidbody::Operation>(bc->GetInt32(RIGID_PHYSICS_MODE));
				if (op_mode == libmmd::PMXRigidbody::Operation::Static)
					continue;

				const Int32 bone_index = bc->GetInt32(RIGID_RELATED_BONE_INDEX);
				if (bone_index < 0)
					continue;

				iferr(physics_dynamic_bone_indices_.Append(bone_index)) {}
			}
		}

	}

	if (joint_manager_data_)
	{
		joint_manager_data_->mmd_physics_manager_ = physics_manager_own_.get();
		if (!joint_manager_data_->BuildStandaloneJoints(physics_manager_own_.get()))
			return false;

		auto* const physics = physics_manager_own_->GetMMDPhysics();
		auto* const joints = physics_manager_own_->GetJoints();
		if (physics && joints)
		{
			for (const auto& joint : *joints)
				physics->AddJoint(joint.get());
		}
	}

	if (rigid_manager_data_)
		rigid_manager_data_->ReconnectRigidBodyPointers(physics_manager_own_.get());
	if (joint_manager_data_)
		joint_manager_data_->ReconnectJointPointers(physics_manager_own_.get());

	return true;
}

Bool MMDModelManagerObject::EnsureStandaloneRuntimeManagers()
{
	iferr_scope_handler{ return false; };
	// CTracks may not have been hydrated when NodeData::Read ran. Migrate once
	// here, before editing or switching the active slot can remove those tracks.
	if (migrate_legacy_morph_tracks_)
	{
		if (model_mode_ != MODEL_MODE_EDIT && !CaptureMorphAnimationSlotFromTracks(animation_index_))
			return false;
		migrate_legacy_morph_tracks_ = false;
	}

	if (*is_runtime_initialized_.Read() && ik_manager_own_ && physics_manager_own_)
		return true;
	cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::Rebuild);

	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
	{
		if (!UpdateManagers(op))
			return false;
	}

	if (!BuildStandaloneBoneAdapters())
		return false;
	if (!BuildStandaloneIKManager())
		return false;
	if (!BuildStandalonePhysics())
		return false;

	BuildIKSolverUI();
	if (bone_manager_data_)
	{
		if (animation_slot_metadata_.GetCount() > 0)
			bone_manager_data_->EnsureAllAnimationSlotCount(static_cast<Int32>(animation_slot_metadata_.GetCount()));
		if (animation_index_ >= 0 && animation_index_ < animation_slot_metadata_.GetCount())
			bone_manager_data_->SetAllActiveAnimationSlot(animation_index_);

		// The manager container is the persistent source of truth for its
		// independently editable mode. Hydrate every tag on every runtime rebuild,
		// including edit mode and scenes without an animation slot.
		Int32 bone_mode = model_mode_ == MODEL_MODE_ANIM ? BONE_MODE_ANIM : BONE_MODE_EDIT;
		if (BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_))
		{
			if (const BaseContainer* const bone_bc = bone_manager_object->GetDataInstance())
				bone_mode = NormalizeModelMode(bone_bc->GetInt32(BONE_MODE));
			bone_manager_data_->SetAllBoneMode(bone_mode, bone_manager_object);
		}
		else
		{
			bone_manager_data_->SetAllBoneMode(bone_mode);
		}
	}

	ApplyPhysicsConfigToRuntime(reinterpret_cast<BaseObject*>(Get()));
	ResetStandalonePhysics();
	*is_runtime_initialized_.Write() = true;
	return true;
}

void MMDModelManagerObject::ResetStandalonePhysics()
{
	cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::Physics);
	if (!physics_manager_own_)
		return;

	// Resetting bodies alone retains Bullet's contact/constraint warm state and
	// substep history. A seek must start from the same cold world as a fresh load.
	// During initial EnsureStandaloneRuntimeManagers the world is already new;
	// that path has not published is_runtime_initialized_ yet.
	if (*is_runtime_initialized_.Read())
	{
		// Joint frames are authored relative to the bind-space bodies. Rebuilding
		// against the current animated pose would silently change those anchors.
		// Reset adapters only, then restore their scene pose before resetting bodies.
		for (const auto& adapter : physics_bone_pool_)
		{
			if (adapter && adapter->GetParent() == nullptr)
				adapter->ResetCurrentTransformToInitial();
		}
		const Bool rebuilt = BuildStandalonePhysics();
		SyncStandaloneBoneAdaptersFromScene(true);
		if (!rebuilt)
		{
			*is_runtime_initialized_.Write() = false;
			if (rigid_manager_data_)
				rigid_manager_data_->ReconnectRigidBodyPointers(physics_manager_own_.get());
			if (joint_manager_data_)
				joint_manager_data_->ReconnectJointPointers(physics_manager_own_.get());
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] ResetStandalonePhysics: cold world rebuild failed");
			return;
		}
		ApplyPhysicsConfigToRuntime(reinterpret_cast<BaseObject*>(Get()));
	}

	auto* const physics = physics_manager_own_->GetMMDPhysics();
	auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
	if (!physics || !rigid_bodies)
		return;

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->ResetTransform();

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->Reset(physics);

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->SetActivation(true);
}

void MMDModelManagerObject::StepStandalonePhysics(const Float elapsed)
{
	cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::Physics);
	if (!physics_manager_own_)
		return;

	bone_manager_data_ = GetBoneManagerData();
	auto* const physics = physics_manager_own_->GetMMDPhysics();
	auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
	if (!physics || !rigid_bodies)
		return;

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->SyncBonePositionToPhysics(elapsed);

	physics->Update(elapsed);
	ApplyStandalonePhysicsResults();
}

void MMDModelManagerObject::ApplyStandalonePhysicsResults()
{
	if (!physics_manager_own_)
		return;
	auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
	if (!rigid_bodies)
		return;
	BaseObject* const model_object = reinterpret_cast<BaseObject*>(Get());
	BaseDocument* const doc = model_object ? model_object->GetDocument() : nullptr;

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->ReflectGlobalTransform();

	SyncStandaloneBoneAdaptersLocalFromGlobal(physics_dynamic_bone_indices_);

	if (bone_manager_data_)
	{
		for (const Int32 bone_index : physics_dynamic_bone_indices_)
		{
			if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index))
			{
				Vector translation;
				std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };
				adapter->GetCurrentRelativeState(translation, rotation);
				bone_manager_data_->SetPhysicsOverride(bone_index, doc, translation, rotation);
			}
		}
	}

	ApplyPhysicsResultsToBoneObjects();
}

void MMDModelManagerObject::ApplyPhysicsResultsToBoneObjects() const
{
	ApplyStandaloneBoneAdaptersToScene(physics_dynamic_bone_indices_);
	MarkMeshHierarchyDirty(GetMeshManagerObject());
}

void MMDModelManagerObject::CommitEditModeBindState(BaseDocument* doc)
{
	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
		std::ignore = UpdateManagers(op);

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
		bone_manager_data_->CommitEditModeBindState(io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->CommitEditorTransforms(io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->CommitEditorTransforms(io_util::ResolveObjectLink(joint_manager_));
	if (mesh_manager_data_ || GetMeshManagerData())
		mesh_manager_data_->RefreshWeightBindPoses(GetMeshManagerObject(), doc);
	if (bone_manager_data_)
		bone_manager_data_->SetAllBoneMode(MODEL_MODE_ANIM, io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->SetAllRigidMode(MODEL_MODE_ANIM, io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->SetAllJointMode(MODEL_MODE_ANIM, io_util::ResolveObjectLink(joint_manager_));

	MarkMeshHierarchyDirty(GetMeshManagerObject());
	*is_morph_initialized_.Write() = true;
	*update_morph_.Write() = true;
}

void MMDModelManagerObject::RestoreBindStateForEdit(BaseDocument* doc)
{
	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
		std::ignore = UpdateManagers(op);

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
		bone_manager_data_->RestoreBindStateForEdit(io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->RestoreEditorTransforms(io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->RestoreEditorTransforms(io_util::ResolveObjectLink(joint_manager_));
	if (bone_manager_data_)
		bone_manager_data_->SetAllBoneMode(MODEL_MODE_EDIT, io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->SetAllRigidMode(MODEL_MODE_EDIT, io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->SetAllJointMode(MODEL_MODE_EDIT, io_util::ResolveObjectLink(joint_manager_));
	ClearMorphRuntimeForEdit();
	MarkMeshHierarchyDirty(GetMeshManagerObject());

	(void)doc;
}

Bool MMDModelManagerObject::IsPhysicsEnabled(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	return bc ? bc->GetBool(MODEL_PHYSICS_ENABLED) : true;
}

Bool MMDModelManagerObject::ShouldResetPhysicsOnSeek(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	return bc ? bc->GetBool(MODEL_PHYSICS_RESET_ON_SEEK) : true;
}

Vector MMDModelManagerObject::GetPhysicsGravity(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	const Float strength = bc ? bc->GetFloat(MODEL_PHYSICS_GRAVITY_STRENGTH, 98.0) : 98.0;
	Vector direction = bc ? bc->GetVector(MODEL_PHYSICS_GRAVITY_DIRECTION, Vector(0, -1, 0)) : Vector(0, -1, 0);
	const Float64 length_sq = static_cast<Float64>(direction.x) * direction.x
		+ static_cast<Float64>(direction.y) * direction.y
		+ static_cast<Float64>(direction.z) * direction.z;
	if (length_sq <= std::numeric_limits<Float64>::epsilon())
		direction = Vector(0, -1, 0);
	else
		direction = direction.GetNormalized();
	return direction * strength;
}

void MMDModelManagerObject::ApplyPhysicsConfigToRuntime(const BaseObject* op)
{
	if (!physics_manager_own_)
		return;

	auto* const physics = physics_manager_own_->GetMMDPhysics();
	if (!physics)
		return;

	if (auto* const world = physics->GetDynamicsWorld())
	{
		const Vector gravity = IsPhysicsEnabled(op) ? GetPhysicsGravity(op) : Vector(0);
		world->setGravity(btVector3(
			static_cast<btScalar>(gravity.x),
			static_cast<btScalar>(gravity.y),
			static_cast<btScalar>(gravity.z)));
	}
}
