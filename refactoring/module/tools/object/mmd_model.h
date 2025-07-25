/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.cpp
Description:	MMD model object

**************************************************************************/

#ifndef MMD_MODEL_H__
#define MMD_MODEL_H__

#include "CMTSceneManager.h"
#include "description/OMMDModelManager.h"

class IMorph;
enum class MMDMorphType : uint8_t;
class MMDModelManagerObject;

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
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(EditorSubMorphDialog)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(EditorSubMorphDialog)
};

enum class ManagerObjectType : uint8_t
{
	DEFAULT,
	MESH_MANAGER,
	BONE_MANAGER,
	RIGID_MANAGER,
	JOINT_MANAGER,
	MODEL_MANAGER
};

enum class MMDModelRootObjectMsgType : uint8_t
{
	DEFAULT,
	MANAGER_OBJECT_UPDATE,
	MODEL_MODE_CHANGE
};

struct MMDModelRootObjectMsg
{
	MMDModelRootObjectMsgType msg_type;
	ManagerObjectType	object_type;
	BaseObject* object;
	Int32	model_mode;

	explicit MMDModelRootObjectMsg(const MMDModelRootObjectMsgType msg_type_ = MMDModelRootObjectMsgType::DEFAULT,
	                            const ManagerObjectType object_type_ = ManagerObjectType::DEFAULT, BaseObject* object_ = nullptr,const Int32 model_mode_ = MODEL_MODE_ANIM)
		:msg_type(msg_type_), object_type(object_type_), object(object_), model_mode(model_mode_) {}
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
	maxon::Synchronized<Bool> m_is_need_update;
	maxon::Synchronized<Bool> m_is_morph_initialized;
	maxon::Synchronized<Bool> is_manager_read;
	maxon::Synchronized<Bool> m_is_ik_map_read;
	Bool m_is_root_initialized = false;
	Int32 m_morph_named_number = 0;
	BaseObject* mesh_manager = nullptr;
	BaseObject* bone_manager = nullptr;
	BaseObject* rigid_manager = nullptr;
	BaseObject* joint_manager = nullptr;
	BaseLink* mesh_manager_link = nullptr;
	BaseLink* bone_manager_link = nullptr;
	BaseLink* rigid_manager_link = nullptr;
	BaseLink* joint_manager_link = nullptr;
	maxon::PointerArray<IMorph> m_morph_arr;
	maxon::HashMap<DescID, maxon::Pair<MMDModelRootDynamicDescriptionType, Int>> m_desc_id_map;
	maxon::HashMap<String, Int> m_morph_name_map;
	maxon::HashMap<String, BaseTag*> m_ik_name_map;
	maxon::HashMap<String, AutoAlloc<BaseLink>> m_ik_link_name_map;

	Int32 animation_index = -1;
	BaseContainer animation_items;
	maxon::BaseArray<std::pair<String, std::unique_ptr<libmmd::VMDAnimation>>> animations;

	MMDModelPtr m_model;
	Int32 model_mode = MODEL_MODE_ANIM;
	Float32 delta_time = 1.f / 30.f;
	BaseTime prev_time{-1};

	MMDModelManagerObject();
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDModelManagerObject)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDModelManagerObject)
	INSTANCEOF(MMDModelRootObject, ObjectData)
public:
	class AddMorphHelper
	{
		MMDModelManagerObject* m_model = nullptr;
		CMT_DISALLOW_COPY_AND_ASSIGN_BODY(AddMorphHelper)
		CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(AddMorphHelper)
	public:
		explicit AddMorphHelper(MMDModelManagerObject* model);
		~AddMorphHelper();
	};

	~MMDModelManagerObject() override = default;
	static NodeData* Alloc();
	Bool Init(GeListNode* node SDK2024_InitParaName) override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	AddMorphHelper BeginMorphChange();
	Int ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph);

	DescID AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index);
	void DeleteDynamicDescription(const DescID& id);
	Bool AddIKBoneDescription(const maxon::String& bone_name_local, BaseTag* ik_tag);

	Int GetMorphNum() const;
	const maxon::PointerArray<IMorph>& GetMorphData();
	const maxon::HashMap<String, Int>& GetMorphNameMap();

	Bool CreateRoot();
	Bool UpdateRoot(BaseObject* op = nullptr);
	BaseObject* GetRootObject(const ManagerObjectType type) const;

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting);
	Bool SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting) const;

	Bool LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log);
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
	Bool WriteMorph(HyperFile* hf) SDK2024_Const;
	Bool CopyMorph(MMDModelManagerObject* dst) const;
	//Bool SetMeshMorphAnimation(const libmmd::vmd_morph_key_frame& data, const CMTToolsSetting::MotionImport& setting);
	//Bool SetModelControllerAnimation(const libmmd::vmd_model_controller_key_frame& data, const CMTToolsSetting::MotionImport& setting);
	Bool DeleteAnimation();
};

#endif // !MMD_MODEL_H__
