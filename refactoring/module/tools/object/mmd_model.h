/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.cpp
Description:	MMD model object 

**************************************************************************/

#pragma once

#include "CMTSceneManager.h"

class MMDModelObject;
class PMXModel;
class IMorph;

enum class MorphType : uint8_t
{
	DEFAULT,
	GROUP,
	FLIP,
	MESH,
	BONE
};


class EditorSubMorphDialog : public GeDialog
{
	MMDModelObject* m_model = nullptr;
	IMorph* m_morph = nullptr;
	std::unique_ptr<ImagesUserArea> m_images = nullptr;
	SimpleListView m_listview;
	maxon::HashSet<Int32> m_delete_button_id_set;
	Int32 m_id = 20000;
	Bool CreateLayout() override;
	Bool InitValues()override;
	Bool Command(Int32 id, const BaseContainer& msg) override;
public:
	EditorSubMorphDialog(MMDModelObject* model, IMorph* morph) : m_model(model), m_morph(morph) {}
	~EditorSubMorphDialog() override = default;
};


class IMorph {
protected:
	DescID m_strength_id;
	String m_name;
	MorphType m_type = MorphType::DEFAULT;
public:
	virtual ~IMorph() = default;
	explicit IMorph(const MorphType& type_) : m_type(type_) {}

	IMorph(DescID strength_id_ = DescID(), String name_ = String(), const MorphType& type_) :
		m_strength_id(std::move(strength_id_)), m_name(std::move(name_)), m_type(type_) {}

	IMorph(const IMorph&) = delete;
	IMorph(IMorph&& other) noexcept :
		m_strength_id(std::move(other.m_strength_id)),
		m_name(std::move(other.m_name)),
		m_type(other.m_type) {}

	const String& GetName() const { return m_name; }
	Float GetStrength(GeListNode* node) const;
	Bool SetStrength(GeListNode* node, const Float& strength) const;
	Bool IsGroupMorph() const { return m_type == MorphType::GROUP; }
	Bool IsFlipMorph() const { return m_type == MorphType::FLIP; }
	Bool IsMeshMorph() const { return m_type == MorphType::MESH; }
	Bool IsBoneMorph() const { return m_type == MorphType::BONE; }
	MorphType GetType() const { return m_type; }
	DescID GetStrengthDescID() { return m_strength_id; }
	bool operator==(const IMorph& other) const { return m_name == other.m_name; }
	virtual void RenameMorph(MMDModelObject* model, const String& name);
	virtual void UpdateMorphOfModel(MMDModelObject* model) = 0;
	virtual Int32 AddMorphToModel(MMDModelObject* model, String morph_name = String()) = 0;
	virtual void DeleteMorphOfModel(MMDModelObject* model) = 0;
	virtual void AddSubMorph(MMDModelObject* model, Int32 id, Float weight) {}
	virtual void AddSubMorphNoCheck(Int32 id, Float weight) {}
	virtual void DeleteSubMorph(const Int32 id) {}
	virtual void RenameSubMorph(const String& old_name, const String& new_name) {}
	virtual maxon::HashMap<Int32, Float>* GetSubMorphDataWritable() { return nullptr; }
	virtual Bool Read(HyperFile* hf);
	virtual Bool Write(HyperFile* hf) const;
	virtual Bool CopyTo(IMorph* dest) const;
};
class GroupMorph final : public IMorph
{
	DescID m_grp_id = DescID();
	DescID m_button_grp_id = DescID();
	DescID m_button_editor_id = DescID();
	DescID m_button_delete_id = DescID();
	DescID m_button_rename_id = DescID();

	maxon::HashMap<Int32, Float> m_data;
public:
	~GroupMorph() override = default;
	GroupMorph() : IMorph(MorphType::GROUP) {}
	GroupMorph(const GroupMorph&) = delete;
	GroupMorph(DescID grp_id_,
	           const DescID& strength_id_,
	           DescID button_grp_id_,
	           DescID button_editor_id_,
	           DescID button_delete_id_,
	           DescID button_rename_id_,
	           const String& name_) :
		IMorph(strength_id_, name_, MorphType::GROUP),
		m_grp_id(std::move(grp_id_)),
		m_button_grp_id(std::move(button_grp_id_)),
		m_button_editor_id(std::move(button_editor_id_)),
		m_button_delete_id(std::move(button_delete_id_)),
		m_button_rename_id(std::move(button_rename_id_)) {}
	GroupMorph(GroupMorph&& other) noexcept :
		IMorph(std::move(other)),
		m_grp_id(std::move(other.m_grp_id)),
		m_button_grp_id(std::move(other.m_button_grp_id)),
		m_button_delete_id(std::move(other.m_button_delete_id)),
		m_button_rename_id(std::move(other.m_button_rename_id)),
		m_data(std::move(other.m_data)) {}

	void UpdateMorphOfModel(MMDModelObject* model) override;
	Int32 AddMorphToModel(MMDModelObject* model, String morph_name = String()) override;
	void DeleteMorphOfModel(MMDModelObject* model) override;
	void RenameMorph(MMDModelObject* model, const String& name) override;
	void AddSubMorph(MMDModelObject* model, Int32 id, Float weight) override;
	void AddSubMorphNoCheck(Int32 id, Float weight) override;
	void DeleteSubMorph(const Int32 id) override { m_data.Erase(id); }
	void RenameSubMorph(const String& old_name, const String& new_name) override;
	Bool Read(HyperFile* hf) override;
	Bool Write(HyperFile* hf) const override;
	Bool CopyTo(IMorph* dest) const override;
	maxon::HashMap<Int32, Float>* GetSubMorphDataWritable() override { return &m_data; }
};
class FlipMorph final : public IMorph
{
	DescID m_grp_id = DescID();
	DescID m_button_grp_id = DescID();
	DescID m_button_editor_id = DescID();
	DescID m_button_delete_id = DescID();
	DescID m_button_rename_id = DescID();
	maxon::HashMap<Int32, Float> m_data;
public:
	~FlipMorph() override = default;
	FlipMorph(const FlipMorph&) = delete;
	FlipMorph() : IMorph(MorphType::FLIP) {}
	FlipMorph(DescID grp_id_,
	          const DescID& strength_id_,
	          DescID button_grp_id_,
	          DescID button_editor_id_,
	          DescID button_delete_id_,
	          DescID button_rename_id_,
	          const String& name_) :
		IMorph(strength_id_, name_, MorphType::FLIP),
		m_grp_id(std::move(grp_id_)),
		m_button_grp_id(std::move(button_grp_id_)),
		m_button_editor_id(std::move(button_editor_id_)),
		m_button_delete_id(std::move(button_delete_id_)),
		m_button_rename_id(std::move(button_rename_id_)) {}
	FlipMorph(FlipMorph&& other) noexcept :
		IMorph(std::move(other)),
		m_grp_id(std::move(other.m_grp_id)),
		m_button_grp_id(std::move(other.m_button_grp_id)),
		m_button_delete_id(std::move(other.m_button_delete_id)),
		m_button_rename_id(std::move(other.m_button_rename_id)),
		m_data(std::move(other.m_data)) {}

	void UpdateMorphOfModel(MMDModelObject* model) override;
	Int32 AddMorphToModel(MMDModelObject* model, String morph_name = String()) override;
	void DeleteMorphOfModel(MMDModelObject* model) override;
	void RenameMorph(MMDModelObject* model, const String& name) override;
	void AddSubMorph(MMDModelObject* model, Int32 id, Float weight) override;
	void AddSubMorphNoCheck(Int32 id, Float weight) override;
	void DeleteSubMorph(const Int32 id) override { m_data.Erase(id); }
	void RenameSubMorph(const String& old_name, const String& new_name) override;
	Bool Read(HyperFile* hf) override;
	Bool Write(HyperFile* hf) const override;
	Bool CopyTo(IMorph* dest) const override;
	maxon::HashMap<Int32, Float>* GetSubMorphDataWritable() override { return &m_data; }
};
class MeshMorph final : public IMorph
{
public:
	MeshMorph() : IMorph(MorphType::MESH) {}
	MeshMorph(const DescID& strength_id_, const String& name_) :
		IMorph(strength_id_, name_, MorphType::MESH) {}
	~MeshMorph() override = default;
	void UpdateMorphOfModel(MMDModelObject* model) override;
	Int32 AddMorphToModel(MMDModelObject* model, String morph_name = String()) override;
	void DeleteMorphOfModel(MMDModelObject* model) override;
};
class BoneMorph final : public IMorph
{
public:
	BoneMorph() : IMorph(MorphType::BONE) {}
	BoneMorph(const DescID& strength_id_, const String& name_) :
		IMorph(strength_id_, name_, MorphType::BONE) {}
	~BoneMorph() override = default;
	void UpdateMorphOfModel(MMDModelObject* model) override;
	Int32 AddMorphToModel(MMDModelObject* model, String morph_name = String()) override;
	void DeleteMorphOfModel(MMDModelObject* model) override;
};
enum class ToolObjectType
{
	DEFAULT,
	MeshRoot,
	BoneRoot,
	RigidRoot,
	JointRoot,
	Model
};
enum class MMDModelObjectMsgType
{
	DEFAULT,
	TOOL_OBJECT_UPDATA
};
struct MMDModelObjectMsg
{
	MMDModelObjectMsgType msg_type;
	ToolObjectType	object_type;
	BaseObject* object;

	explicit MMDModelObjectMsg(const MMDModelObjectMsgType msg_type_ = MMDModelObjectMsgType::DEFAULT,
	                            const ToolObjectType object_type_ = ToolObjectType::DEFAULT, BaseObject* object_ = nullptr)
		:msg_type(msg_type_), object_type(object_type_), object(object_) {}
};

enum class DescType : uint8_t
{
	REAL_STRENGTH,
	BUTTON_EDITOR,
	BUTTON_DELETE,
	BUTTON_RENAME
};

class MMDModelObject final : public ObjectData
{
	maxon::Synchronized<Bool> m_is_need_update;
	maxon::Synchronized<Bool> m_is_morph_initialized;
	Bool m_is_root_initialized = false;
	Int32 m_morph_named_number = 0;
	BaseObject* m_MeshRoot_ptr = nullptr;
	BaseObject* m_BoneRoot_ptr = nullptr;
	BaseObject* m_RigidRoot_ptr = nullptr;
	BaseObject* m_JointRoot_ptr = nullptr;
	maxon::HashMap<DescID, maxon::Pair<DescType, Int32>> m_DescID_map;
	maxon::HashMap<String, Int32> m_morph_name_map;
	maxon::PointerArray<IMorph> m_morph_arr;
private:
	MMDModelObject()
	{
		*m_is_need_update.Write() = true;
		*m_is_morph_initialized.Write() = false;
	}
	void RefreshMorph();
	MAXON_DISALLOW_COPY_AND_ASSIGN(MMDModelObject)
		INSTANCEOF(OMMDModel, ObjectData)
public:
	class AddMorphHelper
	{
		MMDModelObject* m_model = nullptr;
		CMT_DISALLOW_COPY_AND_ASSIGN_BODY(AddMorphHelper)
		CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(AddMorphHelper)
	public:
		explicit AddMorphHelper(MMDModelObject* model);
		~AddMorphHelper();
	};
public:
	~MMDModelObject() override = default;
	Bool Init(GeListNode* node SDK2024_InitPara) override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;


	Bool ReadMorph(HyperFile* hf);
	Bool WriteMorph(HyperFile* hf) const;
	Bool CopyMorph(MMDModelObject* dst) const;
	AddMorphHelper BeginMorphChange();
	Int32 ImportGroupAndFlipMorph(const PMXModel* pmx_model, libmmd::pmx_morph& pmx_morph);

	String GetMorphNamedNumber()
	{
		return String::IntToString(m_morph_named_number++);
	}
	const maxon::PointerArray<IMorph>& GetMorphData()
	{
		return m_morph_arr;
	}
	maxon::PointerArray<IMorph>& GetMorphDataWritable()
	{
		return m_morph_arr;
	}
	Int GetMorphNum() const
	{
		return m_morph_arr.GetCount();
	}
	const maxon::HashMap<String, Int32>& GetMorphNameMap()
	{
		return m_morph_name_map;
	}
	maxon::HashMap<String, Int32>& GetMorphNameMapWritable()
	{
		return m_morph_name_map;
	}
	maxon::HashMap<DescID, maxon::Pair<DescType, Int32>>& GetDescIDMap()
	{
		return m_DescID_map;
	}

	Bool UpdateRoot(BaseObject* op = nullptr);
	Bool CreateRoot();
	BaseObject* GetRootObject(const ToolObjectType type_) const
	{
		switch (type_)
		{
		case ToolObjectType::MeshRoot:
			return this->m_MeshRoot_ptr;
		case ToolObjectType::BoneRoot:
			return this->m_BoneRoot_ptr;
		case ToolObjectType::RigidRoot:
			return this->m_RigidRoot_ptr;
		case ToolObjectType::JointRoot:
			return this->m_JointRoot_ptr;

		case ToolObjectType::DEFAULT:
		case ToolObjectType::Model:;
		}
		return nullptr;
	}

	static NodeData* Alloc()
	{
		return NewObjClear(MMDModelObject);
	}
};
