#pragma once
#include "Utility.h"
#include "OMMDRigidRoot.h"
#include "description/OMMDRigid.h"

namespace mmd {
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
		virtual Bool Init(GeListNode* node);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
		/* 设置参数时调用 */
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		/* 禁用与启用参数 */
		virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		/* 接收Message时调用，用于处理事件 */
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
		/* 实时调用 */
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		/* 将实时调用添加入优先级列表 */
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		/*删除函数 */
		virtual void Free(GeListNode* node);
		/* 生成函数 */
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDRigid));
		}
		BaseObject* GetRootObject() {
			return this->RigidRoot;
		}
	};
}

