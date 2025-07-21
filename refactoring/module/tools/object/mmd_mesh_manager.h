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
#include "mmd_manager.hpp"
#include "description/OMMDMeshManager.h"
#include "utils/morph_ui_data_util.hpp"

namespace CMTToolsSetting
{
	struct ModelImport;
}

enum class MMDMeshManagerObjectMsgType : uint8_t
{
	DEFAULT,
	MESH_MORPH_CHANGE,
	MESH_MODE_CHANGE
};
struct MMDMeshManagerObjectMsg
{
	MMDMeshManagerObjectMsgType type = MMDMeshManagerObjectMsgType::DEFAULT;
	Int32	display_type;
	Int32	mesh_mode;

	explicit MMDMeshManagerObjectMsg(const MMDMeshManagerObjectMsgType type_ = MMDMeshManagerObjectMsgType::DEFAULT,
		const Int32 display_type_ = MESH_DISPLAY_TYPE_ON,
		const Int32 mesh_mode_ = MESH_MODE_ANIM) : type(type_) ,display_type(display_type_), mesh_mode(mesh_mode_){}
};

class MMDMeshManagerObject final : public MMDManagerObject
{
	BaseObject* m_model_root = nullptr;
	maxon::HashMap<BaseTag*, Int32> m_tag_mode_map;
	maxon::HashMap<String, maxon::BaseList<MorphUIData>> m_mesh_morph_data;

	MMDMeshManagerObject() = default;
	~MMDMeshManagerObject() override = default;

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDMeshManagerObject)
	CMT_DEFAULT_MOVE_BODY(MMDMeshManagerObject)
	INSTANCEOF(MMDMeshRootObject, MMDManagerObject)
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
	Bool SetMorphStrength(const String& morph_name, const Float& strength);
	Bool LoadPMX(
		const libmmd::PMXFile& pmx_file,
		const maxon::BaseArray<BaseObject*>& bone_list,
		const CMTToolsSetting::ModelImport& setting);
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting);
private:
	void RefreshMeshMorphData(BaseObject* op);
};

#endif // !MMD_MESH_ROOT_H__
