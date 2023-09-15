#pragma once
#include "Utility.h"
#include "TMMDBone.h"
#include "OMMDModel.h"
#include "description/OMMDBoneRoot.h"

namespace tool {
	
	/*
type 0: updata BoneRoot;
type 1: set bone display type;
type 2: bone index change;
type 3: bone morph change;
*/
	enum class OMMDBoneRoot_MSG_Type
	{
		DEFAULT,
		SET_BONE_DISPLAY_TYPE,
		BONEROOT_UPDATA,
		BONE_MORPH_CHANGE
	};
	struct OMMDBoneRoot_MSG
	{

		OMMDBoneRoot_MSG_Type type = OMMDBoneRoot_MSG_Type::DEFAULT;
		Int32	display_type = BONE_DISPLAY_TYPE_ON;
		BaseObject* object = nullptr;
		OMMDBoneRoot_MSG(
			OMMDBoneRoot_MSG_Type type_ = OMMDBoneRoot_MSG_Type::DEFAULT,
			Int32 display_type_ = BONE_DISPLAY_TYPE_ON,
			BaseObject* BoneRoot_ = nullptr):
			type(type_),
			display_type(display_type_),
			object(BoneRoot_){}
	};
	class OMMDBoneRoot : public ObjectData
	{
		friend class TMMDBone;
		friend class OMMDRigid;
		friend class OMMDJoint;
		
		Int64 name_cnt = 0;
		BaseObject* m_Model_ptr = nullptr;
		BaseObject* m_RigidRoot_ptr = nullptr;
		BaseObject* m_JointRoot_ptr = nullptr;
		BaseContainer m_bone_items;
		maxon::HashMap<Int32, BaseObject*> m_IndexToBone_map;
		maxon::HashMap<BaseObject*, Int32> m_BoneToIndex_map;
		maxon::HashMap<String, maxon::BaseList<bone_morph_hub_data>> m_MorphData_map;
		OMMDBoneRoot() {}
		~OMMDBoneRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDBoneRoot);
		INSTANCEOF(OMMDBoneRoot, ObjectData)
	public:
		Bool Init(GeListNode* node) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(GeListNode* node, HyperFile* hf) override;
		Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDBoneRoot));
		}
		maxon::HashMap<String, maxon::BaseList<bone_morph_hub_data>>& GetBoneMorphMap() { return m_MorphData_map; }
	};
}
