#pragma once
#include "Utility.h"
#include "TMMDBone.h"
#include "description/OMMDModel.h"
#include "PMX.h"

namespace mmd {
	struct PMXMorphData;
}
namespace tool {
	class OMMDModel;
	class PMXModel;
	class IMorph;
	enum class MorphType
	{
		DEFAULT,
		GROUP,
		FLIP,
		MESH,
		BONE
	};


	class EditorSubMorphDialog : public GeDialog
	{
		OMMDModel* m_model = nullptr;
		IMorph* m_morph = nullptr;	
		ImagesGUI* m_images = nullptr;
		SimpleListView m_listview;
		maxon::HashSet<Int32> m_delete_button_id_set;
		Int32 m_id = 20000;
		Bool CreateLayout() override; 
		Bool InitValues()override;
		Bool Command(Int32 id, const BaseContainer& msg) override;
	public:
		EditorSubMorphDialog(OMMDModel* model, IMorph* morph) : m_model(model), m_morph(morph){}
		~EditorSubMorphDialog() { delete m_images; }
	};


	class IMorph {
	protected:
		DescID m_strength_id = DescID();
		String m_name = String();
		MorphType m_type = MorphType::DEFAULT;
	public:
		virtual ~IMorph() {}
		IMorph(const IMorph&) = delete;
		IMorph(const MorphType& type_): m_type(type_) {}
		IMorph(DescID strength_id_,String name_, const MorphType& type_):
			m_strength_id(strength_id_),m_name(name_),m_type(type_){}	
		IMorph(IMorph&& other) noexcept :
			m_strength_id(std::move(other.m_strength_id)),
			m_name(std::move(other.m_name)),
			m_type(std::move(other.m_type)) {}
		const String& GetName() const { return m_name; }
		Float GetStrength(GeListNode* node);
		Bool SetStrength(GeListNode* node, const Float& strength);
		Bool IsGroupMorph() { return m_type == MorphType::GROUP; }
		Bool IsFlipMorph() { return m_type == MorphType::FLIP; }
		Bool IsMeshMorph() { return m_type == MorphType::MESH; }
		Bool IsBoneMorph() { return m_type == MorphType::BONE; }
		MorphType& GetType() { return m_type; }
		DescID GetStrengthDescID() { return m_strength_id; }
		bool operator==(const IMorph& other) const { return m_name == other.m_name; }
		virtual void RenameMorph(OMMDModel* model, const String& name);
		virtual void UpdataMorphOfModel(OMMDModel* model) = 0;
		virtual Int32 AddMorphToModel(OMMDModel* model, String morph_name = String()) = 0;
		virtual void DeleteMorphOfModel(OMMDModel* model) = 0;
		virtual void AddSubMorph(OMMDModel* model, String name, Float influence) {};
		virtual void AddSubMorphNoCheck(OMMDModel* model, String name, Float influence) {};
		virtual void DeleteSubMorph(const String& name) {};
		virtual void RenameSubMorph(const String& old_name, const String& new_name) {};
		virtual maxon::HashMap<String, Float>* GetSubMorphData() { return nullptr; };
		virtual Bool Read(HyperFile* hf);
		virtual Bool Write(HyperFile* hf);
		virtual Bool CopyTo(IMorph* dest);
	};
	class GroupMorph : public IMorph
	{
		DescID m_grp_id = DescID();
		DescID m_button_grp_id = DescID();
		DescID m_button_editor_id = DescID();
		DescID m_button_delete_id = DescID();
		DescID m_button_rename_id = DescID();	

		maxon::HashMap<String, Float> m_data;	
	public:
		~GroupMorph() {}
		GroupMorph() : IMorph(MorphType::GROUP) {}
		GroupMorph(const GroupMorph&) = delete;
		GroupMorph(DescID grp_id_,
			DescID strength_id_,
			DescID button_grp_id_,
			DescID button_editor_id_,
			DescID button_delete_id_,
			DescID button_rename_id_ ,
			DescID power_id_,
			String name_):
			IMorph(strength_id_, name_, MorphType::GROUP),
			m_grp_id(grp_id_),
			m_button_grp_id(button_grp_id_),
			m_button_editor_id(button_editor_id_),
			m_button_delete_id(button_delete_id_),
			m_button_rename_id(button_rename_id_){}
		GroupMorph(GroupMorph&& other) noexcept:
			IMorph(std::move(other)),
			m_grp_id(std::move(other.m_grp_id)),
			m_button_grp_id(std::move(other.m_button_grp_id)),
			m_button_delete_id(std::move(other.m_button_delete_id)),
			m_button_rename_id(std::move(other.m_button_rename_id)),
			m_data(std::move(other.m_data)){}
		virtual void UpdataMorphOfModel(OMMDModel* model);
		virtual Int32 AddMorphToModel(OMMDModel* model, String morph_name = String());
		virtual void DeleteMorphOfModel(OMMDModel* model);
		void RenameMorph(OMMDModel* model, const String& name) override;
		void AddSubMorph(OMMDModel* model, String name, Float influence) override;
		void AddSubMorphNoCheck(OMMDModel* model, String name, Float influence) override;
		void DeleteSubMorph(const String& name) override { m_data.Erase(name); }
		void RenameSubMorph(const String& old_name, const String& new_name) override;
		Bool Read(HyperFile* hf) override;
		Bool Write(HyperFile* hf) override;
		Bool CopyTo(IMorph* dest) override;
		maxon::HashMap<String, Float>* GetSubMorphData() override { return &m_data; };
	};
	class FlipMorph : public IMorph
	{
		DescID m_grp_id = DescID();
		DescID m_button_grp_id = DescID();
		DescID m_button_editor_id = DescID();
		DescID m_button_delete_id = DescID();
		DescID m_button_rename_id = DescID();	
		maxon::HashMap<String, Float> m_data;		
	public:
		~FlipMorph() {}
		FlipMorph(const FlipMorph&) = delete;
		FlipMorph() : IMorph(MorphType::FLIP) {}
		FlipMorph(DescID grp_id_,
			DescID strength_id_,
			DescID button_grp_id_,
			DescID power_id_ ,
			DescID button_editor_id_,
			DescID button_delete_id_,
			DescID button_rename_id_,
			String name_) :
			IMorph(strength_id_, name_, MorphType::FLIP),
			m_grp_id(grp_id_),
			m_button_grp_id(button_grp_id_),
			m_button_editor_id(button_editor_id_),
			m_button_delete_id(button_delete_id_),
			m_button_rename_id(button_rename_id_){}
		FlipMorph(FlipMorph&& other) noexcept :
			IMorph(std::move(other)),
			m_grp_id(std::move(other.m_grp_id)),
			m_button_grp_id(std::move(other.m_button_grp_id)),
			m_button_delete_id(std::move(other.m_button_delete_id)),
			m_button_rename_id(std::move(other.m_button_rename_id)),
			m_data(std::move(other.m_data)) {}
		virtual void UpdataMorphOfModel(OMMDModel* model);
		virtual Int32 AddMorphToModel(OMMDModel* model, String morph_name = String());
		virtual void DeleteMorphOfModel(OMMDModel* model);
		void RenameMorph(OMMDModel* model, const String& name) override;
		void AddSubMorph(OMMDModel* model,String name, Float influence) override;
		void AddSubMorphNoCheck(OMMDModel* model, String name, Float influence) override;
		void DeleteSubMorph(const String& name) override { m_data.Erase(name); }
		void RenameSubMorph(const String& old_name, const String& new_name) override;
		Bool Read(HyperFile* hf) override;
		Bool Write(HyperFile* hf) override;
		Bool CopyTo(IMorph* dest) override;
		maxon::HashMap<String, Float>* GetSubMorphData() override { return &m_data; };
	};
	class MeshMorph : public IMorph
	{
	public:
		MeshMorph() : IMorph(MorphType::MESH) {}
		MeshMorph(DescID strength_id_,String name_):
			IMorph(strength_id_, name_, MorphType::MESH) {}
		~MeshMorph() {}
		virtual void UpdataMorphOfModel(OMMDModel* model);
		virtual Int32 AddMorphToModel(OMMDModel* model, String morph_name = String());
		virtual void DeleteMorphOfModel(OMMDModel* model);
	};
	class BoneMorph : public IMorph
	{
	public:
		BoneMorph() : IMorph(MorphType::BONE) {}
		BoneMorph(DescID strength_id_,String name_):
			IMorph(strength_id_, name_, MorphType::BONE) {}
		~BoneMorph() {}
		virtual void UpdataMorphOfModel(OMMDModel* model);
		virtual Int32 AddMorphToModel(OMMDModel* model, String morph_name = String());
		virtual void DeleteMorphOfModel(OMMDModel* model);
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
	enum class OMMDModel_MSG_Type
	{
		DEFAULT,
		TOOL_OBJECT_UPDATA
	}; 
	struct OMMDModel_MSG
	{
		OMMDModel_MSG_Type msg_type = OMMDModel_MSG_Type::DEFAULT;
		ToolObjectType	object_type = ToolObjectType::DEFAULT;
		BaseObject* object = nullptr;
		OMMDModel_MSG(OMMDModel_MSG_Type msg_type_ = OMMDModel_MSG_Type::DEFAULT,
			ToolObjectType object_type_ = ToolObjectType::DEFAULT, BaseObject* object_ = nullptr)
			:msg_type(msg_type_), object_type(object_type_), object(object_) {}
	};

	class OMMDModel : public ObjectData
	{
	private:	
		maxon::Synchronized<Bool> m_updateable;
		maxon::Synchronized<Bool> m_morph_initializ;
		Bool m_root_initializ = false;
		Int32 m_morph_named_number = 0;
		BaseObject* m_MeshRoot_ptr = nullptr;
		BaseObject* m_BoneRoot_ptr = nullptr;
		BaseObject* m_RigidRoot_ptr = nullptr;
		BaseObject* m_JointRoot_ptr = nullptr;
		maxon::HashMap<DescID, maxon::Pair<DescType, Int32>> m_DescID_map;
		maxon::HashMap<String, Int32> m_morph_name_map;
		maxon::PointerArray<IMorph> m_morph_arr;
	private:
		OMMDModel() 
		{ 
			*m_updateable.Write() = true;
			*m_morph_initializ.Write() = false;
		}
		void RefreshMorph();
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDModel);
		INSTANCEOF(OMMDModel, ObjectData)
	public:
		class AddMorphHelper
		{
			OMMDModel* m_model = nullptr;		
		public:
			AddMorphHelper(OMMDModel* model) :m_model(model)
			{
				*m_model->m_updateable.Write() = false;
				*m_model->m_morph_initializ.Write() = false;
			}
			~AddMorphHelper()
			{
				*m_model->m_updateable.Write() = true;
			}
		};
	public:
		~OMMDModel() {}
		Bool Init(GeListNode* node) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(GeListNode* node, HyperFile* hf) override;
		Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override;
		Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags) override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		/* 实时调用 */
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		/* 将实时调用添加入优先级列表 */
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;


		Bool ReadMorph(HyperFile* hf);
		Bool WriteMorph(HyperFile* hf);
		Bool CopyMorph(OMMDModel* dst);	
		AddMorphHelper BeginMorphChange()
		{
			return AddMorphHelper(this);
		}
		Int32 ImportGroupAndFlipMorph(PMXModel* pmx_model, mmd::PMXMorphData& pmx_morph);

		String GetMorphNamedNumber()
		{
			return String::IntToString(m_morph_named_number++);
		}
		maxon::PointerArray<IMorph>& GetMorphData()
		{
			return m_morph_arr;
		}
		maxon::HashMap<String, Int32>& GetMorphNameMap()
		{
			return m_morph_name_map;
		}
		maxon::HashMap<DescID, maxon::Pair<DescType, Int32>>& GetDescIDMap()
		{
			return m_DescID_map;
		}

		Bool UpdataRoot(BaseObject* op = nullptr);
		Bool CreateRoot();
		BaseObject* GetRootObject(ToolObjectType type_)
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
			default:
				return nullptr;
			}
		}

		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDModel));
		}
	};
}
