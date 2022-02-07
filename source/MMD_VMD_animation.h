#ifndef __MMD_VMD_ANIMATION_H__
#define __MMD_VMD_ANIMATION_H__

#include "MMD_utility.h"
#include "MMD_PMX_Control.h"
#include "description/TMMDBone.h"
#include "description/OMMDCamera.h"

namespace mmd {
	/* MMD animation */

	/* MMD style bone animation. */
	struct VMDBoneAnimation
	{
		String		bone_name = String();                               /* The action corresponds to the bone name. */
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Vector32	position = Vector32();                              /* The action corresponds to the bone position. */
		Vector4d32	rotation = Vector4d32();                            /* The action corresponds to the rotation of the bone (quad). */
		VMDInterpolator	interpolator_position_x = VMDInterpolator();    /* X-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_y = VMDInterpolator();    /* Y-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_z = VMDInterpolator();    /* Z-axis displacement action interpolation. */
		VMDInterpolator	interpolator_rotation = VMDInterpolator();    /* Rotation action interpolation. */
	};
	/* MMD style expression animation. */
	struct VMDMorphAnimation
	{
		String	morph_name = String();                                  /* The action corresponds to the expression name. */
		UInt32	frame_no = 0;                                           /* Frame of action. */
		Float32 weight = 0.f;                                           /* Expression deformation strength. */
	};
	/* MMD风格的摄像机动画 */
	struct VMDCameraAnimation
	{
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Float32		distance = 0.f;                                     /* Camera view distance. */
		Vector32	position = Vector32();                              /* View position of the camera. */
		Vector32	rotation = Vector32();                              /* Camera view rotation (Euler Angle of x and Y reversal) */
		VMDInterpolator	interpolator_position_x = VMDInterpolator();    /* X-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_y = VMDInterpolator();    /* Y-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_z = VMDInterpolator();    /* Z-axis displacement action interpolation. */
		VMDInterpolator	interpolator_rotation = VMDInterpolator();    /* Rotation action interpolation. */
		VMDInterpolator	interpolator_position_d = VMDInterpolator();    /* Distance action interpolation. */
		VMDInterpolator	interpolator_position_v = VMDInterpolator();    /* View Angle motion interpolation */
		UInt32		viewing_angle = 0;                                  /* View Angle. */
		UChar		perspective = 0;                                    /* 0:on, 1:off */
	};
	/* MMD style lighting animation */
	struct VMDLightAnimation
	{
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Vector32	rgb = Vector32();                                   /* Light color. */
		Vector32	position = Vector32();                              /* location. */
	};
	/* MMD style shadow animation */
	struct VMDShadowAnimation
	{
		UInt32	frame_no = 0;                                           /* Frame of action. */
		UChar	shadowType = 0;                                         /* 0:Off 1:mode1 2:mode2 */
		Float32 distance = 0.f;                                         /* Distance. */
	};
	/* MMD style IK enable information */
	struct VMDIkControllerAnimation
	{
		String	name = String();                                        /* IK name. */
		Bool	enable = true;                                          /* Is enable. */
		/* Constructor function */
		VMDIkControllerAnimation() {}
		VMDIkControllerAnimation(const String& name_, Bool enable_ = true) : name(name_), enable(enable_) {}
	};
	/* MMD style model information animation */
	struct VMDModelControllerAnimation
	{
		UInt32				frame_no = 0;                                   /* Frame of action. */
		Bool				show = true;                                       /* Is show. */
		maxon::PointerArray<VMDIkControllerAnimation> IKs_Info;                       /* IKs enable information. */
		/* Constructor function */
		VMDModelControllerAnimation(UInt32 frame_no_ = 0, Bool show_ = true) :frame_no(frame_no_), show(show_) {}
		/* Copy constructor */
		VMDModelControllerAnimation(const mmd::VMDModelControllerAnimation& src)
		{
			if (&src == this)
			{
				return;
			}
			this->frame_no = src.frame_no;
			this->show = src.show;
			this->IKs_Info.CopyFrom(src.IKs_Info) iferr_ignore("err"_s);
		}
		/* operator= */
		VMDModelControllerAnimation& operator =(const mmd::VMDModelControllerAnimation& src)
		{
			if (&src == this)
			{
				return(*this);
			}
			this->frame_no = src.frame_no;
			this->show = src.show;
			this->IKs_Info.CopyFrom(src.IKs_Info) iferr_ignore("err"_s);
			return(*this);
		}
	};
	/* Morph information struct. */
	struct morph_info
	{
		DescID	strength_id = DescID();                                         /* Morph ID. */
		BaseTag* tag = nullptr;                                        /* Morph tag. */
		String name = String();                                        /* Morph name. */
		/* operator== */
		Bool operator ==(const morph_info& other) const {
			return (this->strength_id == other.strength_id && this->tag == other.tag);
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->strength_id.GetHashCode(), this->tag);
		}
	};
	/* Bone information struct. */
	struct bone_info
	{
		BaseObject* obj = nullptr;                                     /* Bone object. */
		BaseTag* tag = nullptr;                                    /* Bone tag. */
		String name = String();									/* Bone name. */
		/* operator== */
		Bool operator ==(const bone_info& other) const {
			return (this->obj == other.obj && this->tag == other.tag);
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->obj, this->tag);
		}
	};
	struct VMD_Conversion_Camera_settings {
		Float		distance = 0;
		Int32		use_rotation = 0;
		BaseObject* str_cam = nullptr;
	};
	
	class VMDAnimation
	{
		MAXON_DISALLOW_COPY_AND_ASSIGN(VMDAnimation);
	private:
		class VMDMotionSortedArray : public maxon::SortedArray<VMDMotionSortedArray, maxon::PointerArray<VMDBoneAnimation> >
		{
		public:
			static Bool LessThan(const VMDBoneAnimation& a, const VMDBoneAnimation& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMDBoneAnimation& a, const VMDBoneAnimation& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDMorphSortedArray : public maxon::SortedArray<VMDMorphSortedArray, maxon::PointerArray<VMDMorphAnimation> >
		{
		public:
			static Bool LessThan(const VMDMorphAnimation& a, const VMDMorphAnimation& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMDMorphAnimation& a, const VMDMorphAnimation& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDCameraSortedArray : public maxon::SortedArray<VMDCameraSortedArray, maxon::PointerArray<VMDCameraAnimation> >
		{
		public:
			static Bool LessThan(const VMDCameraAnimation& a, const VMDCameraAnimation& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMDCameraAnimation& a, const VMDCameraAnimation& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDLightSortedArray : public maxon::SortedArray<VMDLightSortedArray, maxon::PointerArray<VMDLightAnimation> >
		{
		public:
			static Bool LessThan(const VMDLightAnimation& a, const VMDLightAnimation& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMDLightAnimation& a, const VMDLightAnimation& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDShadowSortedArray : public maxon::SortedArray<VMDShadowSortedArray, maxon::PointerArray<VMDShadowAnimation> >
		{
		public:
			static Bool LessThan(const VMDShadowAnimation& a, const VMDShadowAnimation& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMDShadowAnimation& a, const VMDShadowAnimation& b)
			{
				return(a.frame_no == b.frame_no);
			}
		};
		class VMDModelSortedArray : public maxon::SortedArray<VMDModelSortedArray, maxon::PointerArray<VMDModelControllerAnimation> >
		{
		public:
			static Bool LessThan(const VMDModelControllerAnimation& a, const VMDModelControllerAnimation& b)
			{
				return(a.frame_no < b.frame_no);
			}
			static Bool IsEqual(const VMDModelControllerAnimation& a, const VMDModelControllerAnimation& b)
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
		BaseDocument* doc = nullptr;

		/* 用于从文件导入到对象 */
		maxon::Result<void> LoadFromFile(Filename& fn);
		/* 用于将对象保存到文件 */
		maxon::Result<void> SaveToFile(Filename& fn);
		// 遍历场景，初始化目标对象
		maxon::Result<void> TraverseDocument(BaseObject* select_object,
			maxon::HashMap<String, bone_info>& bones_map,
			maxon::HashMap<String, morph_info>& morphs_map,
			maxon::HashMap<String, BaseTag*>& ik_tag_map);
		// 删除先前的动画数据
		maxon::Result<void> DeletePreviousAnimation(BaseObject* select_object,
			maxon::HashMap<String, bone_info>& bones_map,
			maxon::HashMap<String, morph_info>& morphs_map,
			maxon::HashMap<String, BaseTag*>& ik_tag_map);
	public:
		struct
		{
			Float		position_multiple = 8.5;
			Float		time_offset = 0;
			Filename	fn = Filename();
			BaseDocument* doc = nullptr;
		}m_camera_import_settings;
		struct
		{
			Float	position_multiple = 8.5;
			Float	time_offset = 0;
			Int32	use_rotation = 0;
			Bool    use_bake = true;
		}m_camera_export_settings;
		struct
		{
			Float	position_multiple = 8.5;
			Float	time_offset = 0;
			Bool    import_motion = true;
			Bool    import_morph = true;
			Bool    import_model_info = true;
			Bool	delete_previous_animation = true;
			Bool	detail_report = false;
		}m_motions_import_settings;
		struct
		{
			Float	position_multiple = 8.5;
			Float	time_offset = 0;
			Int32   use_rotation = 0;
			Bool    export_motion = true;
			Bool    export_morph = true;
			Bool    export_model_info = true;
			Bool    use_bake = true;
		}m_motions_export_settings;
		/* 构造函数 */
		VMDAnimation(){}
		/* 析构函数 */
		~VMDAnimation(){}
		/* 从文件导入摄像机数据 */
		maxon::Result<void> FromFileImportCamera();
		/* 从项目导出摄像机数据 */
		maxon::Result<void> FromDocumentExportCamera();
		/* 从文件导入动作或表情数据 */
		maxon::Result<void> FromFileImportMotion();
		/* 从项目导出动作或表情数据 */
		maxon::Result<void> FromDocumentExportMotion();	
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