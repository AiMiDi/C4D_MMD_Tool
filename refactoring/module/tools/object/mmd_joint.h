/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_joint.cpp
Description:	C4D MMD joint object

**************************************************************************/

#ifndef MMD_JOINT_H__
#define MMD_JOINT_H__
#include "description/OMMDJointRoot.h"

class MMDJointObject : public ObjectData
{
	Int32	DisplayType = JOINT_DISPLAY_TYPE_OFF;
	Int32	mode = JOINT_MODE_ANIM;
	BaseObject* JointRoot = nullptr;
	BaseObject* link_rigid_a = nullptr;
	BaseObject* link_rigid_b = nullptr;
	BaseTag* protection_tag = nullptr;
	MMDJointObject() {}
	~MMDJointObject() {}
	MAXON_DISALLOW_COPY_AND_ASSIGN(MMDJointObject);
	INSTANCEOF(OMMDJoint, ObjectData)

public:
	// 对象初始化
	Bool Init(GeListNode* node SDK2024_InitParaName) override;

	// 设置参数时调用，用于调用SplineData的回调函数
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool GetDDescription(BaseList2D* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;
	Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);

	// 接收Message时调用，用于处理事件 
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) override;

	// 实时调用
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;

	// 将实时调用添加入优先级列表 
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;

	// 生成函数 
	static NodeData* Alloc()
	{
		return(NewObjClear(MMDJointObject));
	}
};

#endif
