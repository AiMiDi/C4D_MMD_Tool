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
	BoneMorphData() = default;
	BoneMorphData(const BoneMorphData&) = delete;
	BoneMorphData(BoneMorphData&& src) noexcept :
	MAXON_MOVE_MEMBERS(grp_id, strength_id, translation_id, rotation_id, button_grp_id, button_delete_id, button_rename_id, name){}
	Bool Write(HyperFile* hf) const
	{
		if (!grp_id.Write(hf))
			return false;
		if (!strength_id.Write(hf))
			return false;
		if (!translation_id.Write(hf))
			return false;
		if (!rotation_id.Write(hf))
			return false;
		if (!button_grp_id.Write(hf))
			return false;
		if (!button_delete_id.Write(hf))
			return false;
		if (!button_rename_id.Write(hf))
			return false;
		if (!hf->WriteString(name))
			return false;
		return true;
	}
	Bool Read(HyperFile* hf)
	{
		if (!grp_id.Read(hf))
			return false;
		if (!strength_id.Read(hf))
			return false;
		if (!translation_id.Read(hf))
			return false;
		if (!rotation_id.Read(hf))
			return false;
		if (!button_grp_id.Read(hf))
			return false;
		if (!button_delete_id.Read(hf))
			return false;
		if (!button_rename_id.Read(hf))
			return false;
		if (!hf->ReadString(&name))
			return false;
		return true;
	}
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
	// 是否是物理骨骼 
	Bool m_is_physical_bone = false;

	// 储存骨骼表情数据
	maxon::BaseArray<BoneMorphData> bone_morph_data_arr;

	Bool RefreshColor(GeListNode* node, BaseObject* op);
	static TrackDescIDArray GetTrackDescIDsImpl();

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTag)
	CMT_DEFAULT_MOVE_BODY(MMDBoneTag)
	INSTANCEOF(MMDBoneTag, MMDBoneTagBase)

public:
	MMDBoneTag() = default;
	~MMDBoneTag() override = default;

	Bool Init(GeListNode* node SDK2024_InitPara) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	void SetBoneObject(BaseObject* object)
	{
		m_bone_object = object;
	}
	void SetBoneRootObject(BaseObject* object)
	{
		m_bone_root = object;
	}
	Bool IsPhysicalBone() const
	{
		return m_is_physical_bone;
	}
	void SetPhysical(const Bool is_physical_bone)
	{
		m_is_physical_bone = is_physical_bone;
	}
protected:
	TrackDescIDArray GetTrackDescIDs() override;
	TrackObjectArray GetTrackObjects(GeListNode* node) override;
	InterpolatorTrackTableArray GetTrackInterpolatorMap() override;
	CurrentValuesArray GetCurrentValues(GeListNode* node) override;

};
