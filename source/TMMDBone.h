#pragma once
#include "Utility.h"
#include "description/TMMDBone.h"

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
	class TMMDBone : public TagData
	{
		/* 使用Map储存补间曲线数据 */
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_X_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_Y_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_Z_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_R_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_A_map;
		maxon::HashMap<DescID, Int32> button_id_map;
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
		Bool GetInterpolator(const Int32& type, const Int32& frame_on, VMDInterpolator& interpolator) const;
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
		const bone_morph_data* GetMorph(Int32 index)
		{
			if (index >= bone_morph_data_arr.GetCount()) 
			{
				return nullptr;
			}
			else {
				return &bone_morph_data_arr[index];
			}
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
}