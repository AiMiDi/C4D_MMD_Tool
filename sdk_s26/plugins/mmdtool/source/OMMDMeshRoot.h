#pragma once
#include "Utility.h"
#include "OMMDModel.h"

namespace tool {
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
		maxon::HashMap<BaseTag*, Int32> m_tag_mode_map;
		maxon::HashMap<String, maxon::BaseList<mesh_morph_hub_data>> m_MorphData_map;
		OMMDMeshRoot() {}
		~OMMDMeshRoot() override {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDMeshRoot)
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
		void RefreshMorphMap(BaseObject* op);
		maxon::HashMap<String, maxon::BaseList<mesh_morph_hub_data>>& GetMeshMorphMap() { return m_MorphData_map; }
	};
}