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

class IMorph;
class MMDBoneManagerObject;
class MMDMeshManagerObject;
class MMDRigidManagerObject;
class MMDJointManagerObject;
class MMDModelManagerObject;
class C4DIKChainNodeAdapter;
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

	maxon::BaseArray<MMDMaterialData> material_list_;
	Int32 material_selection_index_ = -1;
	mutable BaseContainer material_list_items_;

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
	Int32 model_mode_ = MODEL_MODE_ANIM;
	BaseTime prev_time_{-1};
	Float32 fps_{ 30.f };
	Bool is_animation_initialized_{ false };
	UInt32 control_state_checksum_{ 0 };
	Bool has_transient_vpd_pose_ = false;
	BaseTime transient_vpd_pose_time_{ -1 };
	std::vector<Int32> transient_vpd_bone_indices_;
	std::vector<String> transient_vpd_morph_names_;
	maxon::Synchronized<Bool> is_runtime_initialized_;

	MMDModelManagerObject();
	friend MMDModelManagerObject;
	friend class MMDMeshManagerObject;

public:
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
	void RefreshDisplayFrameUI();
	Bool PreparePMXExportState(BaseDocument* doc);
	void FinishPMXExportState(BaseDocument* doc, Bool restore_edit_mode);
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting);

	Bool AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material,
	                 BaseObject* mesh_object, const String& selection_name,
	                 const maxon::BaseArray<Filename>& texture_paths);

	Bool LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log, const Bool merge = false);
	Bool LoadVPDPose(const libmmd::VPDFile& vpd_file, const CMTToolsSetting::PoseImport& setting, LoadVpdPoseLog& log);
	Bool SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const;
	Bool SaveVPDPose(libmmd::VPDFile& vpd_pose, const CMTToolsSetting::PoseExport& setting) const;

private:
	Int32 GetMorphNamedNumber();
	bool DeleteMorphImpl(IMorph& morph, const Int morph_index);
	Int AddMorph(const MMDMorphType& morph_type, String morph_name = {}, bool is_add_morph_ui = true, Int32 panel = 0);
	void RenameMorph(const String& name);
	void ApplyMorphRuntimeStrengths();
	void ApplyMorphRuntimeStrength(IMorph& morph, Float strength);
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
	Bool ReadMorph(HyperFile* hf);
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
	Bool RunLayeredBonePass(BaseDocument* doc, Bool after_physics);
	void ResetStandalonePhysics();
	void StepStandalonePhysics(Float elapsed);
	void ApplyPhysicsResultsToBoneObjects() const;
	void CommitEditModeBindState(BaseDocument* doc);
	void RestoreBindStateForEdit(BaseDocument* doc);
	Bool IsPhysicsEnabled(const BaseObject* op) const;
	Bool ShouldResetPhysicsOnSeek(const BaseObject* op) const;
	Vector GetPhysicsGravity(const BaseObject* op) const;
	void ApplyPhysicsConfigToRuntime(const BaseObject* op);
	void BuildIKSolverUI();
	void ApplyIKSolverStates();
	void ApplyIKSolverFromParameters(BaseObject* op);
	void ImportVMDIKKeyframes(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting);
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
