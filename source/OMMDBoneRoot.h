#pragma once
#include "Utility.h"
#include "TMMDBone.h"
#include "OMMDModel.h"
#include "description/OMMDBoneRoot.h"

namespace tool {
	struct bone_morph_hub_data {
		BaseTag* bone_tag = nullptr;
		bone_morph_data* data = nullptr;

		Bool SetStrength(const Float& strength)
		{
			return bone_tag->SetParameter(data->strength_id, strength, DESCFLAGS_SET::NONE);
		}
	};
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
		friend class BoneMorph;
		Int64 name_cnt = 1;
		BaseObject* m_Model_ptr = nullptr;
		BaseObject* m_RigidRoot_ptr = nullptr;
		BaseObject* m_JointRoot_ptr = nullptr;
		BaseContainer bone_items;
		maxon::HashMap<Int32, BaseObject*> IndexToBoneMap;
		maxon::HashMap<BaseObject*, Int32> BoneToIndexMap;
		maxon::HashMap<String, bone_morph_hub_data> m_bone_morph_map;		
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
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDBoneRoot));
		}
	};
}
