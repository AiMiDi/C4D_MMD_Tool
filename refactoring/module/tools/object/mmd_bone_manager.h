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
	Float position_multiple_ = 1.0;
	BaseObject* model_manager_ = nullptr;

	libmmd::MMDMorphManager* mmd_morph_manager_ = nullptr;
	libmmd::MMDNodeManager* mmd_node_manager_ = nullptr;

	BaseContainer bone_items_;
	maxon::HashMap<Int, maxon::StrongRef<AutoAlloc<BaseLink>>> bone_list_;
	friend MMDModelManagerObject;
	MMDBoneManagerObject() = default;
	~MMDBoneManagerObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneManagerObject)
	CMT_DEFAULT_MOVE_BODY(MMDBoneManagerObject)
	INSTANCEOF(MMDBoneRootObject, MMDManagerObject)
public:
	static NodeData* Alloc();
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	[[nodiscard]] BaseTag* FindBone(Int32 index) const;
	Int32 FindBoneIndex(const BaseTag* bone_tag) const;
	const BaseContainer& GetBoneItems() const;
	const Float& GetPositionMultiple() const { return position_multiple_; }

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, maxon::BaseArray<BaseObject*>& bone_list, const CMTToolsSetting::ModelImport& setting);
	Bool SavePMX(libmmd::PMXFile& pmx_model, const CMTToolsSetting::ModelExport& setting);

private:
	void CreateDisplayTag(GeListNode* node) override;
	void HandleDescriptionCommandMessage(GeListNode* node, void* data);
	bool HandleMMDBoneTagMessage(GeListNode* node, void* data);
	bool HandleBoneIndexChangeMessage(GeListNode* node);
};
