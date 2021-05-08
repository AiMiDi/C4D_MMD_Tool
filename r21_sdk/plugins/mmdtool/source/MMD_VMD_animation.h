#ifndef __MMD_VMD_ANIMATION_H__
#define __MMD_VMD_ANIMATION_H__

#include "main.h"
#include "MMD_PMX_tag.h"
#include "description/PMX_Bone_Tag.h"
#include "description/VMD_Cam_Obj.h"

namespace mmd{

	class VMDAnimation
	{
	private:
		class VMDMotionSortedArray : public maxon::SortedArray<VMDMotionSortedArray, maxon::PointerArray<VMD_Motion>>
		{
		public:
			static Bool LessThan(const VMD_Motion& a, const VMD_Motion& b) { return a.frame_no < b.frame_no; }
			static Bool IsEqual(const VMD_Motion& a, const VMD_Motion& b) { return a.frame_no == b.frame_no; }
		};

		class VMDMorphSortedArray : public maxon::SortedArray<VMDMorphSortedArray, maxon::PointerArray<VMD_Morph>>
		{
		public:
			static Bool LessThan(const VMD_Morph& a, const VMD_Morph& b) { return a.frame_no < b.frame_no; }
			static Bool IsEqual(const VMD_Morph& a, const VMD_Morph& b) { return a.frame_no == b.frame_no; }
		};

		class VMDCameraSortedArray : public maxon::SortedArray<VMDCameraSortedArray, maxon::PointerArray<VMD_Camera>>
		{
		public:
			static Bool LessThan(const VMD_Camera& a, const VMD_Camera& b) { return a.frame_no < b.frame_no; }
			static Bool IsEqual(const VMD_Camera& a, const VMD_Camera& b) { return a.frame_no == b.frame_no; }
		};

		class VMDLightSortedArray : public maxon::SortedArray<VMDLightSortedArray, maxon::PointerArray<VMD_Light>>
		{
		public:
			static Bool LessThan(const VMD_Light& a, const VMD_Light& b) { return a.frame_no < b.frame_no; }
			static Bool IsEqual(const VMD_Light& a, const VMD_Light& b) { return a.frame_no == b.frame_no; }
		};
		//最初使用动作模型名称
		String ModelName;
		//是否为摄像机动作
		Bool IsCamera;
		//动作关键帧数量
		UInt32 MotionFrameNumber;
		//表情关键帧数量
		UInt32 MorphFrameNumber;
		//摄像机关键帧数量
		UInt32 CameraFrameNumber;
		//灯光关键帧数量
		UInt32 LightFrameNumber;
		//动作数据数组
		VMDMotionSortedArray motion_frames;
		//表情动画数据数组
		VMDMorphSortedArray morph_frames;
		//摄像机数据数组
		VMDCameraSortedArray camera_frames;
		//灯光数据数组
		VMDLightSortedArray light_frames;
	public:
		//构造函数
		VMDAnimation();
		//析构函数
		~VMDAnimation();

		//用于从文件导入到对象
		maxon::Result<void> LoadFromFile(BaseFile* const file);
		//用于将对象保存到文件
		maxon::Result<void> WriteToFile(BaseFile* const file);

		//从文件导入摄像机数据
		static maxon::Result<void> FromFileImportCamera(Float PositionMultiple, Float TimeOffset);
		//从项目导出摄像机数据
		static maxon::Result<void> FromDocumentExportCamera(Float PositionMultiple, Float TimeOffset, Int32 use_rotation);
		//从文件导入动作或表情数据
		static maxon::Result<void> FromFileImportMotions(Float PositionMultiple, Float TimeOffset, Bool QuaternionRotationSW, Bool DetailReport, Bool ByTag);
	};

	class VMD_Cam_Obj : public ObjectData
	{		
	private:
		//使用Map储存补间曲线数据
		maxon::HashMap<Int32, VMD_Curve*> XCurve;
		maxon::HashMap<Int32, VMD_Curve*> YCurve;
		maxon::HashMap<Int32, VMD_Curve*> ZCurve;
		maxon::HashMap<Int32, VMD_Curve*> RCurve;
		maxon::HashMap<Int32, VMD_Curve*> DCurve;
		maxon::HashMap<Int32, VMD_Curve*> VCurve;
		maxon::HashMap<Int32, VMD_Curve*> ACurve;	
		//构造函数
		VMD_Cam_Obj() { cam = nullptr; prev_frame = -1; prev_curve_type = -1;}
		//析构函数
		~VMD_Cam_Obj() {}		
		//储存前一帧，以确定更新状态
		Int32 prev_frame; 
		//储存上一种曲线类型，以确定更新状态
		Int32 prev_curve_type;
		//管理的摄像机对象
		BaseObject* cam;
		INSTANCEOF(VMD_Cam_Obj, ObjectData)

	public:		
		// 用于限制SplineData的回调函数
		static Bool SplineDataCallBack(Int32 cid, const void* data);
		//将普通摄像机转换为MMD摄像机
		static maxon::Result<BaseObject*> ConversionCamera(Float distance,Int32 use_rotation,BaseObject* str_cam = nullptr);
		//获取曲线值
		Bool GetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve);
		//设置曲线值
		Bool SetCurve(Int32 type, Int32 frame_on, VMD_Curve* curve);
		//更新补间曲线
		Bool UpdateCurve(Int32 frame_on);
		//更新全部补间曲线
		Bool UpdateAllCurve();
		//获取对象管理的摄像机对象
		BaseObject* GetCamera() { return cam; }
		//初始化摄像机对象
		inline Bool CameraInit();
		//初始化曲线
		inline Bool CurveInit();

		//对象初始化
		virtual Bool Init(GeListNode* node);
		//设置参数时调用，用于调用SplineData的回调函数
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
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
		static NodeData* Alloc() { return NewObjClear(VMD_Cam_Obj); }
	};

	class VMD_Cam_Draw : public SceneHookData
	{	
		INSTANCEOF(VMD_Cam_Draw, SceneHookData)
	public:
		virtual Bool Draw(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags);
		static NodeData* Alloc(void) { return NewObjClear(VMD_Cam_Draw); }
	};
} // namespace
#endif  __MMD_VMD_ANIMATION_H__