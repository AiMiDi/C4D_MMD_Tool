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

enum class MMDModelRootDynamicDescriptionType : uint8_t
{
	MORPH_GRP,
	MORPH_STRENGTH,
	MORPH_EDITOR_BUTTON,
	MORPH_DELETE_BUTTON,
	MORPH_RENAME_BUTTON,
	IK_BONE_LINK
};

class MMDModelManagerObject final : public ObjectData
{
	maxon::Synchronized<Bool> update_morph_;
	maxon::Synchronized<Bool> is_morph_initialized_;
	maxon::Synchronized<Bool> is_manager_read_;
	Int32 morph_named_number_ = 0;
	BaseObject* mesh_manager_ = nullptr;
	BaseObject* bone_manager_ = nullptr;
	BaseObject* rigid_manager_ = nullptr;
	BaseObject* joint_manager_ = nullptr;
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

	MMDModelPtr mmd_model_;
	Int32 model_mode_ = MODEL_MODE_ANIM;
	BaseTime prev_time_{-1};
	Float32 fps_{ 1.f / 30.f };

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
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	AddMorphHelper BeginMorphChange();
	Int ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph);

	DescID AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index);
	void DeleteDynamicDescription(const DescID& id);

	Int GetMorphNum() const;
	const maxon::PointerArray<IMorph>& GetMorphData();
	const maxon::HashMap<String, Int>& GetMorphNameMap();

	void SetMMDModel(const MMDModelPtr& model);
	Bool CreateManagers();
	Bool UpdateManagers(BaseObject* op = nullptr);
	BaseObject* GetMeshManagerObject() const { return mesh_manager_; }

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting);
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting) const;

	Bool LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log, const Bool merge = false);
	Bool SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const;

private:
	Int32 GetMorphNamedNumber();
	bool DeleteMorphImpl(IMorph& morph, const Int morph_index);
	Int AddMorph(const MMDMorphType& morph_type, String morph_name = {}, bool is_add_morph_ui = true);
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
};
