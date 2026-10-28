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
#include "utils/mmd_control_workflow.hpp"
#include "utils/string_util.hpp"
#include "utils/cmt_runtime_profile.hpp"
#include "utils/cmt_anim_flow_debug.hpp"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include <btBulletDynamicsCommon.h>
#include <algorithm>
#include <limits>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <vector>
#include "utils/cmt_runtime_profile_c4d.hpp"

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

	void MarkMeshHierarchyDirty(BaseObject* mesh_manager_object, const Bool weights_changed = true)
	{
		CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::MeshInvalidation);
		if (!mesh_manager_object)
			return;

		for (BaseObject* mesh_object = mesh_manager_object->GetDown(); mesh_object; mesh_object = mesh_object->GetNext())
		{
			MarkSceneNodeDirty(mesh_object);

			for (BaseTag* tag = mesh_object->GetFirstTag(); tag; tag = tag->GetNext())
			{
				// Pose writes do not change weights or bind matrices. MSG_UPDATE on
				// every weight tag rebuilds its data even when only joints moved.
				if (weights_changed && tag->GetType() == Tweights)
				{
					CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::WeightUpdate);
					MarkSceneNodeDirty(tag);
				}
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
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::BoneStateSync);
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
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::BoneStateSync);
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
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::IK);
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
		if (ik_bone_tag && mmd_control_workflow::OwnsLegSolver(static_cast<BaseTag*>(ik_bone_tag->Get()))) return true;
		if (ik_bone_tag && mmd_control_workflow::IsForcedIK(static_cast<BaseTag*>(ik_bone_tag->Get()))) return false;
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

Bool MMDModelManagerObject::RunLayeredBonePass(BaseDocument* doc, const Bool after_physics,
    mmd_control_workflow::EvaluationContext* controls)
{
	if (!doc)
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return false;

	Bool touched = false;
	// Execute validates the shared plan before entering the two phases.
	for (const Int32 layer : bone_manager_data_->GetPlaybackLayers())
	{
		// Empty after-deform layers have neither animation nor IK work. Keep
		// pre-physics layers: controls can own after-deform bones, and Bullet
		// must still receive the scene pose when every bone is after-deform.
		if (after_physics && bone_manager_data_->GetPlaybackBonesForLayer(layer, after_physics).empty())
			continue;

		Int32 anim_count = 0;
		{
			CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::Animation);
			anim_count = bone_manager_data_->PrepareSceneForPhysicsPlaybackLayer(doc, layer, after_physics);
			SyncStandaloneBoneAdaptersFromScene(true);
		}
		const Int32 control_ik_count = mmd_control_workflow::SolveLayer(*bone_manager_data_, doc, layer, after_physics, controls);
		if (control_ik_count > 0)
			SyncStandaloneBoneAdaptersFromScene(true);
		const Int32 ik_count = SolveStandaloneIKForLayer(layer, after_physics, false);
		touched = touched || anim_count > 0 || ik_count > 0 || control_ik_count > 0;
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
	// P9-001：异步管线持有影子世界与常驻 worker，必须在主世界被拆掉之前关掉——
	// 否则 worker 与影子世界会活过「它被种子化的那个主世界」，旧 world 的结果仍可能
	// 通过 epoch 校验写回重建后的场景（撤销、模式切换、刚体编辑、烘焙都走这里）。
	// Shutdown 是幂等的；下一次 EnsureStandaloneRuntimeManagers() 会用新 epoch 重建影子世界。
	ShutdownStandaloneAsyncPhysics();
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

// ===== P2：异步物理管线（影子世界 + 常驻 worker + 结果槽） =====
// P8 之后默认**开启**：A/B/A 真机验证过稳态语义（动力学刚体 async(N) == sync(N-1)
// 逐位相同，骨骼跟随刚体 async(N) == sync(N)），主线程物理开销 16.7 ms → 0.9 ms。
// 显式设置 CMT_PHYSICS_ASYNC=0/false/off/no 可关闭；无法启动或管线饿死时自动回退到同步步进。
Bool MMDModelManagerObject::AsyncPhysicsSwitchEnabled()
{
	const char* const value = std::getenv("CMT_PHYSICS_ASYNC");
	if (!value || !*value)
		return true;
	const char head = value[0];
	return !(head == '0' || head == 'f' || head == 'F' || head == 'n' || head == 'N' || head == 'o' || head == 'O');
}

// P2-004 / t56 缺陷 A：刚体稳定身份 = PMX 刚体下标（RIGID_INDEX）。
// RIGID_INDEX 是**字符串**参数（mmd_rigid_manager.cpp:449 写入 String::IntToString），
// 旧实现直接 GetInt32 恒读 0 → 479 条身份全重复 → MapRigidSnapshotToMain 整帧拒绝写回。
// 这里与 ReadObjectStoredIndex（mmd_rigid_manager.cpp:96-111）同构：先取数据指针，再按 DTYPE 分支；
// 缺失 / 类型不符 / 非法值（负数、非数字）一律跳过，由数量校验 fail-closed。
static void CollectStandaloneRigidIdentities(MMDRigidManagerObject* const manager, std::vector<Int32>& out)
{
	out.clear();
	if (!manager)
		return;
	BaseObject* const op = static_cast<BaseObject*>(manager->Get());
	if (!op)
		return;
	std::vector<std::pair<Int32, Int32>> entries;
	for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
	{
		if (!child->IsInstanceOf(g_mmd_rigid_object_id))
			continue;
		const BaseContainer* const bc = child->GetDataInstance();
		if (!bc)
			continue;
		const GeData* const data = bc->GetDataPointer(RIGID_INDEX);
		if (!data)
			continue;

		Int32 identity = -1;
		if (data->GetType() == DA_STRING)
			identity = cmt::physics::ParseRigidIdentityText(string_util::GetStdString(data->GetString()).c_str());
		else if (data->GetType() == DA_LONG)
			identity = cmt::physics::ParseRigidIdentityLong(static_cast<long long>(data->GetInt32()));
		if (identity < 0)
			continue;

		entries.emplace_back(identity, identity);
	}
	std::stable_sort(entries.begin(), entries.end(),
		[](const std::pair<Int32, Int32>& a, const std::pair<Int32, Int32>& b) { return a.first < b.first; });
	out.reserve(entries.size());
	for (const auto& entry : entries)
		out.push_back(entry.second);
}

// P6-001：影子世界从主世界当前真实刚体状态种子化（变换/线速度/角速度/激活态）。
// 主世界此时可能已被 ResetStandalonePhysics() 复位到当前帧真实姿态；影子刚体却是刚按
// PMX 定义新建、停在绑定姿态。不种子化就会出现「第一步被骨骼位置拽出 97 mm」的分岔。
Bool MMDModelManagerObject::SeedStandaloneAsyncWorldFromMain()
{
	auto* const shadow_bodies = async_physics_manager_own_ ? async_physics_manager_own_->GetRigidBodys() : nullptr;
	auto* const main_bodies = physics_manager_own_ ? physics_manager_own_->GetRigidBodys() : nullptr;
	if (!shadow_bodies || !main_bodies)
		return false;

	const cmt::physics::RigidSeedStats stats = cmt::physics::SeedWorldFromMain(*shadow_bodies, *main_bodies);
	async_seed_stats_ = stats;
	if (!stats.ok)
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
			"[CMT] async physics refused: rigid seed mismatch (bodies=@ copied=@ skipped=@)",
			Int32(stats.bodies), Int32(stats.copied), Int32(stats.skipped));
		return false;
	}
	return true;
}

// P7-001：影子世界首步前预热 libMMD motion state 的 m_prevBoneOrigin。
// 此刻 worker 未运行，写影子节点安全；真正步进后主线程只提交纯数据载荷。
// elapsed=0 只更新 prev origin，不注入绑定姿态到当帧姿态的虚假速度。
Bool MMDModelManagerObject::PrimeStandaloneAsyncPreviousBoneOrigins()
{
	if (async_prev_primed_)
		return true;
	auto* const shadow_bodies = async_physics_manager_own_ ? async_physics_manager_own_->GetRigidBodys() : nullptr;
	if (!shadow_bodies)
		return false;

	const std::size_t bone_count = static_cast<std::size_t>(async_shadow_bones_.Count());
	for (std::size_t index = 0; index < bone_count; ++index)
	{
		if (libmmd::IMMDNode* const live_node = GetBoneAdapter(static_cast<Int32>(index)))
			if (auto* const shadow_node = async_shadow_bones_.Node(static_cast<Int32>(index)))
				shadow_node->SetGlobalTransform(live_node->GetGlobalTransform());
	}

	for (const auto& rigid_body : *shadow_bodies)
	{
		if (rigid_body)
			rigid_body->SyncBonePositionToPhysics(0.F);
	}
	async_prev_primed_ = true;
	return true;
}

// P4：seek / 导出 / 中途开启一律「镜像重建」——影子世界与同步世界在同一时点、
// 按同一构造序列重建，epoch 随世界边界推进、计数清零。
// 不再用重复步进冒充历史：t58 的 f=541 整帧跳 93.6 mm 正是 replay 与真实输入
// 轨迹不相交造成的，那套口径已废弃。
Bool MMDModelManagerObject::RebuildStandaloneAsyncShadow()
{
	async_prev_primed_ = false;
	const Bool was_async = async_physics_active_;
	if (was_async)
		ShutdownStandaloneAsyncPhysics();
	async_frames_since_reset_ = 0;
	if (!AsyncPhysicsSwitchEnabled())
		return true;
	return StartStandaloneAsyncPhysics();
}

Bool MMDModelManagerObject::StartStandaloneAsyncPhysics()
{
	if (async_physics_active_)
		return true;
	if (!AsyncPhysicsSwitchEnabled())
		return false;

	async_prev_primed_ = false;
	const std::size_t bone_count = physics_bone_pool_.size();
	if (bone_count == 0)
		return false;
	// 没有刚体就没有可并行的物理：保持同步路径，别为一个空世界起 worker。
	const auto* const rigid_bodies = physics_manager_own_ ? physics_manager_own_->GetRigidBodys() : nullptr;
	if (!rigid_bodies || rigid_bodies->empty())
		return false;

	async_shadow_bones_.Resize(bone_count);
	// P8-001：影子世界必须与主世界在**同一姿态窗口**内构建。主世界（BuildStandalonePhysics）
	// 总是在适配器被 Pin 回初始姿态的窗口里建刚体与关节（mmd_model_runtime.cpp:1395-1400），
	// 关节锚帧因此取自 bind 空间；影子世界若在当前场景姿态构建，锚帧就会多叠一层场景姿态，
	// 两世界的约束系统从第一步起就不同（夹具 c7-build-pose-mismatch 逐位证明）。
	// 所以这里先用初始姿态建世界，建完再恢复到当帧场景姿态。
	// 同时把初始全局矩阵写进影子节点：MMDRigidBody::Create(pmx, IMMDNode*) 用
	// GetInitialGlobalTransform() 计算 offsetMat（MMDPhysics.cpp:899），影子节点默认
	// identity 会让 offsetMat 退化成世界空间 rbMat，与主世界 bind^-1*rbMat 不同。
	for (std::size_t index = 0; index < bone_count; ++index)
	{
		if (libmmd::IMMDNode* const node = GetBoneAdapter(static_cast<Int32>(index)))
		{
			if (auto* const shadow_node = async_shadow_bones_.Node(static_cast<Int32>(index)))
			{
				const Eigen::Matrix4f& initial = node->GetInitialGlobalTransform();
				shadow_node->SetInitialGlobalTransform(initial);
				shadow_node->SetGlobalTransform(initial);
			}
		}
	}

	async_physics_manager_own_ = std::make_unique<libmmd::MMDPhysicsManager>();
	if (!async_physics_manager_own_ || !async_physics_manager_own_->Create())
	{
		async_physics_manager_own_.reset();
		return false;
	}

	// t56 缺陷 B：影子世界必须与主线程同一口径——主线程 ApplyPhysicsConfigToRuntime
	// 用 document_fps * GetPhysicsSubsteps(op)（30fps × 3 子步 = 90Hz）并设置重力。
	// 这里复刻同一取值表达式（document fps × substeps、GetPhysicsGravity），只是目标管理器不同。
	ApplyPhysicsConfigToAsyncWorld(async_physics_manager_own_.get(), static_cast<BaseObject*>(Get()));

	// 影子世界用同一批 PMX 刚体定义重建，但绑定到影子节点；因此构建前后必须恢复
	// rigid/joint manager 上的物理管理器指针，避免污染主世界。
	libmmd::MMDPhysicsManager* const previous_manager =
		rigid_manager_data_ ? rigid_manager_data_->mmd_physics_manager_ : nullptr;

	if (rigid_manager_data_)
	{
		rigid_manager_data_->mmd_physics_manager_ = async_physics_manager_own_.get();
		if (!rigid_manager_data_->BuildStandaloneRigidBodies(
			async_physics_manager_own_.get(),
			[this](const Int32 bone_index) -> libmmd::IMMDNode*
			{
				return async_shadow_bones_.MmdNode(bone_index);
			}))
		{
			rigid_manager_data_->mmd_physics_manager_ = previous_manager;
			async_physics_manager_own_.reset();
			return false;
		}

		if (auto* const physics = async_physics_manager_own_->GetMMDPhysics())
		{
			// 名字带 async_ 前缀：外层 :911 已有一个同名的主世界 rigid_bodies，重名会被 C4456 警告。
			if (auto* const async_rigid_bodies = async_physics_manager_own_->GetRigidBodys())
			{
				for (const auto& rigid_body : *async_rigid_bodies)
					physics->AddRigidBody(rigid_body.get());
				// P4：复刻同步世界的三连激活（ResetStandalonePhysics；缺它时动态刚体停在
				// kinematic，Bullet 只做运动学搬运、根本不积分——t60 实测 479/479 全部 kinematic）。
				for (const auto& rigid_body : *async_rigid_bodies)
					if (rigid_body)
						rigid_body->ResetTransform();
				for (const auto& rigid_body : *async_rigid_bodies)
					if (rigid_body)
						rigid_body->Reset(physics);
				for (const auto& rigid_body : *async_rigid_bodies)
					if (rigid_body)
						rigid_body->SetActivation(true);

				// P8-002：关节锚帧取自「建约束瞬间」的刚体世界变换（MMDPhysics.cpp:1252-1255）。
				// 主世界在绑定姿态窗口里建刚体后紧接着建关节（mmd_model_runtime.cpp:750-763），
				// 此时刚体世界 = rbMat；影子世界必须在这里（刚体仍是 bind 窗口姿态、尚未种子化）
				// 建关节，锚帧才会同样是 rbMat。原来把建关节放在种子化之后，锚帧取的是主世界
				// 当前世界变换，两世界约束系统不同，第一步就发散。
				if (joint_manager_data_)
				{
					libmmd::MMDPhysicsManager* const joint_previous_manager = joint_manager_data_->mmd_physics_manager_;
					joint_manager_data_->mmd_physics_manager_ = async_physics_manager_own_.get();
					const Bool joints_ok = joint_manager_data_->BuildStandaloneJoints(async_physics_manager_own_.get());
					joint_manager_data_->mmd_physics_manager_ = joint_previous_manager;
					if (joints_ok)
					{
						if (auto* const shadow_physics = async_physics_manager_own_->GetMMDPhysics())
						{
							if (auto* const shadow_joints = async_physics_manager_own_->GetJoints())
							{
								for (const auto& joint : *shadow_joints)
									shadow_physics->AddJoint(joint.get());
							}
						}
					}
					// 关节建不出来不影响「异步骨架」演示，但结果槽里的刚体/骨骼快照会退化成无关节世界；
					// 这一点必须在报告里如实记录（未覆盖项）。
				}

				// 建世界窗口结束：把影子节点恢复到当帧场景姿态，让后续种子化/预热看到的
				// 世界矩阵与主线程一致（worker 尚未启动，写影子节点安全）。
				for (std::size_t index = 0; index < bone_count; ++index)
				{
					if (libmmd::IMMDNode* const node = GetBoneAdapter(static_cast<Int32>(index)))
					{
						if (auto* const shadow_node = async_shadow_bones_.Node(static_cast<Int32>(index)))
							shadow_node->SetGlobalTransform(node->GetGlobalTransform());
					}
				}

				// P6-001：影子世界不能从 PMX 绑定变换冷启动——把主世界当前真实刚体状态
				// 逐项搬过来（btTransform / 线速度 / 角速度 / 激活态，见 cmt_physics_seed.h）。
				// 任一项缺失都会让第一步起点不同（夹具逐项证伪）。
				if (!SeedStandaloneAsyncWorldFromMain())
				{
					rigid_manager_data_->mmd_physics_manager_ = previous_manager;
					async_physics_manager_own_.reset();
					return false;
				}
				// P7-001：影子世界已建好并种子化，worker 尚未启动，写影子节点安全。
				// 用当帧骨骼姿态预热 prev origin；elapsed=0 不注入运动学速度。
				if (!PrimeStandaloneAsyncPreviousBoneOrigins())
				{
					rigid_manager_data_->mmd_physics_manager_ = previous_manager;
					async_physics_manager_own_.reset();
					return false;
				}
			}
		}
	}

	// P2-004：采集稳定身份，并断言「身份表 / 影子刚体表 / 主世界刚体表」数量一致；
	// 任一处不一致就不启动异步档（fail-closed），绝不带着错位映射跑。
	CollectStandaloneRigidIdentities(rigid_manager_data_, async_rigid_identity_);
	main_rigid_identity_ = async_rigid_identity_;
	{
		const auto* const shadow_bodies = async_physics_manager_own_ ? async_physics_manager_own_->GetRigidBodys() : nullptr;
		const auto* const main_bodies = physics_manager_own_ ? physics_manager_own_->GetRigidBodys() : nullptr;
		const std::size_t identity_count = async_rigid_identity_.size();
		const std::size_t shadow_count = shadow_bodies ? shadow_bodies->size() : 0;
		const std::size_t main_count = main_bodies ? main_bodies->size() : 0;
		if (identity_count == 0 || identity_count != shadow_count || identity_count != main_count)
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT] async physics refused: rigid identity mismatch (identity=@ shadow=@ main=@)",
				Int32(identity_count), Int32(shadow_count), Int32(main_count));
			async_rigid_identity_.clear();
			main_rigid_identity_.clear();
			async_physics_manager_own_.reset();
			return false;
		}
	}

	async_physics_pipeline_.Configure(
		[this](const float dt, const cmt::physics::AsyncJobPayload& job)
		{
			// P2-001：影子节点树只在本线程被写。主线程只提交纯数据载荷，这里先把它应用进影子节点。
			const std::size_t shadow_count = static_cast<std::size_t>(async_shadow_bones_.Count());
			const std::size_t count = job.bone_world.size() < shadow_count ? job.bone_world.size() : shadow_count;
			for (std::size_t index = 0; index < count; ++index)
				async_shadow_bones_.Node(static_cast<Int32>(index))->SetGlobalTransform(job.bone_world[index]);

			auto* const physics = async_physics_manager_own_ ? async_physics_manager_own_->GetMMDPhysics() : nullptr;
			auto* const rigid_bodies = async_physics_manager_own_ ? async_physics_manager_own_->GetRigidBodys() : nullptr;
			if (!physics || !rigid_bodies)
				return;
			for (const auto& rigid_body : *rigid_bodies)
				rigid_body->SyncBonePositionToPhysics(dt);
			physics->Update(dt);
			for (const auto& rigid_body : *rigid_bodies)
				rigid_body->ReflectGlobalTransform();
		},
		[this](std::vector<Eigen::Matrix4f>& bone_world, std::vector<Eigen::Matrix4f>& rigid_world)
		{
			async_shadow_bones_.SnapshotWorldMatrices(bone_world);
			rigid_world.clear();
			if (auto* const rigid_bodies = async_physics_manager_own_ ? async_physics_manager_own_->GetRigidBodys() : nullptr)
			{
				rigid_world.reserve(rigid_bodies->size());
				for (const auto& rigid_body : *rigid_bodies)
					rigid_world.push_back(rigid_body->GetTransform());
			}
		});

	// 背压：上一帧仍在 worker 手上时最多等 500ms（≈25 帧 @30fps），仍忙则拒绝本帧。
	// P9-001：这个上限是「worker 卡死时主线程必须能返回」的保险，正常一步只要几毫秒。
	async_physics_pipeline_.SetBlockWaitBudgetMs(500);

	if (!async_physics_pipeline_.Start(1.F / fps_))
	{
		async_physics_manager_own_.reset();
		return false;
	}

	// P4-001：epoch 只在世界边界推进。首次初始化给 1，之后每次重建/seek/导出/中途开启
	// 严格递增（由 PhysicsEpochCounter 统一维护，绝不回退到 1、也不回绕到 0）。
	async_physics_epoch_ = async_epoch_counter_.Next();
	async_submitted_frame_ = 0;
	async_applied_frame_ = 0;
	async_physics_active_ = true;
	return true;
}

void MMDModelManagerObject::ShutdownStandaloneAsyncPhysics()
{
	async_physics_active_ = false;
	async_prev_primed_ = false;
	async_physics_pipeline_.CancelAndJoin();
	// P9-002：结果缓存属于这一代世界，随管线一起作废（否则同帧重算会重放旧世界的姿态）。
	async_last_result_ = cmt::physics::AsyncFrameResult{};
	has_async_last_result_ = false;
	// P9-003：连续失败计数与「只打一次」的诊断标志随本代世界一起清空，
	// 这样重建后的新世界仍会在首次分发/首次被拒时各打一条判据。
	async_submit_fail_streak_ = 0;
	async_dispatch_reported_ = false;
	async_backpressure_reported_ = false;
	// P4-001：暂停/销毁不推进 epoch；下一次 StartStandaloneAsyncPhysics() 建立新世界时才推进。
	async_submitted_frame_ = 0;
	async_applied_frame_ = 0;
	async_physics_manager_own_.reset();
}

void MMDModelManagerObject::StepStandaloneAsyncPhysics(const Float elapsed)
{
	(void)elapsed;
	// P9-001：worker 抛过异常（Bullet/分配器失败）后不再生产——关掉本代异步世界、回退同步步进，
	// 否则物理会停在最后一份结果上且没有任何提示。
	if (async_physics_pipeline_.Fatal())
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
			"[CMT][physics-async] fallback_to_sync reason=worker_fatal epochs=@ submitted=@ applied=@",
			Int64(async_physics_epoch_), Int64(async_submitted_frame_), Int64(async_applied_frame_));
		ShutdownStandaloneAsyncPhysics();
		StepStandalonePhysicsRaw(elapsed);
		return;
	}
	if (!async_physics_active_ || !async_physics_manager_own_)
	{
		StepStandalonePhysicsRaw(elapsed);
		return;
	}

	// P2-001：主线程只打包「纯数据载荷」（骨骼世界矩阵），绝不写影子节点；
	// 影子节点树由 worker 独占（它先应用载荷，再推进物理）。
	std::vector<Eigen::Matrix4f> bone_world;
	const std::size_t shadow_count = static_cast<std::size_t>(async_shadow_bones_.Count());
	bone_world.reserve(shadow_count);
	for (std::size_t index = 0; index < shadow_count; ++index)
	{
		libmmd::IMMDNode* const node = GetBoneAdapter(static_cast<Int32>(index));
		bone_world.push_back(node ? node->GetGlobalTransform() : Eigen::Matrix4f::Identity());
	}

	// P2-003：先消费上一份结果，再提交本帧——这样「结果槽有未消费结果」不会挡住本帧，
	// 同时保证显示值恰为同步语义下的 N−1（慢 worker 时滞后帧数增大，但不跳帧）。
	// t35：默认 seam 主路径也会进这里——首次分发时打一条宿主可捕获的判据。
	if (!async_dispatch_reported_)
	{
		async_dispatch_reported_ = true;
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
			"[CMT][physics-async] dispatch=seam_async epoch=@ submitted=@ applied=@",
			Int64(async_physics_epoch_), Int64(async_submitted_frame_), Int64(async_applied_frame_));
	}

	cmt::physics::AsyncFrameResult result;
	if (async_physics_pipeline_.TryConsume(async_physics_epoch_, 0, result))
		ApplyStandaloneAsyncResult(result);

	const std::uint64_t frame = async_submitted_frame_ + 1;
	if (async_physics_pipeline_.Submit(frame, async_physics_epoch_, std::move(bone_world), async_rigid_identity_))
	{
		async_submitted_frame_ = frame;
		async_submit_fail_streak_ = 0;
	}
	else
	{
		++async_submit_fail_streak_;
		// 诊断：首次被拒时把两道门的计数打出来（每帧刷屏没有意义）。
		if (!async_backpressure_reported_)
		{
			async_backpressure_reported_ = true;
			const cmt::physics::PhysicsAsyncPipeline::Counters counters = async_physics_pipeline_.GetCounters();
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT] async physics back-pressure: submit_skipped=@ submit_blocked_result_pending=@",
				Int64(counters.submit_skipped), Int64(counters.submit_blocked_result_pending));
		}
		// P9-003：连续被拒说明 worker 已经不再交付（卡死/抛过异常）。此时 submitted 不推进，
		// 下面的「滞后 > 4」永远不成立，物理会静默停摆——这里直接回退同步。
		constexpr std::uint64_t kMaxAsyncSubmitFailStreak = 8;
		if (async_submit_fail_streak_ >= kMaxAsyncSubmitFailStreak)
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
				"[CMT][physics-async] fallback_to_sync reason=submit_rejected streak=@ submitted=@ applied=@ epoch=@",
				Int64(async_submit_fail_streak_), Int64(async_submitted_frame_), Int64(async_applied_frame_),
				Int64(async_physics_epoch_));
			ShutdownStandaloneAsyncPhysics();
			StepStandalonePhysicsRaw(elapsed);
			return;
		}
	}
	// 拒绝（job 在途 / 结果未消费）时不推进帧号：显示值保持上一份结果，滞后增大而不跳帧。

	// P8 默认开启后的安全网：worker 卡死或管线持续被拒时，滞后会一路涨上去、物理等于停摆。
	// 超过阈值就关掉本代异步世界、本帧改走同步步进——宁可掉回 16 ms，也不能让物理不动。
	constexpr std::uint64_t kMaxAsyncLagFrames = 4;
	const std::uint64_t async_lag_frames =
		async_submitted_frame_ > async_applied_frame_ ? (async_submitted_frame_ - async_applied_frame_) : 0;
	if (async_lag_frames > kMaxAsyncLagFrames)
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
			"[CMT][physics-async] fallback_to_sync lag=@ submitted=@ applied=@ epoch=@",
			Int64(async_lag_frames), Int64(async_submitted_frame_), Int64(async_applied_frame_),
			Int64(async_physics_epoch_));
		ShutdownStandaloneAsyncPhysics();
		StepStandalonePhysicsRaw(elapsed);
	}
}

Bool MMDModelManagerObject::ApplyStandaloneAsyncRigidWorld(const std::vector<Eigen::Matrix4f>& rigid_world)
{
	// P2-002：刚体显示路径（mmd_rigid.cpp 每帧读 MMDRigidBody::GetTransform()）读的是主世界刚体；
	// 异步档主世界不推进，因此必须把结果槽里的刚体快照按刚体下标映射回主世界，显示才与同步语义一致。
	auto* const rigid_bodies = physics_manager_own_ ? physics_manager_own_->GetRigidBodys() : nullptr;
	if (!rigid_bodies || rigid_world.empty())
		return false;

	// P2-004：数量/身份必须一一对上，否则整帧拒绝（fail-closed），不做部分错写。
	if (rigid_world.size() != main_rigid_identity_.size() || rigid_world.size() != rigid_bodies->size())
	{
		++async_rigid_identity_mismatch_;
		return false;
	}

	// 按稳定身份（PMX 刚体下标）映射到主世界索引；任何身份/数量不符都整帧拒绝。
	std::vector<std::size_t> main_indices;
	if (!cmt::physics::MapRigidSnapshotToMain(async_rigid_identity_, main_rigid_identity_,
		rigid_bodies->size(), main_indices) || main_indices.size() != rigid_world.size())
	{
		++async_rigid_identity_mismatch_;
		return false;
	}

	std::size_t applied = 0;
	for (std::size_t index = 0; index < rigid_world.size(); ++index)
	{
		const std::size_t main_index = main_indices[index];
		auto* const rigid_body = (*rigid_bodies)[main_index].get();
		btRigidBody* const body = rigid_body ? rigid_body->GetRigidBody() : nullptr;
		if (!body)
			continue;
		btTransform transform;
		transform.setFromOpenGLMatrix(rigid_world[index].data());
		body->setCenterOfMassTransform(transform);
		body->setInterpolationWorldTransform(transform);
		++applied;
	}
	return applied > 0;
}

Bool MMDModelManagerObject::ApplyStandaloneAsyncResult(const cmt::physics::AsyncFrameResult& result)
{
	if (!async_physics_active_ || result.epoch != async_physics_epoch_)
		return false;

	maxon::BaseArray<Int32> touched;
	const std::size_t bone_count = result.bone_world.size();
	for (std::size_t index = 0; index < bone_count; ++index)
	{
		if (libmmd::IMMDNode* const node = GetBoneAdapter(static_cast<Int32>(index)))
		{
			node->SetGlobalTransform(result.bone_world[index]);
			touched.Append(static_cast<Int32>(index)) iferr_ignore("touch");
		}
	}
	if (touched.GetCount() > 0)
		ApplyStandaloneBoneAdaptersToScene(touched);

	ApplyStandaloneAsyncRigidWorld(result.rigid_world);
	async_applied_frame_ = result.frame;
	// P9-002：留一份已写回结果的副本，供同帧重算（控制/形态编辑）重放。
	if (&result != &async_last_result_)
		async_last_result_ = result;
	has_async_last_result_ = true;
	return true;
}

Bool MMDModelManagerObject::ReapplyLastAsyncPhysicsResult()
{
	// 同一帧重算：重放最近一次已写回的结果，数值不变、不推进 Bullet 时间。
	if (!has_async_last_result_ || async_last_result_.epoch != async_physics_epoch_)
		return false;
	return ApplyStandaloneAsyncResult(async_last_result_);
}

Bool MMDModelManagerObject::FlushStandaloneAsyncPhysics()
{
	// P4：Flush 不再依赖 replay。镜像重建保证显示帧与提交帧只差「在途结果」，
	// 需要即时可见时走下面的「等待目标帧结果」路径（阻塞到该帧结果到达）。

	if (!async_physics_active_)
		return false;
	if (async_submitted_frame_ == 0 || async_applied_frame_ == async_submitted_frame_)
		return true;

	// 「返回即含当前帧物理结果」：只接受帧号正好等于目标帧的结果；
	// 更大帧号不能冒充当前帧（会被 TryConsume 的 expected_frame 校验拒掉并计数）。
	const std::uint64_t target = async_submitted_frame_;
	// P9-001：Flush 是主线程忙等，调用点（自动化/尺寸适配/烘焙）都不看返回值，
	// 上限从 4000ms 收到 500ms：worker 正常一步只要几毫秒，超时说明它已经不健康。
	for (Int32 attempt = 0; attempt < 500; ++attempt)
	{
		cmt::physics::AsyncFrameResult result;
		if (async_physics_pipeline_.TryConsume(async_physics_epoch_, target, result))
			ApplyStandaloneAsyncResult(result);
		if (async_applied_frame_ == target)
			return true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
		"[CMT][physics-async] flush_timeout target=@ applied=@", Int64(target), Int64(async_applied_frame_));
	return async_applied_frame_ == target;
}

void MMDModelManagerObject::FlushAsyncPhysicsForDocument(BaseDocument& doc)
{
	BaseObject* const root = doc.GetFirstObject();
	if (!root)
		return;
	std::vector<BaseObject*> stack{ root };
	while (!stack.empty())
	{
		BaseObject* const object = stack.back();
		stack.pop_back();
		if (object->IsInstanceOf(g_mmd_model_manager_object_id))
		{
			if (auto* const manager = object->GetNodeData<MMDModelManagerObject>())
			{
				if (manager->AsyncPhysicsEnabled())
					manager->FlushStandaloneAsyncPhysics();
			}
		}
		for (BaseObject* child = object->GetDown(); child; child = child->GetNext())
			stack.push_back(child);
	}
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
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::Rebuild);

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
	// P2：开关打开时再建影子世界与常驻 worker；建不起来就保持同步路径。
	if (AsyncPhysicsSwitchEnabled())
	{
		const std::uint64_t resume_frame = async_frames_since_reset_;
		if (!StartStandaloneAsyncPhysics())
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] StartStandaloneAsyncPhysics failed; staying on the sync path");
		}
		// P4：中途开启不做 replay——影子世界已在当前时点按同一构造序列建成，
		// 从下一帧起即为同步世界的镜像；更早的历史已被 epoch 边界作废。
		(void)resume_frame;
	}

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
	// P6-001：影子世界在这条路径上先于主世界重置建立（Start 发生在上面的
	// AsyncPhysicsSwitchEnabled 分支），主世界 Reset 会改变刚体起点；
	// 因此必须在 ResetStandalonePhysics() 之后再种子化一次。顺序由 verify 门禁断言。
	if (AsyncPhysicsEnabled() && !SeedStandaloneAsyncWorldFromMain())
	{
		++async_seed_rejected_;
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] async physics refused: seed after reset failed (rejected=@)", async_seed_rejected_);
		ShutdownStandaloneAsyncPhysics();
		async_physics_active_ = false;
	}
	*is_runtime_initialized_.Write() = true;
	return true;
}


// t56 缺陷 B：影子世界必须与主线程同一口径。主线程口径见上面的 ApplyPhysicsConfigToRuntime：
// document_fps * GetPhysicsSubsteps(op)（30fps × 3 子步 = 90Hz）与 IsPhysicsEnabled ? GetPhysicsGravity : 0。
// 这里刻意复用完全相同的取值表达式（不写死常量），差异只在目标管理器。
void MMDModelManagerObject::ApplyPhysicsConfigToAsyncWorld(libmmd::MMDPhysicsManager* const async_manager,
	const BaseObject* op)
{
	if (!async_manager)
		return;

	auto* const shadow_physics = async_manager->GetMMDPhysics();
	if (!shadow_physics)
		return;

	const BaseDocument* const document = op ? const_cast<BaseObject*>(op)->GetDocument() : nullptr;
	const Float32 shadow_fps = document ? static_cast<Float32>(document->GetFps()) : fps_;
	shadow_physics->SetFPS(shadow_fps * static_cast<Float32>(GetPhysicsSubsteps(op)));

	if (auto* const shadow_world = shadow_physics->GetDynamicsWorld())
	{
		const Vector shadow_gravity = IsPhysicsEnabled(op) ? GetPhysicsGravity(op) : Vector(0);
		shadow_world->setGravity(btVector3(
			static_cast<btScalar>(shadow_gravity.x),
			static_cast<btScalar>(shadow_gravity.y),
			static_cast<btScalar>(shadow_gravity.z)));
	}
}

void MMDModelManagerObject::ResetStandalonePhysics()
{
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::Physics);
	if (!physics_manager_own_)
		return;

	// seek / 冷重建会重建 Bullet 世界：结果槽必须整槽作废，
	// 否则消费端可能把上一个世界的结果回写到骨骼。
	// off 档完全不参与缝，连 epoch 都不推进（保证与旧路径零差异）。
	if (physics_pipeline_.SeamEnabled())
		physics_pipeline_.InvalidateEpoch();

	// P2：seek / 冷重建前先停 worker 并推进 epoch，旧世界的在途结果必须作废。
	const Bool async_was_active = async_physics_active_;
	async_prev_primed_ = false;
	if (async_was_active)
		ShutdownStandaloneAsyncPhysics();

	// P3-001：世界边界统一清零 replay 计数器（成功/失败两条路径都从这里过）。
	// 失败路径不重启 worker：ShutdownStandaloneAsyncPhysics 已把 async_physics_active_ 置 false，
	// 因此不会出现「旧世界累计值 + 新世界步数」这种跨世界边界的 replay 目标。
	async_frames_since_reset_ = 0;

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

	// 冷世界重建完成：按原开关恢复 worker（epoch 已在 Shutdown 里推进）。
	if (async_was_active)
		StartStandaloneAsyncPhysics();

	// P6-001：主世界已 Reset 到当前帧真实姿态；Start 内部已按主世界状态种子化。
	// 这里再显式同步一次，覆盖「影子世界先于主世界重置建立」的路径。
	if (async_physics_active_ && !SeedStandaloneAsyncWorldFromMain())
	{
		++async_seed_rejected_;
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] async physics refused: seed after seek failed (rejected=@)", async_seed_rejected_);
		ShutdownStandaloneAsyncPhysics();
		async_physics_active_ = false;
	}
}

void MMDModelManagerObject::RunStandalonePhysicsStep(const Float elapsed)
{
	++async_frames_since_reset_;

	// 单个物理步：输入同步 → Bullet 推进（含 substeps）。不含结果槽、不含回写。
	bone_manager_data_ = GetBoneManagerData();
	auto* const physics = physics_manager_own_->GetMMDPhysics();
	auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
	if (!physics || !rigid_bodies)
		return;

	{
		CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::PhysicsSync);
		for (const auto& rigid_body : *rigid_bodies)
			rigid_body->SyncBonePositionToPhysics(elapsed);
	}
	{
		CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::PhysicsStep);
		physics->Update(elapsed);
	}
}

std::uint64_t MMDModelManagerObject::ProduceStandalonePhysicsFrame(const Float elapsed)
{
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::Physics);
	if (!physics_manager_own_)
		return 0;

	const std::uint64_t frame = physics_pipeline_.BeginFrame();
	const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	RunStandalonePhysicsStep(elapsed);
	// 生产结束：Bullet 刚体已持有本帧结果。P1 只在结果槽里记录「可用」与耗时；
	// P2 会在这里把刚体姿态快照进槽，让消费不再依赖 Bullet 的当前状态。
	const std::chrono::duration<double, std::milli> cost = std::chrono::steady_clock::now() - begin;
	physics_pipeline_.MarkProduced(frame, cost.count());
	return frame;
}

void MMDModelManagerObject::ConsumeStandalonePhysicsFrame(const std::uint64_t frame)
{
	// 帧号 + epoch 双重校验：seek/开关切换之后旧结果一律不回写。
	if (!physics_pipeline_.Consume(frame))
		return;

	ApplyStandalonePhysicsResults();
}

void MMDModelManagerObject::ReapplyStandalonePhysicsFrame(const std::uint64_t frame)
{
	// 同一帧重算：同一个结果回写多次数值不变，但必须走 Reapply，
	// 避免把真实回写重复执行一次（旧路径在这里只重算，不重新推进 Bullet）。
	if (!physics_pipeline_.Reapply(frame))
		return;

	ApplyStandalonePhysicsResults();
}

Bool MMDModelManagerObject::FlushStandalonePhysicsPipeline(const std::uint64_t frame)
{
	// P5（D1 回归修复）：async 档必须转 FlushStandaloneAsyncPhysics()。
	// P4 把这个分支弄丢了：7 处显式 ExecutePasses 的 flush 会落到下面的同步状态机，
	// 返回 false 且拿不到当前帧结果（T37-001 契约回归）。恢复它，且必须在任何
	// physics_pipeline_ 使用之前。
	if (AsyncPhysicsEnabled())
		return FlushStandaloneAsyncPhysics();
	// 契约（P1-005）：返回 true 当且仅当「本次调用之后，场景里已经是 frame 这一帧的物理结果」。
	// 三步：①若本帧停在「已 BeginFrame、未生产」，同步跑完生产（含 substeps）；
	//       ②用 frame + epoch 校验后消费；③真正回写骨骼/网格（ApplyStandalonePhysicsResults）。
	// 幂等：同步模式下结果已消费过时只做校验，不重复回写。
	if (!physics_pipeline_.SeamEnabled())
		return false;

	if (!physics_pipeline_.Ready()
		&& physics_pipeline_.PendingFrame() != 0
		&& physics_pipeline_.PendingFrame() == frame)
	{
		const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		RunStandalonePhysicsStep(1.f / fps_);
		const std::chrono::duration<double, std::milli> cost = std::chrono::steady_clock::now() - begin;
		physics_pipeline_.MarkProduced(frame, cost.count());
	}

	const Bool was_consumed = physics_pipeline_.Consumed();
	if (!physics_pipeline_.Flush(frame))
		return false;

	if (!was_consumed)
		ApplyStandalonePhysicsResults();

	return true;
}

void MMDModelManagerObject::StepStandalonePhysics(const Float elapsed)
{
	// P2：分发判定集中一处。默认 seam 档打开开关时也走异步；关缝时一律同步直算。
	const cmt::physics::PhysicsDispatch dispatch =
		cmt::physics::SelectPhysicsDispatch(physics_pipeline_.SeamEnabled(), AsyncPhysicsEnabled());
	if (dispatch == cmt::physics::PhysicsDispatch::seam_async)
	{
		StepStandaloneAsyncPhysics(elapsed);
		return;
	}

	// 兼容旧调用点：off 档保持旧路径（缝不参与、不计时），
	// 其余档等价于「生产 + 立即消费」。
	if (!physics_pipeline_.SeamEnabled())
	{
		StepStandalonePhysicsRaw(elapsed);
		return;
	}

	const std::uint64_t frame = ProduceStandalonePhysicsFrame(elapsed);
	ConsumeStandalonePhysicsFrame(frame);
}

void MMDModelManagerObject::StepStandalonePhysicsRaw(const Float elapsed)
{
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::Physics);
	if (!physics_manager_own_)
		return;

	RunStandalonePhysicsStep(elapsed);
	ApplyStandalonePhysicsResults();
}

void MMDModelManagerObject::ApplyStandalonePhysicsResults()
{
	CMT_PROFILE_SCOPE(cmt_runtime::RuntimeStage::PhysicsWriteback);
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
	MarkMeshHierarchyDirty(GetMeshManagerObject(), false);
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

Int32 MMDModelManagerObject::GetPhysicsSubsteps(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	const Int32 substeps = bc ? bc->GetInt32(MODEL_PHYSICS_SUBSTEPS, kDefaultPhysicsSubsteps) : kDefaultPhysicsSubsteps;
	return std::clamp(substeps, Int32(1), kMaxPhysicsSubsteps);
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

	// 生产/消费缝的模式在每次应用物理配置时刷新（默认 seam_sync）。
	physics_pipeline_.ConfigureFromEnvironment();

	// One document frame still advances 1 / fps seconds. Substeps only refine
	// that interval; reapply the rate after both creation and cold world rebuilds.
	// R20 的 GeListNode::GetDocument() 是非 const 成员函数，这里只读取文档指针，
	// 因此需要去掉 const 才能在各版本 SDK 上同时编译通过。
	const BaseDocument* const doc = op ? const_cast<BaseObject*>(op)->GetDocument() : nullptr;
	const Float32 document_fps = doc ? static_cast<Float32>(doc->GetFps()) : fps_;
	physics->SetFPS(document_fps * static_cast<Float32>(GetPhysicsSubsteps(op)));

	if (auto* const world = physics->GetDynamicsWorld())
	{
		const Vector gravity = IsPhysicsEnabled(op) ? GetPhysicsGravity(op) : Vector(0);
		world->setGravity(btVector3(
			static_cast<btScalar>(gravity.x),
			static_cast<btScalar>(gravity.y),
			static_cast<btScalar>(gravity.z)));
	}
}
