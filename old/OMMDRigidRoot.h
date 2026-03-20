#pragma once
#include "Utility.h"
#include "description/OMMDRigidRoot.h"

namespace tool {
	struct OMMDRigidRoot_MSG
	{
		Int32	type = 0;
		Int32	DisplayType = RIGID_DISPLAY_TYPE_OFF;
		Int32	mode = RIGID_MODE_ANIM;
		OMMDRigidRoot_MSG(Int32 type_ = 0, Int32 DisplayType_ = RIGID_DISPLAY_TYPE_OFF, Int32 mode_ = RIGID_MODE_ANIM)
		{
			type = type_;
			DisplayType = DisplayType_;
			mode = mode_;
		}
	};
	class OMMDRigidRoot : public ObjectData
	{
		friend class OMMDRigid;
		friend class OMMDJoint;
		Int64 name_cnt = 1;
		BaseContainer rigid_items;
		BaseObject* BoneRoot = nullptr;
		BaseObject* JointRoot = nullptr;
		maxon::HashMap<Int32, BaseObject*> IndexToRigidMap;
		OMMDRigidRoot() {}
		~OMMDRigidRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDRigidRoot);
		INSTANCEOF(OMMDRigidRoot, ObjectData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual void Free(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDRigidRoot));
		}
	};
}

