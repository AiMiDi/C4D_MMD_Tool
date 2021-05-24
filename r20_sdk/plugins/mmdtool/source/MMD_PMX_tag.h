#ifndef __MMD_PMX_TAG_H__
#define __MMD_PMX_TAG_H__

#include "main.h"
#include "c4d_nodedata.h"
#include "description/PMX_Model_Tag.h"
#include "description/PMX_Bone_Tag.h"


namespace mmd {


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
		//储存前一帧，以确定更新状态
		Int32 prev_frame = -1;
		//储存上一种曲线类型，以确定更新状态
		Int32 prev_curve_type = -1;
		//对应的主对象
		BaseObject* obj = nullptr;
		INSTANCEOF(PMX_Bone_Tag, TagData)
	public:
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
		inline Bool CurveInit();
		//接收Message时调用，用于处理事件
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool Init(GeListNode* node);
		//设置参数时调用，用于调用SplineData的回调函数
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		virtual Bool GetDEnabling(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc);
		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 	priority, EXECUTIONFLAGS flags);
		static NodeData* Alloc() { return NewObjClear(PMX_Bone_Tag); }
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
	class PMX_Rigid_Tag : public TagData
	{
	public:
		virtual Bool Init(GeListNode* node);

		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);

		static NodeData* Alloc() { return NewObjClear(PMX_Rigid_Tag); }
	};

	class PMX_Joint_Tag : public TagData
	{
	public:
		virtual Bool Init(GeListNode* node);

		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);

		static NodeData* Alloc() { return NewObjClear(PMX_Joint_Tag); }
	};*/
}

#endif __MMD_PMX_TAG_H__