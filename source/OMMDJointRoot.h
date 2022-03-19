#pragma once
#include "Utility.h"
#include "description/OMMDJointRoot.h"

namespace mmd {
	struct OMMDJointRoot_MSG
	{
		Int32	type = 0;
		Int32	DisplayType = JOINT_DISPLAY_TYPE_OFF;
		Int32	mode = JOINT_MODE_ANIM;
		OMMDJointRoot_MSG(Int32 type_ = 0, Int32 DisplayType_ = JOINT_DISPLAY_TYPE_OFF, Int32 mode_ = JOINT_MODE_ANIM)
		{
			type = type_;
			DisplayType = DisplayType_;
			mode = mode_;
		}
	};
	class OMMDJointRoot : public ObjectData
	{
		friend class OMMDJoint;
		Int64 name_cnt = 1;
		BaseObject* BoneRoot = nullptr;
		BaseObject* RigidRoot = nullptr;
		OMMDJointRoot() {}
		~OMMDJointRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDJointRoot);
		INSTANCEOF(OMMDJointRoot, ObjectData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDJointRoot));
		}
	};
}

