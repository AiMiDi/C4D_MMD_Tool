/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.cpp
Description:	DESC

**************************************************************************/

#pragma once
#include "module/tools/mmd_interpolator.hpp"
#include "description/TMMDBone.h"

enum class MMDBoneTagMsgType : int8_t
{
	DEFAULT = -1,
	BONE_INDEX_CHANGE,
	BONE_MORPH_ADD,
	BONE_MORPH_DELETE,
	BONE_MORPH_RENAME
};

struct BoneMorphData
{
	DescID	grp_id = DescID();
	DescID	strength_id = DescID();
	DescID	translation_id = DescID();
	DescID	rotation_id = DescID();
	DescID	button_grp_id = DescID();
	DescID	button_delete_id = DescID();
	DescID	button_rename_id = DescID();
	String	name = String();
	Bool Write(HyperFile* hf) const;
	Bool Read(HyperFile* hf);
	BoneMorphData() = default;
	~BoneMorphData() = default;
	BoneMorphData(BoneMorphData&& src) noexcept :
	MAXON_MOVE_MEMBERS(grp_id, strength_id, translation_id, rotation_id, button_grp_id, button_delete_id, button_rename_id, name){}
	BoneMorphData& operator=(BoneMorphData&&) = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(BoneMorphData)
};

struct MMDBoneTagMsg
{
	MMDBoneTagMsgType type = MMDBoneTagMsgType::DEFAULT;
	String	name;
	String	name_old;
};

using MMDBoneTagBase = MMDInterpolatorNode<TagData, 6, PMX_BONE_TAG_INTERPOLATOR_NUM, PMX_BONE_TAG_SPLINE, PMX_BONE_TAG_CURVE_TYPE, PMX_BONE_TAG_FRAME_AT, VMD_CAM_OBJ_FRAME_AT_STR>;

class MMDBoneTag final : public MMDBoneTagBase
{
	// 储存前一帧，以确定更新状态 
	Int32 prev_frame = -1;
	// 储存上一种曲线类型，以确定更新状态 
	Int32 prev_interpolator_type = -1;
	// 储存前一帧位置，用于处理骨骼表情 
	Vector	prev_position{};
	// 储存前一帧选择，用于处理骨骼表情 
	Vector	prev_rotation{};

	// 赋予亲骨骼对象 
	AutoAlloc<BaseLink> inherit_bone_parent;
	// 骨骼根对象 
	BaseObject* m_bone_root = nullptr;
	// 对应的骨骼主对象 
	BaseObject* m_bone_object = nullptr;
	// 骨骼标签 
	BaseTag* m_bone_tag = nullptr;
	// 用于限制骨骼
	BaseTag* protection_tag = nullptr;
	// 是否是物理骨骼 
	Bool m_is_physical_bone = false;

	// 骨骼表情索引
	Int32 m_bone_morph_name_index = 0;
	// 储存骨骼表情数据
	maxon::BaseArray<BoneMorphData> bone_morph_data_arr;
	maxon::HashMap<DescID, Int> button_id_map;

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTag)
	CMT_DEFAULT_MOVE_BODY(MMDBoneTag)
	INSTANCEOF(MMDBoneTag, MMDBoneTagBase)

public:
	explicit MMDBoneTag(BaseObject* bone_object, BaseObject* bone_root) : m_bone_root(bone_root), m_bone_object(bone_object) {}
	~MMDBoneTag() override = default;

	static NodeData* Alloc();
	Bool Init(GeListNode* node SDK2024_InitPara) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) SDK2024_Const override;
	EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseTag* tag, PriorityList* list) override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;

	[[nodiscard]] Bool IsPhysicalBone() const;
	void SetPhysical(Bool is_physical_bone);

	Int AddBondMorph(String morph_name);
	BoneMorphData* GetMorph(Int index);
	Bool SetBondMorphTranslation(Int index, const Vector& translation);
	Bool SetBondMorphRotation(Int index, const Vector& rotation);
	[[nodiscard]] Int GetMorphCount() const;
	[[nodiscard]] bool CheckBoneMorphIndex(Int index) const;
protected:
	TrackDescIDArray GetTrackDescIDs() override;
	TrackObjectArray GetTrackObjects(GeListNode* node) override;
	InterpolatorTrackTableArray GetTrackInterpolatorMap() override;
	CurrentValuesArray GetCurrentValues(GeListNode* node) override;
private:
	Bool RefreshColor(GeListNode* node, BaseObject* op = nullptr);
	void CheckInheritBoneParent(const BaseDocument* doc, BaseObject* op, const BaseContainer* bc);
	void UpdateBoneMorph(const BaseTag* tag, BaseObject* op);
	bool CreateBoneLockTag();
	void UpdateBoneIndex(BaseTag* tag, BaseObject* op, BaseContainer* bc);
	void UpdateBoneLock(BaseObject* op, const BaseContainer* bc);
	static TrackDescIDArray GetTrackDescIDsImpl();
};
