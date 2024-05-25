/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_mesh_root.cpp
Description:	MMD mesh root object

**************************************************************************/

#ifndef MMD_MESH_ROOT_H__
#define MMD_MESH_ROOT_H__

#include "CMTSceneManager.h"
#include "CMTSceneManager.h"
#include "CMTSceneManager.h"
#include "mmd_root.hpp"
#include "utils/morph_ui_data_util.hpp"

namespace CMTToolsSetting
{
	struct ModelImport;
}

enum class MMDMeshRootObjectMsgType : uint8_t
{
	DEFAULT,
	MESH_MORPH_CHANGE
};
struct MMDMeshRootObjectMsg
{
	MMDMeshRootObjectMsgType type = MMDMeshRootObjectMsgType::DEFAULT;
	explicit MMDMeshRootObjectMsg(const MMDMeshRootObjectMsgType type_ = MMDMeshRootObjectMsgType::DEFAULT) : type(type_) {}
};

class MMDMeshRootObject final : public MMDRootObject
{
	BaseObject* m_model_root = nullptr;
	maxon::HashMap<BaseTag*, Int32> m_tag_mode_map;
	maxon::HashMap<String, maxon::BaseList<MorphUIData>> m_mesh_morph_data;

	MMDMeshRootObject() = default;
	~MMDMeshRootObject() override = default;

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDMeshRootObject)
	CMT_DEFAULT_MOVE_BODY(MMDMeshRootObject)
	INSTANCEOF(MMDMeshRootObject, MMDRootObject)
public:
	static NodeData* Alloc();
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;

	[[nodiscard]] const maxon::HashMap<String, maxon::BaseList<MorphUIData>>& GetMeshMorphData() const;
	Bool SetMeshMorphStrength(const String& morph_name, Float strength);
	Bool LoadPMX(
		const libmmd::pmx_model& pmx_model,
		const maxon::BaseArray<BaseObject*>& bone_list,
		const CMTToolsSetting::ModelImport& setting);
private:
	void RefreshMeshMorphData(BaseObject* op);
};

#endif // !MMD_MESH_ROOT_H__
