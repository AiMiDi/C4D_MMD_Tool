/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.cpp
Description:	DESC

**************************************************************************/

#ifndef MMD_BONE_ROOT_H__
#define MMD_BONE_ROOT_H__

#include "mmd_root.hpp"
#include "description/OMMDBoneRoot.h"
#include "utils/morph_ui_data_util.hpp"
#include "module/tools/tag/mmd_bone.h"

namespace CMTToolsSetting
{
	struct ModelImport;
}

/*
type 0: update BoneRoot;
type 1: set bone display type;
type 2: bone index change;
type 3: bone morph change;
*/
enum class MMDBoneRootObjectMsgType : int8_t
{
	DEFAULT = -1,
	SET_BONE_DISPLAY_TYPE,
	BONE_ROOT_UPDATE,
	BONE_MORPH_CHANGE
};
struct MMDBoneRootObjectMsg
{

	MMDBoneRootObjectMsgType type;
	Int32	display_type;
	BaseObject* bond_root_object;

	explicit MMDBoneRootObjectMsg(
		const MMDBoneRootObjectMsgType type_ = MMDBoneRootObjectMsgType::DEFAULT,
		const Int32 display_type_ = BONE_DISPLAY_TYPE_ON,
		BaseObject* BoneRoot_ = nullptr) :
		type(type_),
		display_type(display_type_),
		bond_root_object(BoneRoot_) {}
};
class MMDBoneRootObject final : public MMDRootObject
{
	Int bone_name_index = 0;
	BaseObject* m_model_root = nullptr;
	BaseObject* m_rigid_root = nullptr;
	BaseObject* m_joint_root = nullptr;
	BaseContainer m_bone_items;
	maxon::HashMap<Int, maxon::StrongRef<AutoAlloc<BaseLink>>> m_bone_list;
	maxon::HashMap<String, maxon::BaseList<MorphUIData>> m_bone_morph_data;
	MMDBoneRootObject() = default;
	~MMDBoneRootObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneRootObject)
	CMT_DEFAULT_MOVE_BODY(MMDBoneRootObject)
	INSTANCEOF(MMDBoneRootObject, MMDRootObject)
public:
	static NodeData* Alloc();
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	Bool SetBoneMorphStrength(const String& morph_name, Float strength);
	[[nodiscard]] const maxon::HashMap<String, maxon::BaseList<MorphUIData>>& GetBoneMorphData() const;

	[[nodiscard]] BaseList2D* FindBoneTag(Int32 index) const;
	Int32 FindBoneTagIndex(const BaseList2D* bone_tag) const;

	Bool LoadPMX(const libmmd::pmx_model& pmx_model, maxon::HashMap<uint64_t, BaseObject*>& bone_map, const CMTToolsSetting::ModelImport& setting);
private:
	void CreateDisplayTag(GeListNode* node) override;
	void HandleDescriptionCommandMessage(GeListNode* node, void* data);
	bool HandleMMDBoneTagMessage(GeListNode* node, void* data);
	bool HandleBoneIndexChangeMessage(GeListNode* node, void* data, bool& need_update_morph);
	bool HandleBoneMorphAdd(GeListNode* node, void* data, bool& need_update_morph);
	bool HandleBoneMorphDelete(GeListNode* node, void* data, bool& need_update_morph);
	bool HandleBoneMorphRename(GeListNode* node, void* data, bool& need_update_morph);
};

#endif // !MMD_BONE_ROOT_H__
