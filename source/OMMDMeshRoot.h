#pragma once
#include "Utility.h"
#include "OMMDModel.h"

namespace tool {
	struct mesh_morph_hub_data {
		CAPoseMorphTag* morph_tag = nullptr;
		DescID morph_strength_id;

		Bool SetStrength(const Float& strength)
		{
			return morph_tag->SetParameter(morph_strength_id, strength, DESCFLAGS_SET::NONE);
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
		friend class MeshMorph;
		BaseTag* m_displayTag = nullptr;
		BaseObject* m_Model_ptr = nullptr;
		maxon::HashMap<String, mesh_morph_hub_data> m_mesh_morph_map;
		OMMDMeshRoot() {}
		~OMMDMeshRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDMeshRoot);
		INSTANCEOF(OMMDMeshRoot, ObjectData)
	public:
		Bool Init(GeListNode* node) override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDMeshRoot));
		}
	};
}