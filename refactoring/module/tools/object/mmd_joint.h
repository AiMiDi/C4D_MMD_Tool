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

class MMDJointObject final : public ObjectData
{
	Int32	m_display_type = JOINT_DISPLAY_TYPE_OFF;
	Int32	m_joint_mode = JOINT_MODE_ANIM;
	BaseObject* m_joint_root = nullptr;
	BaseObject* m_link_rigid_a = nullptr;
	BaseObject* m_link_rigid_b = nullptr;
	BaseTag* protection_tag = nullptr;

	MMDJointObject() = default;
	~MMDJointObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDJointObject)
	CMT_DEFAULT_MOVE_BODY(MMDJointObject)
	INSTANCEOF(MMDJointObject, ObjectData)

public:
	Bool Init(GeListNode* node SDK2024_InitParaName) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	Bool GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;
	Bool GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) SDK2024_Const override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) override;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;

	static NodeData* Alloc();

private:
	static void DrawBox(const BaseObject* op, BaseDraw* bd, const BaseContainer* bc, Bool wire);
};

#endif
