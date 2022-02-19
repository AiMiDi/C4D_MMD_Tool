#ifndef __MMD_PMX_CONTROL_H__
#define __MMD_PMX_CONTROL_H__

#include "MMD_utility.h"
#include "c4d_nodedata.h"
#include "description/OMMDModel.h"
#include "description/TMMDBone.h"
#include "description/OMMDRigid.h"
#include "description/OMMDJoint.h"
#include "description/OMMDRigidRoot.h"
#include "description/OMMDJointRoot.h"
#include "description/OMMDMeshRoot.h"
#include "description/OMMDBoneRoot.h"
namespace mmd {
	struct bone_morph_data
	{
		DescID	grp_id;
		DescID	strength_id;
		DescID	translation_id;
		DescID	rotation_id;
		DescID	button_grp_id;
		DescID	button_delete_id;
		DescID	button_rename_id;
		String	name;
		bone_morph_data(
			const DescID& grp_id_,
			const DescID& strength_id_,
			const DescID& translation_id_,
			const DescID& rotation_id_,
			const DescID& button_grp_id_,
			const DescID& button_delete_id_,
			const DescID& button_rename_id_,
			const String& name_)
		{
			grp_id = grp_id_;
			strength_id = strength_id_;
			translation_id = translation_id_;
			rotation_id = rotation_id_;
			button_grp_id = button_grp_id_;
			button_delete_id = button_delete_id_;
			button_rename_id = button_rename_id_;
			name = name_;
		}
		bone_morph_data() : bone_morph_data(DescID(), DescID(), DescID(), DescID(), DescID(), DescID(), DescID(), String()) {}
	};
	struct bone_morph_hub_data {
		BaseTag* bone_tag = nullptr;
		bone_morph_data data = bone_morph_data();
	};
	struct mesh_morph_hub_data {
		CAPoseMorphTag* morph_tag = nullptr;
		CAMorph* morph = nullptr;
	};
	enum class OMMDModel_Root_type
	{
		MeshRoot = 0,
		BoneRoot,
		RigidRoot,
		JointRoot
	};
	class OMMDMeshRoot : public ObjectData
	{
		OMMDMeshRoot() {}
		~OMMDMeshRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDMeshRoot);
		INSTANCEOF(OMMDMeshRoot, ObjectData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDMeshRoot));
		}
	};
	class OMMDBoneRoot : public ObjectData
	{
		friend class TMMDBone;
		friend class OMMDRigid;
		friend class OMMDJoint;
		Int64 name_cnt = 1;
		BaseObject* RigidRoot = nullptr;
		BaseObject* JointRoot = nullptr;
		BaseContainer bone_items;
		maxon::HashMap<Int32, BaseObject*> IndexToBoneMap;
		maxon::HashMap<BaseObject*, Int32> BoneToIndexMap;
		OMMDBoneRoot() {}
		~OMMDBoneRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDBoneRoot);
		INSTANCEOF(OMMDBoneRoot, ObjectData)
	public:	
		virtual Bool Init(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDBoneRoot));
		}
	};
	class OMMDRigidRoot : public ObjectData
	{
		friend class OMMDRigid;
		friend class OMMDJoint;
		Int64 name_cnt = 1;
		BaseContainer rigid_items;
		BaseObject* BoneRoot = nullptr;
		BaseObject* JointRoot = nullptr;
		maxon::HashMap<Int32, BaseObject*> IndexToRigidMap;
		OMMDRigidRoot() {}
		~OMMDRigidRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDRigidRoot);
		INSTANCEOF(OMMDRigidRoot, ObjectData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual void Free(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDRigidRoot));
		}
	};
	class OMMDJointRoot : public ObjectData
	{	
		friend class OMMDJoint;
		Int64 name_cnt = 1;
		BaseObject* BoneRoot = nullptr;
		BaseObject* RigidRoot = nullptr;
		OMMDJointRoot() {}
		~OMMDJointRoot() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDJointRoot);
		INSTANCEOF(OMMDJointRoot, ObjectData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDJointRoot));
		}
	};
	class OMMDModel : public ObjectData
	{	
		BaseObject* MeshRoot = nullptr;
		BaseObject* BoneRoot = nullptr;
		BaseObject* RigidRoot = nullptr;
		BaseObject* JointRoot = nullptr;
		OMMDModel() {}
		~OMMDModel() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDModel);
		INSTANCEOF(OMMDModel, ObjectData)
	public:		
		virtual Bool Init(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
		/* 实时调用 */
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		/* 将实时调用添加入优先级列表 */
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		Bool CreateRoot();
		BaseObject* GetRootObject(OMMDModel_Root_type type_)
		{
			switch (type_)
			{
			case mmd::OMMDModel_Root_type::MeshRoot:
				return this->MeshRoot;
			case mmd::OMMDModel_Root_type::BoneRoot:
				return this->BoneRoot;
			case mmd::OMMDModel_Root_type::RigidRoot:
				return this->RigidRoot;
			case mmd::OMMDModel_Root_type::JointRoot:
				return this->JointRoot;
			default:
				return nullptr;
			}
		}
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDModel));
		}
	};
	class TMMDBone : public TagData
	{
		/* 使用Map储存补间曲线数据 */
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_X_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_Y_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_Z_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_R_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_A_map;
		maxon::HashMap<DescID, Int32>		button_id_map;
		/* 骨骼表情索引 */
		Int32 bone_morph_name_index = 0;
		/* 储存前一帧，以确定更新状态 */
		Int32 prev_frame = -1;
		/* 储存上一种曲线类型，以确定更新状态 */
		Int32 prev_interpolator_type = -1;
		/* 对应的骨骼主对象 */
		BaseObject* obj = nullptr;
		/* 赋予亲骨骼对象 */
		BaseObject* inherit_bone_parent = nullptr;
		/* 骨骼根对象 */
		BaseObject* BoneRoot = nullptr;
		/* 是否是物理骨骼 */
		Bool	Is_physical = false;
		/* 用于处理骨骼表情 */
		Vector	prev_position = Vector();
		/* 用于处理骨骼表情 */
		Vector	prev_rotation = Vector();
		/* 储存骨骼表情数据 */
		maxon::PointerArray<bone_morph_data> bone_morph_data_arr;
		TMMDBone() {}
		~TMMDBone() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(TMMDBone);
		INSTANCEOF(TMMDBone, TagData)
	public:
		Int32 AddBondMorph(String morph_name);
		Bool RefreshColor(GeListNode* node = nullptr, BaseObject* op = nullptr);
		/* 用于限制SplineData的回调函数 */
		static Bool SplineDataCallBack(Int32 cid, const void* data);
		/* 获取曲线值 */
		Bool GetInterpolator(const Int32& type, const Int32& frame_on,VMDInterpolator& interpolator) const;
		/* 设置曲线值 */
		Bool SetInterpolator(const Int32& type, const Int32& frame_on, VMDInterpolator&& interpolator, Bool cover = true);
		Bool AutoRegisterKeyFrame(Int32 use_rotation = 0, GeListNode* node = nullptr);
		/* 注册关键帧 */
		Bool RegisterKeyFrame(Int32 frame_on, GeListNode* node = nullptr);
		/* 更新全部补间曲线 */
		Bool UpdateAllInterpolator(GeListNode* node = nullptr);
		/* 初始化曲线 */
		Bool InitInterpolator(GeListNode* node = nullptr);
		/* 删除曲线 */
		Bool DeleteKeyFrame(Int32 frame_on, GeListNode* node = nullptr);
		/* 删除全部曲线 */
		Bool DeleteAllKeyFrame(GeListNode* node = nullptr);
		/* 接收Message时调用，用于处理事件 */
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual Bool Init(GeListNode* node);
		/* 设置参数时调用，用于调用SplineData的回调函数 */
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		static NodeData* Alloc()
		{
			return(NewObjClear(TMMDBone));
		}
		virtual void Free(GeListNode* node);
		void SetObj(BaseObject* obj_)
		{
			this->obj = obj_;
		}
		void SetRootObject(BaseObject* obj_)
		{
			this->BoneRoot = obj_;
		}
		Bool SetBondMorphTranslation(Int32 id, Vector translation)
		{
			if (id < 0 || id > bone_morph_data_arr.GetCount() - 1)
			{
				return(false);
			}
			return(Get()->SetParameter(bone_morph_data_arr[id].translation_id, translation, DESCFLAGS_SET::NONE));
		}
		Bool SetBondMorphRotation(Int32 id, Vector rotation)
		{
			if (id < 0 || id > bone_morph_data_arr.GetCount() - 1)
			{
				return(false);
			}
			return(Get()->SetParameter(bone_morph_data_arr[id].rotation_id, rotation, DESCFLAGS_SET::NONE));
		}
		Int GetMorphCount()
		{
			return(bone_morph_data_arr.GetCount());
		}
		bone_morph_data& GetMorph(Int32 index)
		{
			return(bone_morph_data_arr[index]);
		}
		Bool IsPhysical()
		{
			return(this->Is_physical);
		}
		void SetPhysical(Bool Is_physical_)
		{
			this->Is_physical = Is_physical_;
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
		~OMMDRigid(){}
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
	class OMMDJoint : public ObjectData
	{
	private:
		Int32	DisplayType = JOINT_DISPLAY_TYPE_OFF;
		Int32	mode = JOINT_MODE_ANIM;
		BaseObject* JointRoot = nullptr;
		BaseObject* link_rigid_a = nullptr;
		BaseObject* link_rigid_b = nullptr;
		BaseTag* protection_tag = nullptr;
		OMMDJoint() {}
		~OMMDJoint() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDJoint);
		INSTANCEOF(OMMDJoint, ObjectData)

	public:		
		/* 对象初始化 */
		virtual Bool Init(GeListNode* node);
		/* 设置参数时调用，用于调用SplineData的回调函数 */
		virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
		Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
		/* 接收Message时调用，用于处理事件 */
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		virtual DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
		/* 实时调用 */
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		/* 将实时调用添加入优先级列表 */
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		/* 生成函数 */
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDJoint));
		}
	};
	struct OMMDModel_MSG
	{
		OMMDModel_Root_type	type = OMMDModel_Root_type::MeshRoot;
		BaseObject* Root = nullptr;
		OMMDModel_MSG(OMMDModel_Root_type type_ = OMMDModel_Root_type::MeshRoot, BaseObject* Root_ = nullptr) :type(type_), Root(Root_) {}
	};
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
	struct OMMDBoneRoot_MSG
	{
		/*
		type 0: updata BoneRoot;
		type 1: set bone display type;
		type 2: bone index change;
		*/
		Int32	type = 0;
		Int32	DisplayType = BONE_DISPLAY_TYPE_ON;
		BaseObject* BoneRoot = nullptr;
		OMMDBoneRoot_MSG(Int32 type_ = 0, Int32 DisplayType_ = BONE_DISPLAY_TYPE_ON, BaseObject* BoneRoot_ = nullptr)
		{
			type = type_;
			DisplayType = DisplayType_;
			BoneRoot = BoneRoot_;
		}
	};
	struct OMMDRigidRoot_MSG
	{
		Int32	type = 0;
		Int32	DisplayType = RIGID_DISPLAY_TYPE_OFF;
		Int32	mode = RIGID_MODE_ANIM;
		OMMDRigidRoot_MSG(Int32 type_ = 0, Int32 DisplayType_ = RIGID_DISPLAY_TYPE_OFF, Int32 mode_ = RIGID_MODE_ANIM)
		{
			type = type_;
			DisplayType = DisplayType_;
			mode = mode_;
		}
	};
	struct OMMDJointRoot_MSG
	{
		Int32	type = 0;
		Int32	DisplayType = JOINT_DISPLAY_TYPE_OFF;
		Int32	mode = JOINT_MODE_ANIM;
		OMMDJointRoot_MSG(Int32 type_ = 0, Int32 DisplayType_ = JOINT_DISPLAY_TYPE_OFF, Int32 mode_ = JOINT_MODE_ANIM)
		{
			type = type_;
			DisplayType = DisplayType_;
			mode = mode_;
		}
	};
	/*
	 * class PMX_Material_Tag : public TagData
	 * {
	 * public:
	 * virtual Bool Init(GeListNode* node);
	 *
	 * virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
	 * virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
	 *
	 * static NodeData* Alloc() { return NewObjClear(PMX_Material_Tag); }
	 * };
	 * class PMX_Display_Tag : public TagData
	 * {
	 * public:
	 * virtual Bool Init(GeListNode* node);
	 *
	 * virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
	 * virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
	 *
	 * static NodeData* Alloc() { return NewObjClear(PMX_Display_Tag); }
	 * };
	 */
	class RenameDialog : public GeDialog
	{
		Bool CreateLayout()
		{
			GroupBegin(1000, BFH_LEFT, 2, 1, ""_s, 0, 0, 10);
			AddStaticText(10000, BFH_LEFT, 100, 10, GeLoadString(IDS_MSG_RENAME), BORDER_NONE);
			AddEditText(10001, BFH_LEFT, 230, 10);
			GroupEnd();
			GroupBegin(1002, BFH_CENTER, 2, 1, ""_s, 0, 0, 20);
			GroupSpace(50, 0);
			AddButton(10002, BFH_LEFT, 80, 20, GeLoadString(IDS_MSG_RENAME_OK));
			AddButton(10003, BFH_RIGHT, 80, 20, GeLoadString(IDS_MSG_RENAME_CANCEL));
			GroupEnd();
			return(true);
		}
		Bool Command(Int32 id, const BaseContainer& msg)
		{
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
			return(true);
		}
	public:
		String Rename;
		RenameDialog()
		{
		}
		~RenameDialog()
		{
		}
	};
}
#endif /* __MMD_PMX_CONTROL_H__ */