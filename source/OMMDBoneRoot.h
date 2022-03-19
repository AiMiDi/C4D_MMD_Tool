#pragma once
#include "Utility.h"
#include "description/OMMDBoneRoot.h"

namespace mmd {
	struct OMMDBoneRoot_MSG
	{
		/*
		type 0: updata BoneRoot;
		type 1: set bone display type;
		type 2: bone index change;
		*/
		Int32	type = 0;
		Int32	DisplayType = BONE_DISPLAY_TYPE_ON;
		BaseObject* BoneRoot = nullptr;
		OMMDBoneRoot_MSG(Int32 type_ = 0, Int32 DisplayType_ = BONE_DISPLAY_TYPE_ON, BaseObject* BoneRoot_ = nullptr)
		{
			type = type_;
			DisplayType = DisplayType_;
			BoneRoot = BoneRoot_;
		}
	};
	struct bone_morph_hub_data {
		const BaseTag* bone_tag = nullptr;
		const bone_morph_data* data = nullptr;
	};
	class OMMDBoneRoot : public ObjectData
	{
		friend class TMMDBone;
		friend class OMMDRigid;
		friend class OMMDJoint;
		Int64 name_cnt = 1;
		BaseObject* RigidRoot = nullptr;
		BaseObject* JointRoot = nullptr;
		BaseContainer bone_items;
		maxon::HashMap<Int32, BaseObject*> IndexToBoneMap;
		maxon::HashMap<BaseObject*, Int32> BoneToIndexMap;
		maxon::HashMap<String, bone_morph_hub_data> m_bone_morph_map;
		OMMDBoneRoot() {}
		~OMMDBoneRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDBoneRoot);
		INSTANCEOF(OMMDBoneRoot, ObjectData)
	public:
		const maxon::HashMap<String, bone_morph_hub_data>& GetBoneMorphData() { return m_bone_morph_map; }
		Bool Init(GeListNode* node) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(GeListNode* node, HyperFile* hf) override;
		Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDBoneRoot));
		}
	};
}
