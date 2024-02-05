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

class MMDRigidObject final : public ObjectData
{
	struct OMMDRigid_MSG
	{
		Int32		pred_index = 0;
		Int32		now_index = 0;
		BaseObject* rigid = nullptr;
		OMMDRigid_MSG(Int32 pred_index_ = 0, Int32 now_index_ = 0, BaseObject* rigid_ = nullptr)
		{
			pred_index = pred_index_;
			now_index = now_index_;
			rigid = rigid_;
		}
	};
	class OMMDRigid : public ObjectData
	{
	private:
		Vector		no_anim_pos = Vector();
		Vector		no_anim_rot = Vector();
		Vector		relative_bone_position = Vector();
		Vector		relative_bone_rotation = Vector();
		Int32		DisplayType = RIGID_DISPLAY_TYPE_OFF;
		Int32		mode = RIGID_MODE_ANIM;
		Int32		physics_mode = TRACK_BONES;
		BaseObject* pdraw_obj = nullptr;
		BaseObject* draw_obj = nullptr;
		BaseObject* RigidRoot = nullptr;
		BaseObject* related_bone = nullptr;
		BaseTag* protection_tag = nullptr;
		OMMDRigid() {}
		~OMMDRigid() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDRigid);
		INSTANCEOF(OMMDRigid, ObjectData)
	public:
		/* 对象初始化 */
		Bool Init(GeListNode* node SDK2024_InitParaName) override;
		Bool GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const override;

		/* 设置参数时调用 */
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

		/* 禁用与启用参数 */
		Bool GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) SDK2024_Const override;

		/* 接收Message时调用，用于处理事件 */
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh) override;

		/* 实时调用 */
		EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

		/* 将实时调用添加入优先级列表 */
		Bool AddToExecution(BaseObject* op, PriorityList* list) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
		Bool CopyTo( NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;

		/*删除函数 */
		void Free(GeListNode* node) override;

		// 生成函数
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDRigid));
		}
		BaseObject* GetRootObject()
		{
			return this->RigidRoot;
		}
	};
};

#endif
