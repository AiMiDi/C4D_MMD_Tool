/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_joint.cpp
Description:	C4D MMD joint object

**************************************************************************/

#pragma once

#include "mmd_joint_manager.h"
#include "description/OMMDJointManager.h"

namespace libmmd { class MMDJoint; }

class MMDJointObject final : public ObjectData
{
	Int32	display_type_ = JOINT_DISPLAY_TYPE_OFF;
	Int32	joint_mode_ = JOINT_MODE_ANIM;
	AutoAlloc<BaseLink> link_rigid_a_;
	AutoAlloc<BaseLink> link_rigid_b_;
	AutoAlloc<BaseLink> joint_manager_link_;
	libmmd::MMDJoint* mmd_joint_ = nullptr;
	mutable MMDJointManagerObject* joint_manager_data_ = nullptr;

	MMDJointManagerObject* GetJointManager() const;

	MMDJointObject() = default;
	~MMDJointObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDJointObject)
	CMT_DEFAULT_MOVE_BODY(MMDJointObject)
	INSTANCEOF(MMDJointObject, ObjectData)

public:
	SDK2024_InitOverride;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	SDK2024_GetDDescriptionOverride;
	SDK2024_GetDEnablingOverride;
	void HandleJointModeChange(Int32 mode);
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) override;
	static void HandleJointIndexUpdate(BaseObject* op);
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	SDK2024_CopyToOverride;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
	static NodeData* Alloc();
	friend class MMDJointManagerObject;
private:
	static void DrawBox(const BaseObject* op, BaseDraw* bd, const BaseContainer* bc, Bool wire);
};
