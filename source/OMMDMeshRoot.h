#pragma once
#include "Utility.h"
#include "OMMDModel.h"

namespace tool {
	struct mesh_morph_hub_data {
		CAPoseMorphTag* morph_tag = nullptr;
		DescID strength_id;

		Bool SetStrength(const Float& strength)
		{
			if (morph_tag->GetMode() == ID_CA_POSE_MODE_ANIMATE) {
				return morph_tag->SetParameter(strength_id, strength, DESCFLAGS_SET::NONE);
			}
			else
			{
				return false;
			}
		}
		Bool Write(HyperFile* hf)
		{
			AutoAlloc<BaseLink> morph_tag_link;
			if (morph_tag_link == nullptr)
				return false;
			morph_tag_link->SetLink(morph_tag);
			if (!morph_tag_link->Write(hf))
				return false;
			if (!strength_id.Write(hf))
				return false;
			return true;
		}

		Bool Read(HyperFile* hf)
		{
			AutoAlloc<BaseLink> morph_tag_link;
			if (morph_tag_link == nullptr)
				return false;
			if (!morph_tag_link->Read(hf))
				return false;
			morph_tag = static_cast<CAPoseMorphTag*>(morph_tag_link->ForceGetLink());
			if (!strength_id.Read(hf))
				return false;
			return true;
		}
	}; 
	enum class OMMDMeshRoot_MSG_Type
	{
		DEFAULT,
		MESH_MORPH_CHANGE
	};
	struct OMMDMeshRoot_MSG
	{
		OMMDMeshRoot_MSG_Type type = OMMDMeshRoot_MSG_Type::DEFAULT;
		OMMDMeshRoot_MSG(OMMDMeshRoot_MSG_Type type_ = OMMDMeshRoot_MSG_Type::DEFAULT) : type(type_) {}
	};
	class OMMDMeshRoot : public ObjectData
	{
		BaseTag* m_displayTag = nullptr;
		BaseObject* m_Model_ptr = nullptr;
		maxon::HashMap<String, maxon::BaseList<mesh_morph_hub_data>> m_MorphData_map;
		OMMDMeshRoot() {}
		~OMMDMeshRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDMeshRoot);
		INSTANCEOF(OMMDMeshRoot, ObjectData)
	public:
		Bool Init(GeListNode* node) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(GeListNode* node, HyperFile* hf) override;
		Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDMeshRoot));
		}
		maxon::HashMap<String, maxon::BaseList<mesh_morph_hub_data>>& GetMeshMorphMap() { return m_MorphData_map; }
	};
}