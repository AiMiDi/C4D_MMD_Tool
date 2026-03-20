#pragma once
#include "Utility.h"
#include "description/OMMDJoint.h"
#include "description/OMMDJointRoot.h"

namespace tool {
	class OMMDJoint : public ObjectData
	{
	private:
		Int32	DisplayType = JOINT_DISPLAY_TYPE_OFF;
		Int32	mode = JOINT_MODE_ANIM;
		BaseObject* JointRoot = nullptr;
		BaseObject* link_rigid_a = nullptr;
		BaseObject* link_rigid_b = nullptr;
		BaseTag* protection_tag = nullptr;
		OMMDJoint() {}
		~OMMDJoint() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDJoint);
		INSTANCEOF(OMMDJoint, ObjectData)

	public:
		/* 对象初始化 */
		virtual Bool Init(GeListNode* node);
		/* 设置参数时调用，用于调用SplineData的回调函数 */
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
		Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		/* 接收Message时调用，用于处理事件 */
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
		/* 实时调用 */
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		/* 将实时调用添加入优先级列表 */
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		/* 生成函数 */
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDJoint));
		}
	};
}
