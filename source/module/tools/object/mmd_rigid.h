/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_rigid.h
Description:	C4D MMD rigid object

**************************************************************************/

#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "description/OMMDRigid.h"
#include "description/OMMDRigidManager.h"

class MMDRigidManagerObject;
namespace libmmd { class MMDRigidBody; }

class MMDRigidObject final : public ObjectData
{
	Int32		m_rigid_mode = RIGID_MODE_ANIM;
	Int32		m_display_type = RIGID_DISPLAY_TYPE_OFF;
	Int32		m_physics_mode = TRACK_BONES;
	Int32		m_rigid_shape_type = SPHERICAL;
	Int32		m_rigid_group_id = RIGID_GROUP_0;

	AutoAlloc<BaseLink> rigid_manager_link_;
	mutable MMDRigidManagerObject* rigid_manager_data_ = nullptr;
	libmmd::MMDRigidBody* mmd_rigidbody_ = nullptr;

	MMDRigidManagerObject* GetRigidManager() const;

	AutoFree<BaseObject> draw_mesh_object_;
	ObjectColorProperties draw_color_;

	MMDRigidObject();
	~MMDRigidObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDRigidObject)
	CMT_DEFAULT_MOVE_BODY(MMDRigidObject)
	INSTANCEOF(MMDRigidObject, ObjectData)
public:
	SDK2024_InitOverride;
	SDK2024_GetDDescriptionOverride;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	SDK2024_GetDEnablingOverride;

	Bool Message(GeListNode* node, Int32 type, void* data) override;
	DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) override;
	void HandleRigidIndexUpdate(BaseObject* op) const;
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
	Bool AddToExecution(BaseObject* op, PriorityList* list) override;
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	SDK2024_CopyToOverride;

	static NodeData* Alloc();
	friend class MMDRigidManagerObject;
private:
	void HandleRigidModeChange(Int32 mode);

	template <typename Size>
	void ResetRigidType(const BaseContainer* bc);

	template <typename Type>
	void SetRigidSize(const BaseContainer* bc);

	void UpdateRigidShape(const BaseContainer* bc, Int32 rigid_shape_type);
	void UpdateRigidSize(const BaseContainer* bc);
	void UpdateRigidPhysics(Int32 physics_mode);
	void UpdateRigidGroup(Int32 rigid_group);
};
