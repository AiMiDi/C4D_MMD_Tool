#pragma once
#include "Utility.h"
#include "TMMDBone.h"
#include "description/OMMDModel.h"

namespace tool {
	class OMMDModel;
	enum class MorphType
	{
		DEFAULT,
		GROUP,
		FLIP,
		MESH,
		BONE
	};
	class IMorph {
	protected:
		DescID m_grp_id;
		DescID m_strength_id;
		String m_name = String();
		MorphType m_type = MorphType::DEFAULT;
	public:
		virtual ~IMorph() {}
		IMorph(const IMorph&) = delete;
		IMorph(DescID grp_id_,
			DescID strength_id_,
			String name_, 
			MorphType type_):
			m_grp_id(grp_id_),
			m_strength_id(strength_id_),
			m_name(name_),
			m_type(type_){}	
		IMorph(IMorph&& other) noexcept :
			m_grp_id(std::move(other.m_grp_id)),
			m_strength_id(std::move(other.m_strength_id)),
			m_name(std::move(other.m_name)),
			m_type(std::move(other.m_type)) {}
		void SetName(const String& name) { m_name = name; }
		Float GetStrength(GeListNode* node) 
		{
			GeData ge_data;
			if (node->GetParameter(m_strength_id, ge_data, DESCFLAGS_GET::NONE) == false) {
				return 0.0;
			}
			else {
				return ge_data.GetFloat();
			}
		}
		Bool SetStrength(GeListNode* node,const Float& strength)
		{
			return node->SetParameter(m_strength_id, strength, DESCFLAGS_SET::NONE);
		}
		virtual void MorphUpdata(OMMDModel* model) = 0;
		//virtual void AddMorph(OMMDModel* model, const String& name) = 0;
	};
	class GroupMorph : public IMorph
	{
		DescID m_button_grp_id;
		DescID m_button_editor_id;
		DescID m_button_delete_id;
		DescID m_button_rename_id;
		DescID m_power_id;
		
		maxon::BaseArray<String> m_data;
	public:
		~GroupMorph() {}
		GroupMorph(const GroupMorph&) = delete;
		GroupMorph(DescID grp_id_,
			DescID strength_id_,
			DescID button_grp_id_,
			DescID button_editor_id_,
			DescID button_delete_id_,
			DescID button_rename_id_,
			DescID power_id_,
			String name_):
			IMorph(grp_id_, strength_id_, name_, MorphType::GROUP),
			m_button_grp_id(button_grp_id_),
			m_button_editor_id(button_editor_id_),
			m_button_delete_id(button_delete_id_),
			m_button_rename_id(button_rename_id_),
			m_power_id(power_id_){}
		GroupMorph(GroupMorph&& other) noexcept:
			IMorph(std::move(other)),
			m_button_grp_id(std::move(other.m_button_grp_id)),
			m_button_delete_id(std::move(other.m_button_delete_id)),
			m_button_rename_id(std::move(other.m_button_rename_id)),
			m_power_id(other.m_power_id), m_data(std::move(other.m_data)){}
		virtual void MorphUpdata(OMMDModel* model);
	};
	class FlipMorph : public IMorph
	{
		DescID m_button_grp_id;
		DescID m_button_editor_id;
		DescID m_button_delete_id;
		DescID m_button_rename_id;
		DescID m_power_id;

		maxon::BaseArray<String> m_data;
	public:
		~FlipMorph() {}
		FlipMorph(const FlipMorph&) = delete;
		FlipMorph(DescID grp_id_,
			DescID strength_id_,
			DescID button_grp_id_,
			DescID button_editor_id_,
			DescID button_delete_id_,
			DescID button_rename_id_,
			DescID power_id_,
			String name_) :
			IMorph(grp_id_, strength_id_, name_, MorphType::FLIP),
			m_button_grp_id(button_grp_id_),
			m_button_editor_id(button_editor_id_),
			m_button_delete_id(button_delete_id_),
			m_button_rename_id(button_rename_id_),
			m_power_id(power_id_) {}
		FlipMorph(FlipMorph&& other) noexcept :
			IMorph(std::move(other)),
			m_button_grp_id(std::move(other.m_button_grp_id)),
			m_button_delete_id(std::move(other.m_button_delete_id)),
			m_button_rename_id(std::move(other.m_button_rename_id)),
			m_power_id(other.m_power_id), m_data(std::move(other.m_data)) {}
		virtual void MorphUpdata(OMMDModel* model);
	};
	class MeshMorph : public IMorph
	{
	public:
		MeshMorph(DescID grp_id_,
			DescID strength_id_,
			String name_):
			IMorph(grp_id_, strength_id_, name_, MorphType::MESH) {}
		~MeshMorph() {}
		virtual void MorphUpdata(OMMDModel* model);
	};
	class BoneMorph : public IMorph
	{
	public:
		BoneMorph(DescID grp_id_,
			DescID strength_id_,
			String name_):
			IMorph(grp_id_, strength_id_, name_, MorphType::BONE) {}
		~BoneMorph() {}
		virtual void MorphUpdata(OMMDModel* model);
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
		friend class GroupMorph;
		friend class FlipMorph;
		friend class MeshMorph;
		friend class BoneMorph;
		Bool m_initializ = false;
		BaseObject* m_MeshRoot_ptr = nullptr;
		BaseObject* m_BoneRoot_ptr = nullptr;
		BaseObject* m_RigidRoot_ptr = nullptr;
		BaseObject* m_JointRoot_ptr = nullptr;
		maxon::HashMap<String, IMorph*> m_morph_map;
		OMMDModel() {}
		~OMMDModel() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDModel);
		INSTANCEOF(OMMDModel, ObjectData)
	public:
		Bool Init(GeListNode* node) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(GeListNode* node, HyperFile* hf) override;
		Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override;
		Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags) override;
		/* 实时调用 */
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		/* 将实时调用添加入优先级列表 */
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		//maxon::HashMap<String, IMorph>& GetMorphMap() { return m_morph_map; }
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
