#ifndef __MMD_PMX_CONTROL_H__
#define __MMD_PMX_CONTROL_H__

#include "main.h"
#include "c4d_nodedata.h"
#include "description/PMX_Model_Tag.h"
#include "description/PMX_Bone_Tag.h"


namespace mmd {

	struct bone_morph_data
	{
		DescID grp_id;
		DescID strength_id;
		DescID translation_id;
		DescID rotation_id;
		DescID button_grp_id;
		DescID button_delete_id;
		DescID button_rename_id;
		String name;
	};

	class PMX_Model_Tag : public TagData
	{
		BaseTag* tag = nullptr;
		BaseObject* obj = nullptr;
		Bool tagUpDataSW = false;
		INSTANCEOF(PMX_Model_Tag ,TagData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 	priority, EXECUTIONFLAGS flags);
		static NodeData* Alloc() { return NewObjClear(PMX_Model_Tag); }
	};

	class PMX_Bone_Tag : public TagData
	{
		//使用Map储存补间曲线数据
		maxon::HashMap<Int32, mmd::VMD_Curve*> XCurve;
		maxon::HashMap<Int32, mmd::VMD_Curve*> YCurve;
		maxon::HashMap<Int32, mmd::VMD_Curve*> ZCurve;
		maxon::HashMap<Int32, mmd::VMD_Curve*> RCurve;
		maxon::HashMap<Int32, mmd::VMD_Curve*> ACurve;
		maxon::HashMap<DescID, Int32> button_id_map;
		Int32 bone_morph_name_index = 0;
		//储存前一帧，以确定更新状态
		Int32 prev_frame = -1;
		//储存上一种曲线类型，以确定更新状态
		Int32 prev_curve_type = -1;
		//对应的主对象
		BaseObject* obj = nullptr;		
		Vector prev_position;
		Vector prev_rotation;
		INSTANCEOF(PMX_Bone_Tag, TagData)
	public:	
		maxon::BaseArray<bone_morph_data> bone_morph_data_arr;	
		//是否是物理骨骼
		Bool Is_physical = false;
		Bool SetBondMorphTranslation(Int32 id, Vector& translation) {
			if (id<0 || id>bone_morph_data_arr.GetCount() - 1) {
				return false;
			}
			return Get()->SetParameter(bone_morph_data_arr[id].translation_id, translation, DESCFLAGS_SET::NONE);
		}
		Bool SetBondMorphRotation(Int32 id, Vector& rotation) {
			if (id<0 || id>bone_morph_data_arr.GetCount() - 1) {
				return false;
			}
			return Get()->SetParameter(bone_morph_data_arr[id].rotation_id, rotation, DESCFLAGS_SET::NONE);
		}
		Int32 AddBondMorph(String morph_name);
		// 用于限制SplineData的回调函数
		static Bool SplineDataCallBack(Int32 cid, const void* data);
		//获取曲线值
		Bool GetCurve(Int32 type, Int32 frame_on, mmd::VMD_Curve* curve);
		//设置曲线值
		Bool SetCurve(Int32 type, Int32 frame_on, mmd::VMD_Curve* curve);
		//更新补间曲线
		Bool UpdateCurve(Int32 frame_on);
		//更新全部补间曲线
		Bool UpdateAllCurve();
		//初始化曲线
		Bool CurveInit();
		//接收Message时调用，用于处理事件
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool Init(GeListNode* node);
		//设置参数时调用，用于调用SplineData的回调函数
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		virtual Bool GetDEnabling(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc);
		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 	priority, EXECUTIONFLAGS flags);
		static NodeData* Alloc() { return NewObjClear(PMX_Bone_Tag); }
	};

	class PMX_Rigid_Obj : public ObjectData
	{
	private:
		//析构函数
		~PMX_Rigid_Obj() {}
		INSTANCEOF(PMX_Rigid_Obj, ObjectData)

	public:
		//对象初始化
		virtual Bool Init(GeListNode* node);
		////设置参数时调用，用于调用SplineData的回调函数
		//virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		//禁用与启用参数
		virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		//接收Message时调用，用于处理事件
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		//实时调用
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		//将实时调用添加入优先级列表
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		//删除函数
		virtual void Free(GeListNode* node);
		//生成函数
		static NodeData* Alloc() { return NewObjClear(PMX_Rigid_Obj); }
	};

	class PMX_Joint_Obj : public ObjectData
	{
	private:
		//析构函数
		~PMX_Joint_Obj() {}
		INSTANCEOF(PMX_Joint_Obj, ObjectData)

	public:
		//对象初始化
		virtual Bool Init(GeListNode* node);
		////设置参数时调用，用于调用SplineData的回调函数
		//virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		//禁用与启用参数
		virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		//接收Message时调用，用于处理事件
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		//实时调用
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		//将实时调用添加入优先级列表
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		//删除函数
		virtual void Free(GeListNode* node);
		//生成函数
		static NodeData* Alloc() { return NewObjClear(PMX_Joint_Obj); }
	};
	/*	
	class PMX_Material_Tag : public TagData
	{
	public:
		virtual Bool Init(GeListNode* node);

		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);

		static NodeData* Alloc() { return NewObjClear(PMX_Material_Tag); }
	};
	class PMX_Display_Tag : public TagData
	{
	public:
		virtual Bool Init(GeListNode* node);

		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);

		static NodeData* Alloc() { return NewObjClear(PMX_Display_Tag); }
	};
*/

	class RenameDialog : public GeDialog
	{
		Bool CreateLayout() {
			GroupBegin(1000, BFH_LEFT, 2, 1, ""_s, 0, 0, 10);
			AddStaticText(10000, BFH_LEFT, 100, 10, GeLoadString(IDS_MSG_RENAME), BORDER_NONE);
			AddEditText(10001, BFH_LEFT, 230, 10);
			GroupEnd();
			GroupBegin(1002, BFH_CENTER, 2, 1, ""_s, 0, 0, 20);
			GroupSpace(50, 0);
			AddButton(10002, BFH_LEFT, 80, 20, GeLoadString(IDS_MSG_RENAME_OK));
			AddButton(10003, BFH_RIGHT, 80, 20, GeLoadString(IDS_MSG_RENAME_CANCEL));
			GroupEnd();
			return true;
		}
		Bool Command(Int32 id, const BaseContainer& msg) {
			switch (id)
			{
			case 10002:
			{
				GetString(10001, Rename);
				Close();
				break;
			}
			case 10003:
			{
				Close();
				break;
			}
			default:
				break;
			}
			return true;
		}
	public:
		String Rename;
		RenameDialog() {}
		~RenameDialog() {}
	};
}

#endif //__MMD_PMX_CONTROL_H__