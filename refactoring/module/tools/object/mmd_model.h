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

class MMDModelRootObject;
class PMXModel;
class IMorph;

class EditorSubMorphDialog final : public GeDialog
{
	MMDModelRootObject* m_model = nullptr;
	IMorph* m_morph = nullptr;
	std::unique_ptr<ImagesUserArea> m_images = nullptr;
	SimpleListView m_listview;
	maxon::HashSet<Int32> m_delete_button_id_set;
	Int32 m_id = 20000;
	Bool CreateLayout() override;
	Bool InitValues()override;
	Bool Command(Int32 id, const BaseContainer& msg) override;
public:
	EditorSubMorphDialog(MMDModelRootObject* model, IMorph* morph) : m_model(model), m_morph(morph) {}
	~EditorSubMorphDialog() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(EditorSubMorphDialog)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(EditorSubMorphDialog)
};

enum class MMDMorphType : uint8_t
{
	DEFAULT = 0,
	GROUP = 1,
	FLIP = 1 << 1,
	MESH = 1 << 2,
	BONE = 1 << 3
};

class IMorph
{
protected:
	String m_name;
	DescID m_strength_id;
public:
	explicit IMorph(String name = {}, DescID strength_id = {});
	IMorph(const IMorph&) = delete;
	IMorph(IMorph&& other) noexcept;
	virtual ~IMorph() = default;

	IMorph& operator=(const IMorph&) = delete;
	IMorph& operator=(IMorph&& other) noexcept = default;

	[[nodiscard]] const String& GetName() const { return m_name; }
	Float GetStrength(SDK2024_Const GeListNode* node) const;
	Bool SetStrength(GeListNode* node, const Float& strength) const;
	DescID GetStrengthDescID();
	bool operator==(const IMorph& other) const;
	virtual MMDMorphType GetType() const = 0;
	virtual void AddMorphUI(MMDModelRootObject& model, Int morph_id) = 0;
	virtual void DeleteMorphUI(MMDModelRootObject& model) = 0;
	void RenameMorph(const String& name);
	virtual void UpdateMorph(MMDModelRootObject& model) = 0;
	virtual void AddSubMorph(MMDModelRootObject* model, Int id, Float weight) {}
	virtual void AddSubMorphNoCheck(Int id, Float weight) {}
	virtual void DeleteSubMorph(const Int id) {}
	virtual void RenameSubMorph(const Int old_id, const Int new_id) {}
	virtual maxon::HashMap<Int, Float>* GetSubMorphDataWritable() { return nullptr; }
	virtual Bool Read(HyperFile* hf);
	virtual Bool Write(HyperFile* hf) SDK2024_Const;
	virtual Bool CopyTo(IMorph* dest) const;
};
class GroupMorph final : public IMorph
{
	DescID m_grp_id;
	DescID m_button_grp_id;
	DescID m_button_editor_id;
	DescID m_button_delete_id;
	DescID m_button_rename_id;

	maxon::HashMap<Int, Float> m_data;
public:
	~GroupMorph() override = default;
	GroupMorph(const GroupMorph&) = delete;
	explicit GroupMorph(String name = {},
	                    DescID grp_id = {},
	                    DescID strength_id = {},
	                    DescID button_grp_id = {},
	                    DescID button_editor_id = {},
	                    DescID button_delete_id = {},
	                    DescID button_rename_id = {});
	GroupMorph(GroupMorph&& other) noexcept;

	GroupMorph& operator=(const GroupMorph&) = delete;
	GroupMorph& operator=(GroupMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelRootObject& model) override;
	void AddMorphUI(MMDModelRootObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelRootObject& model) override;
	void AddSubMorph(MMDModelRootObject* model, Int id, Float weight) override;
	void AddSubMorphNoCheck(Int id, Float weight) override;
	void DeleteSubMorph(const Int id) override { m_data.Erase(id); }
	void RenameSubMorph(const Int old_id, const Int new_id) override;
	Bool Read(HyperFile* hf) override;
	Bool Write(HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(IMorph* dest) const override;
	maxon::HashMap<Int, Float>* GetSubMorphDataWritable() override { return &m_data; }
	MMDMorphType GetType() const override { return MMDMorphType::GROUP; }
};
class FlipMorph final : public IMorph
{
	DescID m_grp_id;
	DescID m_button_grp_id;
	DescID m_button_editor_id;
	DescID m_button_delete_id;
	DescID m_button_rename_id;
	maxon::HashMap<Int, Float> m_data;
public:
	~FlipMorph() override = default;
	FlipMorph(const FlipMorph&) = delete;
	explicit FlipMorph(String name = {},
	                   DescID strength_id = {},
	                   DescID grp_id = {},
	                   DescID button_grp_id = {},
	                   DescID button_editor_id = {},
	                   DescID button_delete_id = {},
	                   DescID button_rename_id = {});
	FlipMorph(FlipMorph&& other) noexcept;

	FlipMorph& operator=(const FlipMorph&) = delete;
	FlipMorph& operator=(FlipMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelRootObject& model) override;
	void AddMorphUI(MMDModelRootObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelRootObject& model) override;
	void AddSubMorph(MMDModelRootObject* model, Int id, Float weight) override;
	void AddSubMorphNoCheck(Int id, Float weight) override;
	void DeleteSubMorph(const Int id) override { m_data.Erase(id); }
	void RenameSubMorph(const Int old_id, const Int new_id) override;
	Bool Read(HyperFile* hf) override;
	Bool Write(HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(IMorph* dest) const override;
	maxon::HashMap<Int, Float>* GetSubMorphDataWritable() override { return &m_data; }
	MMDMorphType GetType() const override { return MMDMorphType::FLIP; }
};
class MeshMorph final : public IMorph
{
public:
	explicit MeshMorph(String name = {}, DescID strength_id = {});
	MeshMorph(const MeshMorph&) = delete;
	MeshMorph(MeshMorph&& other) noexcept;
	~MeshMorph() override = default;

	MeshMorph& operator=(const MeshMorph&) = delete;
	MeshMorph& operator=(MeshMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelRootObject& model) override;
	void AddMorphUI(MMDModelRootObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelRootObject& model) override;
	MMDMorphType GetType() const override { return MMDMorphType::MESH; }
};
class BoneMorph final : public IMorph
{
public:
	explicit BoneMorph(String name = {}, DescID strength_id = {});
	BoneMorph(const BoneMorph&) = delete;
	BoneMorph(BoneMorph&& other) noexcept;
	~BoneMorph() override = default;

	BoneMorph& operator=(const BoneMorph&) = delete;
	BoneMorph& operator=(BoneMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelRootObject& model) override;
	void AddMorphUI(MMDModelRootObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelRootObject& model) override;
	MMDMorphType GetType() const override { return MMDMorphType::BONE; }
};
enum class CMTObjectType
{
	DEFAULT,
	MeshRoot,
	BoneRoot,
	RigidRoot,
	JointRoot,
	ModelRoot
};
enum class MMDModelRootObjectMsgType
{
	DEFAULT,
	TOOL_OBJECT_UPDATE
};
struct MMDModelRootObjectMsg
{
	MMDModelRootObjectMsgType msg_type;
	CMTObjectType	object_type;
	BaseObject* object;

	explicit MMDModelRootObjectMsg(const MMDModelRootObjectMsgType msg_type_ = MMDModelRootObjectMsgType::DEFAULT,
	                            const CMTObjectType object_type_ = CMTObjectType::DEFAULT, BaseObject* object_ = nullptr)
		:msg_type(msg_type_), object_type(object_type_), object(object_) {}
};

enum class MMDModelRootDynamicDescriptionType : uint8_t
{
	MORPH_GRP,
	MORPH_STRENGTH,
	MORPH_EDITOR_BUTTON,
	MORPH_DELETE_BUTTON,
	MORPH_RENAME_BUTTON,
	IK_BOME_LINK
};

class MMDModelRootObject final : public ObjectData
{
	maxon::Synchronized<Bool> m_is_need_update;
	maxon::Synchronized<Bool> m_is_morph_initialized;
	Bool m_is_root_initialized = false;
	Int32 m_morph_named_number = 0;
	BaseObject* m_mesh_root = nullptr;
	BaseObject* m_bone_root = nullptr;
	BaseObject* m_rigid_root = nullptr;
	BaseObject* m_joint_root = nullptr;
	maxon::HashMap<DescID, maxon::Pair<MMDModelRootDynamicDescriptionType, Int>> m_desc_id_map;
	maxon::HashMap<String, Int> m_morph_name_map;
	maxon::HashMap<String, BaseTag*> m_ik_name_map;
	maxon::PointerArray<IMorph> m_morph_arr;
private:
	MMDModelRootObject();
	void RefreshMorph();
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDModelRootObject)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDModelRootObject)
	INSTANCEOF(MMDModelRootObject, ObjectData)
public:
	class AddMorphHelper
	{
		MMDModelRootObject* m_model = nullptr;
		CMT_DISALLOW_COPY_AND_ASSIGN_BODY(AddMorphHelper)
		CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(AddMorphHelper)
	public:
		explicit AddMorphHelper(MMDModelRootObject* model);
		~AddMorphHelper();
	};

	~MMDModelRootObject() override = default;
	static NodeData* Alloc();
	Bool Init(GeListNode* node SDK2024_InitParaName) override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	AddMorphHelper BeginMorphChange();
	Int ImportGroupAndFlipMorph(const libmmd::pmx_morph& pmx_morph);

	DescID AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index);
	void DeleteDynamicDescription(const DescID& id);
	Bool AddIKBoneDescription(const maxon::String& bone_name_local, BaseTag* ik_tag);

	Int GetMorphNum() const;
	const maxon::PointerArray<IMorph>& GetMorphData();
	const maxon::HashMap<String, Int>& GetMorphNameMap();

	Bool CreateRoot();
	Bool UpdateRoot(BaseObject* op = nullptr);
	BaseObject* GetRootObject(const CMTObjectType type) const;

	Bool LoadPMXModel(const libmmd::pmx_model& pmx_model, const CMTToolsSetting::ModelImport& setting);
	Bool SavePMXModel(libmmd::pmx_model& pmx_model, const CMTToolsSetting::ModelExport& setting) const;

	Bool LoadVMDMotion(const libmmd::vmd_animation& vmd_motion, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log);
	Bool SaveVMDMotion(libmmd::vmd_animation& vmd_motion, const CMTToolsSetting::MotionExport& setting) const;

private:
	Int32 GetMorphNamedNumber();
	bool DeleteMorphImpl(IMorph& morph, const Int morph_index);
	Int AddMorph(const MMDMorphType& morph_type, String morph_name = {}, bool is_add_morph_ui = true);
	void RenameMorph(const String& name);
	void UpdateMorph(IMorph& morph);
	void DeleteMorph(Int morph_index);
	void DeleteMorph(maxon::EraseIterator<maxon::PointerArray<IMorph>, false>& it);
	Bool ReadMorph(HyperFile* hf);
	Bool WriteMorph(HyperFile* hf) SDK2024_Const;
	Bool CopyMorph(MMDModelRootObject* dst) const;
	Bool SetMeshMorphAnimation(const libmmd::vmd_morph_key_frame& data, const CMTToolsSetting::MotionImport& setting);
	Bool SetModelControllerAnimation(const libmmd::vmd_model_controller_key_frame& data, const CMTToolsSetting::MotionImport& setting);
	Bool DeleteAllMorphAnimation();
	Bool DeleteAllModelControllerAnimation();
};

#endif // !MMD_MODEL_H__
