/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.cpp
Description:	DESC

**************************************************************************/

#pragma once

#include "CMTSceneManager.h"
#include "mmd_manager.hpp"
#include "description/OMMDBoneManager.h"
#include "maxon/pointerarray.h"
#include "utils/morph_ui_data_util.hpp"

class MMDModelManagerObject;

namespace CMTToolsSetting
{
	struct ModelImport;
	struct ModelExport;
	struct MotionImport;
}

enum class MMDBoneManagerObjectMsgType : int8_t
{
	DEFAULT = -1,
	// bone display type change
	SET_BONE_DISPLAY_UPDATE,
	// bone hierarchy change
	BONE_HIERARCHY_UPDATE,
	// bone morph change
	BONE_MORPH_CHANGE,
	// bone mode change
	BONE_MODE_CHANGE
};
struct MMDBoneManagerObjectMsg
{

	MMDBoneManagerObjectMsgType type;
	Int32	display_type;
	BaseObject* bone_manager_object;
	Int32	bone_mode;

	explicit MMDBoneManagerObjectMsg(
		const MMDBoneManagerObjectMsgType in_type = MMDBoneManagerObjectMsgType::DEFAULT,
		const Int32 in_display_mode = BONE_DISPLAY_TYPE_ON,
		BaseObject* in_bone_manager_object = nullptr,
		const Int32 in_bone_mode = BONE_MODE_ANIM) :
		type(in_type),
		display_type(in_display_mode),
		bone_manager_object(in_bone_manager_object),
	    bone_mode(in_bone_mode)
	    {}
};
class MMDBoneManagerObject final : public MMDManagerObject
{
	Int32 bone_name_index_ = 0;
	AutoAlloc<BaseLink> model_manager_;

	maxon::HashMap<String, maxon::PointerArray<MorphUIData>> bone_morph_map_;

	struct BoneHierarchySyncEntry
	{
		BaseObject* object = nullptr;
		BaseTag* tag = nullptr;
		Int32 bone_index = -1;
		Int32 parent_index = -1;
		String parent_name;
	};

	mutable BaseContainer bone_items_;
	maxon::HashMap<Int, maxon::StrongRef<AutoAlloc<BaseLink>>> bone_list_;
	maxon::HashMap<BaseObject*, Int32> bone_index_lookup_;
	Bool is_syncing_bone_hierarchy_ = false;
	Bool has_pending_bone_hierarchy_sync_ = false;
	Bool append_execution_order_dirty_ = true;
	Bool is_refreshing_append_execution_order_ = false;
	friend MMDModelManagerObject;
	MMDBoneManagerObject() = default;
	~MMDBoneManagerObject() override = default;
	public:
	typedef MMDManagerObject SUPER;
	static NodeData* Alloc();
	MMDBoneManagerObject(const MMDBoneManagerObject&) = delete; void operator =(const MMDBoneManagerObject&) = delete;
	MMDBoneManagerObject(MMDBoneManagerObject&& other) noexcept : MMDManagerObject(std::forward<MMDBoneManagerObject>(other)) {} MMDBoneManagerObject& operator =(MMDBoneManagerObject&&) noexcept = default;
	SDK2024_CopyToOverride;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	[[nodiscard]] BaseTag* FindBone(Int32 index) const;
	Int32 FindBoneIndex(const BaseTag* bone_tag) const;
	const BaseContainer& GetBoneItems() const;
	MMDModelManagerObject* GetModelManagerData();
	maxon::HashMap<String, maxon::PointerArray<MorphUIData>>& GetBoneMorphMap() { return bone_morph_map_; }

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, maxon::BaseArray<BaseObject*>& bone_list, const CMTToolsSetting::ModelImport& setting);
	Bool SavePMX(libmmd::PMXFile& pmx_model, const CMTToolsSetting::ModelExport& setting);

	void SetAllBoneMode(Int32 mode);
	Bool EnsureAllAnimationSlotCount(Int32 slot_count);
	void SetAllActiveAnimationSlot(Int32 slot_index);
	void MarkAppendExecutionOrderDirty();
	void EnsureAppendExecutionOrder();

private:
	void CreateDisplayTag(GeListNode* node) override;
	void HandleDescriptionCommandMessage(GeListNode* node, void* data);
	bool HandleMMDBoneTagMessage(GeListNode* node, void* data);
	bool HandleBoneIndexChangeMessage(GeListNode* node);
	bool SynchronizeBoneHierarchy(BaseObject* bone_manager_object, Bool update_ui = true);
	bool CollectBoneHierarchyDFS(BaseObject* object, maxon::BaseArray<BoneHierarchySyncEntry>& entries) const;
	void RefreshBoneHierarchyUI(BaseObject* bone_manager_object) const;
	Int32 ComputeAppendRecursionDepth(Int32 bone_index, maxon::BaseArray<Int32>& depth_cache, maxon::BaseArray<UChar>& visit_state) const;
};
