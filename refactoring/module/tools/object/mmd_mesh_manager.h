/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_mesh_root.cpp
Description:	MMD mesh root object

**************************************************************************/

#pragma once

#include "CMTSceneManager.h"
#include "mmd_manager.hpp"
#include "description/OMMDMeshManager.h"
#include "maxon/pointerarray.h"
#include "utils/morph_ui_data_util.hpp"

class MMDModelManagerObject;

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
	Int32 mesh_mode_ = MESH_MODE_ANIM;
	AutoAlloc<BaseLink> model_manager_;
	maxon::HashMap<BaseTag*, Int32> mesh_morph_mode_;

	libmmd::MMDMorphManager* mmd_morph_manager_;
	maxon::HashMap<String, Int32> mesh_morph_name_;
	maxon::HashSet<String> uv_morph_names_;
	maxon::BaseArray<Int32> morph_manager_index_;
	maxon::BaseArray<maxon::PointerArray<MorphUIData>> mesh_morph_data_;

	maxon::Synchronized<Bool> needs_morph_data_refresh_;

	MMDMeshManagerObject() = default;
	~MMDMeshManagerObject() override = default;

	friend MMDModelManagerObject;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDMeshManagerObject)
	CMT_DEFAULT_MOVE_BODY(MMDMeshManagerObject)
	INSTANCEOF(MMDMeshManagerObject, MMDManagerObject)
public:
	static NodeData* Alloc();
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	SDK2024_CopyToOverride;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;

	[[nodiscard]] const maxon::HashMap<String, Int32>& GetMeshMorphData() const;
	[[nodiscard]] const maxon::HashSet<String>& GetUVMorphNames() const;
	Bool SetMorphStrength(const String& morph_name, const Float& strength);
	void RequestMorphDataRefresh();
	Bool LoadPMX(
		const libmmd::PMXFile& pmx_file,
		const maxon::BaseArray<BaseObject*>& bone_list,
		const CMTToolsSetting::ModelImport& setting);
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting);
private:
	void RefreshMeshMorphData(BaseObject* op, bool suppress_change_message = false);
};
