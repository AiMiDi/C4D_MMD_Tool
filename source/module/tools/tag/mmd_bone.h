/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone.cpp
Description:	DESC

**************************************************************************/

#pragma once

#include <array>
#include <string>
#include <vector>
#include "libMMD/Model/MMD/IMMDNode.h"

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "description/OMMDBoneManager.h"
#include "maxon/basearray.h"
#include "maxon/pointerarray.h"

namespace libmmd { class MMDIkSolver; }

class MMDBoneManagerObject;
class MMDModelManagerObject;
struct MMDBoneManagerObjectMsg;
class MMDBoneTag;

namespace CMTToolsSetting
{
	struct MotionImport;
}


struct BoneMorphTagData
{
	DescID	grp_id;
	DescID	strength_id;
	DescID	translation_id;
	DescID	rotation_id;
	DescID	button_grp_id;
	DescID	button_delete_id;
	DescID	button_rename_id;
	String	name;

	BoneMorphTagData() = default;
	BoneMorphTagData(const BoneMorphTagData&) = delete;
	BoneMorphTagData& operator=(const BoneMorphTagData&) = delete;
	BoneMorphTagData(BoneMorphTagData&& other) noexcept = default;
	BoneMorphTagData& operator=(BoneMorphTagData&& other) noexcept = default;

	Bool Write(HyperFile* hf) SDK2024_Const;
	Bool Read(HyperFile* hf);
};

struct BoneAnimationBezierData
{
	UChar ax = 20;
	UChar ay = 20;
	UChar bx = 107;
	UChar by = 107;

	Bool Write(HyperFile* hf) SDK2024_Const;
	Bool Read(HyperFile* hf);
};

struct BoneAnimationKeyframeData
{
	Int32 frame = 0;
	Vector32 translation = Vector32(0.F, 0.F, 0.F);
	Float32 rotation_x = 0.F;
	Float32 rotation_y = 0.F;
	Float32 rotation_z = 0.F;
	Float32 rotation_w = 1.F;
	BoneAnimationBezierData translate_x;
	BoneAnimationBezierData translate_y;
	BoneAnimationBezierData translate_z;
	BoneAnimationBezierData rotation;

	Bool Write(HyperFile* hf) SDK2024_Const;
	Bool Read(HyperFile* hf);
};

struct BoneAnimationSlotData
{
	maxon::BaseArray<BoneAnimationKeyframeData> keyframes;

	BoneAnimationSlotData() = default;
	BoneAnimationSlotData(const BoneAnimationSlotData& other);
	BoneAnimationSlotData& operator=(const BoneAnimationSlotData& other);
	BoneAnimationSlotData(BoneAnimationSlotData&&) noexcept = default;
	BoneAnimationSlotData& operator=(BoneAnimationSlotData&&) noexcept = default;

	Bool Write(HyperFile* hf) SDK2024_Const;
	Bool Read(HyperFile* hf);
};

enum class MMDBoneTagMsgType : int8_t
{
	DEFAULT = -1,
	BONE_HIERARCHY_DIRTY,
	BONE_MORPH_ADD,
	BONE_MORPH_DELETE,
	BONE_MORPH_RENAME
};

class MMDBoneTagMsg
{
public:
	MMDBoneTagMsgType type;
	String name;
	String name_old;
	BaseTag* bone_tag = nullptr;
	DescID strength_id;

	explicit MMDBoneTagMsg(const MMDBoneTagMsgType in_type = MMDBoneTagMsgType::DEFAULT) : type(in_type) {}
	MMDBoneTagMsg(MMDBoneTagMsgType in_type, const String& name_, const DescID& strength_id_, BaseTag* tag_)
		: type(in_type), name(name_), bone_tag(tag_), strength_id(strength_id_) {}
	MMDBoneTagMsg(MMDBoneTagMsgType in_type, const String& name_, const DescID& strength_id_, BaseTag* tag_, const String& old_name_)
		: type(in_type), name(name_), name_old(old_name_), bone_tag(tag_), strength_id(strength_id_) {}
	virtual ~MMDBoneTagMsg() = default;
	MMDBoneTagMsg(const MMDBoneTagMsg&) = delete; void operator =(const MMDBoneTagMsg&) = delete;
	MMDBoneTagMsg(MMDBoneTagMsg&&) = delete; void operator =(MMDBoneTagMsg&&) = delete;
};

class C4DIKChainNodeAdapter final : public libmmd::IMMDNode
{
public:
	C4DIKChainNodeAdapter() = default;

	void SetupFromBone(BaseObject* bone_object, MMDBoneTag* bone_tag, std::string name);
	void SetParentAdapter(C4DIKChainNodeAdapter* parent);
	void ClearChildren();
	void AddChildAdapter(C4DIKChainNodeAdapter* child);
	void UpdateInitialGlobalTransform();
	void ResetCurrentTransformToInitial();
	void SyncCurrentTransformsFromBoneObject(Bool reset_ik_rotation = true);
	void GetCurrentRelativeState(Vector& translation, std::array<Float32, 4>& rotation) const;
	void ApplyLocalToBoneObject() const;
	Int32 GetBoneIndex() const;

	const std::string& GetName() const override { return name_; }
	void SetGlobalTransform(const Eigen::Matrix4f& m) override;
	void SyncLocalTransformFromGlobal();
	const Eigen::Matrix4f& GetGlobalTransform() const override { return global_transform_; }
	const Eigen::Matrix4f& GetInitialGlobalTransform() const override { return initial_global_transform_; }
	const Eigen::Matrix4f& GetLocalTransform() const override { return local_transform_; }
	void SetIKRotate(const Eigen::Quaternionf& ikr) override { ik_rotation_ = ikr; }
	const Eigen::Quaternionf& GetIKRotate() const override { return ik_rotation_; }
	Eigen::Quaternionf AnimateRotate() const override { return animate_rotation_; }
	void UpdateLocalTransform() override;
	void UpdateGlobalTransform() override;
	C4DIKChainNodeAdapter* GetParent() const override { return parent_; }

private:
	std::string name_;
	BaseObject* bone_object_ = nullptr;
	MMDBoneTag* bone_tag_ = nullptr;
	C4DIKChainNodeAdapter* parent_ = nullptr;
	std::vector<C4DIKChainNodeAdapter*> children_;
	Eigen::Matrix4f initial_local_transform_ = Eigen::Matrix4f::Identity();
	Eigen::Matrix4f initial_global_transform_ = Eigen::Matrix4f::Identity();
	Eigen::Matrix4f global_transform_ = Eigen::Matrix4f::Identity();
	Eigen::Matrix4f local_transform_ = Eigen::Matrix4f::Identity();
	Eigen::Vector3f animate_translation_ = Eigen::Vector3f::Zero();
	Eigen::Quaternionf animate_rotation_ = Eigen::Quaternionf::Identity();
	Eigen::Quaternionf ik_rotation_ = Eigen::Quaternionf::Identity();
};

/**
 * @class MMDBoneTag
 * @brief This class represents a bone tag used in the MMDTool module.
 *
 * The MMDBoneTag class is responsible for managing bone data and operations related to bone manipulation.
 * It provides functions for setting bone root and bone object, initializing the tag, handling messages, executing the tag, and reading/writing data.
 * Additionally, it supports bone morphs, bone protection, and physical bones.
 */
class MMDBoneTag final : public TagData
{
	// Bone manager link (persistent cache)
	AutoAlloc<BaseLink> bone_manager_link_;
	// Bone manager ObjectData (runtime cache)
	MMDBoneManagerObject* bone_manager_data_ = nullptr;
	// Corresponding bone object
	BaseObject* bone_object_ = nullptr;
	// Runtime topology cache for hierarchy dirty detection.
	BaseObject* hierarchy_parent_cache_ = nullptr;
	BaseObject* hierarchy_pred_cache_ = nullptr;
	BaseObject* hierarchy_manager_cache_ = nullptr;
	// Serialized link to the Protection tag used for PMX lock (distinct from user-added Tprotection).
	AutoAlloc<BaseLink> bone_lock_protection_link_;
	// Bone mode
	Int32 bone_mode_ = BONE_MODE_ANIM;
	// Is IK
	Bool is_IK = false;
	// Guards inherit source parameter synchronization between index/link fields.
	Bool is_syncing_inherit_source_ = false;

	// Bone morph data
	Int32 bone_morph_name_index_ = 0;
	maxon::PointerArray<BoneMorphTagData> bone_morph_data_arr_;
	maxon::HashMap<DescID, Int32> bone_morph_button_id_map_;
	Vector prev_position_;
	Vector prev_rotation_;

	// Bone animation data, stored per animation slot.
	maxon::BaseArray<BoneAnimationSlotData> bone_animation_slots_;
	Int32 active_animation_slot_ = -1;
	Vector evaluated_animation_translation_ = Vector();
	std::array<Float32, 4> evaluated_animation_rotation_ { 0.F, 0.F, 0.F, 1.F };
	Vector evaluated_append_animation_translation_ = Vector();
	std::array<Float32, 4> evaluated_append_animation_rotation_ { 0.F, 0.F, 0.F, 1.F };
	std::array<Float32, 4> evaluated_ik_rotation_ { 0.F, 0.F, 0.F, 1.F };
	Vector runtime_playback_override_translation_ = Vector();
	std::array<Float32, 4> runtime_playback_override_rotation_ { 0.F, 0.F, 0.F, 1.F };
	Bool has_runtime_playback_override_ = false;
	BaseTime runtime_playback_override_time_ = BaseTime(-1.);
	BaseTime last_prephysics_time_ = BaseTime(-1.);
	BaseTime last_ik_solve_time_ = BaseTime(-1.);
	BaseTime last_postphysics_ik_solve_time_ = BaseTime(-1.);
	Bool standalone_ik_chain_dirty_ = true;
	const libmmd::MMDIkSolver* standalone_ik_chain_solver_ = nullptr;
	Bool skip_prephysics_scene_write_ = false;
	Bool ik_overridden_this_frame_ = false;
	Int32 append_recursion_depth_ = 0;
	Int32 ui_animation_frame_cache_ = NOTOK;
	Int32 ui_animation_curve_type_cache_ = NOTOK;

	friend class MMDBoneManagerObject;
	friend class C4DIKChainNodeAdapter;
	friend class MMDRigidObject;
	friend class MMDModelManagerObject;

public:
	MMDBoneTag(const MMDBoneTag&) = delete; void operator =(const MMDBoneTag&) = delete;
	MMDBoneTag(MMDBoneTag&&) noexcept = default; MMDBoneTag& operator =(MMDBoneTag&&) noexcept = default;
	typedef TagData SUPER;

	/**
	 * @brief Default constructor for MMDBoneTag.
	 */
	MMDBoneTag() = default;

	/**
	 * @brief Default destructor for MMDBoneTag.
	 */
	~MMDBoneTag() override = default;

	/**
	 * @brief Allocates a new instance of MMDBoneTag.
	 * @return A pointer to the newly allocated MMDBoneTag instance.
	 */
	static NodeData* Alloc();

	/**
	 * @brief Initializes the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] isCloneInit The initialization parameters.
	 * @return true if initialization is successful, false otherwise.
	 */
	SDK2024_InitOverride;
	SDK2024_CopyToOverride;

	/**
	 * @brief Handles messages sent to the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] type The type of the message.
	 * @param[in] data The message data.
	 * @return true if the message is handled, false otherwise.
	 */
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	/**
	 * @brief Sets a dynamic parameter of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] id The ID of the parameter.
	 * @param[in] t_data The data to set.
	 * @param[in,out] flags The flags indicating the status of the parameter.
	 * @return true if the parameter is set successfully, false otherwise.
	 */
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	/**
	 * @brief Gets the enabling status of a dynamic parameter of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] id The ID of the parameter.
	 * @param[in] t_data The data of the parameter.
	 * @param[in] flags The flags indicating the status of the parameter.
	 * @param[in] itemdesc The description of the item.
	 * @return The enabling status of the parameter.
	 */
	SDK2024_GetDEnablingOverride;

	/**
	 * @brief Executes the MMDBoneTag.
	 * @param[in] tag The BaseTag representing the MMDBoneTag.
	 * @param[in] doc The BaseDocument containing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @param[in] bt The BaseThread for execution.
	 * @param[in] priority The execution priority.
	 * @param[in] flags The execution flags.
	 * @return The execution result.
	 */
	EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

	/**
	 * @brief Reads the MMDBoneTag from a HyperFile.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] hf The HyperFile to read from.
	 * @param[in] level The read level.
	 * @return true if the MMDBoneTag is read successfully, false otherwise.
	 */
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;

	/**
	 * @brief Writes the MMDBoneTag to a HyperFile.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] hf The HyperFile to write to.
	 * @return true if the MMDBoneTag is written successfully, false otherwise.
	 */
	SDK2024_WriteOverride;

	/**
	 * @brief Refreshes the color of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @return true if the color is refreshed successfully, false otherwise.
	 */
	Bool RefreshColor(GeListNode* node = nullptr, BaseObject* op = nullptr);

	/**
	 * @brief Gets the bone index of the MMDBoneTag.
	 * @return The bone index.
	 */
	Int32 GetBoneIndex() const;

	Int32 AddBoneMorph(String morph_name = {});
	Bool SetBoneMorphTranslationNoCheck(Int32 id, Vector translation);
	Bool SetBoneMorphRotationNoCheck(Int32 id, Vector rotation);
	static Bool SplineDataCallBack(Int32 cid, const void* data);
	Bool EnsureAnimationSlotCount(Int32 slot_count);
	Bool ReplaceAnimationSlot(Int32 slot_index, const maxon::BaseArray<BoneAnimationKeyframeData>& keyframes);
	void ClearAnimationSlot(Int32 slot_index);
	void ClearAllAnimationSlots();
	Bool CopyAnimationSlot(Int32 slot_index, maxon::BaseArray<BoneAnimationKeyframeData>& keyframes) const;
	void SetActiveAnimationSlot(Int32 slot_index);
	Int32 GetActiveAnimationSlot() const { return active_animation_slot_; }
	Int32 GetAnimationSlotCount() const { return static_cast<Int32>(bone_animation_slots_.GetCount()); }
	Int32 GetMaxAnimationFrame(Int32 slot_index) const;

private:
	void HandleBoneMorphButtonCommand(const DescID& desc_id);
	Bool InitAnimationSpline(GeListNode* node = nullptr);
	Bool SyncSplineFromSelection(GeListNode* node);
	Bool SyncSplineFromCurrentParametersIfNeeded(GeListNode* node = nullptr);
	Bool StoreSplineToSelection(GeListNode* node);
	Bool NavigateAnimationKeyframe(GeListNode* node, BaseDocument* doc, Bool forward);
	Bool AddAnimationKeyframeFromCurrentPose(GeListNode* node, BaseDocument* doc);
	Bool DeleteAnimationKeyframeAtCurrentFrame(GeListNode* node, BaseDocument* doc);
	void RefreshAnimationMarkerTracks(GeListNode* node);
	void InvalidateAnimationUICache();
	BoneAnimationSlotData* EnsureAnimationSlot(Int32 slot_index);
	BoneAnimationSlotData* GetAnimationSlot(Int32 slot_index);
	const BoneAnimationSlotData* GetAnimationSlot(Int32 slot_index) const;
	BoneAnimationSlotData* GetActiveAnimationSlotData();
	const BoneAnimationSlotData* GetActiveAnimationSlotData() const;
	BoneAnimationKeyframeData* FindAnimationKeyframe(BoneAnimationSlotData& slot, Int32 frame);
	const BoneAnimationKeyframeData* FindAnimationKeyframe(const BoneAnimationSlotData& slot, Int32 frame) const;
	Int32 FindAnimationKeyframeIndex(const BoneAnimationSlotData& slot, Int32 frame) const;
	void ResetEvaluatedAnimationState();
	void SetEvaluatedAnimationState(const Vector& translation, const std::array<Float32, 4>& rotation);
	void GetEvaluatedAnimatedLocalState(Vector& translation, std::array<Float32, 4>& rotation) const;
	void BeginPrephysicsFrame(const BaseDocument* doc);
	void MarkPrephysicsSceneWriteSkipped(const BaseDocument* doc);
	Bool ShouldSkipPrephysicsSceneWrite(const BaseDocument* doc) const;
	Bool HasRecentPlaybackRuntimeOverride(const BaseDocument* doc) const;
	void ClearPlaybackRuntimeOverride();
	void SetPlaybackRuntimeOverride(const BaseDocument* doc, const Vector& translation, const std::array<Float32, 4>& rotation);
	Bool GetPlaybackRuntimeOverride(Vector& translation, std::array<Float32, 4>& rotation) const;
	Bool HasPostPhysicsIKSolveAtTime(const BaseDocument* doc) const;
	void MarkPostPhysicsIKSolvedAtTime(const BaseDocument* doc);
	void SetAppendRecursionDepth(Int32 depth);
	void RefreshExecutionPriority(GeListNode* node = nullptr);
	Bool ApplyActiveAnimation(BaseObject* op, BaseDocument* doc, Bool apply_to_scene = true);
	Bool RunIKSolveAnimMode(BaseObject* op, Bool mark_prephysics_chain = true, Bool allow_same_frame_resolve = false);
	BaseTag* ResolveInheritSourceBoneTag() const;
	void SyncInheritSourceIndexFromLink(GeListNode* node, const GeData& link_data);
	void SyncInheritSourceLinkFromIndex(GeListNode* node, Int32 bone_index);
	void RequestAppendExecutionOrderRefresh(GeListNode* node = nullptr);
	void CollectIKAffectedBoneIndices(maxon::BaseArray<Int32>& affected_indices) const;
	void CacheIKSolveRuntimeOverrides(const BaseDocument* doc);
	void MarkPrephysicsIKChainUpdated(const BaseDocument* doc);
	void InvalidateStandaloneIKChainCache();
	/**
	 * @brief Creates a bone lock tag for the MMDBoneTag.
	 * @return true if the bone lock tag is created successfully, false otherwise.
	 */
	bool CreateBoneLockTag();

	/**
	 * @brief Resolves bone_lock_protection_link_ to a Tprotection on bone_object_; clears stale link in non-const paths via FindOrCreateBoneLockTag.
	 */
	BaseTag* GetBoneLockProtectionTag() const;

	/**
	 * @brief Ensures a linked Protection tag exists (deserialize, legacy hidden tag, or create).
	 * @return true if a usable Tprotection is available, false otherwise.
	 */
	bool FindOrCreateBoneLockTag();

	/**
	 * @brief Handles description updates for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the description data.
	 * @param[in] id The ID of the description.
	 */
	void HandleDescriptionUpdate(GeListNode* node, BaseContainer* bc, Int32 id);

	MMDBoneManagerObject* GetBoneManager();
	MMDModelManagerObject* GetModelManager();
	bool UpdateHierarchyTopologyCache(BaseObject* bone_object, Bool notify_managers);
	void NotifyHierarchyDirty(BaseObject* previous_manager_object, BaseObject* current_manager_object) const;

	void HandleBoneModeChange(Int32 bone_mode);

	void BuildStandaloneIKChains();

	/**
	 * @brief Sets the rotation lock for the MMDBoneTag.
	 * @param[in] flag The rotation lock flag.
	 */
	void SetRotationLock(bool flag) const;

	/**
	 * @brief Sets the position lock for the MMDBoneTag.
	 * @param[in] flag The position lock flag.
	 */
	void SetPositionLock(bool flag) const;

	/**
	 * @brief Sets the bone display for the MMDBoneTag.
	 *
	 * This function is responsible for setting the display properties of the bone
	 * based on the provided data instance and root object message.
	 *
	 * @param[in] data_instance_bc The BaseContainer containing the data instance.
	 * @param[in] msg The MMDBoneRootObjectMsg containing the root object message.
	 */
	void SetBoneDisplay(const BaseContainer* data_instance_bc, const MMDBoneManagerObjectMsg* msg) const;
};
