#pragma once
#include "Utility.h"

namespace mmd {
	struct mesh_morph_hub_data {
		const CAPoseMorphTag* morph_tag = nullptr;
		const CAMorph* morph = nullptr;
	};
	class OMMDMeshRoot : public ObjectData
	{
		maxon::HashMap<String, mesh_morph_hub_data> m_mesh_morph_map;

		OMMDMeshRoot() {}
		~OMMDMeshRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDMeshRoot);
		INSTANCEOF(OMMDMeshRoot, ObjectData)
	public:
		const maxon::HashMap<String, mesh_morph_hub_data>& GetMeshMorphData() { return m_mesh_morph_map; }
		Bool Init(GeListNode* node) override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDMeshRoot));
		}
	};
}