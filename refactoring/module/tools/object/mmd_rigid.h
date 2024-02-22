/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_rigid.h
Description:	C4D MMD rigid object

**************************************************************************/

#ifndef MMD_RIGID_H__
#define MMD_RIGID_H__
#include "description/OMMDRigid.h"
#include "description/OMMDRigidRoot.h"

	struct MMDRigidObjectMsg
	{
		Int32		old_index = 0;
		Int32		new_index = 0;
		BaseObject* rigid = nullptr;
		MMDRigidObjectMsg(Int32 pred_index_ = 0, Int32 now_index_ = 0, BaseObject* rigid_ = nullptr)
		{
			old_index = pred_index_;
			new_index = now_index_;
			rigid = rigid_;
		}
	};
	class MMDRigidObject final : public ObjectData
	{
	private:
		Int32		m_display_type = RIGID_DISPLAY_TYPE_OFF;
		Int32		m_rigid_mode = RIGID_MODE_ANIM;
		Int32		m_physics_mode = TRACK_BONES;
		BaseTag*	m_protection_tag = nullptr;
		AutoFree<BaseObject> m_grid_draw_object;
		AutoFree<BaseObject> m_draw_object;

		BaseObject* m_rigid_root = nullptr;
		BaseObject* related_bone = nullptr;

		Vector		m_original_position = Vector();
		Vector		m_original_rotation = Vector();
		Vector		m_relative_bone_position = Vector();
		Vector		m_relative_bone_rotation = Vector();
		MMDRigidObject() = default;
		~MMDRigidObject() override = default;
		CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDRigidObject)
		CMT_DEFAULT_MOVE_BODY(MMDRigidObject)
		INSTANCEOF(MMDRigidObject, ObjectData)
	public: 
		Bool Init(GeListNode* node SDK2024_InitParaName) override;
		Bool GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		Bool GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) SDK2024_Const override;
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) override;
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
		Bool CopyTo( NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;

		static NodeData* Alloc();
		BaseObject* GetRootObject() const;
	private:
		void SetSphericalType(const BaseContainer* bc);
		void SetBoxType(const BaseContainer* bc);
		void SetCapletsType(const BaseContainer* bc);
		void SetSphericalSize(const BaseContainer* bc);
		void SetBoxSize(const BaseContainer* bc);
		void SetCapletsSize(const BaseContainer* bc);
	};

#endif
