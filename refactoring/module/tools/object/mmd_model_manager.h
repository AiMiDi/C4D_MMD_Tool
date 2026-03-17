/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.cpp
Description:	MMD model object

**************************************************************************/

#pragma once

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
enum class MMDMorphType : uint8_t;

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
	MODEL_MODE_CHANGE
};

struct MMDModelManagerObjectMsg
{
	MMDModelManagerObjectMsgType msg_type;
	BaseObject* object;
	Int32	model_mode;

	explicit MMDModelManagerObjectMsg(const MMDModelManagerObjectMsgType msg_type_ = MMDModelManagerObjectMsgType::DEFAULT, BaseObject* object_ = nullptr, const Int32 model_mode_ = MODEL_MODE_ANIM)
		:msg_type(msg_type_), object(object_), model_mode(model_mode_) {}
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
	maxon::BaseArray<std::pair<String, std::unique_ptr<libmmd::VMDAnimation>>> animations_;
	maxon::BaseArray<std::pair<String, std::vector<uint8_t>>> pending_vmd_data_;

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

	MMDModelPtr mmd_model_;
	Int32 model_mode_ = MODEL_MODE_ANIM;
	BaseTime prev_time_{-1};
	Float32 fps_{ 30.f };
	Bool is_animation_initialized_{ false };
	maxon::Synchronized<Bool> is_runtime_initialized_;

	MMDModelManagerObject();
	friend MMDModelManagerObject;

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
	Bool GetDParameter(const GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags) const override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	SDK2024_GetDEnablingOverride;

	AddMorphHelper BeginMorphChange();
	Int ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph, Int32 panel = 0);

	DescID AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index);
	void DeleteDynamicDescription(const DescID& id);

	Int GetMorphNum() const;
	const maxon::PointerArray<IMorph>& GetMorphData();
	const maxon::HashMap<String, Int>& GetMorphNameMap();

	void SetMMDModel(const MMDModelPtr& model);
	Bool CreateManagers();
	Bool UpdateManagers(BaseObject* op = nullptr);
	BaseObject* GetMeshManagerObject() const { return mesh_manager_ ? static_cast<BaseObject*>(mesh_manager_->ForceGetLink()) : nullptr; }
	BaseObject* GetBoneManagerObject() const { return bone_manager_ ? static_cast<BaseObject*>(bone_manager_->ForceGetLink()) : nullptr; }

	MMDBoneManagerObject* GetBoneManagerData();
	MMDMeshManagerObject* GetMeshManagerData();
	MMDRigidManagerObject* GetRigidManagerData();
	MMDJointManagerObject* GetJointManagerData();

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting);
	void ImportDisplayFrames(const libmmd::PMXFile& pmx_file);
	void RebuildDisplayFrameUI();
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting) const;

	Bool AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material,
	                 BaseObject* mesh_object, const String& selection_name,
	                 const maxon::BaseArray<Filename>& texture_paths);

	Bool LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log, const Bool merge = false);
	Bool SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const;

private:
	Int32 GetMorphNamedNumber();
	bool DeleteMorphImpl(IMorph& morph, const Int morph_index);
	Int AddMorph(const MMDMorphType& morph_type, String morph_name = {}, bool is_add_morph_ui = true, Int32 panel = 0);
	void RenameMorph(const String& name);
	void UpdateMorph(IMorph& morph);
	void DeleteMorph(Int morph_index);
	void DeleteMorph(maxon::EraseIterator<maxon::PointerArray<IMorph>, false>& it);
	void RefreshMorph();
	Bool ReadMorph(HyperFile* hf);
#if API_VERSION < 2024000
	Bool WriteMorph(HyperFile* hf);
#else
	Bool WriteMorph(HyperFile* hf) const;
#endif
	Bool CopyMorph(MMDModelManagerObject* dst) const;
	//Bool SetMeshMorphAnimation(const libmmd::vmd_morph_key_frame& data, const CMTToolsSetting::MotionImport& setting);
	//Bool SetModelControllerAnimation(const libmmd::vmd_model_controller_key_frame& data, const CMTToolsSetting::MotionImport& setting);
	Bool DeleteVMDAnimation();
	Bool RebuildRuntime();
	void BuildIKSolverUI();
	void ApplyIKSolverStates();
	void ImportVMDIKKeyframes(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting);
	void SyncSubManagerScale(Float pm);
	void SyncMaterialsList();
	void PruneDeletedMaterialEntries(BaseDocument* doc);
};
