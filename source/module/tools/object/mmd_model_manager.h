/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.cpp
Description:	MMD model object

**************************************************************************/

#pragma once

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>
#include "libMMD/Model/MMD/MMDIkSolver.h"
#include "libMMD/Model/MMD/MMDModel.h"
#include "libMMD/Model/MMD/PMXFile.h"

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "CMTSceneManager.h"
#include "description/OMMDModelManager.h"
#include "module/tools/material/mmd_material.h"
#include "maxon/pointerarray.h"
#include "utils/images_user_area_util.hpp"
#include "utils/mmd_model_info_animation.h"
#include "utils/cmt_runtime_identity.hpp"
#include "module/tools/object/cmt_physics_pipeline.h"
//! P2：影子骨骼 + 常驻 worker + 结果槽（默认关闭，见 CMT_PHYSICS_ASYNC）。
#include "module/tools/object/cmt_physics_async.h"
//! P4-001：epoch 单调计数器（世界边界推进，绝不回退到 1）。
#include "module/tools/object/cmt_physics_epoch.h"
#include "module/tools/object/cmt_physics_seed.h"
#include "module/tools/object/cmt_rigid_identity.h"
#include "module/tools/object/cmt_physics_shadow.h"

class IMorph;
class MaterialMorph;
struct MMDMaterialMorphOffset;
class MMDBoneManagerObject;
class MMDMeshManagerObject;
class MMDRigidManagerObject;
class MMDJointManagerObject;
class MMDModelManagerObject;
class C4DIKChainNodeAdapter;
namespace mmd_control_workflow { class EvaluationContext; }
enum class MMDMorphType : uint8_t;

class StandaloneIKManager
{
public:
	using SolverPtr = std::unique_ptr<libmmd::MMDIkSolver>;

	size_t GetIKSolverCount() const { return ik_solvers_.size(); }

	size_t FindIKSolverIndex(const std::string& name) const
	{
		const auto it = std::find_if(ik_solvers_.begin(), ik_solvers_.end(), [&name](const SolverPtr& solver)
		{
			return solver && solver->GetName() == name;
		});
		return it == ik_solvers_.end() ? static_cast<size_t>(-1) : static_cast<size_t>(it - ik_solvers_.begin());
	}

	libmmd::MMDIkSolver* GetMMDIKSolver(const size_t index) const
	{
		return index < ik_solvers_.size() ? ik_solvers_[index].get() : nullptr;
	}

	libmmd::MMDIkSolver* AddIKSolver()
	{
		ik_solvers_.push_back(std::make_unique<libmmd::MMDIkSolver>());
		return ik_solvers_.back().get();
	}

private:
	std::vector<SolverPtr> ik_solvers_;
};

class EditorSubMorphDialog final : public GeDialog
{
	using ImagesUserAreaRef = maxon::UniqueRef<ImagesUserArea>;

	Int32 m_id = 20000;
	IMorph* m_morph = nullptr;
	SimpleListView m_listview;
	maxon::HashSet<Int32> m_delete_button_id;
	ImagesUserAreaRef m_images;
	MMDModelManagerObject* m_model = nullptr;

	Bool CreateLayout() override;
	Bool InitValues()override;
	Bool Command(Int32 id, const BaseContainer& msg) override;
public:
	EditorSubMorphDialog(MMDModelManagerObject* model, IMorph* morph) : m_morph(morph), m_model(model) {}
	~EditorSubMorphDialog() override = default;
	EditorSubMorphDialog(const EditorSubMorphDialog&) = delete; void operator =(const EditorSubMorphDialog&) = delete;
	EditorSubMorphDialog(EditorSubMorphDialog&&) = delete; void operator =(EditorSubMorphDialog&&) = delete;
};

enum class MMDModelManagerObjectMsgType : uint8_t
{
	DEFAULT,
	MANAGER_OBJECT_UPDATE,
	MODEL_MODE_CHANGE,
	ACTIVE_ANIMATION_SLOT_CHANGE
};

struct MMDModelManagerObjectMsg
{
	MMDModelManagerObjectMsgType msg_type;
	BaseObject* object;
	Int32	model_mode;
	Int32 active_animation_slot;

	explicit MMDModelManagerObjectMsg(const MMDModelManagerObjectMsgType msg_type_ = MMDModelManagerObjectMsgType::DEFAULT, BaseObject* object_ = nullptr, const Int32 model_mode_ = MODEL_MODE_ANIM, const Int32 active_animation_slot_ = -1)
		:msg_type(msg_type_), object(object_), model_mode(model_mode_), active_animation_slot(active_animation_slot_) {}
};

enum class DisplayFrameTargetType : uint8_t
{
	Bone,
	Morph
};

struct DisplayFrameTargetData
{
	DisplayFrameTargetType type = DisplayFrameTargetType::Bone;
	Int32 index = 0;
};

struct DisplayFrameData
{
	String name;
	String name_universal;
	Bool is_special = false;
	maxon::BaseArray<DisplayFrameTargetData> targets;

	void FromPMX(const libmmd::PMXDisplayFrame& pmx_frame);
	void ToPMX(libmmd::PMXDisplayFrame& pmx_frame) const;
	Bool Read(HyperFile* hf);
	Bool Write(HyperFile* hf) const;
	Bool CopyTo(DisplayFrameData& dest) const;
};

struct AnimationSlotMetadata
{
	String name;
	Int32 max_frame = 0;
	UInt64 runtime_identity = cmt_runtime_identity::Next();

	Bool Read(HyperFile* hf);
	Bool Write(HyperFile* hf) const;
	Bool CopyTo(AnimationSlotMetadata& dest) const;
};

struct MorphAnimationKeyframeData
{
	String morph_name;
	Int32 frame = 0;
	Float32 weight = 0.F;

	Bool Read(HyperFile* hf);
	Bool Write(HyperFile* hf) SDK2024_Const;
};

struct MorphAnimationSlotData
{
	maxon::BaseArray<MorphAnimationKeyframeData> keyframes;

	MorphAnimationSlotData() = default;
	MorphAnimationSlotData(const MorphAnimationSlotData& other);
	MorphAnimationSlotData& operator=(const MorphAnimationSlotData& other);
	MorphAnimationSlotData(MorphAnimationSlotData&&) noexcept = default;
	MorphAnimationSlotData& operator=(MorphAnimationSlotData&&) noexcept = default;

	Bool Read(HyperFile* hf);
	Bool Write(HyperFile* hf) SDK2024_Const;
};

enum class MMDModelRootDynamicDescriptionType : uint8_t
{
	MORPH_GRP,
	MORPH_STRENGTH,
	MORPH_EDITOR_BUTTON,
	MORPH_DELETE_BUTTON,
	MORPH_RENAME_BUTTON,
	IK_BONE_LINK,
	DISPLAY_FRAME_DELETE_BUTTON,
	DISPLAY_FRAME_MOVE_UP_BUTTON,
	DISPLAY_FRAME_MOVE_DOWN_BUTTON,
	IK_SOLVER_ENABLE
};

class MMDModelManagerObject final : public ObjectData
{
	maxon::Synchronized<Bool> update_morph_;
	maxon::Synchronized<Bool> is_morph_initialized_;
	maxon::Synchronized<Bool> is_manager_read_;
	Int32 morph_named_number_ = 0;
	AutoAlloc<BaseLink> mesh_manager_;
	AutoAlloc<BaseLink> bone_manager_;
	AutoAlloc<BaseLink> rigid_manager_;
	AutoAlloc<BaseLink> joint_manager_;
	MMDBoneManagerObject* bone_manager_data_ = nullptr;
	MMDMeshManagerObject* mesh_manager_data_ = nullptr;
	MMDRigidManagerObject* rigid_manager_data_ = nullptr;
	MMDJointManagerObject* joint_manager_data_ = nullptr;
	maxon::PointerArray<IMorph> morph_data_;
	maxon::HashMap<DescID, maxon::Pair<MMDModelRootDynamicDescriptionType, Int>> desc_id_map_;
	maxon::HashMap<String, Int> morph_name_;

	Int32 animation_index_ = -1;
	BaseContainer animation_items_;
	maxon::BaseArray<AnimationSlotMetadata> animation_slot_metadata_;
	maxon::BaseArray<MorphAnimationSlotData> morph_animation_slots_;
	std::vector<mmd_model_info::AnimationSlot> model_info_animation_slots_;
	Bool migrate_legacy_model_info_tracks_ = false;
	Bool migrate_legacy_morph_tracks_ = false;
	Bool applying_model_info_parameters_ = false;
	Bool has_visibility_baseline_ = false;
	Bool visibility_override_active_ = false;
	Int32 visibility_editor_baseline_ = MODE_UNDEF;
	Int32 visibility_render_baseline_ = MODE_UNDEF;

	maxon::BaseArray<MMDMaterialData> material_list_;
	Int32 material_selection_index_ = -1;
	mutable BaseContainer material_list_items_;

	// 材质表情运行时同步的 dirty 校验和（与 material_list_ 一一对应）；
	// 仅在有效材质状态变化时才同步到 C4D 材质。
	maxon::BaseArray<maxon::UInt64> material_runtime_checksum_;
	// 曾经接管过材质运行时状态；最后一个 offset/morph 被删除时据此执行一次基础状态恢复。
	Bool material_morph_runtime_active_ = false;
	// Transient authoring state. Ordinary disk reads clear it; document clones
	// carry it to render the current preview without touching animation tracks.
	Bool material_preview_enabled_ = false;
	std::unordered_map<UInt64, Float> material_preview_weights_;
	Int32 material_preview_selection_ = -1;
	String material_binding_diagnostic_;

	// 材质表情属性页（UI-only，不持久化）：选中的材质表情（morph_data_ 下标）与 offset 下标。
	// mutable：GetDDescription（const）会在校正选中索引时写入。
	mutable Int32 material_morph_selection_index_ = -1;
	mutable Int32 material_morph_offset_selection_index_ = -1;
	mutable BaseContainer matmorph_list_items_;
	mutable BaseContainer matmorph_offset_items_;
	mutable BaseContainer matmorph_target_items_;

	maxon::BaseArray<DisplayFrameData> display_frame_list_;
	Int32 display_frame_selection_index_ = -1;
	Int32 display_frame_add_type_ = 0;
	mutable Int32 display_frame_add_target_ = 0;
	mutable Bool display_frame_add_target_empty_ = true;
	mutable BaseContainer display_frame_items_;

	maxon::HashMap<String, Bool> ik_solver_enable_states_;
	/// Parallel to IK dynamic checkboxes: reliable DescID -> libMMD solver index (HashMap<DescID> can collapse keys).
	maxon::BaseArray<maxon::Pair<DescID, Int>> ik_solver_dynamic_params_;

	std::unique_ptr<StandaloneIKManager> ik_manager_own_;
	std::unique_ptr<libmmd::MMDPhysicsManager> physics_manager_own_;
	std::vector<std::unique_ptr<C4DIKChainNodeAdapter>> physics_bone_pool_;
	maxon::HashMap<Int32, C4DIKChainNodeAdapter*> physics_bone_adapters_;
	maxon::BaseArray<Int32> physics_dynamic_bone_indices_;
	//! 物理生产/消费缝（P1）：结果槽状态机，见 cmt_physics_pipeline.h。
	cmt_physics_pipeline::CmtPhysicsPipeline physics_pipeline_;
	//! 本模型当前帧的生产帧号（同帧重算时用它校验消费契约）。
	std::uint64_t physics_frame_id_ = 0;
	//! P2：影子世界、影子骨骼、常驻 worker 与结果槽。
	std::unique_ptr<libmmd::MMDPhysicsManager> async_physics_manager_own_;
	cmt::physics::ShadowBoneSet async_shadow_bones_;
	cmt::physics::PhysicsAsyncPipeline async_physics_pipeline_;
	//! P2：seek/重置/关开关时递增，旧 epoch 的在途结果一律作废。
	std::uint64_t async_physics_epoch_ = 0;
//! P4-001：epoch 的唯一来源；0 表示尚未建立过异步世界。
cmt::physics::PhysicsEpochCounter async_epoch_counter_;
	//! P6-001：最近一次影子世界种子化的统计（bodies/copied/skipped/ok）。
	cmt::physics::RigidSeedStats async_seed_stats_;
	//! P7-001：影子 motion state 已用当帧骨骼姿态预热过上一帧原点。
	Bool async_prev_primed_ = false;
	//! P2：已提交给 worker 的最后一帧与最近一次写回的帧。
	std::uint64_t async_submitted_frame_ = 0;
	std::uint64_t async_frames_since_reset_ = 0;
	Bool async_replaying_ = false;
	std::uint64_t async_applied_frame_ = 0;
	Bool async_physics_active_ = false;
	//! P9-002：最近一次成功写回的异步结果。同一帧重算（控制/形态/外部姿态编辑）直接重放它，
	//! 既不第二次推进 Bullet，也不因为异步档没有 frame id 而丢掉物理姿态回写。
	cmt::physics::AsyncFrameResult async_last_result_;
	Bool has_async_last_result_ = false;
	//! P9-003：连续被拒的提交次数。worker 卡死时 submitted 不推进 ⇒ 滞后看不出来，
	//! 必须单独计数，否则物理会静默停摆（只留一条背压日志）。
	std::uint64_t async_submit_fail_streak_ = 0;
	//! 诊断只打一次（按模型，不是按进程）。
	Bool async_dispatch_reported_ = false;
	Bool async_backpressure_reported_ = false;
	//! P2-004：影子/主世界的刚体稳定身份（PMX 刚体下标）与错位计数。
	std::vector<Int32> async_rigid_identity_;
	std::vector<Int32> main_rigid_identity_;
	std::uint64_t async_rigid_identity_mismatch_ = 0;
	struct ExternalBonePose
	{
		Matrix relative;
		Bool position = false;
		Bool rotation = false;
	};
	// Samples belong only to this expression pass, never to saved/copied state.
	std::unordered_map<Int32, ExternalBonePose> external_bone_poses_;
	Bool external_pose_captured_ = false;
	Bool external_pose_refresh_ = false;
	Int32 model_mode_ = MODEL_MODE_EDIT;
	BaseTime prev_time_{-1};
	Float32 fps_{ 30.f };
	static constexpr Int32 kDefaultPhysicsSubsteps = 3;
	// Match libMMD's maximum catch-up steps so one animation frame is never truncated.
	static constexpr Int32 kMaxPhysicsSubsteps = 10;
	Int32 physics_substeps_ = kDefaultPhysicsSubsteps;
	Bool is_animation_initialized_{ false };
	UInt32 control_state_checksum_{ 0 };
	UInt64 bone_morph_state_checksum_ = 0;
	Bool has_bone_morph_state_checksum_ = false;
	Bool bone_morph_pose_dirty_ = false;
	Bool has_transient_vpd_pose_ = false;
	BaseTime transient_vpd_pose_time_{ -1 };
	std::vector<Int32> transient_vpd_bone_indices_;
	std::vector<String> transient_vpd_morph_names_;
	maxon::Synchronized<Bool> is_runtime_initialized_;

	MMDModelManagerObject();
	friend MMDModelManagerObject;
	friend class MMDMeshManagerObject;

public:
	static constexpr Int32 kExternalPosePreparePriority = EXECUTIONPRIORITY_EXPRESSION - 500;
	static constexpr Int32 kExternalPoseSolvePriority = EXECUTIONPRIORITY_EXPRESSION + 500;
	Bool HasExternalBonePoses() const { return !external_bone_poses_.empty(); }
	Bool GetExternalBonePose(Int32 bone_index, Matrix& relative, Bool& position, Bool& rotation) const;
	Bool HasExternalBoneRotation(Int32 bone_index) const;
	MMDModelManagerObject(const MMDModelManagerObject&) = delete; void operator =(const MMDModelManagerObject&) = delete;
	MMDModelManagerObject(MMDModelManagerObject&&) = delete; void operator =(MMDModelManagerObject&&) = delete;
	typedef ObjectData SUPER;

	class AddMorphHelper
	{
		MMDModelManagerObject* m_model = nullptr;
		public:
		AddMorphHelper(const AddMorphHelper&) = delete; void operator =(const AddMorphHelper&) = delete;
		AddMorphHelper(AddMorphHelper&&) = delete; void operator =(AddMorphHelper&&) = delete;
		explicit AddMorphHelper(MMDModelManagerObject* model);
		~AddMorphHelper();
	};

	~MMDModelManagerObject() override = default;
	static NodeData* Alloc();
	//! P2：文档求值后落定异步物理结果（未启用时为 no-op）。
	static void FlushAsyncPhysicsForDocument(BaseDocument& doc);
	SDK2024_InitOverride;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	SDK2024_CopyToOverride;
	SDK2024_GetDDescriptionOverride;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	SDK2024_GetDParameterOverride;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	SDK2024_GetDEnablingOverride;

	AddMorphHelper BeginMorphChange();
	Int ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph, Int32 panel = 0);

	DescID AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index);
	void DeleteDynamicDescription(const DescID& id);

	Int GetMorphNum() const;
	const maxon::PointerArray<IMorph>& GetMorphData();
	const maxon::HashMap<String, Int>& GetMorphNameMap();
	std::vector<Float> EvaluateMorphWeights(const BaseTime& time, Bool preview, Bool sample_tracks, Bool* cyclic = nullptr);
	std::vector<MMDMaterialRuntimeState> EvaluateMaterialMorphs(const std::vector<Float>& strengths) const;
	Bool GetMaterialRenderState(BaseMaterial* material, const BaseTime& time, MMDMaterialRuntimeState& state);
	Bool HasUniqueMaterialBinding(BaseMaterial* material) const;
	Bool PrepareMaterialMorphBindings(Bool record_undo);
	Bool IsMaterialPreviewMorph(Int32 index) const;
	Float GetMaterialPreviewWeight() const;
	void RefreshMaterialMorphPreview();
	Bool RepairSelectedMaterialBinding();
	Bool UpdateSelectedMaterialTexture(const String& path);
	Bool CreateIndependentMaterialBinding();
	Bool ConvertSelectedMaterialToon();
	Bool UpdateSelectedMaterialToon(Int32 mode, Int32 index, const String& path);
	Bool UpdateSelectedMaterialSphere(Int32 mode, const String& path);
	const maxon::BaseArray<AnimationSlotMetadata>& GetAutomationAnimationSlots() const { return animation_slot_metadata_; }
	Int32 GetAutomationActiveAnimationSlot() const { return animation_index_; }
	Bool SelectAutomationAnimationSlot(UInt64 identity);
	Bool SetAutomationMorphStrength(UInt64 identity, Float strength);
#if defined(CMT_ENABLE_RUNTIME_REGRESSION)
	Bool DeleteMorphForRegression(Int index);
	Bool SetMorphStrengthForRegression(Int index, Float strength);
#endif

	Bool CreateManagers();
	Bool UpdateManagers(BaseObject* op = nullptr);
	BaseObject* GetMeshManagerObject() const { return mesh_manager_ ? static_cast<BaseObject*>(mesh_manager_->ForceGetLink()) : nullptr; }
	BaseObject* GetBoneManagerObject() const { return bone_manager_ ? static_cast<BaseObject*>(bone_manager_->ForceGetLink()) : nullptr; }

	MMDBoneManagerObject* GetBoneManagerData();
	MMDMeshManagerObject* GetMeshManagerData();
	MMDRigidManagerObject* GetRigidManagerData();
	MMDJointManagerObject* GetJointManagerData();
	libmmd::MMDIkSolver* GetStandaloneIKSolver(Int32 bone_index) const;
	C4DIKChainNodeAdapter* GetBoneAdapter(Int32 bone_index) const;
	void SyncStandaloneBoneAdaptersFromScene(Bool reset_ik_rotation = true);
	void SyncStandaloneBoneAdaptersLocalFromGlobal(const maxon::BaseArray<Int32>& bone_indices) const;
	void ApplyStandaloneBoneAdaptersToScene() const;
	void ApplyStandaloneBoneAdaptersToScene(const maxon::BaseArray<Int32>& bone_indices) const;
	void InvalidateStandaloneRuntime();
	Bool EnsureStandaloneRuntimeManagers();

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelImport& setting);
	void ImportDisplayFrames(const libmmd::PMXFile& pmx_file);
	void RemapDisplayFrameBoneIndices(const std::unordered_map<Int32, Int32>& previous_to_current);
	void RefreshDisplayFrameUI();
	Bool PreparePMXExportState(BaseDocument* doc);
	void FinishPMXExportState(BaseDocument* doc, Bool restore_edit_mode);
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting);

	Bool AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material,
	                 BaseObject* mesh_object, const String& selection_name,
	                 const maxon::BaseArray<Filename>& texture_paths);

	/**
	 * @brief 材质被删除后，修正所有材质表情 offset 的目标索引。
	 *
	 * 目标索引等于被删除索引的 offset 会被移除；大于被删除索引的统一减一；-1（全部材质）保持不变。
	 * @param removed_index 被删除材质在 material_list_ 中的原索引。
	 */
	void AdjustMaterialMorphIndicesAfterMaterialRemoval(Int32 removed_index);

	/**
	 * @brief 材质列表重排时同步交换所有材质表情 offset 的目标索引。
	 *
	 * -1（全部材质）保持不变。
	 */
	void AdjustMaterialMorphIndicesAfterMaterialSwap(Int32 first_index, Int32 second_index);

	/** 返回当前属性页选中的材质表情（无效时返回 nullptr）。 */
	MaterialMorph* GetSelectedMaterialMorph();
	const MaterialMorph* GetSelectedMaterialMorph() const;
	/** 返回当前属性页选中材质表情的选中 offset（无效时返回 nullptr）。 */
	MMDMaterialMorphOffset* GetSelectedMaterialMorphOffset();
	const MMDMaterialMorphOffset* GetSelectedMaterialMorphOffset() const;

	/**
	 * @brief 校验所有材质表情 offset 的目标索引，移除越界项以避免运行时/导出悬空索引。
	 * @return 是否检测到并移除了非法索引。
	 */
	Bool ValidateMaterialMorphIndices(Bool drop_invalid = false);

	Bool LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log, const Bool merge = false);
	Bool LoadVPDPose(const libmmd::VPDFile& vpd_file, const CMTToolsSetting::PoseImport& setting, LoadVpdPoseLog& log);
	Bool SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const;
	Bool SaveVPDPose(libmmd::VPDFile& vpd_pose, const CMTToolsSetting::PoseExport& setting) const;

private:
	void ResetStandaloneRuntimeCaches();
	void PrepareExternalBonePoses(BaseDocument* doc);
	void CaptureExternalBonePoses();
	Int32 GetMorphNamedNumber();
	bool DeleteMorphImpl(IMorph& morph, const Int morph_index);
	Int AddMorph(const MMDMorphType& morph_type, String morph_name = {}, bool is_add_morph_ui = true, Int32 panel = 0);
	void RenameMorph(const String& name);
	void ApplyMorphRuntimeStrengths();
	UInt64 GetBoneMorphStateChecksum() const;
	void PrepareSameFrameReevaluation(BaseDocument* doc);
	void ApplyMorphRuntimeStrength(IMorph& morph, Float strength);

	/**
	 * @brief 从基础 `material_list_` 重新合成所有材质表情的有效运行时状态并同步到 C4D 材质。
	 *
	 * 复用 group/flip 展开后的有效强度（@p strengths，下标对齐 morph_data_）。
	 * 按 PMX Mul/Add 规则非累积地合成，仅在有效状态变化时通过材质 adapter 同步。
	 */
	void EvaluateMaterialMorphRuntime(const std::vector<Float>& strengths);
	void DeleteMorph(Int morph_index);
	void DeleteMorph(maxon::EraseIterator<maxon::PointerArray<IMorph>, false>& it);
	void RefreshMorph();
	void SyncMorphSlidersFromTags();
	void CaptureAndClearPMXExportMorphState(BaseDocument* doc);
	void RestorePMXExportMorphState(BaseDocument* doc);
	void ClearMorphRuntimeForEdit();
	void ClearTransientVPDPoseState(BaseDocument* doc);
	Bool IsTransientVPDBone(Int32 bone_index) const;
	Float EvaluateMorphAnimationStrength(const String& morph_name, BaseObject* object, const BaseTime& time);
	Bool ReadMorph(HyperFile* hf, Int32 level = 0);
#if API_VERSION < 2024000
	Bool WriteMorph(HyperFile* hf);
#else
	Bool WriteMorph(HyperFile* hf) const;
#endif
	Bool CopyMorph(MMDModelManagerObject* dst) const;
	Bool AddMorphStrengthKeyframe(const String& morph_name, const BaseTime& key_time, Float weight);
	Bool CaptureMorphAnimationSlotFromTracks(Int32 slot_index);
	Bool RebuildMorphTracksFromAnimationSlot(Int32 slot_index);
	Bool EnsureMorphAnimationSlotCount(Int32 slot_count);
	void ClearMorphAnimationSlots();
	Bool DeleteVMDAnimation();
	Bool EnsureCurrentAnimationSlot(BaseDocument* doc, Int32 frame);
	Bool RegisterCurrentStateKeyframe(BaseDocument* doc);
	Bool DeleteCurrentFrameKeyframes(BaseDocument* doc);
	Bool BuildStandaloneIKManager();
	Bool BuildStandalonePhysics();
	Bool BuildStandaloneBoneAdapters();
	Bool SolveStandaloneIKBeforePhysics(Bool include_after_physics_bones = false);
	Int32 SolveStandaloneIKForLayer(Int32 layer, Bool after_physics, Bool sync_from_scene = true);
	Bool RunLayeredBonePass(BaseDocument* doc, Bool after_physics, mmd_control_workflow::EvaluationContext* controls);
	void ResetStandalonePhysics();
	void StepStandalonePhysics(Float elapsed);
	void ApplyStandalonePhysicsResults();
	//! 单个物理步（Sync + Update，含 substeps）：不含结果槽与回写。
	void RunStandalonePhysicsStep(Float elapsed);
	//! 旧路径原语：Sync + Update + 回写，不触碰生产/消费缝（off 档使用）。
	void StepStandalonePhysicsRaw(Float elapsed);
	//! 生产：把当前帧 Bullet 结果写入结果槽（P1 只记录状态，不复制物理量）。
	//! 返回本次生产对应的帧号；返回 0 表示没有可用物理对象。
	std::uint64_t ProduceStandalonePhysicsFrame(Float elapsed);
	//! 首次消费：仅当结果槽帧号与 frame 一致且属于当前 epoch 时回写骨骼。
	void ConsumeStandalonePhysicsFrame(std::uint64_t frame);
	//! 同帧重算：对已消费的同一帧结果再次回写（数值不变，不推进 Bullet）。
	void ReapplyStandalonePhysicsFrame(std::uint64_t frame);
	//! P9-002：async 档的同帧重算——重放最近一次已写回的异步结果。
	Bool ReapplyLastAsyncPhysicsResult();
	//! 供插件内部直接调用 ExecutePasses 的路径使用：保证返回时是当前帧结果。
	Bool FlushStandalonePhysicsPipeline(std::uint64_t frame);
	//! P2：异步开关（默认关闭；CMT_PHYSICS_ASYNC=1 打开）。
	static Bool AsyncPhysicsSwitchEnabled();
	Bool AsyncPhysicsEnabled() const { return async_physics_active_; }
	Bool StartStandaloneAsyncPhysics();
	//! P6-001：从主世界当前真实刚体状态（变换/线速度/角速度/激活态）种子化影子世界。
	Bool SeedStandaloneAsyncWorldFromMain();
	//! P7-001：worker 启动前钉住每个 motion state 的 prev bone origin，不注入速度。
	Bool PrimeStandaloneAsyncPreviousBoneOrigins();
	Int32 async_seed_rejected_ = 0;
	void ShutdownStandaloneAsyncPhysics();
	void StepStandaloneAsyncPhysics(Float elapsed);
	Bool FlushStandaloneAsyncPhysics();
	//! P3：从共同起点 replay 到目标帧（中途开启 / seek / 导出用）。
	// P4：seek / 导出 / 中途开启统一走镜像重建（不再用重复步进冒充历史）。
	Bool RebuildStandaloneAsyncShadow();
	//! P2-001/P2-002：结果写回（骨骼 + 刚体显示）与刚体快照映射。
	Bool ApplyStandaloneAsyncResult(const cmt::physics::AsyncFrameResult& result);
	Bool ApplyStandaloneAsyncRigidWorld(const std::vector<Eigen::Matrix4f>& rigid_world);
	void ApplyPhysicsResultsToBoneObjects() const;
	void CommitEditModeBindState(BaseDocument* doc);
	void RestoreBindStateForEdit(BaseDocument* doc);
	Bool IsPhysicsEnabled(const BaseObject* op) const;
	Int32 GetPhysicsSubsteps(const BaseObject* op) const;
	Bool ShouldResetPhysicsOnSeek(const BaseObject* op) const;
	Vector GetPhysicsGravity(const BaseObject* op) const;
	void ApplyPhysicsConfigToRuntime(const BaseObject* op);
	//! t56：影子世界与主线程同一口径（同一取值表达式，目标管理器不同）。
	void ApplyPhysicsConfigToAsyncWorld(libmmd::MMDPhysicsManager* async_manager, const BaseObject* op);
	void BuildIKSolverUI();
	void ApplyIKSolverStates();
	void ApplyIKSolverFromParameters(BaseObject* op);
	Bool ImportVMDModelInfo(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, Int32 slot_index);
	Bool CaptureModelInfoAnimationSlotFromTracks(Int32 slot_index);
	Bool RebuildModelInfoTracksFromAnimationSlot(Int32 slot_index);
	void ApplyModelInfoVisibility(BaseObject* object, BaseDocument* doc);
	void AppendModelInfoToVmd(const CMTToolsSetting::MotionExport& setting, libmmd::VMDFile& motion, Bool baked) const;
	Bool BakeVMDMotion(libmmd::VMDFile& motion, const CMTToolsSetting::MotionExport& setting, Bool controls_only = false) const;
	Bool EnsureAnimationSlotCount(Int32 slot_count);
	Bool SetAnimationSlotMetadata(Int32 slot_index, const String& name, Int32 max_frame);
	void RefreshAnimationSlotItems();
	Int32 GetAnimationSlotMaxFrame(Int32 slot_index) const;
	void ApplyAnimationSlotSelection(BaseDocument* doc);
	void StripIKSolverDynamicUI();
	void SyncIKSolverDynamicParamsFromDescMap();
	void SyncSubManagerScale(Float pm);
	void SyncMaterialsList();
	void PruneDeletedMaterialEntries(BaseDocument* doc);

	std::vector<Float> pmx_export_morph_strength_snapshot_;
	Bool pmx_export_has_morph_state_snapshot_ = false;
};
