#ifndef __MMD_VMD_ANIMATION_H__
#define __MMD_VMD_ANIMATION_H__

#include "MMD_utility.h"
#include "MMD_PMX_Control.h"
#include "description/TMMDBone.h"
#include "description/OMMDCamera.h"

#define EXIT_FromFileImportMotions \
	for (auto i : bone_name_map.GetValues()) {\
		if (i != nullptr)\
			DeleteObj(i);\
	}\
	bone_name_map.Reset();\
	for (auto i : morph_name_map.GetValues()) {\
		if (i != nullptr)\
			DeleteObj(i);\
	}\
	morph_name_map.Reset();\
	for (auto i : ik_tag_map.GetValues()) {\
		if (i != nullptr)\
			DeleteObj(i);\
	}\
	ik_tag_map.Reset();\
	for (auto i : MorphFrameList_map.GetValues())\
	{\
		if (i != nullptr)\
			DeleteObj(i);\
	}\
	MorphFrameList_map.Reset();\
	for (auto i : MotionFrameList_map.GetValues())\
	{\
		if (i != nullptr)\
			DeleteObj(i);\
	}\
	MotionFrameList_map.Reset();

namespace mmd {
	struct VMD_Camera_import_settings
	{
		Float		position_multiple = 8.5;
		Float		time_offset = 0;
		Filename	fn = Filename();
		BaseDocument* doc = nullptr;
	};
	struct VMD_Camera_export_settings
	{
		Float	position_multiple = 8.5;
		Float	time_offset = 0;
		Int32	use_rotation = 0;
		Bool    use_bake = true;
	};
	struct VMD_Conversion_Camera_settings {
		Float		distance = 0;
		Int32		use_rotation = 0;
		BaseObject* str_cam = nullptr;
	};
	struct VMD_Motions_import_settings {
		Float	position_multiple = 8.5;
		Float	time_offset = 0;
		Bool    import_motion = true;
		Bool    import_morph = true;
		Bool    import_model_info = true;
		Bool	delete_previous_animation = true;
		Bool	detail_report = false;
	};
	struct VMD_Motions_export_settings {
		Float	position_multiple = 8.5;
		Float	time_offset = 0;
		Int32   use_rotation = 0;
		Bool    export_motion = true;
		Bool    export_morph = true;
		Bool    export_model_info = true;
		Bool    use_bake = true;
	};
	class VMDAnimation
	{
		MAXON_DISALLOW_COPY_AND_ASSIGN(VMDAnimation);
	private:
		class VMDMotionSortedArray : public maxon::SortedArray<VMDMotionSortedArray, maxon::PointerArray<VMD_Motion> >
		{
		public:
			static Bool LessThan(const VMD_Motion& a, const VMD_Motion& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMD_Motion& a, const VMD_Motion& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDMorphSortedArray : public maxon::SortedArray<VMDMorphSortedArray, maxon::PointerArray<VMD_Morph> >
		{
		public:
			static Bool LessThan(const VMD_Morph& a, const VMD_Morph& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMD_Morph& a, const VMD_Morph& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDCameraSortedArray : public maxon::SortedArray<VMDCameraSortedArray, maxon::PointerArray<VMD_Camera> >
		{
		public:
			static Bool LessThan(const VMD_Camera& a, const VMD_Camera& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMD_Camera& a, const VMD_Camera& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDLightSortedArray : public maxon::SortedArray<VMDLightSortedArray, maxon::PointerArray<VMD_Light> >
		{
		public:
			static Bool LessThan(const VMD_Light& a, const VMD_Light& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMD_Light& a, const VMD_Light& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDShadowSortedArray : public maxon::SortedArray<VMDShadowSortedArray, maxon::PointerArray<VMD_Shadow> >
		{
		public:
			static Bool LessThan(const VMD_Shadow& a, const VMD_Shadow& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMD_Shadow& a, const VMD_Shadow& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDModelSortedArray : public maxon::SortedArray<VMDModelSortedArray, maxon::PointerArray<VMD_Model> >
		{
		public:
			static Bool LessThan(const VMD_Model& a, const VMD_Model& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMD_Model& a, const VMD_Model& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		/* 最初使用动作模型名称 */
		String ModelName;
		/* 是否为摄像机动作 */
		Bool IsCamera = false;
		/* 动作数据数组 */
		VMDMotionSortedArray motion_frames;
		/* 表情动画数据数组 */
		VMDMorphSortedArray morph_frames;
		/* 摄像机数据数组 */
		VMDCameraSortedArray camera_frames;
		/* 灯光数据数组 */
		VMDLightSortedArray light_frames;
		/* 灯光数据数组 */
		VMDShadowSortedArray shadow_frames;
		/* 灯光数据数组 */
		VMDModelSortedArray model_frames;
		/* 用于从文件导入到对象 */
		maxon::Result<void> LoadFromFile(Filename& fn);
		/* 用于将对象保存到文件 */
		maxon::Result<void> SaveToFile(Filename& fn);
	public:
		/* 构造函数 */
		VMDAnimation(){}
		/* 析构函数 */
		~VMDAnimation()
		{
			this->motion_frames.Reset();
			/* 表情动画数据数组 */
			this->morph_frames.Reset();
			/* 摄像机数据数组 */
			this->camera_frames.Reset();
			/* 灯光数据数组 */
			this->light_frames.Reset();
			/* 灯光数据数组 */
			this->shadow_frames.Reset();
			/* 灯光数据数组 */
			this->model_frames.Reset();
		}
		/* 从文件导入摄像机数据 */
		maxon::Result<void> FromFileImportCamera(VMD_Camera_import_settings setting);
		/* 从项目导出摄像机数据 */
		maxon::Result<void> FromDocumentExportCamera(VMD_Camera_export_settings setting);
		/* 从文件导入动作或表情数据 */
		maxon::Result<void> FromFileImportMotion(VMD_Motions_import_settings setting);
		/* 从项目导出动作或表情数据 */
		maxon::Result<void> FromDocumentExportMotion(VMD_Motions_export_settings setting);
	};

	class OMMDCamera : public ObjectData
	{
	private:
		/* 使用Map储存补间曲线数据 */
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_X_map;
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_Y_map;
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_Z_map;
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_R_map;
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_D_map;
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_V_map;
		maxon::HashMap<Int32, VMDInterpolator>	interpolator_A_map;
		/* 析构函数 */
		~OMMDCamera()
		{
		}
		/* 储存前一帧，以确定更新状态 */
		Int32 prev_frame = -1;
		/* 储存上一种曲线类型，以确定更新状态 */
		Int32 prev_interpolator_type = -1;
		/* 管理的摄像机对象 */
		BaseObject* cam = nullptr;
		INSTANCEOF(OMMDCamera, ObjectData)

	public:
		/* 用于限制SplineData的回调函数 */
		static Bool SplineDataCallBack(Int32 cid, const void* data);
		/* 将普通摄像机转换为MMD摄像机 */
		static maxon::Result<BaseObject*> ConversionCamera(VMD_Conversion_Camera_settings setting);
		/* 获取曲线值 */
		Bool GetInterpolator(Int32 type, Int32 frame_on, VMDInterpolator& interpolator);
		/* 设置曲线值 */
		Bool SetInterpolator(Int32 type, Int32 frame_on,const VMDInterpolator& interpolator);
		/* 注册关键帧 */
		Bool RegisterKeyFrame(Int32 frame_on, GeListNode* node = nullptr);
		/* 更新全部补间曲线 */
		Bool UpdateAllInterpolator(GeListNode* node = nullptr);
		/* 获取对象管理的摄像机对象 */
		BaseObject* GetCamera()
		{
			return(cam);
		}
		/* 初始化摄像机对象 */
		Bool CameraInit(GeListNode* node = nullptr);
		/* 初始化曲线 */
		Bool InitInterpolator(GeListNode* node = nullptr);
		/* 删除曲线 */
		Bool DeleteKeyFrame(Int32 frame_on, GeListNode* node = nullptr);
		/* 删除全部曲线 */
		Bool DeleteAllKeyFrame(GeListNode* node = nullptr);
		/* 对象初始化 */
		virtual Bool Init(GeListNode* node = nullptr);
		/* 设置参数时调用，用于调用SplineData的回调函数 */
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		/* 禁用与启用参数 */
		virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		/* 接收Message时调用，用于处理事件 */
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		/* 实时调用 */
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		/* 将实时调用添加入优先级列表 */
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		/*删除函数 */
		virtual void Free(GeListNode* node);
		/* 生成函数 */
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDCamera));
		}
	};
	class VMDLoaderData : public SceneLoaderData
	{
		Bool IsCamera = 0;
		class VMDLoaderCameraDialog : public GeDialog
		{
			ImagesGUI* Images = nullptr;
			Filename	fn;
			BaseDocument* doc = nullptr;
		public:
			VMDLoaderCameraDialog(Filename fn_, BaseDocument* doc_) : fn(fn_), doc(doc_)
			{
			}
			virtual ~VMDLoaderCameraDialog(void)
			{
				DeleteObj(Images);
			}
			virtual Bool CreateLayout(void);
			virtual Bool InitValues(void);
			virtual Bool Command(Int32 id, const BaseContainer& msg);
		};
	public:
		virtual Bool Identify(BaseSceneLoader* node, const Filename& name, UChar* probe, Int32 size);
		virtual FILEERROR Load(BaseSceneLoader* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags, maxon::String* error, BaseThread* bt);
		static NodeData* Alloc()
		{
			return(NewObjClear(VMDLoaderData));
		}
	};
	class VMD_Cam_Draw : public SceneHookData
	{
		INSTANCEOF(VMD_Cam_Draw, SceneHookData)
	public:
		virtual Bool Draw(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags);
		static NodeData* Alloc(void)
		{
			return(NewObjClear(VMD_Cam_Draw));
		}
	};
} /* namespace */
#endif  /* __MMD_VMD_ANIMATION_H__ */